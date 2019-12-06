//
//  Queue.c
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
	Node next;
};

struct strQueue{
	Data name;
	Node first,last;
	int size;
};

Queue queue_create(Data name){
	Queue newQueue = (Queue)malloc(sizeof(struct strQueue));
	newQueue->first = NULL;
	newQueue->last = NULL;
	newQueue->name = name;
	newQueue->size = 0;
	return newQueue;
}

void queue_print(Queue queue){
	Node auxNode = queue->first;
	tokenType type;
	while(auxNode){
		data_print(auxNode->data):
		auxNode = auxNode->next;
	}
	return;
}


Data queue_name(Queue queue){
	return queue ? queue->name : NULL;
}


int queue_size(Queue queue){
	return queue ? queue->size : NULL;
}

bool queue_isEmpty(Queue queue){
	return queue && queue->size != 0 ? true : false;
}

void queue_offer(Queue queue, Data data){
	if(!queue){
		return;
	}
	Node node = (Node)malloc(sizeof(struct strNode));
	node->data = data;
	node->next = NULL;
	if(queue_isEmpty(queue)){
		queue->first = node;
	}
	else{
		queue->last->next = node;
	}
	queue->last = node;
	queue->size++;
}
Data queue_peek(Queue queue){
	if(!queue || queue->size == 0){
		return NULL;
	}
	return queue->first->data;
}
Data queue_poll(Queue queue){
	if(!queue || queue->size ==0){
		return NULL;
	}
	Node auxNode = queue->first;
	Data auxData = queue->first->data;
	queue->first = queue->first->next;
	queue->size --;
	if(queue->size == 0){
		queue->last = NULL;
	}
	free(auxNode);
	return auxData;
}
void queue_destroy(Queue queue){
	while(!queue_isEmpty(queue)){
		data_destroy(queue_poll(queue));
	}
	data_destroy(queue->name);
	free(queue);
	return;

}

