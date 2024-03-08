#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

vector<int> string_to_vector(string &s){
    vector<int> v;
    stringstream ss(s);
    int num;
    while(ss >> num){
        v.push_back(num);
    }
    return v;
}


int main() {
    fstream myFile;
    myFile.open("arrays.txt",ios::in);
    if(myFile.is_open()){
        string line;
        vector<int> v;
        while(getline(myFile,line)){
            v = string_to_vector(line);
            for (int it : v) {
                cout<<it<<' ';
            }
            cout<<endl;
        }
        myFile.close();
    }
    return 0;
}
