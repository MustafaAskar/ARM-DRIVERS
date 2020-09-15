/*
 * Description: NVIC (nested vector interrupt controller) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V3.0
 * Changelog:
 * 				-Added NVIC_init() function to initialize interrupts
 * 				-Added priority control functions
 * 				-Fixed a bug in NVIC addresses
 */

#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

/*
 * NVIC priority binary point (format)
 * X : for group bit field
 * Y : for subgroup bit field
 * Options:
 * 			-XXXX		Four bits for group, none for sub
 * 			-XXXY		three bits for group, one for sub
 * 			-XXYY		two bits for group, two for sub
 * 			-XYYY		one bit for group, three for sub
 * 			-YYYY		none for group, four bits for sub
 */

#define NVIC_PRIORITY_DISTRIBUTION			XXYY




#endif /* NVIC_CONFIG_H_ */
