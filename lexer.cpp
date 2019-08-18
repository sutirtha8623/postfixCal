#include"lexer.h"

string concatenate(vector<string> v)
{
    string s;
    for(lsi i=0; i<v.size(); i++)
    {
        s+=v[i];
    }
    return s;
}


vector<Token> lex(string s)
{
    vector<string> buffer;
    vector<Token> result;
    vector<Token> v = tokenize(s);
    for(lsi i=0; i<v.size(); i++)
    {
        if(v[i].type=="number"||v[i].type=="letter")
        {
            buffer.push_back(v[i].val);
            if(i==v.size()-1)
            {
                string s = concatenate(buffer);
                Token *x = new Token;
                x->type = v[i].type;
                x->val = s;
                result.push_back(*x);            
            }
        }
        else
        {
            if(!buffer.empty())
            {
                string s = concatenate(buffer);
                Token *x = new Token;
                x->type = v[i-1].type;
                x->val = s;
                result.push_back(*x);
            }
            result.push_back(v[i]);
            buffer.clear();
        }
    }
    return result;
}
