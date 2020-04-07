#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

void bfs(vector<vector<char>> &arr,  vector<vector<int>> &ways, int &CurX, int &CurY, int &FinishX, int &FinishY,int &CurCycle, int &String, int &Symbols,
queue<int> &ThatX, queue<int> &ThatY, int &done){
    if(CurX > 0 && arr[CurX - 1][CurY] != '#' && ways[CurX - 1][CurY] == 0){
        ways[CurX - 1][CurY] = CurCycle + 1;
        ThatX.push(CurX-1);
        ThatY.push(CurY);
        if(CurX - 1 == FinishX && CurY == FinishY) {
            done = 1;
            return;
        }
    }
    if(CurX < String - 1 && arr[CurX + 1][CurY] != '#' && ways[CurX + 1][CurY] == 0){
        ways[CurX + 1][CurY] = CurCycle + 1;
        ThatX.push(CurX+1);
        ThatY.push(CurY);
        if(CurX + 1 == FinishX && CurY == FinishY) {
            done = 1;
            return;
        }
    }
    if(CurY > 0 && arr[CurX ][CurY - 1] != '#' && ways[CurX][CurY - 1] == 0){
        ways[CurX ][CurY - 1] = CurCycle + 1;
        ThatX.push(CurX);
        ThatY.push(CurY - 1);
        if(CurX  == FinishX && CurY - 1 == FinishY) {
            done = 1;
            return;
        }
    }
    if(CurY < Symbols - 1 && arr[CurX ][CurY + 1] != '#' && ways[CurX][CurY + 1] == 0){
        ways[CurX ][CurY + 1] = CurCycle + 1;
        ThatX.push(CurX);
        ThatY.push(CurY + 1);
        if(CurX  == FinishX && CurY + 1 == FinishY) {
            done = 1;
            return;
        }
    }
    return;
}

int main() {
    int String, Symbols;
    ifstream inp("input.txt");
    inp >> String >> Symbols;
    ofstream outp("output.txt");
    vector<vector<char>> arr(String, vector<char>(Symbols,0));
    int StartX, StartY, FinishX, FinishY;
    vector<vector<int>> Ways(String, vector<int>(Symbols, 0));
    char CurElement;
    for(int i = 0; i < String; i++){
        for(int j = 0; j < Symbols; j++){
            inp >> CurElement;
            arr[i][j] = CurElement;
            if(CurElement == '#'){
                Ways[i][j] = -1;
            }
            if(CurElement == 'S') {
                StartX = i;
                StartY = j;
            }
            if(CurElement == 'T'){
                FinishX = i;
                FinishY = j;
            }
        }
    }
    Ways[StartX][StartY] = 1;
    queue<int> ThatX;
    queue<int> ThatY;
    ThatX.push(StartX);
    ThatY.push(StartY);
    int done = 0;
    while(ThatX.size() > 0){
        bfs(arr,  Ways, ThatX.front(), ThatY.front(), FinishX, FinishY, Ways[ThatX.front()][ThatY.front()], String, Symbols, ThatX, ThatY, done);
        ThatX.pop();
        ThatY.pop();
        if(done == 1)
            break;
    }
    if(done == 0){
        outp << "-1";
        inp.close();
        outp.close();
        return 0;
    }
    outp << Ways[FinishX][FinishY] - 1 <<  endl;
    string Way = "";
    while(Ways[FinishX][FinishY] != 1){
        if(FinishX != 0 && Ways[FinishX][FinishY] - 1 == Ways[FinishX - 1][FinishY]){
            Way = "D" + Way;
            FinishX -= 1;
        }
        if(FinishX != String - 1 && Ways[FinishX][FinishY] - 1 == Ways[FinishX + 1][FinishY]){
            Way = "U" + Way;
            FinishX += 1;
        }
        if(FinishY != 0 && Ways[FinishX][FinishY] - 1 == Ways[FinishX][FinishY - 1]){
            Way = "R" + Way;
            FinishY -= 1;
        }
        if(FinishY != Symbols - 1 && Ways[FinishX][FinishY] - 1 == Ways[FinishX][FinishY + 1]){
            Way = "L" + Way;
            FinishY += 1;
        }
    }
    outp << Way;
    inp.close();
    outp.close();
    return 0;
}
