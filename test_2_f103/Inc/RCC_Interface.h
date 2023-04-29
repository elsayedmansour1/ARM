/*
 * RCC_Interface.h
 *
 *  Created on: Apr 28, 2023
 *      Author: Elsayed mansour
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

void RCC_SetCLKStatus(uint8_t CLK_Type ,uint8_t State);

void RCC_SetSysCLK(uint8_t SysCLK);
/*HSEConfig will use it when you choose system clk as PLL */
static void RCC_HSEConfig(uint8_t HSE_Value);

void RCC_PLLConfig(uint8_t MultiFactor, uint8_t PLLSrc);

void RCC_SetAHB_PeripheralCLKState(uint8_t Peripheral,uint8_t State);

void RCC_SetAPB2_PeripheralCLKState(uint8_t Peripheral,uint8_t State);

void RCC_SetAPB1_PeripheralCLKState(uint8_t Peripheral,uint8_t State);

#endif /* RCC_INTERFACE_H_ */
