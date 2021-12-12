/*
Group No: 54
Group Members:
1)Anurag Sidharth Aribandi 2018A71218H
2)Varun Narayanan 2018A7PS1226H
3)Himnish Kapoor 2018A7PS1215H
4)Anish Sai Mitta 2018A71221H
 
   */
#include<bits/stdc++.h>
#include "lexer.h"

vector<string> keywords={"int","float","boolean","str","fun","ret","loop","if","else","and","true","false","scan","print","endfun","endif","endloop"};
vector<string> tokens={"INT","FLOAT","BOOLEAN","STR","FUN","RET","LOOP","IF","ELSE","AND","TRUE","FALSE","SCAN","PRINT","ENDFUN","ENDIF","ENDLOOP"};

using namespace std;
int flag1 ,flag2 , flag3 =0 , flag4 =0, flag5 =0;
lex_tok* returnLexeme(char c){        
    lex_tok* my_lex_tok = new lex_tok();
    my_lex_tok->lex = "";
    my_lex_tok->lex.push_back(c);
    return my_lex_tok;
}

lex_tok* returnLexeme2(string l){         
    lex_tok* my_lex_tok = new lex_tok();
    my_lex_tok->lex = "";
    int i=left1;
    for(i=left1;i<right1;i++)
    {
        my_lex_tok->lex.push_back(l[i]);
    }
    return my_lex_tok;
}

