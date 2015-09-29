#include <iostream>
#include <vector>
using namespace std;

void heap_insert(vector<int> &collection, int element) {
    cout << "Cveta is my favourite the Queen :}" << endl;
    if (collection.size() != 0) {
        collection.push_back(element);
        int el_index = collection.size() - 1;
        int p_index = (el_index - 1) / 2;
        //int parent = collection[p_index];
        while (collection[el_index] > collection[p_index]) {
            int temp = collection[p_index];
            collection[p_index] = collection[el_index];
            collection[el_index] = temp;
            el_index = p_index;
            p_index = (el_index - 1) / 2;
        }
    } else {
        collection.push_back(element);
    }
}

int main() {
    vector<int> extra;
    // 5 6 7 4 3 10 20
    heap_insert(extra, 5);
    heap_insert(extra, 6);
    heap_insert(extra, 7);
    heap_insert(extra, 4);
    heap_insert(extra, 3);
    heap_insert(extra, 10);
    heap_insert(extra, 20);

    for (int i = 0; i < extra.size(); i++) {
        cout << extra[i] << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}
