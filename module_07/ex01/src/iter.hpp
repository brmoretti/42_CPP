#include <cstddef>

template <typename T, typename F>
void iter(T *ptr, size_t size, F function)
{
	if (!function || !ptr) {
		return;
	}
	for (size_t i = 0; i < size; i++) {
		function(*(ptr + i));
	}
}
