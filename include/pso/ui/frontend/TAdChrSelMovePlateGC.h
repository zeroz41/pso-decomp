#ifndef PSO_UI_FRONTEND_TADCHRSELMOVEPLATEGC_H
#define PSO_UI_FRONTEND_TADCHRSELMOVEPLATEGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct CharacterSlotPosition;

struct MovePlateQuad { f32 values[8]; };
class TAdChrSelMovePlateGC : public TObject {
public:
    TAdChrSelMovePlateGC(TObject *parent);
    virtual ~TAdChrSelMovePlateGC();
    virtual void run_task();
    virtual void render();
    void clear_entries();
    void add_plate_rect(CharacterSlotPosition *position);
    void init_plate_rects();
    void draw_move_plate_quads();

    u8 reserved_1c[4];
    u32 count;
    s32 mode;
    MovePlateQuad quads[12];
    s32 opacity[12];
    s32 other[12];
};
LAYOUT_ASSERT(TAdChrSelMovePlateGC_size, sizeof(TAdChrSelMovePlateGC) == 0x208);
#endif
