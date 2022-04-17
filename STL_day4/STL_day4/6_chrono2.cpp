#include <iostream>
#include <chrono>
using namespace std::chrono;

// duration ���� : Ư�� ������ ����(tick count)�� ǥ���ϴ� �ڷᱸ��
//				  10�� => 1���� 10��
//					   => 1/1000���� 10000��..

int main()
{
	// 1. duration ���
	duration<int, ratio<1, 100>>  d1(2); // 1/100 * 2
	duration<int, ratio<1, 1000>> d2(d1); 

}
