#ifndef MK20DX256_H
#define MK20DX256_H

// System Clock Gating Control Register 4 (SIM_SCGC4)

#define SIM_SCGC4		*((volatile unsigned int*)0x40048034)

#define UART0_CLK_GATE 	( 1 << 10  )
#define UART1_CLK_GATE 	( 1 << 11  )
#define UART2_CLK_GATE 	( 1 << 12  )

#define UART0_BDH		*((volatile unsigned char*)0x4006A000)
#define UART0_BDL		*((volatile unsigned char*)0x4006A001)
#define UART0_C1		*((volatile unsigned char*)0x4006A002)
#define UART0_C2		*((volatile unsigned char*)0x4006A003)
#define UART0_S1		*((volatile unsigned char*)0x4006A004)
#define UART0_S2		*((volatile unsigned char*)0x4006A005)
#define UART0_C3		*((volatile unsigned char*)0x4006A006)
#define UART0_D 		*((volatile unsigned char*)0x4006A007)
#define UART0_MA1		*((volatile unsigned char*)0x4006A008)
#define UART0_MA2		*((volatile unsigned char*)0x4006A009)
#define UART0_C4		*((volatile unsigned char*)0x4006A00A)
#define UART0_C5		*((volatile unsigned char*)0x4006A00B)
#define UART0_ED		*((volatile unsigned char*)0x4006A00C)
#define UART0_MODEM		*((volatile unsigned char*)0x4006A00D)
#define UART0_IR		*((volatile unsigned char*)0x4006A00E)
#define UART0_PFIFO		*((volatile unsigned char*)0x4006A010)
#define UART0_CFIFO     *((volatile unsigned char*)0x4006A011)
#define UART0_SFIFO		*((volatile unsigned char*)0x4006A012)

#define UART_C2_TE		( 1 << 3 )
#define UART_C2_RE		( 1 << 2 )

#define UART_S1_TDRE	( 1 << 7 )

// System Clock Gating Control Register 5 (SIM_SCGC5)

#define SIM_SCGC5 		*((volatile unsigned int*)0x40048038)

#define PORTA_CLK_GATE 	( 1 << 9  )
#define PORTB_CLK_GATE 	( 1 << 10 )
#define PORTC_CLK_GATE 	( 1 << 11 )
#define PORTD_CLK_GATE 	( 1 << 12 )
#define PORTE_CLK_GATE 	( 1 << 13 )

// Pin Control Register n (PORTx_PCRn)

#define PORTC_PCR5 		*((volatile unsigned int*)0x4004B014)

#define GPIOC_PDDR		*((volatile unsigned int*)0x400FF094)
#define GPIOC_PDOR 		*((volatile unsigned int*)0x400FF080)

#define PORTB_PCR16		*((volatile unsigned int*)0x4004A040)
#define PORTB_PCR17		*((volatile unsigned int*)0x4004A044)

#define PIN_MUX(v)		( (v) << 8 )

#define PINMUX_DISABLED 0
#define PINMUX_GPIO		1
#define PINMUX_ALT_2	2
#define PINMUX_ALT_3	3
#define PINMUX_ALT_4	4
#define PINMUX_ALT_5	5
#define PINMUX_ALT_6	6
#define PINMUX_ALT_7	7

#define PIN_PS			( 1 << 0 )
#define PIN_PE			( 1 << 1 )
#define PIN_SRE			( 1 << 2 )
#define PIN_PFE			( 1 << 4 )
#define PIN_ODE			( 1 << 5 )
#define PIN_DSE			( 1 << 6 )

#endif