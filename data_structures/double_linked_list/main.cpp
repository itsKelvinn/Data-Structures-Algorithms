#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

Node* createNode(int value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insert_back(int value){
    Node* newNode = createNode(value);

    if(head == nullptr){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insert_front(int value){
    Node* newNode = createNode(value);

    if(head == nullptr){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void delete_back(){
    if(head == nullptr){
        cout << "There is no data" << endl;
    }
    else{
        Node* temp = tail->prev;
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }
}

void delete_front(){
    if(head == nullptr){
        cout << "There is no data" << endl;
    }
    else{
        Node *temp = head->next;
        temp->prev = nullptr;
        delete head;
        head = temp;
    }
}

void display_all_list(){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }

}

int main(){
    insert_back(1);
    insert_back(2);
    insert_back(3);
    insert_back(4);
    insert_back(5);
    insert_back(6);

    delete_front();
    delete_back();

    display_all_list();
    return 0;
}