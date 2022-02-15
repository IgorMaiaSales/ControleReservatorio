/*
 * pressao.h
 *
 *  Created on: 14 de fev de 2022
 *      @author Rodrigo Hiury
 */

#ifndef INC_PRESSAO_H_
#define INC_PRESSAO_H_


float corrigePressao(float pressao);
float getPressao(float adc);
float getAltura(float pressao, float densidade);
float getCapacidade(float altura, float nivel);

#endif /* INC_PRESSAO_H_ */
