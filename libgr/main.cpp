#include <iostream>
#include <vector>
#include "linkedlist.hpp"
int main(int argc, char** argv)
{
	std::vector<int>* myVect = new std::vector<int>(10);
	std::vector<const char*> myOtherVect(10);
	(*myVect)[0] = 255;
	myOtherVect[0] = "Hello World!";
	std::cout << (*myVect)[0] << std::endl;
	//int var;
	gr::LinkedList<int>* myLL = new gr::LinkedList<int>();
	for(int i = 0; i < 3; i++)
		myLL->add(i);
	gr::LinkedList<int>::Iterator* it = myLL->iterator();
	std::cout << it->current()->getData() << std::endl;
	it->next();
	it->remove();
	it->remove();
	it->remove();
	delete myVect;
	delete myLL;
	int* abc = new int;
	delete abc;
	return 0;
}