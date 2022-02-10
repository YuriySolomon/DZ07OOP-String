#pragma once
#include "AllLibraries.h"

class String
{
	char* text = nullptr;
	unsigned int size = 0;
	unsigned int capacity = 50;

	//void EnsureCapacity(int size); // memory check

public:
	String();
	String(const char* text);
	explicit String(unsigned int capacity);
	String(const String& original);
	String(const char* text, unsigned int capacity);
	~String();

	void SetString(const char* text, unsigned int capacity = 50);
	unsigned int GetSize() const;
	unsigned int GetCapacity() const;
	char* GetString() const;

	void Clear(); // Line cleaning
	void ShowInfo() const; // Displaying information about a string
	void ShrinkToFit();
	char GetCharAt(unsigned int index); // Returns the character of the string at the specified position
	void Print() const; // Displaying a line on the screen
	void PrintLn() const; // Display a line on the screen with the cursor moving to the next line
	void GetLine(); // Entering a string from the keyboard
	const char* GetCharArray() const; // Returning a constant pointer to an array of string characters
	void Concat(const String& s); //Append the given string to our string
	void Concat(const char* text); //Append an array of characters to our string
	void Concat(int num); //Append an array of characters to our string
	int CompareTo(const String& s); // Comparing our string with some other string
	int CompareTo(const char* s); // Comparing our string with some array of characters
	bool Contains(const String& s); // Does our string contain the passed substring (at any position)
	bool EndsWith(const String& s); // Does our string end with the text passed in the parameter
	bool StartsWith(const String& s); // Does our string start with the text passed in the parameter
	bool Equals(const String& s); // Check if our string lexicographically matches another string
	int IndexOf(char c); // Checking for the occurrence of a character in a string, as a result of the work returns the index of the first found character (from the beginning of the string)
	int LastIndexOf(char c); // Checking for the occurrence of a character in a string, as a result of the work returns the index of the last character found (search from the end of the string)
	int IndexOf(const String& s); // Checking for the occurrence of a substring in a string, as a result of the work returns the index of the beginning of the occurrence
	int LastIndexOf(String& s); // Checking for the occurrence of a substring in a string, as a result of work, returns the index of the beginning of the occurrence (but the search goes from the end of the string)
	void Remove(unsigned int index); // Delete all characters up to the end of the string, starting from the passed index
	void Remove(unsigned int start, unsigned int count); // Deleting count characters starting from index start
	void Replace(char R, char Z); // Changes all found R characters in the string to the given Z character
	void Replace(const String& substr, const String& rep); // Replaces found substring substr with string rep
	String* Split(char separator, int& pieces); // Divides our string into pieces separated by separator character
	String ToLower() const; // Drive to lower case
	String ToUpper() const; // Drive to upper case
	void Trim(); // Removes extra spaces at the beginning and end of a string
	void TrimEnd(); // Removes extra spaces at the end of a string
	void TrimStart(); // Removes extra spaces at the beginning of a line
	void Reverse(); // Line reversal
	void SortAZ(); // Sort all characters in a string alphabetically from A to Z
	void SortZA(); // Sort all characters in a string alphabetically from Z to A
	void Shuffle(); // Random shuffling of string characters
	void RandomFill(); // Filling a string with random characters (for the entire capacity)

	String& operator = (const String& s);
	friend ostream& operator << (ostream& os, const String& s);
};