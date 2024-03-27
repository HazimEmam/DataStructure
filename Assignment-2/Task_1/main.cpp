#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
int subIndex = -1;
class DoubleNode{
public:
    char value;
    DoubleNode* next;
    DoubleNode* previous;
};

class DoubleList{
public:
    DoubleNode* head;
    DoubleNode* tail;
    DoubleList(){
        head = tail = nullptr;
    }
    void insert(char c){
        DoubleNode* newDoubleNode = new DoubleNode();
        newDoubleNode->value=c;
        if(head == nullptr){
            head = tail = newDoubleNode;
            newDoubleNode->next = newDoubleNode->previous = nullptr;
        }else{
            newDoubleNode->next = nullptr;
            newDoubleNode->previous = tail;
            tail->next = newDoubleNode;
            tail = newDoubleNode;
        }
    }
    void insertAt(char c, int index){
        DoubleNode* temp = head;
        DoubleNode* after= nullptr;
        DoubleNode* newDoubleNode = new DoubleNode();
        if(index == size()-1){
            insert(c);
            return;
        }
        for (int i = 0; i < index; ++i) {
            temp=temp->next;
        }
        after = temp->next;
        newDoubleNode->value=c;
        temp->next = newDoubleNode;
        newDoubleNode->previous = temp;
        newDoubleNode->next=after;
        after->previous=newDoubleNode;
    }
    void concatenat(DoubleList list2){
        if(list2.head == nullptr){
            return;
        }
        DoubleNode* temp = list2.head;
        temp->previous = tail;
        tail->next = temp;
        list2.head= nullptr;
        tail = list2.tail;
    }
    int size(){
        DoubleNode* temp = head;
        int i = 0;
        while(temp != nullptr){
            temp =temp->next;
            i++;
        }
        return i;
    }
    void deleteFirst(){
        DoubleNode* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteLast(){
        DoubleNode* temp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete temp;
    }
    void deleteByIndex(int index){
        DoubleNode* delDoubleNode = head;
        DoubleNode* before = nullptr;
        if(index == 0){
            deleteFirst();
            return;
        }
        if(index == size()-1){
            deleteLast();
            return;
        }
        for (int i = 0; i < index; ++i) {
            before = delDoubleNode;
            delDoubleNode=delDoubleNode->next;
        }
        delDoubleNode->previous->next= delDoubleNode->next;
        delDoubleNode->next->previous = delDoubleNode->previous;
        delete delDoubleNode;
    }
    bool substring (int index , int length){
        DoubleNode* temp = head;
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
        DoubleNode* temp = head;
        while(temp != nullptr){
            cout<<temp->value;
            temp=temp->next;
        }
        cout<<endl;
    }

    int Search(string substr) {
        if (substr.empty() || head == nullptr)
            return -1;
        DoubleNode* temp = head;
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

    bool match(DoubleNode* start, string substr) {
        DoubleNode* temp = start;
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
        DoubleNode* firstTemp = head;
        DoubleNode* secondTemp = head->next;
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
        DoubleNode* temp = tail;
        while(temp != nullptr){
            cout<<temp->value;
            temp=temp->previous;
        }
        cout<<endl;
    }


};

class Student{
private:
    string name;
    int id;
    float gpa;
public:
    Student(){
        name="";
        id=0;
        gpa=0.0;
    }
    Student(string _name,int _id,float _gpa){
        name=_name;
        id=_id;
        gpa=_gpa;
    }
    string getName(){return name;}
    int getID(){return id;}
    float getGPA(){return gpa;}
};

class Node{
public:
    Student student;
    Node* next;
};

class StudentList{
public:
    Node* head;
    Node* tail;
    StudentList(){
        head = tail = NULL;
    }

    void insert(Student _student){
        Node* newNode = new Node();
        newNode->student=_student;
        if(head==NULL){
            newNode->next=NULL;
            head=newNode;
            tail=newNode;
        }else{
            Node* temp = head;
            Node* position = temp;
            if(temp->student.getID() >= newNode->student.getID()){
                newNode->next=head;
                head=newNode;
                return;
            }
            while(temp != NULL){
                if(temp->student.getID() < newNode->student.getID()){
                    position = temp;
                    temp=temp->next;
                }else{
                    newNode->next = temp;
                    position->next=newNode;
                    temp=NULL;
                }
            }
            if(tail == position){
                position->next = newNode;
                tail=newNode;
                newNode->next=NULL;
            }
        }
    }

    int size(){
        Node* temp = head;
        int count=0;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    bool search(int id){
        Node* temp = head;
        if(head==NULL) {
            cout << "Sorry, There is no items in the list"<<endl;
            return false;
        }else{
            while(temp != NULL){
                if(temp->student.getID() == id){
                    cout<<"Name: "<<temp->student.getName()<<", ID: "<<temp->student.getID()<<", GPA: "<<temp->student.getGPA()<<endl;
                    return true;
                }else{
                    temp=temp->next;
                }
            }
            cout<<"Sorry, There is no student with this ID in the list"<<endl;
        }
    }
    bool search(string name){
        Node* temp = head;
        if(head==NULL) {
            cout << "Sorry, There is no items in the list"<<endl;
            return false;
        }else{
            while(temp != NULL){
                if(temp->student.getName() == name){
                    cout<<"Name: "<<temp->student.getName()<<", ID: "<<temp->student.getID()<<", GPA: "<<temp->student.getGPA()<<endl;
                    return true;
                }else{
                    temp=temp->next;
                }
            }
            cout<<"Sorry, There is no student with this Name in the list"<<endl;
            return false;
        }
    }
    void Delete(int id){
        Node* deltemp = head;
        Node* prev= NULL;

        while(deltemp != NULL && deltemp->student.getID() != id){
            prev=deltemp;
            deltemp=deltemp->next;
        }
        if(deltemp== nullptr){
            cout<<"Sorry, There is no student with this ID in the list"<<endl;
        }else{
            if(prev == NULL){
                head=head->next;
            }else{
                prev->next=deltemp->next;
            }
            if(deltemp == tail){
                tail=prev;
            }
            delete deltemp;
            cout<<"the student with id "<<id<<" deleted"<<endl;
        }

    }
    void display(){
        Node* temp = head;
        while (temp != NULL){
            cout<<"Name: "<<temp->student.getName()<<", ID: "<<temp->student.getID()<<", GPA: "<<temp->student.getGPA()<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
    ~StudentList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = NULL;
    }
};
int main() {
    cout<<"1.Task_1:Sorted linked list"<<endl;
    cout<<"2.Task_2:String Manipulation using Doubly Linked List"<<endl;
    cout<<"Enter Your option:";
    int t; cin>>t;
    switch(t){
        case 1:{
            Student s1("hazim",15,2.5);
            Student s2("emam",16,2.5);
            Student s3("mohamed",17,2.5);
            Student s4("ali",18,2.5);
            StudentList list;
            list.insert(s1);
            list.insert(s2);
            list.insert(s3);
            list.insert(s4);
            list.Delete(11);
            list.display();
            list.Delete(15);
            list.display();
            list.Delete(17);
            list.display();
            list.Delete(18);
            list.display();
            list.insert(s1);
            list.insert(s3);
            list.insert(s4);
            list.display();
            break;
        }
        case 2:{
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
            while(!flag){
                cout<<"Choose a character by index to remove:";
                cin>>index;
                if(index <= list1.size()-1){
                    list1.deleteByIndex(index);
                    cout<<"List after remove: ";
                    list1.printForward();
                    flag = true;
                }else{
                    cout<<"Please enter valid index"<<endl;
                }
            }
            flag = false;
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
            break;
            }
            default:{
                cout<<"please enter valid option";
            break;
            }
    }

    return 0;
}
