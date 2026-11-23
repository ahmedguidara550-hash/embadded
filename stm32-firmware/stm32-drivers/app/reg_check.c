/* Compile-time check: do the addresses we read in the reference manual match
 * the official header files? If one number is wrong, the build FAILS. */
#include <stddef.h>
#include "stm32f4xx.h"
 
/*_Static_assert(RCC_BASE == 0x40023900UL,"RCC base address"); sabotage it*/
_Static_assert(RCC_BASE == 0x40023800UL,"RCC base address");
_Static_assert(offsetof(RCC_TypeDef, AHB1ENR) == 0x30U,"RCC_AHB1ENR offset");
_Static_assert(RCC_AHB1ENR_GPIODEN_Pos == 3U,"GPIODEN is bit 3");
 
_Static_assert(GPIOD_BASE == 0x40020C00UL,"GPIOD base address");
_Static_assert(offsetof(GPIO_TypeDef, MODER) == 0x00U,"GPIOx_MODER offset");
_Static_assert(offsetof(GPIO_TypeDef, ODR)   == 0x14U,"GPIOx_ODR offset");
_Static_assert(offsetof(GPIO_TypeDef, BSRR)  == 0x18U,"GPIOx_BSRR offset");
 
int main(void)
{
    return 0;                         /* nothing to run: the checks happen while compiling */
}
