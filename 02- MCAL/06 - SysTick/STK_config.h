/*
 * Description: STK (system tick timer) driver
 * Author : Mustafa Askar
 * Date : 02/09/2020
 * Version : V2.0
 * Changelog:
 * 			-Added synchronous and asynchronous option
 * 			-Added Callback option
 * 			-Added periodic and single interval option
 * 			-Added elapsed and remaining time
 */

#ifndef STK_CONFIG_H_
#define STK_CONFIG_H_



/*
 * Choose system timer clock source
 * Options:
 * 			STK_AHB_DIV_8	: AHB bus clock /8
 * 			STK_AHB			: AHB bus clock
 */
#define STK_CLOCK_SOURC			STK_AHB_DIV_8




#endif /* STK_CONFIG_H_ */
