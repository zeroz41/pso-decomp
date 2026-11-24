#include "pso/system/save/CardFileInfo.h"
#include "pso/player/TPlyInventory.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/PlayerLevelTable.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/player/PlayerState.h"
#include "pso/player/PlayerHoldPacket.h"
#include "pso/system/SoundEffect.h"
// Built with -inline off,deferred (configure.py): CodeWarrior emits deferred functions
// last to first, so they are defined here from the highest address down.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowReturnCity.h"
#include "pso/object/TActorLight.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/network/TPlyOnCountOver.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/ChunkMaterialState.h"

#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include <stdlib.h>
#include "pso/system/data/FlagWord.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "pso/render/reflection.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/quest/challenge/TChallenge4PResult.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/TEffGuard.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/system/scene/TScene.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/object/base/TObjChara.h"

#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/ui/font/TFontSmallHelp.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_801D3554.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_801C5470.h"
#include <stddef.h>
#include "pso/player/PlayerRequirementStats.h"
#include "pso/player/TPlyDispData.h"
#include "pso/item/TItemData.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/item/TItem.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_8011A780.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/technique/TTecLuker.h"
#include "pso/ui/hud/TMainCursor_8013BEB8.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/CollisionBodySet.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/player/PhotonBlastGauge.h"
#include "pso/item/TItemList.h"
#include "pso/player/TPlyItem.h"
#include "pso/unk/text_801D40D4.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TForceOperate.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/object/base/TObjBase.h"
#include "pso/unk/text_801D94C8.h"
#include "pso/npc/NpcPartnerControl.h"

#pragma readonly_strings on

#define M0(x) virtual void m##x();

struct Base_801B9954 {
    s16 field[18];
};

struct Attack_801B9954 {
    s16 minimum;
    s16 maximum;
    s16 accuracy;
    u8 rest[42];
};

struct Defense_801B9954 {
    s16 evasion;
    s16 resistance[5];
    u8 rest[16];
    s32 defense;
};

struct InventoryCreatePacket_801B849C {
    u8 command;
    u8 size;
    u16 actor;
    TItemData item;
    u32 flags;
};

struct Stats_801B96BC { s16 atp; s16 pad2[0x11]; };

struct Out_801B96BC { s16 a; s16 b; };

struct Self_801B96BC {
    u8 pad0[0x2B0];
    u8 *f2B0;
    u8 pad2B4[0x318 - 0x2B4];
    saddr f318;
    saddr f31C;
    u8 pad320[0xD00 - 0x320];
    TPlyItem *fD00;
    u8 fD04[4];
};

extern "C" {
s32 calc_stat_threshold__10TObjPlayerFPv(void *player);
s32 preview_equip_stats__10TObjPlayerFv(u8 *player, s16 *out, u8 *incoming);
u8 is_volopt_phase_final__10TObjPlayerFv(TObjPlayer *player);
extern u32 local_client_id;
s32 is_item_equipped(TItem *item);
s32 preview_unequip_stats__10TObjPlayerFv(Self_801B96BC *self, Out_801B96BC *out, s32 key);
struct Base_801AF3C4 { char pad[0x8]; };

struct VObj_801AF3C4 : Base_801AF3C4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
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
    virtual s32 m75(s32);
};

struct B_801AF454 { u8 pad[8]; };

struct V_801AF454 : B_801AF454 {
    virtual void m0(); virtual void m1(); virtual void m2();
    virtual void m3(u16 x);
};

struct O_801AF454 { u8 pad[0x380]; V_801AF454 *obj; };

typedef struct Player_801CD72C {
    u8 pad0[0x424];
    void *cursor;
    u8 techs[4];
} Player_801CD72C;

typedef struct Msg_801CD6BC {
    u8 pad0[2];
    u16 id;
    u8 level;
    u8 pad5[3];
} Msg_801CD6BC;

struct L_801AF554 { u8 f0[2]; s16 f2; s8 f4; };

struct VBase_801AFCF4 { u8 pad[8]; };

struct VObj_801AFCF4 : VBase_801AFCF4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32, s32);
};

struct Player_801AFCF4 {
    u8 pad[0x380];
    VObj_801AFCF4 *obj;
};

struct Pkt_801B01AC {
    u8 hdr[2];
    u16 client;
    u16 target;
    s16 amount;
};

typedef struct Pkt_801B0300
{
  u16 hdr;
  u16 a;
  u16 b;
  s16 c;
} Pkt_801B0300;

typedef struct Pkt_801B0300 Pkt_801B0300;

struct Cmd_801B0690 { u16 hdr; u16 client; s32 team; };

struct pkt_801B1674 {
    u8 hdr[2];
    u16 player_id;
};

struct Rec_801B09A4 { u8 bytes[0x42C]; };

struct Pl_801B0B88 {
    u8 pad0[0x424];
    saddr f424;
    u8 f428[0x754 - 0x428];
    u8 f754[0x7c4 - 0x754];
    u8 f7C4[4];
    u8 f7C8[0xd00 - 0x7c8];
    TPlyItem *fD00;
};

struct pkt_801B1FA4 {
    u8 hdr[2];
    u16 slot;
    s32 heading;
    Vec pos;
};

typedef struct Ctx_801B1BA4 { s16 f0; s16 f2; } Ctx_801B1BA4;

typedef struct Ctx_801B1C8C { s16 f0; s16 f2; } Ctx_801B1C8C;

typedef struct Msg_801B1E54 {
    u8 pad0[2];
    u16 a;
    s32 b;
    s16 c;
    u16 d;
} Msg_801B1E54;

struct Eff_801B2C04 { u16 f0; u16 f2; u32 f4; u32 f8; };

struct Pair_801B2C04 { u32 a; u32 b; };

struct Pkt_801B1D8C {
    u8 hdr[4];
    s32 type;
    s16 amount;
    u16 client;
};

struct Pkt_801B1EE0 {
    u8 hdr[2];
    u16 slot;
    s32 heading;
    f32 pos[3];
};

struct Pair_801B2AE8 { u32 a; u32 b; };

struct Pair_801B2AE8;

struct Item_801B2014 { s32 id; f32 val; };

struct Item_801B21AC { s32 id; f32 val; };

struct VBase_801B21AC { char pad[0x18]; };

struct VObj_801B21AC : VBase_801B21AC {
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
    virtual void m76(Item_801B21AC);
};

struct Eff_801B2D88 { u16 f0; u16 f2; u32 f4; u32 f8; };

struct Pair_801B2D88 { u32 a; u32 b; };

struct Eff_801B2CE4 { u16 f0; u16 f2; u32 f4; u32 f8; };

struct Player_801B3DD4 {
    u8 pad0[0x60];
    s32 f60;
};

struct S801B4430_801b4430_801B3FD8 { s8 b[2]; s16 h; };

struct S801B44EC_801b44ec_801B3FD8 { s8 b[2]; s16 h; };

struct S801B4630_801B3FD8 { s8 b[2]; s16 h; };

struct Cursor_801B4A18 { u8 pad[0x124]; };

struct Menu_801B4A18 { u8 pad[0x5c]; Cursor_801B4A18 cursors[4]; };

struct Owner_801B4A18 { u8 pad[0x424]; Menu_801B4A18 *menu; };

struct Slot_801B4AC8 { u8 pad[0x124]; };

struct Cursor_801B4AC8 { u8 pad[0x5C]; Slot_801B4AC8 slots[4]; u8 pad4ec[0x510 - 0x4EC]; u8 f510; };

struct Player_801B4AC8 { u8 pad[0x424]; Cursor_801B4AC8 *cursor; };

struct pkt_801B5164 {
    u8 hdr[2];
    u16 player_id;
};

struct Pkt_801B5328 {
    u8 hdr[2];
    s16 actor_id;
    s16 a;
    s16 b;
    f32 x;
    f32 z;
    f32 radius_sq;
};

struct Obj_801B4FD8 {
    u16 f0;
    s16 f2;
    s32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s16 f20;
    s16 f22;
    s16 f24;
    s16 f26;
    u8 f28[0x64 - 0x28];
    s32 f64;
    u8 f68[8];
    u8 f70[8];
    u8 f78[0x94 - 0x78];
    u8 f94[4];
    MovementHold f98;
    s32 fAC;
    s32 fB0;
    s8 fB4[0x13];
    u8 padC7[0x13C - 0xC7];
    u8 f13C[0x488 - 0x13C];
    s32 f488;
};

struct Pkt_801B5254 {
    u8 hdr[2];
    u16 client;
    s16 f4;
    s16 f6;
    f32 f8;
    f32 fC;
    f32 f10;
};

struct Rec12_801B4CE4 { u8 b[0xC]; };

struct Rec1C_801B4CE4 { u8 b[0x1C]; };

struct Src_801B4CE4 {
    u8 pad0[0x2E];
    s16 f2E;
    u32 f30;
    u8 pad34[0x38 - 0x34];
    u8 pos38[0x5C - 0x38];
    u8 f5C[0x254 - 0x5C];
    Rec12_801B4CE4 f254[5];
    u8 pad290[0x2B0 - 0x290];
    u8 *f2B0;
    u8 pad2B4[0x326 - 0x2B4];
    s16 f326;
    u8 pad328[0x32C - 0x328];
    s16 f32C;
    u8 pad32E[0x334 - 0x32E];
    s32 f334;
    u8 pad338[0x41C - 0x338];
    u8 f41C[0x428 - 0x41C];
    u8 f428[0x730 - 0x428];
    u8 f730[0x828 - 0x730];
    u8 f828[0x830 - 0x828];
    u8 f830[0x858 - 0x830];
    u8 f858[0x85C - 0x858];
    u8 f85C[0xD00 - 0x85C];
    TPlyItem *fD00;
    u8 padD04[0xDAC - 0xD04];
    u8 fDAC[4];
};

struct Dst_801B4CE4 {
    s16 f0;
    s16 f2;
    u32 f4;
    u8 f8[0x14 - 0x8];
    u8 f14[0x20 - 0x14];
    s16 f20;
    s16 f22;
    s16 f24;
    s16 f26;
    Rec12_801B4CE4 f28[5];
    s32 f64;
    u8 f68[8];
    u8 f70[8];
    u8 f78[0x94 - 0x78];
    u8 f94[4];
    MovementHold f98;
    s32 fAC;
    s32 fB0;
    u8 fB4[0x13];
    u8 padC7[0xC8 - 0xC7];
    u8 fC8[0x118 - 0xC8];
    u8 f118[0x13C - 0x118];
    s32 f13C;
    u8 f140[2];
    Rec1C_801B4CE4 f142[0x13];
    u8 pad[0x488 - 0x142 - 0x13 * 0x1C];
    s32 f488;
};

struct S801B5200_801B3FD8 { s8 b[2]; s16 h; };

struct Stack_801B6024 {
    s32 sp8;
    f32 spC;
    s32 sp10;
};

typedef struct Msg_801B6110 {
    u8 pad0[2];
    u16 slot;
    s32 andMask;
    s32 orMask;
} Msg_801B6110;

typedef struct Player_801B6110 {
    u8 pad0[0x30];
    s32 flags;
} Player_801B6110;

struct P_801B5FB0 { u8 pad[0x308]; f32 a; f32 pad30c; f32 b; };

struct Pkt_801B6A5C {
    u8 pad0[2];
    u16 id;
    s16 st[6];
    s16 exp;
    s16 kind;
};

struct Stats_801B6A5C { s16 st[6]; u8 pad[0xc]; s32 exp; };

struct Plr_801B6A5C {
    u8 pad0[0x2b0];
    Stats_801B6A5C *stats;
    u8 pad2b4[4];
    s16 a;
    s16 b;
    u8 pad2bc[0x70];
    s16 a2;
    s16 b2;
};

struct Color_801B6964 { f32 r, g, b, a; };

struct VBase_18_c0d9f3
{
  char pad[0x18];
};

struct VObj_18_c0d9f3 : VBase_18_c0d9f3 {
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
    virtual s32 m17(s32);
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
    virtual s32 m33();
    virtual s32 m34();
    virtual s32 m35();
    virtual s32 m36();
    virtual s32 m37();
    virtual s32 m38();
    virtual s32 m39();
    virtual s32 m40();
    virtual s32 m41();
};

typedef struct Msg_801B6C30 {
    u8 pad0[2];
    s16 f2;
    s16 f4[6];
    s16 f10;
    s16 f12;
} Msg_801B6C30;

typedef struct Src_801B6C30 {
    s16 v[6];
} Src_801B6C30;

typedef struct Player_801B6C30 {
    u8 pad0[0x2B0];
    Src_801B6C30 *src;
} Player_801B6C30;

struct Buf1C { u8 pad[0x1C]; };

typedef struct VBase_18_c0d9f3 VBase_18_c0d9f3;

typedef struct VObj_18_c0d9f3 VObj_18_c0d9f3;

struct Player_801B6C30;

struct P_801B7B58 { u8 pad[0xD00]; void *fD00; };

struct L_801B7E14 { u8 f0[2]; s16 f2; s32 f4; s32 f8; };

typedef struct Cmd_801B7D68 {
    u8 cmd;
    u8 size;
    u16 client;
    u32 item_a;
    u32 item_b;
} Cmd_801B7D68;

struct Pkt_801B7EB8 {
    u8 hdr[2];
    u16 client;
    s32 item;
};

struct Buf_801B802C {
    s32 n;
    TPlyInventoryItem items[30];
    u8 padding[4];
};

LAYOUT_ASSERT(SavedInventoryBufferSize, sizeof(Buf_801B802C) == 0x350);

struct S801B7F4C { s8 b[2]; s16 h; s32 w; };

typedef struct Pkt_801B8344 {
    u8 cmd;
    u8 size;
    u16 client;
    u8 item[0x14];
    u8 pad18;
    s8 f19;
    u8 pad1A[0x1C - 0x1A];
} Pkt_801B8344;

struct Stack_801B8A80 {
    s32 sp8;
    u8 pad_C[0x8];
    s32 sp14;
    u8 trailing_storage[0x4];
};

struct PlayerDeathItemFields {
    u8 before_position[0x38];
    Vec position;
    u8 before_inventory[0xD00-0x44];
    TPlyItem *inventory_owner;
};

typedef struct Msg_801B87E4 {
    u8 pad0[2];
    u16 slot;
    s16 a;
    s16 b;
    s32 c;
    u8 d[16];
} Msg_801B87E4;

typedef struct Player_801B87E4 {
    u8 pad0[0xD00];
    void *inv;
} Player_801B87E4;

struct Item_801B8AF8 {
    u8 data[0xC];
    s32 id;
    u8 data2[4];
};

typedef struct Cmd_801B8870 {
    u8 cmd;
    u8 size;
    s16 client;
    s16 b;
    s16 floor;
    s32 a;
    Vec pos;
} Cmd_801B8870;

struct Data_801B855C { u8 pad[0x20]; s32 meseta; };

struct Player_801B855C { u8 pad[0x2B0]; Data_801B855C *data; };

LAYOUT_ASSERT(DeathPlayerInventoryOffset, offsetof(PlayerDeathItemFields,inventory_owner)==0xD00);

struct L_801B8CB0 { u16 f0; u16 f2; s32 f4; u8 f8[0x78]; };

struct Cmd_801B8DE8 { u8 hdr[2]; s16 id; s32 a; s32 b; };

struct L_801B8D68 { u16 f0; u16 f2; s32 f4; s32 f8; };

struct Inv_801B91F0 {
    u8 pad0[0x1C];
    s16 count;
};

struct Player_801B91F0 {
    u8 pad0[0xD00];
    Inv_801B91F0 *inv;
};


typedef struct Cmd_801B9634 { u8 hdr[2]; s16 client; s32 val; } Cmd_801B9634;

typedef struct Msg_801B9E0C {
    u8 pad0[2];
    u16 slot;
    s32 c;
} Msg_801B9E0C;

typedef struct Player_801B9E0C {
    u8 pad0[0xD00];
    void *inv;
} Player_801B9E0C;

struct UnequipItemPacket {
    u16 header;
    u16 client;
    u32 item_id;
    u32 reserved;
};
LAYOUT_ASSERT(UnequipItemPacketSize, sizeof(UnequipItemPacket) == 12);

struct EquipItemPacket { u16 header; s16 client; s32 item_id; s32 slot; };
LAYOUT_ASSERT(EquipItemPacketSize, sizeof(EquipItemPacket) == 12);

typedef struct Msg_801BA060 {
    u8 pad0[2];
    u16 slot;
    s32 c;
    s32 d;
} Msg_801BA060;

typedef struct Player_801BA060 {
    u8 pad0[0xD00];
    void *inv;
} Player_801BA060;

struct VBase_801B9F40 { char pad[0x18]; };

struct VObj_801B9F40 : VBase_801B9F40 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16();
    virtual void m17(s32);
    virtual void m18();
    virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22();
    virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26();
    virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30();
    virtual s8 m31();
};

struct Player_801B9F40 { u8 pad[0xD04]; u8 slots[4]; };

struct RecoveredGlobal_802A1154_main_task {
    s32 value;
    u8 remaining[0x30];
};

LAYOUT_ASSERT(RecoveredGlobal_802A1154_main_task_size, sizeof(RecoveredGlobal_802A1154_main_task) == 0x34);

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

LAYOUT_ASSERT(RecoveredGlobal_8000F7FC_lbl_80515F48_size, sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28);

struct Base_801BA6BC { u8 pad[0x18]; };

struct Ctrl_801BA6BC : Base_801BA6BC {
    virtual ~Ctrl_801BA6BC();
};

typedef struct Msg_801BA838 {
    u8 pad0[2];
    u16 slot;
    s32 floor;
    u8 vec[12];
    s32 ang;
    u8 pad20[8];
} Msg_801BA838;

typedef struct Player_801BA838 {
    u8 pad0[0x60];
    s32 ang;
} Player_801BA838;

typedef struct Msg20_801BA8D4 {
    u8 pad0[2];
    u16 id;
    s32 f4;
    u8 vec[12];
    s32 ang;
} Msg20_801BA8D4;

typedef struct Msg_801BA8D4 {
    u8 pad0[2];
    u16 id;
    s16 floor;
    u8 pad6[2];
    s32 f8;
    f32 speed;
} Msg_801BA8D4;

typedef struct Player_801BA8D4 {
    u8 pad0[0x38];
    u8 pos[12];
    u8 pad44[0x60 - 0x44];
    s32 ang;
} Player_801BA8D4;

struct Msg_801BA78C {
    u16 cmd;
    u16 slot;
    u32 x4;
    u32 flags;
};

struct Sp8Struct_801baa00 {
    s16 f0;
    s16 fA;
    s32 fC;
};

struct Msg_801BAB1C { u16 cmd; u16 id; s32 value; u8 pad8[8]; };

struct VBase_801BAB78 { char pad[0x18]; };

struct VObj_801BAB78 : VBase_801BAB78 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
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
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, Vec *);
    u8 pad1c[0x3C - 0x1C];
    f32 f3c;
    u8 pad40[0x60 - 0x40];
    s32 f60;
    u8 pad64[0x248 - 0x64];
    u8 f248[4];
};

struct Stack_801BAD60 {
    s32 sp8;
    f32 spC;
};

struct Player_801BB524 { u8 pad[0x30]; u32 flags; u8 pad34[0x324 - 0x34]; s16 control; };

struct VBase_18_9c7036
{
  char pad[0x18];
};

struct VObj_18_9c7036 : VBase_18_9c7036 {
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
    virtual u8 m41();
};

typedef struct VBase_18_9c7036 VBase_18_9c7036;

typedef struct VObj_18_9c7036 VObj_18_9c7036;

struct O_801BC050 { u16 a; u16 pad; s32 b; };

struct Body_801BBD58 {
    Vec offset;
    f32 radius;
    f32 radius2;
    s32 kind;
    s32 flags;
    Vec center;
    f32 extra;
};

struct Player_801BBD58 {
    u8 pad[0x38];
    Vec pos;
    u8 pad44[0x324 - 0x44];
    s16 control;
    u8 pad326[0x680 - 0x326];
    Body_801BBD58 body;
    u8 pad6ac[0x828 - 0x6AC];
    u8 f828[4];
};

typedef struct Msg_801BC068 {
    u8 pad0[2];
    u16 id;
    u8 pad4[2];
    s16 ang;
    u8 pad8[4];
    u8 vec[12];
} Msg_801BC068;

typedef struct Obj_801BC068 {
    u8 pad0[0xC];
    struct Obj_801BC068 *next;
    u8 pad10[0x38 - 0x10];
    u8 pos[12];
    u8 pad44[0x60 - 0x44];
    s32 ang;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    u8 pad6c[0x84 - 0x6C];
    s32 f84;
} Obj_801BC068;

typedef struct List_801BC068 {
    u8 pad0[0x14];
    Obj_801BC068 *head;
} List_801BC068;

s32 fn_8000F740(void *);
void mark_area_change_pending(void);
void clear_velocity(u8 *arg0);
s32 set_hp_clamped__10TObjPlayerFs(void * a0 = 0, s16 a1 = 0);
s32 is_locally_controlled__10TObjPlayerFPv(void * a0);
s32 get_actor_tp(void *);
int obj_getPtr2B0_20(u8 *p);
s32 get_actor_hp__9TObjCharaFv(void *);
s32 get_current_floor();
s32 get_type__10TObjPlayerFPv(void *);
f32 atan2_float(f32 y, f32 x);
s32 test_flags_any(s32 *flags, s32 mask);
s32 *get_shared_text_buffer(void);
s32 fn_8002AE08(s32);
void set_tp__10TObjPlayerFs(TObjPlayer *player, s32 tp);
void obj_clear_flag30_20000(TObjBase *actor);
void copy_player_visual_record(void *, void *);
s32 is_in_shadow_range(u8 *arg0, f32 farg0);
void draw_blob_shadow(s32);
saddr TObjPlayer__sub_80116620(void *, int);
void restore_scene_lighting(void);
void select_actor_lighting(saddr obj);
void publish_actor_light_scalars(u32, f32, f32);
void TObjPlayer__sub_8013A748(void *);
u16 get_id__11TMainCursorFv(void* p);
s32 TMainCursor__sub_80154098(int, int, int);
s32 TMainCursor__sub_801540B8(int, int, int);
u16 register_entity_by_id(void *obj);
u8 * find_entity_by_id(u16);
void check_enemy_body_collisions(void *arg0);
int clear_collision_bodies__14TObjCollidableFv(void*);
u16 TObjRoomId__sub_801A1DB8(s32);
void handle_6x9B_level_up_all_techniques(void *command);
void TObjPlayer__sub_801AF554(void *arg0, s8 arg1);
void play_voice_pair__10TObjPlayerFPv(TObjPlayer *player);
int TObjPlayer__sub_801AF694(void* p);
void set_flags_a00__10TObjPlayerFPv(void *object);
void TObjPlayer__sub_801AF904(s32 arg0);
void clamp_stats__10TObjPlayerFiPv(saddr arg0, void *arg1);
s32 get_class_index__10TObjPlayerFv(u8 *arg0);
s8 TObjPlayer__sub_801AFDBC(s8 cls);
u8 is_key_machine_ready__10TObjPlayerFv(void);
u8 is_lobby_floor_15__15TFontSmallLobbyFv(void);
u8 is_on_current_floor__10TObjPlayerFi(saddr player);
s32 TObjPlayer__sub_801AFFD0(u8 *player);
void handle_6x8F_add_battle_damage_scores(saddr command);
void apply_camera_shake__10TObjPlayerFiii(saddr player, saddr target, s32 damage);
void handle_6x8E(void);
void record_damage_stats__10TOMineTrapFUiUis(uaddr arg0, u32 arg1, s16 arg2);
void draw_player_status(saddr arg0, void *arg1, saddr arg2);
void show_sub_status_window(void *arg0, s32 *arg1, s32 *arg2);
void draw_status_line(void *arg0, s32 *arg1, s32 *arg2, s32 arg3);
int TObjPlayer__sub_801B066C(void* p);
void handle_6x90_set_player_battle_team(saddr command);
void check_flag_01000000__10TObjPlayerFPv(void *player);
void handle_6x82_enable_drop_weapon_on_death(void *command);
s32 TLobby__sub_801B07E0(s32 arg0, void * _w1);
void handle_6x81_disable_drop_weapon_on_death(void *command);
s32 TLobby__sub_801B08F0(s32 arg0, void * _w1);
void TLobby__sub_801B09A4(void);

void check_flag_800000__10TObjPlayerFPv(void *player);
void handle_6x7B_disable_stealth_suit_effect(void *command);
void draw_small_label__15TFontSmallLobbyFi(saddr arg0);
void handle_6x7A_enable_stealth_suit_effect(void *command);
s32 TFontSmallLobby__sub_801B1224(s32 arg0, void * _w1);
void TLobby__sub_801B1254(saddr arg0);
void handle_6x1C_disable_pk_mode_for_player(void *command);
void handle_6x1B_enable_pk_mode_for_player(void *command);
void* draw_font__10TObjPlayerFPv(void* p);
void TObjPlayer__sub_801B18C0(saddr arg0, u32 arg1);
void unequip_by_field326__10TObjPlayerFPv(void *player);
s32 reset_volopt_state__10TObjPlayerFv(TObjPlayer *player);
void foreach_player__10TObjPlayerFv(s32 (*arg0)(u32));
s32 handle_set_visible__10TObjPlayerFi(s32 arg0);
void handle_6x2F_change_player_hp(saddr command);
void send_6x2F_change_player_hp(s32 id, s32 client, s32 hp);
void handle_6x24_teleport_player(saddr command);
s32 is_flag30_10_set__10TObjPlayerFi(saddr actor);
s32 is_flag30_8_set__10TObjPlayerFi(saddr actor);
void remove_status_effect__10TObjPlayerFUiPv(uaddr, Pair_801B2C04 *);
void dispatch_status_effect_msg__10TObjPlayerFUiPv(uaddr player, Pair_801B2AE8 *msg);
void handle_6x0D_add_or_remove_status_effect(void *command);
void send_code_13_3__10TObjPlayerFii(saddr arg0, saddr arg1);
void handle_6x0E_clear_negative_status_effects(s32 command);
s32 clear_negative_status_effects__10TObjPlayerFi(s32 arg0);
void handle_6x0C_add_or_remove_status_effect(void *command);
s32 calc_scaled_value__10TObjPlayerFii(s32 arg0, s32 arg1);
s16 get_attack_params_atp_min(void *);
s16 get_attack_params_atp_max(void *);
void apply_speed_scale__10TObjPlayerFif(saddr arg0, f32 farg0);
s32 build_player_class_stat_template(saddr arg0, saddr arg1);
s32 build_player_equipment_requirement_stats(TObjPlayer *self, PlayerRequirementStats *player_requirement_stats);
void recover_player_full(void *player);
void prepare_guild_return__10TObjPlayerFPv(void *player);
void handle_6x34(void);
void complete_deferred_player_death(void);
int is_flag_400_set__10TObjPlayerFPv(void* p);
void enable_action_input__10TObjPlayerFPv(void* p);
int get_result_entry__18TChallenge4PResultFPv(void* p);
int get_field_340__18TChallenge4PResultFPv(void* p);
int get_player_result__18TChallenge4PResultFPv(void* p);
void TObjPlayer__sub_801B3FD8(void* p);
void TObjPlayer__sub_801B4044(void* p);
s32 test_ordered_anim_markers__10TObjPlayerFPvff(u8 *arg0, f32 at_frame, f32 farg1);
void handle_6xA1_revive_player_v3(void *command);
void handle_6x32_medical_center_revive_all_players(void);
void send_code50_packet__10TObjPlayerFi(saddr player);
void recover_full__10TObjPlayerFPv(void *player);
void handle_6x31_use_medical_center(void *command);
void send_code_49_1__10TObjPlayerFi(saddr player);
void submit_cursor_candidate(void *self);
void submit_target_to_player_cursor(void *target, s32 id);
void fill_player_record__10TObjPlayerFPvPv(Src_801B4CE4 *src, Dst_801B4CE4 *dst);
Obj_801B4FD8 * init_player_join_record(Obj_801B4FD8 *self);
void handle_6x2D_release_hold(void *command);
void handle_6x2C_impose_hold(saddr command);
void *TObjPlayer__sub_801B57E8(TObjPlayer *player);
void TObjPlayer__sub_801B5A44(saddr arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void TObjPlayer__sub_801B5AF8(saddr player, s32 index);
void damp_planar_velocity(P_801B5FB0 *p);
void handle_6x2E_set_or_clear_player_flags(void *command);
void handle_6x30_change_player_level(void *command);
void send_6x30_change_player_level(Player_801B6C30 *arg0);
void calc_move_velocity(const Vec *direction, Vec *out, f32 speed);
void handle_6x99(void);
void handle_6x98(void);
void TObjPlayer__sub_801B7B58(P_801B7B58 *player, s32 key, s32 arg2);
s32 can_destroy_with_parents__10TObjPlayerFUi(uaddr arg0);
s32 fn_801B7CEC(u8 *player, s8 kind, s8 group, s8 index);
void handle_6x28_feed_mag(saddr command);
void send_6x28_feed_mag(void *arg0, s32 arg1, s32 arg2);
void handle_6x27_use_item(saddr command);
s32 try_send_6x27_use_item(void *player, s32 key);
void handle_6x2B_create_inventory_item(saddr command);
void handle_6x2A_drop_item(void *command);
void dispatch_input__10TObjPlayerFPvii(TObjPlayer *player, s32 *keys, s32 count);
void handle_6xAC(void *command);
void handle_6x29_delete_inventory_item(void *command);
void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b);
bool is_target_in_facing_cone__10TObjPlayerFPv(void *self, Vec *target);
void unequip_item__10TObjPlayerFiPv(TObjPlayer *player, TItem *item);
void handle_6x26_unequip_item(void *command);
void handle_6x25_equip_item(void *command);
void TObjPlayer__sub_801BA42C(void);
void handle_6xAE_set_animation_state(void *command);
void handle_6x20_set_position(void *command);
void handle_6x1F_set_player_floor(void *command);
void handle_6x21_inter_level_warp(void *command);
void draw_projected_shadow__10TObjPlayerFPvPvi(VObj_801BAB78 *self, f32 *pos, s32 forceDraw);
void TObjPlayer__sub_801BAC48(void);
void draw_body__10TObjPlayerFPvi(u8 *arg0, s32 arg1);
void run_task__10TObjPlayerFv(TObjPlayer *player);
void TObjPlayer__sub_801BBB70(void);
void TObjPlayer__sub_801BC050(O_801BC050 *p);
void create_player_instance__10TObjPlayerFll(u16, Rec_801B09A4 *);
TObjPlayer *get_local_player();
void clear_flag_4000_callback__10TObjPlayerFv(TObjPlayer *);
void TObjPlayer__sub_801BE784(void *, u8 v);
void TObjPlayer__sub_801BE794(void *, u8 v);
void TObjPlayer__sub_801BE7A4(void *, u8 v);
void TObjPlayer__sub_801BE7B4(void *, u8);
void TObjPlayer__sub_801BE7E0(void *, u8);
void TObjPlayer__sub_801BE80C(void *, u8);
void TObjPlayer__sub_801BE838(void *, u8);
void TObjPlayer__sub_801BE864(void *, u8);
void apply_status_effect__10TObjPlayerFPv(void *);
void swap_endian__10TObjPlayerFi(saddr packet);
void bswap_fields__10TObjPlayerFi(saddr arg0);
void init_inventory_list__10TObjPlayerFPv(void *);
s32 TObjPlayer__sub_801BE8F4(void *, s32, s32);
u8 TObjPlayer__sub_801BEB3C(void *p);
u8 TObjPlayer__sub_801BEB44(void *p);
u8 TObjPlayer__sub_801BEB4C(void *p);
void TObjPlayer__sub_801BEEAC(void *, void *);
void TObjPlayer__sub_801BEEE0(void *, void *);
void TObjPlayer__sub_801BEF30(void *, void *);
void TObjPlayer__sub_801BEF44(void *, void *);
s32 TObjPlayer__sub_801BF3A0(void *, void *);
s32 copy_vec_at_18__10TObjPlayerFv(void *, void *);
s32 set_material_index__18TPlayerLobbyMarkerFUc(u32 a0 = 0, s32 a1 = 0);
s32 __ct__20TPlayerReadyCallbackFP7TObjectUsPFP10TObjPlayer_v(s32, s32, u16, void (*)(int));
int TObjPlayer__sub_801BF460(void*);
int TObjPlayer__sub_801BF47C(void*);
int TObjPlayer__sub_801BF488(void*);
int TObjPlayer__sub_801BF4A0(void*);
s32 is_action_id_none(s32);
u8 TObjPlayer__sub_801C0124(void *, s16);
void TFontSmallLobby__sub_801C013C(void *p);
void bswap_g_client_id_header(void *p);
void *TFontSmallLobby__sub_801C01DC(void *arg0, void *arg1);
s32 copy_subcommand_header();
void send_6x9B_level_up_all_techniques(void *);
void *TFontSmallLobby__sub_801C030C(void *p, void *source);
void send_6x8F_add_battle_damage_scores(void *p);
void *TFontSmallLobby__sub_801C03E0(void *arg0, void *arg1);
void init_packet_6x90_set_player_battle_team(u8 *arg0);
void init_packet_6x82_enable_drop_weapon_on_death(void *p);
void send_6x82_enable_drop_weapon_on_death(void *p);
void init_packet_6x81_disable_drop_weapon_on_death(void *p);
void init_packet_6x7B_disable_stealth_suit_effect(void *p);
void send_6x7B_disable_stealth_suit_effect(void *p);
void init_packet_6x7A_enable_stealth_suit_effect(void *p);
void init_packet_6x1C_disable_pk_mode_for_player(void *p);
void send_6x1C_disable_pk_mode_for_player(void *p);
void init_packet_6x1B_enable_pk_mode_for_player(void *p);
void send_6x1B_enable_pk_mode_for_player(void *p);
void init_packet_6x23_set_player_visible(void *p);
void send_6x23_set_player_visible(void *p);
void fn_801C0630(void *p);
void fn_801C0644(void *p);
void *TObjPlayer__sub_801C06BC(void *arg0, void *arg1);
void TObjPlayer__sub_801C0734(void *);
u8 *TObjPlayer__sub_801C07B4(u8 *arg0, u8 *arg1);
void *TObjPlayer__sub_801C092C(void *arg0, void *arg1);
void bswap_pkt_u16x2_u32__10TObjPlayerFPv(void *p);
void TObjPlayer__sub_801C0C04(u8 *arg0);
void TObjPlayer__sub_801C0D7C(u8 *arg0);
u8 *TObjPlayer__sub_801C106C(u8 *arg0, u8 *source);
u8 *TObjPlayer__sub_801C1268(u8 *arg0, u8 *source);
u8 *TObjPlayer__sub_801C1664(u8 *arg0, u8 *source);
void TObjPlayer__sub_801C18E0(void *);
f32 fn_801C19A4(void *);
s32 TWindowDuelResult__sub_801C19AC(f32 *arg0);
void TObjPlayer__sub_801C19C8(void *p, f32 v);
s32 TLobby__sub_801C19D0(void *p);
void set_player_team_id(void *p, s32 v);
void fn_801C19E0(void *, s32);
void fn_801C19E8(void *p);
void set_player_pk_mode_flag(void *p);
void *TObjPlayer__sub_801C1A00(void *p);
s32 TObjPlayer__sub_801C1AC8(void *);
s32 TObjPlayer__sub_801C1B0C(void *, int);
s32 fn_801C1B88(void *p);
f32 get_lock_target_distance_sq(void *p);
u16 get_lock_target_id(void *p);
s32 fn_801C1BA0();
s32 is_action_channel_active(s32, s32);
u8 *TWindowActionPalette__sub_801C1D7C(saddr arg0, s32 i, s32 arg2);
s32 get_entry_by_index__20TWindowActionPaletteFPll(s32, s32);
saddr ref_primary_action_palette(s32);
saddr ref_secondary_action_palette(s32);
s32 test_photon_blast_modifier(s32);
s32 clear_secondary_action_palette_bank(s32);
s32 clear_primary_action_palette_bank(s32);
s32 set_secondary_action_palette_bank(s32);
s32 set_primary_action_palette_bank(s32);
void set_photon_blast_kind(void *, s16);
s32 fn_801C1F1C(s32);
s32 is_field_0_positive(s32 *arg0);
void *get_ptr_8(void *p);
void *__ct__12StatusEffectFv(void *);
void init_player_telepipe_record(void *);
s8 get_byte_1ab(void *);
s8 get_byte_18f(void *);
s8 get_byte_173(void *);
s32 TLobby__sub_801C2678();
void fn_801C5420(void *, s32);
int fn_801C543C(void*);
void TObjPlayer__sub_801C5780(void *, s32, s32);
s32 set_arrival_override_pos(u16, int, int);
u32 create_lobby_marker__10TObjPlayerFsSc(u16 a0 = 0, s32 a1 = 0);
void release_all_players_control_lock(void);
s32 check_conditions__10TObjPlayerFv(void *, s16);
u8 *TObjPlayer__sub_801CFBFC(u8 *arg0);
s32 check_player_action_allowed();
s32 TObjPlayer__sub_801D4368(TPlyItem *inventory);


