#ifndef PSO_OBJECT_TOBJSINBOARD_H
#define PSO_OBJECT_TOBJSINBOARD_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjSinBoard : public TObjBase {
    TObjSinBoard(TObject *parent, void *set_data);
    virtual ~TObjSinBoard();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjSinBoard_size, sizeof(TObjSinBoard) == 0x90);

void load_midi_stub(void);
// Copies a size-byte signboard picture into a fresh buffer and makes it the
// signboard's texture (quest opcode call_image_data, load_memcard_file).
void load_sin_board_image(const void *image, u32 size);

// The signboard picture: memory card file PSO______099 or a quest image.
s32 is_signboard_texture_buffer_missing(void);
void load_memcard_file(void);
void clear_signboard_texture_buffer_pointer(void);
extern const char *memcard_file_099_name;

#endif
