/*
 * keypad.c
 *
 *  Created on: Feb 16, 2022
 *      Author: IgorMaia
 */
<<<<<<< HEAD
#include "main.h"
=======
>>>>>>> 26a3bbbf2e7928c85f0b49d1555b528aa7d76ef7
#include "stm32f1xx_hal.h"
#include "keypad.h"

uint16_t row[4] = {ROW1, ROW2, ROW3, ROW4};
uint16_t column[4] = {COLUMN1, COLUMN2, COLUMN3, COLUMN4};

char* readKeypad(void){
	char *key[4][4] = {
<<<<<<< HEAD
			{"7", "8", "9", "A"},
			{"4", "5", "6", "B"},
			{"1", "2", "3", "C"},
=======
			{"1", "2", "3", "A"},
			{"4", "5", "6", "B"},
			{"7", "8", "9", "C"},
>>>>>>> 26a3bbbf2e7928c85f0b49d1555b528aa7d76ef7
			{"*", "0", "#", "D"}
	};

	for(int i = 0; i < 4; i++){

		for(int k = 0; k < 4; k++){
			if(k == i){
				HAL_GPIO_WritePin(ROW_PORT, row[k], GPIO_PIN_SET);
			}else{
				HAL_GPIO_WritePin(ROW_PORT, row[k], GPIO_PIN_RESET);
			}
		}

		for(int j = 0; j < 4; j++){

			if(HAL_GPIO_ReadPin(COLUMN_PORT, column[j])){
				return key[i][j];
			}
		}
	}

	return "Z";
}

