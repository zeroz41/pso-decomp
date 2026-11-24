#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
// One TU: TObjFogCollision, TObjFogCollisionSwitch, TObjFogCollisionPoison and the per-client
// TObjFogCollision_Manager. Built with -inline deferred, so functions are written in reverse
// address order (code is emitted last function first).
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/math/FloatRounding.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/map/FloorArea.h"
#include "pso/object/collision/TObjFogCollision.h"
#include "pso/object/collision/TObjFogCollision_Manager.h"
#include "pso/object/collision/TObjFogCollisionSwitch.h"
#include "pso/object/collision/TObjFogCollisionPoison.h"
#include "pso/render/TFogCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D853C.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"


const char *TObjFogCollision__name = "TObjFogCollision";
const char *TObjFogCollisionSwitch__name = "TObjFogCollisionSwitch";
const char *TObjFogCollisionPoison__name = "TObjFogCollisionPoison";

struct VBase_801537CC { char pad[0x18]; };

struct VObj_801537CC : VBase_801537CC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
};

struct O_801538D4 { u8 pad[0x8C]; s32 v; };

struct O_80153D98 { u8 pad[0x88]; s32 mode; };


extern "C" {


void record_fog_collision_hit(s32 arg0, s32 arg1, s32 arg2);
u8 is_current_floor_switch_set(u16);

s32 post_translate_matrix(void *);
extern s32 saved_model_draw_color[];
extern s32 model_material_color[];
extern saddr debug_cylinder_object;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

f32 horizontal_distance_squared(void *, s32);
s32 is_split_screen();

// Function definitions in reverse address order (-inline deferred emits them reversed).
void *TObjFogCollision::create(void *set) {
    void *o = (void *)new TObjFogCollision(tl_05, set);
    return o;
}

}
TObjFogCollision::TObjFogCollision(TObject *parent, void *set) : TObjBase(parent) {
    ((TObject *)this)->m_name = TObjFogCollision__name;
    ((TObjFogCollision *)(((u8 *)this)))->apply_object_set_data(set);
    this->m_90 = 0;
    this->m_94 = 0;
    ((TObject *)(((u8 *)this)))->disallow_rendering();
}

TObjFogCollision::~TObjFogCollision() {

}

int TObjFogCollision::debug_text_enabled() { return 0; }
int TObjFogCollision::debug_draw_enabled() { return 0; }



void TObjFogCollision::vfunc_13(s32) {
    s32 temp_r0;
    temp_r0 = this->set_params[0];
    if (temp_r0 < 0) {
        this->set_params[0] = 0;
        return;
    }
    if (temp_r0 >= 0x80) {
        this->set_params[0] = 0x7F;
    }
}

s32 TObjFogCollision::check_collision(u16 client) {
    f32 x;
    f32 temp_f1;
    f32 temp_f31;
    s32 player;

    player = (saddr)get_player_by_client_id(client);
    if (player != 0) {
        x = this->scale.x;
        temp_f31 = x * x;
        temp_f1 = horizontal_distance_squared((u8 *)&this->position, player + 0x38);
        if (temp_f31 > temp_f1) {
            return 1;
        }
        if ((2.5e+03f + temp_f31) < temp_f1) {
            this->m_94 = 0x3C;
        }
        goto block_5;
    }
block_5:
    return 0;
}

void TObjFogCollision::run_task() {
    u16 i;
    if (debug_text_enabled() == 0 && debug_draw_enabled() == 0) {
        for (i = 0; i != 4; i++) {
            if (check_collision(i) != 0) {
                record_fog_collision_hit(i, this->set_params[0], this->set_params[1] == 0);
            }
        }
    }
}

void TObjFogCollision::vfunc_14() {
    O_80153D98 *arg0 = (O_80153D98 *)this;
    debug_printf_at(0x13001C, "Rad");
    debug_printf_at(0x130020, "Param No");
    if (arg0->mode == 0) {
        debug_printf_at(0x130021, "LINK : ON");
    } else {
        debug_printf_at(0x130021, "LINK : OFF");
    }
}

void TObjFogCollision::render() {
    if (debug_text_enabled() != 0) {
        this->vfunc_14();
    }
    if (debug_draw_enabled() != 0) {
        this->draw_volume();
    }
}

void TObjFogCollision::draw_volume() {
    f32 s;
    if (this->update_object_view_visibility(1.5e+02f, this->scale.x) != 0) {
        NJS_ARGB c0 = {0.7f, 0.5f, 0.5f, 0.5f};
        NJS_ARGB c3 = {0.2f, 0.5f, 0.5f, 0.5f};
        NJS_ARGB cd = {0.5f, 0.5f, 1.0f, 1.0f};
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(0xFF00, 0x800);
        switch (this->m_90) {
        case 0:
            set_constant_material(&c0);
            break;
        case 1:
        case 2:
        case 4:
        case 5:
            set_constant_material(&cd);
            break;
        case 3:
            set_constant_material(&c3);
            break;
        }
        push_matrix();
        s = 0.5f * this->scale.x;
        post_translate_matrix((u8 *)&this->position);
        scale_matrix(0, s, 3.0f, s);
        draw_chunk_object((void *)debug_cylinder_object);
        pop_matrix();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
    }
}

