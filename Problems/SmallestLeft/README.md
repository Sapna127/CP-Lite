# Smallest Left

## Problem Statement
Given an array a of integers of length n, 
find the nearest smaller number for every element such that the smaller element is on left side.
If no small element present on the left print -1.

## Algorithm 
A Simple Solution is to use two nested loops. The outer loop starts from the second element, 
the inner loop goes to all elements on the left side of the element picked by the outer loop and stops as soon as it finds a smaller element.  

## Time Complexity: 
O(n2).

## Space Complexity: 
O(1)
