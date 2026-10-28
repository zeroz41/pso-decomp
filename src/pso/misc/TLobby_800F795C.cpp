#include "pso/protocol/protocol_types.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/boss/TBoss1DragonDemo.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/boss/TBoss7DeRolLeC_802EE4E0.h"
#include "pso/boss/TBoss8Dragon_802F3AB4.h"
#include "pso/enemy/SaverLifecycle.h"
#include "pso/enemy/TObjEneDarkGunCenter.h"
#include "pso/enemy/TObjEneRe2Flower_800C3E14.h"
#include "pso/misc/TLobby_800F795C.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/npc/TObjNpcBase_80149128.h"
#include "pso/npc/TObjNpcFemaleBase_80149C44.h"
#include "pso/npc/TObjNpcFemaleBase_80149C7C.h"
#include "pso/npc/TObjNpcFemaleTall_8014AA48.h"
#include "pso/npc/TObjNpcFemaleTall_8014AA60.h"
#include "pso/npc/TObjNpcLappy_8014B828.h"
#include "pso/npc/TObjNpcLappy_8014B840.h"
#include "pso/player/TObjPlayer_800A894C.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/unk/text_80090488.h"
#include "pso/unk/text_8009F410.h"
#include "pso/unk/text_8035B6B0.h"
#include "pso/unk/text_8035B750.h"
#include "pso/unk/text_8035B788.h"
#include "pso/system/byteswap.h"
#include "pso/boss/TBoss5Gryphon.h"
#include "pso/enemy/TObjEneGyaranzo.h"
#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/enemy/TObjEnePanarms.h"

#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/boss/TBoss1Dragon.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/boss/TBoss7DeRolLeC.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneBalClaw.h"
#include "pso/enemy/TObjEneBalClawClaw.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/enemy/TObjEneBm3FlyNest.h"
#include "pso/enemy/TObjEneBm5GibonU.h"
#include "pso/enemy/TObjEneBm5Wolf.h"
#include "pso/enemy/TObjEneBm9Mericarol.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDelDepth.h"
#include "pso/enemy/TObjEneDellBiter.h"
#include "pso/enemy/TObjEneDf2Bringer.h"
#include "pso/enemy/TObjEneDimedian.h"
#include "pso/enemy/TObjEneDolmOlm.h"
#include "pso/enemy/TObjEneEpsilonGuard.h"
#include "pso/enemy/TObjEneGibbles.h"
#include "pso/enemy/TObjEneIllGill.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe1Gee.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/enemy/TObjEneMe3ShinowaMirage.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEneMerillLia.h"
#include "pso/enemy/TObjEneMoja.h"
#include "pso/enemy/TObjEneMorfos.h"
#include "pso/enemy/TObjEneRe2Flower.h"
#include "pso/enemy/TObjEneRe4Sorcerer.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/enemy/TObjEneRecobox.h"
#include "pso/enemy/TObjEneShark.h"
#include "pso/enemy/TObjEneSlime.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/misc/TOCtrlDubchik.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TPlyPhotonChair.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcCloakroomBase.h"
#include "pso/npc/TObjNpcConnoisseur.h"
#include "pso/npc/TObjNpcExpertBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/npc/TObjNpcFemaleChild.h"
#include "pso/npc/TObjNpcFemaleDwarf.h"
#include "pso/npc/TObjNpcFemaleFat.h"
#include "pso/npc/TObjNpcFemaleMacho.h"
#include "pso/npc/TObjNpcFemaleOld.h"
#include "pso/npc/TObjNpcFemaleTall.h"
#include "pso/npc/TObjNpcGovernorBase.h"
#include "pso/npc/TObjNpcHFW00.h"
#include "pso/npc/TObjNpcHFW01.h"
#include "pso/npc/TObjNpcHHM00.h"
#include "pso/npc/TObjNpcHRM00.h"
#include "pso/npc/TObjNpcHRM01.h"
#include "pso/npc/TObjNpcHosa.h"
#include "pso/npc/TObjNpcHosa2.h"
#include "pso/npc/TObjNpcKenkyu.h"
#include "pso/npc/TObjNpcKenkyu2.h"
#include "pso/npc/TObjNpcKenkyuW.h"
#include "pso/npc/TObjNpcMaleBase.h"
#include "pso/npc/TObjNpcMaleChild.h"
#include "pso/npc/TObjNpcMaleDwarf.h"
#include "pso/npc/TObjNpcMaleFat.h"
#include "pso/npc/TObjNpcMaleMacho.h"
#include "pso/npc/TObjNpcMaleOld.h"
#include "pso/npc/TObjNpcMaleTall.h"
#include "pso/npc/TObjNpcNFM00.h"
#include "pso/npc/TObjNpcNFM01.h"
#include "pso/npc/TObjNpcNFW00.h"
#include "pso/npc/TObjNpcNFW01.h"
#include "pso/npc/TObjNpcNHW00.h"
#include "pso/npc/TObjNpcNHW01.h"
#include "pso/npc/TObjNpcNgcBase.h"
#include "pso/npc/TObjNpcNurseBase.h"
#include "pso/npc/TObjNpcSecretaryBase.h"
#include "pso/npc/TObjNpcSoldierBase.h"
#include "pso/npc/TObjNpcSoldierMacho.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/object/TObjCGrass.h"
#include "pso/object/TObjGrass.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_800C7FEC.h"

