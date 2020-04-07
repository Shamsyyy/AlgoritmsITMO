#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
 
int size = 0;
 
struct bintree{
  int left, right;
  int key;
};
 
int returnsize(bintree *mytree, int cur, int left, int right){
  if(mytree[cur].key > left && mytree[cur].key < right){
  if (mytree[cur].right != 0) {
    if (mytree[cur].key < mytree[mytree[cur].right].key) {

      if (returnsize(mytree, mytree[cur].right, mytree[cur].key, right) == -1) {
        return -1;
        }
      }
      else {
      return -1;
    }
    } 
  if (mytree[cur].left != 0) {
    if (mytree[cur].key > mytree[mytree[cur].left].key) {

      if (returnsize(mytree, mytree[cur].left, left , mytree[cur].key) == -1) {
        return -1;
      }
    } else {
      return -1;
      }
    } 
  }
  else return -1;
  return 0;
}
 
int main() {
  ifstream inp("check.in");
  int commands;
  inp >> commands;
  ofstream outp("check.out");
  if (commands == 0){
    outp << "YES";
    return 0;
  }
  bintree *mytree = new bintree[commands+1];
  int d = 1;
  for(int i = 1; i < commands + 1 ; i++ ){
    int K , R , L;
    inp >> K >> L >> R;
    mytree[i].key = K;
    mytree[i].right = R;
    mytree[i].left = L;
  }
  int isittrue = returnsize(mytree, d,-1000000001,1000000001);
  inp.close();
  if(isittrue == 0)
    outp << "YES";
  else
    outp << "NO";
  outp.close();
  return 0;
}