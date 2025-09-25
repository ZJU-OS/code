CONTAINER_NAME := zju-os-code

# File Locations
ROOTFS_PATH := ../rootfs.ext2
INITRD_PATH := ../initrd.gz
FAT32_PATH := ../fat32.img
#KERNEL_PATH := $(wildcard ../linux-*)
KERNEL_PATH := kernel
IMAGE_PATH := $(KERNEL_PATH)/arch/riscv/boot/Image
VMLINUX_PATH := $(KERNEL_PATH)/vmlinux
OPENSBI_FW_JUMP_PATH := /usr/lib/riscv64-linux-gnu/opensbi/generic/fw_jump.elf
OPENSBI_FW_DYNAMIC_PATH := /usr/lib/riscv64-linux-gnu/opensbi/generic/fw_dynamic.elf

# Alternative Targets
GDB_INIT_SCRIPT := gdbinit
#GDB_INIT_SCRIPT := gdbinit.py
GDB_TARGET := $(VMLINUX_PATH)
#GDB_TARGET := $(OPENSBI_FW_DYNAMIC_PATH)

SIMULATOR := qemu-system-riscv64
ifeq ($(SIMULATOR),qemu-system-riscv64)
	SIMULATOR_OPTS := \
		-nographic \
		-machine virt \
		-kernel $(IMAGE_PATH) \
		-drive file=$(ROOTFS_PATH),format=raw,id=hd0,if=none \
		-device virtio-blk-device,drive=hd0 \
		-netdev user,id=net0 \
		-device virtio-net-device,netdev=net0 \
		-append "root=/dev/vda ro console=ttyS0"
	SIMULATOR_DEBUG_OPTS := -s -S
else ifeq ($(SIMULATOR),spike)
	SIMULATOR_OPTS := \
		--kernel=$(IMAGE_PATH) \
		--initrd=$(INITRD_PATH) \
		--real-time-clint \
		$(OPENSBI_FW_JUMP_PATH)
	SIMULATOR_DEBUG_OPTS := --halted --rbb-port=9824
else
	$(error Unsupported simulator: $(SIMULATOR))
endif

.PHONY: all clean run debug gdb ocd update

ifeq ($(shell which docker),)
# inside docker
all:
	make \
		-C $(KERNEL_PATH) \
		ARCH=riscv \
		CROSS_COMPILE=riscv64-linux-gnu- \
		defconfig
	bear -- make \
		-C $(KERNEL_PATH) \
		ARCH=riscv \
		CROSS_COMPILE=riscv64-linux-gnu- \
		-j$(shell nproc)
clean:
	make -C $(KERNEL_PATH) clean
%:
	make -C $(KERNEL_PATH) $@
else
# outside docker
all:
# check if host Git and SSH config exist
	@if [ ! -f ~/.gitconfig ]; then \
		echo "Error: ~/.gitconfig not found on host"; \
		exit 1; \
	fi
	@if [ ! -d ~/.ssh ]; then \
		echo "Error: ~/.ssh not found on host"; \
		exit 1; \
	fi
	docker compose create --no-recreate
	docker compose start
	docker compose exec -it $(CONTAINER_NAME) /usr/bin/fish
	docker compose stop
clean:
	docker compose down -v --remove-orphans
update: clean
	docker compose pull
endif

run:
	$(SIMULATOR) $(SIMULATOR_OPTS)

debug:
	$(SIMULATOR) $(SIMULATOR_DEBUG_OPTS) $(SIMULATOR_OPTS)

gdb:
	gdb-multiarch -x $(GDB_INIT_SCRIPT) $(VMLINUX_PATH)

ocd:
	openocd -f openocd.cfg
