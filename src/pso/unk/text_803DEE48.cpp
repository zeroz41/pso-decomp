#include "types.h"
#include "pso/unk/text_803DEE48.h"
extern "C" {
s32 DVDChangeDir(const char *dir);
}
#pragma push
#pragma scheduling off
s32 change_disc_directory(const char *dir) {
    DVDChangeDir(dir);
    return 0;
}
#pragma pop
