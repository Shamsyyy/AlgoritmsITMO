#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
 
struct mymap{
  string mykey;
  string myvalue;
};
 
int myhash(string key)
{
    int Hash = 0;
    int p = 39;
    for (int i = 0; i < key.size(); i++) {
        int s = 0;
        if (key[i] - 'a' >= 0 && key[i] - 'a' <= 9)
            s = key[i] - 'a';
        else
            s = key[i] - 'A';
        Hash = (Hash + ((s + 1) * p) % 1000000) % 1000000;
        p = (p * 39) % 1000000;
    }
    return Hash;
}
 
bool put(vector< vector <mymap> > &check,string key, string value)
{
    int Hash = myhash(key);
    for (int i = 0; i < check[Hash].size(); i++)
    {
        if (check[Hash][i].mykey == key)
        {
            check[Hash][i].myvalue = value;
            return true;
        }
    }
    return false;
}

void del(vector < vector < mymap> > &check,string key)
{
    int Hash = myhash(key);
    int number = 0;
    for (int i = 0; i < check[Hash].size(); i++)
    {
        if (check[Hash][i].mykey == key)
        {
            check[Hash].erase(check[Hash].begin()+i);
            return ;
        }
    }
    return;
}

string get(vector < vector < mymap> > &check,string key)
{
    int Hash = myhash(key);
    for (size_t i = 0; i < check[Hash].size(); i++) {
        if (check[Hash][i].mykey == key) {
            return check[Hash][i].myvalue;
        }
    }
    return "none";
}
 
int main() {
  vector<vector<mymap>> check(10000001, vector<mymap>());
  ifstream inp("map.in");
  ofstream outp("map.out");
  string command;
  string key;
  string value;
  int CurKey;
  for(;;){
    inp >> command;
    if(inp.eof())
      break;
    inp >> key;
    if(inp.eof())
      break;
    if(command == "put"){
      inp >> value;
      mymap *itswork = new mymap;
      itswork -> mykey = key;
      itswork -> myvalue = value;
      cout << myhash(key) << ' ';
      if(put(check, key, value));
      else { check[myhash(key)].push_back(*itswork);
      }
    }
    else{
      if(command == "delete"){
        del(check,key);
        }
      else{
        outp << get(check,key) << '\n';
      }
    }
  }
  outp.close();
  inp.close();
  return 0;
}