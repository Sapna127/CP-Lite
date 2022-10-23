### Double-ended queues 
```
->They are sequence containers with the feature of expansion and contraction on both ends. 
->They are similar to vectors, but are more efficient in case of insertion and deletion of elements. Unlike vectors, contiguous storage allocation may not be guaranteed. 
->Double Ended Queues are basically an implementation of the data structure double-ended queue. 
->A queue data structure allows insertion only at the end and deletion from the front. This is like a queue in real life, wherein people are removed from the front and added at the back. Double-ended queues are a special case of queues where insertion and deletion operations are possible at both the ends.
->The functions for deque are same as vector, with an addition of push and pop operations for both front and back.  
```

### The time complexities for doing various operations on deques are-

Accessing Elements- O(1)
Insertion or removal of elements- O(N)
Insertion or removal of elements at start or end- O(1)
```