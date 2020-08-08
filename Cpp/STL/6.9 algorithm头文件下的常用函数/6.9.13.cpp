#include <algorithm>
#include <stdio.h>
using namespace std;
bool cmp(char a, char b) { return a > b; }
int main() {
    int a[] = {'T', 'D', 'A', 'K'};
    sort(a, a + 4, cmp); //��a[0]~a[3]�Ӵ�С����
    for (int i = 0; i < 4; i++) {
        printf("%c", a[i]);
    }
    return 0;
}
