/*
 * Description: DMA (Direct memory access) driver
 * Author : Mustafa Askar
 * Date : 13/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef DMA_PRIV_H_
#define DMA_PRIV_H_

/*DMA1 structure*/
typedef struct
{
	u32 CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;
	u32 Reserved;
}DMA_CHANNEL;

typedef struct
{
	u32 ISR;
	u32 IFCR;
	DMA_CHANNEL Channel[7];
}DMA_t;

/*DMA1 addresses*/

#define DMA 			((DMA_t*)0x40020000)

#endif /* DMA_PRIV_H_ */
