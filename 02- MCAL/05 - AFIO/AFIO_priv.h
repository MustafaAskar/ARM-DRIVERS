/*
 * Description: AFIO (alternate function input output) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V2.0
 * Changelog:
 *			-Improved performance
 */

#ifndef AFIO_PRIV_H_
#define AFIO_PRIV_H_

/*AFIO addresses*/

#define AFIO_EVCR				(*((u32*)0x40010000))
#define AFIO_MAPR				(*((u32*)0x40010004))
#define AFIO_EXTICR1			(*((u32*)0x40010008))
#define AFIO_EXTICR2			(*((u32*)0x4001000C))
#define AFIO_EXTICR3			(*((u32*)0x40010010))
#define AFIO_EXTICR4			(*((u32*)0x40010014))
#define AFIO_MAPR2				(*((u32*)0x4001001C))




#endif /* AFIO_PRIV_H_ */
