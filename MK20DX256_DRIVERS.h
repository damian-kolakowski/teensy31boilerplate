#ifndef MK20DX256_DRIVERS_H
#define MK20DX256_DRIVERS_H

void mk20dx256_mcg_fei_24Mhz();

void mk20dx256_uart0_init();
void mk20dx256_uart0_write(const char*);

void mk20dx256_gpo_port_c_init(unsigned int);
void mk20dx256_gpo_port_c_on(unsigned int);
void mk20dx256_gpo_port_c_off(unsigned int);

char * mk20dx256_cpu_family();

#endif