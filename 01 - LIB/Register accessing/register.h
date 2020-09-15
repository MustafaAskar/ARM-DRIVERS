#ifndef REGISTER_H
#define REGISTER_H

typedef struct
{
	volatile u32 bit0:1;
	volatile u32 bit1:1;
	volatile u32 bit2:1;
	volatile u32 bit3:1;
	volatile u32 bit4:1;
	volatile u32 bit5:1;
	volatile u32 bit6:1;
	volatile u32 bit7:1;
	volatile u32 bit8:1;
	volatile u32 bit9:1;
	volatile u32 bit10:1;
	volatile u32 bit11:1;
	volatile u32 bit12:1;
	volatile u32 bit13:1;
	volatile u32 bit14:1;
	volatile u32 bit15:1;
	volatile u32 bit16:1;
	volatile u32 bit17:1;
	volatile u32 bit18:1;
	volatile u32 bit19:1;
	volatile u32 bit20:1;
	volatile u32 bit21:1;
	volatile u32 bit22:1;
	volatile u32 bit23:1;
	volatile u32 bit24:1;
	volatile u32 bit25:1;
	volatile u32 bit26:1;
	volatile u32 bit27:1;
	volatile u32 bit28:1;
	volatile u32 bit29:1;
	volatile u32 bit30:1;
	volatile u32 bit31:1;
	
}bits_t;

typedef union 
{
	bits_t bits;
	volatile u32 port;
}register_u;




#endif 