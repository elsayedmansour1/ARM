/*
 * RCC_Config.h
 *
 *  Created on: Apr 28, 2023
 *      Author: Elsayed mansour
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

enum CLK_Type
{
	HSI,
	HSE,
	HSE_2,
	PLL
};

enum State
{
	ON,
	OFF
};

enum MultiFactor
{
	InCLK_2,
	InCLK_3,
	InCLK_4,
	InCLK_5,
	InCLK_6,
	InCLK_7,
	InCLK_8,
	InCLK_9,
	InCLK_10,
	InCLK_11,
	InCLK_12,
	InCLK_13,
	InCLK_14,
	InCLK_15,
	InCLK_16
};
#endif /* RCC_CONFIG_H_ */
