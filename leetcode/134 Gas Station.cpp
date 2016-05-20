#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

// ̰���㷨�������A���ܵ���B�����(A,B)֮����κ�λ��Ҳ��Ȼ���ܵ���B
// �Ӷ��ܹ���ԾʽԾ������O(N^2)���㷨����ΪO(N)���㷨
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if (gas.empty() || cost.empty()) return -1;
        
    int n = gas.size();
    vector<int> diff(n, 0);
    for (int i = 0; i < n; ++i) diff[i] = gas[i] - cost[i];
        
    for (int start = 0; start < n; ) {
        if (diff[start] < 0) {
            start++;
        } else {
            int r = diff[start];
            int j = (start + 1) % n;
            while (j != start && r + diff[j] >= 0 ) {
                r += diff[j];
                j = (j+1) % n;
            }
                
            if (j == start) {
                return start;
            } else {
                start = (j < start ? n : j); // �����һ��λ����startǰ�棬�����Ѿ��жϹ����У�����ֱ����start=n������start < j,��start = j;
            }
                
        }
    }
    return -1;      
}