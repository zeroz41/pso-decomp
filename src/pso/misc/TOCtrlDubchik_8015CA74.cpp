#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOCtrlDubchik.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

struct VBase_18_65b835 { char pad[0x18]; };

struct VObj_18_65b835 : VBase_18_65b835 {
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
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual s32 m77(s32 *);
};

struct RecoveredGlobal_8015D314_lbl_804B0A10 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8015D314_lbl_804B0A10_size[sizeof(RecoveredGlobal_8015D314_lbl_804B0A10) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8015D3CC_lbl_804B0A20 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8015D3CC___vt__13TOCtrlDubchik {
    s32 value;
    u8 remaining[0x148];
};

struct Pair_8015D518 { s32 a; s32 b; };

struct Obj_8015D518 {
    u8 pad0[0x326];
    s16 f326;
};

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8015D314_lbl_804B0A10 bm_fs_obj_zombie_con_resource_descriptor;
extern u32 TOCtrlDubchik__shared_resource;
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
extern const f32 TOCtrlDubchik__data_805DB3AC;
extern const f32 TOCtrlDubchik__data_805DB3B0;
extern const f32 TOCtrlDubchik__data_805DB3B4;
extern const f32 TOCtrlDubchik__data_805DB3B8;
s32 try_start_action__9TObjCharaFll(void *, void *, void *);
s32 roll_physical_accuracy__9TObjCharaFPvlf(void *, void *, void *, f32);
s32 __ct__9TObjEnemyFP7TObject(void *);
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_8015D3CC_lbl_804B0A20 TOCtrlDubchik__collision_body;
extern s32 __vt__13TOCtrlDubchik[];
extern s32 lbl_805D2F1C;
extern const f32 TOCtrlDubchik__data_805DB3A8;
extern const f32 lbl_805DB3BC;
extern const f32 lbl_805DB3C8;
u8 *TOCtrlDubchik__ct(TOCtrlDubchik *arg0, s32 arg1, s32 arg2);
f32 sin_table_lookup(s32);
int get_player_data__10TObjPlayerFi(int a0);
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
extern s32 lbl_805D29F8;
extern s32 lbl_805D586C;
extern s32 lbl_805D5870;
void TOCtrlDubchik__sub_8015C9D0(u8 *);
void submit_cursor_candidate(void *, s32);
void *spawn_particle_effect(void *pos, s32 id);
void TObjPlayer__sub_800A8C1C(u8 *arg0);
s32 play_sound_effect(s32, void *, s32, s32);
f32 receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void *, s32, Pair_8015D518, void *, s32, s32);
f32 TOCtrlDubchik__vt21(Obj_8015D518 *arg0, s32 arg1, Pair_8015D518 arg2, void *arg3);
void *__dt__13TOCtrlDubchikFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 select_melee_contact_body__9TObjCharaFPvf();
s32 __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TOCtrlDubchik::sub_8015CA74() {
    u8 *arg0 = (u8 *)this;
    s32 area;
    s32 i;
    u8 *p;
    spawn_particle_effect(&this->position, 0x45);
    spawn_particle_effect(&this->position, 0x46);
    area = get_current_floor_area();
    if (area >= 0x17 || area < 0x13) {
        play_sound_effect(0x4003AD16, (u8 *)&this->position, 0, 0);
    }
    for (i = lbl_805D586C; i < lbl_805D586C + lbl_805D5870; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && p != arg0 && check_value_equals__13TUnk_804B6C24Fl(p, lbl_805D29F8) != 0 &&
            *(s32 *)(p + 0x368) == 0 && *(s16 *)(arg0 + 0x28) == *(s16 *)(p + 0x28)) {
            TObjPlayer__sub_800A8C1C(p);
        }
    }
}

void TOCtrlDubchik::complete_and_destroy() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    if (exchange_object_state__9TObjEnemyFls(arg0, &sp8, 1) != 0) {
        sp8 = 1;
        ((TObjEnemy *)arg0)->send_6x0A_enemy_state(&sp8);
        exchange_object_state__9TObjEnemyFls(arg0, &sp8, 0);
        ((VObj_18_65b835 *)(arg0))->m77(&sp8);
        ((TOCtrlDubchik *)arg0)->sub_8015CA74();
        ((TObjCollidable *)arg0)->set_flag8();
        queue_destruction__7TObjectFv((arg0));
    }
}

#pragma push
#pragma opt_common_subs off
void TOCtrlDubchik::decay_timer_and_clear_flag() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)&this->unk_384 = (f32) (*(f32 *)&this->unk_384 - TOCtrlDubchik__data_805DB3B0);
    if (*(f32 *)&this->unk_384 < TOCtrlDubchik__data_805DB3A8) {
        *(f32 *)&this->unk_384 = (f32) TOCtrlDubchik__data_805DB3A8;
        this->mode = 0;
        ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x08000000);
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TOCtrlDubchik::decay_timer_and_finish() {
    this->m_388 = (f32) (this->m_388 - TOCtrlDubchik__data_805DB3B0);
    if (this->m_388 < TOCtrlDubchik__data_805DB3A8) {
        this->m_388 = (f32) TOCtrlDubchik__data_805DB3A8;
        this->mode = 5;
    }
}
#pragma pop

