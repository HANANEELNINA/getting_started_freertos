/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

extern xQueueHandle q_data, q_print;
extern TaskHandle_t menu_task_h = NULL;
extern TaskHandle_t cmd_task_h = NULL;
extern TaskHandle_t print_task_h = NULL;
extern TaskHandle_t led_task_h = NULL;
extern TaskHandle_t rtc_task_h = NULL;

void menu_task (void * pvT1_params );

void cmd_task (void * pvT2_params );

void print_task (void * pvT3_params );

void led_task (void * pvT4_params );

void rtc_task (void * pvT5_params );


typedef struct {
	uint8_t payload[10];
	uint8_t len;

}command_t;

typedef enum{
	sMainMenu = 0,
	sLedEffect,
	sRtcMenu,
	sRtcDateConfig,
	sRtcDateConfig,
	sRtcReport,

}state_t;

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
