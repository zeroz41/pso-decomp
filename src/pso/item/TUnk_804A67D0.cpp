#include "types.h"
#include "pso/item/TUnk_804A67D0.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/TMainTask.h"

// The timer event class (0x804A0628) has no real constructor yet.
extern "C" s32 construct_timer_event__13TUnk_804A0628Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);

void TUnk_804A67D0::vfunc_60() {
    if (TObjPlayer::get_player_list() == 2) {
        scale_current_matrix(&scale.x);
    }
}

// Starts a 90-frame timer event on the effect objects (named
// madam_umbrella_start_regen before; vtable slot 57).
void TUnk_804A67D0::vfunc_57() {
    void *event;

    if (effect_objects != NULL) {
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            construct_timer_event__13TUnk_804A0628Fv(event, effect_objects, get_owner_client(), 0x5A);
        }
    }
}

void TUnk_804A67D0::update_idle() {
    s32 opened = 0;
    if (scale.x < 1.0f) {
        scale.x += 0.14f;
        if (1.0f <= scale.x) {
            scale.x = 1.0f;
            opened = 1;
        }
    }
    TItemEffOrgaFlowShot::approach_value(&scale.y, -0.04000001f, 1.0f);
    TItemEffOrgaFlowShot::approach_value(&scale.z, 0.14f, 1.0f);
    if (opened == 1) {
        play_sound_effect(0x4001AA24, &this->owner->position, 0, 0);
    }
}

void TUnk_804A67D0::update_attack() {
    TItemEffOrgaFlowShot::approach_value(&scale.x, -0.14f, 0.3f);
    TItemEffOrgaFlowShot::approach_value(&scale.y, 0.04000001f, 1.2f);
    TItemEffOrgaFlowShot::approach_value(&scale.z, -0.14f, 0.3f);
}

TUnk_804A67D0::~TUnk_804A67D0() {}

TUnk_804A67D0::TUnk_804A67D0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

u8 *TObjPlayer::create_fields_state(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A67D0(tl_05, (u8 *)arg0);
    }
    return NULL;
}
