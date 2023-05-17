/* Ex.13.3: Перепишите иерархию классов ba s e DMA- l a c k s DMA-ha s DMA таким образом,
чтобы все три класса были порождены от абстрактного базового класса.
Протестируйте результат с помощью программы, подобной приведенной в листинге
1 3 . 1 0 . То есть она должна использовать массив указателей на абстрактный
базовый класс и позволять пользователю принимать во время работы программы
решения о том, объекты какого типа создавать. Добавьте в определения клас */

// usebrass2.cpp -- polymorphic example
// compile with brass.cpp
#include <iostream>
#include <cstring>
#include <string>
#include "dma.h"
const int CLIENTS = 4;

int main()
{
   using std::cin;
   using std::cout;
   using std::endl;

   Ab_DMA * p_clients[CLIENTS];
   
   char kind;
   int temp_rating;
   char temp_char[50];
   char temp_char_2[50];

   for (int i = 0; i < CLIENTS; i++)
   {
       cout << "Enter label's name: ";
	   cin.getline(temp_char, 49);
       cout << "Enter its rating: ";
       cin >> temp_rating;
       cout << "Enter 0 for baseDMA, 1 for lacksDMA or "
            << "2 for hasDMA Account: ";
       while (cin >> kind && (kind != '0' && kind != '1' && kind != '2'))
           cout <<"Enter either 0, 1 or 2: ";
	   cin.get();
       if (kind == '0')
           p_clients[i] = new baseDMA(temp_char, temp_rating);
       else if (kind == '1')
       {
           cout << "Enter the color: ";
		   cin.getline(temp_char_2, 49);
           p_clients[i] = new lacksDMA(temp_char_2, temp_char, temp_rating);
        }
		else 
		{
			cout << "Enter the style: ";
			cin.getline(temp_char_2, 49);
			p_clients[i] = new hasDMA(temp_char_2, temp_char, temp_rating);
		}
   }
   cout << endl;
   for (int i = 0; i < CLIENTS; i++)
   {
       p_clients[i]->View();
       cout << endl;
   }
              
   for (int i = 0; i < CLIENTS; i++)
   {
       delete p_clients[i];  // free memory
   }
   cout << "Done.\n";         
 
   return 0; 
}
