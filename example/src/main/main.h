/*--------------------------------------------------------------------*-

    main.h (Released 2019-04)

  --------------------------------------------------------------------

    This is the Project Header file.

-*--------------------------------------------------------------------*/


#ifndef _MAIN_H
#define _MAIN_H 1


// Links to target libraries
#include "board.h"
#include "chip.h"
#include <stdlib.h>

// System header
#include "../c-tds/system_lpc1769.h"

// Scheduler header
#include "../c-tds/scheduler_lpc1769.h"

// Port header
#include "../c-tds/port_lpc1769.h"

// Monittor header
#include "../c-tds/monittor_lp1769.h"

// Tasks header
#include "../tasks/task-Run_lpc1769.h"
#include "../tasks/task-Process_lpc1769.h"
#include "../tasks/task-Download_lpc1769.h"

// ------ Public constants -----------------------------------------
/*****************************************************************************
 * GPIO Description
 ****************************************************************************/
//Display D2
#define SEG_A_D2_PORT		0
#define SEG_A_D2_PIN		23
#define SEG_B_D2_PORT		0
#define SEG_B_D2_PIN		26
#define SEG_C_D2_PORT		0
#define SEG_C_D2_PIN		25
#define SEG_D_D2_PORT		0
#define SEG_D_D2_PIN		24

//Display S1
#define SEG_A_D1_PORT		1
#define SEG_A_D1_PIN		8
#define SEG_B_D1_PORT		1
#define SEG_B_D1_PIN		0
#define SEG_C_D1_PORT		1
#define SEG_C_D1_PIN		1
#define SEG_D_D1_PORT		1
#define SEG_D_D1_PIN		4

//LED RGB_1
#define LED1_RED_PORT		0//0	//0 TODO BORRAR!!! SOLO PARA STICK
#define LED1_RED_PIN		17//22	//17
#define LED1_BLUE_PORT		0//3	//0
#define LED1_BLUE_PIN		18//26	//18
#define LED1_GREEN_PORT		2//3	//2
#define LED1_GREEN_PIN		8//25	//8

//LED RGB_2
#define LED2_GREEN_PORT		0
#define LED2_GREEN_PIN		19
#define LED2_RED_PORT		0
#define LED2_RED_PIN		20
#define LED2_BLUE_PORT		0
#define LED2_BLUE_PIN		21

//LED RGB_3
#define LED3_GREEN_PORT		2
#define LED3_GREEN_PIN		3
#define LED3_RED_PORT		2
#define LED3_RED_PIN		4
#define LED3_BLUE_PORT		2
#define LED3_BLUE_PIN		5

//LEDS_IR
#define EMISOR_IR1_PORT		2
#define EMISOR_IR1_PIN		6
#define EMISOR_IR2_PORT		2
#define EMISOR_IR2_PIN		7

//IR_FOTOTR
#define TR_IR1_PORT			1
#define TR_IR1_PIN			9
#define TR_IR2_PORT			1
#define TR_IR2_PIN			10

//BUTTONS
#define PB1_PORT			0//2	//0
#define PB1_PIN				8//10	//8
#define PB2_PORT			0//0	//0
#define PB2_PIN				6//18	//6
#define PB3_PORT			0//0	//0
#define PB3_PIN				7//11	//7
#define PB4_PORT			0//2	//0
#define PB4_PIN				5//13	//5

//MOTORES
#define M1_PORT				2
#define M1_PIN				9
#define M2_PORT				0
#define M2_PIN				16

// ------ Public data type -----------------------------------------


// ------ Public function prototypes -------------------------------
void Board_HW_Set(void);
void Board_HW_Init(void);

#endif


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
