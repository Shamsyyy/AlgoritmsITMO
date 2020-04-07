#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list{
	char a;
	list *head,*next;
};

void push(char a,list *&CurList){
	list *newlist = new list;
	newlist -> a = a;
	newlist -> next = CurList -> head;
	CurList -> head = newlist;
	return;
}

char pop(list *&CurList){
	long long ret;
	ret = CurList-> head -> a;
	list *newlist = CurList -> head -> next;
	delete CurList -> head;
	CurList -> head = newlist;
	return ret;
}

int main() {
	list *CurList = new list;
	CurList->head = NULL;
	int commands;
	ifstream inp("brackets.in");
	char b;
	char a;
	ofstream outp("brackets.out");
	string str;
	while(!inp.eof()){
		getline(inp,str);
	if(inp.eof())
	break;
	for(int i=0;i < str.length(); i++){
		a = str[i];
		push(a,CurList);
	}
	list *CheckList = new list;
	CheckList -> head = NULL;
	for(int i=0;i < str.length() ; i++){
		if(CheckList -> head == NULL){
		a = pop(CurList);
		push(a,CheckList);
		if(a=='(' || a=='['){
		break;
		}
		}
		else{
			if(CurList -> head -> a == ')' || CurList -> head -> a == ']'){
			a = pop(CurList);
			push(a,CheckList);
		}
		else{
			if((CurList -> head -> a == '(' && CheckList -> head -> a == ')') || (CurList -> head -> a == '[' && CheckList -> head -> a == ']') )
			{
			pop(CurList);
			pop(CheckList);
			}
			else{
				break;
			}
		}
		}
		if(CurList -> head == NULL)
		break;
	}
	if(CheckList -> head == NULL)
	outp << "YES" << "\n";
	else
	outp << "NO" << "\n";
	}
	return 0;
}