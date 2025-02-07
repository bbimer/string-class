#pragma once

#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    int size = 0;
    char* newArr = nullptr;

public:
    String(const char* word);
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;
    String operator+(const String& other) const;
    String& operator+=(const String& other);
    char& operator[](size_t index);

    friend std::ostream& operator<<(std::ostream& os, const String& str);

    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator>(const String& other) const;
    bool operator<(const String& other) const;

    void print();
};

#endif // STRING_H
