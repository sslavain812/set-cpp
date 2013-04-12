#ifndef _NODE.H_
#define _NODE.H_

class node
{
public:
  int val;
	node* left;
	node* right;
	node* prev;

	node(int x = -1, node* p = nullptr)
	{
		val = x;
		left = nullptr;
		right = nullptr;
		prev = p;
	}
	node(int x, node* l, node* r, node* p)
	{
		val = x;
		left = l;
		right = r;
		prev = p;
	}
};

#endif
