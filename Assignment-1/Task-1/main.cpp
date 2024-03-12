#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
void printArray(vector<int> v , int n){
    for (int i = 0; i < n; ++i) {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}
void linerInsertionSort(vector<int> &v, int size, int &comparison, int &shift);
void binaryInsertionSort(vector<int> &v, int size, int &comparison, int &shift);
int main() {
    int t;
    cout<<"Number of test cases:";
    cin>>t;
    while (t--){
        int size , comparison = 0 , shift = 0;
        vector<int> v;
        cout<<"enter size of the array:";
        cin>>size;
        cout<<"enter array items:";
        for (int i = 0; i < size; ++i) {
            int x;
            cin>>x;
            v.push_back(x);
        }
        vector<int> linerTmp=v , binaryTmp=v;
        linerInsertionSort(linerTmp, size, comparison,shift);
        cout<<"liner Insertion sort: ";
        printArray(v , size);
        cout<<"Comparisons:"<<comparison<<endl;
        cout<<"Shifts:"<<shift<<endl;
        cout<<endl;
        comparison = 0 , shift = 0;
        binaryInsertionSort(binaryTmp, size, comparison, shift);
        cout<<"Binary Insertion sort: ";
        printArray(v , size);
        cout<<"Comparisons:"<<comparison<<endl;
        cout<<"Shifts:"<<shift<<endl;
    }
    return 0;
}
