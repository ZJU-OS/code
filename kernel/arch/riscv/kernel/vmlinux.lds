OUTPUT_ARCH("riscv")

ENTRY(_start)

PHY_START    = 0x80000000;
PHY_SIZE     = (128 * 1024 * 1024);
PHY_END      = (PHY_START + PHY_SIZE);
PGSIZE       = 0x1000;
OPENSBI_SIZE = (0x200000);
VM_DIRECT_START = 0xffffffd600000000;
VM_DIRECT_END = (VM_DIRECT_START + PHY_SIZE);

MEMORY {
    ram  (wxa!ri): ORIGIN = PHY_START + OPENSBI_SIZE, LENGTH = PHY_SIZE - OPENSBI_SIZE
    ramv (wxa!ri): ORIGIN = VM_DIRECT_START + OPENSBI_SIZE, LENGTH = PHY_SIZE - OPENSBI_SIZE
}

BASE_ADDR = VM_DIRECT_START + OPENSBI_SIZE;

SECTIONS
{
    . = BASE_ADDR;

    _skernel = .;

    .text : ALIGN(0x1000) {
        _stext = .;

        *(.text.init)
        *(.text.entry)
        *(.text .text.*)

        _etext = .;
    } >ramv AT>ram

    .rodata : ALIGN(0x1000) {
        _srodata = .;

        *(.rodata .rodata.*)

        _erodata = .;
    } >ramv AT>ram

    .data : ALIGN(0x1000) {
        _sdata = .;

        *(.data .data.*)
        *(.got .got.*)

        _edata = .;

        . = ALIGN(0x1000);
    } >ramv AT>ram

    .bss : ALIGN(0x1000) {
        _sbss = .;
        _sstack = .;
        *(.bss.stack)
        . = ALIGN(0x1000);
        _estack = .;

        *(.sbss .sbss.*)
        *(.bss .bss.*)

        _ebss = .;
    } >ramv AT>ram

    . = ALIGN(0x1000);
    _ekernel = .;
}
