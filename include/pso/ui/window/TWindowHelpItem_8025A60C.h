#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_8025A60C_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_8025A60C_H

#include "types.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/unk/WindowLayoutRecord.h"

// A row of at least ten star slots with the first `stars` lit (case 10 of
// init_window_layout_entries). Inferred name: item rarity star row.
class TUnk_804CFA10 : public TWindowLayoutEntry {
public:
    f32 pos[2];
    s32 stars;

    f32 get_item_star_row_width();
    virtual void render(WindowDrawContext *context);
    virtual void update();
    virtual ~TUnk_804CFA10();
    TUnk_804CFA10(PointLayoutRecord *rec, s32 client);
};

LAYOUT_ASSERT(TUnk_804CFA10_size, sizeof(TUnk_804CFA10) == 0x14);

extern "C" {
// TUnk_804CFA10::TUnk_804CFA10(PointLayoutRecord *, s32), called by init_window_layout_entries.
void *__ct__13TUnk_804CFA10FP17PointLayoutRecordl(void *p, PointLayoutRecord *rec, s32 client);
}

#endif
