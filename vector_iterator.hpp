#pragma once
#include <iterator>

namespace ft
{
	template <class T, class Category = std::random_access_iterator_tag, class allocator_type = std::allocator<T> >
	class vector_iterator{
		public:
		typedef T			value_type;
		typedef T&		reference;
		typedef const T&	const_reference;
		typedef T*			pointer;
		typedef const T*		const_pointer;
	    typedef size_t      size_type;
      	typedef std::ptrdiff_t   difference_type;
		typedef Category	iterator_category;
		private:
			pointer _ptr;
		public:
			vector_iterator (pointer _ptr = 0): _ptr(_ptr) {};
			
			vector_iterator (const vector_iterator & it): _ptr(it._ptr) {}
			vector_iterator operator=(const vector_iterator & it) { _ptr = it._ptr;
			return *this;}
			bool operator==(const vector_iterator & it) const { return (_ptr == it._ptr);}
			bool operator!=(const vector_iterator & it) const { return (_ptr != it._ptr);}
			bool operator>=(const vector_iterator & it) const { return (_ptr >= it._ptr);}
			bool operator<=(const vector_iterator & it) const { return (_ptr <= it._ptr);}
			bool operator>(const vector_iterator & it) const { return (_ptr > it._ptr);}
			bool operator<(const vector_iterator & it) const { return (_ptr < it._ptr);}
			reference operator*() {return(*_ptr);}
			const_reference operator*() const {return(*_ptr);}
			pointer operator->() {return (_ptr);}
			const_pointer operator->() const {return (_ptr);}
			vector_iterator & operator++()
			{
				_ptr++;
				return (*this);
			}
			pointer base()
			{
				return _ptr;
			}
			const_pointer base() const
			{
				return _ptr;
			}
			vector_iterator operator++(int)
			{
				vector_iterator result = *this;
				++(*this);
				return (result);
			}
			vector_iterator & operator--()
			{
				_ptr--;
				return (*this);
			}
			vector_iterator operator--(int)
			{
				vector_iterator result = *this;
				--(*this);
				return (result);
			}
			vector_iterator & operator+=(difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			vector_iterator & operator-=(difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			vector_iterator operator+(difference_type n) const
			{
				return (_ptr + n);
			}
			vector_iterator operator-(difference_type n) const
			{
				return (_ptr - n);
			}
			difference_type operator-(vector_iterator it) const
			{
				return (_ptr - it._ptr);
			}
			reference operator[](difference_type i) const
			{
				return (*(_ptr + i));
			}
			operator vector_iterator<const T> () const
				{ return (vector_iterator<const T>(_ptr));}
	};
	template <typename T>
	bool
	operator==(const ft::vector_iterator<T> lhs,
			const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template<typename T_L, typename T_R>
	bool
	operator==(const ft::vector_iterator<T_L> lhs,
			const ft::vector_iterator<T_R> rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <typename T>
	bool
	operator!=(const ft::vector_iterator<T> lhs,
			const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template<typename T_L, typename T_R>
	bool
	operator!=(const ft::vector_iterator<T_L> lhs,
			const ft::vector_iterator<T_R> rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <typename T>
	bool
	operator<(const ft::vector_iterator<T> lhs,
			const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template<typename T_L, typename T_R>
	bool
	operator<(const ft::vector_iterator<T_L> lhs,
			const ft::vector_iterator<T_R> rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <typename T>
	bool
	operator>(const ft::vector_iterator<T> lhs,
			const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template<typename T_L,
			typename T_R>
	bool
	operator>(const ft::vector_iterator<T_L> lhs,
			const ft::vector_iterator<T_R> rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <typename T>
	bool
	operator<=(const ft::vector_iterator<T> lhs,
			const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template<typename T_L, typename T_R>
	bool
	operator<=(const ft::vector_iterator<T_L> lhs,
			const ft::vector_iterator<T_R> rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <typename T>
	bool
	operator>=(const ft::vector_iterator<T> lhs,
			const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template<typename T_L,
			typename T_R>
	bool
	operator>=(const ft::vector_iterator<T_L> lhs,
			const ft::vector_iterator<T_R> rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator-(const ft::vector_iterator<T> lhs,
			const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}
	template<typename T_L, typename T_R>
	typename ft::vector_iterator<T_L>::difference_type
	operator-(const ft::vector_iterator<T_L> lhs,
			const ft::vector_iterator<T_R> rhs)
	{
		return (lhs.base() - rhs.base());
	}
		template<typename T>
	ft::vector_iterator<T> operator+(
		typename ft::vector_iterator<T>::difference_type n,
		typename ft::vector_iterator<T>& rai)
		{
			return (&(*rai) + n);
		}
}