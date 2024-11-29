#include<bits/stdc++.h>
using namespace std;

vector<string>ProperNoun={"Sagor", "Selim", "Salma", "Nipu"};
vector<string>ProNoun={"he", "she", "I", "we", "you", "they"};
vector<string>Verb={"read", "eat", "take", "run", "write"};
vector<string>Noun = {"book", "cow", "dog", "home", "grass", "rice", "mango"};

bool Valid_Sub(string sub)
{
    for(string element : ProperNoun)
    {
        if(element==sub) 
        return true;
    }
    for(string element : ProNoun)
    {
        if(element==sub) 
        return true;
    }
    return false;
}

bool ValidPredicate1(string pre)
{
    for(string element : Verb)
    {
        if(element==pre) 
        return true;
    }
    return false;
}

bool ValidPredicate2(string preV, string preN)
{
    bool half1=false;
    bool half2=false;
    for(string element : Verb)
    {
        if(element==preV) 
        half1=true;
    }
    for(string element : Noun)
    {
        if(element==preN) 
        half2=true;
    }
     return half1 && half2;
}
int main()
{
    freopen("problem4.txt", "r", stdin);
    string sentance;
    while(getline(cin, sentance))
{



    cout << sentance<<"\t";

    stringstream ss(sentance);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }
    int x = words.size();
    cout << x << "\t " ;
    if(x==2)
    {
        if(Valid_Sub(words[0]) and ValidPredicate1 (words[1]))
        cout<<"Success";
        else
        cout<<"Invalid";
    }
    else if(x==3)
    {
        if(Valid_Sub(words[0]) and ValidPredicate2 (words[1],words[2]))
        cout<<"Success"<<endl;
        else
        cout<<"Invalid"<<endl;
    }
    else
    cout<<"Invalid"<<endl;
}

}
