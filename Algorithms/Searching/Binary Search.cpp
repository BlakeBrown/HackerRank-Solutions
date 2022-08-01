#include<iostream>


using namespace std;

int binarysearch(int arr[],int left,int right,int x)
{
    int mid;
    while (left<right)
    {

    mid=(left+right)/2;
    if (arr[mid]==x)
        return mid;
    else if(arr[mid]<x)
        left=mid+1;
    else if(arr[mid]>x)
        right=mid-1;


    }
    return -1;
}

int main()
{
    int i,arr[9],output;
    for(i=0;i<9;i++)
    {
        cin>>arr[i];
    }

    output = binarysearch(arr,0,9,20);
    if (output == -1)
        cout<<"Element not found\n";
    else
        cout<<"Element present at location:"<<output;
}
