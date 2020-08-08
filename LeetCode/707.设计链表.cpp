/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 *
 * https://leetcode-cn.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (28.03%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 91.6K
 * Testcase Example:
 * '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\r\n[[],[1],[3],[1,2],[1],[1],[1]]\r'
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
 * 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是
 * 0-index 的。
 *
 * 在链表类中实现这些功能：
 *
 *
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val 
 * 的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index
 * 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 *
 *
 *
 *
 * 示例：
 *
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 * linkedList.get(1);            //返回2
 * linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 * linkedList.get(1);            //返回3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 *
 *
 */

// @lc code=start
class MyLinkedList {
  private:
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };
    int _size;
    LinkedNode *_dummyHead; // 虚拟头部 index 其实相当于 -1

  public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= _size) {
            return -1;
        }
        LinkedNode *curr = _dummyHead->next; // 从 0 开始
        while (index--) {
            curr = curr->next;  // 走了 index 步，现在到了 index
        }
        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked
     * list. */
    void addAtHead(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *curr = _dummyHead;
        while (curr->next != nullptr) { // curr->next == nullptr 即到了悬崖
            curr = curr->next;
        }
        curr->next = newNode;
        _size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If
     * index equals to the length of linked list, the node will be appended to
     * the end of linked list. If index is greater than the length, the node
     * will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > _size) // 千万注意，这里 index == _size 是可以的，相当于在末尾
            return; // =
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *curr = _dummyHead;  // 从 -1 触发
        while (index--) {
            curr = curr->next;  // 到了 index 的前面一个
        }
        newNode->next = curr->next;
        curr->next = newNode;
        _size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size)
            return;
        LinkedNode *curr = _dummyHead;
        while (index--) {
            curr = curr->next;
        }
        LinkedNode *tmp = curr->next;  // 这个 temp 是必要的，不然这个以后指不到
        curr->next = curr->next->next;
        // delete curr->next;
        delete tmp;
        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
