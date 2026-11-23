#ifndef PSO_UI_FRONTEND_TADMCSELECTCURSORGC_H
#define PSO_UI_FRONTEND_TADMCSELECTCURSORGC_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/frontend/TAdMcSelectMcGC.h"

struct TAdMcCheckGC;
#include "pso/system/task/TObject.h"

struct TAdMcSelectCursorGC : public TObject {
    TAdMcSelectCursorGC(TObject *parent);
    virtual ~TAdMcSelectCursorGC();
    s32 m_1c;
    s32 selected_slot;
    s32 previous_slot;
    McSelectMcQuad quads[8];
    u32 cursor_alpha;
    u32 m_12c;
    u8 _pad130[0x4];
    u32 m_134;
    u32 m_138;
    u32 m_13c;
    void render_cursor();
    s32 get_slot_index();
    void set_field_13c(s32 mode);
    virtual void render();
    virtual void run_task();
    static TAdMcSelectCursorGC *get_instance(TObject *parent);
    static void release_cursor_entry();
    static void init_resource();
    static TAdMcCheckGC *get_cursor_type(int slot);
    void sub_8032A140(); // clears m_1c; defined in TAdMcSelectGC.cpp
    void sub_8032A15C(); // sets m_1c to 1; defined in TAdMcSelectGC.cpp
    s32 sub_8032AAC4(); // returns selected_slot, the selected slot; defined in TAdMcSelectMcGC.cpp, its only caller
};

LAYOUT_ASSERT(TAdMcSelectCursorGC_quads_offset, offsetof(TAdMcSelectCursorGC, quads) == 0x28);
LAYOUT_ASSERT(TAdMcSelectCursorGC_cursor_alpha_offset, offsetof(TAdMcSelectCursorGC, cursor_alpha) == 0x128);
LAYOUT_ASSERT(TAdMcSelectCursorGC_mode_offset, offsetof(TAdMcSelectCursorGC, m_13c) == 0x13C);
LAYOUT_ASSERT(TAdMcSelectCursorGC_size, sizeof(TAdMcSelectCursorGC) == 0x140);

extern "C" {
extern TAdMcSelectCursorGC *TAdMcSelectCursorGC__instance;
void *__dt__19TAdMcSelectCursorGCFv(void *arg0, s16 arg1);
}

#endif
