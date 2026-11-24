#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/system/MatrixStack.h"
#include <string.h>
#include <dolphin/os/OSCache.h>
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007C5C0.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/system/main_loop.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/AccelerationCurve.h"
#include "pso/render/TDLGraph.h"
#include "pso/unk/TLobby.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/render_util.h"
#include "pso/system/ControllerInputState.h"
#include "pso/network/protocol/GameplaySoundPacket.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8036EF0C.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnQuery.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/unk/TLobby_803382E4.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"

#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/unk/TLobby_803DE778.h"

// Two debug chunk models other units draw with draw_chunk_object: debug_chunk_object (TObjEneBm3FlyNest,
// TObjEneRecobox, and TObjHMS_EZRope_Player through debug_chunk_b_object) and debug_cylinder_object (TBoss1Dragon, TBoss2Mine,
// TObjFogCollision, TBoss8Dragon). Each is a strip list, an NJD_CV_VN vertex list, an NJS_CNK_MODEL and its NJS_OBJECT.
struct DebugChunkVertexVN {
    f32 pos[3];
    f32 nrm[3];
};
struct DebugChunkVertices16 {
    s32 head;   // NJD_CV_VN chunk header
    s32 range;  // index offset 0, vertex count
    DebugChunkVertexVN vertex[16];
    s32 end;    // NJD_CE
};
struct DebugChunkVertices58 {
    s32 head;
    s32 range;
    DebugChunkVertexVN vertex[58];
    s32 end;
};

