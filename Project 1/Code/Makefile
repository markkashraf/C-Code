CC=arm-none-eabi-
CFLAGS= -mcpu=$(CPU) -gdwarf-2 -g
CPU=cortex-m3
INCS=-I .
LIBS=
SRC = $(wildcard */*.c) main.c startup.c
OBJ = $(SRC:.c=.o)


Project_Name = Pressure_Sensor

%.o: %.c
	$(CC)gcc.exe  $(INCS) $(CFLAGS) -c $< -o $@


$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld  $(OBJ) -o ./bin/$@ -Map=./map/Map_file.map


clean_o:
	echo "Cleaning object files ......" 
	rm */*.o
	
clean_elf:
	echo "Cleaning elf files ......" 
	rm *.elf

clean:
	make clean_o
	make clean_elf
	make clean_bin
