
int main()
{
    string N_temp;
    getline(cin, N_temp);

    int n = stoi(ltrim(rtrim(N_temp)));
    
    if(n & 1) cout<<"Weird"<<endl;
    else 
    {
        if(n>=2 && n<=5) cout<<"Not Weird"<<endl;
        else if(n>=6 && n<=20) cout<<"Weird"<<endl;
        else if(n>20) cout<<"Not Weird"<<endl;
    }

    return 0;
}
