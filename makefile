hepsi:	derle calistir
derle:
		g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
		g++ -I ./include/ -o ./lib/B_S_T_Control.o -c ./src/B_S_T_Control.cpp
		g++ -I ./include/ -o ./bin/Test ./lib/B_S_T_Control.o ./lib/BST.o ./src/Test.cpp
calistir:
		./bin/Test