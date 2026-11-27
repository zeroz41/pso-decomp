#include "types.h"
#include "pso/system/StringCharTable.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_803DA038.h"
#include <string.h>


void append_extension_if_missing(char *dest, char *name, char *ext) {
    char buf[8];
    s32 len;
    len = strlen(name);
    strcpy(buf, &name[len - 4]);
    convert_string_chars_via_table((u8 *)buf);
    if (buf[0] == '.') {
        if (strcmp(buf, ext) != 0) {
            strcpy(dest, name);
            strcat(dest, ext);
        } else {
            strcpy(dest, name);
        }
    } else {
        strcpy(dest, name);
        strcat(dest, ext);
    }
}

s32 is_palette_texture_format(s32 format) {
    switch ((u8)format) {
    case 8:
    case 9:
    case 10:
        return 1;
    }
    return 0;
}

