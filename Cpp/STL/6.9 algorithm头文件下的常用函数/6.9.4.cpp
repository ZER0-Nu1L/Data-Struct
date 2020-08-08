#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
int main() {
    string str = "abcdefghi";
    reverse(str.begin() + 2, str.begin() + 6);
    for (int i = 0; i < str.length(); i++) {
        printf("%c", str[i]);
    }
    return 0;
}
