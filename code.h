#pragma once
#include <stdio.h>

/* pc = program counter  */
#define  pc 7

/* mp = "memory pointer" points
 * to top of memory (for temp storage)
 */
#define  mp 6

/* gp = "global pointer" points
 * to bottom of memory for (global)
 * variable storage
 */
#define gp 5

/* accumulator */
#define  ac 0

/* 2nd accumulator */
#define  ac1 1

void emitRM(FILE *out, char * op, int r, int d, int s, char *c);
void emitRO(FILE *out, char *op, int r, int s, int t, char *c);
void emitComment(FILE *out, char * c );