#include "types.h"
#include "pso/unk/text_803D9FF0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_803DA038.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 strcmp(const char *, const char *);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
u32 strlen(const char *);

void TAdSinglePlyChrSelectGC::append_extension_if_missing(char *name, char *ext) {
    char buf[8];
    s32 len;
    len = strlen(name);
    strcpy(buf, &name[len - 4]);
    convert_string_chars_via_table((u8 *)buf);
    if (buf[0] == '.') {
        if (strcmp(buf, ext) != 0) {
            strcpy(((char *)this), name);
            strcat(((char *)this), ext);
        } else {
            strcpy(((char *)this), name);
        }
    } else {
        strcpy(((char *)this), name);
        strcat(((char *)this), ext);
    }
}

s32 TObjPlayer__sub_803DA104(u8 x) {
    switch (x) {
    case 8:
    case 9:
    case 10:
        return 1;
    }
    return 0;
}

}
