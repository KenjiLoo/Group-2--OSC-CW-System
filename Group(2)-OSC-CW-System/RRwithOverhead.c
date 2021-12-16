#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 30

void RoundRobinWithOverhead(int Time_Quantum, int Burst_Time[], int NumberOfProcess) {
  
  int temp[MAX]; 
  int total = 0;
  int counter = 0;
  int Waiting_Time = 0;
  int WT = 0;
  bool isNotfirst_execution[MAX];
  int diff = 0;
  int overhead = 10;
  int Turnaround_Time = 0;
  int x = NumberOfProcess;
  float Average_Turnaround_Time;
  float Average_Waiting_Time;
  size_t i;

  // To seperate into individual calculation, make it clean to view
  for(i = 0; i < NumberOfProcess; i++) { temp[i] = Burst_Time[i]; }
  for(int a = 0; a < 70; a++){printf("%s", "*");}
  printf("\n\nRound Robin With Overhead :\n\nProcess ID\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n");

  //Calculate the turnaround time and waiting time for each process
  for(i = 0; x != 0; i++) {
    //Last round of execution
    if(temp[i] <= Time_Quantum && temp[i] > 0 ) {
      total += (temp[i] + overhead);
      temp[i] = 0;
      counter = 1;
    }
    //Not the last round of execution
    else if(temp[i] > 0) {
      temp[i] -= Time_Quantum;
      total += (Time_Quantum + overhead);\
      isNotfirst_execution[i] = true;
    }
    //When individual process has been executed completely
    if(temp[i] == 0 && counter == 1) {
      Waiting_Time = i * (Time_Quantum + overhead) - diff;

      //This is for p1, since the waiting time has been subtracted by diff
      if(Waiting_Time < 0 ) { Waiting_Time = 0; }

      /*This is for the process where has been executed completely during the first
      round of execution. The waiting time for the next process will be earlier.
      Therefore, this statement is to identify how much time earlier for the 
      execution of the next process is carried out*/
      if(!isNotfirst_execution[i]) { diff += Time_Quantum - Burst_Time[i]; }

      printf("\n\tP%lu %15d %18d %17d", i + 1, Burst_Time[i], total - overhead, Waiting_Time);
      Turnaround_Time += (total - overhead);
      WT += Waiting_Time;
      x--;
      counter = 0;
    }
    //Another round of execution
    if(i == NumberOfProcess - 1) {
      i = -1;
    }
  }

  /*Calculate the average turnaround time and waiting time for this process
  schedulling algorithms*/
  printf("\n");
  Average_Turnaround_Time = Turnaround_Time * 1.0 / NumberOfProcess;
  Average_Waiting_Time = WT * 1.0 / NumberOfProcess;
  printf("\nThe average Turnaround Time is : %.2f\n", Average_Turnaround_Time);
  printf("The average Waiting Time is : %.2f\n\n", Average_Waiting_Time);
}