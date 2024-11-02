#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include "stack.h"

void init_stack(Interpreter *interpreter, int capacity)
{
    interpreter->stack.interpreter = interpreter;
    interpreter->stack.data = (stack_item *)malloc(capacity * sizeof(stack_item));
    if (interpreter->stack.data == NULL)
    {
        printf("Failed to allocate memory for stack data.\n");
        exit(1);
    
    }
    interpreter->stack.size = 0;
    interpreter->stack.capacity = capacity;
}

void push(Stack *stack, stack_item value)
{
    if (stack->size == stack->capacity)
    {
        stack->capacity *= 2;
        stack->data = (stack_item *)realloc(stack->data, stack->capacity * sizeof(stack_item));
        if (stack->data == NULL) {
            printf("Failed to reallocate memory for stack data.\n");
            exit(1);
        }
    }
    stack->data[stack->size++] = value;
    printf("Pushed value %ld onto stack. Stack size is now %d\n", value, stack->size);
}

stack_item pop(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack underflow\n");
        longjmp((stack->interpreter->env), 1); // reviens au point sauvegardé avec un code d'erreur.
    }
    stack_item value = stack->data[--stack->size];
    printf("Popped value %ld from stack. Stack size is now %d\n", value, stack->size);
    return value;
}

stack_item get_tos(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack underflow\n");
        longjmp((stack->interpreter->env), 1); // reviens au point sauvegardé avec un code d'erreur.
    }
    return stack->data[stack->size - 1];
}