struct RecoveredGlobal_800F7A6C_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_800F7A7C_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

extern RecoveredGlobal_800F7A6C_lbl_804DB1F0 lbl_804DB1F0;
extern RecoveredGlobal_800F7A7C_lbl_8048C9D8 challenge_mode_state;
extern "C" {
s32 is_area_transfer_pending();

void TLobby::bswap_field() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); }
void TLobby::broadcast_state() { bswap_field(); send_subcommand((u8 *)this); }
}

void init_6x9C_enemy_low_game_flags_packet(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0x9C;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TLobby::bswap_enemy_state() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }
void send_6x0A_enemy_state_packet(void* p) { ((TLobby *)p)->bswap_enemy_state(); send_subcommand((u8 *)p); }
void init_6x0A_enemy_state_packet(void* p) { *(u8*)((char*)p + 0x0) = 10; *(u8*)((char*)p + 0x1) = 3; }
int get_attack_credit_slot_count(void) { return 4; }

typedef char RecoveredGlobal_800F7A6C_lbl_804DB1F0_size[sizeof(RecoveredGlobal_800F7A6C_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
f32 TLobby__sub_800F7A6C(void) {
    return *(f32 *)((s8 *)&lbl_804DB1F0.value + 4);
}

typedef char RecoveredGlobal_800F7A7C_lbl_8048C9D8_size[sizeof(RecoveredGlobal_800F7A7C_lbl_8048C9D8) == 0x748 ? 1 : -1];
f32 TLobby__sub_800F7A7C(void) {
    return *(f32 *)((s8 *)&challenge_mode_state.value + 4);
}

void unload_floor_resources(s32 arg0) {
    FloorResourceCallbacks *p = floor_resource_callback_tables[arg0];
    s32 n;
    s32 i;
    if (p != 0) {
        n = 0;
        while (p->unload != 0) { p++; n++; }
        for (i = 0; i < n; i++) {
            void (*fn)() = p[-1].unload;
            p--;
            fn();
        }
    }
}
s32 load_floor_resources(s32 arg0) {
    FloorResourceCallbacks *p = floor_resource_callback_tables[arg0];
    void (*fn)();
    if (p == 0) {
        return 1;
    }
    while ((fn = p->load) != 0) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        fn();
        p++;
    }
    return 1;
}
void unload_current_floor_resources(void) {
    unload_floor_resources(TOKeyMachine01::get_global_state());
}

s32 load_current_floor_resources(void) {
    return load_floor_resources(TOKeyMachine01::get_global_state());
}
extern "C" {

void load_resources__12TBoss1DragonFv();
void TBoss8Dragon__sub_80065C90();
void TObjEneBalClaw__sub_8008D924();
void fn_8009F554();
void TObjPlayer__sub_800A2DCC();
void load_resources__11TObjEneMojaFv();
void TObjEneMerillLia__sub_800D6D64();
void TLobby__sub_800DC028();
void TObjEneMe3ShinowaMirage__sub_800E7B94();
void TBoss4Type3__sub_802D1130();
void TBoss8Dragon__sub_802FDA78();
void TObjEneMe3SinowZoa__sub_8031B240();
void TObjEneMorfos__sub_803350AC();

FloorResourceCallbacks floor_resource_callbacks_selector_00[43] = {
    { load_ply_motion_npc_town, TObjNpcBase::free_static },
    { TObjNpcFemaleBase__sub_80149C7C, TObjNpcFemaleBase__sub_80149C64 },
    { TObjNpcFemaleTall__sub_8014AA60, TObjNpcFemaleTall__sub_8014AA48 },
    { TObjNpcLappy__sub_8014B840, TObjNpcLappy__sub_8014B828 },
    { TObjNpcFemaleBase::load_shared_resource, TObjNpcFemaleBase::free_static_data },
    { TObjNpcFemaleChild::load_shared_resource, TObjNpcFemaleChild::release_static_instance },
    { TObjNpcFemaleDwarf::load_static_resource, TObjNpcFemaleDwarf::unload_static_data },
    { TObjNpcFemaleFat::load_static_resource, TObjNpcFemaleFat::free_static_model },
    { TObjNpcFemaleMacho::load_resources, TObjNpcFemaleMacho::close_dialog_window },
    { TObjNpcFemaleOld::load_resource_instance, TObjNpcFemaleOld::destroy_static_instance },
    { TObjNpcFemaleTall::load_resource_instance, TObjNpcFemaleTall::destroy_instance },
    { TObjNpcMaleBase::load_shared_resource, TObjNpcMaleBase::free_static_data },
    { TObjNpcMaleChild::load_shared_resource, TObjNpcMaleChild::release_static_instance },
    { TObjNpcMaleDwarf::load_shared_resource, TObjNpcMaleDwarf::unload_static_data },
    { TObjNpcMaleFat::load_static_resource, TObjNpcMaleFat::free_static_model },
    { TObjNpcMaleMacho::load_static_resource, TObjNpcMaleMacho::close_dialog_window },
    { TObjNpcMaleOld::load_resource_instance, TObjNpcMaleOld::destroy_static_instance },
    { TObjNpcMaleTall::load_resource_instance, TObjNpcMaleTall::destroy_instance },
    { TObjNpcConnoisseur::load_section_motion, TObjNpcConnoisseur::destroy_instance },
    { TObjNpcSoldierBase::load_shared_resource, TObjNpcSoldierBase::release_static_instance },
    { TObjNpcSoldierMacho::load_shared_resource, TObjNpcSoldierMacho::unload_static_data },
    { TObjNpcGovernorBase::load_shared_resource, TObjNpcGovernorBase::free_shared_data },
    { TObjNpcCloakroomBase::load_shared_resource, TObjNpcCloakroomBase::destroy_static_instance },
    { TObjNpcExpertBase::load_shared_resource, TObjNpcExpertBase::free_shared_data },
    { TObjNpcNurseBase::load_shared_data, TObjNpcNurseBase::free_shared_data },
    { TObjNpcSecretaryBase::load_static_data, TObjNpcSecretaryBase::free_static_data },
    { TObjNpcHHM00::load_resources, TObjNpcHHM00::free_resources },
    { TObjNpcNHW00::load_resources, TObjNpcNHW00::free_static_resources },
    { TObjNpcHRM00::load_resources, TObjNpcHRM00::destroy_resources },
    { TObjNpcARM00::load_resources, TObjNpcARM00::free_resources },
    { TObjNpcARW00::load_resources, TObjNpcARW00::free_resources },
    { TObjNpcHFW00::load_resources, TObjNpcHFW00::free_resources },
    { TObjNpcNFM00::load_assets, TObjNpcNFM00::free_resources },
    { TObjNpcNFW00::load_assets, TObjNpcNFW00::free_resources },
    { TObjNpcNHW01::load_resources, TObjNpcNHW01::free_resources },
    { TObjNpcAHM01::load_resources, TObjNpcAHM01::free_resources },
    { TObjNpcHRM01::load_resources, TObjNpcHRM01::free_shared_objects },
    { TObjNpcHFW01::load_resources, TObjNpcHFW01::free_static_resources },
    { TObjNpcNFM01::load_resources, TObjNpcNFM01::free_resources },
    { TObjNpcNFW01::load_resources, TObjNpcNFW01::free_resources },
    { TObjNpcKenkyu::load_shared_resource, TObjNpcKenkyu::free_static_model },
    { TObjNpcSoutokufu::load_shared_resource, TObjNpcSoutokufu::close_dialog_window },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_01[8] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneBeast::load_resources, free_boss4_rock_pool },
    { TObjEneLappy::load_resources, TLobby::cleanup_handles },
    { TObjEneBm3FlyNest::load_resources, TObjEneBm3FlyNest::free_fly },
    { TObjEneBm5Wolf::load_resources, TObjEneBm5Wolf::release_global_805D5120 },
    { load_and_spawn_chao_npc, TPlyPhotonChair::free_instance },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_02[10] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { load_resources__11TObjEneMojaFv, TObjEneMoja::free_resources },
    { TObjEneLappy::load_resources, TLobby::cleanup_handles },
    { TObjEneBm3FlyNest::load_resources, TObjEneBm3FlyNest::free_fly },
    { TObjEneBm5Wolf::load_resources, TObjEneBm5Wolf::release_global_805D5120 },
    { TObjEneBeast::load_resources, free_boss4_rock_pool },
    { load_and_spawn_chao_npc, TPlyPhotonChair::free_instance },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_03[10] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::release_global_805D5130 },
    { TObjPlayer__sub_800C44C4, TObjEneRe2Flower::destroy_instance },
    { TLobby__sub_800DC028, TLobby::free_global_window },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { TObjEnePanarms::load_and_spawn_npc, TObjEnePanarms::free_data },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_04[10] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::release_global_805D5130 },
    { TObjPlayer__sub_800C44C4, TObjEneRe2Flower::destroy_instance },
    { TLobby__sub_800DC028, TLobby::free_global_window },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { TObjEneSlime::spawn_pair, TObjEneSlime::free_instance },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_05[12] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjPlayer__sub_800C44C4, TObjEneRe2Flower::destroy_instance },
    { TLobby__sub_800DC028, TLobby::free_global_window },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { TObjEneSlime::spawn_pair, TObjEneSlime::free_instance },
    { TObjEnePanarms::load_and_spawn_npc, TObjEnePanarms::free_data },
    { load_ply_motion_npc_town, TObjNpcBase::free_static },
    { TObjNpcFemaleBase__sub_80149C7C, TObjNpcFemaleBase__sub_80149C64 },
    { TObjNpcCloakroomBase::load_shared_resource, TObjNpcCloakroomBase::destroy_static_instance },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selectors_06_07[9] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjPlayer__sub_800AA82C, TObjPlayer::free_effect_resources },
    { TLobby::load_gyaranzo_resources, TObjEneGyaranzo::free_static_instances },
    { TObjEneMe3ShinowaMirage__sub_800E7B94, TObjEneMe3ShinowaMirage::free_shared_resources },
    { fn_8009F554, fn_8009F410 },
    { TOCtrlDubchik::load_shared_resource, TOCtrlDubchik::destroy_instance },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_08[11] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { initialize_saver_resources, TObjPlayer::free_resources },
    { TObjEneRe4Sorcerer::load_resources, TObjEneRe4Sorcerer::free_bits },
    { TObjEneRe7Berura::load_static_resources, TObjEneRe7Berura::destroy_children },
    { TLobby::load_dimedian_resources, TObjEneDimedian::free_boss_objects },
    { TObjEneBalClaw__sub_8008D924, TObjEneBalClaw::release_global_805D4F20 },
    { TObjEneBalClawClaw::spawn_child_enemy, TObjEneBalClawClaw__sub_8008DC14 },
    { spawn_lobby_npc_enemy, fn_80090488 },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_09[10] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { initialize_saver_resources, TObjPlayer::free_resources },
    { TObjPlayer__sub_800A2DCC, TObjPlayer::cleanup_effects },
    { TObjEneDarkGunCenter__sub_800A0E80, TObjEneDarkGunCenter__sub_800A0E7C },
    { TObjEneDf2Bringer::load_resources, TObjEneDf2Bringer::free_resources },
    { TLobby::load_dimedian_resources, TObjEneDimedian::free_boss_objects },
    { TObjEneBalClaw__sub_8008D924, TObjEneBalClaw::release_global_805D4F20 },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_10[11] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneRe4Sorcerer::load_resources, TObjEneRe4Sorcerer::free_bits },
    { TObjPlayer__sub_800A2DCC, TObjPlayer::cleanup_effects },
    { TObjEneDarkGunCenter__sub_800A0E80, TObjEneDarkGunCenter__sub_800A0E7C },
    { TObjEneDf2Bringer::load_resources, TObjEneDf2Bringer::free_resources },
    { TObjEneRe7Berura::load_static_resources, TObjEneRe7Berura::destroy_children },
    { TLobby::load_dimedian_resources, TObjEneDimedian::free_boss_objects },
    { TObjEneBalClaw__sub_8008D924, TObjEneBalClaw::release_global_805D4F20 },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_11[6] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TBoss1DragonDemo__sub_8002B690, TBoss1DragonDemo__sub_8002B68C },
    { load_resources__12TBoss1DragonFv, TBoss1Dragon::free_resources },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_12[5] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { load_resources__13TBoss2DeRolLeFv, reset_parts__13TBoss2DeRolLeFv },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_13[4] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TBoss3Volopt::load_resources, TBoss3Volopt::free_parts },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_14[2] = {
    { TBoss4DarkFalz::load_resources, TBoss4DarkFalz::cleanup_global },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_31[2] = {
    { TBoss6PlotFalz::load_resources, TBoss6PlotFalz::free_all },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_32[5] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjPlayer__sub_802EE574, TBoss7DeRolLeC::run_exit_callbacks },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_33[6] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { clear_boss8_dragon_leader_part, TBoss8Dragon__sub_802F3C74 },
    { TBoss8Dragon__sub_802FDA78, TBoss8Dragon::free_static },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

__declspec(section ".data") FloorResourceCallbacks floor_resource_callbacks_selector_15[1] = {
    { 0, 0 },
};
}

