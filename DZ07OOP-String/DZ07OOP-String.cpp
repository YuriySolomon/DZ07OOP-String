#include "String.h"

int main()
{
	setlocale(0, "");
	String s;
	s.SetString("Solomon");
	s.ShowInfo();
	//String s1(" Yuriy");
	
	String s4("I live and work in London");
	
	cout << "===========================\n";

	int count = 0;
	char c = ' ';
	String* ptr = nullptr;
	cout << s4 << "\n";
	ptr = s4.Split(c, count);
	cout << "===========================\n";
	for (int i = 0; i < count; i++)
	{
		cout << ptr[i] << "\n";
	}

	/*s1.PrintLn();
	s1 = s;
	cout << s1 << "\n";*/
	
	/*s.SetString("I live in Boston");
	cout << s.ToLower() << "\n";
	cout << s.ToUpper() << "\n";*/

	//s.SetString("Я живу в Бостоне");
	//s.SetString("I live IN Boston");
	//s.SetString("Я ЖИВУ в Бостоне");
	/*s.SetString("Solomon");
	s.PrintLn();
	s4.PrintLn();
	cout << boolalpha << s.Equals(s4) << "\n";
	cout << s.CompareTo(s4) << "\n";*/

	/*const char* p = nullptr;
	p = s.GetCharArray();
	cout << p << "\n";*/
	
	//cout << s.LastIndexOf(s4) << "\n";	
	//cout << s.IndexOf(s4) << "\n";
	//cout << s.LastIndexOf('g') << "\n";
	//cout << s.IndexOf('k') << "\n";
			
	system("pause >> NULL");
}

