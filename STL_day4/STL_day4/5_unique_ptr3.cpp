#include <memory>
#include <iostream>

int main()
{
	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2(new int[10]);

	std::unique_ptr<int> up3(static_cast<int*>(malloc(sizeof(int)));


	// shared_ptr vs unique_ptr
	


}