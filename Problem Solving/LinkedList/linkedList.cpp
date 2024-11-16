#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList(){
        Node* temp = head;
        while(head){
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void append(int value){
       Node* newNode = new Node(value);
       if(!head){
           head = newNode;
           tail = newNode;
           length++;
           return;
       }

       tail->next = newNode;
       tail = newNode;
       length++;
    }

    void deleteLast(){
        if(length == 0) return;

        Node* temp = head;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }else{
            while(temp->next != tail){
                temp = temp->next;
            }
            tail = temp;
            temp = temp->next;
            tail->next = nullptr;
            length--;
        }
        delete temp;
    }

    void prepend(int value){
        Node* newNode = new Node(value);
        if(!head){
           head = newNode;
           tail = newNode;
           length++;
           return;
       }
        newNode->next = head;
        head = newNode;
        length++;
    }

    void deleteFirst(){
        if(length == 0) return;

        Node* temp = head;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }else{
            head = head->next;
            temp->next = nullptr;
        }
        delete temp;
    }

    void print(){
        Node* temp = head;

        while(temp){
            cout << temp->value << "\n";
            temp = temp->next;
        }
    }

    void getHead(){
        if(head){
            cout << "Head: " << head->value << "\n";
        }else{
            cout << "There's no value in the list\n";
        }
    }
    void getTail(){
        if(tail){
            cout << "Tail: " << tail->value << "\n";
        }else{
            cout << "There's no value in the list\n";
        }
    }
    void getLength(){
        cout << "length: " << length << "\n";
    }
};

int main(){
    LinkedList* list1 = new LinkedList(5) ;

    list1->append(10);
    list1->append(15);
    list1->print();
    list1->deleteLast();
    list1->print();
    list1->getHead();
    list1->getTail();
    list1->getLength();
    list1->deleteLast();
    list1->print();
    list1->prepend(20);
    list1->prepend(22);
    list1->prepend(25);
    list1->print();
    list1->deleteFirst();
    list1->print();

    return 0;
}
