#include <iostream>
#include "cards.h"
using namespace std;
int main()
{
	CardList testList = CardList("testList");

	testList.insert(42);
	testList.insert(22);
	testList.insert(5);
	testList.printCards();
	bool flag = testList.search(42);

	if(flag) cout << "42 found.\n";
	else cout << "42 not found.\n";

	Node* test = testList.remove(5);
	if(testList.search(5)) cout << "ERROR: 5 still found. Was not deleted.\n";
	else cout << "5 successfully deleted.\n";

	testList.insert(55);
	testList.insert(32);
	testList.insert(66);

	if(testList.maxTree(root)->val == 66) cout << "Maximum successfully found: 66.\n";
	else cout << "ERROR: returned maximum value was " << testList.maxTree(root)->val << endl;

	if(testList.minTree(root)->val == 22) cout << "Minimum successfully found: 22.\n";
	else cout << "ERROR: returned maximum value was " << testList.minTree(root)->val << endl;

	testList.deleteNodesC(testList);
	if(root) cout << "ERROR: root still exists. Was NOT deleted.\n";
	else cout << "Successfully deleted all nodes.\n";


	return 0;
}

