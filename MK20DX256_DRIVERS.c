#include "MK20DX256.h"
#include "MK20DX256_DRIVERS.h"

void mk20dx256_mcg_fei_24Mhz()
{
	MCG_C4 = MCG_C4_DMX_32 | MCG_C4_DRST_LOW;
}

void mk20dx256_uart0_init()
{
	// Enable clock gate for PORTB
	SIM_SCGC5 |= PORTB_CLK_GATE;
	// Disable clock gate for UART0
	SIM_SCGC4 &= ~UART0_CLK_GATE;
	// Setup UARTO_RX
	PORTB_PCR16 = PIN_MUX(PINMUX_ALT_3) | PIN_PS  | PIN_PFE | PIN_PE;
	// Setup UARTO_TX 
	PORTB_PCR17 = PIN_MUX(PINMUX_ALT_3) | PIN_DSE | PIN_SRE; 
	// Enable clock gate for UART0
	SIM_SCGC4 |= UART0_CLK_GATE; 
	// Disable Transmitter and Receiver. Innterupts are off by default.
	UART0_C2 &= ~( UART_C2_TE | UART_C2_RE );
	// Set default UART, 8 bit mode, no parity.
	UART0_C1 = 0;
	// Set badu rate 9600 for 24 MHz 
	// Prescale divisor = 156 = 0x9C, Tuner = 5 ( 5/32 ~ 0.16)
	UART0_BDH = 0;
	UART0_BDL = 0x9C;
	UART0_C4  = 5;
	// Enable Transmitter and Receiver
	UART0_C2 |= ( UART_C2_TE | UART_C2_RE );
}

void mk20dx256_uart0_put_char(unsigned char c)
{
    /* Wait until space is available in the FIFO */
    while ( ! ( UART0_S1 & UART_S1_TDRE ) );
    /* Send the character */
    UART0_D = c;
}

void mk20dx256_uart0_write(const char * buffer)
{
	unsigned int i = 0;
	while ( buffer[i] != '\0' ) {
		mk20dx256_uart0_put_char(buffer[i]);
		i++;
	}
}

void mk20dx256_gpo_port_c_init(unsigned int pin)
{
	SIM_SCGC5 |= PORTC_CLK_GATE;
	PORTC_PCR(pin) = PIN_MUX(PINMUX_GPIO) | PIN_PE | PIN_PS | PIN_DSE;
	GPIOC_PDDR |= 1 << pin;
	GPIOC_PDOR |= 1 << pin;
}

void mk20dx256_gpo_port_c_on(unsigned int pin)
{
	GPIOC_PDOR |= (1 << pin);
}

void mk20dx256_gpo_port_c_off(unsigned int pin)
{
	GPIOC_PDOR &= ~(1 << pin);
}

char * mk20dx256_cpu_family()
{
	switch ( ( SIM_SDID & 0x70 ) >> 4 )  {  
	case 0x0: return "K10";
	case 0x1: return "K20";
	case 0x2: return "K61";
	case 0x4: return "K60";
	case 0x5: return "K70";
    }
    return "Unknown";
}
