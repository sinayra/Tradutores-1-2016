#include "code.h"

int TraceCode = 1;

/* TM location number for current instruction emission */
static int emitLoc = 0 ;

/* Highest TM location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;

/* Procedure emitComment prints a comment line 
 * with comment c in the code file
 */
void emitComment(FILE *out, char * c ){ 
  if (TraceCode) 
    fprintf(out,"\n************ %s ************\n\n",c);
}

/* Procedure emitRM emits a register-to-memory
 * TM instruction
 * op = the opcode
 * r = target register
 * d = the offset
 * s = the base register
 * c = a comment to be printed if TraceCode is TRUE
 */

void emitRM(FILE *out, char * op, int r, int d, int s, char *c){ 
	fprintf(out,"%3d:  %5s  %d,%d(%d) ",emitLoc++,op,r,d,s);

  	if (TraceCode) 
  		fprintf(out,"\t* %s",c) ;
  	fprintf(out,"\n");

  	if (highEmitLoc < emitLoc)  
  		highEmitLoc = emitLoc;
} /* emitRM */

/* Procedure emitRO emits a register-only
 * TM instruction
 * op = the opcode
 * r = target register
 * s = 1st source register
 * t = 2nd source register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRO(FILE *out, char *op, int r, int s, int t, char *c){ 
	fprintf(out,"%3d:  %5s  %d,%d,%d ",emitLoc++,op,r,s,t);
  	if (TraceCode) 
  		fprintf(out,"\t* %s",c);

  fprintf(out,"\n");

  if (highEmitLoc < emitLoc) 
  	highEmitLoc = emitLoc;
} /* emitRO */