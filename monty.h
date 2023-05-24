#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * stack_s - double linked list
 * @n: value in list
 * @next: pointer to next node
 * @prev: pointer to previous node
 * Desription: structure that defines stack or queue
 */
typedef struct stack_s{
	int n;
	struct stack_s *next;
	struct stack_s *prev;
}stack_t;
/**
 * info_s - holdes info necessory for monty opcode interpreter
 * @content: content of a line in monty file
 * @arg: argument part of monty opecode
 * @fp: pointer to a monty file
 * @ll_type: change between stack <-> queue
 */
typedef struct info_s{
	char *content;
	char *arg;
	FILE *file;
	int ll_type;
}info_t;
extern info_t info;


typedef struct opcode{
	char *op;
	void (*func)(stack_t **stack, unsigned int counter);
}op_optn;
/**
 *
 *
 */
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void sq_push(stack_t **stack, unsigned int counter);
void sq_pall(stack_t **stack, unsigned int counter);
void sq_pint(stack_t **stack, unsigned int counter);
void sq_pop(stack_t **stack, unsigned int counter);
void sq_swap(stack_t **stack, unsigned int counter);
void sq_add(stack_t **stack, unsigned int counter);

#endif