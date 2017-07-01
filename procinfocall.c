#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<linux/time.h>
#include "processInfo.h"

asmlinkage long sys_listProcessInfo(void) {
    struct task_struct *proc;
    struct sysinfo si;
    sysinfo (&si);
 
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
  
       printk("Tempo do sistema: %ld dias, %ld:%02ld:%02ld\n", si.uptime/(24*60*60), (si.uptime % (24*60*60))/60*60,
             (si.uptime % (60*60))/60, si.uptime % 60));
       printk("\n\n");

   }
  
  return 0;
}



