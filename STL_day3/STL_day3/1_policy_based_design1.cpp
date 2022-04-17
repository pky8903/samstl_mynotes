// policy base design (단위 전략 디자인)
// 클래스가 사용하는 "어떤 정책"을 템플릿 인자를 통해서 전달하는 것
// 템플릿 인자로 전달되는 정책 클래스는 지켜야하는 규칙을 가지게 됨.
// => 아래 코드에서 "lock()/unlock()" 함수가 있어야한다.
// => 이런 규칙을 모아놓은 것을 "named requirement"라고 한다.

// STL은 "단위 전략 디자인"을 아주 널리 사용한다.

// 단, STL 컨테이너는 멀티스레드 동기화는 되지 않는다.a
// => 아래처럼 되어 있지 않다.

// STL의 핵심 디자인: 단위 전략 디자인!!

template<typename T> class List
{
public:
    void push_front(const T& a)
    {
        lock();
        // ...
        unlock(); // for threadsafety. However, speed is getting slower in single thread environment.
    }
};

template<typename T, typename ThreadModel> class List
{
    ThreadModel tm;
    
public:
    void push_front(const T& a)
    {
        tm.lock();
        // ...
        tm.unlock();
    }
};

// --------------------------------
// 동기화 정책을 담은 정책 클래스를 제공
class mutexLock
{
    // pthread_mutex_t handle;
public:
    inline void lock() {}   // pthread_acquire_mutex() inline이라 치환. 빠르다. 위 push_front에 직접 lock() 한 것과 같은 효과.
    inline void unlock() {} // pthread_release_mutex()
};

class noLock
{
public:
    inline void lock() {}   // do nothing
    inline void unlock() {} // do nothing
};

//---------------------------------
// 이제 List 사용자는 template 인자로 "동기화 정책"을 전달합니다.

//List<int> st; // 전역 변수: multithread 환경에서 안전하지 않음.
List<int, noLock> st; // 정책 전달

int main()
{
    // lock();
    st.push_front(10);
    // unlock(); // put lock and unlock to push_front. This is better.
}
