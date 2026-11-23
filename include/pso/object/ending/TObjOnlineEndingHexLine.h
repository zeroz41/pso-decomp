#ifndef PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXLINE_H
#define PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXLINE_H
#include "pso/system/task/TObject.h"
#include <stddef.h>
#include "types.h"

struct NJS_POINT2;

struct EndingHexPoint {
    s16 x;
    s16 y;
};

class TObjOnlineEndingHexLine : public TObject {
public:
    TObjOnlineEndingHexLine(TObject *parent, EndingHexPoint *start);
    virtual ~TObjOnlineEndingHexLine();
    virtual void render();
    virtual void run_task();
public:
    EndingHexPoint points[32];
    f32 progress;

    void step_line();
    static s32 calc_rotated_hex_point(NJS_POINT2 *out, EndingHexPoint *point);
    static void *create(void *arg0, void *arg1);
};

LAYOUT_ASSERT(EndingHexLineSize, sizeof(TObjOnlineEndingHexLine) == 0xA0);
LAYOUT_ASSERT(EndingHexProgressOffset, offsetof(TObjOnlineEndingHexLine, progress) == 0x9C);

struct GinjaTextureList;
// The f512_multiplay texture list register_texture_f512_multiplay loads for the
// game start screens; TAdGameStartSubGC::destroy_instance releases it.
extern GinjaTextureList *multiplay_texture_f512_handle;

#endif
