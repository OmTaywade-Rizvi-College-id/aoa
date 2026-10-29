#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string X, Y;
    cout << "Enter the string 1: ";
    cin >> X;
    cout << "Enter the string 2: ";
    cin >> Y;

    int n = X.length();
    int m = Y.length();

    vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(X[i-1] == Y[j-1]){
                d[i][j] = 1 + d[i - 1][j - 1];
            }else{
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    cout << "\nThe length of the lcs is: " << d[n][m];

    string lcs = "";
    int i = n;
    int j = m;
    while(i> 0 && j> 0){
        if(X[i-1] == Y[j-1]){
            lcs += X[i - 1];
            i--;
            j--;
        }else if(d[i-1][j]>= d[i][j]){
            i--;
        }else{
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    cout << "\nlsc string is: " << lcs;
    return 0;
}
