#include <iostream>
using namespace std;

pair<int, int> M[10001]; 

pair<int,int> HSM(int i,int m, int n) {
    if(i < 0) return {0, 1e7}; 
    if(i < min(m, n)) return {0, i}; 
    else{
      if(M[i].second == -1) {
        pair<int,int> Hm = HSM(i - m, m, n); 
        Hm.first++;
        pair<int,int> Hn = HSM(i - n,m, n); 
        Hn.first++;
    
        if(Hm.second != Hn.second) {
            M[i] = {Hm.second < Hn.second ? Hm.first : Hn.first, Hm.second < Hn.second ? Hm.second : Hn.second};
        } else {
            M[i] = {Hm.first > Hn.first ? Hm.first : Hn.first, Hm.second};
        }
      }
      return M[i];
    }
}

int main() {
    int m, n, t;
    while(cin >> m >> n >> t) {
        for (int i = 0; i <= t; i++) {
            M[i] = {0, -1}; 
        }
        
        pair<int,int> resultado = HSM(t,m,n);
        if(resultado.second == 0) {
            cout << resultado.first << endl;
        } else {
            cout << resultado.first << " " << resultado.second << endl;
        }
    }
    return 0;
}