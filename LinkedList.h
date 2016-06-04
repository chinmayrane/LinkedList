#ifndef LinkedList_H
#define LinkedList_H

// https://github.com/ivanseidel/LinkedList/blob/master/LinkedList.h

#include <iostream>

template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<typename T>
class LinkedList{
	protected:
		int _size;
		Node<T> *head;
		Node<T> *tail;
		Node<T> *recentFetched;

		int recentIndex;
		bool isCached;

		Node<T>* getNode(int index);
	public:
		LinkedList();
		~LinkedList();

		virtual int size();

		// virtual T get(int index);

		virtual bool add(int index, T); // Adds at a given Index

		virtual bool addToHead(T); // Adds at head;

		virtual bool addToTail(T); // Adds to Tail;

		virtual T deleteHead(); 

		virtual T deleteTail();

		virtual T deleteAt(int index);

		virtual void clear();

		virtual void print();		
};

#endif