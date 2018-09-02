# XVector

**XVector is a dynamic array with a very fast expansion and shrinkage performance. It uses the same "table doubling" technique used by C++ [std::vector](http://www.cplusplus.com/reference/vector/vector/), but instead of coping the actual data, only copies references to data chunks, resulting in significantly lower rate of coping operations.**

**The structure of the container is similar to C++ [std::deque](http://www.cplusplus.com/reference/deque/deque/), a vector of vectors, but without allowing front expansion, getting rid of the performance overhead caused by such model, also decreasing the constant time of accessing a specific data.**

![Structure Image](https://github.com/ahmedhammad97/XVector/blob/master/structure.png)

**XVector is only useful in a situation that requires frequent expansion and shrinkage, consider the following code for illustration:**

```
for(int k=0;k<25;k++){
    for(int i=0;i<1000000;i++){
        xv.push_back(rand());
    }
    for(int i=0;i<500000;i++){
        xv.pop_back();
    }
}
```

**XVector performs better than any dynamic structure in such a case**

![Performance Image](https://github.com/ahmedhammad97/XVector/blob/master/performance.png)

**However, it is usually very slow when it comes to only inserting at the end, because of the frequent pointer referencing.**
