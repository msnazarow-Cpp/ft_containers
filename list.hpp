#include "allocator.hpp"

namespace ft{
	template <class T, class Alloc = std::allocator<T>> class list{
		public:
			typedef T						value_type;
			typedef Alloc				allocator_type;
			typedef T&						reference;
			typedef const T&				const_reference;
			typedef T*						pointer;
			typedef const T*				const_pointer;
			typedef ptrdiff_t				difference_type;
			typedef size_t					size_type;
	};
}
