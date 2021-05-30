#include "Queue.h"
#include <fstream>
int main()
{
	std::string input = "test1.txt";
	std::ifstream ifs;
	ifs.open(input);
	char command;
	int val;
	Queue<int>* myQueue = nullptr;
	try
	{
		while (ifs >> command)
		{
			switch (command)
			{
			//=================================================
			// u : create Queue
			// i capacity : create Queue with capacity
			// c : clear
			// p item : push item
			// d : pop (deQueue)
			// f : get front
			// b : get back
			// o : push front
			// z : print Queue
			//=================================================
			case 'u':
				myQueue = new Queue<int>();
				printf("Create queue\nDefault capacity: %d\n", 1000);
				break;
			case 'i':
				ifs >> val;
				if (val < 0) {
					throw "Capacity can not a negative number\n";
				}
				if (val == 0) {
					throw "Capacity can not be zero\n";
				}
				myQueue = new Queue<int>(val);
				printf("Create queue\nCapacity: %d\n", val);
				break;
			case 'c':
				myQueue->clear();
				printf("Clear queue\n");
				break;
			case 'p': 
				ifs >> val;
				printf("Push: %d\n", val);
				myQueue->push(val);
				break;
			case 'o':
				ifs >> val;
				printf("Push front: %d\n", val);
				myQueue->push_front(val);
				
				break;
			case 'd': 
				printf("Pop: %d\n", myQueue->front());
				myQueue->pop();
				break;
			case 'f':
				printf("Front: %d\n", myQueue->front());
				break;
			case 'b':
				printf("Back: %d\n", myQueue->back());
				break;
			case 'z':
				myQueue->print();
				printf("\n");
				break;
			default:
				throw "Wrong input format\n";
			}
		}
	}
	catch (const char * message)
	{
		printf("Error: %s", message);
	}
	
	

	return 0;
}