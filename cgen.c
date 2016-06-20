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
			emitRM(out, "ST",reg,valor,gp,"carrega endereco de memoria valor de gp em reg");
			memOffset++;
		break;

		case INSTR_STORE_MEMORIA_TEMP:
			emitComment(out, "STORE TEMPORARIO" );
			emitRM(out, "ST",reg,memOffset,mp,"carrega endereco de memoria valor de mp em reg");
			memOffset--;
		break;

		case INSTR_LOAD_MEMORIA:
			emitComment(out, "LOAD" );
			emitRM(out, "LD",reg,valor,gp,"carrega para reg o que tem no endereco de memoria valor que esta no gp");
		break;

		case INSTR_LOAD_CTE:
			emitComment(out, "LOAD CONSTANTE" );
			emitRM(out, "LDC",reg,valor,0,"carrega NUM em reg");
		break;

		case INSTR_WRITE:
			emitComment(out, "WRITE");
			emitRM(out, "LD",ac,valor,gp,"carrega em ac o que tem no endereco de memoria valor de gp");
			emitRO(out, "OUT",ac,0,0,"write ac");
		break;

		case INSTR_TEMP_ACS:
			emitComment(out, "PASSA VALOR PARA AC0 E AC1");

			memOffset++;
			emitRM(out, "LD",ac,memOffset,mp,"carrega em ac o que tem no endereco de memoria valor de mp");
			memOffset++;
			emitRM(out, "LD",ac1,memOffset,mp,"carrega em ac1 o que tem no endereco de memoria valor de mp");
		break;
		
		case INSTR_READ:
			emitComment(out, "READ");
			emitRO(out, "IN", reg, 0, 0, "le valor para o registrador");
			emitRM(out, "ST", reg, valor, gp, "armazena valor de reg para endereco de memoria valor de gp");
			
			
		break;

		case INSTR_ADD:
			emitComment(out, "ADICAO");
			emitRO(out, "ADD",ac,ac1,ac,"ac = ac1 + ac");
			emitRM(out, "ST",ac,memOffset,mp,"armazena valor da soma na memoria mp");
		break;

		case INSTR_SUB:
			emitComment(out, "SUBTRACAO");
			emitRO(out, "SUB",ac,ac1,ac,"ac = ac1 - ac");
			emitRM(out, "ST",ac,memOffset,mp,"armazena valor da subtracao na memoria mp");
		break;

		case INSTR_MULT:
			emitComment(out, "MULTIPLICACAO");
			emitRO(out, "MUL",ac,ac1,ac,"ac = ac1 * ac");
			emitRM(out, "ST",ac,memOffset,mp,"armazena valor da multiplicacao na memoria mp");
		break;

		case INSTR_DIV:
			emitComment(out, "DIVISAO");
			emitRO(out, "DIV",ac,ac1,ac,"ac = ac1 / ac");
			emitRM(out, "ST",ac,memOffset,mp,"armazena valor da divisao na memoria mp");
		break;

		case INSTR_REL_MENOR:
			emitComment(out, "RELACAO: MENOR");
			emitRO(out, "SUB",ac,ac1,ac,"");
			emitRM(out, "JLT",ac,4,pc,"a - b < 0 ? Se sim, pule para armazenar true");
		break;

		case INSTR_REL_MAIOR:
			emitComment(out, "RELACAO: MAIOR");
			emitRO(out, "SUB",ac,ac1,ac,"");
			emitRM(out, "JGT",ac,4,pc,"a - b > 0 ? Se sim, pule para armazenar true");
		break;

		case INSTR_REL_IGUAL:
			emitComment(out, "RELACAO: IGUAL");
			emitRO(out, "SUB",ac,ac1,ac,"");
			emitRM(out, "JEQ",ac,4,pc,"a - b == 0 ? Se sim, pule para armazenar true");
		break;

		case INSTR_STORE_REL:
			emitComment(out, "STORE RESULTADO DA RELACAO");

			emitRM(out, "LDC",ac,0,0,"false");
			emitRM(out, "ST",ac,memOffset,mp,"armazena false no topo");
			emitRM(out, "LDC",ac,0,0,"");
			emitRM(out, "JEQ",ac,2,pc,"Pula para o if");


			emitRM(out, "LDC",ac,1,0,"true");
			emitRM(out, "ST",ac,memOffset,mp,"armazena true no topo");
			memOffset--;
		break;

		case INSTR_JUMP_REL_FALSE:
			emitComment(out, "JUMP se o valor da relacao for false");

			memOffset++;
			emitRM(out, "LD",ac,memOffset,mp,"");
			emitRM(out, "JEQ",ac,valor,pc,"Pula para o else");
		break;

		case INSTR_JUMP:
			emitComment(out, "JUMP");
			emitRM(out, "LDC",ac,0,0,"");
			emitRM(out, "JEQ",ac,valor,pc,"Pula incondicionalmente");
		break;

		default:
			emitComment(out, "ERRO" );
		break;
	}
}

void escreverComentario(FILE *out, char *str){
	emitComment(out, str );
}

int getLinhaAtual(){
	return getEmitLoc();
}
int setLinhaAtual(int linha){
	setEmitLoc(linha);
}