static s16 debug_chunk_a_strips[59] = {
    0x2517, 0x0006, 0xB2B2, 0xFFB2, 0x7F7F, 0xFF7F, 0xFFFF, 0x0BFF, 0x0040, 0x0030, 0x0006, 0xFFFA,
    0x0006, 0x000A, 0x0004, 0x000C, 0x0002, 0x000E, 0x0003, 0x0008, 0x0009, 0x0007, 0x0003, 0x0000,
    0x0001, 0x000F, 0xFFEE, 0x0005, 0x0007, 0x0006, 0x0008, 0x000A, 0x0009, 0x000B, 0x0007, 0x000D,
    0x0005, 0x000F, 0x0003, 0x0001, 0x0002, 0x0000, 0x000E, 0x000F, 0x000D, 0xFFFB, 0x0002, 0x0003,
    0x0004, 0x0005, 0x0006, 0x0005, 0x000E, 0x000D, 0x000C, 0x000B, 0x000A, 0x0000, 0x00FF,
};
static DebugChunkVertices16 debug_chunk_a_vertices = {
    0x00610029, 0x00100000,
    {
        {{2.0f, -5.0f, 0.0f}, {0.77638215f, -0.63026243f, 5.3428018e-08f}},
        {{2.0f, 5.0f, 0.0f}, {0.77638215f, 0.63026243f, 5.3428018e-08f}},
        {{1.4142135f, -5.0f, -1.4142135f}, {0.54898506f, -0.6302625f, -0.54898506f}},
        {{1.4142135f, 5.0f, -1.4142135f}, {0.54898506f, 0.6302625f, -0.54898506f}},
        {{0.0f, -5.0f, -1.9999999f}, {-1.7809338e-08f, -0.6302625f, -0.7763821f}},
        {{0.0f, 5.0f, -1.9999999f}, {-1.7809338e-08f, 0.6302625f, -0.7763821f}},
        {{-1.4142134f, -5.0f, -1.4142134f}, {-0.54898506f, -0.6302625f, -0.54898506f}},
        {{-1.4142134f, 5.0f, -1.4142134f}, {-0.54898506f, 0.6302625f, -0.54898506f}},
        {{-1.9999998f, -5.0f, 0.0f}, {-0.77638215f, -0.63026243f, 0.0f}},
        {{-1.9999998f, 5.0f, 0.0f}, {-0.77638215f, 0.63026243f, 0.0f}},
        {{-1.4142134f, -5.0f, 1.4142134f}, {-0.54898506f, -0.6302625f, 0.54898506f}},
        {{-1.4142134f, 5.0f, 1.4142134f}, {-0.54898506f, 0.6302625f, 0.54898506f}},
        {{0.0f, -5.0f, 1.9999998f}, {0.0f, -0.63026243f, 0.77638215f}},
        {{0.0f, 5.0f, 1.9999998f}, {0.0f, 0.63026243f, 0.77638215f}},
        {{1.4142134f, -5.0f, 1.4142134f}, {0.54898506f, -0.63026243f, 0.5489851f}},
        {{1.4142134f, 5.0f, 1.4142134f}, {0.54898506f, 0.63026243f, 0.5489851f}},
    },
    0x000000FF,
};
static NJS_CNK_MODEL debug_chunk_a_model = {&debug_chunk_a_vertices, debug_chunk_a_strips, {0.0f, 0.0f, -0.0f}, 5.385165f};
static NJS_OBJECT debug_chunk_a_object = {
    NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &debug_chunk_a_model,
    {0.0f, 0.0f, 0.0f}, {0, 0, 0}, {1.0f, 1.0f, 1.0f}, NULL, NULL,
};
static s16 debug_chunk_b_strips[161] = {
    0x2517, 0x0006, 0xB2B2, 0xFFB2, 0x7F7F, 0xFF7F, 0xFFFF, 0x0BFF, 0x0040, 0x0096, 0x000C, 0xFFF4,
    0x0000, 0x0009, 0x0010, 0x000A, 0x0011, 0x000B, 0x0012, 0x000C, 0x0013, 0x000D, 0x0014, 0x000E,
    0xFFF9, 0x0013, 0x0019, 0x0012, 0x0018, 0x0011, 0x0017, 0x0010, 0xFFF9, 0x0019, 0x001F, 0x0018,
    0x001E, 0x0017, 0x0000, 0x0010, 0x0004, 0x0023, 0x0024, 0x001D, 0x0001, 0x0004, 0x001F, 0x001E,
    0x0025, 0x0000, 0xFFFA, 0x0029, 0x0023, 0x002A, 0x0024, 0x002B, 0x0001, 0x000A, 0x0000, 0x002C,
    0x0025, 0x0026, 0x001F, 0x0020, 0x0019, 0x001A, 0x0013, 0x0014, 0xFFF8, 0x002F, 0x0029, 0x0030,
    0x002A, 0x0031, 0x002B, 0x0032, 0x0001, 0xFFF5, 0x0035, 0x002F, 0x0036, 0x0030, 0x0037, 0x0031,
    0x0038, 0x0032, 0x0039, 0x0001, 0x0008, 0xFFF2, 0x0002, 0x0033, 0x0034, 0x002D, 0x002E, 0x0027,
    0x0028, 0x0021, 0x0022, 0x001B, 0x001C, 0x0015, 0x0016, 0x000F, 0x002A, 0x0002, 0x0003, 0x0034,
    0x0035, 0x002E, 0x002F, 0x0028, 0x0029, 0x0022, 0x0023, 0x001C, 0x001D, 0x0016, 0x0001, 0x000F,
    0x0008, 0x000E, 0x0007, 0x000D, 0x0006, 0x000C, 0x0005, 0x000B, 0x0004, 0x000A, 0x0003, 0x0009,
    0x0002, 0x0000, 0x0033, 0x002C, 0x002D, 0x0026, 0x0027, 0x0020, 0x0021, 0x001A, 0x001B, 0x0014,
    0x0015, 0x000E, 0x000F, 0xFFF5, 0x0003, 0x0035, 0x0004, 0x0036, 0x0005, 0x0037, 0x0006, 0x0038,
    0x0007, 0x0039, 0x0008, 0x0000, 0x00FF,
};
static DebugChunkVertices58 debug_chunk_b_vertices = {
    0x015D0029, 0x003A0000,
    {
        {{0.0f, -5.0f, 0.0f}, {-8.297286e-09f, -1.0f, -6.914405e-10f}},
        {{0.0f, 5.0f, 0.0f}, {0.0f, 1.0f, -6.9144046e-10f}},
        {{1.9134172f, -4.6193976f, 0.0f}, {0.42258298f, -0.9063242f, 1.6794909e-08f}},
        {{3.535534f, -3.535534f, 0.0f}, {0.7296192f, -0.6838536f, 3.5057905e-08f}},
        {{4.6193976f, -1.9134171f, 0.0f}, {0.9303025f, -0.3667931f, 1.2089442e-08f}},
        {{5.0f, 1.6391772e-07f, 0.0f}, {1.0f, 0.0f, 2.4487974e-08f}},
        {{4.6193976f, 1.9134173f, 0.0f}, {0.9303025f, 0.36679316f, 3.626833e-08f}},
        {{3.5355337f, 3.5355341f, 0.0f}, {0.72961915f, 0.68385375f, 4.090089e-08f}},
        {{1.9134169f, 4.6193976f, 0.0f}, {0.42258295f, 0.90632427f, 1.8194486e-08f}},
        {{1.3529903f, -4.6193976f, -1.3529903f}, {0.2988113f, -0.90632427f, -0.29881132f}},
        {{2.5f, -3.535534f, -2.5f}, {0.51591873f, -0.68385357f, -0.5159188f}},
        {{3.2664073f, -1.9134171f, -3.2664073f}, {0.6578232f, -0.3667931f, -0.65782326f}},
        {{3.535534f, 1.6391772e-07f, -3.535534f}, {0.70710677f, 0.0f, -0.70710677f}},
        {{3.2664073f, 1.9134173f, -3.2664073f}, {0.65782315f, 0.36679316f, -0.6578232f}},
        {{2.4999998f, 3.5355341f, -2.4999998f}, {0.5159186f, 0.6838537f, -0.5159187f}},
        {{1.35299f, 4.6193976f, -1.35299f}, {0.29881126f, 0.90632427f, -0.2988113f}},
        {{0.0f, -4.6193976f, -1.9134171f}, {-1.1196606e-08f, -0.90632427f, -0.42258298f}},
        {{0.0f, -3.535534f, -3.535534f}, {-2.3371937e-08f, -0.68385357f, -0.7296193f}},
        {{0.0f, -1.9134171f, -4.619397f}, {-2.4178881e-08f, -0.3667931f, -0.93030256f}},
        {{0.0f, 1.6391772e-07f, -5.0f}, {0.0f, 0.0f, -1.0f}},
        {{0.0f, 1.9134173f, -4.619397f}, {-3.6268325e-08f, 0.36679325f, -0.93030256f}},
        {{0.0f, 3.5355341f, -3.5355334f}, {-6.427282e-08f, 0.6838536f, -0.72961915f}},
        {{0.0f, 4.6193976f, -1.9134169f}, {-2.3792788e-08f, 0.90632427f, -0.42258298f}},
        {{-1.3529902f, -4.6193976f, -1.3529902f}, {-0.29881132f, -0.90632427f, -0.2988113f}},
        {{-2.5f, -3.535534f, -2.5f}, {-0.5159188f, -0.6838535f, -0.5159188f}},
        {{-3.266407f, -1.9134171f, -3.266407f}, {-0.6578232f, -0.3667931f, -0.65782326f}},
        {{-3.535534f, 1.6391772e-07f, -3.535534f}, {-0.70710677f, 0.0f, -0.70710677f}},
        {{-3.266407f, 1.9134173f, -3.266407f}, {-0.6578232f, 0.36679327f, -0.65782315f}},
        {{-2.4999995f, 3.5355341f, -2.4999995f}, {-0.51591873f, 0.6838536f, -0.5159187f}},
        {{-1.35299f, 4.6193976f, -1.35299f}, {-0.2988113f, 0.90632427f, -0.2988113f}},
        {{-1.913417f, -4.6193976f, 0.0f}, {-0.42258298f, -0.90632427f, 0.0f}},
        {{-3.535534f, -3.535534f, 0.0f}, {-0.7296193f, -0.6838535f, 0.0f}},
        {{-4.619397f, -1.9134171f, 0.0f}, {-0.93030256f, -0.36679313f, 0.0f}},
        {{-5.0f, 1.6391772e-07f, 0.0f}, {-1.0f, 0.0f, 0.0f}},
        {{-4.619397f, 1.9134173f, 0.0f}, {-0.93030244f, 0.36679327f, -6.0447207e-09f}},
        {{-3.5355332f, 3.5355341f, 0.0f}, {-0.7296192f, 0.6838536f, -5.8429834e-09f}},
        {{-1.9134169f, 4.6193976f, 0.0f}, {-0.42258295f, 0.90632427f, -4.1987276e-09f}},
        {{-1.3529902f, -4.6193976f, 1.3529902f}, {-0.2988113f, -0.90632427f, 0.29881132f}},
        {{-2.5f, -3.535534f, 2.5f}, {-0.5159188f, -0.6838535f, 0.5159188f}},
        {{-3.266407f, -1.9134171f, 3.266407f}, {-0.65782326f, -0.3667931f, 0.6578232f}},
        {{-3.535534f, 1.6391772e-07f, 3.535534f}, {-0.70710677f, 0.0f, 0.70710677f}},
        {{-3.266407f, 1.9134173f, 3.266407f}, {-0.65782315f, 0.36679327f, 0.6578232f}},
        {{-2.4999995f, 3.5355341f, 2.4999995f}, {-0.51591873f, 0.6838536f, 0.5159187f}},
        {{-1.35299f, 4.6193976f, 1.35299f}, {-0.2988113f, 0.90632427f, 0.29881126f}},
        {{0.0f, -4.6193976f, 1.913417f}, {0.0f, -0.90632427f, 0.42258298f}},
        {{0.0f, -3.535534f, 3.535534f}, {0.0f, -0.6838535f, 0.7296193f}},
        {{0.0f, -1.9134171f, 4.619397f}, {0.0f, -0.36679313f, 0.93030256f}},
        {{0.0f, 1.6391772e-07f, 5.0f}, {0.0f, 0.0f, 1.0f}},
        {{0.0f, 1.9134173f, 4.619397f}, {-6.0447207e-09f, 0.36679327f, 0.93030244f}},
        {{0.0f, 3.5355341f, 3.5355332f}, {-5.8429834e-09f, 0.6838536f, 0.7296192f}},
        {{0.0f, 4.6193976f, 1.9134169f}, {-4.1987276e-09f, 0.90632427f, 0.42258295f}},
        {{1.3529902f, -4.6193976f, 1.3529902f}, {0.29881132f, -0.90632427f, 0.29881132f}},
        {{2.5f, -3.535534f, 2.5f}, {0.5159188f, -0.68385357f, 0.5159188f}},
        {{3.266407f, -1.9134171f, 3.266407f}, {0.6578232f, -0.3667931f, 0.65782326f}},
        {{3.535534f, 1.6391772e-07f, 3.535534f}, {0.70710677f, 0.0f, 0.7071069f}},
        {{3.266407f, 1.9134173f, 3.266407f}, {0.6578232f, 0.3667932f, 0.6578232f}},
        {{2.4999995f, 3.5355341f, 2.4999995f}, {0.5159187f, 0.6838537f, 0.51591873f}},
        {{1.35299f, 4.6193976f, 1.35299f}, {0.29881126f, 0.90632427f, 0.2988113f}},
    },
    0x000000FF,
};
static NJS_CNK_MODEL debug_chunk_b_model = {&debug_chunk_b_vertices, debug_chunk_b_strips, {0.0f, 0.0f, 0.0f}, 7.071068f};
NJS_OBJECT debug_chunk_b_object = {
    NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &debug_chunk_b_model,
    {0.0f, 0.0f, 0.0f}, {0, 0, 0}, {1.0f, 1.0f, 1.0f}, NULL, NULL,
};
NJS_OBJECT *debug_chunk_object = &debug_chunk_b_object;
NJS_OBJECT *debug_cylinder_object = &debug_chunk_a_object;

