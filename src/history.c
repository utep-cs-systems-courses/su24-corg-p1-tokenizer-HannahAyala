#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
	List *newList = (List*)malloc(sizeof(List));
	newList -> root = NULL;
	return newList;
}

void add_history(List *list, char *str){
	Item *newItem = (Item*)malloc(sizeof(Item));

	Item *temp = (Item*)malloc(sizeof(Item));
	temp = list->root;
	newItem -> str = str;
	newItem -> next = NULL;
	
	if (temp == NULL){
		newItem -> id= 1;
		list -> root = newItem;
		return;
	}
	int count = 2;
	while (temp -> next != NULL){
		count++;
		temp = temp -> next;
	}
	
	 newItem -> id = count;
	 temp -> next = newItem;
	

}


char *get_history(List *list, int id){
	Item *temp = (Item*)malloc(sizeof(Item));
	temp = list -> root;
	while(temp!= NULL){
		if (temp -> id == id)
			return temp ->str;
		temp = temp -> next;
	}
	return "Not found";
}

void print_history(List *list){
	Item *temp = (Item*)malloc(sizeof(Item));
	temp = list -> root;

	while (temp != NULL){
		printf("%d: ", temp ->id);
	       	char *s = temp -> str;
		while (*s != 0){
			putchar(*s);
			s++;
		}
		putchar('\n');
		temp = temp -> next;
	}
}

void free_history(List *list){}


