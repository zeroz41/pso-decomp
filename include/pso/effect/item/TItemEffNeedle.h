#ifndef PSO_EFFECT_ITEM_TITEMEFFNEEDLE_H
#define PSO_EFFECT_ITEM_TITEMEFFNEEDLE_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItem.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>

struct TItemEquipBase;

// A weapon's needle left stuck where it hit: the weapon's model drawn at a
// point, fading out over 30 frames. It lives while the weapon that fired it
// stays equipped.
class TItemEffNeedleBase : public TObject {
public:
    TItemEffNeedleBase(TObject *parent, TItem *item);
    virtual ~TItemEffNeedleBase();
    virtual void run_task();
    virtual void render();
    // Moves the needle with what it sticks in; 0 when that is gone (the
    // needle is then destroyed) and the fade-out waits.
    virtual int update_attachment();

    NJS_ARGB material_color;  // the constant material; alpha fades to -1
    s32 item_id;              // the weapon that fired it
    Vec position;
    NJS_OBJECT *model;
    s32 texlist;
    s32 rotation[3];
};

// A needle stuck in a point of the world (a wall).
class TItemEffNeedlePos : public TItemEffNeedleBase {
public:
    // Jitters pos by up to one unit per axis and turns the needle along dir.
    TItemEffNeedlePos(TObject *parent, TItem *item, const Vec *pos, Vec *dir);
};

// A needle stuck in one collision body of an actor; it follows the body and
// the actor's y rotation.
class TItemEffNeedle : public TItemEffNeedleBase {
public:
    TItemEffNeedle(TObject *parent, TItem *item, u16 target_id, s32 body_index);
    virtual ~TItemEffNeedle();
    virtual int update_attachment();

    u16 target_id;
    s32 body_index;
    s32 rotation_offset[3];  // rotation, its y relative to the target's
};

typedef char TItemEffNeedleBaseSize[(sizeof(TItemEffNeedleBase) == 0x50) ? 1 : -1];
typedef char TItemEffNeedleSize[(sizeof(TItemEffNeedle) == 0x64) ? 1 : -1];

// Weapon hit callbacks that leave needles.
extern "C" {
void create_needle_pos_effect(s32 item_id, const Vec *pos, Vec *dir);
void spawn_needle_wall_impact(TObject *parent, TItemEquipBase *weapon, const Vec *from, Vec *hit);
void create_needle_effect(s32 item_id, ActorBodyHit *hit);
void spawn_target_needle(TObject *parent, TItemEquipBase *weapon, u16 target_id, s32 body_index);
}

#endif
