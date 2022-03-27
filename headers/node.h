#pragma once

template <typename type>
class node
{
private:
	type _data;
	node* _left;
	node* _right;
	template <typename F_TYPE>
	friend class set;

	size_t _height;
public:
	node(): _data(type(0)), _left(nullptr), _right(nullptr), _height(1) { }
	node(const type& data) : _data(data), _left(nullptr), _right(nullptr), _height(1) { }
	node(const node<type>& copy_node) : _data(copy_node._data), _left(nullptr), _right(nullptr), _height(1) { }

	node<type>& operator=(const node<type>& copy_node)
	{
		if (this != &copy_node)
		{
			_data = copy_node._data;
			_left = nullptr;
			_right = nullptr;
		}
		_height = 1;
		return *this;
	}

	type data() const { return _data; }
	type& data() { return _data; }
	node* left() const { return _left; }
	node* left() { return _left; }
	node* right() const { return _right; }
	node* right() { return _right; }

};