#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Station
{
    double price_;
    double dist_;
public:
    bool operator< (const Station& other) const
    {
        return dist_ < other.dist_;
    }
};

int FindNextStation(double canRunDist, int curStation, const vector<Station>& v)
{
    int ans = -1;
    for (int i = curStation + 1; i < v.size(); ++i)
    {
        if (v[i].dist_ <= canRunDist && v[i].price_ < v[curStation].price_)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

double cmax, D, Davg;
int N;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> cmax >> D >> Davg >> N;
    vector<Station> v(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%lf %lf", &v[i].price_, &v[i].dist_);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i)
    {
        cout << "v[" << i << "]:" << v[i].dist_  << "\t" << v[i].price_<< endl;
    }

    /*
    if (v[0].dist_ == 0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    */

    double ans = 0.0;

    double curDist = 0;
    double curGas = 0;
    int curStation = 0;
    int nextStation = 0;
    double curCanRun = (curGas + 0.0) / (Davg + 0.0) + curDist;
    double longestRun = cmax * Davg;

    while (true)
    {
        // �����ǰ�����ܹ������յ㣬�������󣬷���
        if (curCanRun >= D)
        {
            printf("%.2f\n", ans);
            return 0;
        }

        // �����ǰ�����������ܵ�����ڵ���һվ����ô���������󷵻�
        if (curCanRun < v[nextStation].dist_)
        {
            printf("The maximum travel distance = %.2f\n", curCanRun);
            return 0;
        }
        //�����ǰ�����ܹ���ʹ��һ�������˵ļ���վ��then����ʻ����˵
        else if ((nextStation = FindNextStation(curCanRun, curStation, v)) != -1)
        {
            curDist = v[nextStation].dist_;
            curGas -= (v[nextStation].dist_ - v[curStation].dist_) /(Davg + 0.0);
            curStation = nextStation;
            curCanRun = curGas * Davg;
        }
        // �����һЩ���ܹ���������˵ļ���վ��then��һЩ
        else if ((nextStation = FindNextStation(curDist+longestRun, curStation, v)) != -1)
        {
            double tmpDist = v[nextStation].dist_ - v[curStation].dist_;
            double allNeedGas = tmpDist / (Davg + 0.0);
            ans += v[curStation].price_ * (allNeedGas - curGas);
            curGas = 0;
            curDist = v[nextStation].dist_;
            curStation = nextStation;
            curCanRun = 0;
        }
        // ������ܼӶ����ж����ܵ�������˵ļ���վ, ������, �����������վ������˵�һ��
        else if (nextStation == -1)
        {
            double minPrice = 1E9;
            for (int i = curStation + 1; i < v.size(); ++i)
            {
                if (v[i].dist_ <= curDist + longestRun && v[i].price_ < minPrice)
                {
                    minPrice = v[i].price_;
                    nextStation = i;
                }
            }
            ans += (cmax - curGas) * v[curStation].price_;
            curGas = cmax - (v[nextStation].dist_ - v[curStation].dist_) / (Davg+0.0);
            curStation = nextStation;
            curDist = v[nextStation].dist_;
            curCanRun = curGas * Davg;
        }

    }

    return 0;
}
