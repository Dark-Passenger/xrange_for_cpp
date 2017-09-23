# xrange_for_cpp
xrange for c++ for use with range based for loops.

these headers allow you to do

for(const auto& i : xrange(10))
{
    std::cout << i << std::endl;
}

or even for a custom start.

for(const auto& i : xrange(10, 20))
{
    std::cout << i << std::endl;
}

This as you can see is inspired from python's xrange structures.
