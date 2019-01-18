//  tabletest.cpp

#include <iostream>
#include <fstream>
#include "table.h"
using namespace std;

int main(){
	cout << "Running tabletest.cpp\n";
	ifstream input;
    input.open("fips.txt");
    if (!input.good()) {
        cout << "No fips.txt in current directory. Quitting\n";
        return 1;
    }
    Table t3(100, input);
    Table t1(200, input);
    Table t2(t3);
    // t3.printTable();
    // std::string test = t3.get(31007);
    // cout << "test: "<< test << endl;
    // bool found = t3.remove(31007);
    // cout << found << endl;
    // t3.printTable();
    // found = t3.remove(31007);
    // cout << found << endl;
    //t3.printTable();
    t1 = t2;
    t1.printTable();

    

	return 0;
}