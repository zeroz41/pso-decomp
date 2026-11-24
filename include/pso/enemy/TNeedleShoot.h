#ifndef PSO_ENEMY_TNEEDLESHOOT_H
#define PSO_ENEMY_TNEEDLESHOOT_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include <dolphin/mtx/GeoTypes.h>

struct TechniqueContactList;
class TObjBase;

struct TNeedleShoot : public TObject {
    TNeedleShoot(TObjBase *owner, Vec *from, Vec *to);
    static const char *class_name;
    virtual ~TNeedleShoot();
    // Called when the shot meets a wall (check_wall_hit) or check_target_hit finds no contact list.
    virtual void on_wall_hit();
    virtual void queue_destruction();
    virtual void vfunc_8();
    // Called by check_target_hit with the first receivable contact.
    virtual void on_target_hit(TObjCollidable *target);
    TObjBase *owner;  // the shooter; run_task refreshes it from owner_id
    f32 range;     // the shot is destroyed once distance passes it
    f32 distance;  // speed summed each frame
    Vec prev_pos;
    u16 owner_id;  // get_entity_id(owner), 0xFFFF for none
    u8 _pad36[0x2];
    CollisionBody *contact_body;  // the body check_target_hit hit
    CollisionBody collision_body;  // collider's only body
    TObjCollidable *collider;
    Vec pos;
    u8 pad_78[0x10];
    Vec pad_88;  // set to 1, 1, 1
    Vec dir;
    s32 rotation_x;  // atan2 angles of the direction, set in the ctor
    s32 rotation_y;
    s32 rotation_z;
    f32 speed;  // pos moves by dir * speed each frame
    u32 contact_mode;
    f32 pad_b4;
    s32 active;  // 1 while flying; on_wall_hit clears it in the Gee needle
    virtual void run_task();
    virtual void render();
    void update_position();
    void check_wall_hit();
    Vec *get_shoot_data();
    void update_lifetime();
    void update_stopped();  // run_task step once active is cleared: calls queue_destruction
    // Empties technique_contact_list.
    void clear_technique_contacts();
    s32 is_hit_receivable_target(TObjCollidable *target);
    // The contact collectors check_target_hit picks by contact_mode: players the collider touches, skipping the
    // shooter, into technique_contact_list; NULL when it touches a blocking object first.
    TechniqueContactList *collect_contacts(TObjBase *src);
    TechniqueContactList *collect_technique_contacts(TObjBase *src);
    TechniqueContactList *collect_contacts_from_game_mode(TObjBase *src);
    // Collects the technique contacts of the shot (contact_mode picks the collector) and calls on_wall_hit or
    // on_target_hit.
    void check_target_hit(s32);
};

// The contacts the last check_target_hit collected.
extern TechniqueContactList technique_contact_list;

LAYOUT_ASSERT(TNeedleShoot_size, sizeof(TNeedleShoot) == 0xBC);

#endif
