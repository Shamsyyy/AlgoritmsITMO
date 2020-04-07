#include <iostream>
#include <fstream>
using namespace std;
long long sum=0;
void merge(long long *a,int left,int mid,int right){
    int z=0;
    int schet=left;
    int it1 = 0;
    int it2 = 0;
    int d=0;
    long long result[right-left];
    while ((left + it1 < mid) && (mid + it2 < right))
        if (a[left + it1] <= a[mid + it2]){
            result[it1 + it2] = a[left + it1];
            it1++;
        }
        else{
            result[it1 + it2] = a[mid + it2];
            sum=sum+(mid-left-it1);
            it2++;}

    while (left + it1 < mid){
        result[it1 + it2] = a[left + it1];
        it1++;}

    while (mid + it2 < right){
        result[it1 + it2] = a[mid + it2];
        it2++;}

    for (int i = 0 ; i < it1+it2; i++)
        a[left + i] = result[i];

        return; }

void mergeSort(long long *a,int left,int right){
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
    ifstream inp("inversions.in");
    int g;
    inp >> g;
    long long a[g];
    for(int i=0;i<g;i++){
        inp >> a[i];
    }
    mergeSort(a,0,g);
    ofstream outp("inversions.out");
    outp << sum;

}
