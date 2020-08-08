#include <algorithm>
#include <stdio.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int a[] = {9, 4, 2, 5, 6, -1};
    sort(a, a + 4, cmp);
    for (int i = 0; i < 4; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
