#include <bits/stdc++.h>
using namespace std;

int m, n;
int N2[101];
int N1[101];
int M[101][101];

int TGM(int i, int j) {
    if (i == 0 || j == 0) 
        return 0;   
    else{
        if(M[i][j] == -1){
            if (N1[i-1] == N2[j-1]) {
                M[i][j] = 1 + TGM(i-1, j-1);
            } else {
                M[i][j] = max(TGM(i-1, j), TGM(i, j-1));
            }
        }
    }
    return M[i][j];
}

int main() {
    int caso = 1;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) 
            break;
		memset ( M, -1, sizeof ( M ) );
        for (int i = 0; i < m; i++) {
            cin >> N1[i];
        }
        for (int j = 0; j < n; j++) {
            cin >> N2[j];
        }
        int result = 0;
        result += TGM(m, n);
        cout << "Twin Towers #" << caso << endl;
        cout << "Number of Tiles : " << result << endl;
        cout << "\n";
        caso++;
    }
    return 0;
}