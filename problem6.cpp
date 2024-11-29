#include <bits/stdc++.h>
using namespace std;

int digit = 0;

bool CharVariable (string token )
{
    if(!(token[0] == 'c' && token[1] == 'h' and token[2] == '_'))
    return false;

    for ( int i = 3; i < token.size(); i++)
    {
        if(!isalnum(token[i]))
        return false;
    }
    return true;
}


bool binVariable (string token )
{
    if(!(token[0] == 'b' && token[1] == 'n' and token[2] == '_'))
    return false;

    for ( int i = 3; i < token.size(); i++)
    {
        if(!isalnum(token[i]))
        return false;
    }
    return true;
}


bool BinNumber(string token)
{
    if(token[0] != '0')
    return false;

    for (char c: token)
    {
        if(!(c == '0' or c == '1'))
        return false;
    }

    if(token.size()<2)
    return false;
    
    return true;
}

    
int main()
{
    freopen("problem4.txt", "r", stdin);
    string s;
    while(getline(cin, s))
    {
        cout << s << "\t";

        if(CharVariable(s))
        cout << "Character Variable" << endl;

        else if(binVariable(s))
        {
            cout<<"binary Variable"<<endl;

        }
        else if(BinNumber(s))
        {
            cout<<"binary Number"<<endl;

        }
        else 
        cout<<"invalid"<<endl;
    }
}
