# Longest-Increasing-Subsequence
This project contains code to find out LIS(Longest Increasing Subsequence) string. Given a sorted sequence of integers(in sorted_list.txt), find out the LIS. The program can read sequence of integers of any length, so modify `sorted_list.txt` as you please.

## 1. About binary search here
<img src="BS%20algorithm.PNG" width="70%">
As the algorithm shows, binary search here must return certain index so that the program knows where to put the number from `source_string` to `LIS_string`. We make a little modification to binary search algorithm to meet out needs.

## 2. Execute the program
### In terminal:
Just clone the project:  
`git clone https://github.com/onlyfly34/Longest-Increasing-Subsequence.git`

Enter the project:  
`cd Longest-Increasing-Subsequence`

And compile:  
`make`

Execute:  
`./LIS <input-file-path>`

### Or just open the project with CodeBlocks IDE

## 3. Sample input and output
The same input is in `input-example1` and `input-example2`.  
Take `input-example1` for example:
``` bash
5 3 4 9 6 6 2 1 6 8 7 6 9 20
```

Corresponding output is as follows:
``` bash
Length of LIS: 6
Longest increasing subsequence: [ 3 4 6 7 9 20 ]
```
