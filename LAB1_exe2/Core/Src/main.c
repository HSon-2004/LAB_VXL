/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int count;
int count1;
int count2;
int hour;
int minute;
int second;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void Exercise1_run();
void Exercise2_run();
void Exercise3_run();
void display7SEG(int num);
void display7SEG_2(int num);
void Exercise4_run();
void Exercise5_run();
void Exercise6_run();
void openAllClock();
void clearAllClock();
void setNumberOnClock(int num);
void clearNumberOnClock(int num);
void Exercise10_run();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  count = 0;
  count1 = 0;
  count2 = 0;
  hour = 10;
  minute = 15;
  second = 0;
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //Exercise1_run();
	  //Exercise2_run();
	  //Exercise3_run();
	  //Exercise4_run();
	  //Exercise5_run();
	  //Exercise6_run();
	  Exercise2_run();
	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SEG7_Pin|SEG8_Pin|SEG9_Pin|LED_RED_Pin
                          |LED_YELLOW_Pin|LED_GREEN_Pin|SEG0_Pin|SEG1_Pin
                          |SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|SEG10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin|LED3_Pin|LED11_Pin
                          |LED12_Pin|SEG11_Pin|SEG12_Pin|SEG13_Pin
                          |LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin
                          |LED8_Pin|LED9_Pin|LED10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SEG7_Pin SEG8_Pin SEG9_Pin LED_RED_Pin
                           LED_YELLOW_Pin LED_GREEN_Pin SEG0_Pin SEG1_Pin
                           SEG2_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin SEG10_Pin */
  GPIO_InitStruct.Pin = SEG7_Pin|SEG8_Pin|SEG9_Pin|LED_RED_Pin
                          |LED_YELLOW_Pin|LED_GREEN_Pin|SEG0_Pin|SEG1_Pin
                          |SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|SEG10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin LED11_Pin
                           LED12_Pin SEG11_Pin SEG12_Pin SEG13_Pin
                           LED4_Pin LED5_Pin LED6_Pin LED7_Pin
                           LED8_Pin LED9_Pin LED10_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin|LED11_Pin
                          |LED12_Pin|SEG11_Pin|SEG12_Pin|SEG13_Pin
                          |LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin
                          |LED8_Pin|LED9_Pin|LED10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void Exercise1_run()
{
	if (count>=4) count = 0;

	if (count <2)
	{
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	}
	if (count >= 2)
	{
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	}
	count++;
}

void Exercise2_run()
{
	if (count >= 10) count = 0;
	if (count < 5)
	{
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	}
	if (count >= 5)
	{
		if (count < 7)
		{
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		}
		if (count >= 7)
		{
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
		}
	}
	count++;
}

void Exercise3_run()
{
	if (count < 5)
		{
			if (count < 3)
			{
				HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
				HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED3_GPIO_Port, LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
				HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, SET);
				HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, SET);
			}

			if (count >= 3)
			{
				HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
				HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED3_GPIO_Port, LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
				HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
				HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, SET);
				HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
				HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, SET);
				HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
			}
		}
		if (count >= 5)
		{
			if (count < 8)
			{
				HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
				HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
				HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
				HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, SET);
				HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
				HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
				HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, SET);
				HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, SET);
				HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
			}
			if (count >= 8)
			{
				HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
				HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
				HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
				HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, SET);
				HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
				HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
				HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
				HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, SET);
				HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
				HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, SET);
				HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
				HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
			}
		}
		count++;
		if (count >= 10) count = 0;
}

void display7SEG(int num)
{
	switch (num){
	case 0:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	default:
		break;
	}
}

void Exercise4_run()
{
	if (count >= 10) count = 0;
	display7SEG(count++);
}

void display7SEG_2(int num)
{
	switch (num){
	case 0:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, RESET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, SET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, SET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, SET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, SET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, RESET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, SET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, SET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, SET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, SET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, SET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, SET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, RESET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, SET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, SET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, RESET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
		HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
		HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
		HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
		HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
		HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
		break;
	default:
		break;
	}
}

void Exercise5_run()
{
	switch (count){
	case 0:
		count1 = 5;
		count2 = 3;
		break;
	case 3:
		count2 = 2;
		break;
	case 5:
		count1 = 3;
		count2 = 5;
		break;
	case 8:
		count1 = 2;
		break;
	default:
		break;
	}
	display7SEG(count1);
	display7SEG_2(count2);
	Exercise3_run();
	count1--;
	count2--;
}

void Exercise6_run()
{
	if (count>=12) count = 0;
	switch (count)
	{
	case 0:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, SET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, SET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, SET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, SET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, SET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 10:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 11:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, SET);
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	default:
		break;
	}
	count++;
}

void openAllClock()
{
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, SET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, SET);
	HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, SET);
	HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, SET);
	HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, SET);
	HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, SET);
	HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, SET);
}

void clearAllClock()
{
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
	HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
	HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
	HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
	HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
	HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
}

void setNumberOnClock(int num)
{
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
		break;
	case 9:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
		break;
	case 10:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
		break;
	case 11:
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, SET);
		break;
	default:
		break;
	}
}

void clearNumberOnClock(int num)
{
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
		break;
	case 10:
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
		break;
	case 11:
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, RESET);
		break;
	default:
		break;
	}
}

void Exercise10_run()
{
	int tmp1= (second-1) / 5;
	int tmp2= second / 5;
	if (tmp1 != tmp2) clearNumberOnClock(tmp1);
	setNumberOnClock(second / 5);

	if (second >= 60)
	{
		minute++;
		second = 0;
		int tmp3=(minute-1) / 5;
		int tmp4= minute / 5;
		if (tmp3!= tmp4)clearNumberOnClock(tmp3);
	}
	if (minute >= 60)
	{
		clearNumberOnClock(hour++);
		minute = 0;
	}
	if (hour >= 12){
		hour = 0;
	}

	setNumberOnClock(minute / 5);

	setNumberOnClock(hour);

	second++;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
