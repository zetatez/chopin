/* See LICENSE file for copyright and license details. */
// config.def.h

/* Author: lorenzo */
/* E-mail: lorenzo<zetatez@icloud.com> */

/* open rules */
static const struct KFV open_map[] = {
    /* .ext  , &    , application        */
    {".md"   , 0    , "vim"              } ,
    {".pdf"  , 0    , "zathura"          } ,
    {".doc"  , 0    , "libreoffice"      } ,
    {".docx" , 0    , "libreoffice"      } ,
    {".pptx" , 0    , "libreoffice"      } ,
    {".xls"  , 0    , "libreoffice"      } ,
    {".xlsx" , 0    , "libreoffice"      } ,
    {".tar"  , 0    , "atool --list --"  } ,
    {".gz"   , 0    , "atool --list --"  } ,
};

/* open rules for rest */ // Note: to get mime-type of a file: file --dereference --brief --mime-type file_name
static const struct KFV open_map_else[] = {
    /*mime-type                                                                  , & , application                */
    {"inode/x-empty"                                                             , 0 , "vim"                      } ,
    {"text/calendar"                                                             , 0 , "vim"                      } ,
    {"text/css"                                                                  , 0 , "vim"                      } ,
    {"text/csv"                                                                  , 0 , "vim"                      } ,
    {"text/html"                                                                 , 0 , "vim"                      } ,
    {"text/javascript"                                                           , 0 , "vim"                      } ,
    {"text/plain"                                                                , 0 , "vim"                      } ,
    {"text/troff"                                                                , 0 , "vim"                      } ,
    {"text/x-shellscript"                                                        , 0 , "vim"                      } ,
    {"text/x-c"                                                                  , 0 , "vim"                      } ,
    {"text/x-c++"                                                                , 0 , "vim"                      } ,
    {"text/x-java"                                                               , 0 , "vim"                      } ,
    {"text/x-makefile"                                                           , 0 , "vim"                      } ,
    {"text/x-ruby"                                                               , 0 , "vim"                      } ,
    {"text/x-script.python"                                                      , 0 , "vim"                      } ,
    {"text/x-tex"                                                                , 0 , "vim"                      } ,
    {"text/x-diff"                                                               , 0 , "vim"                      } ,
    {"text/xml"                                                                  , 0 , "vim"                      } ,
    {"application/x-httpd-php"                                                   , 0 , "vim"                      } ,
    {"application/x-javascript"                                                  , 0 , "vim"                      } ,
    {"application/x-latex"                                                       , 0 , "vim"                      } ,
    {"application/x-sh"                                                          , 0 , "vim"                      } ,
    {"application/xhtml+xml"                                                     , 0 , "vim"                      } ,
    {"application/xml"                                                           , 0 , "vim"                      } ,
    {"application/json"                                                          , 0 , "vim"                      } ,
    {"application/pdf"                                                           , 0 , "zathura"                  } ,
    {"application/epub+zip"                                                      , 0 , "foliate"                  } ,
    {"application/msword"                                                        , 0 , "libreoffice"              } ,
    {"application/vnd.ms-excel"                                                  , 0 , "libreoffice"              } ,
    {"application/vnd.ms-outlook"                                                , 0 , "libreoffice"              } ,
    {"application/vnd.ms-powerpoint"                                             , 0 , "libreoffice"              } ,
    {"application/vnd.ms-project"                                                , 0 , "libreoffice"              } ,
    {"application/vnd.openxmlformats-officedocument.presentationml.presentation" , 0 , "libreoffice"              } ,
    {"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"         , 0 , "libreoffice"              } ,
    {"application/vnd.openxmlformats-officedocument.wordprocessingml.document"   , 0 , "libreoffice"              } ,
    {"application/vnd.visio"                                                     , 0 , "libreoffice"              } ,
    {"image/bmp"                                                                 , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/gif"                                                                 , 0 , "sxiv -a"                  } , // sxiv, feh, img2txt --gamma=0.5
    {"image/ief"                                                                 , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/jpg"                                                                 , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/jpeg"                                                                , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/pipeg"                                                               , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/png"                                                                 , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/svg+xml"                                                             , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/tiff"                                                                , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/webp"                                                                , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/x-cmu-raster"                                                        , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/x-cmx"                                                               , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/x-icon"                                                              , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/x-rgb"                                                               , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/x-xbitmap"                                                           , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/x-xpixmap"                                                           , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"image/x-xwindowdump"                                                       , 0 , "sxiv"                     } , // sxiv, feh, img2txt --gamma=0.5
    {"application/ogg"                                                           , 0 , "mpv"                      } ,
    {"audio/3gpp"                                                                , 0 , "mpv"                      } ,
    {"audio/3gpp2"                                                               , 0 , "mpv"                      } ,
    {"audio/acc"                                                                 , 0 , "mpv"                      } ,
    {"audio/midi"                                                                , 0 , "mpv"                      } ,
    {"audio/mpeg"                                                                , 0 , "mpv"                      } ,
    {"audio/ogg"                                                                 , 0 , "mpv"                      } ,
    {"audio/wav"                                                                 , 0 , "mpv"                      } ,
    {"audio/wave"                                                                , 0 , "mpv"                      } ,
    {"audio/webm"                                                                , 0 , "mpv"                      } ,
    {"audio/x-m4a"                                                               , 0 , "mpv"                      } ,
    {"audio/x-midi"                                                              , 0 , "mpv"                      } ,
    {"audio/x-mpegurl"                                                           , 0 , "mpv"                      } ,
    {"audio/x-msvideo"                                                           , 0 , "mpv"                      } ,
    {"audio/x-pn-wav"                                                            , 0 , "mpv"                      } ,
    {"audio/x-realaudio"                                                         , 0 , "mpv"                      } ,
    {"audio/x-wav"                                                               , 0 , "mpv"                      } ,
    {"video/3gpp"                                                                , 0 , "mpv --geometry=100%x100%" } ,
    {"video/3gpp2"                                                               , 0 , "mpv --geometry=100%x100%" } ,
    {"video/mp4"                                                                 , 0 , "mpv --geometry=100%x100%" } ,
    {"video/ogg"                                                                 , 0 , "mpv --geometry=100%x100%" } ,
    {"video/quicktime"                                                           , 0 , "mpv --geometry=100%x100%" } ,
    {"video/webm"                                                                , 0 , "mpv --geometry=100%x100%" } ,
    {"video/x-flv"                                                               , 0 , "mpv --geometry=100%x100%" } ,
    {"video/x-m4v"                                                               , 0 , "mpv --geometry=100%x100%" } ,
    {"video/x-matroska"                                                          , 0 , "mpv --geometry=100%x100%" } ,
    {"video/x-ms-asf"                                                            , 0 , "mpv --geometry=100%x100%" } ,
    {"video/x-ms-wmv"                                                            , 0 , "mpv --geometry=100%x100%" } ,
    {"video/x-sgi-moive"                                                         , 0 , "mpv --geometry=100%x100%" } ,
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
};

/* exec rules */
static const struct KV exec_map[] = {
    /*.ext   , shell scripts                                                                                                                            */
    {".c"    , "file_name=%s; cd ${file_name%.*}; sh build.sh"                                                                                           },
    {".cpp"  , "file_name=%s; cd ${file_name%.*}; sh build.sh"                                                                                           },
    {".go"   , "file_name=%s; go run ${file_name}"                                                                                                       },
    {".java" , "file_name=%s; cd ${file_name%.*}; sh build.sh"                                                                                           },
    {".jl"   , "file_name=%s; julia ${file_name}"                                                                                                        },
    {".js"   , "file_name=%s; node ${file_name}"                                                                                                         },
    {".lua"  , "file_name=%s; lua ${file_name}"                                                                                                          },
    {".py"   , "file_name=%s; python ${file_name}"                                                                                                       },
    {".rb"   , "file_name=%s; ruby ${file_name}"                                                                                                         },
    {".rs"   , "file_name=%s; cargo build && cargo run"                                                                                                  },
    {".scala", "file_name=%s; cd ${file_name%.*}; sh build.sh"                                                                                           },
    {".sh"   , "file_name=%s; sh ${file_name}"                                                                                                           },
    {".sql"  , "file_name=%s; mysql -uroot -p < ${file_name}"                                                                                            },
    {".tex"  , "file_name=%s; xelatex -interaction nonstopmode ${file_name}; bibtex *.aux; xelatex -interaction nonstopmode ${file_name}; zathura *.pdf" },
    {".ts"   , "file_name=%s; tsc ${file_name}"                                                                                                          },
};

/* exec rules for rest */
static const struct KV exec_map_else[] = {
    /**   , shell scripts                  */
    {"*"  , "file_name=%s; sh ${file_name }" }, // any excuteble file
};

/* default options for cp, mv, rm */
static const char *cp_opt = "-fr"; // recommended "-ir"
static const char *mv_opt = "-f" ; // recommended "-i"
static const char *rm_opt = "-fr"; // recommended "-ir"
