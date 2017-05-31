# COMP1927 TheRealMVPair Assignment 2

CC = gcc
CFLAGS = -Wall -Werror -g
LIBS = graph.o queue.o set.o mergesortmod.o readData.o BSTree.o 


all: graph.o queue.o set.o mergesortmod.o BSTree.o readData.o pagerank inverted 

pagerank: pagerank.o 
	$(CC) $(CFLAGS) -o pagerank pagerank.o $(LIBS)

inverted: inverted.o
	$(CC) $(CFLAGS) -o inverted inverted.o $(LIBS)

search: search.o
	$(CC) $(CFLAGS) -o search search.o $(LIBS)

scaled: scaled.o
	$(CC) $(CFLAGS) -o scaled scaled.o $(LIBS)

pagerank.o: pagerank.c
inverted.o: inverted.c 
search.o: searchPagerank.c 
scaled.o: scaledFootrule.c
graph.o: graph.c graph.h
queue.o: queue.c queue.h
BSTree.o: BSTree.c BSTree.h
set.o: set.c set.h
mergesortmod.o: mergesortmod.c mergesortmod.h
readData.o: readData.c readData.h 

clean: 
	rm -f *.o pagerank inverted scaled search core