s32 accumulate_damage_stats(saddr, saddr, s32);
s32 TObjPlayer__sub_801D6D28(s32 *);
s32 get_validated_array_value(s32 *, s32);
u8 fn_801D6DB0(s32 *);
s8 TLobby__sub_801D6DDC(s32 *);
u8 TLobby__sub_801D6F94(s32 *);
u8 TLobby__sub_801D6FFC(s32 *);
u8 TLobby__sub_801D7100(s32 *);
u8 fn_801D7134(s32 *);
u8 fn_801D7168(s32 *);
u8 fn_801D719C(s32 *);
u8 fn_801D71D0(s32 *);
u8 fn_801D7204(s32 *);
s32 TObjPlayer__sub_801D91B8(void *, void *);
void update_all_units__10TObjPlayerFll(void *, u8);
s32 is_item_area_enabled(s32 area);
s32 __ct__17TMedicalCenterMesFP7TObjectP10TObjPlayer(void *, void *, void *);
void text_builder_append_int(s32 arg0);
void text_builder_append(u8 *str);
u32 __nw__7TObjectFUl(s32);
u8 * __ct__7TObjectFP7TObject(void *, void *);
void construct_actor_light_task(void *, Color_801B6964 *, Vec *, s32, s32, s32, f32);
u32 TWindowReturnCity__ct(u32, saddr, u16);
s32 get_battle_ctrl_default__6TLobbyFv();
void run_palettex_callback(u16);
s32 is_palettex_activated(u16);
void reset_client_quest_slot_table(void);
s32 fn_8036B748(void *);
s32 fn_8036B770(void *);
s32 validate_6xAE_set_animation_state(void *);
void __construct_array(void *, void *(*)(void *), void *, u32, u32);
f32 cos_table_lookup(s32);
s32 matrix_mult_vec(int, void *, void *);
f32 vec3_dot(const Vec *, const Vec *);
void scale_matrix(int, f32, f32, f32);
f32 vector_length(const Vec *);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(s32, s32);
void rotate_matrix_z(int, s32);
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
void rotate_matrix_x(int, s32);
void set_chunk_material_override_pair(s32 first, s32 second);
void draw_chunk_object(void *child);

extern const char *TOMineTrap__data_805D3080;
extern const char *TObjPlayer__player_set_class_name;
extern const f32 TObjPlayer__data_805DC278;
extern f32 TObjPlayer__data_805DC28C;
extern f32 TObjPlayer__data_805DC294;
extern const f32 TObjPlayer__data_805DC2BC;
extern RecoveredGlobal_802A1154_main_task TObjPlayer__sub_801BEABC;
extern u8 main_phase_state[];
extern Vec scratch_vec[];
extern Vec lbl_8050BF60;
extern Color_801B6964 player_feedback_light_color[];
extern void *player_slot_table[];
extern u8 lobby_rule_settings[];
const char *lbl_805D3530 = "TObjPlayer";
extern s32 lbl_805D55C0;
extern s32 lobby_player_count;
extern s32 shared_state_flags;
extern Rec_801B09A4 *lobby_char_slot_array;
extern s32 lbl_805DC27C;
extern f32 lbl_805DC280;
extern f32 lbl_805DC284;
extern f32 lbl_805DC288;
extern const f32 lbl_805DC290;
extern const f32 lbl_805DC298;
extern const f32 lbl_805DC29C;
extern const f32 lbl_805DC2B0;
extern const f32 lbl_805DC2B4;
extern const f32 lbl_805DC2B8;
extern const f32 lbl_805DC2C0;
extern const f32 lbl_805DC2C4;
extern const f32 lbl_805DC2C8;
extern const f32 lbl_805DC2CC;
extern const f32 lbl_805DC2D0;
extern const f32 lbl_805DC2D4;
extern s32 model_render_flags;
extern RecoveredGlobal_8000F7FC_lbl_80515F48 start_freeze_self__10TObjPlayerFv;

}

void send_6x24_teleport_player(u16 slot, const Vec *pos, s32 heading);

s16 item_equip_attach_equip_flag_table[10] = {0x3E, 0x3F, 0x18, 0x24, 0x32, 0x23, 0x30, 0x0A, 0x13, 0x00};

extern "C" {

struct Ent_801AF868 { u16 id; s16 val; u32 pad; };
s32 *TWindowDuelResult__sub_801C257C(void);
s32 *get_split_screen_battle_rankings(void);
}
void obj_copyVec2_0(u8 *d, u8 *s);
void set_shadow_material_state(void);
void emit_sand_footstep_effect(saddr arg0);
void emit_water_footstep_effect(saddr arg0);
void emit_grass_footstep_effect(saddr arg0);
void init_6x27_use_item_cmd(u8 *arg0);
void init_6x1F_floor_packet(u8 *arg0);
void init_6x21_inter_level_warp_packet(u8 *arg0);
void refill_trap_counts(saddr arg0, s32 arg1, s32 arg2);
void update_player_appear_fade(u8 *arg0);
void save_render_material_state(u8 *arg0);
s32 player_auxiliary_surfaces_enabled();
void text_builder_reset(void);
s32 validate_6x0E_clear_negative_status_effects(G_ClientIDHeader *packet);
s32 validate_6xA1_revive_player_v3(G_ClientIDHeader *packet);
s32 validate_6x31_use_medical_center(G_ClientIDHeader *packet);
s32 validate_6x30_change_player_level(G_ClientIDHeader *packet);
s32 validate_6x2F_change_player_hp(G_ClientIDHeader *packet);
s32 validate_6x2E_set_or_clear_player_flags(G_ClientIDHeader *packet);
s32 validate_6x2D_release_hold(G_ClientIDHeader *packet);
s32 validate_6x2C_impose_hold(G_ClientIDHeader *packet);
s32 validate_6x2B_create_inventory_item(G_ClientIDHeader *packet);
s32 validate_6x2A_drop_item(G_ClientIDHeader *packet);
s32 validate_6xAC(G_ClientIDHeader *packet);
s32 validate_6x29_delete_inventory_item(G_ClientIDHeader *packet);
s32 validate_6x28_feed_mag(G_ClientIDHeader *packet);
s32 validate_6x27_use_item(G_ClientIDHeader *packet);
s32 validate_6x26_unequip_item(G_ClientIDHeader *packet);
s32 validate_6x25_equip_item(G_ClientIDHeader *packet);
s32 validate_6x24_teleport_player(G_ClientIDHeader *packet);
s32 validate_6x21_inter_level_warp(G_ClientIDHeader *packet);
s32 validate_6x20_set_position(G_ClientIDHeader *packet);
s32 validate_6x1F_set_player_floor(G_ClientIDHeader *packet);
s32 validate_6x82_enable_drop_weapon_on_death(G_ClientIDHeader *packet);
s32 validate_6x81_disable_drop_weapon_on_death(G_ClientIDHeader *packet);
s32 validate_6x7B_disable_stealth_suit_effect(G_ClientIDHeader *packet);
s32 validate_6x7A_enable_stealth_suit_effect(G_ClientIDHeader *packet);
s32 validate_6x90_set_player_battle_team(G_ClientIDHeader *packet);
s32 validate_6x8F_add_battle_damage_scores(G_ClientIDHeader *packet);
s32 validate_6x1C_disable_pk_mode_for_player(G_ClientIDHeader *packet);
s32 validate_6x1B_enable_pk_mode_for_player(G_ClientIDHeader *packet);
s32 validate_6x9B_level_up_all_techniques(G_ClientIDHeader *packet);

// The level-up light colour and direction (spawn_level_change_feedback).
extern const f32 lbl_805DC2A0;
extern const f32 lbl_805DC2A4;
extern const f32 lbl_805DC2A8;
extern const f32 lbl_805DC2AC;
struct Pkt_801B1B08 { u16 f0; u16 client; u32 pad; };
s32 validate_6x23_set_player_visible(G_ClientIDHeader *packet);

struct Pkt_801B1C00 { u16 f0; u16 client; u32 pad; };
s32 validate_6x22_set_player_invisible(G_ClientIDHeader *packet);
extern "C" {
void set_invisible__10TObjPlayerFv(Pkt_801B1C00 *, void *);

struct Pl_801B0B88;
}

// An equipped item and the slot it sits in, kept while apply_battle_level_reset rebuilds the stats.
struct Unk_801B67C4 {
    Unk_801B67C4() {
        slot = 0;
        item = NULL;
    }

    s16 slot;
    TItem *item;
};

struct Pkt_801B8908 { u16 f0; u16 client; s16 a; s16 b; };
s32 validate_6x83_place_trap(G_ClientIDHeader *packet);
extern "C" {
uaddr create_placed_trap__10TOMineTrapFUiss(u8 *, s32, s32);

s32 TWindowCtrl__sub_8024A228(u16);

struct Cand_801BBE54 { s16 val; Obj_801BC068 *obj; };
struct Cmd_801BBE54 { u16 hdr; u16 client; s32 area; u8 pos[12]; };
extern const f32 lbl_805DC2D8;

// Called ahead of its definition: the functions run from the highest address down.
s32 is_action_available__10TObjPlayerFi(saddr arg0);

void TObjPlayer::send_selected_spawn_position(u16 id) {
    Msg_801BC068 m;
    saddr found;
    Obj_801BC068 *o;
    found = 0;
    for (o = ((List_801BC068 *)tl_06)->head; o != NULL; o = o->next) {
        if (reinterpret_cast<TObject *>(o)->check_value_equals(TObjPlayer__player_set_class_name) != 0 && o->f84 == 0 &&
            (s32)o->f68 == id) {
            found = 1;
            break;
        }
    }
    if (found != 0 && (this == NULL || this->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&m))->init_set_position_packet();
        m.id = ((TObjBase *)(this))->get_entity_id();
        m.ang = o->ang;
        VecCopy((Vec *)m.vec, (const Vec *)o->pos);
        TObjPlayer__sub_801C18E0(&m);
    }
}

void TObjPlayer__sub_801BC050(O_801BC050 *p) {
    p->a = 0xFFFF;
    p->b = 0;
}

void TObjPlayer::send_respawn_position() {
    Cand_801BBE54 list[13];
    Cmd_801BBE54 cmd;
    u8 pos[12];
    s32 count;
    s32 i;
    s32 ok;
    Obj_801BC068 *obj;
    Cand_801BBE54 *c;
    s32 area;
    Obj_801BC068 *pick;

    ((void (*)(void *, void *, int, int, int))__construct_array)(list, (void *)TObjPlayer__sub_801BC050, 0, 8, 13);
    c = list;
    count = 0;
    for (obj = ((List_801BC068 *)tl_06)->head; obj != NULL; obj = obj->next) {
        if (reinterpret_cast<TObject *>(obj)->check_value_equals(TObjPlayer__player_set_class_name) != 0 && obj->f84 == 0) {
            f32 range = lbl_805DC2C0;
            ok = 1;
            for (i = 0; i < 12; i++) {
                if (i != (u16)this->get_entity_id()) {
                    u8 *p = (u8 *)get_player_by_client_id(i);
                    if (p != NULL && horizontal_distance_squared((const Vec *)obj->pos, (const Vec *)(p + 0x38)) < range) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok != 0) {
                count++;
                c->val = obj->f68;
                c->obj = obj;
                c++;
            }
        }
        if (count > 4) {
            break;
        }
    }
    ((TObjPlayer *)(&cmd))->init_cmd_6x24();
    pick = list[(s32)((f32)count * (lbl_805DC2D8 * (lbl_805DC288 * (f32)rand())))].obj;
    if (pick == NULL || count == 0) {
        area = this->rotation_y;
        VecCopy((Vec *)pos, (const Vec *)((u8 *)this + 0x38));
    } else {
        area = pick->ang;
        VecCopy((Vec *)pos, (const Vec *)pick->pos);
    }
    if (this == NULL || ((TObjChara *)this)->obj_isState2_324() == 0) {
        cmd.client = this->get_entity_id();
        cmd.area = area;
        VecCopy((Vec *)cmd.pos, (const Vec *)pos);
        ((TObjPlayer *)(&cmd))->send_lobby_update();
    }
}

void TObjPlayer::init_collision_body() {
    Player_801BBD58 *self = (Player_801BBD58 *)this;
    self->body.offset.x = TObjPlayer__data_805DC278;
    self->body.offset.y = TObjPlayer__data_805DC278;
    self->body.offset.z = TObjPlayer__data_805DC278;
    self->body.radius = lbl_805DC2B0;
    self->body.radius2 = lbl_805DC2B0;
    self->body.kind = 0;
    switch (this->control_state) {
    case 1:
    case 2:
        if (get_type__10TObjPlayerFPv(self->f828) == 0) {
            self->body.flags = 0x200B;
        } else {
            self->body.flags = 0x2003;
        }
        break;
    case 3:
        if (get_type__10TObjPlayerFPv(self->f828) == 0) {
            self->body.flags = 0x604B;
        } else {
            self->body.flags = 0x6043;
        }
        break;
    case 6:
        self->body.flags = 0x16043;
        break;
    }
    self->body.center.x = self->pos.x;
    self->body.center.y = self->pos.y;
    self->body.center.z = self->pos.z;
    self->body.extra = TObjPlayer__data_805DC278;
    ((TObjCollidable *)self)->set_collision_body(&self->body);
}

int TObjPlayer::clear_links() { return clear_collision_bodies__14TObjCollidableFv(this); }

void TObjPlayer::create_lockon_cursor() {
    if (is_single_screen() != 0) {
        if (this->lock_on_cursor == NULL) {
            this->lock_on_cursor = new TLockOnCursor(this, this->get_entity_id());
        }
    } else if (((TObjPlayer::is_locally_controlled(this) != 0) || (obj_isState3_324() != 0)) && (this->lock_on_cursor == NULL)) {
        this->lock_on_cursor = new TLockOnCursor(this, this->get_entity_id());
    }
}

void TObjPlayer::release_lock_on_cursor() {  }

void TObjPlayer::update_lock_on_cursor() { void* m = this->lock_on_cursor; if (m) ((TLockOnCursor *)m)->reset_and_spawn_cursors(); }

void TObjPlayer::clear_lock_on_cursor(void *data) { this->lock_on_cursor = NULL; }

void TObjPlayer::init_action_palette_defaults(saddr player) {
    ((TObjPlayer *)player)->set_action_palette_entry(0, 0, 0, 1, 0);
    ((TObjPlayer *)player)->set_action_palette_entry(0, 1, 0, 1, 0);
}

void TObjPlayer::init_player_substructs(u8 *data) {
    TObjPlayer__sub_8013A748((void *)((char *)this + 1280));
    TObjPlayer::init_action_palette_defaults((saddr)this);
}

void TObjPlayer::release_action_palettes() {  }

int TObjPlayer::reset_action_input() { return ((int (*)(void*))enable_action_input__10TObjPlayerFPv)(this); }

void TObjPlayer__sub_801BBB70(void) {  }

void TObjPlayer::setup_fresh_player_state(u8 *arg1) {
    this->hp = (s16) this->hpmax;
    this->tp = (s16) this->tpmax;
    if ((this->obj_isState2_324() != 0) && (TFontSmallLobby::is_lobby_floor_15() == 0) && (TObjPlayer::check_camera_mode() == 0)) {
        deactivate_body_collision();
    }
    if (this->is_android() != 0) {
        this->set_flag_10000();
    }
    if (is_alive_and_ready() != 0) {
        refill_traps();
    }
    this->set_language((int) (*(u8 *)((s8 *)arg1 + 3)));
    scale_state.set_actor_id(this->get_entity_id());
    TObjPlayer::disable_drop_weapon_on_death(this);
    *(s8 *)&this->unk_338 = get_byte_173(arg1);
    this->m_339 = get_byte_18f(arg1);
    *(s8 *)&this->unk_33A = get_byte_1ab(arg1);
}

void TObjPlayer::sub_801BB950() {
  u32 temp_r3_2;
  u8 *equipped_weapon;
    u8 *arg0 = (u8 *)this;
  if (is_current_area_item_enabled() != 0)
  {
    equipped_weapon = (u8 *)TObjPlayer::get_equipped_weapon(arg0);
    if (equipped_weapon != 0)
    {
      this->set_action_provider_variant((s16)((VObj_18_9c7036 *)(equipped_weapon))->m41());
    }
  }
  if ((TObjPlayer::is_locally_controlled(this) != 0) && (TFontSmallLobby::is_lobby_floor_15() == 0))
  {
    if (is_current_area_item_enabled() == 0)
    {
      this->photon_blast_gauge.clear_charge();
    }
    this->photon_blast_gauge.reinit_photon_blast_gauge();
    this->photon_blast_gauge.update_if_ready();
    TObjPlayer::update_photon_blast_state();
  }
  if (TFontSmallLobby::is_lobby_floor_15() != 0)
  {
    temp_r3_2 = this->m_54c;
    if ((temp_r3_2 != 0U) && (reinterpret_cast<TObject *>(temp_r3_2)->check_value_equals(TFontSmallLobby__name) != 0))
    {
      ((TObject *)(this->m_54c))->queue_destruction();
    }
    this->m_54c = (uaddr)TFontSmallLobby::create(this->get_entity_id() & 0xFFFFu);
  }
  obj_clear_flag30_20000(this);
  if (TObjPlayer::is_locally_controlled(this) != 0)
  {
    if (TObjPlayer::check_flag_800000(this) != 0)
    {
      ((s32 (*)(void *))draw_small_label__15TFontSmallLobbyFi)(this);
    }
    if (scale_state.is_scaled() != 0)
    {
      scale_state.request_size_restore();
    }
  }
  TFontSmallLobby__sub_801C013C(&this->technique_state);
  reset_client_quest_slot_table();
}

void TObjPlayer::init_class_flags(saddr arg1) {
    *(s8 *)&this->unk_338 = TObjPlayer__sub_801BEB4C((void *)arg1);
    this->m_339 = TObjPlayer__sub_801BEB44((void *)arg1);
    *(s8 *)&this->unk_33A = TObjPlayer__sub_801BEB3C((void *)arg1);
}

void TObjPlayer::sub_801BB8B0(u8 *arg1) {
    s32 temp_r0;
    s32 var_r4;
    u8 *var_r30;
    u8 *var_r31;
    u8 *var_r3;
    var_r31 = arg1;
    var_r30 = (u8 *)this;
    var_r3 = var_r31;
    temp_r0 = ((TObjPlayer *)var_r3)->unpack_u32_lo();
    var_r3 = (var_r30 + 0x41C);
    var_r4 = temp_r0;
    ((TTecLuker *)var_r3)->set_state(var_r4);
    var_r3 = var_r31;
    *(s32 *)((s8 *)var_r30 + 0x420) = ((TObjPlayer *)var_r3)->unpack_u32_hi();
}

void TObjPlayer::release_pending_action() {  }

void TObjPlayer::reset_pending_action() {  }

extern "C" void TObjPlayer__sub_801BB85C(TObjPlayer *player, u8 *record) {
    u32 state = record[0x143] | (record[0x15F] << 8);
    state |= (record[0x17B] << 16) & 0xFF0000;
    state |= record[0x197] << 24;
    ((TTecLuker *)&player->m_41c)->set_state(state);
}

void TObjPlayer::reset_motion_fields() {
    s32 temp_r30;
    s32 temp_r31;
    s32 anim_id;
    TObjBase::reset_motion_fields();
    this->TObjCollidable::reset_motion_fields();
    this->TObjMotion::reset_motion_fields();
    this->TObjChara::reset_motion_fields();
    this->reset_state();
    reset_body_parts();
    this->place_on_area_entry();
    this->update_input_and_draw();
    reset_pad_binding();
    this->can_cast_technique();
    TObjPlayer::update_recobox((saddr)this);
    this->update_state();
    reset_technique_caps();
    this->reset_area_entry_state();
    this->update_lock_on_cursor();
    reset_action_input();
    this->sub_801BB950();
    reset_pending_action();
    if ((TObjPlayer::is_locally_controlled(this) != 0) && (((s32 (*)(void))is_key_machine_ready__10TObjPlayerFv)() != 0) && (this->check_flag(0x800) == 0) && ((this->test_actor_flags(0x800) != 0) || (((s16 (*)(void *))get_actor_hp__9TObjCharaFv)(this) <= 0))) {
        this->clear_actor_flags((u32)(0x800));
        if (TObjPlayer::check_camera_mode() != 0) {
            ((s32 (*)(void *))send_code_49_1__10TObjPlayerFi)(this);
        } else {
            if (is_single_screen() == 0) {
                this->set_meseta(0);
            }
            send_6x24_teleport_player(this->get_entity_id(), (const Vec *)this->get_hospital_position(), this->get_hospital_yaw());
            this->set_state_flags(0x800);
            this->set_battle_flag(0);
        }
    }
    if ((TObjPlayer::is_locally_controlled(this) != 0) && (this->check_flag(0x800) != 0)) {
        this->clear_state_flags(0x800);
        TWindowCtrl::enable_client_main_menu(this->get_entity_id());
        send_impose_hold(this, 0xF);
        this->update_position_from_target();
        ((s32 (*)(void *))send_code_49_1__10TObjPlayerFi)(this);
        ((s32 (*)(void *))send_code50_packet__10TObjPlayerFi)(this);
        if (this->is_alive_and_ready() != 0) {
            this->refill_traps();
        }
        anim_id = this->get_anim_id();
        switch (anim_id) {
        case 2:
            break;
        case 0:
            TObjPlayer::set_camera_mode(2);
            this->send_field_state();
            this->set_meseta(0);
            {
                void *m = ((void * (*)(int))__nw__7TObjectFUl)(0x234);
                if (m != 0) {
                    __ct__17TMedicalCenterMesFP7TObjectP10TObjPlayer(m, (void *)tl_05, this);
                }
            }
            break;
        case 1:
            TObjPlayer::set_camera_mode(1);
            break;
        }
        this->set_battle_flag(0);
    }
}

s32 TObjPlayer::setup_control_role(s32 role) {
    this->set_control_role(role);
    if (role < 4) {
        ((Player_801BB524 *)this)->control = 1;
    } else if (role == 4) {
        ((Player_801BB524 *)this)->control = 2;
    } else if (role == 5) {
        ((Player_801BB524 *)this)->control = 3;
    } else if (role == 6) {
        ((Player_801BB524 *)this)->control = 6;
    } else if (role == 7) {
        ((Player_801BB524 *)this)->control = 7;
    } else {
        return 0;
    }
    ((Player_801BB524 *)this)->flags |= 0x10000000;
    init_collision_body();
    return register_player_slot() != 1 ? 1 : 0;
}

void TObjPlayer::unregister() {
    clear_links();
    this->unregister_sub();
    ((s32 *)&player_slot_table)[(u16)((TObjBase *)((saddr)this))->get_entity_id()] = 0;
}

void run_task__10TObjPlayerFv(TObjPlayer *player) {
    s16 temp_r0;
    s16 temp_r0_2;

    player->handle_state2_transitions();
    player->update_subsystems();
    player->update_position_history();
    player->update_status_effects();
    player->run_action_state_phase(player->mode, 1);
    player->advance_animation();
    ((TObjChara *)player)->calc_attach_pos();
    player->copy_position();
    ((TObjPlayer *)((u8 *)player + 0x84C))->copy_offset_position(player);
    if (((TObjCollidable *)player)->test_actor_flags(0x800) != 0) {
        ((TObjCollidable *)player)->refresh_collision_body_centers();
    } else if (get_type__10TObjPlayerFPv((u8 *)player + 0x828) == 0) {
        temp_r0 = player->control_state;
        switch (temp_r0) {
        case 1:
            ((TObjCollidable *)player)->refresh_collision_body_centers();
            check_enemy_body_collisions(player);
            player->update_enemy_collision_flags();
            break;
        case 6:
        case 2:
            ((TObjCollidable *)player)->refresh_collision_body_centers();
            break;
        case 3:
            ((TObjCollidable *)player)->refresh_collision_body_centers();
            check_enemy_body_collisions(player);
            player->update_enemy_collision_flags();
            break;
        }
    } else {
        temp_r0_2 = player->control_state;
        switch (temp_r0_2) {
        case 3:
        case 1:
            player->check_object_collisions();
            check_enemy_body_collisions(player);
            player->update_enemy_collision_flags();
            break;
        case 2:
            if (((TObjPlayer *)player)->check_flag(4) != 0) {
                ((TObjCollidable *)player)->refresh_collision_body_centers();
            } else {
                player->check_object_collisions();
            }
            break;
        case 6:
            ((TObjCollidable *)player)->refresh_collision_body_centers();
            break;
        }
    }
    player->update_movement_effects();
    player->update_facing_vector();
}

void render_shadows__10TObjPlayerFv(u8 *self) {
    f32 f;

    if (is_in_shadow_range(self + 0x38, lbl_805DC2D4) != 0) {
        ((TObjCollidable *)self)->set_shadow_flag();
        TParticleCtrl::begin_effect_render();
        if (((TObjCollidable *)self)->test_actor_flags(0x02000000) == 0 && ((TObjPlayer *)self)->is_inactive() != 0 &&
            (((TObjPlayer *)self)->check_flag_4() == 0 ||
             (((TObjPlayer *)self)->check_flag_4() != 0 && *(s16 *)(self + 0x328) == 0))) {
            f = ((TObjPlayer *)self)->classify_actor_view_detail(lbl_805DC2CC, lbl_805DC2D0, TObjPlayer__data_805DC2BC);
            ((TObjBase *)self)->clear_actor_flags((u32)0x08000000);
            draw_body__10TObjPlayerFPvi(self, (s32)f);
            save_render_material_state(self + 0x608);
            ((TObjPlayer *)self)->apply_material_color_override();
            ((void (*)(void *))TObjPlayer__sub_801BAC48)(self);
            ((TObjPlayer *)(self + 0x608))->write_ids();
        }
        TParticleCtrl::end_effect_render();
        ((TObjCollidable *)self)->clear_shadow_flag();
    }
}

void TObjPlayer::render_body_pass(f32 f) {
    u8 *self = (u8 *)this;
    ((TObjBase *)self)->clear_actor_flags((u32)0x08000000);
    TParticleCtrl::end_effect_render();
    select_actor_lighting((saddr)self);
    if (TObjPlayer::check_flag_800000(self) != 0 && ((TObjChara *)self)->obj_isState2_324() != 0) {
        TObjPlayer::draw(self, ((TObjChara *)self)->get_frame());
    } else if (!(*(u16 *)(self + 4) & 0x400)) {
        model_render_flags |= 1;
        draw_body__10TObjPlayerFPvi(self, (s32)f);
        model_render_flags &= ~1;
    }
    save_render_material_state((u8 *)&this->render_material_state);
    apply_material_color_override();
    set_draw_list_mask(1);
    ((void (*)(void *))TObjPlayer__sub_801BAC48)(self);
    ((TObjPlayer *)(self + 0x608))->write_ids();
    restore_scene_lighting();
}

void render__10TObjPlayerFv(u8 *player) {
    s32 spC;
    s32 sp8;
    f32 temp_f31;
    s32 temp_r3;

    if ((((TObjCollidable *)player)->test_actor_flags(0x02000000) == 0) && (((TObjPlayer *)player)->is_inactive() != 0) && ((((TObjPlayer *)player)->check_flag_4() == 0) || ((((TObjPlayer *)player)->check_flag_4() != 0) && (((TObjPlayer *)player)->phase == 0)))) {
        temp_r3 = ((TObjPlayer *)player)->classify_actor_view_detail(lbl_805DC2CC, lbl_805DC2D0, TObjPlayer__data_805DC2BC);
        spC = temp_r3 ^ 0x80000000;
        sp8 = 0x43300000;
        temp_f31 = (f32) temp_r3;
        if (TObjPlayer__data_805DC278 != temp_f31) {
            if (((s32)main_task.get_task_flags() & 0x20) && (is_central_control_area() != 0)) {
                if (push_player_reflection_matrix(((TObjPlayer *)player)->entity_id, 1) != 0) {
                    ((TObjPlayer *)player)->render_body_pass(temp_f31);
                    restore_render_scissor(1);
                }
            } else {
                ((TObjBase *)player)->clear_actor_flags((u32)0x08000000);
                TParticleCtrl::end_effect_render();
                select_actor_lighting((saddr)player);
                if ((TObjPlayer::check_flag_800000(player) != 0) && (((TObjChara *)player)->obj_isState2_324() != 0)) {
                    TObjPlayer::draw(player, ((TObjChara *)player)->get_frame());
                } else if (!(((TObjPlayer *)player)->m_flags & 0x400)) {
                    model_render_flags |= 1;
                    ((s32 (*)(void *, s32))draw_body__10TObjPlayerFPvi)(player, (s32) temp_f31);
                    model_render_flags &= 0xFFFFFFFE;
                }
                save_render_material_state(player + 0x608);
                ((TObjPlayer *)player)->apply_material_color_override();
                set_draw_list_mask(1);
                ((s32 (*)(void *))TObjPlayer__sub_801BAC48)(player);
                ((TObjPlayer *)(player + 0x608))->write_ids();
                ((s32 (*)(void))restore_scene_lighting)();
            }
        } else {
            ((TObjBase *)player)->set_actor_flags(0x08000000);
            set_motion_packed_rotation();
            TObjPlayer::draw(player, ((TObjChara *)player)->get_frame());
            clear_motion_packed_rotation();
            save_render_material_state(player + 0x608);
            ((TObjPlayer *)player)->apply_material_color_override();
            ((s32 (*)(void *))TObjPlayer__sub_801BAC48)(player);
            ((TObjPlayer *)(player + 0x608))->write_ids();
        }
    } else {
        set_motion_packed_rotation();
        TObjPlayer::draw(player, ((TObjChara *)player)->get_frame());
        clear_motion_packed_rotation();
        save_render_material_state(player + 0x608);
        ((TObjPlayer *)player)->apply_material_color_override();
        ((s32 (*)(void *))TObjPlayer__sub_801BAC48)(player);
        ((TObjPlayer *)(player + 0x608))->write_ids();
    }
}

void draw_body__10TObjPlayerFPvi(u8 *player, s32 arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_801BAD60, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_801BAD60, spC) == 0x4);
    Stack_801BAD60 stack;
    Vec *scale;
    push_matrix();
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(player + 0x38));
    stack.spC += ((TObjPlayer *)player)->death_sink.offset;
    translate_matrix_vec3((u8 *)(0), (u8 *)&stack.sp8);
    ((s32 (*)(int, int))rotate_matrix_y)(0, (int) (((TObjPlayer *)player)->rotation_y));
    if (((PlayerScaleState *)(player + 0x5B0))->is_scaled() != 0) {
        scale = ((PlayerScaleState *)(player + 0x5B0))->get_scale();
        ((s32 (*)(int, f32, f32, f32))scale_matrix)(0, scale->x, scale->y, scale->z);
    }
    save_render_material_state((player + 0x608));
    set_model_render_flags(8);
    ((TObjPlayer *)player)->apply_material_color_override();
    if (((TObjPlayer *)player)->m_flags & 0x400) {
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(-1, 0x800);
        set_shadow_material_state();
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(player + 0xCF4));
    set_motion_packed_rotation();
    if (arg1 == 2) {
        ((TObjPlayer *)player)->motion_flags = (s32) (((TObjPlayer *)player)->motion_flags | 0x400);
        ((TObjPlayer *)player)->draw_saving_joints();
    } else {
        ((TObjPlayer *)player)->motion_flags = (s32) (((TObjPlayer *)player)->motion_flags & 0xFFFFFBFF);
        ((TObjPlayer *)player)->draw_saving_joints_checked();
    }
    clear_motion_packed_rotation();
    ((TObjPlayer *)player)->draw_head_attachments();
    ((TObjPlayer *)(player + 0x608))->write_ids();
    pop_matrix();
    if (((PlayerScaleState *)(player + 0x5B0))->is_scaled() != 0) {
        ((s32 (*)(void *, void *, int))draw_projected_shadow__10TObjPlayerFPvPvi)(player, ((PlayerScaleState *)(player + 0x5B0))->get_scale(), 0);
        return;
    }
    ((s32 (*)(void *, void *, int))draw_projected_shadow__10TObjPlayerFPvPvi)(player, NULL, 0);
}

