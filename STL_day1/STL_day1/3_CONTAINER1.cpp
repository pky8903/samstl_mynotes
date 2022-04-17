//
//  3_CONTAINER1.cpp
//  STL_day1
//
//  Created by Kyoungyoon Park on 2022/04/11.
//

#include <iostream>

template<typename T> struct Node
{
    T     data;
    Node* next;

    Node(const T& a, Node* n) : data(a), next(n) {}
};

// iterator class
template<typename T>
class slist_iterator
{
    Node<T>* current;
public:
    slist_iterator(Node<T>* p = nullptr): current(p) {}
    
    // our goal: use find for seracing elements in a linked list!
    // redefinition of ++, !=, ==, * operators
    // it should work like "raw pointer"
    
    slist_iterator& operator++()
    {
        current = current->next;
        return *this;
    }
    T& operator*() { return current->data;}
    bool operator==(const slist_iterator& it) const { return current == it.current; }
    bool operator!=(const slist_iterator& it) const { return current != it.current; }
};

template<typename T> class slist
{
    Node<T>* head = 0;
public:
    // STL에는 class에 3개가 있다는 것을 명심. 1) member var., 2) member func., 3) member type!
    using iterator = slist_iterator<T>; // typedef slist_iterator<T> iterator와 같은 의미.
    using value_type = T;
    
    void push_front(const T& a)
    {
        head = new Node<T>(a, head);
    }
    // 나중에 pop_proint() 소멸자같은 코드 생성
    
    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
};

template <typename InputIter, typename T2>
InputIter xfind(InputIter first, InputIter last, T2 value) // real generic find!!
{
    while (first != last && *first != value)
        ++first;
    return first;
}

int main()
{
    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);
    
    slist<int>::iterator p = s.begin(); // now, p acts like a raw pointer.
    std::cout << *p << std::endl;
    ++p;
    std::cout << *p << std::endl;
    
    auto p2 = xfind(s.begin(), s.end(), 60);
    if (p2 != s.end()){
        std::cout << *p2 << std::endl;
    }
    else {
        std::cout << "not found" << std::endl;
    }
    
}
