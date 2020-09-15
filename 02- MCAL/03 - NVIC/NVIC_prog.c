/*
 * Description: NVIC (nested vector interrupt controller) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V3.0
 * Changelog:
 * 				-Added NVIC_init() function to initialize interrupts
 * 				-Added priority control functions
 * 				-Fixed a bug in NVIC addresses
 */


#include "std_types.h"
#include "bit_math.h"
#include "NVIC_priv.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"



void NVIC_voidInit(void) //initialize interrupts
{
	SCB_AIRCR = NVIC_PRIORITY_DISTRIBUTION; //choose the binary format for interrupt priority with VECTKEY so the changes are accepted
}


void NVIC_voidEnableInterrupt	(u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber<=31)
	{
		NVIC_ISER0 = (1<<Copy_u8InterruptNumber);
	}
	else if (Copy_u8InterruptNumber<=59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISER1 = (1<<Copy_u8InterruptNumber);
	}
}

void NVIC_voidDisableInterrupt	(u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber<=31)
	{
		NVIC_ICER0 = (1<<Copy_u8InterruptNumber);
	}
	else if (Copy_u8InterruptNumber<=59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ICER1 = (1<<Copy_u8InterruptNumber);
	}
}

void NVIC_voidSetPendingFlag 	(u8 Copy_u8InterruptNumber) 	//set pending flag to simulate interrupt. for debugging purpose
{
	if(Copy_u8InterruptNumber<=31)
	{
		NVIC_ISPR0 = (1<<Copy_u8InterruptNumber);
	}
	else if (Copy_u8InterruptNumber<=59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISPR1 = (1<<Copy_u8InterruptNumber);
	}

}

void NVIC_voidClearPendingFlag 	(u8 Copy_u8InterruptNumber) 	//set pending flag to simulate interrupt. for debugging purpose
{
	if(Copy_u8InterruptNumber<=31)
	{
		NVIC_ICPR0 = (1<<Copy_u8InterruptNumber);
	}
	else if (Copy_u8InterruptNumber<=59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ICPR1 = (1<<Copy_u8InterruptNumber);
	}

}

u8 NVIC_u8CheckActiveFlag 		(u8 Copy_u8InterruptNumber)	//check on active flag to see whether the interrupt is being served or not
{
	u8 Local_u8ActiveFlagResult = 255;

	if(Copy_u8InterruptNumber<=31)
	{
		Local_u8ActiveFlagResult = GET_BIT(NVIC_IABR0,Copy_u8InterruptNumber);
	}
	else if (Copy_u8InterruptNumber<=59)
	{
		Copy_u8InterruptNumber -= 32;
		Local_u8ActiveFlagResult = GET_BIT(NVIC_IABR1,Copy_u8InterruptNumber);
	}

	return Local_u8ActiveFlagResult;
}

/*WARNING :
 * 			Copy_u8InterruptGroupPriority must equal to 0 if Copy_u8PriorityFormat = YYYY
 * 			Copy_u8InterruptSubGroupPriority must equal to 0 if Copy_u8PriorityFormat = XXXX
 */
void NVIC_voidSetInterruptPriority(s8 Copy_u8InterruptNumber, u8 Copy_u8InterruptGroupPriority, u8 Copy_u8InterruptSubGroupPriority)
{
	/*
	 *XXXX represents base address for GroupPriority shifting
	 *SubGroupPriority is not shifted till being stored in the register
	 */
	u8 Local_u8Priority = Copy_u8InterruptSubGroupPriority|(Copy_u8InterruptGroupPriority<<((NVIC_PRIORITY_DISTRIBUTION - XXXX)/256));

	/*external interrupts*/
	if(Copy_u8InterruptNumber >=0)
	{
		NVIC_IPR[Copy_u8InterruptNumber]=Local_u8Priority<<4;
	}
	else
	{
		//core interrupts
	}

	SCB_AIRCR = NVIC_PRIORITY_DISTRIBUTION; //choose the binary format for interrupt priority with VECTKEY so the changes are accepted


//	switch(Copy_u8PriorityFormat)
//	{
//	case XXXX:
//		NVIC_IPR[Copy_u8InterruptNumber] = Copy_u8InterruptGroupPriority<<4; 		//LSBs are reserved MSBs represent group priority
//		break;
//
//	case XXXY:
//		Copy_u8InterruptSubGroupPriority &= 0x01;									//making sure the SubGroupPriority is 1 bit
//		Copy_u8InterruptGroupPriority &= 0x07;										//making sure the GroupPriority is 3 bits
//		NVIC_IPR[Copy_u8InterruptNumber] = Copy_u8InterruptGroupPriority<<5; 		//InterruptGroupPriority represents most significant 3 bits
//		NVIC_IPR[Copy_u8InterruptNumber] |= (Copy_u8InterruptSubGroupPriority<<4);	//InterruptSubGroupPriority represents the lowest bit in MSBs
//		break;
//
//	case XXYY:
//		Copy_u8InterruptSubGroupPriority &= 0x03;									//making sure the SubGroupPriority is 2 bit
//		Copy_u8InterruptGroupPriority &= 0x03;										//making sure the GroupPriority is 2 bits
//		NVIC_IPR[Copy_u8InterruptNumber] = Copy_u8InterruptGroupPriority<<6; 		//InterruptGroupPriority represents high 2 bit in MSBs
//		NVIC_IPR[Copy_u8InterruptNumber] |= (Copy_u8InterruptSubGroupPriority<<4);	//InterruptSubGroupPriority represents low 2 bit in MSBs
//		break;
//
//	case XYYY:
//		Copy_u8InterruptSubGroupPriority &= 0x07;									//making sure the SubGroupPriority is 3 bit
//		Copy_u8InterruptGroupPriority &= 0x01;										//making sure the GroupPriority is 1 bits
//		NVIC_IPR[Copy_u8InterruptNumber] = Copy_u8InterruptGroupPriority<<7;		//InterruptGroupPriority represents the lowest bit in MSBs
//		NVIC_IPR[Copy_u8InterruptNumber] |= (Copy_u8InterruptSubGroupPriority<<4);	//InterruptSubGroupPriority represents most significant 3 bits
//		break;
//
//	case YYYY:
//		NVIC_IPR[Copy_u8InterruptNumber] = Copy_u8InterruptSubGroupPriority<<4;		//LSBs are reserved MSBs represent sub group priority
//		break;
//	}
}
























