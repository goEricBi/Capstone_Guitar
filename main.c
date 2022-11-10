#include <driverlib.h>
#include <stdio.h>
#include <string.h>
#include <msp430.h>
#include "timerA.h"
#include "FSM.h"

/* Global Defines */
#define CS_MCLK_DESIRED_FREQUENCY_IN_KHZ   2000  // Target frequency for MCLK in kHz
#define CS_MCLK_FLLREF_RATIO               61    // MCLK/FLLRef Ratio; CS_MCLK_DESIRED_FREQUENCY_IN_KHZ/32768

/* Function declarations */
void GPIO_init(void);
void CS_init(void);


/*
 * main.c
 */

int main(void)
{
    //Stop watchdog timer
    WDT_A_hold(WDT_A_BASE);

    PMM_unlockLPM5();
	GPIO_init();
	CS_init();
//	EUSCI_init();

	// Left hand configuration: Timer B0, decoder 3x8
//	Decoder(input);
//	stringSelectLeft(input)
//	ConfigureTimerB();

	// Right hand configuration: Timer A3, P6.1, P6.2, P4.1, P4.2, P5.3, P5.4
	configureTimerA3();

	// FSM initialization
	FSMType fsm;
	initializeFSM(&fsm);

	while (1) {
	    nextStateFunction(&fsm);
	    outputFunction(&fsm);
	}

}

void GPIO_init(void) {
    //Right hand PWM pre-configuration
    P4DIR |= BIT1;
    P4DIR |= BIT2;
    P1DIR |= BIT6;
    P1DIR |= BIT7;
    P4DIR |= BIT5;
    P4DIR |= BIT6;

    //Left hand PWM pre-configuration
    P4SEL1 |= BIT7;
    P4DIR |= BIT7;

    P5SEL1 |= BIT0;
    P5DIR |= BIT0;

    P5SEL1 |= BIT1;
    P5DIR |= BIT1;

    P5SEL1 |= BIT2;
    P5DIR |= BIT2;

    P4SEL1 |= BIT3;
    P4DIR |= BIT3;

    P4SEL1 |= BIT4;
    P4DIR |= BIT4;

    //Left hand decoder pre-configuration
    P1DIR |= BIT1;
    P1DIR |= BIT2;
    P1DIR |= BIT3;
    P2DIR |= BIT0;
    P2DIR |= BIT1;
    P2DIR |= BIT2;
    P5DIR |= BIT3;
    P5DIR |= BIT4;
    P5DIR |= BIT7;
    P3DIR |= BIT1;
    P3DIR |= BIT2;
    P3DIR |= BIT3;
    P3DIR |= BIT5;
    P3DIR |= BIT6;
    P3DIR |= BIT7;
    P6DIR |= BIT0;
    P6DIR |= BIT1;
    P6DIR |= BIT2;
}

/*
 * Initialize clock system
 */
void CS_init(void)
{
    // Configure one FRAM waitstate as required by the device datasheet for MCLK
    // operation beyond 8MHz _before_ configuring the clock system.
//    FRAMCtl_configureWaitStateControl(FRAMCTL_ACCESS_TIME_CYCLES_1);

    //Set DCO FLL reference = REFO
    CS_initClockSignal(
        CS_FLLREF,
        CS_REFOCLK_SELECT,
        CS_CLOCK_DIVIDER_1
        );

    //Set ACLK = REFO
    CS_initClockSignal(
        CS_ACLK,
        CS_REFOCLK_SELECT,
        CS_CLOCK_DIVIDER_1
        );

    CS_initFLLParam param = {0};

    //Set Ratio/Desired MCLK Frequency, initialize DCO, save trim values
    CS_initFLLCalculateTrim(
        CS_MCLK_DESIRED_FREQUENCY_IN_KHZ,
        CS_MCLK_FLLREF_RATIO,
        &param
        );

    // SMCLK configure
    CSCTL5 |= DIVS_3;

    //Clear all OSC fault flag
    CS_clearAllOscFlagsWithTimeout(1000);
}

