/*
 * Description: Operating system scheduler
 * Author : Mustafa Askar
 * Date : 06/09/2020
 * Version : V1.0
 * Changelog:
 */

#include"std_types.h"
#include"bit_math.h"
#include"STK_interface.h"
#include"OS_priv.h"
#include"OS_interface.h"
#include"OS_config.h"


static task_t Global_task_tOSTasks[OS_NUMBER_OF_TASKS] = {NULL};
volatile u16 Global_u16TickCounter;
volatile u16 Global_u16Counter;


/*public functions*/

void OS_voidCreatTask(u16 Copy_u16TaskID, void(*void_Function)(void), u16 Copy_u16Perodicitiy, u16 Copy_InitialDelay)
{
	//Arranging the tasks depending on their priority (ID)
	Global_task_tOSTasks[Copy_u16TaskID].void_FunctionPtr = void_Function;

	//if there's an initial delay (offset), put it on the task periodicity
	Global_task_tOSTasks[Copy_u16TaskID].TicksPeroidicity = (Copy_u16Perodicitiy + Copy_InitialDelay*OS_TICK_TIME_MS);

	//Change the periodicity unit from ms to system ticks
	Global_task_tOSTasks[Copy_u16TaskID].TicksPeroidicity /= OS_TICK_TIME_MS;

	//Set task as ready
	Global_task_tOSTasks[Copy_u16TaskID].TaskState = OS_TASK_READY;
}

void OS_voidChangeTaskState(u16 Copy_u16TaskID, u8 Copy_u8State) //pause or resume the task
{
	//assign state to task
	Global_task_tOSTasks[Copy_u16TaskID].TaskState = Copy_u8State;
}

void OS_voidDeleteTask(u16 Copy_u16TaskID) //delete a task permanently
{
	Global_task_tOSTasks[Copy_u16TaskID].void_FunctionPtr = NULL;
}

void OS_voidStartScheduler(void) //start os
{
	//System timer initialization
	STK_voidInit();

	//System clock -> 8Mhz, AHB clock-> 8Mhz., System timer clock source ->AHB/8
	STK_voidSetIntervalPeriodic(OS_TICK_TIME_US,OS_voidScheduler);
}


/*private functions*/

void OS_voidScheduler(void)
{
	//looping on every function
	for(Global_u16Counter = 0; Global_u16Counter<OS_NUMBER_OF_TASKS; Global_u16Counter++)
	{
		//if tick counter is divisible over the task periodicity and there is a task, then it can be executed
		if((Global_u16TickCounter % Global_task_tOSTasks[Global_u16Counter].TicksPeroidicity) == 0 && (Global_task_tOSTasks[Global_u16Counter].void_FunctionPtr!=NULL))
		{
			if(Global_task_tOSTasks[Global_u16Counter].TaskState == OS_TASK_READY)
			{
				//executing the task
				Global_task_tOSTasks[Global_u16Counter].void_FunctionPtr();
			}
		}
	}
	Global_u16TickCounter++;
}

