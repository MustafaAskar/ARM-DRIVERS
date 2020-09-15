/*
 * Description: GPIO (general purpose input output) driver
 * Author : Mustafa Askar
 * Date : 12/08/2020
 * Version : V4.0
 * Changelog:
 * 				- Improved performance using BSRR and BRR registers instead of ODR
 * 				- Added GPIO_AssignDirectVal() function to the driver
 *				- Added GPIO_voidTogglePinVal(u8 Copy_u8Port, u8 Copy_u8Pin) function to the driver
 *				- Fixed a bug in the high nibble of register b and c
 *				- Fixed a bug in GPIO_voidAssignVal()
 */

#ifndef GPIO_PRIV_H_
#define GPIO_PRIV_H_

/*GPIOs base addresses*/

#define GPIOA_BASE_REGISTER 	0x40010800
#define GPIOB_BASE_REGISTER 	0x40010C00
#define GPIOC_BASE_REGISTER 	0x40011000

/*GPIOs registers*/

#define GPIOA_CRL			*((u32*)(GPIOA_BASE_REGISTER+0x00))
#define GPIOA_CRH			*((u32*)(GPIOA_BASE_REGISTER+0x04))
#define GPIOA_IDR			*((u32*)(GPIOA_BASE_REGISTER+0x08))
#define GPIOA_ODR			*((u32*)(GPIOA_BASE_REGISTER+0x0C))
#define GPIOA_BSRR			*((u32*)(GPIOA_BASE_REGISTER+0x10))
#define GPIOA_BRR			*((u32*)(GPIOA_BASE_REGISTER+0x14))
#define GPIOA_LCKR			*((u32*)(GPIOA_BASE_REGISTER+0x18))

#define GPIOB_CRL			*((u32*)(GPIOB_BASE_REGISTER+0x00))
#define GPIOB_CRH			*((u32*)(GPIOB_BASE_REGISTER+0x04))
#define GPIOB_IDR			*((u32*)(GPIOB_BASE_REGISTER+0x08))
#define GPIOB_ODR			*((u32*)(GPIOB_BASE_REGISTER+0x0C))
#define GPIOB_BSRR			*((u32*)(GPIOB_BASE_REGISTER+0x10))
#define GPIOB_BRR			*((u32*)(GPIOB_BASE_REGISTER+0x14))
#define GPIOB_LCKR			*((u32*)(GPIOB_BASE_REGISTER+0x18))

#define GPIOC_CRL			*((u32*)(GPIOC_BASE_REGISTER+0x00))
#define GPIOC_CRH			*((u32*)(GPIOC_BASE_REGISTER+0x04))
#define GPIOC_IDR			*((u32*)(GPIOC_BASE_REGISTER+0x08))
#define GPIOC_ODR			*((u32*)(GPIOC_BASE_REGISTER+0x0C))
#define GPIOC_BSRR			*((u32*)(GPIOC_BASE_REGISTER+0x10))
#define GPIOC_BRR			*((u32*)(GPIOC_BASE_REGISTER+0x14))
#define GPIOC_LCKR			*((u32*)(GPIOC_BASE_REGISTER+0x18))




#endif /* GPIO_PRIV_H_ */
