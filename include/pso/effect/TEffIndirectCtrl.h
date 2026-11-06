#ifndef PSO_MISC_TEFFINDIRECTCTRL_H
#define PSO_MISC_TEFFINDIRECTCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

// Scene-side handle of an indirect effect: its constructor registers a TEffIndirectCtrl for `kind`
// (register_indirect_effect_ctrl). Class name is the placeholder of the vtable it installs (0x804DDF04).
struct TUnk_804DDF04 : public TObject {
    TUnk_804DDF04(s32 kind, TObject *parent);
    virtual ~TUnk_804DDF04();
    u8 indirect_kind; // inferred: the kind passed to register_indirect_effect_ctrl
};

typedef char TUnk_804DDF04_size[sizeof(TUnk_804DDF04) == 0x20 ? 1 : -1];

struct TEffIndirectCtrl : public TObject {
    virtual ~TEffIndirectCtrl();
    void sub_802A955C();
    virtual void run_task();
    u32 m_1c;
    u32 m_20;
    u8 m_24;
    u8 m_25;
    u8 _pad26[0x2];
    u32 m_28;
    u32 m_2c;
    void* m_30;
    u8 _pad34[0x8];
    u32 m_3c;
    u32 m_40;
    u16 m_44;
    u16 m_46;
    static void free_buffers();
    virtual void render();
    void copy_and_flush_texture(s32 arg1);
    static void free_all();
    void update_scroll_mode();
    void update_eff_indirect();
    void eff_indirect_update_and_flush();
    u8 unk_48[0x4];
    f32 m_4c;
    u8 unk_50[0x4];
};

typedef char TEffIndirectCtrl_size[sizeof(TEffIndirectCtrl) == 0x54 ? 1 : -1];


extern "C" {
void TEffIndirectCtrl__sub_802A9548(void *p);
u8 TEffIndirectCtrl__sub_802A9554(void *p);
u16 get_indirect_tile_coord(u8 arg0, s32 arg1);
}
void load_indirect_info(void);

#endif
