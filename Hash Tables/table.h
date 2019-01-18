//
//  table.h
//  S18 - Lab04
//
#ifndef table_h
#define table_h
#include "entry.h"
#include <vector>

class Table{
typedef std::vector<Entry> Array;
//defined by me
public:
	//defined by teacher
	Table(unsigned int max_entries = 100);
	Table(unsigned int entries, std::istream& input);
   //lab05 additions
   Table(const Table &t);
   //~Table();
   Table& operator=(const Table& right);
   //
	void put(unsigned int key, std::string data);
   void put(Entry e);
   std::string get(unsigned int key) const;
   bool remove(unsigned int key);
   const Entry* get_entry(unsigned int key) const;
   //defined by me
   int hash(unsigned int key) const;
   void printTable();
   int getCapacity() const;
   std::vector<std::vector<Entry> > getVector() const;

private:
	std::vector<std::vector<Entry> > v;
	int capacity;
};

void merge(int a[], size_t leftArraySize, size_t rightArraySize);
void mergesort(int a[], size_t size);
std::ostream& operator<< (std::ostream& out, const Table& t);

#endif /* table_h */