void TOCtrlDubchik::update_spin() {

    *(s32 *)&this->m_380 = (s32) (((f32) (*(s32 *)&this->m_380)) + TOCtrlDubchik__data_805DB3B4);
    this->m_37c = (f32) (TOCtrlDubchik__data_805DB3B8 + sin_table_lookup(*(s32 *)&this->m_380));
    apply_actor_gravity((TObjEnemy *)this, (s32 *)(((u8 *)this) + 0x390), (f32)this->m_37c);
    *(s32 *)&this->m_38c = (s32) (*(s32 *)&this->m_38c + 0x147);
}

extern void *tl_05;

#pragma fp_contract on
void TOCtrlDubchik::sub_8015CCF4() {
  f32 new_var2;
  f32 new_var4;
  f32 *new_var;
  s8 *new_var3;
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x380)) = (s32) (((f32) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x380)))) + TOCtrlDubchik__data_805DB3B4);
  new_var3 = ((s8 *) ((u8 *)this)) + 0x380;
  *((f32 *) (((s8 *) ((u8 *)this)) + 0x37C)) = (f32) (TOCtrlDubchik__data_805DB3B8 + sin_table_lookup((s32)(*((s32 *) new_var3))));
  new_var = &(*((f32 *) (((s8 *) ((u8 *)this)) + 0x37C)));
  apply_actor_gravity((TObjEnemy *)this, (s32 *)(((u8 *)this) + 0x390), (f32)(*new_var));
  new_var4 = *((f32 *) (((s8 *) ((u8 *)this)) + 0x388));
  *((f32 *) (((s8 *) ((u8 *)this)) + 0x388)) = (f32) (new_var4 + TOCtrlDubchik__data_805DB3B0);
  if (TOCtrlDubchik__data_805DB3AC < (*((f32 *) (((s8 *) ((u8 *)this)) + 0x388))))
  {
    new_var2 = (f32) TOCtrlDubchik__data_805DB3AC;
    *((f32 *) (((s8 *) ((u8 *)this)) + 0x388)) = new_var2;
    *((s16 *) (((s8 *) ((u8 *)this)) + 0x326)) = 3;
    this->clear_player_status_flag(0, 0x08000004);
 do { set_indexed_flags(0, 2); } while (0 != 0U);
  }
  new_var4 = new_var4;
}

#pragma push
#pragma opt_common_subs off
void TOCtrlDubchik::update_bobbing() {
    *(s32 *)&this->m_380 = (s32) (((f32) (*(s32 *)&this->m_380)) + TOCtrlDubchik__data_805DB3B4);
    this->m_37c = (f32) (TOCtrlDubchik__data_805DB3B8 + sin_table_lookup((s32)((int) (*(s32 *)&this->m_380))));
    apply_actor_gravity((TObjEnemy *)this, (s32 *)(((u8 *)this) + 0x390), this->m_37c);
    *(f32 *)&this->unk_384 = (f32) (*(f32 *)&this->unk_384 + TOCtrlDubchik__data_805DB3B0);
    if (TOCtrlDubchik__data_805DB3AC < *(f32 *)&this->unk_384) {
        *(f32 *)&this->unk_384 = (f32) TOCtrlDubchik__data_805DB3AC;
        this->mode = 2;
    }
}
#pragma pop

void TOCtrlDubchik::sub_8015CE80() {
    s32 i;
    u8 *p;
    *(s32 *)&this->m_380 = (f32)*(s32 *)&this->m_380 + TOCtrlDubchik__data_805DB3B4;
    this->m_37c = lbl_805DB3BC + sin_table_lookup(*(s32 *)&this->m_380);
    apply_actor_gravity((TObjEnemy *)this, (s32 *)(((u8 *)this) + 0x390), (f32)this->m_37c);
    for (i = lbl_805D586C; i < lbl_805D586C + lbl_805D5870; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && p != ((u8 *)this) && obj_testFlags30__14TObjCollidableFUl(p, 0x800) != 0 &&
            check_value_equals__13TUnk_804B6C24Fl(p, lbl_805D29F8) != 0 &&
            *(s32 *)(p + 0x368) == 0 && *(s16 *)(((u8 *)this) + 0x28) == *(s16 *)(p + 0x28)) {
            this->mode = 1;
        }
    }
}

