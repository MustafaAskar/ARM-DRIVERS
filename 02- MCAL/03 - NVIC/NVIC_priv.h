/*
 * Description: NVIC (nested vector interrupt controller) driver
 * Author : Mustafa Askar
 * Date : 1/9/2020
 * Version : V2.0
 * Version : V3.0
 * Changelog:
 * 				-Added NVIC_init() function to initialize interrupts
 * 				-Added priority control functions
 * 				-Fixed a bug in NVIC addresses
 */

#ifndef NVIC_PRIV_H_
#define NVIC_PRIV_H_

/*NVIC registers*/
#define NVIC_ISER0				(*((u32*)0xE000E100))
#define NVIC_ISER1				(*((u32*)0xE000E104))
#define NVIC_ICER0				(*((u32*)0xE000E180))
#define NVIC_ICER1				(*((u32*)0xE000E184))
#define NVIC_ISPR0				(*((u32*)0xE000E200))
#define NVIC_ISPR1				(*((u32*)0xE000E204))
#define NVIC_ICPR0				(*((u32*)0xE000E280))
#define NVIC_ICPR1				(*((u32*)0xE000E284))
#define NVIC_IABR0				(*((volatile u32*)0xE000E300)) 	//using volatile for read only memory do prevent optimization
#define NVIC_IABR1				(*((volatile u32*)0xE000E304))	//using volatile for read only memory do prevent optimization
#define NVIC_IPR				((u8*)0xE000E400)
#define SCB_AIRCR				(*((u32*)0xE000ED0C))


/*
 * NVIC priority binary point (format)
 * X : for group bit field
 * Y : for subgroup bit field
 */

#define XXXX 					0x05FA0300
#define XXXY					0x05FA0400
#define XXYY					0x05FA0500
#define XYYY					0x05FA0600
#define YYYY					0x05FA0700

































/*struct and union used for initializing NVIC*/

typedef struct
{
	u32 NVIC_ENABLE_INT0:1;
	u32 NVIC_ENABLE_INT1:1;
	u32 NVIC_ENABLE_INT2:1;
	u32 NVIC_ENABLE_INT3:1;
	u32 NVIC_ENABLE_INT4:1;
	u32 NVIC_ENABLE_INT5:1;
	u32 NVIC_ENABLE_INT6:1;
	u32 NVIC_ENABLE_INT7:1;
	u32 NVIC_ENABLE_INT8:1;
	u32 NVIC_ENABLE_INT9:1;
	u32 NVIC_ENABLE_INT10:1;
	u32 NVIC_ENABLE_INT11:1;
	u32 NVIC_ENABLE_INT12:1;
	u32 NVIC_ENABLE_INT13:1;
	u32 NVIC_ENABLE_INT14:1;
	u32 NVIC_ENABLE_INT15:1;
	u32 NVIC_ENABLE_INT16:1;
	u32 NVIC_ENABLE_INT17:1;
	u32 NVIC_ENABLE_INT18:1;
	u32 NVIC_ENABLE_INT19:1;
	u32 NVIC_ENABLE_INT20:1;
	u32 NVIC_ENABLE_INT21:1;
	u32 NVIC_ENABLE_INT22:1;
	u32 NVIC_ENABLE_INT23:1;
	u32 NVIC_ENABLE_INT24:1;
	u32 NVIC_ENABLE_INT25:1;
	u32 NVIC_ENABLE_INT26:1;
	u32 NVIC_ENABLE_INT27:1;
	u32 NVIC_ENABLE_INT28:1;
	u32 NVIC_ENABLE_INT29:1;
	u32 NVIC_ENABLE_INT30:1;
	u32 NVIC_ENABLE_INT31:1;

}NVIC_INIT;

typedef union
{
	NVIC_INIT NVIC_ENABLE_BITS;
	u32 NVIC_ENABLE_PORT;
}NVIC_INIT_UNION;







#endif /* NVIC_PRIV_H_ */
