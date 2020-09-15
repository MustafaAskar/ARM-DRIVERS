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

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/*NVIC public functions*/

void NVIC_voidInit(void); //initialize interrupts
void NVIC_voidEnableInterrupt		(u8 Copy_u8InterruptNumber);
void NVIC_voidDisableInterrupt		(u8 Copy_u8InterruptNumber);
void NVIC_voidSetPendingFlag 		(u8 Copy_u8InterruptNumber); 	//set pending flag to simulate interrupt. for debugging purpose
void NVIC_voidClearPendingFlag 		(u8 Copy_u8InterruptNumber);	//clear pending flag. for debugging purpose
u8 NVIC_u8CheckActiveFlag 			(u8 Copy_u8InterruptNumber);	//check on active flag to see whether the interrupt is being served or not
void NVIC_voidSetInterruptPriority	(s8 Copy_u8InterruptNumber, u8 Copy_u8InterruptGroupPriority, u8 Copy_u8InterruptSubGroupPriority);





#endif /* NVIC_INTERFACE_H_ */
