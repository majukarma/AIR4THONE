#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interpreter.h"
#include "variables.h"
#include "words.h"
#include "common.h"

int is_number(char *str)
{
    char *endptr;
    strtol(str, &endptr, 10);
    return *endptr == '\0';
}

void add_word(Interpreter *interpreter, char *name, WordFunction func)
{
    interpreter->words[interpreter->word_count].name = strdup(name);
    interpreter->words[interpreter->word_count].func = func;
    interpreter->word_count++;
}

void execute_word(Interpreter *interpreter, char *input) {
    Word key = { .name = input };
    Word *word = (Word *)bsearch(&key, interpreter->words, interpreter->word_count, sizeof(Word), compare_lexemes);
    
    if (word) {
        word->func(&interpreter->stack);
        return;
    }

    Variable key_var = { .name = input };
    Variable *variable = (Variable *)bsearch(&key_var, interpreter->variables, interpreter->variable_count, sizeof(Variable), compare_lexemes);
    
    if (variable) {
        push(&interpreter->stack, (stack_item)&(variable->value));  // Empile l'adresse de la valeur
        return;
    }

    printf("Mot non trouvé: %s\n", input);
}


void init_interpret(Interpreter *interpreter) {
    // Initialisation habituelle
    init_stack(interpreter, 10);
    interpreter->word_count = 0;
    interpreter->variable_count = 0;
    // Ajout des mots de base
    add_word(interpreter, "+", add);
    add_word(interpreter, "-", subtract);
    add_word(interpreter, ".", dot);
    add_word(interpreter, "*", multiply);
    add_word(interpreter, "/", divide);
    add_word(interpreter, ".s", show);
    add_word(interpreter, "!", store_at_address);
    add_word(interpreter, "@", fetch_from_address);
    add_word(interpreter, "dup", dup);
    add_word(interpreter, "drop", drop);
    add_word(interpreter, "swap", swap);
    add_word(interpreter, "tuck", tuck);
    add_word(interpreter, "over", over);
    add_word(interpreter, "rot", rot);
    add_word(interpreter, "2dup", two_dup);
    add_word(interpreter, "2drop", two_drop);
    add_word(interpreter, "cell", cell);

    // Trier les mots après les avoir ajoutés
    qsort(interpreter->words, interpreter->word_count, sizeof(Word), compare_lexemes);
}

char *get_next_word()
{
    static char input[100];
    if (scanf("%s", input) != EOF)
    {
        return input;
    }
    else
    {
        return NULL;
    }
}

void interpret(Interpreter *interpreter, char *input)
{
    if (is_number(input))
    {
        push(&interpreter->stack, atoi(input)); // Pousser le nombre sur la pile
    }
    else if (strcmp(input, "VAR") == 0)
    {
        char *variable_name = get_next_word();
        if (variable_name != NULL)
        {
            define_variable(interpreter, variable_name);
        }
    }
    else
    {
        execute_word(interpreter, input); // Exécuter le mot si ce n'est pas un nombre
    }
}

void repl(Interpreter *interpreter)
{
    if (setjmp(interpreter->env) == 0)
    {
        char input[100];
        while (scanf("%s", input) != EOF)
        {
            interpret(interpreter, input);
        }
    }
    else
    {
        printf("An error occurred. Stack reset.\n");
        init_stack(interpreter, 10); 
        repl(interpreter);           // Relance la boucle REPL
    }
}
