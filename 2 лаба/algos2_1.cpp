#include<bits/stdc++.h>
using namespace std;

void qsort(long long *b,int left,int right) {
    long long middle;
    middle = b[rand() % (right - left + 1) + left];
    int i=left;
    int j=right;
    while(i<j) {
        while(b[i]<middle) {
        i++;
        }
        while(b[j]>middle){
        j--;
        }
        if(i<=j){
            swap(b[i],b[j]);i++;j--;}

    }
    if(left<j)
        qsort(b,left,j);
    if(right>i)
        qsort(b,i,right);
}


int main() {
    int d;
    ifstream inp("sort.in");
    inp >> d;
    long long a[d];
    for (int i=middle-2;i>=0;i--){
        swap(a[i],a[(i+middle-1)/2]);
    }
    qsort(a,0,d-1);
    ofstream outp("sort.out");
    for(int i=0;i<d;i++){
        outp << a[i] << ' ';
    }
return 0;
}
