/*
 * RCC_Program.c
 *
 *  Created on: Apr 28, 2023
 *      Author: Elsayed mansour
 */
#include <stdint.h>
#include "RCC_Interface.h"
#include "RCC_Register.h"
#include "RCC_Config.h"
#include "BIT_MATH.h"
void RCC_SetCLKStatus(uint8_t CLK_Type ,uint8_t State)
{
	switch (CLK_Type)
	{
	case HSI:
		if(State==ON)
		{
			SET_BIT(RCC_BA->CR,0);
			while(!GET_BIT(RCC_BA->CR,1));/*Check HSI is ready to be used*/
		}
		else
		{
			CLR_BIT(RCC_BA->CR,0);
		}
		break;
	case HSE:
		if(State==ON)
		{
			SET_BIT(RCC_BA->CR,16);
			while(!GET_BIT(RCC_BA->CR,17));/*Check HSE is ready to be used*/
		}
		else
		{
			CLR_BIT(RCC_BA->CR,16);
		}
		break;
	case PLL:
		if(State==ON)
		{
			SET_BIT(RCC_BA->CR,24);
			while(!GET_BIT(RCC_BA->CR,25));/*Check PLL is ready to be used*/
		}
		else
		{
			CLR_BIT(RCC_BA->CR,24);
		}
		break;
	default:
		/*ERROR should replaced with error action*/
		break;
	}
}

void RCC_SetSysCLK(uint8_t SysCLK)
{
	switch (SysCLK)
	{
	case HSI:
		CLR_BIT(RCC_BA->CFGR,0);
		CLR_BIT(RCC_BA->CFGR,1);
		break;
	case HSE:
		CLR_BIT(RCC_BA->CFGR,0);
		SET_BIT(RCC_BA->CFGR,1);
		break;
	case PLL:
		SET_BIT(RCC_BA->CFGR,0);
		SET_BIT(RCC_BA->CFGR,1);
		break;
	default:
		/*ERROR should replaced with error action*/
		break;
	}
}
static void RCC_HSEConfig(uint8_t HSE_Value)
{
	/*to enter the whole value of HSE to PLL*/
	if (HSE_Value==HSE)
	{
		CLR_BIT(RCC_BA->CFGR,17);
	}
	else if(HSE_Value==HSE_2)/*to enter the value of HSE divided by two*/
	{
		SET_BIT(RCC_BA->CFGR,17);
	}
}
void RCC_PLLConfig(uint8_t MultiFactor, uint8_t PLLSrc)
{
	if (PLLSrc==HSE)
	{
		SET_BIT(RCC_BA->CFGR,16);
		/*to enter the whole value of HSE to PLL*/
		RCC_HSEConfig(HSE);
	}
	else if (PLLSrc==HSI)
	{
		CLR_BIT(RCC_BA->CFGR,16);
	}
	switch (MultiFactor)
	{
	case InCLK_2:RCC_BA->CFGR|=0<<18;break;
	case InCLK_3:RCC_BA->CFGR|=1<<18;break;
	case InCLK_4:RCC_BA->CFGR|=2<<18;break;
	case InCLK_5:RCC_BA->CFGR|=3<<18;break;
	case InCLK_6:RCC_BA->CFGR|=4<<18;break;
	case InCLK_7:RCC_BA->CFGR|=5<<18;break;
	case InCLK_8:RCC_BA->CFGR|=6<<18;break;
	case InCLK_9:RCC_BA->CFGR|=7<<18;break;
	case InCLK_10:RCC_BA->CFGR|=8<<18;break;
	case InCLK_11:RCC_BA->CFGR|=9<<18;break;
	case InCLK_12:RCC_BA->CFGR|=10<<18;break;
	case InCLK_13:RCC_BA->CFGR|=11<<18;break;
	case InCLK_14:RCC_BA->CFGR|=12<<18;break;
	case InCLK_15:RCC_BA->CFGR|=13<<18;break;
	case InCLK_16:RCC_BA->CFGR|=14<<18;break;
	default:
		/*ERROR should replaced with error action*/
		break;

	}
}
