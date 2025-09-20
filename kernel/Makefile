CROSS_COMPILE := riscv64-linux-gnu-
export GCC := $(CROSS_COMPILE)gcc
export LD := $(CROSS_COMPILE)ld
export OBJCOPY := $(CROSS_COMPILE)objcopy
export OBJDUMP := $(CROSS_COMPILE)objdump
export NM := $(CROSS_COMPILE)nm

ISA := rv64imafd_zicsr_zifencei
ABI := lp64

export CPPFLAGS := -I$(CURDIR)/include
export CFLAGS := \
	-march=$(ISA) \
	-mabi=$(ABI) \
	-mcmodel=medany \
	-ffreestanding \
	-fno-builtin \
	-ffunction-sections \
	-fdata-sections \
	-nostartfiles \
	-nostdlib \
	-nostdinc \
	-static \
	-ggdb \
	-Og \
	-Wall \
	-Wextra \
	-fno-pie \
	-MMD \
	-std=gnu11
export LDFLAGS := \
	-lgcc \
	-Wl,--nmagic \
	-Wl,--gc-sections

.PHONY: all clean defconfig

all:
	$(MAKE) -C lib all
	$(MAKE) -C arch/riscv all
	$(LD) -T arch/riscv/kernel/vmlinux.lds \
		arch/riscv/kernel/*.o \
		lib/*.o \
		-o vmlinux
	mkdir -p arch/riscv/boot
	$(OBJCOPY) -O binary vmlinux arch/riscv/boot/Image
	$(OBJDUMP) -S vmlinux > vmlinux.asm
	$(NM) vmlinux > System.map
	# Build finished!

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C arch/riscv clean
	rm -rf vmlinux vmlinux.asm snprintf_test System.map arch/riscv/boot
	# Clean finished!

defconfig:

format:
	find . -name "*.c" -o -name "*.h" | xargs -r clang-format -i
