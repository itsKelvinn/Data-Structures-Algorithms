#include <iostream>

using namespace std;

struct Node{

    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

Node* createNode(int value){
    Node *node = new Node;
    node->value = value;
    node->next = NULL;  
    return node;
}

void insert_back(int value){
    Node *newNode = createNode(value);

    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void insert_front(int value){
    Node *newNode = createNode(value);

    if(tail == NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void delete_back(){
    if(tail == NULL){
        cout << "There is no data" << endl;
    }
    else{
        Node *temp = head;

        while(temp->next != tail){
            temp = temp->next;
        } 

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

}

void delete_front(){
    if(head == NULL){
        cout << "There is no data " << endl;
    }
    else{
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}



void search(int value){
    Node *temp = head;
    
    while (temp != nullptr){
        if(temp->value == value){
            cout << "data found" << endl;
            break;
        }
        
        temp = temp->next;

    }

    if(temp == nullptr){
        cout << "data not found" << endl;
    }
    
}

void print_all_node(){
    
    Node* temp = head;

    while(temp != NULL){
        cout << temp->value << endl;
        temp = temp->next;
    }

    cout << "head : " << head->value << endl;
    cout << "tail : " << tail->value << endl;
}

int main(){

    insert_front(1);
    insert_front(2);
    insert_front(3);
    insert_front(4);

    search(5);

    // print_all_node();

    return 0;
}