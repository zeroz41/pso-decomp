#ifndef PSO_UI_CHARCREATE_TCHARAMAKING_H
#define PSO_UI_CHARCREATE_TCHARAMAKING_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

struct CharacterAppearanceFields;
struct BmlResourceDescriptor;

extern const char *charamakingmot_model_names[1];
extern const char *charamakingmot_motion_names[50];
extern BmlResourceDescriptor creation_menu_resource_descriptor;
extern const s32 player_class_texture_archive_length[19];

// Resets out-of-range appearance fields (name, section, class, parts); returns 0 if any were bad.
s32 validate_player_visual_record(void *record);

extern "C" {
void TCharaMaking__sub_8028E790(void);
}
// The section id a character name hashes to.
s32 calc_section_id_from_name(s8 *name);

struct TCharaMaking : public TObject {
    static const char *name;
    TCharaMaking(TObject *parent);
    virtual ~TCharaMaking();
    // The scene light's angles; update_light_direction turns them into its direction.
    u32 light_pitch;
    u32 light_yaw;
    static s32 query_state();
    static void setup_from_data(s32 model, CharacterAppearanceFields *appearance);
    static void clear_flag_bit0();
    static void enable_making();
    static s32 is_end();
    void update_light_direction();
    virtual void run_task();
    static void *create(void *parent, void *appearance);
    static s32 update_main_menu(saddr task);
};

LAYOUT_ASSERT(TCharaMaking_size, sizeof(TCharaMaking) == 0x24);

void request_chara_making_archives(void);
// Character-creation helpers built in TCharaMaking's unit; they act on the selected slot, not on a menu.
void copy_char_name(const char *name);
void select_char_menu();
s32 get_current_char_flag();
extern "C" {
int TAdSinglePlyChrSelectGC__sub_8028DC14(void);
int TAdSinglePlyChrSelectGC__sub_8028DC1C(void *p);
}
CharacterAppearanceFields *get_creation_visual_record(void);
void load_creation_visual_record(CharacterAppearanceFields *record);
void invalidate_creation_visual_record(void);
void reset_current_char_appearance(s32 _w0);
#endif