struct Quad_8007D828 { f32 x0; f32 y0; f32 x1; f32 y1; f32 u0; f32 v0; f32 u1; f32 v1; };
// screen.bin / the PSO_SCREEN card file: a 256x192 capture and who was in the room.
struct ScreenSnapshot {
    u32 checksum;
    u16 width;
    u16 height;
    u8 pixels[0x18000];
    u8 bits_per_pixel;
    u8 format;
    u16 player_count;
    u32 class_flags[12];
    u32 levels[12];
    char names[12][0x18];
};
LAYOUT_ASSERT(ScreenSnapshot_size, sizeof(ScreenSnapshot) == 0x1818C);
// The "GetFrameBuffer" temp buffer: the snapshot, then its card file image at the next 32-byte boundary.
struct SnapshotFrameBuffer {
    ScreenSnapshot snapshot;
    u8 pad_1818C[0x14];
    u8 save_image[0x1E000];
};
extern "C" {
extern s32 lbl_805D49B4;
s8 func_801A5E54__Fv(void);
}
f32 sample_acceleration_curve(AccelerationCurve *c, f32 t);
void init_acceleration_curve(AccelerationCurve *c, f32 a, f32 d, f32 length, f32 speed);


u8 boss2_tunnel_state_flag;
u16 TObjBoss2Tunnel__snapshot_state;
ScreenSnapshot *boss2_tunnel_snapshot_buffer;
void *TObjBoss2Tunnel__snapshot_buffer;
s32 TObjBoss2Tunnel__snapshot_saved_flag;

// The snapshot's memory card file: name, comment and icon; screen.bin is the same capture on disc.
const char snapshot_card_filename[32] = "PSO_SCREEN";
const char snapshot_card_title[36] = "SNAPSHOT_FILE"; // inferred: copied into the card header's title
const u8 snapshot_card_icon[16] = {0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 0x57, 0x54, 0x54, 0x54}; // inferred: copied into the card header's icon
const char screen_binary_filename_string[] = "screen.bin";
const char *screen_binary_filename = screen_binary_filename_string;
// Centre of the capture frame, moved with the C stick.
NJS_POINT2 snapshot_frame_center = {320.0f, 240.0f};

// Fills in the 6xB2 header: subcommand 0xB2, size 3 (in words).
void init_6xB2_play_sound(G_PlaySound_6xB2 *cmd) {
    cmd->header.subcommand = 0xB2;
    cmd->header.size = 3;
}

void bswap_6xB2_play_sound(G_PlaySound_6xB2 *cmd) {
    cmd->header.bswap();
    bswap_16(&cmd->client_id);
    bswap_32(&cmd->sound_id);
}

void send_6xB2_play_sound(G_PlaySound_6xB2 *cmd) {
    bswap_6xB2_play_sound(cmd);
    send_subcommand((u8 *)cmd);
}


f32 normalize_vector_safe(Vec *vector) {
    f32 length;
    f32 zero;

    length = 0.0f;
    if (0.0f != vec_squared_length(vector)) {
        length = normalize_vector(vector);
        if (is_float_nonfinite(length) != 0) {
            vector->x = length = 0.0f;
            vector->y = length;
            vector->z = length;
        }
    } else {
        zero = 0.0f;
        vector->x = zero;
        vector->y = zero;
        vector->z = zero;
    }
    return length;
}

#pragma push
#pragma fp_contract on
f32 normalize_vector_xz(Vec *vector) {
    f32 x;
    f32 z;
    f32 length_sq;
    f32 inv_length;

    z = vector->z;
    x = vector->x;
    length_sq = (x * x) + (z * z);
    if (0.0f != length_sq) {
        inv_length = 1.0f / newton_sqrtf(length_sq);
        if (is_float_nonfinite(inv_length) != 0) {
            vector->x = 0.0f;
            vector->z = 0.0f;
            return 0.0f;
        }
        vector->x = x * inv_length;
        vector->z = z * inv_length;
        return length_sq * inv_length;
    }
    vector->x = 0.0f;
    vector->z = 0.0f;
    return 0.0f;
}

#pragma pop

void store_inverse_current_matrix(NJS_CAMERA *camera, CameraMatrix *view) {
    push_matrix();
    TObjPlayer::invert_matrix_in_place(0);
    get_current_matrix(&view->m);
    pop_matrix();
}

#pragma push
#pragma fp_contract on
void transform_vec_by_camera(NJS_CAMERA *camera, const Vec *in, Vec *out) {
    push_matrix();
    premultiply_matrix(NULL, TCameraCtrl::get_view_matrix());
    matrix_mult_vec(NULL, in, out);
    pop_matrix();
}

s32 is_vec_xz_cross_negative(const Vec *a, const Vec *b) {
    if (a->z * b->x - a->x * b->z >= 0.0f) {
        return 0;
    }
    return 1;
}

void rotate_xz_pair_by_angle(f32 *x, f32 *z, s32 angle) {
    f32 x0;
    f32 sin_a;
    f32 cos_a;
    f32 z0;
    cos_a = cos_table_lookup(angle);
    sin_a = sin_table_lookup(angle);
    x0 = *x;
    z0 = *z;
    *z = (cos_a * z0) - (sin_a * x0);
    *x = (sin_a * z0) + (cos_a * x0);
}

void rotate_vec_xz(void *in, void *out, s32 angle) {
    f32 x0;
    f32 sin_a;
    f32 cos_a;
    f32 z0;
    cos_a = cos_table_lookup(angle);
    sin_a = sin_table_lookup(angle);
    x0 = ((Vec *)in)->x;
    z0 = ((Vec *)in)->z;
    ((Vec *)out)->z = (cos_a * z0) - (sin_a * x0);
    ((Vec *)out)->x = (sin_a * z0) + (cos_a * x0);
}

