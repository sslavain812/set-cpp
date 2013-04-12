#include<cstdlib>
#include"node.h"
#include"iterator.h"

using namespace std;

class set
{
  public:
		set()
		{
			// вроде норм
			size=0;
			root = new node();  // мы их еще раз выделяем или как?

			end_ptr = new node();
			end_ptr->left = root;
			end_ptr->right = root;
			root->prev = end_ptr;
		}

		set(set const& newSet)
		{
			root = prefixTravel(newSet.root);
			size = newSet.size;

			end_ptr = new node();
			end_ptr->left = root;
			end_ptr->right = root;
			root->prev = end_ptr;
		}

		set& operator=(set const& newSet)
		{
			set t = set(newSet);    // а он после выхода не удалится?
			return t;
		}

		bool insert(int x, node* n = nullptr)
		{
			// вроде норм
			if(n == nullptr)
				n = root;
			if(x > n->val)
			{
				if(n->right != nullptr)
					insert(x, n->right);
				else
				{
					node* t = new node();
					t->val = x;
					t->prev = n;
					n->right = t;
				}
			}
			else
			{
				if(n->left != nullptr)
					insert(x, n->left);
				else
				{
					node* t = new node();
					t->val = x;
					t->prev = n;
					n->left = n;
				}
			}
			++size;
		}

		iterator find(int x, node* n = nullptr)
		{
			// кажется, неплохо
			if(n == nullptr)
				n =root;
			if(x == n->val)
				return iterator(n);
			
			if(x , n->val)
				return find(x, n->left);
			else
				return find(x, n->right);
		}

		void erase(iterator it)
		{
			if(!isValid(it)) return; 
			--size;
			node *t = it.getnode();   // разыменовали
			node *x = new node();
			node *y = new node();
			if(t->left != nullptr && t->right != nullptr)
			{
				y = next(t);
				x = nullptr;
				if(y == y->prev->left)
					y->prev->left = nullptr;
				else
					y->prev->right = nullptr;
				t->val = y->val;
			}
			else if(t->left != nullptr || t->right != nullptr)
			{
				*y = *t;
				if(y->left != nullptr)
					*x = *(y->left);
				else 
					*x = *(y->right);
			}
			else
			{
				*y = *t;
				x = nullptr;
			}
			if(x != nullptr)
			{
				*(x->prev) = *(y->prev);
			}
			if(y->prev == nullptr)
			{
				*root = *x;
			}
			else
			{
				if(y == y->prev->left)
					*(y->prev->left) = *x;
				else
					*(y->prev->right) = *x;
			}
		}


		iterator begin()
		{
			if(root == nullptr)
				return iterator(end_ptr);

			node *n = root;
			while(n->left != nullptr)
				n = n->left;

			return iterator(n);
		}

		iterator end()
		{
			return iterator(end_ptr);
		}

	private:
		node* root;   // корень
		node* end_ptr;

		bool isValid(iterator it)
		{
			//.. TBD
			return true;
		}

		node* prefixTravel(node* n)
		{
			node* t = new node(n->val);
			t->left = prefixTravel(n->left);
			t->right = prefixTravel(n->right);
			return t;
		}

		node* minimum(node* n)
		{
			while(n->left != nullptr)
				n = n->left;
			return n;
		}

		node* maximum(node* n)
		{
			while(n->right != nullptr)
				n = n->right;
			return n;
		}

		node* next(node* n)
		{
			if(n->right != nullptr)
				return minimum(n->right);
			node* y = n->prev;
			while(y != nullptr && n== y->right)
			{
				n = y;
				y = y->prev;
			}
			return n;
		}

		node* prev(node* n)
		{
			if(n->left != nullptr)
				return maximum(n->left);
			node* y = n->prev;
			while(y != nullptr && n == y->left)
			{
				n = y;
				y = y->prev;		
			}
			return y;
		}
		int size;
};
