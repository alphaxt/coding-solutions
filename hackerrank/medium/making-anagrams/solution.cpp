#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
    int feq[26] = {0};
    
    for(auto x : s1){
        feq[x - 'a']++;
    }
    for(auto x : s2){
        feq[x - 'a']--;
    }
    
    int del = 0;
    
    for(int i=0; i<26; i++){
        del += abs(feq[i]);
    }
    return del;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
