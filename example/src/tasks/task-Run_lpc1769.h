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

#define BUTTON1		1
#define BUTTON2		2
#define	BUTTON3		3
#define	BUTTON4		4
#define SENSOR1		5
#define SENSOR2		6

// ------ Public data type declarations ----------------------------
typedef struct act {
	uint8_t *Destino;
	uint8_t *DestinoDelValor;
	uint8_t Valor;
	struct act *nxt;
} Action;

typedef struct sys {
	uint8_t Previous;
	uint8_t ConditionResult;
	uint8_t Inputs[INPUTSSIMULTANEOS];
	uint8_t ValuesIn[INPUTSSIMULTANEOS];
	Action*	Actions[2];
} System;


// ------ Public function prototypes -------------------------------
void Run_Init(void);
void Run_Update(void);

void UpdateProgram(void);
void UpdateFree(void);
Bool ComplyAllConditions(uint8_t);
Bool ReadInput(uint8_t);

void UpdateDisplays(void);
void UpdateLeds(void);

#endif /* SRC_TASKS_TASK_RUN_LPC1769_H_ */
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