void TObjPlayer::draw_head_attachments() {
    s32 var_r31;
    if ((u32) this->attachment_model != 0U) {
        this->get_joint_matrix(0x3A);
        ((s32 (*)(void))push_matrix_from)();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->attachment_textures));
        if (this->m_flags & 0x400) {
            set_shadow_material_state();
        }
        TObjPlayer::play_phase_transition_sound(this->attachment_model);
        set_default_alpha_blend();
        pop_matrix();
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x8B0) != 0U) {
        this->get_joint_matrix(0x3B);
        ((s32 (*)(void))push_matrix_from)();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((void *) (((u8 *)this) + 0xA1C)));
        if (this->m_flags & 0x400) {
            set_shadow_material_state();
        }
        TCharaMaking::enable_making();
        draw_chunk_object((void *)(*(uaddr *)((s8 *)((u8 *)this) + 0x8B0)));
        TCharaMaking::clear_flag_bit0();
        set_default_alpha_blend();
        pop_matrix();
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x8AC) != 0U) {
        this->get_joint_matrix(0x3B);
        ((s32 (*)(void))push_matrix_from)();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((void *) (((u8 *)this) + 0xA1C)));
        var_r31 = 0;
        if (this->m_flags & 0x400) {
            var_r31 = 1;
        }
        TCharaMaking::enable_making();
        f32 alpha = this->render_material_state.get_alpha();
        TCharaMaking__draw_colored_hair(alpha, (s32)*(u32 *)((s8 *)((u8 *)this) + 0x8AC),
            (CharacterAppearanceFields *)(((u8 *)this) + 0x85C), var_r31);
        TCharaMaking::clear_flag_bit0();
        set_default_alpha_blend();
        pop_matrix();
    }
}

void TObjPlayer__sub_801BAC48(void) {  }

void draw_projected_shadow__10TObjPlayerFPvPvi(VObj_801BAB78 *self, f32 *pos, s32 forceDraw) {
    Vec v;
    s32 a;
    s32 b;
    self->m63(1, &v);
    push_matrix();
    direction_to_rotation_xz(self->f248, &a, &b);
    translate_matrix(0, v.x, lbl_805DC2C8 + self->f3c, v.z);
    rotate_matrix_z(0, b);
    rotate_matrix_x(0, a);
    ((void (*)(int, s32))rotate_matrix_y)(0, self->f60);
    rotate_matrix_x(0, -0x4000);
    if (pos != NULL) {
        scale_matrix(0, pos[0], pos[2], (*(const f32 *)&TObjPlayer__data_805DC294));
    }
    draw_blob_shadow(forceDraw);
    pop_matrix();
}

}

void send_6x21_inter_level_warp(TObjPlayer *player, s32 floor) {
    if (player == 0 || player->obj_isState2_324() == 0) {
        Msg_801BAB1C m;
        init_6x21_inter_level_warp_packet((u8 *)&m);
        m.id = player->get_entity_id();
        m.value = floor;
        ((TObjPlayer *)(&m))->send_warp_packet();
    }
}

extern "C" {

void handle_6x21_inter_level_warp(void *command) {
    G_InterLevelWarp_6x21 m;
    void *p;

    init_6x21_inter_level_warp_packet((u8 *)&m);
    m = *(G_InterLevelWarp_6x21 *)command;
    ((TObjPlayer *)(&m))->bswap_warp_packet();
    if (validate_6x21_inter_level_warp(&m.header) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            if ((((TObjChara *)p)->obj_isState2_324() != 0) && (m.floor != ((TObjPlayer *)p)->get_floor())) {
                ((TObjPlayer *)p)->set_state_flags(0x40000);
            }
            ((TObjPlayer *)p)->set_floor_index(get_floor_area(m.floor));
            ((TObjPlayer *)p)->set_floor(m.floor);
        }
    }
}

void TObjPlayer::apply_state_transform() {
    struct Sp8Struct_801baa00 sp8;

    ::set_flag_400000(this);
    if (((uaddr)this == 0U) || (this->obj_isState2_324() == 0)) {
        init_6x1F_floor_packet((u8 *)((s32 *)&sp8));
        sp8.fA = ((TObjBase *)((uaddr)this))->get_entity_id();
        sp8.fC = this->get_floor();
        ((TObjPlayer *)((s32 *)&sp8))->bswap_and_send_set_floor();
    }
}

void handle_6x1F_set_player_floor(void *command) {
    G_SetPlayerFloor_6x1F m;
    Msg_801BA8D4 m2;
    Msg20_801BA8D4 m3;
    void *p;
    Player_801BA8D4 *pl;
    init_6x1F_floor_packet((u8 *)&m);
    m = *(G_SetPlayerFloor_6x1F *)command;
    ((TObjPlayer *)(&m))->bswap_set_floor_packet();
    if (validate_6x1F_set_player_floor(&m.header) != 0) {
        p = get_player_by_client_id(m.header.client_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_floor_index(get_floor_area(m.floor));
            ((TObjPlayer *)p)->set_floor(m.floor);
        }
        pl = (Player_801BA8D4 *)get_local_player();
        if (pl != NULL && (pl == NULL || ((TObjChara *)pl)->obj_isState2_324() == 0)) {
            ((TObjPlayer *)(&m3))->init_cmd_6x20();
            m3.id = ((TObjBase *)(pl))->get_entity_id();
            m3.f4 = ((TObjPlayer *)pl)->get_floor();
            VecCopy((Vec *)m3.vec, (const Vec *)pl->pos);
            m3.ang = pl->ang;
            ((TObjPlayer *)(&m3))->send_player_floor_packet_u32x5();
            if (TFontSmallLobby::is_lobby_floor_15() != 0) {
                ((TObjPlayer *)(&m2))->build_6xAE_set_animation_state_packet();
                m2.id = ((TObjBase *)(pl))->get_entity_id();
                m2.f8 = ((TObjPlayer *)pl)->get_state_flags();
                m2.floor = ((TBoss7Crawfish *)pl)->get_floor();
                m2.speed = ((TObjChara *)pl)->get_frame();
                ((TObjPlayer *)(&m2))->send_player_floor_packet(m.header.client_id);
            }
        }
    }
}

void handle_6x20_set_position(void *command) {
    Msg_801BA838 m;
    Player_801BA838 *p;
    ((TObjPlayer *)(&m))->init_cmd_6x20();
    TObjPlayer__sub_801C1664((u8 *)&m, (u8 *)command);
    ((TObjPlayer *)(&m))->bswap_pkt_u32x5();
    if (validate_6x20_set_position((G_ClientIDHeader *)&m) != 0) {
        p = (Player_801BA838 *)get_player_by_client_id(m.slot);
        if (p != NULL) {
            ((TObjBase *)p)->set_position_from(m.vec);
            ((TObjPlayer *)p)->set_floor_index(get_floor_area(m.floor));
            ((TObjPlayer *)p)->set_floor(m.floor);
            p->ang = m.ang;
            ::set_flag_400000((TObjPlayer *)p);
        }
    }
}

void handle_6xAE_set_animation_state(void *command) {
    Msg_801BA78C m;
    void *p;
    ((TObjPlayer *)(&m))->build_6xAE_set_animation_state_packet();
    ((TObjPlayer *)(&m))->copy_from(command);
    ((TObjPlayer *)(&m))->bswap_pkt_u16x2_u32x2();
    if (validate_6xAE_set_animation_state(&m) != 0) {
        p = get_player_by_client_id(m.slot);
        if (p != NULL && TFontSmallLobby::is_lobby_floor_15() != 0 && ((TObjPlayer *)p)->test_action_mask(0x01000000) == 0 && (m.flags & 0x04000000)) {
            ((TObjPlayer *)p)->set_state_flags(m.flags & 0x1C000000);
            ((TObjPlayer *)p)->run_action_state_phase(0x18, 0);
        }
    }
}

}

TObjPlayer *get_player_by_client_id(s32 i) {
    if (i == 0xFFFF) {
        return 0;
    }
    if (i < 0 || i >= 12) {
        return 0;
    }
    return static_cast<TObjPlayer *>(player_slot_table[i]);
}

extern "C" {

s32 TObjPlayer::register_player_slot() {
    Ctrl_801BA6BC *c = (Ctrl_801BA6BC *)get_player_by_client_id((u16)this->get_entity_id());
    if (c != 0) {
        delete c;
    }
    player_slot_table[(u16)this->get_entity_id()] = this;
    return register_entity_by_id(this) == (u16)0xFFFF ? 1 : 0;
}

void TObjPlayer::set_action_state(s16 state, s16 animation_number) {
    *(s16 *)((s8 *)this + 0x32A) = (s16) *(s16 *)((s8 *)this + 0x326);
    *(s16 *)((s8 *)this + 0x326) = state;
    if (is_action_id_none(animation_number) == 0) {
        *(s16 *)((s8 *)this + 0xB8) = animation_number;
    }
    *(s32 *)((s8 *)this + 0x320) = (s32) (1 << state);
    this->set_state_flags(0x10);
}

s32 TObjPlayer::start_freeze() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x320) & 0x1E000) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    anim_state.set_action_id(0x10);
    anim_state.set_animation(this->get_idle_animation());
    anim_state.set_state(0);
    anim_state.set_angle(this->rotation_y);
    return 1;
}

s32 TObjPlayer::init_photon_blast(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x320) & 0x1E000) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    anim_state.set_action_id(0x10);
    anim_state.set_animation(arg1);
    anim_state.set_state(0);
    anim_state.set_angle(this->rotation_y);
    return 1;
}

s32 TObjPlayer::start_camera_pan(s16 action, s32 angle) {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x320) & 0x1E000) {
        return 0;
    }
    if ((s16) this->mode == action) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    anim_state.set_action_id(action);
    anim_state.set_animation(this->requested_action);
    anim_state.set_state(0);
    anim_state.set_angle(this->rotation_y);
    return 1;
}

void TObjPlayer::freeze_all_players() {
    ((s32 (*)(s32 *))foreach_player__10TObjPlayerFv)(&start_freeze_self__10TObjPlayerFv.value);
}

s32 TObjPlayer::end_camera_pan() {
    if ((s32) lbl_805D55C0 != 0) {
        return 0;
    }
    if (!(*(s32 *)((s8 *)this + 0x320) & 0x10000)) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFEFFFF);
    return 1;
}

void TObjPlayer__sub_801BA42C(void) {
    ((s32 (*)(void *))foreach_player__10TObjPlayerFv)(&TObjPlayer__sub_801BEABC.value);
    release_all_players_control_lock();
}

s32 TObjPlayer::try_apply_status_action(TObjPlayer *player) {
    if (player->check_flag30_bit20() != 0) {
        player->run_action_state_phase(0x13, 5);
        return 1;
    }
    if (player->is_status_flag_200() != 0) {
        if (player->test_actor_flags(0x400) != 0) {
            player->run_action_state_phase(0xE, 5);
        } else {
            player->run_action_state_phase(0xD, 5);
        }
        return 1;
    }
    if (player->can_guard() != 0) {
        player->run_action_state_phase(0xA, 5);
        return 1;
    }
    if (player->is_status_locked() != 0) {
        if (player->anim_state.get_action_id() == 0x10) {
            player->run_action_state_phase(0x10, 5);
        } else {
            player->clear_actor_flags((u32)0x10000);
            player->run_action_state_phase(player->anim_state.get_action_id(), 5);
            player->anim_state.set_action_id(0);
        }
        return 1;
    }
    return 0;
}

void TObjPlayer::handle_state2_transitions() {
    s16 control_state;
    u8 *arg0 = (u8 *)this;

    this->clear_state_flags(0x10);
    control_state = this->control_state;
    switch (control_state) {
    case 1:
        if ((get_main_phase() != 0xE) && ((s32) lbl_805D55C0 != 0)) {
            goto call3;
        }
        this->select_contextual_pickup_action();
        run_action_state_phase(this->mode, 7);
        if (this->check_flag_48() != 0) {
            break;
        }
        run_action_state_phase(this->mode, 2);
        if (this->check_flag_48() != 0) {
            break;
        }
call3:
        run_action_state_phase(this->mode, 3);
        break;
    case 2:
        if ((((s32 (*)(void *))is_on_current_floor__10TObjPlayerFi)(arg0) == 0) && (this->check_flag_4() == 0)) {
            run_action_state_phase(0x16, 0);
            return;
        }
        if ((TObjPlayer__sub_801BF918((u8 *)&this->m_634) != 0) && (this->is_body_collision_inactive() != 0) && (this->test_action_mask(4) != 0)) {
            ::set_flag_400000(this);
            ((TObjPlayer *)(arg0 + 0x634))->enter_battle_state();
        }
        run_action_state_phase(this->mode, 8);
        return;
    case 3:
    case 6:
        run_action_state_phase(this->mode, 7);
        if (this->check_flag_48() == 0) {
            run_action_state_phase(this->mode, 3);
        }
        break;
    }
}

void send_6x25_equip_item(TObjPlayer *player, s32 item_id, s32 slot) {
    EquipItemPacket packet;
    if (player->check_switch_available(item_id) != 0 && (player == NULL || player->obj_isState2_324() == 0)) {
        ((TObjPlayer *)&packet)->init_command();
        packet.client = player->get_entity_id();
        packet.item_id = item_id;
        packet.slot = slot;
        ((TObjPlayer *)&packet)->bswap_body_dwords5_and_send();
    }
}

void handle_6x25_equip_item(void *arg0) {
    Msg_801BA060 m;
    TObjPlayer *player;
    TItem *item;
    TItemList *slot;
    ((TObjPlayer *)(&m))->init_command();
    ((TObjPlayer *)(&m))->copy_pair_fields4(arg0);
    ((TObjPlayer *)(&m))->bswap_body_dwords5();
    if (validate_6x25_equip_item((G_ClientIDHeader *)&m) != 0) {
        player = (TObjPlayer *)get_player_by_client_id(m.slot);
        if (player != NULL && (slot = static_cast<TItemList *>(player->inventory_objects->start_inventory_update(m.c))) != NULL &&
            (item = slot->get_owner_if_alive()) != NULL) {
            player->equip_item_to_slot(item, m.d);
        }
    }
}

void TObjPlayer::equip_item_to_slot(TItem *item, s32 slot) {
    if (item->is_unit() != 0) {
        if (slot < 9 || slot > 12) {
            slot = 9;
        }
        s32 attach_slot = (s8)slot;
        item->set_attach_slot(attach_slot);
    } else {
        slot = item->get_attach_slot();
    }
    TItem *current = (TItem *)get_slot_value((s32 *)equipped_items, slot);
    if (current == NULL) {
        set_equip_slot_entry((s32)equipped_items, slot, (s32)item);
        item->equip();
    } else if (current != item) {
        unequip_item(current);
        set_equip_slot_entry((s32)equipped_items, slot, (s32)item);
        item->equip();
    }
    if (test_action_mask(2) != 0) {
        set_animation(((s16 (*)(void *))unequip_by_field326__10TObjPlayerFPv)(this));
    }
}

void TObjPlayer::send_6x26_unequip_item(TObjPlayer *target, u32 item_id) {
    if (target == NULL || static_cast<TObjChara *>(target)->obj_isState2_324() == 0) {
        UnequipItemPacket packet;
        ((TObjPlayer *)&packet)->init_cmd_6x26();
        packet.client = static_cast<TObjBase *>(target)->get_entity_id();
        packet.item_id = item_id;
        ((TObjPlayer *)&packet)->bswap_body_dwords4_and_send();
        static_cast<TObjPlayer *>(target)->send_unequip_held_item();
    }
}

void *TObjPlayer::copy_unequip_fields(void *command) {
    copy_subcommand_header();
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)command + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)command + 8);
    return this;
}

void handle_6x26_unequip_item(void *arg0) {
    Msg_801B9E0C m;
    TObjPlayer *player;
    TItem *item;
    TItemList *slot;
    ((TObjPlayer *)(&m))->init_cmd_6x26();
    ((TObjPlayer *)(&m))->copy_unequip_fields(arg0);
    ((TObjPlayer *)(&m))->bswap_body_dwords4();
    if (validate_6x26_unequip_item((G_ClientIDHeader *)&m) != 0) {
        player = (TObjPlayer *)get_player_by_client_id(m.slot);
        if (player != NULL && (slot = static_cast<TItemList *>(player->inventory_objects->start_inventory_update(m.c))) != NULL &&
            (item = slot->get_owner_if_alive()) != NULL) {
            player->unequip_item(item);
        }
    }
}

void TObjPlayer::unequip_item(TItem *item) {
    set_equip_slot_entry((s32)equipped_items, item->get_attach_slot(), 0);
    item->unequip();
    if (item->get_item_type() == 1 && item->get_item_group() == 1) {
        unequip_all_units();
    }
    if (test_action_mask(2) != 0) {
        set_animation(((s16 (*)(void *))unequip_by_field326__10TObjPlayerFPv)(this));
    }
}

void TObjPlayer::unequip_all_units() {
    saddr arg0 = (saddr)this;
    s32 i;
    void *slot_value;

    i = 9;
    do {
        slot_value = (void *)TObjPlayer::get_slot_value((s32 *)(arg0 + 0xD04), i);
        if (slot_value != NULL) {
            set_equip_slot_entry(arg0 + 0xD04, i, 0);
            ((TItem *)slot_value)->unequip();
        }
        i += 1;
    } while (i <= 0xC);
}

#pragma push
#pragma fp_contract on
s32 preview_equip_stats__10TObjPlayerFv(u8 *player, s16 *out, u8 *incoming) {
    Base_801B9954 b;
    Attack_801B9954 a;
    Defense_801B9954 d;
    TItem *prev;
    saddr slot;
    s32 atp;
    f32 rate;
    if (incoming != NULL && out != NULL) {
    prev = NULL;
    TLobby::copy_data(&b, *(void **)(player + 0x2B0));
    ((TLobby *)(&a))->copy_from(*(void **)(player + 0x318));
    ((TLobby *)(&d))->copy_entry(*(void **)(player + 0x31C));
    switch (incoming[0]) {
    case 0:
        prev = TObjPlayer::get_equipped_weapon(player);
        break;
    case 1:
        if (incoming[1] == 1) {
            prev = (TItem *)((TItemData *)player)->get_item_field_2();
        } else if (incoming[1] == 2) {
            prev = (TItem *)((TItemData *)player)->test_flag3();
        }
        break;
    case 2:
        prev = (TItem *)((TObjPlayer *)player)->activate_d04_slot();
        break;
    }
    if (prev != NULL) {
        prev->subtract_equip_stats(&a, (s16 *)&d, (s16 *)&b);
        if (prev->get_item_type() == 1 && prev->get_item_group() == 1) {
            for (slot = 9; slot <= 12; slot++) {
                TItem *unit = (TItem *)TObjPlayer::get_slot_value((s32 *)(player + 0xD04), slot);
                if (unit != NULL) {
                    unit->subtract_equip_stats(&a, (s16 *)&d, (s16 *)&b);
                }
            }
        }
    }
    ((TItemData *)incoming)->apply_equip_effects((saddr)player, (saddr)&a, (saddr)&d, (saddr)&b, 0);
    b.field[0] = clamp_s32(b.field[0], 0, ((s16 *)TObjPlayer::get_class_stat_entry((u8 *)player))[0]);
    b.field[1] = clamp_s32(b.field[1], 0, ((s16 *)TObjPlayer::get_class_stat_entry((u8 *)player))[1]);
    b.field[2] = clamp_s32(b.field[2], 0, ((s16 *)TObjPlayer::get_class_stat_entry((u8 *)player))[2]);
    b.field[4] = clamp_s32(b.field[4], 0, ((s16 *)TObjPlayer::get_class_stat_entry((u8 *)player))[4]);
    b.field[5] = clamp_s32(b.field[5], 0, ((s16 *)TObjPlayer::get_class_stat_entry((u8 *)player))[5]);
    b.field[6] = clamp_s32(b.field[6], 0, ((s16 *)TObjPlayer::get_class_stat_entry((u8 *)player))[6]);
    set_params__10TObjPlayerFPvPvPviPv(out, player, reinterpret_cast<player_stats *>(&b), reinterpret_cast<AttackParams *>(&a), reinterpret_cast<ActorParamBlock *>(&d));
    rate = ((TObjChara *)player)->get_status_effect_amount(2);
    {
        s16 range;
        slot = b.field[0];
        {
        s16 sl = slot;
        atp = (s32)((f32)sl * rate + (f32)(sl + get_attack_params_atp_min(&a)));
        }
        range = get_attack_params_atp_max(&a) - get_attack_params_atp_min(&a);
        out[0] = atp + (s32)((f32)range * rate + (f32)range);
    }
    rate = ((TObjChara *)player)->get_status_effect_amount(3);
    out[1] = (s32)((f32)out[1] * rate + (f32)out[1]);
    return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 preview_unequip_stats__10TObjPlayerFv(Self_801B96BC *self, Out_801B96BC *out, s32 key) {
    u8 a[0x34];
    Stats_801B96BC c;
    u8 b[0x20];
    TItem *owner;
    s32 i;
    s32 base;
    f32 k;
    s16 d;
    void *node_3423 = self->fD00->start_inventory_update(key);
    if (node_3423 == 0U) {
        return 0;
    }
    owner = (TItem *)((TItemList *)node_3423)->get_owner_if_alive();
    if (owner == NULL) {
        return 0;
    }
    if (is_item_equipped(owner) == 0 && ((TObjPlayer *)self)->get_equipped_item(owner->get_attach_slot()) == NULL) {
        return 1;
    }
    ((TLobby *)a)->copy_from((void *)self->f318);
    ((TLobby *)b)->copy_entry((void *)self->f31C);
    TLobby::copy_data(&c, self->f2B0);
    owner->subtract_equip_stats(a, (s16 *)b, (s16 *)&c);
    if (owner->get_item_type() == 1 && owner->get_item_group() == 1) {
        for (i = 9; i <= 12; i++) {
            TItem *s = (TItem *)TObjPlayer::get_slot_value((s32 *)self->fD04, i);
            if (s != NULL) {
                s->subtract_equip_stats(a, (s16 *)b, (s16 *)&c);
            }
        }
    }
    set_params__10TObjPlayerFPvPvPviPv(out, self, (player_stats *)&c, (AttackParams *)a, (ActorParamBlock *)b);
    k = ((TObjChara *)self)->get_status_effect_amount(2);
    i = c.atp;
    {
        s16 sl = i;
        base = (s32)((f32)sl * k + (f32)(sl + (s16)get_attack_params_atp_min(a)));
    }
    d = get_attack_params_atp_max(a) - get_attack_params_atp_min(a);
    out->a = base + (s32)((f32)d * k + (f32)d);
    {
        f32 k2 = ((TObjChara *)self)->get_status_effect_amount(3);
        out->b = (f32)out->b * k2 + (f32)out->b;
    }
    return 2;
}
#pragma pop

void TObjPlayer::send_unequip_held_item() {
    Cmd_801B9634 cmd;
    TItem *item;
    item = get_equipped_weapon(this);
    if ((item != NULL) && (item->check_equip_requirements(this, (s16 *)0) == 0) && (((uaddr)this == 0U) || (this->obj_isState2_324() == 0))) {
        ((TObjPlayer *)(&cmd))->init_cmd_6x26();
        cmd.client = ((TObjBase *)((uaddr)this))->get_entity_id();
        cmd.val = item->get_item_id();
        ((TObjPlayer *)(&cmd))->bswap_body_dwords4_and_send();
    }
}

void TObjPlayer::use_current_item() {
    s32 position;
    void *temp_r3;

    temp_r3 = (void *)((TItemData *)this)->test_flag3();
    if (temp_r3 != NULL) {
        ((TItem *)temp_r3)->perform_action();
        return;
    }
    this->get_anim_node_position(0x24, (Vec *)&position);
    TEffGuard::create((Vec *)&position);
}

void TObjPlayer::get_anim_node_position(s32 joint, Vec *arg2) {
    Vec stack;
    stack.z = TObjPlayer__data_805DC278;
    stack.y = TObjPlayer__data_805DC278;
    stack.x = TObjPlayer__data_805DC278;
    push_matrix_from(0);
    copy_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(get_joint_matrix(joint)));
    premultiply_matrix(NULL, TCameraCtrl::get_view_matrix());
    matrix_mult_vec(0, &stack.x, (void *)arg2);
    pop_matrix();
}

s32 TObjPlayer::update_target_lock() {
    f32 lock_target_distance_sq;
    TLockOnCursor *cursor;
    u16 lock_target_id;
    void *target;

    cursor = this->lock_on_cursor;
    if (cursor == NULL) {
        return 0;
    }
    lock_target_id = get_lock_target_id(&cursor->nearest_target);
    lock_target_distance_sq = get_lock_target_distance_sq(&this->lock_on_cursor->nearest_target);
    fn_801C1B88(&this->lock_on_cursor->nearest_target);
    if (!(this->actorFlags & 0x100000)) {
        if ((u16) lock_target_id == 0xFFFF) {
            return 0;
        }
        if ((target = find_entity_by_id(lock_target_id)) == NULL) {
            return 0;
        }
        if (!(lock_target_distance_sq < lbl_805DC2C0)) {
            goto block_17;
        }
        if (((s32 (*)(void *, s32))is_target_in_facing_cone__10TObjPlayerFPv)(this, (saddr)((TObjPlayer *)target)->get_position_ptr()) == 0) {
            goto block_17;
        }
        this->actorFlags = (s32) (this->actorFlags | 0x100000);
        return 1;
    }
    if ((u16) lock_target_id == 0xFFFF) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFEFFFFF);
        return 0;
    }
    if ((target = find_entity_by_id(lock_target_id)) == NULL) {
        return 0;
    }
    if (lock_target_distance_sq > lbl_805DC2C4) {
        goto clear_and_return;
    }
    if (((s32 (*)(void *, s32))is_target_in_facing_cone__10TObjPlayerFPv)(this, (saddr)((TObjPlayer *)target)->get_position_ptr()) != 0) {
        goto block_17;
    }
clear_and_return:
    this->actorFlags = (s32) (this->actorFlags & 0xFFEFFFFF);
    return 0;
block_17:
    return 0;
}

#pragma push
#pragma fp_contract on
bool TObjPlayer::is_target_in_facing_cone(void *target_arg) {
    Vec *target = (Vec *)target_arg;
    Vec to;
    Vec fwd = {0.0f, 0.0f, 1.0f};
    f32 x;
    f32 z;
    f32 dot;
    fwd.x = sin_table_lookup(rotation_y);
    fwd.y = TObjPlayer__data_805DC278;
    fwd.z = cos_table_lookup(rotation_y);
    x = TObjPlayer__data_805DC2BC * sin_table_lookup(rotation_y + 0x8000) + position.x;
    z = TObjPlayer__data_805DC2BC * cos_table_lookup(rotation_y + 0x8000) + position.z;
    to.x = target->x - x;
    to.y = TObjPlayer__data_805DC278;
    to.z = target->z - z;
    normalize_vector_safe(&to);
    dot = ((f32 (*)(Vec *, Vec *))vec3_dot)(&fwd, &to);
    return !(dot < cos_table_lookup(0x1555));
}
#pragma pop

s32 TObjPlayer::can_inventory_accept_item(u8 *item) {
    s32 max;
    s32 n;
    TItem *owner;
    if (TItemData::lookup_item_def(item) != 0) {
        if (item[0] == 4) {
            return 1;
        }
        void *node_3581 = ((TPlyItem *)(((Player_801B91F0 *)this)->inv))->set_mode_and_refresh_object(item);
        if (node_3581 == 0) {
            if (((Player_801B91F0 *)this)->inv->count >= 30) {
                return 0;
            }
            return ((TItemData *)item)->get_max_stack_size();
        }
        owner = (TItem *)((TItemList *)node_3581)->get_owner_if_alive();
        if (owner == NULL) {
            return 0;
        }
        n = owner->get_max_stack_size();
        n -= owner->get_amount();
        max = ((TItemData *)item)->get_stack_count();
        return (n < max) ? 0 : n;
    }
    return ((Player_801B91F0 *)this)->inv->count < 30;
}

s32 TObjPlayer::can_pickup_item_by_id(TItem *item) {
    s32 item_data[5];

    item->copy_to_item_data((TItemData *)item_data);
    return this->can_pickup_item((TItemData *)item_data);
}

s32 TObjPlayer::can_pickup_item(TItemData *item_data) {
    s32 temp_r31;
    s32 max_stack_size;
    void *held;

    if (TItemData::lookup_item_def((u8 *)item_data) != 0) {
        if ((u8) *(u8 *)item_data == 4) {
            return obj_getPtr2B0_20((u8 *)this) < 0xF423F;
        }
        void *node_3615 = this->inventory_objects->set_mode_and_refresh_object((void *)item_data);
        if (node_3615 != 0U) {
            held = ((void *)((TItemList *)node_3615)->get_owner_if_alive());
            if (held == NULL) {
                return 0;
            }
            max_stack_size = ((TItem *)held)->get_max_stack_size();
            temp_r31 = max_stack_size - ((TItem *)held)->get_amount();
            return (item_data->get_stack_count() <= temp_r31) ? 1 : 0;
        }
        goto block_7;
    }
block_7:
    if ((s16) *(s16 *)((s8 *)(*(void **)((s8 *)this + 0xD00)) + 0x1C) >= 0x1E) {
        return 0;
    }
    return 1;
}

