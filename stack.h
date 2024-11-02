#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <setjmp.h>
#include "common.h"

void init_stack(Interpreter *interpreter, int capacity);
void push(Stack *stack, stack_item value);
stack_item pop(Stack *stack);
stack_item get_tos(Stack *stack);
#endif // STACK_H
