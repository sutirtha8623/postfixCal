#include"tokenizer.h"


bool is_number(char c)
{
    return ((c>='0'&& c<='9')||(c=='.'));
}

bool is_letter(char c)
{
    return (c>='a'&& c<='z');
}

bool is_operator(char c)
{
    return (c=='/'||c=='*'||c=='+'||c=='-'||c=='^');
}

bool is_leftpar(char c)
{
    return (c=='(');
}

bool is_rightpar(char c)
{
    return (c==')');
}

bool is_comma(char c)
{
    return (c==',');
}

vector<Token> tokenize(string s)
{
    vector<Token> v;
    for(lsi i=0; i<s.length(); i++)
    {
        if(is_number(s[i]))
        {
            Token *x= new Token;
            x->type = "number";
            x->val = s[i];
            v.push_back(*x);
        }
        else if(is_letter(s[i]))
        {
            Token *x = new Token;
            x->type = "letter";
            x->val = s[i];
            v.push_back(*x);            
        }
        else if(is_operator(s[i]))
        {
            Token *x = new Token;
            x->type = "operator";
            x->val = s[i];
            v.push_back(*x);
        }
        else if(is_leftpar(s[i]))
        {
            Token *x = new Token;
            x->type = "leftpar";
            x->val = s[i];
            v.push_back(*x);        
        }
        else if(is_rightpar(s[i]))
        {
            Token *x = new Token;
            x->type = "rightpar";
            x->val = s[i];
            v.push_back(*x);            
        }
        else if(is_comma(s[i]))
        {
            Token *x = new Token;
            x->type = "comma";
            x->val = s[i];
            v.push_back(*x);            
        }
        else
            continue;
    }
    return v;
    
}

