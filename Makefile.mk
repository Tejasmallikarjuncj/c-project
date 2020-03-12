ssatm: atm.o read.o write.o gui_fun.o
	gcc -o ssatm read.o write.o gui_fun.o atm.o `pkg-config --cflags --libs gtk+-3.0` `pkg-config --cflags --libs xlsxio_read` `pkg-config --cflags --libs xlsxwriter`-lm

atm.o: atm.c header.h
	gcc -c atm.c `pkg-config --cflags --libs gtk+-3.0`

read.o: read.c header.h
	gcc -c read.c `pkg-config --cflags --libs gtk+-3.0` `pkg-config --cflags --libs xlsxio_read`

write.o: write.c header.h
	gcc -c write.c `pkg-config --cflags --libs gtk+-3.0` `pkg-config --cflags --libs xlsxwriter`-lm

gui_fun.o: gui_fun.c header.h
	gcc -c gui_fun.c `pkg-config --cflags --libs gtk+-3.0`
