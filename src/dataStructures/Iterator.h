#ifndef ITERATOR_H
#define ITERATOR_H
#include </Node.h>

class Iterator {
    public:
        virtual Node first() = 0;
        virtual Node next() = 0;
        virtual boolean IsDone() = 0;
        virtual Node currentItem()= 0;
    private:
        int _index;
};

#endif // ITERATOR_H
