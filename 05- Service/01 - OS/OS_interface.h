/*
 * Description: Operating system scheduler
 * Author : Mustafa Askar
 * Date : 06/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

/*public functions*/
void OS_voidCreatTask		(u16 Copy_u16TaskID, void(*void_Function)(void), u16 Copy_u16Perodicitiy, u16 Copy_InitialDelay);
void OS_voidStartScheduler	(void); //start os
void OS_voidChangeTaskState	(u16 Copy_u16TaskID, u8 Copy_u8State);		//pause or resume the task
void OS_voidDeleteTask		(u16 Copy_u16TaskID); 						//delete a task permanently


/*private functions*/
void OS_voidScheduler		(void);

/*State definitions*/
#define OS_TASK_READY 			1
#define OS_TASK_SUSPENDED		0




#endif /* OS_INTERFACE_H_ */
