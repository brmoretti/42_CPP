#include <cstddef>

template <typename T>
void iter(T *ptr, size_t size, void (func)(T&))
{
	if (!func || !ptr) {
		return;
	}
	for (size_t i = 0; i < size; i++) {
		func(*(ptr + i));
	}
}
template <typename T>
void iter(T *ptr, size_t size, void (func)(const T&))
{
	if (!func || !ptr) {
		return;
	}
	for (size_t i = 0; i < size; i++) {
		func(*(ptr + i));
	}
}
