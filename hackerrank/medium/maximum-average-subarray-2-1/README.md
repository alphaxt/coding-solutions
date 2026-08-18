# Maximum Average Subarray 2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array A of size N and an integer K.

Find the contiguous subarray containing exactly K elements that has the maximum average.

Print the maximum average rounded to 6 decimal places.

 **Input Format** 

The first line contains two integers:

N K

The second line contains N space-separated integers:

A1 A2... AN

 **Constraints** 

1 ≤ K ≤ N ≤ 2 × 10^5 -10^4 ≤ Ai ≤ 10^4

 **Output Format** 

Print the maximum average rounded to exactly 6 decimal places.

 **Sample Input**  6 4 1 12 -5 -6 50 3

 **Sample Output**  12.750000 Explanation

 **The subarray:**  -6 50 3

 **Sample Input 0** 

```
6 4
1 12 -5 -6 50 3

```

 **Sample Output 0** 

```
12.750000

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-18T00:33:28.764Z  

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int s, k;
    cin >> s >> k;
    vector<long long> n(s);
    
    for(int i=0; i<s; i++){
        cin>> n[i];
    }   
    
    long long windowsum = 0;
    
    for(int i=0;i<k ; i++){
        windowsum += n[i];
    }
    
    long long maxsum = windowsum;
    
    for(int i = k; i<s ; i++){
        windowsum += n[i];
        windowsum -= n[i - k];
        
        maxsum = max(maxsum, windowsum);
    }
    
    double maxaverage = (double)maxsum / k;
    
    cout<< fixed << setprecision(6) << maxaverage << endl;
    
    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/maximum-average-subarray-2-1/problem)