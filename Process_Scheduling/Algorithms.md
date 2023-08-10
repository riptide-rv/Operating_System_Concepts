# ALGORITHMS
 *NOTE :  all answers are done with arrival time  , for   
  cases witout arrival time , assume arrival time as 0 and use 0 in the equations used.*


##  FCFS Scheduling ( with arrival time ) 
    
1. Accept the number of processes for ready queue
1. For each process assign a process id and accept arrival time and burst time.
3. For the first process , set waiting time as 0 , starting time as arrival time and turn around time as burst time and <br> endtime = start time + burst time.
1. For each following process  i set , <br>
start time = end time(i-1)<br>end time = burs time + start time<br>
turn around time = end time - arrival time<br>
waiting time = turn around time - burst time.
1. For each process executed , print the gnatt chart with process id , arrival time , burst time , start time , end time, waiting time and turnaround time.
1. Calculate <br>
Average waiting time = Total waiting time / number of processes<br>Average Turnaround time = total turn around time / number of processes 