import os
import time

def main():
    child_pid = os.fork()
    # both parent and child will execute subsequent if statement
    if child_pid==0:
        # child executes this
        pid = os.getpid()
        print ("To see the zombie, run ps u -p {:d}".format(pid))
        exit()
    else:
        # parent executes this
        time.sleep(60)
        print ("Zombie process disappears now")
        
main()