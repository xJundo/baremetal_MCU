ENTRY (Reset_Handler)

MEMORY {
    flash(rx): ORIGIN = 0x00000000, LENGTH = 256K
    sram(rwx): ORIGIN = 0x20000000, LENGTH = 32K
}

SECTIONS {

    /* ".= flash ORIGIN" */
    .text : {
        *(.isr_vectors)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _etext = .;
    } > flash

    .data : {
        _sdata = .;
        *(.data);
        . = ALIGN(4);
        _edata = .;
    } > sram AT > flash /* data from flash to sram */

    .bss : {
        _sbss = .;
        *(.bss)
        *(COMMON)
        _ebss = .;
    } > sram
}