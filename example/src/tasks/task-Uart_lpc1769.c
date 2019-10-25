/*--------------------------------------------------------------------*-

    task-Uart0Tx_lpc1769.c (Released 2019-04)

  --------------------------------------------------------------------

- Detalle de funcionamiento de tarea

-*--------------------------------------------------------------------*/


// Project header
#include "task-Uart_lpc1769.h"

#include "../main/main.h"


// Task header


// ------ Public variable ------------------------------------------

/* Transmit and receive ring buffers */
RINGBUFF_T txring, rxring;

// ------ Private constants ----------------------------------------

#define UART_Def (LPC_UART0)	/* Defined uart */

/* Transmit  ring buffer size */
#define UART_SRB_SIZE 128	/* Send */
#define UART_RRB_SIZE 128	/* Receive */
/* Transmit buffers */
static uint8_t  txbuff[UART_SRB_SIZE], rxbuff[UART_RRB_SIZE];
// ------ Private data type ----------------------------------------

Bool Send_CharTo_RBUart_Tx(uint8_t);
Bool Send_StringTo_RBUart_Tx(void *,uint32_t);
// ------ Private variable -----------------------------------------

Bool Send_StringTo_RBUart_Tx(void *, uint32_t);


/*------------------------------------------------------------------*-

    Uart_Tx_Init()


-*------------------------------------------------------------------*/
void Uart_Init(void)
{

	Chip_IOCON_PinMux(LPC_IOCON, 0, 2, IOCON_MODE_INACT, IOCON_FUNC1);	// P0.2 as Txd0
    Chip_IOCON_PinMux(LPC_IOCON, 0, 3, IOCON_MODE_INACT, IOCON_FUNC1); //  P0.3 as Rxd0

    /* Setup UART for 115.2K8N1 */
	Chip_UART_Init(UART_Def);
	Chip_UART_SetBaud(UART_Def, 115200);
	Chip_UART_ConfigData(UART_Def, (UART_LCR_WLEN8 | UART_LCR_SBS_1BIT));
	Chip_UART_TXEnable(UART_Def);

	RingBuffer_Init(&txring, txbuff, 1, UART_SRB_SIZE);
	RingBuffer_Init(&rxring, rxbuff, 1, UART_RRB_SIZE);
	Chip_UART_SetupFIFOS(UART_Def, (UART_FCR_FIFO_EN | UART_FCR_RX_RS |	UART_FCR_TX_RS | UART_FCR_TRG_LEV2));

}

/*------------------------------------------------------------------*-

    StringTo_RBUart0Tx()

-*------------------------------------------------------------------*/
Bool Send_StringTo_RBUart_Tx(void *buffer, uint32_t size)
{
	uint32_t i=0;
	i=RingBuffer_InsertMult(&txring, buffer, size);
	if(i!=size){
		return FALSE;
	}else
		return TRUE;

}
/*------------------------------------------------------------------*-

    Send_CharTo_RBUart0Tx()

-*------------------------------------------------------------------*/
Bool Send_CharTo_RBUart_Tx(uint8_t SendChar)
{
	if(!RingBuffer_Insert(&txring, &SendChar)){
		return FALSE;
	}else{
		return TRUE;
	}


}
/*------------------------------------------------------------------*-

    Uart_Tx_Update()

-*------------------------------------------------------------------*/
void Uart_Tx_Update(void)
{

	uint8_t data;
	if(!Chip_UART_CheckBusy(UART_Def)){

		if(RingBuffer_Pop(&txring, &data)){
			Chip_UART_SendByte(UART_Def, data);
		}
	}

}

/*------------------------------------------------------------------*/
void Uart_Rx_Update(void)
{
	uint8_t dataIn;

	while(((Chip_UART_ReadLineStatus(UART_Def) & UART_LSR_RDR) != 0)) {
		dataIn = Chip_UART_ReadByte(UART_Def);
		RingBuffer_Insert(&rxring, &dataIn);

	}

}



/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
