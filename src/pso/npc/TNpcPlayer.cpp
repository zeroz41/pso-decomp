#include "pso/player/TPlyDispData.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyInventory.h"
#include <stdlib.h>
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/system/ResourceFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/object/base/TObjChara.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/technique/TechniqueId.h"
#include "types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/system/task/TObject.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/CapturedTargetList.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnQuery.h"


#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/protocol/cast_packets.h"
#include "pso/technique/TTecReverser.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby_8013A874.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_803E18C0.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/render_util.h"

disp_data_part2 *npc_player_char_data_buffer;
s32 quest_npc_visual_pending;

extern "C" {

s32 __dt__12TPlyCharDataFv(s32 object, s16 free_flags);
void * __ct__12TPlyCharDataFv(void *object);
s32 find_parts_in_range__10TNpcPlayerFPvPvif(NpcPlayerView *view, Vec *pos, u16 id, f32 range);
s32 try_update_target_flag__10TNpcPlayerFPvi(NpcPlayerView *view, s32 id);
s32 try_send_6x27_use_item(void *player, s32 key);
s8 get_cast_technique_level(void *, s16);
void __register_global_object(void *obj, void *dtor, void *link);

void copy_player_visual_record(void *, void *);
void __sinit_TNpcPlayer_cpp();
}

disp_data_part2 npc_player_visual_record;
u32 npc_player_ply_char_data_global[3];
u32 npc_player_char_data[263];
disp_data_part2 quest_npc_visual_record;

// Attack techniques by tier (Foie, Barta, Zonde); the second column is used when the
// partner is surrounded and hurt. Read by TNpcPlayer::update_combat_action.
static const s32 npc_player_combat_action_table[3][2] = {
    {TECHNIQUE_FOIE, TECHNIQUE_GIFOIE},
    {TECHNIQUE_BARTA, TECHNIQUE_GIBARTA},
    {TECHNIQUE_ZONDE, TECHNIQUE_RAZONDE},
};

const char *npc_player_char_file_name = "npcplayerchar.dat";
const char *TNpcPlayer::name = "TNpcPlayer";

// npc_player_char_data is constructed by __sinit_TNpcPlayer_cpp, spelled out below because
// the original's static initializer precedes the out-of-line helpers at the end
// of this file, which no compiler-generated __sinit reproduces.
__declspec(section ".ctors") static void *const npc_player_global_initializer = (void *)__sinit_TNpcPlayer_cpp;

