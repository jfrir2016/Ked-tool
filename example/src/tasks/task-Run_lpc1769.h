/*--------------------------------------------------------------------*-

    task-base_lpc1769.h (Released 2019-04)

--------------------------------------------------------------------

    - See task-base_lpc1769.c for details.

-*--------------------------------------------------------------------*/



#ifndef SRC_TASKS_TASK_RUN_LPC1769_H_
#define SRC_TASKS_TASK_RUN_LPC1769_H_ 1

// ------ Public constants -----------------------------------------
#define RUN 		0
#define DOWNLOAD	1
#define PROCESS		2

#define INPUTSSIMULTANEOS 5

// ------ Public data type declarations ----------------------------
typedef struct act {
	uint8_t *Destino;
	uint8_t *DestinoDelValor;
	uint8_t Valor;
	struct act *nxt;
} Action;

typedef struct sys {
	uint8_t Previous;
	uint8_t Inputs[INPUTSSIMULTANEOS];
	uint8_t ValuesIn[INPUTSSIMULTANEOS];
	Action  *Actions;
} System;


// ------ Public function prototypes -------------------------------
void Run_Init(void);
void Run_Update(void);

void UpdateFree(void);
void UpdateButtons(void);
void UpdateDisplays(void);
void UpdateLeds(void);

#endif /* SRC_TASKS_TASK_RUN_LPC1769_H_ */
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
