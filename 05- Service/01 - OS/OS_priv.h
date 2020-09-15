/*
 * Description: Operating system scheduler
 * Author : Mustafa Askar
 * Date : 06/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef OS_PRIV_H_
#define OS_PRIV_H_

/*OS task definition*/
typedef struct
{
	u16 TicksPeroidicity;
	void (*void_FunctionPtr)(void);
	u8 TaskState;

}task_t;

/*calculate new system tick depending on system timer clock source*/
#define OS_TICK_TIME_US 		OS_TICK_TIME_MS*(OS_SYSTEM_CLOCK/8000000)*1000

/*NULL*/
#define NULL 					(void*) 0


#endif /* OS_PRIV_H_ */
