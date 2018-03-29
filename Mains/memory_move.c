
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "diag/Trace.h"
#include "Timer.h"

#define FLASH_DIR 0x20000000
#define SRAM_DIR 0x80000000

int main(void)
{
	char data[]= "Kostal Mexicana embedded :) ";

  for (int i =0; i < sizeof(data);i++)
  {
	  *((uint8_t*)FLASH_DIR + i) = data[i];
  }

 return 0;
}

// ----------------------------------------------------------------------------
