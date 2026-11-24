#include "pso/system/BmlResource.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"

#include "pso/object/container/TContainerAncient01.h"

#include "pso/object/base/TObjChara.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/object/container/TContainerAncient01R.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/BmlResourceLoad.h"

#include "pso/map/FloorArea.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/system/SoundEffect.h"

#include "pso/player/TObjPlayer_80011014.h"


#include "pso/system/task/TObject.h"

static const f32 TContainerAncient01__data_805DBD10[1] = {1.0f};

static const f32 TContainerAncient01__data_805DBD14[1] = {0.0f};

#include "pso/player/TObjPlayer.h"


#include "pso/system/vector.h"


#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/object/ambient/TObjFish.h"

struct Base_8018AC68_8018A584 { char pad[0x18]; };

struct VObj_8018AC68_8018A584 : Base_8018AC68_8018A584 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20(s32, f32);
};

struct Obj_8018AB44 { u8 pad0[0x38]; u8 pos[0x328]; s32 f360; };

struct Atk_8018A584 { s32 type; f32 power; s32 kind; f32 base; };

struct VBase_8018A584 { u8 pad[0x18]; };

struct Player_8018A584 : VBase_8018A584 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(void *, Atk_8018A584 *, s32, s32, s32);
    u8 pad1c[0x38 - 0x1C];
    f32 pos[3];
};

struct Obj_8018A584 { u8 pad[0x38]; f32 pos[3]; };

struct Player_8018A914 { u8 pad[0x38]; f32 pos[3]; };

struct Obj_8018A914 {
    u8 pad[0x38];
    f32 pos[3];
    u8 pad44[0xB8 - 0x44];
    s16 xb8;
    u8 padba[0x2B4 - 0xBA];
    f32 x2b4;
    u8 pad2b8[0x326 - 0x2B8];
    s16 state;
    u8 pad328[0x33C - 0x328];
    f32 x33c;
};

struct Obj_8018B510 { u8 pad0[0x38]; u8 pos[0x7C]; s16 fB4[3]; u8 pad1[0x1FA]; f32 f2B4; u8 pad2[0x6E]; s16 state; u8 pad3[0x10]; f32 f338; };

struct Obj_8018B700 { u8 pad0[0x38]; u8 pos[0x324]; s32 f35C; };

struct Atk_8018B180 { s32 type; f32 power; s32 kind; f32 base; };

struct VBase_8018B180 { u8 pad[0x18]; };

struct Player_8018B180 : VBase_8018B180 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(void *, Atk_8018B180 *, s32, s32, s32);
    u8 pad1c[0x38 - 0x1C];
    f32 pos[3];
};

struct Obj_8018B180 { u8 pad[0x38]; f32 pos[3]; };

struct Obj_8018B180;


struct VBase_8018B030 { u8 pad[0x18]; };

