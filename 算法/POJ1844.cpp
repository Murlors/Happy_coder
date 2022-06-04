/*
URL:http://poj.org/problem?id=1844
完成日期:2022.6.4
题目大意:给出一个数，你需要去寻找到一个最小的n，然后需要得出从1~n的和（可正可负）为该数
所用方法:数学题
*/
#include "iostream"
using namespace std;
int n, sum, i;
int main() {
    cin >> n;
    while (sum < n || (sum - n) % 2)
        sum += ++i;
    cout << i << "\n";
    return 0;
}