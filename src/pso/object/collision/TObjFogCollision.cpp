#define TOBJECT_OUT_OF_LINE_HELPERS
// One TU: TObjFogCollision, TObjFogCollisionSwitch, TObjFogCollisionPoison and the per-client
// TObjFogCollision_Manager. Built with -inline deferred, so functions are written in reverse
// address order (code is emitted last function first).
#include "types.h"
#include "pso/math/FloatRounding.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/object/TUnk_804AF7B0.h"
#include "pso/map/FloorArea.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
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
#include "pso/unk/text_80153674.h"
#include "pso/unk/text_80153A7C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"


const char *TObjFogCollision__name = "TObjFogCollision";
const char *TObjFogCollisionSwitch__name = "TObjFogCollisionSwitch";
const char *TObjFogCollisionPoison__name = "TObjFogCollisionPoison";

struct RecoveredGlobal_80153FD0___vt__16TObjFogCollision {
    s32 value;
    u8 remaining[0x3C];
};

struct VBase_801537CC { char pad[0x18]; };

struct VObj_801537CC : VBase_801537CC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
};

struct O_801538D4 { u8 pad[0x8C]; s32 v; };

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct O_80153D98 { u8 pad[0x88]; s32 mode; };

extern TObject *tl_05;

extern "C" {

s32 __ct__8TObjBaseFP7TObject(void *);
extern s32 __vt__16TObjFogCollision[];
u8 *TObjFogCollision__ct(u8 *fog_collision, void *parent, void *set);
void *TObjFogCollision__create(void *set);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern s32 __vt__22TObjFogCollisionPoison[];
extern s32 __vt__22TObjFogCollisionSwitch[];
extern s32 local_client_id;
s32 vfunc_13__16TObjFogCollisionFl();
void record_fog_collision_hit(s32 arg0, s32 arg1, s32 arg2);
u8 is_current_floor_switch_set(u16);

extern s32 game_difficulty_selection;

s32 scale_matrix(int, f32, f32, f32);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern s32 saved_model_draw_color[];
extern s32 model_material_color[];
extern s32 lbl_805D28BC;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

f32 horizontal_distance_squared(void *, s32);
s32 get_player_by_client_id(u16);
s32 is_split_screen();

}

// Function definitions in reverse address order (-inline deferred emits them reversed).

extern "C" {

void *TObjFogCollision__create(void *set) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TObjFogCollision__ct((u8 *)o, tl_05, set);
    }
    return o;
}

typedef char RecoveredGlobal_80153FD0___vt__16TObjFogCollision_size[sizeof(RecoveredGlobal_80153FD0___vt__16TObjFogCollision) == 0x40 ? 1 : -1];
u8 *TObjFogCollision__ct(u8 *fog_collision, void *parent, void *set) {
    __ct__8TObjBaseFP7TObject(fog_collision);
    *(s32 **)((s8 *)fog_collision + 0x18) = &(*(RecoveredGlobal_80153FD0___vt__16TObjFogCollision *)&__vt__16TObjFogCollision).value;
    ((TObject *)fog_collision)->m_name = TObjFogCollision__name;
    ((TObjFogCollision *)(fog_collision))->apply_object_set_data(set);
    ((TObjFogCollision *)fog_collision)->m_90 = 0;
    ((TObjFogCollision *)fog_collision)->m_94 = 0;
    ((TObject *)(fog_collision))->disallow_rendering();
    return fog_collision;
}

}

TObjFogCollision::~TObjFogCollision() {

}

extern "C" {

int TObjFogCollision__sub_80153F70(void *self) { return 0; }
int TObjFogCollision__sub_80153F68(void *self) { return 0; }

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

s32 TObjFogCollision::check_collision(u16 arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f31;
    s32 player;

    player = get_player_by_client_id((u16)arg1);
    if (player != 0) {
        temp_f0 = this->scale.x;
        temp_f31 = temp_f0 * temp_f0;
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
    if (TObjFogCollision__sub_80153F70(this) == 0 && TObjFogCollision__sub_80153F68(this) == 0) {
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
    u8 *arg0 = (u8 *)this;
    if (((s32)TObjFogCollision__sub_80153F70(this)) != 0) {
        this->vfunc_14();
    }
    if (((s32)TObjFogCollision__sub_80153F68(arg0)) != 0) {
        this->draw_volume();
    }
}

void TObjFogCollision::draw_volume() {
    u8 *arg0 = (u8 *)this;
    f32 s;
    if (((VObj_18_26a62c *)(arg0))->m8(1.5e+02f, this->scale.x) != 0) {
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
        draw_chunk_object((void *)lbl_805D28BC);
        pop_matrix();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
    }
}

void *TObjFogCollisionSwitch__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TObjFogCollisionSwitch__ct(o, tl_05, arg0);
    }
    return o;
}

void *TObjFogCollisionSwitch__ct(void *fog_collision_switch, void *parent, void *set) {
    TObjFogCollision__ct((u8 *)fog_collision_switch, parent, set);
    *(s32 **)((s8 *)fog_collision_switch + 0x18) = __vt__22TObjFogCollisionSwitch;
    ((TObjFogCollisionSwitch *)fog_collision_switch)->m_name = TObjFogCollisionSwitch__name;
    return fog_collision_switch;
}

}

