#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTMODEL_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTMODEL_H
#include "pso/weapon/shoot/TItemShoot.h"
#include "types.h"

struct NJS_TEXLIST;
struct NJS_OBJECT;

class TItemShootModel : public TItemShoot {
public:
 static const char *class_name;
 NJS_OBJECT *model;
 NJS_TEXLIST *texture_list;
 s32   ang;
 s32   pad_64;
 s32   pad_68;

public:
    TItemShootModel(void* owner, const Vec* pos, const Vec* dir, f32 life);
    static TItemShoot *create_shoot_model(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
    // render is declared first: it is the key function that puts the vtable
    // in TItemShoot.cpp (the destructor's kept copy is in another TU).
    virtual void render();
    virtual ~TItemShootModel();
    void set_render_model(NJS_OBJECT *model, NJS_TEXLIST *texture_list);
    s32 is_owner_alive();
};

#endif
