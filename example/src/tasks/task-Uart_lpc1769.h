/*--------------------------------------------------------------------*-

    task-base_lpc1769.h (Released 2019-04)

--------------------------------------------------------------------

    - See task-base_lpc1769.c for details.

-*--------------------------------------------------------------------*/


#ifndef _UART0_TX_H
#define _UART0_TX_H 1


// ------ Public constants -----------------------------------------


// ------ Public data type declarations ----------------------------



// ------ Public function prototypes -------------------------------
void Uart_Init(void);
void Uart_Tx_Update(void);
void  Uart_Rx_Update (void);
#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
