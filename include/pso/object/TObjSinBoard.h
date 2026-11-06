#ifndef PSO_OBJECT_TOBJSINBOARD_H
#define PSO_OBJECT_TOBJSINBOARD_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjSinBoard : public TObjBase {
    TObjSinBoard(TObject *parent, void *set_data);
    virtual ~TObjSinBoard();
    virtual void render();
    virtual void run_task();
};

typedef char TObjSinBoard_size[sizeof(TObjSinBoard) == 0x90 ? 1 : -1];

extern "C" {
void *TObjSinBoard__create(void *set_data);
void TLobby__sub_80197F74(void);
// Copies a size-byte signboard picture into a fresh buffer and makes it the
// signboard's texture (quest opcode call_image_data, load_memcard_file).
void fn_80197FD0(const void *image, u32 size);
}

// The signboard picture: memory card file PSO______099 or a quest image.
s32 is_signboard_texture_buffer_missing(void);
void load_memcard_file(void);
void clear_signboard_texture_buffer_pointer(void);
extern const char *memcard_file_099_name;

#endif
