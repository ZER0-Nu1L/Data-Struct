---
E:\DeskTop\learn\基础理论层\Algorithm\2算法笔记\算法笔记.pdf
---

# 一、C++机试&算法竞赛

- 考虑到 C++的语法向下兼容 C，并且 C 的输入输出语句比 C++的要快很多，在算法竞赛中主体上使用 C 语言的语法；且 C++ 中有一些特性和功能非常好。
- 使用的代码请保存成 .cpp 文件（即C++文件），然后选择C++语言进行提交
- 而C++中大部分语法在机考中都是用不到的；

## 基础语法

### 头文件

在C++的标准中， stdio.h 更推荐使用等价写法： cstdio,
也就是在前面加一个C，然后去掉 h 即可。
`＃include <stdio.h>` 和`＃include <cstdio>` 是等价，
`＃include <math.h>` 和 `＃include <cmath>` 等价，
`＃include <string.h>` 和 `＃include <cstring>` 也等价。

### 数据类型

#### 布尔型

C++中又包括布尔型。

`bool` 取值包括 `0(false)` 和 `1(true)`。

布尔型在C++中可以直接使用，但在C 语言中必须添加stdbool.h 头文件才可以使用。

#### 整型

整型一般可以分为短整型(short) 、整型(int) 和长整型(long long)
<u>整型 int 也被称为long int</u>。

:warning: 绝对值在 $10^9$ 范围以内的整数都可以定义成int 型，超过范围的需要用 long long 型存储； 

注意：如果 long long 型赋大于 $2^{31-1}$ 的初值，则需要在初值后面加上LL, 否则会编译错误。

#### 浮点型

| 单精度float  | 6~7  位有效精度       | 32bit |
| ------------ | --------------------- | ----- |
| 双精度double | 有效精度有15  ~ 16 位 | 64bit |

％f 是 float 和 double 型的输出格式，％lf 是 double 型的输入格式
对浮点型来说，只需要记住一点，不要使用 float, 碰到浮点型的数据都应该用 double 来存储。

### 输入输出注意项

三种实用的输出格式
`%md`
使不足m 位的int 型变量以m 位进行右对齐输出，其中高位用空格补齐；如果变量本身超过m 位，则保持原样。
`%0md`
当变量不足m 位时，将在前面补足够数量的0 而不是空格。
`%.mf`
%.mf 可以让浮点数保留m 位小数输出，这个“保留“使用的是精度的“四舍六入五成
双“规则（具体细节不必掌握）
如果是四舍五入，那么需要用到 round 函数。

`getchar` 用来输入单个字符， `putchar` 用来输出单个字符，在某些 `scanf` 函数使用不便的场合可以使用 `getchar` 来输入字符。



`typedef long long LL;`



memset
int a[5]= {1, 2, 3, 4, 5};
／／赋初值0
memset(a, 0, sizeof (a));

# 二、C++ STL 介绍

> C++中为使用者提供了标准模板库(Standard Template Library, STL) ，其中封装了很多相当实用的容器（读者可以先把容器理解成能够实现很多功能的东西），不需要费力去实现它们的细节而直接调用函数来实很多功能，十分方便。

## 2.1 vector 常见详解

vector 向量，更适合理解成“变长数组”，长度根据需要而自动改变的数组。

```cpp
#include <vector>
using namespace std;
```

### 1. vector 的定义

```cpp
vector<typename> name;
```

相当千是一维数组 name[SIZE]，size 可以更具需要变化。

`typename` 也可以是 `vector<typename>`，定义的时候要记得在 `> >` 符号之间加上空格，因为一些使用C++11 之前标准的编译器会把它视为移位操作，导致编译错误。

```cp
vector<int> name;
vector<double> name;
vector<char> name;
vector<node> nae;
vector< vector<int> > nael;
```

vector 数组:

```cpp
vector<typename> Arrayname[arraySize];
```

这样 Arrayname[0] ~ Arrayname[arraySize - 1] 中每一个都是一个vector 容器。

注意：这种写法的一维长度已经固定为arraySize,

### 2. vector 容器内元素的访问

1. **通过下标访问**

   `vi[index]`

   下标是从0 到 `vi.size() -1`。

1. **通过迭代器访问**

   定义如下：

   ```cpp
   vector<typename>::iterator it;
   // e.g.
   vector<int>::iterator it;
   ```

   通过 `*it` 来访问 vector 里的元素。

```cpp
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
```

`begin()` 函数的作用为取 vi 的首元素地址；

