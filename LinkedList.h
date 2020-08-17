#ifndef LINKEDLIST_H
#include <iostream>//includes standard library for p
template <typename T>//template for the type of t 
struct node//name of node and what is called before node 
{
	node<T>* next;//templated next 
	node<T>* back;//templated back 
	T data;// tells the program what the t is use for 
};

template <typename T>// templates data 
class LinkedList// the class in witch of the functions are called   
{
public:
	LinkedList()//linked list function
	{
		startNode = nullptr;// head or start of node 
	}
	void insert(T newData) //insert the node in order from 1 to 10 
	{
		node<T>* newNode = new node<T>;
		newNode->data = newData;//newNode->data assiagn to equal newData 
		if (startNode == nullptr)// is start node == nullptr dont print anything because their is no need to print 
		{ 
			startNode = newNode;
			newNode->back = nullptr;//this just sets the null pointer to back and next to nullptr if any of the node from 2 to 10 are deleted
			newNode->next = nullptr; //this just sets the null pointer to back and next to nullptr if any of the node from 2 to 10 are deleted
		}
		else //if one or the other does not = nullptr 
		{
			node<T>* currentNode = startNode;// starts the linked list program at startnode=headnode
			node<T>* lastNode = nullptr;//lastnode = to nullptr if their is not data in the linked list 
			while (currentNode != nullptr)// if the currentnode does not = nulptr go through the linked list and print value and address the screen and stop after you get to 10 
			{
				lastNode = currentNode; // keeping the linked list together even when you delete from the middle or insert from the middle and so forth 
				currentNode = currentNode->next;//next to move to the next node from the previous node
			}
			lastNode->next = newNode;//makes last node newNode when you create a new node  makes the one after that Nullptr.  
			newNode->next = nullptr; makes the one after that Nullptr.
			newNode->back = lastNode;//makes back lastNode before Nullptr
		}
	}
	node<T>* dataToFind(int data)// sets data to find 
	{
		if (startNode == nullptr)//start node = nothering return nothing  
		{
			return nullptr;//return null pointer 
		}else
		{
			node<T>* currentNode = startNode;// if startnode = current node go through this loop 
			while (true) 
			{
				if (currentNode == nullptr) // if node = nothing return nothing 
				{
					return nullptr;//returns null pointer 
				}
				else if (currentNode->data == data)//if data-> = data then return current node with data  
				{
					return currentNode;//return Node 
				}
				currentNode = currentNode->next;// move to next node 
			}
		}
	
	}
	void deleteData(node<T>* nodeToDel)// deletes the data from the list 
	{
		if (startNode == nullptr)// if current node is nullptr return null 
		{
			return; return null
		}
		else
		{
			if ((nodeToDel->next != nullptr) && (nodeToDel->back != nullptr))//if null == nodeToDel (delete node) 
			{
				nodeToDel->back->next = nodeToDel->next;//it makes the node that was deleted not confliect with the one binded it and the one ahead of it (next pointer)
				nodeToDel->next->back = nodeToDel->back;//it makes the node that was deleted not confliect with the one binded it and the one ahead of it (back)
			}
			else if (nodeToDel->back == nullptr)//if nullptr = nullmove to next node woith data in it 
			{
				nodeToDel->next->back = nullptr;//if nullptr = nullmove to next node woith data in it
				startNode = nodeToDel->next;//if nullptr = nullmove to next node woith data in it
			}
			else if (nodeToDel->next == nullptr)//if their is not data return nothing 
			{
				nodeToDel->back->next == nullptr;//if their is not data return nothing
			}

			delete nodeToDel;// deletes the node from the list 
		}
	}
private:
	node<T>* startNode;// does not change the the input and start location of the node of the linked list
};
#endif