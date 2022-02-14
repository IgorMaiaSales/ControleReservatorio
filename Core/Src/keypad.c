/*
 * keypad.c
 *
 *  Created on: Feb 13, 2022
 *      Author: IgorMaia
 */

#include "main.h"
#include "stm32f1xx_hal.h"

void setRow(int row){
	GPIOA->ODR = 0x1<<(12 + row);
}

int readColumn(int column){
	column = 0x1<<(column + 8);

	return HAL_GPIO_ReadPin(GPIOA, column);
}

int readKey(int row, int column){
	int keyMatrix[4][4] = {
			{7, 8, 9, -3},
			{4, 5, 6, -4},
			{1, 2, 3, -5},
			{-1, 0, -2, -6}
	};

	return keyMatrix[row][column];
}