`end()` 并不是取 vi 的尾元素地址，而是取尾元素地址的下一个地址。

> 作为迭代器末尾标志，不储存任何元素。左闭右开的思维习惯。

在常用STL 容器中，只有在 vector 和 string 中，才允许使用 `vi.begin()+3` 这种迭代器加上整数的写法。

**其他遍历方法：**

```cpp
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    vector<int> vi;
    for (int i = 1; i <= 5; i++) {
        vi.push_back(i);
    }
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {
        printf("%d ", *it);
    }
    return 0;
}
```

### 3. vector **常用函数实例解析**

#### 1. push_ back()

`push_back(x)` 就是在 vector 后面添加一个元素x, 时间复杂度为 O(1) 。

```cpp
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    vector<int> vi;
    for (int i = 1; i <= 3; i++) {
        vi.push_back(i);
    }
    for (int i = 0; i < vi.size(); i++) {
        printf("%d ", vi[i]);
    }
    return 0;
}
//123
```

#### 2. pop_back()

pop_back() 用以删除vector 的尾元素，时间复杂度为 O(1) 。

```cpp
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    vector<int> vi;
    for (int i = 1; i <= 3; i++) {
        vi.push_back(i);
    }
    vi.pop_back();
    for (int i = 0; i < vi.size(); i++) {
        printf("%d ", vi[i]);
    }
    return 0;
}
// 12
```

#### 3. size()

时间复杂度为O(1)，返回 unsigned 类型，说用 %d 不会出很大问题，这一点对所有 STL 容器都是一样的。

#### 4. clear()

来清空 vector 中的所有元素，时间复杂度为 O(N)；

#### 5. insert()

`insert(it, x)` 用来向 vector 的任意迭代器 it 处插入一个元素x , 时间复杂度 O(N) 。

> 从链表实现的角度，就能思考出它大概是插入到哪里的。

```cpp
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    vector<int> vi;
    for (int i = 1; i <= 5; i++) {
        vi.push_back(i);
    }
    vi.insert(vi.begin() + 2, -1);
    for (int i = 0; i < vi.size(); i++) {
        printf("%d ", vi[i]);
    }
    return 0;
}
// 1 2 -1 3 4 5
```

#### 6. erase()

1. 删除迭代器为 it 处的元素。

   ```cpp
   #include <stdio.h>
   #include <vector>
   using namespace std;
   int main() {
       vector<int> vi;
       for (int i = 5; i <= 9; i++) {
           vi.push_back(i);
       }
       vi.erase(vi.begin() + 3);
       for (int i = 0; i < vi.size(); i++) {
           printf("%d ", vi[i]);
       }
       return 0;
   }
   // 5679
   ```

1. 删除一个区间内的所有元素。（左开右闭）

   ```cpp
   #include <stdio.h>
   #include <vector>
   using namespace std;
   int main() {
       vector<int> vi;
       for (int i = 5; i <= 9; i++) {
           vi.push_back(i);
       }
       vi.erase(vi.begin() + 1, vi.begin() + 4);
       for (int i = 0; i < vi.size(); i++) {
           printf("%d ", vi[i]);
       }
       return 0;
   }
   // 删除vi(l] 、vi[2 ] 、vi[ 3]
   ```

### 4. vector 的常见用途

1. 数组
1. 用邻接表存储图

P208/493

### 5. 补充

`begin()` 方法返回一个当前vector容器中起始元素的迭代器；
`end()` 方法返回一个当前vector容器中末尾元素的迭代器。

`front()` 方法返回当前vector容器中起始元素的引用；
`back()` 方法返回当前vector容器中末尾元素的引用。

---

## 2.2 set 常见详解

一个内部自动有序且不含重复元素的容器。

实用价值：

1. 在考试中，有可能出现需要<font color="yellow">去掉重复元素</font>的情况，而且有可能因这些元素比较大或者类型不是 int 型而不能直接开散列表，在这种情况下就可以用 set 来保留元素本身而不考虑它的个数，

2. 且 set 提供了更为直观的接口，并且加入 set 之后可以实现自动排序，因此熟练使用 set 可以在做某些题时减少思维量。

```cpp
#include <map>
using namespace std;
```

### 1. set 的定义

> 其定义的写法其实和vector 基本是一样的，或者说其实大部分STL 都是这样定义的。

```cpp
set<typename> name;
```

### 2. set 容器内元素的访问

set 只能通过迭代器(iterator)访问：

```cpp
set<typename>::iterator it;
```

