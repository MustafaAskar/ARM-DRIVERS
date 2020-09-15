/*
 * Description: Operating system scheduler
 * Author : Mustafa Askar
 * Date : 06/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef OS_CONFIG_H_
#define OS_CONFIG_H_

/*OS maximum number of tasks
 * Options:
 * 			1:1000
 */
#define OS_NUMBER_OF_TASKS 			6

/*OS tick time in ms
 * WARNING: These calucations are wrong if the System timer clock is not 1Mhz
 * Options:
 *			1:10000
 */
#define OS_TICK_TIME_MS				1000

/*Enter system clock source so the OS can calculate right system tick time*/
#define OS_SYSTEM_CLOCK 			16000000

#endif /* OS_CONFIG_H_ */
