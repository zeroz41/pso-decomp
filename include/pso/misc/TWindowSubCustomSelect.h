#ifndef PSO_MISC_TWINDOWSUBCUSTOMSELECT_H
#define PSO_MISC_TWINDOWSUBCUSTOMSELECT_H

#include "types.h"
#include "pso/misc/TWindowAddition.h"

struct TWindowSubCustomSelect : public TWindowAddition {
    virtual ~TWindowSubCustomSelect();
    virtual void render();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 _pad28[0x4];
    u32 m_2c;
    u8 _pad30[0x4];
    u32 m_34;
    u8 unk_38[0x14];
    f32 m_4c;
    u8 unk_50[0xC];
    u32 m_5c;
    u8 _pad60[0x8];
    void* m_68;
    u8 _pad6C[0x4];
    u8 m_70;
    u8 m_71;
    u8 m_72;
    u8 m_73;
    u32 m_74;
    u32 m_78;
    u32 m_7c;
    u32 m_80;
    void handle_cancel();
    void handle_decide();
    s32 update_list_scroll();
    void handle_grid_navigation();
    void draw_cursor(u8 *arg1);
    void draw_palette_cells(int arg1);
    virtual void run_task();
    int is_active();
};

typedef char TWindowSubCustomSelect_size[sizeof(TWindowSubCustomSelect) == 0x84 ? 1 : -1];

extern "C" {
u8 *TWindowSubCustomSelect__ct(TWindowSubCustomSelect *arg0, s32 arg1);
void *__dt__22TWindowSubCustomSelectFv(void *arg0, s16 arg1);
void render__22TWindowSubCustomSelectFv(TWindowSubCustomSelect *arg0);
}

#endif
