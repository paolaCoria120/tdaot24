default: principal.o funciones.o
	gcc principal.o funciones.o -o pangrama.out

principal.o: principal.c header.h
	gcc -c principal.c

funciones.o: funciones.c header.h
	gcc -c funciones.c

clean:
	rm -f *.o
	rm -f *.out
	rm -f *~
	rm -f *#