#pragma pop
f32 TObjBoss2Tunnel::calc_scaled_value(s32 angle, f32 length) {
    return (0.5f * length) / sin_table_lookup(angle / 2);
}

s32 count_tree_nodes(NJS_OBJECT *node) {
    s32 count;
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;
    count = 1;
    child = node->child;
    if (child != NULL) {
        count = count_tree_nodes(child) + 1;
    }
    sibling = node->sibling;
    if (sibling != NULL) {
        count += count_tree_nodes(sibling);
    }
    return count;
}

s32 count_visible_nodes(NJS_OBJECT *node) {
    s32 flags;
    s32 count;

    count = 0;
    do {
        flags = node->evalflags;
        if (!(flags & 8)) {
            count += 1;
        }
        if (!(flags & 0x10)) {
            count += count_visible_nodes(node->child);
        }
        node = node->sibling;
    } while (node != NULL);
    return count;
}

s32 TObjBoss2Tunnel::turn_toward_angle_limited(s32 angle, s32 cur, s32 target, s32 step, s32 limit) {
    target = angle_diff_s16(angle, target);
    if (target > limit) {
        target = limit;
    } else if (target < -limit) {
        target = -limit;
    }
    if (cur * target >= 0) {
        cur = approach_angle_limited(cur, target, step);
    } else if (cur * angle_diff_s16(cur, target) >= 0) {
        if (cur >= 0) {
            cur = cur - step;
        } else {
            cur = cur + step;
        }
    } else {
        cur = approach_angle_limited(cur, target, step);
    }
    return (s16)(cur);
}

void rotate_y_and_translate(Vec *v, Vec *origin, s32 angle) {
    rotate_xz_pair_by_angle(&v->x, &v->z, angle);
    vec3_add_to(v, origin);
}

s32 TObjBoss2Tunnel::adjust_to_ground(const Vec *from, Vec *out) {
    CsnHit *hit;

    VecCopy(out, from);
    out->y += 20.0f;
    hit = csnVecterUnder(out, 0x16EF);
    if (hit != NULL) {
        VecCopy(out, &hit->contact->point);
        return 1;
    }
    VecCopy(out, from);
    return 0;
}

s32 TObjBoss2Tunnel::spawn_effect(const Vec *from, Vec *out, Vec *normal) {
    CsnHit *hit;

    VecCopy(out, from);
    out->y += 20.0f;
    hit = csnVecterUnder(out, 0x16EF);
    if (hit != NULL) {
        VecCopy(out, &hit->contact->point);
        VecCopy(normal, &hit->contact->normal);
        return 1;
    }
    VecCopy(out, from);
    return 0;
}

// The timer is the top byte of *packed; returns 1 once it runs out.
s32 TObjBoss2Tunnel::decrement_packed_timer(u32 *packed, s32 step) {
    u32 value;

    value = *packed;
    if ((s32)((value >> 24) - step) < 0) {
        *packed = value & 0xFFFFFF;
        return 1;
    }
    *packed = ((((value >> 24) - step) << 24) & 0xFF000000) | (value & 0xFFFFFF);
    return 0;
}

AccelerationCurve::AccelerationCurve() {
    reset_coords();
}

AccelerationCurve::~AccelerationCurve() {}

void AccelerationCurve::reset_coords() {
    decel = 0.0f;
    accel = 0.0f;
    peak = 0.0f;
    end = 0.0f;
    decelStart = 0.0f;
    accelEnd = 0.0f;
    dist = 0.0f;
    decelPos = 0.0f;
    accelDist = 0.0f;
}


void init_acceleration_curve(AccelerationCurve *c, f32 a, f32 d, f32 length, f32 speed) {
    f32 sq;
    f32 up;
    f32 down;
    f32 p;
    c->accel = a;
    if (c->accel <= 0.0f) {
        c->accel = 0.1f;
    }
    c->decel = d;
    if (c->decel >= 0.0f) {
        c->decel = (-0.1f);
    }
    sq = speed * speed;
    c->dist = length;
    c->peak = speed;
    up = (0.5f * sq) / c->accel;
    down = (0.5f * -sq) / c->decel;
    if (up + down >= c->dist) {
        f32 k2 = 2.0f * c->accel;
        c->peak = newton_sqrtf((c->dist * (k2 *= c->decel)) / (c->decel - c->accel));
        sq = c->peak * c->peak;
        c->accelEnd = c->decelStart = c->peak / c->accel;
        c->accelDist = c->decelPos = (0.5f * sq) / c->accel;
        c->end = c->decelStart + (-c->peak / c->decel);
        return;
    }
    c->accelDist = up;
    c->accelEnd = c->peak / c->accel;
    c->decelPos = c->dist - down;
    c->decelStart = c->accelEnd + (c->decelPos - up) / c->peak;
    c->end = c->decelStart + (-c->peak / c->decel);
}

int AccelerationCurve::check_param_threshold(f32 t) {
    return t >= this->end;
}

#pragma push
#pragma fp_contract on
f32 sample_acceleration_curve(AccelerationCurve *c, f32 t) {
    if (t < 0.0f) {
        return 0.0f;
    }
    if (t < c->accelEnd) {
        {
        f32 k = 0.5f * c->accel;
        k *= t;
        return t * k;
        }
    }
    if (t < c->decelStart) {
        t -= c->accelEnd;
        return t * c->peak + c->accelDist;
    }
    if (t < c->end) {
        t = c->end - t;
        {
        f32 k = 0.5f * c->decel;
        k *= t;
        return t * k + c->dist;
        }
    }
    return c->dist;
}

#pragma pop
PiecewiseCurve::PiecewiseCurve() {
    reset_floats();
}

PiecewiseCurve::~PiecewiseCurve() {}

void PiecewiseCurve::reset_floats() {
    accel = decel = 0.0f;
    v0 = peak = 0.0f;
    accelEnd = decelStart = end = 0.0f;
    t = 0.0f;
    accelDist = decelPos = dist = 0.0f;
}

void PiecewiseCurve::init(f32 accel, f32 decel, f32 dist, f32 v0, f32 peak) {
    PiecewiseCurve *c = this;
    f32 sq;
    f32 up;
    f32 down;
    c->t = 0.0f;
    c->accel = accel;
    if (c->accel <= 0.0f) {
        c->accel = 0.1f;
    }
    c->decel = decel;
    if (c->decel >= 0.0f) {
        c->decel = -0.1f;
    }
    c->dist = dist;
    sq = peak * peak;
    c->peak = peak;
    c->v0 = v0;
    if (c->v0 > c->peak) {
        c->accel = c->decel;
    }
    up = (0.5f * (sq - c->v0 * c->v0)) / c->accel;
    down = (-0.5f * sq) / c->decel;
    if (up + down >= c->dist) {
        if (c->v0 > c->peak) {
            c->decel = (-0.5f * (c->v0 * c->v0)) / c->dist;
            c->accelEnd = c->decelStart = c->accelDist = c->decelPos = 0.0f;
            c->end = -c->v0 / c->decel;
        } else {
            c->peak = newton_sqrtf((c->dist * (2.0f * c->accel * c->decel)) / (c->decel - c->accel));
            sq = c->peak * c->peak;
            c->accelEnd = c->decelStart = c->peak / c->accel;
            c->accelDist = c->decelPos = (0.5f * sq) / c->accel;
            c->end = c->decelStart + (-c->peak / c->decel);
        }
    } else {
        c->accelDist = up;
        c->accelEnd = (c->peak - c->v0) / c->accel;
        c->decelPos = c->dist - down;
        c->decelStart = c->accelEnd + (c->decelPos - up) / c->peak;
        c->end = c->decelStart + (-c->peak / c->decel);
    }
}

