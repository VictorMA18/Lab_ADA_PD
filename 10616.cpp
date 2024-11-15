#include <bits/stdc++.h>
using namespace std;

int n, m, d, q, set_num; 
int numeros[201];
int M[201][201][20];

int DGSM(int i, int m, int sum){
    if (m == 0) {
        if(sum % d == 0){
          return 1;
        }else{
          return 0;
        }
    }
    if (i == 0) return 0;
    else{
      int mod_sum = (sum % d + d) % d; 
      if(M[i][m][mod_sum] == -1){
        M[i][m][mod_sum] = DGSM( i - 1, m - 1, sum + numeros[i - 1]) + DGSM( i - 1, m, sum);
      }
      return M[i][m][mod_sum];
    }
}

int main() {   
    set_num = 1;
    while (true) {
        cin >> n >> q;
        
        if (n == 0 && q == 0) break; 
        
        for (int i = 0; i < n; i++) {
            cin >> numeros[i];
        }
        
        cout << "SET " << set_num << ":\n";
        set_num++;

        for (int t = 0; t < q; t++) {
            cin >> d; cin >> m;
            memset ( M, -1, sizeof ( M ) );
            int result = DGSM(n, m, 0);
            cout<< "QUERY " << (t+1) << ": " << result << "\n";
        }
    }
    return 0;
}