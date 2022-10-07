# Git-Tutorial

# What's git?
![What's git](imgs/r_2329045_c5v7p.jpg)\
Git is a version control system, although it's spelled with three letters it actually doesn't stand for something specific.\
according to [initial commit of git](https://github.com/git/git/blob/e83c5163316f89bfbde7d9ab23ca2e25604af290/README), it can stands for multiple things:

>	GIT - the stupid content tracker"git" can mean anything, depending on your mood.
> - "global information tracker": you're in a good mood, and it actually
   works for you. Angels sing, and a light suddenly fills the room. 
> - "goddamn idiotic truckload of sh*t": when it breaks

# What's version control system?
A system that records changes in the system, yes just that.
> This is a stupid (but extremely fast) directory content manager.\
> It doesn't do a whole lot, but what it **does** do is track directory
contents efficiently.

# Where's the problem in doing it by hand, why learn to use git?
If we want to avoid failure in the system, we would create a backup of the project, and if the project fails we would restore it from the backup.\
like this:
- 📁 Project
- 📁 Project_backup

but the process of creating a project doesn't happen in one day, so it makes sense we keep track of changes in case a failure happens, it would look like this:
- 📁 Version 1
- 📁 Version 2
- 📁 Version 3
- 📁 Version 4
- ...
- 📁 Version 219

and that if we were working alone, but if we were working with a team, we must create a folder for each change we made, and for each team member, like this:
- 📁 Version 1
  - 📁 Team member 1
  - 📁 Team member 2
  - 📁 Team member 3
  - 📁 Team member 4
  - 📁 Final version
-  📁 Version 2
   - 📁 Team member 1
   - 📁 Team member 2
   - 📁 Team member 3
   - 📁 Team member 4
   - 📁 Final version
- 📁 Version 3
  - 📁 Team member 1
  - 📁 Team member 2
  - 📁 Team member 3
  - 📁 Team member 4
  - 📁 Final version
- and so on... you got the idea

that if we accesed the project from one device, but in real life we work on multiple devices, so we must create a centerlized folder for that all of the team members can access it, and in order to avoid conflicts, we must create a folder for each team member again, then we combain all their work, like this:
- 📁 Version 1
  - 📁 Team member 1
  - 📁 Team member 2
  - 📁 Team member 3
  - 📁 Team member 4
  - 📁 Final version

but what if two team members worked on the same file at the same time?\
then we should review their work and merge them together, and if the project was big enough, it would be impossible to do that manually, counting for human errors.

all of that and more shift the focus from the actual project to managing the project files.

that's why we use git, and it's not limited to just that, it can do more.
![Git is the solution](imgs/baby-git-release.png)


# There are three main components of a Git project:

- **Working tree (working directory)** :
   - It consists of files that you are currently working on. 
   - You can think of a working tree as a file system where you can view and modify files.

- **Staging Area (Index)** :
  - It is where commits are prepared. 
  - The index compares the files in the working tree to the files in the repo. 
  - When you make a change in the working tree, the index marks the file as modified before it is committed.

- **Repository (repo)** :

  - It is the “container” that tracks the changes to your project files. 
  - It holds all of the commits — a snapshot of all your files at a point in time — that have been made. 
  - You can access the commit history with the Git log.

## The basic workflow of Git.

When you modify a file, the change will only be found in the working tree. You must then stage the changes if you want to include them in your next commit. Once you finish staging all files, you can commit them and add a message describing what you changed. The modified files will then be safely stored in the repo.

**Step 1 −** You modify a file from the working directory.

**Step 2 −** Stage the changes you want to include in the next commit.

**Step 3 −** Commit your changes. (Committing will take the files from the index and store them as a snapshot in the repository.)

![image](imgs//163606654-ed29a836-0813-408c-a186-a229f2b7d736.png)


# How to install git?
## Windows
- Download the installer from [git-scm.com](https://git-scm.com/downloads)

## Linux
- Open the terminal and type:
```bash
sudo apt install git
```
- or
```bash
sudo pacman -S git
```

# Git Version

 To check your current version of Git
 
 `git --version`
 
 
# Git configuration levels

- **Local** --> The current repository.
- **Global** --> All repositories of the current user.
- **System** --> All users.


 **The order of priority of the Git config is local, global, and system, respectively.** 

 It means when looking for a configuration value, Git will start at the local level and bubble up to the system level.


## --local

- It is the default level in Git. Git config will write to a local level if no configuration option is given.

- Local configuration values are stored in **.git/config** directory as a file.

## --global

- The global level configuration is user-specific configuration. User-specific means, it is applied to an individual operating system user. 

- Global configuration values are stored in a user's home directory. ||**~ /.gitconfig**|| on UNIX systems and **C:\Users\username\.gitconfig** on windows as a file format.

## --system

- The system-level configuration is applied across an entire system. The entire system means all users on an operating system and all repositories. 

- The system-level configuration file stores in a gitconfig file off the system directory. $(prefix)/etc/gitconfig on UNIX systems and C:\ProgramData\Git\config on Windows.



# Git config command

- **Setting username**
  
  `git config --global user.name "Salma"`


- **Setting email id**
 
  `git config --global user.email "salma@example.com"`
  
⬆ This information is used by Git for each commit.

  
- **Setting default editor**
   `git config --global core.editor "code --wait"`
  
  - Here we specified vscode as our default editor
  - The `wait` flag to tell the terminal window to wait until we close the **new** vscode instance

  If you have not selected any of the editors, Git will use your default system's editor.

- ***Setting default branch**
   - To configure the initial branch name to use in all of your new repositories: `git config --global init.defaultBranch <name>`
      -  E.g,`git config --global init.defaultBranch "main"` 
   
   - To see local branch names : `git branch`
   - To see all remote branch names : `git branch -r`
   - To see all local and remote branches : `git branch -a`
 
- **Configuring git Credentials**
   - Git will sometimes need credentials from the user in order to perform operations; for example, it may need to ask for a username and password in order to access a remote repository over HTTP. 
   - To avoid inputting these credentials repeatedly:
      - Make Git store the username and password and it will never ask for them : `git config --global credential.helper store`
      - Save the username and password for a session (cache it) : `git config --global credential.helper cache`
      - You can also set a timeout for the above setting : `git config --global credential.helper 'cache --timeout=600'`
 
    
- **Listing Git settings**

   `git config --list`

   Git settings of the local repository

- **To editing Global Settings**
  `git config --global -e`

To edit all the global settings using our default editor in this code using vscode.



------------------------------------------------

# Git Init command

Initializing a repository a local repository.

 `git init Demo`  


# Git clone command

This command allows creating a local copy of that repository on your local directory from the repository URL.

 `git clone URL`  


# Git add command (Staging files)

- This command is used to add one or more files in your **working directory** to **staging (Index) area.**

- `git add` is an important command - without it, no git commit would ever do anything.


**Syntax**

- `git add <path>` : Stage a specific directory or file
  - Examples : 
     - Stages a single file : `git add README.md`   
     - Stages multiple files :`git add file1.js` file2.js`
     - Stages with a pattern : `git add *.js`
      
- `git add .` : Stages the current directory and all its content that are not listed in the **.gitignore**

- `git add -p` : Interactively stage hunks of changes


# Viewing the status 

- Full status : `git status`  

- Short status : - `git status -s`  


# Committing the staged files 

 - Commits with a one-line message : `git commit -m “Message”` 

- Opens the default editor to type a long message : `git commit` 


# Skipping the staging area 

 `git commit -am “Message” `

- Say you have 10 files. You made changes to 5 of them and created 5 more. You have two choices.

  **1-** You can do `Git add file1`, `Git add file2` ...etc
This will take my changes and add them to a "staging" area. From there you can do a git commit, which will commit the changes to my local repository. If you wanted to push those changes to a remote repository, you would do "git push"

  **2-** You could use a shortcut. `Git commit -a` Will automatically add any files that were changed to the "Staging" area as well as commit them.

# Listing the staging area files
`git ls-files`


# Removing files
 
 - Removes from working directory only: `rm file.txt` --> Not a git command 
 - Removes from staging area only : `git rm --cached file1.txt` 
 - Removes from working directory and staging area : `git rm file1.txt`

# Renaming or moving files 

- Rename a file on working directory only : ` mv oldName newName`

- Rename a file on working directory and staging area  :  `git mv oldName newName`


----------------------------------------------------

# Gitignore

- The **.gitignore** file is a text file that tells Git which files or folders to ignore in a project.

- A local .gitignore file is usually placed in the root directory of a project. You can also create a global .gitignore file and any entries in that file will be ignored in all of your Git repositories.

- To create a local .gitignore file, create a text file and name it .gitignore **(remember to include the . at the beginning)**. Then edit this file as needed. Each new line should list an additional file or folder that you want Git to ignore.
     - `nano .gitignore'
     - `git add  .gitignore`
     - `git commit -m "Add .gitignore"`

- The entries in this file can also follow a matching pattern.

  - **\*** is used as a wildcard match
  - **/** is used to ignore pathnames relative to the .gitignore file
  - **#** is used to add comments to a .gitignore file

- This is an example of what the .gitignore file could look like:
   ```
   # Ignore test folder
   test/

   # Ignore all text files
   *.txt

   # Ignore files related to API keys
   .env
   
   ```

- To add or change your global .gitignore file, run the following command:

   `git config --global core.excludesfile ~/.gitignore_global`

  This will create the file **~/.gitignore_global**. Now you can edit that file the same way as a local .gitignore file. All of your Git repositories will ignore the files  and folders listed in the global .gitignore file.

----------------------------------------------------


# CRLF vs. LF: Normalizing Line Endings in Git


- On windows end of lines are marked with two special characters  carriage return \r and line feed \n

- On Max or Linux systems end of lines are indicated with line feed \n

If one developer uses Windows and another uses Mac or Linux, and they each save and commit the same files, they may see line ending changes in their Git diffs—a conversion from CRLF to LF or vice versa. This leads to unnecessary noise due to single-character changes and can be quite annoying.

For this reason, Git allows you to configure line endings in one of two ways: by changing your local Git settings or by adding a .gitattributes file to your project. 


`git config --global core.autocrlf [true|false|input]`


|Setting	|	Working Tree (checkout)| Repo (check-in)|
|core.autocrlf=true	|	CRLF| LF |
|core.autocrlf=input|	original (usually LF, or CRLF if you're viewing a file you created on Windows)| 	LF|


## LF: Line Feed
LF stands for "line feed," but you're probably more familiar with the term newline (the escape sequence \n). Simply put, this character represents the end of a line of text. On Linux and Mac, this is equivalent to the start of a new line of text. That distinction is important because Windows does not follow this convention. 

## CR: Carriage Return
CR (the escape sequence \r) stands for carriage return, which moves the cursor to the start of the current line. For example, if you've ever seen a download progress bar on your terminal, this is how it works its magic. By using the carriage return, your terminal can animate text in place by returning the cursor to the start of the current line and overwriting any existing text.


------------------------------------

# Revert the full commit

- Reverting a commit means to create a new commit that undoes all changes that were made in the bad commit (Undo a whole commit with all changes). 

`git revert {commit_id}`
e.g, `git revert 3f08719`


# Viewing Repo Timeline

- `git log` : Shows the commit history for the currently active branch.
- `git log --oneline` : Shows the commit history for the currently active branch in a compact format.
- `git log --oneline --graph` : Shows the commit history for the currently active branch in a compact format with a graph.
- `git log --oneline --graph --all` : Shows the commit history for all branches in a compact format with a graph.
- `git log --oneline --graph --all --decorate` : Shows the commit history for all branches in a compact format with a graph and branch names.

# Comparing Commits
- `git diff {commit_id1} {commit_id2}` : Shows the difference between two commits.
- `git diff {commit_id1} {commit_id2} --stat` : Shows the difference between two commits with a summary of the changes.
- `git diff {commit_id1} {commit_id2} --stat --color-words` : Shows the difference between two commits with a summary of the changes and highlights the changes in color.
- `git diff {commit_id1} {commit_id2} --stat --color-words --word-diff-regex=.` : Shows the difference between two commits with a summary of the changes and highlights the changes in color. This command also shows the changes in the middle of a word.

# All about Branches

- `git branch {branch_name}` : Creates a new branch.

- `git checkout {branch_name}` : Switches to the specified branch and updates the working directory.

- `git checkout -b {branch_name}` : Creates a new branch and switches to it.

- `git branch -d {branch_name}` : Deletes the specified branch.

- `git branch -D {branch_name}` : Deletes the specified branch. This command is used to delete a branch that has unmerged changes.

- `git branch -m {old_branch_name} {new_branch_name}` : Renames the specified branch.

- `git branch -M {old_branch_name} {new_branch_name}` : Renames the specified branch. This command is used to rename a branch even if the new branch name already exists. ie, force rename

- `git branch -a` : Lists all branches. This command shows both remote-tracking branches and local branches.

# Pull vs Fetch

- `git pull` : Fetches and merges changes on the remote server to your working directory. (Fetch + Merge)

- `git fetch` : Fetches changes on the remote server to your local repository. This command downloads all new branches from the remote repository and all commits from these branches. It will not merge these changes with your local branches. (Update local repo)

