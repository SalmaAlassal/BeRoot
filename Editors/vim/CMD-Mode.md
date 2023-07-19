# Command Line Mode

- Command-Line mode `prompts` us to enter:

- In `Command-Line` mode we can type the name of a command and then execute it by pressing `<CR>`.

- We can switch from `Command-Line` mode back to `Normal` mode by pressing `<Esc>`.

- We can use `Ex` commands to:

  1.  read and write files `:edit and :write`.

  2.  create tabs `:tabnew` or split windows `:split`.

  3.  show the list of buffers `:ls`.

  4.  alot more...\*\*

  In fact, Vim has an Ex command for just about everything.

- `Command-Line` mode is similar to `Insert` mode in that most of the buttons on the keyboard simply enter a character. In `Insert` mode, the text goes into a `buffer`, whereas in `Command-Line` mode the text `appears at the prompt`.

> #### TIP TIME
>
> - We can insert the contents of `any register` at the `command line` using the `<C-r>{register}` command.
> - In `Command-Line` mode, we can use the `<Tab>` key to `auto-complete` the `name of a file` or the `name of a command`.

## Command-Line History

- Vim keeps a `history` of the `commands` we have entered in `Command-Line` mode, so we do not need to write all of them again.

- By default it keeps the `last 20 commands` we have entered, but you can `change` this number by changing the `hisotry` option, say we want vim to remember the last `200` commands that we have entered in the `Command-Line` mode. You can do this by writing `set history=200`, in your `.vimrc` file.

- We can use the `<Up>` key to go to the next `command` in the `commands' history`, and `<Down>` key to go to the `previous command` in the `commands' history`.

- In this way of navigation through our command's history, we do not have the all power ov vim features, like `searching` for a `command` in the `history` or `filtering` the `history` to show only the `commands` that `match` a `pattern`. Likely vim know this and introduce us to the `Command-Line window`.

- The `Command-Line window` is like a regular vim `buffer` where each line contains a command from our history and we can naviagte through them usine our favorite `hjkl` keys, and we can use `search` and `filter` to find the `command` we want. We can also `execute` the command in the current line by pressing `<CR>`.

- We can open the `Command-Line window` by pressing `q:` in `Normal-Line` mode.

## Why Ex commands?

- One of the mose important features of `Ex` commands, is their ability to be executed across many lines at the same time.

- Many `Ex commands` can be given a `[range]` of lines to act upon. We can specify the start and end of a range with either:

  1. a `line number`.

  2. a `mark`.

  3. a `pattern`.

### Usine Line Numbers

- if we enter a `line number` without any commands in `Command-Line` mode, vim will jump to that `line`.

- Examples:

  1. `:1` $\to$ go to the `first line` in the `buffer`.

  2. `:5` $\to$ go to the `fifth line` in the `buffer`.

  3. `:$` $\to$ go to the `last line` in the `buffer`.

- If we enter a command with a `line number` as a `[range]`, the command will be executed on that `line` only.

- Examples:

  1. `:5d` $\to$ `delete` the `fifth line` in the `buffer`.

  2. `:3,8d` $\to$ `delete` from line number `3` to line number `8` in the `buffer`.

  3. `:1,$d` or `:%d` $\to$ `delete` from the `first line` to the `last line` in the `buffer`.

  4. `:d` $\to$ `delete` the `current line` in the `buffer`.

- Ass you gussed from examples `2` and `3`, that we can use the `:{start},{end}` to specify a range of lines from `start` to `end`

- As we have seen that `d` $\to$ `delete`, there are alot of other commands we can perform on text from the `Command-Line`mode.

- Examples:

  1. `y` $\to$ `yank` or `copy` the `text` in the `buffer` to the `register`.

  2. `p` $\to$ `paste` the `text` in the `register` to the `buffer`.

  3. `c` $\to$ `change` the `text` in the `buffer`.

  4. `s` $\to$ `substitute` the `text` in the `buffer`.

  5. `gU` $\to$ `uppercase` the `text` in the `buffer`.

  6. `gu` $\to$ `lowercase` the `text` in the `buffer`.

  7. `>` $\to$ `indent` the `text` in the `buffer`.

  8. `<` $\to$ `unindent` the `text` in the `buffer`.

  9. `m` $\to$ `move` the `text` in the `buffer`.

### Specify a Range of Lines by Visual Selection

- We can also specify rnage of lines using `visual selections`.

- Try do the following:

  1. Go to `visual mode ` by pressing `:v` from `normal mode`

  2. Select some lines using `hjkl` keys.

  3. Press `:` to go to `Command-Line` mode.

  4. You will see that vim has already entered the `:'<,'>` for you. You can think of this as the range of lines that you have selected in `visual mode`.

  5. Now you can enter the `command` you want to execute on the `selected lines` or the `range`.

## Specify a Range of Lines by Patterns

- Suppose we have the following text in our `buffer`:

  ```rs
  fn main() {
    let cat = 1;

    if cat == 1 {
      println!("x = {}", x);
    }

    let dog = 2;

    let z = 1 + 2;

    println!("z = {}", z);
  }
  ```

- try to type `:/cat/,/dog/d` in `Command-Line` mode.

- this create a `range` of lines from the line that contains the word `cat` to the line that contains the word `dot`, and then delete them.
