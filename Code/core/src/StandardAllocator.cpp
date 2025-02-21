#include "StandardAllocator.hpp"

#include <cstdlib>
#include <malloc.h>

namespace TiltedPhoques
{
	void* StandardAllocator::Allocate(const size_t aSize) noexcept
	{
		return malloc(aSize);
	}

	void StandardAllocator::Free(void* apData) noexcept
	{
		free(apData);
	}

	size_t StandardAllocator::Size(void* apData) noexcept
	{
		if (apData == nullptr) return 0;

#ifdef _WIN32
		return _msize(apData);
#elif __linux__
		return malloc_usable_size(apData);
#else
		static_assert(false, "Not implemented");
		return 0;
#endif
	}
}