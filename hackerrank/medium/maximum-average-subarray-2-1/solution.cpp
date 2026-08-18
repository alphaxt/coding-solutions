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