void *TObjFogCollisionSwitch::create(void *set) {
    return new TObjFogCollisionSwitch(tl_05, set);
}

TObjFogCollisionSwitch::TObjFogCollisionSwitch(TObject *parent, void *set) : TObjFogCollision(parent, set) {
    m_name = TObjFogCollisionSwitch__name;
}


TObjFogCollisionSwitch::~TObjFogCollisionSwitch() {

}


void TObjFogCollisionSwitch::vfunc_13(s32 arg) {
    s32 temp_r0;

    TObjFogCollision::vfunc_13(arg);
    temp_r0 = this->set_params[2];
    if (temp_r0 < 0) {
        this->set_params[2] = 0;
        return;
    }
    if (temp_r0 > 0xFF) {
        this->set_params[2] = 0xFF;
    }
}

// inferred: vfunc_14 prints "SwitchMode:ON->ON" when this is nonzero, "ON->OFF" otherwise.
s32 TObjFogCollisionSwitch::get_switch_mode() {
    return this->scale.z >= 1.0f;
}

void TObjFogCollisionSwitch::run_task() {
    s32 st;
    u16 i;
    if (debug_text_enabled() == 0 && debug_draw_enabled() == 0) {
        st = get_switch_mode();
        if (st == is_current_floor_switch_set(set_params[2])) {
            for (i = 0; i != 4; i++) {
                if (check_collision(i) != 0) {
                    record_fog_collision_hit(i, set_params[0], set_params[1] == 0);
                }
            }
        }
    }
}

void TObjFogCollisionSwitch::vfunc_14() {
    O_801538D4 *arg0 = (O_801538D4 *)this;
    ((TObjFogCollision *)arg0)->TObjFogCollision::vfunc_14();
    if (((TObjFogCollisionSwitch *)arg0)->get_switch_mode() != 0) {
        debug_printf_at(0x13001E, "SwitchMode:ON->ON");
    } else {
        debug_printf_at(0x13001E, "SwitchMode:ON->OFF");
    }
    debug_printf_at(0x130022, "SwitchID:%3d", this->set_params[2]);
}

void *TObjFogCollisionPoison::create(void *set) {
    return new TObjFogCollisionPoison(tl_05, set);
}

TObjFogCollisionPoison::TObjFogCollisionPoison(TObject *arg1, void *set) : TObjFogCollisionSwitch(arg1, set) {
    u16 i;
    TObject *parent = this;
    m_name = TObjFogCollisionPoison__name;
    ((VObj_801537CC *)parent)->m11();
    if (is_split_screen() != 0) {
        for (i = 0; i != 4; i++) {
            new TObjFogCollisionPoison_Ticker((TObject *)parent, i);
        }
    } else {
        new TObjFogCollisionPoison_Ticker((TObject *)parent, local_client_id);
    }
}


TObjFogCollisionPoison::~TObjFogCollisionPoison() {

}


void TObjFogCollisionPoison::vfunc_13(s32) {
    f32 var_f2;

    *(s32 *)&this->m_98 = (s32) floor_to_float(this->scale.y);
    switch ((s32) game_difficulty_selection) {
    default:
    case 0:
        var_f2 = 1.0f;
        break;
    case 1:
        var_f2 = 2.0f;
        break;
    case 2:
        var_f2 = 3.0f;
        break;
    case 3:
        var_f2 = 6.0f;
        break;
    }
    *(s32 *)&this->m_98 = (s32) ((f32) *(s32 *)&this->m_98 * var_f2);
}

void TObjFogCollisionPoison::run_task() {
    if (debug_text_enabled()) {
        return;
    }
    if (debug_draw_enabled()) {
        return;
    }
}


// ---- poison area sounds, damage and the per-client fog managers ----

// inferred: name pointer of TObjFogCollision_Manager (its string is the class name; the
// manager ctor stores it in m_name like the other three X__name pointers).
const char *TObjFogCollision_Manager__name = "TObjFogCollision_Manager";

TObjFogCollision_Manager *TObjFogCollisionPoison__instances[12];

extern "C" {
s32 send_6x2F_change_player_hp(s32, u16, s16);
}

void TObjFogCollisionPoison::play_poison_sound() {
    switch (get_current_floor_area()) {
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004C115, &position, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004C123, &position, 0, 0);
        break;
    default:
        play_sound_effect(0x4004C11B, &position, 0, 0);
        break;
    }
}

