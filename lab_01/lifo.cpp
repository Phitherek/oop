#include <iostream>
#include <cstdlib>
#include <cstring>
#include "lifo.h"
using namespace std;

Lifo* init() {
Lifo* newlifo = (Lifo*)malloc(sizeof(Lifo));
if(newlifo == NULL) {
cerr << "Memory allocation error!" << endl;
exit(1);
}
newlifo -> next = NULL;
return newlifo;	
}

void insert(Lifo* head, const char *txt) {
Lifo* newlifo = NULL;
newlifo = (Lifo*)malloc(sizeof(Lifo));
if(newlifo == NULL) {
cerr << "Memory allocation error!" << endl;
exit(1);
}
if(head == NULL) {
newlifo -> txt = txt;
newlifo -> next = NULL;
head = newlifo;
} else if(head -> txt == NULL) {
head -> txt = txt;	
} else {
Lifo* iter;
for(iter = head; iter -> next != NULL; iter = iter -> next);
newlifo -> txt = txt;
newlifo -> next = NULL;
iter -> next = newlifo;
}
}

const char* get(Lifo* head) {
	if(head -> txt == NULL) {
	cerr << "List is empty!" << endl;
	return 0;	
	}
	const char *tab;
	int len;
	Lifo *iter;
	Lifo *prev;
	for(iter = head; iter -> next != NULL; iter = iter -> next) {
	prev = iter;	
	}
	len = strlen(iter -> txt);
	tab = (char*)malloc(len*sizeof(char));
	tab = iter -> txt;
	free(iter);
	prev -> next = NULL;
	return tab;
}
