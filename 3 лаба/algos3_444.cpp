#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void radixsort(vector<string> &arr, int m, int k,int i) {
    vector<string> result(arr.size(),"");
    vector<int> counters(26,0);
    	for (int j = 0; j < arr.size(); j++) {
            counters[arr[j][i] - 'a']++;
        }
        int temp, count = 0;
        for (int j = 0; j < counters.size(); j++) {
            temp = counters[j];
            counters[j] = count;
            count += temp;
        }
        for (int j = 0; j < arr.size(); j++) {
            result[ counters[arr[j][i] - 'a'] ] = arr[j];
            counters[arr[j][i] - 'a']++;
        }
        arr = result;
    }



int main()
{
    ifstream inp("radixsort.in");
    int n, m, k;
    inp >> n >> m >> k;
    vector<string> a(n,"");
    for (int i = 0; i < n; i++) {
        inp >> a[i];
    }
    inp.close();
	for(int i = m - 1 ; i > m - k - 1 ; i-- )
    radixsort(a, m, k, i);
    ofstream outp("radixsort.out");
    for (int i = 0; i < n; i++) {
        outp << a[i] << endl;
    }
    outp.close();
}
