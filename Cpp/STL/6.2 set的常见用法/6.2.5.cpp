#include <set>
#include <stdio.h>
using namespace std;
int main() {
    set<int> st;
    st.insert(20);
    st.insert(10);
    st.insert(40);
    st.insert(30);
    set<int>::iterator it = st.find(30);
    st.erase(it, st.end());
    for (it = st.begin(); it != st.end(); it++) {
        printf("%d\n", *it);
    }
    return 0;
}