struct Obj_8018B030 : VBase_8018B030 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(void *);
    u8 pad1c[0x24 - 0x1C];
    s32 x24;
    u8 pad28[0x30 - 0x28];
    u32 flags;
    s32 x34;
    Vec pos;
    u8 pad44[0x74 - 0x44];
    Vec pos74;
    u8 pad80[0xB8 - 0x80];
    s16 anim;
    u8 padba[0xD8 - 0xBA];
    TObjMotionAction *animTbl;
    BmlMotionEntry *motion_list;
    u8 pade0[0x2FC - 0xE0];
    Vec pos2fc;
    u8 pad308[0x326 - 0x308];
    s16 state;
};
extern "C" {


void init_collision_body_parts(void *, void *, int);


s32 submit_cursor_candidate(void *, int, f32);

extern BmlResource *TContainerAncient01R__bml_resource;


unsigned int __cvt_fp2unsigned(f32);

f32 horizontal_distance_squared(void *, void *);

// Effect ids load_resources picks per area (0x230/0x231 or 0x45/0x46) and the
// pair TContainerAncient01R::init_table_entries copies for its open effect.
s32 TContainerAncient01__effect_id_table[2];

saddr TContainerAncient01__open_effect_table[2];

void TContainerAncient01__sub_8018A584(Obj_8018A584 *self, f32 range);

extern s32 registered_player_count;

BmlResource *TContainerAncient01__sub_8018BE90(void);

void TContainerAncient01__sub_8018B180(Obj_8018B180 *self, f32 range);

s32 scale_current_matrix(void *);

s32 post_translate_matrix(void *);



void TContainerAncient01R__sub_8018AF74(void);

s32 free_collision_body_parts(void *);


const char *fe_obj_h_s_konte_model_names[3] = { "fe_obj_h_s_konte.gj", "fe_obj_h_s_konte2.gj", NULL };

const char *fe_obj_h_s_konte_motion_names[3] = { "fe_obj_h_s_konte.njm", "fe_obj_h_s_konte2.njm", NULL };

BmlResourceDescriptor TContainerAncient01__resource_descriptor = {
    "fe_obj_h_s_konte.bml", fe_obj_h_s_konte_model_names, fe_obj_h_s_konte_motion_names, 2, 2,
};

const char *bm_obj_geenest_model_names[3] = { "obj_o_geenest01.gj", "obj_o_geenest02.gj", NULL };

const char *bm_obj_geenest_motion_names[3] = { "obj_o_geenest01.njm", "obj_o_geenest02.njm", NULL };

BmlResourceDescriptor TContainerAncient01__resource_descriptor_2 = {
    "bm_obj_geenest.bml", bm_obj_geenest_model_names, bm_obj_geenest_motion_names, 2, 2,
};

void *TContainerAncient01__collision_body_parts[11] = {
    (void *)0x0, (void *)0x41000000, (void *)0x0, (void *)0x41200000,
    (void *)0x41200000, (void *)0x0, (void *)0x38003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};

TObjMotionAction TContainerAncient01__anim_table[3] = {
    {1, 0, 0, 1.0f, 1},
    {1, 0, 0, 6.0f, 1},
    {2, 0, 1, 1.0f, 4},
};

// The constructors install these names (TObject::m_name).
const char *TContainerAncient01__name = "TContainerAncient01";

// The kind-3 preview uses this action table and the current floor archive's motions.
static const NpcAnimationBinding container_ancient_anim_binding = {
    NULL, TContainerAncient01__anim_table, 0, 0, 3,
};

const char *TContainerAncient01R__name = "TContainerAncient01R";

}

#include "pso/system/task/TObject_80019A50.h"

#include "pso/render/GinjaMaterial.h"

#include "pso/unk/text_803D96A8.h"

struct Base_8018B820_8018B79C { char pad[0x18]; };

struct VObj_8018B820_8018B79C : Base_8018B820_8018B79C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20(s32, f32);
};
extern "C" {
extern BmlResource *TContainerAncient01__bml_resource;

s32 reset_state__19TContainerAncient01Fv();
}

#include "pso/npc/TObjNpcEnemy.h"


#include "pso/render/RenderFadeState.h"

#include "pso/ui/hud/TRaderMapCore.h"

#include "pso/object/container/TObjContainerJungEnemy.h"

#include "pso/object/container/TObjContainerIdo.h"

#include "pso/item/TUnk_804B97C0.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/ModelDrawContext.h"

struct B_8018BE30 { u8 pad[0x18]; };

struct V_8018BE30 : B_8018BE30 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(s32 a, f32 b);
};

struct B_8018BE98 { u8 pad[0x18]; };

struct V_8018BE98 : B_8018BE98 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(s32 a, f32 b);
};

BmlResource *TContainerAncient01__bml_resource;
BmlResource *TContainerAncient01R__bml_resource;

s32 TContainerAncient01::roll_physical_accuracy(void *, s32, f32) { return 1; }

s32 TContainerAncient01::try_start_action(s32, s32) { return 1; }

void TContainerAncient01::apply_knockback_from_attacker(u8 *, f32) {  }

f32 TContainerAncient01::receive_weapon_special_attack(void *, void *) {
    V_8018BE98 *self = (V_8018BE98 *)this;
    self->m20(0, TContainerAncient01__data_805DBD10[0]);
    return TContainerAncient01__data_805DBD14[0];
}

BmlResource *TContainerAncient01__sub_8018BE90(void) {
    return TContainerAncient01__bml_resource;
}

int TContainerAncient01::get_table_entry(int a0) {  return TContainerAncient01__effect_id_table[a0]; }

