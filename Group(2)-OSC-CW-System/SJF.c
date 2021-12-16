#include <stdio.h>
#include <stdlib.h>
#define MAX 30

void ShortestJobFirst(int Process[], int Burst_Time[], int NumberOfProcess) {

  int bt[MAX];
  int Waiting_Time[MAX];
  int Turnaround_Time[MAX];
  int temp;
  float Average_Turnaround_Time = 0;
  float Average_Waiting_Time = 0;
  size_t i;
  size_t j;

  //Bubble sort the array in ascending order
  for(i = 0; i < NumberOfProcess; i++) { bt[i] = Burst_Time[i];}
  for(i = 0; i < NumberOfProcess; i++) {
    for(j = 0; j < NumberOfProcess - i - 1; j++) {
      if(bt[j] > bt[j+1]) {
        temp = bt[j];
        bt[j] = bt[j+1];
        bt[j+1] = temp;

        temp = Process[j];
        Process[j] = Process[j+1];
        Process[j+1] = temp;
      }	
    }	
  }

  // To seperate into individual calculation, make it clean to view
  for(int a = 0; a < 70; a++){printf("%s", "*");}
  printf("\n\nShortest Job First :\n\nProcess ID\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n");

  //Calculate the turnaround time and waiting time for each process
  for(i = 0; i < NumberOfProcess; i++) {
    Waiting_Time[i] = 0;
    Turnaround_Time[i] = 0;

    for(j = 0; j < i; j++) { Waiting_Time[i] += + bt[j]; }	

    Turnaround_Time[i]= Waiting_Time[i] + bt[i];
    Average_Waiting_Time += Waiting_Time[i];
    Average_Turnaround_Time += Turnaround_Time[i];

    printf("\n\tP%d %15d %18d %17d", Process[i], bt[i], Turnaround_Time[i], Waiting_Time[i]);
  }
  
  /*Calculate the average turnaround time and waiting time for this process
  schedulling algorithms*/
  printf("\n");
  Average_Turnaround_Time /= NumberOfProcess;
  Average_Waiting_Time /= NumberOfProcess;
  printf("\nThe average Turnaround Time is : %.2f\n", Average_Turnaround_Time);
  printf("The average Waiting Time is : %.2f\n\n", Average_Waiting_Time);
}