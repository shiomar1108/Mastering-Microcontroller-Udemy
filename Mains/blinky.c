
#include <stdio.h>
#include <stdlib.h>

#include "diag/Trace.h"
#include "Timer.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f446xx.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

void delay ()
{
	for(int i = 0; i < 5000000; i++);
	trace_printf("delay... \n");
}

int main(int argc, char* argv[])
{

  trace_puts("Hello ARM World!");

  trace_printf("System clock: %u Hz\n", SystemCoreClock);

  HAL_Init();

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitTypeDef led;
  led.Pin = GPIO_PIN_5;
  led.Mode = GPIO_MODE_OUTPUT_PP;
  led.Pull = GPIO_NOPULL;
  led.Speed = GPIO_SPEED_FREQ_MEDIUM;

  HAL_GPIO_Init(GPIOA, &led);

  while (1)
  {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
	  delay();
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	  delay();
  }

}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
