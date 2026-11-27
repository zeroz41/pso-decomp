#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGEX_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGEX_H

#include "types.h"
#include "pso/object/container/TObjContainerBase.h"

struct QuestObjectEntry;

struct NJS_OBJECT;
struct NJS_TEXLIST;

struct TObjContainerJungEx : public TObjContainerBase {
    TObjContainerJungEx(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjContainerJungEx();
    virtual void spawn_break_effects() const;
    virtual void update_state();
    virtual void draw_model();
    virtual void apply_saved_state(QuestObjectEntry *, s32);
    static void *create(ObjectSetData *set_data);
    static NJS_OBJECT *get_model(s32 index);
    static NJS_TEXLIST *get_textures(s32 index);
    static void free_data();
    static void load_resource_instance();
};

LAYOUT_ASSERT(TObjContainerJungEx_size, sizeof(TObjContainerJungEx) == 0x368);

#endif
