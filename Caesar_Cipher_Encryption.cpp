#include<bits/stdc++.h>
using namespace std;

int main(){

    int i,j,k,p,s;
    string st;

    cout<< "Enter Your PlainText: ";
    cin>>st;
    cout<< "Enter Your Key Value: ";
    cin>>k;

    for(i=0;i<st.size();i++){

        if(st[i]>='A' && st[i]<='Z') st[i]= ((( st[i]-65 )+k)%26)+65;
        else st[i]= ((( st[i]-97 ) +k)%26)+97;
    }

    cout<< "CipherText = "<<st<<endl;
}
