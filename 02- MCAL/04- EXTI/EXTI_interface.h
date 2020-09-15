/*
 * Description: EXINT (external interrupt) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V2.0
 * Changelog:
 *			-Added callback option
 *			-Fixed pending flag bug
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*public functions*/

void EXTI_voidInit				(void);
void EXTI_voidEnableInt			(u8 Copy_u8Line);
void EXTI_voidDisableInt		(u8 Copy_u8Line);
void EXTI_voidSetMode			(u8 Copy_u8Line, u8 Copy_u8Mode); //set sensing mode for interrupt line
void EXTI_voidSWInt				(u8 Copy_u8Line); //simulate interrupt for debugging purposes
void EXTI0_voidInitIRQHandler	(void(*Copy_voidFunction)(void));




/*EXIT enable and disable macros*/
#define EXTI_LINE0				0
#define EXTI_LINE1				1
#define EXTI_LINE2				2
#define EXTI_LINE3				3
#define EXTI_LINE4				4


#define EXTI_RISING 			0
#define EXTI_FALLING			1
#define EXTI_ON_CHANGE 			2



#endif /* EXTI_INTERFACE_H_ */