void TObjFogCollisionPoison::play_poison_persistent_sound() {
    switch (get_current_floor_area()) {
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_persistent_sound(0x4004BC16, this, &position, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_persistent_sound(0x4004BC24, this, &position, 0, 0);
        break;
    default:
        play_persistent_sound(0x4004BC1C, this, &position, 0, 0);
        break;
    }
}

void TObjFogCollisionPoison::record_poison_hit(u16 client) {
    record_fog_collision_hit(client, this->set_params[0], (s32)((int) ((u8) (this->set_params[1] == 0))));
}

void TObjFogCollisionPoison::apply_poison_damage(s32 client) {
    saddr p;
    s16 v;
    p = (saddr)get_player_by_client_id(client & 0xFFFF);
    if (((TObjEneDD *)p)->is_valid_target() != 0) {
        v = ((TObjChara *)p)->get_actor_hp() - this->m_98;
        if (v < 0) {
            v = 0;
        }
        send_6x2F_change_player_hp(0xFFFF, ((TObjBase *)(p))->get_entity_id(), v);
    }
}

s32 TObjFogCollisionPoison::check_switch() {
    s32 switch_mode;

    switch_mode = get_switch_mode();
    return (u8)((u8) (switch_mode == is_current_floor_switch_set((u16) this->set_params[2])));
}

void TObjFogCollisionPoison::vfunc_14() {
    TObjFogCollisionSwitch::vfunc_14();
    debug_printf_at(0x13001D, "Poison Power");
}

void TObjFogCollisionPoison::clear_state_array() {
    s32 i;
    for (i = 0; i < 12; i++) {
        TObjFogCollisionPoison__instances[i] = 0;
    }
}

void TObjFogCollisionPoison__sub_801533BC(void) {  }

void TObjFogCollisionPoison::create() {
    s32 i;

    if (is_split_screen() == 0) {
        new TObjFogCollision_Manager(tl_05, local_client_id);
    } else {
        for (i = 0; i != 4; i++) {
            new TObjFogCollision_Manager(tl_05, i);
        }
    }
}

// One manager per client: registers itself in TObjFogCollisionPoison__instances[index].
TObjFogCollision_Manager::TObjFogCollision_Manager(TObject *parent, s32 index) : TObject(parent) {
    m_name = TObjFogCollision_Manager__name;
    player = index;
    TObjFogCollisionPoison__instances[player] = this;
    hit_count = 0;
    fog_level = 0;
    fog_link = 1;
    cleared = 1;
}

TObjFogCollision_Manager::~TObjFogCollision_Manager() {
    TObjFogCollisionPoison__instances[player] = 0;
}

void TObjFogCollision_Manager::record_hit(s32 level, s32 link) {
    if (fog_level <= level) {
        hit_count++;
        fog_level = level;
        fog_link = link;
    }
}

void record_fog_collision_hit(s32 arg0, s32 level, s32 link) {
    TObjFogCollision_Manager *manager;
    if ((arg0 >= 0) && (arg0 < 0xC)) {
        manager = TObjFogCollisionPoison__instances[arg0];
        if (manager != 0) {
            manager->record_hit(level, link);
        }
    }
}

void TObjFogCollision_Manager::run_task() {
    s32 var_r4;
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        switch (cleared) {
        case 0:
            if (hit_count > 0) {
                var_r4 = this->fog_level;
                if (var_r4 >= 0x1000) {
                    var_r4 -= 0x1000;
                }
                if (var_r4 < 0) {
                    var_r4 = 0;
                } else if (var_r4 >= 0x80) {
                    var_r4 = 0x7F;
                }
                if (fog_link != 0) {
                    TFogCtrl::select_fog_for_viewport(this->player, var_r4, 0);
                } else {
                    TFogCtrl::select_fog_for_viewport(this->player, var_r4, 1);
                }
                hit_count = 0;
            } else {
                cleared = 1;
                if (fog_link != 0) {
                    TFogCtrl::restore_fog_for_player(this->player, 0);
                } else {
                    TFogCtrl::restore_fog_for_player(this->player, 1);
                }
            }
            break;
        case 1:
            if (hit_count > 0) {
                hit_count = 0;
                cleared = 0;
            }
            break;
        }
        this->fog_level = 0;
    }
}

// Per-client poison ticker under a TObjFogCollisionPoison (its constructor creates one
// per client; callers pass the client as u16).
TObjFogCollisionPoison_Ticker::TObjFogCollisionPoison_Ticker(TObject *parent, u16 client) : TObject(parent) {
    this->client = client;
    damage_interval = 0x96;
    damage_timer = 0;
    contact_ticks = 0;
}

TObjFogCollisionPoison_Ticker::~TObjFogCollisionPoison_Ticker() {

}

void TObjFogCollisionPoison_Ticker::run_task() {
    TObjFogCollisionPoison *poison;

    poison = (TObjFogCollisionPoison *)m_up;
    if (poison->check_switch() != 0) {
        if (poison->check_collision(client) != 0) {
            poison->record_poison_hit(client);
            damage_timer++;
            if (damage_timer >= damage_interval) {
                poison->apply_poison_damage(client);
                damage_timer = 0;
                damage_interval = 0x1E;
            }
            contact_ticks++;
        } else {
            damage_interval = 0x96;
            contact_ticks = 0;
        }
        if (contact_ticks == 1) {
            poison->play_poison_sound();
            return;
        }
        if (contact_ticks > 0x3C) {
            poison->play_poison_persistent_sound();
        }
    }
}
