chopin

# chopin

## Dependencies
- fd
- fzf
- vim
- libreoffice
- zathura
- evince
- foliate
- okular
- sxiv
- mpv
- 7z
- unrar
- atool

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
- Add following lines to your `~/.zshrc` and try.
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

## Configuration
```c
// see config.def.h

/* open rules */
static const struct KFV open_map[] = {
    /* .ext  , &    , application        */
    {".cbr"  , 1    , "zathura"          } ,
    {".cbz"  , 1    , "zathura"          } ,
    {".djvu" , 1    , "evince"           } ,
    {".epub" , 1    , "foliate"          } ,
    {".mobi" , 1    , "okularr"          } ,
    {".pdf"  , 1    , "zathura"          } ,
    {".doc"  , 1    , "libreoffice"      } ,
    {".docm" , 1    , "libreoffice"      } ,
    {".docx" , 1    , "libreoffice"      } ,
    {".dot"  , 1    , "libreoffice"      } ,
    {".dotx" , 1    , "libreoffice"      } ,
    {".fodt" , 1    , "libreoffice"      } ,
    {".odt"  , 1    , "libreoffice"      } ,
    {".ott"  , 1    , "libreoffice"      } ,
    {".rtf"  , 1    , "libreoffice"      } ,
    {".uot"  , 1    , "libreoffice"      } ,
    {".pptx" , 1    , "libreoffice"      } ,
    {".dbf"  , 1    , "libreoffice"      } ,
    {".dif"  , 1    , "libreoffice"      } ,
    {".fods" , 1    , "libreoffice"      } ,
    {".ods"  , 1    , "libreoffice"      } ,
    {".ots"  , 1    , "libreoffice"      } ,
    {".slk"  , 1    , "libreoffice"      } ,
    {".uos"  , 1    , "libreoffice"      } ,
    {".xls"  , 1    , "libreoffice"      } ,
    {".xlsm" , 1    , "libreoffice"      } ,
    {".xlsx" , 1    , "libreoffice"      } ,
    {".xlt"  , 1    , "libreoffice"      } ,
    {".Z"    , 0    , "atool --list --"  } ,
    {".a"    , 0    , "atool --list --"  } ,
    {".ace"  , 0    , "atool --list --"  } ,
    {".alz"  , 0    , "atool --list --"  } ,
    {".arc"  , 0    , "atool --list --"  } ,
    {".arj"  , 0    , "atool --list --"  } ,
    {".bz"   , 0    , "atool --list --"  } ,
    {".bz2"  , 0    , "atool --list --"  } ,
    {".cab"  , 0    , "atool --list --"  } ,
    {".cpio" , 0    , "atool --list --"  } ,
    {".deb"  , 0    , "atool --list --"  } ,
    {".gz"   , 0    , "atool --list --"  } ,
    {".jar"  , 0    , "atool --list --"  } ,
    {".lha"  , 0    , "atool --list --"  } ,
    {".lz"   , 0    , "atool --list --"  } ,
    {".lzh"  , 0    , "atool --list --"  } ,
    {".lzma" , 0    , "atool --list --"  } ,
    {".lzo"  , 0    , "atool --list --"  } ,
    {".rpm"  , 0    , "atool --list --"  } ,
    {".rz"   , 0    , "atool --list --"  } ,
    {".t7z"  , 0    , "atool --list --"  } ,
    {".tZ"   , 0    , "atool --list --"  } ,
    {".tar"  , 0    , "atool --list --"  } ,
    {".tbz"  , 0    , "atool --list --"  } ,
    {".tbz2" , 0    , "atool --list --"  } ,
    {".tgz"  , 0    , "atool --list --"  } ,
    {".tlz"  , 0    , "atool --list --"  } ,
    {".txz"  , 0    , "atool --list --"  } ,
    {".tzo"  , 0    , "atool --list --"  } ,
    {".war"  , 0    , "atool --list --"  } ,
    {".xpi"  , 0    , "atool --list --"  } ,
    {".xz"   , 0    , "atool --list --"  } ,
    {".zip"  , 0    , "atool --list --"  } ,
    {".rar"  , 0    , "unrar -lt -p- --" } ,
    {".7z"   , 0    , "7z l -p- --"      } ,
    {".json" , 0    , "vim"              } ,
    {NULL    , 0    , NULL               }
};

/* open rules for rest */
static const struct KFV open_else_map[] = {
    /*mine     , &    , application                */
    {"image/*" , 1    , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5 , ..
    {"video/*" , 1    , "mpv --geometry=100%x100%" } , // mpv  , vlc   , ...
    {"audio/*" , 0    , "mpv"                      } , // mpv  , vlc   , ...
    {"text/*"  , 0    , "vim"                      } , // vim  , emacs ,
    {"inode/*" , 0    , "vim"                      } , // vim  , emacs , // inode/x-empty
    {NULL      , 0    , NULL                       }
};

/* exec rules */
static const struct KV exec_map[] = {
    /*.ext   , shell scripts                                                                                                                          */
    {".sh"   , "filename=%s; sh ${filename}"                                                                                                          },
    {".py"   , "filename=%s; python ${filename}"                                                                                                      },
    {".jl"   , "filename=%s; julia ${filename}"                                                                                                       },
    {".tex"  , "filename=%s; xelatex -interaction nonstopmode ${filename}; bibtex *.aux; xelatex -interaction nonstopmode ${filename}; zathura *.pdf" },
    {".c"    , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".cpp"  , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".go"   , "filename=%s; go run ${filename}"                                                                                                      },
    {".scala", "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".java" , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".rs"   , "filename=%s; cargo build && cargo run"                                                                                                },
    {".rb"   , "filename=%s; ruby ${filename}"                                                                                                        },
    {".lua"  , "filename=%s; lua ${filename}"                                                                                                         },
    {".js"   , "filename=%s; node ${filename}"                                                                                                        },
    {".ts"   , "filename=%s; tsc ${filename}"                                                                                                         },
    {".sql"  , "filename=%s; mysql -uroot -p < ${filename}"                                                                                           },
    {NULL    , NULL                                                                                                                                   }
};

/* exec rules for rest */
static const struct KV exec_else_map[] = {
    /**   , shell scripts                  */
    {"*"  , "filename=%s; sh ${filename }" }, // any excuteble file
    {NULL , NULL                           }
};

/* default options for cp, mv, rm */
static const char *cp_opt           = "-fr"; // recommended "-ir"
static const char *mv_opt           = "-f" ; // recommended "-i"
static const char *rm_opt           = "-fr"; // recommended "-ir"



```

## LICENSE

MIT.

