#include <stdint.h>

#define SRAM_START 0x20000000
#define SRAM_SIZE (32UL * 1024)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_START (SRAM_END)
extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;

void Reset_Handler               ( void );
void NMI_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler           ( void ) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler              ( void ) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void PM_Handler                  ( void ) __attribute__((weak, alias("Default_Handler")));
void SYSCTRL_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void WDT_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void RTC_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void EIC_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void NVMCTRL_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void DMAC_Handler                ( void ) __attribute__((weak, alias("Default_Handler")));
void USB_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void EVSYS_Handler               ( void ) __attribute__((weak, alias("Default_Handler")));
void SERCOM0_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void SERCOM1_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void SERCOM2_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void SERCOM3_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void SERCOM4_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void SERCOM5_Handler             ( void ) __attribute__((weak, alias("Default_Handler")));
void TCC0_Handler                ( void ) __attribute__((weak, alias("Default_Handler")));
void TCC1_Handler                ( void ) __attribute__((weak, alias("Default_Handler")));
void TCC2_Handler                ( void ) __attribute__((weak, alias("Default_Handler")));
void TC3_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void TC4_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void TC5_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void ADC_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void AC_Handler                  ( void ) __attribute__((weak, alias("Default_Handler")));
void DAC_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void PTC_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));
void I2S_Handler                 ( void ) __attribute__((weak, alias("Default_Handler")));



uint32_t vectors_table[]            __attribute__((section(".isr_vectors"))) = {
    STACK_START,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)&SVC_Handler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,
    (uint32_t)&PM_Handler,
    (uint32_t)&SYSCTRL_Handler,
    (uint32_t)&WDT_Handler,
    (uint32_t)&RTC_Handler,
    (uint32_t)&EIC_Handler,
    (uint32_t)&NVMCTRL_Handler,
    (uint32_t)&DMAC_Handler,
    (uint32_t)&USB_Handler,
    (uint32_t)&EVSYS_Handler,
    (uint32_t)&SERCOM0_Handler,
    (uint32_t)&SERCOM1_Handler,
    (uint32_t)&SERCOM2_Handler,
    (uint32_t)&SERCOM3_Handler,
    (uint32_t)&SERCOM4_Handler,
    (uint32_t)&SERCOM5_Handler,
    (uint32_t)&TCC0_Handler,
    (uint32_t)&TCC1_Handler,
    (uint32_t)&TCC2_Handler,
    (uint32_t)&TC3_Handler,
    (uint32_t)&TC4_Handler,
    (uint32_t)&TC5_Handler,
    (uint32_t)&ADC_Handler,
    (uint32_t)&AC_Handler,
    (uint32_t)&DAC_Handler,
    (uint32_t)&PTC_Handler,
    (uint32_t)&I2S_Handler,
    (uint32_t)0
};

void Reset_Handler(void)
{
    //copy .data section to SRAM
    uint32_t size = &_edata - &_sdata;
    uint8_t *src = (uint8_t *)&_etext; //false
    uint8_t *dst = (uint8_t *)&_sdata; // sram

    for (uint32_t i = 0; i < size; i++) {
        *dst++ = *src++;
    }

    //Init the .bss section
    size = &_ebss - &_sbss;
    
}

void Default_Handler(void)
{
    while(1);
}