s32 TContainerAncient01R::roll_physical_accuracy(void *, s32, f32) { return 1; }

s32 TContainerAncient01R::try_start_action(s32, s32) { return 1; }

void TContainerAncient01R::apply_knockback_from_attacker(u8 *, f32) {  }

f32 TContainerAncient01R::receive_weapon_special_attack(void *, void *) {
    V_8018BE30 *self = (V_8018BE30 *)this;
    self->m20(0, TContainerAncient01__data_805DBD10[0]);
    return TContainerAncient01__data_805DBD14[0];
}

#pragma push
#pragma fp_contract on
TContainerAncient01::TContainerAncient01(TObject *parent, void *set_data) : TObjChara(parent) {
    m_name = TContainerAncient01__name;
    this->apply_object_set_data(set_data);
    this->model = get_bml_model(TContainerAncient01__bml_resource, 0);
    this->texlist = get_bml_texlist(TContainerAncient01__bml_resource, 0);
    this->action_table = TContainerAncient01__anim_table;
    this->set_action_table(this->action_table);
    this->motion_list = TContainerAncient01__bml_resource->motions;
    this->requested_action = 0;
    this->set_animation((this->requested_action));
    this->set_requested_action((int) (this->requested_action));
    this->actorFlags = (s32) (this->actorFlags | 0x60000000);
    init_collision_body_parts(this, (void *)&TContainerAncient01__collision_body_parts, 1);
    ((TObjPlayer *)this)->register_object_by_id();
    VecCopy((Vec *)((u8 *)this + 0x74), (const Vec *)(((u8 *)this) + 0x38));
    *(f32 *)((s8 *)this + 0x78) = (f32) ((*(f32 *)((s8 *)&TContainerAncient01__collision_body_parts + 4) / 2.0f) + *(f32 *)((s8 *)this + 0x78));
    VecCopy((Vec *)((u8 *)this + 0x2FC), (const Vec *)(((u8 *)this) + 0x74));
    this->mode = 0;
    this->init_state_vectors();
}

#pragma pop
TContainerAncient01::~TContainerAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TContainerAncient01::load_resources() {
    BmlResource *p;
    TContainerAncient01__bml_resource = NULL;
    if (TContainerAncient01::is_global_state_in_table() != 0) {
        p = new BmlResource(5, &TContainerAncient01__resource_descriptor_2, 0, 0, NULL);
        TContainerAncient01__effect_id_table[0] = 0x230;
        TContainerAncient01__bml_resource = p;
        TContainerAncient01__effect_id_table[1] = 0x231;
    } else {
        p = new BmlResource(5, &TContainerAncient01__resource_descriptor, 0, 0, NULL);
        TContainerAncient01__effect_id_table[0] = 0x45;
        TContainerAncient01__bml_resource = p;
        TContainerAncient01__effect_id_table[1] = 0x46;
    }
    NpcAnimationBinding prm = container_ancient_anim_binding;
    prm.motions = TContainerAncient01__bml_resource->motions;
    TObjNpcEnemy::register_animated_ginja(0x3B, get_bml_model(TContainerAncient01__bml_resource, 0),
                                             get_bml_texlist(TContainerAncient01__bml_resource, 0), &prm,
                                             10.0f, TContainerAncient01__data_805DBD14[0]);
}

void TContainerAncient01::release_static_resource() {
    if (TContainerAncient01__bml_resource != NULL) {
        delete TContainerAncient01__bml_resource;
        TContainerAncient01__bml_resource = NULL;
    }
}

void *TContainerAncient01::create(void *set_data) {
    return new TContainerAncient01(tl_05, set_data);
}

