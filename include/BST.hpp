/**
* @file BST.hpp
* @description 
* @course 1.Ögretim C grubu
* @assignment 3.Ödev 
* @date 13.12.2019
* @author Omar Alkadri omar.alkadri@ogr.sakarya.edu.tr
* @author Avad almohammadalibrahim awad.alibrahim@ogr.sakarya.edu*/
#define BST_HPP
#ifdef BST_HPP
#include <iostream>
using namespace std;
struct bstNod
{
	int data;
	int NumberOfChildren;
	bstNod* right;
	bstNod* left;
};
class Bst
{
private:
	bstNod* rootbst;
	bstNod* temp;
	bstNod* NewNode(const int data);
	bstNod* InsertData(bstNod*, const int);
	int HowManyChildren(bstNod*)const;
	void postorder(bstNod*);
	int FindTBigNumber(bstNod*);
	//int FindTSmullNumber(bstNod*);
	int RemoveRoot(bstNod*);
	void RemoveNode(bstNod*);
	int NumberTotal(bstNod*);
	void InsertNumber(bstNod*);
	//int Search(bstNod*, const int);
	int Total;
	void RemoveNodeLeft(bstNod*);
	void RemoveNodeRight(bstNod*);
public:
	void RemoveNode();
	int RemoveRoot();
	bstNod* RootNode()const;
	int FindTBigNumber();
	//int FindTSmullNumber();
	int NumberTotal();
	void Insert(const int data);
	void postorder();
	~Bst();
};
#endif // BST_HPP
