/*
 * Description: LEDMATRIX (LED matrix) driver
 * Author : Mustafa Askar
 * Date : 12/09/2020
 * Version : V1.0
 * Changelog:
 */

#include"std_types.h"
#include"bit_math.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"GPIO_priv.h"
#include"STK_interface.h"
#include"LEDMATRIX_interface.h"
#include"LEDMATRIX_config.h"

u8* Global_u8FrameStart;
u8 Global_u8State;
void LEDMATRIX_voidInit(void)
{
	//Initialize GPIO
	GPIO_voidSetPinMode(MATRIX_ROW_PORT,PIN0,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_ROW_PORT,PIN1,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_ROW_PORT,PIN2,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_ROW_PORT,PIN3,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_ROW_PORT,PIN4,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_ROW_PORT,PIN5,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_ROW_PORT,PIN6,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_ROW_PORT,PIN7,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_COL_PORT,PIN8,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_COL_PORT,PIN9,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_COL_PORT,PIN10,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_COL_PORT,PIN11,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_COL_PORT,PIN12,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_COL_PORT,PIN13,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_COL_PORT,PIN14,GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(MATRIX_COL_PORT,PIN15,GPIO_OUTPUT_10MHZ_PP);

	//disable all columns
	GPIO_voidAssignPortVal(MATRIX_COL_PORT,0x0000ff00);
}

void LEDMATRIX_voidDisplay(u8* Copy_u8Frame, u8 Copy_u8FrameSize)
{
	static u8 Local_u8PtrINCCounter = 0;
	static u8 Local_u8Counter;
	static u8 Local_u8Delay;
	u8 Local_u8FrameEnd = (Copy_u8FrameSize-8);

	do
	{
		//outer loop for delaying, displaying the same character number of times
		for(Local_u8Delay = 0; Local_u8Delay<12; Local_u8Delay++)
		{
			for(Local_u8Counter = 0; Local_u8Counter<8; Local_u8Counter++)
			{
				GPIOA_ODR &= ~(0xff);
				GPIOA_ODR |= Copy_u8Frame[Local_u8Counter];
				GPIO_voidSetPinVal(GPIOB,(Local_u8Counter+8),LOW);
				STK_voidSetBusyWait(2500);
				GPIO_voidSetPinVal(GPIOB,(Local_u8Counter+8),HIGH);
			}
		}
		Copy_u8Frame = Copy_u8Frame+1;
		Local_u8PtrINCCounter++;
	}while(Local_u8PtrINCCounter< Local_u8FrameEnd);

}