FloorResourceCallbacks floor_resource_callbacks_selector_16[10] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { load_resources__11TObjEneMojaFv, TObjEneMoja::free_resources },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::release_global_805D5130 },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { TObjEneMe3ShinowaMirage__sub_800E7B94, TObjEneMe3ShinowaMirage::free_shared_resources },
    { initialize_saver_resources, TObjPlayer::free_resources },
    { TObjEneDf2Bringer::load_resources, TObjEneDf2Bringer::free_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_17[10] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { load_resources__11TObjEneMojaFv, TObjEneMoja::free_resources },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::release_global_805D5130 },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { TObjEneMe3ShinowaMirage__sub_800E7B94, TObjEneMe3ShinowaMirage::free_shared_resources },
    { initialize_saver_resources, TObjPlayer::free_resources },
    { TObjEneDf2Bringer::load_resources, TObjEneDf2Bringer::free_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_18[29] = {
    { load_ply_motion_npc_town, TObjNpcBase::free_static },
    { TObjNpcFemaleBase__sub_80149C7C, TObjNpcFemaleBase__sub_80149C64 },
    { TObjNpcFemaleTall__sub_8014AA60, TObjNpcFemaleTall__sub_8014AA48 },
    { TObjNpcLappy__sub_8014B840, TObjNpcLappy__sub_8014B828 },
    { TObjNpcFemaleDwarf::load_static_resource, TObjNpcFemaleDwarf::unload_static_data },
    { TObjNpcFemaleOld::load_resource_instance, TObjNpcFemaleOld::destroy_static_instance },
    { TObjNpcMaleChild::load_shared_resource, TObjNpcMaleChild::release_static_instance },
    { TObjNpcMaleFat::load_static_resource, TObjNpcMaleFat::free_static_model },
    { TObjNpcMaleOld::load_resource_instance, TObjNpcMaleOld::destroy_static_instance },
    { TObjNpcMaleTall::load_resource_instance, TObjNpcMaleTall::destroy_instance },
    { TObjNpcConnoisseur::load_section_motion, TObjNpcConnoisseur::destroy_instance },
    { TObjNpcSoldierBase::load_shared_resource, TObjNpcSoldierBase::release_static_instance },
    { TObjNpcGovernorBase::load_shared_resource, TObjNpcGovernorBase::free_shared_data },
    { TObjNpcCloakroomBase::load_shared_resource, TObjNpcCloakroomBase::destroy_static_instance },
    { TObjNpcNurseBase::load_shared_data, TObjNpcNurseBase::free_shared_data },
    { TObjNpcSecretaryBase::load_static_data, TObjNpcSecretaryBase::free_static_data },
    { TObjNpcARM00::load_resources, TObjNpcARM00::free_resources },
    { TObjNpcARW00::load_resources, TObjNpcARW00::free_resources },
    { TObjNpcHFW00::load_resources, TObjNpcHFW00::free_resources },
    { TObjNpcNFM00::load_assets, TObjNpcNFM00::free_resources },
    { TObjNpcNFM01::load_resources, TObjNpcNFM01::free_resources },
    { TObjNpcKenkyu::load_shared_resource, TObjNpcKenkyu::free_static_model },
    { TObjNpcSoutokufu::load_shared_resource, TObjNpcSoutokufu::close_dialog_window },
    { TObjNpcHosa::load_static_resource, TObjNpcHosa::destroy_static_instance },
    { TObjNpcKenkyuW::load_resource_instance, TObjNpcKenkyuW::destroy_instance },
    { TObjNpcHosa2::load_shared_resource, TObjNpcHosa2::close_dialog_window },
    { TObjNpcKenkyu2::load_shared_resource, TObjNpcKenkyu2::free_static_model },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_21[9] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjPlayer__sub_800AA82C, TObjPlayer::free_effect_resources },
    { TOCtrlDubchik::load_shared_resource, TOCtrlDubchik::destroy_instance },
    { TLobby::load_gyaranzo_resources, TObjEneGyaranzo::free_static_instances },
    { TObjEneBm5Wolf::load_resources, TObjEneBm5Wolf::release_global_805D5120 },
    { TObjEnePanarms::load_and_spawn_npc, TObjEnePanarms::free_data },
    { initialize_saver_resources, TObjPlayer::free_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_22[9] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjPlayer__sub_800AA82C, TObjPlayer::free_effect_resources },
    { TOCtrlDubchik::load_shared_resource, TOCtrlDubchik::destroy_instance },
    { TObjEneBm5Wolf::load_resources, TObjEneBm5Wolf::release_global_805D5120 },
    { TObjEnePanarms::load_and_spawn_npc, TObjEnePanarms::free_data },
    { initialize_saver_resources, TObjPlayer::free_resources },
    { TObjEneRe4Sorcerer::load_resources, TObjEneRe4Sorcerer::free_bits },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selectors_19_20[11] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneLappy::load_resources, TLobby::cleanup_handles },
    { load_resources__11TObjEneMojaFv, TObjEneMoja::free_resources },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::release_global_805D5130 },
    { TObjPlayer__sub_800C44C4, TObjEneRe2Flower::destroy_instance },
    { TObjEneBm3FlyNest::load_resources, TObjEneBm3FlyNest::free_fly },
    { TLobby::load_dimedian_resources, TObjEneDimedian::free_boss_objects },
    { TObjEneRe7Berura::load_static_resources, TObjEneRe7Berura::destroy_children },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selectors_23_24_25_26_27[16] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneMe3Stelth::load_shared_resources, TObjEneMe3Stelth::free_shared_resources },
    { TObjEneMerillLia__sub_800D6D64, TObjEneMerillLia::destroy_rocks },
    { TBoss4Type3__sub_802D1130, TObjEneBm9Mericarol::free_shared_instances },
    { TObjEneBm5GibonU::load_resources, TObjEneBm5GibonU::release_static_resource },
    { TObjEneGibbles::load_resources, TObjEneGibbles::free_static },
    { TObjEneMe1Gee::load_resources, TObjEneMe1Gee::free_globals },
    { TObjEneMe1GiGue::load_resources, TObjEneMe1GiGue::delete_barrier },
    { TObjEneLappy::load_resources, TLobby::cleanup_handles },
    { load_ply_motion_npc_town, TObjNpcBase::free_static },
    { TObjNpcFemaleBase__sub_80149C7C, TObjNpcFemaleBase__sub_80149C64 },
    { TObjNpcFemaleTall__sub_8014AA60, TObjNpcFemaleTall__sub_8014AA48 },
    { TObjNpcLappy__sub_8014B840, TObjNpcLappy__sub_8014B828 },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_34[15] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneDolmOlm::load_shared_resources, TObjEneDolmOlm::free_shared_resources },
    { TObjEneRecobox::load_resources, TObjEneRecobox::release_static_instance },
    { TObjEneMerillLia__sub_800D6D64, TObjEneMerillLia::destroy_rocks },
    { TObjEneBm5GibonU::load_resources, TObjEneBm5GibonU::release_static_resource },
    { TObjEneMe1Gee::load_resources, TObjEneMe1Gee::free_globals },
    { fn_8035B788, fn_8035B750 },
    { TObjEneLappy::load_resources, TLobby::cleanup_handles },
    { load_ply_motion_npc_town, TObjNpcBase::free_static },
    { TObjNpcFemaleBase__sub_80149C7C, TObjNpcFemaleBase__sub_80149C64 },
    { TObjNpcFemaleTall__sub_8014AA60, TObjNpcFemaleTall__sub_8014AA48 },
    { TObjNpcLappy__sub_8014B840, TObjNpcLappy__sub_8014B828 },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_35[16] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TBoss4Type3__sub_802D1130, TObjEneBm9Mericarol::free_shared_instances },
    { TObjEneGibbles::load_resources, TObjEneGibbles::free_static },
    { TObjEneMe1GiGue::load_resources, TObjEneMe1GiGue::delete_barrier },
    { TObjEneRecobox::load_resources, TObjEneRecobox::release_static_instance },
    { TObjEneDellBiter::load_resources, TObjEneDellBiter::destroy_static_instance },
    { TObjEneEpsilonGuard::load_assets, TObjEneEpsilonGuard::free_shared_resources },
    { TObjPlayer__sub_800C44C4, TObjEneRe2Flower::destroy_instance },
    { TObjEneIllGill::load_shared_resources, TObjEneIllGill::free_effect },
    { load_ply_motion_npc_town, TObjNpcBase::free_static },
    { TObjNpcFemaleBase__sub_80149C7C, TObjNpcFemaleBase__sub_80149C64 },
    { TObjNpcFemaleTall__sub_8014AA60, TObjNpcFemaleTall__sub_8014AA48 },
    { TObjNpcLappy__sub_8014B840, TObjNpcLappy__sub_8014B828 },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selectors_28_29[14] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneDolmOlm::load_shared_resources, TObjEneDolmOlm::free_shared_resources },
    { TObjEneMorfos__sub_803350AC, TObjEneMorfos::unload_static_data },
    { TObjEneRecobox::load_resources, TObjEneRecobox::release_static_instance },
    { TObjEneMe3SinowZoa__sub_8031B240, TObjEneMe3SinowZoa::free_resources },
    { TObjEneDelDepth::load_assets, TObjEneDelDepth::free_shared_data },
    { TObjEneDellBiter::load_resources, TObjEneDellBiter::destroy_static_instance },
    { load_ply_motion_npc_town, TObjNpcBase::free_static },
    { TObjNpcFemaleBase__sub_80149C7C, TObjNpcFemaleBase__sub_80149C64 },
    { TObjNpcFemaleTall__sub_8014AA60, TObjNpcFemaleTall__sub_8014AA48 },
    { TObjNpcLappy__sub_8014B840, TObjNpcLappy__sub_8014B828 },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_30[4] = {
    { load_corpse_mark_resource, TObjPlayer::destroy_static_lobby },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TBoss8Dragon__sub_80065C90, TBoss5Gryphon::cleanup },
    { 0, 0 },
};

