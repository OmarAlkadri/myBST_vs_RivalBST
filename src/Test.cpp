/**
* @file Test.cpp
* @description 
* @course 1.Ögretim C grubu
* @assignment 3.Ödev 
* @date 13.12.2019
* @author Omar Alkadri omar.alkadri@ogr.sakarya.edu.tr
* @author Avad almohammadalibrahim awad.alibrahim@ogr.sakarya.edu*/
#include"B_S_T_Control.hpp"
#include <fstream>
int main()
{
	Bst* benim = new Bst();
	Bst* rakip = new Bst();
	Control* p1 = new Control;
	ifstream MyFile(".\\doc\\benim.txt");
	ifstream HeFile(".\\doc\\rakip.txt");
	int line;
	int line1;
	if (MyFile.is_open())
	{
		while (MyFile >> line)
		{
			benim->Insert(line);
		}
	}
	if (HeFile.is_open())
	{
		while (HeFile >> line1)
		{
			rakip->Insert(line1);
		}
	}
	cout << "Benim Agac PostOrder :\n";
	benim->postorder();
	cout << "\nBenim Agac Toplam Soy Sayisi : " << benim->NumberTotal() << endl;
	cout << "---------------------\n\n";
	cout << "Rakip Agac PostOrder :\n";
	rakip->postorder();
	cout << "\nRakip Agac Toplam Soy Sayisi : " << rakip->NumberTotal() << endl;
	cout << "---------------------\n\n";
	/*while (i < sayigir)
	{
		while (sayigir > 20 || 5 > sayigir)
		{
			system("cls");
			cout << "girilen Tur sayisi 5 le 20 arasi olmaktadir.\nlutfan Sagyi giriniz :";
			cin >> sayigir;
			system("cls");
			cout << "Benim Agac PostOrder :\n";
			benim->postorder();
			cout << "\nBenim Agac Toplam Soy Sayisi : " << benim->NumberTotal() << endl;
			cout << "---------------------\n\n";
			cout << "Rakip Agac PostOrder :\n";
			rakip->postorder();
			cout << "\nRakip Agac Toplam Soy Sayisi : " << rakip->NumberTotal() << endl;
			cout << "---------------------\n\n";

		}
		p1->Vs(benim, rakip);
		cout << "Benim Agac PostOrder :\n";
		benim->postorder();
		cout << "\nBenim Agac Toplam Soy Sayisi : " << benim->NumberTotal() << endl;
		cout << "---------------------\n\n";
		cout << "Rakip Agac PostOrder :\n";
		rakip->postorder();
		cout << "\nRakip Agac Toplam Soy Sayisi : " << rakip->NumberTotal() << endl;
		cout << "---------------------\n\n";
		i++;
	}*/
	p1->Vs(benim, rakip);

	return 0;
}