/*
 * KPD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */

#ifndef HAL_KEYPAD_KPD_H_
#define HAL_KEYPAD_KPD_H_

#include <util/delay.h>
#include "KPD_Cfg.h"
#include "../../MCAL/DIO/DIO.h"

#define KPD_KEY_NOT_PRESSED 0xff


u8 KPD_GetPressedKey(void);

#endif /* HAL_KEYPAD_KPD_H_ */
