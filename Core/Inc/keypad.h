/*
 * keypad.h
 *
 *  Created on: Feb 13, 2022
 *      Author: IgorMaia
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

void setRow(int row);
int readColumn(int column);
int readKey(int row, int column);

#endif /* INC_KEYPAD_H_ */
