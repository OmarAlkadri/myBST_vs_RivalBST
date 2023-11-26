/**
* @file B_S_T_Control.cpp
* @description 
* @course 1.Ögretim C grubu
* @assignment 3.Ödev 
* @date 13.12.2019
* @author Omar Alkadri omar.alkadri@ogr.sakarya.edu.tr
* @author Avad almohammadalibrahim awad.alibrahim@ogr.sakarya.edu*/
#include"B_S_T_Control.hpp"

/*void Control::Search(Bst* p1, Bst* p2)
{
	bstNod* temp;
	if (p1->RootNode() != nullptr && p2->RootNode() != nullptr)
	{
		if (temp == NULL)
		{
			temp = p2->RootNode();
		}
		if (temp != nullptr && p->Search(p1->RootNode(), temp->data) == temp->data)
		{
			cout << "True";
			return;
		}
		if (temp->right != nullptr && p1->RootNode()->data > temp->data)
		{
			temp = temp->right;
			Search(p1, p2);
		}
		if (temp->left != nullptr && p1->RootNode()->data < temp->data)
		{
			temp = temp->left;
			Search(p1, p2);
		}
	}
}*/
Control::Control()
{
	benimTuru = 0;
	rakipTuru = 0;
	turSayisi = 0;
	
}

void Control::Vs(Bst* p1, Bst* p2)
{
	while (true) {
		system("pause");
		if (p1->RootNode() != nullptr && p2->RootNode() != nullptr)
		{


			int p11 = p1->NumberTotal();// daha hizli olma acisindan bir deva okuyup sartlara bakar
			int p22 = p2->NumberTotal();
			if (benimTuru != 5 && rakipTuru != 5 && turSayisi < 20)
			{
				turSayisi++;
				if (p11 < p22)
				{
					benimTuru++;
					if (p2->RootNode()->right != nullptr)
						p1->Insert(p2->FindTBigNumber());
					if (p1->RootNode() != nullptr)
						p2->Insert(p1->RemoveRoot());
					p1->NumberTotal();
					p2->NumberTotal();
					cout << "Benim Agac PostOrder :\n";
					p1->postorder();
					cout << "\nBenim Agac Toplam Soy Sayisi : " << p1->NumberTotal() << endl;
					cout << "---------------------\n\n";
					cout << "Rakip Agac PostOrder :\n";
					p2->postorder();
					cout << "\nRakip Agac Toplam Soy Sayisi : " << p2->NumberTotal() << endl;
					cout << "---------------------\n\n";
					cout << "--TEBRIKLER TURU KAZANDINIZ--\n\n";
					cout << "SKOR";
					cout << "\nBenim : " << benimTuru;
					cout << "\nRakip : " << rakipTuru;
					cout << "\n------------------------------------------------------------------" << endl;
				}
				else if (p11 > p22)
				{
					rakipTuru++;
					if (p1->RootNode()->right != nullptr)
						p2->Insert(p1->FindTBigNumber());
					if (p2->RootNode() != nullptr)
						p1->Insert(p2->RemoveRoot());
					p1->NumberTotal();
					p2->NumberTotal();
					cout << "Benim Agac PostOrder :\n";
					p1->postorder();
					cout << "\nBenim Agac Toplam Soy Sayisi : " << p1->NumberTotal() << endl;
					cout << "---------------------\n\n";
					cout << "Rakip Agac PostOrder :\n";
					p2->postorder();
					cout << "\nRakip Agac Toplam Soy Sayisi : " << p2->NumberTotal() << endl;
					cout << "---------------------\n\n";
					cout << "--UZGUNUM RAKIP KAZANDI--\n\n";
					cout << "SKOR";
					cout << "\nBenim : " << benimTuru;
					cout << "\nRakip : " << rakipTuru;
					cout << "\n------------------------------------------------------------------" << endl;
				}
				else if (p11 == p22)
				{
					p1->Insert(p2->RemoveRoot());
					p2->Insert(p1->RemoveRoot());
					p1->NumberTotal();
					p2->NumberTotal();
					cout << "Benim Agac PostOrder :\n";
					p1->postorder();
					cout << "\nBenim Agac Toplam Soy Sayisi : " << p1->NumberTotal() << endl;
					cout << "---------------------\n\n";
					cout << "Rakip Agac PostOrder :\n";
					p2->postorder();
					cout << "\nRakip Agac Toplam Soy Sayisi : " << p2->NumberTotal() << endl;
					cout << "---------------------\n\n";
					cout << "--BERABERLIK--\n\n" << endl;
					cout << "SKOR";
					cout << "\nBenim : " << benimTuru;
					cout << "\nRakip : " << rakipTuru;
					cout << "\n------------------------------------------------------------------" << endl;

				}
			}
			else
			{
				return;
			}
			/*else
			{
				system("cls");
				if (benimTuru == 5 || rakipTuru == 5 && turSayisi < 20)
					cout << "\n5 Tur Kazinildi Oyun Biti Tekrari Izlemebilirsiniz.\n";
				if (benimTuru != 5 && rakipTuru != 5 && turSayisi == 20)
					cout << "\nOyun Biti 20 Tur oynalindi Ama Kimse 5 Tur Kazanamadi.\n";
				if (benimTuru == 5 || benimTuru > rakipTuru)
					cout << "--TEBRIKLER TURU KAZANDINIZ--\n\n";
				else if (rakipTuru == 5 || rakipTuru > benimTuru)
					cout << "--UZGUNUM RAKIP KAZANDI--\n\n";
				else
					cout << "--BERABERLIK--\n\n" << endl;
				cout << "SKOR";
				cout << "\nBenim : " << benimTuru;
				cout << "\nRakip : " << rakipTuru;
				cout << "\n------------------------------------------------------------------" << endl;
			}*/
		}
		else cout << "Agac Yok !!!" << endl;
	}
}