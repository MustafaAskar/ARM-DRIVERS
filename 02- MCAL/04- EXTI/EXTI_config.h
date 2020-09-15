/*
 * Description: EXINT (external interrupt) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V2.0
 * Changelog:
 *			-Added callback option
 *			-Fixed pending flag bug
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Initialization configurations*/

/*enable interrupt line
 * Options:
 * 			EXTI_LINE0 : EXTI_LINE4
 */
#define EXTI_LINE		 	EXTI_LINE0


/*Choosing interrupt sensing mode
 * Options:
 * 			EXTI_RISING		: On rising edge
 * 			EXIT_FALLING	: On falling edge
 * 			EXIT_ON_CHANGE 	: On any logical change
 */
#define EXTI_MODE 			EXTI_FALLING


#endif /* EXTI_CONFIG_H_ */
