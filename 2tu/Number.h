#ifndef _NUMBER_H_
#define _NUMBER_H_

#include <iostream>

class Number {
    private:
        int _x;

    public:
        Number(int x) : _x(x) {}

        bool operator==(const Number& other) const {
            return this->_x == other._x;
        }

        bool operator<(const Number& other) const {
            return this->_x < other._x;
        }

        int getX() const {
            return this->_x;
        }

        void setX(int x) {
            this->_x;
        }

        std::ostream& print(std::ostream& out) const {
            out << this->_x;
            return out;
        }
};

inline std::ostream& operator<<(std::ostream& out, const Number& n) {
    return n.print(out);
}

#endif /* _NUMBER_H_ */
