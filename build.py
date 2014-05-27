import glob
import os

arm_none_path	= '/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/arm-none-eabi/bin';
arm_none_as		= arm_none_path + '/arm-none-eabi-as'
arm_none_gcc	= arm_none_path + '/arm-none-eabi-gcc'
arm_none_copy	= arm_none_path + '/arm-none-eabi-objcopy'

asm_files		= glob.glob("*.s")
c_files			= glob.glob("*.c")
linker_files	= glob.glob("*.ld")

hex_file_name	= 'main'

if len(asm_files) <= 0 and len(c_files) <= 0:
	err('No files to compile.')
	exit()

if len(linker_files) <= 0:
	err('No linker files.')
	exit()

print 'Compiling ' + ', '.join(asm_files + c_files) + ' files with linker file ' + linker_files[0] + ' ...'
if 0 != os.system(arm_none_gcc + ' -mcpu=cortex-m4 -mthumb -nostdlib -o ' + hex_file_name + '.elf -T ' + linker_files[0] + ' ' + ' '.join(asm_files + c_files)):
	exit()
print 'Success.'

print 'Building ' + hex_file_name + '.hex image...'
if 0 != os.system(arm_none_copy + ' -O ihex -R .eeprom ' + hex_file_name + '.elf ' + hex_file_name + '.hex'):
	exit();
print 'Success.'






