#ifndef PSO_UI_WINDOW_HELPITEMRARITYSTARROW_H
#define PSO_UI_WINDOW_HELPITEMRARITYSTARROW_H

#include "types.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/unk/WindowLayoutRecord.h"

// A row of at least ten star slots with the first `stars` lit (case 10 of
// init_window_layout_entries).
// inferred: item rarity star row (class name from what it draws).
class HelpItemRarityStarRow : public TWindowLayoutEntry {
public:
    f32 pos[2];
    s32 stars;

    f32 get_item_star_row_width();
    virtual void render(WindowDrawContext *context);
    virtual void update();
    virtual ~HelpItemRarityStarRow();
    HelpItemRarityStarRow(PointLayoutRecord *rec, s32 client);
};

LAYOUT_ASSERT(HelpItemRarityStarRow_size, sizeof(HelpItemRarityStarRow) == 0x14);

extern "C" {
// HelpItemRarityStarRow::HelpItemRarityStarRow(PointLayoutRecord *, s32). init_window_layout_entries cannot use new: calc_bar_width
// stays pure (slot 0 of the vtable), so the class is abstract.
void *__ct__21HelpItemRarityStarRowFP17PointLayoutRecordl(void *p, PointLayoutRecord *rec, s32 client);
}

#endif
