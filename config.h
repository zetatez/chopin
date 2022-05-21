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
    {".djvu" , 1    , "evince"           } ,
    {".epub" , 1    , "foliate"          } ,
    {".mobi" , 1    , "okular"           } ,
    {".pdf"  , 1    , "zathura"          } ,
    {".doc"  , 1    , "libreoffice"      } ,
    {".docx" , 1    , "libreoffice"      } ,
    {".pptx" , 1    , "libreoffice"      } ,
    {".xls"  , 1    , "libreoffice"      } ,
    {".xlsx" , 1    , "libreoffice"      } ,
    {".iso"  , 0    , "atool --list --"  } ,
    {".cpio" , 0    , "atool --list --"  } ,
    {".pkg"  , 0    , "atool --list --"  } ,
    {".gz"   , 0    , "atool --list --"  } ,
    {".jar"  , 0    , "atool --list --"  } ,
    {".tar"  , 0    , "atool --list --"  } ,
    {".tgz"  , 0    , "atool --list --"  } ,
    {".zip"  , 0    , "atool --list --"  } ,
    {".rar"  , 0    , "unrar -lt -p- --" } ,
    {".7z"   , 0    , "7z l -p- --"      } ,
    {".json" , 0    , "vim"              } ,
    {NULL    , 0    , NULL               }
};

