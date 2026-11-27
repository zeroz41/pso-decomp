#include "pso/enemy/nanodrago/TObjEneNanoDrago.h"
#include "pso/enemy/darkgunner/DarkGunner.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/boss/dragon/TBoss1DragonDemo.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3AB4.h"
#include "pso/enemy/saver/SaverLifecycle.h"
#include "pso/enemy/saver/TObjEneSaver.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunCenter.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunner.h"
#include "pso/enemy/EnemyStateSync.h"
#include "pso/network/TGameProtocol.h"
#include "pso/npc/TObjNpcFemale.h"
#include "pso/npc/TObjNpcFomarl.h"
#include "pso/npc/TObjNpcMale.h"
#include "pso/enemy/dubchik/TObjEneDubchik.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin.h"
#include "pso/npc/ChaoNpcSpawn.h"
#include "pso/npc/NightsNpcResource.h"
#include "pso/system/byteswap.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/enemy/gyaranzo/TObjEneGyaranzo.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "pso/enemy/balclaw/TObjEneBalClawBody.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest.h"
#include "pso/enemy/gibon/TObjEneBm5GibonU.h"
#include "pso/enemy/wolf/TObjEneBm5Wolf.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/deldepth/TObjEneDelDepth.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter.h"
#include "pso/enemy/bringer/TObjEneDf2Bringer.h"
#include "pso/enemy/dimedian/TObjEneDimedian.h"
#include "pso/enemy/dolmolm/TObjEneDolmOlm.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/enemy/gibbles/TObjEneGibbles.h"
#include "pso/enemy/illgill/TObjEneIllGill.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaMirage.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/merilllia/TObjEneMerillLia.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "pso/enemy/morfos/TObjEneMorfos.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/enemy/shark/TObjEneShark.h"
#include "pso/enemy/slime/TObjEneSlime.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/dubchik/TOCtrlDubchik.h"
#include "pso/player/TPlyPhotonChair.h"
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
#include "pso/object/ambient/TObjCGrass.h"
#include "pso/object/ambient/TObjGrass.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/LegacyEnemyKill.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/object/TDeadSpot.h"
void G_SetEnemyLowGameFlagsUltimate_6x9C::bswap() {
    ((G_ClientIDHeader *)&header)->bswap();
    bswap_32((u32 *)&status_effect_flags);
}

void G_SetEnemyLowGameFlagsUltimate_6x9C::send() {
    bswap();
    send_subcommand(this);
}

void init_6x9C_enemy_low_game_flags_packet(G_SetEnemyLowGameFlagsUltimate_6x9C *packet) {
    packet->status_effect_flags = 0;
    packet->header.subcommand = 0x9C;
    packet->header.size = 2;
}

void G_UpdateEnemyState_6x0A::bswap() {
    ((G_ClientIDHeader *)&header)->bswap();
    bswap_16(&enemy_index);
    bswap_16((u16 *)&total_damage);
}

void G_UpdateEnemyState_6x0A::send() {
    bswap();
    send_subcommand(this);
}

void init_6x0A_enemy_state_packet(G_UpdateEnemyState_6x0A *packet) {
    packet->header.subcommand = 0x0A;
    packet->header.size = sizeof(G_UpdateEnemyState_6x0A) / 4;
}
int get_attack_credit_slot_count(TObjEnemy *) { return 4; }

f32 get_challenge4p_exp_multiplier(void) {
    return challenge4p_mode_state.exp_multiplier;
}

f32 get_challenge_exp_multiplier(void) {
    return challenge_mode_state.exp_multiplier;
}

