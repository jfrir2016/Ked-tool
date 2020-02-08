/*
 * @brief Common SystemInit function for LPC17xx/40xx chips
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */
#include "main.h"

#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
#if defined(NO_BOARD_LIB)
/* System oscillator rate and RTC oscillator rate */
const uint32_t OscRateIn = 12000000;
const uint32_t RTCOscRateIn = 32768;
#endif

/*****************************************************************************
 * Private functions
 ****************************************************************************/
/* Initializes HW */
void Board_HW_Init(void)
{
	Chip_IOCON_PinMux(LPC_IOCON, 0, 22, IOCON_MODE_INACT, IOCON_FUNC0);
	Chip_IOCON_PinMux(LPC_IOCON, 3, 25, IOCON_MODE_INACT, IOCON_FUNC0);
	Chip_IOCON_PinMux(LPC_IOCON, 3, 26, IOCON_MODE_INACT, IOCON_FUNC0);
	Chip_IOCON_PinMux(LPC_IOCON, 2, 10, IOCON_MODE_INACT, IOCON_FUNC0);


	//INICIALIZACION DE LAS SALIDAS
	Chip_IOCON_PinMux(LPC_IOCON, 0, 23, IOCON_MODE_INACT, IOCON_FUNC0);//DISPLAY2
	Chip_IOCON_PinMux(LPC_IOCON, 0, 24, IOCON_MODE_INACT, IOCON_FUNC0);
	Chip_IOCON_PinMux(LPC_IOCON, 0, 25, IOCON_MODE_INACT, IOCON_FUNC0);
	Chip_IOCON_PinMux(LPC_IOCON, 0, 26, IOCON_MODE_INACT, IOCON_FUNC0);

	Chip_IOCON_PinMux(LPC_IOCON, 1, 1, IOCON_MODE_INACT, IOCON_FUNC0);//DISPLAY1
	Chip_IOCON_PinMux(LPC_IOCON, 1, 0, IOCON_MODE_INACT, IOCON_FUNC0);
	Chip_IOCON_PinMux(LPC_IOCON, 1, 4, IOCON_MODE_INACT, IOCON_FUNC0);
	Chip_IOCON_PinMux(LPC_IOCON, 1, 8, IOCON_MODE_INACT, IOCON_FUNC0);

	Chip_IOCON_PinMux(LPC_IOCON, 2, 6, IOCON_MODE_INACT, IOCON_FUNC0);//Emisor_IR1
	Chip_IOCON_PinMux(LPC_IOCON, 2, 7, IOCON_MODE_INACT, IOCON_FUNC0);//Emisor_IR2

	Chip_IOCON_PinMux(LPC_IOCON, 2, 3, IOCON_MODE_INACT, IOCON_FUNC0);//Green_LED1
	Chip_IOCON_PinMux(LPC_IOCON, 2, 4, IOCON_MODE_INACT, IOCON_FUNC0);//Red_LED1
	Chip_IOCON_PinMux(LPC_IOCON, 2, 5, IOCON_MODE_INACT, IOCON_FUNC0);//Blue_LED1

	Chip_IOCON_PinMux(LPC_IOCON, 0, 19, IOCON_MODE_INACT, IOCON_FUNC0);//Green_LED2
	Chip_IOCON_PinMux(LPC_IOCON, 0, 20, IOCON_MODE_INACT, IOCON_FUNC0);//Blue_LED2
	Chip_IOCON_PinMux(LPC_IOCON, 0, 21, IOCON_MODE_INACT, IOCON_FUNC0);//Blue_LED2

	Chip_IOCON_PinMux(LPC_IOCON, 0, 17, IOCON_MODE_INACT, IOCON_FUNC0);//Green_LED3
	Chip_IOCON_PinMux(LPC_IOCON, 0, 18, IOCON_MODE_INACT, IOCON_FUNC0);//Red_LED3
	Chip_IOCON_PinMux(LPC_IOCON, 2, 8, IOCON_MODE_INACT, IOCON_FUNC0);//Blue_LED3

	Chip_IOCON_PinMux(LPC_IOCON, 0, 5, IOCON_MODE_INACT, IOCON_FUNC0);//PB1
	Chip_IOCON_PinMux(LPC_IOCON, 0, 6, IOCON_MODE_INACT, IOCON_FUNC0);//PB2
	Chip_IOCON_PinMux(LPC_IOCON, 0, 7, IOCON_MODE_INACT, IOCON_FUNC0);//PB3
	Chip_IOCON_PinMux(LPC_IOCON, 0, 8, IOCON_MODE_INACT, IOCON_FUNC0);//PB4

	Chip_IOCON_PinMux(LPC_IOCON, 1, 9, IOCON_MODE_INACT, IOCON_FUNC0);//Transistor_IR1
	Chip_IOCON_PinMux(LPC_IOCON, 1, 10, IOCON_MODE_INACT, IOCON_FUNC0);//Transistor_IR2

	//DISPLAY2
	Chip_GPIO_WriteDirBit(LPC_GPIO, SEG_A_D2_PORT, SEG_A_D2_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, SEG_B_D2_PORT, SEG_B_D2_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, SEG_C_D2_PORT, SEG_C_D2_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, SEG_D_D2_PORT, SEG_D_D2_PIN, true);
	//DISPLAY1
	Chip_GPIO_WriteDirBit(LPC_GPIO, SEG_A_D1_PORT, SEG_A_D1_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, SEG_B_D1_PORT, SEG_B_D1_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, SEG_C_D1_PORT, SEG_C_D1_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, SEG_D_D1_PORT, SEG_D_D1_PIN, true);
	//LED_RGB1
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED1_RED_PORT, LED1_RED_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED1_GREEN_PORT, LED1_GREEN_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED1_BLUE_PORT, LED1_BLUE_PIN, true);
	//LED_RGB2
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED2_RED_PORT, LED2_RED_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED2_GREEN_PORT, LED2_GREEN_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED2_BLUE_PORT, LED2_BLUE_PIN, true);
	//LED_RGB3
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED3_RED_PORT, LED3_RED_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED3_GREEN_PORT, LED3_GREEN_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, LED3_BLUE_PORT, LED3_BLUE_PIN, true);
	//LEDS_IR
	Chip_GPIO_WriteDirBit(LPC_GPIO, EMISOR_IR1_PORT, EMISOR_IR1_PIN, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO, EMISOR_IR2_PORT, EMISOR_IR2_PIN, true);
	//PB
	Chip_GPIO_WriteDirBit(LPC_GPIO, PB1_PORT, PB1_PIN, false);
	Chip_GPIO_WriteDirBit(LPC_GPIO, PB2_PORT, PB2_PIN, false);
	Chip_GPIO_WriteDirBit(LPC_GPIO, PB3_PORT, PB3_PIN, false);
	Chip_GPIO_WriteDirBit(LPC_GPIO, PB4_PORT, PB4_PIN, false);
}

