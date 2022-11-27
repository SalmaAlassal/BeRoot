# VIM

## What is VIM ? 

Vim is an improved version of the **vi** editor distributed with **Linux and UNIX** systems. Vim is highly
configurable and efficient for ***practiced users***, including such features as split screen editing, color
formatting, and highlighting for editing text.

## Why to learn VIM ? 

- You should know how to use at least one text editor that can be used from a **text-only shell prompt**.
- The key reason is that Vim is **almost
always installed on a server**, if any text editor is present.

## VIM Modes : 
![](./imgs/vim_modes.png)

### **Command mode** *aka* **Normal Mode** :
- Is the default mode that **vim start in** and we can navigate among other modes through it.
- This mode is the place that we spent most our time in.
- **To return to this mode** from other modes see the image above.

### **Insert Mode** : 
- Is the second most used mode in **vim** .
- As the name indicate .. it's used to insert text to the file that we use . 
- To enter this mode press `i` 

### **Visual mode** :
- It's used to select text similar to how clicking and dragging with a mouse behaves. 
 - **After selecting text** using the visual mode you can return back to the **command mode** and copy ,paste or delete the selected text using the keys `y` `p` `x` **in order**.
- #### **Visual mode types** : 
    1. #### **Character mode  :**
        Select **single characters**.
        to enter this mode press `v`

    2. #### **Line mode :**
        Select text **by line**.\
        to enter this mode press `Shift + v`
    3. #### **Block mode :** 
        **Rectangle selection** of text.
        to enter this mode press `Ctrl + v`

### **Extended Command mode :**
- To enter this mode press `:`
- used to give vim commands\
***Examples:***
    1. `:w` to save changes made to the file.
    2. `:wq` save the changes then **exit vim**.
    3. `:q!` discard the chnages we made and then **exit vim**.
## *Notes* : 
- Before switching between different modes you should **return to the command mode first**\
**Example**: \
If I want to switch from **insert mode** to **visual mode** I should first return to the commmand mode by pressing `Esc` and then enter the insert mode by pressing `i` .
- You can move inside the file using the **arrow keys** in any mode , but it's considered a **good practise to return to the command mode and using (h,j,k,l)** instead. 

    ![](./imgs/vim_keys.jpeg)
    
    play this game to get your self familier with using the **(h,j,k,l)** keys => [vim-adventure](https://vim-adventures.com/)

- To **undo** the last change enter the  **command mode** then type `u` and to **redo** press `Ctrl+r`
- To go to the start of a file enter the **command mode** then type `gg` and to go to the end of a file type `G` (can be useful when dealing with large files).

## Extend your knowledge : 
- Run the command `vimtutor` and read through the output .
- https://www.freecodecamp.org/news/vim-editor-modes-explained/
- **practise..practise..practise**