void unload_floor_resources(s32 selector) {
    FloorResourceCallbacks *p = floor_resource_callback_tables[selector];
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
s32 load_floor_resources(s32 selector) {
    FloorResourceCallbacks *p = floor_resource_callback_tables[selector];
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
    unload_floor_resources(get_current_floor_area());
}

s32 load_current_floor_resources(void) {
    return load_floor_resources(get_current_floor_area());
}
extern "C" {

void load_boss5_gryphon_resources();


FloorResourceCallbacks floor_resource_callbacks_selector_00[43] = {
    { TObjNpcBase::load_resources, TObjNpcBase::free_static },
    { TObjNpcFemale::load_resources, TObjNpcFemale::free_resources },
    { TObjNpcFomarl::load_resources, TObjNpcFomarl::free_resources },
    { TObjNpcMale::load_resources, TObjNpcMale::free_resources },
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
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneBeast::load_resources, free_boss4_rock_pool },
    { TObjEneLappy::load_resources, TObjEneLappy::free_resources },
    { TObjEneBm3FlyNest::load_resources, TObjEneBm3FlyNest::free_fly },
    { TObjEneBm5Wolf::load_resources, TObjEneBm5Wolf::free_resources },
    { load_and_spawn_chao_npc, TPlyPhotonChair::free_instance },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_02[10] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneMoja::load_resources, TObjEneMoja::free_resources },
    { TObjEneLappy::load_resources, TObjEneLappy::free_resources },
    { TObjEneBm3FlyNest::load_resources, TObjEneBm3FlyNest::free_fly },
    { TObjEneBm5Wolf::load_resources, TObjEneBm5Wolf::free_resources },
    { TObjEneBeast::load_resources, free_boss4_rock_pool },
    { load_and_spawn_chao_npc, TPlyPhotonChair::free_instance },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_03[10] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::free_resources },
    { load_re2_flower_resources, TObjEneRe2Flower::destroy_instance },
    { TObjEneNanoDrago::load_resources, TObjEneNanoDrago::free_resources },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { TObjEnePanarms::load_and_spawn_npc, TObjEnePanarms::free_data },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_04[10] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::free_resources },
    { load_re2_flower_resources, TObjEneRe2Flower::destroy_instance },
    { TObjEneNanoDrago::load_resources, TObjEneNanoDrago::free_resources },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { TObjEneSlime::spawn_pair, TObjEneSlime::free_instance },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_05[12] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { load_re2_flower_resources, TObjEneRe2Flower::destroy_instance },
    { TObjEneNanoDrago::load_resources, TObjEneNanoDrago::free_resources },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { TObjEneSlime::spawn_pair, TObjEneSlime::free_instance },
    { TObjEnePanarms::load_and_spawn_npc, TObjEnePanarms::free_data },
    { TObjNpcBase::load_resources, TObjNpcBase::free_static },
    { TObjNpcFemale::load_resources, TObjNpcFemale::free_resources },
    { TObjNpcCloakroomBase::load_shared_resource, TObjNpcCloakroomBase::destroy_static_instance },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selectors_06_07[9] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneDubchik::load_resources, TObjEneDubchik::free_resources },
    { TLobby::load_gyaranzo_resources, TObjEneGyaranzo::free_static_instances },
    { load_shinowa_mirage_resources, TObjEneMe3ShinowaMirage::free_shared_resources },
    { TObjEneMe1Canadin::load_resources, TObjEneMe1Canadin::free_resources },
    { TOCtrlDubchik::load_shared_resource, TOCtrlDubchik::destroy_instance },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_08[11] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { initialize_saver_resources, TObjEneSaver::free_resources },
    { TObjEneRe4Sorcerer::load_resources, TObjEneRe4Sorcerer::free_bits },
    { TObjEneRe7Berura::load_static_resources, TObjEneRe7Berura::destroy_children },
    { TLobby::load_dimedian_resources, TObjEneDimedian::free_boss_objects },
    { TObjEneBalClaw::load_resources, TObjEneBalClaw::free_resources },
    { TObjEneBalClawBody::load_resources, TObjEneBalClawBody::free_resources },
    { TObjEneBalClawClaw::load_resources, TObjEneBalClawClaw::free_resources },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_09[10] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { initialize_saver_resources, TObjEneSaver::free_resources },
    { load_darkgunner_effect_resources, TObjEneDarkGunner::cleanup_effects },
    { TObjEneDarkGunCenter::load_resources, TObjEneDarkGunCenter::free_resources },
    { TObjEneDf2Bringer::load_resources, TObjEneDf2Bringer::free_resources },
    { TLobby::load_dimedian_resources, TObjEneDimedian::free_boss_objects },
    { TObjEneBalClaw::load_resources, TObjEneBalClaw::free_resources },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_10[11] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneRe4Sorcerer::load_resources, TObjEneRe4Sorcerer::free_bits },
    { load_darkgunner_effect_resources, TObjEneDarkGunner::cleanup_effects },
    { TObjEneDarkGunCenter::load_resources, TObjEneDarkGunCenter::free_resources },
    { TObjEneDf2Bringer::load_resources, TObjEneDf2Bringer::free_resources },
    { TObjEneRe7Berura::load_static_resources, TObjEneRe7Berura::destroy_children },
    { TLobby::load_dimedian_resources, TObjEneDimedian::free_boss_objects },
    { TObjEneBalClaw::load_resources, TObjEneBalClaw::free_resources },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_11[6] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TBoss1DragonDemo::load_assets, TBoss1DragonDemo::free_assets },
    { TBoss1Dragon::load_resources, TBoss1Dragon::free_resources },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_12[5] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TBoss2DeRolLe::load_resources, TBoss2DeRolLe::reset_parts },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_13[4] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
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
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TBoss7DeRolLeC::load_resources, TBoss7DeRolLeC::run_exit_callbacks },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_33[6] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { clear_boss8_dragon_leader_part, release_boss8_dragon_leader_part },
    { TBoss8Dragon::load_resources, TBoss8Dragon::free_static },
    { reset_camera_override, restore_cameras_if_overridden },
    { 0, 0 },
};

