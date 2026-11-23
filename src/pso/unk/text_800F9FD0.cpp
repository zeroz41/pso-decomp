#include "pso/unk/text_800FA464.h"
#include "types.h"
#include "pso/unk/text_800F9FD0.h"


struct Key_800F9FF4 { u8 pad0[4]; s32 id; };

extern "C" {
s32 TLobby__sub_800F9FF4(Key_800F9FF4 *key);
bool TLobby__sub_800F9FD0(void) {
    if ((s32) async_file_read_state != 0) {
        return 1;
    }
    return async_file_read_current_request != 0;
}
s32 TLobby__sub_800F9FF4(Key_800F9FF4 *key) {
    AsyncFileReadRequest *n;
    if (key == NULL) {
        return 0;
    }
    for (n = async_file_read_current_request; n != NULL; n = n->next) {
        if (n->id == key->id) {
            n->flags |= 0x200;
            return 1;
        }
    }
    return 0;
}

}
