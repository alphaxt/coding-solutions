#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin>> s;
    
    bool ispal = true;
    int left = 0;
    int right = s.size() - 1;
    
    while(left < right){
        if(s[left] != s[right]){
            ispal = false;
            break;
        }
        left++;
        right--;
    }
    if(ispal){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
