#include<iostream>
#include<math.h>
using namespace std;

bool checkPrime(int n){
    if (n <= 2){
        return true;
    }
    for(int i = 2 ; i<= sqrt(n); i++){
        if(n%i == 0 ) {
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"enter a number to check total prime between N: ";
    cin>>n;

    int count = 0 ;
    for (int i = 1 ; i<n ; i++) {
     if(checkPrime(i)){
       count++;
    }
   }


cout<<"total prime between 0 to " <<n<<" is : "<<count<<endl;
   
}
