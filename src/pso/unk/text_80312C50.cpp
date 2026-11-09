#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"

struct B_80312D4C { char pad[0x18]; };

struct Ply_80312D4C : B_80312D4C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(f32);
};

extern "C" {
void *get_element__10TObjPlayerFPvi(void *a0, int a1);
int TObjPlayer__sub_80313218(void* p);
u8 *TObjPlayer__sub_80312FB0(TObjPlayer *arg0);
void append_photon_blast_request(s32 arg0, s16 arg1, s16 arg2);
void *get_player_by_client_id(s32);
int TObjPlayer__sub_803131AC(void* a0);
void TObjPlayer__sub_80312E98(void *o, u16 id);
void *TObjPlayer__sub_803131B4(void *, int);
void set_field_0__10TObjPlayerFs(void* p, int v);
void TObjPlayer__sub_80313250(void *arg0, s32 arg1);
void TObjPlayer__sub_80313010(void *o, s32 id);
s32 get_section_id__10TObjPlayerFv(void *);
int TObjPlayer__sub_803131AC(void* a0 = 0);
}
void release_photon_blast_requests(void *registry);

void release_photon_blast_requests(void *registry) {
    s32 count;
    s32 i;
    u8 *owner;
    count = TObjPlayer__sub_803131AC(registry);
    for (i = 0; i < count; i++) {
        u16 player = ((u16)get_section_id__10TObjPlayerFv(get_element__10TObjPlayerFPvi(registry, i)));
        if (player != 0xFFFF) {
            owner = (u8 *)get_player_by_client_id(player);
            if (owner != NULL) {
                ((TObjPlayer *)(owner + 0x4AC))->check_photon_blast_flag();
                ((TObjPlayer *)(owner + 0x4AC))->trigger_photon_blast();
            }
        }
    }
}

void *TObjPlayer::find_by_section_id(u16 section) {
    s32 n;
    s32 i;
    u8 *e;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        e = (u8 *)get_element__10TObjPlayerFPvi(this, i);
        if (section == (u16)get_section_id__10TObjPlayerFv(e)) {
            return TObjPlayer__sub_803131B4(e, 0);
        }
    }
    return 0;
}

void TObjPlayer::create_party_effects(s32 id) {
    s32 n;
    s32 i;
    s32 sec;
    Ply_80312D4C *ent;
    u8 *e;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        e = (u8 *)get_element__10TObjPlayerFPvi(this, i);
        sec = get_section_id__10TObjPlayerFv(e);
        ent = (Ply_80312D4C *)get_player_by_client_id((u16)sec);
        if (ent != NULL && (u16)id != (u16)sec && ((TObjPlayer *)((u8 *)ent + 0x4AC))->query_field40() != 0) {
            TWindowCtrl::create_party_effect((void*)id, (void*)sec);
            TObjPlayer__sub_80313010(e, id);
            ent->m75(10.0f);
        }
    }
}

typedef u16 (*SectionFn_80312E0C)(void *);
u16 TObjPlayer::find_first_valid_target_id() {
    s32 n;
    s32 i;
    u8 *e;
    u8 *ent;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        e = (u8 *)get_element__10TObjPlayerFPvi(this, i);
        ent = (u8 *)get_player_by_client_id(((SectionFn_80312E0C)get_section_id__10TObjPlayerFv)(e));
        if (ent != NULL && ((TObjPlayer *)(ent + 0x4AC))->query_field40() != 0) {
            return ((SectionFn_80312E0C)get_section_id__10TObjPlayerFv)(e);
        }
    }
    return 0xFFFF;
}

void TObjPlayer__sub_80312E98(void *o, u16 id) {
    s32 n = TObjPlayer__sub_803131AC(o);
    s32 i;
    for (i = 0; i < n; i++) {
        if (id == ((u16)get_section_id__10TObjPlayerFv(get_element__10TObjPlayerFPvi(o, i)))) {
            ((TObjPlayer *)o)->process_indexed_element((s32)((void*)((void *)i)));
        }
    }
}

void TObjPlayer::process_all_elements() { { int n = TObjPlayer__sub_803131AC(this); int i; for (i = 0; i < n; i++) { process_indexed_element((s32)((void*)i)); } } }

void append_photon_blast_request(s32 arg0, s16 arg1, s16 arg2) {
    s32 temp_r3;
    temp_r3 = ((s32)TObjPlayer__sub_80312FB0((TObjPlayer *)((u8 *)arg0)));
    if (temp_r3 != 0) {
        ((TObjPlayer *)temp_r3)->check_flag_at_4();
        ((TObjPlayer *)temp_r3)->set_type(arg1);
        ((TObjPlayer *)temp_r3)->set_field_2(arg2);
    }
}

u8 *TObjPlayer__sub_80312FB0(TObjPlayer *arg0) {
    s32 var_r31;
    u8 *temp_r3;
    var_r31 = 0;
loop_1:
    temp_r3 = (u8 *)(get_element__10TObjPlayerFPvi(arg0, var_r31));
    if (TObjPlayer__sub_80313218(temp_r3) != 0) {
        return temp_r3;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        return NULL;
    }
    goto loop_1;
}
void TObjPlayer__sub_80313010(void *o, s32 id) {
    s32 n;
    s32 i;
    void *e;
    n = TObjPlayer::get_max_children(o);
    for (i = 0; i < n; i++) {
        e = TObjPlayer__sub_803131B4(o, i);
        if ((u16)id == ((TObjPlayer *)e)->get_entity_type()) {
            TObjPlayer__sub_80313250(e, 10);
            return;
        }
        if (((TObjPlayer *)e)->get_entity_type() == 0xFFFF) {
            set_field_0__10TObjPlayerFs(e, id);
            TObjPlayer__sub_80313250(e, 10);
            return;
        }
    }
}
