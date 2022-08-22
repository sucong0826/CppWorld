#pragma once

#include <iostream>

template<typename T>
struct Node
{
public:
	Node(T t) 
	{
		value = t;
		prev = nullptr;
		next = nullptr;
		is_head = false;
		is_last = false;
	}

public:
	T value;
	Node* prev;
	Node* next;
	bool is_head;
	bool is_last;
};

template<typename T, size_t N>
class CustomizedQueue
{
public:
	CustomizedQueue()
	{
		max_size = N;
		std::cout << "max_size=" << max_size << std::endl;
	}

	virtual ~CustomizedQueue()
	{
	}

	bool is_empty()
	{
		return length == 0;
	}

	size_t size()
	{
		return length;
	}

	bool add_last(T t)
	{
		if (!root)
		{
			// means no node now and queue is empty
			// so the added node should be the root node
			Node<T>* node = new Node<T>(t);
			root = node;
			root->is_head = true;
			root->is_last = true;
			length++;
		}
		else
		{
			if (length >= max_size)
			{
				std::cout << "add_last() capacity is full! Can't be added." << std::endl;
				return false;
			}
			else
			{
				Node<T>* prev_root = root;
				Node<T>* node = new Node<T>(t);
				root = node;
				root->next = nullptr;
				root->prev = prev_root;
				root->is_last = true;
				prev_root->next = root;

				Node<T>* prev = prev_root->prev;
				if (!prev) prev_root->is_head = true;
				else prev_root->is_head = false;
				prev_root->is_last = false;

				length++;
			}
		}

		return true;
	}

	bool remove_last()
	{
		if (!root) return false;
		if (root->is_last)
		{
			Node<T>* root_prev = root->prev;
			delete root;
			root = nullptr;
			root = root_prev;
			if (root)
			{
				root->next = nullptr;
				root->is_last = true;
			}
			length--;
			return true;
		}

		return false;
	}

	bool remove_at(int index)
	{
		if (index < 0 || index > length - 1)
		{
			std::cout << "remove_at() index=" << index << " is an illegal argument." << std::endl;
			return false;
		}

		if (is_empty())
		{
			std::cout << "remove_at() is an empty queue." << std::endl;
			return false;
		}

		Node<T>* itr_node = root;
		bool is_removed = false;
		for (int i = length - 1; i >= 0; --i)
		{
			if (i == index)
			{
				if (itr_node->is_last)
				{
					is_removed = remove_last();
					break;
				}
				else if (itr_node->is_head)
				{
					Node<T>* new_head_node = itr_node->next;
					new_head_node->prev = nullptr;
					new_head_node->is_head = true;
					itr_node->next = nullptr;
					delete itr_node;
					length--;
					is_removed = true;
					break;
				}
				else
				{
					Node<T>* _next = itr_node->next;
					Node<T>* _prev = itr_node->prev;
					_next->prev = _prev;
					_prev->next = _next;
					delete itr_node;
					length--;
					is_removed = true;
					break;
				}
			}

			itr_node = itr_node->prev;
		}

		return is_removed;
	}

	bool remove(T t)
	{
		if (is_empty())
		{
			std::cout << "remove() queue is empty!" << std::endl;
			return false;
		}
		
		bool is_removed = false;
		if (root)
		{
			Node<T>* itr_node = root;
			for (int i = length - 1; i >= 0; --i)
			{
				if (t == itr_node->value)
				{
					if (itr_node->is_last)
					{
						is_removed = remove_last();
						break;
					}
					else if (itr_node->is_head)
					{
						Node<T>* new_head_node = itr_node->next;
						new_head_node->prev = nullptr;
						new_head_node->is_head = true;
						itr_node->next = nullptr;
						delete itr_node;
						length--;
						is_removed = true;
						break;
					}
					else
					{
						Node<T>* _next = itr_node->next;
						Node<T>* _prev = itr_node->prev;
						_next->prev = _prev;
						_prev->next = _next;
						delete itr_node;
						length--;
						is_removed = true;
						break;
					}
				}

				itr_node = itr_node->prev;
			}
		}

		return is_removed;
	}

	bool remove_all()
	{
		if (!root || is_empty())
		{
			std::cout << "remove_all() queue is empty now." << std::endl;
			return false;
		}

		Node<T>* itr = root;
		while (itr)
		{
			Node<T>* itr_prev = itr->prev;
			delete itr;
			itr = nullptr;
			itr = itr_prev;
			length--;
			root = itr;
		}

		root = nullptr;
		return true;
	}

	T* get(int index)
	{
		if (index < 0 || index > length - 1)
		{
			std::cout << "get() index=" << index << " is an illegal argument." << std::endl;
			return nullptr;
		}

		if (is_empty())
		{
			std::cout << "get() queue is empty!" << std::endl;
			return nullptr;
		}

		if (root)
		{
			Node<T>* itr_node = root;
			for (int i = length - 1; i >= 0; --i)
			{
				if (i == index)
				{
					if (itr_node)
					{
						return &(itr_node->value);
					}
				}

				itr_node = itr_node->prev;
			}
		}

		return nullptr;
	}

	T* get_first()
	{
		if (is_empty() || !root)
		{
			std::cout << "get_first() queue is empty!" << std::endl;
			return nullptr;
		}

		if (root->is_head)
		{
			return &root->value;
		}
		else
		{
			Node<T>* itr = root->prev;
			while (itr)
			{
				if (itr->is_head)
				{
					return &(itr->value);
				}
				else
				{
					itr = itr->prev;
				}
			}
		}

		return nullptr;
	}

	T* get_last()
	{
		if (is_empty() || !root)
		{
			std::cout << "get_last() queue is empty!" << std::endl;
			return nullptr;
		}

		if (root->is_last)
		{
			return &root->value;
		}

		return nullptr;
	}

	bool set(int index, T value)
	{
		if (index < 0 || index > length - 1)
		{
			std::cout << "set() index=" << index << " is an illegal argument." << std::endl;
			return false;
		}

		if (is_empty() || !root)
		{
			std::cout << "set() queue is empty!" << std::endl;
			return false;
		}

		Node<T>* itr_node = root;
		bool is_set = false;
		for (int i = length - 1; i >= 0; --i)
		{
			if (i == index)
			{
				if (itr_node)
				{
					itr_node->value = value;
					is_set = true;
					break;
				}
			}

			itr_node = itr_node->prev;
		}

		return is_set;
	}

private:
	size_t length = 0;
	size_t max_size = N;
	Node<T>* root = nullptr;
};