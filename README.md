chopin

# chopin

## Dependencies
- [fd](https://github.com/sharkdp/fd)
- [fzf](https://github.com/junegunn/fzf)
- vim
- ...

## Installation

```bash
git clone https://github.com/zetatez/chopin.git

cd chopin
sudo make clean install

# sudo make uninstall
```

## Usage
```bash
Usage: chopin [-vhoecmr] [file]
  -o, --open file     open a file with your default setting automatically
  -e, --exec file     exec a file with your default setting automatically
  -c, --cp   file     cp a file
  -m, --mv   file     mv a file
  -r, --rm   file     rm a file
  -h, --help          help
  -v, --version       version
```

## Workflow: Search and Handle
What can `chopin` do when combined with `fd` and `fzf` ?

- fd  ->  fzf ->  chopin

[fd]: find a file list -> [fzf]: interactive filter -> [chopin]: open, exec, cp, mv, rm.

## Best Practice
- To use chopin in cli: Add following lines to your `~/.zshrc` and try.
```zsh
# chopin open
alias chopin-open="chopin -o \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='open>' --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s '^F' 'chopin-open\n'

# chopin exec
alias chopin-exec="chopin -e \"\$(fd -e sh -e jl -e py -e tex -e c -e cpp -e go -e scala -e java -e rs -e sql . './'|fzf --prompt='exec>'  --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s '^X' 'chopin-exec\n'

# chopin cp
alias chopin-cp="chopin -c \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='cp>'  --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s "^N" 'chopin-cp\n'

# chopin mv
alias chopin-mv="chopin -m \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='mv>' --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s "^V" 'chopin-mv\n'

# chopin rm
alias chopin-rm="chopin -r \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='rm>' --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s "^Z" 'chopin-rm\n'

# chopin open books
alias chopin-open-book="chopin -o \"\$(fd -e pdf -e epub -e djvu -e mobi --exclude ~/go . '$HOME/obsidian/docs'|fzf --prompt='books>' --reverse --select-1 --exit-0|sed 's/ /\\ /g')\";exit"
bindkey -s '^P' 'chopin-open-book\n'

# chopin open wiki
alias chopin-open-wiki="chopin -o \"\$(fd --type f --hidden --exclude .git . '$HOME/obsidian/wiki'|fzf --prompt='wikis>' --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s '^W' 'chopin-open-wiki\n'

# chopin open media
alias chopin-open-media="chopin -o \"\$(fd -e jpg -e jpeg -e png -e gif -e bmp -e tiff -e mp3 -e flac -e mkv -e avi -e mp4 . '$HOME'|fzf --prompt='medias>' --reverse --select-1 --exit-0|sed 's/ /\\ /g')\";exit"
bindkey -s '^A' 'chopin-open-media\n'
```

- To use chopin in vim
```vimscript
""""""
"""""" chopin
nnoremap <LEADER>f :!chopin -o "$(fd --type f --hidden --exclude .git . './'\|fzf --prompt='open>' --preview 'bat --color=always {}' --select-1 --exit-0\|sed 's/ /\\ /g')"<CR><CR>
nnoremap <LEADER>x :!chopin -e "$(fd -e sh -e jl -e py -e tex -e c -e cpp -e go -e scala -e java -e rs -e sql . './'\|fzf --prompt='exec>' --preview 'bat --color=always {}' --select-1 --exit-0\|sed 's/ /\\ /g')"<CR><CR>
```

## Configuration
See [*config.def.h*](https://github.com/zetatez/chopin/blob/main/config.def.h)

## LICENSE

MIT.

