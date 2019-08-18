

#include<iostream>
#include<vector>
#include<string>
typedef long unsigned int lsi; 
using namespace std;

#ifndef _TOKEN_H
#define _TOKEN_H
class Token{
public:
    string type;
    string val;
};
#endif

bool is_number(char c);
bool is_letter(char c);
bool is_operator(char c);
bool is_leftpar(char c);
bool is_rightpar(char c);
bool is_comma(char c);

vector<Token> tokenize(string s);
