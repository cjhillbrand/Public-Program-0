/**
 * TODO file documentation
 *
 * @author TODO
 * @date TODO
 */

#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H

#include <string>

using namespace std;

class TurtleProgram {
public:
    TurtleProgram();
    TurtleProgram(string&);
    TurtleProgram(string&, string&);
    TurtleProgram(const TurtleProgram&);
    ~TurtleProgram();

    friend ostream& operator<<(ostream&, TurtleProgram&);

    bool operator== (const TurtleProgram&) const;
    bool operator!= (const TurtleProgram&) const;

    const TurtleProgram& operator= (const TurtleProgram&);

    TurtleProgram operator+ (const TurtleProgram&) const;
    TurtleProgram& operator+= (const TurtleProgram&);

    TurtleProgram operator* (int) const;
    TurtleProgram& operator*= (int);

    int getLength() const;
    string getIndex(int) const;
    void setIndex(string, int n);

private:
    int size;
    string *data;
};

#endif // TURTLEPROGRAM_H
