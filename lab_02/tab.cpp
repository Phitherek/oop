#include <iostream>
#include <cstdlib>
#include "tab.h"
using namespace std;

int getindex(int rowsize, int x, int y) {
return x*rowsize+y;	
}

void init(Tab* t, int x, int y, int initval) {
t = (Tab*)malloc(sizeof(Tab));
t.tab = (int*)malloc(x*y*sizeof(int));
t.x = x;
t.y = y;
for(int i = 0; i < getindex(t.x, t.x-1, t.y-1)+1; i++) {
	t.tab[i] = initval;
}
}

void diag(Tab* t, int val) {
int x = 0;
int y = 0;
while(x < t.x && y < t.y) {
t.tab[getindex(t.x, x, y)] = val;
x++;
y++;
}
}

void set(Tab* t, int x, int y, int val) {
t.tab[getindex(t.x, x, y)] = val;	
}

void set_part(Tab* t, TabRange range, int val) {
	for(int i = range[0]; i < range[2]; i++) {
		for(int j = range[1]; j < range[3]; j++) {
		t.tab[getindex(t.x, i, j)] = val;	
		}
	}
}

void print(Tab* t) {
	for(int i = 0; i < t.x; i++) {
		for(int j = 0; j < t.y; j++) {
		cout << t.tab[getindex(t.x, i, j)] << " ";	
		}
		cout << endl;
	}
}

void insert(Tab* source, Tab* dest, TabRange range) {
int x = 0;
int y = 0;
for(int i = range[0]; i < range[2]; i++) {
	for(int j = range[1]; j < range[3]; j++) {
	dest.tab[getindex(dest.x, i, j)] = source.tab[getindex(source.x, x, y)];
	if(x+1 >= source.x) {
	x = 0;
	y++;	
	} else {
	x++;	
	}
	}
}
}

Tab* extract(Tab* t, TabRange range) {
Tab* newtab;
newtab = (Tab*)malloc(sizeof(Tab));
int sizex = range[2]-range[0];
int sizey = range[3]-range[1];
newtab.tab = (int*)malloc(sizex*sizey*sizeof(int));
newtab.x = sizex;
newtab.y = sizey;
int x = 0;
int y = 0;
for(int i = range[0]; i < range[2]; i++) {
	for(int j = range[1]; j < range[3]; j++) {
	newtab.tab[getindex(newtab.x, x, y)] = t.tab[getindex(t.x, i, j)];
	if(x+1 >= newtab.x) {
	x = 0;
	y++;	
	} else {
	x++;	
	}
	}
}
return newtab;
}

void clean(Tab* t) {
free(t.tab);
t.tab = NULL;
free(t);
}
