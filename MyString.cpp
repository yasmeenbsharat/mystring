#include "MyString.h"

// Default constructor
MyString::MyString(const char* uarr) {
    while (uarr[m_length] != '\0')
        m_length++;
    m_buffer = copyMyString(m_buffer, uarr);
}

// Copy constructor
MyString::MyString(const MyString& mystring) {

    m_length = mystring.m_length;
    m_buffer = copyMyString(m_buffer, mystring.m_buffer);
}

// Copy assignment
MyString MyString::operator = (const MyString& mystring) {
    if (this != &mystring) {
        delete[] m_buffer;
        m_buffer = NULL;
        m_length = mystring.m_length;
        m_buffer = copyMyString(m_buffer, mystring.m_buffer);
    }
    return *this;
}

//print string operator<<
std::ostream& operator << (std::ostream& out,
    const MyString& mystring) {
    out << mystring.m_buffer;
    return out;
}

bool operator == (const MyString& mystring1,
    const MyString& mystring2) {

    if (mystring1.m_length != mystring2.m_length)
        return false;

    for (int i = 0; i < mystring1.m_length; i++) {
        if (mystring1.m_buffer[i] != mystring2.m_buffer[i])
            return false;

    }
    return true;
}

MyString operator + (const MyString& mystring1,
    const MyString& mystring2) {

    if (mystring1.m_length == 0)
        return mystring2;
    else if (mystring2.m_length == 0)
        return mystring1;
    else {
        MyString temp;
        size_t i = mystring1.m_length + mystring2.m_length;
        temp.m_buffer = new char[i + 1];
        temp.m_length = i;
        i = 0;
        while (mystring1.m_buffer[i] != '\0') {
            temp.m_buffer[i] = mystring1.m_buffer[i];
            i++;
        } //w1
        int j = 0;

        while ((mystring2.m_buffer[j]) != '\0') {
            temp.m_buffer[i] = mystring2.m_buffer[j];
            i++;
            j++;
        }
        temp.m_buffer[i] = '\0';
        return temp;
    }

}

MyString MyString::operator += (const MyString& mystring1) {
    char* temp = NULL;
    size_t i = mystring1.m_length + m_length;
    if (m_length != 0) {
        temp = copyMyString(temp, m_buffer);
        delete[] m_buffer;
        m_buffer = NULL;
    }

    m_buffer = new char[i + 1];
    m_length = i;
    i = 0;
    if (temp) {
        while (temp[i] != '\0') {
            m_buffer[i] = temp[i];
            i++;
        } //w1
        delete[] temp;
    }
    if (mystring1.m_length != 0) {
        int j = 0;
        while ((mystring1.m_buffer[j]) != '\0') {
            m_buffer[i] = mystring1.m_buffer[j];
            i++;
            j++;
        } //w

    }
    m_buffer[i] = '\0';
    return *this;
}

char MyString::operator[](size_t index) {
    if (index <= m_length)
        return m_buffer[index];

    return NULL;
}
//Copy My String 
char* MyString::copyMyString(char* destination,
    const char* source) {
    int i = 0;
    while (source[i] != '\0')
        i++;
    size_t len = i + 1;
    i = 0;
    destination = new char[len];
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    } //w
    destination[i] = '\0';
    return destination;
} // e

//print string
void MyString::printString() {
    {
        int i = 0;
        if (m_buffer) {
            while ((m_buffer[i]) != '\0') {
                std::cout << m_buffer[i];
                i++;
            }
        }
        else {
            std::cout << "empty string";
        }
    }
}

// destructor
MyString::~MyString() {
    delete[] m_buffer;
}