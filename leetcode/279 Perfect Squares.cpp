// ��̬�滮
// �� F(n) = ����ȫƽ�����ͱ�ʾn����Ҫ��������ȫƽ����
// ���Ȼ����ȫƽ����x, F(n-x) + 1 = F(n)
// �������е�x��ȡ��Сֵ����
// ��Ϊ���������n������n��1��ʾ�����Գ�ֵ����ΪF(n) = n;
int numSquares(int n) {
    vector<int> F(n+1, 0);
    // init values
    for (int i = 0; i <= n; ++i) F[i] = i;

    // bottom to up
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            int x = j * j;
            F[i] = min(F[i], 1 + F[i-x]);
        }
    }

    return F[n];

}
