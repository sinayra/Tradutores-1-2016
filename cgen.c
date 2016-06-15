#include "cgen.h"

void montador(FILE *out, tipoInstr tipo, int valor){
	switch(tipo){
		case INSTR_INICIO:
			emitComment(out, "INICIO" );
			emitRM(out, "LD",mp,0,ac,"load maxaddress from location 0");
			emitRM(out, "ST",ac,0,ac,"clear location 0");
		break;
		case INSTR_FIM:
			emitComment(out, "FIM" );
			emitRO(out, "HALT",0,0,0,"");
		break;
		case INSTR_STORE_MEMORIA:
			emitComment(out, "STORE" );
			emitRM(out, "ST",ac,valor,gp,"armazena na memoria index o valor de ac");
		break;
		case INSTR_LOAD_MEMORIA:
			emitComment(out, "LOAD" );
			emitRM(out, "LD",ac,valor,gp,"carrega posicao de memoria index em ac");
		break;
		case INSTR_LOAD_CTE:
			emitComment(out, "LOAD CONSTANTE" );
			emitRM(out, "LDC",ac,valor,0,"carrega NUM em ac");
		break;
		case INSTR_WRITE:
			emitComment(out, "WRITE");
			emitRO(out, "OUT",ac,0,0,"write ac");
		break;
		default:
			emitComment(out, "ERRO" );
		break;
	}
}