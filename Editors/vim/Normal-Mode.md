# Normal Mode

## Moving in a File

## Character Navigation 

|Character| Function |
|---------|----------|
|   `h`   |   Left   |
|   `j`   |   Down   |
|   `k`   |   Up     |
|   `l`   |   Right  |

Although you will use `hjkl` to move around at first, once you master vi/vim you probably won't use `h` and `l` ('left' and 'right') at all, and you will use `j` and `k` sparingly. Why is that? Because there are other, more powerful motions, that will often get you where you want to go much faster. 

You can also move with directional arrows, but the letter based replacement for the arrow keys allows you to navigate the text without taking your hands away from standard typing configuration. This is arguably **more efficient and faster** than moving your hand to hit the arrow keys.

> If you wonder why Vim uses `hjkl` to move, this is because Lear-Siegler ADM-3A terminal where Bill Joy wrote Vi, didn't have arrow keys and used `hjkl` as left/down/up/right.

### Important Notes

- By default the `j` and `k` movements always move by physical lines and not by screen lines. This may lead to a bunch of screen lines being taken up by only a single "real" line, so commands like `j` and `k` which move on real lines will skip over a lot of screen lines. You can use `gj` and `gk` to move by screen lines.

- Moving up or down to a shorter line moves you to the last column in the shorter line, but if you keep moving to a longer line you'll end up in the same column where you started!

### Extra

