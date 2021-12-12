/*
Group No: 54
Group Members:
1)Anurag Siddharth Aribandi 2018A7PS1218H
2)Varun Narayanan 2018A7PS1226H
3)Himnish Kapoor  2018A7PS1215H
4)Anish Sai Mitta 2018A71221H
   */

#include<bits/stdc++.h>
using namespace std;

typedef struct LexerTokenPair
{
	string lex="";
	string tok="";
	int lineno;
	int tokenno;
	
}lex_tok;

extern int left1,right1,ln;
extern int count_tok;
lex_tok* getNextToken(string l);




