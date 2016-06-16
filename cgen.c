#include "cgen.h"

void montador(FILE *out, tipoInstr tipo, int valor, int reg){
 	static int memOffset = 0;

	switch(tipo){
		case INSTR_INICIO:
			reg = ac;
			emitComment(out, "INICIO" );
			emitRM(out, "LD",mp,0,reg,"load maxaddress from location 0");
			emitRM(out, "ST",reg,0,reg,"clear location 0");
		break;

		case INSTR_FIM:
			emitComment(out, "FIM" );
			emitRO(out, "HALT",0,0,0,"");
		break;

		case INSTR_STORE_MEMORIA:
			emitComment(out, "STORE" );
			emitRM(out, "ST",reg,valor,gp,"armazena na memoria index o valor de reg");
		break;

		case INSTR_STORE_MEMORIA_TEMP:
			emitComment(out, "STORE" );
			emitRM(out, "ST",reg,memOffset,mp,"armazena na memoria index o valor de reg");
			memOffset--;
		break;

		case INSTR_LOAD_MEMORIA:
			emitComment(out, "LOAD" );
			emitRM(out, "LD",reg,valor,gp,"carrega posicao de memoria index em reg");
		break;

		case INSTR_LOAD_CTE:
			emitComment(out, "LOAD CONSTANTE" );
			emitRM(out, "LDC",reg,valor,0,"carrega NUM em reg");
		break;

		case INSTR_WRITE:
			reg = ac;
			emitComment(out, "WRITE");
			emitRM(out, "LD",reg,valor,gp,"carrega posicao de memoria index em reg");
			emitRO(out, "OUT",reg,0,0,"write ac");
		break;

		case INSTR_TEMP_ACS:
			emitComment(out, "PASSA VALOR PARA AC0 E AC1");

			memOffset++;
			emitRM(out, "LD",ac,memOffset,mp,"carrega posicao de memoria index em reg");
			memOffset++;
			emitRM(out, "LD",ac1,memOffset,mp,"passa valor do topo da pilha para ac1");
		break;

		case INSTR_ADD:
			emitComment(out, "ADD");
			emitRO(out, "ADD",ac,ac1,ac,"op + entre ac e ac1");
			emitRM(out, "ST",ac,memOffset,mp,"armazena valor da soma na memoria");
			memOffset--;
		break;
		default:
			emitComment(out, "ERRO" );
		break;
	}
}