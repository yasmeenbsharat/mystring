#include <iostream>
class MyString {

public:
	int lenString(const char* uarr);

	MyString(const char* uarr = "");

	MyString(const MyString& mystring);

	MyString operator = (const MyString& mystring);

	char operator[](int index);

	friend std::ostream& operator<< (std::ostream& out, const MyString& mystring);

	friend bool operator== (const MyString& mystring1, const MyString& mystring2);

	friend MyString operator+(const MyString& mystring1, const MyString& mystring2);

	MyString operator+=(const MyString& mystring1);
	 // destructor
	~MyString();
	
private:
	char* arr;
	//Copy My String 
	char* CopyMyString(char* destination, const char* source);
};