```cpp
#include <stdio.h>
#include <set>
using namespace std;
int main(){	//set中的元素自动递增排序，且自动去重复元素 
	set<int> st;
	st.insert(3);	//将insert(x)插入set中
	st.insert(5);
	st.insert(2);
	st.insert(3);
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		printf("%d",*it);
	} 
	return 0;
}
```

> 除开 vector 和 string 之外的STL 容器都不支持 `*(it+ i)` 的访问方式，

### 3. set 常用函数实例解析

#### 1. insert()

自动递增排序和去重，时间复杂度为 O(logN)

```cpp
setname.insert(x);
```

#### 2. find()

返回 set 中对应值为 value 的迭代器，

时间复杂度为 O(logN), 其中 N 为 set 内的元素个数。

```cpp
#include <stdio.h>
#include <set>
using namespace std;
int main() {
	set<int> st;
	for(int i=1;i<=3;i++){
		st.insert(i);
	}
	set<int>::iterator it = st.find(2);	//在set中查找2，返回迭代器
	printf("%d\n",*it);
	return 0;
}
```

#### 3. erase()

1. 删除单个元素。（参数为迭代器）

   `st.erase(it)`，时间复杂度为 O(1) ，可以结合 `find()` 函数来使用

   ```cpp
   #include <set>
   #include <stdio.h>
   using namespace std;
   int main() {
       set<int> st;
       st.insert(100);
       st.insert(200);
       st.insert(100);
       st.insert(300);
       st.erase(st.find(100));
       st.erase(st.find(200));
       for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
           printf("%d\n", *it);
       }
       return 0;
   }
   ```

1. 删除单个元素。（参数为要删除的元素值）

   `st.erase(value)`，时间复杂度为O(logN)

   ```cpp
   #include <stdio.h>
   #include <set>
   using namespace std;
   int main(){
   	set<int> st;
   	st.insert(100);
   	st.insert(200);
   	st.erase(100);	//删除set中值为100的元素
   	for(set<int>::iterator it=st.begin();it != st.end();it++){
   		printf("%d\n",*it);
   	} 
   	return 0;
   }
   ```

