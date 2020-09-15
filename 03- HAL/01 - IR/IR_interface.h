/*
 * Description: IR (infra-red communication system) driver
 * Author : Mustafa Askar
 * Date : 02/09/2020
 * Version : V1.0
 * Changelog:
 */

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

/*public functions*/
void IR_voidInit(void);
void IR_voidGetButton(u8* Copy_u8Button);


/*private functions*/
void Local_DataAnalysis(void);
void Local_GetData(void);


#endif /* IR_INTERFACE_H_ */
