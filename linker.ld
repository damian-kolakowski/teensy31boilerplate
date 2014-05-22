MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
	RAM  (rwx) : ORIGIN = 0x1FFF8000, LENGTH = 64K
}

SECTIONS 
{
	.text :
	{
		*(.vectors)
		*(.startup)
		*(.text)
		*(.text.*)
		*(.rodata);
	} > FLASH
    
    flash_sdata = .;

    .data : AT (flash_sdata) 
    {
    	. = ALIGN(4);
		ram_sdata = .; 
		*(.data*)
		. = ALIGN(4);
		ram_edata = .; 
    } > RAM

    data_size = ram_edata - ram_sdata;
    
    .bss : 
    {
    	. = ALIGN(4);
    	sbss = .;
		* (.bss);
		. = ALIGN(4);
		ebss = .;
    } > RAM

    bss_size = ebss - sbss;
}
