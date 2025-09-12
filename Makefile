CONTAINER_NAME := zju-os-code
ROOTFS_PATH := ../rootfs.ext2
KERNEL_PATH := ../linux-*
QEMU_DEFAULT_OPTS := -nographic \
	-machine virt \
	-kernel $(KERNEL_PATH)/arch/riscv/boot/Image \
	-drive file=$(ROOTFS_PATH),format=raw,id=hd0,if=none \
	-device virtio-blk-device,drive=hd0 \
	-netdev user,id=net0 \
	-device virtio-net-device,netdev=net0 \
	-append "root=/dev/vda ro console=ttyS0"

.PHONY: build all clean qemu qemu-debug gdb

# run on host
all:
	docker compose create --no-recreate
	docker compose start
	docker compose exec -it $(CONTAINER_NAME) /usr/bin/fish
	docker compose stop

clean:
	docker compose down -v --remove-orphans

# inside docker
qemu:
	qemu-system-riscv64 $(QEMU_DEFAULT_OPTS)

qemu-debug:
	qemu-system-riscv64 $(QEMU_DEFAULT_OPTS) \
		-s -S

gdb:
	gdb-multiarch -x gdbinit $(KERNEL_PATH)/vmlinux

gdb-opensbi:
	gdb-multiarch -x gdbinit /usr/lib/riscv64-linux-gnu/opensbi/generic/fw_dynamic.elf
