#include<iostream>
using namespace std;


int findHCF(int a , int b){
    if(a == 0 ) return b;
    if(b == 0) return a;

    while( a > 0 && b > 0){

        if(a > b){
            a = a-b;
        }
        else{
            b = b-a;
        }

    }

    return a == 0 ? b:a;



}


int main(){
    cout<<"enter to number a and b to find hcf ";
    int a , b;
    cin>>a>>b;

    int hcf = findHCF(a , b);

    cout<<"HCF of "<<a<<" and " <<b<<" is "<<hcf<<endl;
}