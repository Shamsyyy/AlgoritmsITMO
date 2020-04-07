#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void Search(int MatSize, vector<vector<int>> &arr, vector<int> &used, int count, int CurElement){
    used[CurElement] = count;
    for(int i = 0; i < arr[CurElement].size() ; i++)
    {
        if(used[arr[CurElement][i]] == 0){
            Search(MatSize, arr, used, count, arr[CurElement][i]);
        }
    }
    return;
}

int main()
{
    ifstream inp("components.in");
    ofstream outp("components.out");
    int MatSize, NumbersOfTops;
    inp >> MatSize >> NumbersOfTops;
    vector<int> used(MatSize,0);
    vector<vector<int>> arr(MatSize,vector<int>());
    int String, Colomn;
    for(int i = 0 ; i < NumbersOfTops; i ++){
        inp >> String >> Colomn;
        arr[Colomn-1].push_back(String - 1);
        arr[String-1].push_back(Colomn - 1);
    }
    int count = 1;
    for(int i = 0; i < MatSize; i++){
        if(used[i] == 0){
            Search(MatSize, arr, used, count, i);
            count += 1;
        }
    }
    outp << count - 1 << endl;
    for(int i = 0; i < MatSize; i++){
        outp << used[i] << ' ';
    }
    outp.close();
    inp.close();
    return 0;
}
