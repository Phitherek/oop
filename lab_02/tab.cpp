#include <iostream>
#include <cstdlib>
#include "tab.h"
using namespace std;

int getindex(int rowsize, int x, int y) {
return x*rowsize+y;	
}

void init(Tab* t, int x, int y, int initval) {
(*t).tab = (int*)malloc(x*y*sizeof(int));
t -> x = x;
t -> y = y;
for(int i = 0; i < getindex((*t).y, (*t).x-1, (*t).y-1)+1; i++) {
	(*t).tab[i] = initval;
}
}

void diag(Tab* t, int val) {
int x = 0;
int y = 0;
while(x < (*t).x && y < (*t).y) {
(*t).tab[getindex((*t).y, x, y)] = val;
x++;
y++;
}
}

void set(Tab* t, int x, int y, int val) {
(*t).tab[getindex((*t).y, x, y)] = val;	
}

void set_part(Tab* t, TabRange range, int val) {
	for(int i = range[0]; i < range[2]; i++) {
		for(int j = range[1]; j < range[3]; j++) {
		(*t).tab[getindex((*t).y, i, j)] = val;	
		}
	}
}

void print(Tab* t) {
	if((*t).tab != NULL) {
	for(int i = 0; i < (*t).x; i++) {
		for(int j = 0; j < (*t).y; j++) {
		cout << (*t).tab[getindex((*t).y, i, j)] << " ";	
		}
		cout << endl;
	}
	} else {
	cout << endl;	
	}
}

void insert(Tab* source, Tab* dest, TabRange range) {
int x = 0;
int y = 0;
for(int i = range[0]; i < range[2]; i++) {
	for(int j = range[1]; j < range[3]; j++) {
	(*dest).tab[getindex((*dest).y, i, j)] = (*source).tab[getindex((*source).y, x, y)];
	if(y+1 >= (*source).y) {
	y = 0;
	x++;	
	} else {
	y++;	
	}
	}
}
}

Tab* extract(Tab* t, TabRange range) {
static Tab newtab;
int sizex = range[3]-range[1];
int sizey = range[2]-range[0];
newtab.tab = (int*)malloc(sizex*sizey*sizeof(int));
newtab.x = sizex;
newtab.y = sizey;
int x = 0;
int y = 0;
for(int i = range[1]; i < range[3]; i++) {
	for(int j = range[0]; j < range[2]; j++) {
	newtab.tab[getindex(newtab.y, x, y)] = (*t).tab[getindex((*t).y, i, j)];
	if(y+1 >= newtab.y) {
	y = 0;
	x++;	
	} else {
	y++;	
	}
	}
}
return &newtab;
}

void clean(Tab* t) {
free((*t).tab);
(*t).tab = NULL;
(*t).x = 0;
(*t).y = 0;
}
