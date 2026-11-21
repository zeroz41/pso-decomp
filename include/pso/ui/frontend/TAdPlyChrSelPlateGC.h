#ifndef PSO_UI_FRONTEND_TADPLYCHRSELPLATEGC_H
#define PSO_UI_FRONTEND_TADPLYCHRSELPLATEGC_H
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include <stddef.h>

struct ChrSelPlateLayout;
struct CharacterSlotPosition;

class TAdPlyChrSelPlateGC : public TObject {
public:
    TAdPlyChrSelPlateGC(TObject *parent, const ChrSelPlateLayout *layout);
    virtual ~TAdPlyChrSelPlateGC();
    virtual void run_task();
    virtual void render();
public:
    s32 is_slot_value_ready(s32 i);
    void reset_selection_slots();
    void push_plate_position(const CharacterSlotPosition *position);

    NJS_POINT2 plate_pos[32];  // 0x1C: top-left corner of each plate (inferred)
    NJS_POINT2 target_pos[32];
    NJS_POINT2 plate_size;     // 0x21C: width, height added to the far corners (inferred)
    u32 plate_count;           // 0x224
    s32 plate_shown[32];       // 0x228: non-zero when the plate is drawn (inferred)
    f32 plate_progress[32];
    NJS_COLOR plate_color[32]; // 0x328
    NJS_COLOR active_color;
    s32 animation_frame;
    s32 settings;
};

LAYOUT_ASSERT(TAdPlyChrSelPlateGC_plate_pos_offset, offsetof(TAdPlyChrSelPlateGC, plate_pos) == 0x1C);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_target_pos_offset, offsetof(TAdPlyChrSelPlateGC, target_pos) == 0x11C);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_plate_size_offset, offsetof(TAdPlyChrSelPlateGC, plate_size) == 0x21C);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_plate_count_offset, offsetof(TAdPlyChrSelPlateGC, plate_count) == 0x224);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_shown_offset, offsetof(TAdPlyChrSelPlateGC, plate_shown) == 0x228);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_progress_offset, offsetof(TAdPlyChrSelPlateGC, plate_progress) == 0x2A8);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_color_offset, offsetof(TAdPlyChrSelPlateGC, plate_color) == 0x328);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_frame_offset, offsetof(TAdPlyChrSelPlateGC, animation_frame) == 0x3AC);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_settings_offset, offsetof(TAdPlyChrSelPlateGC, settings) == 0x3B0);
LAYOUT_ASSERT(TAdPlyChrSelPlateGC_size, sizeof(TAdPlyChrSelPlateGC) == 0x3B4);

// Plate size (then four bytes the plate copies and a word) passed to the TAdPlyChrSelPlateGC ctor
struct ChrSelPlateLayout {
    f32 width;
    f32 height;
    u8 color[4];
    s32 settings;
};

LAYOUT_ASSERT(ChrSelPlateLayout_size, sizeof(ChrSelPlateLayout) == 0x10);

// Draws one plate quad of `plate`'s size at `pos` in `color`, `depth` steps in front.
extern "C" void draw_selection_plate(TAdPlyChrSelPlateGC *plate, NJS_POINT2 *pos, NJS_COLOR color, u32 depth);

#endif
