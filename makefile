CC 		= gcc
CFLAGS 	= -std=gnu99
INCLUDE = lista
SRC = lex.yy.c sintatico.tab.c lista.c

all: $(INCLUDE) flex bison compile clean

flex:	
		win_flex lexico.l
		
bison:	
		win_bison -d sintatico.y

lista: 
		$(CC) $(CFLAGS) -c lista.c
		
compile:	
		$(CC) $(CFLAGS) $(SRC) -o compasc

clean:
		del *.o

