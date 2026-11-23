/* Linker script for STM32F407VG (1 MB Flash, 128 KB main SRAM) */
ENTRY(Reset_Handler)
 
_Min_Stack_Size = 0x400;               /* reserve at least 1 KB for the stack */
 
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1024K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}
 
_estack = ORIGIN(RAM) + LENGTH(RAM);   /* the stack starts at the END of RAM */
 
SECTIONS
{
    .isr_vector :
    {
        KEEP(*(.isr_vector))           /* vector table: must be first in Flash */
    } > FLASH
 
    .text :
    {
        *(.text*)                      /* code */
        *(.rodata*)                    /* constants */
        KEEP(*(.init))
        KEEP(*(.fini))
        . = ALIGN(4);
    } > FLASH
 
    .ARM.extab : { *(.ARM.extab* .gnu.linkonce.armextab.*) } > FLASH
    .ARM.exidx : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) } > FLASH
 
    _sidata = LOADADDR(.data);         /* initial values of .data live here, in Flash */
 
    .data :
    {
        _sdata = .;
        *(.data*)                      /* variables WITH an initial value */
        . = ALIGN(4);
        _edata = .;
    } > RAM AT > FLASH
 
    .bss :
    {
        _sbss = .;
        *(.bss*)                       /* variables WITHOUT an initial value */
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM
 
    /* Make the linker FAIL if .data + .bss leave less than 1 KB for the stack. */
    ASSERT((_estack - _ebss) >= _Min_Stack_Size, "ERROR: not enough RAM left for the stack")
}
