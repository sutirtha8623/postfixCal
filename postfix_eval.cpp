
#include"postfix_eval.h"

double eval_postfix(string s)
{
    vector<Token> v = to_postfix(s);
    vector<double> result;
    
    for(lsi i=0; i<v.size(); i++)
    {
        if(v[i].type=="number")
        {
        	int size = v[i].val.length()+1;
        	char c[size+1];
        	v[i].val.copy(c, size+1);
            result.push_back(atof(c));
        }
        else if(v[i].type=="operator")
        {
            double op2 = result.back();
            result.pop_back();
            double op1 = result.back();
            result.pop_back();
            if(v[i].val=="^")
            {
                double x = pow(op1, op2);
                result.push_back(x);
            }
            else if(v[i].val=="/")
            {
                double x = op1/op2;
                result.push_back(x);
            }
            else if(v[i].val=="*")
            {
                double x = op1*op2;
                result.push_back(x);
            }
            else if(v[i].val=="+")
            {
                double x = op1+op2;
                result.push_back(x);
            }
            else if(v[i].val=="-")
            {
                double x = op1-op2;
                result.push_back(x);
            }
        }
        else
        {
            
            if(v[i].val=="max")
            {
                double op2 = result.back();
                result.pop_back();
                double op1 = result.back();
                result.pop_back();
                double x = fmax(op2, op1);
                result.push_back(x);
            }
            else if(v[i].val=="sin")
            {
                double op = result.back();
                result.pop_back();
                double x = sin(op);
                result.push_back(x);
            }
            else if(v[i].val=="cos")
            {
                double op = result.back();
                result.pop_back();
                double x = cos(op);
                result.push_back(x);
            }
            else if(v[i].val=="tan")
            {
                double op = result.back();
                result.pop_back();
                double x = tan(op);
                result.push_back(x);
            }
        }
    }
    return result.back();
}
