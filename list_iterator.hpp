#include "iterator.hpp"
#include <iterator>
namespace ft {
	template <typename T>
	class list_iterator : iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		T /* data */;
	
	public:
		list_iterator();
		list_iterator(const list_iterator &it);
		list_iterator &it operator = (const list_iterator &it);
		~list_iterator();
		bool operator == (const list_iterator &a, const list_iterator &b);
		bool operator != (const list_iterator &a, const list_iterator &b);
		list_iterator & operator++();
		list_iterator operator++(int);
		list_iterator & operator--();
		list_iterator operator--(int);
		
		reference operator *();
		pointer operator->
	};
	
}