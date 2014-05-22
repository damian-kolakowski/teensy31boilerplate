#ifndef MK20DX256_DRIVERS_H
#define MK20DX256_DRIVERS_H

int mk20dx256_uart0_init();
int mk20dx256_uart0_write(const char * buffer, unsigned int size);

#endif