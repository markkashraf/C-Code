#include <stdint.h>
#define STACK_Start_SP 0x20001000
#define volatile unsigned int vuint32_t;

/*resolving external symbols*/
extern int main(void); /*Defined in main.c*/

void Reset_Handler(void); 

void Default_Handler()
{
    Reset_Handler();
}
/*set handlers to be weak for a future
 user-overridden implementaion, and until
  the user does so we set it to link to the Default_Handler*/
void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void H_fault_Handler(void) __attribute__((weak,alias("Default_Handler")));

/*we reserve bytes so that it can be used as a stack and it will be 
    included inside the .bss section, we make it static so that it cannot be accessed from outside this file*/
static unsigned long stack[256]; /* 1024 byte */



/*create a table of words and put it in a .vectors section*/
void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = {
   (void (*)()) ((unsigned long)stack + sizeof(stack)),
   &Reset_Handler,
   &NMI_Handler,
   &H_fault_Handler};


extern uint32_t _S_DATA; /*Defined in linker script*/
extern uint32_t _E_DATA; /*Defined in linker script*/
extern uint32_t _S_bss; /*Defined in linker script*/
extern uint32_t _E_bss; /*Defined in linker script*/
extern uint32_t _E_text; /*Defined in linker script*/



void Reset_Handler()
{
  
    /*Pre-proessing data*/

    /*casting just in case :3 */
    unsigned int Data_Size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
    unsigned int bss_size  = (unsigned char*)&_E_bss -  (unsigned char*)&_S_bss;
    /*creating a byte pointers for source and destenation*/
    unsigned char* P_src, *P_dst;
    int i;

    /* Copying data from ROM to RAM */
    P_src = (unsigned char*)_E_text; /* just in case :> */
    P_dst = (unsigned char*)_S_DATA; /* just in case :> */
    for(i=0; i<Data_Size; i++)
    *((unsigned char*)P_dst++) = *((unsigned char*)P_src++); /* :3 */


     /* Initializing bss to 0 */
    P_dst = (unsigned char*)_S_bss; /* just in case :> */
    for(i=0; i<bss_size; i++)
    *((unsigned char*)P_dst++) = (unsigned char)0; /* :3 */
    

    main();
}