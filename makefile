CC 		= gcc
CFLAGS 	= -std=gnu99
INCLUDE = lista code
SRC = lex.yy.c sintatico.tab.c lista.o code.o

all: $(INCLUDE) flex bison compile clean

flex:	
		win_flex lexico.l
		
bison:	
		win_bison -d sintatico.y

lista: lista.c
		$(CC) $(CFLAGS) -c lista.c

code: code.c
		$(CC) $(CFLAGS) -c code.c

compile: 
		$(CC) $(CFLAGS) -o compasc $(SRC) 

clean:
		del *.o
