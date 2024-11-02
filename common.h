#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <setjmp.h>

#define MAX_WORDS 100
#define MAX_VARIABLES 100

typedef long stack_item;

// Déclaration anticipée pour Interpreter
struct s_interpreter;
typedef struct s_interpreter Interpreter;

// Définition de Stack
typedef struct s_stack
{
    stack_item *data;
    int size;
    int capacity;
    Interpreter *interpreter;
} Stack;

// Définition de Variable
typedef struct
{
    char *name;
    stack_item value;
} Variable;

// Définition de WordFunction
typedef void (*WordFunction)(Stack *);

// Définition de Word
typedef struct s_word
{
    char *name;
    WordFunction func;
} Word;

// Définition de Interpreter
struct s_interpreter
{
    Stack stack;
    Word words[MAX_WORDS];
    int word_count;
    Variable variables[MAX_VARIABLES];
    int variable_count;
    jmp_buf env;
};

// fonction utilitaires:
// Fonctions utilitaires
int compare_lexemes(const void *a, const void *b);


#endif // COMMON_H
