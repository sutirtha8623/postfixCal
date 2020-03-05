#include<iostream>
#include<string>
#include<stdlib.h>
#include"postfix_eval.h"
#include<fstream>
using namespace std;

int main(int argc, char** argv)
{
	string s;
	if(argc==1)
	{
		cout<<"(enter expression/q to quit)\n";
		while(true)
		{
			cout<<"->";
			getline(cin, s);
			if(s!="q")
			{
				cout<<"->"<<eval_postfix(s)<<"\n";
			}
			else
				exit(0);
		}
	}

	else if(argc==2)
	{
		string inp(argv[1]);
		ifstream in_file(inp);
		ofstream out_file("result.txt");
		while(getline(in_file, s))
		{
			out_file<<s<<" = "<<eval_postfix(s)<<"\n";
		}
		cout<<"results have been written in result.txt\n";
	}
	else if(argc == 3)
	{
		string inp(argv[1]);
		string outp(argv[2]);
		ifstream in_file(inp);
		ofstream out_file(outp);
		while(getline(in_file, s))
		{
			out_file<<s<<" = "<<eval_postfix(s)<<"\n";
		}
		cout<<"results have been written in "<<outp<<"\n";
	}

}
