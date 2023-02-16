import os

def child():
    print ("Child process has PID {:d}".format(os.getpid()))

def parent():
    # only parent executes this code
    print ("Parent process has PID {:d}".format(os.getpid()))
    child_pid = os.fork()
    # both parent and child will execute subsequent if statement
    if child_pid==0:
        # child executes this
        child()
    else:
        # parent executes this
        print ("Parent {:d} has just forked child {:d}".format(os.getpid(), child_pid))

parent()