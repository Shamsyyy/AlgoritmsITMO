#include <iostream>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

void kpor(vector<int> &mas, int n,int l,int r) {
	while(true){
	if(r <= l + 1){
		if((r == l + 1) && (mas[l] > mas[r]))
		swap(mas[l], mas[r]);
		return ;
	}
	int mid = (rand() % (r - l + 1) + l);
	swap(mas[mid], mas[l + 1]);
	if(mas[l] > mas[r])
	swap(mas[l], mas[r]);
	if(mas[l+1] > mas[r])
	swap(mas[l + 1], mas[r]);
	if(mas[l] > mas[l + 1])
	swap(mas[l], mas[l + 1]);
	int i = l + 1;
	int j = r;
	int check = mas[l + 1];
	while(true){
		while(mas[++i] < check);
		while(mas[--j] > check);
		if(i > j)
		break;
		swap(mas[i],mas[j]);
	}
	mas[l + 1] = mas[j];
	mas[j] = check;
	if(j >= n)
	r = j - 1;
	if(j <= n)
	l = i;
	}
}

int main() {
    int a,b,c,d,f;
    fstream inp("kth.in");
    inp >> a >> b >> c >> d >> f;
    int zap;
    vector <int> mas;
    for(int i = 0; i < 2; i++){
        inp >> zap;
        mas.push_back(zap);
    }
    for(int i = 2; i < a; i++){
        mas.push_back(c * mas[i - 2] + d * mas[i - 1] + f);
    }
    ofstream outp("kth.out");
    kpor(mas, b-1, 0, mas.size() - 1);
    outp << mas[b - 1];
    return 0;
}
