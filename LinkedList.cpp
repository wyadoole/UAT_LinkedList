// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;


int main()
{
	LinkedList<int> list;
	for (int i = 0; i < 10; i++){list.insert(i);}//inserts in the list from 0 intill 10 which is stops 
	for (int i = 0; i < 10; i++)// prints out the list in order 
	{ 
		cout << "Addr: " << list.dataToFind(i) << endl;//"box" in wich it is stored 
		cout << "Value: " << list.dataToFind(i)->data << endl;//value in the box
	}
	list.deleteData(list.dataToFind(3));//delete the data in the address that I told it to delete with the value 
	list.deleteData(list.dataToFind(5));//delete the data in the address that I told it to delete with the value
	cout << "---------------------" << endl; //spacing to show that the new list that a printed are different and can be easly read
	for (int i = 0; i < 10; i++)//iterats through the list through the for loop until it gets to 10 
	{
		if (list.dataToFind(i) != nullptr)//if dataToFind returns null dont print anything 
		{
			cout << "Addr: " << list.dataToFind(i) << endl;//print "box" in which it is stored
			cout << "Value: " << list.dataToFind(i)->data << endl;// the value in the box 
		}
	}
	system("pause");//pause for user input to continue 
	return 0;//returns nothing 
}

