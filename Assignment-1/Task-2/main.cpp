#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
template <typename T>
void printArray(deque<T> dq, int n)
{
    for (int i=0; i < n; i++)
        cout << dq[i] << " ";
}

deque<int> string_to_vector(string &s){
    deque<int> v;
    stringstream ss(s);
    int num;
    while(ss >> num){
        v.push_back(num);
    }
    return v;
}

template <typename T>
void shellSort(deque<T> &dq , int size , int &comparison , int &move){
    for(int gap = size/2 ; gap > 0 ; gap/=2){
        for (int i = gap ; i < size ; ++i) {
            T temp = dq[i];
            int j = i;
            for( ;j >= gap && temp < dq[j - gap]; j-=gap){ // 3  4
                comparison++;
                dq[j] = dq[j- gap];
                move++;

            }
            dq[j] = temp;
            move++;
        }
    }
}
int main() {
    fstream myFile;
    myFile.open("arrays.txt",ios::in);
    if(myFile.is_open()){
        string line;
        deque<int> v;
        deque<int> shellTmp;
        deque<int> selectionTmp;
        deque<int> mergeTmp;
        while(getline(myFile,line)){
            v = string_to_vector(line);
            int size = v[0];
            v.pop_front();
            shellTmp = v , selectionTmp = v , mergeTmp = v;
            int comparison = 0 , move = 0;
            //cout<<comparison<<' '<< move << endl;
            /*-----------------Shell sort------------*/
            cout<<"Original array: ";
            printArray(v , size);
            cout<<endl;
            shellSort(shellTmp, size,comparison,move);
            cout<<"Shell Sort:"<<endl;
            cout<<" Sorted Array: ";
            printArray(shellTmp,size);
            cout<<" Comparisons: "<<comparison<<endl;
            cout<<" Moves: "<<move<<endl;
            cout<<endl;
            /*-----------------merge sort------------*/
        }
        myFile.close();
    }
    return 0;
}
