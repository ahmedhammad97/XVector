# XVector

XVector is a dynamic array with a very fast expansion and shrinkage performance. It uses the same "table doubling" technique used by C++ [std::vector](http://www.cplusplus.com/reference/vector/vector/), but instead of coping the actual data -which takes Θ(n)-, only copies references to data chunks, resulting in significantly lower rate of coping operations, taking Θ(n/b), where 'n' is the number of elements, and 'b' is the chunk size.

<br>

An attempt to achieve Θ(log(n)) for expansion by letting 'b' increase in size logarithmically in 'n', failed practically because the constant time functions used to achieve this, such as ```Pow()``` and ```Log()```, resulted in a bad performance. So it is concluded that keeping 'b' as a large enough constant -so that the last chunk can fit in the cache- is practically better.

<br>

The structure of the container is similar to C++ [std::deque](http://www.cplusplus.com/reference/deque/deque/), a vector of vectors, but without allowing front expansion, getting rid of the performance overhead caused by such model, also decreasing the constant time of accessing a specific data.

<br>

![Structure Image](https://github.com/ahmedhammad97/XVector/blob/master/Structure.png)

<br>

**XVector is only useful in a situation that requires frequent expansion and shrinkage, consider the following code for illustration:**

```
for(int k=0;k<25;k++){
    for(int i=0; i< 1000000; i++){
        xv.push_back(rand());
    }
    for(int i=0;i<500000;i++){
        xv.pop_back();
    }
}
```

**XVector performs better than any dynamic structure in such a case**

<br>

![Performance Image](https://github.com/ahmedhammad97/XVector/blob/master/Performance.png)

<br>

However, it is usually slower when it comes to only inserting at the end or accessing the data, because of the frequent pointer referencing, as XVector uses two pointer references -instead of one for regular dynamic arrays-, to access any data.

And fortunately this turns out to be a very good illustration of how frequent pointer referencing can lead to a very bad performance in a RAM model of computation.
