#include <algorithm>
#include <stdio.h>
using namespace std;
bool cmp(double a, double b) {
    return a > b; //�� a > b ʱ���� a ���� b ��ǰ��
}
int main() {
    double a[] = {9, 1.4, -2.1, 5.6, -1};
    sort(a, a + 4, cmp); //��a[0]~a[3]�Ӵ�С����
    for (int i = 0; i < 4; i++) {
        printf("%.1lf ", a[i]);
    }
    return 0;
}
