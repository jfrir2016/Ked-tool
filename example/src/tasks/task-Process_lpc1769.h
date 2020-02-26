/*--------------------------------------------------------------------*-

    task-base_lpc1769.h (Released 2019-04)

--------------------------------------------------------------------

    - See task-base_lpc1769.c for details.

-*--------------------------------------------------------------------*/

#include "main.h"

//#ifndef SRC_TASKS_TASK_PROCESS_LPC1769_H_
//#define SRC_TASKS_TASK_PROCESS_LPC1769_H_ 1


// ------ Public constants -----------------------------------------
#define RED		0
#define	BLUE 	1
#define GREEN	2

#define NOFINPUTS 7
#define NOFOUTPUTS 8
#define NOFSYSTEMS 20

// ------ Private constants -----------------------------------------
#define START		0
#define DETECT		1
#define	CONDITION	2
#define	OUT			3
#define JUMP		4
#define FINISH		5

#define SETEO	0
#define VALUE	1

// ------ Public data type declarations ----------------------------
uint8_t IsConditional(uint8_t);
uint8_t IsOutput(uint8_t);
uint8_t IsJump(uint8_t);
uint8_t IsLogic(uint8_t data);
void Update(uint8_t*);
void ResetProgram(void);

// ------ Public function prototypes -------------------------------
void Process_Init(void);
void Process_Update(void);

//#endif /* SRC_TASKS_TASK_PROCESS_LPC1769_H_ */
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
