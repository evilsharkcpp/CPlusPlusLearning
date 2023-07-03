#include "Solution091.hpp"

void MyStack::push(int x) {
    m_first.push(x);
}

int MyStack::pop() {
    for(int i{}; i < m_first.size() - 1;) {
        m_second.push(m_first.front());
        m_first.pop();
    }

    int x { m_first.front() };
    m_first.pop();

    std::swap(m_first, m_second);

    return x;
}

int MyStack::top() {
    return m_first.back();
}

bool MyStack::empty() {
    return m_first.empty();
}
