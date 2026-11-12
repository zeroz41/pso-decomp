#ifndef PSO_UI_FRONTEND_TADPLYCHRSELPLATEGC_H
#define PSO_UI_FRONTEND_TADPLYCHRSELPLATEGC_H
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

class TAdPlyChrSelPlateGC : public TObject {
public:
    virtual ~TAdPlyChrSelPlateGC();
    virtual void run_task();
    virtual void render();
public:
    bool is_slot_value_ready(s32 i);
    void reset_selection_slots();
    void push_plate_position();

    NJS_POINT2 plate_pos[32];  // 0x1C: top-left corner of each plate (inferred)
    u8 pad_11C[0x100];
    NJS_POINT2 plate_size;     // 0x21C: width, height added to the far corners (inferred)
    u32 plate_count;           // 0x224
    s32 plate_shown[32];       // 0x228: non-zero when the plate is drawn (inferred)
    f32 pad_2A8[32];
    NJS_COLOR plate_color[32]; // 0x328
    u8 pad_3A8[0xC];
};

// Plate size (then four bytes the plate copies and a word) passed to the TAdPlyChrSelPlateGC ctor
struct ChrSelPlateLayout {
    f32 width;
    f32 height;
    u8 pad_8[4];
    s32 pad_c;
};

// Draws one plate quad of `plate`'s size at `pos` in `color`, `depth` steps in front.
extern "C" void TAdEnterSerialAccessGC__sub_802C4B64(TAdPlyChrSelPlateGC *plate, NJS_POINT2 *pos, NJS_COLOR color, u32 depth);

#endif
