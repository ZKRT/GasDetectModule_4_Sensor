#ifndef __DELAY_H__
#define __DELAY_H__
#include "stm32f0xx.h"
//void delay_init(uint8_t SYSCLK);
//void delay_us(uint32_t nus);
//void delay_xms(uint16_t nms);
void RCC_Configuration(void);
void SysTick_Init(void);
void delay_us(uint16_t nus);				
void delay_ms(uint16_t nms);	
void delay_xms(uint16_t nms);	
#endif


