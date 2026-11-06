#include "types.h"
#include "pso/weapon/TUnk_804A08B8.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TMainTask.h"

// The timer event class has no real constructor yet.
extern "C" s32 init_item_timer_event__13TUnk_804A0648Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);

void TUnk_804A08B8::emit_marker_effects() {
    WeaponVector pos;

    if (is_mode_two_and_ready() != 0) {
        get_joint_position(2, &pos);
        spawn_particle_effect(&pos, 0x1BE);
    }
}

// Starts a 90-frame timer event on the effect objects (named
// marina_bag_start_regen before; vtable slot 57).
void TUnk_804A08B8::vfunc_57() {
    void *event;

    if (effect_objects != NULL) {
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            init_item_timer_event__13TUnk_804A0648Fv(event, effect_objects, get_owner_client(), 0x5A);
        }
    }
}

TUnk_804A08B8::~TUnk_804A08B8() {}

TUnk_804A08B8::TUnk_804A08B8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

u8 *TObjPlayer::create_vtable_804A08B8(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A08B8(tl_05, arg0);
    }
    return NULL;
}
