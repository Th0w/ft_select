# ft_select

42 Unix branch project.

Create a program which receives as input a list of files names. The user can then _select_ a number a file from this list.
When the choice is done, the resulting list is written to the standard output, which can be used as a new input for an other command.

It features:
* filename colouring by type (red for executables, blue for directories, gray for files not found in given path, ...)
* dynamic search
* key-binding:
  * `/` or `h` to toggle colouring
  * `a` to select all files
  * `s` to deselect all files
  * `f` to select regular files
  * `d` to select directories
  * `l` to select symlinks
  * `x` to select executables
  * `<Esc>` to exit ft_select
  * `:` to enter dynamic search mode (`?` for case-insensitivness):
    * `<Esc>` to exit search
    * `<Enter>` or `<CR>` to exit search and select its result
* Custom signal handling

Just clone repo and `make` it.

`usage: ./ft_select [file ...]`
