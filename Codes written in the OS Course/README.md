Consists of the codes that I had written as homeworkds for the OS course:

1. In the xargs.c file we are trying to recreate the xargs utility of linux, which takes in arguments from the one end of its standard input and passes it to the command 
that it was provided as an argument. 

2. Coin_tossing.c involves using threads to simulate the situation where coins are flips arbitrary number of times however, there are rules laid in place regarding which threads gets to choose a coin first. 
In the first scenario(one_person_once), a thread can hold the lock until it has flipped all the coins that it want to flip. In the second scenario(one_set_of_flips_once), the coins 
threads only hold the lock for one set of coin flips, and after that they release the lock, allowing another thread to enter and do the same. In the third scenario(one_coins_once), 
the threads can have to release their lock corresponding to a coin, after they have flipped the coin. When we observed the execution times of these scenarios, we saw that the 
execution time was longer for the latter approaches, and it was due to the need to frequently receive and release the locks to flip the coins.

3. scat.c aka simple cat.c , demosntrates the difference of the performance of system calls and library calls for printing characters on the screen. We used three approaches to 
copy the the contents of the file whose name was given in the standard input to the standard output. Here we saw that due to optimized buffer sizes, the librarry calls were faster becuase
they did not invoke many system calls to copy something from a particular file to another file.

4. Online quiz: In this example we work with pipes, and do some plumbing between the parent process and the child process, where the read_end of the pipe is duplicated to the 
stdin file descriptor of the of the parent process, and the write end of the pipe is duplicated to the write end of the child process. THe child executes a curl command and retrives
the quiz question from a URL, and the parent process takes that information and displays it to the user.

5. fd_utility: This program is somewhat similar to the ls command with the program showing files that match some descriptions. But this program's search is not limited to the current
directory and proceeeds to find all the files that match the descriptions provided as command line arguments. In addition to this, it takes in multiple of these 'roots' where the
'search tree' starts.