void TContainerAncient01::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 frame_timer;
    f32 y;
    if (TObjPlayer::check_demo_mode() == 0) {
        if ((s32) this->m_35c == 0) {
            switch (this->mode) {
            case 0:
                ((TContainerAncient01 *)arg0)->update_wait_for_player();
                break;
            case 1:
                ((TContainerAncient01 *)arg0)->sub_8018B48C();
                break;
            case 2:
                ((TContainerAncient01 *)arg0)->sub_8018B284();
                break;
            default:
                this->mode = 0;
                this->requested_action = (s16) this->mode;
                this->frame_timer = (f32) (-1.0f);
                ((TContainerAncient01 *)arg0)->update_wait_for_player();
                break;
            }
            frame_timer = this->frame_timer;
            this->frame_timer = (f32) (frame_timer + TContainerAncient01__data_805DBD10[0]);
            submit_cursor_candidate(arg0, -1, frame_timer);
        } else {
            y = this->open_scale.y;
            if (y <= 0.2f) {
                *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) - 0.025f);
                if (*(f32 *)((s8 *)arg0 + 0x3C) <= ((-1e+01f) * this->open_scale.y)) {
                    ((TObject *)arg0)->TObject::queue_destruction();
                }
            } else {
                this->open_scale.y = (f32) (y - 0.025f);
            }
        }
    }
    if (static_cast<const void *>(current_motion) == get_bml_motion(TContainerAncient01__bml_resource, 0)) {
        this->model = get_bml_model(TContainerAncient01__bml_resource, 0);
    }
    if (static_cast<const void *>(current_motion) == get_bml_motion(TContainerAncient01__bml_resource, 1)) {
        this->model = get_bml_model(TContainerAncient01__bml_resource, 1);
    }
    ((TObject *)arg0)->TObject::run_task();
}

void TContainerAncient01::render() {
    if (this->update_object_view_visibility(3e+02f, 2e+01f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_35c != 0) {
            scale_current_matrix(&this->open_scale.x);
        }
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_ginja_object(this->model);
        } else {
            draw_ginja_model_with_motion((void *)(*(saddr *)&this->model), (void *)(*(saddr *)&this->current_motion), this->frame);
        }
        pop_matrix();
    }
}

s32 TContainerAncient01::select_melee_contact_body(void *target, f32) {
    return xyz_distance_squared(&static_cast<const TObjBase *>(target)->position, &position) < 4e+02f;
}

int TContainerAncient01::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TContainerAncient01::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
    s32 kind;
    struct VObj_8018B820_8018B79C *o = (struct VObj_8018B820_8018B79C *)this;

    kind = payload.kind;
    if ((kind == 0) || ((kind - 1) <= 3U) || (kind == 0x13)) {
        o->m20(0, TContainerAncient01__data_805DBD10[0]);
    }
    return TContainerAncient01__data_805DBD14[0];
}

f32 TContainerAncient01::receive_physical_attack(void *, f32) {
    s16 sp8;

    if ((u16) this->entity_id >= 0x1000U) {
        reset_state__19TContainerAncient01Fv();
        if (((uaddr) this->set_entry != 0U) && (access_object_saved_state(&sp8, 1) != 0)) {
            sp8 = 1;
            access_object_saved_state(&sp8, 0);
            send_object_state_update(&sp8);
        }
    }
    return TContainerAncient01__data_805DBD14[0];
}

void TContainerAncient01::sub_8018B700() {
    Obj_8018B700 *arg0 = (Obj_8018B700 *)this;
    if (arg0->f35C == 0) {
        arg0->f35C = 1;
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        spawn_effect(&this->position, TContainerAncient01__effect_id_table[0]);
        spawn_effect(&this->position, TContainerAncient01__effect_id_table[1]);
        if (TContainerAncient01::is_global_state_in_table() == 0) {
            ((TObjChara *)arg0)->request_box_item_drop(&((TObjChara *)arg0)->position, 1);
        }
        ((TObjCollidable *)arg0)->set_flag8();
    }
}

void TContainerAncient01::vfunc_6(s16 *arg1, s32 arg2) {
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            sub_8018B700();
            this->m_35c = 1;
        }
    } else if ((s16) *arg1 == 1) {
        this->m_35c = 1;
    }
}
#pragma push
#pragma fp_contract on
void TContainerAncient01::init_state_vectors() {
    *(f32 *)&this->m_338 = (f32) (3e+02f + (this->scale.x - TContainerAncient01__data_805DBD10[0]));
    this->m_33c = (f32) (2.1e+02f + (this->scale.y - TContainerAncient01__data_805DBD10[0]));
    this->range = (f32) (4e+02f + (this->scale.z - TContainerAncient01__data_805DBD10[0]));
    this->m_36c = (s32) (*(s32 *)&this->set_params[2] + 4);
    VecCopy(&this->lower_effect_position, &this->position);
    this->lower_effect_position.y = (f32) (this->lower_effect_position.y + *(f32 *)((s8 *)&TContainerAncient01__collision_body_parts + 4));
    VecCopy(&this->upper_effect_position, &this->lower_effect_position);
    this->upper_effect_position.y = (f32) ((1.25f * *(f32 *)((s8 *)&TContainerAncient01__collision_body_parts + 4)) + this->upper_effect_position.y);
    *(s32 *)&this->m_35c = 0;
    this->open_scale.x = (f32) TContainerAncient01__data_805DBD10[0];
    this->open_scale.y = (f32) TContainerAncient01__data_805DBD10[0];
    this->open_scale.z = (f32) TContainerAncient01__data_805DBD10[0];
}

