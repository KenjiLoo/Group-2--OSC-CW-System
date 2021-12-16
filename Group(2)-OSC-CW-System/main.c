#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#define MAX 30

//Function declaration
void selection();

/*Take user input for No. of processes, burst time for each process
and the time quantum*/
int main(void) {

  int NumberOfProcess;
  int Burst_Time[MAX];
  int Time_Quantum;
  int Process[MAX];
  size_t i;

  printf("\nEnter total number of process : ");
  scanf("%d", &NumberOfProcess);
  printf("\n");

  for(i = 0; i < NumberOfProcess; i++) {
    printf("P%lu Burst time : ", i + 1);
    scanf("%d", &Burst_Time[i]);
    Process[i] = i + 1;
  }

  printf("\nEnter the time quantum : ");
  scanf("%d", &Time_Quantum);
  printf("\n");

  /*Execute the functions which have been declared in process.h
  Every scheduling process will be displayed table by table*/
  ShortestJobFirst(Process, Burst_Time, NumberOfProcess);
  RoundRobinWithoutOverhead(Time_Quantum, Burst_Time, NumberOfProcess);
  RoundRobinWithOverhead(Time_Quantum, Burst_Time, NumberOfProcess);

  selection();
}

/*Take user input for either continue the program with new set
of data or exit the program*/
void selection() {

  int select;
  printf("Press 1 to continue/ Press 2 to exit : ");
  scanf("%d", &select);

  switch(select) {
    case 1:
      main();
      break;
    case 2:
      exit(0);
      break;
    default:
      printf("\nWrong selection !\n");
      selection();
      break;
  }
}