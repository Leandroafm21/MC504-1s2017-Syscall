#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

asmlinkage long sys_listProcessInfo(void) {
    struct task_struct *proc;
 
    for_each_process(proc) {
       printk(
           "Process: %s PID: %ld\n",
           proc->comm, (long)task_pid_nr(proc)
       );
   }
  
  return 0;
}
