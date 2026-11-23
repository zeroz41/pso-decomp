#ifndef PSO_EFFECT_TEFFINDIRECTCTRL_H
#define PSO_EFFECT_TEFFINDIRECTCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"

struct GinjaTextureInput;

// Scene-side handle of an indirect (texture warp) effect: the scene's map models and Ra Foie
// create one per warped surface; its constructor registers a TEffIndirectCtrl for `kind`.
class TEffIndirect : public TObject {
public:
    TEffIndirect(s32 kind, TObject *parent);
    virtual ~TEffIndirect();

    u8 kind;
};

LAYOUT_ASSERT(TEffIndirect_size, sizeof(TEffIndirect) == 0x20);

// One row of indinfo.dat: how a kind warps its indirect texture every frame.
struct TEffIndirectRecipe {
    u8 mode;  // 0 scroll, 1 wave, 2 wave that keeps the 0xFF texels
    s8 horizontal_amplitude;
    s8 vertical_amplitude;
    s8 variation;
    s8 horizontal_step;
    s8 vertical_step;
    u8 phase_step;
    u8 source_index;
};

// One of the eight 64x64 I8 source textures of indirect.dat.
struct TEffIndirectSource {
    u8 header[8];
    s32 texture_id;
    u8 header_tail[0x14];
    u8 pixels[0x1000];
};

LAYOUT_ASSERT(TEffIndirectRecipe_size, sizeof(TEffIndirectRecipe) == 8);
LAYOUT_ASSERT(TEffIndirectSource_size, sizeof(TEffIndirectSource) == 0x1020);

// Owns the indirect texture of one kind and rewrites its texels every frame from the source
// texture the kind's recipe names.
class TEffIndirectCtrl : public TObject {
public:
    TEffIndirectCtrl(s32 kind, TObject *parent);
    virtual ~TEffIndirectCtrl();
    virtual void run_task();
    virtual void render();
    void pause_indirect_effect();
    void resume_indirect_effect();
    u8 get_indirect_kind();
    void copy_and_flush_texture(u8 *source);
    void update_scroll_mode();
    void update_eff_indirect();
    void eff_indirect_update_and_flush();
    static void free_buffers();
    static void free_all();

    static const char *class_name;
    static TEffIndirectSource *source_buffers[8];

    u8 *pixels;  // texels of the texture below, rewritten every frame
    TEffIndirectRecipe *recipe;
    u8 source_index;
    u8 kind;
    u8 pad_26[0x2];
    GinjaTextureInput *texture_info;
    NJS_TEXLIST *texture_list;
    NJS_TEXNAME texture_entry;
    u32 horizontal_phase;
    u32 vertical_phase;
    u16 scroll_phase;
    u16 paused;
    f32 horizontal_amplitude;
    f32 vertical_amplitude;
    f32 jitter;
};

LAYOUT_ASSERT(TEffIndirectCtrl_size, sizeof(TEffIndirectCtrl) == 0x54);

// One texel of a row being scrolled: where it goes and its new value.
struct IndirectScrollTexel {
    u16 idx;
    u16 val;
};

TEffIndirectRecipe *get_indirect_recipe(s32 index);
void load_indirect_info();
void load_indirect_dat();
u32 get_indirect_tile_coord(u8 x, u8 y, s32 width);
saddr get_indirect_source_id(u8 index);
u8 *get_indirect_source_pixels(u8 index);
u32 calc_i8_tiled_texel_offset(u8 x, u8 y, u32 width);
void deform_indirect_texture_scroll(u8 *pixels, u32 scroll_x, u32 scroll_y, s32 amplitude, u32 phase);
void deform_indirect_texture_wave(u8 *pixels, s32 amplitude_x, s32 amplitude_y, s32 phase_x, s32 phase_y,
                                  u8 phase_step);
void update_indirect_texture_wave(u8 *pixels, s32 amplitude_x, s32 amplitude_y, s32 phase_x, s32 phase_y,
                                  u8 phase_step);
void setup_indirect_tev_alternate(TEffIndirectCtrl *ctrl, s32 unused, s32 sampler, s32 scale);
void setup_indirect_tev_ordinary(TEffIndirectCtrl *ctrl, s32 sampler, s32 scale, s32 second);
void reset_indirect_effect_ctrl_table();
void clear_indirect_effect_ctrl_table();
s8 find_indirect_effect_ctrl(s32 kind);
void register_indirect_effect_ctrl(s32 kind);
void enable_indirect_tev(TEffIndirect *effect, s32 sampler, s32 scale, s32 mode);
void disable_indirect_tev(TEffIndirect *effect, s32 direct);

#endif
