/*
 * Description: EXINT (external interrupt) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V2.0
 * Changelog:
 *			-Added callback option
 *			-Fixed pending flag bug
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

/*EXINT addresses*/
#define EXTI_IMR 				((volatile register_u*)0x40010400)
#define EXTI_EMR 				((volatile register_u*)0x40010404)
#define EXTI_RTSR 				((volatile register_u*)0x40010408)
#define EXTI_FTSR 				((volatile register_u*)0x4001040C)
#define EXTI_SWIER 				((volatile register_u*)0x40010410)
#define EXTI_PR 				((volatile register_u*)0x40010414)


#endif /* EXTI_PRIV_H_ */
