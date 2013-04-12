#ifndef _ITERATOR.H_
#define _ITERATOR.H_

#include"node.h"

class iterator
{
public:
  
	iterator (node *x);
	iterator();
	iterator& operator++();   // префиксный
	iterator operator++(int);
	iterator& operator--();     // префиксный
	iterator operator--(int);
	int& operator*() const;
	node* getnode();
	bool operator==(iterator const& it) const;
	bool operator!=(iterator const& it) const;
	
private:
	node* n;
};

#endif
