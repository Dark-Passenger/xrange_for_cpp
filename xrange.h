#ifndef _X_RANGE_H_
#define _X_RANGE_H_

#include "xrange_iter.h"

class xrange
{
    int _start;
    int _end;

    public:
        explicit xrange(const int end) : _start(0), _end(end) {}
        xrange(int start, int end) : _start(start), _end(end) {}

        xrange_iterator begin() const
        {
            return xrange_iterator(_start, _end);
        }

        xrange_iterator end() const
        {
            return xrange_iterator(_end);
        }
};


#endif
