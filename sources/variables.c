#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variables.h"
#include "stack.h"

void define_variable(Interpreter *interpreter, char *variable_name) {
    // Vérifier si le nom est déjà un mot
    Word key = { .name = variable_name };
    if (bsearch(&key, interpreter->words, interpreter->word_count, sizeof(Word), compare_lexemes)) {
        printf("Error: Variable name '%s' is already a word\n", variable_name);
        longjmp((interpreter->env), 1);
    }

    // Vérifier si la variable existe déjà
    Variable key_var = { .name = variable_name };
    if (bsearch(&key_var, interpreter->variables, interpreter->variable_count, sizeof(Variable), compare_lexemes)) {
        printf("Error: Variable name '%s' already exists\n", variable_name);
        longjmp((interpreter->env), 1);
    }

    // Taille du tableau à réserver, 1 par défaut
    stack_item size = pop(&interpreter->stack); 

    // Ajouter la nouvelle variable ou tableau
    Variable *var = &interpreter->variables[interpreter->variable_count];
    var->name = strdup(variable_name);
    if (size == 1) {
        var->value = 0L;
    } else {
        var->value = (stack_item)malloc(size * sizeof(stack_item));
        if (var->value == NULL) {
            printf("Error: Memory allocation failed for variable '%s'\n", variable_name);
            longjmp((interpreter->env), 1);
        }
        // Initialiser la mémoire allouée à 0
        memset((void*)var->value, 0, size * sizeof(stack_item));
    }
    interpreter->variable_count++;

    // Trier les variables après les avoir ajoutées
    qsort(interpreter->variables, interpreter->variable_count, sizeof(Variable), compare_lexemes);
    printf("Defined variable '%s'. Variable count is now %d\n", variable_name, interpreter->variable_count);
}

void forget_variable(Interpreter *interpreter, char *variable_name) {
    Variable key_var = { .name = variable_name };
    Variable *variable = (Variable *)bsearch(&key_var, interpreter->variables, interpreter->variable_count, sizeof(Variable), compare_lexemes);
    
    if (variable) {
        // Libérer la mémoire allouée pour le nom de la variable
        free(variable->name);

        // Déplacer toutes les variables après celle à supprimer
        for (Variable *v = variable; v < &interpreter->variables[interpreter->variable_count - 1]; v++) {
            *v = *(v + 1);
        }

        interpreter->variable_count--;
        printf("Forgot variable '%s'. Variable count is now %d\n", variable_name, interpreter->variable_count);
    } else {
        printf("Error: Variable '%s' not found\n", variable_name);
    }
}
