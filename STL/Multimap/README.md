# Multimap
## Introduction
A multimap is a sorted associative container that contains key-value pairs with unique keys. Keys are sorted by using the comparison function Compare. Search, removal, and insertion operations have logarithmic complexity. Multimaps are usually implemented as binary search trees.

## Template parameters
* Key - type of the keys. Each element in a multimap is uniquely identified by its key value.
* T - type of the mapped value. Each element in a multimap is used to store some data as its mapped value.
* Compare - comparison function object which returns ​true​ if the first argument is less than (i.e. is ordered before) the second. This can either be a function pointer or a function object. This defaults to ​std::less<Key>​.
* Alloc - an allocator object used to define the storage allocation model. By default, uses ​std::allocator<std::pair<const Key,T>>​.

## Member types
* key_type - Key
* mapped_type - T
* value_type - std::pair<const Key,T>
* key_compare - Compare
* value_compare - ​std::less<value_type>​ by default
* reference - value_type&​
* const_reference - const value_type&​
* pointer - ​std::allocator_traits<Alloc>::pointer​
* const_pointer - ​std::allocator_traits<Alloc>::const_pointer​
* iterator - implementation-defined
* const_iterator - implementation-defined
* reverse_iterator - ​std::reverse_iterator<iterator>​
* const_reverse_iterator - ​std::reverse_iterator<const_iterator>​
* difference_type - ​std::allocator_traits<Alloc>::difference_type​
* size_type - ​std::allocator_traits<Alloc>::size_type​

## Member functions
* (constructor) - constructs the container. The container is empty.
* (destructor) - destructs the container.
* operator= - assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
* get_allocator - returns the associated allocator.
* begin - returns an iterator to the beginning.
* end - returns an iterator to the end.
* rbegin - returns a reverse iterator to the beginning.
* rend - returns a reverse iterator to the end. 
* cbegin - returns a const_iterator to the beginning.
* cend - returns a const_iterator to the end.
* crbegin - returns a const_reverse_iterator to the beginning.
* crend - returns a const_reverse_iterator to the end.
* empty - checks whether the container is empty.
* size - returns the number of elements.
* max_size - returns the maximum possible number of elements.
* clear - clears the contents.
* insert - inserts elements or nodes.
* emplace - constructs elements in-place.
* emplace_hint - constructs elements in-place using a hint.
* erase - erases elements.
* swap - swaps the contents.
* count - returns the number of elements with a specific key.
* find - finds elements with a specific key.
* equal_range - returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
* lower_bound - returns an iterator to the first element that is not considered to go before k (i.e., either it is equivalent or goes after).
* upper_bound - returns an iterator to the first element that is considered to go after k.

## Non-member functions
* swap - swaps the contents of two multisets.

## Iterators
The iterators are bidirectional iterators.

## Complexity
All operations are logarithmic in the size of the container.

## Exceptions
Strong exception safety guarantee: if an exception is thrown, the container is left unchanged.

## Example
```cpp
#include <map>

int main()
{
    std::multimap<int, int> multimap = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

    multimap.emplace(6, 6);
    multimap.emplace_hint(multimap.end(), 7, 7);

    for(const auto& [key, value] : multimap)
    {
        // Do something with key and value
    }

    multimap.erase(1);
    multimap.erase(multimap.begin(), multimap.end());

    multimap.swap(multimap);
}
```