1. 删除一个区间内的所有元素。

   `st.erase(frrst, last)`，时间 复杂度为 O(last - first)。

   ```cpp
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
   ```

   #### 4. qit 

   begin(), end(), size(), clear();

   ### 4. set 的常见用途

   最主要的作用是自动去重并按升序排序，因此碰到需要去重但是却不方便直接开数组的情况，可以尝试用set 解决。

   如果需要处理不唯一的情况，则需要使用 multiset。

   另外，C++11 标准中还增加了unordered_set, 以散列代替set 内部的红黑树(Red Black Tree, 一种自平衡二叉查找树）实现，使其可以用来处理只去重但不排序的需求，速度比set 要快得多，

---

## 2.3 String 常用详解

在C 语言中， 一般使用字符数组 char str[] 来存放字符。

为了使编程者可以更方便地对字符串进行操作， C++在 STL 中加入了string 类型，对字符串常用的需求功能进行了封装，使得操作起来更方便，且不易出错。

```cpp
include<string>
using namespace std;
```

> 注意 string.h 和 string 是不一样的头文。

### 1. string 的定义

```cpp
string str = "abdc";
```

### 2. string 中内容的访问

1. 通过下标访问
   直接像字符数组那样去访问 string。

   如果要读入和输出整个字符串，则只能用 cin 和 cout

   如果用  `printf("%s", str)` 的话，需要用 `c_str()` 做类型转换（string -> char array）

   ```cpp
   #include <stdio.h>
   #include <string>
   using namespace std;
   int main() {
       string str = "abcd";
       printf("%s\n", str.c_str());
       return 0;
   }
   ```

1. 通过迭代器访问

   ```cpp
   #include <stdio.h>
   #include <string>
   using namespace std;
   int main() {
       string str = "abcd";
       for (string::iterator it = str.begin(); it != str.end(); it++) {
           printf("%c", *it);
       }
       return 0;
   }
   ```

   > string 和vector 一样，支持直接对迭代器进行加减某个数字

### 3. string 常用函数实例解析

#### 1. 加法拼接

#### 2. 比较

可以直接使用 ==、!=、<、<=、>、>= 比较大小，比较规则是字典序。

```cpp
#include <stdio.h>
#include <string>
using namespace std;
int main() {
    string str1 = "aa", str2 = "aaa", str3 = "abc", str4 = "xyz";
    if (str1 < str2)
        printf("ok1\n");
    if (str1 != str3)
        printf("ok2\n");
    if (str4 >= str3)
        printf("ok3\n");
    return 0;
}
```

#### 3. insert()

`insert()` 函数有很多种写法，这里给出几个常用的写法，时间复杂度为 O(N) 。

1. `insert(pos, string)`，在pos 号位置插入字符串 string
1. `insert(it, it2, it3)`，it 为原字符串的欲插入位置， it2 和 it3 为待插字符串的首尾迭代器，
   用来表示串[it2, it3)将被插在 it 的位置上。

#### 4.replace()

1. `str.replace(pos, len, str2)` 把 str 从 pos 号位开始、长度为 len 的子串替换为 str2
1. `str.replace(it1, it2, str2)` 把 str 的迭代器 [it1, it2) 范围的子串替换为 str2。
   时间复杂度为 O(str. length()) 。

#### 5. erase()

删除单个元素、删除一个区间内的所有元素。时间复杂度均为 O(N) 。

1. 删除单个元素

   `str.erase(it)`

1. 删除一个区间内的所有元素

   `str.erase(first, last)` | 删除[first, last)

#### 6. substr()

`substr(pos, len)` 返回从 pos 号位开始、长度为 len 的子串，时间复杂度为 O(len) 。

#### 7. string::npos

一个常数、其本身的值为 -1, 但由于是unsigned_int 类型，因此实际上也可以认为是unsigned_int类型的最大值。

#### 8.find()

`str.find(str2)`，当 str2 是 str 的子串时，返回其在 str 中第一次出现的位置；如果 str2 不是 str 的子串，那么返回 `string::npos`。

`str.find(str2, pos)`，从 str 的 pos 号位开始匹配 str2, 返回值与上相同。

时间复杂度为O(nm) ，其中 n 和 m 分别为 str 和 str2 的长度。

KMP 算法需要自己写！

#### 其他

length() == size()

clear()

---

## 2.4 map 常见详解

**数组的抽象**：一个double 型数组则是将 int 型映射到 double 型；

当需要以其他类型作为关键字来做映射时，会显得不太方便。

map 可以将任何基本类型（包括STL容器）映射到任何基本类型（包括STL 容器），

```cpp
#include <map>
using namespace std;
```

### 1. map 的定义

```cpp
map<typename1, typename2> mapname;
```

注意：

如果是字符串到整型的映射，必须使用string 而不能用 char 数组：

### 2. map 容器内元素的访问

1. **通过下标访问**

   ```cpp
   map<char,int> mp;
   mp['c'] = 20;
   printf("%d\n",mp['c']);
   ```

1. **通过迭代器访问**

   map 迭代器的使用方式和其他STL 容器的迭代器不同

   ```cpp
   map<typename1, typename2>::iterator it;
   ```

   map 可以使用 `it->first` 来访问键，使用 `it->second` 来访问值。

```cpp
#include <cstdio>
#include <map>
using namespace std;
int main() {
	map<char,int> mp;
	mp['m'] = 20;
	mp['r'] = 30;
	mp['a'] = 40;
	for(map<char,int>::iterator it = mp.begin(); it != mp.end();it++) {
		printf("%c %d\n", it->first, it->second);
	}
	return 0;
}
```

:star: 发现了一个很有意思的现象： map 会以键从小到大的顺序自动排序，这是由于 map 内部是使用红黑树实现的（set 也是）， 在建立映射的过程中会自动实现从小到大的排序功能。

### 3. vector **常用函数实例解析**

#### 1. find()

`find(key)` 返回键为 key 的映射的迭代器，时间复杂度为<font color="yellow">O(logN)</font>，N 为map 中映射的个数。

```cpp
#include <stdio.h>
#include <map>
using namespace std;
int main(){
	map<char,int> mp;
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	map<char,int>::iterator it = mp.find('b');
	printf("%c %d\n",it->first,it->second);
	return 0;
}
```

#### 2. erase()

有两种用法：删除单个元素、删除一个区间内的所有元素。

1. **删除单个元素**

   可以根据迭代器删除指定元素，也可以根据值删除指定元素

   - 方式一：

     `mp.erase(it)`，it 为需要删除的元素的迭代器。时间复杂度为 <font color="yellow">O(1)</font> 。

     ```cpp
     #include <stdio.h>
     #include <map>
     using namespace std;
     int main(){
     	map<char,int> mp;
     	mp['a'] = 1;
     	mp['b'] = 2;
     	mp['c'] = 3;
     	map<char,int>::iterator it = mp.find('b');
     	mp.erase(it);	//删除 b: 2
     	for(map<char,int>::iterator it = mp.begin();it != mp.end();it++){
     		printf("%c %d\n",it->first,it->second);
     	}
     	return 0;
     }
     ```

   - 方式二：

     `mp.erase(key)`，key 为欲删除的映射的键。
     时间复杂度为 <font color="yellow">O(logN)</font>，N 为 map 内元素的个数。

     ```cpp
     #include <stdio.h>
     #include <map>
     using namespace std;
     int main(){
     	map<char,int> mp;
     	mp['a'] = 1;
     	mp['b'] = 2;
     	mp['c'] = 3;
     	mp.erase('b');	//删除b 2 
     	for(map<char,int>::iterator it = mp.begin();it != mp.end();it++){
     		printf("%c %d\n",it->first,it->second);
     	}
     	return 0;
     }
     ```

1. **删除一个区间内的所有元素**

   `mp.erase(first, last) ` 左开右闭，first 为需要删除的区间的起始迭代器，而 last 则为需要删除的
   区间的末尾迭代器的下一个地址。

   时间复杂度为 <font color="yellow">O (last - first)</font>

   ```cpp
   #include <stdio.h>
   #include <map>
   using namespace std;
   int main(){
   	map<char,int> mp;
   	mp['a'] = 1;
   	mp['b'] = 2;
   	mp['c'] = 3;
   	map<char,int>::iterator it = mp.find('b');	//令it指向键为b的映射 
   	mp.erase(it,mp.end());	//删除b 2 
   	for(map<char,int>::iterator it = mp.begin();it != mp.end();it++){
   		printf("%c %d\n",it->first,it->second);
   	}
   	return 0;
   }
   ```

#### 3. size()

map 中映射的对数，时间复杂度为 O(1) 。

#### 4. clear()

清空 map 中的所有元素。

### 4. map 常见用途

1. 需要建立字符（或字符串）与整数之间映射的题目
1. 判断大整数或者其他类型数据是否存在的题目
1. 字符串和字符串的映射

延伸： map 的键和值是唯一的，而如果一个键需要对应多个值，就只能用multimap 。

另外， C++11 标准中还增加了unordered_map, 以散列代替map 内部的红黑树实现，使其可以
用来处理只映射而不按key 排序的需求，速度比map 要快得多，有兴趣的读者可以自行了解，
此处不多作说明。

---

## 2.5 queue

一种先进先出的限制性数据结构.

```cpp
#include<queue>
using namespace std;
```

### 1. queue 的定义

```cpp
queue<typename> name;
```

### 2. queue 容器内元素的访问

只能通过 `front()` 来访问队首元素，或是通过 `back()` 来访问队尾元素。

### 3. queue 常用函数实例解析

1. push()
1. front(), back()
1. pop()
1. empty()
1. size()

### 4. queue 的常见用途

当需要实现广度优先搜索时，可以不用自己手动实现一个队列，而是用queue 作为代替，以提高程序的准确性。

另外有一点注意的是，使用 `front()` 和 `pop()` 函数前，必须用 `empty()` 判断队列是否为空，否则可能因为队空而出现错误。



双端队列(deque)：首尾皆可插入和删除的队列

优先队列(priority _ queue)：使用堆实现的默认将当前队列最大元素置于队首的容器。 | 将在6.6 节进行介绍



---

## 2.7 stack

不介绍了吧



---

# 三、algorithm 头文件下的常用函数

## 1. max(), min()

## 2. swap(x, y)

## 3. reverse()

   `reverse(it, it2)` 可以将 <u>数组指针</u> 在 [it, it2) 之间的元素或 <u>容器的迭代器</u> 在 [it, it2) 范围内的元
   素进行反转。

   ```cpp
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
   ```

## 4. next_pennutation()

## 5. fill()

可以把数组或容器中的某一段区间赋为某个相同的值。

> 和memset 不同，这里的赋值可以是数组类型对应范围中的任意值。

```cpp
#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    fill(a, a + 5, 233);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
```

## 6. sort()

一般来说，不推荐使用 C 语言中的 qsort 函数。

原因是 qsort 用起来比较烦琐，涉及很多指针的操作。而且 sort 在实现中规避了经典快速排序中可能出现的会导致实际复杂度退化到 O(n^2) 的极端情况。

### 排序对象

对char 型数组排序（默认为字典序）

在STL 标准容器中，只有 vector、string、deque 是可以使用 sort 的。

### cmp

1. 不同类型的数组

   ```cpp
   #include <algorithm>
   #include <stdio.h>
   using namespace std;
   bool cmp(int a, int b) {
       return a > b;
   }
   int main() {
   	// int a[] = {'T', 'D', 'A', 'K'};
       // double a[] = {9, 1.4, -2.1, 5.6, -1};
       int a[] = {9, 4, 2, 5, 6, -1};
       sort(a, a + 4, cmp);
       for (int i = 0; i < 4; i++) {
           printf("%d ", a[i]);
       }
       return 0;
   }
   ```

1. 结构体

   ```cpp
   #include <algorithm>
   #include <stdio.h>
   using namespace std;
   struct node {
       int x, y;
   } ssd[10];
   bool cmp1(node a, node b) {
       return a.x > b.x;
   }
   bool cmp2(node a, node b) {
       if (a.x != b.x)
           return a.x > b.x;
       else
           return a.y < b.y;
   }
   int main() {
       ssd[0].x = 2;
       ssd[0].y = 2;
       ssd[1].x = 1;
       ssd[1].y = 3;
       ssd[2].x = 3;
       ssd[2].y = 1;
       sort(ssd, ssd + 3, cmp1);
       for (int i = 0; i < 3; i++) {
           printf("%d %d\n", ssd[i].x, ssd[i].y);
       }
       return 0;
   }
   ```

   3. 容器

      ```cpp
      #include <algorithm>
      #include <stdio.h>
      #include <vector>
      using namespace std;
      bool cmp(int a, int b) {
          return a > b;
      }
      int main() {
          vector<int> vi;
          vi.push_back(3);
          vi.push_back(1);
          vi.push_back(2);
          sort(vi.begin(), vi.end(), cmp);
          for (int i = 0; i < 3; i++) {
              printf("%d ", vi[i]);
          }
          return 0;
      }
      ```

## 7. lower_bound() 和 upper...... bound()

需要用在一个有序数组或容器中。

`lower_bound(first, last, val)` 用来寻找在数组或容器的 [first, last) 范围内第一个值大于等于 val 的元素的位置，如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器。
`upper_bound(first, last, val)` 用来寻找在数组或容器的 [first, last) 范围内第一个值大大 val 的元素的位置，如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器。



如果数组或容器中没有需要寻找的元素，则lower_bound() 和upper_bound() 均返回可以插入该元素的位置的指针或迭代器。

复杂度均为 O(log(last - first))。

用对分查找实现的。



----

# C++ 语法补充

## 结构体构造函数使用总结

## nullptr

### 一、C程序中的NULL

在C语言中，NULL通常被定义为：<font color="yellow">`#define NULL ((void *)0)`</font>

所以说 NULL 实际上是一个空指针，如果在 C 语言中写入以下代码，编译是没有问题的，因为在C语言中把空指针赋给 int 和 char 指针的时候，发生了隐式类型转换，把 void 指针转换成了相应类型的指针。

```c
int  *pi = NULL;
char *pc = NULL;
```

### 二、C++程序中的NULL

但是问题来了，以上代码如果使用C++编译器来编译则是会出错的，因为C++是<font color="yellow">强类型语言</font>，void*是<font color="yellow">不能隐式</font>转换成其他类型的指针的，所以实际上编译器提供的头文件做了相应的处理：

```cpp
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
```

但是实际上，为了保全这“强类型语言”的特性，<u>用NULL代替0表示空指针在函数重载时会出现问题</u>。

问题举例如下：

```cpp
#include <iostream>
using namespace std;
void func(void* t) {
	cout << "func（ void* ）" << endl;
}
void func(int i) {
	cout << "func（ int ） " << endl;
}
int main(void) {
	func(NULL);
	func(nullptr);
	system("pause");
	return 0;
}
```

![img](https://img-blog.csdnimg.cn/20190822192543549.png)

我们本来是想用NULL来代替空指针，但是在将NULL输入到函数中时，它却选择了int形参这个函数版本，所以是有问题的，这就是用NULL代替空指针在C++程序中的二义性。

为解决NULL代指空指针存在的二义性问题，在C++11版本(2011年发布)中特意引入了nullptr这一新的关键字来代指空指针，从上面的例子中我们可以看到，使用nullptr作为实参，确实选择了正确的以void*作为形参的函数版本。

Refer: https://blog.csdn.net/reasonyuanrobot/article/details/100022574?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param