lex_tok* getNextToken(string l)
{
        int state=0;
        while(right1<l.length())
        {
                if(right1>=l.length())
                {
                        break;
                }
                char c=l[right1];
                switch(state)
                {
                        case 0:
                                if(c==' '|| c=='\t'){
                                        state = 0;
                                        c = l[++right1];
                                        left1 = right1;
                                        //break;
                                }   
                                else if(c=='+')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->tok = "ADDITION_OP";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }    
                                else if(c=='(')
                                {
                                        lex_tok* pair=returnLexeme(c);
                                        pair->tok = "OP_PAR";
                                        pair->lineno = ln;
                                        count_tok++;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return pair;
                                        break;
                                }
                                else if(c==')')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->tok = "CL_PAR";
                                        lex_tok_pair->lineno = ln;
                                        count_tok++;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }
                                else if(c=='-')
                                {
                                        state = 0;
                                        c = l[++right1];
                                }
                                else if(c==':')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->tok = "COL";
                                        lex_tok_pair->lineno = ln;
                                        count_tok++;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;    
                                }
                                else if(c=='[')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->tok = "OP_SQB";
                                        lex_tok_pair->lineno = ln;
                                        count_tok++;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }
                                else if(c==']')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->tok = "CL_SQB";
                                        lex_tok_pair->lineno = ln;
                                        count_tok++;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }
                                else if(c==',')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->tok = "COM";
                                        lex_tok_pair->lineno = ln;
                                        count_tok++;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }
                                
                                else if(c=='\"') 
                                {
                                        flag1 =1;
                                        state=8;
                                        c = l[++right1];
                                } 
                                //e
                                else if(c=='%')
                                {
                                        state=7;
                                        c=l[++right1];
                                }
                                else if(c=='<'){
                                        c = l[++right1];
                                        state = 5;
                                }
                                else if(c=='>'){
                                        c = l[++right1];
                                        state = 4;
                                }
                                else if(c=='!'){
                                        c = l[++right1];
                                        state = 6;
                                }
                                else if(c=='=')
                                {
                                        state=3;
                                        c = l[++right1];
                                }
                                else if(c=='!'){
                                        c = l[++right1];
                                        state = 6;
                                }
                                else if(isalpha(c)){//to do
                                        c=l[++right1];
                                        state=2;
                                }
                                else if(c=='0')
                                {
                                        if(right1==l.length()-1)
                                        {
                                                lex_tok* lex_tok_pair=returnLexeme(c);

                                                lex_tok_pair->tok = "INT_LIT";
                                                lex_tok_pair->lineno = ln;
                                                count_tok++;
                                                state=0;
                                                right1++;
                                                left1=right1;
                                                return lex_tok_pair;
                                                break;

                                        }
                                        c=l[++right1];
                                        state=9;
                                }
                                else if(c>='1' && c<='9')
                                {
                                        if(right1==l.length()-1)
                                        {
                                                lex_tok* lex_tok_pair=returnLexeme(l[left1]);
                                                for(int i =left1+1;i<=right1;i++)
                                                {
                                                        lex_tok_pair->lex.push_back(l[i]);
                                                }
                                                lex_tok_pair->tok = "INT_LIT";
                                                lex_tok_pair->lineno = ln;
                                                count_tok++;
                                                state=0;
                                                right1++;
                                                left1=right1;
                                                return lex_tok_pair;
                                                break;

                                        }
                                        c=l[++right1];
                                        state=10;
                                }
                                else if(c=='\n')
                                {
                                        return NULL;
                                        break;
                                }
                                break;
                        case 2:
                                
                                if(c=='_'){
                                        state=1;
                                        c=l[++right1];
                                }
                                else {   if(isalpha(c)){
                                        state=2;
                                        c=l[++right1];

                                }
                                else{
                                        lex_tok* lex_tok_pair=returnLexeme2(l);
                                        auto it = find(keywords.begin(), keywords.end(), lex_tok_pair->lex);
                                        if(it!=keywords.end())
                                        {
                                                lex_tok_pair->tok = tokens[it-keywords.begin()];
                                                lex_tok_pair->lineno = ln;
                                                state=0;
                                                
                                                left1=right1;
                                                count_tok++;
                                                return lex_tok_pair;
                                                break;
                                        }
                                        else{
                                                lex_tok_pair->tok = "IDENTIFIER";
                                                lex_tok_pair->lineno = ln;
                                                state=0;
                                                
                                                left1=right1;
                                                count_tok++;
                                                return lex_tok_pair;
                                                break;
                                        }
                                }
                                } break;
                        case 3:
                                if(c == '=')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->lex = "==";
                                        lex_tok_pair->tok = "EQ";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }
                                else
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->tok = "ASSIGN_OP";
                                        lex_tok_pair->lex = "=";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                        
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                } break;
                        case 4:
                                if(c=='=')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->lex = ">=";
                                        lex_tok_pair->tok = "GE";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }
                                else
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->lex = ">";
                                        lex_tok_pair->tok = "GT";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                        
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                } break;
                        case 5:
                                if(c=='=')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);

                                        lex_tok_pair->lex = "<=";
                                        lex_tok_pair->tok = "LE";
                                       lex_tok_pair->lineno = ln;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }
                                else
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->lex = "<";
                                        lex_tok_pair->tok = "LT";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                } break;
                        case 6:
                                if(c=='=')
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->lex = "!=";
                                        lex_tok_pair->tok = "NE";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                        right1++;
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                }
                                else
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->tok = "Lexical Error";
                                        lex_tok_pair->lex = "!";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                        
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                } break;
                                break;
                        case 7:
                                if(c=='%')
                                {
                                        right1++;
                                        while(right1<l.length()-1 && !(l[right1]=='%' && l[right1+1]=='%'))
                                        {
                                                right1++;
                                        }
                                        if(l[right1]=='%' && l[right1+1]=='%')
                                        {
                                                right1+=2;
                                                left1 = right1;
                                                state = 0;
                                                break;
                                        }
                                        else{
                                                cout<<"The comments section wasnt closed\n";
                                        }
                                }
                                else
                                {
                                        lex_tok* lex_tok_pair=returnLexeme(c);
                                        lex_tok_pair->lex="%";
                                        lex_tok_pair->tok = "MOD_OP";
                                        lex_tok_pair->lineno = ln;
                                        state=0;
                                        
                                        left1=right1;
                                        return lex_tok_pair;
                                        break;
                                } break;
                                
                        case 8:
                                for(int i = right1;i<l.length();i++)
                                {
                                        if(l[i]=='\"')
                                        {
                                                lex_tok* lex_tok_pair=returnLexeme(l[left1]);
                                                for(int j=left1+1;j<=i;j++){
                                                        lex_tok_pair->lex.push_back(l[j]);
                                                }
                                                lex_tok_pair->tok = "STRING_LIT";
                                                lex_tok_pair->lineno = ln;
                                                count_tok++;
                                                left1 = right1=i+1;
                                                
                                                state = 0;
                                                return lex_tok_pair;
                                                break;
                                        }
                                }
                        
                                if(true)
                                {
                                lex_tok* lex_tok_pair=returnLexeme(l[left1]);
                                for(int j=left1+1;j<l.length();j++){
                                        lex_tok_pair->lex.push_back(l[j]);
                                }
                                lex_tok_pair->tok = "LEXICAL ERROR";
                                lex_tok_pair->lineno = ln;
                                count_tok++;
                        
                                
                                state = 0;
                                left1=right1=l.length();
                                return lex_tok_pair;
                                break;
                                }
                                break;
                              
                        case 9:
                               
                                if(c>='0' && c<='9')
                                {
                                       
                                        lex_tok* lex_tok_pair=returnLexeme(l[left1]);
                                        for(int j=left1+1;j<l.length();j++){
                                                if((l[j]>='0' && l[j]<='9') || l[j]== '.' )
                                                {
                                                        lex_tok_pair->lex.push_back(l[j]);
                                                        if(j==l.length()-1)
                                                        {
                                                                if(j==l.length()-1)
                                                                {
                                                                        lex_tok_pair->tok = "LEXICAL ERROR";
                                                                        lex_tok_pair->lineno = ln;
                                                                        count_tok++;
                                                                        left1 = right1 = ++j;
                                                                        state = 0;
                                                                        return lex_tok_pair;
                                                                        break;
                                                                        

                                                                }
                                                        }
                                                }
                                                else
                                                {
                                                        lex_tok_pair->tok = "LEXICAL ERROR";
                                                        lex_tok_pair->lineno = ln;
                                                        count_tok++;
                                                        left1 = right1 = j;
                                                        
                                                        state = 0;
                                                        return lex_tok_pair;
                                                        break;

                                                }
                                        }
                                        break;

                                }
                                else if(c=='.')
                                {
                                        
                                        state = 10;
                                        break;

                                }
                                else
                                {
                                      
                                        lex_tok* lex_tok_pair = returnLexeme(c);
                                        lex_tok_pair->lex = "0";
                                        lex_tok_pair->tok = "INT_LIT";
                                        lex_tok_pair->lineno = ln;
                                        count_tok++;
                                        
                                        left1 = right1;
                                        state = 0;
                                        return lex_tok_pair;
                                        break;
                                       


                                }
                                break;
                        case 10:
                                if(c>='0' && c<='9' && right1!=l.length()-1)
                                {
                                        c=l[++right1];
                                        state=10;
                                }
                                else if(c=='.')
                                {
                                      
                                        lex_tok* lex_tok_pair=returnLexeme(l[left1]);
                                        for(int j=left1+1;j<l.length();j++){
                                                if((l[j]>='0' && l[j]<='9') || l[j]== '.')
                                                {
                                                        if(l[j]=='.')
                                                        {
                                                                flag4++;
                                                        }
                                                        lex_tok_pair->lex.push_back(l[j]);
                                                        if(j==l.length()-1)
                                                        {
                                                                lex_tok_pair->tok = "FLOAT_LIT";
                                                                lex_tok_pair->lineno = ln;
                                                                count_tok++;
                                                                left1 = right1 = ++j;
                                                                //break;

                                                        }
                                                }
                                                else
                                                {
                                                        lex_tok_pair->tok = "FLOAT_LIT";
                                                        lex_tok_pair->lineno = ln;
                                                        count_tok++;
                                                        left1 = right1 = j;
                                                        break;
                                                       

                                                }
                                        }
                                        if(flag4>1 || l[right1-1]=='.'||l[right1-1]== '0')
                                        {
                                                lex_tok_pair->tok= "LEXICAL ERROR";
                                        }
                                        state = 0;
                                        flag4=0;
                                        return lex_tok_pair;
                                        break;
                                }
                                
                                else
                                {
                                        if(right1==l.length()-1 && l[right1] >='0' && l[right1]<='9')
                                        {
                                                right1++;
                                        }
                                        lex_tok* lex_tok_pair=returnLexeme(l[left1]);
                                        for(int j=left1+1;j<right1;j++){
                                                lex_tok_pair->lex.push_back(l[j]);
                                        }
                                        lex_tok_pair->tok = "INT_LIT";
                                        lex_tok_pair->lineno = ln;
                                        count_tok++;
                                        left1 = right1;
                                        
                                        state = 0;
                                        return lex_tok_pair;
                                        break;
                                }
                                break;
                                

                }
        }
    
}
