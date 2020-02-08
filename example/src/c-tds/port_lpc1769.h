/*------------------------------------------------------------------*-

    port_lpc1769.h (Released 2019-04)

  ------------------------------------------------------------------

    This is the "Port Header" file: it documents usage of port pins
    in the project.

-*------------------------------------------------------------------*/

#ifndef _PORT_H
#define _PORT_H 1


// ------ Public constants -----------------------------------------
#define TIM_PRESCALE_USVAL	(100)





// Allows Active Low or Active High led to be used (or other wiring variations)
#define LED_ON	(false)
#define LED_OFF	(true)


// Heartbeat LED
// Connected to "LED2" on LPC1769 board
// Port 0, Pin 22
#define HEARTBEAT_LED_PORT 2//(0)
#define HEARTBEAT_LED_PIN 13//(22)
#define HEARTBEAT_LED_PIN_MODE (IOCON_MODE_INACT)
#define HEARTBEAT_LED_PIN_FUNC (IOCON_FUNC0)




// Add jumper wire on baseboard to control WDT
// WDT is enabled *only* if jumper is in place.
// (Jumper is read at init phase only)
// Port 2, Pin 3 => Connected to "SW2 UP" on LPCXpresso baseboard
#define WDT_JUMPER_PORT (0)
#define WDT_JUMPER_PIN (23)
#define WDT_JUMPER_PIN_MODE (IOCON_MODE_PULLUP)
#define WDT_JUMPER_PIN_FUNC (IOCON_FUNC0)


// ------ Public data type declarations ----------------------------


// ------ Public function prototypes -------------------------------


#endif


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