/* open rules for rest */ // to get mime-type of a file: file --dereference --brief --mime-type filename
static const struct KFV open_else_map[] = {
    /*mime-type                                                                  , & , application                */
    {"application/epub+zip"                                                      , 1 , "foliate"                  } ,
    {"application/json"                                                          , 0 , "vim"                      } ,
    {"application/msword"                                                        , 1 , "libreoffice"              } ,
    {"application/ogg"                                                           , 0 , "mpv"                      } ,
    {"application/pdf"                                                           , 0 , "zathura"                  } ,
    {"application/vnd.ms-excel"                                                  , 1 , "libreoffice"              } ,
    {"application/vnd.ms-outlook"                                                , 1 , "libreoffice"              } ,
    {"application/vnd.ms-powerpoint"                                             , 1 , "libreoffice"              } ,
    {"application/vnd.ms-project"                                                , 1 , "libreoffice"              } ,
    {"application/vnd.openxmlformats-officedocument.presentationml.presentation" , 1 , "libreoffice"              } ,
    {"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"         , 1 , "libreoffice"              } ,
    {"application/vnd.openxmlformats-officedocument.wordprocessingml.document"   , 1 , "libreoffice"              } ,
    {"application/vnd.visio"                                                     , 1 , "libreoffice"              } ,
    {"application/x-httpd-php"                                                   , 0 , "vim"                      } ,
    {"application/x-javascript"                                                  , 0 , "vim"                      } ,
    {"application/x-latex"                                                       , 0 , "vim"                      } ,
    {"application/x-sh"                                                          , 0 , "vim"                      } ,
    {"application/xhtml+xml"                                                     , 0 , "vim"                      } ,
    {"application/xml"                                                           , 0 , "vim"                      } ,
    {"application/bz"                                                            , 0 , "atool --list --"          } ,
    {"application/bz2"                                                           , 0 , "atool --list --"          } ,
    {"application/rar"                                                           , 0 , "atool --list --"          } ,
    {"application/x-7z-compressed"                                               , 0 , "atool --list --"          } ,
    {"application/x-cpio"                                                        , 0 , "atool --list --"          } ,
    {"application/x-gzip"                                                        , 0 , "atool --list --"          } ,
    {"application/x-hdf"                                                         , 0 , "atool --list --"          } ,
    {"application/x-rar"                                                         , 0 , "atool --list --"          } ,
    {"application/x-rar-compressed"                                              , 0 , "atool --list --"          } ,
    {"application/x-tar"                                                         , 0 , "atool --list --"          } ,
    {"application/zip"                                                           , 0 , "atool --list --"          } ,
    {"audio/3gpp"                                                                , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/3gpp2"                                                               , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/acc"                                                                 , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/midi"                                                                , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/mpeg"                                                                , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/ogg"                                                                 , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/wav"                                                                 , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/wave"                                                                , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/webm"                                                                , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/x-m4a"                                                               , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/x-midi"                                                              , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/x-mpegurl"                                                           , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/x-msvideo"                                                           , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/x-pn-wav"                                                            , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/x-realaudio"                                                         , 0 , "mpv"                      } , // mpv  , vlc
    {"audio/x-wav"                                                               , 0 , "mpv"                      } , // mpv  , vlc
    {"video/3gpp"                                                                , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/3gpp2"                                                               , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/mp4"                                                                 , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/ogg"                                                                 , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/quicktime"                                                           , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/webm"                                                                , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/x-flv"                                                               , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/x-m4v"                                                               , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/x-matroska"                                                          , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/x-ms-asf"                                                            , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/x-ms-wmv"                                                            , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"video/x-sgi-moive"                                                         , 1 , "mpv --geometry=100%x100%" } , // mpv  , vlc
    {"image/bmp"                                                                 , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/gif"                                                                 , 1 , "sxiv -a"                  } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/ief"                                                                 , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/jpg"                                                                 , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/jpeg"                                                                , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/pipeg"                                                               , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/png"                                                                 , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/svg+xml"                                                             , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/tiff"                                                                , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/webp"                                                                , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/x-cmu-raster"                                                        , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/x-cmx"                                                               , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/x-icon"                                                              , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/x-rgb"                                                               , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/x-xbitmap"                                                           , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/x-xpixmap"                                                           , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"image/x-xwindowdump"                                                       , 1 , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5
    {"inode/x-empty"                                                             , 0 , "vim"                      } , // vim  , emacs
    {"text/calendar"                                                             , 0 , "vim"                      } , // vim  , emacs
    {"text/css"                                                                  , 0 , "vim"                      } , // vim  , emacs
    {"text/csv"                                                                  , 0 , "vim"                      } , // vim  , emacs
    {"text/html"                                                                 , 0 , "vim"                      } , // vim  , emacs
    {"text/javascript"                                                           , 0 , "vim"                      } , // vim  , emacs
    {"text/plain"                                                                , 0 , "vim"                      } , // vim  , emacs
    {"text/troff"                                                                , 0 , "vim"                      } , // vim  , emacs
    {"text/x-c"                                                                  , 0 , "vim"                      } , // vim  , emacs
    {"text/x-c++"                                                                , 0 , "vim"                      } , // vim  , emacs
    {"text/x-java"                                                               , 0 , "vim"                      } , // vim  , emacs
    {"text/x-makefile"                                                           , 0 , "vim"                      } , // vim  , emacs
    {"text/x-ruby"                                                               , 0 , "vim"                      } , // vim  , emacs
    {"text/x-script.python"                                                      , 0 , "vim"                      } , // vim  , emacs
    {"text/x-tex"                                                                , 0 , "vim"                      } , // vim  , emacs
    {"text/xml"                                                                  , 0 , "vim"                      } , // vim  , emacs
    {NULL                                                                        , 0 , NULL                       }
};

/* exec rules */
static const struct KV exec_map[] = {
    /*.ext   , shell scripts                                                                                                                          */
    {".c"    , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".cpp"  , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".go"   , "filename=%s; go run ${filename}"                                                                                                      },
    {".java" , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".jl"   , "filename=%s; julia ${filename}"                                                                                                       },
    {".js"   , "filename=%s; node ${filename}"                                                                                                        },
    {".lua"  , "filename=%s; lua ${filename}"                                                                                                         },
    {".py"   , "filename=%s; python ${filename}"                                                                                                      },
    {".rb"   , "filename=%s; ruby ${filename}"                                                                                                        },
    {".rs"   , "filename=%s; cargo build && cargo run"                                                                                                },
    {".scala", "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".sh"   , "filename=%s; sh ${filename}"                                                                                                          },
    {".sql"  , "filename=%s; mysql -uroot -p < ${filename}"                                                                                           },
    {".tex"  , "filename=%s; xelatex -interaction nonstopmode ${filename}; bibtex *.aux; xelatex -interaction nonstopmode ${filename}; zathura *.pdf" },
    {".ts"   , "filename=%s; tsc ${filename}"                                                                                                         },
    {NULL    , NULL                                                                                                                                   }
};

/* exec rules for rest */
static const struct KV exec_else_map[] = {
    /**   , shell scripts                  */
    {"*"  , "filename=%s; sh ${filename }" }, // any excuteble file
    {NULL , NULL                           }
};

/* default options for cp, mv, rm */
static const char *cp_opt = "-fr"; // recommended "-ir"
static const char *mv_opt = "-f" ; // recommended "-i"
static const char *rm_opt = "-fr"; // recommended "-ir"


