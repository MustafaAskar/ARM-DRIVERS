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

#include "std_types.h"
#include "bit_math.h"
#include "GPIO_interface.h"
#include "GPIO_priv.h"
#include "GPIO_config.h"

/*
 * WARNING :
 * 			You must choose GPIO_INPUT_PULL_DOWN or GPIO_INPUT_PULL_UP
 * 			and set pin bit in output register to choose input mode.
 * 			High 	: to access pull down
 * 			Low 	: to access pull up
 */
void 	GPIO_voidSetPinMode		(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
					if(Copy_u8Pin<=7)
					{
						//reseting the pins before assigning new value to it
						GPIOA_CRL &= ~(0b1111<<(Copy_u8Pin*4));
						GPIOA_CRL = GPIOA_CRL|(Copy_u8Mode<<(Copy_u8Pin*4));
					}
					else if(Copy_u8Pin<=15)
					{
						Copy_u8Pin = Copy_u8Pin - 8; //accessing the high part of the register

						//reseting the pins before assigning new value to it
						GPIOA_CRH &= ~(0b1111<<(Copy_u8Pin*4));
						GPIOA_CRH = GPIOA_CRL|(Copy_u8Mode<<(Copy_u8Pin*4));
					}
					break;

		case GPIOB:
					if(Copy_u8Pin<=7)
					{
						//reseting the pins before assigning new value to it
						GPIOB_CRL &= ~(0b1111<<(Copy_u8Pin*4));
						GPIOB_CRL = GPIOB_CRL|(Copy_u8Mode<<(Copy_u8Pin*4));
					}
					else if(Copy_u8Pin<=15)
					{
						Copy_u8Pin -=8;	//accessing the high part of the register

						//reseting the pins before assigning new value to it
						GPIOB_CRH &= ~(0b1111<<(Copy_u8Pin*4));
						GPIOB_CRH = GPIOB_CRH|(Copy_u8Mode<<(Copy_u8Pin*4));
					}
					break;

		case GPIOC:
					if(Copy_u8Pin<=7)
					{
						//reseting the pins before assigning new value to it
						GPIOC_CRL &= ~(0b1111<<(Copy_u8Pin*4));
						GPIOC_CRL = GPIOC_CRL|(Copy_u8Mode<<(Copy_u8Pin*4));
					}
					else if(Copy_u8Pin<=15)
					{
						Copy_u8Pin -=8;	//accessing the high part of the register

						//reseting the pins before assigning new value to it
						GPIOC_CRH &= ~(0b1111<<(Copy_u8Pin*4));
						GPIOC_CRH = GPIOC_CRH|(Copy_u8Mode<<(Copy_u8Pin*4));
					}
					break;
	}

}

/*
 * WARNING :
 * 			GPIO_voidSetPinVal doesn't have value check for Copy_u8Pin to improve performance. Use it with caution.
 */
void 	GPIO_voidSetPinVal		(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if(Copy_u8Val == HIGH)
			{
				GPIOA_BSRR = (1<<Copy_u8Pin); //accessing BSRR register for improved performance

				//SET_BIT(GPIOA_ODR,Copy_u8Pin);
			}
			else if (Copy_u8Val == LOW)
			{
				GPIOA_BRR = (1<<Copy_u8Pin); //accessing BRR register for improved performance

				//CLEAR_BIT(GPIOA_ODR,Copy_u8Pin);
			}
					break;

		case GPIOB:
			if(Copy_u8Val == HIGH)
			{
				GPIOB_BSRR = (1<<Copy_u8Pin); //accessing BSRR register for improved performance

				//SET_BIT(GPIOB_ODR,Copy_u8Pin);
			}
			else if (Copy_u8Val == LOW)
			{
				GPIOB_BRR = (1<<Copy_u8Pin); //accessing BRR register for improved performance

				//CLEAR_BIT(GPIOB_ODR,Copy_u8Pin);
			}
					break;

		case GPIOC:
			if(Copy_u8Val == HIGH)
			{
				GPIOC_BSRR = (1<<Copy_u8Pin); //accessing BSRR register for improved performance

				//SET_BIT(GPIOC_ODR,Copy_u8Pin);
			}
			else if (Copy_u8Val == LOW)
			{
				GPIOC_BRR = (1<<Copy_u8Pin); //accessing BRR register for improved performance

				//CLEAR_BIT(GPIOC_ODR,Copy_u8Pin);
			}
					break;
	}

}


void 	GPIO_voidAssignPortVal(u8 Copy_u8Port, u32 Copy_u8Val) //direct access to output register
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			GPIOA_ODR = Copy_u8Val;
					break;

		case GPIOB:
			GPIOB_ODR = Copy_u8Val;
					break;

		case GPIOC:
			GPIOC_ODR = Copy_u8Val;
					break;
	}

}


u8 		GPIO_u8GetPinVal 		(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 LOC_u8PinVal = 0;
	switch(Copy_u8Port)
	{
		case GPIOA:
			LOC_u8PinVal = (GPIOA_IDR>>Copy_u8Pin)&0x1;
					break;

		case GPIOB:
			LOC_u8PinVal = (GPIOB_IDR>>Copy_u8Pin)&0x1;
					break;

		case GPIOC:
			LOC_u8PinVal = (GPIOC_IDR>>Copy_u8Pin)&0x1;
					break;
	}

	return LOC_u8PinVal;
}



void 	GPIO_voidTogglePinVal(u8 Copy_u8Port, u8 Copy_u8Pin) //toggle pin value
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			TOGGLE_BIT(GPIOA_ODR,Copy_u8Pin);
					break;

		case GPIOB:
			TOGGLE_BIT(GPIOB_ODR,Copy_u8Pin);
					break;

		case GPIOC:
			TOGGLE_BIT(GPIOC_ODR,Copy_u8Pin);
					break;
	}

}
