#include <iostream>
#include <fstream>

using namespace std;
    int main() {
    int ramzer;
    ifstream file ("sortland.in");
    file >> ramzer;
    float p;
    float mas[ramzer+1];
    float mas2[ramzer+1];
    for (int i=1;i<ramzer+1;i++){
        file >> p;
        mas[i]=p;
        mas2[i]=p;
    }
    float q;
    for (int i=1;i<=ramzer;i++){
        for(int j=i;j<=ramzer;j++){
            if (mas[i]>mas[j]){
                q=mas[i];
                mas[i]=mas[j];
                mas[j]=q;
            }
        }
    }
    float min = mas[1];
    float max = mas [ramzer];
    float midl = mas[(ramzer+1)/2];
    int minn,maxx,midll;
    for (int i=1;i<ramzer+1;i++){
        if(mas2[i]== min)
        minn=i;
        if(mas2[i]== max)
        maxx=i;
        if(mas2[i]== midl)
        midll=i;
    }
        ofstream fileout ("sortland.out");
    fileout << minn << ' ' << midll << ' ' << maxx;
    return 0;
}