#pragma push
#pragma fp_contract on
f32 PiecewiseCurve::speed_at(f32 time) {
    PiecewiseCurve *c = this;
    f32 t;
    f32 r = 0.0f;
    if (time < r) {
        r = r;
    } else {
        if (time < c->accelEnd) {
            r = c->accel * time + c->v0;
        } else {
            t = c->decelStart;
            if (time < t) {
                r = c->peak;
            } else if (time < c->end) {
                t = time - t;
                r = c->decel * t + c->peak;
            }
        }
    }
    return r;
}

#pragma pop
f32 PiecewiseCurve::current_speed() {
    return speed_at(t);
}

#pragma push
#pragma fp_contract on
s32 PiecewiseCurve::sample(f32 *out, f32 t) {
    PiecewiseCurve *c = this;
    s32 done = 0;
    if (t < 0.0f) {
        *out = 0.0f;
    } else if (t < c->accelEnd) {
        *out = t * (0.5f * c->accel * t + c->v0);
    } else if (t < c->decelStart) {
        t -= c->accelEnd;
        *out = t * c->peak + c->accelDist;
    } else if (t < c->end) {
        t = c->end - t;
        *out = t * (0.5f * c->decel * t) + c->dist;
    } else {
        done = 1;
        *out = c->dist;
    }
    return done;
}
#pragma pop
s32 PiecewiseCurve::advance(f32 *out) {
    PiecewiseCurve *c = this;
    s32 done = c->sample(out, c->t);
    c->t += 1.0f;
    return done;
}

void TObjBoss2Tunnel::reset_state() {
    snapshot_frame_center.x = 320.0f;
    boss2_tunnel_state_flag = 0;
    snapshot_frame_center.y = 240.0f;
    TObjBoss2Tunnel__snapshot_buffer = 0;
    TObjBoss2Tunnel__snapshot_state = 0;
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    TQuestListVM::reset();
}

void TObjBoss2Tunnel__sub_8007DD24(void) {  }

/* Moves the capture frame with the C stick and keeps it on screen. */
void move_snapshot_frame(void) {
    s16 stick_x = controller_physical_port_bank.controllers[3].cstick_x;
    s16 stick_y = controller_physical_port_bank.controllers[3].cstick_y;
    f32 magnitude = controller_physical_port_bank.controllers[3].cstick_magnitude;
    if (magnitude > 0.2f) {
        f32 speed = 0.3f * magnitude;
        s16 dx = stick_x * speed;
        s16 dy = stick_y * speed;
        dx = dx + dx % 4;
        dy = dy + dy % 4;
        snapshot_frame_center.x += dx;
        snapshot_frame_center.y += dy;
    }
    if (snapshot_frame_center.x - 128.0f <= 0.0f) {
        snapshot_frame_center.x = 128.0f;
    }
    if (128.0f + snapshot_frame_center.x >= 640.0f) {
        snapshot_frame_center.x = 512.0f;
    }
    if (snapshot_frame_center.y - 96.0f <= 0.0f) {
        snapshot_frame_center.y = 96.0f;
    }
    if (96.0f + snapshot_frame_center.y >= 480.0f) {
        snapshot_frame_center.y = 384.0f;
    }
}

void draw_snapshot_capture_overlay(void) {
    Quad_8007D828 q;
    ProjectedVertex v[4];
    s32 i;
    set_default_alpha_blend();
    for (i = 0; i < 4; i++) {
        v[i].z = 0.25f;
        v[i].color = 0x8F000000;
    }
    set_depth_buffer_settings_1();
    v[0].x = 0.0f;
    v[0].y = 0.0f;
    v[1].x = 640.0f;
    v[1].y = 0.0f;
    v[2].x = 0.0f;
    v[2].y = snapshot_frame_center.y - 96.0f;
    v[3].x = 640.0f;
    v[3].y = snapshot_frame_center.y - 96.0f;
    TObjBoss2Tunnel::setup_projected_color_draw(1);
    TObjBoss2Tunnel::draw_projected_quads(v, 4);
    TObjBoss2Tunnel::reset_player_state();
    v[0].x = 0.0f;
    v[0].y = snapshot_frame_center.y - 96.0f;
    v[1].x = snapshot_frame_center.x - 128.0f;
    v[1].y = snapshot_frame_center.y - 96.0f;
    v[2].x = 0.0f;
    v[2].y = 480.0f;
    v[3].x = snapshot_frame_center.x - 128.0f;
    v[3].y = 480.0f;
    TObjBoss2Tunnel::setup_projected_color_draw(1);
    TObjBoss2Tunnel::draw_projected_quads(v, 4);
    TObjBoss2Tunnel::reset_player_state();
    v[0].x = 128.0f + snapshot_frame_center.x;
    v[0].y = snapshot_frame_center.y - 96.0f;
    v[1].x = 640.0f;
    v[1].y = snapshot_frame_center.y - 96.0f;
    v[2].x = 128.0f + snapshot_frame_center.x;
    v[2].y = 96.0f + snapshot_frame_center.y;
    v[3].x = 640.0f;
    v[3].y = 96.0f + snapshot_frame_center.y;
    TObjBoss2Tunnel::setup_projected_color_draw(1);
    TObjBoss2Tunnel::draw_projected_quads(v, 4);
    TObjBoss2Tunnel::reset_player_state();
    v[0].x = snapshot_frame_center.x - 128.0f;
    v[0].y = 96.0f + snapshot_frame_center.y;
    v[1].x = 640.0f;
    v[1].y = 96.0f + snapshot_frame_center.y;
    v[2].x = snapshot_frame_center.x - 128.0f;
    v[2].y = 480.0f;
    v[3].x = 640.0f;
    v[3].y = 480.0f;
    TObjBoss2Tunnel::setup_projected_color_draw(1);
    TObjBoss2Tunnel::draw_projected_quads(v, 4);
    TObjBoss2Tunnel::reset_player_state();
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(1, -1);
    begin_screen_draw(1);
    q.x0 = snapshot_frame_center.x - 27.0f;
    q.y0 = snapshot_frame_center.y - 27.0f;
    q.x1 = snapshot_frame_center.x;
    q.y1 = snapshot_frame_center.y;
    q.u0 = 0.31764707f;
    q.v0 = 0.494117647f;
    q.u1 = 0.423529416f;
    q.v1 = 0.600000024f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    q.x0 = snapshot_frame_center.x;
    q.y0 = snapshot_frame_center.y - 27.0f;
    q.x1 = 27.0f + snapshot_frame_center.x;
    q.y1 = snapshot_frame_center.y;
    q.u0 = 0.31764707f;
    q.v0 = 0.494117647f;
    q.u1 = 0.423529416f;
    q.v1 = 0.600000024f;
    q.u0 = 0.423529416f;
    q.u1 = 0.31764707f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    q.x0 = snapshot_frame_center.x - 27.0f;
    q.y0 = snapshot_frame_center.y;
    q.x1 = snapshot_frame_center.x;
    q.y1 = 27.0f + snapshot_frame_center.y;
    q.u0 = 0.31764707f;
    q.v0 = 0.494117647f;
    q.u1 = 0.423529416f;
    q.v1 = 0.600000024f;
    q.v0 = 0.600000024f;
    q.v1 = 0.494117647f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    q.x0 = snapshot_frame_center.x;
    q.y0 = snapshot_frame_center.y;
    q.x1 = 27.0f + snapshot_frame_center.x;
    q.y1 = 27.0f + snapshot_frame_center.y;
    q.u0 = 0.31764707f;
    q.v0 = 0.494117647f;
    q.u1 = 0.423529416f;
    q.v1 = 0.600000024f;
    q.v0 = 0.600000024f;
    q.v1 = 0.494117647f;
    q.u0 = 0.423529416f;
    q.u1 = 0.31764707f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    TWindowSubStatusDisp::get_player();
    restore_saved_depth_alpha_state();
}

