#include<bits/stdc++.h>
using namespace std;
vector<string>ProperNoun={"Sagor", "Selim", "Salma", "Nipu"};
vector<string>ProNoun={"he", "she", "I", "we", "you", "they"};
vector<string>Verb={"read", "eat", "take", "run", "write"};
vector<string>Noun = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
bool validsub(string s)
{
    for(auto properN:ProperNoun)
    {
        if(s==properN)
        {
            cout<<"proper noun: "<<"\t";
            return true;
        }
    }
    for(auto proN:ProNoun)
    {
        if(s==proN)
        {
            cout<<"pro noun: "<<"\t";
            return true;
        }
    }
    return false;
}
bool validV(string s)
{
    for(auto v:Verb)
    {
        if(s==v)
        return true;
    }
    return false;
}
bool validN(string s)
{
    for(auto n:Noun)
    {
        if(n==s)
        return true;
    }
    return false;
}
main()
{
    string sentance;
    freopen("problem4.txt", "r", stdin);
    while(getline(cin, sentance))
    {
        stringstream ss(sentance);
        vector<string>words;
        string word;

        while(ss >> word)
        {
            words.push_back(word);
        }

        cout<<"Sentance: "<<sentance<<"\t";

        if(words.size()==2)
        {
            if( validsub(words[0]) and validV (words[1]))
            cout << "valid" <<endl;
            else 
            cout<<"invalid" <<endl;
        }
        else if(words.size()==3)
        {
            if(validsub(words[0]) && validV(words[1]) && validN(words[2]))
            cout << "valid"<<endl;
            else 
            cout<<"invalid" <<endl;
        }
        

    }
}
