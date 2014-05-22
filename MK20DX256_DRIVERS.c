#include "MK20DX256.h"
#include "MK20DX256_DRIVERS.h"

int mk20dx256_uart0_init()
{
	// Disable clock gate for UART0
	SIM_SCGC4 &= ~UART0_CLK_GATE;
	// Setup UARTO_RX
	PORTB_PCR16 = PIN_MUX(PINMUX_ALT_3) | PIN_PS  | PIN_PFE | PIN_PE;
	// Setup UARTO_TX 
	PORTB_PCR17 = PIN_MUX(PINMUX_ALT_3) | PIN_DSE | PIN_SRE; 
	// Enable clock gate for UART0
	SIM_SCGC4 |= UART0_CLK_GATE; 
	// Disable Transmitter and Receiver
	UART0_C2 = ~( UART_C2_TE | UART_C2_RE );
	// Set default UART, 8 bit mode, no parity.
	UART0_C1 = 0;
	// Enable Transmitter and Receiver
	UART0_C2 |= ( UART_C2_TE | UART_C2_RE );
	return 0;
}

int mk20dx256_uart0_write(const char * buffer, unsigned int size)
{

	return 0;
}

int mk20dx256_uart0_put_char(unsigned char c)
{
    /* Wait until space is available in the FIFO */
    while ( ! ( UART0_S1 & UART_S1_TDRE ) );
    /* Send the character */
    UART0_D = c;
}

