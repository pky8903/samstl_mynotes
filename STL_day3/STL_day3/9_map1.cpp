#include <map>  
#include "show.h"
// map : pair �� �����ϴ� set,   key ������ value �� ����
int main()
{
	std::map<std::string, std::string> m;

	// ��� �ֱ�
	// 1. pair ���� �ֱ�

	// 2. make_pair

	// 3. emplace

	// 4. [] ������ ���
	//------------------------
	
	// �ݺ��ڿ� ���ؼ�
	auto p = m.find("wed"); // find(Ű��)

	// p�� ����ؼ� "wed : ������" �̶�� ����غ�����

	// [] ������
	std::cout << m["sun"] << std::endl; 
}




