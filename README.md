# simulation-program-for-memory-management-system

The code begins with defining a constant MEMORY_SIZE which sets the total size of the memory available for allocation, and a MAX_PROCESSES constant that determines the maximum number of processes that can be allocated memory.

The memory array is used to simulate the memory space. It is initialized with zeros in the init_memory() function, which sets all the memory to be unallocated at the start.

The print_memory() function prints the current state of the memory array.

The bestfit() function is where the Best Fit allocation algorithm is implemented. It searches for the smallest available memory block that is larger than the requested size. It starts from the beginning of the memory array and iterates through each unallocated block. If the block is large enough for the requested size and smaller than the current smallest block, then it updates the start variable and smallest variable to the start index and size of the new smallest block. It returns the starting index of the smallest available block.

The allocate_memory() function takes a size parameter which is the size of memory requested by a process. It calls the bestfit() function to find the best available block of memory to allocate. If it finds a block that is large enough, it assigns the process a unique ID number and updates the memory array with the ID number for the allocated memory block. It then increments the num_processes variable.

The deallocate_memory() function takes a pid parameter which is the ID of the process whose memory is being deallocated. It searches through the memory array and sets all the elements with the pid value to 0, indicating that the memory is unallocated.

The simulate() function is where the simulation occurs. It takes a num_time_units parameter which determines the number of simulation iterations to run. Each simulation iteration involves the following steps:

    Generate a random size value between 1 and 10 to request memory allocation for a process.
    Call allocate_memory() with the size value to allocate memory for a process.
    Generate another random size value between 1 and 10 to allocate memory for another process.
    Call allocate_memory() again with the new size value.
    Generate a random pid value between 1 and the current number of processes to deallocate the memory for a process.
    Call deallocate_memory() with the pid value to deallocate the memory for the process.
    Generate another random pid value to deallocate memory for another process.
    Call deallocate_memory() again with the new pid value.
    Calculate the fragmentation and wasted memory for the current memory state.
    Add the fragmentation and wasted memory to the respective total variables.
    Increment the num_simulations variable.
    Print the current fragmentation and wasted memory values.

After all simulation iterations have completed, the avg_fragmentation and avg_wasted values are calculated by dividing the respective total variables by the number of simulations. These values are then printed out to the console.

Finally, the main() function initializes the random number generator, calls the init_memory() function to set up the memory array, and then calls the simulate() function to run the memory allocation simulation.
