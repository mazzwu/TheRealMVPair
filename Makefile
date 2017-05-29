# COMP1927 TheRealMVPair Assignment 2

CC = gcc
CFLAGS = -Wall -Werror -g
LIBS = graph.o queue.o set.o mergesortmod.o readData.o

all: pagerank inverted 

pagerank: pagerank.o 
	$(CC) $(CFLAGS) -o pagerank pagerank.o $(LIBS)

inverted: inverted.o
	$(CC) $(CFLAGS) -o inverted inverted.o $(LIBS)

search: search.o
	$(CC) $(CFLAGS) -o search search.o $(LIBS)

# scaled: graph.o queue.o scaled.o 

pagerank.o: pagerank.c
inverted.o: inverted.c 
search.o: searchPagerank.c 
# scaled.o: queue.c graph.h
graph.o: graph.c graph.h
queue.o: queue.c queue.h
BSTree.o: BSTree.c BSTree.h
set.o: set.c set.h
mergeSort.o: mergesortmod.c mergesortmod.h
readData.o: readData.c readData.h 

clean: 
	rm -f *.o pagerank inverted scaled search core
