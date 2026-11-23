/*
 * startup_stm32f407.c - start-up code and vector table for the STM32F407
 *
 * 1. The CPU reads word 0 of Flash  -> initial stack pointer
 * 2. The CPU reads word 1 of Flash  -> address of Reset_Handler, and jumps there
 * 3. Reset_Handler prepares RAM, calls SystemInit(), then main().
 */
#include <stdint.h>
 
/* Symbols created by the linker script (linker/stm32f407.ld) */
extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
 
int  main(void);
void SystemInit(void);
 
void Reset_Handler(void);
void Default_Handler(void);
 
/* Every handler is a WEAK alias of Default_Handler. If your own code defines a
 * function with the same name, yours replaces it automatically. */
#define WEAK_ALIAS __attribute__((weak, alias("Default_Handler")))
 
void NMI_Handler(void) WEAK_ALIAS;
void HardFault_Handler(void) WEAK_ALIAS;
void MemManage_Handler(void) WEAK_ALIAS;
void BusFault_Handler(void) WEAK_ALIAS;
void UsageFault_Handler(void) WEAK_ALIAS;
void SVC_Handler(void) WEAK_ALIAS;
void DebugMon_Handler(void) WEAK_ALIAS;
void PendSV_Handler(void) WEAK_ALIAS;
void SysTick_Handler(void) WEAK_ALIAS;
void WWDG_IRQHandler(void) WEAK_ALIAS;
void PVD_IRQHandler(void) WEAK_ALIAS;
void TAMP_STAMP_IRQHandler(void) WEAK_ALIAS;
void RTC_WKUP_IRQHandler(void) WEAK_ALIAS;
void FLASH_IRQHandler(void) WEAK_ALIAS;
void RCC_IRQHandler(void) WEAK_ALIAS;
void EXTI0_IRQHandler(void) WEAK_ALIAS;
void EXTI1_IRQHandler(void) WEAK_ALIAS;
void EXTI2_IRQHandler(void) WEAK_ALIAS;
void EXTI3_IRQHandler(void) WEAK_ALIAS;
void EXTI4_IRQHandler(void) WEAK_ALIAS;
void DMA1_Stream0_IRQHandler(void) WEAK_ALIAS;
void DMA1_Stream1_IRQHandler(void) WEAK_ALIAS;
void DMA1_Stream2_IRQHandler(void) WEAK_ALIAS;
void DMA1_Stream3_IRQHandler(void) WEAK_ALIAS;
void DMA1_Stream4_IRQHandler(void) WEAK_ALIAS;
void DMA1_Stream5_IRQHandler(void) WEAK_ALIAS;
void DMA1_Stream6_IRQHandler(void) WEAK_ALIAS;
void ADC_IRQHandler(void) WEAK_ALIAS;
void CAN1_TX_IRQHandler(void) WEAK_ALIAS;
void CAN1_RX0_IRQHandler(void) WEAK_ALIAS;
void CAN1_RX1_IRQHandler(void) WEAK_ALIAS;
void CAN1_SCE_IRQHandler(void) WEAK_ALIAS;
void EXTI9_5_IRQHandler(void) WEAK_ALIAS;
void TIM1_BRK_TIM9_IRQHandler(void) WEAK_ALIAS;
void TIM1_UP_TIM10_IRQHandler(void) WEAK_ALIAS;
void TIM1_TRG_COM_TIM11_IRQHandler(void) WEAK_ALIAS;
void TIM1_CC_IRQHandler(void) WEAK_ALIAS;
void TIM2_IRQHandler(void) WEAK_ALIAS;
void TIM3_IRQHandler(void) WEAK_ALIAS;
void TIM4_IRQHandler(void) WEAK_ALIAS;
void I2C1_EV_IRQHandler(void) WEAK_ALIAS;
void I2C1_ER_IRQHandler(void) WEAK_ALIAS;
void I2C2_EV_IRQHandler(void) WEAK_ALIAS;
void I2C2_ER_IRQHandler(void) WEAK_ALIAS;
void SPI1_IRQHandler(void) WEAK_ALIAS;
void SPI2_IRQHandler(void) WEAK_ALIAS;
void USART1_IRQHandler(void) WEAK_ALIAS;
void USART2_IRQHandler(void) WEAK_ALIAS;
void USART3_IRQHandler(void) WEAK_ALIAS;
void EXTI15_10_IRQHandler(void) WEAK_ALIAS;
void RTC_Alarm_IRQHandler(void) WEAK_ALIAS;
void OTG_FS_WKUP_IRQHandler(void) WEAK_ALIAS;
void TIM8_BRK_TIM12_IRQHandler(void) WEAK_ALIAS;
void TIM8_UP_TIM13_IRQHandler(void) WEAK_ALIAS;
void TIM8_TRG_COM_TIM14_IRQHandler(void) WEAK_ALIAS;
void TIM8_CC_IRQHandler(void) WEAK_ALIAS;
void DMA1_Stream7_IRQHandler(void) WEAK_ALIAS;
void FSMC_IRQHandler(void) WEAK_ALIAS;
void SDIO_IRQHandler(void) WEAK_ALIAS;
void TIM5_IRQHandler(void) WEAK_ALIAS;
void SPI3_IRQHandler(void) WEAK_ALIAS;
void UART4_IRQHandler(void) WEAK_ALIAS;
void UART5_IRQHandler(void) WEAK_ALIAS;
void TIM6_DAC_IRQHandler(void) WEAK_ALIAS;
void TIM7_IRQHandler(void) WEAK_ALIAS;
void DMA2_Stream0_IRQHandler(void) WEAK_ALIAS;
void DMA2_Stream1_IRQHandler(void) WEAK_ALIAS;
void DMA2_Stream2_IRQHandler(void) WEAK_ALIAS;
void DMA2_Stream3_IRQHandler(void) WEAK_ALIAS;
void DMA2_Stream4_IRQHandler(void) WEAK_ALIAS;
void ETH_IRQHandler(void) WEAK_ALIAS;
void ETH_WKUP_IRQHandler(void) WEAK_ALIAS;
void CAN2_TX_IRQHandler(void) WEAK_ALIAS;
void CAN2_RX0_IRQHandler(void) WEAK_ALIAS;
void CAN2_RX1_IRQHandler(void) WEAK_ALIAS;
void CAN2_SCE_IRQHandler(void) WEAK_ALIAS;
void OTG_FS_IRQHandler(void) WEAK_ALIAS;
void DMA2_Stream5_IRQHandler(void) WEAK_ALIAS;
void DMA2_Stream6_IRQHandler(void) WEAK_ALIAS;
void DMA2_Stream7_IRQHandler(void) WEAK_ALIAS;
void USART6_IRQHandler(void) WEAK_ALIAS;
void I2C3_EV_IRQHandler(void) WEAK_ALIAS;
void I2C3_ER_IRQHandler(void) WEAK_ALIAS;
void OTG_HS_EP1_OUT_IRQHandler(void) WEAK_ALIAS;
void OTG_HS_EP1_IN_IRQHandler(void) WEAK_ALIAS;
void OTG_HS_WKUP_IRQHandler(void) WEAK_ALIAS;
void OTG_HS_IRQHandler(void) WEAK_ALIAS;
void DCMI_IRQHandler(void) WEAK_ALIAS;
void CRYP_IRQHandler(void) WEAK_ALIAS;
void HASH_RNG_IRQHandler(void) WEAK_ALIAS;
void FPU_IRQHandler(void) WEAK_ALIAS;
 
