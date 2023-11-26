/**
* @file BST.cpp
* @description 
* @course 1.Ögretim C grubu
* @assignment 3.Ödev 
* @date 13.12.2019
* @author Omar Alkadri omar.alkadri@ogr.sakarya.edu.tr
* @author Avad almohammadalibrahim awad.alibrahim@ogr.sakarya.edu*/
#include"Bst.hpp"
bstNod* Bst::NewNode(int data)
{
	bstNod* temp = new bstNod;
	temp->data = data;
	temp->NumberOfChildren = -1;
	temp->left = temp->right = nullptr;
	return temp;
}
bstNod* Bst::RootNode()const
{
	if (rootbst != nullptr)return rootbst;
	return nullptr;
}
void Bst::Insert(const int data)
{
	InsertData(rootbst, data);
}
bstNod* Bst::InsertData(bstNod* node, int data)
{
	if (rootbst == NULL)
		rootbst = NewNode(data);
	if (node == NULL)
		return NewNode(data);
	if (data < node->data || data == node->data)
		node->left = InsertData(node->left, data);
	else if (data > node->data)
		node->right = InsertData(node->right, data);
	return node;
}
int Bst::NumberTotal()
{
	if (rootbst != nullptr)
	{
		Total = 0;
		InsertNumber(rootbst);
		return NumberTotal(rootbst);
	}
}
int Bst::NumberTotal(bstNod* newNode)
{
	if (newNode != nullptr) {
		if (newNode != nullptr)
			Total += newNode->NumberOfChildren;
		NumberTotal(newNode->left);
		NumberTotal(newNode->right);
		return Total;
	}
}
void Bst::InsertNumber(bstNod* newNode)
{
	if (newNode != nullptr)
	{
		InsertNumber(newNode->left);
		InsertNumber(newNode->right);
		if (newNode != nullptr)
			newNode->NumberOfChildren = HowManyChildren(newNode) - 1;
	}
}
void Bst::postorder()
{
	if (rootbst != nullptr)
	{
		NumberTotal();
		postorder(rootbst);
	}
	else cout << "Agac Yok!" << endl;
}
void Bst::postorder(bstNod* newNode)
{
	if (newNode != nullptr)
	{
		postorder(newNode->left);
		postorder(newNode->right);
		if (newNode != nullptr)
			cout << "<" << newNode->data << "," << newNode->NumberOfChildren << "> ";
	}
}
int Bst::HowManyChildren(bstNod* Node)const
{
	if (Node == nullptr)
		return 0;
	return 1 + HowManyChildren(Node->left) + HowManyChildren(Node->right);
}
int Bst::FindTBigNumber()
{
	return FindTBigNumber(rootbst);
}

int Bst::FindTBigNumber(bstNod* node)
{
	int data;
	while (node != NULL && node->right != nullptr)
	{
		if (node->right->right == nullptr)
		{
			data = node->right->data;
			temp = node->right;
			if (node->left != nullptr)
				node->right = node->right->left;
			else node->right = NULL;
			delete temp;
			return data;
		}
		node = node->right;
	}
}

