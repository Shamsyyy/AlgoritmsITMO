#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

 
struct bintree{
  int left, right;
  int key;
};
 
int returnsize(bintree *mytree, int sizee,int cur){
  int r = sizee;
  int l = sizee;
  if(mytree[cur].right != 0)
    r = returnsize(mytree , sizee + 1 , mytree[cur].right);
  if(mytree[cur].left != 0)
    l = returnsize(mytree , sizee + 1 , mytree[cur].left);
  return max(r,l);
}
 
int main() {
  ifstream inp("height.in");
  int commands;
  inp >> commands;
  ofstream outp("height.out");
  if (commands == 0){
    outp << 0;
    return 0;
  }
  bintree *mytree = new bintree[commands+1];
  int d = 1;
  for(int i = 1; i < commands + 1 ; i++ ){
    int K , R , L;
    inp >> K >> R >> L;
    mytree[i].key = K;
    mytree[i].right = R;
    mytree[i].left = L;
    if(R == 1 || L == 1)
      d = i;
  }
  cout << d << ' ';
  inp.close();
  outp << returnsize(mytree , 0 , d)+1;
  outp.close();
  return 0;
}