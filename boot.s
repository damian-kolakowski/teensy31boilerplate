    .syntax unified
    .thumb    
    .section ".vectors"
    .global _start
    .global _vectors

_vectors:    
_start:

    /* ARM Innterrupts Vector. */

    .long 0x20000000             
    .long _startup
  
    .org 0x400

    /* Flash Configuration */

    .long 0xFFFFFFFF
    .long 0xFFFFFFFF
    .long 0xFFFFFFFF
    .long 0xFFFFFFFE

    /* Code entry point */

    .thumb
    .section ".startup","x",%progbits
    .thumb_func
    .global _startup

_startup:

    /* Suggested register initialisation */
    
    mov     r0,#0
    mov     r1,#0
    mov     r2,#0
    mov     r3,#0
    mov     r4,#0
    mov     r5,#0
    mov     r6,#0
    mov     r7,#0
    mov     r8,#0
    mov     r9,#0
    mov     r10,#0
    mov     r11,#0
    mov     r12,#0

    /* Disable innterrupts */

    CPSID i

unlock_watchdog:

    /* WDOG_UNLOCK doc: K20P64M50SF0RM.pdf ( Page: 423 ) */

    ldr r6, = 0x4005200e 
    ldr r0, = 0xc520
    strh r0, [r6]
    ldr r0, = 0xd928
    strh r0, [r6]

disable_watchdog:

    /* WDOG_STCTRLH doc: K20P64M50SF0RM.pdf ( Page: 418 ) */

    ldr r6, = 0x40052000 
    ldr r0, = 0x01d2
    strh r0, [r6]

    /* Enable innterrupts */

    CPSIE i

    /* Prepeare everything for C runtime */

    /* Copy data to RAM */

    ldr r0, =flash_sdata
    ldr r1, =ram_sdata
    ldr r2, =data_size

    /* Handle data_size == 0 */
    
    cmp   r2, #0
    beq   init_bss

copy:
    
    ldrb   r4, [r0], #1
    strb   r4, [r1], #1
    subs   r2, r2, #1
    bne    copy

init_bss:
    
    /* Initialize .bss */
    
    ldr   r0, =sbss
    ldr   r1, =ebss
    ldr   r2, =bss_size

    /* Handle bss_size == 0 */
    
    cmp   r2, #0
    beq   init_stack
    mov   r4, #0

zero:

    strb  r4, [r0], #1
    subs  r2, r2, #1
    bne   zero

init_stack:

    /* Initialize the stack pointer */
    
    ldr   sp, =0x20000000
    bl    main

stop:   
    b     stop
    .end

