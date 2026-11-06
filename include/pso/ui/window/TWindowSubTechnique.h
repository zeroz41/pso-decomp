#ifndef PSO_UI_WINDOW_TWINDOWSUBTECHNIQUE_H
#define PSO_UI_WINDOW_TWINDOWSUBTECHNIQUE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubTechnique : public TObject {
    virtual ~TWindowSubTechnique();
    s32 sub_80286AA8();
    u8 m_1c;
    u8 _pad1D[0x1];
    u16 m_1e;
    void* m_20;
    void* m_24;
    s32 playerIndex;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;

    void rebuildTechniqueList(s32 list, s32 category);
    s32 open_menu();
    void update_selected_help(s32 arg1);
    virtual void render();
    virtual void run_task();
    void clear_flag70_bit80();
    static void get_selection(s16 *arg0, s32 *arg1, s32 arg2);
    static s32 update_selection(s16 *arg0, s32 *arg1);
    int get_current_selection(void* _w1);
    static s32 lookup_technique(s32 arg0, s32 arg1);
    s32 create_title_window();
    static s32 is_technique_available(s32 arg0, s32 arg1);
    static void draw_technique_row(s32 id, s32 arg1, s32 arg2);
};

typedef char TWindowSubTechnique_size[sizeof(TWindowSubTechnique) == 0x40 ? 1 : -1];

extern "C" {
void *TWindowSubTechnique__ct(TWindowSubTechnique *arg0, s32 arg1, s32 arg2);
s32 TWindowSubTechnique__sub_8028753C(s32 arg0);
void *__dt__19TWindowSubTechniqueFv(TWindowSubTechnique *arg0, s16 arg1);
}

#endif
