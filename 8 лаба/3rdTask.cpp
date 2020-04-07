#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp("input.txt");
    ofstream outp("output.txt");
    int MatSize, NumbersOfTops;
    inp >> MatSize >> NumbersOfTops;
    int arr[MatSize][MatSize] , String, Colomn;
    for(int i = 0; i < MatSize; i ++){
        for(int j = 0; j < MatSize; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0 ; i < NumbersOfTops; i ++){
        inp >> String >> Colomn;
        arr[String - 1][Colomn - 1] += 1;
    }
    for(int i = 0; i < MatSize; i++){
            for(int j = 0; j < MatSize; j++){
                if(arr[i][j] > 1 || (arr[j][i] == 1 && arr[i][j] > 0)) {
                    outp << "YES";
                    outp.close();
                    inp.close();
                    return 0;
                }
            }
    }
    outp << "NO";
    outp.close();
    inp.close();
    return 0;
}
