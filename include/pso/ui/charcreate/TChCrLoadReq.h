#ifndef PSO_UI_CHARCREATE_TCHCRLOADREQ_H
#define PSO_UI_CHARCREATE_TCHCRLOADREQ_H
#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"

struct CharacterAppearanceFields;
struct CharacterClassAppearance;
struct NJS_TEXLIST;
struct NJS_OBJECT;
struct TObjPlayer;
class TChCrLoadAfs;

struct CharacterPreviewLoadArgs {
    CharacterAppearanceFields *appearance;
    s32 *completion_flags;
    s32 load_slot;
    s32 *body_model;
    s32 *part_models;
    NJS_TEXLIST *body_textures;
    NJS_TEXLIST *other_textures;
    NJS_TEXLIST *head_textures;

    void copy_from(const CharacterPreviewLoadArgs *source);
};

LAYOUT_ASSERT(CharacterPreviewLoadArgs_size, sizeof(CharacterPreviewLoadArgs) == 0x20);

class TChCrLoadReq : public TObject {
public:
    static const char *name;
    TChCrLoadReq(TObject *parent, const CharacterPreviewLoadArgs *args);
    TChCrLoadReq(TObjPlayer *player);
    virtual ~TChCrLoadReq();
    void release_load_slot();
    s32 try_claim_load_slot();
    void request_model_loads();
    void request_texture_loads();
    s32 all_preview_loads_complete();
    void load_preview_models();
    void start_preview_loads();
    s32 are_preview_load_flags_clear();
public:
    u8 pad_1C[0x38 - 0x1C];
    CharacterPreviewLoadArgs inputs;
    s32 *head_model_slot;  // the slot of part_models that receives the head model
    CharacterClassAppearance *class_appearance;
    s32 state;
    s32 timer;
    saddr calc_preview_last_index(s32 display_index, s32 region_index);
    saddr calc_preview_offset(s32 display_index, s32 head, s32 region_index);
    virtual void run_task();
    void close_and_destroy();
    void try_advance_state();
    void update_load_progress();
public:
    void reset_request();
    static void *create(void *parent);
    s32 sample_indices[3];  // the proportion samples the preview blends
    TChCrLoadAfs *sample_loads[6];  // 0-2 head samples, 3-5 body samples
    s32 holds_load_slot;
};
TChCrLoadReq *create_ch_cr_load_req(TObject *parent, const CharacterPreviewLoadArgs *args);
s32 is_node_tree_valid(NJS_OBJECT *object);
s32 is_load_slot_free();

extern s32 chr_select_load_slot_count;
extern s32 chr_select_preview_stride_table[19];
extern s32 chr_select_preview_base_offset_table[19];

LAYOUT_ASSERT(TChCrLoadReq_inputs_offset, offsetof(TChCrLoadReq, inputs) == 0x38);
LAYOUT_ASSERT(TChCrLoadReq_state_offset, (offsetof(TChCrLoadReq,state)==0x60));
LAYOUT_ASSERT(TChCrLoadReq_timer_offset, (offsetof(TChCrLoadReq,timer)==0x64));
LAYOUT_ASSERT(TChCrLoadReq_size, sizeof(TChCrLoadReq) == 0x90);
#endif