void Reset_Handler(void)
{
    /* Step 1: copy the initial values of .data from Flash to RAM */
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata)
    {
        *dst = *src;
        dst++;
        src++;
    }
 
    /* Step 2: fill .bss with zeros */
    for (dst = &_sbss; dst < &_ebss; dst++)
    {
        *dst = 0U;
    }
 
    /* Step 3: early hardware set-up, then the real program */
    SystemInit();
    (void)main();
 
    /* main() should never return: stay here if it does */
    for (;;)
    {
    }
}
 
/* Any interrupt without its own handler ends up here. */
void Default_Handler(void)
{
    for (;;)
    {
    }
}
 
/* The vector table: 16 core entries + 82 STM32F407 interrupts = 98 words. */
__attribute__((section(".isr_vector"), used))
void (* const vector_table[])(void) =
{
    (void (*)(void))&_estack,   /* 0: initial stack pointer */
    Reset_Handler,              /* 1: reset */
    NMI_Handler,                /* 2: NMI */
    HardFault_Handler,          /* 3: HardFault */
    MemManage_Handler,          /* 4: MemManage */
    BusFault_Handler,           /* 5: BusFault */
    UsageFault_Handler,         /* 6: UsageFault */
    0,                          /* 7: reserved */
    0,                          /* 8: reserved */
    0,                          /* 9: reserved */
    0,                          /* 10: reserved */
    SVC_Handler,                /* 11: SVC */
    DebugMon_Handler,           /* 12: DebugMon */
    0,                          /* 13: reserved */
    PendSV_Handler,             /* 14: PendSV */
    SysTick_Handler,            /* 15: SysTick */
    WWDG_IRQHandler,            /* IRQ 0 */
    PVD_IRQHandler,             /* IRQ 1 */
    TAMP_STAMP_IRQHandler,      /* IRQ 2 */
    RTC_WKUP_IRQHandler,        /* IRQ 3 */
    FLASH_IRQHandler,           /* IRQ 4 */
    RCC_IRQHandler,             /* IRQ 5 */
    EXTI0_IRQHandler,           /* IRQ 6 */
    EXTI1_IRQHandler,           /* IRQ 7 */
    EXTI2_IRQHandler,           /* IRQ 8 */
    EXTI3_IRQHandler,           /* IRQ 9 */
    EXTI4_IRQHandler,           /* IRQ 10 */
    DMA1_Stream0_IRQHandler,    /* IRQ 11 */
    DMA1_Stream1_IRQHandler,    /* IRQ 12 */
    DMA1_Stream2_IRQHandler,    /* IRQ 13 */
    DMA1_Stream3_IRQHandler,    /* IRQ 14 */
    DMA1_Stream4_IRQHandler,    /* IRQ 15 */
    DMA1_Stream5_IRQHandler,    /* IRQ 16 */
    DMA1_Stream6_IRQHandler,    /* IRQ 17 */
    ADC_IRQHandler,             /* IRQ 18 */
    CAN1_TX_IRQHandler,         /* IRQ 19 */
    CAN1_RX0_IRQHandler,        /* IRQ 20 */
    CAN1_RX1_IRQHandler,        /* IRQ 21 */
    CAN1_SCE_IRQHandler,        /* IRQ 22 */
    EXTI9_5_IRQHandler,         /* IRQ 23 */
    TIM1_BRK_TIM9_IRQHandler,   /* IRQ 24 */
    TIM1_UP_TIM10_IRQHandler,   /* IRQ 25 */
    TIM1_TRG_COM_TIM11_IRQHandler,/* IRQ 26 */
    TIM1_CC_IRQHandler,         /* IRQ 27 */
    TIM2_IRQHandler,            /* IRQ 28 */
    TIM3_IRQHandler,            /* IRQ 29 */
    TIM4_IRQHandler,            /* IRQ 30 */
    I2C1_EV_IRQHandler,         /* IRQ 31 */
    I2C1_ER_IRQHandler,         /* IRQ 32 */
    I2C2_EV_IRQHandler,         /* IRQ 33 */
    I2C2_ER_IRQHandler,         /* IRQ 34 */
    SPI1_IRQHandler,            /* IRQ 35 */
    SPI2_IRQHandler,            /* IRQ 36 */
    USART1_IRQHandler,          /* IRQ 37 */
    USART2_IRQHandler,          /* IRQ 38 */
    USART3_IRQHandler,          /* IRQ 39 */
    EXTI15_10_IRQHandler,       /* IRQ 40 */
    RTC_Alarm_IRQHandler,       /* IRQ 41 */
    OTG_FS_WKUP_IRQHandler,     /* IRQ 42 */
    TIM8_BRK_TIM12_IRQHandler,  /* IRQ 43 */
    TIM8_UP_TIM13_IRQHandler,   /* IRQ 44 */
    TIM8_TRG_COM_TIM14_IRQHandler,/* IRQ 45 */
    TIM8_CC_IRQHandler,         /* IRQ 46 */
    DMA1_Stream7_IRQHandler,    /* IRQ 47 */
    FSMC_IRQHandler,            /* IRQ 48 */
    SDIO_IRQHandler,            /* IRQ 49 */
    TIM5_IRQHandler,            /* IRQ 50 */
    SPI3_IRQHandler,            /* IRQ 51 */
    UART4_IRQHandler,           /* IRQ 52 */
    UART5_IRQHandler,           /* IRQ 53 */
    TIM6_DAC_IRQHandler,        /* IRQ 54 */
    TIM7_IRQHandler,            /* IRQ 55 */
    DMA2_Stream0_IRQHandler,    /* IRQ 56 */
    DMA2_Stream1_IRQHandler,    /* IRQ 57 */
    DMA2_Stream2_IRQHandler,    /* IRQ 58 */
    DMA2_Stream3_IRQHandler,    /* IRQ 59 */
    DMA2_Stream4_IRQHandler,    /* IRQ 60 */
    ETH_IRQHandler,             /* IRQ 61 */
    ETH_WKUP_IRQHandler,        /* IRQ 62 */
    CAN2_TX_IRQHandler,         /* IRQ 63 */
    CAN2_RX0_IRQHandler,        /* IRQ 64 */
    CAN2_RX1_IRQHandler,        /* IRQ 65 */
    CAN2_SCE_IRQHandler,        /* IRQ 66 */
    OTG_FS_IRQHandler,          /* IRQ 67 */
    DMA2_Stream5_IRQHandler,    /* IRQ 68 */
    DMA2_Stream6_IRQHandler,    /* IRQ 69 */
    DMA2_Stream7_IRQHandler,    /* IRQ 70 */
    USART6_IRQHandler,          /* IRQ 71 */
    I2C3_EV_IRQHandler,         /* IRQ 72 */
    I2C3_ER_IRQHandler,         /* IRQ 73 */
    OTG_HS_EP1_OUT_IRQHandler,  /* IRQ 74 */
    OTG_HS_EP1_IN_IRQHandler,   /* IRQ 75 */
    OTG_HS_WKUP_IRQHandler,     /* IRQ 76 */
    OTG_HS_IRQHandler,          /* IRQ 77 */
    DCMI_IRQHandler,            /* IRQ 78 */
    CRYP_IRQHandler,            /* IRQ 79 */
    HASH_RNG_IRQHandler,        /* IRQ 80 */
    FPU_IRQHandler,             /* IRQ 81 */
};
