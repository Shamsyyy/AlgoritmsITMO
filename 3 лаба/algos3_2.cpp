#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int main() {
    ifstream inp("isheap.in");
    vector<long long> arr;
    int size;
    inp >> size;
    long long num;
    arr.push_back(0);
    for(int i=0;i<size+1;i++){
        inp >> num;
        arr.push_back(num);
    }
    int k = 0;
    ofstream outp("isheap.out");
    for(int i=1;i<size+1;i++){
        if(i * 2 > size-1)
        break;
        if(arr[i] > arr[i * 2] ){
        	outp << "NO";
        	k = 1;
        	break;
        }
        if(i * 2 + 1 > size-1)
        break;
        if(arr[i] > arr[i * 2 + 1] ){
        	outp << "NO";
        	break;
        }
    }
    if(k != 1){
    	outp << "YES";
    }
}
