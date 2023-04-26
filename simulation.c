#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100
#define MAX_PROCESSES 10

int memory[MEMORY_SIZE]; // array representing memory, where each element is either 0 (unallocated) or the PID of a process
int num_processes = 0; // counter for the number of processes that have been allocated memory

void init_memory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0; // initialize all elements of the memory array to 0 (unallocated)
    }
}

void print_memory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("%d ", memory[i]); // print out the current contents of the memory array
    }
    printf("\n");
}

int bestfit(int size) {
    int start = -1; // initialize the starting index of the best-fit block to -1 (no suitable block found yet)
    int smallest = MEMORY_SIZE; // initialize the size of the smallest block found so far to the size of the entire memory
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0) { // if the current block is unallocated
            int j = i;
            int curr_size = 0;
            while (j < MEMORY_SIZE && memory[j] == 0) { // find the size of the contiguous block of unallocated memory
                curr_size++;
                j++;
            }
            if (curr_size >= size && curr_size < smallest) { // if the current block is big enough and smaller than the current best fit
                smallest = curr_size;
                start = i; // update the best fit block
            }
        }
    }
    return start; // return the starting index of the best fit block (or -1 if no suitable block found)
}

void allocate_memory(int size) {
    int start = bestfit(size); // find the starting index of the best-fit block
    if (start != -1) { // if a suitable block was found
        for (int i = start; i < start + size; i++) {
            memory[i] = num_processes + 1; // mark the allocated block with the PID of the new process (incremented from the previous number of processes)
        }
        printf("Process %d allocated memory starting at address %d.\n", num_processes, start); // print out confirmation message
        num_processes++; // increment the counter for the number of processes
    } else {
        printf("Process could not be allocated memory.\n"); // print out error message if no suitable block was found
    }
}

void deallocate_memory(int pid) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == pid) { // find all blocks in memory that are currently allocated to the specified process
            memory[i] = 0; // deallocate each of these blocks by setting the corresponding memory array element to 0
        }
    }
    printf("Process %d deallocated memory.\n", pid); // print out confirmation message
}

void simulate(int num_time_units) {
    int fragmentation_total = 0;
	int wasted_total = 0;
	int num_simulations = 0;
	for (int t = 0; t < num_time_units; t++) {
		printf("Time unit %d:\n", t);
		// Allocate two random processes
		int size = rand() % 10 + 1;
		allocate_memory(size);
		size = rand() % 10 + 1;
		allocate_memory(size);

		// Deallocate two random processes
		int pid = rand() % num_processes + 1;
		deallocate_memory(pid);
		pid = rand() % num_processes + 1;
		deallocate_memory(pid);

		// Calculate fragmentation and wasted memory
		int fragmentation = 0;
		int wasted = 0;
		for (int i = 0; i < MEMORY_SIZE; i++) {
			if (memory[i] == 0) {
				wasted++;
				while (i < MEMORY_SIZE && memory[i] == 0) {
					fragmentation++;
					i++;
				}
			}
		}
    fragmentation_total += fragmentation;
    wasted_total += wasted;
    num_simulations++;
    printf("Fragmentation: %d, Wasted Memory: %d\n", fragmentation, wasted);
}

	// Calculate and print average fragmentation and wasted memory
	float avg_fragmentation = (float) fragmentation_total / num_simulations;
	float avg_wasted = (float) wasted_total / num_simulations;
	printf("\nAverage Fragmentation: %.2f\n", avg_fragmentation);
	printf("Average Wasted Memory: %.2f\n", avg_wasted);

}

int main() {
    srand(1); // set random seed for reproducibility
    init_memory();
    printf("enter the number of simulation u want to do:");
    scanf("%d",&no_of_simulation);
    simulate(no_of_simulation);
    return 0;
}
