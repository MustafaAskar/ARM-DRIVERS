/*
 * Description: DMA (Direct memory access) driver
 * Author : Mustafa Askar
 * Date : 13/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_

#define DMA_CHANNEL							DMA_CHANNEL1
#define DMA_MODE							MEM2MEM
#define DMA_PRIORITY 						VERY_HIGH
#define DMA_DESTINATION_ADDRESS				0
#define DMA_DESTINATION_LENTGH				_32_BITS
#define DMA_DESTINATION_INC					ON
#define DMA_SOURCE_ADDRESS					0
#define DMA_SOURCE_LENTGH					_32_BITS
#define DMA_SOURCE_INC						ON
#define DMA_BLOCK_SIZE						1000
#define DMA_CIRCULAR_MODE 					OFF
#define DMA_INTERRUPT						ON



#endif /* DMA_CONFIG_H_ */
