/*
 * Description: RCC (reset and clock control) driver
 * Author : Mustafa Askar
 * Date : 08/08/2020
 * Version : V3.0
 * Changelog:
 * 			1. Added "ON" and "OFF" definitions
 * 			2. Added overall protection over configurations files
 * 			3. Fixed PLL multiplier won't change bug
 */

#include"std_types.h"
#include"bit_math.h"
#include"RCC_interface.h"
#include"RCC_priv.h"
#include"RCC_config.h"

void RCC_voidInitSystemClock(void) //Initialize system clock
{
	/*WARNING:
	 * Default clock for the system is PLL with its input source 8Mhz
	 * from the HSE. You need to switch to HSI first and disable PLL
	 * to confirm any change you make to the PLL
	 */
	RCC_CFGR = 0x0;						//switching to HSI
	CLEAR_BIT(RCC_CR,24);				// disabling PLL

	/*internal clock*/
	/*enabling section*/
	#if RCC_ENABLE_HSI == ON
		SET_BIT(RCC_CR, 0);				//enabling internal clock
	#elif RCC_ENABLE_HSI == OFF
		CLEAR_BIT(RCC_CR, 0);			//disabling internal clock
	#else
		#error RCC_Config: You choose wrong choice at RCC_ENABLE_HSI
	#endif

	/*external clock*/
	/*enabling section*/
	#if RCC_ENABLE_HSE == ON
		SET_BIT(RCC_CR,16);				// enabling external clock
	#elif RCC_ENABLE_HSE == OFF
		CLEAR_BIT(RCC_CR,16); 			// disabling external clock
	#else
		#error RCC_Config: You choose wrong choice at RCC_ENABLE_HSE
	#endif

	/*PLL*/
	#if RCC_ENABLE_PLL == ON

		/*multiplier section*/
		#if RCC_PLL_MUL < 2 || RCC_PLL_MUL > 16 //Validating the pll multiplier
			#error RCC_config: you entered a wrong PLL multiplier
		#else
			RCC_CFGR &= ~(0b1111<<18);
			RCC_CFGR |= ((RCC_PLL_MUL-2)<<18);
		#endif

		/*input section*/
		#if RCC_PLL_INPUT == RCC_HSI_DIV_2
			CLEAR_BIT(RCC_CFGR,16);			// enabling internal clock / 2 as pll input
		#elif RCC_PLL_INPUT == RCC_HSE
			SET_BIT(RCC_CFGR,16);				// enabling external clock as pll input
		#elif RCC_PLL_INPUT == RCC_HSE_DIV_2
			SET_BIT(RCC_CFGR,16);				// enabling external clock / 2 as pll input
			SET_BIT(RCC_CFGR,17);
		#else
			#error RCC_config: you entered a wrong PLL input
		#endif

			/*enabling section*/
		#if RCC_ENABLE_PLL == ON
			SET_BIT(RCC_CR,24);				// enabling PLL
		#elif RCC_ENABLE_PLL == OFF
			CLEAR_BIT(RCC_CR,24);			// disabling PLL
		#else
			#error RCC_Config: You choose wrong choice at RCC_ENABLE_PLL
		#endif
	#endif

	/*configurations section*/
	#if RCC_ENABLE_CSS == ON
		SET_BIT(RCC_CR, 19);			//enabling clock security system
	#elif RCC_ENABLE_CSS == OFF
		CLEAR_BIT(RCC_CR, 19);			//disabling clock security system
	#else
		#error RCC_Config: You choose wrong choice at RCC_ENABLE_CSS
	#endif

	#if RCC_ENABLE_MCO == ON
		SET_BIT(RCC_CFGR, 26);			//enabling uc system clock output
	#elif RCC_ENABLE_MCO == OFF
		CLEAR_BIT(RCC_CFGR, 26); 			//disabling uc system clock output
	#else
		#error RCC_Config: You choose wrong choice at RCC_ENABLE_MCO
	#endif

	/*choosing clock source*/
	#if RCC_SYS_CLOCK_TYPE == RCC_HSE_RC
			//setting the clock source bits as HSE RC clock (since it needs HSE bypass)
			RCC_CFGR = (RCC_CFGR&0xfffffffC)|(RCC_HSE_CRYSTAL);
			SET_BIT(RCC_CR,18);
	#elif RCC_SYS_CLOCK_TYPE == RCC_HSE_CRYSTAL || RCC_SYS_CLOCK_TYPE == RCC_HSI || RCC_SYS_CLOCK_TYPE == RCC_PLL
			//setting the clock source bits as any other type
			RCC_CFGR &= ~(0b11);
			RCC_CFGR|=(RCC_SYS_CLOCK_TYPE);
	#else
		#error RCC_config: you choose wrong system clock source
	#endif

}

void RCC_voidEnablePreph(u8 Copy_u8BusId, u8 Copy_u8PrephId) //enable clock for peripherals
{
	//validation condition to make sure the input peripheral id is valid
	if(Copy_u8PrephId <=31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB 	: SET_BIT(RCC_AHBENR	,Copy_u8PrephId);	break;
		case RCC_APB1 	: SET_BIT(RCC_APB1ENR	,Copy_u8PrephId); 	break;
		case RCC_APB2 	: SET_BIT(RCC_APB2ENR	,Copy_u8PrephId); 	break;
		}
	}
	else
	{
		//raise error
	}
}


void RCC_voidDisablePreph(u8 Copy_u8BusId, u8 Copy_u8PrephId) //disable clock for peripherals
{
	//validation condition to make sure the input peripheral id is valid
	if(Copy_u8PrephId <=31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB 	: CLEAR_BIT(RCC_AHBENR,Copy_u8PrephId);		break;
		case RCC_APB1 	: CLEAR_BIT(RCC_APB1ENR,Copy_u8PrephId); 	break;
		case RCC_APB2 	: CLEAR_BIT(RCC_APB2ENR,Copy_u8PrephId); 	break;

		//validation condition to make sure the input bus id is valid
		default 	: /*raise an error*/; 							break;
		}
	}
	else
	{
		//raise error
	}

}

