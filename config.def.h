/* See LICENSE file for copyright and license details. */
// config.def.h

/* Author: lorenzo */
/* E-mail: lorenzo<zetatez@icloud.com> */

struct KV {
    char *key;
    char *value;
};

/* open rules */
static const struct KV open_map[] = {
    {".cbr"    , "zathura"},
    {".cbz"    , "zathura"},
    {".djvu"   , "evince"},
    {".epub"   , "foliate"},
    {".mobi"   , "okularr"},
    {".pdf"    , "zathura"},
    {".doc"    , "wps"},
    {".docm"   , "wps"},
    {".docx"   , "wps"},
    {".dot"    , "wps"},
    {".dotx"   , "wps"},
    {".fodt"   , "wps"},
    {".odt"    , "wps"},
    {".ott"    , "wps"},
    {".rtf"    , "wps"},
    {".uot"    , "wps"},
    {".pptx"   , "libreoffice"},
    {".dbf"    , "wps"},
    {".dif"    , "wps"},
    {".fods"   , "wps"},
    {".ods"    , "wps"},
    {".ots"    , "wps"},
    {".slk"    , "wps"},
    {".uos"    , "wps"},
    {".xls"    , "wps"},
    {".xlsm"   , "wps"},
    {".xlsx"   , "wps"},
    {".xlt"    , "wps"},
    {".Z"      , "atool --list --"},
    {".a"      , "atool --list --"},
    {".ace"    , "atool --list --"},
    {".alz"    , "atool --list --"},
    {".arc"    , "atool --list --"},
    {".arj"    , "atool --list --"},
    {".bz"     , "atool --list --"},
    {".bz2"    , "atool --list --"},
    {".cab"    , "atool --list --"},
    {".cpio"   , "atool --list --"},
    {".deb"    , "atool --list --"},
    {".gz"     , "atool --list --"},
    {".jar"    , "atool --list --"},
    {".lha"    , "atool --list --"},
    {".lz"     , "atool --list --"},
    {".lzh"    , "atool --list --"},
    {".lzma"   , "atool --list --"},
    {".lzo"    , "atool --list --"},
    {".rpm"    , "atool --list --"},
    {".rz"     , "atool --list --"},
    {".t7z"    , "atool --list --"},
    {".tZ"     , "atool --list --"},
    {".tar"    , "atool --list --"},
    {".tbz"    , "atool --list --"},
    {".tbz2"   , "atool --list --"},
    {".tgz"    , "atool --list --"},
    {".tlz"    , "atool --list --"},
    {".txz"    , "atool --list --"},
    {".tzo"    , "atool --list --"},
    {".war"    , "atool --list --"},
    {".xpi"    , "atool --list --"},
    {".xz"     , "atool --list --"},
    {".zip"    , "atool --list --"},
    {".rar"    , "unrar -lt -p- --"},
    {".7z"     , "7z l -p- --"},
    {".json"   , "vim"},
    {NULL      , NULL}
};

/* open rules for rest */
static const struct KV open_else_map[] = {
    {"image/*" , "sxiv"}                     , // sxiv , feh   , img2txt --gamma=0.5 , ..
    {"video/*" , "mpv --geometry=100%x100%"} , // mpv  , vlc   , ...
    {"audio/*" , "mpv"}                      , // mpv  , vlc   , ...
    {"text/*"  , "vim"}                      , // vim  , emacs ,
    {"inode/*" , "vim"}                      , // vim  , emacs ,                             // inode/x-empty
    {NULL      , NULL}
};

/* exec rules */
static const struct KV exec_map[] = {
    {".sh"    , "filename=%s; sh ${filename}"},
    {".py"    , "filename=%s; python ${filename}"},
    {".jl"    , "filename=%s; julia ${filename}"},
    {".tex"   , "filename=%s; xelatex -interaction nonstopmode ${filename}; bibtex *.aux; xelatex -interaction nonstopmode ${filename}; zathura *.pdf"},
    {".c"     , "filename=%s; cd ${filename%.*}; sh build.sh"},
    {".c++"   , "filename=%s; cd ${filename%.*}; sh build.sh"},
    {".go"    , "filename=%s; go run ${filename}"},
    {".scala" , "filename=%s; cd ${filename%.*}; sh build.sh"},
    {".java"  , "filename=%s; cd ${filename%.*}; sh build.sh"},
    {".rs"    , "filename=%s; cargo build && cargo run"},
    {".rb"    , "filename=%s; ruby ${filename}"},
    {".lua"   , "filename=%s; lua ${filename}"},
    {".js"    , "filename=%s; node ${filename}"},
    {".ts"    , "filename=%s; tsc ${filename}"},
    {".sql"   , "filename=%s; mysql -uroot -p < ${filename}"},
    {NULL     , NULL}
};

/* exec rules for rest */
static const struct KV exec_else_map[] = {
    {"*"      , "filename=%s; sh ${filename}"},  // any excuteble file
    {NULL     , NULL}
};

/* default options for cp, mv, rm */
static const char *cp_opt           = "-fr"; // recommended "-ir"
static const char *mv_opt           = "-f";  // recommended "-i"
static const char *rm_opt           = "-fr"; // recommended "-ir"


