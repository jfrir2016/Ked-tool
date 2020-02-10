/*--------------------------------------------------------------------*-

    task-Uart0Tx_lpc1769.c (Released 2019-04)

  --------------------------------------------------------------------

- Detalle de funcionamiento de tarea

-*--------------------------------------------------------------------*/


// Project header
#include "task-Download_lpc1769.h"

#include "../main/main.h"


// Task header


// ------ Public variable ------------------------------------------

/* Receive ring buffers */
RINGBUFF_T rxring;

// ------ Private constants ----------------------------------------
#define UART_Def (LPC_UART3)	/* Defined uart */

/* Receive ring buffer size */
#define UART_RRB_SIZE 128	/* Receive */

/* Receive buffers */
static uint8_t  rxbuff[UART_RRB_SIZE];

// ------ Private data type ----------------------------------------
Bool Send_CharTo_RBUart_Tx(uint8_t);
Bool Send_StringTo_RBUart_Tx(void *,uint32_t);

// ------ Private variable -----------------------------------------
Bool Send_StringTo_RBUart_Tx(void *, uint32_t);

// ------ External variable -----------------------------------------
extern uint8_t STATE;

/*------------------------------------------------------------------*-

    Uart_Init()
-*------------------------------------------------------------------*/
void Uart_Rx_Init(void)
{

	Chip_IOCON_PinMux(LPC_IOCON, 0, 0, IOCON_MODE_INACT, IOCON_FUNC2);	// P0.2 as Txd0
    Chip_IOCON_PinMux(LPC_IOCON, 0, 1, IOCON_MODE_INACT, IOCON_FUNC2); //  P0.3 as Rxd0

    /* Setup UART for 115.2K8N1 */
	Chip_UART_Init(UART_Def);
	Chip_UART_SetBaud(UART_Def, 115200);
	Chip_UART_ConfigData(UART_Def, (UART_LCR_WLEN8 | UART_LCR_SBS_1BIT));
	Chip_UART_TXEnable(UART_Def);

	RingBuffer_Init(&rxring, rxbuff, 1, UART_RRB_SIZE);
	Chip_UART_SetupFIFOS(UART_Def, (UART_FCR_FIFO_EN | UART_FCR_RX_RS |	UART_FCR_TX_RS | UART_FCR_TRG_LEV2));
}

/*------------------------------------------------------------------*-
    Uart_Update()
-*------------------------------------------------------------------*/

void Uart_Rx_Update(void)
{
	uint8_t dataIn;
	static uint8_t letra = 0;
	char *String = {"CYO10L10XL11XF"};

//	while(((Chip_UART_ReadLineStatus(UART_Def) & UART_LSR_RDR) != 0)) {
//		dataIn = Chip_UART_ReadByte(UART_Def);
	if(STATE == DOWNLOAD){							//TODO Eliminar esto
		dataIn = (uint8_t) String[letra];			//TODO    "      "
		letra++;									//TODO    "     letra
		RingBuffer_Insert(&rxring, &dataIn);
		STATE = DOWNLOAD;
		if (dataIn == 'F'){
			STATE = PROCESS;
			letra = 0;
		}
	}
}

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
