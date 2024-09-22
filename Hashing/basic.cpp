#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<list<pair<int, string>>> table; // হ্যাশ টেবিল

public:
    HashTable(int size) {
        table.resize(size);
    }

    int hashFunction(int key) {
        return key % table.size(); // সিম্পল হ্যাশ ফাংশন
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value));
    }

    void display() {
        for (int i = 0; i < table.size(); i++) {
            cout << "Index " << i << ": ";
            for (auto& entry : table[i]) {
                cout << "{" << entry.first << ", " << entry.second << "} ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert(1, "One");
    ht.insert(2, "Two");
    ht.insert(11, "Eleven"); // Collision example
    ht.display();
    return 0;
}
