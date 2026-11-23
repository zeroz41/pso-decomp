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

// The speed, scale, angle and point count of the ending's hex lines.
struct EndingHexLineParams {
    f32 speed;
    f32 scale;
    s32 angle;
    f32 count;
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
    static void *create(void *parent, void *start);

    // The live line parameters; TObjOnlineEndingHexMove eases them toward
    // online_ending_hex_line_param.
    static EndingHexLineParams hex_line_params;
};

LAYOUT_ASSERT(EndingHexLineSize, sizeof(TObjOnlineEndingHexLine) == 0xA0);
LAYOUT_ASSERT(EndingHexProgressOffset, offsetof(TObjOnlineEndingHexLine, progress) == 0x9C);

void copy_ending_hex_point(EndingHexPoint *point, const EndingHexPoint *source);
extern EndingHexLineParams online_ending_hex_line_state;
extern "C" void reset_hex_line_params(void);

struct NJS_TEXLIST;
// The f512_multiplay texture list register_texture_f512_multiplay loads for the
// game start screens; TAdGameStartSubGC::destroy_instance releases it.
extern NJS_TEXLIST *multiplay_texture_f512_handle;

#endif
