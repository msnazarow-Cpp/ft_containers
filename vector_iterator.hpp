#include <iterator>
namespace ft
{
	class vector_iterator : iterator<std::random_access_iterator_tag, T>
	{
		private:
			pointer ptr;
		public:
			vector_iterator():ptr(0) {}
			vector_iterator(vector_iterator & it) : ptr(it.ptr) {}
			~vector_iterator() {}
			vector_iterator
	}
}