#include <algorithm>
#include <cstdio>
#include <vector>

#define TEST_1 0
#define TEST_2 1
using namespace std;
int main(void) {
    // int an[5][2] = {
    //     {1,3}, {2,6}, {8,10}, {15,18}
    // };

#if TEST_1
    // One
    vector<vector<int>> vec;
    vector<int> ab;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);
    vec.push_back(a);
    vec.push_back(b);

    printf("%llu\n", vec.size()); // 2

    // Two
    //得到一个5行3列的数组
    int i, j;
    vector<vector<int>> array(5);
    for (i = 0; i < array.size(); i++)
        array[i].resize(3); //由vector实现的二维数组，可以通过resize()的形式改变行、列值

    for (i = 0; i < array.size(); i++) {
        for (j = 0; j < array[0].size(); j++) {
            array[i][j] = (i + 1) * (j + 1);
        }
    }
#endif

#if TEST_2
    vector<int> vi(4);
    vi[2] = 1;
    printf("%d\n", vi[2]);
#endif
    getchar();
    return 0;
}
