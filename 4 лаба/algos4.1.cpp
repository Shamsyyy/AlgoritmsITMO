#include <iostream>
#include <fstream>
using namespace std;

struct list{
	long long a;
	list *head,*next;
};

void push(long long a,list *&CurList){
	list *newlist = new list;
	newlist -> a = a;
	newlist -> next = CurList -> head;
	CurList -> head = newlist;
	return;
}

long long pop(list *&CurList){
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
	ifstream inp("stack.in");
	inp >> commands;
	char b;
	long long a;
	ofstream outp("stack.out");
	for(int i=0;i < commands; i++){
		inp >> b;
		switch(b){
			case '+':
				inp >> a;
				push(a,CurList);
				break;
			case '-':
				outp << pop(CurList) <<'\n';
				break;
		}
	}
	return 0;
}