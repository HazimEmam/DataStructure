#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

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
    void display(){
        Node* temp = head;
        while (temp != NULL){
            cout<<"Name: "<<temp->student.getName()<<", ID: "<<temp->student.getID()<<", GPA: "<<temp->student.getGPA()<<endl;
            temp = temp->next;
        }
        cout<<endl;
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
        Node* temp = head;
        Node* prev= NULL;
        if(!search(id)){
            cout<<"Sorry, There is no student with this ID in the list";
        }else{
            //1-head
            if(head->student.getID() == id){
                head=head->next;
                delete temp;
            }
            //2-mid
            //3-tail
        }
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
    Student s1("hazim",15,2.5);
    Student s2("emam",16,2.5);
    Student s3("mohamed",17,2.5);
    Student s4("ali",18,2.5);
    StudentList list;
    list.insert(s1);
    list.insert(s2);
    list.insert(s3);
    list.insert(s4);
    list.display();
    list.Delete(15);
   // list.display();
//    list.Delete(17);
    list.display();
    list.display();
    return 0;
}
