CC = arm-none-eabi-gcc
STD = -std=gnu11
MCU = -mcpu=cortex-m0plus -mthumb
CFLAGS = -Wall -O0 $(STD) $(MCU)
LDFLAGS = -nostdlib -T linker.ld -Wl,-Map=$(NAME).map

NAME = final

LINKER = linker.ld

SRC = main.c \
	  startup.c


OBJ 	= $(SRC:.c=.o)

all: startup.o main.o link

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $^

startup.o: startup.c
	$(CC) $(CFLAGS) -c -o $@ $^

dontlink:
	$(CC) $(CFLAGS) -c $(FILE) -o $(FILE:.c=.o)

assembly:
	$(CC) $(CFLAGS) -S $(FILE) -o $(FILE:.c=.s)

link: startup.o main.o
	$(CC) $(LDFLAGS) -o $(NAME).elf $^

dump:
	arm-none-eabi-objdump -h $(FILE)

clean:
	rm -f *.o *.elf *.s *.map

re: clean all