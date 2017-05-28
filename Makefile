# COMP1927 TheRealMVPair Assignment 2

CC = gcc
CFLAGS = -Wall -Werror -g

pagerank: graph.o queue.o pagerank.o
	$(CC) $(CFLAGS) -o pagerank graph.o queue.o pagerank.o

inverted: graph.o queue.o BSTree.o inverted.o
	$(CC) $(CFLAGS) -o inverted graph.o queue.o BSTree.o inverted.o

search: graph.o queue.o search.o
	$(CC) $(CFLAGS) -o search graph.o queue.o search.o

# scaled: graph.o queue.o scaled.o 

pagerank.o: pagerank.c queue.h graph.h 
inverted.o: inverted.c BSTree.h graph.h queue.h
search.o: searchPagerank.c graph.h queue.h
# scaled.o: queue.c graph.h
graph.o: graph.c graph.h
queue.o: queue.c queue.h
BSTree.o: BSTree.c BSTree.h
set.o: set.c set.h

clean: 
	rm -f *.o pagerank inverted scaled search core
