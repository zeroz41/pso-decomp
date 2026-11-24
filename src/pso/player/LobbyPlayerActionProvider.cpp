#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/LobbyPlayerActionProvider.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

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
struct RecoveredGlobal_lbl_805430E8 { s32 value; u8 remaining[0x1BC]; };
RecoveredGlobal_lbl_805430E8 lbl_805430E8;
struct RecoveredGlobal_lbl_805432A8 { s32 value; u8 remaining[0x1BC]; };
RecoveredGlobal_lbl_805432A8 lbl_805432A8;
int is_valid_player_motion_variant(s32 variant = 0);
int TLobby__sub_802A7278(s32 a0 = 0);
void check_valid_state__6TLobbyFi(saddr unused);
s32 is_handle_valid__10TObjPlayerFv();

s32 lobby_action_motion_buffer;
s32 lbl_805D6C84;

int LobbyPlayerActionProvider::get_run_action() {
    s32 t = ((TObjPlayer *)this)->is_handle_valid();
    s32 r = 2;
    if (t == 2) {
        r = 5;
    }
    return r;
}

int LobbyPlayerActionProvider::vfunc_22() {
    s32 t = ((TObjPlayer *)this)->is_handle_valid();
    s32 r = 1;
    if (t == 2) {
        r = 4;
    }
    return r;
}

int LobbyPlayerActionProvider::vfunc_23() {
    return ((((TObjPlayer *)this)->is_handle_valid() - 2) == 0) ? 3 : 0;
}

