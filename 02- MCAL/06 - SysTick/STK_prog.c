/*
 * Description: STK (system tick timer) driver
 * Author : Mustafa Askar
 * Date : 02/09/2020
 * Version : V2.0
 * Changelog:
 * 			-Added synchronous and asynchronous option
 * 			-Added Callback option
 * 			-Added periodic and single interval option
 * 			-Added elapsed and remaining time
 */

#include "std_types.h"
#include "bit_math.h"
#include "register.h"
#include "STK_priv.h"
#include "STK_interface.h"
#include "STK_config.h"


u8 Global_u8SetIntervalSingle;
void(*Global_voidCallback)(void);


/* Disable interrupt
 * Disable timer
 * Choose clock source
 */
void STK_voidInit(void)
{
	STK_CTRL->bits.bit2 = STK_CLOCK_SOURC;
}

void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	//Set timer ticks
	STK_LOAD->port = Copy_u32Ticks;

	//Enable timer
	STK_CTRL->bits.bit0 = 1;

	//Pool over the clock count flag
	while(STK_CTRL->bits.bit16 == 0);

	//Stop timer
	STK_LOAD->port = 0;
	STK_VAL->port = 0;
	STK_CTRL->bits.bit0 = 0;

}

void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void(*Copy_voidFunction)(void))
{
	//Set interval as single
	Global_u8SetIntervalSingle = 1;

	//Initialize callback
	Global_voidCallback = Copy_voidFunction;

	//Set timer ticks
	STK_LOAD->port = Copy_u32Ticks;

	//Enable interrupt
	STK_CTRL->bits.bit1 = 1;

	//Enable timer
	STK_CTRL->bits.bit0 = 1;


}

void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void(*Copy_voidFunction)(void))
{
	//Initialize callback
	Global_voidCallback = Copy_voidFunction;

	//Set interval as periodic
	Global_u8SetIntervalSingle = 0;

	//Set timer ticks
	STK_LOAD->port = Copy_u32Ticks;

	//Enable interrupt
	STK_CTRL->bits.bit1 = 1;

	//Enable timer
	STK_CTRL->bits.bit0 = 1;

}

void STK_voidStopTimer(void)
{
	//Stop timer
	STK_LOAD->port = 0;
	STK_VAL->port = 0;
	STK_CTRL->bits.bit0 = 0;
}


u32 STK_u32GetElapsedTime(void)
{
	return(STK_LOAD->port - STK_VAL->port);
}

u32 STK_u32GetRemainingTime(void)
{
	return(STK_VAL->port);
}

void SysTick_Handler(void)
{
	u8 Local_u8Temp;

	if(Global_u8SetIntervalSingle == 1)
	{
		//Disable interrupt
		STK_CTRL->bits.bit1 = 0;

		//Stop timer
		STK_LOAD->port = 0;
		STK_VAL->port = 0;
		STK_CTRL->bits.bit0 = 0;
	}

	//callback accessing
	Global_voidCallback();

	//Reading flag
	Local_u8Temp = STK_CTRL->bits.bit16;
}

