/* Ex.12.2: Усовершенствуйте объявление класса S t r i n g (т. е . замените s t r i n g l . h на
s t r i ng2 . h) , выполнив перечисленные ниже действия.
а. Перегрузите операцию + для объединения д вух строк в одну 
б. Напишите функцию-член s t r i n g low ( ) , которая преобразует в с е буквенные
символы в строке в нижний регистр . (Не забудьте о семействе c c t ype символьных
функци й . )
в. Напишите функцию-член s t r i ngup ( ) , которая преобразует в с е буквенные
символы в строке в верхний регистр.
г. Напишите функцию-член, которая принимает аргумент типа char и возвраща-
ет количество раз, которое символ появляется в строке. */

#include <iostream>
using namespace std;
#include "string2.h"

int main()
{
	String sl (" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + sl; 
	cout << s2 << "\n";
	s2.stringup(); 
	cout << s2 << "\n";
	cout << "The string\n" << s2 << "\ncontains " << s2.has ('A')
		 << "'A' characters in it.\n";
	sl = "red"; 
	String rgb[3] = {String(sl), String ("green"), String ("blue")};
	cout << "Enter the name of aprimary color for mixing light: "; 
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		
		for (int i=0; i < 3; i++)
		{
			if (ans == rgb [i])
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye\n";
	
	return 0;
}