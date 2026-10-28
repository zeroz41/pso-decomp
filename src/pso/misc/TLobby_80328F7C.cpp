#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TPlyPhotonChair.h"
#include "pso/misc/TUnk_804DDD28.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TUnk_804ED7D0.h"

struct Base_80328F7C { char pad[0x8]; };
struct VObj_80328F7C : Base_80328F7C {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual s32 m73();
};
struct Base_80329044 { char pad[0x8]; };
struct VObj_80329044 : Base_80329044 {
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
    virtual void m75(s32);
};

struct RecoveredGlobal_80329088_lbl_805430E8 {
    s32 value;
    u8 remaining[0x1BC];
};

struct RecoveredGlobal_80329088_lbl_805432A8 {
    s32 value;
    u8 remaining[0x1BC];
};

struct PlayerMotionEntry {
    u32 unk0;
    s32 unk4;
    f32 unk8;
    u32 unkC;
};

const PlayerMotionEntry lbl_804767D0[56] = {
    {0x0001FFFF, 0, 0.9f, 0x00000001},
    {0x0001FFFF, 1, 1.4f, 0x20000002},
    {0x0001FFFF, 2, 0.8f, 0x20000002},
    {0x0001FFFF, 3, 1.0f, 0x20000001},
    {0x0001FFFF, 4, 1.0f, 0x20000002},
    {0x0001FFFF, 5, 0.8f, 0x20000002},
    {0x0003FFFF, 6, 1.4f, 0x20000040},
    {0x0003FFFF, 7, 3.7f, 0x20000040},
    {0x0003FFFF, 8, 1.3f, 0x20000400},
    {0x0003FFFF, 9, 3.0f, 0x20000010},
    {0x0003FFFF, 10, 1.2f, 0x20000004},
    {0x0003FFFF, 11, 1.1f, 0x20000004},
    {0x0003FFFF, 12, 1.3f, 0x20000004},
    {0x0003FFFF, 13, 1.4f, 0x20000004},
    {0x0003FFFF, 14, 1.5f, 0x20000004},
    {0x0003FFFF, 15, 1.5f, 0x20000004},
    {0x0003FFFF, 16, 1.4f, 0x20000008},
    {0x0003FFFF, 17, 1.4f, 0x20000008},
    {0x0003FFFF, 18, 1.0f, 0x00000080},
    {0x0003FFFF, 19, 0.8f, 0x00000001},
    {0x0003FFFF, 20, 1.0f, 0x20000008},
    {0x0003FFFF, 21, 1.0f, 0x20000008},
    {0x0003FFFF, 22, 1.0f, 0x20000008},
    {0x0003FFFF, 23, 1.0f, 0x20000008},
    {0x0003FFFF, 24, 1.0f, 0x20000008},
    {0x0003FFFF, 25, 1.0f, 0x20000001},
    {0x0003FFFF, 26, 1.0f, 0x20000001},
    {0x0003FFFF, 27, 1.0f, 0x20000001},
    {0x0003FFFF, 28, 1.0f, 0x20000001},
    {0x0003FFFF, 29, 1.0f, 0x20000001},
    {0x0003FFFF, 30, 1.0f, 0x20000001},
    {0x0003FFFF, 31, 1.0f, 0x20000001},
    {0x0003FFFF, 32, 1.0f, 0x20000001},
    {0x0003FFFF, 33, 1.0f, 0x20000001},
    {0x0003FFFF, 34, 1.0f, 0x20000001},
    {0x0003FFFF, 35, 1.0f, 0x20000001},
    {0x0003FFFF, 36, 1.0f, 0x20000001},
    {0x0003FFFF, 37, 1.0f, 0x20000001},
    {0x0003FFFF, 38, 1.0f, 0x20000001},
    {0x0003FFFF, 39, 1.0f, 0x20000001},
    {0x0003FFFF, 40, 1.0f, 0x20000001},
    {0x0003FFFF, 41, 1.0f, 0x20000001},
    {0x0003FFFF, 42, 1.0f, 0x20000001},
    {0x0003FFFF, 43, 1.0f, 0x20000001},
    {0x0003FFFF, 44, 1.0f, 0x20000001},
    {0x0003FFFF, 45, 1.0f, 0x20000001},
    {0x0003FFFF, 46, 1.0f, 0x20000001},
    {0x0003FFFF, 47, 1.0f, 0x20000001},
    {0x00020036, 48, 1.0f, 0x30000001},
    {0x00020037, 49, 1.0f, 0x30000001},
    {0x0003FFFF, 50, 1.0f, 0x20000001},
    {0x0003FFFF, 51, 1.0f, 0x20000001},
    {0x0003FFFF, 52, 1.0f, 0x20000001},
    {0x0003FFFF, 53, 1.0f, 0x20000001},
    {0x0001FFFF, 54, 0.7f, 0x30000001},
    {0x0001FFFF, 55, 0.7f, 0x30000001},
};
const PlayerMotionEntry lbl_80476B50[56] = {
    {0x0001FFFF, 0, 1.0f, 0x00000001},
    {0x0001FFFF, 1, 1.0f, 0x20000002},
    {0x0001FFFF, 2, 0.8f, 0x20000002},
    {0x0001FFFF, 3, 1.0f, 0x20000001},
    {0x0001FFFF, 4, 1.0f, 0x20000002},
    {0x0001FFFF, 5, 0.8f, 0x20000002},
    {0x0003FFFF, 6, 1.5f, 0x20000040},
    {0x0003FFFF, 7, 3.7f, 0x20000040},
    {0x0003FFFF, 8, 1.3f, 0x20000400},
    {0x0003FFFF, 9, 3.0f, 0x20000010},
    {0x0003FFFF, 10, 1.4f, 0x20000004},
    {0x0003FFFF, 11, 1.1f, 0x20000004},
    {0x0003FFFF, 12, 1.3f, 0x20000004},
    {0x0003FFFF, 13, 1.4f, 0x20000004},
    {0x0003FFFF, 14, 1.5f, 0x20000004},
    {0x0003FFFF, 15, 1.7f, 0x20000004},
    {0x0003FFFF, 16, 1.4f, 0x20000008},
    {0x0003FFFF, 17, 1.4f, 0x20000008},
    {0x0003FFFF, 18, 1.0f, 0x00000080},
    {0x0003FFFF, 19, 0.8f, 0x00000001},
    {0x0003FFFF, 20, 1.0f, 0x20000008},
    {0x0003FFFF, 21, 1.0f, 0x20000008},
    {0x0003FFFF, 22, 1.0f, 0x20000008},
    {0x0003FFFF, 23, 1.0f, 0x20000008},
    {0x0003FFFF, 24, 1.0f, 0x20000008},
    {0x0003FFFF, 25, 1.0f, 0x20000001},
    {0x0003FFFF, 26, 1.0f, 0x20000001},
    {0x0003FFFF, 27, 1.0f, 0x20000001},
    {0x0003FFFF, 28, 1.0f, 0x20000001},
    {0x0003FFFF, 29, 1.0f, 0x20000001},
    {0x0003FFFF, 30, 1.0f, 0x20000001},
    {0x0003FFFF, 31, 1.0f, 0x20000001},
    {0x0003FFFF, 32, 1.0f, 0x20000001},
    {0x0003FFFF, 33, 1.0f, 0x20000001},
    {0x0003FFFF, 34, 1.0f, 0x20000001},
    {0x0003FFFF, 35, 1.0f, 0x20000001},
    {0x0003FFFF, 36, 1.0f, 0x20000001},
    {0x0003FFFF, 37, 1.0f, 0x20000001},
    {0x0003FFFF, 38, 1.0f, 0x20000001},
    {0x0003FFFF, 39, 1.0f, 0x20000001},
    {0x0003FFFF, 40, 1.0f, 0x20000001},
    {0x0003FFFF, 41, 1.0f, 0x20000001},
    {0x0003FFFF, 42, 1.0f, 0x20000001},
    {0x0003FFFF, 43, 1.0f, 0x20000001},
    {0x0003FFFF, 44, 1.0f, 0x20000001},
    {0x0003FFFF, 45, 1.0f, 0x20000001},
    {0x0003FFFF, 46, 1.0f, 0x20000001},
    {0x0003FFFF, 47, 1.0f, 0x20000001},
    {0x00020036, 48, 1.0f, 0x30000001},
    {0x00020037, 49, 1.0f, 0x30000001},
    {0x0003FFFF, 50, 1.0f, 0x20000001},
    {0x0003FFFF, 51, 1.0f, 0x20000001},
    {0x0003FFFF, 52, 1.0f, 0x20000001},
    {0x0003FFFF, 53, 1.0f, 0x20000001},
    {0x0001FFFF, 54, 0.7f, 0x30000001},
    {0x0001FFFF, 55, 0.7f, 0x30000001},
};
const s32 lbl_80476ED0[56] = {
    201, 200, 207, 201, 200, 207, 202, 204,
    109, 199, 196, 153, 91, 155, 178, 173,
    194, 126, 205, 174, 187, 137, 206, 164,
    87, 208, 209, 210, 211, 212, 213, 214,
    215, 216, 217, 218, 219, 220, 221, 222,
    223, 224, 225, 226, 227, 228, 229, 230,
    231, 232, 233, 234, 235, 236, 237, 238,
};
const s32 lbl_80476FB0[56] = {
    335, 412, 416, 487, 506, 508, 359, 413,
    340, 411, 408, 369, 321, 371, 389, 384,
    406, 357, 414, 385, 399, 363, 415, 341,
    317, 417, 418, 419, 420, 421, 422, 423,
    424, 425, 426, 427, 428, 429, 430, 431,
    432, 433, 434, 435, 436, 437, 438, 439,
    440, 441, 233, 234, 235, 236, 442, 443,
};
const PlayerMotionEntry * lbl_804ED690[19] = {
    lbl_804767D0, lbl_804767D0, lbl_804767D0, lbl_804767D0,
    lbl_804767D0, lbl_804767D0, lbl_804767D0, lbl_804767D0,
    lbl_804767D0, lbl_804767D0, lbl_804767D0, lbl_804767D0,
    lbl_804767D0, lbl_804767D0, lbl_804767D0, lbl_804767D0,
    lbl_804767D0, lbl_804767D0, lbl_804767D0,
};
const PlayerMotionEntry * lbl_804ED6DC[19] = {
    lbl_80476B50, lbl_80476B50, lbl_80476B50, lbl_80476B50,
    lbl_80476B50, lbl_80476B50, lbl_80476B50, lbl_80476B50,
    lbl_80476B50, lbl_80476B50, lbl_80476B50, lbl_80476B50,
    lbl_80476B50, lbl_80476B50, lbl_80476B50, lbl_80476B50,
    lbl_80476B50, lbl_80476B50, lbl_80476B50,
};
__declspec(section ".data") const PlayerMotionEntry ** lbl_804ED728[2] = {
    lbl_804ED690, lbl_804ED6DC,
};
const s32 * lbl_804ED730[19] = {
    lbl_80476ED0, lbl_80476ED0, lbl_80476ED0, lbl_80476ED0,
    lbl_80476ED0, lbl_80476ED0, lbl_80476ED0, lbl_80476ED0,
    lbl_80476ED0, lbl_80476ED0, lbl_80476ED0, lbl_80476ED0,
    lbl_80476ED0, lbl_80476ED0, lbl_80476ED0, lbl_80476ED0,
    lbl_80476ED0, lbl_80476ED0, lbl_80476ED0,
};
const s32 * lbl_804ED77C[19] = {
    lbl_80476FB0, lbl_80476FB0, lbl_80476FB0, lbl_80476FB0,
    lbl_80476FB0, lbl_80476FB0, lbl_80476FB0, lbl_80476FB0,
    lbl_80476FB0, lbl_80476FB0, lbl_80476FB0, lbl_80476FB0,
    lbl_80476FB0, lbl_80476FB0, lbl_80476FB0, lbl_80476FB0,
    lbl_80476FB0, lbl_80476FB0, lbl_80476FB0,
};
__declspec(section ".data") const s32 ** town_player_motion_clip_index_tables[2] = {
    lbl_804ED730, lbl_804ED77C,
};

