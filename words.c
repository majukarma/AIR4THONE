#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include "words.h"

void add(Stack *stack)
{
    stack_item b = pop(stack);
    stack_item a = pop(stack);
    push(stack, a + b);
}

void subtract(Stack *stack)
{
    stack_item b = pop(stack);
    stack_item a = pop(stack);
    push(stack, a - b);
}

void multiply(Stack *stack)
{
    stack_item a = pop(stack);
    stack_item b = pop(stack);
    push(stack, a * b);
}

void divide(Stack *stack)
{
    stack_item b = pop(stack);
    stack_item a = pop(stack);
    if (b == 0)
    {
        printf("Error: Division by zero\n");
        longjmp((stack->interpreter->env), 1);
    }
    else
    {
        push(stack, a / b);
    }
}

void dot(Stack *stack)
{
    stack_item a = pop(stack);
    printf("%ld\n", a);
}

void dup(Stack *stack)
{
    stack_item a = get_tos(stack);
    push(stack, a);
}

void show(Stack *stack)
{
    if (stack->size > 0)
    {
        printf("Stack content: ");
        for (int i = 0; i < stack->size; i++)
        {
            printf("%ld ", stack->data[i]);
        }
    }
    else
    {
        printf("Stack is empty!");
    }
    printf("\n");
}

void store_at_address(Stack *stack) {
    stack_item address = pop(stack);  // Obtenir l'adresse mémoire
    stack_item value = pop(stack);    // Obtenir la valeur
    *(stack_item *)address = value;   // Stocker la valeur à l'adresse
}

void fetch_from_address(Stack *stack) {
    stack_item *address = (stack_item *)pop(stack); // Obtenir l'adresse mémoire
    printf("Fetching value from address: %p\n", (void *)address); // Ajoutons une trace
    stack_item value = *address;                    // Obtenir la valeur à cette adresse
    push(stack, value);                             // Pousser la valeur sur la pile
    printf("Fetched value %ld from address %p\n", value, (void *)address); // Trace additionnelle
}

void drop(Stack *stack) {
            pop(stack);
}

void swap(Stack *stack) {
    if (stack->size >= 2) {
        stack_item* tos = &stack->data[stack->size - 1]; // Référence au sommet de la pile
        stack_item* nos = &stack->data[stack->size - 2]; // Référence au deuxième élément

        // Échange des valeurs
        stack_item temp = *tos;
        *tos = *nos;
        *nos = temp;

        printf("Swapped top two elements.\n");
    } else {
        printf("Error: Not enough elements on the stack\n");
        longjmp((stack->interpreter->env), 1);
    }
}


void tuck(Stack *stack) {
    stack_item a = pop(stack);
    stack_item b = pop(stack);
    push(stack, a);
    push(stack, b);
    push(stack, a);
}

void over(Stack *stack) {
    stack_item a = pop(stack);
    stack_item b = pop(stack);
    push(stack, b);
    push(stack, a);
    push(stack, b);
}

void rot(Stack *stack) {
    stack_item a = pop(stack);
    stack_item b = pop(stack);
    stack_item c = pop(stack);
    push(stack, b);
    push(stack, a);
    push(stack, c);
}

void two_dup(Stack *stack) {
    stack_item a = pop(stack);
    stack_item b = pop(stack);
    push(stack, b);
    push(stack, a);
    push(stack, b);
    push(stack, a);
}

void two_drop(Stack *stack) {
    pop(stack); // Déjà géré par la fonction pop
    pop(stack); // Déjà géré par la fonction pop
}

void cell(Stack *stack) {
    push(stack, sizeof(stack_item));
}