int get_registered_object_count(void);
TNpcPlayer::AiParams npc_player_ai_templates[64] = {
    {0x0, 0x4, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 13.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0xf, 0x0, 50.0f},
    {0x1, 0xc, TECHNIQUE_FLAGS_BARTA_GIBARTA, 100.0f, 10.0f, 15.0f, 35.0f, 25.0f, 100.0f, 0x0, 0x9, 0x19, 0x5a, 50.0f},
    {0x2, 0x14, TECHNIQUE_FLAGS_BARTA_GIBARTA, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 100.0f, 0x2, 0x9, 0x1e, 0x50, 50.0f},
    {0x3, 0x12, TECHNIQUE_FLAGS_FOIE_GIFOIE, 120.0f, 10.0f, 18.0f, 40.0f, 30.0f, 100.0f, 0x0, 0x9, 0x3c, 0x28, 50.0f},
    {0x4, 0xe, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 120.0f, 0x0, 0x9, 0x14, 0x0, 50.0f},
    {0x5, 0x18, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0x6, 0x19, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x0, 0x9, 0x50, 0x28, 50.0f},
    {0x7, 0xb, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 13.0f, 40.0f, 30.0f, 100.0f, 0x0, 0x9, 0x14, 0x0, 50.0f},
    {0x8, 0x11, TECHNIQUE_FLAGS_BARTA_GIBARTA, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 100.0f, 0x6, 0x9, 0x1e, 0x46, 50.0f},
    {0x9, 0x1b, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x37, 0x0, 50.0f},
    {0xa, 0x12, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0xb, 0x11, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x4, 0x9, 0x2d, 0x37, 50.0f},
    {0xc, 0x23, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x0, 0x2d, 0x0, 50.0f},
    {0xd, 0xf, TECHNIQUE_FLAGS_FOIE_GIFOIE, 100.0f, 10.0f, 15.0f, 50.0f, 30.0f, 100.0f, 0x0, 0x9, 0x37, 0x14, 50.0f},
    {0xe, 0x22, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 50.0f, 30.0f, 100.0f, 0x0, 0x9, 0x32, 0x0, 50.0f},
    {0xf, 0xb, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 40.0f, 30.0f, 100.0f, 0x0, 0x9, 0x28, 0x0, 50.0f},
    {0x10, 0x9, TECHNIQUE_FLAGS_BARTA_GIBARTA, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 80.0f, 0x2, 0x9, 0xa, 0x50, 50.0f},
    {0x11, 0x2a, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 150.0f, 10.0f, 15.0f, 45.0f, 30.0f, 120.0f, 0xb, 0xb, 0x32, 0x46, 50.0f},
    {0x12, 0x20, TECHNIQUE_FLAGS_FOIE_GIFOIE, 100.0f, 10.0f, 15.0f, 30.0f, 30.0f, 120.0f, 0x9, 0x9, 0x32, 0x5a, 50.0f},
    {0x13, 0x7, TECHNIQUE_FLAGS_FOIE_GIFOIE, 100.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0xb, 0xa, 0x50, 50.0f},
    {0x14, 0x17, TECHNIQUE_FLAGS_FOIE_GIFOIE, 300.0f, 10.0f, 30.0f, 40.0f, 25.0f, 25.0f, 0x2, 0x0, 0x1e, 0x28, 50.0f},
    {0x15, 0x18, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 80.0f, 60.0f, 40.0f, 35.0f, 0x0, 0x0, 0x32, 0x0, 50.0f},
    {0x16, 0x14, TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF, 300.0f, 10.0f, 30.0f, 30.0f, 20.0f, 60.0f, 0x4, 0x0, 0x32, 0x4b, 45.0f},
    {0x17, 0xb, TECHNIQUE_FLAGS_NONE_NO_BACKOFF, 300.0f, 10.0f, 50.0f, 50.0f, 20.0f, 100.0f, 0x0, 0x9, 0xf, 0x0, 70.0f},
    {0x18, 0xc, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 40.0f, 40.0f, 30.0f, 80.0f, 0x0, 0x9, 0x2d, 0x0, 60.0f},
    {0x19, 0x13, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 40.0f, 40.0f, 30.0f, 80.0f, 0x0, 0x9, 0x37, 0x0, 60.0f},
    {0x1a, 0x11, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x4, 0x9, 0x32, 0x0, 50.0f},
    {0x1b, 0xd, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 50.0f, 30.0f, 80.0f, 0x0, 0x9, 0x1e, 0x0, 50.0f},
    {0x1c, 0x14, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 70.0f, 10.0f, 15.0f, 20.0f, 30.0f, 50.0f, 0x0, 0x9, 0x32, 0x32, 50.0f},
    {0x1d, 0xd, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 50.0f, 30.0f, 80.0f, 0x0, 0x9, 0x1e, 0x0, 50.0f},
    {0x1e, 0x18, TECHNIQUE_FLAGS_BARTA_GIBARTA, 80.0f, 10.0f, 15.0f, 50.0f, 30.0f, 60.0f, 0x6, 0x9, 0x32, 0x1e, 50.0f},
    {0x1f, 0x1e, TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF, 300.0f, 10.0f, 40.0f, 40.0f, 20.0f, 100.0f, 0x8, 0x9, 0x23, 0x50, 45.0f},
    {0x20, 0xa, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x32, 0x0, 50.0f},
    {0x21, 0xf, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x32, 0x0, 50.0f},
    {0x22, 0x2a, TECHNIQUE_FLAGS_FOIE_GIFOIE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x3c, 0x1e, 50.0f},
    {0x23, 0x21, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x6, 0x9, 0x3c, 0x32, 50.0f},
    {0x24, 0xb, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 50.0f, 0x0, 0x9, 0x64, 0x32, 50.0f},
    {0x25, 0x1a, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 100.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0x26, 0x23, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 15.0f, 60.0f, 30.0f, 30.0f, 0x0, 0x0, 0x3c, 0x0, 50.0f},
    {0x27, 0x1c, TECHNIQUE_FLAGS_FOIE_GIFOIE, 120.0f, 10.0f, 15.0f, 50.0f, 30.0f, 100.0f, 0x7, 0x9, 0x3c, 0x1e, 50.0f},
    {0x28, 0x14, TECHNIQUE_FLAGS_BARTA_GIBARTA, 200.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x4, 0x9, 0x3c, 0x1e, 50.0f},
    {0x29, 0x1b, TECHNIQUE_FLAGS_FOIE_GIFOIE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x4, 0x9, 0x3c, 0x32, 50.0f},
    {0x2a, 0x1d, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 25.0f, 45.0f, 30.0f, 30.0f, 0x9, 0x9, 0x64, 0x32, 50.0f},
    {0x2b, 0x22, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0x2c, 0x9, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x9, 0x9, 0x64, 0x32, 50.0f},
    {0x2d, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE_NO_BACKOFF, 300.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x32, 0x1e, 50.0f},
    {0x2e, 0x9, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 15.0f, 60.0f, 30.0f, 30.0f, 0x0, 0x9, 0x46, 0x0, 50.0f},
    {0x2f, 0x9, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x0, 0x9, 0x32, 0x0, 50.0f},
    {0x30, 0x9, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x37, 0x0, 50.0f},
    {0x31, 0x9, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x46, 0x0, 50.0f},
    {0x32, 0x9, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 50.0f, 30.0f, 100.0f, 0x0, 0x9, 0x41, 0x0, 50.0f},
    {0x33, 0x9, TECHNIQUE_FLAGS_NONE_NO_BACKOFF, 200.0f, 10.0f, 20.0f, 20.0f, 30.0f, 80.0f, 0x0, 0x9, 0x19, 0x0, 30.0f},
    {0x34, 0x9, TECHNIQUE_FLAGS_NONE_NO_BACKOFF, 200.0f, 10.0f, 40.0f, 40.0f, 30.0f, 80.0f, 0x0, 0x9, 0x23, 0x0, 70.0f},
    {0x35, 0x9, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 200.0f, 10.0f, 15.0f, 60.0f, 30.0f, 30.0f, 0x4, 0x9, 0x3c, 0x1e, 50.0f},
    {0x36, 0x9, TECHNIQUE_FLAGS_NONE_NO_BACKOFF, 200.0f, 10.0f, 40.0f, 40.0f, 30.0f, 80.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0x37, 0x9, TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF, 150.0f, 10.0f, 25.0f, 45.0f, 30.0f, 120.0f, 0x6, 0x9, 0x32, 0x50, 50.0f},
    {0x38, 0x23, TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF, 300.0f, 10.0f, 40.0f, 40.0f, 20.0f, 150.0f, 0xc, 0xc, 0x3c, 0x46, 50.0f},
    {0x39, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 100.0f, 10.0f, 25.0f, 45.0f, 30.0f, 80.0f, 0x0, 0x9, 0x32, 0x50, 50.0f},
    {0x3a, 0x9, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x1e, 0x0, 50.0f},
    {0x3b, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 25.0f, 45.0f, 30.0f, 50.0f, 0x0, 0x9, 0x64, 0x32, 50.0f},
    {0x3c, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 13.0f, 45.0f, 30.0f, 50.0f, 0x0, 0x9, 0x64, 0x32, 50.0f},
    {0x3d, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 15.0f, 45.0f, 30.0f, 30.0f, 0x0, 0x9, 0x64, 0x32, 50.0f},
    {0x3e, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 25.0f, 45.0f, 30.0f, 30.0f, 0x9, 0x9, 0x32, 0x50, 50.0f},
    {0x3f, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 25.0f, 45.0f, 30.0f, 30.0f, 0x1, 0x9, 0x1e, 0x32, 50.0f},
};
TPlyInventoryItem npc_normal_set_00[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_10[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_16[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xa, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_15[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_19[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xc, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_40[10] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 0, 8, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_01[4] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xc, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_11[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xd, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xb, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xb, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_09[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xe, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_38[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_13[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_20[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xa, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_53[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_32[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xe, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xe, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_25[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_15[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xe, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xe, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_02[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xa, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x17, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x17, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_04[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 6, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xc, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xc, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_17[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x1b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x17, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_30[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x16, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_23[10] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_41[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_43[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_60[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x15, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_21[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_57[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_03[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xe, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xe, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_47[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_51[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 8, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_22[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_31[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xa, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_35[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xd, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x17, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_46[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x16, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x16, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_12[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_36[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xc, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_00[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_10[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_16[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xa, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xb, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xb, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_29[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_19[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xc, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_40[10] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 0, 8, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1d, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_01[4] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xc, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_11[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xd, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xc, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xd, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_09[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xe, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1d, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_38[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x11, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_13[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xb, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xb, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_20[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xe, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_53[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xc, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xc, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_32[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_25[10] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 9, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xa, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 0, 9, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1d, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_02[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xa, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1b, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1b, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_04[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_17[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x1b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1b, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1d, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_30[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_23[10] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_41[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_43[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_60[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1b, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1d, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_21[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_57[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_03[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_47[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x20, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0xc, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xc, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_51[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 8, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0xb, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_22[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_31[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xa, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_35[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xd, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1b, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1d, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_46[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 1, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_12[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x11, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_hard_set_36[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xc, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_05[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 8, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1c, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_very_hard_set_08[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xc, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x1a, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1b, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_06[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1d, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_37[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x8b, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1c, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_very_hard_set_13[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x15, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1c, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_very_hard_set_11[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0xd, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1d, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_very_hard_set_15[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1c, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem npc_normal_set_34[5] = {
    { { 1, 0, 0, 0 }, 8, { { { 0, 0x89, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 1, 0x19, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 8, { { { 1, 2, 0x1c, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 0, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
    { { 1, 0, 0, 0 }, 0, { { { 3, 1, 2, 0, 0, 0xa, 0, 0, 0, 0, 0, 0 } }, 0xffffffff, { { 0, 0, 0, 0 } } } },
};
TPlyInventoryItem *npc_player_equipment_normal[64] = {
    npc_normal_set_00, npc_normal_set_01, npc_normal_set_02, npc_normal_set_03,
    npc_normal_set_04, npc_normal_set_05, npc_normal_set_06, npc_normal_set_04,
    npc_normal_set_02, npc_normal_set_09, npc_normal_set_10, npc_normal_set_11,
    npc_normal_set_12, npc_normal_set_13, npc_normal_set_03, npc_normal_set_15,
    npc_normal_set_16, npc_normal_set_17, npc_normal_set_02, npc_normal_set_19,
    npc_normal_set_20, npc_normal_set_21, npc_normal_set_22, npc_normal_set_23,
    npc_normal_set_23, npc_normal_set_25, npc_normal_set_10, npc_normal_set_00,
    npc_normal_set_19, npc_normal_set_15, npc_normal_set_30, npc_normal_set_31,
    npc_normal_set_32, npc_normal_set_32, npc_normal_set_34, npc_normal_set_35,
    npc_normal_set_36, npc_normal_set_37, npc_normal_set_38, npc_normal_set_13,
    npc_normal_set_40, npc_normal_set_41, npc_normal_set_02, npc_normal_set_43,
    npc_normal_set_41, npc_normal_set_04, npc_normal_set_46, npc_normal_set_47,
    npc_normal_set_43, npc_normal_set_15, npc_normal_set_17, npc_normal_set_51,
    npc_normal_set_51, npc_normal_set_53, npc_normal_set_51, npc_normal_set_03,
    npc_normal_set_17, npc_normal_set_57, npc_normal_set_04, npc_normal_set_40,
    npc_normal_set_60, npc_normal_set_60, npc_normal_set_25, npc_normal_set_57,
};
TPlyInventoryItem *npc_player_equipment_hard[64] = {
    npc_hard_set_00, npc_hard_set_01, npc_hard_set_02, npc_hard_set_03,
    npc_hard_set_04, npc_normal_set_05, npc_normal_set_06, npc_hard_set_04,
    npc_hard_set_02, npc_hard_set_09, npc_hard_set_10, npc_hard_set_11,
    npc_hard_set_12, npc_hard_set_13, npc_hard_set_03, npc_hard_set_15,
    npc_hard_set_16, npc_hard_set_17, npc_hard_set_02, npc_hard_set_19,
    npc_hard_set_20, npc_hard_set_21, npc_hard_set_22, npc_hard_set_23,
    npc_hard_set_23, npc_hard_set_25, npc_hard_set_10, npc_hard_set_00,
    npc_hard_set_19, npc_hard_set_29, npc_hard_set_30, npc_hard_set_31,
    npc_hard_set_32, npc_hard_set_32, npc_normal_set_34, npc_hard_set_35,
    npc_hard_set_36, npc_normal_set_37, npc_hard_set_38, npc_hard_set_13,
    npc_hard_set_40, npc_hard_set_41, npc_hard_set_02, npc_hard_set_43,
    npc_hard_set_41, npc_hard_set_04, npc_hard_set_46, npc_hard_set_47,
    npc_hard_set_43, npc_hard_set_43, npc_hard_set_17, npc_hard_set_51,
    npc_hard_set_51, npc_hard_set_53, npc_hard_set_51, npc_hard_set_03,
    npc_hard_set_02, npc_hard_set_57, npc_hard_set_04, npc_hard_set_40,
    npc_hard_set_60, npc_hard_set_60, npc_hard_set_25, npc_hard_set_57,
};
TPlyInventoryItem *npc_player_equipment_very_hard[64] = {
    npc_hard_set_00, npc_hard_set_01, npc_hard_set_02, npc_hard_set_03,
    npc_hard_set_04, npc_normal_set_05, npc_normal_set_06, npc_hard_set_04,
    npc_very_hard_set_08, npc_hard_set_09, npc_hard_set_10, npc_very_hard_set_11,
    npc_hard_set_12, npc_very_hard_set_13, npc_hard_set_03, npc_very_hard_set_15,
    npc_very_hard_set_08, npc_hard_set_17, npc_hard_set_02, npc_hard_set_19,
    npc_hard_set_20, npc_hard_set_21, npc_hard_set_22, npc_hard_set_23,
    npc_hard_set_23, npc_hard_set_25, npc_hard_set_10, npc_hard_set_00,
    npc_hard_set_19, npc_hard_set_29, npc_hard_set_30, npc_hard_set_31,
    npc_hard_set_32, npc_hard_set_32, npc_normal_set_34, npc_very_hard_set_11,
    npc_hard_set_36, npc_normal_set_37, npc_hard_set_38, npc_very_hard_set_13,
    npc_hard_set_40, npc_hard_set_41, npc_hard_set_02, npc_hard_set_43,
    npc_hard_set_41, npc_hard_set_04, npc_hard_set_46, npc_hard_set_47,
    npc_hard_set_43, npc_hard_set_43, npc_hard_set_17, npc_hard_set_51,
    npc_hard_set_51, npc_hard_set_53, npc_hard_set_51, npc_hard_set_03,
    npc_hard_set_17, npc_hard_set_57, npc_hard_set_04, npc_hard_set_40,
    npc_hard_set_60, npc_hard_set_60, npc_hard_set_25, npc_hard_set_57,
};
TPlyInventoryItem *npc_player_equipment_ultimate[64] = {
    npc_hard_set_00, npc_hard_set_01, npc_hard_set_02, npc_hard_set_03,
    npc_hard_set_04, npc_normal_set_05, npc_normal_set_06, npc_hard_set_04,
    npc_very_hard_set_08, npc_hard_set_09, npc_hard_set_10, npc_very_hard_set_11,
    npc_hard_set_12, npc_very_hard_set_13, npc_hard_set_03, npc_very_hard_set_15,
    npc_very_hard_set_08, npc_hard_set_17, npc_hard_set_02, npc_hard_set_19,
    npc_hard_set_20, npc_hard_set_21, npc_hard_set_22, npc_hard_set_23,
    npc_hard_set_23, npc_hard_set_25, npc_hard_set_10, npc_hard_set_00,
    npc_hard_set_19, npc_hard_set_29, npc_hard_set_30, npc_hard_set_31,
    npc_hard_set_32, npc_hard_set_32, npc_normal_set_34, npc_very_hard_set_11,
    npc_hard_set_36, npc_normal_set_37, npc_hard_set_38, npc_very_hard_set_13,
    npc_hard_set_40, npc_hard_set_41, npc_hard_set_02, npc_hard_set_43,
    npc_hard_set_41, npc_hard_set_04, npc_hard_set_46, npc_hard_set_47,
    npc_hard_set_43, npc_hard_set_43, npc_hard_set_17, npc_hard_set_51,
    npc_hard_set_51, npc_hard_set_53, npc_hard_set_51, npc_hard_set_03,
    npc_hard_set_17, npc_hard_set_57, npc_hard_set_04, npc_hard_set_40,
    npc_hard_set_60, npc_hard_set_60, npc_hard_set_25, npc_hard_set_57,
};

u16 TObjPlayer::get_npc_controller() { return npc_control.controller_client_id; }

int get_registered_object_count(void) {  return registered_entity_count; }

void PhotonBlastTarget::reset() {
    entity_id = 0xFFFF;
    index = 0;
}

PhotonBlastTarget::PhotonBlastTarget() { reset(); }

void PhotonBlastTarget::set_entity_id(s32 id) { entity_id = id; }

void PhotonBlastTarget::set_index(s16 part) { index = part; }

void PhotonBlastTarget::bswap() {
    bswap_16(&entity_id);
    bswap_16((u16 *)&index);
}

void CapturedTargetList::set_count(s32 n) { count = n; }

void CapturedTarget::set_uid(u16 id) { uid = id; }

void CapturedTarget::set_collider_index(s16 index) { collider_index = index; }

void G_WalkToPosition_6x40::init() {
    pos.z = 0.0f;
    pos.x = 0.0f;
    flags = 0;
    header.subcommand = 0x40;
    header.size = 4;
}

void G_WalkToPosition_6x40::bswap() {
    header.bswap();
    pos.bswap();
    bswap_32(&flags);
}

void G_WalkToPosition_6x40::send() {
    bswap();
    broadcast_subcommand(this);
}

void G_MoveToPosition_6x41_6x42::init() {
    pos.z = 0.0f;
    pos.x = 0.0f;
    header.subcommand = 0x42;
    header.size = 3;
}

void G_MoveToPosition_6x41_6x42::bswap() {
    header.bswap();
    pos.bswap();
}

void G_MoveToPosition_6x41_6x42::send() {
    bswap();
    broadcast_subcommand(this);
}

G_CastTechniqueParams_6x47::G_CastTechniqueParams_6x47() {
    target_count = 0;
    level = 0;
    unused = 0;
    technique_number = 0;
}

G_CastTechnique_6x47::G_CastTechnique_6x47() {
    header.subcommand = 0x47;
    header.size = sizeof(G_CastTechnique_6x47) / 4;
}

u8 G_CastTechnique_6x47::get_size() {
    return sizeof(G_CastTechnique_6x47) - (10 - params.target_count) * sizeof(PhotonBlastTarget);
}

void G_CastTechnique_6x47::bswap() {
    s32 i;
    header.bswap();
    for (i = 0; i < params.target_count; i++) {
        targets[i].bswap();
    }
}

void G_CastTechnique_6x47::send() {
    header.size = (get_size() >> 2) & 0x3F;
    bswap();
    send_subcommand(this);
}

void G_Attack_6x43::init() {
    angle_y = 0;
    action_type = 0;
    header.subcommand = 0x43;
    header.size = 2;
}

void G_Attack_6x43::bswap() {
    header.bswap();
    bswap_16(&angle_y);
    bswap_16(&action_type);
}

void G_Attack_6x43::send() {
    bswap();
    broadcast_subcommand(this);
}

void G_Attack_6x44::init() {
    angle_y = 0;
    action_type = 0;
    header.subcommand = 0x44;
    header.size = 2;
}

void G_Attack_6x44::bswap() {
    header.bswap();
    bswap_16(&angle_y);
    bswap_16(&action_type);
}

void G_Attack_6x44::send() {
    bswap();
    broadcast_subcommand(this);
}

void G_Attack_6x45::init() {
    angle_y = 0;
    action_type = 0;
    header.subcommand = 0x45;
    header.size = 2;
}

void G_Attack_6x45::bswap() {
    header.bswap();
    bswap_16(&angle_y);
    bswap_16(&action_type);
}

void G_Attack_6x45::send() {
    bswap();
    broadcast_subcommand(this);
}

void PartnerCounters::clear() {
    s32 i;
    for (i = 0; i < 11; i++) {
        count[i] = 0;
    }
}

PartnerCounters::PartnerCounters() { clear(); }

void NpcPlayerView::set_target(u32 id, s32 collider) {
    prev_target_id = target_id;
    target_id = id;
    target_collider = collider;
}

NpcPlayerView *NpcPlayerView::target_list() { return this; }

s32 PartnerCounters::clamp(s32 index, s32 limit) {
    if (is_reached(index, limit) != 0) {
        count[index] = limit;
        return 1;
    }
    return 0;
}

void NpcPlayerView::clear_flags() {
    status = 0;
    condition = 0;
}

u32 NpcPlayerView::get_status() { return status; }

void NpcPlayerViewTarget::copy(NpcPlayerViewTarget *src) {
    entity_id = src->entity_id;
    collider = src->collider;
    distance_sq = src->distance_sq;
}

void NpcPlayerView::copy_target(NpcPlayerViewTarget *src, NpcPlayerViewTarget *dst) { dst->copy(src); }

u32 NpcPlayerView::get_condition() { return condition; }

u32 NpcPlayerView::get_prev_target_id() { return prev_target_id; }

void PartnerCounters::set(s32 index, s16 value) { count[index] = value; }

s32 PartnerCounters::is_reached(s32 index, s32 value) { return value <= count[index] ? 1 : 0; }

s32 PartnerCounters::reset_if_reached(s32 index, s32 limit) {
    if (is_reached(index, limit) != 0) {
        count[index] = 0;
        return 1;
    }
    return 0;
}

s16 PartnerCounters::get(s32 index) { return count[index]; }

u16 NpcPlayerView::get_client_id() { return client_id; }

u32 NpcPlayerView::get_target_id() { return target_id; }

s32 NpcPlayerView::get_target_collider() { return target_collider; }

void PartnerCounters::increment(s32 index) { count[index]++; }

void PartnerCounters::reset(s32 index) { count[index] = 0; }

void PlayerTechniqueState::set_technique_level(s16 technique, u8 level) { levels[technique] = level; }

void __sinit_TNpcPlayer_cpp() {
    __register_global_object(__ct__12TPlyCharDataFv(npc_player_char_data), (void *)__dt__12TPlyCharDataFv, npc_player_ply_char_data_global);
}

void TNpcPlayer::ensure_rock_singleton() {
    if (npc_player_char_data_buffer == NULL) {
        npc_player_char_data_buffer = static_cast<disp_data_part2 *>(mem_alloc(64 * sizeof(disp_data_part2)));
    }
}

TPlyCharData *TNpcPlayer::build_npc_player_record(s32 index) {
    s32 mode;
    s32 diff;
    s32 lvl;
    u16 base;

    if (quest_npc_visual_pending != 0) {
        quest_npc_visual_pending = 0;
        copy_player_visual_record(&npc_player_visual_record, &quest_npc_visual_record);
    } else {
        copy_player_visual_record(&npc_player_visual_record, &npc_player_char_data_buffer[index]);
    }
    bswap__15disp_data_part2Fv((saddr)&npc_player_visual_record);
    mem_free(npc_player_char_data_buffer);
    mode = game_difficulty_selection;
    npc_player_char_data_buffer = NULL;
    if (mode >= 0 && mode <= 2) {
        diff = mode;
    } else {
        diff = 2;
    }
    base = npc_player_ai_templates[index].base_level;
    lvl = base + diff * 25;
    if (mode == 3) {
        lvl = base + 150;
    }
    if (lvl >= 198) {
        lvl = 198;
    }
    switch (mode) {
    case 0:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_normal[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    case 1:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_hard[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    case 2:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_very_hard[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    case 3:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_ultimate[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    default:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_very_hard[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    }
    copy_player_visual_record(&reinterpret_cast<TPlyCharData *>(npc_player_char_data)->m_disp_part2, &npc_player_visual_record);
    return reinterpret_cast<TPlyCharData *>(npc_player_char_data);
}

TPlyCharData *load_npc_player_template(s32 index) {
    s32 mode;
    s32 diff;
    s32 lvl;
    u16 base;

    if (npc_player_char_data_buffer != NULL) {
        return NULL;
    }
    npc_player_char_data_buffer = static_cast<disp_data_part2 *>(mem_alloc(64 * sizeof(disp_data_part2)));
    if (quest_npc_visual_pending != 0) {
        quest_npc_visual_pending = 0;
        copy_player_visual_record(&npc_player_visual_record, &quest_npc_visual_record);
    } else {
        read_disc_file(npc_player_char_file_name, npc_player_char_data_buffer);
        copy_player_visual_record(&npc_player_visual_record, &npc_player_char_data_buffer[index]);
    }
    bswap__15disp_data_part2Fv((saddr)&npc_player_visual_record);
    mem_free(npc_player_char_data_buffer);
    mode = game_difficulty_selection;
    npc_player_char_data_buffer = NULL;
    if (mode >= 0 && mode <= 2) {
        diff = mode;
    } else {
        diff = 2;
    }
    base = npc_player_ai_templates[index].base_level;
    lvl = base + diff * 25;
    if (mode == 3) {
        lvl = base + 150;
    }
    if (lvl >= 198) {
        lvl = 198;
    }
    switch (mode) {
    case 0:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_normal[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    case 1:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_hard[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    case 2:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_very_hard[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    case 3:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_ultimate[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    default:
        TNpcPlayer::send_command(npc_player_visual_record.char_class, 5, (const TPlyInventoryItem *)npc_player_equipment_normal[index], lvl, (TPlyCharData *)npc_player_char_data);
        break;
    }
    copy_player_visual_record(&reinterpret_cast<TPlyCharData *>(npc_player_char_data)->m_disp_part2, &npc_player_visual_record);
    return reinterpret_cast<TPlyCharData *>(npc_player_char_data);
}

TNpcPlayer::TNpcPlayer(u16 leader_id, u16 self_id, int template_id, TObject *parent) : TObject(parent) {
    m_name = TNpcPlayer::name;
    chatter_id = 0x19;
    in_combat = 0;
    zeroed_word = 0;
    move_target.x = 0.0f;
    move_target.y = 0.0f;
    move_target.z = 0.0f;
    steer_point.x = 0.0f;
    steer_point.y = 0.0f;
    steer_point.z = 0.0f;
    goal.x = 0.0f;
    goal.y = 0.0f;
    goal.z = 0.0f;
    zeroed_words[0] = 0;
    zeroed_words[1] = 0;
    zeroed_words[2] = 0;
    template_index = template_id;
    ai_flags = 0;
    ai_state = 0;
    escort_distance_sq = 0.0f;
    leader_distance_sq = 0.0f;
    stuck_frames = 0;
    attack_delay = 0;
    still_frames = 0;
    leader_view = new NpcPlayerView(leader_id);
    self_view = new NpcPlayerView(self_id);
    ai_params.copy(&npc_player_ai_templates[template_index]);
    if (self_view != 0 && self_view->player != 0) {
        VecCopy(&goal, &self_view->player->position);
        init_equipment();
    }
    escort_leader = 0;
}

void TNpcPlayer::AiParams::copy(AiParams *src) {
    npc_id = src->npc_id;
    base_level = src->base_level;
    technique_flags = src->technique_flags;
    enemy_lock_on_range = src->enemy_lock_on_range;
    min_distance_from_player = src->min_distance_from_player;
    max_distance_from_player = src->max_distance_from_player;
    enemy_unlock_range = src->enemy_unlock_range;
    block_range = src->block_range;
    attack_range = src->attack_range;
    attack_technique_level = src->attack_technique_level;
    support_technique_level = src->support_technique_level;
    attack_probability = src->attack_probability;
    attack_technique_probability = src->attack_technique_probability;
    escort_keep_distance = src->escort_keep_distance;
}

TNpcPlayer::TNpcPlayer(u16 leader_id, u16 self_id, int template_id, s32 escort, TObject *parent) : TObject(parent) {
    m_name = TNpcPlayer::name;
    chatter_id = 0x19;
    in_combat = 0;
    zeroed_word = 0;
    move_target.x = 0.0f;
    move_target.y = 0.0f;
    move_target.z = 0.0f;
    steer_point.x = 0.0f;
    steer_point.y = 0.0f;
    steer_point.z = 0.0f;
    goal.x = 0.0f;
    goal.y = 0.0f;
    goal.z = 0.0f;
    zeroed_words[0] = 0;
    zeroed_words[1] = 0;
    zeroed_words[2] = 0;
    template_index = template_id;
    ai_flags = 0;
    ai_state = 0;
    escort_distance_sq = 0.0f;
    leader_distance_sq = 0.0f;
    stuck_frames = 0;
    attack_delay = 0;
    still_frames = 0;
    leader_view = new NpcPlayerView(leader_id);
    self_view = new NpcPlayerView(self_id);
    ai_params.copy(&npc_player_ai_templates[template_index]);
    if (self_view != 0 && self_view->player != 0) {
        VecCopy(&goal, &self_view->player->position);
        init_equipment();
    }
    escort_leader = escort;
}

TNpcPlayer::~TNpcPlayer() {
    TObjPlayer *player;
    NpcPlayerView *view;
    NpcPlayerView *partner;
    view = leader_view;
    if (view != NULL) {
        delete view;
        leader_view = NULL;
    }
    partner = self_view;
    if (partner != NULL) {
        player = get_player_by_client_id(partner->get_client_id());
        if (player != NULL) {
            TObjPlayer::send_disable_pk_mode(player);
        }
        delete self_view;
        self_view = NULL;
    }
}

void TNpcPlayer::run_task() {
    NpcPlayerView *owner;
    owner = leader_view;
    if (owner == NULL || self_view == NULL) {
        return;
    }
    if (owner->is_player_lost() != 0) {
        queue_destruction();
        return;
    }
    if (self_view->is_player_lost() != 0) {
        queue_destruction();
        return;
    }
    if ((self_view->player->is_inactive() != 0) && ((self_view->player == NULL) || (((TObjPlayer *)self_view->player)->get_npc_controller() != 0xFFFF))) {
        init_state();
        if (!(leader_view->player->actorFlags & 0x800)) {
            if (self_view->player->actorFlags & 0x800) {
                if (partner_counters.clamp(3, 0x400) != 0) {
                    request_chatter(5);
                } else if (partner_counters.is_reached(3, 0) != 0) {
                    request_chatter(4);
                }
                partner_counters.increment(3);
                change_ai_state(0);
            } else {
                partner_counters.reset(3);
                update_condition_flags();
                partner_observe_surroundings();
                decide_action();
                update_follow_target();
            }
            deliver_partner_action();
        }
    }
}

void TNpcPlayer::decide_action() {
    f32 threshold;
    f32 roll;
    f32 aggression;
    if ((get_current_floor_area() == AREA_PIONEER2_EP1) || (get_current_floor_area() == AREA_PIONEER2_EP2)) {
        calc_follow_goal();
        change_ai_state(1);
        return;
    }
    switch (in_combat) {
    case 0:
        if (self_view->get_status() & NPC_STATUS_ENEMIES_IN_RANGE) {
            in_combat = 1;
            change_ai_state(0);
            return;
        }
        ai_flags = ai_flags & ~NPC_AI_RETURNING_TO_LEADER;
        if (select_recovery_action(1) != 0) {
            if (ai_flags & NPC_AI_SELF_NEEDS_RECOVERY) {
                request_chatter(0x13);
                change_ai_state(8);
                return;
            }
            ai_flags &= ~NPC_AI_SELF_NEEDS_RECOVERY;
            if (horizontal_distance_squared(&goal, &self_view->player->position) < 900.0f) {
                change_ai_state(8);
                return;
            }
            calc_follow_goal();
            change_ai_state(1);
            return;
        }
        calc_follow_goal();
        change_ai_state(1);
        attack_delay = 0;
        return;
    case 1:
        aggression = 1.0f;
        if (ai_flags & NPC_AI_DOUBLE_AGGRESSION) {
            aggression = 2.0f;
        }
        if ((self_view->player->can_perform_physical_action() != 0) && (attack_delay == 0)) {
            roll = fabs_float(10.0f * (3.0517578125e-05f * (f32) rand()));
            threshold = 0.1f * (f32) ai_params.attack_probability;
            threshold *= aggression;
            if (roll < threshold) {
                attack_delay = 0;
            } else {
                attack_delay = (s16) (10.0f * (roll - threshold));
            }
        }
        attack_delay = (s16) (attack_delay - 1);
        if (attack_delay < 0) {
            attack_delay = 0;
        }
        if ((check_return_to_leader() != 0) && (escort_leader == 0)) {
            if (select_recovery_action(0) != 0) {
                request_chatter(0x13);
                change_ai_state(8);
                ai_flags = ai_flags & ~NPC_AI_ATTACK_BLOCKER;
            } else {
                if (ai_flags & NPC_AI_ATTACK_BLOCKER) {
                    ai_flags &= ~NPC_AI_ATTACK_BLOCKER;
                    if (attack_delay == 0) {
                        change_ai_state(2);
                    }
                } else {
                    calc_follow_goal();
                    change_ai_state(1);
                }
            }
        } else if (select_recovery_action(1) != 0) {
            partner_counters.reset(8);
            if (ai_flags & NPC_AI_SELF_NEEDS_RECOVERY) {
                request_chatter(0x13);
                change_ai_state(8);
            } else if (ai_flags & NPC_AI_ATTACK_BLOCKER) {
                ai_flags &= ~(NPC_AI_SELF_NEEDS_RECOVERY | NPC_AI_ATTACK_BLOCKER);
                if (attack_delay == 0) {
                    change_ai_state(2);
                }
            } else {
                ai_flags &= ~NPC_AI_SELF_NEEDS_RECOVERY;
                if (horizontal_distance_squared(&goal, &self_view->player->position) < 900.0f) {
                    change_ai_state(8);
                } else if (escort_leader != 0) {
                    if (attack_delay == 0) {
                        change_ai_state(2);
                    }
                } else {
                    calc_follow_goal();
                    change_ai_state(1);
                }
            }
        } else if ((choose_attack_target() != 0) && (attack_delay == 0)) {
            if (ai_flags & NPC_AI_TARGET_IN_REACH) {
                change_ai_state(2);
                ai_flags = ai_flags & ~NPC_AI_TARGET_IN_REACH;
            } else {
                change_ai_state(1);
            }
            ai_flags = ai_flags & ~NPC_AI_TARGET_IN_REACH;
        } else {
            if (escort_leader != 0) {
                calc_follow_goal();
            } else {
                VecCopy(&goal, &self_view->player->position);
            }
            change_ai_state(1);
        }
        if (!(self_view->get_status() & NPC_STATUS_ENEMIES_IN_RANGE)) {
            in_combat = 0;
        }
        return;
    }
}

s32 TNpcPlayer::update_follow_target() {
    if (needs_movement() != 0) {
        select_path_waypoint();
        if (check_movement_progress() != 0) {
            VecCopy(&move_target, &steer_point);
            if ((u32) ai_state != 2U) {
                change_ai_state(1);
            }
        } else {
            VecCopy(&move_target, &self_view->player->position);
        }
        return 1;
    }
    if ((ai_flags & NPC_AI_MOVE_STATE) && ((u32) ai_state != 8U)) {
        change_ai_state(0);
    }
    return 0;
}

s32 TNpcPlayer::check_return_to_leader() {
    NpcPlayerView *t;
    TObjChara *o;
    f32 r2;

    t = self_view->target_list();
    r2 = ai_params.enemy_unlock_range * ai_params.enemy_unlock_range;
    if (leader_view->get_status() & NPC_STATUS_ENEMIES_IN_RANGE) {
        ai_flags &= ~NPC_AI_RETURNING_TO_LEADER;
        return 0;
    }
    if (self_view->get_condition() & NPC_CONDITION_HP_LOW) {
        ai_flags |= NPC_AI_RETURNING_TO_LEADER;
        return 1;
    }
    if (leader_distance_sq >= r2) {
        ai_flags |= NPC_AI_RETURNING_TO_LEADER;
        if (t->target_count != 0) {
            partner_counters.increment(5);
            if (partner_counters.reset_if_reached(5, 3) != 0) {
                o = (TObjChara *)find_active_entity_by_id(t->targets[0].entity_id);
                ai_flags &= ~NPC_AI_DOUBLE_AGGRESSION;
                if (o != 0) {
                    if (horizontal_distance_squared(&o->position, &self_view->player->position) < ai_params.block_range * ai_params.block_range) {
                        ai_flags |= NPC_AI_DOUBLE_AGGRESSION | NPC_AI_ATTACK_BLOCKER;
                    }
                }
            }
        }
        return 1;
    }
    if (ai_flags & NPC_AI_RETURNING_TO_LEADER) {
        return 1;
    }
    ai_flags &= ~NPC_AI_RETURNING_TO_LEADER;
    return 0;
}

s32 TNpcPlayer::choose_attack_target() {
    s32 i;
    NpcPlayerView *view;
    TObjBase *tgt;
    view = self_view->target_list();
    if (view->target_count >= 3) {
        ai_flags |= NPC_AI_SURROUNDED;
        partner_counters.increment(6);
        if (partner_counters.reset_if_reached(6, 100) != 0) {
            if (self_view->get_condition() & NPC_CONDITION_HP_LOW) {
                request_chatter(1);
            } else {
                request_chatter(0);
            }
        }
    } else {
        ai_flags &= ~NPC_AI_SURROUNDED;
    }
    if (view->target_count != 0) {
        for (i = 0; i < view->target_count; i++) {
            if (self_view->is_target_line_clear(view->targets[i].entity_id)) {
                tgt = (TObjBase *)find_active_entity_by_id(view->targets[0].entity_id);
                self_view->set_target(view->targets[i].entity_id, view->targets[i].collider);
                goal.x = tgt->position.x;
                goal.y = self_view->player->body_center.y;
                goal.z = tgt->position.z;
                if (horizontal_distance_squared(&goal, &self_view->player->position) < (10.0f + ai_params.attack_range) * (10.0f + ai_params.attack_range)) {
                    ai_flags |= NPC_AI_TARGET_IN_REACH;
                }
                ai_flags &= ~NPC_AI_NO_CLEAR_TARGET;
                return 1;
            }
        }
        request_chatter(8);
        ai_flags |= NPC_AI_NO_CLEAR_TARGET;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 TNpcPlayer::calc_follow_goal() {
    Vec dir;
    f32 keep_distance;
    f32 z;
    TObjPlayer *obj_player;
    if (escort_leader != 0) {
        if (ai_params.technique_flags & TECHNIQUE_FLAGS_NO_BACKOFF) {
            keep_distance = ai_params.escort_keep_distance;
            if (escort_distance_sq <= (keep_distance * keep_distance)) {
                obj_player = self_view->player;
                dir.x = goal.x - obj_player->position.x;
                z = goal.z - obj_player->position.z;
                dir.y = 0.0f;
                dir.z = z;
                if (0.0f != vector_length(&dir)) {
                    normalize_vector(&dir);
                }
                goal.x = -((ai_params.escort_keep_distance * dir.x) - goal.x);
                goal.z = -((ai_params.escort_keep_distance * dir.z) - goal.z);
                goal.y = self_view->player->body_center.y;
            } else {
                VecCopy(&goal, &leader_view->player->body_center);
            }
        } else {
            VecCopy(&goal, &leader_view->player->body_center);
        }
    } else {
        VecCopy(&goal, &leader_view->player->body_center);
    }
    return 1;
}
#pragma pop

s32 TNpcPlayer::select_recovery_action(s32 check_leader) {
    u8 flags = 0;
    NpcPlayerView *tgt;
    TObjBase *ent;
    if (self_view->get_status() & NPC_STATUS_NEEDS_RECOVERY) {
        flags |= 1;
    }
    if (check_leader != 0 && (leader_view->get_status() & NPC_STATUS_NEEDS_RECOVERY) && escort_leader == 0) {
        flags |= 2;
    }
    tgt = self_view->target_list();
    if (check_leader != 0 && tgt->target_count != 0 && (flags & 2)) {
        partner_counters.increment(5);
        if (partner_counters.reset_if_reached(5, 0x1E) != 0) {
            ent = (TObjBase *)find_active_entity_by_id(tgt->targets[0].entity_id);
            ai_flags &= ~NPC_AI_DOUBLE_AGGRESSION;
            if (ent != NULL) {
                if (horizontal_distance_squared(&ent->position, &self_view->player->position) < ai_params.block_range * ai_params.block_range) {
                    VecCopy(&goal, &ent->position);
                    ai_flags |= NPC_AI_DOUBLE_AGGRESSION | NPC_AI_ATTACK_BLOCKER;
                    return 1;
                }
            }
        }
    }
    if (flags == 3) {
        ai_flags |= NPC_AI_SELF_NEEDS_RECOVERY;
        if (self_view->get_condition() & NPC_CONDITION_STATUS_AILMENT) {
            if (self_view->can_recover(2, 1) != 0) {
                if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
                    recovery_action = 2;
                    return 1;
                }
                if (!(ai_params.technique_flags & TECHNIQUE_FLAGS_NONE)) {
                    recovery_action = 2;
                    return 1;
                }
            }
        } else if (self_view->get_condition() & NPC_CONDITION_HP_LOW) {
            if (self_view->can_recover(0, 1) != 0) {
                if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
                    recovery_action = 0;
                    return 1;
                }
                if (!(ai_params.technique_flags & TECHNIQUE_FLAGS_NONE)) {
                    recovery_action = 0;
                    return 1;
                }
            } else {
                if (partner_counters.get(8) == 0) {
                    request_chatter(0x14);
                }
                partner_counters.increment(8);
                partner_counters.reset_if_reached(8, 0x5DC);
            }
        } else if (self_view->get_condition() & NPC_CONDITION_TP_LOW) {
            if (self_view->can_recover(1, 1) != 0) {
                recovery_action = 1;
                return 1;
            }
        } else {
            flags = 2;
        }
    }
    if (flags == 2) {
        if (self_view->get_status() & NPC_STATUS_ENEMIES_IN_RANGE) {
            return 0;
        }
        VecCopy(&goal, &leader_view->player->body_center);
        ai_flags |= NPC_AI_MOVE_STATE;
        if (leader_view->get_condition() & NPC_CONDITION_STATUS_AILMENT) {
            if (self_view->can_recover(2, 0) != 0) {
                if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
                    recovery_action = 2;
                    return 1;
                }
                if (!(ai_params.technique_flags & TECHNIQUE_FLAGS_NONE)) {
                    recovery_action = 2;
                    return 1;
                }
            }
        } else if (leader_view->get_condition() & NPC_CONDITION_HP_CRITICAL) {
            if (self_view->can_recover(0, 0) != 0) {
                if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
                    recovery_action = 0;
                    return 1;
                }
                if (!(ai_params.technique_flags & TECHNIQUE_FLAGS_NONE)) {
                    recovery_action = 0;
                    return 1;
                }
            }
        }
    }
    if (flags == 1) {
        ai_flags |= NPC_AI_SELF_NEEDS_RECOVERY;
        if (self_view->get_condition() & NPC_CONDITION_STATUS_AILMENT) {
            if (self_view->can_recover(2, 1) != 0) {
                if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
                    recovery_action = 2;
                    return 1;
                }
                if (!(ai_params.technique_flags & TECHNIQUE_FLAGS_NONE)) {
                    recovery_action = 2;
                    return 1;
                }
            }
        } else if (self_view->get_condition() & NPC_CONDITION_HP_LOW) {
            if (self_view->can_recover(0, 1) != 0) {
                if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
                    recovery_action = 0;
                    return 1;
                }
                if (!(ai_params.technique_flags & TECHNIQUE_FLAGS_NONE)) {
                    recovery_action = 0;
                    return 1;
                }
            } else {
                if (partner_counters.get(8) == 0) {
                    request_chatter(0x14);
                }
                partner_counters.increment(8);
                partner_counters.reset_if_reached(8, 0x5DC);
            }
        } else if (self_view->get_condition() & NPC_CONDITION_TP_LOW) {
            if (self_view->can_recover(1, 1) != 0) {
                recovery_action = 1;
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
void TNpcPlayer::deliver_partner_action() {
    Vec d;
    f32 len;

    if ((ai_flags & NPC_AI_CHATTER_PENDING) && !(partner_chatter_flags & 2)) {
        deliver_partner_chatter();
    }
    if (self_view->player->test_action_mask(2) == 0) {
        return;
    }
    switch (ai_state) {
    case 0:
        VecCopy(&move_target, VecCopy(&steer_point, &goal));
        partner_counters.increment(4);
        if (partner_counters.get(4) == 5401) {
            ai_flags &= ~NPC_AI_CHATTER_PENDING;
            chatter_id = 25;
            partner_counters.set(4, 0);
        }
        if (partner_counters.clamp(4, 5400) != 0) {
            request_chatter(11);
        }
        break;
    case 1:
        d.x = move_target.x - self_view->player->position.x;
        d.y = 0.0f;
        d.z = move_target.z - self_view->player->position.z;
        len = vector_length(&d);
        if (len <= 1.0f) {
            return;
        }
        if (self_view->player->actorFlags & 0x100000) {
            send_walk_request();
        } else if (len <= ai_params.max_distance_from_player) {
            if (!(ai_flags & NPC_AI_RUNNING)) {
                send_walk_request();
            } else {
                send_run_request();
            }
        } else {
            ai_flags |= NPC_AI_RUNNING;
            send_run_request();
        }
        break;
    case 2:
        update_combat_action();
        break;
    case 4:
        break;
    case 8:
        dispatch_action(recovery_action);
        break;
    }
    if (ai_state != 2) {
        partner_counters.reset(1);
        partner_counters.reset(5);
        ai_flags &= ~NPC_AI_DOUBLE_AGGRESSION;
    }
    if (ai_state != 1) {
        ai_flags &= ~NPC_AI_RUNNING;
    }
    if (ai_state != 0) {
        partner_counters.reset(4);
    }
}
#pragma pop

void TNpcPlayer::send_walk_request() {
    G_WalkToPosition_6x40 m;
    m.init();
    if (self_view != 0) {
        m.header.client_id = self_view->get_client_id();
        m.pos.x = move_target.x;
        m.pos.z = move_target.z;
        m.flags = 0;
        if (self_view->player->actorFlags & 0x100000) {
            m.flags |= 8;
        }
        m.send();
    }
}

void TNpcPlayer::send_run_request() {
    G_MoveToPosition_6x41_6x42 m;
    m.init();
    if (self_view != 0) {
        m.header.client_id = self_view->get_client_id();
        m.pos.x = move_target.x;
        m.pos.z = move_target.z;
        m.send();
    }
}

void TNpcPlayer::update_combat_action() {
    s32 tier;
    s32 alt;
    s32 id;
    TechniqueParams *tec;
    u32 fl;
    f32 diff;
    f32 mx;

    if (self_view->get_prev_target_id() == 0xFFFF) {
        return;
    }
    if (self_view->player->can_perform_physical_action() == 0) {
        return;
    }
    if (!(ai_params.technique_flags & TECHNIQUE_FLAGS_NONE) && !(self_view->get_condition() & NPC_CONDITION_TP_LOW)) {
        fl = ai_params.technique_flags;
        if (fl & TECHNIQUE_FLAGS_FOIE_GIFOIE) {
            tier = 0;
        } else if (fl & TECHNIQUE_FLAGS_BARTA_GIBARTA) {
            tier = 1;
        } else if (fl & TECHNIQUE_FLAGS_ZONDE_RAZONDE) {
            tier = 2;
        } else {
            tier = 0;
        }
        if ((ai_flags & NPC_AI_SURROUNDED) && (self_view->get_condition() & NPC_CONDITION_HP_HURT_IN_COMBAT)) {
            alt = 1;
        } else {
            alt = 0;
        }
        if (alt == 0) {
            if (fabs_float(10.0f * (3.0517578125e-05f * (f32)rand())) >
                0.1f * (f32)ai_params.attack_technique_probability) {
                partner_request_physical_attack();
                return;
            }
        }
        id = npc_player_combat_action_table[tier][alt];
        tec = calc_technique_parameters(id, *(s8 *)&ai_params.attack_technique_level, 0xFFFF);
        diff = (f32)(get_actor_tp((u8 *)self_view->player) - tec->tp_cost);
        mx = (f32)obj_getS16_2BA((u8 *)self_view->player);
        if (diff / mx <= 0.2f && 0.0f != mx) {
            request_chatter(3);
        }
        ai_flags &= ~NPC_AI_SURROUNDED;
        if (TObjPlayer::try_camera_action((saddr)self_view->player, id) != 0) {
            partner_request_technique_cast(id);
            return;
        }
    }
    partner_request_physical_attack();
}

void TNpcPlayer::request_technique_cast(s32 kind) {
    G_CastTechnique_6x47 cmd;
    TObjPlayer *player;

    player = self_view->player;
    if (kind == TECHNIQUE_RESTA || kind == TECHNIQUE_ANTI) {
        request_chatter(0x16);
    } else if (kind == TECHNIQUE_FOIE || kind == TECHNIQUE_BARTA || kind == TECHNIQUE_ZONDE) {
        request_chatter(0x17);
    } else {
        request_chatter(2);
    }
    if (TObjPlayer::try_camera_action((saddr)player, kind) != 0) {
        cmd.header.client_id = self_view->get_client_id();
        cmd.params.technique_number = kind;
        cmd.params.target_count = 1;
        if (kind == TECHNIQUE_RESTA || kind == TECHNIQUE_ANTI) {
            if (kind == TECHNIQUE_RESTA) {
                ai_flags |= NPC_AI_CAST_RESTA;
            }
            cmd.params.level = get_cast_technique_level(&player->technique_state, kind);
            cmd.targets[0].set_entity_id(leader_view->get_client_id());
            cmd.targets[0].set_index(0);
        } else {
            cmd.params.level = get_cast_technique_level(&player->technique_state, kind);
            cmd.targets[0].set_entity_id((u16)self_view->get_target_id());
            cmd.targets[0].set_index(self_view->get_target_collider());
        }
        cmd.send();
    }
}

void TNpcPlayer::init_state() {
    leader_view->clear_flags();
    self_view->clear_flags();
    switch (init_step) {
    case 0:
        init_follow_target();
        init_step = 1;
    case 1:
        return;
    }
}

void TNpcPlayer::update_condition_flags() {
    leader_view->check_moved();
    leader_view->update_conditions();
    if (leader_view->get_condition() & NPC_CONDITION_STATUS_AILMENT) {
        if (partner_counters.get(0xA) == 0) {
            request_chatter(9);
        }
        partner_counters.increment(0xA);
    } else {
        partner_counters.reset(0xA);
    }
    if (leader_view->scan_targets(30.0f) != 0) {
        if (leader_view->get_condition() & NPC_CONDITION_HP_LOW) {
            if (partner_counters.get(9) == 0) {
                request_chatter(0xC);
            }
            partner_counters.increment(8);
            partner_counters.reset_if_reached(9, 0x2BC);
            return;
        }
        partner_counters.reset(9);
    }
}

#pragma push
#pragma fp_contract on
void TNpcPlayer::partner_observe_surroundings() {
    f32 x;
    TObjPlayer *leader;
    TObjPlayer *self_player;
    NpcPlayerView *view;
    leader = leader_view->player;
    leader_distance_sq = horizontal_distance_squared(&leader->position, &self_view->player->position);
    if (escort_leader != 0) {
        ((s32 (*)(void *, s32, f32))try_update_target_flag__10TNpcPlayerFPvi)(self_view, leader_view->get_client_id(), ai_params.enemy_lock_on_range);
    } else {
        self_view->scan_targets(ai_params.enemy_lock_on_range);
    }
    self_view->update_conditions();
    x = goal.x;
    self_player = self_view->player;
    self_view->goal_angle = (s32)(10430.38043493439 * atan2_float(x - self_player->position.x, goal.z - self_player->position.z));
    self_view->probe_obstacles();
    if (self_view->update_hp_change() != 0) {
        if (self_view->get_condition() & NPC_CONDITION_BIG_DAMAGE) {
            request_chatter(0xE);
        } else if (self_view->get_condition() & NPC_CONDITION_MEDIUM_DAMAGE) {
            request_chatter(0xF);
        } else if (self_view->get_condition() & NPC_CONDITION_HEALED) {
            if (ai_state != 8U) {
                if (ai_flags & NPC_AI_CAST_RESTA) {
                    ai_flags &= ~NPC_AI_CAST_RESTA;
                } else {
                    request_chatter(0x11);
                }
            }
        } else {
            request_chatter(0x10);
        }
    }
    if (self_view->check_moved() == 0) {
        if (ai_state == 1U) {
            if (self_view->get_status() & 0x80) {
                stuck_frames = 0;
                still_frames = 0;
                return;
            }
            still_frames = (s8)(still_frames + 1);
            if (still_frames > 0x1E) {
                still_frames = 0x1E;
            }
            stuck_frames = (s8)(stuck_frames + 1);
        }
    } else {
        view = self_view;
        VecCopy(&view->last_position, &view->player->prev_position);
        stuck_frames = 0;
        still_frames = 0;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TNpcPlayer::select_path_waypoint() {
    Vec midpoint;
    Vec hit;
    Vec route;
    Vec dir;
    Vec normal;
    TObjPlayer *actor;
    f32 len;
    f32 half;
    s32 clear;

    actor = self_view->player;
    dir.x = goal.x - actor->body_center.x;
    dir.y = goal.y - actor->body_center.y;
    dir.z = goal.z - actor->body_center.z;
    len = vector_length(&dir);
    if (0.0f != len) {
        normalize_vector(&dir);
    }
    actor = self_view->player;
    half = len / 2.0f;
    midpoint.x = half * dir.x + actor->body_center.x;
    midpoint.y = half * dir.y + actor->body_center.y;
    midpoint.z = half * dir.z + actor->body_center.z;
    if (partner_find_wall_segment(&actor->body_center, &goal, &hit, &normal) != 0) {
        Vec shortcut = {0.0f, 0.0f, 0.0f};
        clear = partner_route_around_wall(&self_view->player->body_center, &hit, &normal, &route, &shortcut);
        if (!(ai_flags & NPC_AI_DETOUR_WAYPOINT)) {
            if (clear != 0) {
                VecCopy(&waypoint, &shortcut);
            } else {
                VecCopy(&waypoint, &route);
                waypoint.y = goal.y;
                Vec clipped;
                if (partner_clip_path_point(&goal, &waypoint, &clipped) != 0) {
                    VecCopy(&waypoint, &clipped);
                }
            }
            waypoint_dir.x = goal.x - waypoint.x;
            waypoint_dir.y = 0.0f;
            waypoint_dir.z = goal.z - waypoint.z;
            if (0.0f != vector_length(&waypoint_dir)) {
                normalize_vector(&waypoint_dir);
            }
            ai_flags |= NPC_AI_DETOUR_WAYPOINT;
        }
        if (clear != 0) {
            detour_frames = 0;
            if (ai_flags & NPC_AI_DETOUR_OVERSHOOT) {
                Vec d1;
                actor = self_view->player;
                d1.x = steer_point.x - actor->position.x;
                d1.y = 0.0f;
                d1.z = steer_point.z - actor->position.z;
                if (vector_length(&d1) <= 1.5f) {
                    VecCopy(&steer_point, &shortcut);
                    ai_flags &= ~NPC_AI_DETOUR_OVERSHOOT;
                }
            } else {
                VecCopy(&steer_point, &shortcut);
            }
        } else if (ai_flags & NPC_AI_DETOUR_OVERSHOOT) {
            Vec d2;
            actor = self_view->player;
            d2.x = steer_point.x - actor->position.x;
            d2.y = 0.0f;
            d2.z = steer_point.z - actor->position.z;
            if (vector_length(&d2) <= 5.0f) {
                Vec clipped2;
                if (partner_clip_path_point(&self_view->player->body_center, &route, &clipped2) != 0) {
                    VecCopy(&steer_point, &clipped2);
                } else {
                    VecCopy(&steer_point, &route);
                }
                ai_flags &= ~NPC_AI_DETOUR_OVERSHOOT;
                detour_frames = 0;
            }
            detour_frames++;
            if (detour_frames >= 100) {
                detour_frames = 100;
            }
        } else {
            Vec d3;
            detour_frames = 0;
            actor = self_view->player;
            d3.x = steer_point.x - actor->position.x;
            d3.y = 0.0f;
            d3.z = steer_point.z - actor->position.z;
            steer_point.x = waypoint.x;
            steer_point.y = waypoint.y;
            steer_point.z = waypoint.z;
            if (vector_length(&d3) < 1.0f) {
                detour_frames = 0;
                steer_point.x = 40.0f * waypoint_dir.x + waypoint.x;
                steer_point.y = 40.0f * waypoint_dir.y + waypoint.y;
                steer_point.z = 40.0f * waypoint_dir.z + waypoint.z;
                ai_flags |= NPC_AI_DETOUR_OVERSHOOT;
                ai_flags &= ~NPC_AI_DETOUR_WAYPOINT;
            }
        }
        return;
    }
    if (self_view->get_status() & NPC_STATUS_OBSTACLE_AHEAD) {
        if (route_around_object(&route) != 0 && stuck_frames < 30) {
            VecCopy(&steer_point, &route);
        } else {
            if (still_frames > 15) {
                stuck_frames = 0;
            }
            VecCopy(&steer_point, &midpoint);
        }
    } else if (self_view->get_status() & 0x80) {
        VecCopy(&steer_point, &midpoint);
    } else if (stuck_frames >= 15 && stuck_frames < 30) {
        Vec d4;
        Vec detour;
        NpcPlayerView *view = self_view;
        actor = view->player;
        d4.x = actor->position.x - view->last_position.x;
        d4.y = actor->position.y - view->last_position.y;
        d4.z = actor->position.z - view->last_position.z;
        partner_compute_stalled_detour(&actor->position, &goal, &d4, &detour);
        VecCopy(&steer_point, &detour);
    } else {
        if (still_frames > 15) {
            stuck_frames = 0;
        }
        VecCopy(&steer_point, &midpoint);
    }
    ai_flags &= ~NPC_AI_DETOUR_WAYPOINT;
    detour_frames = 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 TNpcPlayer::needs_movement() {
    f32 distance_sq;
    f32 range;
    if (ai_flags & NPC_AI_ATTACK_STATE) {
        return 1;
    }
    range = 12.0f + ai_params.max_distance_from_player;
    if (range >= 40.0f) {
        range = 40.0f;
    }
    distance_sq = horizontal_distance_squared(&goal, &self_view->player->position);
    escort_distance_sq = distance_sq;
    if (distance_sq >= (range * range)) {
        return 1;
    }
    ai_flags = ai_flags & ~NPC_AI_RETURNING_TO_LEADER;
    return 0;
}
#pragma pop

void TNpcPlayer::init_follow_target() {
    TObjPlayer *t = leader_view->player;
    Vec off = {0.0f, 0.0f, 18.0f};
    if (t != NULL) {
        steer_point.x = leader_view->player->position.x + off.x;
        steer_point.y = leader_view->player->position.y + off.y;
        steer_point.z = leader_view->player->position.z + off.z;
        VecCopy(&move_target, &leader_view->player->position);
    }
}

void TNpcPlayer::render() {  }

s32 TNpcPlayer::check_movement_progress() {
    s8 stuck;
    if (horizontal_distance_squared(&move_target, &steer_point) <= 100.0f) {
        return 0;
    }
    stuck = stuck_frames;
    if (stuck > 0x1E) {
        stuck_frames = 0x1EU;
        ai_flags = ai_flags | NPC_AI_STUCK;
        if (partner_counters.get(7) == 0) {
            request_chatter(7);
        }
        partner_counters.increment(7);
        partner_counters.reset_if_reached(7, 0x12C);
        return 0;
    }
    if ((stuck == 0) && (ai_flags & NPC_AI_STUCK)) {
        partner_counters.reset(7);
        request_chatter(0x18);
        ai_flags = ai_flags & ~NPC_AI_STUCK;
    }
    return 1;
}

s32 NpcPlayerView::check_moved() {
    Vec d;
    Vec *prev;
    Vec *pos;
    prev = player->get_prev_position_ptr();
    pos = player->get_position_ptr();
    if (prev == NULL || pos == NULL) {
        return 0;
    }
    d.x = pos->x - prev->x;
    d.y = pos->y - prev->y;
    d.z = pos->z - prev->z;
    if (vector_length(&d) > 0.4f) {
        status = status | NPC_STATUS_MOVED;
        return 1;
    }
    return 0;
}

s32 NpcPlayerView::can_recover(s32 kind, s32 allow_item) {
    switch (kind) {
    case 0:
        if ((allow_item != 0) && (player->find_inventory_item_id(3, 0) != -1)) {
            condition = condition | NPC_CONDITION_HAS_RECOVERY_ITEM;
            return 1;
        }
        if (TObjPlayer::try_camera_action((saddr)player, TECHNIQUE_RESTA) != 0) {
            return 1;
        }
        break;
    case 1:
        if (player->find_inventory_item_id(3, 1) != -1) {
            condition = condition | NPC_CONDITION_HAS_RECOVERY_ITEM;
            return 1;
        }
        break;
    case 2:
        if (TObjPlayer::try_camera_action((saddr)player, TECHNIQUE_ANTI) != 0) {
            return 1;
        }
        break;
    case 3:
        if (player->find_inventory_item_id(3, 6) != -1) {
            condition = condition | NPC_CONDITION_HAS_RECOVERY_ITEM;
            return 1;
        }
        if (TObjPlayer::try_camera_action((saddr)player, TECHNIQUE_REVERSER) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

s32 NpcPlayerView::scan_targets(f32 range) {
    if (scan_nearby_enemies(&player->position, range) != 0) {
        status = status | NPC_STATUS_ENEMIES_IN_RANGE;
        return 1;
    }
    return 0;
}

s32 try_update_target_flag__10TNpcPlayerFPvi(NpcPlayerView *view, s32 id) {
    TObjPlayer *obj_player;

    obj_player = view->player;
    if (((s32 (*)(void *, void *, s32, TObjPlayer *))find_parts_in_range__10TNpcPlayerFPvPvif)(view, &obj_player->position, id, obj_player) != 0) {
        view->status = view->status | NPC_STATUS_ENEMIES_IN_RANGE;
        return 1;
    }
    return 0;
}

s32 NpcPlayerView::update_conditions() {
    f32 hp_ratio;
    f32 tp_max;
    f32 actor_hp;
    f32 actor_tp;
    s32 actorFlags;
    s32 changed;
    changed = 0;
    actor_hp = (f32)player->get_actor_hp();
    hp_ratio = actor_hp / (f32)player->get_hpmax();
    if (status & 2) {
        if (hp_ratio <= 0.25f) {
            changed = 1;
            condition = condition | NPC_CONDITION_HP_LOW;
            status = status | NPC_STATUS_NEEDS_RECOVERY;
        }
        if (hp_ratio <= 0.75f) {
            changed = 1;
            condition = condition | NPC_CONDITION_HP_HURT_IN_COMBAT;
        }
    } else if (hp_ratio <= 0.75f) {
        changed = 1;
        condition = condition | NPC_CONDITION_HP_LOW;
        status = status | NPC_STATUS_NEEDS_RECOVERY;
    }
    if (hp_ratio <= 0.1f) {
        changed = 1;
        condition = condition | NPC_CONDITION_HP_CRITICAL;
        status = status | NPC_STATUS_NEEDS_RECOVERY;
    }
    actorFlags = player->actorFlags;
    if ((actorFlags & 1) || (actorFlags & 2) || (actorFlags & 0x10)) {
        changed = 1;
        condition = condition | NPC_CONDITION_STATUS_AILMENT;
        status = status | NPC_STATUS_NEEDS_RECOVERY;
    }
    actor_tp = (f32)get_actor_tp((u8 *)player);
    tp_max = (f32)obj_getS16_2BA((u8 *)player);
    if (((actor_tp / tp_max) <= 0.2f) && (0.0f != tp_max)) {
        status = status | NPC_STATUS_NEEDS_RECOVERY;
        condition = condition | NPC_CONDITION_TP_LOW;
    }
    return changed;
}

s32 NpcPlayerView::update_hp_change() {
    s16 damage;
    s16 actor_hp;
    s16 hpmax;
    s16 prev_hp;
    actor_hp = player->get_actor_hp();
    hpmax = player->get_hpmax();
    if (last_hp <= 0) {
        last_hp = actor_hp;
        return 0;
    }
    prev_hp = last_hp;
    damage = (s16)(prev_hp - actor_hp);
    if (prev_hp >= (s32)(actor_hp - 1)) {
        if ((f32)damage > (0.3f * (f32)hpmax)) {
            condition = condition | NPC_CONDITION_BIG_DAMAGE;
        } else if ((f32)damage > (0.2f * (f32)hpmax)) {
            condition = condition | NPC_CONDITION_MEDIUM_DAMAGE;
        } else if ((f32)damage > (0.01f * (f32)hpmax)) {
            condition = condition | NPC_CONDITION_SMALL_DAMAGE;
        }
    } else {
        condition = condition | NPC_CONDITION_HEALED;
    }
    last_hp = actor_hp;
    return damage ? 1 : 0;
}

// Dead-stripped from the DOL: no code of it survives, only its literal (0.2,
// pooled between init_ai_state's 19.0 and partner_view_update_hp_change's 0.3).
// It is the low-HP test hp_change and partner_view_update_conditions make against
// a fifth of the maximum. Name inferred from that role.
bool TNpcPlayer::is_hp_low(f32 hp, f32 max_hp) {
    return hp <= 0.2f * max_hp;
}

NpcPlayerView::NpcPlayerView(s32 id) {
    s32 i;
    player = (TObjPlayer *)find_entity_by_id(id);
    last_position.x = 0.0f;
    last_position.y = 0.0f;
    last_position.z = 0.0f;
    status = 0;
    condition = 0;
    client_id = id;
    last_hp = -1;
    target_collider = 0;
    target_count = 0;
    for (i = 0; i < 10; i++) {
        targets[i].entity_id = 0xFFFF;
        targets[i].distance_sq = 0.0f;
    }
    obstacle_angle = 0;
    probe_body.offset.x = 0.0f;
    probe_body.offset.y = 0.0f;
    probe_body.offset.z = 5.0f;
    probe_body.radius = 19.0f;
    probe_body.half_width = 5.0f;
    probe_body.shape = 0;
    probe_body.flags = 0x1103;
    probe = new TObjCollidable(tl_05);
    if (probe != 0) {
        init_collision_body_parts(probe, &probe_body, 1);
    }
    target_id = 0xFFFF;
    prev_target_id = 0xFFFF;
}

#pragma push
#pragma fp_contract on
s32 NpcPlayerView::is_player_lost() {
    TObjPlayer *v;
    player = get_player_by_client_id(client_id);
    v = player;
    if (v == NULL) {
        return 1;
    }
    return (u32)__cntlzw(v->all_parents_unqueued_for_destruction()) >> 5;
}

NpcPlayerView::~NpcPlayerView() {
    if (probe != NULL) {
        free_collision_body_parts(probe);
        probe->queue_destruction();
        probe = NULL;
    }
}

s32 NpcPlayerView::is_target_line_clear(u32 id) {
    Vec target;
    VecCopy(&target, &((TObjChara *)find_active_entity_by_id(id))->body_center);
    target.y = player->body_center.y;
    if (csnVector(&player->body_center, &target, 0x2100) != NULL) {
        return 0;
    }
    return 1;
}

s32 NpcPlayerView::scan_nearby_enemies(Vec *pos, f32 range) {
    Vec origin;
    TObjCollidable *actor;
    s32 found;
    s32 i;
    s32 c;
    s32 j;
    f32 d;
    found = 0;
    ((TObjBase *)(player))->get_room();
    VecCopy(&origin, pos);
    target_count = 0;
    for (j = 0; j < 10; j++) {
        targets[j].entity_id = 0xFFFF;
        targets[j].distance_sq = 0.0f;
    }
    i = TLobby::get_game_mode();
    range = range * range;
    for (; i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i++) {
        actor = (TObjCollidable *)TObjPlayer::get_player_data(i);
        if (actor->is_active() == 0 || !(actor->actorFlags & 0x20000000)) {
            continue;
        }
        for (c = 0; c < actor->body_count; c++) {
            if (actor->bodies == 0) {
                break;
            }
            if (!(actor->bodies[c].flags & 0x8000)) {
                continue;
            }
            d = horizontal_distance_squared(&origin, &actor->bodies[c].center);
            if (d < range) {
                found = 1;
                targets[target_count].entity_id = actor->get_entity_id();
                targets[target_count].distance_sq = d;
                targets[target_count].collider = c;
                if (target_count >= 9) {
                    break;
                }
                target_count++;
            }
        }
    }
    sort_targets(&targets[0], 0, target_count - 1);
    return found;
}

s32 find_parts_in_range__10TNpcPlayerFPvPvif(NpcPlayerView *view, Vec *pos, u16 id, f32 range) {
    TObjCollidable *actor;
    s32 found;
    s32 i;
    f32 d;
    s32 j;

    view->target_count = 0;
    found = 0;
    for (j = 0; j < 10; j++) {
        view->targets[j].entity_id = 0xFFFF;
        view->targets[j].distance_sq = 0.0f;
    }
    actor = find_entity_by_id(id);
    if (((TObjBase *)actor)->is_alive() != 0) {
        range = range * range;
        for (i = 0; i < actor->body_count; i++) {
            if (actor->bodies == 0) {
                break;
            }
            d = horizontal_distance_squared(pos, &actor->bodies[i].center);
            if (d < range) {
                found = 1;
                view->targets[view->target_count].entity_id = actor->get_entity_id();
                view->targets[view->target_count].distance_sq = d;
                view->targets[view->target_count].collider = i;
                if (view->target_count >= 9) {
                    break;
                }
                view->target_count++;
            }
        }
    }
    view->sort_targets(&view->targets[0], 0, view->target_count - 1);
    return found;
}

void NpcPlayerView::sort_targets(NpcPlayerViewTarget *entries, s32 lo, s32 hi) {
    s32 pivot;

    if (lo < hi) {
        pivot = partition_targets(entries, lo, hi);
        sort_targets(entries, lo, pivot - 1);
        sort_targets(entries, pivot + 1, hi);
    }
}

s32 NpcPlayerView::partition_targets(NpcPlayerViewTarget *a, int lo, int hi) {
    NpcPlayerViewTarget tmp;
    f32 pivot;
    s32 i;
    s32 j;

    j = hi;
    i = lo - 1;
    pivot = a[hi].distance_sq;
    for (;;) {
        while (a[++i].distance_sq < pivot) {
        }
        while (i < --j && pivot < a[j].distance_sq) {
        }
        if (i >= j || i >= 10 || j >= 10) {
            break;
        }
        copy_target(&a[i], &tmp);
        copy_target(&a[j], &a[i]);
        copy_target(&tmp, &a[j]);
    }
    copy_target(&a[i], &tmp);
    copy_target(&a[hi], &a[i]);
    copy_target(&tmp, &a[hi]);
    return i;
}

s32 NpcPlayerView::probe_obstacles() {
    s32 i;
    TObjCollidable *actor;
    CollisionBody *contact;
    TObjCollidable *sweep;
    sweep = probe;
    if (sweep == NULL) {
        return 0;
    }
    VecCopy(&sweep->position, &player->position);
    probe->rotation_y = goal_angle;
    for (i = TLobby::get_game_mode(); i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count() + get_registered_object_count(); i++) {
        actor = (TObjCollidable *)TObjPlayer::get_player_data(i);
        if ((actor != NULL) && !(actor->actorFlags & 0x80000000)) {
            contact = (CollisionBody *)probe->find_actor_body_contact(reinterpret_cast<TObjCollidable *>(actor), 10000.0f);
            if (contact != NULL) {
                if (actor->actorFlags & 0x40000000) {
                    if (!(contact->flags & 8) && !(contact->flags & 0x100) && !(contact->flags & 0x200)) {
                        copy_collision_body(&obstacle_body, contact);
                        obstacle_angle = actor->rotation_y;
                        status |= NPC_STATUS_OBSTACLE_AHEAD;
                        return 1;
                    }
                } else if (actor->actorFlags & 0x20000000) {
                    if (!(contact->flags & 8) && !(contact->flags & 0x100) && !(contact->flags & 0x200)) {
                        status |= 0x80;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

s32 TNpcPlayer::partner_find_wall_segment(Vec *from, Vec *to, Vec *point, Vec *normal) {
    CsnHit *hit;
    hit = csnVector(from, to, 0x2100);
    if (hit != NULL) {
        VecCopy(point, &hit->contact->point);
        VecCopy(normal, &hit->contact->normal);
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
s32 TNpcPlayer::partner_route_around_wall(Vec *from, Vec *to, Vec *d, Vec *out, Vec *out2) {
    Line line;
    Vec dir;
    Vec perp;
    Vec hit;
    Vec tmp;
    Vec v;
    f32 len;
    f32 s;
    dir.x = to->x - from->x;
    dir.y = 0.0f;
    dir.z = to->z - from->z;
    len = vector_length(&dir);
    if (0.0f != len) {
        normalize_vector(&dir);
    }
    perp.x = d->z;
    perp.y = 0.0f;
    perp.z = -d->x;
    if (vec3_dot(&dir, &perp) < 0.0f) {
        perp.x = -perp.x;
        perp.z = -perp.z;
    }
    line.o.x = self_view->player->body_center.x;
    line.o.y = self_view->player->body_center.y;
    line.o.z = self_view->player->body_center.z;
    line.d.x = perp.x;
    line.d.y = 0.0f;
    line.d.z = perp.z;
    project_point_onto_line(&goal, &line, &hit);
    s = 1.5f * len;
    if (s <= 20.0f) {
        s = 20.0f;
    }
    out->x = perp.x * s + from->x;
    out->y = from->y;
    out->z = perp.z * s + from->z;
    VecCopy(&tmp, &leader_view->player->body_center);
    if (csnVector(&tmp, &hit, 0x2100) != NULL) {
        hit.x = 5.0f * perp.x + hit.x;
        hit.z = 5.0f * perp.z + hit.z;
        return 0;
    }
    v.x = leader_view->player->body_center.x - hit.x;
    v.z = leader_view->player->body_center.z - hit.z;
    v.y = 0.0f;
    if (0.0f != vector_length(&v)) {
        normalize_vector(&v);
    }
    out2->x = 5.0f * perp.x + hit.x;
    out2->z = 5.0f * perp.z + hit.z;
    out2->y = 0.0f;
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TNpcPlayer::partner_compute_stalled_detour(Vec *from, Vec *to, Vec *d, Vec *out) {
    Vec dir;
    Vec save;
    Vec a;
    Vec b;
    Vec diff;
    dir.x = -d->x;
    dir.y = 0.0f;
    dir.z = -d->z;
    if (0.0f != vector_length(&dir)) {
        normalize_vector(&dir);
    }
    VecCopy(&save, &dir);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, 0x4000);
    matrix_mult_vec(0, &dir, &a);
    pop_matrices(1);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, -0x4000);
    matrix_mult_vec(0, &dir, &b);
    pop_matrices(1);
    diff.x = to->x - from->x;
    diff.y = 0.0f;
    diff.z = to->z - from->z;
    if (0.0f != vector_length(&diff)) {
        normalize_vector(&diff);
    }
    if (vec3_dot(&diff, &a) > 0.0f) {
        VecCopy(&dir, &b);
    } else {
        VecCopy(&dir, &a);
    }
    if (stuck_frames >= 0x14) {
        out->x = -((20.0f * dir.x) - from->x);
        out->y = from->y;
        out->z = -((20.0f * dir.z) - from->z);
    } else {
        out->x = 20.0f * dir.x + from->x;
        out->y = from->y;
        out->z = 20.0f * dir.z + from->z;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TNpcPlayer::route_around_object(Vec *out) {
    CollisionBody info;
    Vec perp;
    Vec to;
    Vec toSelf;
    f32 r;
    copy_collision_body(&info, &self_view->obstacle_body);
    if (info.shape == 0 || info.shape == 0 ||
        (info.half_width <= 12.0f && info.shape == 1 && info.half_width == info.radius)) {
        TObjPlayer *t = self_view->player;
        r = 20.0f + info.radius;
        to.x = t->position.x - info.center.x;
        to.y = 0.0f;
        to.z = t->position.z - info.center.z;
        perp.x = to.z;
        perp.y = 0.0f;
        perp.z = -to.x;
        if (0.0f != vector_length(&perp)) {
            normalize_vector(&perp);
        }
        toSelf.x = goal.x - info.center.x;
        toSelf.y = 0.0f;
        toSelf.z = goal.z - info.center.z;
        if (0.0f != vector_length(&toSelf)) {
            normalize_vector(&toSelf);
        }
        if (vec3_dot(&perp, &toSelf) < 0.0f) {
            perp.x = -perp.x;
            perp.z = -perp.z;
        }
        if (0.0f != vector_length(&to)) {
            normalize_vector(&to);
        }
        perp.x += to.x;
        perp.y += to.y;
        perp.z += to.z;
        if (0.0f != vector_length(&perp)) {
            normalize_vector(&perp);
        }
        out->x = r * perp.x + info.center.x;
        out->y = r * perp.y + info.center.y;
        out->z = r * perp.z + info.center.z;
        if (stuck_frames > 10) {
            out->x = info.center.x - r * perp.x;
            out->y = info.center.y - r * perp.y;
            out->z = info.center.z - r * perp.z;
        }
    } else {
        Vec a = {1.0f, 0.0f, 0.0f};
        Vec b = {0.0f, 0.0f, 1.0f};
        Vec c0;
        Vec c2;
        Vec c1;
        Vec c3;
        Vec esc;
        Vec dir;
        Vec axis;
        Vec clip;
        Vec alt;
        f32 dist;
        a.x *= info.radius;
        b.z *= info.half_width;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, self_view->obstacle_angle + 0x4000);
        matrix_mult_vec(0, &a, &a);
        matrix_mult_vec(0, &b, &b);
        pop_matrices(1);
        c0.x = info.center.x + a.x;
        c0.y = info.center.y + a.y;
        c0.z = info.center.z + a.z;
        c1.x = info.center.x - a.x;
        c1.y = info.center.y - a.y;
        c1.z = info.center.z - a.z;
        c2.x = info.center.x + b.x;
        c2.y = info.center.y + b.y;
        c2.z = info.center.z + b.z;
        c3.x = info.center.x - b.x;
        c3.y = info.center.y - b.y;
        c3.z = info.center.z - b.z;
        dir.x = leader_view->player->position.x - info.center.x;
        dir.y = leader_view->player->position.y - info.center.y;
        dir.z = leader_view->player->position.z - info.center.z;
        if (0.0f != vector_length(&dir)) {
            normalize_vector(&dir);
        }
        calc_box_escape_axis(&c0, &c1, &c2, &c3, &self_view->player->position, &axis, &dist);
        VecCopy(&esc, &axis);
        if (vec3_dot(&dir, &esc) < 0.0f) {
            esc.x = -esc.x;
            esc.z = -esc.z;
        }
        r = dist;
        out->x = r * esc.x + self_view->player->position.x;
        out->y = r * esc.y + self_view->player->body_center.y;
        out->z = r * esc.z + self_view->player->position.z;
        if (partner_clip_path_point(&self_view->player->body_center, out, &clip) != 0) {
            out->x = clip.x;
            out->y = clip.y;
            out->z = clip.z;
        }
        if (stuck_frames > 15) {
            alt.x = esc.z;
            alt.y = 0.0f;
            alt.z = esc.x;
            if (vec3_dot(&dir, &alt) < 0.0f) {
                alt.x = -alt.x;
                alt.z = -alt.z;
            }
            out->x = r * alt.x + self_view->player->position.x;
            out->y = self_view->player->body_center.y;
            out->z = r * alt.z + self_view->player->position.z;
        }
    }
    return 1;
}
#pragma pop

void TNpcPlayer::calc_box_escape_axis(Vec *a, Vec *b, Vec *c, Vec *d, Vec *pos, Vec *axis, f32 *reach) {
    Vec point1;
    Vec point2;
    Vec first;
    Vec second;
    Vec center1;
    Vec center2;
    Line line1;
    Line line2;
    f32 len1;
    f32 len2;
    f32 dist1;
    f32 dist2;
    f32 reach1;
    f32 reach2;

    first.x = a->x - b->x;
    first.y = a->y - b->y;
    first.z = a->z - b->z;
    len1 = vector_length(&first);
    if (len1 != 0.0f) {
        normalize_vector(&first);
    }
    second.x = c->x - d->x;
    second.y = c->y - d->y;
    second.z = c->z - d->z;
    len2 = vector_length(&second);
    if (len2 != 0.0f) {
        normalize_vector(&second);
    }
    line1.o.x = b->x;
    line1.o.y = b->y;
    line1.o.z = b->z;
    line1.d.x = first.x;
    line1.d.y = first.y;
    line1.d.z = first.z;
    dist1 = project_point_onto_line(pos, &line1, &point1);
    center1.x = 0.5f * (a->x + b->x);
    center1.y = 0.5f * (a->y + b->y);
    center1.z = 0.5f * (a->z + b->z);
    reach1 = (10.0f + 0.5f * len1) - xyz_distance(&center1, &point1);
    if (reach1 < 0.0f) {
        reach1 = 0.5f * len1;
    }
    line2.o.x = d->x;
    line2.o.y = d->y;
    line2.o.z = d->z;
    line2.d.x = second.x;
    line2.d.y = second.y;
    line2.d.z = second.z;
    dist2 = project_point_onto_line(pos, &line2, &point2);
    center2.x = 0.5f * (a->x + b->x);
    center2.y = 0.5f * (a->y + b->y);
    center2.z = 0.5f * (a->z + b->z);
    reach2 = (10.0f + 0.5f * len2) - xyz_distance(&center2, &point2);
    if (reach2 < 0.0f) {
        reach2 = 0.5f * len2;
    }
    if (dist2 < dist1) {
        *reach = 10.0f + reach1;
        VecCopy(axis, &first);
    } else if (dist2 == dist1) {
        *reach = 7.0f;
        axis->x = 0.5f * (first.x + second.x);
        axis->y = 0.5f * (first.y + second.y);
        axis->z = 0.5f * (first.z + second.z);
    } else {
        *reach = 10.0f + reach2;
        VecCopy(axis, &second);
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literals (0.5 and
// 12.0, pooled between partner_clip_path_point's 10.0 and
// calc_box_escape_axis's 7.0). It is the half-size limit under which
// route_around_object walks around an obstacle instead of escaping its box.
// Name inferred from that role.
bool TNpcPlayer::is_small_obstacle(f32 size) {
    return 0.5f * size <= 12.0f;
}

#pragma push
#pragma fp_contract on
s32 TNpcPlayer::partner_clip_path_point(Vec *from, Vec *to, Vec *out) {
    Vec dir;
    CsnHit *hit;
    hit = csnVector(from, to, 0x2100);
    if (hit != NULL) {
        dir.x = to->x - from->x;
        dir.y = 0.0f;
        dir.z = to->z - from->z;
        if (0.0f != vector_length(&dir)) {
            normalize_vector(&dir);
        }
        VecCopy(out, &hit->contact->point);
        out->x = -((10.0f * dir.x) - out->x);
        out->y = -((10.0f * dir.y) - out->y);
        out->z = -((10.0f * dir.z) - out->z);
        return 1;
    }
    return 0;
}
#pragma pop

void TNpcPlayer::request_chatter(u32 id) {
    if (escort_leader != 0 && (id == 4 || id == 0x11)) {
        return;
    }
    partner_counters.reset(0);
    if (id != chatter_id) {
        chatter_id = id;
        ai_flags |= NPC_AI_CHATTER_PENDING;
    }
}

void TNpcPlayer::deliver_partner_chatter() {
    u32 id;
    char *text;
    if (chatter_id >= 0x19) {
        ai_flags &= ~NPC_AI_CHATTER_PENDING;
        chatter_id = 0x19;
        return;
    }
    if (TObjPlayer::is_any_teammate_in_state() != 0) {
        return;
    }
    id = self_view->player->get_entity_id();
    if (id != 0xFFFF) {
        text = (char *)get_partner_custom_text(chatter_id, id);
        if (text != 0) {
            TWindowCtrl::open(id, text, 0x1B);
        } else {
            text = npc_partner_dialogue_state[chatter_id].text;
            if (text[0] != 0) {
                TWindowCtrl::open(id, text, 0x1B);
            }
        }
    }
    ai_flags &= ~NPC_AI_CHATTER_PENDING;
    if (partner_counters.reset_if_reached(0, 0x190) != 0) {
        chatter_id = 0x19;
    }
}

void TNpcPlayer::handle_action(s32 action) {
    s32 item;

    switch (action) {
    case 0:
        item = self_view->player->find_inventory_item_id(3, 0);
        if (item != -1) {
            try_send_6x27_use_item(self_view->player, item);
            ai_flags = ai_flags | NPC_AI_CAST_RESTA;
        }
        break;
    case 1:
        item = self_view->player->find_inventory_item_id(3, 1);
        if (item != -1) {
            try_send_6x27_use_item(self_view->player, item);
            return;
        }
        break;
    case 2:
        item = self_view->player->find_inventory_item_id(3, 6);
        if (item != -1) {
            try_send_6x27_use_item(self_view->player, item);
        }
        break;
    }
}

void TNpcPlayer::change_ai_state(u32 state) {
    ai_state = state;
    ai_flags = ai_flags & ~NPC_AI_TARGET_IN_REACH;
    switch (state) {
    case 0:
        ai_flags = ai_flags & ~(NPC_AI_MOVE_STATE | NPC_AI_ATTACK_STATE);
        VecCopy(&goal, &self_view->player->body_center);
        return;
    case 1:
        ai_flags = ai_flags & ~NPC_AI_ATTACK_STATE;
        ai_flags = ai_flags | NPC_AI_MOVE_STATE;
        return;
    case 2:
        ai_flags = ai_flags & ~NPC_AI_MOVE_STATE;
        ai_flags = ai_flags | NPC_AI_ATTACK_STATE;
        return;
    case 8:
        VecCopy(&goal, &self_view->player->body_center);
        return;
    case 16:
        ai_flags = ai_flags & ~NPC_AI_ATTACK_STATE;
        ai_flags = ai_flags | NPC_AI_MOVE_STATE;
    default:
        return;
    }
}

void TNpcPlayer::dispatch_action(s32 action) {
    switch (action) {
    case 0:
        if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
            handle_action(action);
        } else {
            request_technique_cast(TECHNIQUE_RESTA);
        }
        if (ai_flags & NPC_AI_SELF_NEEDS_RECOVERY) {
            request_chatter(0x13);
        }
        return;
    case 1:
        if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
            handle_action(action);
            return;
        }
        break;
    case 2:
        if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
            handle_action(action);
            return;
        }
        request_technique_cast(TECHNIQUE_ANTI);
        return;
    case 3:
        if (self_view->get_condition() & NPC_CONDITION_HAS_RECOVERY_ITEM) {
            handle_action(action);
            return;
        }
        request_technique_cast(TECHNIQUE_REVERSER);
        break;
    }
}

#pragma push
#pragma scheduling off
void TNpcPlayer::partner_request_physical_attack() {
    u32 prev_target;
    u32 target;
    prev_target = this->self_view->get_prev_target_id();
    target = this->self_view->get_target_id();
    if (target != prev_target) {
        partner_counters.set(1, 0);
    }
    partner_counters.reset_if_reached(1, 3);
    send_partner_attack_stage_request();
}
#pragma pop

void TNpcPlayer::send_partner_attack_stage_request() {
    G_Attack_6x43 cmd43;
    G_Attack_6x44 cmd44;
    G_Attack_6x45 cmd45;
    TObjPlayer *player;
    TObjCollidable *target;
    switch (partner_counters.get(1)) {
    case 0:
        cmd43.init();
        if (self_view != NULL) {
            cmd43.header.client_id = self_view->get_client_id();
            cmd43.action_type = 0;
            target = find_active_entity_by_id(self_view->get_target_id());
            if (target != NULL) {
                cmd43.angle_y = calc_angle_to(&self_view->player->position, &target->position);
                player = self_view->player;
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->set_count(1);
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_uid(self_view->get_target_id());
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_collider_index(self_view->get_target_collider());
                cmd43.send();
                partner_counters.increment(1);
            }
        }
        break;
    case 1:
        cmd44.init();
        if (self_view != NULL) {
            cmd44.header.client_id = self_view->get_client_id();
            cmd44.action_type = 1;
            target = find_active_entity_by_id(self_view->get_target_id());
            if (target != NULL) {
                cmd44.angle_y = calc_angle_to(&self_view->player->position, &target->position);
                player = self_view->player;
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->set_count(1);
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_uid(self_view->get_target_id());
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_collider_index(self_view->get_target_collider());
                cmd44.send();
                partner_counters.increment(1);
            }
        }
        break;
    case 2:
        cmd45.init();
        if (self_view != NULL) {
            cmd45.header.client_id = self_view->get_client_id();
            cmd45.action_type = 1;
            target = find_active_entity_by_id(self_view->get_target_id());
            if (target != NULL) {
                cmd45.angle_y = calc_angle_to(&self_view->player->position, &target->position);
                player = self_view->player;
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->set_count(1);
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_uid(self_view->get_target_id());
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_collider_index(self_view->get_target_collider());
                cmd45.send();
                partner_counters.reset(1);
                request_chatter(0xD);
            }
        }
        break;
    }
}

void TNpcPlayer::partner_request_technique_cast(s32 kind) { request_technique_cast(kind); }

void enable_quest_npc_visual() { quest_npc_visual_pending = 1; }

void TNpcPlayer::init_equipment() {
    TObjPlayer *player;
    s32 flags;

    flags = this->ai_params.technique_flags;
    player = this->self_view->player;
    if (flags & TECHNIQUE_FLAGS_FOIE_GIFOIE) {
        TObjPlayer::set_technique_level_clamped(player, this->ai_params.attack_technique_level, 0);
        TObjPlayer::set_technique_level_clamped(player, this->ai_params.attack_technique_level, 1);
        player->technique_state.set_technique_level(0, this->ai_params.attack_technique_level);
        player->technique_state.set_technique_level(1, this->ai_params.attack_technique_level);
    } else if (flags & TECHNIQUE_FLAGS_BARTA_GIBARTA) {
        TObjPlayer::set_technique_level_clamped(player, this->ai_params.attack_technique_level, 3);
        TObjPlayer::set_technique_level_clamped(player, this->ai_params.attack_technique_level, 4);
        player->technique_state.set_technique_level(3, this->ai_params.attack_technique_level);
        player->technique_state.set_technique_level(4, this->ai_params.attack_technique_level);
    } else if (flags & TECHNIQUE_FLAGS_ZONDE_RAZONDE) {
        TObjPlayer::set_technique_level_clamped(player, this->ai_params.attack_technique_level, 6);
        TObjPlayer::set_technique_level_clamped(player, this->ai_params.attack_technique_level, 8);
        player->technique_state.set_technique_level(6, this->ai_params.attack_technique_level);
        player->technique_state.set_technique_level(8, this->ai_params.attack_technique_level);
    }
    TObjPlayer::set_technique_level_clamped(player, this->ai_params.support_technique_level, 0xF);
    TObjPlayer::set_technique_level_clamped(player, this->ai_params.support_technique_level, 0x10);
    player->technique_state.set_technique_level(0xF, this->ai_params.support_technique_level);
    player->technique_state.set_technique_level(0x10, this->ai_params.support_technique_level);
}
