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

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*public functions*/

void 	GPIO_voidSetPinMode		(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void 	GPIO_voidSetPinVal		(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val);
void 	GPIO_voidAssignPortVal(u8 Copy_u8Port, u32 Copy_u8Val); //direct access to output register
void 	GPIO_voidTogglePinVal(u8 Copy_u8Port, u8 Copy_u8Pin); //toggle pin value
u8 		GPIO_u8GetPinVal 		(u8 Copy_u8Port, u8 Copy_u8Pin);


/*pins ids*/

#define PIN0 		0
#define PIN1 		1
#define PIN2 		2
#define PIN3 		3
#define PIN4 		4
#define PIN5 		5
#define PIN6 		6
#define PIN7 		7
#define PIN8 		8
#define PIN9 		9
#define PIN10 		10
#define PIN11 		11
#define PIN12 		12
#define PIN13 		13
#define PIN14 		14
#define PIN15 		15

/*ports ids*/

#define GPIOA		0
#define GPIOB		1
#define GPIOC		2

/*general definitions*/

#define HIGH 		1
#define LOW 		0

/*GPIO modes*/

/*input modes*/
#define GPIO_INPUT_ANALOG 		0b0000
#define GPIO_INPUT_FLOATING		0b0100
#define GPIO_INPUT_PULL_UP 		0b1000
#define GPIO_INPUT_PULL_DOWN 	0b1000

/*output modes*/
#define GPIO_OUTPUT_10MHZ_PP	0b0001
#define GPIO_OUTPUT_10MHZ_OD	0b0101
#define GPIO_OUTPUT_10MHZ_AFPP	0b1001
#define GPIO_OUTPUT_10MHZ_AFOD	0b1101

#define GPIO_OUTPUT_2MHZ_PP		0b0010
#define GPIO_OUTPUT_2MHZ_OD		0b0110
#define GPIO_OUTPUT_2MHZ_AFPP	0b1010
#define GPIO_OUTPUT_2MHZ_AFOD	0b1110

#define GPIO_OUTPUT_50MHZ_PP	0b0011
#define GPIO_OUTPUT_50MHZ_OD	0b0111
#define GPIO_OUTPUT_50MHZ_AFPP	0b1011
#define GPIO_OUTPUT_50MHZ_AFOD	0b1111







#endif /* GPIO_INTERFACE_H_ */
