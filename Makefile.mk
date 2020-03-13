ssatm: atm.o read.o write.o gui_fun.o
	gcc -o ssatm read.o write.o gui_fun.o atm.o `pkg-config --cflags --libs gtk+-3.0` -I/include -L/usr/lib  -lxlsxwriter -lm -lxlsxio_read

read.o: read.c header.h
	gcc -c read.c `pkg-config --cflags --libs gtk+-3.0` -I/include -L/usr/lib -lxlsxio_read

write.o: write.c header.h
	gcc -c write.c `pkg-config --cflags --libs gtk+-3.0` -lxlsxwriter -lm

gui_fun.o: gui_fun.c header.h
	gcc -c gui_fun.c `pkg-config --cflags --libs gtk+-3.0`

atm.o: atm.c header.h
	gcc -c atm.c `pkg-config --cflags --libs gtk+-3.0`