void Board_HW_Set(){

	Chip_GPIO_WritePortBit(LPC_GPIO, LED1_RED_PORT, LED1_RED_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, LED2_RED_PORT, LED2_RED_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, LED3_RED_PORT, LED3_RED_PIN, false);

	Chip_GPIO_WritePortBit(LPC_GPIO, LED2_GREEN_PORT, LED2_GREEN_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, LED3_GREEN_PORT, LED3_GREEN_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, LED1_GREEN_PORT, LED1_GREEN_PIN, false);

	Chip_GPIO_WritePortBit(LPC_GPIO, LED2_BLUE_PORT, LED2_BLUE_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, LED3_BLUE_PORT, LED3_BLUE_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, LED1_BLUE_PORT, LED1_BLUE_PIN, false);

	Chip_GPIO_WritePortBit(LPC_GPIO, EMISOR_IR1_PORT, EMISOR_IR1_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, EMISOR_IR2_PORT, EMISOR_IR2_PIN, false);

	Chip_GPIO_WritePortBit(LPC_GPIO, SEG_A_D2_PORT, SEG_A_D2_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, SEG_B_D2_PORT, SEG_B_D2_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, SEG_C_D2_PORT, SEG_C_D2_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, SEG_D_D2_PORT, SEG_D_D2_PIN, false);

	Chip_GPIO_WritePortBit(LPC_GPIO, SEG_A_D1_PORT, SEG_A_D1_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, SEG_B_D1_PORT, SEG_B_D1_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, SEG_C_D1_PORT, SEG_C_D1_PIN, false);
	Chip_GPIO_WritePortBit(LPC_GPIO, SEG_D_D1_PORT, SEG_D_D1_PIN, false);
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* Set up and initialize hardware prior to call to main */
void SystemInit(void)
{
	unsigned int *pSCB_VTOR = (unsigned int *) 0xE000ED08;

#if defined(__IAR_SYSTEMS_ICC__)
	extern void *__vector_table;

	*pSCB_VTOR = (unsigned int) &__vector_table;
#elif defined(__CODE_RED)
	extern void *g_pfnVectors;

	*pSCB_VTOR = (unsigned int) &g_pfnVectors;
#elif defined(__ARMCC_VERSION)
	extern void *__Vectors;

	*pSCB_VTOR = (unsigned int) &__Vectors;
#endif

#if defined(__FPU_PRESENT) && __FPU_PRESENT == 1
	fpuInit();
#endif

#if defined(NO_BOARD_LIB)
	/* Chip specific SystemInit */
	Chip_SystemInit();
#else
	/* Setup system clocking and muxing */
	Board_SystemInit();
#endif
}
