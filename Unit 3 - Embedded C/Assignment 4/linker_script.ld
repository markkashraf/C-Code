MEMORY
{
    flash(RX) : ORIGIN = 0x00000000, LENGTH = 128K
    sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text : 
    {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = . ;

    } > flash         /* set the .text section to be at flash at runtime 
                        and map all assembbly sections named .vectors, .text
                        and .rodata (in order) to the .text section */

    .data : 
    {
        _S_DATA = . ;
        *(.data)
        . = ALIGN(4);
        _E_DATA = . ;

    } > sram AT> flash /* set the .data section to be at sram at runtime 
                        and map it to all assembbly sections named .data */
    .bss : 
    {
        _S_bss = . ;
        *(.bss*)
        _E_bss = . ;
    }  > sram           /* set the .bss section to be at sram at runtime 
                        and map it to all assembbly sections named .bss */

}