#ifndef _X_RANGE_H_
#define _X_RANGE_H_
#include <type_traits>

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class xrange
{
    T _start;
    T _end;

    public:
        explicit constexpr xrange(const T end) : _start(0), _end(end) {}
        constexpr xrange(const T start, const T end) : _start(start), _end(end) {}
        class iterator
        {
            T value;
            T end;

            friend xrange<T>;

            constexpr iterator(T _end) : value(_end), end(_end) {}
            constexpr iterator(T _value, T _end) : value(_value), end(_end) {}
            constexpr bool ended() const { return (value >= end); }

            public:
            #if __cpp_constexpr >= 201304
                constexpr iterator& operator++() {
            #else
                iterator& operator++() {
            #endif
                    ++value;
                    return *this;
                }

            #if __cpp_constexpr >= 201304
                constexpr iterator operator++(T) {
            #else
                iterator operator++(T) {
            #endif
                    return iterator(value++, end);
                }

            constexpr bool operator==(const iterator& other) const {
                return ((value == other.value && end == other.end) ||
                        (ended() && other.ended()));
            }

            constexpr bool operator!=(const iterator& other) const {
                return !(*this == other);
            }

            constexpr T operator*() const {
                return value;
            }
        };

        constexpr iterator begin() const {
            return iterator(_start, _end);
        }

        constexpr iterator end() const {
            return iterator(_end);
        }
};


#endif
