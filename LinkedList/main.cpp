#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList<int> list;
	list.addHead(0);
	list.addTail(2);
	list.addHead(0);
	list.addTail(3);
	list.add(2, 5);
	cout << list;
	list.popHead();
	cout << list;
	list.popTail();
	cout << list << list.size();
	list.pop(1);
	cout << list << list.size();

	return 0;
}