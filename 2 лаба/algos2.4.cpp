#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream inp("antiqs.in");
	int g;
	cin >> g;
	int a[g];
	for(int i = 0;i < g; i++){
		a[i] = i + 1;
	}
	int p;
	for(int i=0 ;i < g; i++){
		p = a[i / 2];
		a[i / 2] = a[i];
		a[i] = p;
	}
	ofstream outp("antiqs.out");
	for(int i=0; i < g; i++){
		outp << a[i] << ' ';
	}
	return 0;
}
