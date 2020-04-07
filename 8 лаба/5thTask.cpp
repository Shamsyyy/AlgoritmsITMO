#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

void bfs(vector<int> &used, vector<vector<int>> &arr, int Counter, int CurNum, vector<int> &ways, queue<int> &QueOfTops){
    for(int i = 0; i < arr[CurNum].size(); i++){
        if(used[arr[CurNum][i]] == 0) {
            used[arr[CurNum][i]] = 1;
            ways[arr[CurNum][i]] = Counter + 1;
            QueOfTops.push(arr[CurNum][i]);
        }
    }
}

int main() {
    ifstream inp("pathbge1.in");
    ofstream outp("pathbge1.out");
    int MatSize, CountTops;
    inp >> MatSize >> CountTops;
    vector<vector<int>> arr(MatSize, vector<int>());
    int String, Colom;
    for(int i = 0; i < CountTops; i++){
        inp >> String >> Colom;
        arr[String - 1].push_back(Colom - 1);
        arr[Colom - 1].push_back(String - 1);
    }
    vector<int> used(MatSize, 0);
    used[0] = 1;
    vector<int> ways(MatSize, 0);
    queue<int> QueOfTops;
    bfs(used, arr, 0, 0, ways, QueOfTops);
    int Cur;
    while(QueOfTops.size() > 0){
        Cur = QueOfTops.front();
        QueOfTops.pop();
        bfs(used, arr, ways[Cur], Cur, ways, QueOfTops);
    }
    for(int i = 0; i < MatSize; i++){
        outp << ways[i] << ' ';
    }
    outp.close();
    inp.close();
    return 0;
}
