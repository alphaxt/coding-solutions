# Valid Palindrome 57

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string S.

Determine whether S is a palindrome.

The comparison should be case-sensitive, and every character should be considered.

Print YES if the string is a palindrome; otherwise, print NO.

 **Input Format** 

The first line contains a string S.

 **Constraints** 

1 ≤ |S| ≤ 2 × 10^5

S contains lowercase and uppercase English letters and digits.

 **Output Format** 

Print YES if S is a palindrome.

Otherwise, print NO.

 **Sample Input 0** 

```
bob

```

 **Sample Output 0** 

```
YES

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-15T21:46:21.604Z  

```cpp
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

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/valid-palindrome-57/problem)