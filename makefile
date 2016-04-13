CC 		= gcc
CFLAGS 	= -Wall

all: flex bison compile

cflatc: flex bison compile

flex:	
		win_flex lexico.l
		
bison:	
		win_bison -d sintatico.y
		
compile:	bison flex
			gcc lex.yy.c sintatico.tab.c -o teste

