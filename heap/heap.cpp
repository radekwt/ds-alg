#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap {
    class HeapNode {
    public:
        string birthDate;
        string name;
    };
    vector<HeapNode*> heap;
    bool byName = true;
public:
    Heap();
    static bool isFirstOlder(string date1, string date2);
    static bool isFirstHigher(string name1, string name2);
    void heapifyByName(int index);
    void heapifyByDate(int index);
    void deleteMin();
    void printAll();
    void insert(const string& date, const string& name);
    void changeOrder();
    void clean();
};
Heap::Heap() {
}
bool Heap::isFirstOlder(string date1,string date2) {
    for (int i = 6; i < 10; i++) {
        if (date1[i] < date2[i]) {
            return true;
        }
        if (date2[i] < date1[i]) {
            return false;
        }
    }
    for (int i = 3; i < 5; i++) {
        if (date1[i] < date2[i]) {
            return true;
        }
        if (date2[i] < date1[i]) {
            return false;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (date1[i] < date2[i]) {
            return true;
        }
        if (date2[i] < date1[i]) {
            return false;
        }
    }
    return false;
}
bool Heap::isFirstHigher(string name1, string name2) {
    int size;
    if (name1.size() > name2.size()) {
        size = name2.size();
    }
    else {
        size = name1.size();
    }
    for (int i = 0; i < size; i++) {
        if (name1[i] < name2[i]) {
            return true;
        }
        if (name2[i] < name1[i]) {
            return false;
        }
    }
    if (name1.size() >= name2.size()) {
        return false;
    }
    else
        return true;
}
//kod z wykładu
void Heap::heapifyByName(int index) {
    int size = heap.size();
    int childRight = 2 * index + 2;
    int childLeft = 2 * index + 1;
    int maxps;
    if (childLeft < size && isFirstHigher( heap[childLeft]->name,heap[index]->name)) {
        maxps = childLeft;
    }
    else {
        maxps = index;
    }
    if (childRight < size && isFirstHigher( heap[childRight]->name,heap[maxps]->name)) {
        maxps = childRight;
    }
    if (maxps != index) {
        swap(heap[index], heap[maxps]);
        heapifyByName(maxps);
    }
}
void Heap::heapifyByDate(int index)
{
    int size = heap.size();
    int childRight = 2 * index + 2;
    int childLeft = 2 * index + 1;
    int maxps;
    if (childLeft < size && isFirstOlder(heap[childLeft]->birthDate, heap[index]->birthDate)) {
        maxps = childLeft;
    }
    else {
        maxps = index;
    }
    if (childRight < size && isFirstOlder(heap[childRight]->birthDate, heap[maxps]->birthDate)) {
        maxps = childRight;
    }
    if (maxps != index) {
        swap(heap[index], heap[maxps]);
        heapifyByDate(maxps);
    }
}
void Heap::deleteMin()
{
    cout << heap[0]->birthDate << " " << heap[0]->name << endl;
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
    {
        if (byName)
            heapifyByName(i);
        else
            heapifyByDate(i);
    }
}
void Heap::printAll()
{
    for (size_t i = 0; i < heap.size(); i++) {
        cout <<heap[i]->birthDate<<" "<< heap[i]->name;
        cout << endl;
    }
}
void Heap::insert(const string &date,const string &name){
    HeapNode* new_node = new HeapNode;
    new_node->birthDate = date;
    new_node->name = name;
    heap.push_back(new_node);
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
    {
        if (byName)
            heapifyByName(i);
        else
            heapifyByDate(i);
    }
}
void Heap::changeOrder()
{
    if (byName)
        byName = false;
    else
        byName = true;

    for (int i = heap.size() / 2 - 1; i >= 0; i--)
    {
        if(byName)
            heapifyByName(i);
        else
            heapifyByDate(i);
    }
}
void Heap::clean()
{
    int size = heap.size();
    for (int i = 0; i < size; i++) {
        heap.pop_back();
    }
}
int main(){
    Heap heap;
    char input = 'x';
    while (input != 'q') {
        cin >> input;
        if (input == '+') {
            int howMany;
            string date;
            string name;
            cin >> howMany;
            for (int i = 0; i < howMany; i++) {
                cin >> date;
                cin >> name;
                heap.insert(date,name);
            }
        }
        if (input == '-') {
            int howMany;
            cin >> howMany;
            for (int i = 0; i < howMany; i++) {
                heap.deleteMin();
            }
        }
        if (input == 'p') {
            heap.printAll();
        }
        if (input == 'r') {
            heap.changeOrder();
        }
    }
    heap.clean();

}
