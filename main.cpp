#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

int main()
{
	LinkedList<int> l1;

	l1.addToHead(20);
	l1.print();
	l1.addToTail(40);
	l1.print();
	l1.add(1,60);
	l1.print();

	l1.add(2,75);
	l1.print();

	l1.add(3,70);
	l1.print();

	l1.add(4,80);
	l1.print();

	l1.deleteTail();
	l1.print();

	l1.deleteAt(3);
	l1.print();

    
LinkedList<int> l2;

	l2.addToHead(10);
	l2.print();
	l2.addToTail(23);
	l2.print();
	l2.add(1,43);
	l2.print();

	l2.add(2,55);
	l2.print();

	l2.add(3,27);
	l2.print();

	l2.add(4,19);
	l2.print();

	l2.deleteTail();
	l2.print();

	l2.deleteAt(2);
	l2.print();

	return 0;
}