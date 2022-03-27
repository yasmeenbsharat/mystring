#include "MyString.h"
#include <iostream>
using namespace std;

//String length
int MyString::lenString(const char* uarr) {
int i = 0;
if (uarr) {
	while (*(uarr + i) != '\0') {
		i++; }
	return i; }
else return 0; }

// Default constructor
MyString::MyString(const char* uarr ) {
cout << "inside Default constructor " << endl;
arr = CopyMyString(arr, uarr);}

// Copy constructor
MyString::MyString(const MyString& mystring) {
	cout << "inside Copy constructor "<<endl;
	arr=CopyMyString(arr, mystring.arr);}

// Copy assignment
MyString MyString:: operator = (const MyString& mystring) {
cout << "inside Copy assignment " << endl;
delete [] arr;
arr = NULL;
arr=CopyMyString(arr, mystring.arr);
return *this;
}

//print string operator<<
std::ostream& operator<< (std::ostream& out, const MyString& mystring)
{
out << mystring.arr;
return out;
}


bool operator== (const MyString& mystring1, const MyString& mystring2) {
bool result = true;
int i = 0;
while (result &&(((mystring1.arr[i]) != '\0') &&(mystring2.arr[i]) != '\0')) {
if (mystring1.arr[i] > mystring2.arr[i]) {
	result = false;}
else if (mystring1.arr[i] < mystring2.arr[i]) {
	result = false;}
	i++; }
if (result && (((mystring1.arr[i]) == '\0') && (mystring2.arr[i]) == '\0'))
result = true;
else
result = false;
return result;}

MyString operator+(const MyString& mystring1, const MyString& mystring2) {//this=mystring1+mystring2
	MyString temp;
size_t i = 0,j=0;
	while (*(mystring1.arr+i) != '\0')
		i++;
	while (*(mystring2.arr + j) != '\0')
		j++;
	temp.arr = new char[i + j + 1];
	i = 0;
	while (*(mystring1.arr + i) != '\0'){
		*(temp.arr+ i) = *(mystring1.arr + i);
		i++; }//w1
	i--;
	j = 0;
	while ((mystring2.arr[j]) != '\0') {
		*(temp.arr + i) = mystring2.arr[j];
		i++;
		j++;}
	*(temp.arr + i) = '\0';
	return temp;}

MyString MyString::operator+=(const MyString& mystring1) {
char* temp=NULL;
    temp=CopyMyString(temp,arr);
	delete[] arr;
	arr = NULL;
	arr = new char[lenString(temp) + lenString(mystring1.arr) + 1];
	int i = 0;
	while (*(temp + i) !='\0'){
		*(arr + i) = *(temp + i);
		i++;}//w1
	i--;
	int j = 0;
	while ((mystring1.arr[j]) != '\0') {
		*(arr + i) = mystring1.arr[j];
		i++;
		j++;     }//w
	delete[] temp;
	*(arr + i) = '\0';
	return *this;}

char  MyString::operator[](int index) {
char temp = NULL;
for (int i=0;i<= lenString(arr);i++)
	if (i== index)
	temp =  * (arr + i);
return temp;}
	 
//Copy My String 
char *  MyString::CopyMyString(char* destination, const char* source) {
int i = 0;
size_t len = lenString(source)+1;
destination = new char[len];
while (*(source + i) != '\0'){
	*(destination + i) = *(source + i);
	i++;  }//w
*(destination + i) = '\0';
return destination; }// e

 // destructor
MyString::~MyString() { delete[] arr; }
	
	





