/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MuxA_Sig1_Pin GPIO_PIN_13
#define MuxA_Sig1_GPIO_Port GPIOC
#define MuxA_Sig2_Pin GPIO_PIN_14
#define MuxA_Sig2_GPIO_Port GPIOC
#define MuxA_Sig3_Pin GPIO_PIN_15
#define MuxA_Sig3_GPIO_Port GPIOC
#define Analog_MuxA_Pin GPIO_PIN_0
#define Analog_MuxA_GPIO_Port GPIOC
#define Analog_MuxB_Pin GPIO_PIN_1
#define Analog_MuxB_GPIO_Port GPIOC
#define MuxB_Sig1_Pin GPIO_PIN_10
#define MuxB_Sig1_GPIO_Port GPIOA
#define MuxB_SIg0_Pin GPIO_PIN_11
#define MuxB_SIg0_GPIO_Port GPIOA
#define MuxB_Sig2_Pin GPIO_PIN_10
#define MuxB_Sig2_GPIO_Port GPIOC
#define MuxB_Sig3_Pin GPIO_PIN_11
#define MuxB_Sig3_GPIO_Port GPIOC
#define MuxA_Sig0_Pin GPIO_PIN_12
#define MuxA_Sig0_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
