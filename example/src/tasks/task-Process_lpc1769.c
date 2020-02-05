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


// --- NUEVO!!! ------------

uint8_t *DirSalidas[NOFOUTPUTS][2];

System Program[NOFSYSTEMS];
Action* Entradas[NOFINPUTS];
uint8_t ValuesIn[NOFINPUTS];

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
	uint8_t i;

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

	for(i = 0; i < NOFINPUTS; i++){
		Entradas[i] = 0;
		ValuesIn[i] = 0;
	}
}

/*------------------------------------------------------------------*-

    Process_Update()
-*------------------------------------------------------------------*/
void Process_Update(void)
{
	uint8_t data, prev, i;
	Action *new, *aux;
	static uint8_t Type = START;
	static uint8_t cont = 0;
	static uint8_t hard = 0, and = FALSE;
	static uint8_t indx = 0;
	static uint8_t in = 0, inNumber = 0;

	//TODO implementar maquina de estados para procesar 					ok!
	//TODO refrescar los registros cuando se inicia el proceso

	//TODO muchas salidas en un solo condicional 							ok!
	//TODO salidas sin condicional 											ok!
	//TODO poder poner un condicional dentro de otro
	//TODO implementar AND y OR
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
					prev = indx;
					Update(&indx);
					Program[indx].Previous = prev;
				}
				if(IsOutput(data)){
					Type = OUT;
				}
				if(data == 'A'){ //TODO Falta pensar OR
					and = TRUE;
					inNumber++; // TODO cuando vuelve a 0???
					Type = CONDITION;
				}
				if(IsJump(data)){
					indx = Program[indx].Previous;
				}
				hard = data;
				cont = 0;
				break;
			case CONDITION:
				cont++;
				if(cont == 1)
					in = data - 'N';

				if(cont == 2){
					in = in + data - '1';

					if(indx > 1 && !and){
						prev = Program[indx].Previous;
						for(i = 0; Program[prev].Inputs[i] != 0; i++){
							Program[indx].Inputs[i] = Program[prev].Inputs[i];
						}
						inNumber = i;
					}
					Program[indx].Inputs[inNumber] = in;
				}

				if(cont == 3){
					Program[indx].ValuesIn[inNumber] = data - '0';
					cont = 0;
					Type = DETECT;
				}
				break;
			case OUT: //TODO ver salidas particulares
				cont++;
				if (cont == 1){
					dirSet = DirSalidas[(hard -'G') + (data - '1')][SETEO];
					dirValue = DirSalidas[(hard -'G') + (data - '1')][VALUE];
					break;
				}
				if(cont == 2){
					Value = (data - '0');
					new = (Action*) malloc(sizeof(Action));
					new->Destino = dirSet;
					new->DestinoDelValor = dirValue;
					new->Valor = Value;
					new->nxt = 0;
					if(Program[indx].Actions){
						for(aux = Program[indx].Actions; aux->nxt != 0; aux = aux->nxt);
						aux->nxt = new;
					}
					else{
						Program[indx].Actions = new;
					}
					cont = 0;
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

uint8_t Detection(uint8_t data){

}

uint8_t IsConditional(uint8_t data){
	uint8_t ret = 0;
	if(data == 'W' || data == 'Y' || data == 'Z'){
		ret = 1;
	}
	return ret;
}

uint8_t IsOutput(uint8_t data){
	if(data == 'G' || data == 'I' || data == 'K' || data == 'L'){
		return 1;
	}
	return 0;
}

uint8_t IsJump(uint8_t data){
	if(data == 'X'){
		return 1;
	}
	return 0;
}

uint8_t IsLogic(uint8_t data){
	if(data == 'A' || data == 'B'){
		return 1;
	}
	return 0;
}

void Update(uint8_t *i){
	for(; Program[*i].Inputs[0] != 0; *i++);
}
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
