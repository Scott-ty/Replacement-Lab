//Name: Scott Renslow
//Programming Assignment: Replacement Lab
//

#pragma once
#include <stdio.h>

template <typename T>
class Node;

template <typename T>
class Widget;

template <typename T>
class Nodes
{
public:
	friend class Node<T>;
	friend class Widget<T>;
private:
	Node<T>* m_nodes;							//Data Members
	size_t m_numberOfElements;				

	Nodes();									//default
	Nodes(const Nodes<T>& copy);				//copy ctor
	Nodes(Nodes<T>&& other);					//move ctor
	Nodes<T>& operator= (const Nodes<T>& rhs);	//copy assignment
	Nodes<T>& operator= (Nodes<T>&& rhs);		//move assignment
	~Nodes();									//dtor

	void Prepend(Node<T>* ptr);
	void Append(Node<T>* ptr);
	void Remove(Node<T>* ptr);					//nodes class functions
	bool Contains(Node<T>* ptr) const;
	size_t Count() const;
	Nodes<T>& operator [] (size_t index);
};

template <typename T>
Nodes<T>::Nodes() : m_numberOfElements(0), m_nodes(nullptr) {
}

template <typename T>
Nodes<T>::Nodes(const Nodes<T>& copy) : m_numberOfElements(other.m_numberOfElements) {
	for (int i = 0; i < m_numberOfElements; i++){
		m_nodes[i] = copy.m_nodes[i];
	}
}

template <typename T>
Nodes<T>::Nodes(Nodes<T>&& other) : m_numberOfElements(std::move(other.m_numberOfElements)){
	for (int i = 0; i < m_numberOfElements; i++) {
		m_nodes[i] = std::move(other.m_nodes[i]);
	}
	other.m_nodes = nullptr;
}

template <typename T>
Nodes<T>& Nodes<T>::operator= (const Nodes<T>& rhs) {
	if (this != &rhs){
		m_numberOfElements = rhs.m_numberOfElements;
		delete m_nodes;


		//m_nodes = (rhs.m_nodes != nullptr) ? new Node<T>(&rhs.m_nodes) : nullptr;
	}
	return *this;
}

template <typename T>
Nodes<T>& Nodes<T>::operator= (Nodes<T>&& rhs) {
	if (this != &rhs) {
		m_numberOfElements = std::move(rhs.m_numberOfElements);
		m_nodes = std::move(rhs.m_nodes);
		rhs.m_nodes = nullptr;
	}
	return *this;
}

template<typename T>
inline Nodes<T>::~Nodes(){
	//m_nodes = nullptr;
}

template<typename T>
void Nodes<T>::Prepend(Node<T>* ptr) {
	if (ptr == nullptr)
		throw std::exception("Out of Bounds!");
	Node<T>* temp = new Node<T>;
	for (int i = 0; i < m_numberOfElements; i++) {
		temp[i] = m_nodes[i];
	}
	temp[m_numberOfElements] = ptr;
	m_numberOfElements++;
	for (int i = 0; i < m_numberOfElements; i++) {
		m_nodes[i] = temp[i];
	}
}

template<typename T>
void Nodes<T>::Append(Node<T>* ptr) {
	if (ptr == nullptr)
		throw std::exception("Out of Bounds!");
}

template<typename T>
void Nodes<T>::Remove(Node<T>* ptr) {

}

template<typename T>
bool Nodes<T>::Contains(Node<T>* ptr) const {
	bool test = false;
	while (test == false) {
		for (int i = 0; i < m_numberOfElements; i++) {
			if (ptr == m_nodes)
				return test;
			else
				test = false;
		}
		return test;
	}
}

template<typename T>
size_t Nodes<T>::Count() const {
	return m_numberOfElements;
}

template<typename T>
Nodes<T>& Nodes<T>::operator [] (size_t index) {
	if (index > m_numberOfElements || index < 0)
		throw std::exception("Out of Bounds!");
	return m_nodes[index];
}