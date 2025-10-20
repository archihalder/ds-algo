# Top K Frequent Elements

## Problem Statement
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

## Solutions

### Approach 1 - Sorting
- Put all the elements into a hashmap to get their frequency
- Now make a vector of pairs using those elements and their frequency {frequency, element}
- Sort the vector based on frequency
- Now the take the last k elements from the vector (since the vector is sorted in descending order)
- Time Complexity - O(n log n)
- Space Complexity - O(n)

### Approach 2 - Min Heap
- Put all the elements into a hashmap to get their frequency
- Create a min-heap of pairs (priority queue in C++)
- Traverse the hashmap and put pair {frequency, element} into the min-heap. When the size of min-heap exceeds k, pop the least frequent element i.e., top of the min-heap. This ensures, we have the top k frequent elements in the min-heap
- Now put all the elements in the min-heap into a vector
- Time Complexity - O(n log k)
- Space Complexity - O(n + k) 

### Approach 3 - Bucket Sort
- Put all the elements into a hashmap to get their frequency
- Idea - the frequency of any element cannot be more than the size of the given array
- So, we can create a bucket of vectors (vector of vectors) of size n (number of elements) in which the indices denote the frequency and the value contains all the elements with that frequency
- Now take a vector and from the end of the bucket keep pushing elements into the vector till the vector size reaches k
- Time Complexity - O(n)
- Space Complexity - O(n)
 