#include <bits/stdc++.h>
using namespace std;

int main(){
    long long unsigned n;
    while(cin >> n){
        long unsigned max = ((long unsigned) sqrt(n)) + 1;
        bool flag = false;
        for(long unsigned i = max; i > 0;i--){
            for(long unsigned j = 1; j < max;j++){
                if(flag) break;
                else if(pow(i, 2) + pow(j, 2) == n){
                    cout << "1" << endl;
                    flag = true;
                    break;
                }
            }   
        }
        if(!flag) cout << "0" << endl;
    }
}