/* Takes a snapshot of the screen with the C stick frame and saves it to the memory card. */
s32 take_snapshot(void) {
    static char buffer_owner[] = "GetFrameBuffer";
    SnapshotFrameBuffer *frame;
    ScreenSnapshot *snap;
    u32 *sum;
    PadSlot *pad;
    s32 filter;
    u8 *p;
    s32 mode;
    u16 *countp;
    u32 *flags;
    u32 *levels;
    char *name;
    u16 count;
    TObjPlayer *me;
    s32 i;
    TObjPlayer *player;
    TDLGraph *graph;
    s32 err;
    s32 err2;
    CardSaveDescriptor card;
    G_PlaySound_6xB2 cmd;
    f32 pos[2];
    f32 size[2];
    f32 limit;
    f32 t;

    if (get_main_phase() == 0xF &&
        (is_boss_area() != 0 || is_quest_active() != 0 || TQuestVmDownLoadServer__sub_8007EB14() != 0)) {
        return 0;
    }
    if (TQuestListVM::get_quest_bin() != NULL) {
        return 0;
    }
    if (TCameraCtrl::is_view_override_active() != 0) {
        return 0;
    }
    if (is_split_screen() != 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::get_instance() != 0) {
        return 0;
    }
    pad = get_pad_slot(0x12);
    if (test_previous_buttons_packed(&controller_physical_port_bank.controllers[3], 0x20000) != 0) {
        if (boss2_tunnel_state_flag == 0) {
            move_snapshot_frame();
            draw_snapshot_capture_overlay();
        }
    } else if (boss2_tunnel_state_flag == 0) {
        return 0;
    }
    if (boss2_tunnel_state_flag == 0) {
        if (pad->held & 4) {
            if (memcard_check_snapshot(0, &err) == 0) {
                TObjBoss2Tunnel::show_message_and_wait(err);
                return 0;
            }
            if (TObjBoss2Tunnel::run_confirm_message_loop() != 0) {
                boss2_tunnel_state_flag |= 1;
            } else {
                boss2_tunnel_state_flag = 0;
            }
        } else if (pad->held & 0x400) {
            if (memcard_check_snapshot(0, &err2) == 0) {
                TObjBoss2Tunnel::show_message_and_wait(err2);
                return 0;
            }
            if (TObjBoss2Tunnel::run_confirm_message_loop() != 0) {
                boss2_tunnel_state_flag |= 2;
            } else {
                boss2_tunnel_state_flag = 0;
            }
        } else {
            boss2_tunnel_state_flag = 0;
        }
        return 0;
    }
    mode = (boss2_tunnel_state_flag & 1) ^ 1;
    boss2_tunnel_state_flag = 0;
    filter = get_display_copy_filter();
    set_display_copy_filter(0);
    TObjPlayer::copy_screen_to_texture(mode, &snapshot_frame_center);
    set_display_copy_filter(filter);
    render_tick();
    if (TLobby::tmp_buf_is_free() != 0) {
        frame = (SnapshotFrameBuffer *)TLobby::tmp_buf_use_req(buffer_owner);
        p = (u8 *)frame;
        sum = (u32 *)p;
        snap = (ScreenSnapshot *)p;
        *sum = 0;
        frame->snapshot.width = 0x100;
        frame->snapshot.height = 0xC0;
        p += 8;
        move_data((void *)(p), (const void *)((void *)get_capture_texture_pixels()), sizeof(snap->pixels));
        p += sizeof(snap->pixels);
        *p++ = 0x18;
        *p++ = 2;
        countp = (u16 *)p;
        p += 2;
        flags = (u32 *)p;
        levels = (u32 *)(p + 0x30);
        name = (char *)(p + 0x60);
        memset(name, 0, sizeof(snap->names));
        count = TLobby::get_game_mode();
        me = (TObjPlayer *)find_entity_by_id(local_client_id);
        if (me != NULL) {
            *flags++ = me->class_flags;
            if (me->get_stats() != NULL) {
                *levels++ = me->get_actor_level_index();
            }
            strncpy(name, me->name, sizeof(snap->names[0]));
            name += sizeof(snap->names[0]);
        }
        for (i = 0; i < count; i++) {
            if (i != local_client_id) {
                player = (TObjPlayer *)find_entity_by_id(i);
                if (player != NULL) {
                    *flags++ = player->class_flags;
                    if (player->get_stats() != NULL) {
                        *levels++ = player->get_actor_level_index();
                    }
                    strncpy(name, player->name, sizeof(snap->names[0]));
                    name += sizeof(snap->names[0]);
                }
            }
        }
        *countp = count;
        memset(&card, 0, sizeof(card));
        strcpy(card.filename, episode_i_and_ii_card_filename.game_name);
        strcpy(card.title, snapshot_card_title);
        memcpy(card.key, snapshot_card_icon, 0x10);
        set_card_banner_and_icon(&card, 4);
        card.field_4c = 1;
        card.field_4e = 1;
        card.field_50 = 0;
        card.omit_title_space = 0;
        card.data = (u8 *)snap;
        card.size = sizeof(ScreenSnapshot);
        *sum = calc_crc32_bitwise((u8 *)snap, sizeof(ScreenSnapshot));
        TAdPlayerLoadGC::build_save_file_image(frame->save_image, &card);
        release_card_banner_and_icon(&card);
        init_6xB2_play_sound(&cmd);
        cmd.floor = get_current_floor_area();
        cmd.unused = 0;
        cmd.client_id = local_client_id;
        cmd.sound_id = 0x52B20;
        send_6xB2_play_sound(&cmd);
        if (memcard_check_snapshot(0, NULL) != 0) {
            if (TAdSinglePlyChrSelectGC::load_player(1, (saddr)snapshot_card_filename, (saddr)frame->save_image, 0xF) == 0) {
                t = 0.0f;
                graph = (TDLGraph *)TDLGraph::create();
                if (get_main_phase() == 0xF) {
                    TLobby::reset_state_flags();
                }
                limit = 60.0f;
                do {
                    t += 1.0f;
                    if (t > limit) {
                        t = limit;
                    }
                    func_803DCDFC__Fv();
                    controller_stuff();
                    main_task.run_tl_camera_tasks();
                    pos[0] = 192.0f;
                    pos[1] = 144.0f;
                    size[0] = 256.0f;
                    size[1] = 192.0f;
                    TParticleCtrl::begin_effect_render();
                    TObjPlayer::draw_textured_screen_quad(-1, pos, size, 1);
                    if (graph != NULL) {
                        TDLGraph::update_graph((s32)t, (s32)limit);
                        graph->run_task();
                        graph->render();
                    }
                    TLobby::update_pulse_colors(1);
                    TLobby__sub_80338534();
                    TParticleCtrl::end_effect_render();
                    render_tick();
                } while (poll_memcard_result(1) == 0xFFFFFFFF);
                if (TAdPlayerLoadGC::get_load_result(1) == 0xFFFFFF81) {
                    TObjBoss2Tunnel::show_message_and_wait(-2);
                }
                if (graph != NULL) {
                    delete graph;
                }
                if (get_main_phase() == 0xF) {
                    TLobby::process_deferred_player_setup();
                }
                TParticleCtrl::end_effect_render();
            } else {
                TObjBoss2Tunnel::show_message_and_wait(-2);
            }
        }
        TLobby::tmp_buf_release(buffer_owner);
        return 1;
    }
    return 0;
}

