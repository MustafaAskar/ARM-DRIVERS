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

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_u32Ticks); //Synchronous function, halts processor while executing
void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void(*Copy_voidFunction)(void)); //Asynchronous single interval function
void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void(*Copy_voidFunction)(void)); //Asynchronous periodic interval function
void STK_voidStopTimer(void);
u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemainingTime(void);







#endif /* STK_INTERFACE_H_ */
