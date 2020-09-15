/*
 * Description: IR (infra-red communication system) driver
 * Author : Mustafa Askar
 * Date : 02/09/2020
 * Version : V1.0
 * Changelog:
 */

#include"std_types.h"
#include"bit_math.h"
#include"NVIC_interface.h"
#include"EXTI_interface.h"
#include"STK_interface.h"
#include"IR_interface.h"

volatile u8 Global_u8Flag;
volatile u32 Global_u32FrameData [34];
volatile u8 Global_u8EdgeCounter;
volatile u8 Local_u8Counter;
volatile u8 Global_u8Data = 255; //choosing a value that will never be find on a remote


/*
 * WARNING:
 * 			You must initialize IR before EXTI otherwise a hard fault will happen
 */
void IR_voidInit(void)
{
	//Initialize interrupt handler
	EXTI0_voidInitIRQHandler(Local_GetData);
}

void Local_GetData(void)
{
	if(Global_u8Flag == 0)
	{
		Global_u8Flag = 1;
		STK_voidSetIntervalSingle(30000,Local_DataAnalysis);
	}
	else
	{
		Global_u32FrameData[Global_u8EdgeCounter] = STK_u32GetElapsedTime();
		STK_voidSetIntervalSingle(30000,Local_DataAnalysis);
		Global_u8EdgeCounter++;
	}
}

void Local_DataAnalysis(void)
{
	volatile u8 Local_u8Counter;
	for(Local_u8Counter = 0; Local_u8Counter<8; Local_u8Counter++)
	{
		if(Global_u32FrameData[17+Local_u8Counter]>2000 && Global_u32FrameData[17+Local_u8Counter]<3000)
		{
			SET_BIT(Global_u8Data,Local_u8Counter);
		}
		else
		{
			CLEAR_BIT(Global_u8Data,Local_u8Counter);
		}
	}

	Global_u8EdgeCounter = 0;
	Global_u32FrameData[0] = 0;
	Global_u8Flag = 0;

}

void IR_voidGetButton(u8* Copy_u8Button)
{
	*Copy_u8Button = Global_u8Data;
}
