#include <iostream>
#include <stdio.h>
#include "LinkedList.h"

using namespace std;

// Constructor
template<typename T>
LinkedList<T>::LinkedList(){
	head = NULL;
	tail = NULL;
	_size = 0;

	recentFetched = head;
	recentIndex = 0;
	isCached = false;
}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList(){
	Node<T>* temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		delete temp;
	}

	tail = NULL;
	_size = 0;
	isCached = false;
}

// Size

template<typename T>
int LinkedList<T>::size(){
	return _size;
}

// Fetch a node at a particular position

template<typename T>
Node<T>* LinkedList<T>::getNode(int index){
	int _pos = 0;
	Node<T> *current = head;

	// Check if cached and immediately after the recently fetched
	if(isCached && recentIndex <= index){
		_pos = recentIndex;
		current = recentFetched;
	}

	while( _pos < index && current){
		current = current-> next;
		_pos++;
	}

	if(_pos == index){
		isCached = true;
		recentIndex = 	index;
		recentFetched = current;

		return current;
	}

	//return false;
}

// Add at any index

template<typename T>
bool LinkedList<T>::add(int index, T _t){
	if(index >= _size){
		return addToTail(_t);
	}

	if(index == 0){
		return addToHead(_t);
	}

	Node<T>* temp = new Node<T>();
	Node<T>* _prev = getNode(index-1);
	
	temp->data = _t;
	temp->next = _prev->next;
	_prev->next = temp;

	_size++;
	isCached = false;

	return true;
}

// Add at the Tail
template<typename T>
bool LinkedList<T>::addToTail(T _t){
	Node<T> *temp = new Node<T>();
	temp->data = _t;
	temp->next = NULL;

	if(head){
		tail->next = temp;
		tail = temp;
	}else{
		head = temp;
		tail = temp;
	}

	_size++;
	isCached = false;

	return true;
}

// Add to Head of Linked List
template<typename T>
bool LinkedList<T>::addToHead(T _t){
	if(_size == 0){
		return addToTail(_t);
	}

	Node<T> *temp = new Node<T>();
	temp->data = _t;
	temp->next = head;
	head = temp;

	_size++;
	isCached = false;

	return true;
}

//Delete Node at Tail

template<typename T>
T LinkedList<T>::deleteTail(){
	if(_size <= 0){
		return T();
	}

	isCached = false;

	if(_size >=2){
		Node<T>* temp = getNode(_size-2);
		
		T popNode = temp->next->data;

		delete (temp->next);
		temp->next = NULL;
		tail = temp;

		_size--;

		return popNode;
	}else{
		T popNode = head->data;
		delete(head);
		head = tail = NULL;
		_size = 0;
		return popNode;
	}
}

// Delete at Head

template<typename T>
T LinkedList<T>::deleteHead(){
	if(_size <= 0){
		return T();
	}
	
	if(_size > 1){
		Node<T>* temp = head->next;
		T popNode = head->data;
		delete(head);
		head = temp;

		_size--;
		isCached = false;

		return popNode;
	}else{
		return deleteTail();
	}
}

// Remove at a given Position

template<typename T>
T LinkedList<T>::deleteAt(int index){
	if(_size < 0 || index >= _size){
		return T();
	}

	if(index == 0){
		return deleteHead();
	}

	if(index == _size-1){
		return deleteTail();
	}

	Node<T>* temp = getNode(index-1);
	Node<T>* deleteNode = temp->next;
	T deletedNode = deleteNode->data;
	temp->next = deleteNode->next;
	delete(deleteNode);

	_size--;
	isCached = false;

	return deletedNode;
}

//Clear LinkedList

template<typename T>
void LinkedList<T>::clear(){
	while(size() > 0)
		deleteHead();
}

// Print Linked List
template<typename T>
void LinkedList<T>::print(){
	Node<T>* temp = head;

	cout<<"The Linked List is : ";

	while(temp){
		printf(" %d", temp->data);
		temp = temp->next;
	}

	cout<<"\n";
}