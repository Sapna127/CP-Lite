# Table of content
- [Count Set Bits](#count-set-bits)
- [check power of 2](#check-power-2)


# Count Set Bits
#power of 2

## Problem Statement 
Given a positive integer N, print count of set bits in it. Set Bits are the no. of bits that are 1.

## Examples
Example 1 : Input : N = 6

            Output : 2

Example 2 :  Input : N = 8

             Output : 1
             
 ![image](https://user-images.githubusercontent.com/94545831/169095943-17f56cab-2bea-4ce6-bf8a-cbbfb5abfd9c.png)

            
## Algorithm
   - This algorithm is of fast approach as mentioned in code.
- Given a number N.
- Run the while loop till number is greater than 0.
- Do Bitwise AND operation of that number to its preceding number.
- Assign the result to that original number.
- Increment the counter by 1.
- Return the counter.

## Time Complexity and Space Complexity
Time Complexity : O(n log n)

Space Complexity : O(1)

## Problem Statement 
Given a positive integer check if it is power of 2 or not.

## Examples
Example 1 : Input : N = 6

            Output : 0

Example 2 :  Input : N = 16

             Output : 1
             
## Algorithm
- This algorithm is of fast approach as mentioned in code.
- Given a number N.
- Check if number has only one set bit.
- If it has only one set bit then return 0.
- otherwise return 1.
 
## Time Complexity and Space Complexity.\
Time Complexity : O(1)

Space Complexity : O(1).

