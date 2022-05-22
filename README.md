chopin
![chopin](https://raw.githubusercontent.com/zetatez/chopin/main/.pics/chopin.gif)

# chopin
A cli tool that greatly improves your working efficiency.

## Dependencies
- [fd](https://github.com/sharkdp/fd)
- [fzf](https://github.com/junegunn/fzf)
- vim
- ...

## Installation
```bash
git clone https://github.com/zetatez/chopin.git
cd chopin

## configure chopin if needed:
# vim config.def.h

## To install
sudo make clean install

## To uninstall
# sudo make uninstall
```

## Configuration
See [*config.def.h*](https://github.com/zetatez/chopin/blob/main/config.def.h)

HINTS:
- To get mime-type of a file:
    ```bash
    file --dereference --brief --mime-type filename
    ```

## Usage
```bash
chopin --help
    # Usage: chopin [-vhoecmr] [file]
    #     -o, --open file     open a file with your default setting automatically
    #     -e, --exec file     exec a file with your default setting automatically
    #     -c, --cp   file     cp a file
    #     -m, --mv   file     mv a file
    #     -r, --rm   file     rm a file
    #     -h, --help          help
    #     -v, --version       version
```

## Best Practice
- Search and Handle workflow in dwm.
    ```
    key binding(shell/vim/...) -> [fd  ->  fzf ->  chopin] -> dwm
    ```

- To use chopin in zsh: `~/.zshrc`.
```zsh
# chopin
# chopin open
alias chopin-open="chopin -o \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='open>' --preview 'bat --color=always {}' --select-1 --exit-0)\""
bindkey -s '^F' 'chopin-open\n'

# chopin exec
alias chopin-exec="chopin -e \"\$(fd -e sh -e jl -e py -e tex -e c -e cpp -e go -e scala -e java -e rs -e sql --exclude .git . './'|fzf --prompt='exec>'  --preview 'bat --color=always {}' --select-1 --exit-0)\""
bindkey -s '^X' 'chopin-exec\n'

# chopin cp
alias chopin-cp="chopin -c \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='cp>'  --preview 'bat --color=always {}' --select-1 --exit-0)\""
bindkey -s "^N" 'chopin-cp\n'

# chopin mv
alias chopin-mv="chopin -m \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='mv>' --preview 'bat --color=always {}' --select-1 --exit-0)\""
bindkey -s "^V" 'chopin-mv\n'

# chopin rm
alias chopin-rm="chopin -r \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='rm>' --preview 'bat --color=always {}' --select-1 --exit-0)\""
bindkey -s "^Z" 'chopin-rm\n'

# chopin open wiki
alias chopin-open-wiki="chopin -o \"\$(fd --type f --hidden --exclude .git . '$HOME/obsidian/wiki'|fzf --prompt='wikis>' --preview 'bat --color=always {}' --select-1 --exit-0)\""
bindkey -s '^W' 'chopin-open-wiki\n'

# chopin open books
alias chopin-open-book="chopin -o \"\$(fd -e pdf -e epub -e djvu -e mobi --exclude .git . '$HOME/obsidian/docs'|fzf --prompt='books>' --reverse --select-1 --exit-0)\";exit"
bindkey -s '^P' 'chopin-open-book\n'

# chopin open media
alias chopin-open-media="chopin -o \"\$(fd -e jpg -e jpeg -e png -e gif -e bmp -e tiff -e mp3 -e flac -e mkv -e avi -e mp4 --exclude .git . '$HOME'|fzf --prompt='medias>' --reverse --select-1 --exit-0)\";exit"
bindkey -s '^A' 'chopin-open-media\n'
```

- To use chopin in bash: `~/.bashrc`.
```bash
# chopin
# chopin open
alias chopin-open="chopin -o \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='open>' --preview 'bat --color=always {}' --select-1 --exit-0)\""
bind -x '"\C-f":"chopin-open"'

# chopin exec
alias chopin-exec="chopin -e \"\$(fd -e sh -e jl -e py -e tex -e c -e cpp -e go -e scala -e java -e rs -e sql --exclude .git . './'|fzf --prompt='exec>'  --preview 'bat --color=always {}' --select-1 --exit-0)\""
bind -x '"\C-x":"chopin-exec"'

# chopin cp
alias chopin-cp="chopin -c \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='cp>'  --preview 'bat --color=always {}' --select-1 --exit-0)\""
bind -x '"\C-n":"chopin-cp"'

# chopin mv
alias chopin-mv="chopin -m \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='mv>' --preview 'bat --color=always {}' --select-1 --exit-0)\""
bind -x '"\C-v":"chopin-mv"'

# chopin rm
alias chopin-rm="chopin -r \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='rm>' --preview 'bat --color=always {}' --select-1 --exit-0)\""
bind -x '"\C-z":"chopin-rm"'

# chopin open wiki
alias chopin-open-wiki="chopin -o \"\$(fd --type f --hidden --exclude .git . '$HOME/obsidian/wiki'|fzf --prompt='wikis>' --preview 'bat --color=always {}' --select-1 --exit-0)\""
bind -x '"\C-w":"chopin-open-wiki"'

# chopin open books
alias chopin-open-book="chopin -o \"\$(fd -e pdf -e epub -e djvu -e mobi --exclude ~/go . '$HOME/obsidian/docs'|fzf --prompt='books>' --reverse --select-1 --exit-0)\";exit"
bind -x '"\C-p":"chopin-open-book"'

# chopin open media
alias chopin-open-media="chopin -o \"\$(fd -e jpg -e jpeg -e png -e gif -e bmp -e tiff -e mp3 -e flac -e mkv -e avi -e mp4 --exclude .git . '$HOME'|fzf --prompt='medias>' --reverse --select-1 --exit-0)\";exit"
bind -x '"\C-a":"chopin-open-media"'
```

- To use chopin in vim: `~/.vimrc`.
```vimscript
""""""
"""""" chopin
nnoremap <LEADER>f :!chopin -o "$(fd --type f --hidden --exclude .git . './'\|fzf --prompt='open>' --preview 'bat --color=always {}' --select-1 --exit-0)"<CR><CR>
nnoremap <LEADER>x :!chopin -e "$(fd -e sh -e jl -e py -e tex -e c -e cpp -e go -e scala -e java -e rs -e sql . './'\|fzf --prompt='exec>' --preview 'bat --color=always {}' --select-1 --exit-0)"<CR><CR>
```

## LICENSE

MIT.

