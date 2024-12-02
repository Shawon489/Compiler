#include<bits/stdc++.h>
using namespace std;
vector<string>words;

int pre(char c) 
{
    if (c =='+' || c=='-') return 1;
    if (c =='*' || c=='/') return 2;
}
string postfix(string word)
{
    string postfixString="";
    stack<char>stk;
    for(char c : word)
    {
        if (isalnum(c))
        postfixString += c;

        else if (c == '(')
        stk.push(c);

        else if (c == ')') 
        {
            while(stk.top() !='(')
            {
                postfixString += stk.top();
                stk.pop();
            }
             stk.pop();      
        }
        else
        {
            if (!stk.empty() and (pre(stk.top())>=pre(c)))
            {
                postfixString += c;
                stk.pop();
            }
              stk.push(c);
        }

    }
    if(!stk.empty())
    {
        postfixString +=stk.top();   
        stk.pop();
    }
    return postfixString;

}
int main()
{
    string s;
    getline(cin,s);
    string word;
    string ans="";
    stack <string> stk;
    stringstream ss(s);
    while(ss>>word)
    words.push_back(word);
    for(auto x : words)
    {
        if( x == "if" || x == "else")
        stk.push(x);
        else if( x == "then" )
        continue;
        else
        {
            ans += postfix(x);
           while(!stk.empty() and stk.top() == "else")
           {
            ans += '?';
            stk.pop();
            stk.pop();
            }
        }
        cout << ans <<endl;
    }
}
