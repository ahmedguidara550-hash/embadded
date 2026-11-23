#include "stm32f4xx.h"

static void delay(volatile uint32_t count){
    while (count > 0U){
        count--;
    }
}

int main(void){
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; /*clock for port D*/
    GPIOD->MODER &= ~GPIO_MODER_MODER12; /*clear the mode bits of pin 12*/
    GPIOD->MODER |= GPIO_MODER_MODER12_0; /* 01 = output*/

    for(;;){
        GPIOD->BSRR = GPIO_BSRR_BS12; /*set pin 12 (LED on)*/
        delay(400000U);
        GPIOD->BSRR = GPIO_BSRR_BR12; /*reset pin 12 (LED off)*/
        delay(400000U);
    }
}