void TContainerAncient01::update_wait_for_player() {
    Obj_8018B510 *arg0 = (Obj_8018B510 *)this;
    s32 flag;
    u16 i;
    u8 *p;
    f32 c;
    ((TObjMotion *)arg0)->advance_animation();
    flag = 0;
    if (arg0->f338 <= this->frame_timer) {
        flag = 1;
    } else {
        c = 6.4e+03f;
        for (i = 0; i < 4; i++) {
            p = (u8 *)get_player_by_client_id(i);
            if (p != 0 && horizontal_distance_squared(arg0->pos, p + 0x38) < c) {
                flag = 1;
            }
        }
    }
    if (flag != 0) {
        this->mode = 1;
        arg0->fB4[2] = this->mode;
        this->frame_timer = (-1.0f);
    }
}
#pragma pop
void TContainerAncient01::sub_8018B48C() {
    u8 *arg0 = (u8 *)this;
  ((TObjMotion *)arg0)->advance_animation();
  if (((__cvt_fp2unsigned(this->frame_timer) & 0xFFFFFFFF) % 15) == 0)
  {
    spawn_effect(&this->lower_effect_position, 0x7D);
  }
  if (6e+01f <= (this->frame_timer))
  {
    this->mode = 2;
    this->requested_action = this->mode;
    this->frame_timer = (f32) (-1.0f);
  }
}

void TContainerAncient01::sub_8018B284() {
    u32 period;
    u32 phase;
    f32 t;
    this->advance_animation();
    if (1e+01f == this->frame_timer) {
        switch (get_current_floor_area()) {
        case AREA_CENTRAL_CONTROL_AREA:
        case AREA_JUNGLE_NORTH:
        case AREA_JUNGLE_EAST:
        case AREA_MOUNTAIN:
        case AREA_SEASIDE:
            play_sound_effect(0x4BC1C, &this->position, 0, 0);
            break;
        case AREA_SEASIDE_NIGHT:
            play_sound_effect(0x4004BC1C, &this->position, 0, 0);
            break;
        case AREA_TOWER:
            play_sound_effect(0x4004BC1C, &this->position, 0, 0);
            break;
        default:
            play_sound_effect(0x4004BC16, &this->position, 0, 0);
            break;
        }
    }
    if (1e+01f == this->frame_timer || 12.0f == this->frame_timer || 14.0f == this->frame_timer) {
        spawn_effect(&this->upper_effect_position, 0x7D);
    }
    if (4e+01f == this->frame_timer) {
        spawn_effect(&this->lower_effect_position, 0x7E);
    }
    period = (u32)(3e+01f / (f32)this->m_36c);
    phase = (u32)(t = this->frame_timer) % period;
    if (14.0f < t && t < 6e+01f && phase == 0) {
        spawn_effect(&this->upper_effect_position, 0x7E);
    }
    if (6e+01f < this->frame_timer && phase == 0) {
        spawn_effect(&this->lower_effect_position, 0x7E);
    }
    TContainerAncient01__sub_8018B180((Obj_8018B180 *)this, this->range);
    if (this->m_33c <= this->frame_timer) {
        this->reset_state();
    }
}

void TContainerAncient01::reset_state() { this->mode = 0; this->requested_action = this->mode; this->frame_timer = (-1.0f); }

