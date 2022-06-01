/*
URL:http://poj.org/problem?id=2454
完成日期:2022.6.1
题目大意:给定3*k个数字，分为3组，至少让两组中数字的和大于500*k
所用方法:贪心,随机化算法(LasVegas,拉斯维加斯算法)
*/
#include "iostream"
#include "algorithm"
using namespace std;
int k,sum1,sum2,r1,r2;
struct cow {
    int value, id;
    bool operator<(const cow &b) const {
        return value > b.value;
    }
}arr[200];
int main() {
    cin >> k;
    for (int i = 0; i < 3 * k; ++i)
        cin >> arr[i].value, arr[i].id = i + 1;
    sort(arr, arr + 3 * k);
    for (int i = 0; i < k; ++i)
        sum1 += arr[i].value, sum2 += arr[k + i].value;
    while (sum1 <= 500 * k || sum2 <= 500 * k) {
        r1 = rand() % k, r2 = rand() % k + k;
        sum1 += -arr[r1].value + arr[r2].value;
        sum2 += arr[r1].value - arr[r2].value;
        swap(arr[r1], arr[r2]);
    }
    for (int i = 0; i < 3 * k; ++i)
        cout << arr[i].id << "\n";
    return 0;
}