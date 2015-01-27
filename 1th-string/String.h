#ifndef STRING_H_
#define STRING_H_

#include <iostream>
#include <cstdint>

class String {
    private: 
        char *ptr;
        uint32_t len;
    public:
        String(void) {
            // nullptr is a typesafe value which represents 0, the null pointer
            // guaranteed to be no information stored at 0
            ptr = nullptr;
            len = 0;
        }

        String(const char* ptr) {
            len = 0;
            while (ptr[len]) { len += 1; }
            this->ptr = new char[len+1];
            for (uint32_t k = 0; k <= len; k += 1) {
                this->ptr[k]=ptr[k];
            }
        }

        ~String(void) {
            // SCOPING RULES
            // look for local
            // look for param
            // look for class variable (using this)
            // look for global matching the name

            // delete[] ptr;

            destroy();
        }

        String(const String& that) {
            // just copy the other object and don't worry about whether
            // it will end up getting deleted

            copy(that);
        }

        String& operator=(const String& rhs) {
            if (this != &rhs) {
                destroy(); // destroy yourself first, then do the copy
                copy(rhs);
            }
            return *this;
        }

        uint32_t size(void) const { return len; }

        void print(std::ostream& out) const {
            for (uint32_t k = 0; k < len; k+=1) {
                out << ptr[k];
            }
        }

    private:
        void copy(const String& that) {
            this->len = that.len;
            if (that.ptr) {
                this->ptr = new char[len+1];
                char *curr = this->ptr;
                char const *other = that.ptr;
                char const *end = &(this->ptr[len]);
                while (curr != end) {
                    *curr = *other;
                    curr++;
                    other++;
                }
                // std::cout << "made it to the end" << std::endl;
            } else {
                ptr = nullptr;
            }
        }
        void destroy() {
            delete[] ptr;
        }
};

inline std::ostream& operator<<(std::ostream& o, String& str) {
    str.print(o);
    return o; // must return the stream so output can be chained
}


#endif /* STRING_H_ */
