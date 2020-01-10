/*--------------------------------------------------------------------*-

    task-Process_lpc1769.c (Released 2019-04)

  --------------------------------------------------------------------

- Detalle de funcionamiento de tarea

-*--------------------------------------------------------------------*/


// Project header
#include "task-Process_lpc1769.h"

#include "../main/main.h"


// Task header


// ------ Global registers ----------------------------------------
extern uint8_t SetLed1;
extern uint8_t SetLed2;
extern uint8_t SetLed3;
extern uint8_t SetMotor1;
extern uint8_t SetMotor2;
extern uint8_t SetDisplay1;
extern uint8_t SetDisplay2;
extern uint8_t SetServo;

extern uint8_t ValueLed1;
extern uint8_t ValueLed2;
extern uint8_t ValueLed3;
extern uint8_t SenseMotor1;
extern uint8_t SenseMotor2;
extern uint8_t ValueServo;
extern uint8_t ValueDisplay1;
extern uint8_t ValueDisplay2;

extern uint8_t *ActionPulsador1;
extern uint8_t *ActionPulsador2;
extern uint8_t *ActionPulsador3;
extern uint8_t *ActionPulsador4;
extern uint8_t *ActionSensor1;
extern uint8_t *ActionSensor2;

// ------ Private varible ----------------------------------------
uint8_t Type;

// --- NUEVO!!! ------------

uint8_t *DirSalidas[8][2];

Action* Entradas[6];
uint8_t ValuesIn[6];

// ------ Private data type ----------------------------------------
uint8_t *dirSet = 0;
uint8_t *dirValue = 0;
uint8_t Value = 0;

// ------ Public variable -----------------------------------------
uint8_t Start_Process = 0;
uint8_t Finish_Process = 0;

// ------ External variable -----------------------------------------
extern uint8_t STATE;
extern RINGBUFF_T rxring;

/*------------------------------------------------------------------*-

    Process_Init()
-*------------------------------------------------------------------*/
void Process_Init(void)
{
	DirSalidas[0][0]	= &SetDisplay1;
	DirSalidas[0][1] 	= &ValueDisplay1;
	DirSalidas[1][0]	= &SetDisplay2;
	DirSalidas[1][1] 	= &ValueDisplay2;

	DirSalidas[2][0]	= &SetMotor1;
	DirSalidas[2][1] 	= &SenseMotor1;
	DirSalidas[3][0]	= &SetMotor2;
	DirSalidas[3][1] 	= &SenseMotor2;

	DirSalidas[4][0]	= &SetServo;
	DirSalidas[4][1] 	= &ValueServo;

	DirSalidas[5][0]	= &SetLed1;
	DirSalidas[6][0]	= &SetLed2;
	DirSalidas[7][0]	= &SetLed3;
	DirSalidas[5][1] 	= &ValueLed1;
	DirSalidas[6][1] 	= &ValueLed2;
	DirSalidas[7][1] 	= &ValueLed3;
}

/*------------------------------------------------------------------*-

    Process_Update()
-*------------------------------------------------------------------*/
void Process_Update(void)
{
	uint8_t data;
	static uint8_t cont = 0;
	static uint8_t hard = 0;
	static uint8_t indx = 0;

	//TODO implementar maquina de estados para procesar
	//TODO refrescar los registros cuando se inicia el proceso

	//TODO muchas salidas en un solo condicional
	//TODO salidas sin condicional
	//TODO poder poner un condicional dentro de otro
	//TODO implementar while, repeat, delay

	if(STATE == PROCESS){
		if(RingBuffer_Pop(&rxring, &data)){

			switch (Type){
			case START:
				if(data == 'C'){
					Type = DETECT;
				}
				break;
			case DETECT:
				if(data == 'F'){
					Type = FINISH;
				}
				if(IsConditional(data)){
					Type = CONDITION;
				}
				if(IsOutput(data)){
					Type = OUT;
				}
				hard = data;
				cont = 0;
				break;
			case CONDITION:
				if(cont == 0){
					indx = data - 'O';
					cont++;
				}
				if(cont == 1){
					indx = indx + data - '1';
					Entradas[indx] = malloc(sizeof(Action));
					cont++;
				}
				if(cont == 2){
					ValuesIn[indx] = data - '0';
					cont = 0;
					Type = DETECT;
				}
				break;
			case OUT:
				if (cont == 0){
					dirSet = DirSalidas[(hard -'G') + (data - '1')][SETEO];
					dirValue = DirSalidas[(hard -'G') + (data - '1')][VALUE];
					cont++;
					break;
				}
				if(cont == 1){
					Value = (data - '0');
					cont = 0;
					Entradas[indx]->Destino = dirSet;
					Entradas[indx]->ValorDestino = dirValue;
					Entradas[indx]->Valor = Value;
					Entradas[indx]->nxt = 0;
					Type = DETECT;
				}
				break;
			case FINISH:
				Type = START;
				STATE = RUN;
			}
		}
	}
}

uint8_t IsConditional(uint8_t data){
	uint8_t ret = 0;
	if(data == 'I' || data == 'R' || data == 'W'){
		ret = 1;
	}
	return ret;
}

uint8_t IsOutput(uint8_t data){
	if(data == 'M' || data == 'Z' || data == 'L' || data == 'G'){
		return 1;
	}
	return 0;
}
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
