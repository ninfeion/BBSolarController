/* Includes ------------------------------------------------------------------*/  
#include "bsp.h"

/* Private define ------------------------------------------------------------*/  
#define  DWT_CR      *(CPU_REG32 *)0xE0001000  
#define  DWT_CYCCNT  *(CPU_REG32 *)0xE0001004  
#define  DEM_CR      *(CPU_REG32 *)0xE000EDFC  
#define  DBGMCU_CR   *(CPU_REG32 *)0xE0042004  
  
#define  DEM_CR_TRCENA                   (1 << 24)  
#define  DWT_CR_CYCCNTENA                (1 <<  0)  
  
/* Periph functions ---------------------------------------------------------*/  
void SysTick_Configuration(void);  
  
void BSP_Init(void)  
{  
    /* Configure the SysTick to generate an interrupt each 1 millisecond */  
    SysTick_Configuration();  
}  
  
void  BSP_IntDisAll (void)  
{  
    CPU_IntDis();  
}  
  
CPU_INT32U  BSP_CPU_ClkFreq (void)  
{  
    RCC_ClocksTypeDef  rcc_clocks;  
  
  
    RCC_GetClocksFreq(&rcc_clocks);  
  
    return ((CPU_INT32U)rcc_clocks.HCLK_Frequency);  
}  
  
void  CPU_TS_TmrInit (void)  
{  
    CPU_INT32U  cpu_clk_freq_hz;  
  
  
    DEM_CR         |= (CPU_INT32U)DEM_CR_TRCENA;                /* Enable Cortex-M3's DWT CYCCNT reg.                   */  
    DWT_CYCCNT      = (CPU_INT32U)0u;  
    DWT_CR         |= (CPU_INT32U)DWT_CR_CYCCNTENA;  
  
    cpu_clk_freq_hz = BSP_CPU_ClkFreq();  
    CPU_TS_TmrFreqSet(cpu_clk_freq_hz);  
}  
  
CPU_TS_TMR  CPU_TS_TmrRd (void)  
{  
    return ((CPU_TS_TMR)DWT_CYCCNT);  
}  
  
  
/** 
  * @brief  Configures the SysTick to generate an interrupt each 1 ms. 
  * @param  None 
  * @retval None 
  */  
void SysTick_Configuration(void)  
{  
    /* SysTick interrupt each 1 ms with SysTick Clock equal to (HCLK/8) */  
    if (SysTick_Config(SystemCoreClock / 1000))  
    {  
        /* Capture error */  
        while (1);  
    }  
}  