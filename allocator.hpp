#include <limits>

namespace ft{
	template <class T> class allocator;ghd
	template <> class allocator<void> {
	public:
	typedef void* pointer;
	typedef const void* const_pointer;
	typedef void value_type;
	template <class U> struct rebind { typedef allocator<U> other; };
	};
	template <class T> class allocator{
	public:
		typedef T				value_type;
		typedef T*				pointer;
		typedef const T*		const_pointer;
		typedef T&				reference;
		typedef const T&		const_reference;
		typedef std::size_t		size_type;
		typedef std::ptrdiff_t	difference_type;
		template <class Type> struct rebind {
		typedef allocator<Type> other;
		};
		allocator() throw() {}
		allocator (const allocator& alloc) throw() {}
		template <class U> allocator (const allocator<U>& alloc) throw(){}
		allocator & operator = (const allocator& alloc) throw() {}
		~allocator(){}
		pointer address ( reference x ) const { return &x; }
		const_pointer address ( const_reference x ) const { return &x; }
		pointer allocate (size_type n, allocator<void>::const_pointer hint=0){
			return(::operator new(n * sizeof(value_type)));
		}
		void deallocate (pointer p, size_type n)
		{
			::operator delete(p);
		}
		size_type max_size() const throw()
		{
			return(std::numeric_limits<size_type>::max() / sizeof(value_type));
		}
		void construct( pointer p, const_reference val )
		{
			new((void *)p) value_type (val);
		}
		void destroy (pointer p)
		{
			p->~value_type();
		}
	};
	
}
