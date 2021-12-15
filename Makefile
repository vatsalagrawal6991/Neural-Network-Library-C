arg1 =
arg2 =
arg3 =
arg4 =

all: neural

neural: main.out main2.out main3.out main4.out main5.out main6.out main7.out

main7.out: obj/main7.o lib_neural.so
	gcc $< -o $@ -lm -L. -l_neural

main6.out: obj/main6.o lib_neural.so
	gcc $< -o $@ -lm -L. -l_neural

main5.out: obj/main5.o lib_neural.so
	gcc $< -o $@ -lm -L. -l_neural

main4.out: obj/main4.o lib_neural.so
	gcc $< -o $@ -lm -L. -l_neural

main3.out: obj/main3.o lib_neural.so
	gcc $< -o $@ -lm -L. -l_neural

main2.out: obj/main2.o lib_neural.so
	gcc $< -o $@ -lm -L. -l_neural

main.out: obj/main.o lib_neural.so
	gcc $< -o $@ -lm -L. -l_neural

obj/main7.o: src/main7.c inc/neural.h
	gcc -c $< -o $@ -I./inc

obj/main6.o: src/main6.c inc/neural.h
	gcc -c $< -o $@ -I./inc

obj/main5.o: src/main5.c inc/neural.h
	gcc -c $< -o $@ -I./inc

obj/main4.o: src/main4.c inc/neural.h
	gcc -c $< -o $@ -I./inc

obj/main3.o: src/main3.c inc/neural.h
	gcc -c $< -o $@ -I./inc

obj/main2.o: src/main2.c inc/neural.h
	gcc -c $< -o $@ -I./inc

obj/main.o: src/main.c inc/neural.h
	gcc -c $< -o $@ -I./inc

lib_neural.so: obj/neural.o
	gcc $^ -shared -o $@ -lm

obj/neural.o: lib/neural.c inc/neural.h
	gcc -Wall -fpic -c $< -o $@ -I./inc

clear:
	rm -f ./obj/*.o *.out *.so

run: all
	./main.out

run1: all
	./main3.out

run2: all
	./main4.out

run3: all
	./main5.out

run4:
	/home/baadalvm/PycharmProjects/pythonProject/venv/bin/python ./src/mainclass.py

run5:
	/home/baadalvm/PycharmProjects/pythonProject/venv/bin/python ./src/mainregress.py

run6: all
	./main2.out

run7: all
	/home/baadalvm/PycharmProjects/pythonProject/venv/bin/python ./src/mainown.py

run8: all
	./main6.out

run9: all
	./main7.out

plot1:
	gnuplot ./data/plot1.p

plot2:
	gnuplot ./data/plot2.p

plot3:
	gnuplot ./data/plot3.p