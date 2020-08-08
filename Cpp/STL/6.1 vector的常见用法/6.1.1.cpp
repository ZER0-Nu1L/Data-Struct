/*向量的常见方法详解*/
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    vector<int> vi; // *(vi.begin()+i)等价于vi[i]
    for (int i = 1; i <= 5; i++) {
        vi.push_back(i);
    } // vi.begin()为取vi的首元素地址，而 it 指向这个地址
    vector<int>::iterator it = vi.begin();
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(it + i)); //输出
    }
    return 0;
}
