#include<bits/stdc++.h>
using namespace std;

int main(){

    int i,j,k,p,s;
    string st;

    cout<< "Enter Your PlainText: ";
    cin>>st;

    int q=23,a=9,ys,yr=3,xs;

    xs=4;

    ys=(pow(a,xs));
    ys=ys%q;

    k=(pow(yr,xs));
    k=k%q;

    //cout<<k<<endl;


    for(i=0;i<st.size();i++){

        if(st[i]>='A' && st[i]<='Z') st[i]= ((( st[i]-65 )+k)%26)+65;
        else st[i]= ((( st[i]-97 ) +k)%26)+97;
    }

    cout<< "CipherText = "<<st<<endl;
}

