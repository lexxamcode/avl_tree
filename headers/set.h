#pragma once
#include "node.h"

template <typename type>
class set
{
private:
	node<type>* root;

	size_t height(node<type>* rt)
	{
		if (!rt)
			return 0;
		else
			return rt->_height;
	}

	int balanceFactor(node<type>* rt)
	{
		return height(rt->_right) - height(rt->_left);
	}

	void fixHeight(node<type>* rt)
	{
		size_t hl = height(rt->_left);
		size_t hr = height(rt->_right);

		if (hl > hr)
			rt->_height = hl + 1;
		else
			rt->_height = hr + 1;
	}

	node<type>* rotateRight(node<type>* rt)
	{
		node<type>* temp = rt->_left;
		rt->_left = temp->_right;
		temp->_right = rt;
		fixHeight(rt);
		fixHeight(temp);
		return temp;
	}
	node<type>* rotateLeft(node<type>* rt)
	{
		node<type>* temp = rt->_right;
		rt->_right = temp->_left;
		temp->_left = rt;
		fixHeight(rt);
		fixHeight(temp);
		return temp;
	}
	node<type>* balance(node<type>* rt)
	{
		fixHeight(rt);

		if (balanceFactor(rt) > 1)
		{
			if (balanceFactor(rt->_right) < 0)
				rt->_right = rotateRight(rt->_right);
			return rotateLeft(rt);
		}
		if (balanceFactor(rt) < -1)
		{
			if (balanceFactor(rt->_left) > 0)
				rt->_left = rotateLeft(rt->_left);
			return rotateRight(rt);
		}

		return rt;
	}
	void copy(node<type>* copy_root)
	{
		if (!copy_root)
			return;

		insert(copy_root->_data);
		copy(copy_root->_left);
		copy(copy_root->_right);
	}

	void straightPrint(node<type>* rt) const
	{
		if (rt)
		{
			std::cout << rt->_data << " ";
			straightPrint(rt->_left);
			straightPrint(rt->_right);
		}
		else
			return;
	}

	node<type>* findMin(node<type>* rt)
	{
		if (rt->_left)
			return findMin(rt->_left);
		else
			return rt;
	}
	node<type>* delMin(node<type>* rt)
	{
		if (!rt->_left)
			return rt->_right;

		rt->_left = delMin(rt->_left);
		return balance(rt);
	}	
	node<type>* del(node<type>* rt, const type& data)
	{
		if (!rt)
			return rt;
		else
		{
			if (data < rt->_data)
			{
				rt->_left = del(rt->_left, data);
			}
			if (data > rt->_data)
			{
				rt->_right = del(rt->_right, data);
			}
			else
			{
				node<type>* templ = rt->_left;
				node<type>* tempr = rt->_right;
				delete rt;
				if (!tempr)
					return templ;
				node<type>* min = findMin(tempr);
				min->_right = delMin(tempr);
				min->_left = templ;
				return balance(min);
			}

			return balance(rt);
		}
	}

	node<type>* addTo(node<type>* rt, const type& data)
	{
		if (!rt)
			rt = new node<type>(data);
		else if (data < rt->_data)
			rt->_left = addTo(rt->_left, data);
		else if (data > rt->_data)
			rt->_right = addTo(rt->_right, data);
		return balance(rt);
	}

public:
	set():root(nullptr) { }
	set(const set<type>& copySet)
	{
		root = nullptr;

		if (copySet.root)
			copy(copySet.root);
	}

	void print() const
	{
		straightPrint(root);
	}

	bool find(const type& data) const
	{
		node<type>* tmp = root;
		while (tmp)
		{
			if (tmp->_data > data)
				tmp = tmp->_left;
			else if (tmp->_data < data)
				tmp = tmp->_right;
			else
				return 1;
		}
		return 0;
	}

	bool insert(const type& data)
	{
		root = addTo(root, data);
		if (root)
			return 1;
		else return 0;
	}

	bool erase(const type& data)
	{
		root = del(root, data);
		if (root)
			return 1;
		else
			return 0;
	}
};