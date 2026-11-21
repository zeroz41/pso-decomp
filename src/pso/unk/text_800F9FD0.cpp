#include "types.h"
#include "pso/unk/text_800F9FD0.h"

struct Node_800F9FF4 { u32 flags; s32 id; u8 pad8[0x30]; Node_800F9FF4 *next; };

struct Key_800F9FF4 { u8 pad0[4]; s32 id; };

extern "C" {
extern saddr async_file_read_current_request;
extern s32 async_file_read_state;
s32 TLobby__sub_800F9FF4(Key_800F9FF4 *key);
bool TLobby__sub_800F9FD0(void) {
    if ((s32) async_file_read_state != 0) {
        return 1;
    }
    return async_file_read_current_request != 0;
}
s32 TLobby__sub_800F9FF4(Key_800F9FF4 *key) {
    Node_800F9FF4 *n;
    if (key == NULL) {
        return 0;
    }
    for (n = (Node_800F9FF4 *)async_file_read_current_request; n != NULL; n = n->next) {
        if (n->id == key->id) {
            n->flags |= 0x200;
            return 1;
        }
    }
    return 0;
}

}
