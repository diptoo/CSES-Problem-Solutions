#include<iostream>
using namespace std;

int main()
{
    int n = 2;
    int arr[n][n];
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 3;
    arr[2][1]= 4; 
    //arr[3][1] = 5;
    cout<<arr[2][0]<<endl;
}