// Checks memory card slot B for the PSO_SCREEN file; *error gets the card error code (1 when
// the file is missing). for_save == 1 also needs a free file entry and 15 free blocks.
s32 memcard_check_snapshot(s32 for_save, s32 *error) {
    s32 card_file;

    if (TAdPlayerLoadGC::get_instance() != 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::probe_card_slot(1) == 0) {
        if (error != NULL) {
            *error = -4;
        }
        return 0;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(1) == 0) {
        if (error != NULL) {
            if ((u32)(TAdPlayerLoadGC::get_load_result(1) + 0x10000) == 0xff83U) {
                if (error != NULL) {
                    *error = -6;
                }
            } else if ((u32)(TAdPlayerLoadGC::get_load_result(1) + 0x10000) == 0xff21U) {
                if (error != NULL) {
                    *error = -8;
                }
            } else if (error != NULL) {
                *error = -2;
            }
        }
        return 0;
    }
    if (TAdPlayerLoadGC::check_memcard_status(1) != 0) {
        if (error != NULL) {
            *error = -3;
        }
        return 0;
    }
    if (poll_memcard_result(1) != 0) {
        if (error != NULL) {
            *error = -2;
        }
        return 0;
    }
    card_file = TAdPlayerLoadGC::find_card_file(1, snapshot_card_filename);
    if (card_file == 0) {
        if (error != NULL) {
            *error = 1;
        }
        return 1;
    }
    if ((card_file + 0x10000) == 0xff41U) {
        if (error != NULL) {
            *error = -9;
        }
        return 0;
    }
    if (for_save != 1) {
        return 0;
    }
    if (get_memcard_free_files(1) < 1) {
        if (error != NULL) {
            *error = -7;
        }
        return 0;
    }
    if (TAdPlayerLoadGC::query_memcard_capacity(1, 0) < 0xF) {
        if (error != NULL) {
            *error = -1;
        }
        return 0;
    }
    if (error != NULL) {
        *error = 0;
    }
    return 1;
}

void load_data_buffers(void) {
    s32 size;
    u8 *file;
    ScreenSnapshot *buf;

    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    TObjBoss2Tunnel__snapshot_buffer = xmalloc(0x1E000);
    TObjBoss2Tunnel__snapshot_state = 0;
    init_capture_texture(0);
    buf = static_cast<ScreenSnapshot *>(xmalloc(sizeof(ScreenSnapshot)));
    boss2_tunnel_snapshot_buffer = buf;
    if (buf != NULL) {
        memset(buf, 0, 0x1818C);
    }
    size = get_resource_file_size(screen_binary_filename);
    if (size <= (s32)sizeof(ScreenSnapshot)) {
        file = load_disc_file(screen_binary_filename);
        if (file != 0) {
            if (boss2_tunnel_snapshot_buffer != NULL) {
                memmove(boss2_tunnel_snapshot_buffer, file, size);
            }
            safe_free(file);
        }
    }
}

void TObjBoss2Tunnel::free_buffers() {
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    if (boss2_tunnel_snapshot_buffer != NULL) {
        xfree(boss2_tunnel_snapshot_buffer);
        boss2_tunnel_snapshot_buffer = NULL;
    }
    release_shared_capture_texture();
    if (TObjBoss2Tunnel__snapshot_buffer != NULL) {
        xfree(TObjBoss2Tunnel__snapshot_buffer);
        TObjBoss2Tunnel__snapshot_buffer = NULL;
    }
}

s32 TObjBoss2Tunnel::save_snapshot() {
    s32 status;

    memcard_check_snapshot(1, &status);
    if (status == 1) {
        if ((s32) TObjBoss2Tunnel__snapshot_saved_flag != 0) {
            return -9;
        }
        save_screen_snapshot();
loop_4:
        if (TAdPlayerLoadGC::probe_card_slot(1) == 0) {
            TObjBoss2Tunnel__snapshot_saved_flag = 0;
            return -5;
        }
        if (TObjBoss2Tunnel::load_snapshot() != 0) {
            if (!TObjBoss2Tunnel::verify_snapshot_checksum()) {
                TObjBoss2Tunnel__snapshot_saved_flag = 1;
                return -9;
            }
            goto block_9;
        }
        goto loop_4;
    }
block_9:
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    return status;
}

s32 TObjBoss2Tunnel::save_snapshot_to_card() {
    CardSaveDescriptor c;
    u32 *checksum;
    if (memcard_check_snapshot(1, 0) == 0) {
        return 0;
    }
    if (TObjBoss2Tunnel__snapshot_buffer == NULL) {
        return 0;
    }
    memset(TObjBoss2Tunnel__snapshot_buffer, 0, 4);
    memset(&c, 0, 0x60);
    strcpy(c.filename, episode_i_and_ii_card_filename.game_name);
    strcpy(c.title, snapshot_card_title);
    memcpy(c.key, snapshot_card_icon, 0x10);
    set_card_banner_and_icon(&c, 4);
    c.field_4c = 1;
    checksum = &boss2_tunnel_snapshot_buffer->checksum;
    c.field_4e = 1;
    c.field_50 = 0;
    c.omit_title_space = 0;
    *checksum = 0;
    *checksum = calc_crc32_bitwise(reinterpret_cast<u8 *>(boss2_tunnel_snapshot_buffer), sizeof(ScreenSnapshot));
    c.data = (u8 *)boss2_tunnel_snapshot_buffer;
    c.size = sizeof(ScreenSnapshot);
    TAdPlayerLoadGC::build_save_file_image(TObjBoss2Tunnel__snapshot_buffer, &c);
    release_card_banner_and_icon(&c);
    if (TAdSinglePlyChrSelectGC::load_player(1, (saddr)snapshot_card_filename, (saddr)TObjBoss2Tunnel__snapshot_buffer, 0xF) != 0) {
        return 0;
    }
    lbl_805D49B4 = 1;
    TObjBoss2Tunnel__snapshot_state = 1;
    return 1;
}

