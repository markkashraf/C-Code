CC=arm-none-eabi-
CFLAGS= -mcpu=$(CPU) -gdwarf-2 -g
CPU=cortex-m4
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_Name = unit3_lab4_cortexM4


%.o: %.c
	$(CC)gcc.exe  $(INCS) $(CFLAGS) -c $< -o $@

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	cp $(Project_Name).elf $(Project_Name).axf


$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map



clean_o:
	echo "Cleaning object files ......" 
	rm *.o
	
clean_elf:
	echo "Cleaning elf files ......" 
	rm *.elf

clean_bin:m
	echo "Cleaning bin files ......" 
	rm *.bin

clean:
	make clean_o
	make clean_elf
	make clean_bin
