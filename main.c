
#include "MK20DX256.h"
#include "MK20DX256_DRIVERS.h"

#define TEENSY31_LED_PIN_NUMBER 5

int main() 
{
	mk20dx256_mcg_fei_24Mhz();

	mk20dx256_uart0_init();
	mk20dx256_uart0_write("\nSTART");
	mk20dx256_uart0_write("\nCPU family...");
	mk20dx256_uart0_write(mk20dx256_cpu_family());

	mk20dx256_gpo_port_c_init(TEENSY31_LED_PIN_NUMBER);
 	int i = 0;
	while ( 1 ) {
		for ( i = 0 ; i < 500000 ; ++i ) { }
		mk20dx256_gpo_port_c_on(TEENSY31_LED_PIN_NUMBER);
		mk20dx256_uart0_write("\nLED is on");
		for ( i = 0 ; i < 500000 ; ++i ) { }
		mk20dx256_gpo_port_c_off(TEENSY31_LED_PIN_NUMBER);
		mk20dx256_uart0_write("\nLED is off");
	}
	return 0;
}
