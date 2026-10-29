#ifndef PSO_OBJECT_TOBJSEABEDSUISOBRAKABLE_H
#define PSO_OBJECT_TOBJSEABEDSUISOBRAKABLE_H

#include "types.h"
#include "pso/misc/TORockCaveBrakable.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/BmlResourceDescriptor.h"

struct BmlResource;
struct AnimationMotion;

// The seabed's breakable tank (object 0x224): one of three models, broken
// into TObjSuisoChip debris. Its statics hold the seabed tank resources
// that TObjSeabedSuiso_CH draws from too.
struct TObjSeabedSuisoBrakable : public TORockCaveBrakable {
    TObjSeabedSuisoBrakable(void *set_data);
    virtual ~TObjSeabedSuisoBrakable();
    virtual void render();
    virtual void vfunc_14();
    virtual void vfunc_16();
    virtual void spawn_break_effect();
    virtual void vfunc_19();
    void init_model();
    s32 kind;  // abs(set_params[1]) clamped to 2: the model and chip set

    static void *create_instance(void *set_data);
    static void free_static_resources();
    static void load_resources();
    static s32 get_texture_entry(int index);
    static NJS_OBJECT *get_model12_node(int index);
    static NJS_OBJECT *get_model13_node(int index);
    static void notify_break(NJS_OBJECT *node);
    static AnimationMotion *get_bml_motion_by_index(s32 index);
    static s32 get_texlist(int index);  // the one texture list, whatever the index
    static void *get_model(int index);

    static const char *class_name;
    static BmlResource *bml_resource;
    static u32 texture_list;
    static s32 texture_entries[5];       // the scrolled textures, by name
    static NJS_OBJECT *model12_nodes[3];
    static NJS_OBJECT *model13_nodes[3];
    static s32 last_uv_scroll_tick;
};

typedef char TObjSeabedSuisoBrakable_size[sizeof(TObjSeabedSuisoBrakable) == 0xC0 ? 1 : -1];

// The textures whose UVs the tanks scroll, by name, in the lower and the
// upper seabed's texture archive.
struct SeabedSuisoTextureNames {
    const char *name[5];
};

// The tank archives and texture files of the upper and the lower seabed.
extern BmlResourceDescriptor bm_obj_seabed_suiso_resource_descriptor;
extern BmlResourceDescriptor bm_obj_seabed_suiso_2_resource_descriptor;
extern const SeabedSuisoTextureNames seabed_suiso_texture_names;
extern const SeabedSuisoTextureNames seabed_suiso_2_texture_names;
extern const char seabed_suiso_gvm_name[];
extern const char seabed_suiso_2_gvm_name[];

#endif
