/**
 * TODO file documentation
 *
 * @author TODO
 * @date TODO
 */

#include "turtleprogram.h"
#include <iostream>
TurtleProgram::TurtleProgram() : size(0), data(new string[0]) {}

TurtleProgram::TurtleProgram(string &a) : size(1), data(new string[1]) {
    data[0] = a;
}

TurtleProgram::TurtleProgram(string &a, string &b) : size(2), data(new string[2]) {
    data[0]= a;
    data[1] = b;
}

TurtleProgram::TurtleProgram(const TurtleProgram& rhs) {
    *this = rhs;
}

TurtleProgram::~TurtleProgram() {
    delete[] data;
}

ostream& operator<<(ostream& out, TurtleProgram& val) {
    out << "[";
    for (int i = 0; i < val.size - 1; i++) {
        out << val.data[i] << " ";
    }
    val.size - 1 < 1 ? out << val.data[val.size - 1] << "]" : out << "]";
    return (out << endl);
};

bool TurtleProgram::operator==(const TurtleProgram& rhs) const{
    if (size != rhs.size)
        return false;
    for (int i = 0; i < size; i++) {
        if (data[i].compare(rhs.data[i]) != 0)
            return false;
    }
    return true;
}

bool TurtleProgram::operator!=(const TurtleProgram &rhs) const {
    return !(*this == rhs);
}

const TurtleProgram& TurtleProgram::operator=(const TurtleProgram &rhs) {
    if (*this != rhs) {
        delete[] data;
        data = new string[rhs.size];
        for (int i = 0; i < rhs.size; i++) {
            data[i] = rhs.data[i];
        }
        size = rhs.size;
    }
    return *this;
}

TurtleProgram TurtleProgram::operator+(const TurtleProgram& rhs) const{
    TurtleProgram result = TurtleProgram();
    result.size = size + rhs.size;
    for (int i = 0; i < size; i++)
        result.data[i] = data[i];
    for (int i = size; i < result.size; i++)
        result.data[i] = rhs.data[i];
    return result;
}

TurtleProgram& TurtleProgram::operator+=(const TurtleProgram& rhs) {
    *this = *this + rhs;
    return *this;
}

TurtleProgram TurtleProgram::operator*(int n) const {
    TurtleProgram result = TurtleProgram();
    result.size = size * n;
    for (int i = 0; i < result.size; i++)
        result.data[i] = data[i % size];
    return result;
}

TurtleProgram& TurtleProgram::operator*=(int n) {
    *this = *this * n;
    return *this;
}

int TurtleProgram::getLength() const {
    return size;
}

string TurtleProgram::getIndex(int n) const {
    if (n < 0 || n >= size)
        throw "IndexOutOfBoundsException";
    return data[n];
}

void TurtleProgram::setIndex(string val, int n) {
    if (n < 0 || n >= size)
        throw "IndexOutOfBoundsException";
    data[n] = val;
}

