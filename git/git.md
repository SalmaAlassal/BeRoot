# Git Installation

### Windows

Download the installer from [git-scm.com](https://git-scm.com/downloads)

### Linux

**Debian/Ubuntu**

```bash
sudo apt install git
```

**Fedora**
```bash
sudo dnf install git 
```

**Arch**
```bash
sudo pacman -S git
```

### Git Version

To check your current version of Git : `git --version`

If Git is installed, it should show something like `git version X.Y.Z`

----------------------------------------------------------------

# How to write Git commands?

Git is a command-line tool that does not have GUI (Graphical User Interface) by default, so developers have to know how to interact with it.

Git commands are usually written in the following format `git <command> [<args>]`

### Examples 

- `git init`
- `git add file.txt`
- `git add file.txt data.txt`

----------------------------------------------------------------

# Getting Help

Git Help can be accessed from your Git Bash just by typing the command `git help` 

This command will display all the information about Git. These are brief information to get any beginner started. 

![git help](imgs/git-help.png)

These commands as shown above are the most common commands used in Git. 

### There are a couple of different ways you can use the `help` command in command line:

- To see all the available commands in Git : `git help -a` or `git help --all`

- To get help on one particular command : `git help <command name>`
  - E.g, `git help clone`

- To see all the available options for the specific command : `git command -help`
  - E.g, `git clone -help`

- To open any specific guide : `git help <guide_name>`
  - E.g, `git help attributes`
  
> Note: If you find yourself stuck in the list view, type `q` to exit the view.

[Git online man Page](https://git-scm.com/docs/git "Git Documentation")

------------------------------------------------------------------

# Git Configuration Levels

- **Local** → The current repository.
- **Global** → All repositories of the current user.
- **System** → All users.

**The order of priority of the Git config is local, global, and system, respectively.** It means when looking for a configuration value, Git will start at the local level and bubble up to the system level.

## First-Time Git Setup

Now that you have Git on your system, you’ll want to do a few things to customize your Git environment. You should have to do these things only once on any given computer; they’ll stick around between upgrades. You can also change them at any time by running through the commands again.

### `--local`

- It is the default level in Git. Git config will write to a local level if no configuration option is given.

- Local configuration values are stored in **.git/config** directory as a file.

### `--global`

- The global level configuration is user-specific configuration. User-specific means, it is applied to an individual operating system user. 

- Global configuration values are stored in a user's home directory. **~ /.gitconfig** on UNIX systems and **C:\Users\username\.gitconfig** on Windows.

### `--system`

- The system-level configuration is applied across an entire system. The entire system means all users on an operating system and all repositories. 

- The system-level configuration file stores in a gitconfig file off the system directory. `/etc/gitconfig` on UNIX systems and `C:\ProgramData\Git\config` on Windows.

## `git config` Command

Git comes with a tool called `git config` that lets you get and set configuration variables that control all aspects of how Git looks and operates. 

### Setting username
  
`git config --global user.name "Salma"`

### Setting email ID
 
`git config --global user.email "salma@example.com"`
  
**⬆ This information is used by Git for each commit.**
  
### Setting default editor

`git config --global core.editor "code --wait"`
  
Here we specified VS Code as our default editor

The `wait` flag to tell the terminal window to wait until we close the **new** vs code instance.

**If you have not selected any of the editors, Git will use your default system's editor.**

If you want to use VIM : `git config --global core.editor "vim"`

### Setting default branch

To configure the initial branch name to use in all of your new repositories: `git config --global init.defaultBranch <name>`

E.g,`git config --global init.defaultBranch "main"` 

### Setting the default behavior of `git push`

If you want to use `git push` without a branch specified (e.g, `git push origin main`) issue :
 `git config --global push.default current` → it pushes the current branch to a branch of the same name 

### Configuring git Credentials

Git will sometimes need credentials from the user in order to perform operations; for example, it may need to ask for a username and password in order to access a remote repository over HTTP. 

To avoid inputting these credentials repeatedly:
  - Make Git store the username and password, and it will never ask for them : `git config --global credential.helper store`
  - Save the username and password for a session (cache it) : `git config --global credential.helper cache`
  - You can also set a timeout for the above setting : `git config --global credential.helper 'cache --timeout=600'`
 
### Listing Git settings

Git settings of the local repository : `git config --list`

### To edit Global Settings

To edit all the global settings using our default editor : `git config --global -e`

------------------------------------------------
------------------------------------------------

# LF vs CRLF

- On Windows end of lines are marked with two special characters, carriage return `\r` and line feed `\n`

- On Mac or Linux systems end of lines are indicated with line feed `\n`

### LF: Line Feed

LF stands for "line feed," but you're probably more familiar with the term newline (the escape sequence `\n`). Simply put, this character represents the end of a line of text. On Linux and Mac, this is equivalent to the start of a new line of text. That distinction is important because Windows does not follow this convention. 

### CR: Carriage Return

CR (the escape sequence `\r`) stands for carriage return, which moves the cursor to the start of the current line. For example, if you've ever seen a download progress bar on your terminal, this is how it works its magic. By using the carriage return, your terminal can animate text in place by returning the cursor to the start of the current line and overwriting any existing text.

# Normalizing Line Endings in Git

If one developer uses Windows and another uses Mac or Linux, and they each save and commit the same files, they may see line ending changes in their `git diff`— a conversion from CRLF to LF or vice versa. This leads to unnecessary noise due to single-character changes and can be quite annoying. 

### Some Examples

- `git status` showing all your files as modified because of the automatic EOL conversion done when cloning a Unix-based EOL Git repo to a Windows one.

- If you have **prettier** (code formatter) enabled and the `endOfLine` property is set to `lf`. On the Windows machine the developer will encounter linting issues from prettier, like those below :

    ![prettier](imgs/prettier.png)

**For this reason, Git allows you to configure line endings in one of two ways:** 
  - by changing your local Git settings 
  - or by adding a `.gitattributes` file to modified your project. 

So you can collaborate effectively with people who use different operating systems.

### Changing your local Git settings

The below command is used to change how Git handles line endings. It takes a single argument :

**Syntax :** `git config --global core.autocrlf [true|false|input]`

```
         core.autocrlf=true                     core.autocrlf=input                        core.autocrlf=false

           repository                                repository                                 repository        
            ^       V                                 ^       V                                 ^        V          
           /         \                               /         \                               /          \         
      CRLF->LF     LF->CRLF                     CRLF->LF        LF                            /            \
         /              \                          /              \                          /              \ 
        /                \                        /                \                        /                \   
       /                  \                      /                  \                      /                  \   
      /                    \                    /                    \                    /                    \    
     /                      \                  /                      \                  /                      \      
file to commit      checked out file      file to commit      checked out file      file to commit      checked out file  

Or we can say :
→ true :            x -> LF -> CRLF
→ input:            x -> LF -> LF
→ false:            x -> x -> x

where x is either CRLF (windows-style) or LF (unix-style).
```
**Let's sum up :**

- If you're using Linux/MAC, use :  `git config --global core.autocrlf input`
- If you're using Windows, use : `git config --global core.autocrlf true`

## Gitattributes

The `.gitattributes` file allows you to specify the attributes that should be used by git when performing git actions, such as `git commit`, etc. In other words git automatically saves the file according to the attributes specified, every time a file is created or saved. One of these attributes is the **eol** (end of line) and is used to configure the line endings for a file.

### Why to use `.gitattributes` ?

You shouldn't rely on people having correctly configured Git installations. If someone with an incorrect configuration checked in a file, it would not be easily visible in a pull request, and you'd end up with a repository with inconsistent line endings.

The solution to this is to add a `.gitattributes` file on your repository and set the line endings to be automatically normalized like so:

```
# Auto detect text files and perform LF normalization
* text=auto

*.bat	        text eol=crlf
*.cmd           text eol=crlf
```

Now when anyone gets the code from the repo the default correct line ending will be used automatically via git, when creating and modifying the files.

**Remember to add the `.gitattributes` to the remote repo.**

[A Collection of Useful `.gitattributes` Templates](https://github.com/alexkaratarakis/gitattributes)

[Create `.gitattributes` file for your project.](https://gitattributes.io/)

--------------------------------------
--------------------------------------

# `git init` Command

Initializing a local repository : `git init`  

Git now knows that it should watch the folder you initiated it on. 

Executing this command will create a new `.git` subdirectory in your current working directory to keep track of changes. 

# `git add` Command (Staging Files)

This command is used to add one or more files in your **working directory** to **staging (Index) area.**

It is an important command without it, no git commit would ever do anything.

**Syntax :** `git add <path>` → Stage a specific directory or file
  
### Examples 

- Stages a single file : `git add README.md`   
- Stages multiple files :`git add file1.js` `file2.js`
- Stages a directory : `git add folder1`
- Stages multiple directories : `git add folder1 folder 2`
- Stages multiple files & directories : `git add folder1 folder2 file.txt`
- Stages with a pattern : `git add *.js` → Adds all files that ends with `.js`
- Stages the current directory and all its content that are not listed in the **.gitignore** : `git add .`  
- Stages all changes (new, modified, and deleted) files : `git add --all`

### `.` vs `*`

- `git add *` means add all files in the current directory, **except** for files whose name begin with a dot **.** This is your shell functionality and Git only ever receives a list of files.

- `git add .` has no special meaning in your shell, and thus Git adds the entire directory recursively, which is almost the same, but including files whose **names begin with a dot**.

# Removing Files/Directories
 
### Files

- Removes from working directory only: `rm file.txt` → Not a git command 
- Removes from staging area only : `git rm --cached file1.txt` 
- Removes from working directory and staging area : `git rm file1.txt`

### Directories

- Removes from working directory only: `rm -r  dir` → Not a git command 
- Removes from staging area only : `git rm -r --cached dir` 
- Removes from working directory and staging area : `git rm -rf dir`


# Renaming or Moving Files 

- Rename a file on working directory only : ` mv oldName newName` → Not a git command

- Rename a file on working directory and staging area : `git mv oldName newName`


# Listing the staging area files

`git ls-files`

# Viewing the Status 

- Full status : `git status`  

- Short status : - `git status -s` 

> * ?? - Untracked files
> * A - Files added to stage
> * M - Modified files
> * D - Deleted files 

# Committing the staged files 

Adding commits keep track of our progress and changes as we work. Git considers each commit change point or "save point".

- Commits with a one-line message : `git commit -m "A brief message"` 
  > The `commit` command performs a commit, and the `-m "message"` adds a message.

- Opens the default editor to type a long message : `git commit` 

> When we commit, we should always include a message.

# Skipping the staging area 

 `git commit -am “Message” `

> The `-am` allows us to add and message at the same time.

- Say you have 10 files. You made changes to 5 of them and created 5 more. You have two choices.

  1. You can do `git add file1`, `git add file2` ...etc. This will take my changes and add them to a "staging" area. From there you can do a git commit, which will commit the changes to my local repository. If you wanted to push those changes to a remote repository, you would do `git push`

  2. You could use a shortcut. `git commit -a` Will automatically add any files that were changed to the "Staging" area as well as commit them.

# Git Amend Command

It is a convenient way to modify the most recent commit. It lets you **combine** staged changes with the previous commit instead of creating an entirely new commit. 

Furthermore, it can also be used to simply edit the previous commit message without changing its snapshot.

> Usually used to change the latest commit message.

`git commit --amend -m "New message"`

# Adding a remote repository

To add a new remote, use the `git remote add` command on the terminal, in the directory your repository is stored at.

The git remote add command takes two arguments:

  - A remote name, for example, `origin`
    - In Git, "origin" is a shorthand name for the remote repository that a project was originally cloned from. More precisely, it is used instead of that original repository's URL - and thereby makes referencing much easier.
  - A remote URL, for example, `https://github.com/SalmaAlassal/BeRoot.git`

For example: `git remote add origin https://github.com/SalmaAlassal/BeRoot.git` → Set a new remote for the current working dir.

### Verify new remote

`git remote -v`

# `git push` Command

The git push command is used to upload local repository content to a remote repository. Pushing is how you transfer commits from your local repository to a remote repo.

**Syntax :** `git push <repo name> <branch name>`

**Example :** `git push origin master`

> To force a Git push use : `git push -f`

### Push to a Specific Remote Repository and All Branches in it

If you want to push all your changes to the remote repository and all branches in it, you can use: `git push --all <repo name>`

- `--all` is the flag that signals that you want to push all branches to the remote repository

# `git pull` Command

The git pull command is used to fetch and download content from a remote repository and immediately update the local repository to match that content.

When you are on the dev branch, `git pull` will update your local dev to the same point as the remote dev branch. Note that it will fetch all branches, but only pull the one you are on to the top of the tree.

# `git fetch` Command

`git fetch` gathers any commits from the target branch that do not exist in the current branch and stores them in your **local repository** (not the working directory). However, it does not merge them with your current branch. This is particularly useful if you need to keep your repository up to date, but are working on something that might break if you update your files. To integrate the commits into your current branch, you must use `git merge origin/<branch name>` afterwards.

> `git fetch` simply updates your `.git` folder with the packed data. It does not update your working directory only the internal `.git` folder.

# Pull vs Fetch

- `git pull` : Fetches and merges changes on the remote server to your working directory. **(Fetch + Merge)**
  > `git pull` says "bring the changes in the remote repository to where I keep my own code."

- `git fetch` : Fetches changes on the remote server to your local repository. This command downloads all new branches from the remote repository and all commits from these branches. It will not merge these changes with your local branches. **(Update local repo)**
  > `git fetch` is the command that says "bring my local copy of the remote repository up to date."


# `git clone` Command

`git clone URL` : This command allows creating a local copy of that repository on your local directory from the repository URL.

Internally, git clone first calls `git init` to create a new repository. It then copies the data from the existing repository, and checks out a new set of working files. 

Also, when you clone a repository, the command automatically adds that remote repository under the name **origin**.

> You can use `git clone URL` instead of `git init` & `git remote add origin URL` 

-----------------------------------------

# Comparing Commits

`git diff` simply displays the changes between two commits

- `git diff {commit_id1} {commit_id2}` : Shows the difference between two commits.
- `git diff {commit_id1} {commit_id2} --stat` : Shows the difference between two commits with a summary of the changes.
- `git diff {commit_id1} {commit_id2} --stat --color-words` : Shows the difference between two commits with a summary of the changes and highlights the changes in color.
- `git diff {commit_id1} {commit_id2} --stat --color-words --word-diff-regex=.` : Shows the difference between two commits with a summary of the changes and highlights the changes in color. This command also shows the changes in the middle of a word.

> Note: change the order of the commits affects the result as it displays the changes from commit1 and commit2.

---------------------------------------------

# Git Ignore

When sharing your code with others, there are often files or parts of your project, you do not want to share.

### Examples

- log files
- temporary files
- hidden files
- personal files
- etc.

Git can specify which files or parts of your project should be ignored by Git using a `.gitignore` file.

Git will not track files and folders specified in `.gitignore`. However, the `.gitignore` file itself id **tracked** by Git.

To create a local `.gitignore` file, create a text file and name it `.gitignore` **(remember to include the `.` at the beginning)**. Then edit this file as needed. Each new line should list an additional file or folder that you want Git to ignore.
     
  - `nano .gitignore`
  - `git add  .gitignore`
  - `git commit -m "Add gitignore"`

The entries in this file can also follow a matching pattern.

  - **\*** is used as a wildcard match
  - **/** is used to ignore just directories, add a slash at the end of the pattern. Otherwise, it will ignore both files and directories.
  - **#** is used to add comments to a `.gitignore` file


This is an example of what the `.gitignore` file could look like:

```bash
# ignore ALL .log files
*.log

# Ignore all files with the temp.md
temp.md

# ignore ALL files in ANY directory named temp
temp/

# ignore ALL files in ANY directory named test
test/
```

> Note: In this case, we use a single .gitignore which applies to the entire repository.
> It is also possible to have additional .gitignore files in subdirectories. These only apply to files or folders within that directory.

[A collection of useful .gitignore templates](https://github.com/github/gitignore)

--------------------------------------------------------

# `git clean` Command

The clean command cleans your working directory by recursively removing files that are not under version control(untracked files).

### Removes untracked files from your working directory.

Git provides you an option to do a dry run to know what files will be removed by this command : `git clean -n` or `git clean --dry-run`

Once you are cognizant of the files that will be removed, you can use `git clean -f` to force delete the files.

If you want to remove untracked directories, you have to just add `-d` to the command. `git clean -f -d`

---------------------------------------------

# Viewing Repo Timeline

- `git log` : Shows the commit history for the currently active branch.
- `git log remotename/branchname` : Shows the commit history for the remote repo.
- `git log --oneline` : Shows the commit history for the currently active branch in a compact format.
- `git log --oneline --graph` : Shows the commit history for the currently active branch in a compact format with a graph.
- `git log --oneline --graph --all` : Shows the commit history for all branches in a compact format with a graph.
- `git log --oneline --graph --all --decorate` : Shows the commit history for all branches in a compact format with a graph and branch names.

---------------------------------------------

# All about Branches

A **Branch** is a new/separate version of the main repository.

Using **Branches** allows you:

- Working on a new version without impacting the live version
- Creating a new branch to fix small errors then merge it to the live version.
- Divide the work between more than one person working on independent units.
- You can switch between different **Branches** and work on them without impacting each other.

### To check on Created Branches

```Bash
git branch
    NewBranch
  * master
```
The **\*** refers to that we are currently on that **Branch** (master).

### To navigate between Branches

```Bash
git checkout NewBranch  #Old Command
git switch NewBranch
```

### Commands

- `git branch` : Lists all local branch names

- `git branch -r ` : Lists all remote branch names

- `git branch -a` : Lists all branches. This command shows both remote-tracking branches and local branches.

- `git branch {branch_name}` : Creates a new branch.

- `git checkout {branch_name}` : Switches to the specified branch and updates the working directory.

- `git checkout -b {branch_name}` : Creates a new branch and switches to it.
  > Using `-b` on `checkout` will create a new branch if it doesn't exit then it will navigate to the new created branch.

- `git branch -d {branch_name}` : Deletes the specified branch.

- `git push origin -d {remote_branch_name}` : Deletes the remote branch from the server. 

- `git branch -m {old_branch_name} {new_branch_name}` : Renames the specified branch.

- `git branch -M {old_branch_name} {new_branch_name}` : Renames the specified branch. This command is used to rename a branch even if the new branch name already exists. Ie, force rename

---------------------------------------

# Merge Branches

First we need to navigate to our destination branch which will have the merged version, and it's usually the **master branch** then we **merge** the master branch with NewBranch.

```Bash
git checkout master
git merge NewBranch
```
Since we finished the work on **NewBranch** we can delete it.

```Bash
git branch -d Newbranch
```

# Merge Conflicts

Merge Conflict happens when there are two versions of the same file in the master and the other branch you want to merge into. 

To fix the conflict we edit the file with the conflict **in the destination branch** then we run **git commit** that will conclude the **merge**.

---------------------------------------

# Undoing Changes

There are two ways to undo changes: `git revert` and `git reset`.

# `git revert` Command

The `git revert` command can be considered an **'undo'** type command, however, it is not a traditional undo operation. Instead of removing the commit from the project history, it figures out how to **invert** the changes introduced by the commit and appends a new commit with the resulting **inverse content**. This prevents Git from losing history, which is important for the integrity of your revision history and for reliable collaboration.

**Reverting should be used when you want to apply the inverse of a commit from your project history.** This can be useful, for example, if you’re tracking down a bug and find that it was introduced by a single commit. Instead of manually going in, fixing it, and committing a new snapshot, you can use git revert to automatically do all of this for you.

### Revert the full commit

To do this, you need to know your previous correct **commit’s SHA code**. The SHA code can be found, with the help of `git log` or `git log  --oneline` command.

- `git revert {commit_id}`
  - E.g, `git revert 3f08719` → It simply creates a new commit that is the opposite of that commit.

![Revert](imgs/git-revert.png)

**IMPORTANT NOTE**

- `git revert` undoes a single commit—it **does not** "revert" back to the previous state of a project by removing all subsequent commits. In Git, this is actually called a **reset**, not a revert.

### Revert using `HEAD~x`

To **revert** to an earlier commit, use **HEAD~x** where **x** refers (**Number of steps**) : `git revert  HEAD~n`

**Steps :**

1. Find the previous commit.
1. Calculate the number of steps.
1. Make it the new commit.

`git revert HAED~2`

It will revert the 3rd previous commit.

# `git reset` Command 

`git reset` is the command we use when we want to move the repository back to a previous commit, discarding any changes made after that commit. Practically, you can think of it as a **"rollback"**—it points your local environment back to a previous commit. By "local environment," we mean your local repository, staging area, and working directory.

- `git reset [<mode>] [<commit>]`
  - E.g, `git reset --hard 2a5aad3` 

> If you type `git reset <commit id>`, Git assumes that you’re performing a mixed reset, as it’s the default reset option. 

### Mixed Reset `git reset --mixed `

In a nutshell, the mixed option resets your changes safely by preserving your **uncommitted or staged changes and resetting them as unstaged changes.** It gives you a chance to undo your changes that were ready to commit but didn’t actually get committed. 

### Possible to revert changes by using the following commands :

- `git add`
- `git commit`

### Hard Reset `git reset --hard {commit_id}`

The hard reset is a more direct and **dangerous** way to undo your changes as it deletes changes from everywhere. It not possible to revert changes.

The hard reset moves the HEAD pointer to your last commit and also resets the Staging Area as well as the Working Directory to that commit. **This means all your changes in the working tree and Staging Area are completely lost.** 


### Soft Reset `git reset --soft {commit_id}`

The soft reset deletes changes only from the local repository. It leaves both your Staging Area and your Working Directory unchanged.

#### Possible to revert changes by using the following commands :

- `git commit`

**Use Case - Combine a series of local commits**

"Oops. Those three commits could be just one."

So, undo the last 3 (or whatever) commits (without affecting the index nor working directory). Then commit all the changes as one.

#### Example
```
$ git add readme 
$ git commit -m "Start here."
$ git add file1  
$ git commit -m "One"
$ git add file2  
$ git commit -m "Two"
$ git add file3  
$ git commit -m "Three"
$ git log --oneline --graph -4 --decorate

  * da883dc (HEAD, master) Three
  * 92d3eb7 Two
  * c6e82d3 One
  * e1e8042 Start here.

$ git reset --soft e1e8042
$ git log --oneline --graph -1 --decorate

> * e1e8042 Start here.

Now all your changes are preserved and ready to be committed as one.
```

### Important Notes

`git reset` could be used to go backward or forward so store the **commit ID/hash** before applying the reset, so you can get back to any commit.

> When you use `git log` after rest you will find the commits are no longer displayed in the log, but they still exist.


# Resetting vs. Reverting

- **Reverting** has two important advantages over resetting :
  - First, it doesn’t change the project history, which makes it a **“safe”** operation for commits that have already been published to a shared repository.

  - Second, git revert is able to target an individual commit at an arbitrary point in the history, whereas `git reset` can only work backward from the current commit. For example, if you wanted to undo an old commit with `git reset`, you would have to remove all the commits that occurred after the target commit, remove it, then re-commit all the subsequent commits. Needless to say, this is not an elegant undo solution.

    ![Resetting vs. Reverting](imgs/Resetting-vs-reverting.png)

**Git revert is a safer alternative to git reset regarding losing work.**

----------------------------------------------------
----------------------------------------------------