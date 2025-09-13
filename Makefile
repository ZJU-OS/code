CONTAINER_NAME := zju-os-code
ROOTFS_PATH := ../rootfs.ext2
FAT32_PATH := ../fat32.img
KERNEL_PATH := $(wildcard ../linux-*)
#KERNEL_PATH := kernel
IMAGE_PATH := $(KERNEL_PATH)/arch/riscv/boot/Image
VMLINUX_PATH := $(KERNEL_PATH)/vmlinux
GDB_INIT_SCRIPT := gdbinit
#GDB_INIT_SCRIPT := gdbinit.py
GDB_TARGET := $(VMLINUX_PATH)
#GDB_TARGET := /usr/lib/riscv64-linux-gnu/opensbi/generic/fw_dynamic.elf # for opensbi debug
QEMU_DEFAULT_OPTS := -nographic \
	-machine virt \
	-kernel $(IMAGE_PATH) \
	-drive file=$(ROOTFS_PATH),format=raw,id=hd0,if=none \
	-device virtio-blk-device,drive=hd0 \
	-netdev user,id=net0 \
	-device virtio-net-device,netdev=net0 \
	-append "root=/dev/vda ro console=ttyS0"

.PHONY: build all clean qemu qemu-debug gdb

all:
	docker compose create --no-recreate
	docker compose start
	docker compose exec -it $(CONTAINER_NAME) /usr/bin/fish
	docker compose stop

ifeq ($(shell which docker),)
clean:
	make -C $(KERNEL_PATH) clean
else
clean:
	docker compose down -v --remove-orphans
endif

build:
	make ARCH=riscv CROSS_COMPILE=riscv64-linux-gnu- -C $(KERNEL_PATH) defconfig
	make ARCH=riscv CROSS_COMPILE=riscv64-linux-gnu- -C $(KERNEL_PATH) -j$(nproc)

qemu: build
	qemu-system-riscv64 $(QEMU_DEFAULT_OPTS)

qemu-debug:
	qemu-system-riscv64 $(QEMU_DEFAULT_OPTS) \
		-s -S

gdb:
	gdb-multiarch -x $(GDB_INIT_SCRIPT) $(VMLINUX_PATH)
