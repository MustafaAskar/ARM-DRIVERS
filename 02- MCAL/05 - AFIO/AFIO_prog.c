/*
 * Description: AFIO (alternate function input output) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V2.0
 * Changelog:
 *			-Improved performance
 */
#include"std_types.h"
#include"bit_math.h"
#include"AFIO_priv.h"
#include"AFIO_interface.h"
#include"AFIO_config.h"

void AFIO_voidSetExternalInterruptPort(u8 Copy_u8Line, u8 Copy_u8Port)
{
	if(Copy_u8Line<=3)
	{
		AFIO_EXTICR1  &= ~((0b1111<<(Copy_u8Line*4)));
		AFIO_EXTICR1  |= ((Copy_u8Port<(Copy_u8Line*4)));
	}
	else if(Copy_u8Line<=7)
	{
		Copy_u8Line -= 4;
		AFIO_EXTICR2  &= ~((0b1111<<(Copy_u8Line*4)));
		AFIO_EXTICR2  |= ((Copy_u8Port<(Copy_u8Line*4)));
	}
	else if(Copy_u8Line<=11)
	{
		Copy_u8Line -= 8;
		AFIO_EXTICR3  &= ~((0b1111<<(Copy_u8Line*4)));
		AFIO_EXTICR3  |= ((Copy_u8Port<(Copy_u8Line*4)));
	}
	else if(Copy_u8Line<=15)
	{
		Copy_u8Line -= 12;
		AFIO_EXTICR4  &= ~(0b1111<<(Copy_u8Line*4));
		AFIO_EXTICR4  |= ((Copy_u8Port<(Copy_u8Line*4)));
	}


}

