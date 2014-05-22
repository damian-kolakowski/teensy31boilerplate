
#include "MK20DX256.h"
#include "MK20DX256_DRIVERS.h"

int main() 
{


	// SIM_SCGC5  doc: K20P64M50SF0RM.pdf ( Page 239 )
	SIM_SCGC5 = PORTA_CLK_GATE | PORTB_CLK_GATE | PORTC_CLK_GATE | PORTD_CLK_GATE | PORTE_CLK_GATE; 

	// PORTC_PCR5 doc: K20P64M50SF0RM.pdf ( Pages 210, 213 )
	PORTC_PCR5 = PIN_MUX(PINMUX_GPIO) | PIN_PE | PIN_PS | PIN_DSE;

	// GPIOC_PDDR doc: K20P64M50SF0RM.pdf ( Pages: 1181, 1185 
	GPIOC_PDDR |= 1 << 5;

	// GPIOC_PDOR doc: K20P64M50SF0RM.pdf ( Pages: 1180, 1182 )
	GPIOC_PDOR |= 1 << 5;

	mk20dx256_uart0_init();
	
	int i = 0;
	while ( 1 ) {
		for ( i = 0 ; i < 500000 ; ++i ) { }
		GPIOC_PDOR |= (1 << 5);
		for ( i = 0 ; i < 500000 ; ++i ) { }
		GPIOC_PDOR &= ~(1 << 5);
	}
	return 0;
}
