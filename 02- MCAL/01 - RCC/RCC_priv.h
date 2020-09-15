/*
 * Description: RCC (reset and clock control) driver
 * Author : Mustafa Askar
 * Date : 08/08/2020
 * Version : V3.0
 * Changelog:
 * 			1. Added "ON" and "OFF" definitions
 * 			2. Added overall protection over configurations files
 * 			3. Fixed PLL multiplier won't change bug
 */

#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_

/* Register definitions*/
#define RCC_CR				*((volatile u32*)0x40021000)
#define RCC_CFGR			*((volatile u32*)0x40021004)
#define RCC_CIR				*((volatile u32*)0x40021008)
#define RCC_APB2RSTR		*((volatile u32*)0x4002100C)
#define RCC_APB1RSTR		*((volatile u32*)0x40021010)
#define RCC_AHBENR			*((volatile u32*)0x40021014)
#define RCC_APB2ENR			*((volatile u32*)0x40021018)
#define RCC_APB1ENR			*((volatile u32*)0x4002101C)
#define RCC_BDCR			*((volatile u32*)0x40021020)
#define RCC_CSR				*((volatile u32*)0x40021024)

/*General definitions*/
#define ON 					1
#define OFF 				0

/*System clock configurations*/
#define RCC_HSI 			0
#define RCC_HSE_CRYSTAL 	1
#define RCC_PLL 			2
#define RCC_HSE_RC 			3

/*PLL inputs*/
#define RCC_HSI_DIV_2		0
#define RCC_HSE				1
#define RCC_HSE_DIV_2		2

#endif /* RCC_PRIV_H_ */
