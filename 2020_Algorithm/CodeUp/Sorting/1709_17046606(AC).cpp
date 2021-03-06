﻿#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++)
        cin>>v[i];
        
    sort(v.begin(), v.end(), greater<int>());
    
    for(int num : v)
        cout<<num<<' ';
    
    return 0;
}
