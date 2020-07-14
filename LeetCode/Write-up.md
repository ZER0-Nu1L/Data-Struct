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


# 26.删除排序数组中的重复项
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