void TContainerAncient01__sub_8018B180(Obj_8018B180 *self, f32 range) {
    u16 i;
    Player_8018B180 *pl;
    for (i = 0; i < 4; i++) {
        pl = (Player_8018B180 *)get_player_by_client_id(i);
        if (pl != NULL) {
            if (((TObjPlayer *)pl)->get_floor() == get_current_floor() && ((TObjCollidable *)pl)->test_actor_flags(1) == 0 &&
                horizontal_distance_squared(self->pos, pl->pos) < range) {
                Atk_8018B180 atk;
                atk.type = 0xF;
                atk.base = 1e+02f;
                atk.kind = 0xF;
                *(s32 *)&atk.power = *(s32 *)&atk.base;
                pl->m21(self, &atk, 0, -1, -1);
            }
        }
    }
}

void TContainerAncient01::spawn_effect(const Vec *position, s32 effect_id) {
    spawn_particle_effect(position, effect_id);
}
#pragma push
#pragma fp_contract on
#define self ((Obj_8018B030 *)this)
TContainerAncient01R::TContainerAncient01R(TObject *parent, void *set_data) : TObjChara(parent) {
    NJS_POINT2 *c;

    m_name = TContainerAncient01R__name;
    self->m5(set_data);
    model = get_bml_model(TContainerAncient01R__bml_resource, 0);
    texlist = get_bml_texlist(TContainerAncient01R__bml_resource, 0);
    self->animTbl = TContainerAncient01__anim_table;
    ((TObjMotion *)self)->set_action_table(self->animTbl);
    self->motion_list = TContainerAncient01R__bml_resource->motions;
    self->anim = 0;
    ((TObjMotion *)self)->set_animation(self->anim);
    ((TObjMotion *)self)->set_requested_action(self->anim);
    self->flags |= 0x60000000;
    init_collision_body_parts(self, (void *)&TContainerAncient01__collision_body_parts, 1);
    ((TObjPlayer *)self)->register_object_by_id();
    VecCopy((Vec *)&self->pos74, (const Vec *)&self->pos);
    c = (NJS_POINT2 *)&TContainerAncient01__collision_body_parts;
    self->pos74.y = c->y / 2.0f + self->pos74.y;
    VecCopy((Vec *)&self->pos2fc, (const Vec *)&self->pos74);
    self->state = 0;
    init_positions();
}
#pragma pop
#undef self
TContainerAncient01R::~TContainerAncient01R() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TContainerAncient01R::init_table_entries() {
    TContainerAncient01R__bml_resource = TContainerAncient01__sub_8018BE90();
    TContainerAncient01__open_effect_table[0] = TContainerAncient01::get_table_entry(0);
    TContainerAncient01__open_effect_table[1] = TContainerAncient01::get_table_entry(1);
}

void TContainerAncient01R__sub_8018AF74(void) { TContainerAncient01R__bml_resource = NULL; }

void *TContainerAncient01R::create(void *parent) {
    return new TContainerAncient01R(tl_05, parent);
}

void TContainerAncient01R::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 frame_timer;
    f32 y;
    if (TObjPlayer::check_demo_mode() == 0) {
        if ((s32) this->m_360 == 0) {
            switch (this->mode) {
            case 0:
                ((TContainerAncient01R *)arg0)->check_open_trigger();
                break;
            case 1:
                ((TContainerAncient01R *)arg0)->update_spawning();
                break;
            case 2:
                ((TContainerAncient01R *)arg0)->sub_8018A688();
                break;
            default:
                this->mode = 0;
                this->requested_action = (s16) this->mode;
                this->frame_timer = (f32) (-1.0f);
                ((TContainerAncient01R *)arg0)->check_open_trigger();
                break;
            }
            frame_timer = this->frame_timer;
            this->frame_timer = (f32) (frame_timer + TContainerAncient01__data_805DBD10[0]);
            submit_cursor_candidate(arg0, -1, frame_timer);
        } else {
            y = this->open_scale.y;
            if (y <= 0.2f) {
                *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) - 0.025f);
                if (*(f32 *)((s8 *)arg0 + 0x3C) <= ((-1e+01f) * this->open_scale.y)) {
                    ((TObject *)arg0)->TObject::queue_destruction();
                }
            } else {
                this->open_scale.y = (f32) (y - 0.025f);
            }
        }
    }
    if (static_cast<const void *>(current_motion) == get_bml_motion(TContainerAncient01R__bml_resource, 0)) {
        this->model = reinterpret_cast<NJS_OBJECT *>(get_bml_model(TContainerAncient01R__bml_resource, 0));
    }
    if (static_cast<const void *>(current_motion) == get_bml_motion(TContainerAncient01R__bml_resource, 1)) {
        this->model = reinterpret_cast<NJS_OBJECT *>(get_bml_model(TContainerAncient01R__bml_resource, 1));
    }
    ((TObject *)arg0)->TObject::run_task();
}

