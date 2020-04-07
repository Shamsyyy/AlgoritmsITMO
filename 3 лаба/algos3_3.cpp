#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void siftDown(vector <long long> &arr,long long i,long long roof){
	long long right;
	long long left;
	long long score;
	while(2*i<roof){
		left = 2 * i;
		right = 2 * i + 1;
		score = 2 * i;
		if((right != roof) && (arr[right] > arr[left]))
		score=right;

		if(arr[score] > arr[i])
		swap(arr[score], arr[i]);
		else return;
		i = score;
	}
	return;
}

void siftUp(vector <long long> &arr,long long i){
	while(true){
		if(i == 1)
		return;
		if(arr[i] > arr[i/2])
		swap(arr[i], arr[i/2]);
		else return;

	}
}

int main() {
	ifstream fInp("sort.in");
	vector<long long> arr;
	long long size;
	long long suff;
	fInp >> size;
	arr.push_back(-1);
	for(int i=1;i<size+1;i++){
		fInp >> suff;
		arr.push_back(suff);
		if(i > 1){
			siftUp(arr, i);
		}
	}
	for(int i=arr.size()-1;i>0;i--){
		swap(arr[i], arr[1]);
		siftDown(arr, 1, i);
	}
	ofstream fOut("sort.out");
	for(int i=1;i<arr.size();i++){
		fOut << arr[i] << ' ';
	}
	return 0;
}
