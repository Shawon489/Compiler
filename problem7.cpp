#include<bits/stdc++.h>

using namespace std;


vector<string> keywords={"int", "float", "double", "main", "string", "if", "else", "while", "elseif", "for", "goto"};

vector<string> operators={"+", "-", "*", "/", "!=", "==", ">=", "<="};

bool is_float(string token)
{
    int dotcnt = 0;
    for(int i=0; i<=token.size(); i++)
    {
       if(token[i] == '.')
       dotcnt++;
       else if (!isdigit(token[i]))
       return false;
    }
    if(dotcnt !=1)
    return false;

    if(token[0]=='.')
    return false;

  return true;
}
bool is_int(string token)
{
    for(int i=0; i<=token.size(); i++)
    {
       if (!isdigit(token[i]))
       return false;
    }
    return true;

}

bool is_keyword(string token)
{
    for(string keyword : keywords)
    {
        if(keyword==token)
        return true;
    }
    return false;
}

bool is_operator(string token)
{
     for(string keyword : operators)
    {
        if(keyword==token)
        return true;
    }
    return false  ;
}

 bool is_identifier(string token)
 {
    for(char c : token)
    {
        if(!(isalnum(c) or c=='_'))
        return false;
    }

    if(isdigit(token[0]))
    return false;


    return true;
 }
main()
{
    freopen("problem4.txt", "r", stdin);
    string s;
    while(getline(cin, s))
    {
        cout << s <<"\t" ;

        if(is_keyword(s))
        cout<<"keyword"<<endl;

        else if(is_operator(s))
        {
            cout<<"is_operator"<<endl;   
        }
        else if(is_identifier(s))
        {
            cout<<"identifier"<<endl;   
        }

        else if(is_float(s))
        {
            cout<<"is_float"<<endl;   
        }

        else if( is_int(s))
        {
            cout<<"int"<<endl;   
        }
        
        else
        cout<<"internal problem"<<endl;
    }
}

