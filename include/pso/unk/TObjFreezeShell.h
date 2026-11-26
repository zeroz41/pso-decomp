#ifndef PSO_UNK_TOBJFREEZESHELL_H
#define PSO_UNK_TOBJFREEZESHELL_H
#include "types.h"
#include "pso/object/base/TObjChara.h"

struct CollisionBody;

// The ice shell a freezing hit puts around a character: it grows to the
// character's size, holds while the character stays frozen, and fades out.
class TObjFreezeShell : public TObjChara {
public:
    TObjFreezeShell(TObjChara *chara, CollisionBody *body, s32 duration);
    // Puts a shell around chara (at body when given) unless items are off in this area.
    static void create(TObjChara *chara, CollisionBody *body, s32 duration);
    static void free_freeze_ice_resource();
    static void load_freeze_ice_resource();
    virtual ~TObjFreezeShell();
    void freeze_shell_grow();
    void freeze_shell_hold();
    void update_freeze_shell_timer();
    virtual void apply_knockback_from_attacker(TObjBase *, f32);
    virtual f32 receive_weapon_special_attack(TObjChara *, CollisionBody *);
    virtual f32 receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual int calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float);
    virtual s32 select_melee_contact_body(TObjChara *, f32);
    virtual void render();
    virtual void run_task();
    s32 state;            // 0 grow, 1 hold, 2 fade, 3 done
    f32 max_scale;        // the shell grows until its scale passes this
    s32 grow_frames;      // frames spent growing; a mist particle every third
    NJS_ARGB color;       // the fade colour; alpha drops each fading frame
    void *emitter;        // the cold particles around the shell
    s32 hit_count;        // the shell breaks on the third physical hit
    u16 owner_id;         // entity id of the frozen character
    Vec owner_position;   // where the character stood when it froze
};
LAYOUT_ASSERT(TObjFreezeShell_state, offsetof(TObjFreezeShell, state) == 0x334);
LAYOUT_ASSERT(TObjFreezeShell_owner_position, offsetof(TObjFreezeShell, owner_position) == 0x35C);
LAYOUT_ASSERT(TObjFreezeShell_size, sizeof(TObjFreezeShell) == 0x368);

#endif
