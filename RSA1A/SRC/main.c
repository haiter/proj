
#include "stm32f10x.h"

GPIO_InitTypeDef GPIO_InitStructure;

void RCC_Configuration(void);

void Delay(__IO uint32_t nCount);

int main(){

	//uint16_t a;
	  /* System Clocks Configuração **********************************************/

	  RCC_Configuration();

	  //
	  /* Configura todos não usados pinos para Analogico Input modo (floating input
	     trigger OFF), para diminuir consumo e evitar interferencia EMI/EMC *************************************************/

	  RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1 |RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
	                         RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
	                         RCC_APB2Periph_GPIOE, ENABLE);


	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;				     //D1  D2
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(GPIOC, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_13;		 //D3, D4
	  GPIO_Init(GPIOD, &GPIO_InitStructure);

	  while (1)
	    {
	      GPIO_SetBits(GPIOC, GPIO_Pin_6);

	      GPIO_SetBits(GPIOC, GPIO_Pin_7 );
	      GPIO_ResetBits(GPIOC, GPIO_Pin_6);
	      Delay(0xAFFFF);

	      GPIO_SetBits(GPIOD, GPIO_Pin_13 );
	      GPIO_ResetBits(GPIOC, GPIO_Pin_7);
	      Delay(0xAFFFF);

	      GPIO_SetBits(GPIOD, GPIO_Pin_6 );
	      GPIO_ResetBits(GPIOD, GPIO_Pin_13);
	      Delay(0xAFFFF);

	      GPIO_ResetBits(GPIOD, GPIO_Pin_6);
	    }


return 0;
}

void RCC_Configuration(void)
{
  /* Setup the microcontroller system. Initialize the Embedded Flash Interface,
     initialize the PLL and update the SystemFrequency variable. */
  SystemInit();
}


void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

void _init(int a){

	while(1){

	}
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */



void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
