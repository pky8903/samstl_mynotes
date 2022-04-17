#include <vector>

// resize 의 원리를 생각해봅시다.
// 메모리 할당기(allocator): 메모리 할당 정책을 담은 클래스
//template<typename T>
//class vector
//{
//public:
//    void resize(int sz)
//    {
//        // 메모리 할당이 필요한 경우에 어떻게 할까요 ?
//        // new ? malloc ? memory pool
//    }
//};

// 메모리 할당기(allocator): 메모리 할당 정책을 담은 클래스
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
    Alloc ax;   // 2번째 인자로 전달 받은 할당기의 객체를 멤버로 포함
                // 메모리 할당이 필요할 때 이 할당기 사용
public:
    void resize(int sz)
    {
        // 메모리 할당이 필요한 경우에 어떻게 할까요 ?
        // new ? malloc ? memory pool
        T* buff = ax.allocate(sz);  // T type sz개 할당
        ax.dallocate(buff, sz);     // 메모리 해지할 때도 할당기에 의존.
    }
};

int main()
{
    std::vector<int> v(5);  // C++ 표준 할당기 (std::allocator)
    std::vector<int, MyAlloc<int> > v(5);   // 사용자가 만든 할당기 전달
    v.resize(10);           //
}


