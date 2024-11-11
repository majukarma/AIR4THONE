#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <setjmp.h>
#include "common.h"


void init_interpret(Interpreter *interpreter);
void interpret(Interpreter *interpreter, char *input);
void add_word(Interpreter *interpreter, char *name, WordFunction func);
void execute_word(Interpreter *interpreter, char *input);
void repl(Interpreter *interpreter);

#endif // INTERPRETER_H
