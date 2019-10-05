#include<iostream>
#include<string>
#include<stdlib.h>
#include"postfix_eval.h"
using namespace std;

int main()
{
	string s;
    while(true)
    {
    	cout<<"->";
    	getline(cin, s);
    	if(s!="exit" || s!="quit")
    	{
    		cout<<"->"<<eval_postfix(s)<<endl;
    	}
    	else
    		exit(0);
    }
}