void TContainerAncient01R::render() {
    if (this->update_object_view_visibility(3e+02f, 2e+01f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_360 != 0) {
            scale_current_matrix(&this->open_scale.x);
        }
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_ginja_object(this->model);
        } else {
            draw_ginja_model_with_motion((void *)(*(saddr *)&this->model), (void *)(*(saddr *)&this->current_motion), this->frame);
        }
        pop_matrix();
    }
}

s32 TContainerAncient01R::select_melee_contact_body(void *target, f32) {
    return xyz_distance_squared(&static_cast<const TObjBase *>(target)->position, &position) < 4e+02f;
}

int TContainerAncient01R::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TContainerAncient01R::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
    s32 kind;
    struct VObj_8018AC68_8018A584 *o = (struct VObj_8018AC68_8018A584 *)this;

    kind = payload.kind;
    if ((kind == 0) || ((kind - 1) <= 3U) || (kind == 0x13)) {
        o->m20(0, TContainerAncient01__data_805DBD10[0]);
    }
    return TContainerAncient01__data_805DBD14[0];
}

f32 TContainerAncient01R::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    if ((u16) this->entity_id >= 0x1000U) {
        this->m_338 = (this->m_338 + 1);
        if (((uaddr) this->set_entry != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
            sp8 = this->m_338;
            ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
            ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
        }
    }
    return TContainerAncient01__data_805DBD14[0];
}

void TContainerAncient01R::open_container() {
    Obj_8018AB44 *arg0 = (Obj_8018AB44 *)this;
    if (arg0->f360 == 0) {
        arg0->f360 = 1;
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        trigger_spawn(&this->position, TContainerAncient01__open_effect_table[0]);
        trigger_spawn(&this->position, TContainerAncient01__open_effect_table[1]);
        if (TContainerAncient01::is_global_state_in_table() == 0) {
            ((TObjChara *)arg0)->request_box_item_drop(&((TObjChara *)arg0)->position, 1);
        }
        ((TObjCollidable *)arg0)->set_flag8();
    }
}

void TContainerAncient01R::vfunc_6(s16 *arg1, s32 arg2) {
    this->m_338 = (s16) *arg1;
    if (arg2 != 0) {
        if ((this->hp - this->m_338) <= 0) {
            this->reset_hp();
            this->open_container();
            this->m_360 = 1;
        }
    } else if ((this->hp - this->m_338) <= 0) {
        this->m_360 = 1;
    }
}
#pragma push
#pragma fp_contract on
void TContainerAncient01R::init_positions() {
    this->m_33c = (f32) (3e+02f + (this->scale.x - TContainerAncient01__data_805DBD10[0]));
    this->m_340 = (f32) (2.1e+02f + (this->scale.y - TContainerAncient01__data_805DBD10[0]));
    this->range = (f32) (4e+02f + (this->scale.z - TContainerAncient01__data_805DBD10[0]));
    this->m_370 = (this->set_params[2] + 4);
    VecCopy(&this->lower_effect_position, &this->position);
    this->lower_effect_position.y = (f32) (this->lower_effect_position.y + *(f32 *)((s8 *)&TContainerAncient01__collision_body_parts + 4));
    VecCopy(&this->upper_effect_position, &this->lower_effect_position);
    this->upper_effect_position.y = (f32) ((1.25f * *(f32 *)((s8 *)&TContainerAncient01__collision_body_parts + 4)) + this->upper_effect_position.y);
    this->m_360 = 0;
    this->open_scale.x = (f32) TContainerAncient01__data_805DBD10[0];
    this->open_scale.y = (f32) TContainerAncient01__data_805DBD10[0];
    this->open_scale.z = (f32) TContainerAncient01__data_805DBD10[0];
    this->hp = (s16) this->rotation_z;
    if ((s16) this->hp < 1) {
        this->hp = 1;
    }
    this->m_338 = 0;
}
#pragma pop
void TContainerAncient01R::check_open_trigger() {
    Obj_8018A914 *self = (Obj_8018A914 *)this;
    s32 hit;
    u16 i;
    Player_8018A914 *pl;
    f32 range;

    ((TObjMotion *)self)->advance_animation();
    hit = 0;
    if (this->m_33c <= this->frame_timer) {
        hit = 1;
    } else {
        range = 6.4e+03f;
        for (i = 0; i < registered_player_count; i++) {
            pl = (Player_8018A914 *)get_player_by_client_id(i);
            if (pl != NULL && horizontal_distance_squared(self->pos, pl->pos) < range) {
                hit = 1;
            }
        }
    }
    if (hit != 0) {
        this->mode = 1;
        this->requested_action = this->mode;
        this->frame_timer = (-1.0f);
    }
}

