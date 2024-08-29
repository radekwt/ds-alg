#include <iostream>
#include <string>
#define TABLE_SIZE 200000
using namespace std;
class Node{
public:
        string name;
    int value = 0;
    Node* next = NULL;
};
void addNode(Node** head, const string name) {
        Node* new_node = new Node;
        new_node->name = name;
        new_node->value = 1;
        Node* temp = *head;
        if ((*head) == NULL) {
                (*head) = new_node;
                return;
        }
        else {
                while (temp->next != NULL) {
                        if ((temp->name) == name) {
                                temp->value++;
                                delete new_node;
                                return;
                        }
                        temp = temp->next;
                }
                if ((temp->name) == name) {
                        temp->value++;
                        delete new_node;
                        return;
                }
                temp->next = new_node;
                return;
        }
}
void deleteNode(Node** head_ref, const string name)
{
        Node* temp = *head_ref;
        Node* prev = NULL;
        if (temp != NULL && (temp->name) == name)
        {
                *head_ref = temp->next; 
                delete temp;            
                return;
        }
        else
        {
                while (temp != NULL && (temp->name) != name)
                {
                        prev = temp;
                        temp = temp->next;
                }
                if (temp == NULL)
                        return;
                prev->next = temp->next;
                delete temp;
        }
}
int getNodeValue(Node* head, const string name) {
        Node* temp = head;
        while (temp != NULL) {
                if ((temp->name) == name) {
                        return temp->value;
                }
                temp = temp->next;
        }
        return 0;
}
class Hash {
        Node* node;
        int size;
        int count;
public:
    Node** table = new Node * [TABLE_SIZE];
        unsigned int hash(string name);
        void insertNode(string name);
        void deleteFromHash(string name);
        void showValue(string name);
};
unsigned int Hash::hash(const string name) {
        unsigned int hash = 0;
        int g = 31;
        for (size_t i = 0; i < name.length(); i++) {
                hash += (name)[i];
                hash = (g*(hash * (name)[i])) % TABLE_SIZE;
        }
        
        return hash;
}
void Hash::insertNode(const string name) {
        addNode(&table[hash(name)], name);
        return;
}
void Hash::deleteFromHash(const string name) {
        unsigned int index = hash(name);
        deleteNode(&table[index], name);
}
void Hash::showValue(const string name) {
        unsigned int index = hash(name);
        cout << getNodeValue(table[index], name) << endl;;
}
int main() {

        Hash hashTable;
        for (int i = 0; i < TABLE_SIZE; i++) {
                hashTable.table[i] = NULL;
        }
        string input;
        while (1) {
                cin >> input;
                if (input[0] == '?') {
                        input.erase(0,1);
                        hashTable.showValue(input);
                }
                else if (input[0] == '-') {
                        input.erase(0,1);
                        hashTable.deleteFromHash(input);
                }
                else if (input == "q") {
                        break;
                }
                else {
                        hashTable.insertNode(input);
                }
        }

        return 0;
}


