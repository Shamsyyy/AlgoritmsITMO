#include <iostream>
#include <fstream>

using namespace std;

int main() {
    short counter,tops;
    ifstream inp("input.txt");
    inp >> counter;
    short arr[counter][counter];
    for(int i = 0; i < counter; i++){
        for(int j = 0; j < counter; j++)
            arr[i][j] = 0;
    }
    inp >> tops;
    short String, column;
    for(int i = 0; i < tops; i++){
        inp >> String >> column;
        arr[String-1][column-1] = 1;
    }
    inp.close();
    ofstream outp("output.txt");
    for(int i = 0; i < counter; i++){
        for(int j = 0; j < counter; j++){
            outp << arr[i][j] << ' ';
        }
        outp << endl;
    }
    outp.close();
    return 0;
}
