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

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/*public functions prototypes*/
void RCC_voidInitSystemClock(void); 							//Initialize system clock
void RCC_voidEnablePreph(u8 Copy_u8BusId, u8 Copy_u8PrephId); 	//enable clock for peripherals
void RCC_voidDisablePreph(u8 Copy_u8BusId, u8 Copy_u8PrephId); 	//disable clock for peripherals



/*Bus ids*/

#define RCC_AHB 	0
#define RCC_APB1 	1
#define RCC_APB2 	2



#endif /* RCC_INTERFACE_H_ */
