/*
 * RCC_Register.h
 *
 *  Created on: Apr 28, 2023
 *      Author: Elsayed mansour
 */

#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_
#include <stdint.h>
typedef 	struct
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
}RCC;
RCC * RCC_BA= ((RCC*)0x40021000);

#endif /* RCC_REGISTER_H_ */
