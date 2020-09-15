/*
 * Description: DMA (Direct memory access) driver
 * Author : Mustafa Askar
 * Date : 13/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

/*public functions*/
void DMA_voidInit(void);
void DMA_voidMEM2MEMTransfer	(u8 Copy_u8Channel, u32* Copy_u32Memory1Address, u32* Copy_u32Memory2Address, u16 Copy_u16BlockSize, void(*function)(void));
void DMA_voidPREPH2MEMTransfer	(u8 Copy_u8Channel, u32* Copy_u32MemoryAddress, u32* Copy_u32PrepheralAddress, u16 Copy_u16BlockSize, void(*function)(void));
void DMA_voidMEM2PREPHTransfer 	(u8 Copy_u8Channel, u32* Copy_u32MemoryAddress, u32* Copy_u32PrepheralAddress, u16 Copy_u16BlockSize, void(*function)(void));
void DMA_voidChangePriority		(u8 Copy_u8Channel, u8 Copy_u8Priority);
void DMA_voidDisableInterrupt	(u8 Copy_u8Channel);



/*Channels IDs*/
#define DMA_CHANNEL1 			0
#define DMA_CHANNEL2 			1
#define DMA_CHANNEL3 			2
#define DMA_CHANNEL4 			3
#define DMA_CHANNEL5 			4
#define DMA_CHANNEL6 			5
#define DMA_CHANNEL7 			6

/*Modes*/
#define MEM2MEM 				1
#define PREPH2MEM 				0

/*Priority*/
#define LOW						0
#define MEDIUM					1
#define HIGH					2
#define VERY_HIGH				3

/*Word length*/
#define _8_BITS					0
#define _16_BITS				1
#define _32_BITS				2

/*general definitions*/
#define ON						1
#define OFF						0

#endif /* DMA_INTERFACE_H_ */
