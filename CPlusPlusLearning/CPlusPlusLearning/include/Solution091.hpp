#pragma once

#include<queue>

///<summary>
/// https://leetcode.com/problems/implement-stack-using-queues/
///</summary>
class MyStack {
public:
    MyStack() {}
    
    void push(int x);
    
    int pop();
    
    int top();
    
    bool empty();
private:
    std::queue<int> m_first;
    std::queue<int> m_second;
};