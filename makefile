CC 		= gcc
CFLAGS 	= -std=gnu99

all: flex bison compile

cflatc: flex bison compile

flex:	
		win_flex lexico.l
		
bison:	
		win_bison -d sintatico.y
		
compile:	bison flex
			$(CC) $(CFLAGS) lex.yy.c sintatico.tab.c -o compasc

