#include<iostream>
#include<string>
#include"postfix_eval.h"
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    cout<<eval_postfix(s)<<endl;
}
