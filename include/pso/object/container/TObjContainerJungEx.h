#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGEX_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGEX_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct NJS_OBJECT;
struct GinjaTextureList;

struct TObjContainerJungEx : public TUnk_804B6C24 {
    TObjContainerJungEx(TObject *parent, void *set_data);
    virtual ~TObjContainerJungEx();
    virtual void vfunc_79() const;
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *arg0);
    static NJS_OBJECT *get_model(s32 arg0);
    static GinjaTextureList *get_textures(s32 index);
    static void free_data();
    static void load_resource_instance();
};

typedef char TObjContainerJungEx_size[sizeof(TObjContainerJungEx) == 0x368 ? 1 : -1];

#endif
