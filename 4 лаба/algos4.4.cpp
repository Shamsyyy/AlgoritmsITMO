#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main() {
	stack<int> CurList;
	int commands;
	ifstream inp("postfix.in");
	char b;
  int z;
	ofstream outp("postfix.out");
	for(;;){
		inp >> b;
    if(inp.eof())
    break;
    if(b -'0' > -1){
    CurList.push(b -'0');
    }
    else
    switch(b){
      case '+':
      z = CurList.top();
      CurList.pop();
      CurList.top() = CurList.top() + z;
      break;
      case '*':
      z = CurList.top();
      CurList.pop();
      CurList.top() = CurList.top() * z;
      break;
      case '-':
      z = CurList.top();
      CurList.pop();
      CurList.top() = CurList.top() - z;
      break;
    }
  }
  if(CurList.size() == 0){
  	outp << '0';
  }
  else{
  outp << CurList.top();
  }
  return 0;
}