int Bst::RemoveRoot()
{
	if (rootbst != nullptr)
		return RemoveRoot(rootbst);
}
int Bst::RemoveRoot(bstNod* node)
{
	int data = rootbst->data;
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			if (node->left->right != nullptr) {
				node = node->left;
				while (node->right->right != nullptr)
					node = node->right;
				rootbst->data = node->right->data;
				temp = node->right;
				if (node->right->left != nullptr)
					node->right = node->right->left;
				else node->right = nullptr;
				delete temp;
				return data;
			}
			else
			{
				rootbst->data = node->left->data;
				temp = node->left;
				if (node->left->left != nullptr)
					node->left = node->left->left;
				else node->left = nullptr;
				delete temp;
				return data;
			}
		}
		else if (node->right != nullptr)
		{
			if (node->right->left != nullptr) {
				node = node->right;
				while (node->left->left != nullptr)
					node = node->left;
				rootbst->data = node->left->data;
				temp = node->left;
				if (node->left->right != nullptr)
					node->left = node->left->right;
				else node->left = nullptr;
				delete temp;
				return data;
			}
		}
	}
	if (node->left == nullptr && node->right == nullptr)
	{
		temp = node;
		node = nullptr;
		rootbst = NULL;
		delete temp;
		return data;
	}
	if (node->left != nullptr && node->right == nullptr)
	{
		rootbst->data = node->left->data;
		temp = node->left;
		if (node->left->left != nullptr)
			node->left = node->left->left;
		else node->left = nullptr;
		delete temp;
		return data;
	}
	if (node->left == nullptr && node->right != nullptr)
	{
		rootbst->data = node->right->data;
		temp = node->right;
		if (node->right->right != nullptr)
			node->right = node->right->right;
		else node->right = nullptr;
		delete temp;
		return data;
	}
	return data;
}
void Bst::RemoveNode()
{
	if (rootbst != nullptr)
	RemoveNode(rootbst);
	rootbst = nullptr;
}
void Bst::RemoveNodeRight(bstNod* node)
{
	if (node != nullptr)
	{
		if (node->right != nullptr)
			RemoveNodeLeft(node->right);
		if (node->left != nullptr)
			RemoveNodeLeft(node->left);
		temp = node;
		node = nullptr;
		delete temp;
	}
}
void Bst::RemoveNodeLeft(bstNod* node)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
			RemoveNodeLeft(node->left);
		if (node->right != nullptr)
			RemoveNodeLeft(node->right);
		temp = node;
		node = nullptr;
		delete temp;
	}
}
void Bst::RemoveNode(bstNod* deleteNode)
{
	if (deleteNode != nullptr)
	{
		if (deleteNode->left != nullptr)
		{
			RemoveNodeRight(deleteNode->left);
			if (deleteNode->right != nullptr)
			{
				RemoveNodeLeft(deleteNode->right);
			}
			temp = deleteNode;
			deleteNode = nullptr;
			delete temp;
		}
		else if (deleteNode->right != nullptr)
		{
			RemoveNodeLeft(deleteNode->right);
			temp = deleteNode;
			deleteNode = nullptr;
			delete temp;
		}
		else
		{
			temp = deleteNode;
			deleteNode = nullptr;
			delete temp;
		}
	}
}
Bst::~Bst()
{
	if (rootbst != nullptr)
	RemoveNode();
}
/*
int Bst::Search(bstNod* root1, int data)
{
	if (root1 != nullptr && root1->data == data)
		return data;
	if (root1 != nullptr && root1->data < data) {
		if (root1->right == nullptr)
		{
			return root1->data;
		}
		return Search(root1->right, data);
	}

	if (root1 != nullptr && root1->data > data)
	{
		if (root1->left == nullptr)
		{
			return root1->data;
		}
		return  Search(root1->left, data);
	}
}
*/
/*int Bst::Search(bstNod* root1, const int data)
{
	if (root1 != nullptr && root1->data == data)
		return data;
	if (root1 != nullptr && root1->data < data) {
		return Search(root1->right, data);

	}
	if (root1 != nullptr && root1->data > data)
	{
		return  Search(root1->left, data);
	}
}*/

/*
	void Bst::RemoveNode(bstNod* deleteNode)
{
	if (deleteNode != nullptr)
	{
		if (deleteNode->left != nullptr)
		{
			if (deleteNode->left->right != nullptr) {
				deleteNode = deleteNode->left;
				while (deleteNode->right->right != nullptr) {
					deleteNode = deleteNode->right;
				}
				temp = deleteNode->right;
				if (deleteNode->right->left != nullptr)
					deleteNode->right = deleteNode->right->left;
				else deleteNode->right = nullptr;
				delete temp;
			}
			else
			{
				temp = deleteNode->left;
			if (deleteNode->left->left != nullptr)
				deleteNode->left = deleteNode->left->left;
			else deleteNode->left = nullptr;
			delete temp;
		}
	}
	else if (deleteNode->right != nullptr)
	{
		if (deleteNode->right->left != nullptr) {
			deleteNode = deleteNode->right;
			while (deleteNode->left->left != nullptr) {
				deleteNode = deleteNode->left;
			}
			temp = deleteNode->left;
			if (deleteNode->left->right != nullptr)
				deleteNode->left = deleteNode->left->right;
			else deleteNode->left = nullptr;
			delete temp;
		}
}
}
if (rootbst->left == nullptr && rootbst->right == nullptr)
{
	temp = deleteNode;
	deleteNode = nullptr;
	rootbst = NULL;
	delete temp;
}
if (deleteNode->left != nullptr && deleteNode->right == nullptr)
{
	temp = deleteNode->left;
	if (deleteNode->left->left != nullptr)
		deleteNode->left = deleteNode->left->left;
	else deleteNode->left = nullptr;
	delete temp;
}
if (deleteNode->left == nullptr && deleteNode->right != nullptr)
{
	temp = deleteNode->right;
	if (deleteNode->right->right != nullptr)
		deleteNode->right = deleteNode->right->right;
	else deleteNode->right = nullptr;
	delete temp;
}*/
/*	if (rootbst != nullptr)
	{
		if (rootbst->data == data)
		{
		}
		else
		{
			if (data < deleteNode->data && deleteNode->left != nullptr)
			{
				deleteNode->left->data == data ? 5 : 4;
			}
			else if (data > deleteNode->data&& deleteNode->right != nullptr)
			{
				deleteNode->right->data == data ? 5 : 4;
			}
		}
	}
	}*/
	/*int Bst::FindTSmullNumber()
	{
		return FindTSmullNumber(rootbst);
	}
	int Bst::FindTSmullNumber(bstNod* node)
	{
		int data;
		while (node != NULL && node->left != nullptr)
		{
			if (node->left->left == nullptr)
			{
				data = node->left->data;
				temp = node->left;
				if (node->right != nullptr)
					node->left = node->left->right;
				else node->left = NULL;
				delete temp;
				return data;
			}
			node = node->left;
		}
	}*/