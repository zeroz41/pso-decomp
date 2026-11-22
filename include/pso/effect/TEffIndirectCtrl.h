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

LAYOUT_ASSERT(TUnk_804DDF04_size, sizeof(TUnk_804DDF04) == 0x20);

struct TEffIndirectRecipe {
    u8 mode;
    s8 horizontal_amplitude;
    s8 vertical_amplitude;
    s8 variation;
    s8 horizontal_step;
    s8 vertical_step;
    u8 phase_step;
    u8 source_index;
};

struct TEffIndirectSource {
    u8 header[8];
    s32 texture_id;
    u8 header_tail[0x14];
    u8 pixels[0x1000];
};

LAYOUT_ASSERT(TEffIndirectRecipe_size, sizeof(TEffIndirectRecipe) == 8);
LAYOUT_ASSERT(TEffIndirectSource_size, sizeof(TEffIndirectSource) == 0x1020);

struct TEffIndirectCtrl : public TObject {
    virtual ~TEffIndirectCtrl();
    void pause_indirect_effect();
    virtual void run_task();
    u8 *m_1c;
    TEffIndirectRecipe *m_20;
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
    void copy_and_flush_texture(u8 *source);
    static void free_all();
    void update_scroll_mode();
    void update_eff_indirect();
    void eff_indirect_update_and_flush();
    u8 unk_48[0x4];
    f32 m_4c;
    u8 unk_50[0x4];
};

LAYOUT_ASSERT(TEffIndirectCtrl_size, sizeof(TEffIndirectCtrl) == 0x54);


extern "C" {
void TEffIndirectCtrl__resume_indirect_effect(TEffIndirectCtrl *ctrl);
u8 TEffIndirectCtrl__get_indirect_kind(TEffIndirectCtrl *ctrl);
}
u32 get_indirect_tile_coord(u8 x, u8 y, s32 width);
void enable_indirect_tev(TUnk_804DDF04 *effect, s32 sampler, s32 scale, s32 mode);
void disable_indirect_tev(TUnk_804DDF04 *effect, s32 direct);
void load_indirect_info(void);

#endif
