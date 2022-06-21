//Name: Scott Renslow
//Programming Assignment: Replacement Lab
//

#pragma once

#include "Nodes.h"

template <typename T>
class Widget;

template <typename T>
class Node
{
public:
	friend class Widget<T>;
private:
	T m_data;									//data members
	Nodes<T> m_nodes;

	Node();										//default
	Node(const Node<T>& copy);					//copy ctor
	Node(Node<T>&& other);						//move ctor
	Node<T>& operator= (const Node<T>& rhs);	//copy assignment
	Node<T>& operator= (Node<T>&& rhs);		    //move assignment
	~Node();									//dtor

	void IsLeaf();
	void Add(Node<T>* nodePtr);					//node class functions
	void Remove(Node<T>* nodePtr);
};

template <typename T>
Node<T>::Node(){

}

template <typename T>
Node<T>::Node(const Node<T>& copy){

}

template <typename T>
Node<T>::Node(Node<T>&& other){

}

template <typename T>
Node<T>& Node<T>::operator= (const Node<T>& rhs) {
	if (this != &rhs) {

	}
	return *this;
}

template <typename T>
Node<T>& Node<T>::operator= (Node<T>&& rhs) {
	if (this != &rhs) {

	}
	return *this;
}

template<typename T>
inline Node<T>::~Node(){

}

template<typename T>
void Node<T>::IsLeaf(){

}

template<typename T>
void Node<T>::Add(Node<T>* nodePtr){

}

template<typename T>
void Node<T>::Remove(Node<T>* nodePtr) {

}