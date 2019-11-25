//
//  Stack.c
//  shrek
//
//

#include "List.h"
#include "Map.h"
#include "Set.h"
#include "Stack.h"
#include "Queue.h"

struct strNode{
	Data data;
	Node prior;
};
struct strStack{
	int size;
	Data name;
	Node top;
};

Stack stack_create(Data name){
	Stack newStack = (Stack)malloc(sizeof(struct strStack));
	newStack -> size = 0;
	newStack -> name = name;
	newStack -> top = NULL;
	return newStack;
}

void stack_print(Stack stack);

char * stack_name(Stack stack){
	return stack ? stack->name : NULL;
}

void stack_destroy(Stack stack);
bool stack_isEmpty(Stack stack){
	return stack->size != 0 ? true : false ;
}

int size(Stack stack){
	return stack ? stack->size : NULL;
}
Data stack_top(Stack stack){
	return stack ? stack->top->data : NULL;
}

Data pop(Stack stack){
	if(!stack || !stack->name){
		return NULL;
	}
	Data auxData = stack->top->data;
	Node auxNode = stack->top;
	stack->top = stack->top->prior;
	free(auxNode);
	return auxData;
}
void push(Stack stack,Data data){
	if(!stack){
		return;
	}
	Node newNode = (Node) malloc (sizeof(struct strNode));
	newNode->data = data;
	if(stack->top){
		newNode->prior = stack->top;
	}
	else{
		newNode->prior = NULL;
	}
	stack->top = newNode;
}