extern "C" {
s32 is_valid_state__6TLobbyFPvi(void *unused, s32 arg1);
RecoveredGlobal_80329088_lbl_805430E8 lbl_805430E8;
RecoveredGlobal_80329088_lbl_805432A8 lbl_805432A8;
int is_valid_player_motion_variant(void* a0);
int TLobby__sub_802A7278(void* a0);
int is_valid_player_motion_variant(void* a0 = 0);
int TLobby__sub_802A7278(void* a0 = 0);
void check_valid_state__6TLobbyFi(s32 arg0);
s32 is_handle_valid__10TObjPlayerFv();

s32 lbl_805D6C80;

s32 TLobby::get_cell_address(s32 arg1, s32 arg2) {
    struct VObj_80328F7C *o = (struct VObj_80328F7C *)this;
    return lbl_805D6C80 + ((arg2 + (arg1 * o->m73())) << 0xE);
}

s32 is_valid_state__6TLobbyFPvi(void *unused, s32 arg1) {
    switch (arg1) {
    case 0:
    case 3:
        return 0;
    case 1:
    case 2:
    case 4:
    case 5:
        return 1;
    default:
        return 0;
    }
}

void check_valid_state__6TLobbyFi(s32 unused) {
    is_valid_state__6TLobbyFPvi((void *)unused, (s32)((s32)(is_handle_valid__10TObjPlayerFv())));
}

int TUnk_804ED7D0::vfunc_76() {
    struct VObj_80329044 *o = (struct VObj_80329044 *)this;
    o->m75(is_handle_valid__10TObjPlayerFv());
}
typedef char RecoveredGlobal_80329088_lbl_805430E8_size[sizeof(RecoveredGlobal_80329088_lbl_805430E8) == 0x1C0 ? 1 : -1];
typedef char RecoveredGlobal_80329088_lbl_805432A8_size[sizeof(RecoveredGlobal_80329088_lbl_805432A8) == 0x1C0 ? 1 : -1];
s32 *TLobby::get_state_table(s32 _w1) {
    s32 unused = (s32)this;
    s32 *var_r3;
    switch (is_valid_state__6TLobbyFPvi((void *)unused, (s32)_w1)) {
    case 0:
        var_r3 = &lbl_805430E8.value;
        var_r3 = &lbl_805430E8.value;
        return &lbl_805430E8.value;
    case 1:
        var_r3 = &lbl_805432A8.value;
        var_r3 = &lbl_805432A8.value;
        return &lbl_805432A8.value;
    default:
        var_r3 = NULL;
        return NULL;
    }
}

int TUnk_804ED7D0::vfunc_9(s32 a, s32 b, s32 c) {
    return town_player_motion_clip_index_tables[a][b][c];
}

int TUnk_804ED7D0::vfunc_8(s32 arg1, s32 arg2) {
    if (((s32)TLobby__sub_802A7278((void*)arg1)) == 0) {
        return 0;
    }
    if (((s32)is_valid_player_motion_variant((void*)arg2)) != 0) {
        return (int)town_player_motion_clip_index_tables[arg1][arg2];
    }
    return 0;
}
int TUnk_804ED7D0::vfunc_7(s32, s32) {
    s32 i = ((s32 (*)(void))is_valid_state__6TLobbyFPvi)();
    if (((s32 (*)(void))TLobby__sub_802A7278)() != 0) {
        return (int)*lbl_804ED728[i];
    }
    return 0;
}

s32 apply_player_flag_2__6TLobbyFv();
void mem_free(void*);
s32 set_flag_1_at_6c84__6TLobbyFv();

int TUnk_804ED7D0::vfunc_6(s32, s32, s32) { return 1; }
int TUnk_804ED7D0::vfunc_5(s32) {
    s32 arg0 = (s32)this;
    if (set_flag_1_at_6c84__6TLobbyFv() == 0) {
        TLobby::init_object_flag();
        ((TUnk_804DDD28 *)arg0)->load_action_motion_pairs(0, 0, 0);
    }
    if (apply_player_flag_2__6TLobbyFv() == 0) {
        TLobby::apply_state_6c84();
        ((TUnk_804DDD28 *)arg0)->load_action_motion_pairs(1, 1, 0);
    }
    return 1;
}

void TLobby::free_singleton_805D6C80() {
    if ((u32) (*(u32 *)&lbl_805D6C80) != 0U) {
        mem_free((void*)(*(u32 *)&lbl_805D6C80));
        (*(u32 *)&lbl_805D6C80) = 0U;
    }
}

void alloc_work_buffer__6TLobbyFv(void);
void *mem_alloc(u32 size);

void alloc_work_buffer__6TLobbyFv(void) {
    lbl_805D6C80 = (s32)mem_alloc(0x1C0000);
}

void *TLobby__sub_80329310(void *arg0, s16 arg1);
s32 vfunc_3__13TUnk_804DDD28Fs(void *, s32);

void free__10TObjPlayerFPv(void *a0);

void TLobby::update_photon_chairs() { TPlyPhotonChair::free_static_model(); TLobby::free_singleton_805D6C80(); TLobby::set_photon_chair_flag(0); TLobby::clear_flag_at_6c84(); }
void TLobby::update_photon_chair() {
    TLobby::set_photon_chair_flag(0);
    if (((u32 (*)(void))alloc_work_buffer__6TLobbyFv)() == 0U) {
        TLobby::set_photon_chair_flag(1);
        return;
    }
    TPlyPhotonChair::load_resources();
}

extern s32 lbl_804ED7D0[];

void *TLobby__sub_80329310(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 8) = lbl_804ED7D0;
        vfunc_3__13TUnk_804DDD28Fs(arg0, 0);
        if (arg1 > 0) {
            free__10TObjPlayerFPv(arg0);
        }
    }
    return arg0;
}