u32 TObjPlayer::pickup_item(TItem *item) {
    u32 item_data[5];
    saddr id;
    void *list;
    s32 n;
    TItem *owner;
    u8 *inv;
    s16 idx;
    if (item == NULL) {
        return 0;
    }
    if (item->get_item_type() == 4) {
        this->add_meseta(item->calc_price());
        record_meseta_pickup(item->calc_price());
        item->destroy();
        this->play_sound_if_on_floor(0x52802);
        return 0;
    }
    if (this->can_pickup_item_by_id(item) == 0) {
        return 0;
    }
    ((void (*)(void *))TObjPlayer__sub_801C1B0C)(item);
    list = 0;
    switch (item->get_item_type()) {
    case 0:
    case 1:
    case 2:
        list = new TItemList(this->inventory_objects->pad_1C4);
        break;
    case 3:
        if (TObjPlayer__sub_801C1AC8((u8 *)item) != 0) {
            item->copy_to_item_data((TItemData *)&item_data);
            id = (saddr)this->inventory_objects->set_mode_and_refresh_object(&item_data);
            if (id == 0) {
                list = new TItemList(this->inventory_objects->pad_1C4);
                break;
            }
            n = item->get_amount();
            if (n == 0) {
                n = 1;
            }
            owner = (TItem *)((TItemList *)id)->get_owner_if_alive();
            if (owner != NULL) {
                owner->add_amount(n);
            }
            item->destroy();
            return 0;
        }
        list = new TItemList(this->inventory_objects->pad_1C4);
        break;
    }
    if (list != NULL) {
        ((TItemList *)list)->set_field_1c(item);
        inv = *(u8 * *)&this->inventory_objects;
        TObjPlayer__sub_801C1B0C((u8 *)item, (*(s16 *)((s8 *)inv + 0x1C))++);
        item->set_mode(1);
        ((TObject *)item)->set_parent((TObject *)(*(void **)((s8 *)(this->inventory_objects) + 0x1C8)));
        item->set_owner_client(this->get_entity_id());
        return (uaddr)list;
    }
    return 0;
}

void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b) {
    Cmd_801B8DE8 cmd;
    if (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() != 0) {
        return;
    }
    if (obj != 0 && ((TObjChara *)obj)->obj_isState2_324() != 0) {
        return;
    }
    ((TObjPlayer *)(&cmd))->init_cmd_6x29();
    cmd.id = ((TObjBase *)(obj))->get_entity_id();
    cmd.a = a;
    cmd.b = b;
    ((TObjPlayer *)(&cmd))->bswap_body_dwords3_and_send();
    ((TObjPlayer *)obj)->send_unequip_held_item();
}

void handle_6x29_delete_inventory_item(void *command) {
    L_801B8D68 sp8;
    ((TObjPlayer *)(&sp8))->init_cmd_6x29();
    ((TObjPlayer *)(&sp8))->copy_pair_fields3(command);
    ((TObjPlayer *)(&sp8))->bswap_body_dwords3();
    if (validate_6x29_delete_inventory_item((G_ClientIDHeader *)&sp8) != 0) {
        saddr p = (saddr)get_player_by_client_id(sp8.f2);
        if (p != 0 && ((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0) {
            ((TObjPlayer *)p)->dispatch_action(sp8.f4, sp8.f8);
        }
    }
}

void TObjPlayer::dispatch_action(s32 key, s32 amount) {
    inventory_objects->use_item(this, key, amount);
}

void handle_6xAC(void *command) {
    L_801B8CB0 sp8;
    ((TObjPlayer *)(&sp8))->init_6xAC_packet();
    TObjPlayer__sub_801C1268((u8 *)&sp8, (u8 *)command);
    ((TObjPlayer *)(&sp8))->byteswap_data();
    if (validate_6xAC((G_ClientIDHeader *)&sp8) != 0) {
        saddr p = (saddr)get_player_by_client_id(sp8.f2);
        if (p != 0 && TFontSmallLobby::is_lobby_floor_15() == 0) {
            dispatch_input__10TObjPlayerFPvii(reinterpret_cast<TObjPlayer *>(p), reinterpret_cast<s32 *>(sp8.f8), sp8.f4);
        }
    }
}

void dispatch_input__10TObjPlayerFPvii(TObjPlayer *player, s32 *keys, s32 count) {
    TObjPlayer__sub_801D49F4(player->inventory_objects, player, keys, count);
}

s32 TObjPlayer::count_items_of_type(s8 arg1, s8 arg2, s8 arg3) {
    TItemData item_data;
    if (this->inventory_objects == NULL) {
        return 0;
    }
    item_data.init();
    item_data.data1.data_u8[0] = arg1;
    item_data.data1.data_u8[1] = arg2;
    item_data.data1.data_u8[2] = arg3;
    return this->inventory_objects->count_items_by_id(&item_data);
}

void TObjPlayer::request_item_drop(s32 key, s32 count) {
    Item_801B8AF8 item;
    TItem *owner;
    s32 id;
    if (check_player_action_allowed() != 0 &&
        (poll_memcard_result((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 0 ||
         TAdPlayerLoadGC::probe_card_slot((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 1)) {
        ((void (*)(s32, s32, s32, s32))play_sound_effect)(0x53F06, 0, 0, 0);
        return;
    }
    void *node_3768 = this->inventory_objects->start_inventory_update(key);
    if (node_3768 == 0) {
        return;
    }
    owner = (TItem *)((TItemList *)node_3768)->get_owner_if_alive();
    if (owner == NULL) {
        return;
    }
    send_impose_hold(this, 0x384);
    set_action_flag_2();
    owner->copy_to_item_data((TItemData *)&item);
    ((TItemData *)&item)->set_stack_count(count);
    id = item.id;
    if (owner->get_amount() - count > 0) {
        item.id = -1;
    }
    insert_item_node(&inventory_objects->list, (Vec *)TObjPlayer__sub_801BF914(&m_84c), this, (TItemData *)&item, id);
}

void TObjPlayer::request_meseta_drop(s32 amount) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_801B8A80, sp8) == 0x0);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_801B8A80, sp14) == 0xC);
    Stack_801B8A80 stack;
    if (amount > 0) {
        send_impose_hold(this, 0x384);
        set_action_flag_2();
        ((TObjPlayer *)(&stack.sp8))->init_item_data(amount);
        stack.sp14 = -1;
        insert_item_node(&inventory_objects->list, (Vec *)TObjPlayer__sub_801BF914(&m_84c), this, (TItemData *)&stack.sp8, -1);
    }
}

s32 TObjPlayer::send_trap_packet(int arg1_) {
    s32 arg1 = arg1_;
    Pkt_801B8908 pkt;

    if ((u8 *)this != NULL && this->obj_isState2_324() != 0) {
        return 0;
    }
    if (TWindowCtrl__sub_8024A228((u16)((TObjBase *)this)->get_entity_id()) == 0) {
        return 0;
    }
    if (((s32 (*)(void *))is_action_available__10TObjPlayerFi)((u8 *)this) == 0) {
        return 0;
    }
    if ((s8)((TObjPlayer *)trap_counts)->clamp_char_at(arg1) <= 0) {
        return 0;
    }
    ((TObjPlayer *)(&pkt))->init_trap_packet();
    pkt.client = (u16)((TObjBase *)this)->get_entity_id();
    pkt.a = arg1;
    pkt.b = (s8)((TObjPlayer *)trap_counts)->clamp_char_at(arg1);
    ((TObjPlayer *)(&pkt))->bswap_body_words_and_send();
    return 1;
}

void handle_6x83_place_trap(void *command) {
    Pkt_801B8908 pkt;
    ((TObjPlayer *)(&pkt))->init_trap_packet();
    ((TObjPlayer *)(&pkt))->copy_short_fields(command);
    ((TObjPlayer *)(&pkt))->bswap_body_words();
    if (validate_6x83_place_trap((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.client);
        if (p != NULL && create_placed_trap__10TOMineTrapFUiss(p, pkt.a, pkt.b) != 0) {
            ((TObjPlayer *)(p + 0x7C4))->consume_trap_count(1, pkt.a);
            if (TObjPlayer::is_locally_controlled(p) != 0) {
                TWindowCtrl::call_window_method_with_default_vec((u16)((TObjBase *)(p))->get_entity_id());
            }
        }
    }
}

void TObjPlayer::send_6x2A_drop_item(void *player, s32 source, void *arg2, s32 arg3) {
    Cmd_801B8870 cmd;
    if (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0 && (player == NULL || ((TObjChara *)player)->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&cmd))->init_6x2A();
        cmd.client = ((TObjBase *)((saddr)player))->get_entity_id();
        cmd.a = source;
        cmd.b = arg3;
        cmd.floor = ((s16 (*)(void))get_current_floor)();
        VecCopy((Vec *)&cmd.pos, (const Vec *)arg2);
        ((TObjPlayer *)(&cmd))->bswap_fields_and_send();
        ((TObjPlayer *)player)->send_unequip_held_item();
    }
}

void handle_6x2A_drop_item(void *command) {
    Msg_801B87E4 m;
    Player_801B87E4 *p;
    ((TObjPlayer *)(&m))->init_6x2A();
    TObjPlayer__sub_801C106C((u8 *)&m, (u8 *)command);
    bswap_fields__10TObjPlayerFi((saddr)&m);
    if (validate_6x2A_drop_item((G_ClientIDHeader *)&m) != 0) {
        p = (Player_801B87E4 *)get_player_by_client_id((u16)m.slot);
        if ((p != NULL) && (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0)) {
            ((TPlyItem *)(p->inv))->update_inventory_item(reinterpret_cast<TObjPlayer *>(p), m.c, reinterpret_cast<f32 *>(m.d), m.a, m.b);
        }
    }
}

void TObjPlayer::drop_items_on_death() {
    PendingItemDrop *record;
    s32 count;
    TItemData* item;
    void* equipped;
    PlayerDeathItemFields* fields=(PlayerDeathItemFields*)this;
    if (fields->inventory_owner==NULL || this->obj_isState3_324()!=0 || is_script_controlled()!=0) {
        return;
    }
    PendingItemDrop records[9];
    count=0;
    if (TTecCtrl::is_technique_ready()!=0) {
        if (TObjPlayer::check_flag_01000000(this) == 0) {
            count=fields->inventory_owner->set_globals_and_notify(this, records);
        }
        if (obj_getPtr2B0_20((u8 *)this)!=0) {
            record=&records[count];
            record->set_source_id(-1);
            item=(TItemData *)get_ptr_8(record);
            ((TObjPlayer *)item)->init_item_data(obj_getPtr2B0_20((u8 *)this));
            count+=1;
            item->id=-1;
        }
    } else if (TObjPlayer::check_flag_01000000(this) == 0) {
        count=fields->inventory_owner->set_globals_and_notify(this, records);
    } else {
        equipped = get_equipped_weapon(this);
        if (equipped!=NULL) {
            TObjPlayer::send_6x26_unequip_item(this, ((TItem *)equipped)->get_item_id());
        }
    }
    if (count>0) {
        lbl_8050BF60.x=fields->position.x;
        lbl_8050BF60.y=TObjPlayer__data_805DC2BC+fields->position.y;
        lbl_8050BF60.z=fields->position.z;
        create_drop_nodes__9TItemListFPvPvPvPvi(&fields->inventory_owner->list, &lbl_8050BF60, this, records, count);
        set_action_flag_2();
    }
}

s32 try_buy_item(saddr player, void *item) {
    if (((TObjPlayer *)player)->can_pickup_item((TItemData *)item) == 0) {
        return 1;
    }
    if (try_spend_actor_meseta(reinterpret_cast<TObjChara *>(player), *(s32 *)((s8 *)item + 0x10) * ((TItemData *)item)->get_stack_count()) != 0) {
        buy_item_for_client((TItemData *)item, ((TObjBase *)(player))->get_entity_id());
        return 0;
    }
    return 2;
}

#pragma push
#pragma opt_propagation off
s32 TObjPlayer::try_add_sale_meseta(s32 arg1, s32 amount, s32 count) {
    s32 max = 999999;
    if (max < ((Player_801B855C *)this)->data->meseta + amount) {
        return 0;
    }
    ((TObjPlayer *)((Player_801B855C *)this))->add_meseta((s32)amount);
    ((void (*)(void *, s32, s32))send_6x29_delete_item__10TObjPlayerFPvii)(((Player_801B855C *)this), arg1, count);
    return 1;
}
#pragma pop

void delete_item(void *player, s32 id, s32 count) { send_6x29_delete_item__10TObjPlayerFPvii(player, id, count); }
}

void TObjPlayer::request_inventory_item(TItemData* item) {
    TObjPlayer* player = this;
    InventoryCreatePacket_801B849C packet;
    if (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0) {
        if ((s32)item->id == -1) {
            item->id = advance_item_id_counter((u16)local_client_id);
        }
        if (player == 0 || ((TObjChara *)player)->obj_isState2_324() == 0) {
            ((TObjPlayer *)(&packet))->init_pkt_6x2B();
            packet.actor = player->get_entity_id();
            ((TItemData *)(&packet.item))->copy_from((TItemData *)(item));
            ((TItemData *)&packet.item)->encode_for_network();
            ((TObjPlayer *)(&packet))->send_cmd_item_data();
        }
    }
}

void handle_6x2B_create_inventory_item(saddr command) {
    Pkt_801B8344 pkt;
    saddr player;
    s32 kind;
    u8 *item;
    ((TObjPlayer *)(&pkt))->init_pkt_6x2B();
    ((TObjPlayer *)(&pkt))->copy((void *)command);
    ((TObjPlayer *)(&pkt))->bswap_cmd_item_data();
    if (validate_6x2B_create_inventory_item((G_ClientIDHeader *)&pkt) != 0) {
        player = (saddr)get_player_by_client_id(pkt.client);
        if ((player != 0) && (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0)) {
            if ((u32)(pkt.size * 4) == 0x18) {
                kind = 0;
                ((TItemData *)pkt.item)->convert_from_version(0);
            } else {
                kind = 2;
                ((TItemData *)pkt.item)->convert_from_version(2);
            }
            ((TItemData *)pkt.item)->decode_from_network();
            item = ((u8 * (*)(s32 *))create_item)((s32 *)pkt.item);
            if ((item != NULL) && (((TObjPlayer *)player)->pickup_item((TItem *)item) != 0U) && (kind == 2) && (pkt.f19 != 0) && (TObjPlayer::get_slot_value((s32 *)(player + 0xD04), ((TItem *)item)->get_attach_slot()) == 0U)) {
                set_equip_slot_entry((saddr)(player + 0xD04), ((TItem *)item)->get_attach_slot(), (saddr)item);
                ((TObjPlayer *)player)->set_flag_20000();
                ((TItem *)item)->equip();
                ((TObjPlayer *)player)->clear_flag_20000();
            }
        }
    }
}

s32 query_state_if_present__10TObjPlayerFPv(TObjPlayer *player, TPlyInventoryItem *out) {
    TPlyItem *inventory = player->inventory_objects;
    if (inventory == NULL) {
        return 0;
    }
    return inventory->run_state_query(out);
}

void TObjPlayer::create_inventory() {
    u8 *object;
    u8 *var_r0_3;
    if ((void *) this->inventory_objects == NULL) {
        this->inventory_objects = new TPlyItem(this);
    }
    this->inventory_objects->pad_1C4 = new TItemList((TObject *)this->inventory_objects);
    object = (u8 *)(((u8 * (*)(s32))__nw__7TObjectFUl)(0x1C));
    var_r0_3 = object;
    if (var_r0_3 != NULL) {
        var_r0_3 = (u8 *)(__ct__7TObjectFP7TObject(object, this));
    }
    *(void **)((s8 *)this->inventory_objects + 0x1C8) = var_r0_3;
    TObjPlayer__sub_801BF8F8((s32 *)(((u8 *)this) + 0xD04));
}

void TObjPlayer::bind_saved_inventory_equipment(TObjPlayer *player, TPlyInventoryItem *records, int count) {
    if (records != NULL) {
        player->set_action_provider_variant((s16)TObjPlayer::default_action_provider_variant());
        for (s32 i = 0; i < count; i++) {
            equip_saved_item_if_slot_empty(player, records);
            ++records;
        }
        if (is_current_area_item_enabled() == 0) {
            player->set_action_provider_variant((s16)TObjPlayer::default_action_provider_variant());
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TObjPlayer::equip_saved_item_if_slot_empty(TObjPlayer *player, TPlyInventoryItem *record) {
    TItem *item = create_item(&record->m_data);
    if (item != NULL && player->pickup_item(item) != 0 && (record->m_flags & 8) &&
        TObjPlayer::get_slot_value(reinterpret_cast<s32 *>(player->equipped_items), item->get_attach_slot()) == 0U) {
        set_equip_slot_entry((saddr)player->equipped_items, item->get_attach_slot(), (saddr)item);
        player->set_flag_20000();
        item->equip();
        player->clear_flag_20000();
    }
}
#pragma pop

void assign_inventory_item_ids(TObjPlayer *player, TPlyInventoryItem *records, s32 count) {
    s32 i;
    u16 client;
    if (records != NULL) {
        client = ((TObjBase *)(player))->get_entity_id();
        for (i = 0; i < count; i++) {
            records->m_data.id = advance_item_id_counter(client);
            ++records;
        }
    }
}

void rebuild_player_inventory(TObjPlayer *player) {
    Buf_801B802C buffer;
    if (player->inventory_objects != NULL) {
        init_inventory_list__10TObjPlayerFPv(&buffer);
        buffer.n = query_state_if_present__10TObjPlayerFPv(player, buffer.items);
        player->inventory_objects->destroy_subobjects(player);
        player->inventory_objects->queue_destruction();
        player->inventory_objects = NULL;
        player->create_inventory();
        assign_inventory_item_ids(player, buffer.items, buffer.n);
        TObjPlayer::bind_saved_inventory_equipment(player, buffer.items, buffer.n);
    }
}

s32 try_send_6x27_use_item(void *player, s32 key) {
    struct S801B7F4C sp8;
    void *temp;
    if (TFontSmallLobby::is_lobby_floor_15() != 0) {
        return 0;
    }
    void *node_4064 = ((TObjPlayer *)player)->inventory_objects->start_inventory_update(key);
    if (node_4064 == 0U) {
        return 0;
    }
    temp = ((void *)((TItemList *)node_4064)->get_owner_if_alive());
    if (temp == NULL) {
        return 0;
    }
    if (((TObjPlayer *)player)->can_use_item(temp) == 0) {
        play_sound_effect(0x3816, 0, 0, 0);
        return 0;
    }
    if ((player != NULL) && (((TObjChara *)player)->obj_isState2_324() != 0)) {
        return 0;
    }
    init_6x27_use_item_cmd((u8 *)&sp8);
    sp8.h = ((TObjBase *)(player))->get_entity_id();
    sp8.w = key;
    ((TObjPlayer *)(&sp8))->send_use_item_cmd();
    return 1;
}

void handle_6x27_use_item(saddr command) {
    Pkt_801B7EB8 pkt;
    u8 *player;
    u8 *owner_if_alive;
    void *node;
    init_6x27_use_item_cmd((u8 *)&pkt);
    ((TObjPlayer *)(&pkt))->copy_field_4((void *)command);
    ((TObjPlayer *)(&pkt))->bswap_cmd_u32();
    if (validate_6x27_use_item((G_ClientIDHeader *)(&pkt)) != 0) {
        player = (u8 *)get_player_by_client_id((u16)pkt.client);
        if ((player != NULL) && ((node = ((TObjPlayer *)player)->inventory_objects->start_inventory_update(pkt.item)) != 0U)) {
            owner_if_alive = (u8 *)((TItemList *)node)->get_owner_if_alive();
            if (owner_if_alive != NULL) {
                ((TItem *)owner_if_alive)->use();
            }
        }
    }
}

void TWindowSubMag::feed_mag(void* p, void* a1, void* a2) { ((int (*)(void*))send_6x28_feed_mag)(p); ((int (*)(void*, void*, void*))send_6x29_delete_item__10TObjPlayerFPvii)(p, a2, (void*)1); }

void send_6x28_feed_mag(void *arg0, s32 arg1, s32 arg2) {
    L_801B7E14 sp8;
    if (arg0 == 0 || ((TObjChara *)arg0)->obj_isState2_324() == 0) {
        TObjPlayer__sub_801C0D7C((u8 *)&sp8);
        sp8.f2 = ((TObjBase *)(arg0))->get_entity_id();
        sp8.f4 = arg1;
        sp8.f8 = arg2;
        ((TObjPlayer *)(&sp8))->bswap_and_send_body_dwords2();
    }
}

void handle_6x28_feed_mag(saddr command) {
    Cmd_801B7D68 cmd;
    u8 *p;
    saddr a;
    saddr b;
    void *node;
    TObjPlayer__sub_801C0D7C((u8 *)&cmd);
    ((TObjPlayer *)(&cmd))->copy_pair_fields2((void *)command);
    ((TObjPlayer *)(&cmd))->bswap_body_dwords2();
    if (validate_6x28_feed_mag((G_ClientIDHeader *)&cmd) != 0) {
        p = (u8 *)get_player_by_client_id((u16)cmd.client);
        if (p != NULL && (node = ((TObjPlayer *)p)->inventory_objects->start_inventory_update(cmd.item_a)) != 0U) {
            a = (saddr)((TItemList *)node)->get_owner_if_alive();
            if (a != 0 && (node = ((TObjPlayer *)p)->inventory_objects->start_inventory_update(cmd.item_b)) != 0U) {
                b = (saddr)((TItemList *)node)->get_owner_if_alive();
                if (b != 0) {
                    feed_item_to_mag((TItem *)a, (TItem *)b);
                }
            }
        }
    }
}

s32 fn_801B7CEC(u8 *player, s8 kind, s8 group, s8 index) {
    TItemData item;
    item.init();
    item.data1.data_u8[0] = kind;
    item.data1.data_u8[1] = group;
    item.data1.data_u8[2] = index;
    void *node_4144 = ((TObjPlayer *)player)->inventory_objects->set_mode_and_refresh_object(&item);
    if (node_4144 == 0U) {
        return -1;
    }
    TItem *owner = (TItem *)((TItemList *)node_4144)->get_owner_if_alive();
    if (owner == NULL) {
        return -1;
    }
    return owner->get_item_id();
}

s32 TObjPlayer::find_inventory_item_id(s8 arg1, s8 arg2) {
    TItemData item;
    item.init();
    item.data1.data_u8[0] = arg1;
    item.data1.data_u8[1] = arg2;
    TItemList *node = inventory_objects->find_first_inventory_entry(&item);
    if (node == 0U) {
        return -1;
    }
    TItem *owner = (TItem *)((TItemList *)node)->get_owner_if_alive();
    if (owner == NULL) {
        return -1;
    }
    return owner->get_item_id();
}

s32 TWindowSubItem::is_usable(saddr player) {
    if ((((TObjPlayer *)player)->is_action_active() != 0U) || (((TObjPlayer *)player)->test_action_mask(0x43001E) == 0) || (((TObjCollidable *)player)->test_actor_flags(0x20) != 0) || (((TObjPlayer *)player)->check_player_flag1() != 0)) {
        return 0;
    }
    return 1;
}

s32 can_destroy_with_parents__10TObjPlayerFUi(uaddr arg0) {
    if ((arg0 != 0U) && (((TObject *)arg0)->all_parents_unqueued_for_destruction() != 0)) {
        return 1;
    }
    return 0;
}

void TObjPlayer__sub_801B7B58(P_801B7B58 *player, s32 key, s32 arg2) {
    if (TObjPlayer::is_locally_controlled(player) == 0) {
        return;
    }
    if (key == -1 || arg2 == -1) {
        return;
    }
    if (player->fD00 != 0) {
        TObjPlayer__sub_801D47EC((TPlyItem *)player->fD00, key, arg2);
    }
}

void handle_6x98(void) {  }

void TObjPlayer::close_sub_window() {
    void *p;
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        p = this->inventory_objects;
        if (p != 0) {
            TObjPlayer__sub_801D4368((TPlyItem *)p);
        }
    }
}

void handle_6x99(void) {  }

CsnHit *TObjPlayer::update_actor_ground_y() {
    return update_actor_ground_y_at(get_position_ptr());
}

CsnHit *TObjPlayer::update_actor_ground_y_at(Vec *pos) {
    Vec stack;
    f32 y;
    s32 temp_r31;
    CsnHit *hit;
    stack.x = pos->x;
    y = pos->y;
    stack.y = y + stat_block->proportions;
    stack.z = pos->z;
    hit = csnVectorUnder(&stack, ground_candidates.groups, 0x5F);
    if (hit == NULL) {
        return NULL;
    }
    contact_surface.clear_surface();
    temp_r31 = hit->hit_mask;
    if (temp_r31 & 0x10) {
        contact_surface.check_flag_2();
        copy_vec_at_18__10TObjPlayerFv((u8 *)&follow_particles, &hit->contact[1].point);
    }
    if ((temp_r31 & 4) && (player_auxiliary_surfaces_enabled() != 0)) {
        contact_surface.set_flag_4();
        TObjPlayer__sub_801BF3A0((u8 *)&follow_particles, &hit->contact[2].point);
    }
    if ((temp_r31 & 2) && (player_auxiliary_surfaces_enabled() != 0)) {
        contact_surface.set_sand();
        TObjPlayer__sub_801BF3A0((u8 *)&follow_particles, &hit->contact[3].point);
    }
    if (temp_r31 & 8) {
        this->contact_surface.test_flag_16();
    }
    if (!(temp_r31 & 1)) {
        return NULL;
    }
    position.y = hit->contact[0].point.y;
    VecCopy(&ground_normal, &hit->contact[0].normal);
    return hit;
}

#pragma push
#pragma fp_contract on
#pragma scheduling off
void calc_wall_slide_point(const Vec *movement, const Vec *normal, Vec *out) {
    f32 component = -vec3_dot(movement, normal);
    out->x = component * normal->x + movement->x;
    out->y = component * normal->y + movement->y;
    out->z = component * normal->z + movement->z;
}
#pragma pop

void calc_move_velocity(const Vec *direction, Vec *out, f32 speed) {
    s32 angle = (s32)(10430.38043493439 * atan2_float(direction->x, direction->z));
    out->x = speed * sin_table_lookup(angle);
    out->y = TObjPlayer__data_805DC278;
    out->z = speed * cos_table_lookup(angle);
}

void calc_move(const Vec *movement, const Vec *direction, Vec *out) {
    calc_move_velocity(direction, out, vector_length(movement));
}

// Pushes the move in velocity off the walls it runs into: slides it along a
// wall it meets at a shallow angle, steps around a corner. Returns the wall
// contact that stops it, NULL when the move may go on.
CsnHit *TObjPlayer::apply_wall_response() {
    if (is_single_screen()) {
        s32 angle;
        f32 dx;
        f32 dz;
        f32 reach;
        f32 speed;
        Vec from;
        Vec to;
        angle = (s32)(10430.38043493439 * atan2_float(velocity.x, velocity.z));
        speed = vector_length(&velocity);
        reach = speed + TObjPlayer__sub_8017A1A4(this, 0);
        dx = reach * sin_table_lookup(angle);
        dz = reach * cos_table_lookup(angle);
        from.x = position.x;
        from.y = lbl_805DC2B0 + position.y;
        from.z = position.z;
        to.x = from.x + dx;
        to.y = from.y;
        to.z = from.z + dz;
        return csnVector(&from, &to, 0x28A0);
    }

    s32 ray;
    s32 angle;
    Vec *normal;
    WallRayResult *blocked;
    Vec *offset;
    s32 i;
    f32 radius = TObjPlayer__sub_8017A1A4(this, 0);
    Vec move;
    WallRayQuery query;
    Vec rays[8];
    VecCopy(&move, &velocity);
    move.y = TObjPlayer__data_805DC278;
    Vec *origin = &query.origin;
    f32 reach = radius + vector_length(&move);
    query.count = 1;
    query.mask = 0x28A0;
    origin->x = position.x;
    origin->y = lbl_805DC2B0 + position.y;
    origin->z = position.z;
    query.rays = rays;
    angle = (s32)(10430.38043493439 * atan2_float(move.x, move.z));
    rays[0].x = reach * sin_table_lookup(angle);
    rays[0].y = TObjPlayer__data_805DC278;
    rays[0].z = reach * cos_table_lookup(angle);
    query.radius = lbl_805DC2B4 + reach;
    blocked = query_wall_radial(&query);
    Vec dir;
    if (blocked != NULL) {
        ray = blocked->index;
        normal = &blocked->header.contact[ray].normal;
        VecCopy(&dir, &move);
        normalize_vector_safe(&dir);
        if (vec3_dot(&dir, normal) > lbl_805DC2B8) {
            Vec end;
            Vec slide;
            Vec step;
            Vec *hit_ray = &query.rays[ray];
            end.x = origin->x + hit_ray->x;
            end.y = origin->y + hit_ray->y;
            end.z = origin->z + hit_ray->z;
            vsub(&blocked->header.contact->point, &end, &dir);
            calc_wall_slide_point(&dir, normal, &slide);
            vsub(origin, &move_target, &dir);
            dir.y = TObjPlayer__data_805DC278;
            calc_move(&dir, &slide, &step);
            move_target.x = position.x + step.x;
            move_target.z = position.z + step.z;
            calc_move(&velocity, &slide, &step);
            VecCopy(&velocity, &step);
            blocked = NULL;
        }
    }

    VecCopy(&move, &velocity);
    query.radius = radius;
    query.count = 8;
    origin->x = position.x + move.x;
    origin->z = position.z + move.z;
    offset = rays;
    for (i = 0; i < 8; i++) {
        offset->x = radius * sin_table_lookup(angle);
        offset->y = TObjPlayer__data_805DC278;
        offset->z = radius * cos_table_lookup(angle);
        angle += 0x2000;
        offset++;
    }
    WallRayResult *wall = query_prepared_wall_polygons(&query);
    if (wall != NULL) {
        ray = wall->index;
        normal = &wall->header.contact[ray].normal;
        VecCopy(&dir, &move);
        normalize_vector_safe(&dir);
        f32 facing = vec3_dot(&dir, normal);
        if (facing <= lbl_805DC2B8) {
            blocked = wall;
        } else if (facing > TObjPlayer__data_805DC278) {
            blocked = NULL;
        } else {
            f32 push = lbl_805DC298 + wall->depth;
            Vec *wall_normal = &wall->header.contact[ray].normal;
            f32 px = wall_normal->x * push;
            f32 pz = wall_normal->z * push;
            Vec corner;
            corner.x = origin->x + px;
            corner.y = origin->y;
            corner.z = origin->z + pz;
            s32 target = calc_angle_to(&corner, &move_target);
            angle = lerp_angle_half(approach_angle_adaptive(rotation_y, target), target);
            move.x = move_speed.get_speed() * sin_table_lookup(angle);
            move.y = TObjPlayer__data_805DC278;
            move.z = move_speed.get_speed() * cos_table_lookup(angle);
            origin->x = corner.x + move.x;
            origin->z = corner.z + move.z;
            Vec first_ray;
            VecCopy(&first_ray, &query.rays[ray]);
            angle = (s32)(10430.38043493439 * atan2_float(move.x, move.z));
            offset = rays;
            for (i = 0; i < 8; i++) {
                offset->x = radius * sin_table_lookup(angle);
                offset->y = TObjPlayer__data_805DC278;
                offset->z = radius * cos_table_lookup(angle);
                angle += 0x2000;
                offset++;
            }
            WallRayResult *next = query_prepared_wall_polygons(&query);
            if (next == NULL) {
                blocked = NULL;
                position.x += px;
                position.z += pz;
            } else {
                Vec next_ray;
                VecCopy(&next_ray, &query.rays[next->index]);
                move.x = -velocity.z;
                move.z = velocity.x;
                f32 side = vec3_dot(&move, &first_ray);
                if (side * vec3_dot(&move, &next_ray) >= TObjPlayer__data_805DC278) {
                    blocked = NULL;
                    position.x += px;
                    position.z += pz;
                } else {
                    blocked = wall;
                }
            }
        }
    }
    return reinterpret_cast<CsnHit *>(blocked);
}

void TObjPlayer::get_hand_joint_position(saddr arg1) {
    this->get_anim_node_position(*(s32 *)(get_cast_motion_record() + 0x10), (Vec *)arg1);
}

void TObjPlayer::init_effect_5f0() {
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    anim_state.set_action_id(0x10);
    anim_state.set_animation(this->get_idle_animation());
    anim_state.set_state(0);
    anim_state.set_angle(this->rotation_y);
}

void TObjPlayer::clear_lobby_flag(void *base) {
    if ((s32) lbl_805D55C0 == 0) {
        ((TObjBase *)base)->clear_actor_flags((u32)0x10000);
    }
}

void TObjPlayer::update_position_history() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;

    if ((*(f32 *)((s8 *)arg0 + 0x44) != *(f32 *)((s8 *)arg0 + 0x38)) || (*(f32 *)((s8 *)arg0 + 0x4C) != *(f32 *)((s8 *)arg0 + 0x40))) {
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x6AC) + 1;
        *(s32 *)((s8 *)arg0 + 0x6AC) = temp_r0;
        if (temp_r0 >= 0x10) {
            *(s32 *)((s8 *)arg0 + 0x6AC) = 0;
        }
        this->set_position_history_entry(*(s32 *)((s8 *)arg0 + 0x6AC), *(f32 *)((s8 *)arg0 + 0x38), *(f32 *)((s8 *)arg0 + 0x40));
    }
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)&this->position);
    this->contact_surface.update_field8();
}

