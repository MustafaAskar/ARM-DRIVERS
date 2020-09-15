/*
 * Description: ADC (analog to digital converter) driver
 * Author : Mustafa Askar
 * Date : 12/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*public functions*/
void ADC_voidSetRegularGroup						(u8* Copy_u8ptrChannels, u8 Copy_u8ChannelsNumber);
void ADC_voidSetInjectedGroup						(u8* Copy_u8ptrChannels, u8 Copy_u8ChannelsNumber);
void ADC_voidInjectedInit							(void); 	//Initialize injected group analog to digital converter
void ADC_voidRegularInit							(void); 	//Initialize regular group analog to digital converter
void ADC_voidRegularConversion						(void); 	//convert a single value
void ADC_voidInjectedStartSingleConversion			(u32* Copy_u32ArrInjectedConversionData); 	//convert a single value
void ADC_voidStartContinousConversion				(void); 	//convert continuous signal
void ADC_voidDisableADC								(void);		//disabling ADC puts it to sleep


/*Channels IDs*/
#define ADC_CHANNEL0		0
#define ADC_CHANNEL1		1
#define ADC_CHANNEL2		2
#define ADC_CHANNEL3		3
#define ADC_CHANNEL4		4
#define ADC_CHANNEL5		5
#define ADC_CHANNEL6		6
#define ADC_CHANNEL7		7
#define ADC_CHANNEL8		8
#define ADC_CHANNEL9		9
#define ADC_CHANNEL10		10
#define ADC_CHANNEL11		11
#define ADC_CHANNEL12		12
#define ADC_CHANNEL13		13
#define ADC_CHANNEL14		14
#define ADC_CHANNEL15		15

#endif /* ADC_INTERFACE_H_ */
