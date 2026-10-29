#include<iostream>
#include<vector>
using namespace std;

void lpsTable(vector<int> &lps, string pattern){
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while(i< pattern.length()){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len - 1];
            }else{
                i++;
            }
        }
    }
}

void KMP(string text, string pattern){
    int n = text.length();
    int m = pattern.length();

    if(m == 0){
        cout << "Pattern is empty so no match will be found";
        return;
    }
    vector<int> lps(m, 0);
    lpsTable(lps, pattern);

    int i = 0;
    int j = 0;
    bool found = false;
    while (i<n)
    {
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            cout << "Pattern match found at index: " << i - j<<endl;
            found = true;
            j = lps[j-1];
        }else if(i< n && text[i] != pattern[j]){
            if(j!=0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }

    if(!found){
        cout << "Pattern doesn't found in text";
        return;
    }
}

int main(){
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    KMP(text, pattern);
    return 0;
}