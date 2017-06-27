#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<linux/time.h>
#include "processInfo.h"

asmlinkage long sys_listProcessInfo(void) {
    struct task_struct *proc;
 
    for_each_process(proc) {
       
       timespec start_time = proc->start_time;
       
       time_t actual_time = start_time;
       double actual_time_sec;
       actual_time = time(0);
       actual_time_sec = difftime(actual_time, 0);

       printk(
           "Process: %s\nPID: %ld\nStart Time: %g\n",
           proc->comm, (long)task_pid_nr(proc), actual_time_sec
       );
  
       printk("\n\n");

   }
  
  return 0;
}



