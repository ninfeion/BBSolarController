#ifndef _SYSTEMINIT_H_
#define _SYSTEMINIT_H_

#include "stm32f10x.h"

#define LedA_on    GPIO_SetBits(GPIOA, GPIO_Pin_4)
#define LedA_off   GPIO_ResetBits(GPIOA, GPIO_Pin_4)
#define LedB_on    GPIO_SetBits(GPIOA, GPIO_Pin_7)
#define LedB_off   GPIO_ResetBits(GPIOA, GPIO_Pin_7)
#define LedC_on    GPIO_SetBits(GPIOA, GPIO_Pin_6)
#define LedC_off   GPIO_ResetBits(GPIOA, GPIO_Pin_6)
#define LedD_on    GPIO_SetBits(GPIOA, GPIO_Pin_5)
#define LedD_off   GPIO_ResetBits(GPIOA, GPIO_Pin_5)

uint8_t sysclockInit(void);
uint8_t systickInit(void);
void ledInit(void);

#endif