#include "systeminit.h"
#include "stm32f10x_flash.h"

uint8_t sysclockInit(void)
{
    ErrorStatus HSEStartUpStatus;
	
    RCC_DeInit();/* RCC重置 */
    RCC_HSEConfig(RCC_HSE_ON); /*使能HSE*/
    HSEStartUpStatus = RCC_WaitForHSEStartUp();
    if(HSEStartUpStatus == SUCCESS)   //外部晶振使能成功
    {
        RCC_HCLKConfig(RCC_SYSCLK_Div1); /* 配置HCLK = SYSCLK */
        RCC_PCLK2Config(RCC_HCLK_Div1); /* 配置PCLK2 = HCLK */
        RCC_PCLK1Config(RCC_HCLK_Div2); /* 配置PCLK1 = HCLK/2 */

        FLASH_SetLatency(FLASH_Latency_2);
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  /* RCC_PLLSource_HSE_Div1为外置晶振的分频系数;RCC_PLLMul_9为倍频数 */
        RCC_PLLCmd(ENABLE);
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); //等待pll工作
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);   /* 选定PLL为系统主时钟 */
        while(RCC_GetSYSCLKSource() != 0x08); //判断pll是否为系统时钟
		return 1;

	}
	else
		return 0;
}


uint8_t systickInit(void)
{
	return SysTick_Config(72); //计1000次是1us
}


void ledInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE); //使能GPOIA,GPIOB复用时钟	   
   	
    //LED GPIO初始化
    //LED_0->D3->PA4
    //LED_3->D4->PA7
    //LED_2->D5->PA6
    //LED_1->D6->PA5
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 ;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;   
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
    GPIO_Init(GPIOA, &GPIO_InitStructure); 
  
    LedA_off;
    LedB_off;
    LedC_off;
    LedD_off;
}
