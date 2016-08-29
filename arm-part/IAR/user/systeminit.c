#include "systeminit.h"
#include "stm32f10x_flash.h"

uint8_t sysclockInit(void)
{
    ErrorStatus HSEStartUpStatus;
	
    RCC_DeInit();/* RCC���� */
    RCC_HSEConfig(RCC_HSE_ON); /*ʹ��HSE*/
    HSEStartUpStatus = RCC_WaitForHSEStartUp();
    if(HSEStartUpStatus == SUCCESS)   //�ⲿ����ʹ�ܳɹ�
    {
        RCC_HCLKConfig(RCC_SYSCLK_Div1); /* ����HCLK = SYSCLK */
        RCC_PCLK2Config(RCC_HCLK_Div1); /* ����PCLK2 = HCLK */
        RCC_PCLK1Config(RCC_HCLK_Div2); /* ����PCLK1 = HCLK/2 */

        FLASH_SetLatency(FLASH_Latency_2);
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  /* RCC_PLLSource_HSE_Div1Ϊ���þ���ķ�Ƶϵ��;RCC_PLLMul_9Ϊ��Ƶ�� */
        RCC_PLLCmd(ENABLE);
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); //�ȴ�pll����
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);   /* ѡ��PLLΪϵͳ��ʱ�� */
        while(RCC_GetSYSCLKSource() != 0x08); //�ж�pll�Ƿ�Ϊϵͳʱ��
		return 1;

	}
	else
		return 0;
}


uint8_t systickInit(void)
{
	return SysTick_Config(72); //��1000����1us
}


void ledInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;//����GPIO��ʼ���ṹ��

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE); //ʹ��GPOIA,GPIOB����ʱ��	   
   	
    //LED GPIO��ʼ��
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
