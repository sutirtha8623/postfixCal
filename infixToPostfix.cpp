#include"infixToPostfix.h"

//stack class is not used as vector satisfies all requirements
//functions should be written as (func(arg)) rather than func(arg)

int precedence(string s)
{
    if(s=="^"){return 4;}
    else if(s=="/" || s=="*"){return 3;}
    else if(s=="+" || s=="-"){return 2;}
    else
        return -1;
}

string associativity(string s)
{
    string res = (s=="^") ? "right" : "left";
    return res;
}

vector<Token> to_postfix(string s)
{
    vector<Token> v = lex(s);
    vector<Token> output;
    vector<Token> op_stack;
    Token* x = new Token;
    x->type = "null";
    x->val = "null";
    op_stack.push_back(*x);
    
    for(lsi i=0; i<v.size(); i++)
    {
        if(v[i].type=="number")
        {
            output.push_back(v[i]);
        }
        else if(v[i].type=="letter")
        {
            op_stack.push_back(v[i]);
        }
        else if(v[i].type=="leftpar")
        {
            op_stack.push_back(v[i]);
        }
        else if(v[i].type=="rightpar")
        {
            while(op_stack.back().type!="null" && op_stack.back().type!="leftpar")
            {
                Token x = op_stack.back();
                op_stack.pop_back();
                output.push_back(x);
            }
            if(op_stack.back().type=="leftpar")
            {
                Token x = op_stack.back();
                op_stack.pop_back();
            }
        }
        else if(v[i].type=="comma")
        {
            continue;
        }
        else
        {
            while(op_stack.back().type!="null" && precedence(op_stack.back().val)>=precedence(v[i].val) && associativity(v[i].val)=="left")
            {
                Token x = op_stack.back();
                op_stack.pop_back();
                output.push_back(x);
            }
            op_stack.push_back(v[i]);
        }
        
    }
    while(op_stack.back().type!="null")
    {
        Token x = op_stack.back();
        op_stack.pop_back();
        output.push_back(x);
    }
    return output;
}

