class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};

//void foo(Rect r)            // call by value
void foo(const Rect& r)       // 사용자 정의 타입을 인자로 받을 때는 call by value는 좋지 않다. 그래서 상수 참조를 쓰면?
{
	int n = r.getArea();      // getArea()에 const 안붙이면 에러! 이럴 땐 const &를 떼는게 아니라 getArea()에 const를 붙인다.
}

// 상수 멤버 함수는 선택이 아닌 필수 문법입니다.
// 멤버 함수를 만들 때, 객체의 상태를 변경하지 않은 모드 멤버함수(getter)는
// 반드시 "상수 멤버 함수"로 해야합니다.

int main()
{
	Rect r(1,2,3,4);	    // no const object
	int n = r.getArea();    // ok.
	foo(r);
}
