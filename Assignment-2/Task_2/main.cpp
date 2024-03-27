#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

class Node{
public:
    char value;
    Node* next;
    Node* previous;
};

class DoubleList{
public:
    Node* head;
    Node* tail;
    DoubleList(){
        head = tail = nullptr;
    }
    void insert(char c){
        Node* newNode = new Node();
        newNode->value=c;
        if(head == nullptr){
            head = tail = newNode;
            newNode->next = newNode->previous = nullptr;
        }else{
            newNode->next = nullptr;
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void concatenat(DoubleList list2){
        if(list2.head == nullptr){
            return;
        }
        Node* temp = list2.head;
        temp->previous = tail;
        tail->next = temp;
        list2.head= nullptr;
        tail = list2.tail;
    }
    int size(){
        Node* temp = head;
        int i = 0;
        while(temp != nullptr){
            temp =temp->next;
            i++;
        }
        return i;
    }
    void deleteFirst(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteLast(){
        Node* temp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete temp;
    }
    void deleteByIndex(int index){
        Node* delNode = head;
        Node* before = nullptr;
        if(index == 0){
            deleteFirst();
            return;
        }
        if(index == size()-1){
            deleteLast();
            return;
        }
        for (int i = 0; i < index; ++i) {
            before = delNode;
            delNode=delNode->next;
        }
        delNode->previous->next= delNode->next;
        delNode->next->previous = delNode->previous;
        delete delNode;
    }
    bool substring (int index , int length){
        Node* temp = head;
        if(index + length > size()){
            cout<<"please enter valid input."<<endl;
            return false;
        }
        for (int i = 1; i <= index; ++i) {
            temp=temp->next;
        }
        cout<<"Substring:";
        for (int i = 1; i <= length; ++i) {
            cout<<temp->value;
            temp= temp->next;
        }
        return true;
    }
    void printForward(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->value;
            temp=temp->next;
        }
        cout<<endl;
    }

    void printReverse(){
        Node* temp = tail;
        while(temp != nullptr){
            cout<<temp->value;
            temp=temp->previous;
        }
        cout<<endl;
    }


};

int main() {
    string s1 , s2;
    DoubleList list1 , list2;
    cout<<"Enter string to add to list 1:";
    cin>>s1;
    cout<<"Enter string to add to list 2:";
    cin>>s2;
    for (int i = 0; i < s1.size(); ++i) {
        list1.insert(s1[i]);
    }
    for (int i = 0; i < s2.size(); ++i) {
        list2.insert(s2[i]);
    }
    cout<<"Concatenated list: ";
    list1.concatenat(list2);
    list1.printForward();
    int index , length;
    cout<<"Choose a character by index to remove:";
    cin>>index;
    list1.deleteByIndex(index);
    cout<<"List after remove: ";
    list1.printForward();
    bool flage = false;
    while(!flage){
        cout<<"Enter index and length to get substring:";
        cin>>index>>length;
        flage = list1.substring(index,length);
    }

    return 0;
}
