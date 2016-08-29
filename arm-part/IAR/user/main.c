#include "stm32f10x.h"
#include "os.h"
#include "bsp.h"
#include "systeminit.h"

#define  APP_TASK_START_PRIO                        2
#define  APP_TASK_START_STK_SIZE                    128

static OS_TCB       AppTaskStartTCB;

static OS_MUTEX     AppMutex;
static OS_Q         AppQ;

static CPU_STK      AppTaskStartStk[128];

static void AppTaskStart(void *p_arg);

int main(void)
{
    OS_ERR err;
    
    sysclockInit();
    
    BSP_IntDisAll();
    OSInit(&err);
    
    OSMutexCreate((OS_MUTEX *)&AppMutex,
        		  (CPU_CHAR *)"My App Mutex",
    			  (OS_ERR	*)&err);

    OSQCreate((OS_Q  	*)&AppQ,
    		  (CPU_CHAR *)"My App Queue",
    		  (OS_MSG_QTY)10,
    		  (OS_ERR	*)&err);
    
    OSTaskCreate((OS_TCB 	 *)&AppTaskStartTCB, 
				 (CPU_CHAR 	 *)"App Task Start",
				 (OS_TASK_PTR )AppTaskStart,
				 (void 		 *)0,
				 (OS_PRIO 	  )APP_TASK_START_PRIO,
				 (CPU_STK 	 *)&AppTaskStartStk[0],
				 (CPU_STK_SIZE)APP_TASK_START_STK_SIZE / 10,
				 (CPU_STK_SIZE)APP_TASK_START_STK_SIZE,
				 (OS_MSG_QTY  )0,
				 (OS_TICK 	  )0,
				 (void 		 *)0,
				 (OS_OPT 	  )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
				 (OS_ERR 	 *)&err);    

    OSStart(&err);
    
}

static void AppTaskStart(void *p_arg)
{
    OS_ERR err;
    
    BSP_Init();
    CPU_Init();
    
    ledInit();
    
    while(1)
    {
        LedA_on;
        OSTimeDlyHMSM(0, 0, 0, 200,                     /* Delay task for 200 ms                             */  
                      OS_OPT_TIME_HMSM_STRICT,  
                      &err);  
        LedA_off;
        OSTimeDlyHMSM(0, 0, 0, 200,                                 
                      OS_OPT_TIME_HMSM_STRICT,  
                      &err);         
    }
}