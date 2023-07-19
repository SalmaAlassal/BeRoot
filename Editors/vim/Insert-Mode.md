# Insert Mode

Vim's insert mode contains many useful features.

## Ways To Go To Insert Mode

There are many ways to get into insert mode from the normal mode. Here are some of them:

| Key  | Function                                                                                            |
| ---- | --------------------------------------------------------------------------------------------------- |
| `i ` | Insert text **before** the cursor.                                                                  |
| `I ` | Insert text before the first non-blank character of the line.                                       |
| `a ` | Append text **after** the cursor.                                                                   |
| `A ` | Append text **at the end of line**.                                                                 |
| `o ` | Starts a new line **below** the cursor and enter insert mode.                                       |
| `O ` | Starts a new line **above** the cursor and enter insert mode.                                       |
| `s ` | Delete the character under the cursor and enter insert mode.                                        |
| `S ` | Delete the current line and enter insert mode.                                                      |
| `cw` | Delete from the **current** cursor's position to the end of the current word and enter insert mode. |
| `cc` | Change line by deleting it and then entering insert mode.                                           |
| `gi` | Insert text in same position where the last insert mode was stopped.                                |
| `I`  | Insert text at the start of line (column 1).                                                        |

## Different Ways To Exit Insert Mode

There are a few different ways to return to the normal mode while in the insert mode:

| Key      | Function                                                        |
| -------- | --------------------------------------------------------------- |
| `<Esc> ` | Exits insert mode and go to normal mode.                        |
| `Ctrl-[` | Exits insert mode and go to normal mode.                        |
| `Ctrl-C` | Like `Ctrl-[` and `<Esc>`, but does not check for abbreviation. |

## Repeating Insert Mode

You can insert text multiple times by passing a count parameter before entering insert mode.

**For example:** `10i`

If you type `"hello world!"` and **exit** insert mode, Vim will repeat the text 10 times. This will work with any insert mode method (ex: `10I`, `11a`, `12o`).

**Another example,** an underline of a header might consist of 30 `-`. With `30i- Esc`, there's no need to press `-` 30 times.

## Deleting Chunks In Insert Mode

When you make a typing mistake, it can be cumbersome to type <Backspace> repeatedly. It may make more sense to go to normal mode and delete your mistake. You can also delete several characters at a time while in insert mode.

| Key      | Function                                       |
| -------- | ---------------------------------------------- |
| `Ctrl-H` | Delete one character **before** the cursor.    |
| `Ctrl-W` | Delete one word **before** the cursor.         |
| `Ctrl-U` | Delete the entire line **before** the cursor.. |

**Important Note**

You can't undo these deletions. However, what you've typed is still in the `.` register.

## Executing Normal Mode Command (Insert Normal Mode)

You can use `CTRL-O` to execute a **one** normal-mode command without leaving insert mode.

When you press `Ctrl-o`, you'll be in **insert-normal** sub-mode. If you look at mode indicator on bottom left, normally you will see `-- INSERT --`, but `Ctrl-o `will change it to `-- (insert) --`.

### Example 1 : Navigating while remaining in insert mode

Let's say while typing, you wanted to add a word in the beginning of current line. Do `Ctrl-o 0` to jump to the beginning of the line, add the word, then jump back with to the end with `Ctrl-o $`.

### Example 2: Centering screen

If you're at the bottom of the screen. You can center your current position by doing `Ctrl-o zz`.

### Example 3: Deleting faster

If you wanted to delete a block of text from your current position to an anchor, say a comma, you can just do `Ctrl-o d t ,`

---
