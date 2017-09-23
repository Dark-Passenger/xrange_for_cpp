#ifndef _X_RANGE_ITER_H_
#define _X_RANGE_ITER_H_

class xrange;

class xrange_iterator
{
    int value;
    int end;

    friend xrange;

    constexpr xrange_iterator(int end) : value(end), end(end) {}
    constexpr xrange_iterator(int value, int end) : value(value), end(end) {}
    constexpr bool ended() const { return (value >= end); }

    public:
        xrange_iterator& operator++()
        {
            value += 1;
            return *this;
        }

        xrange_iterator operator++(int)
        {
            value += 1;
            return xrange_iterator(value - 1, end);
        }

        constexpr bool operator==(const xrange_iterator& other) const
        {
            return ((value == other.value && end == other.end) ||
                                    (ended() && other.ended()));
        }

        constexpr bool operator!=(const xrange_iterator& other) const
        {
            return !(*this == other);
        }

        constexpr int operator*() const
        {
            return value;
        }
};

#endif
