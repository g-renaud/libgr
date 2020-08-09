#include <iostream>
#include "linkedlist.hpp"

int main(int argc, char** argv)
{
	/*gr::Vector<const char*>* myVect = new gr::Vector<const char*>();
	myVect->set("aasdb");
	std::cout << myVect->get() << std::endl;*/
	//int var;
	gr::LinkedList<int>* myLL = new gr::LinkedList<int>();
	myLL->addNode(1);
	myLL->addNode(2);
	myLL->addNode(3);
	myLL->~LinkedList();
	delete myLL;
	return 0;
}