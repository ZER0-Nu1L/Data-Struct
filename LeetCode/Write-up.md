# Error

## 错误提示：load of null pointer of type 'const int'

在调用函数时，如果返回值如果是一个常量则没问题；
如果返回值若为指针则可能会出现该错误，假如返回的指针地址指向函数内的局部变量，在函数退出时，该变量的存储空间会被销毁，此时去访问该地址就会出现这个错误。

解决办法有以下三种:

1. 返回的指针使用 malloc 分配空间（推荐）
2. 将该变量使用 static 修饰 static 修饰的内部变量作用域不变 但是声明周期延长到程序结束 即该变量在函数退出后仍然存在；
3. 使用全局变量（不推荐）

```C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 不看题目注释，吃亏在眼前！
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *answer = (int *)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i+1; j < numsSize; j++) {
            if(nums[i]+nums[j] == target) {
                answer[0] = i;
                answer[1] = j;
                *returnSize = 2;
                return answer;
            }
        }
    }
    return answer;
}
```

# Write Up

## 1. 两数之和

### 暴力

时间复杂度：$O(n^2)$， 空间复杂度 $O(1)$。

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
```

### 两遍哈希

一种更有效的方法来检查数组中是否存在目标元素。如果存在，我们需要找出它的索引。保持数组中的每个元素与其索引相互对应的最好方法是什么？哈希表。

以空间换取速度。

时间复杂度：$O(n)$， 空间复杂度 $O(n)$。

第一次迭代中，我们将每个元素的值和它的索引添加到表中。

在第二次迭代中，我们将检查每个元素所对应的目标元素  $target - nums[i]$是否存在于表中。:warning: 注意，该目标元素不能是 nums[i] 本身！

没有考虑就会出现：

<img src="Write-up/image-20200717010328879.png" alt="image-20200717010328879" style="zoom:67%;" />

```cpp
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> result;
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> HashMap;
        // 1. set up HashMap
        for(int i = 0; i < nums.size(); i++) {
            HashMap[nums[i]] = i;
        }
        // 2. find
        for(int i = 0; i < nums.size(); i++) {
            if(HashMap.count(target-nums[i])>0 && i != HashMap[target-nums[i]]) {
                result.push_back(i);
                result.push_back(HashMap[target - nums[i]]);
                return result;
            }
        }
        return result;
    }
};
```

p.s. map 查找不到对应的键的表示方法：

1. find 的返回迭代器为空，注意不是 null。

   map中有一个函数叫 end()，这个函数默认指向 map 中最后一个元素的后一个位置，由此可以理解为空。

   所以，如果非要对 iterator 进行初始化的话，可以将 iterator 指向 end() 函数即可。判断是否为空即与end() 函数做比较即可。

   ```cpp
   map<int, int> Map01;
   map<int, int>::iterator Map_it = Map01.end();
   Map_it.find(num)
   if (it != mymap.end())
       //...
   ```

2. 在 LeetCode 的题解中找到更有趣更简练的方法：

   ```cpp
   map<int, int> Map01;
   if( Map01.count(num) > 0)
       //..
   ```

### 一遍哈希

实证明，我们可以一次完成。在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。

```cpp
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> HashMap;
        for(int i = 0; i < nums.size(); i++) {
            if(HashMap.count(target-nums[i]) > 0) { // 条件少了一个
↑               result.push_back(HashMap[target-nums[i]]);
↓               result.push_back(i); // 注意调换顺序！
                return result;
            }
↕           HashMap[nums[i]] = i;
        }
        return result;
    }
};
```

> 作者：LeetCode
> 链接：https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/
> 来源：力扣（LeetCode）
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## 283.移动零.c

思路1

// 1. for, if zero, move

```cpp
void moveZeroes(int* nujs, int numsSize) {
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) {
            for(int j = i; j < numsSize-1; j++) {
                nums[j] = nums[j+1]；
            }
            nums[numsSize-1] = 0;
        }
    }
}
```

Submit 遇到问题：

![image-20200713165532513](Write-up/image-20200713165532513.png)

<font color="yellow">反思</font>：在脑海里动态地考虑这个问题

如果改成：

```cpp
void moveZeroes(int* nujs, int numsSize) {
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) {
            for(int j = i; j < numsSize-1; j++) {
                nums[j] = nums[j+1]；
            }
            nums[numsSize-1] = 0;
+           i--;
        }
    }
}
```

遇到连续的 0 就会将进入死循环。

// 不要抢救！换思路！

```cpp
void moveZeroes(int* nums, int numsSize) {
    int num_0 = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) {
            num_0++;
        }
    }
    for(int i = 0; i < numsSize; i++) {
        if(num_0 == 0)
            break;
        if(nums[i] == 0) {
            for(int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j+1];
            }
            i--;
            nums[numsSize-1]=0;
            num_0 --;
        }
    }
}
```


## 26.删除排序数组中的重复项
// 1. for i for j  if == move? 
// 优化：对重复个数进行计数——一次性移动
```Cpp
int removeDuplicates(int* nums, int numsSize)
{
    int time = 0;
    for(int i = 0; i < numsSize - 1; i++) {
        time = 1;   //代表一个元素出现的次数
        for(int j = i+1; j < numsSize; j++) {
            if(nums[i] == nums[j]) {
                time++;
            } else {
                break;
            }
        }
        // time 次出现，需要移动 time-1 格，~~移动次数 = 后面的个数 = numsSize-i-time-1~~
        if(time > 1) {
            // numsSize = xxx + j + time - 1
            for(int j = i+1; j < numsSize-time+1; j++) {
                nums[j] = nums[j+time-1];
            }
        }
        numsSize = numsSize - time + 1;
    }
    return numsSize;
}
```

官方题解：双指针法
```cpp
int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0) return 0;
    int i = 0;
    for(int j = 1; j < numsSize; j++) {
        if(nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];            
        }
    }
    return (i+1);
}
```
用 j 带动 i 移动，厉害的！

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;  // 注意这个处理! nums.empty() 好用啊
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};
```