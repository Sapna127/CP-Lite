MERGE SORT
Merge Sort is a Divide and Conquer algorithm.
•	It divides the input array into two halves
•	Calls itself for the two halves
•	And then merges the two sorted halves. 
The merge() function is used for merging two halves. 
The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
Important Characteristics of Merge Sort:
•	Merge Sort is useful for sorting linked lists.
•	Merge Sort is a stable sort which means that the same element in an array maintain their original positions with respect to each other.
•	Overall time complexity of Merge sort is O(nLogn). It is more efficient as it is in worst case also the runtime is O(nlogn)
•	The space complexity of Merge sort is O(n). This means that this algorithm takes a lot of space and may slower down operations for the last data sets.

