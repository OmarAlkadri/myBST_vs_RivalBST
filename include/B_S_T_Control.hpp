/**
* @file B_S_T_Control.hpp
* @description 
* @course 1.Ögretim C grubu
* @assignment 3.Ödev 
* @date 13.12.2019
* @author Omar Alkadri omar.alkadri@ogr.sakarya.edu.tr
* @author Avad almohammadalibrahim awad.alibrahim@ogr.sakarya.edu*/
#define CONTROL_HPP
#ifdef CONTROL_HPP
#include"BST.hpp"

class Control
{
private:
	int turSayisi;
	int benimTuru;
	int rakipTuru;
public:
	//void Search(Bst*, Bst*);
	void Vs(Bst*, Bst*);
	Control();
};
#endif // CONTROL_HPP