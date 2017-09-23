# xrange_for_cpp
xrange for c++ for use with range based for loops.

these headers allow you to do
```cpp
for(const auto& i : xrange(10))
{
    std::cout << i << std::endl;
}
```
or even for a custom start.

```cpp
for(const auto& i : xrange(10, 20))
{
    std::cout << i << std::endl;
}
```
This as you can see is inspired from python's xrange structures.

And added value its constexpr !!! c++11 compatible since the operator++ is not constexpr
