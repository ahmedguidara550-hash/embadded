#include <stdint.h>

/*adresses taken from the STM32F407 reference manual(RM0090)*/
#define RCC_AHB1ENR (*(volatile uint32_t *)0x40023830U) /*RCC base 0x40023800 + 0x30*/
#define GPIOD_MODER (*(volatile uint32_t *)0x40020C00U) /*GPIOD base 0x40020C00 + 0x00*/
#define GPIOD_ODR (*(volatile uint32_t *)0x40020C14U) /*GPIOD base 0x40020C00 + 0x14*/
//#define GPIOD_BSRR (*(volatile uint32_t *)0x40020C18U)

static void delay(volatile uint32_t count){
    while (count > 0U){
        count--;
    }
}
int main(void){
    RCC_AHB1ENR |=(1U << 3); /*bit 3 = GPIODEN: switch on the clock of port D*/
    //GPIOD_MODER &= ~(3U << (12 * 2)); /*clear the 2 mode bits of pin 12*/
    //GPIOD_MODER |= (1U << (12 * 2)); /*01 = general purpose output*/
    GPIOD_MODER &= ~((3U << (12 * 2)) | (3U << (15 * 2)));   /* clear both fields */
    GPIOD_MODER |=   (1U << (12 * 2)) | (1U << (15 * 2));    /* 01 = output, both */

    for(;;){
        //GPIOD_ODR ^= (1U << 12); /*toggle pin 12: the green LED*/
        //delay(400000U);
        GPIOD_ODR ^= (1U << 12) | (1U << 15);                /* both LEDs together */
        delay(400000U);
        //GPIOD_BSRR = (1U << 12) | (1U << (15 + 16));   /* = 0x80001000 */
    }
}