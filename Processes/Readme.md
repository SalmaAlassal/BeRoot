# **What are Processes ?**

* Processes are the programs that are running on your machine. They are managed by the kernel and each process has an ID associated with it called the process ID (PID). This PID is assigned in the order that processes are created.

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/1.jpg)

***Any process can be run in two ways :***

* **Foreground process :** By default, All the processes are run in the foreground. When a process is run in foreground, no other process can be run on the same terminal until the process is finished or killed. When issuing this type of process, the system receives input from the keyboard(stdin) and gives output to the screen(stdout). 

* **Background process :** Adding ‘&’ to a foreground command makes it a background process. A background process runs on its own without input from the keyboard(stdin) and waits for input from the keyboard. While the process runs in the background, other processes can be run in the foreground.

--------------------------------------------------
# **There are five types of Process in Linux :**

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/6.png)


1.  **Parent process :**  The process created by the user on the terminal. All processes have a parent process, If it was created directly by user then the parent process will be the kernel process.
![parent](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/5.webp)
![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/7.jpg)


2. **Child process :**   The process created by another process (by its parent process). All child processes have a parent process.
Status of a process
- The example is given above, the process having PID 28500(last row) is a child process of the process having PID 26544.
  

3. **Orphan process :** Sometimes when the parent gets executed before its own child process then the child process becomes an orphan process. The orphan process have “Init” process (PID 0) as their PPID (parent process ID)
   

4. **Zombie process :** The processes which are already dead but shows up in process status is called Zombie process. Zombie processes have Zero CPU consumption.
![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/image289.webp)
![zombie](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/4.png)

5. **Daemon process :** These are system-related processes that run in the background. A Daemon process can be recognized if it has “?” in its TTY field (6th column)
--------------------------------------------------
# **State of a Process :**

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/2.png)

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/3.png)

In the STAT column, you'll see lots of values. A linux process can be in a number of different states. The most common state codes you'll see are described below:

* R: running or runnable, it is just waiting for the CPU to process it
* S: Interruptible sleep, waiting for an event to complete, such as input from the terminal
* D: Uninterruptible sleep, processes that cannot be killed or interrupted with a signal, usually to make them go away you have to reboot or fix the issue
* Z: Zombie, we discussed in a previous lesson that zombies are terminated processes that are waiting to have their statuses collected

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/10.webp)

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/9.gif)

* T: Stopped, a process that has been suspended/stopped

------------------------------------------

# **ps command :**

```
$ ps
```

![ps](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/ps.png)
![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/ps-axw.png)

**This shows you a quick snapshot of the current processes :**

* PID: Process ID
* TTY: Controlling terminal associated with the process (we'll go in detail about this later)
* STAT: Process status code
* TIME: Total CPU usage time
* CMD: Name of executable/command

----------------------------------------------
* If you look at the man page for ps you'll see that there are lots of command options you can pass, they will vary depending on what options you want to use - BSD, GNU or Unix. In my opinion the BSD style is more popular to use, so we're gonna go with that. If you are curious the difference between the styles is the amount of dashes you use and the flags.
---------------------------

```
ps -axw
```

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/ps-aux.png)

The **a** displays all processes running, including the ones being ran by other users. 

The **u** shows more details about the processes. 

And finally the **x** lists all processes that don't have a TTY associated with it, these programs will show a ? in the TTY field, they are most common in daemon processes that launch as part of the system startup.

You'll notice you're seeing a lot more fields now, no need to memorize them all, in a later course on advanced processes, we'll go over some of these again:

* USER: The effective user (the one whose access we are using)
* PID: Process ID
* %CPU: CPU time used divided by the time the process has been running
* %MEM: Ratio of the process's resident set size to the physical memory on the machine
* VSZ: Virtual memory usage of the entire process
* RSS: Resident set size, the non-swapped physical memory that a task has used
* TTY: Controlling terminal associated with the process
* STAT: Process status code
* START: Start time of the process
* TIME: Total CPU usage time
* COMMAND: Name of executable/command
--------------------------------------------------
**What ps flag is used to view detailed information about processes?**
* u
-------------------------------------------

# **top & htop commands**
![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/top-vs-htop.webp)

```
$ top
```
![top](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/top.png)

* Top command displays a list of processes that are running in real-time along with their memory and CPU usage. Let’s understand the output a little better:

* PID : Unique Process ID given to each process.
* User: Username of the process owner.
* PR: Priority given to a process while scheduling.
* NI: ‘nice’ value of a process.
* VIRT: Amount of virtual memory used by a process.
* RES : Amount of physical memory used by a process.
* SHR : Amount of memory shared with other processes.
* S : state of the process
    * ‘D’ = uninterruptible sleep
    * ‘R’ = running
    * ‘S’ = sleeping
    * ‘T’ = traced or stopped
    * ‘Z’ = zombie
* %CPU: Percentage of CPU used by the process.
* %MEM; Percentage of RAM used by the process.
* TIME+: Total CPU time consumed by the process.
* Command: Command used to activate the process.
  
---------------------------------

```
$ htop  [-dChusv]
```


* -d –delay : Used to show the delay between updates, in tenths of seconds.
* -C –no-color –no-colour : Start htop in monochrome mode.
* -h –help : Used to display the help message and exit.
* -u –user=USERNAME : Used to show only the processes of a given user
* -p –pid=PID, PID… : Used to show only the given PIDs.
* -s –sort-key COLUMN : Sort by this column (use –sort-key help for a column list).
* -v –version : Output version information and exit

--------------------------------

# **Signals**

A **signal** is a notification to a process that something has happened.

***Why we have signals ?***

They are software interrupts and they have lots of uses :

* A user can type one of the special terminal characters (Ctrl-C) or (Ctrl-Z) to kill, interrupt or suspend processes
* Hardware issues can occur and the kernel wants to notify the process
* Software issues can occur and the kernel wants to notify the process
* They are basically ways processes can communicate

***Signal process :***

When a signal is generated by some event, it's then delivered to a process, it's considered in a pending state until it's delivered. When the process is ran, the signal will be delivered. However, processes have signal masks and they can set signal delivery to be blocked if specified. **When a signal is delivered, a process can do a multitude of things :**

* Ignore the signal
* "Catch" the signal and perform a specific handler routine
* Process can be terminated, as opposed to the normal exit system call
* Block the signal, depending on the signal mask

***Common signals :***

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/killsignals.png)

Each signal is defined by integers with symbolic names that are in the form of **SIGxxx** . Some of the most common signals are:

* SIGHUP or HUP or 1 : Hangup
* SIGINT or INT or 2 : Interrupt
* SIGKILL or KILL or 9 : Kill
* SIGSEGV or SEGV or 11 : Segmentation fault
* SIGTERM or TERM or 15 : Software termination
* SIGSTOP or STOP : Stop


Numbers can vary with signals so they are usually referred by their names.

**Some signals are unblockable, one example is the SIGKILL signal. The KILL signal destroys the process.**

------------------------------------------
# **kill & kilall commads**

* **It is similar to End Task in Windows.**

*To send a sigkill, we can use the command*

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/kill-process-pkill1.png)

```
$ kill <PID>

$ killall <process_name>

$ kill -l
```

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/kill-l.png)

---------------------------------------
## **Differences between SIGHUP, SIGINT, SIGTERM, SIGKILL, SIGSTOP?**

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/Signals.png)

These signals all sound reasonably similar, but they do have their differences.

* SIGHUP - Hangup, sent to a process when the controlling terminal is closed. For example, if you closed a terminal window that had a process running in it, you would get a SIGHUP signal. So basically you've been hung up on
* SIGINT - Is an interrupt signal, so you can use Ctrl-C and the system will try to gracefully kill the process
* SIGTERM - Kill the process, but allow it to do some cleanup first
* SIGKILL - Kill the process, kill it with fire, doesn't do any cleanup
* SIGSTOP - Stop/suspend a process


# **Change priority of a process :**
In Linux, you can prioritize between processes. The priority value for a process is called the ‘Niceness’ value. Niceness value can range from **-20** to **19** . ***0*** is the default value.


The fourth column in the output of top command is the column for niceness value.

## **To start a process and give it a nice value other than the default one, use :**

```
$ nice -n [value] [process name]
```
![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/priority-with-nice.png)

To set the negative priority for a process 
![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/negative-priority-with-nice.png)

To change nice value of a process that is already running use:
```
$ renice -n [value] -p 'PID'
```
![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/priority-of-running-porcess.png)

------------------------------------------
![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/lovelinux.jpg)

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/memes.webp)

![](https://github.com/SalmaAlassal/BeRoot/blob/main/Processes/imgs/memes2.jpg)