void TObjPlayer::update_status_effects() {
    u8 *arg0 = (u8 *)this;
  update_player_appear_fade(((u8 *)&this->m_634));
  update_target_lock();
  if ((this->is_actor_cadence_frame(3)) != 0)
  {
    if (this->check_flag_02000000() == 0)
    {
      get_current_floor_area();
      *((s16 *) (((s8 *) arg0) + 0x28)) = TScene::find_player_section(((TObjBase *)(arg0))->get_entity_id());
    }
  }
  this->clear_flag_2000000();
  (this->vfunc_43());
  (this->update_poison_status());
  (this->update_action_hold_status());
  (this->update_slow_status());
  (this->update_flag30_timer());
  (this->update_movement_status());
  (this->update_shock_clock());
  (this->update_attack_stat_status());
  (this->update_defense_stat_status());
  if (this->protection.get_frames() <= 0)
  {
    this->clear_actor_flags((u32)(0x04000100));
  }
  else
  {
    TObjPlayer::decrement_clamp((s32 *)(arg0 + 0x644), 1);
    set_actor_flags(0x04000000);
  }
  if ((this->hp) <= 0)
  {
    set_actor_flags(0xA00);
  }
  this->contact_surface.update_timer();
}

void TObjPlayer::check_level_up() {
    struct Buf1C sp40;
    struct Buf1C sp24;
    struct Buf1C sp8;
    s32 i;
    u8 *temp_r31;
    s32 j;
    s32 lvl;
    u8 *temp_r30_2;
    if ((TObjPlayer::is_locally_controlled(this) != 0) && (is_current_area_item_enabled() != 0)) {
        lvl = this->clamp_nested_index() + 1;
        if (lvl <= TObjPlayer::get_max_level()) {
            if (TObjPlayer::get_current_state_field(get_class_index__10TObjPlayerFv(reinterpret_cast<u8 *>(this)), lvl) <= (s32) this->stat_block->exp) {
                ((TObjPlayer *)(&sp40))->reset_sub_status_disp();
                ((TObjPlayer *)(&sp24))->reset_sub_status_disp();
                ((TObjPlayer *)(&sp8))->reset_sub_status_disp();
                j = 0;
                do {
                    temp_r31 = (u8 *)TObjPlayer::get_slot_value((s32 *)this->equipped_items, j);
                    if ((((s32 (*)(void))can_destroy_with_parents__10TObjPlayerFUi)() != 0) && (is_item_equipped((TItem *)temp_r31) != 0)) {
                        ((TItem *)temp_r31)->remove_equip_stats(1);
                    }
                    j += 1;
                } while (j < 0xD);
                init_shield_params(&sp40, (u8 *)this, this->stat_block, this->attack_params, param_block);
                this->apply_exp_level_growth();
                init_shield_params(&sp24, (u8 *)this, this->stat_block, this->attack_params, param_block);
                i = 0;
                do {
                    temp_r30_2 = (u8 *)TObjPlayer::get_slot_value((s32 *)this->equipped_items, i);
                    if ((((s32 (*)(void))can_destroy_with_parents__10TObjPlayerFUi)() != 0) && (is_item_equipped((TItem *)temp_r30_2) != 0)) {
                        ((TItem *)temp_r30_2)->add_equip_stats(1);
                    }
                    i += 1;
                } while (i < 0xD);
                ((TObjPlayer *)(&sp40))->calc_pos_delta(&sp24, &sp8);
                TWindowCtrl::create_level_up_window((saddr)&sp8, ((TObjBase *)this)->get_entity_id());
                send_6x30_change_player_level((Player_801B6C30 *)((struct Player_801B6C30 *) ((u8 *)this)));
            }
        }
    }
}

s32 TObjPlayer::apply_exp_level_growth() {
    s32 i;
    s32 lvl;
    s32 cls;
    PlayerLevelTableRow *e;
    cls = reinterpret_cast<s8 (*)(TObjPlayer *)>(get_class_index__10TObjPlayerFv)(this);
    lvl = clamp_nested_index() + 1;
    for (i = 0; i < TObjPlayer::get_max_level(); i++) {
        if (lvl > TObjPlayer::get_max_level()) {
            break;
        }
        e = get_ply_level_table_row(cls, lvl);
        if (e == NULL) {
            break;
        }
        if (get_level_row_exp_threshold(e) > stat_block->exp) {
            break;
        }
        add_stat(get_char_class__10TObjPlayerFv(e));
        add_mst(get_team_id__10TObjPlayerFv(e));
        add_evp(get_byte_2(e));
        add_hp(get_byte_3(e));
        add_dfp(get_byte_4__10TObjPlayerFv(e));
        add_ata(get_field_5__10TObjPlayerFv(e));
        stat_block->level = lvl;
        lvl++;
    }
    return 1;
}

void send_6x30_change_player_level(Player_801B6C30 *arg0) {
    Msg_801B6C30 m;
    Src_801B6C30 *s;
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) && ((arg0 == NULL) || (((TObjChara *)arg0)->obj_isState2_324() == 0))) {
        ((TObjPlayer *)(&m))->build_6x30_change_level_packet();
        m.f2 = ((s16)((TObjBase *)(arg0))->get_entity_id());
        s = arg0->src;
        m.f4[0] = s->v[0];
        m.f4[1] = s->v[1];
        m.f4[2] = s->v[2];
        m.f4[3] = s->v[3];
        m.f4[4] = s->v[4];
        m.f4[5] = s->v[5];
        m.f10 = ((TObjPlayer *)arg0)->clamp_nested_index();
        m.f12 = 0;
        ((TObjPlayer *)(&m))->send_swapped_packet_6x30();
    }
}

void *TObjPlayer::copy_fields(void *command) {
    copy_subcommand_header();
    this->m_flags = (s16) *(s16 *)((s8 *)command + 4);
    this->m_id = (s16) *(s16 *)((s8 *)command + 6);
    *(s16 *)((s8 *)this + 8) = (s16) *(s16 *)((s8 *)command + 8);
    *(s16 *)((s8 *)this + 0xA) = (s16) *(s16 *)((s8 *)command + 0xA);
    *(s16 *)((s8 *)this + 0xC) = (s16) *(s16 *)((s8 *)command + 0xC);
    *(s16 *)((s8 *)this + 0xE) = (s16) *(s16 *)((s8 *)command + 0xE);
    *(s16 *)((s8 *)this + 0x10) = (s16) *(s16 *)((s8 *)command + 0x10);
    *(s16 *)((s8 *)this + 0x12) = (s16) *(s16 *)((s8 *)command + 0x12);
    return this;
}

void handle_6x30_change_player_level(void *command) {
    Pkt_801B6A5C pkt;
    Plr_801B6A5C *p;
    f32 f;
    ((TObjPlayer *)(&pkt))->build_6x30_change_level_packet();
    ((TObjPlayer *)(&pkt))->copy_fields(command);
    swap_endian__10TObjPlayerFi((saddr)&pkt);
    if (validate_6x30_change_player_level((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    p = (Plr_801B6A5C *)get_player_by_client_id((u16)pkt.id);
    if (p == NULL) {
        return;
    }
    if (((s32 (*)(Plr_801B6A5C *))reset_volopt_state__10TObjPlayerFv)(p) == 0) {
        return;
    }
    p->stats->st[0] = pkt.st[0];
    p->stats->st[1] = pkt.st[1];
    p->stats->st[2] = pkt.st[2];
    p->stats->st[3] = pkt.st[3];
    p->stats->st[4] = pkt.st[4];
    p->stats->st[5] = pkt.st[5];
    p->stats->exp = pkt.exp;
    f = ((TObjPlayer *)p)->get_tp_class_factor();
    ((TObjChara *)p)->recalc_combat_stats((player_stats *)((saddr)p->stats), NULL, NULL, (f32)(((TObjPlayer *)p)->get_class_hp_factor()), (f32)f);
    p->a2 = p->a;
    p->b2 = p->b;
    if (((TObjPlayer *)p)->is_alive_and_ready() != 0) {
        ((TObjPlayer *)p)->refill_traps();
    }
    if (((TObjPlayer *)p)->check_flag_4() == 0) {
        if (pkt.kind == 1) {
            ((TObjPlayer *)p)->spawn_level_change_feedback("Level Down");
        } else {
            ((TObjPlayer *)p)->spawn_level_change_feedback("Level Up");
        }
    }
}

void TObjPlayer::spawn_level_change_feedback(const char *message) {
    notify_volopt_if_ready(this);
    new TFontSmallHelp(get_entity_id(), -1, 0x3C, (uaddr)message);
    new_child_object(get_entity_id());
    scratch_vec[0].x = TObjPlayer__data_805DC278;
    scratch_vec[0].y = lbl_805DC2A0;
    scratch_vec[0].z = TObjPlayer__data_805DC278;
    player_feedback_light_color[0].g = player_feedback_light_color[0].r = TObjPlayer__data_805DC294;
    player_feedback_light_color[0].b = lbl_805DC2A4;
    player_feedback_light_color[0].a = lbl_805DC2A8;
    new TActorLight(lbl_805DC2AC, (NJS_ARGB *)player_feedback_light_color, scratch_vec, 10, this, tl_07);
    publish_actor_light_scalars(get_entity_id(), TObjPlayer__data_805DC294, TObjPlayer__data_805DC28C);
}

void TObjPlayer::notify_volopt_if_ready(void* p) { if (TObjPlayer::is_locally_controlled(p) != 0) { ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)335646, (void*)0, (void*)0, (void*)0); } }

#pragma push
#pragma scheduling off
void copy_stats__10TObjPlayerFPv(stats *out, const stats *source) {
    out->atp = source->atp;
    out->mst = source->mst;
    out->evp = source->evp;
    out->hp = source->hp;
    out->dfp = source->dfp;
    out->ata = source->ata;
    out->lck = source->lck;
}
#pragma pop

// Base stats of the class plus the growth of every level row up to `level`, each clamped to the class caps.
void apply_class_level_growth(s32 cls, s32 level, stats *st) {
    s32 n;
    s32 i;
    PlayerLevelTableRow *row;
    const player_stats *caps;

    n = TObjPlayer::clamp_index_to_max(level);
    copy_stats__10TObjPlayerFPv(st, get_class_base_stats(cls));
    row = get_ply_level_table_row(cls, 0);
    if (row != NULL) {
        caps = get_class_stat_caps(cls);
        for (i = 0; i < n; i++) {
            ++row;
            TObjPlayer::add_stat_clamped(get_char_class__10TObjPlayerFv(row), &st->atp, caps->stats.atp);
            TObjPlayer::add_stat_clamped(get_team_id__10TObjPlayerFv(row), &st->mst, caps->stats.mst);
            TObjPlayer::add_stat_clamped(get_byte_2(row), &st->evp, caps->stats.evp);
            TObjPlayer::add_stat_clamped(get_byte_3(row), &st->hp, caps->stats.hp);
            TObjPlayer::add_stat_clamped(get_byte_4__10TObjPlayerFv(row), &st->dfp, caps->stats.dfp);
            TObjPlayer::add_stat_clamped(get_field_5__10TObjPlayerFv(row), &st->ata, caps->stats.ata);
        }
    }
}

// Battle rule "level": rebuilds the stats as the class base plus the growth of every level row up to
// `level`, then puts back the equipment the new stats still allow (units last, and only over an armor).
void TObjPlayer::apply_battle_level_reset(s32 level) {
    level = clamp_index_to_max(level);

    Unk_801B67C4 saved[9];
    s16 result;
    s32 i;

    Unk_801B67C4 *e = saved;
    for (i = 0; i < 13; i++) {
        TItem *item = get_equipped_item(i);
        if (item != NULL) {
            e->slot = item->get_attach_slot();
            e->item = item;
            e++;
        }
    }
    inventory_objects->set_flag_and_update(this);
    s32 cls = get_class_index__10TObjPlayerFv(reinterpret_cast<u8 *>(this));
    stats *base = get_class_base_stats(cls);
    stat_block->stats.atp = base->atp;
    stat_block->stats.mst = base->mst;
    stat_block->stats.evp = base->evp;
    stat_block->stats.hp = base->hp;
    stat_block->stats.dfp = base->dfp;
    stat_block->stats.ata = base->ata;
    stat_block->stats.lck = base->lck;
    PlayerLevelTableRow *row = get_ply_level_table_row(cls, 0);
    if (row != 0) {
        const player_stats *caps = get_class_stat_caps(cls);
        for (i = 0; i < level; i++) {
            ++row;
            add_stat_clamped(get_char_class__10TObjPlayerFv(row), &stat_block->stats.atp, caps->stats.atp);
            add_stat_clamped(get_team_id__10TObjPlayerFv(row), &stat_block->stats.mst, caps->stats.mst);
            add_stat_clamped(get_byte_2(row), &stat_block->stats.evp, caps->stats.evp);
            add_stat_clamped(get_byte_3(row), &stat_block->stats.hp, caps->stats.hp);
            add_stat_clamped(get_byte_4__10TObjPlayerFv(row), &stat_block->stats.dfp, caps->stats.dfp);
            add_stat_clamped(get_field_5__10TObjPlayerFv(row), &stat_block->stats.ata, caps->stats.ata);
        }
    }
    stat_block->level = level;
    stat_block->mbr_0xe = 40;
    stat_block->exp = get_current_state_field(cls, level);
    stat_block->meseta = 300;
    f32 tp_factor = get_tp_class_factor();
    recalc_combat_stats(NULL, NULL, NULL, get_class_hp_factor(), tp_factor);
    hp = hpmax;
    tp = tpmax;
    set_flag_20000();
    Unk_801B67C4 *p = saved;
    for (s32 i = 0; i < 9; i++, p++) {
        TItem *item = p->item;
        if (item == NULL) {
            break;
        }
        if (!item->is_unit() && item->check_equip_requirements(this, &result)) {
            equip_item_to_slot(item, p->slot);
        }
    }
    Unk_801B67C4 *q = saved;
    for (s32 i = 0; i < 9; i++, q++) {
        TItem *item = q->item;
        if (item == NULL) {
            break;
        }
        if (item->is_unit() && item->check_equip_requirements(this, &result) && (TItem *)((TItemData *)this)->get_item_field_2() != NULL) {
            equip_item_to_slot(item, q->slot);
        }
    }
    clear_flag_20000();
}

void TObjPlayer::update_aim_angle(s32 aim) {
    s32 class_state_field;

    class_state_field = this->get_class_state_field(TObjPlayer::clamp_index_to_max(aim + get_actor_level_index()));
    add_actor_exp(class_state_field - this->obj_getPtr2B0_1C());
}

void TObjPlayer::recalc_stats() {
    f32 tp_class_factor;
    f32 xscale;

    tp_class_factor = this->get_tp_class_factor();
    xscale = this->get_class_hp_factor();
    this->recalc_combat_stats(NULL, NULL, NULL, (f32)xscale, (f32)tp_class_factor);
    this->clamp_hp();
    this->clamp_tp();
}

s16 TObjPlayer::add_stat(s32 amount) {
    return add_stat_clamped(amount, (s16 *)(*(saddr *)((s8 *)this + 0x2B0)), (s16)(*((s16 *)TObjPlayer::get_class_stat_entry((u8 *)this))));
}

s16 TObjPlayer::add_dfp(s32 amount) {
    return add_stat_clamped(amount, (s16 *)(*(saddr *)((s8 *)this + 0x2B0) + 8), (s16)(*(s16 *)((s8 *)(((s16 *)TObjPlayer::get_class_stat_entry((u8 *)this))) + 8)));
}

s16 TObjPlayer::add_hp(s32 amount) {
    return add_stat_clamped(amount, (s16 *)(*(saddr *)((s8 *)this + 0x2B0) + 6), (s16)(*(s16 *)((s8 *)(((s16 *)TObjPlayer::get_class_stat_entry((u8 *)this))) + 6)));
}

s16 TObjPlayer::add_mst(s32 amount) {
    return add_stat_clamped(amount, (s16 *)(*(saddr *)((s8 *)this + 0x2B0) + 2), (s16)(*(s16 *)((s8 *)(((s16 *)TObjPlayer::get_class_stat_entry((u8 *)this))) + 2)));
}

s16 TObjPlayer::add_ata(s32 amount) {
    return add_stat_clamped(amount, (s16 *)(*(saddr *)((s8 *)this + 0x2B0) + 0xA), (s16)(*(s16 *)((s8 *)(((s16 *)TObjPlayer::get_class_stat_entry((u8 *)this))) + 0xA)));
}

s16 TObjPlayer::add_evp(s32 amount) {
    return add_stat_clamped(amount, (s16 *)(*(saddr *)((s8 *)this + 0x2B0) + 4), (s16)(*(s16 *)((s8 *)(((s16 *)TObjPlayer::get_class_stat_entry((u8 *)this))) + 4)));
}

s16 TObjPlayer::add_lck(s32 amount) {
    return add_stat_clamped(amount, (s16 *)(*(saddr *)((s8 *)this + 0x2B0) + 0xC), (s16)(*(s16 *)((s8 *)(((s16 *)TObjPlayer::get_class_stat_entry((u8 *)this))) + 0xC)));
}

s16 TObjPlayer::add_stat_clamped(s32 amount, s16 *arg1, s16 arg2) {
    s16 temp_r3;
    s16 var_r6;

    var_r6 = 0;
    *arg1 += amount;
    temp_r3 = *arg1;
    if (temp_r3 < 0) {
        *arg1 = 0;
    } else {
        var_r6 = temp_r3 - arg2;
        if (var_r6 > 0) {
            *arg1 = arg2;
        }
    }
    return var_r6;
}

void handle_6x2E_set_or_clear_player_flags(void *command) {
    Msg_801B6110 m;
    Player_801B6110 *p;
    TObjPlayer__sub_801C0C04((u8 *)&m);
    ((TObjPlayer *)(&m))->copy_pair_fields(command);
    ((TObjPlayer *)(&m))->bswap_body_dwords();
    if (validate_6x2E_set_or_clear_player_flags((G_ClientIDHeader *)&m) != 0) {
        p = (Player_801B6110 *)get_player_by_client_id(m.slot);
        if (p != NULL) {
            p->flags = p->flags & m.andMask;
            p->flags = p->flags | m.orMask;
        }
    }
}

s32 TObjPlayer::is_matching_id(s16 arg1) {
    if ((this->is_flag_b0_4() != 0) && (arg1 == (s16) this->previous_action)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::rewind_position_history() {
    Stack_801B6024 stack;
    s32 temp_r0;
    u8 *temp_r3;
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x6AC) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x6AC) = temp_r0;
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)((u8 *)this) + 0x6AC) = 0xF;
    }
    get_position_history_entry(*(s32 *)((s8 *)((u8 *)this) + 0x6AC), &stack.sp8, &stack.sp10);
    stack.spC = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
    temp_r3 = (u8 *)csnVectorUnder((Vec *)&stack.sp8, this->ground_candidates.groups, 0x41);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)((u8 *)this) + 0x38) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 4)) + 0);
        *(f32 *)((s8 *)((u8 *)this) + 0x3C) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 4)) + 4);
        *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 4)) + 8);
    }
}

void damp_planar_velocity(P_801B5FB0 *p) {
    if (p->a < lbl_805DC298 && p->a > lbl_805DC29C) {
        p->a = TObjPlayer__data_805DC278;
    } else {
        p->a *= (*(const f32 *)&TObjPlayer__data_805DC28C);
    }
    if (p->b < lbl_805DC298 && p->b > lbl_805DC29C) {
        p->b = TObjPlayer__data_805DC278;
    } else {
        p->b *= (*(const f32 *)&TObjPlayer__data_805DC28C);
    }
}

saddr TObjPlayer::resolve_move_collision() {
    Vec p;
    p.x = position.x + velocity.x;
    p.y = position.y + velocity.y;
    p.z = position.z + velocity.z;
    if (this->update_actor_ground_y_at(&p) == 0U) {
        clear_velocity((u8 *)this);
        return 1;
    }
    if (apply_wall_response() != 0U) {
        clear_velocity((u8 *)this);
        return 2;
    }
    if ((TObjPlayer__sub_801BE8F4(this, 0, 0x380000) != 0) && (TObjPlayer__sub_801BE8F4(this, 0, 0x01C00000) != 0)) {
        clear_velocity((u8 *)this);
        return 4;
    }
    if (is_outside_movement_hold(&p.x) != 0) {
        clear_velocity((u8 *)this);
        return 3;
    }
    return 0;
}

s32 TObjPlayer::check_actor_blocking_move() {
    Vec pos;
    Vec diff;
    CollisionBody hit;
    pos.x = position.x + velocity.x;
    pos.y = TObjPlayer__data_805DC278;
    pos.z = position.z + velocity.z;
    if (test_player_overlap_with_players(this, this, &pos, &hit) != 0) {
        if (hit.flags & 0x100) {
            return 0;
        }
        diff.x = pos.x - hit.center.x;
        diff.y = TObjPlayer__data_805DC278;
        diff.z = pos.z - hit.center.z;
        if (vec3_dot(&diff, &velocity) < TObjPlayer__data_805DC278) {
            return 1;
        }
    }
    return 0;
}

void TObjPlayer::update_ground_contact() {
    saddr arg0 = (saddr)this;
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        if (pad_binding.is_button_held(fn_8002AE08(((TObjBase *)(arg0))->get_entity_id())) != 0) {
            set_primary_action_palette_bank(arg0 + 0x500);
            if (this->photon_blast_gauge.has_ready_flag() != 0) {
                set_secondary_action_palette_bank(arg0 + 0x500);
            }
        } else {
            clear_primary_action_palette_bank(arg0 + 0x500);
            if (this->photon_blast_gauge.has_ready_flag() != 0) {
                clear_secondary_action_palette_bank(arg0 + 0x500);
            }
        }
        TObjPlayer::refresh_party_cursors(arg0);
    }
}

