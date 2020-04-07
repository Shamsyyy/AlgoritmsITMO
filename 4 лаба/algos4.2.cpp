#include <iostream>
#include <fstream>
using namespace std;

struct list{
	long long a;
	list *begin,*end,*next;
};

void push(long long a,list *&CurList){
	list *newlist = new list;
	CurList -> end -> next = newlist;
	CurList -> end = newlist;
	CurList -> end -> a = a;
	CurList -> end -> next = NULL;
	return;
}

long long pop(list *&CurList){
	long long ret;
	ret = CurList -> begin -> next -> a;
	CurList -> begin = CurList -> begin -> next;
	return ret;
}

int main() {
	list *CurList = new list;
	CurList -> next = NULL;
	CurList -> begin = CurList;
	CurList -> end = CurList;
	int commands;
	ifstream inp("queue.in");
	inp >> commands;
	char b;
	long long a;
	ofstream outp("queue.out");
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