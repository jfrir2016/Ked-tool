/*--------------------------------------------------------------------*-

    task-base_lpc1769.c (Released 2019-04)

  --------------------------------------------------------------------

- Detalle de funcionamiento de tarea

-*--------------------------------------------------------------------*/


// Project header
#include "task-base_lpc1769.h"

#include "../main/main.h"


// Task header


// ------ Public variable ------------------------------------------
uint8_t dummyVec[25]="0123456789012345678901234";

extern RINGBUFF_T rxring;
// ------ Private constants ----------------------------------------
#define TEST_TX (1)		/* Test only tx */
#define TEST_ECHO (2)	/* Test tx & rx */


#define TEST (TEST_ECHO)

#define MAX_DURATION (1000)


// ------ Private data type ----------------------------------------



// ------ Private variable -----------------------------------------
static uint32_t Time_in_state_G;

/*------------------------------------------------------------------*-

    Base_Init()


-*------------------------------------------------------------------*/
void Base_Init(void)
{
	Time_in_state_G=MAX_DURATION;
}


/*------------------------------------------------------------------*-

    Base_Update()



-*------------------------------------------------------------------*/
void Base_Update(void)
{
#if (TEST == TEST_TX)	/* Test original task */
	Time_in_state_G--;
	if(!Time_in_state_G){
		Time_in_state_G=MAX_DURATION;
		Send_StringTo_RBUart_Tx(dummyVec, 25);
	}

}
#endif
#if (TEST == TEST_ECHO)	/* Test original task */
uint8_t datarx;

	if(RingBuffer_Pop(&rxring, &datarx)){

		Send_CharTo_RBUart_Tx(datarx);
	}

}
#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