void TOCtrlDubchik::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TOCtrlDubchik__sub_8015C9D0(arg0);
        return;
    }
    if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x800) != 0) {
        *(s16 *)(arg0 + 0x326) = 6;
    } else if (this->update_movement_status() != 0) {
        ((TObjCollidable *)arg0)->refresh_collision_body_centers();
        submit_cursor_candidate(arg0, -1);
        return;
    }
    switch (*(s16 *)(arg0 + 0x326)) {
    case 0:
        ((TOCtrlDubchik *)arg0)->sub_8015CE80();
        break;
    case 1:
        ((TOCtrlDubchik *)arg0)->update_bobbing();
        break;
    case 2:
        ((TOCtrlDubchik *)arg0)->sub_8015CCF4();
        break;
    case 3:
        ((TOCtrlDubchik *)arg0)->update_spin();
        break;
    case 4:
        decay_timer_and_finish();
        break;
    case 5:
        decay_timer_and_clear_flag();
        break;
    case 6:
        complete_and_destroy();
        break;
    }
    VecCopy((Vec *)&this->m_2fc, (const Vec *)&this->position);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    submit_cursor_candidate(arg0, -1);
}

void *TOCtrlDubchik::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x3A0);
    if (o != NULL) {
        o = TOCtrlDubchik__ct((TOCtrlDubchik *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOCtrlDubchik::destroy_instance() {
    if ((u32) TOCtrlDubchik__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOCtrlDubchik__shared_resource, 1);
        TOCtrlDubchik__shared_resource = 0U;
    }
}

void TOCtrlDubchik::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_zombie_con_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOCtrlDubchik__shared_resource) = var_r0;
}

void *__dt__13TOCtrlDubchikFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TOCtrlDubchik;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8015D3CC_lbl_804B0A20_size[sizeof(RecoveredGlobal_8015D3CC_lbl_804B0A20) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8015D3CC___vt__13TOCtrlDubchik_size[sizeof(RecoveredGlobal_8015D3CC___vt__13TOCtrlDubchik) == 0x14C ? 1 : -1];
u8 *TOCtrlDubchik__ct(TOCtrlDubchik *ctrl_dubchik, s32 arg1, s32 arg2) {
    __ct__9TObjEnemyFP7TObject(ctrl_dubchik);
    *(s32 **)((s8 *)ctrl_dubchik + 0x18) = &(*(RecoveredGlobal_8015D3CC___vt__13TOCtrlDubchik *)&__vt__13TOCtrlDubchik).value;
    *(s32 *)((s8 *)ctrl_dubchik + 0) = (s32) lbl_805D2F1C;
    ((TOCtrlDubchik *)(ctrl_dubchik))->apply_set_data((void *)arg2);
    ((TObjPlayer *)ctrl_dubchik)->init_position_vectors();
    ctrl_dubchik->model = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOCtrlDubchik__shared_resource) + 0x42C)) + 8));
    ctrl_dubchik->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOCtrlDubchik__shared_resource) + 0x42C)) + 0xC);
    init_collision_body_parts(ctrl_dubchik, &TOCtrlDubchik__collision_body.value, 1);
    ((TObjCollidable *)ctrl_dubchik)->refresh_collision_body_centers();
    ((TObjPlayer *)ctrl_dubchik)->register_object_by_id();
    ((TObjCollidable *)ctrl_dubchik)->set_indexed_flags(0, 0x08000000);
    ctrl_dubchik->mode = 0;
    ctrl_dubchik->hp = 0x12C;
    ctrl_dubchik->hpmax = 0x12C;
    *(f32 *)((s8 *)ctrl_dubchik + 0x374) = (f32) lbl_805DB3C8;
    ctrl_dubchik->m_378 = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)ctrl_dubchik->model + 4)) + 0x14);
    ctrl_dubchik->m_37c = (f32) lbl_805DB3BC;
    ctrl_dubchik->m_380 = 0;
    *(f32 *)((s8 *)ctrl_dubchik + 0x384) = (f32) TOCtrlDubchik__data_805DB3A8;
    ctrl_dubchik->m_388 = (f32) TOCtrlDubchik__data_805DB3A8;
    ctrl_dubchik->m_38c = 0;
    VecCopy((Vec *)((u8 *)ctrl_dubchik + 0x390), (const Vec *)((u8 *)ctrl_dubchik + 0x50));
    ctrl_dubchik->m_39c = 1;
    return (u8 *)ctrl_dubchik;
}

s32 TOCtrlDubchik::select_melee_contact_body(void *, f32) {
    if (this->mode != 0) {
        return select_melee_contact_body__9TObjCharaFPvf();
    }
    return 0;
}

f32 TOCtrlDubchik__vt21(Obj_8015D518 *arg0, s32 arg1, Pair_8015D518 arg2, void *arg3) {
    if (arg0->f326 != 0) {
        return receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(arg0, arg1, arg2, arg3, -1, -1);
    }
    return TOCtrlDubchik__data_805DB3A8;
}

s32 TOCtrlDubchik::try_start_action(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (this->mode != 0) {
        return try_start_action__9TObjCharaFll((void *)arg0, (void *)arg1, (void *)arg2);
    }
    return 0;
}

s32 TOCtrlDubchik::roll_physical_accuracy(void *arg1, s32 arg2, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    if (this->mode != 0) {
        return roll_physical_accuracy__9TObjCharaFPvlf((void *)arg0, (void *)arg1, (void *)arg2, (f32)farg0);
    }
    return 0;
}

void TOCtrlDubchik::apply_knockback_from_attacker(u8 *) {  }

}