FloorResourceCallbacks* floor_resource_callback_tables[36] = {
    floor_resource_callbacks_selector_00,
    floor_resource_callbacks_selector_01,
    floor_resource_callbacks_selector_02,
    floor_resource_callbacks_selector_03,
    floor_resource_callbacks_selector_04,
    floor_resource_callbacks_selector_05,
    floor_resource_callbacks_selectors_06_07,
    floor_resource_callbacks_selectors_06_07,
    floor_resource_callbacks_selector_08,
    floor_resource_callbacks_selector_09,
    floor_resource_callbacks_selector_10,
    floor_resource_callbacks_selector_11,
    floor_resource_callbacks_selector_12,
    floor_resource_callbacks_selector_13,
    floor_resource_callbacks_selector_14,
    floor_resource_callbacks_selector_15,
    floor_resource_callbacks_selector_16,
    floor_resource_callbacks_selector_17,
    floor_resource_callbacks_selector_18,
    floor_resource_callbacks_selectors_19_20,
    floor_resource_callbacks_selectors_19_20,
    floor_resource_callbacks_selector_21,
    floor_resource_callbacks_selector_22,
    floor_resource_callbacks_selectors_23_24_25_26_27,
    floor_resource_callbacks_selectors_23_24_25_26_27,
    floor_resource_callbacks_selectors_23_24_25_26_27,
    floor_resource_callbacks_selectors_23_24_25_26_27,
    floor_resource_callbacks_selectors_23_24_25_26_27,
    floor_resource_callbacks_selectors_28_29,
    floor_resource_callbacks_selectors_28_29,
    floor_resource_callbacks_selector_30,
    floor_resource_callbacks_selector_31,
    floor_resource_callbacks_selector_32,
    floor_resource_callbacks_selector_33,
    floor_resource_callbacks_selector_34,
    floor_resource_callbacks_selector_35,
};
