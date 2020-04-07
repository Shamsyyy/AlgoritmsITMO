#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct set{
  vector <int> z;
};

int hashh(int a){
  return abs(a) % 1000000;
}

bool isinhash(set *check, int num){
  int CurHash = hashh(num);
  for(int i = 0; i < check[CurHash].z.size(); i++){
    if(check[CurHash].z[i] == num){
      return true;
    }
  }
  return false;
}

void del(set *check,int num){
  int CurHash = hashh(num);
  for(int i = 0; i < check[CurHash].z.size(); i++){
    if(check[CurHash].z[i] == num){
      check[CurHash].z.erase(check[CurHash].z.begin() + i);
      return;
    }
  }
  return;
}



int main() {
  set *check = new set[1000000];
  ifstream inp("set.in");
  ofstream outp("set.out");
  string stroke;
  int num;
  for(;;){
    inp >> stroke;
    if(inp.eof())
      break;
    if(stroke == "insert"){
      inp >> num;
      if(isinhash(check, num));
      else{
      check[hashh(num)].z.push_back(num);
      }
    }
    else{
      if(stroke == "delete"){
        inp >> num;
        if(check[hashh(num)].z.empty());
        else{
          del(check , num);
        }
      }
      else{
        inp >> num;
        if(isinhash(check, num))
         outp << "true\n";
        else
         outp << "false\n";
      }
    }
  }
  outp.close();
  inp.close();
  return 0;
}