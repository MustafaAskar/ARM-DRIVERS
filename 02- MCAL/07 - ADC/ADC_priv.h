/*
 * Description: ADC (analog to digital converter) driver
 * Author : Mustafa Askar
 * Date : 12/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

/*ADC addresses*/
#define ADC_SR 					(*((volatile u32*)0x40012400))
#define ADC_CR1 				(*((volatile u32*)0x40012404))
#define ADC_CR2 				(*((volatile u32*)0x40012408))
#define ADC_SMPR1 				(*((volatile u32*)0x4001240C))
#define ADC_SMPR2 				(*((volatile u32*)0x40012410))
#define ADC_JOFR1 				(*((volatile u32*)0x40012414))
#define ADC_JOFR2 				(*((volatile u32*)0x40012418))
#define ADC_JOFR3 				(*((volatile u32*)0x4001241C))
#define ADC_JOFR4 				(*((volatile u32*)0x40012420))
#define ADC_HTR 				(*((volatile u32*)0x40012424))
#define ADC_LTR 				(*((volatile u32*)0x40012428))
#define ADC_SQR1 				(*((volatile u32*)0x4001242C))
#define ADC_SQR2 				(*((volatile u32*)0x40012430))
#define ADC_SQR3 				(*((volatile u32*)0x40012434))
#define ADC_JSQR 				(*((volatile u32*)0x40012438))
#define ADC_JDR1 				(*((volatile u32*)0x4001243C))
#define ADC_JDR2 				(*((volatile u32*)0x40012440))
#define ADC_JDR3 				(*((volatile u32*)0x40012444))
#define ADC_JDR4 				(*((volatile u32*)0x40012448))
#define ADC_DR 					(*((volatile u32*)0x4001244C))




#endif /* ADC_PRIV_H_ */
