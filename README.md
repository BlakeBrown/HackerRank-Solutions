/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long int n,x,y,i,a[n],c=0;
    cin>>n>>x>>y;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]>=x&&a[i]<=y)
        ++c;
    }
    if(c==n)
    cout<<"YES";
    if(c<n)
    cout<<"NO";
return 0;
}
    
    
