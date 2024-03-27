#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
int subIndex = -1;
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
    void insertAt(char c, int index){
        Node* temp = head;
        Node* after= nullptr;
        Node* newNode = new Node();
        if(index == size()-1){
            insert(c);
            return;
        }
        for (int i = 0; i < index; ++i) {
            temp=temp->next;
        }
        after = temp->next;
        newNode->value=c;
        temp->next = newNode;
        newNode->previous = temp;
        newNode->next=after;
        after->previous=newNode;
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
        cout<<endl;
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

    int Search(string substr) {
        if (substr.empty() || head == nullptr)
            return -1;
        Node* temp = head;
        int index = 0;
        while (temp != nullptr) {
            if (match(temp, substr)){
                subIndex = index;
                return subIndex;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    bool match(Node* start, string substr) {
        Node* temp = start;
        int i = 0;
        while (temp != nullptr && i < substr.size()) {
            if (temp->value != substr[i])
                return false;
            temp = temp->next;
            i++;
        }
        return i == substr.size();
    }

    void replace(string s1 , string s2 , int index){
        Node* firstTemp = head;
        Node* secondTemp = head->next;
        int counter = index;
        for (int i = 0; i < index; ++i) {
            firstTemp=firstTemp->next;
            secondTemp=secondTemp->next;
        }
        for (int i = 0; i < s2.size(); ++i) {
            if(firstTemp != nullptr && firstTemp->value == s1[i]){
                firstTemp->value = s2[i];
                firstTemp=firstTemp->next;
                counter++;
            }else{
                insertAt(s2[i],counter-1);
                counter++;
            }
        }


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
    bool flag = false;
    cout<<"Choose a character by index to remove:";
    cin>>index;
    list1.deleteByIndex(index);
    cout<<"List after remove: ";
    list1.printForward();
    while(!flag){
        cout<<"Enter index and length to get substring:";
        cin>>index>>length;
        flag = list1.substring(index,length);
    }
    flag = false;
    while (!flag){
        if(subIndex == -1){
            string s;
            cout<<"Search for a string in the list:";
            cin>>s;
            int result = list1.Search(s);
            cout<<"Found at index "<<result<<endl;
        }else{
            flag = true;
        }
        if(subIndex == -1){
            cout<<"There is no match strings"<<endl;
        }
    }
    flag = false;
    while(!flag){
        string str1 , str2;
        cout<<"Enter 2 substrings to replace one with another:";
        cin>>str1>>str2;
        int result = list1.Search(str1);
        if(result == -1){
            cout<<"Please enter valid substring to replace"<<endl;
        }else{
            list1.replace(str1,str2,result);
            flag = true;
        }
    }
    cout<<"List after replace:";
    list1.printForward();
    cout<<"Reversed List: ";
    list1.printReverse();
    return 0;
}
