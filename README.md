# cmput379_a3

Program that simulates physical memory with virtual memory to analyze the working set requirements for two sorting algorithms, Quicksort and Heapsort.

To run the program: (*sorting_algorithm* can either be "quicksort" or "heapsort")<br>
**bash -f sim.sh** *page_size* *window_size* *sorting_algorithm*

1. The program will then ask the user to input the number of integers they wish to sort
2. After this, the program will begin sorting the integers (may take a while if sorting an extremely large amount)
  - Lab computers will run 10 million values well (1 min quicksort and 3 min heapsort)
  - 30 million values unfortunately seg fault (explained in the report)
3. Finally, the program prompts the users to select if they want to print (to stdout) all of the working set sizes computed
  - if the user selects 'y' then all the values will print 
  - if the user selects 'n' the values will not be printed to stdout

In either case all of the working set sizes will be written to a .csv file named "data_psize_wsize.csv", with the respective page size and window size)

The program finishes by displaying 
- The working set requirement ("TotalAvg:")
- The number of working sets ("Total number of partitions:")
- The .csv filename that the data was written to
- The function to write to excel if the user wishes to calculate the working set requirement with excel/similar programs
