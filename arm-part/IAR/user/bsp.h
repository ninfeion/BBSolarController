#ifndef _BSP_H_  
#define _BSP_H_  
  
#include  <stdarg.h>  
#include  <stdio.h>  
  
#include  <cpu.h>  
#include  <cpu_core.h>  
  
#include  <lib_ascii.h>  
#include  <lib_def.h>  
#include  <lib_mem.h>  
#include  <lib_str.h>  
  
#include  <stm32f10x.h>   
  
  
void         BSP_Init                    (void);  
void         BSP_IntDisAll               (void);  
CPU_INT32U   BSP_CPU_ClkFreq             (void);  
  
  
#endif  