/*
 * Description: STK (system tick timer) driver
 * Author : Mustafa Askar
 * Date : 02/09/2020
 * Version : V2.0
 * Changelog:
 * 			-Added synchronous and asynchronous option
 * 			-Added Callback option
 * 			-Added periodic and single interval option
 * 			-Added elapsed and remaining time
 */

#ifndef STK_PRIV_H_
#define STK_PRIV_H_

/*STK addresses*/

#define STK_CTRL					((volatile register_u*)0xE000E010)
#define STK_LOAD					((volatile register_u*)0xE000E014)
#define STK_VAL						((volatile register_u*)0xE000E018)
#define STK_CALIB					((volatile register_u*)0xE000E01C)

/*STK interrupt configs*/
#define STK_INTERRUPT_DISABLED 			0
#define STK_INTERRUPT_ENABLED 			1


/*STK clock source*/
#define STK_AHB_DIV_8					0
#define STK_AHB							1

#endif /* STK_PRIV_H_ */
