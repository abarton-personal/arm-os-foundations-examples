/* Note that this code needs to run in the kernel. It is privileged code since it accesses critical OS data
structures. The easiest way to implement this is to wrap up the code as a kernel module, which is
explained in Section 2.4.3. The printk function is like printf only it outputs to the kernel log,
which you can read with the dmesg utility */

#include <linux/module.h> /* Needed by all modules */
#include <linux/kernel.h> /* Needed for KERN_INFO */
#include <linux/sched.h> /* for task_struct */

int init_module(void)
{
    struct task_struct *task;

    for (task = current; task != &init_task; task = task->parent) 
    {
        printk(KERN_INFO " %d (%s) -> ", task->pid, task->comm);
    }
    
    printk(KERN_INFO " %d (%s) \n", task->pid, task->comm);

    return 0;
}