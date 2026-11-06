#ifndef PSO_UI_FRONTEND_TADSUBPLYITEMGC_H
#define PSO_UI_FRONTEND_TADSUBPLYITEMGC_H
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "types.h"

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
    int render_status_line(int a1);
    u8 *format_level_text(int level);

    u8 pad_1C[4];
    char names[4][0xFF];
    u32 levels[4];
    u32 alpha[4];
    s32 visible[4];
    NJS_POINT2 name_pos[4];
    NJS_POINT2 level_pos[4];
};
typedef char TAdSubPlyItemGCExtent[sizeof(TAdSubPlyItemGC) == 0x48C ? 1 : -1];

#endif