There are also plugins to help break this bad habit. One of them is [vim-hardtime](https://github.com/takac/vim-hardtime).

## Current Line Navigation

|Character     | Function                                                                         |
|--------------|----------------------------------------------------------------------------------|
|  `0`         | Go to the **first char** in the current line.                                    |
|  `$`         | Go to the **last char** in the current line.                                     |
|  `^`         | Go to the **first nonblank char** in the current line.                           |
|  `g_`        | Go to the **last non-blank char** in the current line.                           |
| `f` <br> `F` | Search **forward** for a **match** in the same line.                             |
|  `t`         | Search **forward** for a **match** in the same line, **stopping before match**.  |
|  `;`         | **Repeat** the last search in the same line using the **same direction.**        |
|  `,`         | **Repeat** the last search in the same line using the **opposite direction.**    |


**Example:** `const hello = "world";`

With your cursor at the start of the line, you can go to the last character in current line (";") with one keypress: `$`. If you want to go to "w" in "world", you can use `fw`.

## Word Navigation

### word & WORD Similarities

Both word and WORD are separated by non-blank characters.

### word & WORD Differences

- A **word** is a sequence of characters containing only `a-zA-Z0-9_`. 

- A **WORD** is a sequence of all characters except white space (a white space means either space, tab, and EOL). 

|Character     | Function                                                   |
|--------------|------------------------------------------------------------|
|   `w`        | Move forward to the **beginning** of the **next word**.    |
|   `W`        | Move forward to the **beginning** of the **next WORD**.    |
|   `e`        | Move forward one word to the **end** of the **next word**. |
|   `E`        | Move forward one word to the **end** of the **next WORD**. |
|   `b`        | Move backward to **beginning** of the **previous word**.   |
|   `B`        | Move backward to **beginning** of the **previous WORD**.   |
|   `ge`       | Move backward to **end** of the **previous word**.         |
|   `gE`       | Move backward to **end** of the **previous WORD**.         |


## Count Your Move

Vim motions accept a preceding numerical argument. You can go down 12 lines with `12j`. The 12 in `12j` is the count number.

The syntax to use count with your motion is: `[count] + motion`

You can apply this to all motions. If you want to move 9 characters to the right, instead of pressing `l` 9 times, you can do `9l`.


## Line Number Navigation `gg` `G`

`gg` will move you to **the first line** in the file, and `G` will move you to **the last line** in the file. 

Alternatively, if you type `nG` or `ngg` where n is a number, you'll jump to that line, e.g, `5G` or `5gg`.

Often you don't know exactly what line number your target is, but you know it's approximately at 70% of the whole file. In this case, you can do `70%`. To jump halfway through the file, you can do `50%`.

|Key |Function                |
|----|------------------------|
|`gg`|Go to the **first line**|
|`G `|Go to the **last line** |
|`nG`|Go to **line n**        |
|`n%`|Go to **n% in file**    |   


## Match Navigation `%`

In text that is structured with parentheses or brackets, `(` or `{` or `[`, use `%` to jump to the matching parenthesis or bracket.

Here is `(a sample)` text to try that. 

If the cursor is on a non-bracket character and a bracket character is present later in the line, the `%` command will move to the matching pair of that character (which could be present in some other line too).

Default supported pairs: `()`, `{}`, `[]` - use `:h matchpairs` in vim for more info.

Use the `matchpairs` option to customize the matching pairs. For example, `:set matchpairs+=<:>` will match` <>` as well.

## Sentence and Paragraph Navigation

A sentence ends with either `.` `!` `?` followed by an `EOL`, a `space`, or a `tab`. You can jump to the next sentence with `)` and the previous sentence with `(`.

|Key|Function                      |
|---|------------------------------|
|`(`|Jump to the previous sentence.|
|`)`|Jump to the next sentence.    |

A paragraph begins after each empty line and also at each set of a paragraph macro specified by the pairs of characters in paragraphs option.

|Key|Function                       |
|---|-------------------------------|
|`{`|Jump to the previous paragraph.|
|`}`|Jump to the next paragraph.    |

Check out `:h sentence` and `:h paragraph` to learn more.

## Scrolling

To scroll, you have 3 speed increments: 
  - **full-screen** (`Ctrl-F`/`Ctrl-B`)
  - **half-screen** (`Ctrl-D`/`Ctrl-U`)
  - **line** (`Ctrl-E`/`Ctrl-Y`).

|Key     |Function                |
|--------|------------------------|
|`Ctrl-E`|Scroll down a line      |
|`Ctrl-D`|Scroll down half screen |
|`Ctrl-F`|Scroll down whole screen|
|`Ctrl-Y`|Scroll up a line        |
|`Ctrl-U`|Scroll up half screen   |
|`Ctrl-B`|Scroll up whole screen  |

You can also scroll relatively to the **current line** (zoom screen sight):

|Key |Function                                              |
|----|------------------------------------------------------|
|`zt`| Bring the current line near the top of your screen   |
|`zz`| Bring the current line to the middle of your screen  |
|`zb`| Bring the current line near the bottom of your screen|

## Search Navigation

Often you know that a phrase exists inside a file. You can use search navigation to very quickly reach your target. To search for a phrase, you can use `/` to search forward and `?` to search backward. To repeat the last search you can use `n`. To repeat the last search going opposite direction, you can use `N`.

> For advanced use cases, it's possible to use regexps that help to find text of particular form. 

|Key|Function                                                       |
|---|---------------------------------------------------------------|
|`/`|Search **forward** for a match                                 |
|`?`|Search **backward** for a match                                |
|`n`|Repeat last search in **same direction** of previous search    |
|`N`|Repeat last search in **opposite direction** of previous search|

You can enable search highlight with `set hlsearch`. Now when you search for `/let`, it will highlight all matching phrases in the file. In addition, you can set incremental search with `set incsearch`. This will highlight the pattern while typing. By default, your matching phrases will remain highlighted until you search for another phrase. This can quickly turn into an annoyance. To disable highlight, you can run `:nohlsearch`.

You can quickly search for the text under the cursor with `*` to search forward and `#` to search backward. If your cursor is on the string "one", pressing `*` will be the same as if you had done `/\<one\>`.

Both `\<` and `\>` in `/\<one\>` mean whole word search. It does not match "one" if it is a part of a bigger word. It will match for the word "one" but not "onetwo". If your cursor is over "one" and you want to search forward to match whole or partial words like "one" and "onetwo", you need to use `g*` instead of `*`.

|Key |Function                                                       |
|----|---------------------------------------------------------------|
|`* `|Search for whole word under cursor forward                     |
|`# `|Search for whole word under cursor backward                    |
|`g*`|Search for word under cursor forward                           |
|`g#`|Search for word under cursor backward                          |

## Marking Position

You can use marks to save your current position and return to this position later. It's like a bookmark for text editing. You can set a mark with `mx`, where x can be any alphabetical letter `a-zA-Z`. There are two ways to return to mark: exact (line and column) with ``x` and linewise (`'x`).


|Key     |Function                   |
|--------|---------------------------|
|`ma`    |Mark position with mark "a"|
|`` `a ``|Jump to line and column "a"|
|`'a`    |Jump to line "a"           |


There is a difference between marking with lowercase letters (a-z) and uppercase letters (A-Z). Lowercase alphabets are local marks and uppercase alphabets are global marks (sometimes known as file marks).

Let's talk about local marks. Each buffer can have its own set of local marks. If I have two files opened, I can set a mark "a" (`ma`) in the first file and another mark "a" (`ma`) in the second file.

Unlike local marks where you can have a set of marks in each buffer, you only get one set of global marks. If you set `mA` inside myFile.txt, the next time you run `mA` in a different file, it will overwrite the first "A" mark. One advantage of global marks is you can jump to any global mark even if you are inside a completely different project. Global marks can travel across files.

To view all marks, use `:marks`. You may notice from the marks list there are more marks other than `a-zA-Z`.  If you're curious, check out :`h marks`.

----------------------------------------------------
----------------------------------------------------

## Yank, Delete and Put
## Copy, Cut and Paste

Vim has its own terminology for copying, cutting, and pasting. **Copy** is called **yank** (`y`), **cut** is called **delete** (`d`), and **paste** is called **put** (`p`).

### Yanking (Copying)

To copy text, place the cursor in the desired location and press the `y` key followed by the movement command. Below are some helpful yanking commands:

- `yy ` – Yank the current line, including the newline character.
- `3yy` – Yank three lines, starting from the line where the cursor is positioned.
- `y$ ` – Yank everything from the cursor to the end of the line.
- `y^ ` – Yank everything from the cursor to the start of the line.
- `yw ` – Yank to the start of the next word.
- `yiw` – Yank the current word.
- `y% ` – Yank to the matching character. Useful to copy text between matching brackets.

### Deleting (Cutting)

`d` is the key for cutting (deleting) text, **it also copies the content**, so that you can paste it with `p` to another location.

Move the cursor to the desired position and press the `d` key, followed by the movement command. Here are some helpful deleting commands:

- `dd ` – Delete the current line, including the newline character.
- `3dd` or `d3j` – Delete three lines, starting from the line where the cursor is positioned.
- `d$ ` – Delete everything from the cursor to the end of the line.
- `d2e` – Delete two words

The movement commands that apply for yanking are also valid for deleting. For example `dw`, deletes to the start of the next word, and `d^` deletes everything from the cursor to the start of the line.

### Putting (Pasting)

To put the yanked or deleted text, move the cursor to the desired location and press `p` to put (paste) the text **after** the cursor or `P` to put (paste) **before** the cursor.

> Vim’s visual mode allows you to select and manipulate text.

## Removing a character `x` and `X`

`x` (does the same as `dl`) and `X` delete the character **under the cursor** and **to the left of the cursor**, respectively.

----------------------------------------------------
----------------------------------------------------

## The Replace Command `r`

The replace command is suitable for very small changes that you want to make in the text(buffer).

`r` replace one character of text with the next character entered.

----------------------------------------------------
----------------------------------------------------

## Change Case

|Command|Function                 |
|-------|-------------------------|
| `Vu`  |Lowercase the entire line|
| `VU`  |Uppercase the entire line|
| `V~`  |Invert selected case     |

----------------------------------------------------
----------------------------------------------------

## The Dot Command `.` (Repetition)

The dot command repeats **the last change**. Any time you update (add, modify, or delete) the content of the current buffer, you are making a **change**. 

To repeat the previous command, just press `.`.

For example, remove two words with `d2w`. After that, remove the rest of the words in this line with `.`. 

> A change excludes motions because it does not update buffer content. 
> The commands starting with `:` do not count as a change.

----------------------------------------------------

## Undo, Redo, and UNDO

Vim's undo system is not only capable of undoing and redoing simple mistakes, but also accessing different text states, giving you control to all the texts you have ever typed.

|Key     |Function               |
|--------|-----------------------|
|`u`     |Undo a single change   |
|`Ctrl+R`|Redo                   |
|`U`     |Undo all latest changes|

You can also run `:undo`, `:redo`.

### `u` vs `U`

- `U` removes **all the changes on the latest changed line**, while `u` only removes **one change at a time**. 

- While doing `u` does **not** count as **a change**, doing `U` counts as **a change**. Since UNDO actually creates a new change in Vim, **you can UNDO your UNDO**.

### Breaking The Blocks

If you do `ione two three<Esc>` then press `u`, Vim removes the entire `"one two three"` text because the whole thing counts as a change. 

Luckily, you can break the undo blocks. When you are typing in insert mode, pressing `Ctrl-G u` creates an undo breakpoint. For example, if you do `ione <Ctrl-G u>two <Ctrl-G u>three<Esc>`, then press `u`, you will only lose the text "three" (press `u` one more time to remove "two"). 

When you write a long text, use `Ctrl-G` u strategically. 

#### Extras

- **Undo Tree** : Vim stores every change ever written in an undo tree.
-**Persistent Undo** : Vim can preserve your undo history with an undo file with `:wundo`.
- **Time Travel** : Vim can travel to a text state in the past with `:earlier` command-line command.

----------------------------------------------------
----------------------------------------------------