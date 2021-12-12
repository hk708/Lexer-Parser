/*
Team Members :
Anurag Sidharth Aribandi 2018A7PS1218H
Himnish Kapoor 2018A7PS1215H
Varun Narayanan 2018A7PS1226H
Anish Sai Mitta 2018A7PS1221H
*/
#include<bits/stdc++.h>
#include<string>
using namespace std;

string non_terminals[26];
string terminals[34];
string parsing_table[27][35];
stack <string> input;
stack <string> parsing;
//struct for a node in parsing tree
struct node
{
	vector <node*> children;
	string value;
};
//function to create a new node
node *createNode(string s)
{
	struct node *link = new node;
	link->value = s;
	return link;
}
//function to return whether an input string is a terminal or not
int isTerminal(string inp)
{
    if(inp[0] == '[')
    return 1;
    else
    return 0;
}
//linear search function
int search(string s,int isT) {
	if(isT == 0) {
		for(int i = 0;i<26;i++) {
			if(non_terminals[i].compare(s) == 0) {
				return i;
			}
		}
	}
	else {
		for(int i = 0;i<34;i++) {
			if(terminals[i].compare(s) == 0) {
				return i;
			}
		}
	}
	return -2;
}
//function to return an index for the parsing table given an input string 
int index(string s) {

	int ind = search(s,isTerminal(s));
	return ind + 1;
}
//function to produce a vector of strings for an RHS given a single production rule string
vector <string> prod_strings(string prod_rule) {
	int index = prod_rule.find("=") + 1;
	int end = prod_rule.length();
	vector <string> final;
	string temp = "";
	for(int i = index;i<end;i++) 
	{
		temp+=prod_rule[i];
	}
	string temp2 = "";
	for(int i = 0;i<temp.length();i++) 
	{
		if(temp[i] == '>' || temp[i] == ']')
		{
			temp2+=temp[i];
			final.push_back(temp2);
			temp2 = "";
		}
		else {
			temp2+=temp[i];
		}
	}
	return final;
}
int main(int argc, char **argv) {
	ifstream f;
	f.open("Parsing Table.csv");
	int i = 0;
	int j = 0;  
	int l = 0;
	int flag = 0;
	string line;
	//storing the parsing table in a 2-D array
  	while (getline (f, line)) {         
        string val;                     
        stringstream s (line); 
        int k = 0;      
        while (getline (s, val, ',')) 
        {   

           if(j == 0 && k!=0) 
           		terminals[l++] = val;
           
           if(k == 0 && j!=0) 
            	non_terminals[i++] = val;

           parsing_table[j][k] = val;
            k++;
        }
        j++;
    }
    string tokens;
    ifstream lexeme_reader;
	//opening the input file test case
    lexeme_reader.open(argv[1]);
	string input_tokens[1000];
	string line_num[1000];
	//pushing $ onto the input stack
	input.push("$");
    string tofind = "[";
    string end = "]";
	int size = 0;
	//storing the input tokens into an input stack
    while (getline(lexeme_reader,tokens)) {
		int start_index = tokens.find(tofind);
		int end_index = tokens.find(end);
		int startl = tokens.find("Line no.");
		string temp = "";
		string templ = "";
		for(int j = start_index;j<=end_index;j++) {
			temp +=tokens[j];
		}
		for(int j = startl;j<tokens.length();j++)
		{
			templ += tokens[j];
		}
		input_tokens[size] = temp;
		line_num[size] = templ;
		size++;
	}
	for(i=size-1; i>=0; i--)
	{
		input.push(input_tokens[i]);
	}
	int matched = 0;
	int ind = 0;
	//pushing start nonterminal and $ onto the parsing stack
	parsing.push("$");
	parsing.push("<START_PROGRAM>");
	node* top = createNode("<START_PROGRAM>");
	node* current = top;
	fstream outp;
	outp.open("stack_output.txt",ios::out);
	fstream toutp;
	toutp.open("tree_output.txt",ios::out);
	//parsing process starts
	while(!parsing.empty()) 
	{
		string production_rule = "";
		vector <string> prod_string;
		if(parsing.top().compare(input.top()) == 0 && parsing.top().compare("$") == 0) 
		{	
			if(flag == 0) 
			{
				cout<<"PARSED"<<endl;
				outp<<"PARSED"<<endl;
				toutp<<"PARSED"<<endl;
			}
			else if(flag == 1)
			{
				cout<<"ERROR AT "<<line_num[ind]<<endl;
				outp<<"ERROR AT "<<line_num[ind]<<endl;
				toutp<<"ERROR AT "<<line_num[ind]<<endl;
			}
			parsing.pop();
			input.pop();
		}
		else if(parsing.top().compare(input.top()) == 0 && isTerminal(parsing.top()))
		{
			node* temp2 = createNode(input.top());
			current->children.push_back(temp2);
			matched++;
			outp<<"Matched "<<parsing.top()<<endl<<endl;
			parsing.pop();
			input.pop();

		}
		else if( parsing.top().compare(input.top()) != 0 && isTerminal(input.top()) && isTerminal(parsing.top()))
		{
			if(flag == 0)
				ind = matched;
			outp<<"TERMINAL ERROR, TRIED TO MATCH "<<input.top()<<" WITH "<<parsing.top()<<endl<<endl;
			toutp<<"TERMINAL ERROR, TRIED TO MATCH "<<input.top()<<" WITH "<<parsing.top()<<endl<<endl;
			input.pop();
			flag = 1;
			continue;
		}
		else 
		{
			if(parsing_table[index(parsing.top())][index(input.top())].compare("0") == 0)
			{
				if(flag == 0)
					ind = matched;
				outp<<"SKIP"<<endl<<endl;
				toutp<<"SKIP"<<endl<<endl;
				input.pop();
				flag = 1;
			}
			else if(parsing_table[index(parsing.top())][index(input.top())].compare("SYNCH") == 0)
			{
				if(flag == 0)
					ind = matched;
				outp<<"SYNCH"<<endl<<endl;
				toutp<<"SYNCH"<<endl<<endl;
				parsing.pop();
				flag = 1;
			}
			
			else {
				if(parsing.top().compare("<START_PROGRAM>") != 0)
				{
					node* temp1 = createNode(parsing.top());
					current = temp1;
				}
				production_rule = parsing_table[index(parsing.top())][index(input.top())];
				stack <string> temp;
				temp = parsing;
				outp<<"Stack : ";
				while(!temp.empty())
				{
					outp<<temp.top();
					temp.pop();
				}
				outp<<endl<<"Production rule is : "<<production_rule<<endl;	
				parsing.pop();
				prod_string = prod_strings(production_rule);
				for(auto i = prod_string.rbegin(); i!=prod_string.rend(); ++i) 
				{
					string st = *i;
					if(st.length() != 0)
					{
						vector <node*> kids = current->children;
						parsing.push(*i);
						node* temp = createNode(*i);
						kids.push_back(temp);
						current->children = kids;
					}
		   		}
				int si = current->children.size();
				if(si != 0)
				{
					toutp<<"Parent :"<<current->value<<endl;
					for(auto i = current->children.rbegin(); i!=current->children.rend(); ++i)
					{
						node* temptemp = *i;
						toutp<<"Child :"<<temptemp->value<<endl;
					}
					toutp<<endl;
				}
				if(si == 0)
				{
					toutp<<"Parent :"<<current->value<<endl;
					toutp<<"Child :"<<"NULL"<<endl;
					toutp<<endl;
				}
				temp = parsing;
				outp<<"Stack after production rule : ";
				while(!temp.empty())
				{
					outp<<temp.top();
					temp.pop();
				}
				outp<<endl<<"Input top is : "<<input.top()<<endl<<endl;
			}
		}	
	}
	return 0;
}