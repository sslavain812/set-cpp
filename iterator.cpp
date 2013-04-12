#include"iterator.h"
#include"node.h"

iterator::iterator(node* x)
{
  n = x;
}

iterator::iterator()
{
	n = nullptr;
}
iterator& iterator::operator++()   // префиксный
{
	if(n->right != nullptr)
	{
		n = n->right;
		while(n->left != nullptr)
			n = n->left;
	}
	else
	{
		while(n != (n->prev)->left)  // пока мы правый сын
		{
			n = n->prev;
		}
		n = n->prev;
	}
}
iterator iterator::operator++(int)
{
	iterator it;
	it.n = n;
	return ++it;
}
iterator& iterator::operator--()     // префиксный
{
	if(n->prev->left == n->prev->right) // если мы в корне
	{
		// или ничего не делать,
		// или начать с конца
		return *this;
	}

	if(n->left != nullptr)   // есть левое поддерево
	{
		n = n->left;
		while(n->right != nullptr)
			n = n->right;
		return *this;
	}
	else
	{
		while(n != (n->prev)->right)  // пока мы левый сын
		{
			n = n->prev;
		}
		n = n->prev;
	}
}
iterator iterator::operator--(int)
{
	iterator it;
	it.n = n;
	return --it;
}
int& iterator::operator*() const
{
	return n->val;
}
node* iterator::getnode()
{
	return n;
}
bool iterator::operator==(iterator const& it) const
{
	if(n->val == it.n->val) return true;
	else return false;
}
bool iterator::operator!=(iterator const& it) const
{
	if(n->val == it.n->val) return false;
	else return true;
}
