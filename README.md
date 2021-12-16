#SCHEDULING ALGORITHMS 

#This folder contains 5 files which have their own roles. 
#The files: 


1) `main.c`

- The traffic control of the algorithm. It reads the values like the `number of processes`,`burst times`, 
`time quantum`, which algorithm should be used.
- It then passes in the values to the functions which are in the other files. 
- Upon running and inputting the values, all three results of the different algorithms will show. 
- The results will look like a graph listing the values of the `process ID`, the `burst time` of each process,
the `turnaround time` of each process, and the `waiting time` of each process.
- The results will also display the `average turnaround time` and the `average waiting time` of each process. 


2)`process.h`

- The header file that allows main.c to access the algorithm's files respectively. 


3)`RRwithoutOverhead.c`
 
- This is the file that deals with the Round Robin without Overhead scheduler.
- The file starts with the function's name, which will be passed into `process.h` and then into `main.c`.
- The important variables like `burst times`, `number of processes`, `time quantum`, are all defined in `main.c`.


4)`RRwithOverhead.c`

- This is the file that deals with the Round Robin without Overhead scheduler.
- The file starts with the function's name, which will be passed into `process.h` and then into `main.c`.
- The important variables like `burst times`, `number of processes`, `time quantum`, are all defined in `main.c`.


5)`SJF.c`

- This is the file that deals with the Round Robin without Overhead scheduler.
- The file starts with the function's name, which will be passed into `process.h` and then into `main.c`.
- The important variables like `burst times`, `number of processes`, are all defined in `main.c`.
