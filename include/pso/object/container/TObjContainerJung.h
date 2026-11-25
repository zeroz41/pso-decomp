#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNG_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNG_H

#include "types.h"
#include "pso/player/TObjContainerCommon.h"

struct NJS_OBJECT;
struct NJS_TEXLIST;

struct TObjContainerJung : public TObjContainerCommon {
    TObjContainerJung(TObject *parent, void *set_data);
    virtual ~TObjContainerJung();
    virtual void spawn_break_effects() const;
    virtual void update_state();
    virtual void draw_model();
    virtual void apply_saved_state(s16 *, s32);
    static NJS_OBJECT *get_model_by_index(s32 index);
    static void *create(void *set_data);
    static NJS_TEXLIST *get_textures(s32);
    static void release();
    static void load_resources();
};

LAYOUT_ASSERT(TObjContainerJung_size, sizeof(TObjContainerJung) == 0x368);

#endif
