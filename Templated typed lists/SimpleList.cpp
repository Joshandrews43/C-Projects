//SimpleList.cpp
//Josh Andrews
//May 28 2018
#include "SimpleList.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
template<class T>
void destroy(T element) {}
template<class T>
void destroy(T* element) {
	delete element;
}
template<class T>
SimpleList<T>::SimpleList() {
	this->numElements = 0;
	this->elements = new T[CAPACITY];
}
template<class T>
SimpleList<T>::~SimpleList(){
	for(int i = 0; i < this->numElements; i++) {
		destroy(elements[i]);
	}
	delete [] elements;
}
template<class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException){
	if(index < 0 || index >= numElements)
		throw InvalidIndexException();
	return elements[index];
}
template<class T>
bool SimpleList<T>::empty() const {
	if(this->getNumElements() == 0)
		return true;
	else
		return false;
}
template<class T>
T SimpleList<T>::first() const throw (EmptyListException) {
	if(this->empty())
		throw EmptyListException();
	return elements[0];
}
template<class T>
T SimpleList<T>::last() const throw (EmptyListException) {
	if(this->empty())
		throw EmptyListException();
	return elements[this->getNumElements()-1];
}
template<class T>
int SimpleList<T>::getNumElements() const {
	return this->numElements;
}
template<class T>
void SimpleList<T>::insert(T item) throw (FullListException) {
	if(this->getNumElements() == 10)
		throw FullListException();
	else {
		elements[this->getNumElements()] = item;
		this->numElements++;
	}
}
template<class T> 
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException) {
	if(this->empty())
		throw EmptyListException();
	else if(index < 0 || index > this->getNumElements()-1)
		throw InvalidIndexException();
	else {
		destroy(elements[index]);
		for(int i = index; i < CAPACITY - 1; i++){
			elements[i] = elements[i+1];
		}
		this->numElements--;
	}
}