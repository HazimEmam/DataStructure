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
            cout<<temp->student.getName()<<' '<<temp->student.getID()<<' '<<temp->student.getGPA()<<endl;
            temp = temp->next;
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
};
int main() {
    Student s1("hazim",15,2.5);
    Student s3("mohamed",17,2.5);
    StudentList list;
    list.insert(s1);
    list.insert(s3);
    list.display();
    cout<<list.size()<<endl;
    Student s2("emam",16,2.5);
    list.insert(s2);
    list.display();
    cout<<list.size()<<endl;
    Student s4("ali",18,2.5);
    list.insert(s4);
    list.display();
    cout<<list.size()<<endl;
    Student s5("ali",14,2.5);
    list.insert(s5);
    list.display();
    cout<<list.size()<<endl;
    return 0;
}
