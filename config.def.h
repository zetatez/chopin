/* See LICENSE file for copyright and license details. */
// config.def.h

/* Author: lorenzo */
/* E-mail: lorenzo<zetatez@icloud.com> */

#include <stdbool.h>
#include <stdlib.h>

struct KFV {
    const char *key;
    bool flag;
    const char *value;
};

struct KV {
    const char *key;
    const char *value;
};

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