s32 save_screen_snapshot(void) {
    if (memcard_check_snapshot(1, 0) == 0) {
        return 0;
    }
    if (TAdSinglePlyChrSelectGC::load_player_slot(1, snapshot_card_filename, TObjBoss2Tunnel__snapshot_buffer) != 0) {
        return 0;
    }
    TObjBoss2Tunnel__snapshot_state = 2;
    return 1;
}

s32 TObjBoss2Tunnel::load_snapshot() {
    CardSaveDescriptor file;
    void *buf;
    if (poll_memcard_result(1) == 0) {
        if (((s32) TObjBoss2Tunnel__snapshot_state != 0) && ((s32) TObjBoss2Tunnel__snapshot_state >= 0) && ((s32) TObjBoss2Tunnel__snapshot_state < 3)) {
            buf = (void *)get_capture_texture_pixels();
            if (verify_card_save_header(&file, TObjBoss2Tunnel__snapshot_buffer) == 0) {
                memcpy(buf, file.data + 8, 0x1818C);
                DCFlushRange(buf, 0x1818C);
            }
            lbl_805D49B4 = 0;
        }
        return 1;
    }
    return 0;
}

BOOL TObjBoss2Tunnel::verify_snapshot_checksum() {
    CardSaveDescriptor ld;
    ScreenSnapshot *snapshot;
    u32 saved;
    u32 sum;
    if ((u32)verify_card_save_header(&ld, TObjBoss2Tunnel__snapshot_buffer) == 0xFFFFFF20) {
        return FALSE;
    }
    snapshot = reinterpret_cast<ScreenSnapshot *>(ld.data);
    saved = snapshot->checksum;
    snapshot->checksum = 0;
    sum = calc_crc32_bitwise(ld.data, sizeof(ScreenSnapshot));
    snapshot->checksum = saved;
    return sum == saved ? TRUE : FALSE;
}

// Draws the captured snapshot at pos (default 192,144), 345.6 x 259.2.
void draw_screen_snapshot(uaddr pos) {
    f32 position[2];
    f32 size[2];
    if (pos == 0U) {
        position[0] = 192.0f;
        position[1] = 144.0f;
    } else {
        copy_vec2(position, (void *)pos);
    }
    size[0] = 345.6f;
    size[1] = 259.2f;
    TObjPlayer::draw_textured_screen_quad(-1, position, size, 1);
}

void TObjBoss2Tunnel::show_message_and_wait(s32 message) {
    static const f32 window_pos[2] = {46.0f, 131.0f};
    static const f32 window_size[2] = {548.0f, 220.0f};
    // Text position and width inside the window, set on first call (the retail build never reads them).
    static f32 text_pos[2] = {20.0f + window_pos[0], 10.0f + (window_pos[1] + window_size[1])};
    static f32 text_width = window_size[0] - 40.0f;
    TWindowMessage *win;
    s32 frames;
    win = (TWindowMessage *)TWindowMessage::create((saddr)window_pos, window_size, (u32)1, 4);
    if (win != NULL) {
        switch (message) {
        case -2:
        case -9:
            win->append_line(get_localized_text_entry(0x24, 3), 3);
            break;
        case -4:
            win->append_line(get_localized_text_entry(0x24, 0xD), 3);
            break;
        default:
            win->append_line(get_localized_text_entry(0x24, 0xC), 3);
            break;
        }
        win->set_depth(36900.0f);
        win->complete_reveal();
    }
    if (get_main_phase() == 0xF) {
        TLobby::reset_state_flags();
    }
    frames = 0;
    for (;;) {
        frames++;
        func_803DCDFC__Fv();
        controller_stuff();
        if (camera_ctrl_instance != NULL) {
            camera_ctrl_instance->setup_default_view(0);
        }
        main_task.render();
        if ((f32)frames >= 30.0f) {
            break;
        }
        TLobby::wait_ready_loop();
        if (static_cast<s8>(func_801A5E54()) != 0) {
            break;
        }
        render_tick();
    }
    if (get_main_phase() == 0xF) {
        TLobby::process_deferred_player_setup();
    }
    if (win != NULL) {
        delete win;
    }
}

void TObjBoss2Tunnel::poll_pso_screen_load() {
    TAdPlayerLoadGC::delete_memcard_file(1, (const char *)(((u8 *)&snapshot_card_filename)));
}

s32 TObjBoss2Tunnel::run_confirm_message_loop() {
    s32 result = 0;
    static const f32 window_pos[2] = {46.0f, 131.0f};
    static const f32 window_size[2] = {548.0f, 220.0f};
    static f32 text_pos[2] = {20.0f + window_pos[0], 10.0f + (window_pos[1] + window_size[1])};
    static f32 text_width = window_size[0] - 40.0f;
    ControllerInputContext *pad;
    TWindowMessage *win;
    TDLGraph *graph;
    s32 frames;
    win = (TWindowMessage *)TWindowMessage::create((saddr)window_pos, window_size, (u32)1, 4);
    if (win != NULL) {
        win->append_line(get_localized_text_entry(0x24, 0xB), 3);
        win->set_depth(36900.0f);
    }
    win->complete_reveal();
    graph = (TDLGraph *)TDLGraph::create();
    if (graph != NULL) {
        graph->set_graph_param(2);
    }
    frames = 0;
    if (get_main_phase() == 0xF) {
        TLobby::reset_state_flags();
    }
    pad = &controller_physical_port_bank.controllers[3];
    for (;;) {
        frames++;
        func_803DCDFC__Fv();
        controller_stuff();
        if (camera_ctrl_instance != NULL) {
            camera_ctrl_instance->setup_default_view(0);
        }
        main_task.render();
        draw_snapshot_capture_overlay();
        TLobby::wait_ready_loop();
        if (static_cast<s8>(func_801A5E54()) != 0) {
            break;
        }
        TParticleCtrl::begin_effect_render();
        if (graph != NULL) {
            TDLGraph::update_graph(frames, 0x78);
            graph->run_task();
            graph->render();
        }
        win->render();
        TParticleCtrl::end_effect_render();
        if (frames >= 6.0) {
            if (test_pressed_buttons_packed(pad, 2) != 0 || frames >= 0x78) {
                result = 0;
                break;
            }
            if (test_pressed_buttons_packed(pad, 4) != 0) {
                result = 1;
                break;
            }
        }
        render_tick();
    }
    if (graph != NULL) {
        delete graph;
    }
    if (get_main_phase() == 0xF) {
        TLobby::process_deferred_player_setup();
    }
    if (win != NULL) {
        delete win;
    }
    return result;
}

