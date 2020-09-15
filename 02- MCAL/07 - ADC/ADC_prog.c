/*
 * Description: ADC (analog to digital converter) driver
 * Author : Mustafa Askar
 * Date : 12/09/2020
 * Version : V1.0
 * Changelog:
 */

#include"std_types.h"
#include"bit_math.h"
#include"register.h"
#include"ADC_priv.h"
#include"ADC_interface.h"
#include"ADC_config.h"

void ADC_voidSetRegularGroup			(u8* Copy_u8ptrChannels, u8 Copy_u8ChannelsNumber)
{
	u8 Local_u8Counter;

	/*setting conversion number in the group*/
	ADC_SQR1 &= ~(0b1111<<20);
	ADC_SQR1 |= ((Copy_u8ChannelsNumber-1)<<20);

	/*assigning channels to group*/
	for(Local_u8Counter = 0; Local_u8Counter<Copy_u8ChannelsNumber; Local_u8Counter++ )
	{
		if(Local_u8Counter<=6)
		{
			ADC_SQR3 |= Copy_u8ptrChannels[Local_u8Counter]<<(Local_u8Counter*5);
		}
		else if (Local_u8Counter<=12)
		{
			ADC_SQR2 |= Copy_u8ptrChannels[Local_u8Counter]<<((Local_u8Counter-7)*5);
		}
		else if (Local_u8Counter<=15)
		{
			ADC_SQR1 |= Copy_u8ptrChannels[Local_u8Counter]<<((Local_u8Counter-13)*5);
		}
		else
		{
			//error
		}
	}

}

void ADC_voidSetInjectedGroup			(u8* Copy_u8ptrChannels, u8 Copy_u8ChannelsNumber)
{
	u8 Local_u8Counter;

	/*setting conversion number in the group*/
	ADC_JSQR &= ~(0b11<<20);
	ADC_JSQR |= ((Copy_u8ChannelsNumber-1)<<20);

	/*assigning channels to group*/
	for(Local_u8Counter = 0; Local_u8Counter<Copy_u8ChannelsNumber; Local_u8Counter++ )
	{
		//note: injected group counts down (channel 4 is served first)
		ADC_JSQR |= Copy_u8ptrChannels[Local_u8Counter]<<((3-Local_u8Counter)*5);

	}
}

void ADC_voidRegularInit			(void) 	//Initialize regular group analog to digital converter
{
	//enable regular group interrupt
	SET_BIT(ADC_CR1,5);

#if ADC_CONTINOUS_MODE ==1
	//enable continuous conversion
	SET_BIT(ADC_CR2,1);
#elif ADC_CONTINOUS_MODE == 0
	//disable continuous conversion
	CLEAR_BIT(ADC_CR2,1);
#else
#error (ADC_CONTINOUS_MODE: wrong option)
#endif

	//enable DMA request
	SET_BIT(ADC_CR2,8);

	//enable scan mode
	SET_BIT(ADC_CR1,8);

	//enable external trigger
	SET_BIT(ADC_CR2, 20);

	//select SWSTART as external trigger
	ADC_CR2 &= ~(0b111<<17);
	ADC_CR2 |= 0b111<<17;

	//enable ADC
	SET_BIT(ADC_CR2,0);

	//Calibrate ADC
	SET_BIT(ADC_CR2,2);

}

void ADC_voidInjectedInit			(void) 	//Initialize injected group analog to digital converter
{
#if ADC_INJECTED_GROUP_INTERRUPT == 0
	//disable injected group interrupt
	CLEAR_BIT(ADC_CR1,7);
#elif ADC_INJECTED_GROUP_INTERRUPT ==1
	//enable injected group interrupt
	SET_BIT(ADC_CR1,7);
#else
#error (ADC_INJECTED_GROUP_INTERRUPT: Wrong error)
#endif

#if ADC_CONTINOUS_MODE ==1
	//enable continuous conversion
	SET_BIT(ADC_CR2,1);
#elif ADC_CONTINOUS_MODE == 0
	//disable continuous conversion
	CLEAR_BIT(ADC_CR2,1);
#else
#error (ADC_CONTINOUS_MODE: wrong option)
#endif

	//enable scan mode
	SET_BIT(ADC_CR1,8);

	//enable external trigger
	SET_BIT(ADC_CR2,15);

	//choose JSWSTART bit as an external trigger
	ADC_CR2 &= ~(0b111<<12);
	ADC_CR2 |= 0b111<<12;

	//enable ADC
	SET_BIT(ADC_CR2,0);

	//Calibrate ADC
	SET_BIT(ADC_CR2,2);
}

void ADC_u16RegularConversion			(void) 	//convert a single value
{
	//enable ADC one more time starts the conversion
	SET_BIT(ADC_CR2,22);

}

void ADC_voidInjectedStartSingleConversion			(u32* Copy_u32ArrInjectedConversionData ) 	//convert a single value
{
	//enable ADC one more time starts the conversion
	SET_BIT(ADC_CR2,21);

	//waiting for conversion to be over
	while((GET_BIT(ADC_SR,2))==0);

	//setting ADC in ready state
	CLEAR_BIT(ADC_SR,3);
	CLEAR_BIT(ADC_SR,3);

	//returning the array of the converted values
	Copy_u32ArrInjectedConversionData[0] = ADC_JDR1;
	Copy_u32ArrInjectedConversionData[1] = ADC_JDR2;
	Copy_u32ArrInjectedConversionData[2] = ADC_JDR3;
	Copy_u32ArrInjectedConversionData[3] = ADC_JDR4;

}

void ADC_voidDisableADC(void)
{
	//disabling ADC puts it to sleep
	CLEAR_BIT(ADC_CR2,0);
}
