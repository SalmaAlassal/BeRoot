## File Compression and Archiving

- An **archive file** is a collection of files and directories that are stored in one file. **The archive file is not compressed** — it uses the same amount of disk space as all the individual files and directories combined.

- A **compressed file** is a collection of files and directories that are stored in one file and stored in a way that uses less disk space than all the individual files and directories combined. If you do not have enough disk space on your computer, you can compress files that you do not use very often or files that you want to save but do not use anymore. You can even create an archive file and then compress it to save disk space.

> Note : An archive file is not compressed, but a compressed file can be an archive file.

-----------------------------------------------------

## Compression Only


| Compression Tool | File Extension | Uncompression Tool | Example |
|------------------|----------------|--------------------|---------|
| `gzip`	       |     `.gz`      |      `gunzip`      |**Compress :** `gzip fileName`     <br> **Decompress** `gunzip fileName.gz`    |
| `bzip2`	       |     `.bz2`     |      `bunzip2`     |**Compress :** `bzip2 fileName`    <br> **Decompress** `bunzip2 fileName.bz2`  |


- You can compress multiple files :
    - `gzip file1 file2 file3`  ⇾ **Output :** file1.gz file2.gz file3.gz
    - `bzip2 file1 file2 file3` ⇾ **Output :** file1.bz2 file2.bz2 file3.bz2

    >  gzip and bzip2 can't add multiple files into one archive.

- You can decompress multiple files :
    - `gunzip file1.gz file2.gz file3.gz`
    - `bunzip2 file1.bz2 file2.bz2 file3.bz2` 

You can compress multiple files and directories :

- `bzip2 file1 file2 file3 /usr/work/school/*` 

- `gzip -r file1 file2 file3 /usr/work/school`  ⇾ **Output :** file1.gz file2.gz file3.gz /usr/work/school/AllFiles.gz

------------------------------------------------------

## Archiving and Compression `zip`

|   Tool           | File Extension | Decompression Tool | Example |
|------------------|----------------|--------------------|---------|
| `zip`	           |     `.zip`     |      `unzip`       |**Compress :** `zip file.zip fileName` <br> **Decompress**  `unzip fileName.zip`       |


- To compress multiple files : `zip files.zip file1 file2 file3` ⇾ **Output :** files.zip

- To decompress multiple files : `unzip '*.zip'`

- To compress multiple files and directories : ` zip -r filename.zip file1 file2 file3 /usr/work/school` 

    - The above command compresses file1, file2, file3, and the contents of the /usr/work/school directory and places them in a file named **filename.zip**.

> If you need to transfer files between Linux and other operating system such as MS Windows, you should use zip because it is more commonly used on those other operating systems.

-----------------------------------------------------

## Creating Archives with `tar`

- A tar file is a collection of several files and/or directories in one file. When you create an archive using `tar`, it will have a `.tar` extension.

- Some of the options used with the tar are:

    - `-c` — create a new archive.

     - `-x` — extract files from an archive.

    - `-f` — when used with the
        - `-c` option, use the filename specified for the creation of the tar file.
        - `-x` option, unarchive the specified file.

    - `-v` — tell the program to be verbose and let us see what it's doing.

    - `-t` — show the list of files in the tar file.

    - `-z` — compress the tar file with `gzip`.

    - `-j` — compress the tar file with `bzip2`.

    
- To create a tar file : `tar -cvf filename.tar files/directories`

    - `tar -cvf filename.tar /home/mine/work /home/mine/school`
        - The above command places all the files in the work and the school subdirectories of /home/mine in a new file called filename.tar in the current directory.

- To list the contents of a tar file : `tar -tvf filename.tar` or `tar -tf filename.tar`

- To extract the contents of a tar file : `tar -xvf filename.tar`


> Remember, the tar command does not compress the files by default. 

- To create a **tarred** and **gzipped** compressed file, use the `-z` option: `tar -czvf filename.tgz files/directories`
    - tar files compressed with gzip are conventionally given the extension `.tgz` or `tar.gz`.

    - This command creates the archive file **filename.tar** and then compresses it as the file **filename.tgz**. If you uncompress the filename.tgz file with the gunzip command, the filename.tgz file is removed and replaced with filename.tar.

- To extract a gzip tar archive : `tar xzvf filename.tar.gz`



- To create a **tarred and bzipped** compressed file, use the `-j` option : `tar -cjvf filename.tbz files/directories` 
    - tar files compressed with bzip2 are conventionally given the extension `.tbz`.

    - This command creates an archive file and then compresses it as the file filename.tbz. If you uncompress the filename.tbz file with the bunzip2 command, the filename.tbz file is removed and replaced with filename.tar.

- To extract a bzip2 tar archive : `tar xjvf filename.tar.tbz`

----------------------------------------------------------------------------------

[↗ List of archive formats](https://en.wikipedia.org/wiki/List_of_archive_formats)