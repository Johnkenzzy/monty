#include "monty.h"


instruction_t instructions[] = {
	{"push", push}, {"pall", pall},
	{"pint", pint}, {"pop", pop},
	{"swap", swap}, {"add", add},
	{"nop", nop}, {"sub", sub},
	{"div", divd}, {"mul", mul},
	{"pchar", pchar}, {"pstr", pstr},
	{"mod", mod}, {"rotl", rotl},
	{"rotr", rotr}, {"stack", stack},
	{"queue", queue}, {NULL, NULL}
};
