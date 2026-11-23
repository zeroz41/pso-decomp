#ifndef PSO_UI_FRONTEND_TADMULTIOKGC_H
#define PSO_UI_FRONTEND_TADMULTIOKGC_H

#include "pso/system/task/TObject.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"

// The players taking part (count) and the bit set of their character slots
// (mask), filled by TAdMultiConfirmGC.
struct TAdMultiOkSetup {
    s32 count;
    u32 mask;
};

// Where a row of count markers starts and how far apart they are.
struct TAdMultiOkRow {
    f32 x, y, step;
};

// One player's OK marker: five copies of its quad that trail in on A
// (flags 1 confirmed, 2 animating, 4 finished).
struct TAdMultiOkEntry {
    u32 flags;
    s32 frame;
    f32 x;
    f32 y;
    u32 colors[5];
    TexturedQuad quads[5];
};

class TAdMultiOkGC : public TObject {
public:
    TAdMultiOkGC(TObject *parent, TAdMultiOkSetup *setup);
    virtual ~TAdMultiOkGC();
    virtual void run_task();
    virtual void render();

    void draw_entry(int index);
    void update_entry_animation(int index);
    void handle_player_buttons(int i);
    s32 are_all_entries_finished();
    int multi_confirm_cancel_requested();

    TAdMultiOkEntry m_entries[12];
    s32 m_players[12];
    s32 m_count;
    u32 m_flags;
};

LAYOUT_ASSERT(TAdMultiOkGC_size, sizeof(TAdMultiOkGC) == 0x984);

void free_multi_confirm_textures(void);
void load_multi_confirm_textures(void);

#endif
