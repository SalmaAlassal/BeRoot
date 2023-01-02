# Visual Mode

Highlighting and applying changes to a body of text is a common feature in many text editors and word processors. Vim can do this using visual mode. We will learn how to use the visual mode to manipulate texts efficiently.

## Three Types of Visual Modes

Vim has three different visual modes. They are:

### 1. Character-Wise Visual Mode

Press `v` on the first character. Then go down to the next line with `j`. It highlights all texts from "one" up to your cursor location. If you press `gU`, Vim uppercases the highlighted characters.

### 2. Line-Wise Visual Mode

Press `V` and watch Vim selects the entire line your cursor is on. Just like character-wise visual mode, if you run `gU`, Vim uppercases the highlighted characters.

### 3. Block-Wise Visual Mode

It gives you more freedom of movement than the other two modes. If you press `Ctrl-V`, Vim highlights the character under the cursor just like character-wise visual mode, except instead of highlighting each character until the end of the line before going down to the next line, it goes to the next line with minimal highlighting. Try moving around with `h`/`j`/`k`/`l` and watch the cursor moves.

> On the bottom left of your Vim window, you will see either `-- VISUAL --`, `-- VISUAL LINE --`, or `-- VISUAL BLOCK --` displayed to indicate which visual mode you are in.

### Selecting The Last Visual Mode Area

`gv` can quickly highlight the last visual mode highlight. Suppose you just applied uppercase operation on a text block and forgot to apply another operation to the same text block. Instead of going back, reselecting, and applying operation, you can skip the first two steps if you used gv. It will make the same selection area as the last one, so you can just apply the operation you need.

You can also go to the location of the start and the end of the last visual mode with these two special marks:

- `` '< `` : Go to the **first place** of the previous visual mode highlight
- `` '> `` : Go to the **last place** of the previous visual mode highlight

You can selectively execute command-line commands on a highlighted text, like `:s/const/let/g`. When you did that, you'd see this below: `` :'<,'>s/const/let/g `` You were actually executing a ranged `s/const/let/g` command (with the two marks as the addresses).

You can always edit these marks anytime you wish. If instead you needed to substitute from the start of the highlighted text to the end of the file, you just change the command to: `` :'<,$s/const/let/g``

-----------------------------------------------------

### Summary

|Key       | Mode                         | Description                      |
|----------|------------------------------|----------------------------------|
| `v      `| Character-wise visual mode   |Works with individual characters  |
| `V      `| Line-wise visual mode        |works with lines                  |
| `Ctrl-V `| Block-wise visual mode       |works with rows and columns       |
| `gv`     |Go to the previous visual mode|It will start the same visual mode on the same highlighted text block as you did last time.|
|`` '< ``  | |Go to the **first place** of the previous visual mode highlight.|
| `` '> `` | |Go to the **last place** of the previous visual mode highlight. |


While you are inside a visual mode, you can switch to another visual mode by pressing either `v`, `V`, or `Ctrl-V`.

-----------------------------------------------------

## Different Ways to Exit Visual Mode

- `<Esc>`
- `Ctrl-c`
- **The same key** as your current visual mode.
    - What the latter means is if you are currently in the line-wise visual mode (`V`), you can exit it by pressing `V` again. If you are in the character-wise visual mode, you can exit it by pressing `v`.

-----------------------------------------------------

## Entering Visual Mode from Insert Mode

To go to character-wise visual mode while you are in insert mode: `Ctrl-O v`

> Notice that on the bottom left of the screen, it says `--(insert) VISUAL--`. 

Running `Ctrl-O` while in the insert mode lets you execute a **normal mode command**. While in this normal-mode-command-pending mode, run `v` to enter character-wise visual mode. 

This trick works with any visual mode operator: `v`, `V`, and `Ctrl-V`.

-----------------------------------------------------

## Visual Mode Navigation

Once you're in a visual mode, you can expand the selection with vim motions, like `hjkl`.

With `o` or `O` in visual mode, the cursor jumps from the beginning to the end of the highlighted block, allowing you to expand the highlight area. So if your cursor is on bottom of the selection and you want to expand upward, change cursor location with `o` and go up with `k`.

-----------------------------------------------------

## Visual Mode Operators

Vim is a modal editor. It means that the same key may work differently depending on the mode. Luckily, many keys in visual mode overlap functionalities with normal mode keys. 

To use visual mode operators, first visually select an area of text (`v`/`V`/`Ctrl-v` + motion), then press a visual-mode operator key. That's it.

**For example**, if you have the following text, and you want to delete the first two lines from visual mode:

```
one
two
three
```

Highlight the lines "one" and "two" with `V` then Press `d` to delete the selection, similar to normal mode. 

### More Examples

- Running `x` deletes all highlighted texts.
- Running `yy` copies all highlighted texts, you can paste it with `p`.
- Running `r-` replaces all highlighted texts with `-`.

### Some most Common Operators

|Key  |Function   |
|-----|-----------|
| `u` | lowercase |
| `U` | uppercase |
| `d` | delete    |
| `c` | change    |
| `y` | yank      |
| `>` | indent    |
| `<` | dedent    |

For more operators, check out `:h visual-operators`.

-----------------------------------------------------

## Visual Mode and Command-line Commands

You can selectively apply command-line commands on a highlighted text block. If you have these statements, and you want to substitute "const" with "let" only on the first two lines:

```
const one = "one";
const two = "two";
const three = "three";
```
Highlight the first two lines with any visual mode and run the substitute command :`s/const/let/g`

```
let one = "one";
let two = "two";
const three = "three";
```

**Notice** we said you can do this with any visual mode. You do not have to highlight the entire line to run the command on that line. As long as you select at least a character on each line, the command is applied.

-----------------------------------------------------

## Repeating Visual Mode

Vim's dot command (`.`) repeats the last change. When you repeat a visual mode operation, the same operation will be applied to the same text block.

Suppose you deleted these two lines with line-wise visual mode (`Vjd`).
```
const one = "one";
const two = "two";
```
The next time you use dot command, it will also delete the next two lines.

-----------------------------------------

## Adding Text on Multiple Lines

You can add text on multiple lines in Vim using the block-wise visual mode. If you need to add a semicolon at the end of each line:

```
const one = "one"
const two = "two"
const three = "three"
```

With your cursor on the first line:

- Run block-wise visual mode and go down two lines (`Ctrl-V jj`).
- Highlight to the end of the line (`$`).
- Append (`A`) then type `;`.
- Exit visual mode (<Esc>).

You should see the appended "`;`" on each line now.

-----------------------------------------

## Incrementing Numbers

You can increment columns of numbers with `Ctrl-a`/`Ctrl-x` in vim. Here's how you can apply it to multiple lines.

Suppose you have a text:

```html
<div id="app-1"></div>
<div id="app-1"></div>
<div id="app-1"></div>
<div id="app-1"></div>
<div id="app-1"></div>
```

It's not a good practice to have multiple ids with same name. Let's increment them. 

  1. Put your cursor on the second line.
  2. Start block-wise visual mode, go down 3 more lines (`Ctrl-v 3j`). You should be selecting all the remaining "1"'s.
  3. Type `g Ctrl-a`.

That's it! Now everything is incremented:

```html
<div id="app-1"></div>
<div id="app-2"></div>
<div id="app-3"></div>
<div id="app-4"></div>
<div id="app-5"></div>
```

> Extra: `Ctrl-x`/`Ctrl-a` can increments letters too, with: `:set nrformats+=alpha`

--------------------------------