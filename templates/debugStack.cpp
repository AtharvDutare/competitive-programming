#include <bits/stdc++.h>
using namespace std;
template <typename T, typename Container = std::deque<T>>
struct DebugStack : private std::stack<T, Container> {
    auto& push(T& elem) {
        std::stack<T>::push(elem);
        return *this;
    }
    auto& push(T&& elem) {
        std::stack<T>::push(elem);
        return *this;
    }
    auto& pop() {
        std::stack<T>::pop();
        return *this;
    }
    T top() {
        return std::stack<T>::top();
    }
    void print() {
        auto const& container = std::stack<T>::c;
        //T should be printable
        std::copy(begin(container), end(container), std::ostream_iterator<T>(std::cout, " "));
        std::cout<<'\n';
    }
};
int main(){
    DebugStack<int> st;
    st.push(1);
    st.push(2);
    st.print();
}