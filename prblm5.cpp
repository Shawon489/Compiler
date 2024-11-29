#include <bits/stdc++.h>
using namespace std;

bool floatvariable (string token )
{
    if(!(( tolower(token[0])>= 'a' and tolower(token[0])<='h') or (tolower(token[0]) >= 'o' and tolower(token[0])<='z')))
     return false;
     for( int i = 1; i<token.size(); i++ )
     {
        if(isalnum(token[i]) )
        continue;
        else
        return false;
     }
     return true;
}
bool FloatNumber(string token)
{
    int count = 0;
    int CountAfterPoint = 0;

    if((token[0]=='0') and (token[1]=='.'))
    {

        for( int i =2; i<token.size(); i++)
        {
            
            if(isdigit(token[i]))
            CountAfterPoint++;
            else
            return false;
        }

        if(CountAfterPoint==2)
        {
            cout << "FloatNumber"<<endl;
            return true;
        }
        
        else if(CountAfterPoint>=3)
        {
            cout << "DoubleNumber"<<endl;
            return true;
        }
    }
    
    else if (token[0]!='0')
    {
        size_t position = token.find('.');
        if (position == string::npos) return false;

        for(int i = position-1; i>=0; i--)
        {
            if(!isdigit(token[i]))
            return false;
        }

        
            for(int i = position+1; i<token.size(); i++)
            {

            if(isdigit(token[i]))
            count++;
            else
            return false;
            }

        if(count==2)
        {
            cout << "FloatNumber"<<endl;
            return true;
        }

        else if(count>=3)
        {
            cout << "DoubleNumber"<<endl;
            return true;
        }

    }
    else
    return false;
}
    


int main()
{
    freopen("problem4.txt", "r", stdin);
    string s;
    while(getline(cin, s))
    {
        cout << s << "\t";

        if(floatvariable(s))
        cout << "floatvariable" << endl;

        else if(FloatNumber(s))
        {
            cout<<"";
        }
        else 
        cout<<"invalid"<<endl;
    }
    

    
}
