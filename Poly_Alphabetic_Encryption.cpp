#include<bits/stdc++.h>
using namespace std;

int main(){

    int i,j,k,p,s,x,y;
    string st,st2;

    cout<< "Enter Your PlainText: ";
    cin>>st;
    cout<< "Enter Your KeyText: ";
    cin>>st2;

    x=st.size();
    y=st2.size();

    i=0;
    while(y<x){
        st2=st2 + st2[i];
        i++;
        y++;
    }

    cout<<st2<<endl;

    for(i=0;i<st.size();i++){

        st[i]= ( (st[i]-97)+(st2[i]-97) )%26+97;
    }

    cout<< "CipherText = "<<st<<endl;
}

