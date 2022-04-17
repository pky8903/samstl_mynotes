#include <iostream>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>

template<typename Container> void show(Container&& c)
{
	for (const auto& n : c)
		std::cout << n << ", ";
	std::cout << std::endl;
}

template<typename InputIter>
void show(InputIter first, InputIter last )
{
	std::copy(first, last,
		std::ostream_iterator<typename std::iterator_traits<InputIter>::value_type>(std::cout, ", "));
	std::cout << std::endl;
}
