CC=arm-none-eabi-
CFLAGS= -mcpu=$(CPU) -gdwarf-2
CPU=arm926ej-s
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ= $(As:.s=.o)
all: learn-in-depth.bin


%.o: %.s
	$(CC)as.exe   $(INCS) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe  $(INCS) $(CFLAGS) -c $< -o $@

learn-in-depth.elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@


clean: 
	rm *.o *elf *bin
	echo "Everything Clean"
