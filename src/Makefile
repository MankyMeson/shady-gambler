CC = g++
ALLMODOBJECTS = primitive.o run_utils.o

.PHONY = all

all: main.out

main.out: main.o $(ALLMODOBJECTS)
	$(CC) $^ -o ../$@

main.o: main.cpp primitive.o
	$(CC) -c $< -o $@

primitive.o: primitive.cpp run_utils.o
	$(CC) -c $< -o $@

#constants.o: constants.cpp
#	$(CC) -c $< -o $@

run_utils.o: run_utils.cpp
	$(CC) -c $< -o $@
