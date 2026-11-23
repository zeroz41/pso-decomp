#ifndef PSO_UI_FRONTEND_TADSUBPLYITEMGC_H
#define PSO_UI_FRONTEND_TADSUBPLYITEMGC_H
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "types.h"

struct PlayerSlotLabel {
    s32 slot;
    const char *name;
    s32 level;
    NJS_POINT2 position;
};

LAYOUT_ASSERT(PlayerSlotLabelSize, sizeof(PlayerSlotLabel) == 0x14);

// Up to four player lines (name, then "LV%d" right-aligned) on the character-select plates.
class TAdSubPlyItemGC : public TObject {
public:
    TAdSubPlyItemGC(TObject *parent);
    // render is declared first: it is the class's key function, so the vtable is emitted
    // with it, after TAdPlayerLoadGC's data, as in the original data.
    virtual void render();
    virtual ~TAdSubPlyItemGC();
    virtual void run_task();
public:
    // Draws text with the menu font at (x, y). The floats come first: TAdEnterSerialAccessGC's
    // literal pool has 281.0f before "-" (separator calls), which only that argument order creates.
    static void render_status_line(f32 x, f32 y, f32 scale, const char *text, u32 color);
    u8 *format_level_text(int level);
    // Hides all four lines (clears visible[]).
    void sub_802D6D88();

    u8 pad_1C[4];
    char names[4][0xFF];
    u32 levels[4];
    u32 alpha[4];
    s32 visible[4];
    NJS_POINT2 name_pos[4];
    NJS_POINT2 level_pos[4];
};
LAYOUT_ASSERT(TAdSubPlyItemGCExtent, sizeof(TAdSubPlyItemGC) == 0x48C);

extern "C" void set_entry_text__15TAdSubPlyItemGCFPvPv(TAdSubPlyItemGC *self, PlayerSlotLabel *entry);

#endif
