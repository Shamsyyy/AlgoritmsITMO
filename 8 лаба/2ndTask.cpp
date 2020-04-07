#include <iostream>
#include <fstream>

using namespace std;

int main() {
    short MatSize;
    ifstream inp("input.txt");
    ofstream outp("output.txt");
    inp >> MatSize;
    short Number;
    short arr[MatSize][MatSize];
    for(int i = 0; i < MatSize; i++) {
        for (int j = 0; j < MatSize; j++) {
            inp >> Number;
            if(i > j && arr[j][i] != Number){
                outp << "NO";
                inp.close();
                outp.close();
                return 0;
            }
            if(i == j && Number != 0){
                outp << "NO";
                inp.close();
                outp.close();
                return 0;
            }
            arr[i][j] = Number;
        }
    }
    outp << "YES";
    inp.close();
    outp.close();
    return 0;
}
