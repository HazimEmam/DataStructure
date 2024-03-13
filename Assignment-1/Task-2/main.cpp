#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
template <typename T>
void printArray(deque<T> dq, int n)
{
    for (int i=0; i < n; i++)
        cout << dq[i] << " ";
}
void printArray(vector<int> v , int n){
    for (int i = 0; i < n; ++i) {
        cout<<v[i]<<' ';
    }
    cout<<endl;
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
            ++comparison;
            for( ;j >= gap && temp < dq[j - gap]; j-=gap){ // 3  4
                ++comparison;
                dq[j] = dq[j- gap];
                move++;

            }
            dq[j] = temp;

        }
    }
}
void merge(deque<int> &arr ,int l , int mid , int r){
    int i,j,k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int leftArr[n1] , rightArr[n2];
    //copy items of array to the sub-arrays
    for (int m = 0; m < n1; ++m) {
        leftArr[m] = arr[ l + m];
    }
    for (int m = 0; m < n2; ++m) {
        rightArr[m] = arr[mid+1+m];
    }

    i=0 , j=0, k=l;

    for (;i<n1&&j<n2;k++) {
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }
    }
    for (;i<n1;k++) {
        arr[k] = leftArr[i];
        i++;
    }
    for (;j<n2;k++) {
        arr[k] = rightArr[j];
        j++;
    }
}
void mergeSort(deque<int> &arr, int l , int r){
    if (l < r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr, mid+1,r);
        merge(arr , l , mid , r);
    }
}
void selectionSort(deque<int> &arr , int size , int &comparison , int &move){
    for (int i = 0, j, min; i < size-1; ++i) {
        for (j = i+1 , min = i; j < size; ++j) {
            ++comparison;
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        swap(arr[i],arr[min]);
        move+=3;

    }
}
void linerInsertionSort(vector<int> &v, int size, int &comparison, int &shift);
void binaryInsertionSort(vector<int> &v, int size, int &comparison, int &shift);
int main() {
    string s;
    do{
        cout<<"Please select option:"<<endl;
        cout<<"1.Task_1:Insertion sort and Binary Search"<<endl;
        cout<<"2.Task_2:Selection, Shell, and Merge Sort"<<endl;
        cout<<"3.Exit"<<endl;
        cin>>s;
        if(s=="1"){
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
                //linerInsertionSort(linerTmp, size, comparison,shift);
                cout<<"liner Insertion sort: ";
                printArray(v , size);
                cout<<"Comparisons:"<<comparison<<endl;
                cout<<"Shifts:"<<shift<<endl;
                cout<<endl;
                comparison = 0 , shift = 0;
                //binaryInsertionSort(binaryTmp, size, comparison, shift);
                cout<<"Binary Insertion sort: ";
                printArray(v , size);
                cout<<"Comparisons:"<<comparison<<endl;
                cout<<"Shifts:"<<shift<<endl;
            }
        }else if(s == "2"){
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
                    /*-----------------merge sort------------*/
                    comparison = 0 , move = 0;
                    mergeSort(mergeTmp , 0 , size - 1);
                    cout<<"merge Sort:"<<endl;
                    cout<<" Sorted Array: ";
                    printArray(mergeTmp,size);
                    cout<<endl;
                    cout<<" Comparisons: "<<comparison<<endl;
                    cout<<" Moves: "<<move<<endl;
                    /*-----------------selection sort------------*/
                    comparison = 0 , move = 0;
                    selectionSort(selectionTmp , size , comparison, move);
                    cout<<"selection Sort:"<<endl;
                    cout<<" Sorted Array: ";
                    printArray(selectionTmp,size);
                    cout<<endl;
                    cout<<" Comparisons: "<<comparison<<endl;
                    cout<<" Moves: "<<move<<endl;
                    cout<<endl;
                }
                myFile.close();
            }
        }else{
            cout<<"Please enter valid number."<<endl;
        }
    } while (s != "3");


    return 0;
}