s32 LobbyPlayerActionProvider::get_cell_address(s32 arg1, s32 arg2) {
    return lobby_action_motion_buffer + ((arg2 + (arg1 * vfunc_75())) << 0xE);
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

void check_valid_state__6TLobbyFi(saddr unused) {
    TLobby::is_valid_state((void *)unused, (s32)((s32)(is_handle_valid__10TObjPlayerFv())));
}

BmlMotionEntry *LobbyPlayerActionProvider::vfunc_76() {
    return reinterpret_cast<BmlMotionEntry *>(get_state_table(((TObjPlayer *)this)->is_handle_valid()));
}
s32 *LobbyPlayerActionProvider::get_state_table(s32 _w1) {
    saddr unused = (saddr)this;
    s32 *var_r3;
    switch (TLobby::is_valid_state((void *)unused, (s32)_w1)) {
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

int LobbyPlayerActionProvider::vfunc_9(s32 a, s32 b, s32 c) {
    return town_player_motion_clip_index_tables[a][b][c];
}

const s32 *LobbyPlayerActionProvider::vfunc_8(s32 arg1, s32 variant) {
    if (((s32)TLobby__sub_802A7278(arg1)) == 0) {
        return NULL;
    }
    if (((s32)is_valid_player_motion_variant(variant)) != 0) {
        return town_player_motion_clip_index_tables[arg1][variant];
    }
    return NULL;
}
int LobbyPlayerActionProvider::vfunc_7(s32, s32) {
    s32 i = ((s32 (*)(void))is_valid_state__6TLobbyFPvi)();
    if (((s32 (*)(void))TLobby__sub_802A7278)() != 0) {
        return (saddr)*lbl_804ED728[i];
    }
    return 0;
}


int LobbyPlayerActionProvider::vfunc_6(s32, s32, s32) { return 1; }
int LobbyPlayerActionProvider::vfunc_5(s32) {
    saddr arg0 = (saddr)this;
    if (TLobby::test_flag_1_at_6c84() == 0) {
        TLobby::init_object_flag();
        ((PlayerActionProvider *)arg0)->load_action_motion_pairs(0, 0, 0);
    }
    if (TLobby::test_flag_2_at_6c84() == 0) {
        TLobby::apply_state_6c84();
        ((PlayerActionProvider *)arg0)->load_action_motion_pairs(1, 1, 0);
    }
    return 1;
}

}

void free_lobby_action_motion_buffer() {
    if ((u32) (*(u32 *)&lobby_action_motion_buffer) != 0U) {
        mem_free((void*)(*(uaddr *)&lobby_action_motion_buffer));
        (*(u32 *)&lobby_action_motion_buffer) = 0U;
    }
}

s32 alloc_lobby_action_motion_buffer() {
    return lobby_action_motion_buffer = (saddr)mem_alloc(0x1C0000);
}


void release_lobby_player_actions() { TPlyPhotonChair::free_static_model(); free_lobby_action_motion_buffer(); set_player_action_provider_selector(0); TLobby::clear_flag_at_6c84(); }
void init_lobby_player_actions() {
    set_player_action_provider_selector(0);
    if ((u32)alloc_lobby_action_motion_buffer() == 0U) {
        set_player_action_provider_selector(1);
        return;
    }
    TPlyPhotonChair::load_resources();
}

LobbyPlayerActionProvider::~LobbyPlayerActionProvider() {}

LobbyPlayerActionProvider::LobbyPlayerActionProvider() {}

void TLobby::init_player_forward() {
    __ct__8FlagWordFv((&lbl_805D6C84));
}

__declspec(section ".ctors") static void *const __sinit_LobbyPlayerActionProvider_cpp_ref = (void *)TLobby::init_player_forward;

#define IVS ((int (*)(void*))is_valid_state__6TLobbyFPvi)
#define CVS ((int (*)(void*))check_valid_state__6TLobbyFi)

int LobbyPlayerActionProvider::vfunc_11() { return (IVS(this)) == 0; }
int LobbyPlayerActionProvider::vfunc_10() { return (CVS(this)) == 0; }

int LobbyPlayerActionProvider::vfunc_13() {
    return (u8) (((s32)IVS(this)) == 1);
}

int LobbyPlayerActionProvider::vfunc_12() {
    return (u8) (((s32)CVS(this)) == 1);
}

int LobbyPlayerActionProvider::vfunc_4() {  return lobby_action_motion_buffer; }

int LobbyPlayerActionProvider::get_knockdown_action() { return 0x6; }
int LobbyPlayerActionProvider::get_hurt_action() { return 0x7; }
int LobbyPlayerActionProvider::get_interact_action() { return 0x8; }
int LobbyPlayerActionProvider::get_use_item_action() { return 0x9; }
int LobbyPlayerActionProvider::vfunc_31() { return 0xA; }
int LobbyPlayerActionProvider::vfunc_32() { return 0xB; }
int LobbyPlayerActionProvider::vfunc_33() { return 0xC; }
int LobbyPlayerActionProvider::vfunc_34() { return 0xD; }
int LobbyPlayerActionProvider::vfunc_35() { return 0xE; }
int LobbyPlayerActionProvider::vfunc_36() { return 0xF; }
int LobbyPlayerActionProvider::vfunc_37() { return 0x10; }
int LobbyPlayerActionProvider::vfunc_38() { return 0x11; }
int LobbyPlayerActionProvider::vfunc_20() { return 0x13; }
int LobbyPlayerActionProvider::vfunc_39() { return 0x14; }
int LobbyPlayerActionProvider::vfunc_40() { return 0x15; }
int LobbyPlayerActionProvider::vfunc_41() { return 0x16; }
int LobbyPlayerActionProvider::vfunc_42() { return 0x17; }
int LobbyPlayerActionProvider::vfunc_43() { return 0x18; }
int LobbyPlayerActionProvider::get_death_action() { return 0x12; }
int LobbyPlayerActionProvider::vfunc_44() { return 0x19; }
int LobbyPlayerActionProvider::vfunc_45() { return 0x1A; }
int LobbyPlayerActionProvider::vfunc_46() { return 0x1B; }
int LobbyPlayerActionProvider::vfunc_47() { return 0x1C; }
int LobbyPlayerActionProvider::vfunc_48() { return 0x1D; }
int LobbyPlayerActionProvider::vfunc_49() { return 0x1E; }
int LobbyPlayerActionProvider::vfunc_50() { return 0x1F; }
int LobbyPlayerActionProvider::vfunc_51() { return 0x20; }
int LobbyPlayerActionProvider::vfunc_52() { return 0x21; }
int LobbyPlayerActionProvider::vfunc_53() { return 0x22; }
int LobbyPlayerActionProvider::vfunc_54() { return 0x23; }
int LobbyPlayerActionProvider::vfunc_55() { return 0x24; }
int LobbyPlayerActionProvider::vfunc_56() { return 0x25; }
int LobbyPlayerActionProvider::vfunc_57() { return 0x26; }
int LobbyPlayerActionProvider::vfunc_58() { return 0x27; }
int LobbyPlayerActionProvider::vfunc_59() { return 0x28; }
int LobbyPlayerActionProvider::vfunc_60() { return 0x29; }
int LobbyPlayerActionProvider::vfunc_61() { return 0x2A; }
int LobbyPlayerActionProvider::vfunc_62() { return 0x2B; }
int LobbyPlayerActionProvider::vfunc_63() { return 0x2C; }
int LobbyPlayerActionProvider::vfunc_64() { return 0x2D; }
int LobbyPlayerActionProvider::vfunc_65() { return 0x2E; }
int LobbyPlayerActionProvider::vfunc_66() { return 0x2F; }
int LobbyPlayerActionProvider::vfunc_67() { return 0x30; }
int LobbyPlayerActionProvider::vfunc_68() { return 0x31; }
int LobbyPlayerActionProvider::vfunc_69() { return 0x32; }
int LobbyPlayerActionProvider::vfunc_70() { return 0x33; }
int LobbyPlayerActionProvider::vfunc_71() { return 0x34; }
int LobbyPlayerActionProvider::vfunc_72() { return 0x35; }
int LobbyPlayerActionProvider::vfunc_75() { return 0x38; }

void TLobby::apply_state_6c84() {
    ((FlagWord *)(&lbl_805D6C84))->set(2);
}

s32 TLobby::test_flag_2_at_6c84() {
    return test_flags_any(&lbl_805D6C84, 2);
}

void TLobby::init_object_flag() {
    ((FlagWord *)(&lbl_805D6C84))->set(1);
}

s32 TLobby::test_flag_1_at_6c84() {
    return test_flags_any(&lbl_805D6C84, 1);
}

void TLobby::clear_flag_at_6c84() {
    ((FlagWord *)(&lbl_805D6C84))->reset();
}
