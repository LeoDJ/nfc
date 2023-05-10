/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

#include "debug.h"
#include "NFC_Reader.h"

/* ÿ���ļ�����debug��ӡ�Ŀ��أ���0���Խ�ֹ���ļ��ڲ���ӡ */
#define DEBUG_PRINT_IN_THIS_FILE 1
#if DEBUG_PRINT_IN_THIS_FILE
    #define PRINTF(...) printf_(__VA_ARGS__)
#else
    #define PRINTF(...) do {} while (0)
#endif

/*********************************************************************
 * @fn      sys_periph_clock_init
 *
 * @brief   ��ǰ�������õ�������ʱ������
 *
 * @param   None.
 *
 * @return  None.
 */
void sys_periph_clock_init(void)
{
    /* ����ʱ�� */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  /* ����DMAʱ�� */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM4, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | \
            RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_TIM1 | \
            RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE );
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2 );
    Delay_Init();
    USART_Printf_Init( 115200 );
    PRINTF( "SystemClk:%d\r\n", SystemCoreClock );

    sys_periph_clock_init();

    nfc_signal_bsp_init();

	while(1);
}

