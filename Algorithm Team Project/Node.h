#ifndef __NODE_H__
#define __NODE_H__

#define NAME_LENGTH 20


typedef struct mynode {

	int time;
	int cost;
	char start[NAME_LENGTH];
	char end[NAME_LENGTH];
	struct mynode * next;

}Node;


typedef struct {

	Node * head;
	Node * tail;
	Node * before;

}Pointer;



#endif