TObjFogCollisionSwitch::~TObjFogCollisionSwitch() {

}

extern "C" {

void TObjFogCollisionSwitch::vfunc_13(s32) {
    s32 temp_r0;

    vfunc_13__16TObjFogCollisionFl();
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

void run_task__22TObjFogCollisionSwitchFv(TObjFogCollisionSwitch *arg0) {
    s32 st;
    u16 i;
    if (TObjFogCollision__sub_80153F70(arg0) == 0 && TObjFogCollision__sub_80153F68(arg0) == 0) {
        st = arg0->get_switch_mode();
        if (st == is_current_floor_switch_set(arg0->set_params[2])) {
            for (i = 0; i != 4; i++) {
                if (((TObjFogCollision *)arg0)->check_collision(i) != 0) {
                    record_fog_collision_hit(i, arg0->set_params[0], *(s32 *)((s8 *)arg0 + 0x88) == 0);
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

void *create__22TObjFogCollisionPoisonFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0x9C);
    if (o != NULL) {
        o = TObjFogCollisionPoison__ct(o, tl_05, arg0);
    }
    return o;
}

void *TObjFogCollisionPoison__ct(void *arg0, void *arg1, void *arg2) {
    u16 i;
    TObjFogCollisionSwitch__ct(arg0, arg1, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TObjFogCollisionPoison;
    ((TObject *)arg0)->m_name = TObjFogCollisionPoison__name;
    ((VObj_801537CC *)arg0)->m11();
    if (is_split_screen() != 0) {
        for (i = 0; i != 4; i++) {
            new TUnk_804AF7B0((TObject *)arg0, i);
        }
    } else {
        new TUnk_804AF7B0((TObject *)arg0, local_client_id);
    }
    return arg0;
}

}

TObjFogCollisionPoison::~TObjFogCollisionPoison() {

}

extern "C" {

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

void run_task__22TObjFogCollisionPoisonFv(void *self) {
    if (TObjFogCollision__sub_80153F70(self)) {
        return;
    }
    if (TObjFogCollision__sub_80153F68(self)) {
        return;
    }
}

}

// ---- poison area sounds, damage and the per-client fog managers ----

// inferred: name pointer of TObjFogCollision_Manager (its string is the class name; the
// manager ctor stores it in m_name like the other three X__name pointers).
const char *TObjFogCollision_Manager__name = "TObjFogCollision_Manager";

TObjFogCollision_Manager *TObjFogCollisionPoison__instances[12];

extern "C" {
s16 get_actor_hp(s32);
s32 get_entity_id(s32);
s32 is_valid_target__9TObjEneDDFv(s32);
s32 send_6x2F_change_player_hp(s32, s32, s16);
s32 play_sound_effect(s32, s32, s32, s32);
}

void TObjFogCollisionPoison__sub_801535D0(s32 arg0) {
    switch (get_current_floor_area()) {
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004C115, arg0 + 0x38, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004C123, arg0 + 0x38, 0, 0);
        break;
    default:
        play_sound_effect(0x4004C11B, arg0 + 0x38, 0, 0);
        break;
    }
}

void TObjFogCollisionPoison__sub_80153520(s32 arg0) {
    switch (get_current_floor_area()) {
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_persistent_sound(0x4004BC16, arg0, arg0 + 0x38, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_persistent_sound(0x4004BC24, arg0, arg0 + 0x38, 0, 0);
        break;
    default:
        play_persistent_sound(0x4004BC1C, arg0, arg0 + 0x38, 0, 0);
        break;
    }
}

void TObjFogCollisionPoison::record_poison_hit(u16 arg1) {
    record_fog_collision_hit(arg1, this->set_params[0], (s32)((int) ((u8) (this->set_params[1] == 0))));
}

void TObjFogCollisionPoison::apply_poison_damage(s32 arg1) {
    s32 p;
    s16 v;
    p = get_player_by_client_id(arg1);
    if (is_valid_target__9TObjEneDDFv(p) != 0) {
        v = get_actor_hp(p) - this->m_98;
        if (v < 0) {
            v = 0;
        }
        send_6x2F_change_player_hp(0xFFFF, get_entity_id(p), v);
    }
}

u8 TObjFogCollisionPoison::check_switch() {
    s32 temp_r31;

    temp_r31 = get_switch_mode();
    return (u8) (temp_r31 == is_current_floor_switch_set((u16) this->set_params[2]));
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

void record_fog_collision_hit(s32 arg0, s32 arg1, s32 arg2) {
    TObjFogCollision_Manager *manager;
    if ((arg0 >= 0) && (arg0 < 0xC)) {
        manager = TObjFogCollisionPoison__instances[arg0];
        if (manager != 0) {
            manager->record_hit(arg1, arg2);
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

// Per-client poison ticker under a TObjFogCollisionPoison (TObjFogCollisionPoison__ct creates one
// per client; callers pass the client as u16).
TUnk_804AF7B0::TUnk_804AF7B0(TObject *parent, u16 client) : TObject(parent) {
    this->client = client;
    damage_interval = 0x96;
    damage_timer = 0;
    contact_ticks = 0;
}

TUnk_804AF7B0::~TUnk_804AF7B0() {

}
