#pragma once
#include "node.h"

template <typename type>
class set
{
private:
	node<type>* root;
	size_t height(node<type>* rt = root)
	{
		if (!rt)
			return 0;
		else if (!rt->_left && !rt->_right)
		{
			return 1;
		}
		else if (height(rt->_left) > height(rt->_right))
			return height(rt->_left) + 1;
		else
			return height(rt->_right) + 1;
	}
	void updateHeight(node<type>* rt)
	{
		if (rt)
		{
			rt->_height = height(rt);
			updateHeight(rt->_left);
			updateHeight(rt->_right);
		}
		else
			return;
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
	node<type>* minimum(node<type>* rt)
	{
		if (!rt->_left)
			return rt;
		return minimum(rt->_left);
	}
	bool delElem(node<type>* rt, const type& data)
	{
		node<type>* tmp = rt;
		node<type>* parent = nullptr;
		while (tmp)
		{
			if (tmp->_data > data)
			{
				parent = tmp;
				tmp = tmp->_left;
			}
				
			else if (tmp->_data < data)
			{
				parent = tmp;
				tmp = tmp->_right;
			}
				
			else//found
			{
				if (!tmp->_right && !tmp->_left)
				{
					if (parent->_data > tmp->_data)
					{
						parent->_left = nullptr;
						delete tmp;
						tmp = nullptr;
					}
					else
					{
						parent->_right = nullptr;
						delete tmp;
						tmp = nullptr;
					}

				}
				else if (tmp->_right && !tmp->_left)
				{
					tmp->_data = tmp->_right->_data;
					tmp->_left = tmp->_right->_left;
					tmp->_right = tmp->_right->_right;
					delete tmp->_right;
					tmp->_right = nullptr;
				}
				else if (!tmp->_right && tmp->_left)
				{
					tmp->_data = tmp->_left->_data;
					tmp->_right = tmp->_left->_right;
					tmp->_left = tmp->_left->_left;
					delete tmp->_left;
					tmp->_left = nullptr;
				}
				else
				{
					node<type>* minElem = minimum(tmp->_right);
					tmp->_data = minElem->_data;
					tmp->_right = minElem->_right;
					delete minElem;
					minElem = nullptr;
				}

				return 1;
			}
		}
		return 0;
	}
public:
	set():root(nullptr) { }
	set(const set<type>& copySet)
	{
		root = nullptr;

		if (copySet.root)
			copy(copySet.root);
	}

	bool erase(const type& data)
	{
		return delElem(root, data);
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
		if (!root)
		{
			root = new node<type>(data);
			return 1;
		}

		node<type>* checkpoint = root;

		while (checkpoint)
		{
			if (data == checkpoint->_data)
				return 0;
			else
			{
				if (data < checkpoint->_data)
				{
					if (checkpoint->_left)
						checkpoint = checkpoint->_left;
					else
					{
						checkpoint->_left = new node<type>(data);
						break;
					}
				}
				else if (data > checkpoint->_data)
				{
					if (checkpoint->_right)
						checkpoint = checkpoint->_right;
					else
					{
						checkpoint->_right = new node<type>(data);
						break;
					}
				}
			}
		}
		updateHeight(root);
		return 1;
	}

};