__declspec(section ".data") FloorResourceCallbacks floor_resource_callbacks_selector_15[1] = {
    { 0, 0 },
};
}

FloorResourceCallbacks floor_resource_callbacks_selector_16[10] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneMoja::load_resources, TObjEneMoja::free_resources },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::free_resources },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { load_shinowa_mirage_resources, TObjEneMe3ShinowaMirage::free_shared_resources },
    { initialize_saver_resources, TObjEneSaver::free_resources },
    { TObjEneDf2Bringer::load_resources, TObjEneDf2Bringer::free_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_17[10] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneMoja::load_resources, TObjEneMoja::free_resources },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::free_resources },
    { TLobby::load_shark_resources, TObjEneShark::free_resources },
    { load_shinowa_mirage_resources, TObjEneMe3ShinowaMirage::free_shared_resources },
    { initialize_saver_resources, TObjEneSaver::free_resources },
    { TObjEneDf2Bringer::load_resources, TObjEneDf2Bringer::free_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_18[29] = {
    { TObjNpcBase::load_resources, TObjNpcBase::free_static },
    { TObjNpcFemale::load_resources, TObjNpcFemale::free_resources },
    { TObjNpcFomarl::load_resources, TObjNpcFomarl::free_resources },
    { TObjNpcMale::load_resources, TObjNpcMale::free_resources },
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
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneDubchik::load_resources, TObjEneDubchik::free_resources },
    { TOCtrlDubchik::load_shared_resource, TOCtrlDubchik::destroy_instance },
    { TLobby::load_gyaranzo_resources, TObjEneGyaranzo::free_static_instances },
    { TObjEneBm5Wolf::load_resources, TObjEneBm5Wolf::free_resources },
    { TObjEnePanarms::load_and_spawn_npc, TObjEnePanarms::free_data },
    { initialize_saver_resources, TObjEneSaver::free_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_22[9] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneDubchik::load_resources, TObjEneDubchik::free_resources },
    { TOCtrlDubchik::load_shared_resource, TOCtrlDubchik::destroy_instance },
    { TObjEneBm5Wolf::load_resources, TObjEneBm5Wolf::free_resources },
    { TObjEnePanarms::load_and_spawn_npc, TObjEnePanarms::free_data },
    { initialize_saver_resources, TObjEneSaver::free_resources },
    { TObjEneRe4Sorcerer::load_resources, TObjEneRe4Sorcerer::free_bits },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selectors_19_20[11] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneLappy::load_resources, TObjEneLappy::free_resources },
    { TObjEneMoja::load_resources, TObjEneMoja::free_resources },
    { TObjGrass::load_resources, TObjGrass::destroy_all },
    { TObjCGrass::load_resources, TObjCGrass::free_resources },
    { load_re2_flower_resources, TObjEneRe2Flower::destroy_instance },
    { TObjEneBm3FlyNest::load_resources, TObjEneBm3FlyNest::free_fly },
    { TLobby::load_dimedian_resources, TObjEneDimedian::free_boss_objects },
    { TObjEneRe7Berura::load_static_resources, TObjEneRe7Berura::destroy_children },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selectors_23_24_25_26_27[16] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneMe3Stelth::load_shared_resources, TObjEneMe3Stelth::free_shared_resources },
    { TObjEneMerillLia::load_resources, TObjEneMerillLia::free_resources },
    { TObjEneBm9Mericarol::load_resources, TObjEneBm9Mericarol::free_shared_instances },
    { TObjEneBm5GibonU::load_resources, TObjEneBm5GibonU::release_static_resource },
    { TObjEneGibbles::load_resources, TObjEneGibbles::free_static },
    { TObjEneMe1Gee::load_resources, TObjEneMe1Gee::free_globals },
    { TObjEneMe1GiGue::load_resources, TObjEneMe1GiGue::delete_barrier },
    { TObjEneLappy::load_resources, TObjEneLappy::free_resources },
    { TObjNpcBase::load_resources, TObjNpcBase::free_static },
    { TObjNpcFemale::load_resources, TObjNpcFemale::free_resources },
    { TObjNpcFomarl::load_resources, TObjNpcFomarl::free_resources },
    { TObjNpcMale::load_resources, TObjNpcMale::free_resources },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_34[15] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneDolmOlm::load_shared_resources, TObjEneDolmOlm::free_shared_resources },
    { TObjEneRecobox::load_resources, TObjEneRecobox::release_static_instance },
    { TObjEneMerillLia::load_resources, TObjEneMerillLia::free_resources },
    { TObjEneBm5GibonU::load_resources, TObjEneBm5GibonU::release_static_resource },
    { TObjEneMe1Gee::load_resources, TObjEneMe1Gee::free_globals },
    { load_nights_npc_resource, free_nights_npc_resource },
    { TObjEneLappy::load_resources, TObjEneLappy::free_resources },
    { TObjNpcBase::load_resources, TObjNpcBase::free_static },
    { TObjNpcFemale::load_resources, TObjNpcFemale::free_resources },
    { TObjNpcFomarl::load_resources, TObjNpcFomarl::free_resources },
    { TObjNpcMale::load_resources, TObjNpcMale::free_resources },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_35[16] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneBm9Mericarol::load_resources, TObjEneBm9Mericarol::free_shared_instances },
    { TObjEneGibbles::load_resources, TObjEneGibbles::free_static },
    { TObjEneMe1GiGue::load_resources, TObjEneMe1GiGue::delete_barrier },
    { TObjEneRecobox::load_resources, TObjEneRecobox::release_static_instance },
    { TObjEneDellBiter::load_resources, TObjEneDellBiter::destroy_static_instance },
    { TObjEneEpsilonGuard::load_assets, TObjEneEpsilonGuard::free_shared_resources },
    { load_re2_flower_resources, TObjEneRe2Flower::destroy_instance },
    { TObjEneIllGill::load_shared_resources, TObjEneIllGill::free_effect },
    { TObjNpcBase::load_resources, TObjNpcBase::free_static },
    { TObjNpcFemale::load_resources, TObjNpcFemale::free_resources },
    { TObjNpcFomarl::load_resources, TObjNpcFomarl::free_resources },
    { TObjNpcMale::load_resources, TObjNpcMale::free_resources },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selectors_28_29[14] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { TObjEneDolmOlm::load_shared_resources, TObjEneDolmOlm::free_shared_resources },
    { TObjEneMorfos::load_static_data, TObjEneMorfos::unload_static_data },
    { TObjEneRecobox::load_resources, TObjEneRecobox::release_static_instance },
    { TObjEneMe3SinowZoa::load_resources, TObjEneMe3SinowZoa::free_resources },
    { TObjEneDelDepth::load_assets, TObjEneDelDepth::free_shared_data },
    { TObjEneDellBiter::load_resources, TObjEneDellBiter::destroy_static_instance },
    { TObjNpcBase::load_resources, TObjNpcBase::free_static },
    { TObjNpcFemale::load_resources, TObjNpcFemale::free_resources },
    { TObjNpcFomarl::load_resources, TObjNpcFomarl::free_resources },
    { TObjNpcMale::load_resources, TObjNpcMale::free_resources },
    { TObjNpcNgcBase::load_resources, TObjNpcNgcBase::free_shared_resources },
    { 0, 0 },
};

FloorResourceCallbacks floor_resource_callbacks_selector_30[4] = {
    { TDeadSpot::load_resource, TDeadSpot::free_resource },
    { TObjEneDD::create_instance, TObjEneDD::release_resource },
    { load_boss5_gryphon_resources, TBoss5Gryphon::cleanup },
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
