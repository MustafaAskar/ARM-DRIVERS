/*
 * Description: AFIO (alternate function input output) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V2.0
 * Changelog:
 *			-Improved performance
 */

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

/*public functions*/
void AFIO_voidSetExternalInterruptPort(u8 Copy_u8Line, u8 Copy_u8Port);


/*line mapping*/
#define EXTI_LINE0				0
#define EXTI_LINE1				1
#define EXTI_LINE2				2
#define EXTI_LINE3				3
#define EXTI_LINE4				4



/*port mapping*/
#define AFIO_PORTA				0
#define AFIO_PORTB				1
#define AFIO_PORTC				2


#endif /* AFIO_INTERFACE_H_ */
