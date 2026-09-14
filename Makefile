CC= gcc
CFLAGS= -Wno-implicit-funciton-declaration -Wno-builtin-declaration-mismatch 


output:laksh.o tokenizer.o 
	$(CC) laksh.o tokenizer.o -o laksh
laksh.o:laksh.c
	$(CC)  $(CFLAGS) laksh.c -c
tokenizer.o:tokenizer.c
	$(CC)  $(CFLAGS) tokenizer.c -c



