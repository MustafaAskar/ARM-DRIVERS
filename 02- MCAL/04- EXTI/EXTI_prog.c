/*
 * Description: EXINT (external interrupt) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V2.0
 * Changelog:
 *			-Added callback option
 *			-Fixed pending flag bug
 */

#include"std_types.h"
#include"bit_math.h"
#include"register.h"
#include "EXTI_priv.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

void(*Global_voidCallbackHandler)(void);

void EXTI_voidInit(void)
{
	SET_BIT(EXTI_IMR->port,EXTI_LINE); //enabling interrupt line

/*choosing sensing mode*/
#if EXTI_MODE == EXTI_RISING
	SET_BIT(EXTI_RTSR->port,EXTI_LINE);

#elif EXTI_MODE == EXTI_FALLING
	SET_BIT(EXTI_FTSR->port,EXTI_LINE);

#elif EXTI_MODE == EXTI_ON_CHANGE
	SET_BIT(EXTI_RTSR->port,EXTI_LINE);
	SET_BIT(EXTI_FTSR->port,EXTI_LINE);

#else
	#error "EXTI_MODE: You choose wrong value"

#endif
}


void EXTI_voidEnableInt(u8 Copy_u8Line)
{
	SET_BIT(EXTI_IMR->port,Copy_u8Line);
}

void EXTI_voidDisableInt(u8 Copy_u8Line)
{
	CLEAR_BIT(EXTI_IMR->port,Copy_u8Line);
}

void EXTI_voidSetMode(u8 Copy_u8Line, u8 Copy_u8Mode) //set sensing mode for interrupt line
{
	switch(Copy_u8Mode)
	{
	case EXTI_RISING:
		SET_BIT(EXTI_RTSR->port,Copy_u8Line);
		CLEAR_BIT(EXTI_FTSR->port,Copy_u8Line);
		break;
	case EXTI_FALLING:
		SET_BIT(EXTI_FTSR->port,Copy_u8Line);
		CLEAR_BIT(EXTI_RTSR->port,Copy_u8Line);
		break;
	case EXTI_ON_CHANGE:
		SET_BIT(EXTI_FTSR->port,Copy_u8Line); //enabling both rising and falling edge cause on change interrupt
		SET_BIT(EXTI_RTSR->port,Copy_u8Line);
		break;
	}
}

void EXTI_voidSWInt(u8 Copy_u8Line) //simulate interrupt for debugging purposes
{
	SET_BIT(EXTI_SWIER->port,Copy_u8Line);
}

void EXTI0_voidInitIRQHandler(void(*Copy_voidFunction)(void))
{
	Global_voidCallbackHandler = Copy_voidFunction;
}

void EXTI0_IRQHandler(void)
{
	Global_voidCallbackHandler();
	EXTI_PR->bits.bit0 = 1;
}
