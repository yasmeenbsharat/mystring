#include <iostream>
class MyString {

public:

	MyString(const char* uarr = "");

	MyString(const MyString& mystring);

	MyString operator = (const MyString& mystring);

	char operator[](int index);

	friend std::ostream& operator<< (std::ostream& out, const MyString& mystring);

	friend bool operator== (const MyString& mystring1, const MyString& mystring2);

	friend MyString operator+(const MyString& mystring1, const MyString& mystring2);

	MyString operator+=(const MyString& mystring1);

	void printString();

	~MyString();

private:
	char* m_buffer;
	int m_length = 0;
	//Copy My String 
	char* copyMyString(char* destination, const char* source);
};



