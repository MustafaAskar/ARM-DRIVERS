/*
 * Description: DMA (Direct memory access) driver
 * Author : Mustafa Askar
 * Date : 13/09/2020
 * Version : V1.0
 * Changelog:
 */
#include"std_types.h"
#include"bit_math.h"
#include"DMA_priv.h"
#include"DMA_interface.h"
#include"DMA_config.h"

void (*DMA_IRQHandlers[7])(void);

void DMA_voidInit()
{
	//Disable channel
	CLEAR_BIT(DMA->Channel[DMA_CHANNEL].CCR,0);

	//Setting peripheral to be source
	CLEAR_BIT(DMA->Channel[DMA_CHANNEL].CCR,4);

	//Channel mode
	#if DMA_MODE == 0
	CLEAR_BIT(DMA->Channel[DMA_CHANNEL].CCR, 14);

	#elif DMA_MODE == 1
	SET_BIT(DMA->Channel[DMA_CHANNEL].CCR, 14);

	#endif

	//Channel priority
	DMA->Channel[DMA_CHANNEL].CCR  &= ~(0b11<<12);
	DMA->Channel[DMA_CHANNEL].CCR  |= DMA_PRIORITY<<12;

	//Source length
	DMA->Channel[DMA_CHANNEL].CCR  &= ~(0b11<<8);
	DMA->Channel[DMA_CHANNEL].CCR  |= DMA_SOURCE_LENTGH<<8;

	//Destination length
	DMA->Channel[DMA_CHANNEL].CCR  &= ~(0b11<<10);
	DMA->Channel[DMA_CHANNEL].CCR  |= DMA_DESTINATION_LENTGH<<10;

	//destination increment mode
	#if DMA_DESTINATION_INC == 0
	CLEAR_BIT(DMA->Channel[DMA_CHANNEL].CCR, 7);

	#elif DMA_DESTINATION_INC == 1
	SET_BIT(DMA->Channel[DMA_CHANNEL].CCR, 7);

	#endif

	//source increment mode
	#if DMA_SOURCE_INC == 0
	CLEAR_BIT(DMA->Channel[DMA_CHANNEL].CCR, 6);

	#elif DMA_SOURCE_INC == 1
	SET_BIT(DMA->Channel[DMA_CHANNEL].CCR, 6);

	#endif

	//Circular mode
	#if DMA_CIRCULAR_MODE == 0
	CLEAR_BIT(DMA->Channel[DMA_CHANNEL].CCR, 5);

	#elif DMA_CIRCULAR_MODE == 1
	SET_BIT(DMA->Channel[DMA_CHANNEL].CCR, 5);

	#endif

	//interrupt at transfer complete
	#if DMA_INTERRUPT == 0
	CLEAR_BIT(DMA->Channel[DMA_CHANNEL].CCR, 1);

	#elif DMA_INTERRUPT == 1
	SET_BIT(DMA->Channel[DMA_CHANNEL].CCR, 1);

	#endif

	//Block size
	DMA->Channel[DMA_CHANNEL].CNDTR = DMA_BLOCK_SIZE;

	//Source address
	DMA->Channel[DMA_CHANNEL].CPAR = DMA_SOURCE_ADDRESS;

	//Destination address
	DMA->Channel[DMA_CHANNEL].CMAR = DMA_DESTINATION_ADDRESS;

	//Enable DMA
	SET_BIT(DMA->Channel[DMA_CHANNEL].CCR, 0);

}

void DMA_voidMEM2MEMTransfer	(u8 Copy_u8Channel, u32* Copy_u32MemorySourceAddress, u32* Copy_u32MemoryDestinationAddress, u16 Copy_u16BlockSize, void(*function)(void))
{
	//Disable channel
	CLEAR_BIT(DMA->Channel[Copy_u8Channel].CCR,0);

	//memory to memory mode
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 14);

	//Source length 32 bit
	DMA->Channel[Copy_u8Channel].CCR  &= ~(0b11<<8);
	DMA->Channel[Copy_u8Channel].CCR  |= 0b10<<8;

	//Destination length 32 bit
	DMA->Channel[Copy_u8Channel].CCR  &= ~(0b11<<10);
	DMA->Channel[Copy_u8Channel].CCR  |= 0b10<<10;

	//destination increment mode
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 7);

	//source increment mode
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 6);

	//interrupt at transfer complete
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 1);

	//Block size
	DMA->Channel[Copy_u8Channel].CNDTR = Copy_u16BlockSize;

	//Source address
	DMA->Channel[Copy_u8Channel].CPAR = Copy_u32MemorySourceAddress;

	//Destination address
	DMA->Channel[Copy_u8Channel].CMAR = Copy_u32MemoryDestinationAddress;

	//Initializing DMA IQR handler
	DMA_IRQHandlers[Copy_u8Channel] = function;

	//Enable DMA
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 0);

}

