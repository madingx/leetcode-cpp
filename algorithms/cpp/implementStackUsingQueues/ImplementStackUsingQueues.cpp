// Source : https://leetcode.com/problems/implement-stack-using-queues/
// Author : Hao Chen
// Date   : 2015-06-13

/********************************************************************************** 
 * 225. Implement Stack using Queues [Easy]
 * Implement the following operations of a stack using queues.
 * 
 * push(x) -- Push element x onto stack.
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * top() -- Get the top element.
 * 
 * empty() -- Return whether the stack is empty.
 * 
 * Notes:
 * 
 * You must use only standard operations of a queue -- which means only push to back, 
 * peek/pop from front, size, and is empty operations are valid.
 *
 * Depending on your language, queue may not be supported natively. You may simulate 
 * a queue by using a list or deque (double-ended queue), as long as you use only 
 * standard operations of a queue.
 *
 * You may assume that all operations are valid (for example, no pop or top operations 
 * will be called on an empty stack).
 * 
 * Update (2015-06-11):
 * The class name of the Java function had been updated to MyStack instead of Stack.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and all test cases.
 *               
 **********************************************************************************/


class Stack {
    public:
        // Push element x onto stack.
        void push(int x) {
            nums.push(x);
        }
        // Removes the element on top of the stack.
        void pop() {
            if (!empty()) {
                int len = nums.size()-1;
                //Don't treat the "-->" is a new operator. ;-)
                while ( len-->0) {
                    nums.push(nums.front());
                    nums.pop();
                }
                nums.pop();
            }
        }
        // Get the top element.
        int top() {
            return nums.back();
        }
        // Return whether the stack is empty.
        bool empty() {
            return nums.empty();
        }

    private:
        queue<int> nums;
};


// 0 ms, faster than 100.00% of C++, 8.8 MB, less than 88.68% of C++
class MyStack {
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;++i){
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = que.front();
        que.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};