# Terminal Types
 
Terminal equipment can be divided into the following types:

   - Virtual Terminal
   - Pseudo Terminal
   - Serial Port Terminal

# Virtual Console

> A virtual console (VC) – also known as a virtual terminal (VT)

**In the 1970s and 1980s,** people can often use only one terminal. Heavyweight people in a company or university can use multiple terminals, because they need to do many things with the operating system. So there would be several terminals on their desks.

**Nowadays,** we don’t need to put multiple terminals on the desk, because Linux can create **multiple virtual terminals**. One of them is **graphics terminal**, the other six is **character terminal**. The 7 virtual terminals are more commonly known as **virtual consoles**, and they use the same keyboard and monitor. 

When Linux boots up, it creates the 6 (maybe differ) virtual consoles and by default brings you to the graphics console, i.e, the desktop environment. Each virtual console supports an **independent login session**.

The file name is `/dev/ttyn` (e.g, `dev/tty1`, `dev/tty2`).

> Many system administrators choose not to run a graphical environment on their servers. This allows resources which would be used by the graphical environment to be used by the server's services instead.

> Virtual Terminals are similar to Terminal. The only difference is that you cannot use the mouse with the Virtual Terminals. 

> The graphical environment also runs on a virtual console.

## Navigating through Virtual Terminals

You can navigate between the 6 virtual terminals using the following command: 

```bash
Ctrl + Alt + F (1 to 6) key # or more, if you have configured more
```

### Example

```
CTRL + ALT + F1 – Lockscreen
CTRL + ALT + F2 – Desktop Environment
CTRL + ALT + F3 – TTY3
CTRL + ALT + F4 – TTY4
CTRL + ALT + F5 – TT5
CTRL + ALT + F6 – TTY6
```

You can work on all of at the same time.

> By default, in Fedora 36 the desktop runs on TTY2. In case of Ubuntu, it defaults to TTY7. 

> A desktop needs a tty to run but that does not make the GUI a tty. You should call it a session and a tty you use to login either to command line session or a desktop session.

> If you are already logged in to a graphical session, and log in as another user on the graphical login screen or use the Switch User menu item to switch users in the graphical environment without logging out, another graphical environment will be started for that user on the next free virtual console.

### Logging out

When you are finished using the shell and want to quit, you can choose one of several ways to end the session. You can enter the `exit` command to terminate the current shell session. Alternatively, finish a session by pressing `Ctrl+D`.

## Check TTY Number

- To know the TTY number you are connected to, just type in `tty`. And, if there are multiple users connected to the Linux machine remotely, you can use the `who` command to check what other users are connected to.

> `/dev/pts` shows you are in virtual terminal.

> `/dev/tty` shows you are in actual terminal.

- You can also run the `sudo fgconsole` command to check which tty you are using.



----------------------------------------------------------------

# Usages
 
### Single User

It should come in handy in case the graphical desktop environment **freezes**. In some cases, reinstalling the desktop environment from the TTY helps resolve the program.

Or, you can also choose to carry out **tasks** in TTY like updating the Linux system and similar, where you do not want visual issues to interrupt your process.

Worst-case scenario, you can go to the TTY and **reboot** the computer if your graphical user interface is unresponsive.

### Multi-user System 

Remember that Linux was originally a command-line only system and designed for multiple users. So what if different users need to work on the same system at a time? How do you do that? This is where we need the **virtual terminals**.

The idea was that each user could log into a single **tty**. This would not happen on the same physical machine of course, think of servers that many computer terminals would connect to. Each user would connect using a different computer and the server log them in to a **tty**.

Virtual Terminals enable a number of users to work on different programs at the same time on the same computer.

Usually, there are six (default) virtual terminals on a Linux operating system, and you can log into them as different users to conducts different tasks. 

## Number of virtual consoles 

Different Linux flavors offer different number of virtual consoles. For instance, **RHEL** provides **six** virtual consoles while **Ubuntu** provides **seven** virtual consoles. 

Virtual consoles are always mentioned along with **one physical console** (also known as default console). So, the actual number of virtual consoles remains one less than the total number of consoles. For example, in RHEL and Ubuntu the number of actual virtual consoles are 5 (six - one) and 6 (seven - one) respectively.

----------------------------------------------------------------------------------

# Pseudo Terminal (PTY)

Running the **terminal application** provides you with a **virtual environment** called a **pseudo terminal** which is running a shell that allows you to issue commands at its prompt. 

So a **pty** is virtual terminal device which is emulated by another program (e.g, xterm, screen, telnet, ssh …etc.).

The file name of the pseudo terminal is `/dev/pts/n`

> A **pts** is the slave part of a **pty**.

> A **pts device** is actually a **pseudo tty device**. Whenever you launch a terminal emulator or use any kind of shell in your system, it interacts with virtual TTYs that are known as **pseudo-TTYs** or **PTY**.

----------------------------------------------------------------------------------

# Serial Port Terminal

The computer considers each **serial port** to be a **"device"**. It's sometimes called a **terminal device**. 

For each such serial port there is a special file in the `/dev` (device) directory. The file name of the serial port terminal `/dev/ttySn`(the "S" stands for Serial port), for example `/dev/ttyS0` is the special file for the serial port known as `COM1` in the DOS/Windows world.

----------------------------------------------------------------------------------

# Extras

- [Linux Virtual Console and Terminal Explained](https://www.computernetworkingnotes.com/linux-tutorials/linux-virtual-console-and-terminal-explained.html)

- [Linux Terminal and Console Explained](https://www.linuxbabe.com/command-line/linux-terminal#:~:text=Physical%20console%20is%20the%20combination,virtual%20console%20you%20are%20using.)