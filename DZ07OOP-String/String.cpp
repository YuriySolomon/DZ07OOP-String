#include "String.h"

String::String() : String("", 50) {}
String::String(const char* text) : String(text, 50) {}
String::String(unsigned int capacity) : String("", capacity) {}
String::String(const String& original) : String(original.text, original.capacity) {}
String::String(const char* text, unsigned int capacity)
{
	SetString(text, capacity);
}
String::~String()
{
	if (text != nullptr) delete[] text;
}

void String::SetString(const char* text, unsigned int capacity)
{
	size = strlen(text);
	if (capacity <= size)
	{
		capacity = size + 1;
	}
	this->capacity = capacity;
	delete[] this->text;
	this->text = new char[capacity];
	strcpy_s(this->text, size + 1, text);
}


unsigned int String::GetSize() const
{
	return size;
}
unsigned int String::GetCapacity() const
{
	return capacity;
}
char* String::GetString() const
{
	return text;
}
void String::Clear()
{
	text[0] = 0;
	size = 0;
}
void String::ShowInfo() const
{
	cout << "Text: " << GetString() << "\n";
	cout << "Size: " << GetSize() << "\n";
	cout << "Capacity: " << GetCapacity() << "\n";
}
void String::ShrinkToFit()
{
	if (size + 1 <= capacity)
	{
		return;
	}
	capacity = size + 1;
	char* temp = new char[capacity];
	strcpy_s(temp, capacity, text);
	delete[] text;
	text = temp;
}
char String::GetCharAt(unsigned int index)
{
	if (index > 0 && index < size)
	{
		return text[index];
	}
	else
	{
		throw "Error";
	}
}
void String::Print() const
{
	cout << text;
}
void String::PrintLn() const
{
	cout << text << "\n";
}
void String::GetLine()
{
	string s;
	cout << "\nEnter a string and press Enter: ";
	getline(cin, s);
	unsigned int size = s.length();
	const char* temp = new char[size];
	temp = s.c_str(); // The pointer obtained from c_str() may only be treated as a pointer to a null-terminated character string if the string object does not contain other null characters.
	SetString(temp);
}
const char* String::GetCharArray() const
{
	if (text != nullptr) return this->text;
}
void String::Concat(const String& s)
{
	size += s.size;
	char* temp = new char[size + 1];
	strcpy_s(temp, size, text);
	strcat_s(temp, size + 1, s.text);
	SetString(temp);
}
void String::Concat(const char* text)
{
	size += strlen(text);
	char* temp = new char[size + 1];
	strcpy_s(temp, size, this->text);
	strcat_s(temp, size + 1, text);
	SetString(temp);
}
void String::Concat(int num)
{
	int size_num = 1;
	int temp = num;
	while ((temp /= 10) > 0)
	{
		size_num++;
	}
	char temp_num[10] = {};
	_itoa_s(num, temp_num, 10);	
	cout << "temp_num = " << temp_num << "\n";
	Concat(temp_num);
}
int String::CompareTo(const String& s)
{
	if (size == s.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (text[i] != s.text[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}	
}
int String::CompareTo(const char* s)
{
	if (size == strlen(s))
	{
		for (int i = 0; i < size; i++)
		{
			if (text[i] != s[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
bool String::Contains(const String& s)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (text[i] == s.text[j])
		{
			j++;
		}
		else
		{
			j = 0;
		}
		if (j == s.size)
		{
			return true;
		}
	}
	return false;
}
bool String::EndsWith(const String& s)
{	
	int j = s.size - 1;
	for (int i = size - 1; i >= 0; i--)
	{
		if (text[i] == s.text[j] && j >= 0)
		{
			j--;
		}
		else
		{
			return false;
		}
		if (j < 0)
		{
			return true;
		}		
	}
}
bool String::StartsWith(const String& s)
{
	for (int i = 0; i < size; i++)
	{
		if (text[i] != s.text[i] && i < s.size)
		{
			return false;
		}		
		if (i == s.size)
		{
			return true;
		}
	}
}
bool String::Equals(const String& s)
{
	return CompareTo(s) == 0 ? false : true;
}
int String::IndexOf(char c)
{
	for (int i = 0; i < size; i++)
	{
		if (text[i] == c)
		{
			return i;
		}
	}
	return -1;
}
int String::LastIndexOf(char c)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (text[i] == c)
		{
			return i;
		}
	}
	return -1;
}
int String::IndexOf(const String& s)
{
	int j = 0;
	int temp = -1;
	for (int i = 0; i < size; i++)
	{
		if (text[i] == s.text[j] && j < s.size)
		{
			j++;
		}
		else if (text[i] != s.text[j])
		{
			j = 0;
			temp = -1;
		}
		if (j == 1)
		{
			temp = i;
		}
		if (j == s.size)
		{
			return temp;
		}
	}
	return temp;
}
int String::LastIndexOf(String& s)
{
	int j = s.size - 1;
	int temp = -1;
	for (int i = size - 1; i >= 0; i--)
	{
		if (text[i] == s.text[j] && j >= 0)
		{
			j--;
		}
		else if (text[i] != s.text[j])
		{
			j = s.size - 1;
			temp = -1;
		}
		if (j < 0)
		{
			temp = i;
			return temp;
		}
	}
	return temp;
}
void String::Remove(unsigned int index)
{
	if (index < 0 || index > size)
	{
		throw "Invalid value entered";
	}
	char* temp = new char[size] {};
	for (int i = 0; i < index; i++)
	{
		temp[i] = text[i];		
	}
	size = index;
	SetString(temp);	
}
void String::Remove(unsigned int start, unsigned int count)
{
	if (start < 0 || count < 0 || start + count > size)
	{
		throw "Invalid value entered";
	}
	unsigned int temp_count = count;
	char* temp = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		if (i < start)
		{
			temp[i] = text[i];
		}
		else if	(i >= start && temp_count != 0)
		{
			temp_count--;
		}
		else
		{
			temp[i - count] = text[i];
		}
	}
	size -= count;
	SetString(temp);
}
void String::Replace(char R, char Z)
{
	for (int i = 0; i < size; i++)
	{
		if (R == text[i])
		{
			text[i] = Z;
		}		
	}
}
void String::Replace(const String& substr, const String& rep)
{
	int prov = 0;
	prov = IndexOf(substr);
	if (prov == -1)
	{
		cout << "The entered substring does not exist in the existing string\n";
		return;
	}
	else
	{
		char* temp = new char[capacity] {};
		int j = 0;
		int k = 0;
		int new_size = size >= (size - substr.size + rep.size) ? size : (size - substr.size + rep.size);
		for (int i = 0; i < new_size; i++)
		{
			if (i < prov)
			{
				temp[i] = text[k];
				k++;
			}
			else if (i >= prov && j < rep.size)
			{
				temp[i] = rep.text[j];
				j++;
			}
			else
			{
				temp[i] = text[k + substr.size];
				k++;
			}
		}
		SetString(temp);
	}
}
String* String::Split(char separator, int& pieces)
{
	for (int i = 0; i < size; i++)
	{
		if (text[i] == separator)
		{
			pieces++;		
		}
	}
	pieces++;
	String* ptr = new String[pieces + 1];
	int j = 0;
	int k = 0;
	char* temp = new char[capacity];
	for (int i = 0; i < size; i++)
	{
		if (text[i] == separator)
		{			
			temp[k] = '\0';
			ptr[j].SetString(temp);
			j++;
			k = 0;
		}
		else if (i == size - 1)
		{
			temp[k++] = text[i];
			temp[k] = '\0';
			ptr[j].SetString(temp);
		}
		else
		{
			temp[k] = text[i];
			k++;
		}
	}
	return ptr;
}
String String::ToLower() const
{
	char* temp = new char[capacity]{};
	for (int i = 0; i < size; i++)
	{
		if (text[i] >= 'A' && text[i] <= 'Z')
		{
			text[i] -= 'Z' - 'z';
		}
		else if (text[i] >= 'À' && text[i] <= 'ß')
		{
			text[i] -= 'ß' - 'ÿ';
		}
	}
	strcpy_s(temp, capacity, text);
	return temp;
}
String String::ToUpper() const
{
	char* temp = new char[capacity] {};
	for (int i = 0; i < size; i++)
	{
		if (text[i] >= 'a' && text[i] <= 'z')
		{
			text[i] += 'A' - 'a';
		}
		else if (text[i] >= 'à' && text[i] <= 'ÿ')
		{
			text[i] += 'À' - 'à';
		}
	}
	strcpy_s(temp, capacity, text);
	return temp;
}
void String::Trim()
{
	TrimStart();
	TrimEnd();
}
void String::TrimEnd()
{
	char* temp = new char[capacity] {};
	bool end = true;
	for (int i = size - 1; i >= 0; i--)
	{
		if (text[i] == ' ' && end)
		{
			continue;
		}
		else if (text[i] != ' ' && end)
		{
			temp[i] = text[i];
			end = false;
		}
		else
		{
			temp[i] = text[i];
		}
	}
	SetString(temp);
}
void String::TrimStart()
{
	char* temp = new char[capacity] {};
	bool start = true;
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (text[i] == ' ' && start)
		{
			continue;
		}
		else if (text[i] != ' ' && start)
		{
			temp[j] = text[i];
			j++;
			start = false;
		}
		else
		{
			temp[j] = text[i];
			j++;
		}
	}
	SetString(temp);
}
void String::Reverse()
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(text[i], text[size - i - 1]);
	}
}
void String::SortAZ()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (text[j] > text[j + 1])
			{
				swap(text[j], text[j + 1]);
			}
		}
	}
}
void String::SortZA()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (text[j] < text[j + 1])
			{
				swap(text[j], text[j + 1]);
			}			
		}		
	}
}
void String::Shuffle()
{
	for (int i = 0; i < size; i++)
	{
		swap(text[rand() % (size - 1)], text[rand() % (size - 1)]);
	}
}
void String::RandomFill()
{
	char* temp = new char[capacity + 1] {};
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = char('a' + rand() % ('z' - 'a'));
	}
	SetString(temp);
}

String& String::operator = (const String& s)
{
	delete[] text;
	size = s.size;
	capacity = s.capacity;
	text = new char[capacity] {};
	for (int i = 0; i < s.size; i++)
	{
		text[i] = s.text[i];
	}
	return *this;
}
ostream& operator << (ostream& os, const String& s)
{
	for (int i = 0; i < s.size; i++)
	{
		os << s.text[i];
	}
	return os;
}