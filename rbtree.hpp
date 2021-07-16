/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 12:12:34 by adrien            #+#    #+#             */
/*   Updated: 2021/07/16 16:00:09 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"
namespace ft
{
	typedef enum
	{
		black,
		red
	} color_type;

	template <typename T>
	class node
	{
	public:
		node *parent;
		node *left;
		node *right;
		T data;
		color_type color;

		node(void): left(NULL), right(NULL), parent(NULL), data(), color(black){}
		node(const T &data, color_type color, node<T> *left = NULL, node<T> *right = NULL,
				node<T> *parent = NULL): left(left), right(right), parent(parent), data(data), color(color){}
		~node(){};
		node(const node<T> &src): left(src.left), right(src.right), parent(src.parent), data(src.data), color(src.color){}
		node<T> &operator=(const node<T> &rhs){
			left = rhs.left;
			right = rhs.right;
			parent = rhs.parent;
			data = rhs.data;
			color = rhs.color;
			return (*this);}
	};

	template <class T, class Compare, bool allowDuplicates>
	class RedBlackTreeIterator
	{
	private:
		node *tNull;
		node *min;
		node *max;
		node *ptr;
	public:
		typedef ft::node<T> node;
		typedef typename iterator_traits<T>::value_type value_type;
		typedef typename iterator_traits<T>::difference_type difference_type;
		typedef typename iterator_traits<T>::pointer pointer;
		typedef typename iterator_traits<T>::reference reference;
		typedef std::bidirectional_iterator_tag iterator_category;

		RedBlackTreeIterator(void){}
		RedBlackTreeIterator(node *ptr, node *tNull, node *min, node *max): ptr(ptr), tNull(tNull), min(min), max(max){}
		RedBlackTreeIterator(const RedBlackTreeIterator &src): ptr(src.ptr), tNull(src.tNull), min(src.min), max(src.max){}
		~RedBlackTreeIterator(){}
		RedBlackTreeIterator &operator=(const RedBlackTreeIterator &rhs)
		{
			ptr = rhs.ptr;
			tNull = rhs.tNull;
			min = rhs.min;
			max = rhs.max;
		}
		reference operator*(void) const {return this->ptr->data;}
		pointer operator->(void) const {return &this->ptr->data;}
		bool isLeafNode(node *e){return (e == tNull);}
		RedBlackTreeIterator &operator++()
		{
			if (ptr == NULL || isLeafNode(ptr))
				ptr = min;
			else if (!isLeafNode(ptr->right))
			{
				ptr = ptr->right;
				while (!isLeafNode(ptr) && !isLeafNode(ptr->left))
					ptr = ptr->left;
			}
			else
			{
				node *tmp;
				tmp = ptr;
				ptr = ptr->parent;
				while (!isLeafNode(ptr) && tmp == ptr->right)
				{
					tmp = ptr;
					ptr = ptr->parent;
				}
		}
		return (*this);}
		RedBlackTreeIterator &operator--()
		{
			if (!ptr || isLeafNode(ptr))
			ptr = max;
			else if (!isLeafNode(ptr->left))
			{
				ptr = ptr->left;
				while (!isLeafNode(ptr) && !isLeafNode(ptr->right))
				{
					ptr = ptr->right;
				}
			}
			else
			{
				node *tmp;
				tmp = ptr;
				ptr = ptr->parent;
				while (!isLeafNode(ptr) && tmp == ptr->left);
				{
					tmp = ptr;
					ptr = ptr->parent;
				}
			}
			return (*this);
		}
		RedBlackTreeIterator operator++(int)
		{
			RedBlackTreeIterator copy = *this;
			++(*this);
			return (copy);
		}
		RedBlackTreeIterator operator--(int)
		{
			RedBlackTreeIterator copy = *this;
			--(*this);
			return (copy);
		}

		bool operator==(const RedBlackTreeIterator &rhs) const {return this->ptr == rhs.ptr;}
		bool operator!=(const RedBlackTreeIterator &rhs) const {return this->ptr != rhs.ptr;}



	};
	template <class T, class Compare, bool allowDuplicates>
	class RedBlackTree
	{
	private:
		nodePtr root;
		nodePtr tNull;
		size_t length;
		Compare cmp;
	public:
		typedef node<T> *nodePtr;
		typedef node<const T> *const_nodePtr;
		typedef RedBlackTreeIterator<T, Compare, allowDuplicates> iterator;
		typedef RedBlackTreeIterator<const T, Compare, allowDuplicates> const_iterator;
		typedef ReverseBiDirIter<iterator> reverse_iterator;
		typedef ReverseBiDirIter<const_iterator> const_reverse_iterator;

		explicit RedBlackTree(const Compare &comp = Compare()) : length(0), cmp(src.cmp)
		{
			tNull = new TreeNode<T>;
			root = tNull;
		}
		template <class InputIterator>
		RedBlackTree(InputIterator first, InputIterator last, const Compare &comp = Compare()): length(0), cmp(src.cmp)
		{
			tNull = new TreeNode<T>;
			root = tNull;
			insert(first, last);
		}
		RedBlackTree(const RedBlackTree &src): length(0), cmp(src.cmp)
		{
			tNull = new TreeNode<T>;
			root = tNull;
			deepCopy(src.root, src.tNull);
		}
		~RedBlackTree()
		{
			clear();
			delete tNull;
		}
		RedBlackTree &operator=(const RedBlackTree &rhs)
		{
			if (this != &rhs)
			{
				clear();
				deepCopy(rhs.root, rhs.tNull);
			}
			return (*this);
		}

		iterator insert(const T &data)
		{
			return insertFrom(root, data);
		}
		iterator insert(iterator, const T &data)
		{
			return insertFrom(root, data);
		}
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (InputIterator it = first; it != last; it++)
				insert(*it);
		}

		void erase(iterator position) {return deleteNode(position.ptr);}
		void erase(iterator first, iterator last)
		{
			iterator it = first;
			while (it != last)
				erase(it++);
		}
		template <typename Predicate>
		size_t eraseIf(Predicate pred, const T &data)
		{
			(void)pred;
			nodePtr node;
			size_t initalLength = size();

			node = this->root;
			while (node && node != tNull)
			{
				if (pred(node->data, data))
				{
					deleteNode(node);
					node = this->root;
				}
				else if (cmp(data, node->data))
					node = node->left;
				else if (cmp(node->data, data))
					node = node->right;
			}
			return initalLength - size();
		}

		void swap(RedBlackTree<T, Compare, allowDuplicates> &x)
		{
		nodePtr tmp_root = root;
		nodePtr tmp_tNull = tNull;
		size_t tmp_length = size();

		root = x.root;
		tNull = x.tNull;
		length = x.length;

		x.root = tmp_root;
		x.tNull = tmp_tNull;
		x.length = tmp_length;
		}

		template <typename Predicate>
		iterator find(Predicate pred, const T &data)
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (pred(data, *it))
					return it;
			}
			return end();
		}
		template <typename Predicate>
		const_iterator find(Predicate pred, const T &data) const
		{
			for (const_iterator it = begin(); it != end(); it++)
			{
				if (pred(data, *it))
					return it;
			}
			return end();
		}

		template <typename Predicate>
		size_t countIf(Predicate pred, const T &data) const {return countIfRec(this->root, pred, data);}

		void clear()
		{
			while (!empty())
				erase(begin());
		}

		// Iterators

		iterator begin()
		{
			nodePtr min = minimum();
			return iterator(min, this->tNull, min, maximum());
		}
		const_iterator begin() const
		{
			const_nodePtr min = reinterpret_cast<const_nodePtr>(minimum());
			const_nodePtr max = reinterpret_cast<const_nodePtr>(maximum());
			const_nodePtr tNull = reinterpret_cast<const_nodePtr>(this->tNull);
			return const_iterator(min, tNull, min, max);
		}

		iterator end()
		{
			nodePtr max = maximum();
			return ++iterator(max, this->tNull, minimum(), max);
		}
		const_iterator end() const
		{
			const_nodePtr min = reinterpret_cast<const_nodePtr>(minimum());
			const_nodePtr max = reinterpret_cast<const_nodePtr>(maximum());
			const_nodePtr tNull = reinterpret_cast<const_nodePtr>(this->tNull);
			return ++const_iterator(max, tNull, min, max);
		}

		reverse_iterator rbegin() {return reverse_iterator(end());}
		const_reverse_iterator rbegin() const {const_reverse_iterator(end());}

		reverse_iterator rend() {return reverse_iterator(begin());}
		const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

		// Capacity

		bool empty() const {return (size() == 0);}
		size_t size() const {return length;}


		nodePtr getParent(nodePtr n) {return n == NULL ? NULL : n->parent;}
		nodePtr getGrandParent(nodePtr n){ return getParent(getParent(n));}
		nodePtr getSibling(nodePtr n)
		{
			nodePtr parent = getParent(n);

			if (!parent)
				return NULL;

			if (parent->left == n)
				return parent->right;

			return parent->left;
		}
		nodePtr getUncle(nodePtr n) {return getSibling(getParent(n));}

		nodePtr minimum() const {return minimum(this->root);}
		nodePtr maximum() const {return maximum(this->root);}

		nodePtr minimum(nodePtr n) const
		{
			if (!n || n == tNull)
				return NULL;
			while (n->left != tNull)
				n = n->left;
			return n;
		}
		nodePtr maximum(nodePtr n) const
		{
			if (!n || n == tNull)
				return NULL;
			while (n->right != tNull)
				n = n->right;
			return n;
		}

		void rotateLeft(nodePtr n)
		{
			nodePtr y = x->right;
			x->right = y->left;
			if (y->left != tNull)
				y->left->parent = x;
			y->parent = getParent(x);
			if (getParent(x) == NULL || getParent(x) == tNull)
				root = y;
			else if (x == getParent(x)->left)
				getParent(x)->left = y;
			else
				getParent(x)->right = y;
			y->left = x;
			x->parent = y;
		}
		void rotateRight(nodePtr n)
		{
			nodePtr y = x->left;
			x->left = y->right;

			if (y->right != tNull)
				y->right->parent = x;
			y->parent = x->parent;
			if (getParent(x) == NULL || getParent(x) == tNull)
				root = y;
			else if (getParent(x)->right == x)
				getParent(x)->right = y;
			else
				getParent(x)->left = y;
			y->right = x;
			x->parent = y;
		}

		nodePtr createNewNodeToAdd(const T &data, nodePtr parent)
		{
			length++;
			return new node<T>(data, red, tNull, tNull, parent);
		}

		iterator insertFrom(nodePtr recRoot, const T &data)
		{
			iterator it = insertRecurse(recRoot, data);

			insertRepair(it.ptr);

			recRoot = it.ptr;
			while (getParent(recRoot) && getParent(recRoot) != tNull)
				recRoot = getParent(recRoot);

			this->root = recRoot;

			return it;
		}
		iterator insertRecurse(nodePtr recRoot, const T &data)
		{
			if (recRoot != NULL && recRoot != tNull)
			{
				if (cmp(data, recRoot->data))
				{
					if (recRoot->left != tNull)
						return insertRecurse(recRoot->left, data);
					else
					{
						recRoot->left = createNewNodeToAdd(data, recRoot);
						return iterator(recRoot->left, tNull, minimum(), maximum());
					}
				}
				else if (cmp(recRoot->data, data) || allowDuplicates)
				{
					if (recRoot->right != tNull)
						return insertRecurse(recRoot->right, data);
					else
					{
						recRoot->right = createNewNodeToAdd(data, recRoot);
						return iterator(recRoot->right, tNull, minimum(), maximum());
					}
				}
				else
				{
					return iterator(recRoot, tNull, minimum(), maximum());
				}
			}
			else
				return iterator(createNewNodeToAdd(data, recRoot), tNull, minimum(), maximum());
		}
		void insertRepair(nodePtr n)
		{
			if (getParent(n) == NULL || getParent(n) == tNull)
				insertCase1(n);
			else if (getParent(n)->color == black)
				insertCase2(n);
			else if (getUncle(n) != NULL && getUncle(n)->color == red)
				insertCase3(n);
			else
				insertCase4(n);
		}
		void insertCase1(nodePtr n) {n->color = black;}
		void insertCase2(nodePtr){}
		void insertCase3(nodePtr n)
		{
			getParent(n)->color = black;
			getUncle(n)->color = black;
			getGrandParent(n)->color = red;
			insertRepair(getGrandParent(n));
		}
		void insertCase4(nodePtr n)
		{
			nodePtr parent = getParent(n);
			nodePtr grandParent = getGrandParent(n);

			if (n == parent->right && parent == grandParent->left)
			{
				rotateLeft(parent);
				n = n->left;
			}
			else if (n == parent->left && parent == grandParent->right)
			{
				rotateRight(parent);
				n = n->right;
			}
			insertCase4Step2(n);
		}
		void insertCase4Step2(nodePtr n)
		{
			nodePtr parent = getParent(n);
			nodePtr grandParent = getGrandParent(n);

			if (n == parent->left)
				rotateRight(grandParent);
			else
				rotateLeft(grandParent);

			parent->color = black;
			grandParent->color = red;
		}

		void replaceNode(nodePtr n, nodePtr child)
		{
			if (u->parent == NULL || u->parent == tNull)
				root = v;
			else if (u == getParent(u)->left)
				getParent(u)->left = v;
			else
				getParent(u)->right = v;

			v->parent = u->parent;
		}

		void deleteNode(nodePtr node)
		{
			nodePtr x, y = NULL;
		nodePtr toDelete = node;

		if (toDelete == NULL || toDelete == tNull)
			return;

		y = toDelete;
		t_colors originalColor = toDelete->color;

		if (toDelete->left == tNull)
		{
			x = toDelete->right;
			replaceNode(toDelete, toDelete->right);
		}
		else if (toDelete->right == tNull)
		{
			x = toDelete->left;
			replaceNode(toDelete, toDelete->left);
		}
		else
		{
			y = minimum(toDelete->right);
			originalColor = y->color;
			x = y->right;
			if (getParent(y) == toDelete)
				x->parent = y;
			else
			{
				replaceNode(y, y->right);
				y->right = toDelete->right;
				y->right->parent = y;
			}
			replaceNode(toDelete, y);
			y->left = toDelete->left;
			y->left->parent = y;
			y->color = toDelete->color;
		}
		delete toDelete;
		length--;
		if (originalColor == black)
			deleteFix(x);
		}
		void deleteFix(nodePtr x)
		{
			nodePtr s;
			while (x != root && x->color == black)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == red)
					{
						s->color = black;
						x->parent->color = red;
						rotateLeft(x->parent);
						s = x->parent->right;
					}

					if (s->left->color == black && s->right->color == black)
					{
						s->color = red;
						x = x->parent;
					}
					else
					{
						if (s->right->color == black)
						{
							s->left->color = black;
							s->color = red;
							rotateRight(s);
							s = x->parent->right;
						}

						s->color = x->parent->color;
						x->parent->color = black;
						s->right->color = black;
						rotateLeft(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == red)
					{
						s->color = black;
						x->parent->color = red;
						rotateRight(x->parent);
						s = x->parent->left;
					}

					if (s->right->color == black && s->right->color == black)
					{
						s->color = red;
						x = x->parent;
					}
					else
					{
						if (s->left->color == black)
						{
							s->right->color = black;
							s->color = red;
							rotateLeft(s);
							s = x->parent->left;
						}

						s->color = x->parent->color;
						x->parent->color = black;
						s->left->color = black;
						rotateRight(x->parent);
						x = root;
					}
				}
			}
			x->color = black;
		}
			void deepCopy(nodePtr srcRoot, nodePtr srcTNull)
			{
				if (!srcRoot || srcRoot == srcTnull)
					return;
				deepCopy(srcRoot->left, srcTnull);
				insert(srcRoot->data);
				deepCopy(srcRoot->right, srcTnull);
			}

			template <typename Predicate>
			size_t countIfRec(nodePtr recRoot, Predicate pred, const T &data) const`
			{
				size_t count = 0;
				if (!recRoot || recRoot == tNull)
					return 0;
				count += countIfRec(recRoot->left, pred, data);
				count += countIfRec(recRoot->right, pred, data);

				if (pred(data, recRoot->data))
					count++;
				return count;
			}

		};

		template <class T, class Compare, bool allowDuplicates>
		template <class InputIterator>
		RedBlackTree<T, Compare, allowDuplicates>::RedBlackTree(InputIterator first, InputIterator last, const Compare &comp) : length(0), cmp(comp)
		{
			tNull = new node<T>;
			root = tNull;
			insert(first, last);
		}

		template <class T, class Compare, bool allowDuplicates>
		RedBlackTree<T, Compare, allowDuplicates>::RedBlackTree(const Compare &comp) : length(0), cmp(comp)
		{
			tNull = new node<T>;
			root = tNull;
		}

		template <class T, class Compare, bool allowDuplicates>
		RedBlackTree<T, Compare, allowDuplicates> &RedBlackTree<T, Compare, allowDuplicates>::operator=(const RedBlackTree &rhs)
		{
			if (this != &rhs)
			{
				clear();
				deepCopy(rhs.root, rhs.tNull);
			}
			return (*this);
		}

		template <class T, class Compare, bool allowDuplicates>
		RedBlackTree<T, Compare, allowDuplicates>::RedBlackTree(const RedBlackTree &src) : length(0), cmp(src.cmp)
		{
			tNull = new node<T>;
			root = tNull;
			deepCopy(src.root, src.tNull);
		}

		template <class T, class Compare, bool allowDuplicates>
		void RedBlackTree<T, Compare, allowDuplicates>::deepCopy(nodePtr srcRoot, nodePtr srcTnull)
		{

		}
}