#include <iostream>
#include <fstream>

using namespace std;
    int main() {
    int ramzer;
    ifstream file ("smallsort.in");
    file >> ramzer;
    long long mas[ramzer];
    for (int i=0;i<ramzer;i++){
    file >> mas[i];
    }
    int q;
    for (int i=0;i<ramzer;i++){
        for(int j=i;j<ramzer;j++){
            if (mas[i]>mas[j]){
                q=mas[i];
                mas[i]=mas[j];
                mas[j]=q;
            }
        }
    }
    ofstream fileout ("smallsort.out");
    for (int i=0;i<ramzer;i++)
    fileout << mas[i] <<' ';

    return 0;
}
