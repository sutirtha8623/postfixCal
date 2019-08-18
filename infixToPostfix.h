#include<iostream>
#include<string>
#include<vector>
#include"tokenizer.h"
#include"lexer.h"
using namespace std;

int precedence(string s);

string associativity(string s);

vector<Token> to_postfix(string s);

