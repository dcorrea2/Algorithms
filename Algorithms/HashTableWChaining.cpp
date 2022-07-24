#include <iostream>
#include <list>
using namespace std;

class HashTable { 
private:
	list<int> *hashTable;
public:

	void createNewTable(int size) {
		hashTable = new list<int>[size];
	}

	void insert(int key, int size) {

		hashTable[key%size].push_front(key);

	}


	void search(int key, int size) {
		list<int> sInd = hashTable[key%size];
		list<int>::iterator val;
		int index = 0;
		if (sInd.empty())
			cout << key << ":NOT_FOUND;" << endl;
		else {

			for (val = sInd.begin(); val != sInd.end(); ++val){
				if (*val == key){
					cout << key << ":FOUND_AT" << (key%size) << "," << index << ";" << endl;
					return;
				}
				index++;
			}
			cout << key << ":NOT_FOUND;" << endl;
		}

	}

	bool deleteKey(int key, int size) {
		list<int> index = hashTable[key%size];
		list<int>::iterator val;
		if (index.empty())
			return false;
		else {

			for (val = index.begin(); val != index.end(); ++val) {
				if (*val == key) {
					index.erase(val);
					hashTable[key%size] = index;
					return true;
				}
			}
			return false;
		}
	}
	void output(int size) {
		list<int> index;
		list<int>::iterator val;
		for (int i = 0; i<size; i++) {
			index = hashTable[i];

			if (index.empty()){
				cout << i << ":;" << endl;
			}
			else {
				cout << i << ":";
				for (val = index.begin(); val != index.end(); ++val){
					cout << *val << "->";
				}
				cout << ";" << endl;
			}
		}
	}

};

int main()
{
	int size, key;
	cin >> size;
	char op;

	HashTable table;
	table.createNewTable(size);
	cin >> op;
	while (op != 'e') {
		if (op == 'i') {
			cin >> key;
			table.insert(key, size);
		}
		else if (op == 'd') {
			cin >> key;
			if (table.deleteKey(key, size))
				cout << key << ":DELETED;" << endl;
			else
				cout << key << ":DELETE_FAILED;" << endl;
		}
		else if (op == 's') {
			cin >> key;
			table.search(key, size);

		}
		else if (op == 'o') {
			table.output(size);
		}

		cin >> op;
	}



	return 0;
}