void TContainerAncient01R::update_spawning() {
    u8 *arg0 = (u8 *)this;
  ((TObjMotion *)arg0)->advance_animation();
  if ((__cvt_fp2unsigned(this->frame_timer) % 15) == 0)
  {
    trigger_spawn(&this->lower_effect_position, 0x7D);
  }
  if (6e+01f <= (this->frame_timer))
  {
    this->mode = 2;
    this->requested_action = this->mode;
    this->frame_timer = (f32) (-1.0f);
  }
}

void TContainerAncient01R::sub_8018A688() {
    u32 period;
    f32 t;
    u32 rem;

    this->advance_animation();
    if (1e+01f == this->frame_timer) {
        switch (get_current_floor_area()) {
        case AREA_CENTRAL_CONTROL_AREA:
        case AREA_JUNGLE_NORTH:
        case AREA_JUNGLE_EAST:
        case AREA_MOUNTAIN:
        case AREA_SEASIDE:
            play_sound_effect(0x4BC1C, &this->position, 0, 0);
            break;
        case AREA_SEASIDE_NIGHT:
            play_sound_effect(0x4004BC1C, &this->position, 0, 0);
            break;
        case AREA_TOWER:
            play_sound_effect(0x4004BC1C, &this->position, 0, 0);
            break;
        default:
            play_sound_effect(0x4004BC16, &this->position, 0, 0);
            break;
        }
    }
    if (1e+01f == this->frame_timer || 12.0f == this->frame_timer || 14.0f == this->frame_timer) {
        trigger_spawn(&this->upper_effect_position, 0x7D);
    }
    if (4e+01f == this->frame_timer) {
        trigger_spawn(&this->lower_effect_position, 0x7E);
    }
    period = __cvt_fp2unsigned(3e+01f / this->m_370);
    t = this->frame_timer;
    rem = (u32)t % period;
    if (14.0f < t && t < 6e+01f && rem == 0) {
        trigger_spawn(&this->upper_effect_position, 0x7E);
    }
    if (6e+01f < this->frame_timer && rem == 0) {
        trigger_spawn(&this->lower_effect_position, 0x7E);
    }
    TContainerAncient01__sub_8018A584((Obj_8018A584 *)this, this->range);
    if (this->m_340 <= this->frame_timer) {
        this->reset_hp();
    }
}

void TContainerAncient01R::reset_hp() { this->mode = 0; this->requested_action = this->mode; this->frame_timer = (-1.0f); }

void TContainerAncient01__sub_8018A584(Obj_8018A584 *self, f32 range) {
    u16 i;
    Player_8018A584 *pl;
    for (i = 0; i < 4; i++) {
        pl = (Player_8018A584 *)get_player_by_client_id(i);
        if (pl != NULL) {
            if (((TObjPlayer *)pl)->get_floor() == get_current_floor() && ((TObjCollidable *)pl)->test_actor_flags(1) == 0 &&
                horizontal_distance_squared(self->pos, pl->pos) < range) {
                Atk_8018A584 atk;
                atk.type = 0xF;
                atk.base = 1e+02f;
                atk.kind = 0xF;
                *(saddr *)&atk.power = *(saddr *)&atk.base;
                pl->m21(self, &atk, 0, -1, -1);
            }
        }
    }
}