void TObjPlayer::select_contextual_pickup_action() {
    s32 type;
    TMainCursor *cursor;
    saddr ent;
    TLockOnCursor *obj;
    obj = this->lock_on_cursor;
    if (obj != NULL) {
        cursor = (TMainCursor *)&obj->selection.target;
        type = 0;
        if (cursor->get_id() != 0xFFFF) {
            ent = ((s32 (*)(u16))find_entity_by_id)(cursor->get_id());
            if (ent != 0) {
                type = ((TObjCollidable *)ent)->get_cursor_action();
                if (type != 0) {
                    switch (type) {
                    case 4:
                        if (test_action_mask(0xE0) != 0) {
                            type = 0;
                        } else {
                            TItem *item = (TItem *)find_entity_by_id(cursor->get_id());
                            if (this->can_pickup_item_by_id(item) != 0) {
                                if ((((s32 (*)(void *))is_flag_400_set__10TObjPlayerFPv)(this)) != 0) {
                                    ((s32 (*)(void *, s32))get_field_340__18TChallenge4PResultFPv)(this, 1);
                                }
                            } else {
                                type = 0;
                                if (is_controls_locked() == 0 && pad_binding.is_button_pressed(4) != 0) {
                                    play_sound_effect(0x3816, ((TObjPlayer *)ent)->get_position_ptr(), 0, 1);
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        if (type == 0 && (((s32 (*)(void *))is_flag_400_set__10TObjPlayerFPv)(this)) != 0) {
            type = 2;
        }
        ((void (*)(void *, s32, s32, s32, u16))TObjPlayer__sub_801B5A44)(this, 0, 0, 0, type);
        ((void (*)(void *, s32, s32, s32, u16))TObjPlayer__sub_801B5A44)(this, 0, 1, 0, type);
    }
}

saddr TObjPlayer::refresh_effect() {
    saddr arg0 = (saddr)this;
    if (this->photon_blast_gauge.has_ready_flag() != 0) {
        if (test_photon_blast_modifier(arg0 + 0x500) != 0) {
            return ref_primary_action_palette(arg0 + 0x500);
        }
        return ref_secondary_action_palette(arg0 + 0x500);
    }
    return ref_primary_action_palette(arg0 + 0x500);
}

TPlyDispConfigSmth *TObjPlayer::select_action_palette(int secondary) {
    if (secondary == 1) {
        return (TPlyDispConfigSmth *)ref_secondary_action_palette((saddr)&action_palettes);
    }
    return (TPlyDispConfigSmth *)ref_primary_action_palette((saddr)&action_palettes);
}
extern "C" {
#pragma push
#pragma fp_contract on
void TObjPlayer__sub_801B5AF8(saddr player, s32 index) {
    TWindowActionPalette::get_slot_type_for_index((s32 *)(((TObjPlayer *)player)->refresh_effect()), (s32)index);
}
#pragma pop
#pragma push
#pragma fp_contract on
s32 TObjPlayer::get_action_palette_entry(s32 index) {
    return get_entry_by_index__20TWindowActionPaletteFPll(this->refresh_effect(), index);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer::select_action_palette_and_apply(s32 secondary, s32 arg2, s32 arg3) {
    TWindowActionPalette__sub_801C1D7C((saddr)this->select_action_palette(secondary), arg2, arg3);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer__sub_801B5A44(saddr player, s32 secondary, s32 i, s32 arg3, s32 arg4) {
    TWindowActionPalette::set_slot_by_index((saddr)((TObjPlayer*)player)->select_action_palette(secondary), i, arg3, arg4);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer::set_action_palette_entry(s32 secondary, s32 valid, s32 idx, s32 arg4, s32 arg5) {
    TWindowActionPalette::set_palette_entry((saddr)this->select_action_palette(secondary), valid, idx, arg4, arg5);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjPlayer::refresh_party_cursors(saddr arg0) {
    TObjPlayer::update_party_cursors(((TObjPlayer *)arg0)->refresh_effect(), arg0);
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjPlayer::is_effect_channel_active(saddr player, s32 index) {
    return is_action_channel_active(((TObjPlayer *)player)->refresh_effect(), index);
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjPlayer::is_action_channel_available(s32 arg1) {
    if (arg1 == 1) {
        if (((s32 (*)(void))is_flag_400_set__10TObjPlayerFPv)() != 0) {
            return 1;
        }
        if (this->has_action_palette_entry() != 0) {
            return 1;
        }
        goto block_5;
    }
block_5:
    return is_action_channel_active(this->refresh_effect(), arg1);
}
#pragma pop

s32 TObjPlayer::has_action_palette_entry() {
    if ((this->lock_on_cursor != NULL) && (((u16)get_action_palette_entry(0)) != 0)) {
        return 1;
    }
    return 0;
}

s32 TObjPlayer::is_quest_interaction_blocked() {
    if (this->lock_on_cursor == NULL) {
        return 0;
    }
    switch ((u16) get_action_palette_entry(0)) {
    case 0:
    case 2:
        return 0;
    case 1:
    default:
        return 0;
    }
}

void *TObjPlayer__sub_801B57E8(TObjPlayer *player) {
    s32 i;
    saddr cursor;
    if (player->lock_on_cursor == NULL) {
        return NULL;
    }
    cursor = (saddr)player->lock_on_cursor->action_slots;
    for (i = 0; i < 4; i++) {
        if (try_move__11TMainCursorFiii(cursor, get_player_action_palette_mode(&player->action_palette_state),
                get_player_action_palette_slot(&player->action_palette_state)) != 0) {
            return (void *)cursor;
        }
        cursor += 0x124;
    }
    return NULL;
}

void TObjPlayer::action_enable_if_present() { void* m = this->lock_on_cursor; if (m) ((TObjPlayer *)m)->clear_flag_1_at_1c(); }

void TObjPlayer::release_attached_resource() { void* m = this->lock_on_cursor; if (m) ((TObjPlayer *)m)->set_flags_bit1(); }

s32 TObjPlayer::get_camera_field() {
    void *p = this->lock_on_cursor;
    if (p != 0) {
        return ((TMainCursor *)p)->is_cursor_clear();
    }
    return 0;
}

void TObjPlayer::reset_equip_slots() { pad_binding.disable_buttons(0x406); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)0); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)1); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)2); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)3); this->set_state_flags(256); }

void TObjPlayer::init_parts() { pad_binding.enable_buttons(0x406); ((TChallenge4PResult *)this)->get_player_rank(); this->clear_state_flags(256); }

s32 TObjPlayer::is_controls_locked() { return check_flag(256); }

int TObjPlayer::has_valid_handle() { return ((TObjPlayer *)(*(void**)((char*)this + 0x380)))->is_handle_valid(); }

void TObjPlayer::select_class_action_provider() {
  s8 class_index;
  class_index = ((TObjPlayer *)this)->get_class_index();
  {
    switch (class_index)
    {
      case 0:
      case 2:
      case 3:
      case 4:
      case 7:
        TObjPlayer::forward_801C210C(*(void **)((s8 *)this + 0x380), 0);
        return;
      case 1:
      case 5:
      case 8:
        TObjPlayer::forward_801C210C(*(void **)((s8 *)this + 0x380), 1);
        return;
      case 6:
        TObjPlayer::forward_801C210C(*(void **)((s8 *)this + 0x380), 2);
        return;
      case 9:
        TObjPlayer::forward_801C210C(*(void **)((s8 *)this + 0x380), 4);
        return;
      case 10:
        TObjPlayer::forward_801C210C(*(void **)((s8 *)this + 0x380), 3);
        return;
      case 11:
        TObjPlayer::forward_801C210C(*(void **)((s8 *)this + 0x380), 5);
        break;
    }
  }
}

void TObjPlayer::apply_input_mode() {
    s32 class_flags;

    class_flags = get_class_flags();
    if (class_flags & CLASS_FLAG_HUNTER) {
        this->set_input_mode(0);
        return;
    }
    if (class_flags & CLASS_FLAG_RANGER) {
        this->set_input_mode(1);
        return;
    }
    this->set_input_mode(2);
}

void TObjPlayer::set_move_mode_from_class_flags() {
    s32 class_flags;

    class_flags = this->get_class_flags();
    if (class_flags & CLASS_FLAG_ANDROID) {
        this->set_move_mode(2);
        return;
    }
    if (class_flags & CLASS_FLAG_NEWMAN) {
        this->set_move_mode(1);
        return;
    }
    this->set_move_mode(0);
}

s32 TObjPlayer::get_clamped_index() {
    s32 temp_r3;

    temp_r3 = this->m_3d8;
    if ((temp_r3 < 0) || (temp_r3 >= 3)) {
        return 0;
    }
    return temp_r3;
}

}

void TObjPlayer::init_trait_flags() {
    this->target_attribute_mask = 0;
    if (get_class_flags() & CLASS_FLAG_ANDROID) {
        this->add_flags_2e4(4);
    } else {
        this->add_flags_2e4(1);
    }
    if (get_class_flags() & CLASS_FLAG_RANGER) {
        this->add_flags_2e4(0x20);
    }
}

void send_impose_hold(TObjPlayer *player, int frames) {
    ((s32 (*)(TObjPlayer *, Vec *, s32, s32, f32))send_6x2C_impose_hold)(player, player->get_position_ptr(), frames, 0, (*(f32 *)&TObjPlayer__data_805DC278));
}

extern "C" {

void TObjPlayer::play_effect(TObjPlayer *player, s32 effect_id, s32 mode) {
    send_6x2C_impose_hold(player, player->get_position_ptr(), effect_id, mode, TObjPlayer__data_805DC278);
}

void send_6x2C_impose_hold(TObjPlayer *player, Vec *pos, s32 frames, s32 mode, f32 radius) {
    struct Pkt_801B5328 pkt;
    if (player == NULL || player->obj_isState2_324() == 0) {
        ((TObjPlayer *)(&pkt))->build_6x2C_impose_hold_packet();
        pkt.actor_id = player->get_entity_id();
        pkt.b = static_cast<s16>(mode);
        pkt.a = static_cast<s16>(frames);
        pkt.x = pos->x;
        pkt.z = pos->z;
        pkt.radius_sq = radius * radius;
        ((TObjPlayer *)(&pkt))->bswap_and_send_packet();
    }
}

void handle_6x2C_impose_hold(saddr command) {
    Pkt_801B5254 pkt;
    TObjPlayer * player;
    ((TObjPlayer *)(&pkt))->build_6x2C_impose_hold_packet();
    ((TObjPlayer *)(&pkt))->copy_hold_params((u8 *)command);
    bswap_pkt_u16x2_u32__10TObjPlayerFPv(&pkt);
    if (validate_6x2C_impose_hold((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    player = get_player_by_client_id(pkt.client);
    if (player == 0) {
        return;
    }
    player->movement_hold.set_effect_type(pkt.f6);
    player->movement_hold.set_frames(pkt.f4);
    player->movement_hold.set_center(pkt.f8, pkt.fC);
    player->movement_hold.set_radius_sq(pkt.f10);
    player->set_state_flags(1);
    if (player->check_flag_4() == 0 && ((s32 (*)(TObjPlayer *))is_on_current_floor__10TObjPlayerFi)(player) != 0) {
        TObjEneHoldEffect::create(player, pkt.f6, pkt.f4);
    }
}

}

void send_release_hold(TObjPlayer *player) {
    struct S801B5200_801B3FD8 sp8;

    if ((player == NULL) || (player->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_45_1();
        sp8.h = player->get_entity_id();
        ((TObjPlayer *)(&sp8))->send_lobby_update_font();
    }
}

extern "C" {

s32 TObjPlayer::draw_small_font(saddr arg0, void * command) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x2D_release_hold(void *command) {
    struct pkt_801B5164 pkt;
    ((TObjPlayer *)(&pkt))->set_code_45_1();
    TObjPlayer::draw_small_font((s32)((saddr) &pkt), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x2D_release_hold((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->clear_state_flags(1);
        }
    }
}

#pragma push
#pragma fp_contract on
s32 TObjPlayer::is_outside_movement_hold(f32 *pos) {
    f32 *center;
    f32 x, y, z;
    f32 dx, dz;
    if (check_player_flag1() == 0) {
        return 0;
    }
    center = movement_hold.get_center();
    x = center[0];
    y = pos[0];
    z = center[1];
    dx = x - y;
    dz = z - pos[2];
    return (u32)__cntlzw(movement_hold.get_radius_sq() > (dx * dx + dz * dz)) >> 5;
}
#pragma pop

Obj_801B4FD8 *init_player_join_record(Obj_801B4FD8 *self) {
    s32 i;
    __construct_array(self->f28, __ct__12StatusEffectFv, 0, 0xC, 5);
    ((TObjPlayer *)(self->f68))->clear_header_struct();
    TObjPlayer__sub_801C1A00(self->f70);
    init_player_telepipe_record(self->f78);
    __ct__8FlagWordFv((self->f94));
    self->f98.init();
    init_inventory_list__10TObjPlayerFPv(self->f13C);
    self->f0 = 0xFFFF;
    self->f2 = 0;
    self->f4 = 0;
    self->f8 = self->fC = self->f10 = TObjPlayer__data_805DC278;
    self->f14 = self->f18 = self->f1C = 0;
    self->f20 = 0;
    self->f22 = 0;
    self->f24 = 0;
    self->f26 = 0;
    self->f64 = 0;
    self->fAC = 0;
    self->f488 = 0;
    self->fB0 = 0;
    for (i = 0; i < 0x13; i++) {
        self->fB4[i] = TObjPlayer::get_item_count_max();
    }
    return self;
}

void fill_player_record__10TObjPlayerFPvPv(Src_801B4CE4 *src, Dst_801B4CE4 *dst) {
    s32 j;
    s32 i;
    s32 a;
    s32 b;
    u32 v;
    dst->f0 = ((TObjBase *)((saddr)src))->get_entity_id();
    dst->f2 = src->f2E;
    dst->f4 = src->f30 & ~0x02000000;
    VecCopy((Vec *)dst->f8, (const Vec *)src->pos38);
    copy_xyz(dst->f14, src->f5C);
    dst->f20 = src->f326;
    dst->f22 = src->f32C;
    for (i = 0; i < 5; i++) {
        TObjPlayer__sub_801BEF44(&dst->f28[i], &src->f254[i]);
    }
    ((TLobby *)(dst->f68))->copy_header_struct(src->fDAC);
    TObjPlayer__sub_801BEF30(dst->f70, src->f828);
    ((TObjPlayer *)(dst->f78))->copy_player_record_header(src->f830);
    TObjPlayer__sub_801BEEE0(dst->f94, src->f858);
    TObjPlayer__sub_801BEEAC(&dst->f98, src->f730);
    dst->fAC = ((TObjPlayer *)src)->get_area();
    dst->f488 = ((TObjPlayer *)src)->get_floor();
    dst->fB0 = src->f334;
    dst->f64 = ((TObjPlayer *)src)->get_language();
    copy_player_visual_record(dst->fC8, src->f85C);
    dst->f13C = src->fD00->run_state_query(reinterpret_cast<TPlyInventoryItem *>(dst->f140));
    a = get_actor_hp__9TObjCharaFv(src);
    b = get_actor_tp(src);
    for (i = 0; i != 0xD; i++) {
        TItem *e = ((TObjPlayer *)src)->get_equipped_item(i);
        if (e != NULL) {
            e->remove_equip_stats(1);
        }
    }
    TLobby::copy_data(dst->f118, src->f2B0);
    dst->f24 = ((TObjPlayer *)src)->get_hp_bonus();
    dst->f26 = ((TObjPlayer *)src)->get_tp_bonus();
    TObjPlayer__sub_801BE864(dst, ((TObjPlayer *)src)->get_power_materials_used());
    TObjPlayer__sub_801BE838(dst, ((TObjPlayer *)src)->get_mind_materials_used());
    TObjPlayer__sub_801BE80C(dst, ((TObjPlayer *)src)->get_evade_materials_used());
    TObjPlayer__sub_801BE7E0(dst, ((TObjPlayer *)src)->get_def_materials_used());
    TObjPlayer__sub_801BE7B4(dst, ((TObjPlayer *)src)->get_luck_materials_used());
    for (i = 0; i < 0x13; i++) {
        TObjPlayer::split_capped_value(TObjPlayer__sub_801C0124(src->f428, i), &dst->fB4[i], dst->f142[i].b);
    }
    for (j = 0; j != 0xD; j++) {
        TItem *e = ((TObjPlayer *)src)->get_equipped_item(j);
        if (e != NULL) {
            e->add_equip_stats(1);
        }
    }
    ((void (*)(void *, s32))set_hp_clamped__10TObjPlayerFs)(src, a);
    set_tp__10TObjPlayerFs(reinterpret_cast<TObjPlayer *>(src), b);
    encode_player_record_inventory(dst);
    v = TObjPlayer__sub_801BFFA0(src->f41C);
    dst->f142[0].b[1] = v;
    dst->f142[1].b[1] = v >> 8;
    dst->f142[2].b[1] = v >> 16;
    dst->f142[3].b[1] = v >> 24;
    TObjPlayer__sub_801BE7A4(dst, ((TObjPlayer *)src)->get_mag_level());
    TObjPlayer__sub_801BE794(dst, ((TObjPlayer *)src)->get_byte_339());
    TObjPlayer__sub_801BE784(dst, ((TObjPlayer *)src)->get_battle_mode());
    TLobby::bswap_player_data(dst);
}

s32 TObjPlayer::get_battle_ctrl_flag(u16 id) {
    s32 player;

    player = (saddr)get_player_by_client_id((u16)id);
    if ((player != 0) && (((s32 (*)(void))is_on_current_floor__10TObjPlayerFi)() != 0)) {
        return player;
    }
    return 0;
}

void TObjPlayer::apply_material_color_override() {
    if (!(this->render_material_state.get_alpha() >= TObjPlayer__data_805DC294)) {
        set_default_alpha_blend();
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)(((saddr)this + 0x624)));
    }
}

void TObjPlayer::clear_action_flag() {
    if ((is_field_0_positive(&this->inventory_objects->list.count) == 0) && (((TObjPlayer *)this)->is_action_active() != 0U)) {
        this->clear_flag_0x2();
        send_release_hold(this);
    }
}

void TObjPlayer::update_facing_vector() {
    this->m_404 = sin_table_lookup(this->rotation_y);
    *(f32 *)((s8 *)((u8 *)this) + 0x408) = (f32) TObjPlayer__data_805DC278;
    this->m_40c = cos_table_lookup(this->rotation_y);
    update_ground_contact();
    if (this->lock_on_cursor != NULL) {
        ((TMainCursor *)this->lock_on_cursor)->reset_slots();
    }
    this->contact_surface.check_surface_exit();
}

void submit_target_to_player_cursor(void *target, s32 id) {
    s32 i;
    Player_801B4AC8 *player;
    Slot_801B4AC8 *entry;
    if (target == NULL || (u16)id == 0xFFFF || (u16)id >= 0x1000) {
        return;
    }
    player = (Player_801B4AC8 *)get_player_by_client_id((u16)id);
    if (player != NULL && player->cursor != NULL) {
        for (i = 0; i < 4; i++) {
            entry = &player->cursor->slots[i];
            if (((TMainCursor *)entry)->get_selected_entry() != 0) {
                TMainCursor::try_add_target_candidate(entry, target, player, &player->cursor->f510);
            }
        }
    }
}

void submit_cursor_candidate(void *self) {
    s32 j;
    s32 i;
    Owner_801B4A18 *o;
    Owner_801B4A18 **pp;
    if (self != 0) {
        pp = ((Owner_801B4A18 * *)&player_slot_table);
        for (i = 0; i < 4; i++) {
            o = *pp++;
            if (o != 0 && o->menu != 0) {
                for (j = 0; j < 4; j++) {
                    Cursor_801B4A18 *c = &o->menu->cursors[j];
                    if (((TMainCursor *)c)->get_selected_entry() != 0) {
                        TMainCursor::try_add_target_candidate(c, self, o, (u8 *)o->menu + 0x510);
                    }
                }
            }
        }
    }
}

s32 TObjPlayer::get_battle_ctrl_id(u16 client) {
    u32 temp_r3;
    void *player;

    player = get_player_by_client_id(client);
    if (player == NULL) {
        return 0xFFFF;
    }
    temp_r3 = *(u32 *)((s8 *)player + 0x424);
    if (temp_r3 == 0U) {
        return 0xFFFF;
    }
    return ((s32 (*)(s32))get_id__11TMainCursorFv)(temp_r3 + 0x4F8);
}

void TObjPlayer::update_subsystems() {
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        this->check_level_up();
        sync_status_effect_flags();
        clear_action_flag();
        this->update_target();
        if ((this->check_player_flag1() != 0) && (this->movement_hold.get_frames() >= 0) && (this->movement_hold.count_down() == 0)) {
            send_release_hold(this);
        }
        this->battle_music.update_target_lock(this);
        if (scale_state.is_scaled() != 0) {
            scale_state.update_camera();
        }
    }
}

s32 TObjPlayer::is_target_valid() {
    if (this->lock_on_cursor == NULL) {
        return 0;
    }
    if (((u16) this->interactor != 0xFFFF) || (is_controls_locked() != 0) || (((TMainCursor *)this->lock_on_cursor)->is_cursor_clear() == 0) || (this->check_flag_0x40000000() != 0) || (test_action_mask(0x1E) == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::update_target() {
    u16 current_target_id;
    saddr arg0 = (saddr)this;

    current_target_id = TObjPlayer::get_current_target_id();
    if ((current_target_id == 0xFFFF) || (current_target_id == ((TObjBase *)(arg0))->get_entity_id())) {
        this->photon_blast_gauge.reset_targets();
        return;
    }
    fn_801C1F1C(arg0 + 0x4AC);
    if (this->can_use_action() != 0) {
        this->photon_blast_gauge.draw_party_label(this, current_target_id);
    }
}

void TObjPlayer::play_photon_blast_feedback() { ((TObjPlayer *)((char*)this + 0x384))->emit_photon_blast_feedback_from_packet(); this->play_sound_if_on_floor(142625); }

s32 TObjPlayer::can_use_action() {
    if (pad_binding.is_button_pressed(0x200) == 0) {
        return 0;
    }
    if (is_controls_locked() != 0) {
        return 0;
    }
    if (this->test_action_mask(0x200) != 0) {
        return 0;
    }
    return this->photon_blast_gauge.is_ready() != 0 ? 1 : 0;
}

s32 TObjPlayer::get_recovery_need_flags() {
    s32 var_r31;
    var_r31 = 0;
    if ((s16) this->hp < (s16) this->hpmax) {
        var_r31 |= 1;
    }
    if (this->tp < this->tpmax) {
        var_r31 |= 2;
    }
    if (test_actor_flags(0x3F) != 0) {
        var_r31 |= 4;
    }
    switch (this->get_status_effect_type(2)) {
    case 0xB:
        var_r31 |= 4;
        break;
    }
    switch (this->get_status_effect_type(3)) {
    case 0xC:
        var_r31 |= 4;
        break;
    }
    return var_r31;
}

void send_code_49_1__10TObjPlayerFi(saddr player) {
    struct S801B4630_801B3FD8 sp8;

    if ((player == 0) || (((TObjChara *)player)->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_49_1();
        sp8.h = ((TObjBase *)(player))->get_entity_id();
        ((TObjPlayer *)(&sp8))->bswap_font_lobby();
    }
}

s32 TObjPlayer::update_medical_font(saddr arg0, void * command) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x31_use_medical_center(void *command) {
    struct pkt_801B1674 pkt;
    ((TObjPlayer *)(&pkt))->set_code_49_1();
    TObjPlayer::update_medical_font((s32)((s32)((saddr) &pkt)), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x31_use_medical_center((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            recover_full__10TObjPlayerFPv(p);
        }
    }
}

void recover_full__10TObjPlayerFPv(void *player) {
    ((s32 (*)(void))play_voice_pair__10TObjPlayerFPv)();
    ((TObjPlayer *)player)->clear_all_status_effects();
    ((TObjBase *)player)->clear_actor_flags((u32)0xE00);
    ((TObjPlayer *)player)->clear_state_flags(1);
}

void send_code50_packet__10TObjPlayerFi(saddr player) {
    struct S801B44EC_801b44ec_801B3FD8 sp8;

    if ((player == 0) || (((TObjChara *)player)->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_50_1();
        sp8.h = ((TObjBase *)(player))->get_entity_id();
        ((TObjPlayer *)(&sp8))->send_font_state();
    }
}

void handle_6x32_medical_center_revive_all_players(void) {
    s32 i;
    void *p;
    void **pp = player_slot_table;
    for (i = 0; i < 4; i++, pp++) {
        p = *pp;
        if (p != NULL && ((TObjChara *)p)->obj_isState3_324() != 0) {
            recover_full__10TObjPlayerFPv(p);
        }
    }
}

void TObjPlayer::send_6xA1_player_id() {
    struct S801B4430_801b4430_801B3FD8 sp8;

    if ((((saddr)this) == 0) || (this->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_161_1();
        sp8.h = ((TObjBase *)(((saddr)this)))->get_entity_id();
        ((TObjPlayer *)(&sp8))->update_font();
    }
}

s32 TObjPlayer::revive_6xA1(saddr arg0, void * command) {
    copy_subcommand_header();
    return arg0;
}

void handle_6xA1_revive_player_v3(void *command) {
    struct pkt_801B1674 pkt;
    ((TObjPlayer *)(&pkt))->set_code_161_1();
    TObjPlayer::revive_6xA1((s32)((s32)((saddr) &pkt)), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6xA1_revive_player_v3((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->revive();
        }
    }
}

void TObjPlayer::revive() {
    update_rotation();
    clear_all_status_effects();
    clear_actor_flags((u32)0xE00);
    clear_state_flags(1);
}

void TObjPlayer::update_rotation() {
    if ((TObjPlayer::check_camera_mode() == 0) && (((s32 (*)(void *))reset_volopt_state__10TObjPlayerFv)(this) != 0) && (TTecCtrl::is_technique_ready() == 0) && (obj_isState3_324() == 0)) {
        set_hp_clamped((s16) ((s16) this->hpmax / 2));
        return;
    }
    set_hp_clamped(this->hpmax);
    set_tp(this->tpmax);
}

void TObjPlayer::play_footstep_sound(f32 at_frame, f32 farg1) {
    if (test_ordered_anim_markers__10TObjPlayerFPvff((u8 *)this, at_frame, farg1) != 0) {
        this->play_sound_if_on_floor(this->get_footstep_floor_index());
    }
}

void TObjPlayer::emit_footstep_effect(f32 at_frame, f32 farg1) {
    s32 temp_r3;
    s32 contact_surface_type;
    saddr arg0 = (saddr)this;
    if ((this->is_body_collision_inactive() == 0) && (temp_r3 = ((s32)test_ordered_anim_markers__10TObjPlayerFPvff((u8 *)arg0, at_frame, farg1)), ((temp_r3 == 0) == 0))) {
        contact_surface_type = this->contact_surface.get_contact_surface_type();
        switch (contact_surface_type) {
        case 1:
            emit_grass_footstep_effect((arg0 + 0x384));
            return;
        case 2:
            emit_water_footstep_effect((arg0 + 0x384));
            return;
        case 3:
            emit_sand_footstep_effect((arg0 + 0x384));
            return;
        case 4:
            this->update_foot_stamp(temp_r3);
            return;
        case 0:
            if (this->contact_surface.is_timer_running() != 0) {
                this->update_foot_stamp(temp_r3);
            }
            break;
        }
    }
}

s32 test_ordered_anim_markers__10TObjPlayerFPvff(u8 *motion, f32 at_frame, f32 farg1) {
    if (((TObjMotion *)motion)->is_passing_frame((f32)at_frame) != 0) {
        return 1;
    }
    return (((TObjMotion *)motion)->is_passing_frame((f32)farg1) != 0) ? 2 : 0;
}

void TObjPlayer::update_foot_stamp(int arg1) {
    if (arg1 == 1) {
        TObjPlayer::clear_foot_stamp((saddr)((u8 *)this + 0x384), (saddr)this);
    } else if (arg1 == 2) {
        TObjPlayer::enable_foot_stamp((saddr)((u8 *)this + 0x384), (saddr)this);
    }
}

s32 TObjPlayer::classify_action_state() {
    s8 class_index;

    class_index = ((TObjPlayer *)this)->get_class_index();
    switch (class_index) {
    case 5:
    case 9:
    case 2:
        return 1;
    case 4:
        return 2;
    default:
        return 0;
    }
}

void TObjPlayer__sub_801B4044(void* p) { ((TObjPlayer *)p)->battle_music.set_flag_2(); }

void TObjPlayer::forward_1BF500_at_63c() { battle_music.clear_flag0_bit1(); }

void TObjPlayer::attach_battle_ctrl_sub() { battle_music.clear_target_lock(); }

void TObjPlayer__sub_801B3FD8(void* p) { ((TObjPlayer *)p)->battle_music.reset_ring(); }

s32 TObjPlayer::execute_palette_action(s32 mode, void *target) {
    u8 *self = (u8 *)this;
    s16 kind;
    s16 act;
    kind = ((s32 (*)(void *, s32))TObjPlayer__sub_801B5AF8)(this, mode);
    act = get_action_palette_entry(mode);
    set_player_action_palette_mode(&action_palette_state, kind);
    set_player_action_palette_slot(&action_palette_state, act);
    switch (kind) {
    case 0:
        return 0;
    case 1:
        if (target == NULL) {
            return 0;
        }
        if (is_target_valid() != 0) {
            ((TObjCollidable *)target)->interact(this->get_entity_id());
            return 1;
        }
        break;
    case 2:
        ((TObjPlayer *)(self + 0x7CC))->set_action_type(act);
        if (this->check_mode_action(act) != 0) {
            if (pad_binding.get_stick_magnitude() >= lbl_805DC290) {
                ((Player_801B3DD4 *)this)->f60 = ((s32 (*)(void *, s32))calc_scaled_value__10TObjPlayerFii)(this, pad_binding.get_stick_angle());
            }
            run_action_state_phase(5, 5);
            return 1;
        }
        break;
    case 3:
        if (TObjPlayer::try_camera_action((saddr)this, (s32)act) != 0) {
            technique_state.set_technique_id(act);
            run_action_state_phase(8, 5);
            return 1;
        }
        break;
    case 4:
        if (can_use_camera_field() != 0 && dispatch_palette_action(act) != 0) {
            return 1;
        }
        break;
    case 5:
        if (check_conditions__10TObjPlayerFv(this, act) != 0) {
            set_photon_blast_kind((u8 *)&this->photon_blast_gauge, act);
            run_action_state_phase(9, 5);
            return 1;
        }
        break;
    case 6:
        if (TObjPlayer::is_player_valid_target(this->get_entity_id()) != 0) {
            run_palettex_callback(this->get_entity_id());
        }
        break;
    default:
        return 0;
    }
    return 0;
}

s32 TObjPlayer::handle_palette_button_input() {
    u8 *arg0 = (u8 *)this;
    if (pad_binding.is_button_pressed(4) != 0 && ((int (*)(void *, s32))get_result_entry__18TChallenge4PResultFPv)(arg0, 1) != 0) {
        s32 mode;
        void *target;
        if (has_action_palette_entry() != 0) {
            target = find_entity_by_id(((TMainCursor *)(*(u8 **)(arg0 + 0x424) + 0x4F8))->get_id());
            mode = 0;
        } else {
            target = 0;
            mode = 1;
        }
        if (execute_palette_action(mode, target) != 0) {
            TWindowCtrl::dispatch_to_child(((TObjBase *)(arg0))->get_entity_id(), 1);
            return 1;
        }
    } else if (pad_binding.is_button_pressed(0x400) != 0 && ((int (*)(void *, s32))get_result_entry__18TChallenge4PResultFPv)(arg0, 2) != 0) {
        if (is_palettex_activated(((TObjBase *)(arg0))->get_entity_id()) != 0 && ((TWindowActionPalette *)(arg0 + 0x500))->handle_input_forward() != 0) {
            if (TObjPlayer::is_player_valid_target(((TObjBase *)(arg0))->get_entity_id()) != 0) {
                run_palettex_callback(((TObjBase *)(arg0))->get_entity_id());
            }
        } else if (this->execute_palette_action(2, 0) != 0) {
            TWindowCtrl::dispatch_to_child(((TObjBase *)(arg0))->get_entity_id(), 2);
            return 1;
        }
    } else if (pad_binding.is_button_pressed(2) != 0 && ((int (*)(void *, s32))get_result_entry__18TChallenge4PResultFPv)(arg0, 3) != 0 &&
               this->execute_palette_action(3, 0) != 0) {
        TWindowCtrl::dispatch_to_child(((TObjBase *)(arg0))->get_entity_id(), 3);
        return 1;
    }
    return 0;
}

int get_player_result__18TChallenge4PResultFPv(void* p) { return TObjPlayer__sub_801BF4A0((char*)p + 0x340); }

int get_field_340__18TChallenge4PResultFPv(void* p) { return TObjPlayer__sub_801BF488((char*)p + 0x340); }

int TChallenge4PResult::get_player_rank() { return TObjPlayer__sub_801BF47C((char*)this + 0x340); }

int get_result_entry__18TChallenge4PResultFPv(void* p) { return TObjPlayer__sub_801BF460((char*)p + 0x340); }

s32 TObjPlayer::dispatch_palette_action(u32 act) {
    switch (act) {
    case 0:
        return ((s32)try_use_item_by_type(3, 0, 0));
    case 1:
        return ((s32)try_use_item_by_type(3, 0, 1));
    case 2:
        return ((s32)try_use_item_by_type(3, 0, 2));
    case 3:
        return ((s32)try_use_item_by_type(3, 1, 0));
    case 4:
        return ((s32)try_use_item_by_type(3, 1, 1));
    case 5:
        return ((s32)try_use_item_by_type(3, 1, 2));
    case 6:
        return ((s32)try_use_item_by_type(3, 6, 0));
    case 7:
        return ((s32)try_use_item_by_type(3, 6, 1));
    case 8:
        return check_can_add_item((s8)(3), (s8)(3));
    case 9:
        return check_can_add_item((s8)(3), (s8)(4));
    case 10:
        technique_state.reset_slots();
        return check_can_add_item((s8)(3), (s8)(5));
    case 11:
        return check_can_add_item((s8)(3), (s8)(7));
    case 12:
        return check_can_add_item((s8)(3), (s8)(8));
    case 13:
        return send_trap_packet(0);
    case 14:
        return send_trap_packet(1);
    case 15:
        return send_trap_packet(2);
    case 16:
        return send_trap_packet(3);
    default:
        return 0;
    }
}

s32 TObjPlayer::can_use_camera_field() {
    if ((is_controls_locked() != 0) || (this->get_camera_field() == 0) || (is_current_area_item_enabled() == 0)) {
        return 0;
    }
    return 1;
}

s32 TObjPlayer::can_use_item(void *item) {
    LockOnActionSlot *slot;
    if (TTecCtrl::is_technique_ready() != 0 && ((u8 (*)(void *))fn_801D7168)(lobby_rule_settings) == 2) {
        return 0;
    }
    switch (((TItem *)item)->get_item_type()) {
    case 3:
        switch (((TItem *)item)->get_item_group()) {
        case 0:
            if (this->hp >= this->hpmax) {
                return 0;
            }
            break;
        case 1:
            if (this->tp >= this->tpmax) {
                return 0;
            }
            break;
        case 6:
            switch (((TItem *)item)->get_item_index()) {
            case 0:
                if (test_actor_flags(1) == 0) {
                    return 0;
                }
                break;
            case 1:
                if (test_actor_flags(2) == 0) {
                    return 0;
                }
                break;
            }
            break;
        case 3:
            if (!(get_recovery_need_flags() & 4)) {
                return 0;
            }
            break;
        case 4:
            if (this->lock_on_cursor != NULL) {
                slot = this->lock_on_cursor->find_by_pos(4, 9);
                if (slot == NULL) {
                    return 0;
                }
                if (((TObjPlayer *)TObjPlayer__sub_80116620(&slot->target_records, 0))->get_type_id() == 0xFFFF) {
                    return 0;
                }
            }
            break;
        case 7:
            if (TObjWarpBossMulti::is_flag_clear(this) == 0) {
                return 0;
            }
            break;
        }
        break;
    }
    return 1;
}

s32 TObjPlayer::check_can_add_item(s8 arg1, s8 arg2) {
    s8 item_data[24];

    ((TItemData *)item_data)->init();
    item_data[0] = arg1;
    item_data[1] = arg2;
    void *node_5996 = this->inventory_objects->set_mode_and_refresh_object(item_data);
    if (node_5996 == 0U) {
        return 0;
    }
    TItem *owner = (TItem *)((TItemList *)node_5996)->get_owner_if_alive();
    if (owner == NULL) {
        return 0;
    }
    if (try_send_6x27_use_item(this, owner->get_item_id()) == 0) {
        return 0;
    }
    void *node_6006 = this->inventory_objects->set_mode_and_refresh_object(item_data);
    if (node_6006 == 0U) {
        return 0;
    }
    TObject *obj = (TObject *)((TItemList *)node_6006)->get_owner_if_alive();
    if (obj == NULL) {
        return 0;
    }
    return obj->all_parents_unqueued_for_destruction() != 0 ? 1 : 0;
}

int TObjPlayer::try_use_item_by_type(int arg1, int arg2, int arg3) {
    s8 item_data[24];
    ((TItemData *)item_data)->init();
    item_data[0] = arg1;
    item_data[1] = arg2;
    item_data[2] = arg3;
    void *node_6022 = this->inventory_objects->set_mode_and_refresh_object(item_data);
    if (node_6022 == 0U) {
        return 0;
    }
    TItem *owner = (TItem *)((TItemList *)node_6022)->get_owner_if_alive();
    if (owner == NULL) {
        return 0;
    }
    if (try_send_6x27_use_item(this, owner->get_item_id()) == 0) {
        return 0;
    }
    void *node_6032 = this->inventory_objects->set_mode_and_refresh_object(item_data);
    if (node_6032 == 0U) {
        return 0;
    }
    TObject *obj = (TObject *)((TItemList *)node_6032)->get_owner_if_alive();
    if (obj == NULL) {
        return 0;
    }
    return obj->all_parents_unqueued_for_destruction() != 0 ? 1 : 0;
}

void TObjPlayer::disable_action_input() { this->set_state_flags(1024); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)1); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)2); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)3); }

void TObjPlayer::disable_primary_action_input() { this->set_state_flags(1024); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)1); }

void enable_action_input__10TObjPlayerFPv(void* p) { ((TObjPlayer *)p)->clear_state_flags(1024); ((TChallenge4PResult *)p)->get_player_rank(); }

int is_flag_400_set__10TObjPlayerFPv(void* p) { return ((TObjPlayer *)p)->check_flag(1024); }

void TObjPlayer::set_flag_4096() { this->set_state_flags(4096); }

void TObjPlayer::clear_flag_4096() { this->clear_state_flags(4096); }

int TObjWarpBossMulti::is_flag_clear(void* p) { return (((TObjPlayer *)p)->check_flag(4096)) == 0; }

s32 TObjPlayer::create_return_city_window() {
    if ((TObjPlayer::is_locally_controlled(this) != 0) && ((u32) this->m_36c == 0U) && ((u32) *(u32 *)((s8 *)this + 0x548) != 0U)) {
        this->m_36c = (saddr)new TWindowReturnCity(tl_07, (u16)this->get_entity_id());
        return 1;
    }
    return 0;
}

void TObjPlayer::stop_battle() { this->set_battle_flag(0); }

void complete_deferred_player_death(void) {
    u8 lvl;
    s16 aim;
    u16 room;
    TObjPlayer *p;
    p = get_player_by_client_id(fn_801C1BA0());
    if (p == NULL) {
        return;
    }
    ((FlagWord *)((u8 *)p + 0x858))->clear(2);
    if (((TObjPlayer *)p)->try_pickup_item() != 0) {
        return;
    }
    if (TTecCtrl::is_technique_ready() != 0) {
        if (((u8 (*)(void *))TLobby__sub_801D7100)(lobby_rule_settings) == 1) {
            TObjPlayer::send_6x4E_player_revivable((saddr)p);
            return;
        }
        if (((u8 (*)(void *))TLobby__sub_801D7100)(lobby_rule_settings) == 2 && TObjPlayer::decrement_timer((s32 *)((u8 *)p + 0x754)) == 0) {
            TObjPlayer::send_6x4E_player_revivable((saddr)p);
            return;
        }
        ((TObjPlayer *)p)->send_respawn_position();
        aim = ((TLobby *)lobby_rule_settings)->clamp_value_below_200();
        room = TObjRoomId__sub_801A1DB8(((TObjPlayer *)p)->get_attacker_id());
        if (aim != 0 && (room == 0 || room == 0x1000)) {
            ((TObjPlayer *)p)->update_aim_angle(aim);
        }
        if ((lvl = (u8)((TLobby *)lobby_rule_settings)->get_clamped_level()) != 0 && (room == 0 || room == 0x1000)) {
            ((s32 (*)(void *, u8))TObjPlayer__sub_801AF554)(p, lvl);
        }
        p->reset_pose();
        return;
    }
    if (TObjPlayer::is_camera_mode_active() != 0) {
        TObjPlayer::send_6x4E_player_revivable((saddr)p);
        return;
    }
    if (get_main_phase() == 0xE) {
        if (TObjPlayer::check_camera_mode() != 0) {
            if (((TObjPlayer *)p)->get_anim_id() == 1) {
                ((s32 (*)(void *, int))prepare_guild_return__10TObjPlayerFPv)(p, 0);
                return;
            }
            ((TObjPlayer *)p)->prepare_hospital_return();
            floor_transition_state.set_next_floor(0, get_floor_map_terrain(0));
            ((s32 (*)(void))mark_area_change_pending)();
            send_inter_level_warp_all(floor_transition_state.get_next_floor());
            return;
        }
        ((TObjPlayer *)p)->create_return_city_window();
        TObjPlayer::send_6x4E_player_revivable((saddr)p);
        return;
    }
    ((TObjPlayer *)p)->create_return_city_window();
    TObjPlayer::send_6x4E_player_revivable((saddr)p);
}

void TObjPlayer::prepare_hospital_return() {
    send_6x21_inter_level_warp(this, 0);
    set_arrival_override_pos(this->get_entity_id(), get_hospital_yaw(), (saddr)((TObjPlayer *)this)->get_hospital_position());
    this->set_state_flags(0x800);
    this->set_battle_flag(0);
    apply_to_players((s32)(floor_transition_state.get_next_floor()), get_npc_lobby_entry_position(), get_npc_lobby_entry_yaw());
}

void handle_6x34(void) {  }

int TLobby::check_player_state_flag_2() { return test_flags_any((s32 *)((char*)this + 0x858), 2); }

void TLobby::player_flag_1() { ((TObjPlayer *)this)->set_battle_flag(1); }

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
#pragma scheduling on
void prepare_guild_return__10TObjPlayerFPv(void *player) {
    floor_transition_state.set_next_floor(0, get_floor_map_terrain(0));
    mark_area_change_pending();
    set_arrival_override_pos(((TObjBase *)((saddr) player))->get_entity_id(), ((TObjPlayer *)player)->get_guild_return_yaw(), (saddr)((TObjPlayer *)player)->get_guild_return_position());
    ((TObjPlayer *)player)->set_state_flags(0x800);
    ((TObjPlayer *)player)->set_battle_flag(1);
    send_6x21_inter_level_warp((TObjPlayer *)player, floor_transition_state.get_next_floor());
    apply_to_players((s32)(floor_transition_state.get_next_floor()), get_party_position(), get_party_yaw());
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
void recover_player_full(void *player) { recover_full__10TObjPlayerFPv(player); }
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
s32 build_player_equipment_requirement_stats(TObjPlayer *self, PlayerRequirementStats *player_requirement_stats) {
    set_params__10TObjPlayerFPvPvPviPv(player_requirement_stats, self, self->get_stats(),
                                       get_class_attack_template(self), get_class_defense_template(self));
    return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
s32 build_player_class_stat_template(saddr arg0, saddr arg1) {
  void *new_var;
  unsigned int new_var2;
  s32 temp_r30;
  s32 temp_r31;
  if (arg0 == 0)
  {
    if (!arg0)
    {
    }
    return 0;
  }
  temp_r31 = (saddr)get_class_defense_template((TObjPlayer *)arg0);
  new_var = (void *) arg0;
  temp_r30 = temp_r31;
  new_var2 = (int) temp_r30;
  temp_r31 = (saddr)get_class_attack_template((TObjPlayer *)new_var);
  set_params__10TObjPlayerFPvPvPviPv((void *) arg1, new_var, TObjPlayer::get_class_stat_entry((u8 *)new_var), (AttackParams *)temp_r31, (ActorParamBlock *)new_var2);
  return 1;
}
#pragma pop

void apply_speed_scale__10TObjPlayerFif(saddr actor, f32 farg0) {
    f32 var_f1;

    if (((s32 (*)(void))is_flag30_8_set__10TObjPlayerFi)() != 0) {
        var_f1 = TObjPlayer__data_805DC28C * farg0;
    } else {
        var_f1 = farg0;
    }
    ((TObjMotion *)actor)->set_override_speed(var_f1);
}

s32 calc_scaled_value__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (((s32 (*)(void))is_flag30_10_set__10TObjPlayerFi)() != 0) {
        return (s32) (lbl_805DC280 * (lbl_805DC284 * (lbl_805DC288 * (f32) rand())));
    }
    return arg1;
}

s32 TObjPlayer::get_next_level_exp() {
    s32 actor_level_index;
    s32 max_level;
    max_level = TObjPlayer::get_max_level();
    if (this->get_actor_level_index() >= max_level) {
        return 0;
    }
    actor_level_index = this->get_actor_level_index();
    return TObjPlayer::get_current_state_field(get_class_index__10TObjPlayerFv(reinterpret_cast<u8 *>(this)), actor_level_index + 1);
}

void TObjPlayer::vfunc_78(saddr arg1) {
    s32 spC;
    s32 sp8;

    if ((this == 0) || (obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_12_3();
        *(s16 *)((s8 *)&sp8 + 2) = this->get_entity_id();
        obj_copyVec2_0((u8 *)&spC, (u8 *)arg1);
        ((TObjPlayer *)(&sp8))->reinit_update_sub4_and_send();
    }
}

void handle_6x0C_add_or_remove_status_effect(void *command) {
    Eff_801B2D88 e;
    ((TObjPlayer *)(&e))->set_code_12_3();
    TObjPlayer__sub_801C092C(&e, command);
    apply_status_effect__10TObjPlayerFPv(&e);
    if (fn_8036B770(&e) != 0) {
        u32 p = (uaddr)get_player_by_client_id(e.f2);
        if (p != 0) {
            Pair_801B2D88 q;
            q.a = e.f4;
            q.b = e.f8;
            ((void (*)(u32, Pair_801B2D88 *))dispatch_status_effect_msg__10TObjPlayerFUiPv)(p, &q);
        }
    }
}

s32 clear_negative_status_effects__10TObjPlayerFi(s32 arg0) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x0E_clear_negative_status_effects(s32 command) {
    Eff_801B2CE4 e;
    ((TObjPlayer *)(&e))->set_code_14_1();
    ((void (*)(void *, s32))clear_negative_status_effects__10TObjPlayerFi)(&e, command);
    bswap_g_client_id_header(&e);
    if (validate_6x0E_clear_negative_status_effects((G_ClientIDHeader *)&e) != 0) {
        TObjPlayer *p = get_player_by_client_id(e.f2);
        if (p != 0) {
            p->clear_harmful_statuses();
        }
    }
}

void send_code_13_3__10TObjPlayerFii(saddr arg0, saddr arg1) {
    s32 spC;
    s32 sp8;

    if ((arg0 == 0) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_13_3();
        *(s16 *)((s8 *)&sp8 + 2) = ((TObjBase *)(arg0))->get_entity_id();
        obj_copyVec2_0((u8 *)&spC, (u8 *)arg1);
        ((TObjPlayer *)(&sp8))->update_and_send();
    }
}

void handle_6x0D_add_or_remove_status_effect(void *command) {
    Eff_801B2C04 e;
    ((TObjPlayer *)(&e))->set_code_13_3();
    ((TObjPlayer *)(&e))->copy_6x0d_status_effect_packet(command);
    ((TObjPlayer *)(&e))->bswap_status_effect();
    if (fn_8036B748(&e) != 0) {
        u32 p = (uaddr)get_player_by_client_id(e.f2);
        if (p != 0) {
            Pair_801B2C04 q;
            q.a = e.f4;
            q.b = e.f8;
            remove_status_effect__10TObjPlayerFUiPv(p, &q);
        }
    }
}

void dispatch_status_effect_msg__10TObjPlayerFUiPv(uaddr player, Pair_801B2AE8 *msg) {
    switch (msg->a) {
    case 15:
        ((TObjPlayer *)player)->apply_poison_status();
        break;
    case 16:
        ((TObjPlayer *)player)->apply_paralysis();
        break;
    case 17:
        ((TObjPlayer *)player)->apply_slow_status();
        break;
    case 18:
        ((TObjPlayer *)player)->apply_confusion_status();
        break;
    case 3:
        ((TObjPlayer *)player)->apply_shock_status();
        break;
    case 2:
        ((TObjPlayer *)player)->apply_movement_ailment(0);
        break;
    case 7:
        ((TObjPlayer *)player)->clear_harmful_statuses();
        break;
    case 9:
    case 11:
        {
            Pair_801B2AE8 tmp = *msg;
            ((TObjPlayer *)player)->apply_attack_stat_status(&tmp);
        }
        break;
    case 10:
    case 12:
        {
            Pair_801B2AE8 tmp2 = *msg;
            ((TObjPlayer *)player)->apply_defense_stat_status(&tmp2);
        }
        break;
    }
}

void remove_status_effect__10TObjPlayerFUiPv(uaddr arg0_, Pair_801B2C04 *arg1_) {
    u8 *arg0 = (u8 *)arg0_;
    s32 *arg1 = (s32 *)arg1_;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    f32 temp_f31_4;
    f32 temp_f31_5;
    s32 temp_r0;
    f32 v;

    temp_r0 = *arg1;
    switch (temp_r0) {
    case 0:
        ((TObjChara *)arg0)->actorFlags = (s32) (((TObjChara *)arg0)->actorFlags & 0xFFFFFFFC);
        temp_f31 = -((TObjChara *)arg0)->get_status_effect_amount(0);
        v = ((TObjChara *)arg0)->get_base_evp();
        v *= temp_f31;
        ((TObjChara *)arg0)->adjust_evp((s32) v);
        ((TObjChara *)arg0)->status_effects[0].clear();
        return;
    case 1:
        ((TObjChara *)arg0)->actorFlags = (s32) (((TObjChara *)arg0)->actorFlags & 0xFFFFFFC3);
        temp_f31_2 = -((TObjChara *)arg0)->get_status_effect_amount(1);
        v = ((TObjChara *)arg0)->get_base_evp();
        v *= temp_f31_2;
        ((TObjChara *)arg0)->adjust_evp((s32) v);
        ((TObjChara *)arg0)->status_effects[1].clear();
        return;
    case 2:
        temp_f31_3 = -((TObjChara *)arg0)->get_status_effect_amount(2);
        v = ((TObjChara *)arg0)->get_base_atp();
        v *= temp_f31_3;
        ((TObjChara *)arg0)->adjust_atp((s32) v);
        temp_f31_4 = -((TObjChara *)arg0)->get_status_effect_amount(2);
        v = ((TObjChara *)arg0)->get_base_atp_range();
        v *= temp_f31_4;
        ((TObjChara *)arg0)->adjust_atp_range((s32) v);
        ((TObjChara *)arg0)->status_effects[2].clear();
        return;
    case 3:
        temp_f31_5 = -((TObjChara *)arg0)->get_status_effect_amount(3);
        v = ((TObjChara *)arg0)->get_base_dfp();
        v *= temp_f31_5;
        ((TObjChara *)arg0)->adjust_dfp((s32) v);
        ((TObjChara *)arg0)->status_effects[3].clear();
        return;
    }
}

void TObjPlayer::cancel_status_effects() {
#define arg0 ((u8 *)((Pl_801B0B88 *)this))
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    f32 temp_f31_4;
    f32 temp_f31_5;
    f32 v;
    ((TObjChara *)arg0)->actorFlags = (s32) (((TObjChara *)arg0)->actorFlags & 0xFFFFFFFC);
    temp_f31 = -((TObjChara *)arg0)->get_status_effect_amount(0);
    v = ((TObjChara *)arg0)->get_base_evp();
    ((TObjChara *)arg0)->adjust_evp((s32) (v * temp_f31));
    ((TObjChara *)arg0)->status_effects[0].clear();
    ((TObjChara *)arg0)->actorFlags = (s32) (((TObjChara *)arg0)->actorFlags & 0xFFFFFFC3);
    temp_f31_2 = -((TObjChara *)arg0)->get_status_effect_amount(1);
    v = ((TObjChara *)arg0)->get_base_evp();
    ((TObjChara *)arg0)->adjust_evp((s32) (v * temp_f31_2));
    ((TObjChara *)arg0)->status_effects[1].clear();
    temp_f31_3 = -((TObjChara *)arg0)->get_status_effect_amount(2);
    v = ((TObjChara *)arg0)->get_base_atp();
    ((TObjChara *)arg0)->adjust_atp((s32) (v * temp_f31_3));
    temp_f31_4 = -((TObjChara *)arg0)->get_status_effect_amount(2);
    v = ((TObjChara *)arg0)->get_base_atp_range();
    ((TObjChara *)arg0)->adjust_atp_range((s32) (v * temp_f31_4));
    ((TObjChara *)arg0)->status_effects[2].clear();
    temp_f31_5 = -((TObjChara *)arg0)->get_status_effect_amount(3);
    v = ((TObjChara *)arg0)->get_base_dfp();
    ((TObjChara *)arg0)->adjust_dfp((s32) (v * temp_f31_5));
    ((TObjChara *)arg0)->status_effects[3].clear();
}
#undef arg0

s32 is_flag30_8_set__10TObjPlayerFi(saddr actor) {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return ((TObjCollidable *)actor)->test_actor_flags(8);
    }
    return 0;
}

s32 is_flag30_10_set__10TObjPlayerFi(saddr actor) {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return ((TObjCollidable *)actor)->test_actor_flags(0x10);
    }
    return 0;
}

s32 TObjPlayer::check_flag30_bit20() {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return test_actor_flags(0x20);
    }
    return 0;
}

s32 TObjPlayer::update_poison_status() {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_poison_status();
}

s32 TObjPlayer::update_action_hold_status() {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_action_hold_status();
}

s32 TObjPlayer::update_slow_status() {
    saddr player = (saddr)this;
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (((TObjPlayer *)player)->is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_slow_status();
}

s32 TObjPlayer::update_flag30_timer() {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_flag30_timer();
}

s32 TObjPlayer::update_movement_status() {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_movement_status();
}

s32 TObjPlayer::update_shock_clock() {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (is_body_collision_inactive() != 0)) {
        return 0;
    }
    return TObjChara::update_shock_clock();
}

s32 TObjPlayer::update_attack_stat_status() {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return TObjChara::update_attack_stat_status();
    }
    return 0;
}

s32 TObjPlayer::update_defense_stat_status() {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return TObjChara::update_defense_stat_status();
    }
    return 0;
}

void TObjPlayer::sync_status_effect_flags() {
    TObjPlayer *self = this;
    Item_801B21AC item;
    u32 diff;
    item.val = TObjPlayer__data_805DC278;
    diff = (self->m_3cc ^ self->actorFlags) & 0x3F;
    if (diff != 0) {
        if (diff & 3) {
            if (self->actorFlags & 3) {
                if (self->actorFlags & 1) {
                    item.id = 0xF;
                }
                if (self->actorFlags & 2) {
                    item.id = 0x10;
                }
                ((VObj_801B21AC *)this)->m76(item);
            } else {
                item.id = 0;
                ((s32 (*)(void *, Item_801B21AC))send_code_13_3__10TObjPlayerFii)(this, item);
            }
        }
        if (diff & 0x3C) {
            if (self->actorFlags & 0x3C) {
                if (self->actorFlags & 8) {
                    item.id = 0x11;
                }
                if (self->actorFlags & 0x10) {
                    item.id = 0x12;
                }
                if (self->actorFlags & 0x20) {
                    item.id = 2;
                }
                if (self->actorFlags & 4) {
                    item.id = 3;
                }
                ((VObj_801B21AC *)this)->m76(item);
            } else {
                item.id = 1;
                ((s32 (*)(void *, Item_801B21AC))send_code_13_3__10TObjPlayerFii)(this, item);
            }
        }
        if (diff & 0x40) {
            item.id = 7;
            ((VObj_801B21AC *)this)->m76(item);
        }
        self->m_3cc = self->actorFlags;
    }
}

void TObjPlayer::resend_status_effects() {
    Item_801B2014 item;
    item.val = TObjPlayer__data_805DC278;
    if (this->test_actor_flags(1) != 0) {
        item.id = 0xF;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(((saddr)this), item);
    }
    if (this->test_actor_flags(2) != 0) {
        item.id = 0x10;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(((saddr)this), item);
    }
    if (this->test_actor_flags(0x40) != 0) {
        item.id = 7;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(((saddr)this), item);
    }
    if (this->test_actor_flags(8) != 0) {
        item.id = 0x11;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(((saddr)this), item);
    }
    if (this->test_actor_flags(0x10) != 0) {
        item.id = 0x12;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(((saddr)this), item);
    }
    if (this->test_actor_flags(0x20) != 0) {
        item.id = 2;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(((saddr)this), item);
    }
    if (this->test_actor_flags(4) != 0) {
        item.id = 3;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(((saddr)this), item);
    }
}

}

void send_6x24_teleport_player(u16 slot, const Vec *pos, s32 heading) {
    struct pkt_801B1FA4 pkt;
    ((TObjPlayer *)(&pkt))->init_cmd_6x24();
    TObjChara *chara = (TObjChara *)get_player_by_client_id(slot);
    if (chara != NULL && chara->obj_isState2_324() == 0) {
        pkt.slot = slot;
        pkt.heading = heading;
        VecCopy(&pkt.pos, pos);
        ((TObjPlayer *)(&pkt))->send_lobby_update();
    }
}

extern "C" {

void handle_6x24_teleport_player(saddr command) {
    Pkt_801B1EE0 pkt;
    uaddr player;
    ((TObjPlayer *)(&pkt))->init_cmd_6x24();
    TObjPlayer__sub_801C07B4((u8 *)&pkt, (u8 *)command);
    ((TObjPlayer *)(&pkt))->byteswap_packet_body();
    if (validate_6x24_teleport_player((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    player = (uaddr)get_player_by_client_id(pkt.slot);
    if (player == 0) {
        return;
    }
    ((TObjBase *)player)->set_position_from(pkt.pos);
    *(s32 *)(player + 0x60) = *(s32 *)(player + 0x3F0) = pkt.heading;
    ((TObjChara *)player)->calc_attach_pos();
    ((TObjPlayer *)player)->set_flag_4000();
    ((TObjPlayer *)player)->refresh_equipment_slot();
    TPlyOnCountOver::create(((TObjBase *)player)->get_entity_id(), 2, clear_flag_4000_callback__10TObjPlayerFv);
    if (TObjPlayer::is_locally_controlled((void *)(player)) != 0) {
        reset_cameras_to_actor(reinterpret_cast<TObjPlayer *>(player), 0);
    }
}

void send_6x2F_change_player_hp(s32 id, s32 client, s32 hp) {
    Msg_801B1E54 m;

    TObjChara *chara = (TObjChara *)get_player_by_client_id(id & 0xFFFF);
    if (((chara == NULL) || (chara->obj_isState2_324() == 0)) && ((get_player_by_client_id(client & 0xFFFF) == NULL) || (((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0))) {
        ((TObjPlayer *)(&m))->init_6x2F_packet_header();
        m.a = id;
        m.b = 0;
        m.c = hp;
        m.d = client;
        TObjPlayer__sub_801C0734(&m);
    }
}

void handle_6x2F_change_player_hp(saddr command) {
    Pkt_801B1D8C pkt;
    uaddr player;
    ((TObjPlayer *)(&pkt))->init_6x2F_packet_header();
    TObjPlayer__sub_801C06BC(&pkt, (void *)command);
    ((TObjPlayer *)(&pkt))->bswap_change_hp_packet();
    if (validate_6x2F_change_player_hp((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    player = (uaddr)get_player_by_client_id(pkt.client);
    if (player == 0) {
        return;
    }
    if (((TObjCollidable *)player)->test_actor_flags(0x800) != 0) {
        return;
    }
    switch (pkt.type) {
    case 0:
        ((TObjPlayer *)player)->set_hp_clamped(pkt.amount);
        break;
    case 1:
        add_actor_hp((TObjChara *)player, pkt.amount);
        break;
    case 2:
        add_actor_hp((TObjChara *)player, *(s16 *)(player + 0x2B8));
        break;
    }
}

s32 TObjPlayer::is_in_tl03_state() {
    int var_r31;

    var_r31 = 0;
    if ((check_flag_4() == 0) && ((u32) *(u32 *)((s8 *)this + 0x10) == (uaddr) tl_03)) {
        var_r31 = 1;
    }
    return (u8)((u8)var_r31);
}

void TObjPlayer::play_sound_if_on_floor(s32 sound_id) {
    if (((s32 (*)(void))is_on_current_floor__10TObjPlayerFi)() != 0) {
        play_sound_effect(sound_id, static_cast<const Vec *>(get_position_ptr()), 0, 0);
    }
}

void TObjPlayer::send_local_player_invisible() {
    Ctx_801B1C8C ctx;
    void *p;
    fn_801C0630(&ctx);
    p = get_local_player();
    if (p != NULL && (p == NULL || ((TObjChara *)p)->obj_isState2_324() == 0)) {
        ctx.f2 = ((TObjBase *)(p))->get_entity_id();
        fn_801C0644(&ctx);
    }
}

void handle_6x22_set_player_invisible(void *command) {
    Pkt_801B1C00 pkt;
    fn_801C0630((Ctx_801B1C8C *)&pkt);
    set_invisible__10TObjPlayerFv(&pkt, command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x22_set_player_invisible((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.client);
        if (p != NULL && ((TObjPlayer *)p)->check_flag_4() == 0) {
            ((TObjPlayer *)p)->set_state_flags(0x40000);
            ((TObjPlayer *)p)->deactivate_body_collision();
            ((TObjPlayer *)p)->clear_flag_200000();
        }
    }
}

void TObjPlayer::send_local_player_visible() {
    Ctx_801B1BA4 ctx;
    void *p;
    init_packet_6x23_set_player_visible(&ctx);
    p = get_local_player();
    if (p != NULL && (p == NULL || ((TObjChara *)p)->obj_isState2_324() == 0)) {
        ctx.f2 = ((TObjBase *)(p))->get_entity_id();
        send_6x23_set_player_visible(&ctx);
    }
}

s32 handle_set_visible__10TObjPlayerFi(s32 arg0) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x23_set_player_visible(void *command) {
    Pkt_801B1B08 pkt;
    init_packet_6x23_set_player_visible((Ctx_801B1BA4 *)&pkt);
    ((s32 (*)(Pkt_801B1B08 *, void *))handle_set_visible__10TObjPlayerFi)(&pkt, command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x23_set_player_visible((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.client);
        if (p != NULL) {
            ((TObjPlayer *)p)->clear_state_flags(0x40000);
        }
    }
}
}

int TObjPlayer::check_flag_40000() {
    return check_flag(0x40000);
}

void TObjPlayer::for_each_player_slot(void (*callback)(void *)) {
    s32 i;
    void **p;
    p = (void **)((s32 *)&player_slot_table);
    for (i = 0; i < 12; i++, p++) {
        if (*p != NULL) {
            callback(*p);
        }
    }
}

void foreach_player__10TObjPlayerFv(s32 (*arg0)(u32)) {
    s32 (*var_r27)(u32);
    s32 i;
    s32 *var_r30;
    s32 var_r31;
    uaddr player;

    var_r27 = arg0;
    i = 0;
    var_r30 = ((s32 *)&player_slot_table);
    var_r31 = 0;
    do {
        player = var_r30[var_r31];
        if ((player != 0U) && (TObjPlayer::is_locally_controlled((void *)(player)) != 0)) {
            var_r27(player);
        }
        i += 1;
        var_r31 += 1;
    } while (i < 0xC);
}

s32 reset_volopt_state__10TObjPlayerFv(TObjPlayer *player) { return is_item_area_enabled(player->get_area()); }

void TObjPlayer::play_phase_transition_sound(saddr child) {
    if (((get_main_phase() == 0xE) || (get_main_phase() == 0xF)) && (TFontSmallLobby::is_lobby_floor_15() != 0)) {
        draw_chunk_object((void *)child);
        return;
    }
    draw_chunk_object((void *)child);
}

void unequip_by_field326__10TObjPlayerFPv(void *player) {
    TObjPlayer__sub_801B18C0((saddr)player, (u32)((TObjPlayer *)player)->mode);
}

void TObjPlayer__sub_801B18C0(saddr player, u32 arg1) {
    switch (arg1) {
    default:
        ((TObjPlayer *)player)->get_idle_animation();
        return;
    case 2:
    case 3:
        TObjPlayer__sub_801CFBFC((u8 *)player);
        return;
    case 4:
        ((TObjPlayer *)player)->get_vobj_state_28();
        return;
    case 5:
        ((TObjPlayer *)player)->call_subobject_m15();
        return;
    case 6:
        ((TObjPlayer *)player)->get_state();
        return;
    case 7:
        ((TObjPlayer *)player)->get_model_state();
        return;
    case 8:
        ((TObjPlayer *)player)->get_status();
        return;
    case 9:
        ((TObjPlayer *)player)->query_equip();
        return;
    case 10:
        ((TObjPlayer *)player)->query_child_state();
        return;
    case 11:
        ((TObjPlayer *)player)->call_obj_vt26();
        return;
    case 12:
        ((TObjPlayer *)player)->get_weapon_stat_c();
        return;
    case 13:
        ((TObjPlayer *)player)->call_model_m24();
        return;
    case 14:
        ((TObjPlayer *)player)->get_action_animation();
        return;
    case 15:
        ((TObjPlayer *)player)->get_model_field_m25();
        return;
    }
}

int TObjPlayer::get_field_828() { return ((int (*)(void*))get_type__10TObjPlayerFPv)((char*)this + 0x828); }

void TObjPlayer::send_enable_pk_mode(TObjPlayer *player) {
    s8 sp8[8];

    if ((player == NULL) || (player->obj_isState2_324() == 0)) {
        init_packet_6x1B_enable_pk_mode_for_player((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = player->get_entity_id();
        send_6x1B_enable_pk_mode_for_player((s32 *)&sp8);
    }
}

void* draw_font__10TObjPlayerFPv(void* p) { ((int (*)(void*))copy_subcommand_header)(p); return p; }

void handle_6x1B_enable_pk_mode_for_player(void *command) {
    struct pkt_801B1674 pkt;
    init_packet_6x1B_enable_pk_mode_for_player(&pkt);
    ((s32 (*)(s32, void *))draw_font__10TObjPlayerFPv)((s32)((saddr) &pkt), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x1B_enable_pk_mode_for_player((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_state_flag_6043();
        }
    }
}

void TObjPlayer::set_state_flag_6043() {
    if (this->obj_isState3_324() != 0) {
        this->m_698 = 0x6043;
    } else {
        this->m_698 = 0x2003;
    }
    set_player_pk_mode_flag(((u8 *)this) + 0x828);
}

void TObjPlayer::send_disable_pk_mode(TObjPlayer *player) {
    s8 sp8[8];

    if ((player == NULL) || (player->obj_isState2_324() == 0)) {
        init_packet_6x1C_disable_pk_mode_for_player((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = player->get_entity_id();
        send_6x1C_disable_pk_mode_for_player((s32 *)&sp8);
    }
}

s32 TObjPlayer::update_small_font(saddr arg0, void * command) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x1C_disable_pk_mode_for_player(void *command) {
    struct pkt_801B1674 pkt;
    init_packet_6x1C_disable_pk_mode_for_player(&pkt);
    TObjPlayer::update_small_font((s32)((saddr) &pkt), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x1C_disable_pk_mode_for_player((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_state_flag_604B();
        }
    }
}

void TObjPlayer::set_state_flag_604B() {
    if (this->obj_isState3_324() != 0) {
        this->m_698 = 0x604B;
    } else {
        this->m_698 = 0x200B;
    }
    fn_801C19E8(((u8 *)this) + 0x828);
}

void *TObjPlayer::find_revival_item() {
    TItemData item;
    item.init();
    item.data1.data_u8[0] = 1;
    item.data1.data_u8[1] = 2;
    item.data1.data_u8[2] = 0x52;
    void *found = inventory_objects->set_mode_and_refresh_object(&item);
    if (found == NULL) {
        item.init();
        item.data1.data_u8[0] = 3;
        item.data1.data_u8[1] = 9;
        found = inventory_objects->set_mode_and_refresh_object(&item);
    }
    return found;
}
extern "C" {
s32 TObjPlayer::try_pickup_item() {
    saddr owner_if_alive;

    if (this->obj_isState2_324() != 0) {
        return 0;
    }
    void *node;
    if ((node = this->find_revival_item()) != NULL) {
        owner_if_alive = (saddr)((TItemList *)node)->get_owner_if_alive();
        if (owner_if_alive == 0) {
            return 0;
        }
        ((s32 (*)(s32))recover_full__10TObjPlayerFPv)((saddr)this);
        ((FlagWord *)((saddr)this + 0x858))->set(4);
        ((s32 (*)(s32, s32, s32))send_6x29_delete_item__10TObjPlayerFPvii)((saddr)this, ((TItem *)owner_if_alive)->get_item_id(), 1);
        return 1;
    }
    return 0;
}

void TObjPlayer::draw() {
    push_matrix();
    translate_matrix_vec3((u8 *)(0), (u8 *)(this->get_position_ptr()));
    rotate_matrix_y(0, this->rotation_y);
    calc_joint_matrices(this->current_motion, *(f32 *)&TObjPlayer__data_805DC278, *(s32 *)((s8 *)this + 0xE0));
    pop_matrix();
}

void TObjPlayer::draw(void *player, f32 at_frame) {
    push_matrix();
    translate_matrix_vec3((u8 *)(0), (u8 *)(((TObjPlayer *)player)->get_position_ptr()));
    rotate_matrix_y(0, ((TObjPlayer *)player)->rotation_y);
    ((TObjPlayer *)player)->calc_joint_matrices(((TObjPlayer *)player)->current_motion, at_frame, *(s32 *)((s8 *)player + 0xE0));
    pop_matrix();
}

void TObjPlayer::spawn_effect(saddr player) {
    if (TObjPlayer::is_locally_controlled((void *)player) != 0) {
        start_pad_rumble_client(0xC0, 0xF, ((TObjBase *)(player))->get_entity_id());
    }
}

void TObjPlayer::send_field_state() {
    if ((this->is_body_collision_inactive() == 0) && (TObjPlayer::check_flag_800000(this) == 0)) {
        ((TObjPlayer *)((saddr)this + 0x384))->check_hit_by_id_431_from_packet();
    }
    this->play_sound_if_on_floor(0x42D08);
}

s32 TObjPlayer::is_actor_cadence_frame(s32 arg1) {
    return (u8) ((actor_frame_tick & arg1) == get_entity_id());
}

void TObjPlayer::deactivate_body_collision() {
    set_actor_flags(0x02000000U);
    this->clear_player_status_flag(0, 1U);
}

void TObjPlayer::activate_body_collision() {
    clear_actor_flags((u32)0x02000000U);
    set_indexed_flags(0, 1);
}

s32 TObjPlayer::is_body_collision_inactive() {
    return test_actor_flags(0x02000000);
}

void TLobby__sub_801B1254(saddr arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
        init_packet_6x7A_enable_stealth_suit_effect((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((TObjBase *)arg0)->get_entity_id();
        ((TLobby *)((s32 *)&sp8))->cleanup_small_font();
    }
}

s32 TFontSmallLobby__sub_801B1224(s32 arg0, void * _w1) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x7A_enable_stealth_suit_effect(void *command) {
    struct pkt_801B1674 pkt;
    init_packet_6x7A_enable_stealth_suit_effect(&pkt);
    TFontSmallLobby__sub_801B1224((s32)((s32)((saddr) &pkt)), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x7A_enable_stealth_suit_effect((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_stealth_suit_flags();
        }
    }
}

void TObjPlayer::set_stealth_suit_flags() {
    set_state_flags(0x800000U);
    set_indexed_flags(0, 0x08000000);
}

void draw_small_label__15TFontSmallLobbyFi(saddr arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
        init_packet_6x7B_disable_stealth_suit_effect((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((TObjBase *)arg0)->get_entity_id();
        send_6x7B_disable_stealth_suit_effect((s32 *)&sp8);
    }
}

s32 TFontSmallLobby::disable_stealth_suit_effect(s32 arg0, void * command) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x7B_disable_stealth_suit_effect(void *command) {
    struct pkt_801B1674 pkt;
    init_packet_6x7B_disable_stealth_suit_effect(&pkt);
    TFontSmallLobby::disable_stealth_suit_effect((s32)((s32)((saddr) &pkt)), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x7B_disable_stealth_suit_effect((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->clear_stealth_suit_flags();
        }
    }
}

void TObjPlayer::clear_stealth_suit_flags() {
    this->clear_state_flags(0x800000U);
    this->clear_player_status_flag(0, 0x08000000);
}

s32 TObjPlayer::check_flag_800000(void *player) {
    return static_cast<TObjPlayer *>(player)->check_flag(0x800000);
}

void TObjPlayer::refresh_equipment_slot() {
    u8 *temp_r3;
    temp_r3 = (u8 *)((TObjPlayer *)this)->activate_d04_slot();
    if (temp_r3 != NULL) {
        ((TItem *)temp_r3)->snap_to_owner();
    }
}

void TObjPlayer::update_photon_chair() {
    ((TObjPlayer *)((saddr)this + 0x634))->enter_battle_state();
    if (this->obj_isState2_324() != 0) {
        this->clear_flag_400000();
    }
}

s32 TObjPlayer::add_actor_exp(s32 arg1) {
    s32 temp_r31;
    s32 temp_r3;
    player_stats *stat_block;

    if (is_current_area_item_enabled() == 0) {
        return 0;
    }
    stat_block = this->stat_block;
    temp_r31 = stat_block->exp;
    temp_r3 = TObjPlayer__sub_801D91B8(this, stat_block);
    temp_r31 = temp_r31 + arg1;
    if (temp_r31 > temp_r3) {
        temp_r31 = temp_r3;
    }
    if (temp_r31 < 0) {
        temp_r31 = 0;
    }
    this->stat_block->exp = temp_r31;
    return 1;
}

s32 TTecCtrl::is_technique_ready() {
    int var_r31;

    var_r31 = 0;
    if ((TObjPlayer::get_player_count() == 1) && (TObjPlayer::get_rule_field_0() == 1)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

void TLobby::apply_battle_rules_to_players() {
    s32 i;
    s32 *q;
    Pl_801B0B88 *p;
    saddr j;
    TItem *weapon;
    s32 lv;
    q = ((s32 *)&lobby_rule_settings);
    for (i = 0; i < 0xC; i++) {
        p = (Pl_801B0B88 *)get_player_by_client_id(i);
        if (p == NULL) {
            continue;
        }
        ((TLobby *)(p->f754))->update_all_children();
        if (((TLobby *)q)->get_rule_field_0() == 1) {
            ((TObjPlayer *)p)->set_state_flag_6043();
            if (TObjPlayer::is_locally_controlled((void *)(p)) != 0) {
                lobby_player_count = 1;
            }
        } else {
            return;
        }
        switch (fn_801D71D0(q)) {
        case 1:
        case 2:
        case 3:
            ((TPlyItem *)(p->fD00))->set_globals_and_update(reinterpret_cast<TObjPlayer *>(p), 0);
            ((TPlyItem *)(p->fD00))->set_globals_and_update(reinterpret_cast<TObjPlayer *>(p), 1);
            break;
        }
        switch (fn_801D719C(q)) {
        case 1:
            ((TPlyItem *)(p->fD00))->set_globals_and_update(reinterpret_cast<TObjPlayer *>(p), 2);
            break;
        }
        if ((weapon = TObjPlayer::get_equipped_weapon(p)) != NULL && weapon->check_equip_requirements((TObjPlayer *)p, (s16 *)0) == 0) {
            reinterpret_cast<TObjPlayer *>(p)->unequip_item(weapon);
        }
        switch (fn_801D7168(q)) {
        case 1:
        case 2:
            ((TPlyItem *)(p->fD00))->set_globals_and_update(reinterpret_cast<TObjPlayer *>(p), 3);
            break;
        }
        if (fn_801D7134(q) == 1) {
            for (j = 0; j < 4; j++) {
                TObjPlayer__sub_801C5780(p->f7C4, get_validated_array_value(q, j), j);
            }
        }
        switch (TLobby__sub_801D7100(q)) {
        case 2:
            fn_801C19E0(p->f754, fn_801D6DB0(q));
            break;
        }
        switch (((TLobby *)q)->clamp_rule_value_2()) {
        case 1:
            ((TObjPlayer *)p)->sub_801BEE2C(0);
            ((TObjPlayer *)p)->sub_801BEE24(0);
            ((TObjPlayer *)p)->apply_battle_level_reset(((TLobby *)q)->clamp_player_index());
            break;
        }
        lv = TLobby__sub_801D6DDC(q);
        switch (fn_801D7204(q)) {
        case 1:
            ((TObjPlayer *)(p->f428))->copy_all_technique_entries((void *)0xFF);
            ((TObjPlayer *)(p->f428))->set_all_technique_levels((void *)0xFF);
            break;
        case 2:
            ((TObjPlayer *)(p->f428))->copy_all_technique_entries((void *)0x1D);
            update_all_units__10TObjPlayerFll(p->f428, lv);
            break;
        }
        ((TObjPlayer *)p)->set_flag_drop_weapon_on_death();
        switch (((TLobby *)q)->normalize_battle_rule_value_b()) {
        case 1:
            TObjPlayer::disable_drop_weapon_on_death(p);
            break;
        }
        if (((TLobby *)q)->normalize_battle_rule_value() == 1 && TObjPlayer::is_locally_controlled((void *)(p)) != 0) {
            ((TObjPlayer *)(p->f424))->set_flags_bit2();
        }
        if (TLobby__sub_801D6FFC(q) != 0) {
            ((TObjPlayer *)p)->set_meseta(0);
        }
        if (((TLobby *)q)->clamp_value_below_2() == 1) {
            fn_801C5420(p->f7C8, TObjPlayer__sub_801D6D28(q));
        }
        if (TLobby__sub_801D6F94(q) == 1) {
            TLobby__sub_801D4C28((TPlyItem *)p->fD00, reinterpret_cast<TObjPlayer *>(p), 3, 9);
        }
        ((TObjPlayer *)p)->set_flag_4096();
        ((void (*)(Pl_801B0B88 *))recover_full__10TObjPlayerFPv)(p);
        ((TObjPlayer *)p)->cancel_status_effects();
        ((TObjPlayer *)(&lobby_char_slot_array[i]))->copy_lobby_header((saddr)p);
    }
}

s32 TObjPlayer::check_switch_available(s32 item_id) {
    if (TTecCtrl::is_technique_ready() != 0) {
        if (fn_801D71D0(((s32 *)&lobby_rule_settings)) == 2) {
            TItemList *slot = static_cast<TItemList *>(inventory_objects->start_inventory_update(item_id));
            if (slot == NULL) {
                return 0;
            }
            TItem *item_owner = slot->get_owner_if_alive();
            if (item_owner == NULL) {
                return 0;
            }
            if (item_owner->get_item_type() == 0) {
                return 0;
            }
            goto block_8;
        }
block_8:
        if (fn_801D719C(((s32 *)&lobby_rule_settings)) == 1) {
            TItemList *slot = static_cast<TItemList *>(inventory_objects->start_inventory_update(item_id));
            if (slot == NULL) {
                return 0;
            }
            TItem *item_owner = slot->get_owner_if_alive();
            if (item_owner == NULL) {
                return 0;
            }
            if (item_owner->get_item_type() == 2) {
                return 0;
            }
            goto block_15;
        }
        goto block_15;
    }
block_15:
    return 1;
}

void TLobby__sub_801B09A4(void) {
    TObjPlayer *players[12];
    s32 i;
    TObjPlayer *p;
    shared_state_flags |= 1;
    for (i = 0; i < 12; i++) {
        players[i] = NULL;
    }
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            players[i] = p;
            delete p;
        }
    }
    for (i = 0; i < 12; i++) {
        if (players[i] != NULL) {
            create_player_instance__10TObjPlayerFll(i, &lobby_char_slot_array[i]);
            TWindowCtrl::enable_client_main_menu(i);
        }
    }
    shared_state_flags &= ~1;
}

s32 TLobby::count_members() {
    void **p = player_slot_table;
    s32 n = 0;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (*p) {
            n++;
        }
        p++;
    }
    return n;
}

void TLobby::send_font_state(saddr arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
        init_packet_6x81_disable_drop_weapon_on_death((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((TObjBase *)arg0)->get_entity_id();
        ((TFontSmallLobby *)((s32 *)&sp8))->send_font_state_msg();
    }
}

s32 TLobby__sub_801B08F0(s32 arg0, void * _w1) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x81_disable_drop_weapon_on_death(void *command) {
    struct pkt_801B1674 pkt;
    init_packet_6x81_disable_drop_weapon_on_death(&pkt);
    TLobby__sub_801B08F0((s32)((s32)((saddr) &pkt)), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x81_disable_drop_weapon_on_death((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            TObjPlayer::disable_drop_weapon_on_death(p);
        }
    }
}

void TObjPlayer::disable_drop_weapon_on_death(void *player) {
    ((TObjPlayer *)player)->set_state_flags(0x01000000);
}

void TLobby::send_field1c_packet(saddr arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
        init_packet_6x82_enable_drop_weapon_on_death((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((TObjBase *)arg0)->get_entity_id();
        send_6x82_enable_drop_weapon_on_death((s32 *)&sp8);
    }
}

s32 TLobby__sub_801B07E0(s32 arg0, void * _w1) {
    copy_subcommand_header();
    return arg0;
}

void handle_6x82_enable_drop_weapon_on_death(void *command) {
    struct pkt_801B1674 pkt;
    init_packet_6x82_enable_drop_weapon_on_death(&pkt);
    TLobby__sub_801B07E0((s32)((s32)((saddr) &pkt)), command);
    bswap_g_client_id_header(&pkt);
    if (validate_6x82_enable_drop_weapon_on_death((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *)get_player_by_client_id(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_flag_drop_weapon_on_death();
        }
    }
}

void TObjPlayer::set_flag_drop_weapon_on_death() {
    clear_state_flags(0x01000000);
}

s32 TObjPlayer::check_flag_01000000(void *player) {
    return static_cast<TObjPlayer *>(player)->check_flag(0x01000000);
}

void handle_6x90_set_player_battle_team(saddr command) {
    struct Cmd_801B0690 cmd;
    u8 *p;
    s32 team;
    init_packet_6x90_set_player_battle_team((u8 *)&cmd);
    TFontSmallLobby__sub_801C03E0(&cmd, (void *)command);
    ((TFontSmallLobby *)(&cmd))->bswap_6x90_set_player_battle_team();
    if (validate_6x90_set_player_battle_team((G_ClientIDHeader *)&cmd) == 0) {
        return;
    }
    p = (u8 *)get_player_by_client_id((u16)cmd.client);
    if (p == NULL) {
        return;
    }
    team = cmd.team;
    set_player_team_id(p + 0x828, team);
    if (team == 1) {
        TMainCursor__sub_801540B8((saddr) p, *(s32 *)((s8 *)p + 0xA4), 0);
    } else {
        TMainCursor__sub_80154098((saddr) p, *(s32 *)((s8 *)p + 0xA4), 0);
    }
}

int TObjPlayer__sub_801B066C(void* p) { return TLobby__sub_801C19D0((char*)p + 0x828); }

void draw_status_line(void *arg0, s32 *str, s32 *arg2, s32 arg3) {
    text_builder_reset();
    text_builder_append((u8 *)str);
    text_builder_append((u8 *)arg2);
    text_builder_append((u8 *)&lbl_805DC27C);
    text_builder_append_int(arg3);
    text_builder_append((u8 *)&lbl_805DC27C);
    TWindowCtrl::init_all((void*)(get_shared_text_buffer()), (void*)0x200);
}

void show_sub_status_window(void *arg0, s32 *str, s32 *arg2) {
    text_builder_reset();
    text_builder_append((u8 *)str);
    text_builder_append((u8 *)arg2);
    text_builder_append((u8 *)&lbl_805DC27C);
    TWindowCtrl::init_all((void*)(get_shared_text_buffer()), (void*)0x200);
}

void draw_player_status(saddr arg0, void *arg1, saddr str) {
    saddr name;

    name = (saddr)((TUnk_804B6C24 *)arg1)->get_name();
    if (name != 0) {
        if (static_cast<TObject *>(arg1)->check_value_equals(lbl_805D3530) != 0) {
            ((s32 (*)(s32, s32, s32, s32))draw_status_line)(arg0, str, name, ((s32 (*)(void *))TObjPlayer__sub_801AFFD0)(arg1));
            return;
        }
        show_sub_status_window((void *)arg0, (s32 *)str, (s32 *)name);
    }
}

extern "C" void fn_801B0480(u8 *player, void *attacker, s32 amount) {
    if (reinterpret_cast<TObject *>(attacker)->check_value_equals(lbl_805D3530) == 0
        || ((TLobby *)lobby_rule_settings)->get_rule_field_a() != 1
        || TLobby__sub_801C19D0(player + 0x828) != TLobby__sub_801C19D0((u8 *)attacker + 0x828)) {
        accumulate_damage_stats((saddr)(player + 0x75C), (saddr)attacker, amount);
        play_sound_effect(0x4004B20A, 0, 0, 0);
    }
}

extern "C" s32 accumulate_damage_stats_at_76c(s32 player, s32 attacker, s32 amount) {
    return accumulate_damage_stats(player + 0x76C, attacker, amount);
}

void record_damage_stats__10TOMineTrapFUiUis(uaddr mine_trap, u32 att, s16 arg2) {
  Pkt_801B0300 pkt;
  u32 player;
  uaddr obj;
  if (TTecCtrl::is_technique_ready() != 0)
  {
    obj = att;
    if ((reinterpret_cast<TObject *>(obj)->check_value_equals(TOMineTrap__data_805D3080) != 0) && (((TOMineTrap *)obj)->get_trap_type() != 0xFFFF))
    {
      obj = ((u32 (*)(void))find_entity_by_id)();
    }
    if (((TObjCollidable *)obj)->test_actor_flags(0x10000000) == 0)
    {
      if (TObjPlayer::is_locally_controlled((void *)(mine_trap)) != 0)
      {
        ((int (*)(u32, u32, s16)) accumulate_damage_stats)(mine_trap + 0x77C, obj, arg2);
      }
    }
    else
      if ((TObjPlayer::is_locally_controlled((void *)(mine_trap)) != 0) && ((mine_trap == 0U) || (((TObjChara *)mine_trap)->obj_isState2_324() == 0)))
    {
      ((int (*)(u32, u32, s16)) accumulate_damage_stats)(mine_trap + 0x77C, obj, arg2);
      if (((TObjBase *)(obj))->get_entity_id() != ((TObjBase *)(mine_trap))->get_entity_id())
      {
        player = (uaddr)get_player_by_client_id(((TObjBase *)(obj))->get_entity_id());
        if (player != 0U)
        {
          ((int (*)(u32, u32, s16)) accumulate_damage_stats)(player + 0x78C, mine_trap, arg2);
        }
      }
      if (TObjPlayer::is_final_phase() != 0)
      {
        ((TFontSmallLobby *)(&pkt))->init_packet_6x8f_battle_damage();
        pkt.a = ((TObjBase *)(obj))->get_entity_id();
        pkt.b = ((TObjBase *)(mine_trap))->get_entity_id();
        pkt.c = arg2;
        send_6x8F_add_battle_damage_scores(&pkt);
      }
    }
  }
}

void handle_6x8E(void) {  }

void apply_camera_shake__10TObjPlayerFiii(saddr player, saddr target, s32 damage) {
    if ((TTecCtrl::is_technique_ready() != 0) && (((TObjCollidable *)target)->test_actor_flags(0x10000000) == 0) && (TObjPlayer::is_locally_controlled((void *)(player)) != 0)) {
        accumulate_damage_stats(player + 0x78C, target, damage);
    }
}

void handle_6x8F_add_battle_damage_scores(saddr command) {
    Pkt_801B01AC pkt;
    u8 *player;
    u8 *target;
    u8 *other;
    ((TFontSmallLobby *)(&pkt))->init_packet_6x8f_battle_damage();
    TFontSmallLobby__sub_801C030C(&pkt, (void *)command);
    ((TFontSmallLobby *)(&pkt))->bswap_battle_damage_packet();
    if (validate_6x8F_add_battle_damage_scores((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    player = (u8 *)get_player_by_client_id((u16)pkt.client);
    if (player == NULL) {
        return;
    }
    target = find_entity_by_id(pkt.target);
    if (target == NULL) {
        return;
    }
    if ((u16)((TObjBase *)(target))->get_entity_id() != (u16)((TObjBase *)(player))->get_entity_id()) {
        accumulate_damage_stats((saddr)(player + 0x78C), (saddr)target, pkt.amount);
    }
    if (((TObjCollidable *)target)->test_actor_flags(0x10000000) == 0) {
        return;
    }
    other = (u8 *)get_player_by_client_id((u16)((TObjBase *)(target))->get_entity_id());
    if (other != NULL) {
        accumulate_damage_stats((saddr)(other + 0x77C), (saddr)player, pkt.amount);
    }
}

void TObjPlayer::record_meseta_pickup(s32 arg1) {
    if (TObjPlayer::is_locally_controlled((void *)this) == 0 || ((u8 (*)(void *))TLobby__sub_801D6FFC)(lobby_rule_settings) != 2 || TTecCtrl::is_technique_ready() == 0) {
        return;
    }
    TObjPlayer__sub_801C19C8(((u8 *)this) + 0x79C, (f32) arg1);
}

s32 TObjPlayer__sub_801AFFD0(u8 *player) {
    f32 v;

    v = (f32)TWindowDuelResult__sub_801C19AC((f32 *)(player + 0x78C));
    v -= (f32)TWindowDuelResult__sub_801C19AC((f32 *)(player + 0x77C));
    v += (f32)TWindowDuelResult__sub_801C19AC((f32 *)(player + 0x75C));
    v -= (f32)TWindowDuelResult__sub_801C19AC((f32 *)(player + 0x76C));
    if (((TObjCollidable *)player)->test_actor_flags(0x800) == 0) {
        v += (f32)obj_getPtr2B0_20(player) * fn_801C19A4(player + 0x79C);
    }
    return (s32)v;
}

int TObjPlayer::get_key_machine_global_state(void* p) { return ((int)get_current_floor_area()); }

void TObjPlayer::sync_current_area() {
    current_area = get_key_machine_global_state(this);
}

void TObjPlayer::sync_current_floor() {
    this->current_floor = get_current_floor();
}

u8 is_on_current_floor__10TObjPlayerFi(saddr player) {
    s32 current_floor;
    s32 temp_r3;
    current_floor = get_current_floor();
    temp_r3 = ((TObjPlayer *)player)->get_floor();
    return (u8) (temp_r3 == current_floor);
}

u8 is_lobby_floor_15__15TFontSmallLobbyFv(void) {
    return (u8) (get_current_floor_area() == AREA_LOBBY);
}

u8 is_volopt_phase_final__10TObjPlayerFv(TObjPlayer *player) {
    return (u8) (player->get_area() == 0xF);
}

u8 is_key_machine_ready__10TObjPlayerFv(void) {
    s32 area;
    s32 var_r0;

    area = get_current_floor_area();
    var_r0 = 0;
    if ((area == AREA_PIONEER2_EP1) || (area == AREA_PIONEER2_EP2)) {
        var_r0 = 1;
    }
    return (u8) var_r0;
}

s32 TObjPlayer::check_technique_castable(saddr player) {
    s32 area;

    if ((TTecCtrl::is_technique_ready() != 0) || (TObjPlayer::is_camera_mode_active() != 0) || (is_boss_area() != 0)) {
        ((TObjPlayer *)player)->set_flag_4096();
        return 0;
    }
    area = get_current_floor_area();
    switch (area) {
    case AREA_PIONEER2_EP1:
    case AREA_LOBBY:
    case AREA_PIONEER2_EP2:
        ((TObjPlayer *)player)->set_flag_4096();
        return 0;
    default:
        ((TObjPlayer *)player)->clear_flag_4096();
        return 1;
    }
}

s8 TObjPlayer__sub_801AFDBC(s8 cls) {
    if ((cls < 0) || (cls >= 0xC)) {
        return 0;
    }
    return cls;
}

s8 TObjPlayer::get_class_index() {
    return (s8) this->m_88d;
}

s32 TObjPlayer::get_class_flags() { return this->class_flags; }

s32 TObjPlayer::get_language() {
    s32 temp_r3;
    temp_r3 = this->language;
    if ((temp_r3 < 0) || (temp_r3 >= 5)) {
        return 1;
    }
    return temp_r3;
}

s32 TObjPlayer::get_controller_port() { return this->controller_port; }

void TObjPlayer::set_action_provider_variant(s16 arg1) {
    if (arg1 != ((TObjPlayer *)(((Player_801AFCF4 *)this)->obj))->sub_802a7290_fwd() && fn_8000F740(main_phase_state) != 0) {
        ((Player_801AFCF4 *)this)->obj->m4(this->get_entity_id(), ((TObjPlayer *)((Player_801AFCF4 *)this))->has_valid_handle(), arg1);
        this->apply_motion_entry();
    }
}

s16 TObjPlayer::get_handle_value() { return (s16)(((TObjPlayer *)(*(void**)((char*)this + 0x380)))->sub_802a7290_fwd()); }

f32 TObjPlayer::receive_physical_attack(void *attacker, f32 scale) {
    if (obj_isState2_324() != 0) {
        return TObjPlayer__data_805DC278;
    }
    return TObjChara::receive_physical_attack(attacker, scale);
}

void clamp_stats__10TObjPlayerFiPv(saddr player, void *arg1) {
    s16 temp_r0;
    s16 temp_r0_2;
    s16 temp_r0_3;
    s16 temp_r0_4;
    s16 temp_r0_5;
    s16 temp_r0_6;
    s16 temp_r0_7;
    s16 temp_r3;
    s16 temp_r3_2;
    s16 temp_r3_3;
    s16 temp_r3_4;
    s16 temp_r3_5;
    s16 temp_r3_6;
    s16 temp_r3_7;
    s16 temp_r4;
    s32 max_level;
    s32 temp_r28_2;
    s32 temp_r28_3;
    s32 temp_r3_8;
    s32 temp_r4_2;
    const player_stats *class_stat_caps;
    void *temp_r31;

    temp_r31 = ((TObjPlayer *)player)->get_stats();
    class_stat_caps = get_class_stat_caps(get_class_index__10TObjPlayerFv(reinterpret_cast<u8 *>(player)));
    temp_r4 = *(s16 *)((s8 *)temp_r31 + 0);
    if (temp_r4 < 0) {
        *(s16 *)((s8 *)arg1 + 0) = 1;
        ((TObjPlayer *)player)->clamp_stat_41c();
    } else {
        temp_r0 = *(s16 *)((s8 *)class_stat_caps + 0);
        if (temp_r4 > temp_r0) {
            *(s16 *)((s8 *)arg1 + 0) = temp_r0;
            ((TObjPlayer *)player)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 0) = temp_r4;
        }
    }
    temp_r3 = *(s16 *)((s8 *)temp_r31 + 2);
    if (temp_r3 < 0) {
        *(s16 *)((s8 *)arg1 + 2) = 1;
        ((TObjPlayer *)player)->clamp_stat_41c();
    } else {
        temp_r0_2 = *(s16 *)((s8 *)class_stat_caps + 2);
        if (temp_r3 > temp_r0_2) {
            *(s16 *)((s8 *)arg1 + 2) = temp_r0_2;
            ((TObjPlayer *)player)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 2) = temp_r3;
        }
    }
    temp_r3_2 = *(s16 *)((s8 *)temp_r31 + 4);
    if (temp_r3_2 < 0) {
        *(s16 *)((s8 *)arg1 + 4) = 1;
        ((TObjPlayer *)player)->clamp_stat_41c();
    } else {
        temp_r0_3 = *(s16 *)((s8 *)class_stat_caps + 4);
        if (temp_r3_2 > temp_r0_3) {
            *(s16 *)((s8 *)arg1 + 4) = temp_r0_3;
            ((TObjPlayer *)player)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 4) = temp_r3_2;
        }
    }
    if (*(s16 *)((s8 *)temp_r31 + 6) < 0) {
        *(s16 *)((s8 *)arg1 + 6) = 1;
        ((TObjPlayer *)player)->clamp_stat_41c();
    }
    temp_r3_3 = *(s16 *)((s8 *)temp_r31 + 6);
    temp_r0_4 = *(s16 *)((s8 *)class_stat_caps + 6);
    if (temp_r3_3 > temp_r0_4) {
        *(s16 *)((s8 *)arg1 + 6) = temp_r0_4;
        ((TObjPlayer *)player)->clamp_stat_41c();
    } else {
        *(s16 *)((s8 *)arg1 + 6) = temp_r3_3;
    }
    temp_r3_4 = *(s16 *)((s8 *)temp_r31 + 8);
    if (temp_r3_4 < 0) {
        *(s16 *)((s8 *)arg1 + 8) = 1;
        ((TObjPlayer *)player)->clamp_stat_41c();
    } else {
        temp_r0_5 = *(s16 *)((s8 *)class_stat_caps + 8);
        if (temp_r3_4 > temp_r0_5) {
            *(s16 *)((s8 *)arg1 + 8) = temp_r0_5;
            ((TObjPlayer *)player)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 8) = temp_r3_4;
        }
    }
    temp_r3_5 = *(s16 *)((s8 *)temp_r31 + 0xA);
    if (temp_r3_5 < 0) {
        *(s16 *)((s8 *)arg1 + 0xA) = 1;
        ((TObjPlayer *)player)->clamp_stat_41c();
    } else {
        temp_r0_6 = *(s16 *)((s8 *)class_stat_caps + 0xA);
        if (temp_r3_5 > temp_r0_6) {
            *(s16 *)((s8 *)arg1 + 0xA) = temp_r0_6;
            ((TObjPlayer *)player)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 0xA) = temp_r3_5;
        }
    }
    temp_r3_6 = *(s16 *)((s8 *)temp_r31 + 0xC);
    if (temp_r3_6 < 0) {
        *(s16 *)((s8 *)arg1 + 0xC) = 1;
        ((TObjPlayer *)player)->clamp_stat_41c();
    } else {
        temp_r0_7 = *(s16 *)((s8 *)class_stat_caps + 0xC);
        if (temp_r3_6 > temp_r0_7) {
            *(s16 *)((s8 *)arg1 + 0xC) = temp_r0_7;
            ((TObjPlayer *)player)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 0xC) = temp_r3_6;
        }
    }
    temp_r3_7 = *(s16 *)((s8 *)temp_r31 + 0xE);
    if (temp_r3_7 < 0) {
        *(s16 *)((s8 *)arg1 + 0xE) = 1;
        ((TObjPlayer *)player)->clamp_stat_41c();
    } else {
        *(s16 *)((s8 *)arg1 + 0xE) = temp_r3_7;
    }
    *(f32 *)((s8 *)arg1 + 0x10) = (f32) *(f32 *)((s8 *)temp_r31 + 0x10);
    *(f32 *)((s8 *)arg1 + 0x14) = (f32) *(f32 *)((s8 *)temp_r31 + 0x14);
    temp_r28_2 = *(s32 *)((s8 *)temp_r31 + 0x18);
    max_level = TObjPlayer::get_max_level();
    if (temp_r28_2 < 0) {
        *(s32 *)((s8 *)arg1 + 0x18) = 0;
        ((TObjPlayer *)player)->set_flag_41c_bit1();
    } else if (temp_r28_2 > max_level) {
        *(s32 *)((s8 *)arg1 + 0x18) = max_level;
        ((TObjPlayer *)player)->set_flag_41c_bit1();
    } else {
        *(s32 *)((s8 *)arg1 + 0x18) = temp_r28_2;
    }
    temp_r28_2 = *(s32 *)((s8 *)temp_r31 + 0x1C);
    temp_r3_8 = TObjPlayer::get_current_state_field(get_class_index__10TObjPlayerFv(reinterpret_cast<u8 *>(player)), max_level);
    if (temp_r28_2 < 0) {
        *(s32 *)((s8 *)arg1 + 0x1C) = 0;
        ((TObjPlayer *)player)->check_flag_at_41c();
    } else if (temp_r28_2 > temp_r3_8) {
        *(s32 *)((s8 *)arg1 + 0x1C) = temp_r3_8;
        ((TObjPlayer *)player)->check_flag_at_41c();
    } else {
        *(s32 *)((s8 *)arg1 + 0x1C) = temp_r28_2;
    }
    temp_r4_2 = *(s32 *)((s8 *)temp_r31 + 0x20);
    if (temp_r4_2 < 0) {
        *(s32 *)((s8 *)arg1 + 0x20) = 0;
        ((TObjPlayer *)player)->check_stat_flag_41c();
        return;
    }
    if (temp_r4_2 > 0xF423F) {
        *(s32 *)((s8 *)arg1 + 0x20) = 0xF423F;
        ((TObjPlayer *)player)->check_stat_flag_41c();
        return;
    }
    *(s32 *)((s8 *)arg1 + 0x20) = temp_r4_2;
}

void TObjPlayer__sub_801AF904(s32 arg0) {
    s32 temp_r3;
    temp_r3 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x24);
    if (temp_r3 != 0) {
        __ct__20TPlayerReadyCallbackFP7TObjectUsPFP10TObjPlayer_v(temp_r3, arg0, ((TObjBase *)(saddr)(arg0))->get_entity_id(), (void (*)(int))set_flags_a00__10TObjPlayerFPv);
    }
}

void set_flags_a00__10TObjPlayerFPv(void *object) {
    if (object != NULL) {
        ((TObjBase *)object)->set_actor_flags(0xA00);
    }
}

s16 TObjPlayer__sub_801AF868(void *player) {
    u16 id;
    Ent_801AF868 *e;
    int i;

    id = ((TObjBase *)(player))->get_entity_id();
    if (TObjPlayer::is_single_screen() != 0) {
        e = (Ent_801AF868 *)get_split_screen_battle_rankings();
    } else {
        e = (Ent_801AF868 *)TWindowDuelResult__sub_801C257C();
    }
    for (i = 0; i < 4; i++, e++) {
        if (id == e->id) {
            return e->val;
        }
    }
    return -1;
}

s32 TObjPlayer::update_movement_by_screen() {
    if (is_single_screen() != 0) {
        return get_battle_ctrl_default__6TLobbyFv();
    }
    return TLobby__sub_801C2678();
}

void TObjPlayer::refill_traps() {
    refill_trap_counts((saddr)trap_counts, get_actor_level_index(), ((s32 (*)(void))get_class_index__10TObjPlayerFv)());
}

s32 TObjPlayer::is_alive_and_ready() {
    if ((TTecCtrl::is_technique_ready() == 0) && (this->is_android() != 0)) {
        return 1;
    }
    return 0;
}

s32 TObjPlayer::are_traps_full() {
    return are_trap_counts_full(trap_counts, get_actor_level_index(), get_class_index()) != 0 ? 1 : 0;
}

s32 is_action_available__10TObjPlayerFi(saddr arg0) {
    if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        return 0;
    }
    if (TObjPlayer::is_camera_ready() != 0) {
        return (u32)__cntlzw(((TObjCollidable *)arg0)->test_actor_flags(0x20000)) >> 5;
    }
    return ((TObjPlayer *)arg0)->is_android() != 0 ? 1 : 0;
}

int TObjPlayer__sub_801AF694(void* p) { return fn_801C543C((char*)p + 0x7c4); }

u32 TObjPlayer::set_lobby_marker(s32 arg1) {
    u32 temp;

    if (TFontSmallLobby::is_lobby_floor_15() == 0) {
        return 0U;
    }
    temp = *(u32 *)((s8 *)this + 0x3B8);
    if (temp == 0U) {
        *(u32 *)((s8 *)this + 0x3B8) = create_lobby_marker__10TObjPlayerFsSc(this->get_entity_id(), arg1);
    } else {
        set_material_index__18TPlayerLobbyMarkerFUc(temp, arg1);
    }
    return *(u32 *)((s8 *)this + 0x3B8);
}

void TObjPlayer::reset_pose() { this->clear_actor_flags((uaddr)((void*)2048)); update_rotation(); }

void play_voice_pair__10TObjPlayerFPv(TObjPlayer *player) {
    ((TObjPlayer *)player)->set_hp_clamped(player->hpmax);
    ((TObjPlayer *)player)->set_tp(player->tpmax);
}

void TObjPlayer__sub_801AF554(void *arg0, s8 arg1) {
    L_801AF554 sp8;
    if (arg0 == 0 || ((TObjChara *)arg0)->obj_isState2_324() == 0) {
        ((TFontSmallLobby *)(&sp8))->init_packet_6x9b_level_up();
        sp8.f2 = ((TObjBase *)(arg0))->get_entity_id();
        sp8.f4 = arg1;
        send_6x9B_level_up_all_techniques(&sp8);
    }
}

void handle_6x9B_level_up_all_techniques(void *command) {
    Msg_801CD6BC m;
    u8 *p;
    ((TFontSmallLobby *)(&m))->init_packet_6x9b_level_up();
    TFontSmallLobby__sub_801C01DC(&m, command);
    bswap_g_client_id_header(&m);
    if (validate_6x9B_level_up_all_techniques((G_ClientIDHeader *)&m) != 0) {
        p = (u8 *)get_player_by_client_id((u16)m.id);
        if (p != NULL) {
            ((TObjPlayer *)(p + 0x428))->level_up_all_techniques(m.level);
        }
    }
}

f32 TObjPlayer::get_battle_value(u16 client, s16 technique) {
    if (get_player_by_client_id(client) == NULL) {
        return (*(f32 *)&TObjPlayer__data_805DC278);
    }
    return get_class_technique_boost(get_class_index(), technique);
}

void TObjPlayer::sub_801AF454(s32 x) {
    if (((O_801AF454 *)this)->obj) {
        ((O_801AF454 *)this)->obj->m3(x);
    }
}

void TObjPlayer::update_facing_from_lock() {
    if (((VObj_801AF3C4 *)*(void **)((s8 *)this + 0x380))->m8() != 0) {
        this->set_motion_list(reinterpret_cast<BmlMotionEntry *>(((VObj_801AF3C4 *)*(void **)((s8 *)this + 0x380))->m75(1)));
        return;
    }
    this->set_motion_list(reinterpret_cast<BmlMotionEntry *>(((VObj_801AF3C4 *)*(void **)((s8 *)this + 0x380))->m75(0)));
}

s32 calc_stat_threshold__10TObjPlayerFPv(void *player) {
    s32 var_r31;
    var_r31 = ((TObjPlayer *)player)->get_actor_level_index();
    if (var_r31 > 0x63) {
        var_r31 = 0x63;
    }
    if (((TObjPlayer *)player)->is_newman() != 0) {
        var_r31 *= 0.8;
        return 0x5A - var_r31;
    }
    var_r31 *= 0.55;
    return 0x3C - var_r31;
}

s32 TObjPlayer::tick_regen_timer() {
    s32 v;
    TObjPlayer *target;
    s32 r = 0;
    TObjPlayer *player;
    s32 cur = get_regen_timer();
    target = player = (TObjPlayer *)this;
    v = cur + 1;
    if (v >= ((s32 (*)(void *, s32))calc_stat_threshold__10TObjPlayerFPv)(target, cur)) {
        v = 0;
        r = 1;
    }
    player->set_regen_timer(v);
    return r;
}
}
