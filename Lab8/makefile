final: main.o hashTable.o
	g++ -oplagiarismCatcher  main.o hashTable.o
driver: main.cpp hashTable.h
	g++ -c main.cpp
hashTable.o: hashTable.cpp hashTable.h
	g++ -c hashTable.cpp