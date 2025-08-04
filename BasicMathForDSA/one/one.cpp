
#include<iostream>
using namespace std;

int area(int length , int width)
{
    return length*width;
}

int parameter(int length , int width)
{
    int p;
    p = 2*(length*width);
    return p;
}

int main()
{
    int length=0, width=0;
    cout<<"enter the length and width: ";
    cin>>length>>width;
    int area1=area(length,width);
    int pari = parameter(length,width);

    cout<<"Area is =  "<<area1<<endl<<"And parameter is =  "<<pari<<endl;
    

    return 0;

}