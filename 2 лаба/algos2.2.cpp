#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <string>
using namespace std;

void merge(string a[][2],int left,int mid,int right){
    int z=0;
    int it1 = 0;
    int it2 = 0;
    int d=0;
    string result[right-left][2];
    while ((left + it1 < mid) && (mid + it2 < right)){
        if (a[left + it1][0] <= a[mid + it2][0]){
            result[it1 + it2][0] = a[left + it1][0];
            result[it1 + it2][1] = a[left + it1][1];
            it1++;}
        else{
            result[it1 + it2][0] = a[mid + it2][0];
            result[it1 + it2][1] = a[mid + it2][1];
            it2++;}}

    while (left + it1 < mid){
        result[it1 + it2][0] = a[left + it1][0];
        result[it1 + it2][1] = a[left + it1][1];
        it1 += 1;}

    while (mid + it2 < right){
        result[it1 + it2][0] = a[mid + it2][0];
        result[it1 + it2][1] = a[mid + it2][1];
        it2 += 1;}

    for (int i = 0 ; i < it1+it2; i++){
        a[left + i][0] = result[i][0];
        a[left + i][1] = result[i][1];
    }
        return; }

void mergeSort(string a[][2],int left,int right){
    if(left+1>=right){

        return;
    }
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
    return;
}


int main() {
    int d;
    ifstream inp("race.in");
    inp >> d;
    string a[d][2];
    for (int i=0;i<d;i++){
        inp >> a[i][0] >> a[i][1];
    }
    mergeSort(a,0,d);
    ofstream outp("race.out");
    for(int i=0;i<d;i++){
    	if(i!=0){
    		if(a[i-1][0]==a[i][0])
    		outp << a[i][1] << '\n';
    		else{
    			outp << "=== " << a[i][0] << " ===" << '\n' << a[i][1] << '\n';
    		}
    	}
    	else
        outp << "=== " << a[i][0] << " ===" << '\n' << a[i][1] << '\n';
    }
    return 0;
}
