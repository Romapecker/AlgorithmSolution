// �����������1�ĸ��� 
int numberOfOnes(int x) {
    int cnt = 0;
    while (x) {
        x = x & (x-1);
        cnt++;
    }
    return cnt;
}
//
bool isPowerOfFour(int num) {
    if (num < 0) return false;
    // ��֤�������н���һ��1������1�������2,4,6,8,10���� 
    if (numberOfOnes(num) == 1 && numberOfOnes(num-1) % 2 == 0) return true;
    else return false;
}
