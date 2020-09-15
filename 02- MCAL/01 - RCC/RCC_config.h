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

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
/*System clock configurations*/



/*	System clock source
 * 	Options : 			RCC_HSE_CRYSTAL		External crystal clock
 * 						RCC_HSE_RC			External RC clock
 * 						RCC_HSI				Internal 8Mhz RC clock
 * 						RCC_PLL				PLL (WARNING: you need to configure PLL down below)
 */
#define RCC_SYS_CLOCK_TYPE 		RCC_HSE




/*You need to enable the system clock and any other clock you might need
 * Options : 			ON					Enabled
 * 						OFF 				DISABLED
 */
#define RCC_ENABLE_HSI 			OFF
#define RCC_ENABLE_HSE 			ON
#define RCC_ENABLE_PLL 			OFF




//NOTE: Don't change if you're not on PLL
#if RCC_ENABLE_PLL == ON

/* 	PLL source
 * 	Options : 			RCC_HSE				external clock
 * 						RCC_HSI_DIV_2		internal clock / 2
 * 						RCC_HSE_DIV_2 		external clock / 2
 */
#define RCC_PLL_INPUT			RCC_HSE



//NOTE: Don't change if you're not on PLL
/*	PLL multiplier (WARNING: total frequency cannot exceed 72Mhz
 * 						Range 				 from 2 to 16
 */
#define RCC_PLL_MUL 			2
#endif




/*	Clock security system: if external clock fails,
 *	it'll switch automatically to integral and fire an interrupt
 *	Options : 			ON					Enabled
 *						OFF 				Disabled
 */
#define RCC_ENABLE_CSS 			OFF





/*	uc output pin: it'll out a system clock on MCO pin
 * 	Options : 			ON					Enabled
 *						OFF 				Disabled
 */
#define RCC_ENABLE_MCO 			OFF




#endif /* RCC_CONFIG_H_ */
