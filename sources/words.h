#ifndef WORDS_H
#define WORDS_H

#include "common.h"
#include "stack.h"

// Définitions des mots de base.
void add(Stack *stack); 
void subtract(Stack *stack);
void multiply(Stack *stack);
void divide(Stack *stack);
void dot(Stack *stack);
void show(Stack *stack);
void store_at_address(Stack *stack);
void fetch_from_address(Stack *stack);
void dup(Stack *stack);
void drop(Stack *stack);
void swap(Stack *stack);
void tuck(Stack *stack);
void over(Stack *stack);
void rot(Stack *stack);
void two_dup(Stack *stack);
void two_drop(Stack *stack);
void cell(Stack *stack);

#endif // WORDS_H
