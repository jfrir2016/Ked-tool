/*--------------------------------------------------------------------*-

    task-Run_lpc1769.c (Released 2019-04)

  --------------------------------------------------------------------

- Detalle de funcionamiento de tarea

-*--------------------------------------------------------------------*/


// Project header
#include "../main/main.h"

#include "task-Run_lpc1769.h"

// Task header
// ------ Set registers ------------------------------------------
uint8_t SetLed1 	= 0;
uint8_t SetLed2 	= 0;
uint8_t SetLed3 	= 0;
uint8_t Display 	= 0;
uint8_t SetMotor1	= 0;
uint8_t SetMotor2 	= 0;
uint8_t SetDisplay1 = 0;
uint8_t SetDisplay2 = 0;
uint8_t SetServo 	= 0;

// ------ Value registers ----------------------------------------
uint8_t ValueLed1 	= 0;
uint8_t ValueLed2 	= 0;
uint8_t ValueLed3 	= 0;
uint8_t SenseMotor1	= 0;
uint8_t SenseMotor2	= 0;
uint8_t ValueServo 	= 0;
uint8_t ValueDisplay1 = 0;
uint8_t ValueDisplay2 = 0;

// ------ Action pointer registers ---------------------------------
uint8_t *ActionPulsador1 = 0;
uint8_t *ActionPulsador2 = 0;
uint8_t *ActionPulsador3 = 0;
uint8_t *ActionPulsador4 = 0;
uint8_t *ActionSensor1	= 0;
uint8_t *ActionSensor2 	= 0;

// ------ External variable -----------------------------------------
extern Action* Entradas[6];
extern uint8_t ValuesIn[6];

// ------ Private data type ----------------------------------------


// ------ Global variable -----------------------------------------
uint8_t STATE = DOWNLOAD; //RUN; TODO volver a poner RUN

/*------------------------------------------------------------------*-

    Run_Init()
-*------------------------------------------------------------------*/
void Run_Init(void)
{
	SetLed1 	= 1;
	ValueLed1 	= 5;
	SetDisplay2 = 1;
	SetDisplay1 = 1;
	SetDisplay2 = 0;
}

/*------------------------------------------------------------------*-

    Run_Update()
-*------------------------------------------------------------------*/
void Run_Update(void)
{
	if(STATE == RUN) {
		UpdateFree();
		UpdateButtons();
		UpdateDisplays();
		UpdateLeds();
	}
}

void UpdateFree(){
	Action *aux;

	if(Entradas[0] != 0){ //Creo que no hace falta el if
		for(aux = Entradas[0]; aux != 0; aux = aux->nxt){
			*aux->Destino = 1;
			*aux->DestinoDelValor = aux->Valor;
		}
	}
}

void UpdateButtons(void){
	uint8_t state;

	state = Chip_GPIO_ReadPortBit(LPC_GPIO, PB1_PORT, PB1_PIN);
	if(state == ValuesIn[1] && Entradas[1] != 0){
		*Entradas[1]->Destino = 1;
		*Entradas[1]->DestinoDelValor = Entradas[1]->Valor;
	}

	state = Chip_GPIO_ReadPortBit(LPC_GPIO, PB2_PORT, PB2_PIN);
	if(state == ValuesIn[2] && Entradas[2] != 0){
		*Entradas[2]->Destino = 1;
		*Entradas[2]->DestinoDelValor = Entradas[2]->Valor;
	}

	state = Chip_GPIO_ReadPortBit(LPC_GPIO, PB3_PORT, PB3_PIN);
	if(state == ValuesIn[3] && Entradas[3] != 0){
		*Entradas[3]->Destino = 1;
		*Entradas[3]->DestinoDelValor = Entradas[3]->Valor;
	}

	state = Chip_GPIO_ReadPortBit(LPC_GPIO, PB4_PORT, PB4_PIN);
	if(state == ValuesIn[4] && Entradas[4] != 0){
		*Entradas[4]->Destino = 1;
		*Entradas[4]->DestinoDelValor = Entradas[4]->Valor;
	}
}

void UpdateLeds(void){
	uint8_t red, blue, green;

	if(SetLed1){
		red = ValueLed1 & (1<<2);
		blue = ValueLed1 & (1<<1);
		green = ValueLed1 & (1<<0);

		Chip_GPIO_WritePortBit(LPC_GPIO, LED1_RED_PORT, LED1_RED_PIN, red);
		Chip_GPIO_WritePortBit(LPC_GPIO, LED1_BLUE_PORT, LED1_BLUE_PIN, blue);
		Chip_GPIO_WritePortBit(LPC_GPIO, LED1_GREEN_PORT, LED1_GREEN_PIN, green);
	}
	if(SetLed2){
		red = ValueLed2 & (1<<2);
		blue = ValueLed2 & (1<<1);
		green = ValueLed2 & (1<<0);

		Chip_GPIO_WritePortBit(LPC_GPIO, LED2_RED_PORT, LED2_RED_PIN, red);
		Chip_GPIO_WritePortBit(LPC_GPIO, LED2_BLUE_PORT, LED2_BLUE_PIN, blue);
		Chip_GPIO_WritePortBit(LPC_GPIO, LED2_GREEN_PORT, LED2_GREEN_PIN, green);
	}
	if(SetLed3){
		red = ValueLed3 & (1<<2);
		blue = ValueLed3 & (1<<1);
		green = ValueLed3 & (1<<0);

		Chip_GPIO_WritePortBit(LPC_GPIO, LED3_RED_PORT, LED3_RED_PIN, red);
		Chip_GPIO_WritePortBit(LPC_GPIO, LED3_BLUE_PORT, LED3_BLUE_PIN, blue);
		Chip_GPIO_WritePortBit(LPC_GPIO, LED3_GREEN_PORT, LED3_GREEN_PIN, green);
	}
	return;
}

void UpdateDisplays(void){
	uint8_t a, b, c, d;

	if(SetDisplay1){
		d = ValueDisplay1 & (1<<3);
		c = ValueDisplay1 & (1<<2);
		b = ValueDisplay1 & (1<<1);
		a = ValueDisplay1 & (1<<0);

		Chip_GPIO_WritePortBit(LPC_GPIO, SEG_A_D1_PORT, SEG_A_D1_PIN, a);
		Chip_GPIO_WritePortBit(LPC_GPIO, SEG_B_D1_PORT, SEG_B_D1_PIN, b);
		Chip_GPIO_WritePortBit(LPC_GPIO, SEG_C_D1_PORT, SEG_C_D1_PIN, c);
		Chip_GPIO_WritePortBit(LPC_GPIO, SEG_D_D1_PORT, SEG_D_D1_PIN, d);
	}
	if(SetDisplay2){
		d = ValueDisplay2 & (1<<3);
		c = ValueDisplay2 & (1<<2);
		b = ValueDisplay2 & (1<<1);
		a = ValueDisplay2 & (1<<0);

		Chip_GPIO_WritePortBit(LPC_GPIO, SEG_A_D2_PORT, SEG_A_D2_PIN, a);
		Chip_GPIO_WritePortBit(LPC_GPIO, SEG_B_D2_PORT, SEG_B_D2_PIN, b);
		Chip_GPIO_WritePortBit(LPC_GPIO, SEG_C_D2_PORT, SEG_C_D2_PIN, c);
		Chip_GPIO_WritePortBit(LPC_GPIO, SEG_D_D2_PORT, SEG_D_D2_PIN, d);
	}
	return;
}
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
