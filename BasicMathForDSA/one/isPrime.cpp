#include<iostream>
#include<math.h>
using namespace std;

bool checkPrime(int n){
    if (n <= 2){
        return true;
    }
    for(int i = 2 ; i< sqrt(n); i++){
        if(n%i == 0 ) {
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"enter a number to check prime or composite: ";
    cin>>n;

    if(checkPrime(n)){
        cout<<n<<" is a Prime number"<<endl;
    }
    else{
        cout<<n<<" is a composite number"<<endl;
    }

}
