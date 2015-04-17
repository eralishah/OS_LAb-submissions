#include<stdio.h>


/*Deadline     = i^th quantum of time by which the process to finish -->> we prioritize on this
release time = start time
exection     = time required with the processor.
PROC: 0 means no process*/

void main()
{

 int N_process;

int i,wait_prev,k,temp,m,l;
 
 printf("\nEnter no of processes:");
 scanf("%d",&N_process);
 
 int exec[N_process],start[N_process],deadline[N_process], flag[N_process];
 for(i=0;i<N_process;i++)
	flag[N_process] = 0;
 
 wait_prev = 0;
  
 
 
 for(i=0;i<N_process;i++)
 {
 	printf("\nEnter absolute start time, exec time and absolute deadline for process %d:",i+1);
 	scanf("%d %d %d", &start[i], &exec[i], &deadline[i]);
 }
	
 int time_quatum      = 0;
 int end_false        = 1;
 int nearest_deadline = 10000;
 int index            = -1;
 int count            = 0;
 while(end_false)
 {
	for(i = 0; i< N_process;i++)
	{
	
		if(start[i] == time_quatum || exec[index] == 0)
		{
			
			
			if(flag[i] != 1)
			{
				if((deadline[i] - time_quatum) < nearest_deadline)
				{
					nearest_deadline = (deadline[i] - time_quatum);
					//printf("\n min deadline  %d, proc %d  , time %d, difference %d", nearest_deadline, i+1, time_quatum,(deadline[i] - time_quatum) );
					index            = i;
				}
			}
		}
		
		
	}
	if(exec[index] == 0)
			{
				nearest_deadline = 10000;
				index=-1;
			}
	if(index!=-1)
	{
	printf("\n from time quantum %d to %d, proc %d", time_quatum, time_quatum+1, index+1);
	exec[index]--;
	
	if(exec[index] == 0)
	{
		flag[index]=1;
		count++;
	}
	}
	if(count == N_process)
		end_false = 0;
	
 time_quatum++;
 }
 
}
