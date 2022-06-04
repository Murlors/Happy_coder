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