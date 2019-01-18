// SimpleList.h

// Written for CS32 S18, Lab07

#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include "EmptyListException.h"
#include "FullListException.h"
#include "InvalidIndexException.h"

template <class T>
class SimpleList {
	public:
		SimpleList();
		~SimpleList();
		T at(int index) const throw (InvalidIndexException);
		bool empty() const;
		T first() const throw (EmptyListException);
		T last() const throw (EmptyListException);
		int getNumElements() const;
		void insert(T item) throw (FullListException);
		void remove(int index) throw (InvalidIndexException, EmptyListException);
		static const int CAPACITY = 10;
	private:
		int numElements;
		T* elements;
};

#endif