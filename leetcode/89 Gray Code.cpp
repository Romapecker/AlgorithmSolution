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

// �����͹��죬ÿ���ǵ�ǰ����Ԫ��ȡ������һ����λ0ȫ����Ϊ1�Ľ��
// 00
// --
// 01
// --
// 01
// 10
// --
vector<int> grayCode(int n) {
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < n; ++i) {
        int sz = (int)v.size();
        for (int j = sz - 1; j >= 0; --j) {
            int x = v[j];
            int new_x = x ^ (1 << i);
            v.push_back(new_x);
        }
    }
    return v;
        
}