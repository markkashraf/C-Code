ENTRY(reset)

MEMORY
{
    Mem (rwx) : ORIGIN = 0x00000000, LENGTH = 64M
}

SECTIONS
{
    . = 0x10000;
    .text . : 
    {
       startup.o(.text) 
    }> Mem
    .code_text_and_rodata :
    {
        *(.text) *(.rodata)
    }> Mem

    .initialized_global_data : 
    {
        *(.data)
    }> Mem
     .unitialized_global_data : 
    {
        *(.bss)
    }> Mem
    . = . + 0x1000;
    stack_top = .;
}