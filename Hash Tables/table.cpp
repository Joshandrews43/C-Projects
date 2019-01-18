//  table.cpp
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "table.h"

using namespace std;




Table::Table(unsigned int max_entries){
	this->capacity = max_entries;
	v.resize(capacity);
}

Table::Table(unsigned int entries, std::istream& input){
	this->capacity = 2*entries;
	v.resize(capacity);

	string line, keyString, name;
	int key;
	for(int i = 0; i < entries; i++){
		line = "";
		keyString = "";
		name = "";
		getline(input, line);
		int index1 = line.find("\t");
		for(int j = 0; j < index1; j++){
			keyString+= line[j];
		}
		name = line.substr(index1+1);
		//cout << keyString << endl;
		//cout << name << endl;
		key = stoi(keyString);
		put(Entry(key, name));
	}
}

void Table::put(unsigned int key, std::string data){
	Entry temp = Entry(key, data);
	put(temp);
}

void Table::put(Entry e){
	int index = hash(e.get_key());

	for(int i = 0; i < v[index].size(); i++){
		if(v[index][i].get_key() == e.get_key()) {
			v[index][i] = e;
			return;
		}
	}
	v[index].push_back(e);
}

string Table::get(unsigned int key) const{
	int index = hash(key);
	//cout << "index: " << index << endl;
	for(int i = 0; i < v[index].size(); i++){
		if(v[index][i].get_key() == key)
			return v[index][i].get_data();
	}
	return "";
}

const Entry* Table::get_entry(unsigned int key) const{
	int index = hash(key);
	//cout << "index: " << index << endl;
	for(int i = 0; i < v[index].size(); i++){
		if(v[index][i].get_key() == key)
			return &v[index][i];
	}
	return NULL;
}

bool Table::remove(unsigned int key){
	int index = hash(key);

	for(auto i = v[index].begin(); i != v[index].end(); i++){
		if((*i).get_key() == key){
			v[index].erase(i);
			return true;
		} 
	}
	return false;
}

int Table::hash(unsigned int key) const{
	return key % capacity;
}


vector<vector<Entry> > Table::getVector() const{
	return v;
}

int Table::getCapacity() const{
	return capacity;
}



void Table::printTable(){
	int count = 1;
	for(int i = 0; i < v.size(); i++){
		for (int j = 0; j < v[i].size(); j++)
		{
			if(v[i][j].get_key() != 0){
				cout << count << ": " << " i: " << i << " j: " << j << " :" <<  v[i][j] << endl;
				count++;
			}
		}
	}
}

Table& Table::operator=(const Table& right){
	if (&right == this) {
		return *this;
	}

	this->capacity = right.capacity;
	this->v.resize(capacity);

	for(int i = 0; i < this->v.size(); i++){
		this->v[i].clear();
	}

	for(int i = 0; i < right.v.size(); i++){
		this->v[i].resize(right.v[i].size());
		for(int j = 0; j < right.v[i].size(); j++){
			this->put(right.v[i][j]);
		}
	}
	return *this;
}

// Table::~Table(){
// 	for(int i =0; i < v.size(); i++){
// 		for(int j = 0; j< v[i].size(); j++){
// 			delete v[i];
// 		}
// 	}
// }

Table::Table(const Table &t){
	//int count = 0;
	this->capacity = t.capacity;
	v.resize(capacity);
	if(t.capacity > 0){
		for(int i = 0; i < t.v.size(); i++){
			v[i].resize(t.v[i].size());
			//cout << "size of t.v[" << i << "] is " << t.v[i].size() << "\n";
			//cout << "size of v[" << i << "] is " << v[i].size() << "\n";
			for(int j = 0; j < t.v[i].size(); j++){
				this->put(t.v[i][j]);
				//cout << "successfully put";
				//count++;
				
			}
		}
	}
	//cout << count << endl;
}

void merge(unsigned int a[], size_t leftArraySize, size_t rightArraySize) {

	// Note: we are assuming the left and right sub arrays are sorted

	unsigned int* tempArray;		// tempArray to hold sorted elements
	size_t copied = 0; 	// num elements copied to tempArray
	size_t leftCopied = 0;	// num elements copied from leftArray
	size_t rightCopied = 0;	// num elements copied from rightArray

	// create temp array
	tempArray = new unsigned int[leftArraySize + rightArraySize];

	// merge left and right arrays into temp in sorted order
	while ((leftCopied < leftArraySize) && (rightCopied < rightArraySize)) {
		if (a[leftCopied] < (a + leftArraySize)[rightCopied]) {
			tempArray[copied++] = a[leftCopied++];
		} else {
			tempArray[copied++] = (a + leftArraySize)[rightCopied++];
		}
	}

	// copy remaining elements from left/right sub arrays into tempArray

	// if elements in leftArray still exist, then ...
	while (leftCopied < leftArraySize) {
		tempArray[copied++] = a[leftCopied++];
	}


	// if elements in rightArray still exist, then ...
	while (rightCopied < rightArraySize) {
		tempArray[copied++] = (a + leftArraySize)[rightCopied++];
	}

	// Replace the sorted values into the original array
	for (int i = 0; i < leftArraySize + rightArraySize; i++) {
		a[i] = tempArray[i];
	}

	// free up memory
	delete [] tempArray;
}


void mergesort(unsigned int a[], size_t size) {
	size_t leftArraySize;
	size_t rightArraySize;

	if (size > 1) {
		leftArraySize = size / 2;
		rightArraySize = size - leftArraySize;

		// call mergesort on left array
		mergesort(a, leftArraySize); 
		
		// call mergesort on right array
		mergesort((a + leftArraySize), rightArraySize);

		// left and right sorted arrays together
		merge(a, leftArraySize, rightArraySize);
	}
}

ostream& operator<< (std::ostream& out, const Table& t){
	auto v = t.getVector();

	vector<unsigned int> arr;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			arr.push_back(v[i][j].get_key());
		}
	}

	unsigned int* realArr = &arr[0];
	size_t len = arr.size();
	mergesort(realArr, len);

	for(int i = 0; i < len; i++){
		const Entry* e = t.get_entry(realArr[i]);
		if(e != NULL){
			out << *e << ": " << e->get_data() << endl;
		}
	}

	return out;

}
