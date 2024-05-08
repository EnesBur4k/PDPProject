hepsi:derle bagla calistir
derle:
	gcc -c -I "./include" ./src/Habitat.c -o ./lib/Habitat.o
	gcc -c -I "./include" ./src/Canli.c -o ./lib/Canli.o
	gcc -c -I "./include" ./src/Bitki.c -o ./lib/Bitki.o
	gcc -c -I "./include" ./src/Bocek.c -o ./lib/Bocek.o
	gcc -c -I "./include" ./src/Sinek.c -o ./lib/Sinek.o
	gcc -c -I "./include" ./src/Pire.c -o ./lib/Pire.o
	gcc -c -I "./include" ./src/Test.c -o ./lib/Test.o

bagla:
	gcc ./lib/Habitat.o ./lib/Canli.o ./lib/Bitki.o ./lib/Bocek.o ./lib/Sinek.o ./lib/Pire.o ./lib/Test.o -o ./bin/Test

calistir:
	./bin/Test