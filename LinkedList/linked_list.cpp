#include <iostream>
using namespace std;
class Node {
public:
        int data;
        Node* next;
        Node* prev;
};
void addNode(Node** head, int data, int index) {
        Node* new_node = new Node();
        new_node->data = data;
        Node* temp = *head;
        if (index == 0) {
                if (*head == NULL) {
                        *head = new_node;
                        new_node->next = NULL;
                        new_node->prev = NULL;
                        return;
                }
                else {
                        new_node->next = *head;
                        new_node->prev = NULL;
                        (*head)->prev = new_node;
                        *head = new_node;
                }
        }
        int i = 0;
        while (i != index) {
                if (temp->next == NULL) {
                        temp->next = new_node;
                        new_node->next = NULL;
                        new_node->prev = temp;
                        return;
                }
                else
                temp = temp->next;
                i++;
        }
        temp->prev->next = new_node;
        new_node->next = temp;
        temp->prev = new_node;
        new_node->prev = temp->prev;
}
void deleteNode(Node** head,int index) {
        Node* temp = *head;
        if (index == 0) {
                if (*head == NULL) {
                        return;
                }
                else {
                        if ((*head)->next == NULL) {
                                delete temp;
                                *head = NULL;
                                return;
                        }
                        else {
                                (*head)->next->prev = (*head)->prev;
                                *head = (*head)->next;
                                delete temp;
                                return;
                        }
                }
        }
        int i = 0;
        while (i != index) {
                        temp = temp->next;
                        i++;
        }
        temp->prev->next = temp->next;
        if (temp->next == NULL) {
                delete temp;
                return;
        }
        temp->next->prev = temp->prev;
        delete temp;
}
int showElement(Node* head,int index) {
        Node* temp = head;
        int i = 0;
        while (i != index) {
                temp = temp->next;
                i++;
        }
        return temp->data;
}
void deleteList(Node** head) {
        Node* temp = *head;
        while (*head != NULL) {
                if ((*head)->next == NULL) {
                        delete (*head);
                        return;
                }
                (*head) = (*head)->next;
                delete (*head)->prev;
        }
}
int main() {
        Node* head = NULL;
        char input = NULL;
        int index,data;
        while (input != 'q') {
                cin >> input;
                if (input == 'i') {
                        cin >> data;
                        cin >> index;
                        addNode(&head, data, index);
                }
                else if (input == 'd') {
                        cin >> index;
                        deleteNode(&head, index);
                }
                else if (input == 'g') {
                        cin >> index;
                        cout << showElement(head, index)<<endl;
                }
        }
}
