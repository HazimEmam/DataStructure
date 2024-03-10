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
template <typename T>
void merge(deque<T> &dq , int l ,int mid, int r){
    // i -> left sub-array
    // j -> right sub-array
    // k -> tmp array
    int i = mid - l + 1 , k=l , j = r - mid;
    vector<T> v;
    for(;i <= mid && j <= r; k++){
        if(dq[i] <= dq[j]){
            v[k] = dq[i];
            i++;
        }else{
            v[k] = dq[j];
            j++;
        }
    }
    for (;i<=mid;k++ , i++) {
        v[k] = dq[i];
    }
    for (;j<=r;k++ , j++) {
        v[k] = dq[j];
    }

    for (int m = l; m <= r ; ++m) {
        dq[m] = v[m];
    }
}
template <typename T>
void mergeSort(deque<T> &dq , int l , int r){
    if (l < r ) {
        int mid = l + ((r - l) / 2);
        mergeSort(dq, l, mid);
        mergeSort(dq, mid + 1, r);
        merge(dq, l, mid, r);
    }
    return;
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
            cout<<endl;
            cout<<" Comparisons: "<<comparison<<endl;
            cout<<" Moves: "<<move<<endl;
            cout<<endl;
            /*-----------------merge sort------------*/
            comparison = 0 , move = 0;
            mergeSort(mergeTmp , 0 , size);
            cout<<"merge Sort:"<<endl;
            cout<<" Sorted Array: ";
            printArray(mergeTmp,size);
            cout<<" Comparisons: "<<comparison<<endl;
            cout<<" Moves: "<<move<<endl;
            cout<<endl;
        }
        myFile.close();
    }
    return 0;
}
