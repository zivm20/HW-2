CC=gcc
FLAGS=-Wall -g
OBJECTS_MAIN=main.o


all: my_mat.so main


#create main program

main: $(OBJECTS_MAIN) my_mat.so
	$(CC) $(FLAGS) -o main $(OBJECTS_MAIN) ./my_mat.so -lm



#clean
clean:
	rm *.o *.so main 

.PHONY: clean all


#compile dependencies
%.so: %.o
	$(CC) -shared -o $@ $<

%.a: %.o
	ar -rcs -o $@ $<

#compile objects
my_mat.o: my_mat.h my_mat.c
	$(CC) $(FLAGS) -c my_mat.c


main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
