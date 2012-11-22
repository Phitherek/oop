#include <iostream>
#include <cstdlib>
#include <string>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "ObjectContainer.h"
using namespace std;

int main() {
char c = 's';
ObjectContainer oc;
while(c != 'p') {
cout << "What would you like to do? (a)dd an Object/(p)rint and quit: ";
cin >> c;
if(c == 'a') {
	string desc;
	cout << "desc: ";
	cin >> desc;
	char c2;
	cout << "(r)ectangle/(s)quare/(c)ircle/(t)riangle: ";
	cin >> c2;
	if(c2 == 'r') {
	Rectangle r;
	int x, y;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	r.setSize(x, y);
	r.setDesc(desc);
	cout << "Created rectangle: desc: " << r.getDesc() << ", x: " << r.getX() << ", y: " << r.getY() << endl;
	oc.push(r);	
	} else if(c2 == 's') {
	Square s;
	int x;
	cout << "x: ";
	cin >> x;
	s.setSize(x);
	s.setDesc(desc);
	cout << "Created square: desc: " << s.getDesc() << ", x: " << s.getSize() << endl;
	oc.push(s);	
	} else if(c2 == 'c') {
		Circle c;
	int r;
	cout << "r: ";
	cin >> r;
	c.setR(r);
	c.setDesc(desc);
	cout << "Created circle: desc: " << c.getDesc() << ", r: " << c.getR() << endl;
	oc.push(c);
	} else if(c2 == 't') {
		Triangle t;
	int a, h;
	cout << "a: ";
	cin >> a;
	cout << "h: ";
	cin >> h;
	t.setSize(a, h);
	t.setDesc(desc);
	cout << "Created rectangle: desc: " << t.getDesc() << ", a: " << t.getA() << ", h: " << t.getH() << endl;
	oc.push(t);
	} else {
	cerr << "No such object!" << endl;	
	}
} else if(c != 'p') {
cerr << "No such action!" << endl;	
}
}
while(oc.size() > 0) {
Object o;
o = oc.pop();
o.draw();
}
return EXIT_SUCCESS;
}
