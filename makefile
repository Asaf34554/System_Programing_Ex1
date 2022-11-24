CC = gcc
FLAGS = -Wall -g
MAIN = main.o
LOP = advancedClassificationLoop.o 
REC = advancedClassificationRecursion.o
BAS = basicClassification.o
NUM = NumClass.h



all: libclassloops.a libclassrec.a libclassloops.so libclassrec.so loops recursives recursived loopd mains maindloop maindrec 

loops: $(BAS) $(MAIN) libclassloops.a
	$(CC) $(FLAGS) -o loops $(BAS) $(MAIN) libclassloops.a -lm

recursives: $(BAS) $(MAIN) libclassrec.a 
	$(CC) $(FLAGS) -o recursives $(BAS) $(MAIN) libclassrec.a -lm

recursived: $(MAIN) $(BAS) $(REC)
	$(CC) $(FLAGS) -o recursived $(MAIN) $(BAS) $(REC) ./libclassrec.so -lm

loopd: $(MAIN) $(BAS) $(LOP)
	$(CC) $(FLAGS) -o loopd $(MAIN) $(BAS) $(LOP) ./libclassloops.so -lm

libclassloops.a: $(LOP)
	ar -rcs libclassloops.a $(LOP) -lm

libclassrec.a: $(REC)
	ar -rcs libclassrec.a $(REC) -lm

libclassloops.so: $(LOP)
	$(CC) -shared -o libclassloops.so $(LOP) -lm

libclassrec.so: $(LOP)
	$(CC) -shared -o libclassrec.so $(REC) -lm

mains: recursives
	$(CC) $(FLAGS) -o mains $(MAIN) $(BAS) libclassrec.a -lm

maindloop: loopd 
	$(CC) $(FLAGS) -o maindloop $(MAIN) $(LOP) $(BAS) -lm

maindrec: recursived
	$(CC) $(FLAGS) -o maindrec $(MAIN) $(REC) $(BAS) -lm

main.o: main.c $(NUM)
	$(CC) $(FLAGS) -c main.c

advancedClassificationLoop.o: advancedClassificationLoop.c $(NUM)
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(NUM)
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

basicClassification.o: basicClassification.c $(NUM)
	$(CC) $(FLAGS) -c basicClassification.c
.PHONY: clean all
clean:
	rm -f *.o *.so *.a loops loopd recursives recursived mains maindloop maindrec

