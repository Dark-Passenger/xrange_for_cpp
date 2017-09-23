#ifndef _X_RANGE_ITER_H_
#define _X_RANGE_ITER_H_

class xrange;

class xrange_iterator
{
    int value;
    int end;

    friend xrange;

    constexpr xrange_iterator(int _end) : value(_end), end(_end) {}
    constexpr xrange_iterator(int _value, int _end) : value(_value), end(_end) {}
    constexpr bool ended() const { return (value >= end); }

    public:
        #if __cplusplus >= 201402L
        constexpr xrange_iterator& operator++()
        #else
        xrange_iterator& operator++()
        #endif
        {
            value += 1;
            return *this;
        }

        #if __cplusplus >= 201402L
        constexpr xrange_iterator operator++(int)
        #else
        xrange_iterator operator++(int)
        #endif
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
