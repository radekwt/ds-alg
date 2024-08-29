#include <iostream>
#include <string>
using namespace std;
const int ALPHABET_SIZE = 26;
class Node {
public:
    Node* next[ALPHABET_SIZE];
    bool isEndOfWord;
    string trans;
};

void insert(Node* root, string key,string trans){
    Node* temp = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (temp->next[index]==NULL) {

            temp->next[index] = new Node;
            temp->next[index]->isEndOfWord = false;

            for (int i = 0; i < ALPHABET_SIZE; i++) {
                temp->next[index]->next[i] = NULL;
            }
        }
        temp = temp->next[index];
    }
    temp->trans = trans;
    temp->isEndOfWord = true;
}

string search(Node* root, string word){
    Node* temp = root;

    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (!temp->next[index])
            return "-";

        temp = temp->next[index];
    }
    if (!temp->isEndOfWord) {
        return "-";
    }
    return (temp->trans);
}
void display(Node* root) {
    if (root->isEndOfWord) {
        cout << root->trans << endl;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->next[i]) {
            display(root->next[i]);
        }
    }
}
void goToNode(Node* root, string word) {
    Node* temp = root;

    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (!temp->next[index]) {
            cout << "-" << endl;
            return;
        }
        temp = temp->next[index];
    }
   
    display(temp);
    
}
int main() {
    Node* root = new Node;
    root->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        root->next[i] = NULL;
    }
    string input;
    while (1) {
        cin >> input;
        if (feof(stdin) != 0) {
            break;
        }
        if (input == "+") {
            cin >> input;
            string trans;
            cin >> trans;
            insert(root, input, trans);
        }
        else if (input == "?") {
            cin >> input;
            cout << search(root, input) << endl;
        }
        else if (input == "*") {
            cin >> input;
            goToNode(root, input);
        }
    }
    return 0;
}
