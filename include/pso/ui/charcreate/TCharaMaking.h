#ifndef PSO_UI_CHARCREATE_TCHARAMAKING_H
#define PSO_UI_CHARCREATE_TCHARAMAKING_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct CharacterAppearanceFields;
struct BmlResourceDescriptor;

extern const char *charamakingmot_model_names[1];
extern const char *charamakingmot_motion_names[50];
extern BmlResourceDescriptor creation_menu_resource_descriptor;
extern const char *TCharaMaking__name;
extern const s32 lbl_8045122C[19];

struct TCharaMaking : public TObject {
    virtual ~TCharaMaking();
    u32 m_1c;
    u32 m_20;
    static s32 query_state();
    static void setup_from_data(s32 model, CharacterAppearanceFields *appearance);
    void free_loaded_buffers();
    void update_body_parts();
    static void clear_flag_bit0();
    static void enable_making();
    static s32 is_end();
    s32 get_display_index();
    void update_light_direction();
    virtual void run_task();
    static void *create(void *arg0, void *arg1);
    static s32 update_main_menu(s32 arg0);
};

typedef char TCharaMaking_size[sizeof(TCharaMaking) == 0x24 ? 1 : -1];
#endif