u8 *TLobby__sub_802A7B50(u8 *arg0);

void *TUnk_804ED7D0::init_vtable8() {
    TLobby__sub_802A7B50((u8 *)this);
    *(s32 **)((s8 *)this + 0x8) = lbl_804ED7D0;
    return this;
}

extern s32 lbl_805D6C84;

void TLobby::init_player_forward() {
    __ct__8FlagWordFv((&lbl_805D6C84));
}

}

__declspec(section ".ctors") static void *const __sinit_TLobby_80328F7C_80329368_cpp_ref = (void *)TLobby::init_player_forward;

#define IVS ((int (*)(void*))is_valid_state__6TLobbyFPvi)
#define CVS ((int (*)(void*))check_valid_state__6TLobbyFi)

int TUnk_804ED7D0::vfunc_11() { return (IVS(this)) == 0; }
int TUnk_804ED7D0::vfunc_10() { return (CVS(this)) == 0; }

int TUnk_804ED7D0::vfunc_13() {
    s32 arg0 = (s32)this;
    return (u8) (((s32)IVS((void*)arg0)) == 1);
}

int TUnk_804ED7D0::vfunc_12() {
    return (u8) (((s32)CVS(this)) == 1);
}

int TUnk_804ED7D0::vfunc_4() {  return lbl_805D6C80; }
