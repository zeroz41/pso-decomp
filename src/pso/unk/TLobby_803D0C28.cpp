#include "types.h"
#include "pso/unk/TLobby_803D0C28.h"

extern s32 fileio_error_context;
extern s32 fileio_error_callback;

void TLobby__sub_803D0C28(s32 arg0, s32 arg1) {
    fileio_error_callback = arg0;
    fileio_error_context = arg1;
}
