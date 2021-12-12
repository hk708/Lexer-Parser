/*
Group No: 54
Group Members:
1)Anurag Sidharth Aribandi 2018A71218H
2)Varun Narayanan 2018A7PS1226H
3)Himnish Kapoor 2018A7PS1215H
4)Anish Sai Mitta 2018A71221H
 
   */

#include <bits/stdc++.h>
#include "lexer.h"
//#include "lexer.cpp"
using namespace std;
int left1,right1,ln;
int count_tok;
int main(int argc, char *argv[])
{
        string tp;
        fstream newfile,newfile1;
        newfile1.open(argv[2],ios::out);
        newfile.open(argv[1],ios::in);
        if (newfile.is_open()){
                while(getline(newfile, tp)){
                        
                        left1 =0,right1=0;
                        ln++;
                        do
                        {
                                lex_tok* lex_tok=getNextToken(tp);
                                if(lex_tok==NULL)
                                {
                                        break;
                                }
                                else
                                {
                                        if(lex_tok->tok=="INVALID ERROR")
                                        {
                                                newfile1<<"Invalid Lexeme : "<<" ; Lexeme : "<<lex_tok->lex<<" ; Line no. "<<ln<<'\n';
                                        }
                                        else
                                        {
                                                newfile1<<"Lexeme : "<<lex_tok->lex<<" ; Token :["<<lex_tok->tok<<"]; Line no. "<<ln<<'\n';
                                        }
                                }
                        }while(left1<tp.length());
                }
        }
        newfile.close();
        newfile1.close();
        return 0;
}
