#ifndef _SYSTEM_CONFIG_H_
#define _SYSTEM_CONFIG_H_

#define LedA_on    GPIO_SetBits(GPIOA, GPIO_Pin_4)
#define LedA_off   GPIO_ResetBits(GPIOA, GPIO_Pin_4)
#define LedB_on    GPIO_SetBits(GPIOA, GPIO_Pin_7)
#define LedB_off   GPIO_ResetBits(GPIOA, GPIO_Pin_7)
#define LedC_on    GPIO_SetBits(GPIOA, GPIO_Pin_6)
#define LedC_off   GPIO_ResetBits(GPIOA, GPIO_Pin_6)
#define LedD_on    GPIO_SetBits(GPIOA, GPIO_Pin_5)
#define LedD_off   GPIO_ResetBits(GPIOA, GPIO_Pin_5)

// #define USB_DEBUG
// #define USE_MAG_PASSMODE
#define BRO_ENABLED
#define USE_LPF_FILTER
#define SAMPLINGFREQ  200.0f
#define LPFCUTOFFFREQ 30.0f

#endif