void DMA_voidPREPH2MEMTransfer	(u8 Copy_u8Channel, u32* Copy_u32MemoryAddress, u32* Copy_u32PrepheralAddress, u16 Copy_u16BlockSize, void(*function)(void))
{
	//Disable channel
	CLEAR_BIT(DMA->Channel[Copy_u8Channel].CCR,0);

	//memory to peripheral mode
	CLEAR_BIT(DMA->Channel[Copy_u8Channel].CCR, 14);

	//read from peripheral
	CLEAR_BIT(DMA->Channel[Copy_u8Channel].CCR,4);

	//Source length 32 bit
	DMA->Channel[Copy_u8Channel].CCR  &= ~(0b11<<8);
	DMA->Channel[Copy_u8Channel].CCR  |= 0b10<<8;

	//Destination length 32 bit
	DMA->Channel[Copy_u8Channel].CCR  &= ~(0b11<<10);
	DMA->Channel[Copy_u8Channel].CCR  |= 0b10<<10;

	//destination increment mode
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 7);

	//source increment mode
	CLEAR_BIT(DMA->Channel[Copy_u8Channel].CCR, 6);

	//interrupt at transfer complete
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 1);

	//Block size
	DMA->Channel[Copy_u8Channel].CNDTR = Copy_u16BlockSize;

	//Source address
	DMA->Channel[Copy_u8Channel].CPAR = Copy_u32PrepheralAddress;

	//Destination address
	DMA->Channel[Copy_u8Channel].CMAR = Copy_u32MemoryAddress;

	//Initializing DMA IQR handler
	DMA_IRQHandlers[Copy_u8Channel] = function;

	//Enable DMA
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 0);

}

void DMA_voidMEM2PREPHTransfer 	(u8 Copy_u8Channel, u32* Copy_u32MemoryAddress, u32* Copy_u32PrepheralAddress, u16 Copy_u16BlockSize, void(*function)(void))
{
	//Disable channel
	CLEAR_BIT(DMA->Channel[Copy_u8Channel].CCR,0);

	//memory to peripheral mode
	CLEAR_BIT(DMA->Channel[Copy_u8Channel].CCR, 14);

	//read from memory
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR,4);

	//Source length 32 bit
	DMA->Channel[Copy_u8Channel].CCR  &= ~(0b11<<8);
	DMA->Channel[Copy_u8Channel].CCR  |= 0b10<<8;

	//Destination length 32 bit
	DMA->Channel[Copy_u8Channel].CCR  &= ~(0b11<<10);
	DMA->Channel[Copy_u8Channel].CCR  |= 0b10<<10;

	//destination increment mode
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 7);

	//source increment mode
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 6);

	//interrupt at transfer complete
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 1);

	//Block size
	DMA->Channel[Copy_u8Channel].CNDTR = Copy_u16BlockSize;

	//Destination address
	DMA->Channel[Copy_u8Channel].CPAR = Copy_u32PrepheralAddress;

	//Source address
	DMA->Channel[Copy_u8Channel].CMAR = Copy_u32MemoryAddress;

	//Initializing DMA IQR handler
	DMA_IRQHandlers[Copy_u8Channel] = function;

	//Enable DMA
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR, 0);

}

void DMA_voidChangePriority(u8 Copy_u8Channel, u8 Copy_u8Priority)
{
	//Channel priority
	DMA->Channel[Copy_u8Channel].CCR  &= ~(0b11<<12);
	DMA->Channel[Copy_u8Channel].CCR  |= Copy_u8Priority<<12;
}

void DMA_voidDisableInterrupt(u8 Copy_u8Channel)
{
	//interrupt at transfer complete
	CLEAR_BIT(DMA->Channel[Copy_u8Channel].CCR, 1);
}

void DMA1_Channel1_IRQHandler(void)
{
	//Disable DMA
	CLEAR_BIT(DMA->Channel[0].CCR, 0);

	//Clear CGIF and TCIF
	DMA->IFCR = 0x00000003;

	//Execute IRQ
	DMA_IRQHandlers[0]();
}

void DMA1_Channel2_IRQHandler(void)
{
	//Disable DMA
	CLEAR_BIT(DMA->Channel[1].CCR, 0);

	//Clear CGIF and TCIF
	DMA->IFCR = 0x00000030;

	//Execute IRQ
	DMA_IRQHandlers[1]();
}

void DMA1_Channel3_IRQHandler(void)
{
	//Disable DMA
	CLEAR_BIT(DMA->Channel[2].CCR, 0);

	//Clear CGIF and TCIF
	DMA->IFCR = 0x00000300;

	//Execute IRQ
	DMA_IRQHandlers[2]();
}

void DMA1_Channel4_IRQHandler(void)
{
	//Disable DMA
	CLEAR_BIT(DMA->Channel[3].CCR, 0);

	//Clear CGIF and TCIF
	DMA->IFCR = 0x00003000;

	//Execute IRQ
	DMA_IRQHandlers[3]();
}

void DMA1_Channel5_IRQHandler(void)
{
	//Disable DMA
	CLEAR_BIT(DMA->Channel[4].CCR, 0);

	//Clear CGIF and TCIF
	DMA->IFCR = 0x00030000;

	//Execute IRQ
	DMA_IRQHandlers[4]();
}

void DMA1_Channel6_IRQHandler(void)
{
	//Disable DMA
	CLEAR_BIT(DMA->Channel[5].CCR, 0);

	//Clear CGIF and TCIF
	DMA->IFCR = 0x00300000;

	//Execute IRQ
	DMA_IRQHandlers[5]();
}

void DMA1_Channel7_IRQHandler(void)
{
	//Disable DMA
	CLEAR_BIT(DMA->Channel[6].CCR, 0);

	//Clear CGIF and TCIF
	DMA->IFCR = 0x03000000;

	//Execute IRQ
	DMA_IRQHandlers[6]();
}
