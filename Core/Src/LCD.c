/*
 * lcd.c
 *
 *  	Created on: 13 de fev de 2022
 *      @author Rodrigo Hiury
 */

#include "LCD.h"
#include "stm32f1xx_hal.h"
#include "string.h"


/*
 * @brief Manda um byte para o LCD
 *
 * @param cmd: Byte a ser enviado.
 *
 */
void LCD_SendByte(uint8_t cmd)
{

	HAL_GPIO_WritePin(LCD_PORT, LCD_RW, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_PORT, LCD_D_ALL, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_PORT, LCD_EN, GPIO_PIN_SET);

	if( cmd & 0x01 )
		HAL_GPIO_WritePin(LCD_PORT, LCD_D0, GPIO_PIN_SET);
	if( cmd & 0x02 )
		HAL_GPIO_WritePin(LCD_PORT, LCD_D1, GPIO_PIN_SET);
	if( cmd & 0x04 )
		HAL_GPIO_WritePin(LCD_PORT, LCD_D2, GPIO_PIN_SET);
	if( cmd & 0x08 )
		HAL_GPIO_WritePin(LCD_PORT, LCD_D3, GPIO_PIN_SET);
	if( cmd & 0x10 )
		HAL_GPIO_WritePin(LCD_PORT, LCD_D4, GPIO_PIN_SET);
	if( cmd & 0x20 )
		HAL_GPIO_WritePin(LCD_PORT, LCD_D5, GPIO_PIN_SET);
	if( cmd & 0x40 )
		HAL_GPIO_WritePin(LCD_PORT, LCD_D6, GPIO_PIN_SET);
	if( cmd & 0x80 )
		HAL_GPIO_WritePin(LCD_PORT, LCD_D7, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LCD_PORT, LCD_EN, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_PORT, LCD_D_ALL, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_PORT, LCD_RS, GPIO_PIN_RESET);
	HAL_Delay(5); //Enquanto a Busy Flag está setada
}

/*
 * @brief Manda um comando pro LCD
 *
 * @param cmd: uint8_t
 */
void LCD_SendCmd(uint8_t cmd)
{
	HAL_GPIO_WritePin(LCD_PORT, LCD_RS, GPIO_PIN_RESET);
	HAL_Delay(1);
	LCD_SendByte(cmd);
}

/*-
 * @brief Manda um dado para o LCD
 *
 * @param data: uint32_t.
 */
void LCD_SendData(uint32_t data)
{
	HAL_GPIO_WritePin(LCD_PORT, LCD_RS, GPIO_PIN_SET);
	HAL_Delay(1);
	LCD_SendByte(data);
}

/*
 * @brief imprime um inteiro até 9999
 *
 * @param x: uint32.
 */
void LCD_Num(uint32_t x)
{
	LCD_SendData((x/1000) + 0x30);
	LCD_SendData((x/100)%10 + 0x30);
	LCD_SendData((x%100)/10 + 0x30);
	LCD_SendData((x%10) + 0x30);
}

/*
 * @brief imprime um texto no LCD
 *
 * @param text: vetor de char
 */
void LCD_SendText(char text[])
{
	for (int i = 0; i < strlen(text); i++){
		LCD_SendData(text[i]);
	}
}

/*
 * @brief Limpa o LCD e manda o cursor para a posição (0,0)
 */
void LCD_Clear(void)
{
	LCD_SendCmd(0x01);
}

/*
 * @brief seta a posição do curso do LCD
 *
 * @param linha e coluna
 */
void LCD_GoTo(unsigned char line, unsigned char column)
{
	uint8_t position = 0;

	switch(line)
	{
		case 0:	position = 0x00;
				break;
		case 1:	position = 0x40;
				break;
		case 2:	position = 0x10;
				break;
		case 3:	position = 0x50;
				break;
		default: position = 0x00;
				break;
	}
	LCD_SendCmd(0x80 | (position + column));
}

/*
 * @brief Inicializa o LCD
 */
void LCD_Init(void)
{
	LCD_SendCmd(0x38); /* 2 linha, matriz 5x8 							*/
	LCD_SendCmd(0x08); /* Desliga o  display							*/
	LCD_SendCmd(0x0C); /* Display ctrl:Disp=ON,Curs/Blnk=OFF 			*/
	LCD_SendCmd(0x06); /* Entry mode: Move right, no shift   			*/
	LCD_SendCmd(0x01); /* Limpa o Display e manda o cursor para 0 	 	*/
	LCD_SendCmd(0x02); /* Força o cursor para o começo					 */

	HAL_Delay(1);
}


