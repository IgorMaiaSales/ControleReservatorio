/*
 * pressao.c
 *
 *  Created on: Feb 14, 2022
 *      Author: Rodrigo Hiury
 */

#include "pressao.h"

float corrigePressao(float pressao){
	return -6.1048283274439417e+000
			+ 1.2990936811532654e+000 * pressao
			+ 6.0765816418719276e-005 * pressao * pressao;
}

float getPressao(float adc){
	float pressao;
	adc /= 204.8;
	adc += 0.475;
    adc /= 0.045;
    adc -=  1.3;
    adc *= 0.94148052;
    adc /= 100;
    pressao = (((adc/5.1)+0.095)/0.009)*0.93692308;
    return corrigePressao(pressao);
}

float getAltura(float pressao, float densidade){
	pressao *= 1000;
	return (pressao/(densidade*9.81));
}

float getCapacidade(float altura, float nivel){
	return ((nivel/altura)*100);
}
