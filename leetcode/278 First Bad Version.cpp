#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

bool isBadVersion(int version);

/**
 * �൱��ʵ��lower_bound
 * ע��߽����������������ѭ��
 */
int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    if (left == right) {
        if (isBadVersion(left)) {
            return left;
        } else {
            return 0;
        }
    }
            
    return 0;
}