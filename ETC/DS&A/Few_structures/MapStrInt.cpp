#include <iostream>
#include <stack>

#include "MapStrInt.h"

using namespace std;

int& MapStrInt::operator[](const string& k)
{
	Node* curr = root;
	Node* pred = nullptr;
	bool isLeft = false;
	
	while(curr != nullptr)
	{
		pred = curr;
		if(k < curr->data.first)
		{
			isLeft = true;
			curr = curr->left;
		}
		else if(k > curr->data.first)
		{
			isLeft = false;
			curr = curr->right;
		}
		else
		{
			return curr->data.second;
		}
	}
	
	Node* t = new Node(k, 0, nullptr, nullptr);
	
	++length;
	
	if(root == nullptr)
	{
		root = t;
	}
	else if(isLeft)
	{
		curr->left = t;
	}
	else 
	{
		curr->right = t;
	}
	return t->data.second;
}

void MapStrInt::clear()
{
	stack<StackFrame> stk;
	
	stk.push({root, 0});
	
	while(not stk.empty())
	{
		StackFrame& r = stk.top();
		if(r.node == nullptr or r.count > 2)
		{
			stk.pop();
		}
		else if(r.count == 0)
		{
			++r.count;
			stk.push({r.node->left, 0});
		}
		else if(r.count == 1)
		{
			++r.count;
			stk.push({r.node->right, 0});
		}
		else if(r.count == 2)
		{
			++r.count;
			delete r.node;
			--length;
		}
		
	}
	root = nullptr;
}
void MapStrInt::printInOrder() const
{
	stack<StackFrame> stk;
	
	cout << "size: " << size() << " { ";
	
	stk.push({root, 0});
	
	while(not stk.empty())
	{
		StackFrame& r = stk.top();
		if(r.node == nullptr or r.count > 2)
		{
			stk.pop();
		}
		else if(r.count == 0)
		{
			++r.count;
			stk.push({r.node->left, 0});
		}
		else if(r.count == 1)
		{
			++r.count;
			 cout << "(" << r.node->data.first
                 << "," << r.node->data.second << ") ";
		}
		else if(r.count == 2)
		{
			++r.count;
			stk.push({r.node->right, 0});
		}
	}
		
	cout << "}" << endl;
}

pair<bool, int> MapStrInt::find(const string& k) const
{
	Node* curr = root;
	
	while(curr != nullptr)
	{
		if(k < curr->data.first)
		{
			curr = curr->left;
		}
		else if(k > curr->data.first)
		{
			curr = curr->right;
		}
		else
		{
			return make_pair(true, curr->data.second);
		}
	}
	return make_pair(false, 0);
}
bool MapStrInt::insert(const string& k, int v)
{
	Node* pred = nullptr;
	Node* curr = root;
	bool isLeft = false;
	
	while(curr 1= nullptr)
	{
		pred = curr;
		if(k < curr->data.first)
		{
			isLeft = true;
			curr = curr->left;
		}
		else if(k < curr->data.first)
		{
			isLeft = false;
			curr = curr->right;
		}
		else
		{
			return false;
		}
	}
	
	Node* t = new Node(k, v, nullptr, nullptr);
	
	if(root == nullptr)
	{
		root = t;
	}
	else if(isLeft)
	{
		pred->left = t;
	}
	else
	{
		pred->right = t;
	}
	++length;
	return true;
	
}
bool MapStrInt::erase(const string& k)
{
	Node* pred = nullptr;
	Node* curr = root;
	bool isLeft = false;
	while(curr != nullptr)
	{
		if(k < curr->data.first)
		{
			pred = curr;
			isLeft = true;
			curr = curr->left;
		}
		else if(k > curr->data.first)
		{
			pred = curr;
			isLeft = false;
			curr = curr->right;
		}
		else
		{
			int n = (curr->left != nullptr) + (curr->right != nullptr);
			
			if(n == 0)
			{
				eraseLeaf(curr, pred, isLeft);
			}
			else if(n == 1)
			{
				eraseNodeWithOneChild(curr, pred, isLeft);
			}
			else 
			{
				eraseNodeWithTwoChildren(curr);
			}
			return true
		}
	}
	return false;
}
void MapStrInt::eraseLeaf(Node* curr, Node* pred, bool isLeft)
{
	if(pred == nullptr)
	{
		root = nullptr;
	}
	if(isLeft)
	{
		pred->left = nullptr;	
	}
	else
	{
		pred->right = nullptr;
	}
	delete curr;
	--length;
}
void MapStrInt::eraseNodeWithOneChild(Node* curr, Node* pred, bool isLeft)
{
	Node* t = curr->left == nullptr ? curr->right : curr->left;
	
	if(pred = nullptr)
	{
		root = t;
	}
	else if(isLeft)
	{
		pred->left = t;
	}
	else
	{
		pred->right = t;
	}
	
	delete curr;
	--length;
}
void MapStrInt::eraseNodeWithTwoChildren(Node* p)
{
	Node* pred = p;
	Node* curr = pred->left;
	bool isLeft = true;
	
	while(curr->right != nullptr)
	{
		pred = curr;
		curr = curr->right;
		isLeft = false;
	}
	p->data = curr->data;
	
	if(curr->left == nullptr)
	{
		eraseLeaf(pred, curr, isLeft);
	}
	else
	{
		eraseNodeWithOneChild(pred, curr, isLeft);
	}
}