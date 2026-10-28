#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/protocol/protocol_types.h"
#include "pso/system/PadRumble.h"
#include "pso/misc/TKeyBoardControl_803DE9C4.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/object/obj_band.h"
#include "pso/render/depth_buffer.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TShopJudgmentItemWindow.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubMag.h"
#include "pso/object/TObjWarpBossMulti.h"
#include "pso/ui/TChallenge4PResult.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TAdRicoRing.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/effect/TEffGuard.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TScene.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss7Crawfish.h"
#include "pso/player/TObjPlayer.h"
#include <stddef.h>
#include "pso/player/PlayerRequirementStats.h"
#include "pso/item/TItemData.h"
#include "pso/misc/CharacterAppearance.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneHoldEffect.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TCharaMaking.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TOMineTrap.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TMainCursor_8013BEB8.h"
#include "pso/misc/TWindowActionPalette.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/map/CurrentArea.h"
#include "pso/player/TObjPlayer_80141D1C.h"

#define M0(x) virtual void m##x();
struct Base_801AF2F0 { char pad[0x18]; };

struct VObj_801AF2F0 : Base_801AF2F0 {
    M0(0) M0(1) M0(2) M0(3) M0(4) M0(5) M0(6) M0(7) M0(8) M0(9)
    M0(10) M0(11) M0(12) M0(13)
    virtual s32 m14();
};

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

struct ItemBase_801B9954 { char pad[0x18]; };

struct Item_801B9954 : ItemBase_801B9954 {
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
    virtual void subtract_applied(Attack_801B9954 *, Defense_801B9954 *, Base_801B9954 *);
};

struct InventoryCreatePacket_801B849C {
    u8 command;
    u8 size;
    u16 actor;
    TItemData item;
    u32 flags;
};

struct VBase_801B96BC { char pad[0x18]; };

struct VObj_801B96BC : VBase_801B96BC {
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
    virtual void m23(void *, void *, void *);
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual s8 m31();
};

struct Stats_801B96BC { s16 atp; s16 pad2[0x11]; };

struct Out_801B96BC { s16 a; s16 b; };

struct Self_801B96BC {
    u8 pad0[0x2B0];
    s32 f2B0;
    u8 pad2B4[0x318 - 0x2B4];
    s32 f318;
    s32 f31C;
    u8 pad320[0xD00 - 0x320];
    s32 fD00;
    u8 fD04[4];
};

void reset_status_effect_row(u8 *arg0);
extern "C" {
f32 TObjPlayer__sub_800192C4(void *, int);
extern const f64 lbl_80446F38;
extern const f64 lbl_80446F40;
s32 calc_stat_threshold__10TObjPlayerFPv(void *arg0);
void copy_data__6TLobbyFPvPv(void *, s32);
u8 get_item_type__5TItemFv(void *);
u8 * activate_d04_slot__10TObjPlayerFv(void *);
void * test_flag3__9TItemDataFv(void *);
Item_801B9954 *get_item_field_2__9TItemDataFv(void *);
s32 set_params__10TObjPlayerFPvPvPviPv(void *, void *, void *, int, int);
u8 * get_slot_value__10TObjPlayerFPvi(void *, s32);
s32 get_class_stat_entry__10TObjPlayerFPUc(void *);
s32 preview_equip_stats__10TObjPlayerFv(u8 *arg0, s16 *out, u8 *incoming);
u8 is_volopt_phase_final__10TObjPlayerFv(void);
s32 advance_item_id_counter(int);
s32 obj_isState2_324__13TUnk_804806E8Fv();
s32 get_entity_id(void * a0);
extern u32 local_client_id;
s16 get_attack_params_atp_min(void *);
s16 get_attack_params_atp_max(void *);
s32 is_item_equipped(int);
u32 start_inventory_update__10TObjPlayerFi(s32, s32);
u32 get_owner_if_alive__10TObjPlayerFv();
s32 preview_unequip_stats__10TObjPlayerFv(Self_801B96BC *self, Out_801B96BC *out, s32 arg2);
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

struct B_801AF734 { u8 pad[0x18]; };

struct V_801AF734 : B_801AF734 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void *m14();
};

struct Base_801AF7E0 { u8 pad[0x18]; };

struct TObjPlayer_801AF7E0 : Base_801AF7E0 {
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
    virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
    virtual void v8();  virtual void v9();  virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual s32 v14();
    u8 pad1[0x7C4 - 0x1C];
    u8 slot[4];
};

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

struct VBase_801B09A4 { char pad[0x18]; };

struct VObj_801B09A4 : VBase_801B09A4 {
    virtual void m0(s32);
};

struct Rec_801B09A4 { u8 bytes[0x42C]; };

struct Pl_801B0B88 {
    u8 pad0[0x424];
    s32 f424;
    u8 f428[0x754 - 0x428];
    u8 f754[0x7c4 - 0x754];
    u8 f7C4[4];
    u8 f7C8[0xd00 - 0x7c8];
    s32 fD00;
};

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
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
    virtual s32 m40();
};

struct Stack_801B15A4 {
    s8 sp8;
    s8 sp9;
    s8 spA;
    u8 rest[17];
};

struct Vec_801B1FA4 { f32 x, y, z; };

struct pkt_801B1FA4 {
    u8 hdr[2];
    u16 slot;
    s32 heading;
    struct Vec_801B1FA4 pos;
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

struct VBase_801B2AE8 { char pad[0x18]; };

struct VObj_801B2AE8 : VBase_801B2AE8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46(s32);
    virtual void m47();
    virtual void m48();
    virtual void m49(Pair_801B2AE8);
    virtual void m50(Pair_801B2AE8);
};

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

struct VBase_801B2CE4 { char pad[0x18]; };

struct VObj_801B2CE4 : VBase_801B2CE4 {
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
};

struct Eff_801B2CE4 { u16 f0; u16 f2; u32 f4; u32 f8; };

struct ReturnLobby { u8 bytes[0x28]; };

struct VBase_801B3274 { char pad[0x18]; };

struct VObj_801B3274 : VBase_801B3274 {
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
};

struct VBase_801B3DD4 { char pad[0x18]; };

struct VObj_801B3DD4 : VBase_801B3DD4 {
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
    virtual void m11(s32);
};

struct Player_801B3DD4 {
    u8 pad0[0x60];
    s32 f60;
};

struct Base_801B4340_801B3FD8 { char pad[0x18]; };

struct VObj_801B4340_801B3FD8 : Base_801B4340_801B3FD8 {
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
};

struct S801B4430_801b4430_801B3FD8 { s8 b[2]; s16 h; };

struct S801B44EC_801b44ec_801B3FD8 { s8 b[2]; s16 h; };

struct Base_801B4540_801B3FD8 { char pad[0x18]; };

struct VObj_801B4540_801B3FD8 : Base_801B4540_801B3FD8 {
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
    virtual void m52(); virtual void m53();
};

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

struct Vec_801B5328 { f32 x, y, z; };

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
    u8 f98[0xAC - 0x98];
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
    s32 f2B0;
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
    s32 fD00;
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
    u8 f98[0xAC - 0x98];
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

typedef struct Vec_801B5DDC { f32 x, y, z; } Vec_801B5DDC;

struct Hit_801B5DDC {
    u8 pad0[0x18];
    u32 flags;
    Vec_801B5DDC pos;
    u8 pad28[0x38 - 0x28];
};

struct Obj_801B5DDC {
    u8 pad0[0x38];
    Vec_801B5DDC pos;
    u8 pad44[0x308 - 0x44];
    Vec_801B5DDC f308;
};

struct Vec_801B5EA4 { f32 x, y, z; };

struct Pad_801B5EA4 { u8 pad[0x18]; };

struct Obj_801B5EA4 : Pad_801B5EA4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual u32 v16(Vec_801B5EA4 *);
    u8 pad1c[0x38 - 0x1C];
    Vec_801B5EA4 pos;
    u8 pad44[0x308 - 0x44];
    Vec_801B5EA4 vel;
};

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

typedef struct Vec_801B6964 { f32 x, y, z; } Vec_801B6964;

struct Color_801B6964 { f32 r, g, b, a; };

struct Base_801B6414_801B3FD8 { char pad[0x18]; };

struct VObj_801B6414_801B3FD8 : Base_801B6414_801B3FD8 {
    virtual void m0();
    virtual void m1();  virtual void m2();  virtual void m3();  virtual void m4();
    virtual void m5();  virtual void m6();  virtual void m7();  virtual void m8();
    virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(s32);
    virtual void m13();
    virtual s32 m14();
};

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

struct Stats_801B6CE0 {
    u8 pad0[0x18];
    s32 level;
    s32 exp;
};

struct Obj_801B6CE0 {
    u8 pad0[0x2B0];
    Stats_801B6CE0 *stats;
};

struct Buf1C { u8 pad[0x1C]; };

struct VBase { u8 pad[0x18]; };

struct VObj : VBase {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(s32); virtual void m21(s32);
};

typedef struct VBase_18_c0d9f3 VBase_18_c0d9f3;

typedef struct VObj_18_c0d9f3 VObj_18_c0d9f3;

struct Player_801B6C30;

struct Obj_801B6CE0;

struct Base_801B7AC8_801B3FD8 { char pad[0x18]; };

struct VObj_801B7AC8_801B3FD8 : Base_801B7AC8_801B3FD8 {
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
    virtual void m16(s32);
};

struct Stack_801B7998 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct P_801B7B58 { u8 pad[0xD00]; void *fD00; };

struct ItemData_801B7C78 {
    s8 kind;
    s8 group;
    u8 rest[0x16];
};

struct ItemData_801B7CEC {
    s8 kind;
    s8 group;
    s8 sub;
    u8 rest[0x15];
};

struct L_801B7E14 { u8 f0[2]; s16 f2; s32 f4; s32 f8; };

typedef struct Cmd_801B7D68 {
    u8 cmd;
    u8 size;
    u16 client;
    u32 item_a;
    u32 item_b;
} Cmd_801B7D68;

struct VBase_801B7EB8 { char pad[0x18]; };

struct VObj_801B7EB8 : VBase_801B7EB8 {
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
};

struct Pkt_801B7EB8 {
    u8 hdr[2];
    u16 client;
    s32 item;
};

struct Ent_801B80C0;

struct Buf_801B802C {
    s32 n;
    u8 ents[0x34C];
};

struct Ent_801B80C0 { u8 pad[0x14]; s32 f14; u8 pad18[0x1C - 0x18]; };

struct S801B7F4C { s8 b[2]; s16 h; s32 w; };

struct VBase_18_e9153c { char pad[0x18]; };

struct VObj_18_e9153c : VBase_18_e9153c {
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
    virtual s32 m18();
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
    virtual s8 m31();
};

struct VObj_18_p65 : VBase_18 {
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
    virtual s32 m18();
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
    virtual s8 m31();
};

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

struct DeathDropRecord {
    s32 state;
    s32 source_id;
    TItemData item;
};

struct DeathItemPosition { f32 x,y,z; };

struct PlayerDeathItemFields {
    u8 before_position[0x38];
    DeathItemPosition position;
    u8 before_inventory[0xD00-0x44];
    u8* inventory_owner;
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

struct VBase_801B8AF8 { char pad[0x18]; };

struct VObj_801B8AF8 : VBase_801B8AF8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33();
    virtual s32 m34();
};

struct Item_801B8AF8 {
    u8 data[0xC];
    s32 id;
    u8 data2[4];
};

typedef struct Vec_801B8870 { f32 x, y, z; } Vec_801B8870;

typedef struct Cmd_801B8870 {
    u8 cmd;
    u8 size;
    s16 client;
    s16 b;
    s16 floor;
    s32 a;
    Vec_801B8870 pos;
} Cmd_801B8870;

struct Data_801B855C { u8 pad[0x20]; s32 meseta; };

struct Player_801B855C { u8 pad[0x2B0]; Data_801B855C *data; };

typedef char DeathDropRecordSize[(sizeof(DeathDropRecord)==0x1C)?1:-1];

typedef char DeathDropItemOffset[(offsetof(DeathDropRecord,item)==8)?1:-1];

typedef char DeathPlayerInventoryOffset[(offsetof(PlayerDeathItemFields,inventory_owner)==0xD00)?1:-1];

struct L_801B8CB0 { u16 f0; u16 f2; s32 f4; u8 f8[0x78]; };

struct Cmd_801B8DE8 { u8 hdr[2]; s16 id; s32 a; s32 b; };

struct L_801B8D68 { u16 f0; u16 f2; s32 f4; s32 f8; };

struct VObj_18_p72 : VBase_18 {
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
    virtual s32 m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual s32 m34();
    virtual void m35();
    virtual void m36(s32);
};

struct Base_B { char pad[0x18]; };

struct V_B : Base_B {
    virtual void f0();
    virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6();
    virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12();
    virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18();
    virtual void f19(); virtual void f20(); virtual void f21();
    virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30();
    virtual void f31(); virtual void f32(); virtual void f33();
    virtual s32 m34();
};

struct VBase_801B91F0 { char pad[0x18]; };

struct VObj_801B91F0 : VBase_801B91F0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33();
    virtual s32 m34();
};

struct Inv_801B91F0 {
    u8 pad0[0x1C];
    s16 count;
};

struct Player_801B91F0 {
    u8 pad0[0xD00];
    Inv_801B91F0 *inv;
};

typedef struct Vec_801B92EC { f32 x, y, z; } Vec_801B92EC;

struct Obj_801B92EC {
    u8 pad0[0x38];
    Vec_801B92EC pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
};

struct Stack_801B9544 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Base_801B95C8 { char pad[0x18]; };

struct VObj_801B95C8 : Base_801B95C8 {
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
    virtual void pad29(); virtual void pad30(); virtual void pad31();
    virtual void pad32(); virtual void pad33(); virtual void pad34();
    virtual void pad35(); virtual void pad36(); virtual void pad37();
    virtual void pad38(); virtual void pad39(); virtual void pad40();
    virtual void pad41(); virtual void pad42(); virtual void pad43();
    virtual void pad44(); virtual void pad45(); virtual void pad46();
    virtual void pad47(); virtual void pad48(); virtual void pad49();
    virtual void pad50(); virtual void pad51(); virtual void pad52();
    virtual void pad53(); virtual void pad54(); virtual void pad55();
    virtual void pad56(); virtual void pad57(); virtual void pad58();
    virtual void pad59(); virtual void pad60(); virtual void pad61();
    virtual void pad62();
    virtual void m63(s32, s32 *);
};

typedef struct Cmd_801B9634 { u8 hdr[2]; s16 client; s32 val; } Cmd_801B9634;

struct Base_801B9CE0 { char pad[0x18]; };

struct VObj_801B9CE0 : Base_801B9CE0 {
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
};

struct Base_801B9D50 { char pad[0x18]; };

struct VObj_801B9D50 : Base_801B9D50 {
virtual void f13();
virtual void f14();
virtual void f15();
virtual void f16();
virtual void f17();
virtual void f18();
virtual void f19();
virtual void f20();
virtual void f21();
virtual void f22();
virtual void f23();
virtual void f24();
virtual void f25();
virtual void f26();
virtual void f27();
virtual void f28();
virtual void f29();
virtual void f30();
virtual void f31();
    virtual void m19();
virtual void f33();
virtual void f34();
virtual void f35();
virtual void f36();
virtual void f37();
virtual void f38();
virtual void f39();
virtual void f40();
virtual void f41();
virtual void f42();
virtual void f43();
    virtual s32 m31();
};

typedef struct Msg_801B9E0C {
    u8 pad0[2];
    u16 slot;
    s32 c;
} Msg_801B9E0C;

typedef struct Player_801B9E0C {
    u8 pad0[0xD00];
    void *inv;
} Player_801B9E0C;

struct Cmd_801B9EDC { u16 hdr; u16 id; void *item; };

struct L_801BA0F0 { u16 f0; s16 f2; s32 f4; s32 f8; };

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

typedef char RecoveredGlobal_802A1154_main_task_size[sizeof(RecoveredGlobal_802A1154_main_task) == 0x34 ? 1 : -1];

struct RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8000F9E4_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F90C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F9CC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8FC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8EC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F91C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];

typedef char RecoveredGlobal_8000F7FC_lbl_80515F48_size[sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_8000F90C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F90C_lbl_804FE120) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8000F8FC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8FC_lbl_804FE120) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8000F8EC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8EC_lbl_804FE120) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8000F91C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F91C_lbl_804FE120) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8000F9E4_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9E4_lbl_804FE120) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8000F9CC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9CC_lbl_804FE120) == 0x18 ? 1 : -1];

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

typedef struct Msg1F_801BA8D4 {
    u8 pad0[2];
    u16 slot;
    s32 floor;
} Msg1F_801BA8D4;

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

typedef struct Msg_801BAA6C {
    u8 pad0[2];
    u16 slot;
    s32 floor;
} Msg_801BAA6C;

struct Msg_801BAB1C { u16 cmd; u16 id; s32 value; u8 pad8[8]; };

struct Vec_801BAB78 { f32 x, y, z; };

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
    virtual void m63(s32, Vec_801BAB78 *);
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

struct Vec_801BBD58 { f32 x, y, z; };

struct Body_801BBD58 {
    Vec_801BBD58 offset;
    f32 radius;
    f32 radius2;
    s32 kind;
    s32 flags;
    Vec_801BBD58 center;
    f32 extra;
};

struct Player_801BBD58 {
    u8 pad[0x38];
    Vec_801BBD58 pos;
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

struct VBase801BAEC8 { char pad[0x18]; };

struct VObj801BAEC8 : VBase801BAEC8 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
    virtual s32 m9(f32, f32, f32);
};

struct VBase_801BB1F8 { char pad[0x18]; };

struct VObj_801BB1F8 : VBase_801BB1F8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

s32 fn_8000F740(void *);
s32 get_main_phase();
void mark_area_change_pending(void);
s32 get_field_2d4__10TObjPlayerFv(void *);
void TObjPlayer__sub_8001053C(u8 *arg0);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
s32 set_hp_clamped__10TObjPlayerFs(void * a0 = 0, s16 a1 = 0);
s32 add_actor_hp(u8 *arg0, s16 arg1);
f32 receive_physical_attack__13TUnk_804806E8FPvf(s32, s32, f32);
s32 update_attack_stat_status__13TUnk_804806E8Fv(s32);
s32 update_shock_clock__13TUnk_804806E8Fv(s32);
s32 update_movement_status__13TUnk_804806E8Fv(s32);
s32 update_flag30_timer__13TUnk_804806E8Fv(s32);
s32 vfunc_37__13TUnk_804806E8Fv(s32);
s32 update_action_hold_status__13TUnk_804806E8Fv(s32);
s32 update_poison_status__13TUnk_804806E8Fv(s32);
s32 reset_motion_fields__13TUnk_804806E8Fv(void *);
s32 is_locally_controlled__10TObjPlayerFPv(void * a0);
s32 obj_getArrWord_254(void *, s32);
s32 get_actor_tp(void *);
int obj_getPtr2B0_20(u8 *p);
s32 get_actor_hp(void *);
s32 obj_isState3_324__13TUnk_804806E8Fv(void *);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(s32, s32);
s32 obj_setFlags30(void *, s32);
s32 get_current_floor();
s32 get_item_field_6__10TObjPlayerFPv(Pl_801B0B88 *);
s32 get_type__10TObjPlayerFPv(void *);
f32 atan2_float(f32 y, f32 x);
s32 queue_destruction__7TObjectFv(u32);
int test_flags_any(void*, int);
s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
s32 *get_shared_text_buffer(void);
s32 fn_8002AE08(u16);
s32 get_field_3e0__12TBoss3VoloptFv();
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
void obj_clear_flag30_20000(void *arg0);
s32 check_player_flag1__6TLobbyFv(s32);
s32 check_flag__10TObjPlayerFl(void *, s32);
s32 get_position_ptr__10TObjPlayerFv();
s32 get_mode__11TCameraCtrlFPv(void *p);
void copy_player_visual_record(void *, void *);
u8 * csnVectorUnder(s32 *, void *, s32);
void * get_quest_id__12TQuestListVMFv();
s32 test_action_mask__10TObjPlayerFl(s32, s32);
s32 is_in_shadow_range(u8 *arg0, f32 farg0);
s32 get_item_id__5TItemFv();
void draw_blob_shadow(s32);
void __ct__14TFontSmallHelpFUlUllUl(void *, u16, s32, s32, s32);
u32 create__15TFontSmallLobbyFPv(void *);
s32 set_owner_client__5TItemFUs(void *, s16);
s32 check_equip_requirements__5TItemFP10TObjPlayerPs(s32, Pl_801B0B88 *, s32);
s32 set_tp__10TObjPlayerFs(void * a0 = 0, s16 a1 = 0);
s32 is_script_controlled__10TObjPlayerFv(TObjPlayer*);
s32 lookup_item_def__9TItemDataFPv(u8 *);
s32 init__9TItemDataFv(s8 *);
s32 get_item_type_or_default__9TItemListFv(void *);
void set_stack_count__24TShopEquipmentListWindowFSc(Item_801B8AF8 *, u8);
u16 get_type_id__10TObjPlayerFv();
s32 TObjPlayer__sub_80116620(void *, int);
s32 sub_8011E204__10TObjPlayerFl(void *, s32);
void set_state_flags__10TObjPlayerFUl(void *, u32);
s32 is_flag_b0_4__10TObjPlayerFv();
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
void publish_actor_light_scalars(u16, f32, f32);
void bswap_player_data__6TLobbyFi(void *);
void TObjPlayer__sub_8013A748(void *);
void try_add_target_candidate__11TMainCursorFPvPvPvPv(void *c, void *self, void *owner, void *p);
u32 TLockOnCursor__ct(u32, void *, s32);
u16 get_id__11TMainCursorFv(void* p);
s32 draw_model_with_callback__10TObjPlayerFllf(void *, s32, s32, f32);
s32 set_animation__10TObjMotionFs(s32, s32);
s32 advance_animation_playback(void *);
s32 TMainCursor__sub_80154098(int, int, int);
s32 TMainCursor__sub_801540B8(int, int, int);
u16 register_entity_by_id(void *obj);
u8 * find_entity_by_id(u16);
s32 test_player_overlap_with_players(Obj_801B5DDC *, Obj_801B5DDC *, Vec_801B5DDC *, Hit_801B5DDC *);
void check_enemy_body_collisions(void *arg0);
int clear_obj_links__13TUnk_804AF8A0Fv(void*);
s32 is_state_ec1_ed3__10TObjPlayerFv(void *);
s32 get_dest_area__17TObjAreaWarpQuestFv(void *);
void fn_8019DD24(void *p, u32 v);
u16 TObjRoomId__sub_801A1DB8(s32);
s32 reset_motion_fields__13TUnk_804B9870Fv();
s32 is_final_phase__10TObjPlayerFv();
s32 is_camera_ready__10TObjPlayerFv();
s32 is_camera_mode_active__10TObjPlayerFv();
s32 is_single_screen__10TObjPlayerFv();
void handle_6x9B_level_up_all_techniques(void *arg0);
void TObjPlayer__sub_801AF554(void *arg0, s8 arg1);
void play_voice_pair__10TObjPlayerFPv(TObjPlayer *arg0);
int TObjPlayer__sub_801AF694(void* p);
void set_flags_a00__10TObjPlayerFPv(void *arg0);
void TObjPlayer__sub_801AF904(s32 arg0);
void clamp_stats__10TObjPlayerFiPv(s32 arg0, void *arg1);
f32 TObjPlayer__vt20(s32 arg0, s32 arg1, f32 farg0);
s32 TObjPlayer__sub_801AFD8C(u8 *arg0);
s8 get_class_index__10TObjPlayerFv(u8 *arg0);
s8 TObjPlayer__sub_801AFDBC(s8 arg0);
u8 is_key_machine_ready__10TObjPlayerFv(void);
u8 is_lobby_floor_15__15TFontSmallLobbyFv(void);
u8 is_on_current_floor__10TObjPlayerFi(s32 arg0);
s32 TObjPlayer__sub_801AFFD0(u8 *arg0);
void TObjPlayer__sub_801B0124(u8 *self, s32 arg1);
void handle_6x8F_add_battle_damage_scores(s32 arg0);
void apply_camera_shake__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
void handle_6x8E(void);
void record_damage_stats__10TOMineTrapFUiUis(u32 arg0, u32 arg1, s16 arg2);
void draw_player_status(s32 arg0, void *arg1, s32 arg2);
void show_sub_status_window(void *arg0, s32 *arg1, s32 *arg2);
void draw_status_line(void *arg0, s32 *arg1, s32 *arg2, s32 arg3);
int TObjPlayer__sub_801B066C(void* p);
void handle_6x90_set_player_battle_team(s32 arg0);
void check_flag_01000000__10TObjPlayerFPv(void *arg0);
void handle_6x82_enable_drop_weapon_on_death(void *arg0);
s32 TLobby__sub_801B07E0(s32 arg0, void * _w1);
void handle_6x81_disable_drop_weapon_on_death(void *arg0);
s32 TLobby__sub_801B08F0(s32 arg0, void * _w1);
void TLobby__sub_801B09A4(void);
s32 check_switch_available__6TLobbyFPvi(void *arg0, s32 arg1);
u8 is_technique_ready__8TTecCtrlFv(void);
void check_flag_800000__10TObjPlayerFPv(void *arg0);
void handle_6x7B_disable_stealth_suit_effect(void *arg0);
void draw_small_label__15TFontSmallLobbyFi(s32 arg0);
void handle_6x7A_enable_stealth_suit_effect(void *arg0);
s32 TFontSmallLobby__sub_801B1224(s32 arg0, void * _w1);
void TLobby__sub_801B1254(s32 arg0);
void test_flag_2000000__10TObjPlayerFPv(void *arg0);
void draw__10TObjPlayerFPvf(void *arg0, f32 farg0);
void handle_6x1C_disable_pk_mode_for_player(void *arg0);
void handle_6x1B_enable_pk_mode_for_player(void *arg0);
void* draw_font__10TObjPlayerFPv(void* p);
void TObjPlayer__sub_801B18C0(s32 arg0, u32 arg1);
void unequip_by_field326__10TObjPlayerFPv(void *arg0);
void reset_volopt_state__10TObjPlayerFv(void);
void foreach_player__10TObjPlayerFv(s32 (*arg0)(u32));
void for_each_player_slot__10TObjPlayerFv(void (*arg0)(void *));
s32 handle_set_visible__10TObjPlayerFi(s32 arg0);
void TObjPlayer__sub_801B1BA4(void);
void TObjPlayer__sub_801B1C8C(void);
void send_field_state_if_active__10TObjPlayerFP10TObjPlayerl(s32 arg0, s32 arg1);
void handle_6x2F_change_player_hp(s32 arg0);
void send_6x2F_change_player_hp(s32 arg0, s32 arg1, s32 arg2);
void handle_6x24_teleport_player(s32 arg0);
void send_6x24_teleport_player(u16 slot, void *pos, s32 heading);
void TObjPlayer__sub_801B2014(s32 arg0);
s32 TObjPlayer__vt38(s32 arg0);
s32 TObjPlayer__vt37(s32 arg0);
s32 TObjPlayer__vt36(s32 arg0);
s32 TObjPlayer__vt34(s32 arg0);
s32 TObjPlayer__vt33(s32 arg0);
s32 check_flag30_bit20__10TObjPlayerFi(s32 arg0);
s32 is_flag30_10_set__10TObjPlayerFi(s32 arg0);
s32 is_flag30_8_set__10TObjPlayerFi(s32 arg0);
void remove_status_effect__10TObjPlayerFUiPv(u32, Pair_801B2C04 *);
void dispatch_status_effect_msg__10TObjPlayerFUiPv(u32 arg0, Pair_801B2AE8 *msg);
void handle_6x0D_add_or_remove_status_effect(void *arg0);
void send_code_13_3__10TObjPlayerFii(s32 arg0, s32 arg1);
void handle_6x0E_clear_negative_status_effects(s32 arg0);
s32 clear_negative_status_effects__10TObjPlayerFi(s32 arg0);
void handle_6x0C_add_or_remove_status_effect(void *arg0);
void TObjPlayer__vt76(s32 arg0, s32 arg1);
s32 calc_scaled_value__10TObjPlayerFii(s32 arg0, s32 arg1);
void apply_speed_scale__10TObjPlayerFif(s32 arg0, f32 farg0);
s32 build_player_class_stat_template(s32 arg0, s32 arg1);
s32 build_player_equipment_requirement_stats(TObjPlayer *self, PlayerRequirementStats *arg1);
int fn_801B309C(void* p);
void prepare_guild_return__10TObjPlayerFPv(void *player);
void handle_6x34(void);
void complete_deferred_player_death(void);
int is_flag_400_set__10TObjPlayerFPv(void* p);
void enable_action_input__10TObjPlayerFPv(void* p);
int get_result_entry__18TChallenge4PResultFPv(void* p);
int get_field_340__18TChallenge4PResultFPv(void* p);
int get_player_result__18TChallenge4PResultFPv(void* p);
int TObjPlayer__sub_801B3FD8(void* p);
void TObjPlayer__sub_801B4044(void* p);
s32 test_ordered_anim_markers__10TObjPlayerFPvff(u8 *arg0, f32 farg0, f32 farg1);
void update_rotation__10TObjPlayerFv(void *arg0);
void handle_6xA1_revive_player_v3(void *arg0);
void TObjPlayer__sub_801B4430(s32 arg0);
void handle_6x32_medical_center_revive_all_players(void);
void send_code50_packet__10TObjPlayerFi(s32 arg0);
void recover_full__10TObjPlayerFPv(void *arg0);
void handle_6x31_use_medical_center(void *arg0);
void send_code_49_1__10TObjPlayerFi(s32 arg0);
void send_field_state__10TObjPlayerFPv(void* p);
void submit_cursor_candidate(void *self);
void submit_target_to_player_cursor(void *target, s32 id);
void fill_player_record__10TObjPlayerFPvPv(Src_801B4CE4 *src, Dst_801B4CE4 *dst);
Obj_801B4FD8 * init_player_join_record(Obj_801B4FD8 *self);
void handle_6x2D_release_hold(void *arg0);
void handle_6x2C_impose_hold(s32 arg0);
void send_6x2C_impose_hold(s32 arg0, struct Vec_801B5328 *pos, s16 arg2, s16 arg3, f32 radius);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
void set_move_mode__10TObjPlayerFi(s32 arg0);
int check_flag_100__10TObjPlayerFPv(void* p);
void *TObjPlayer__sub_801B57E8(TObjPlayer *player);
int TObjPlayer__sub_801BF6E4(void *p);
s32 is_action_channel_available__10TObjPlayerFii(s32 arg0, s32 arg1);
void TObjPlayer__sub_801B5A44(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void TObjPlayer__sub_801B5AF8(s32 arg0, s32 arg1);
void damp_planar_velocity(P_801B5FB0 *p);
void handle_6x2E_set_or_clear_player_flags(void *arg0);
void apply_battle_level_reset__10TObjPlayerFv(Pl_801B0B88 *, s32);
void TObjPlayer__sub_801B67C4(void* p);
void spawn_level_change_feedback__10TObjPlayerFv(s32 arg0, s32 arg1);
void handle_6x30_change_player_level(void *arg0);
void send_6x30_change_player_level(Player_801B6C30 *arg0);
void calc_move_velocity__10TObjPlayerFPvPvf(void *arg0, void *arg1, f32 farg0);
void handle_6x99(void);
void handle_6x98(void);
void TObjPlayer__sub_801B7B58(P_801B7B58 *arg0, s32 arg1, s32 arg2);
s32 can_destroy_with_parents__10TObjPlayerFUi(u32 arg0);
s32 fn_801B7CEC(u8 *arg0, s8 arg1, s8 arg2, s8 arg3);
void handle_6x28_feed_mag(s32 arg0);
void send_6x28_feed_mag(void *arg0, s32 arg1, s32 arg2);
void handle_6x27_use_item(s32 arg0);
s32 try_send_6x27_use_item(void *arg0, s32 arg1);
void rebuild_player_inventory(void *arg0);
void assign_inventory_item_ids(void *arg0, Ent_801B80C0 *arg1, s32 arg2);
void equip_saved_item_if_slot_empty__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
void bind_saved_inventory_equipment__10TObjPlayerFPvPvi(u8 *p, u8 *records, s32 count);
s32 query_state_if_present__10TObjPlayerFPv(void *arg0);
void handle_6x2B_create_inventory_item(s32 arg0);
void handle_6x2A_drop_item(void *arg0);
void dispatch_input__10TObjPlayerFPvii(void *arg0, s32 arg1, s32 arg2);
void handle_6xAC(void *arg0);
void handle_6x29_delete_inventory_item(void *arg0);
void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b);
void * pickup_item__10TObjPlayerFP5TItem(u8 *arg0, u8 *arg1);
s32 can_pickup_item__10TObjPlayerFP9TItemData(void *arg0, u8 *arg1);
void can_pickup_item_by_id__10TObjPlayerFP5TItem(s32 arg0, s32 arg1);
bool is_target_in_facing_cone__10TObjPlayerFPv(Obj_801B92EC *self, Vec_801B92EC *target);
void unequip_item__10TObjPlayerFiPv(s32 arg0, void *arg1);
void handle_6x26_unequip_item(void *arg0);
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *self, void *item);
void handle_6x25_equip_item(void *arg0);
void send_6x25_equip_item(void *arg0, s32 arg1, s32 arg2);
void handle_state2_transitions__10TObjPlayerFv(u8 *arg0);
void TObjPlayer__sub_801BA42C(void);
void set_action_state__10TObjPlayerFPvss(void *arg0, s16 arg1, s16 arg2);
void * get_player_by_client_id(s32 i);
void handle_6xAE_set_animation_state(void *arg0);
void handle_6x20_set_position(void *arg0);
void handle_6x1F_set_player_floor(void *arg0);
void handle_6x21_inter_level_warp(void *arg0);
void send_6x21_inter_level_warp(void *obj, s32 value);
void draw_projected_shadow__10TObjPlayerFPvPvi(VObj_801BAB78 *self, f32 *pos, s32 arg2);
void TObjPlayer__sub_801BAC48(void);
void draw_body__10TObjPlayerFPvi(u8 *arg0, s32 arg1);
void run_task__10TObjPlayerFv(TObjPlayer *arg0);
void TObjPlayer__sub_801BB8A8(void);
void TObjPlayer__sub_801BB8AC(void);
void TObjPlayer__sub_801BBB70(void);
int TObjPlayer__sub_801BBB74(void* p);
void TObjPlayer__sub_801BBB94(void);
void TObjPlayer__sub_801BBC64(void);
int clear_links__10TObjPlayerFPv(void* p);
void TObjPlayer__sub_801BC050(O_801BC050 *p);
void TObjPlayer__send_selected_spawn_position(void *self, u16 id);
s32 TObjPlayer__sub_801BCA0C(void *);
s32 TObjPlayer__sub_801BCD50(void *);
s32 TObjPlayer__sub_801BD3A4(void *);
void create_player_instance__10TObjPlayerFll(u16, Rec_801B09A4 *);
s32 check_camera_mode__10TObjPlayerFv();
void * update_battle_controller__10TObjPlayerFv();
s32 check_flag_4__10TObjPlayerFv(void *);
void clear_flag_4000_callback__10TObjPlayerFv(void);
int set_battle_flag__10TObjPlayerFl(void*, int);
u32 is_action_active__10TObjPlayerFv();
void TObjPlayer__sub_801BE784(void *, s32);
s32 get_battle_mode__10TObjPlayerFv(void *);
void TObjPlayer__sub_801BE794(void *, s32);
s32 get_byte_339__10TObjPlayerFv(void *);
void TObjPlayer__sub_801BE7A4(void *, s32);
s32 get_mag_level__10TObjPlayerFPv(void *);
void TObjPlayer__sub_801BE7B4(void *, s32);
s32 TObjPlayer__sub_801BE7BC(void *);
void TObjPlayer__sub_801BE7E0(void *, s32);
void TObjPlayer__sub_801BE80C(void *, s32);
void TObjPlayer__sub_801BE838(void *, s32);
void TObjPlayer__sub_801BE864(void *, s32);
void init_inventory_list__10TObjPlayerFPv(void *);
s32 TObjPlayer__sub_801BE8F4(void *, s32, s32);
void *TObjPlayer__sub_801BE918(void *a0, int a1, void *a2, void *a3);
s16 clamp_nested_index__10TObjPlayerFv(void *, int);
void TObjPlayer__sub_801BE9A8(s32);
void set_flag_20000__10TObjPlayerFi(s32);
s32 set_flag_02000000__10TObjPlayerFv(void *);
s32 set_flag_400000__10TObjPlayerFi(void *);
s32 TObjPlayer__sub_801BEB0C(void *);
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
s32 __ct__20TPlayerReadyCallbackFP7TObjectUsPFP10TObjPlayer_v(s32, s32, s32, void (*)(int));
int TObjPlayer__sub_801BF460(void*);
int TObjPlayer__sub_801BF47C(void*);
int TObjPlayer__sub_801BF488(void*);
int TObjPlayer__sub_801BF4A0(void*);
void update_action_palette__10TObjPlayerFv(void *, u8);
void set_action_palette_mode__10TObjPlayerFv(void *, u8);
s32 is_timer_running(void *);
s32 TObjPlayer__sub_801BF560(s16 *arg0);
s16 TObjPlayer__sub_801BF57C(void *p);
s32 TObjPlayer__sub_801BF584(u8 *arg0);
void *TObjPlayer__sub_801BF660(void *arg0);
f32 TObjPlayer__sub_801BF6B0(void *, f32, f32, f32);
f32 * TObjPlayer__sub_801BF6B8(void *);
void TObjPlayer__sub_801BF6C0(void *p, f32 v);
void TObjPlayer__sub_801BF6C8(s32, f32, f32);
void TObjPlayer__sub_801BF6D4(void *p, s16 v);
void TObjPlayer__sub_801BF6DC(void *p, s16 v);
s32 set_anim_state__10TObjPlayerFs(void *, s32);
s32 set_action_id__10TObjPlayerFs(void *, s32);
int TObjPlayer__sub_801BF840(void *p);
int TObjPlayer__sub_801BF8AC(void *p);
void set_equip_slot_entry(s32, s32, s32);
void TObjPlayer__sub_801BF8F8(s32 *p);
s32 TObjPlayer__sub_801BF914(void *);
s32 TObjPlayer__sub_801BF918(void *);
void *TObjPlayer__sub_801BF934(void *p);
s32 TObjPlayer__sub_801BF93C(void *, void *);
u32 TObjPlayer__sub_801BFFA0(void *);
s32 forward_801C210C__10TObjPlayerFv(int, int);
s32 is_action_id_none(s32);
u8 TObjPlayer__sub_801C0124(void *, s16);
int TFontSmallLobby__sub_801C013C(void *p);
int TFontSmallLobby__sub_801C01BC(void *p);
void *TFontSmallLobby__sub_801C01DC(void *arg0, void *arg1);
s32 TFontSmallLobby__sub_801C0228();
void TFontSmallLobby__sub_801C029C(void *);
void TFontSmallLobby__sub_801C030C(Pkt_801B01AC *, s32);
void TFontSmallLobby__sub_801C0378(void *p);
s32 TFontSmallLobby__sub_801C03E0(void *, void *);
s32 TFontSmallLobby__sub_801C041C(void *);
void TFontSmallLobby__sub_801C0438(void *p);
void TFontSmallLobby__sub_801C044C(void *p);
void TFontSmallLobby__sub_801C0480(void *p);
void TFontSmallLobby__sub_801C04C8(void *p);
void fn_801C04DC(void *p);
void fn_801C0510(void *p);
void fn_801C0558(void *p);
void fn_801C056C(void *p);
void fn_801C05A0(void *p);
void fn_801C05B4(void *p);
void fn_801C05E8(void *p);
void fn_801C05FC(void *p);
void fn_801C0630(void *p);
void fn_801C0644(void *p);
void TObjPlayer__sub_801C06BC(Pkt_801B1D8C *, s32);
void TObjPlayer__sub_801C0734(void *);
void TObjPlayer__sub_801C07B4(Pkt_801B1EE0 *, s32);
void apply_status_effect__10TObjPlayerFPv(void *);
void *TObjPlayer__sub_801C092C(void *arg0, void *arg1);
void bswap_pkt_u16x2_u32__10TObjPlayerFPv(void *p);
void TObjPlayer__sub_801C0C04(u8 *arg0);
void swap_endian__10TObjPlayerFi(s32 arg0);
void TObjPlayer__sub_801C0D7C(u8 *arg0);
void bswap_fields__10TObjPlayerFi(void *);
void TObjPlayer__sub_801C106C(void *, void *);
void TObjPlayer__sub_801C1268(void *, void *);
void TObjPlayer__sub_801C1664(void *, void *);
void TObjPlayer__sub_801C18E0(void *);
f32 fn_801C19A4(void *);
s32 TWindowDuelResult__sub_801C19AC(void *);
void TObjPlayer__sub_801C19C8(void *p, f32 v);
s32 TLobby__sub_801C19D0(void *p);
void fn_801C19D8(void *p, s32 v);
void fn_801C19E0(void *, s32);
void fn_801C19E8(void *p);
void fn_801C19F4(void *p);
void *TObjPlayer__sub_801C1A00(void *p);
s32 TObjPlayer__sub_801C1AC8(void *);
s32 TObjPlayer__sub_801C1B0C(void *, int);
s32 fn_801C1B88(void *p);
f32 get_lock_target_distance_sq(s32, u32);
u16 get_lock_target_id(void *p);
s32 fn_801C1BA0();
s32 is_action_channel_active(s32, s32);
u8 *TWindowActionPalette__sub_801C1D7C(s32 arg0, s32 i, s32 arg2);
s32 get_entry_by_index__20TWindowActionPaletteFPll(s32, s32);
s32 fn_801C1E44(s32);
s32 fn_801C1E48(s32);
s32 test_photon_blast_modifier(s32);
s32 fn_801C1E74(s32);
s32 fn_801C1EA4(s32);
s32 fn_801C1EC4(s32);
s32 fn_801C1EF4(s32);
void set_photon_blast_kind(void *, s16);
s32 fn_801C1F1C(s32);
s32 TObjPlayer__sub_801C1F50(s32);
s32 TObjPlayer__sub_801C2044(s32 *arg0);
TItemData* TObjPlayer__sub_801C2058(DeathDropRecord*);
void* init_c2098_return_self__10TObjPlayerFv(void*);
void init_player_telepipe_record(void *);
s16 TObjPlayer__sub_801C2114(void);
u8 TObjPlayer__sub_801C212C(void *p);
u8 TObjPlayer__sub_801C2134(void *p);
s32 get_level_row_exp_threshold();
s8 TObjPlayer__sub_801C21AC(void *);
s8 TObjPlayer__sub_801C21B4(void *);
s8 TObjPlayer__sub_801C21BC(void *);
s32 TLobby__sub_801C2678();
void fn_801C5420(void *, s32);
int fn_801C543C(void*);
s32 are_trap_counts_full(void *, void *, int);
void TObjPlayer__sub_801C5780(void *, s32, s32);
int reset_ring__10TObjPlayerFv(void*);
int clear_target_lock__10TObjPlayerFv(void*);
void update_target_lock__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 init_shield_params__10TObjPlayerFl(void *, void *, void *, int, int);
s32 set_arrival_override_pos(u16, int, int);
void create__15TPlyOnCountOverFPvPvPv(s16, s32, void (*)(void));
void update_player_scale_camera(PlayerScaleState *state);
s32 request_player_size_restore(void *);
u32 create_lobby_marker__10TObjPlayerFsc(s32 a0 = 0, s32 a1 = 0);
s32 get_contact_surface_type(void *);
s32 can_guard__10TObjPlayerFPv(u8 *arg0);
void release_all_players_control_lock(void);
s32 check_conditions__10TObjPlayerFv(void *, s16);
u8 *TObjPlayer__sub_801CFBFC(u8 *arg0);
void run_action_state_phase__10TObjPlayerFisi(void *, s32, s32);
s32 insert_item_node__10TObjPlayerFiiiii(int, void *, void *, void *, int);
void create_drop_nodes__9TItemListFPvPvPvPvi(u8*,DeathItemPosition*,TObjPlayer*,DeathDropRecord*,s32);
s32 check_player_action_allowed();
s32 TObjPlayer__sub_801D4368(void * a0 = 0);
void TObjPlayer__sub_801D47EC(void *, s32, s32);
s32 run_state_query__10TObjPlayerFi(s32, void *);
s32 TObjPlayer__sub_801D49F4(s32, void *, s32, s32, void *);
s32 use_item__6TLobbyFlll(s32, void *, s32, s32, void *);
void TLobby__sub_801D4C28(s32, Pl_801B0B88 *, s32, s32);
u32 find_first_inventory_entry__10TObjPlayerFi(int, void *);
u32 set_mode_and_refresh_object__10TObjPlayerFPvi(s32, s8 *);
u8 * TPlyItem__ct(void *, void *);
s32 set_field_1c__10TObjPlayerFl(void *, void *);
u8 * __ct__9TItemListFv(void *, void *);
s32 draw_party_label__15TFontSmallLobbyFiUis(s32, s32, s32);
s32 accumulate_damage_stats(s32, s32, s32);
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
s32 get_guild_return_yaw__10TObjPlayerFv(void *);
s32 get_guild_return_position__10TObjPlayerFPv(void *);
s32 get_hospital_yaw__10TObjPlayerFv(void *);
s32 get_hospital_position__10TObjPlayerFv(void *);
u8 * TObjPlayer__sub_801D8DCC();
s32 TObjPlayer__sub_801D91B8(void *, void *);
s32 get_current_state_field__10TObjPlayerFScl(s32, s32);
s32 get_class_attack_template(void *);
s32 get_class_defense_template();
void * get_class_stat_caps();
f32 get_tp_class_factor__10TObjPlayerFv();
f32 get_class_technique_boost(s32, s32);
void split_capped_value__10TObjPlayerFUcPUcPSc(u8, void *, void *);
void update_all_units__10TObjPlayerFll(void *, u8);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 is_boss_area();
int is_item_area_enabled(void);
s32 get_floor_map_terrain(int);
s32 __ct__17TMedicalCenterMesFP7TObjectP10TObjPlayer(void *, void *, void *);
s32 play_sound_effect(s32, s32, s32, s32);
void set_area__6TLobbyFl(void *, int, int);
void TWindowSubStatusDisp__sub_80228F5C(s32 arg0);
void text_builder_append(u8 *str);
u32 __nw__7TObjectFUl(s32);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
u8 * __ct__7TObjectFP7TObject(void *, void *);
void construct_actor_light_task(void *, Color_801B6964 *, Vec_801B6964 *, s32, s32, s32, f32);
void TLobby__sub_8024AC20(s32);
void dispatch_to_child__11TWindowCtrlFPv(u16, s32);
u32 TWindowReturnCity__ct(u32, s32, u16);
s32 get_battle_ctrl_default__6TLobbyFv();
s32 get_party_yaw();
u8 *get_party_position(void);
s32 TNpcPlayer__sub_8034DE40();
void TObjPlayer__sub_80354BE4(s32);
s32 TObjPlayer__sub_80354D5C(s32);
void TObjPlayer__sub_80354E7C(void);
s32 fn_8036B748(void *);
s32 fn_8036B770(void *);
s32 validate_6xAE_set_animation_state(void *);
}
void obj_copyVec2_0(u8 *d, u8 *s);
void reset_cameras_to_actor(void *actor, s32 arg1);
void set_shadow_material_state(void);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void draw_motion_model_saving_joints(TObjPlayer *arg0);
void mask_action_buttons(void *p, u32 v);
void emit_sand_footstep_effect(s32 arg0);
void emit_water_footstep_effect(s32 arg0);
void emit_grass_footstep_effect(s32 arg0);
void init_6x27_use_item_cmd(u8 *arg0);
void init_6x1F_floor_packet(u8 *arg0);
void init_6x21_inter_level_warp_packet(u8 *arg0);
void refill_trap_counts(s32 arg0, s32 arg1, s32 arg2);
void update_player_appear_fade(u8 *arg0);
void save_render_material_state(u8 *arg0);
void reinit_photon_blast_gauge(u16 *arg0);
s32 get_ply_level_table_row(s8 arg0, s32 arg1);
s32 player_auxiliary_surfaces_enabled();
void text_builder_reset(void);
void restore_render_scissor(s32 arg0);
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
extern "C" {
void __construct_array(void *, void *(*)(void *), void *, u32, u32);
s32 rand();
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 matrix_mult_vec(int, void *, void *);
f32 vec3_dot(Vec_801B5DDC *, Vec_801B5DDC *);
void scale_matrix(int, f32, f32, f32);
int vector_length(void*);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(s32, s32);
void rotate_matrix_z(int, s32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void rotate_matrix_x(int, s32);
s32 push_matrix_from(int);
s32 push_matrix();
s32 pop_matrix();
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
void draw_chunk_object(void *child);

extern s32 TOMineTrap__data_805D3080;
extern s32 TObjPlayer__player_set_class_name;
extern const f32 TObjPlayer__data_805DC278;
extern f32 TObjPlayer__data_805DC28C;
extern f32 TObjPlayer__data_805DC294;
extern const f32 TObjPlayer__data_805DC2BC;
extern RecoveredGlobal_802A1154_main_task TObjPlayer__sub_801BEABC;
extern const Vec_801B92EC lbl_80446F2C;
extern u8 lbl_80446F50[];
extern u8 lbl_80446F5C[];
extern const f64 lbl_80446F68;
extern u8 main_phase_state[];
extern Vec_801B6964 lbl_8050BEE0[];
extern DeathItemPosition lbl_8050BF60;
extern Color_801B6964 player_feedback_light_color[];
extern void *player_slot_table[];
extern u8 lobby_rule_settings[];
extern ReturnLobby lbl_80515BA0;
extern s32 lbl_805D2B28;
extern s32 lbl_805D3530;
extern s32 actor_frame_tick;
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
extern const f32 lbl_805DC2C0;
extern const f32 lbl_805DC2C4;
extern const f32 lbl_805DC2C8;
extern const f32 lbl_805DC2CC;
extern const f32 lbl_805DC2D0;
extern const f32 lbl_805DC2D4;
extern s32 model_render_flags;
extern RecoveredGlobal_8000F7FC_lbl_80515F48 start_freeze_self__10TObjPlayerFv;
extern u32 tl_03;
extern s32 tl_05;
extern List_801BC068 *tl_06;
extern s32 tl_07;

extern "C" {
s32 TObjPlayer__sub_801BE2C8(void *);
void TObjPlayer__sub_801BE2C0(void *, s32);

s32 TObjPlayer__sub_801AF290(void *p) {
    s32 v;
    TObjPlayer *target;
    s32 r = 0;
    TObjPlayer *player;
    s32 cur = TObjPlayer__sub_801BE2C8(p);
    target = player = (TObjPlayer *)p;
    v = cur + 1;
    if (v >= ((s32 (*)(void *, s32))calc_stat_threshold__10TObjPlayerFPv)(target, cur)) {
        v = 0;
        r = 1;
    }
    TObjPlayer__sub_801BE2C0(player, v);
    return r;
}
}
s32 calc_stat_threshold__10TObjPlayerFPv(void *arg0) {
    s32 var_r31;
    var_r31 = ((VObj_801AF2F0*)arg0)->m14();
    if (var_r31 > 0x63) {
        var_r31 = 0x63;
    }
    if (((TObjPlayer *)arg0)->is_newman() != 0) {
        var_r31 *= lbl_80446F38;
        return 0x5A - var_r31;
    }
    var_r31 *= lbl_80446F40;
    return 0x3C - var_r31;
}

void TObjPlayer::update_facing_from_lock() {
    if (((VObj_801AF3C4 *)*(void **)((s8 *)this + 0x380))->m8() != 0) {
        this->set_field_dc(((VObj_801AF3C4 *)*(void **)((s8 *)this + 0x380))->m75(1));
        return;
    }
    this->set_field_dc(((VObj_801AF3C4 *)*(void **)((s8 *)this + 0x380))->m75(0));
}

void TObjPlayer::sub_801AF454(s32 x) {
    if (((O_801AF454 *)this)->obj) {
        ((O_801AF454 *)this)->obj->m3(x);
    }
}

f32 TObjPlayer::get_battle_value(s32 arg0, int arg1, s32 arg2) {
    if (((u32 (*)(u16))get_player_by_client_id)((u16)arg1) == 0U) {
        return (*(f32 *)&TObjPlayer__data_805DC278);
    }
    return get_class_technique_boost(((s32 (*)(s32))get_class_index__10TObjPlayerFv)(arg0), arg2);
}

void handle_6x9B_level_up_all_techniques(void *arg0) {
    Msg_801CD6BC m;
    u8 *p;
    ((TFontSmallLobby *)(&m))->init_packet_6x9b_level_up();
    TFontSmallLobby__sub_801C01DC(&m, arg0);
    TFontSmallLobby__sub_801C01BC(&m);
    if (validate_6x9B_level_up_all_techniques((G_ClientIDHeader *)&m) != 0) {
        p = ((u8 * (*)(u16))get_player_by_client_id)(m.id);
        if (p != NULL) {
            ((TObjPlayer *)(p + 0x428))->level_up_all_techniques(m.level);
        }
    }
}

void TObjPlayer__sub_801AF554(void *arg0, s8 arg1) {
    L_801AF554 sp8;
    if (arg0 == 0 || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(arg0) == 0) {
        ((TFontSmallLobby *)(&sp8))->init_packet_6x9b_level_up();
        sp8.f2 = get_entity_id(arg0);
        sp8.f4 = arg1;
        TFontSmallLobby__sub_801C029C(&sp8);
    }
}

void play_voice_pair__10TObjPlayerFPv(TObjPlayer *arg0) {
    set_hp_clamped__10TObjPlayerFs(arg0, arg0->hpmax);
    set_tp__10TObjPlayerFs(arg0, arg0->tpmax);
}

void TObjPlayer::reset_pose() { this->obj_clearFlags30((u32)((void*)2048)); ((int (*)(void*))update_rotation__10TObjPlayerFv)(this); }

u32 TObjPlayer::set_lobby_marker(s32 arg1) {
    u32 temp;

    if (((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() == 0) {
        return 0U;
    }
    temp = *(u32 *)((s8 *)this + 0x3B8);
    if (temp == 0U) {
        *(u32 *)((s8 *)this + 0x3B8) = create_lobby_marker__10TObjPlayerFsc(get_entity_id(this), arg1);
    } else {
        set_material_index__18TPlayerLobbyMarkerFUc(temp, arg1);
    }
    return *(u32 *)((s8 *)this + 0x3B8);
}

int TObjPlayer__sub_801AF694(void* p) { return fn_801C543C((char*)p + 0x7c4); }

s32 is_action_available__10TObjPlayerFi(s32 arg0) {
    if ((are_items_enabled_here() == 0) || (is_boss_area() != 0)) {
        return 0;
    }
    if (is_camera_ready__10TObjPlayerFv() != 0) {
        return (u32)__cntlzw(obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x20000)) >> 5;
    }
    return ((TObjPlayer *)arg0)->is_android() != 0 ? 1 : 0;
}

s32 TObjPlayer::are_traps_full() {
    return are_trap_counts_full((u8 *)((V_801AF734 *)this) + 0x7C4, ((V_801AF734 *)this)->m14(), ((s32 (*)(void *))get_class_index__10TObjPlayerFv)(((V_801AF734 *)this))) != 0 ? 1 : 0;
}

s32 TObjPlayer::is_alive_and_ready() {
    s32 arg0 = (s32)this;
    if ((((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() == 0) && (((TObjPlayer *)arg0)->is_android() != 0)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::refill_traps() {
    refill_trap_counts((s32)(((TObjPlayer_801AF7E0 *)this)->slot), this->get_actor_level_index(), ((s32 (*)(void))get_class_index__10TObjPlayerFv)());
}

void TObjPlayer::update_movement_by_screen() {
    if (is_single_screen__10TObjPlayerFv() != 0) {
        get_battle_ctrl_default__6TLobbyFv();
        return;
    }
    TLobby__sub_801C2678();
}

struct Ent_801AF868 { u16 id; s16 val; u32 pad; };
Ent_801AF868 *TWindowDuelResult__sub_801C257C();
Ent_801AF868 *get_split_screen_battle_rankings();

s16 TObjPlayer__sub_801AF868(void *arg0) {
    s32 id;
    Ent_801AF868 *e;
    int i;

    id = get_entity_id(arg0);
    if (is_single_screen__10TObjPlayerFv() != 0) {
        e = get_split_screen_battle_rankings();
    } else {
        e = TWindowDuelResult__sub_801C257C();
    }
    for (i = 0; i < 4; i++, e++) {
        if ((u16)id == e->id) {
            return e->val;
        }
    }
    return -1;
}

void set_flags_a00__10TObjPlayerFPv(void *arg0) {
    if (arg0 != NULL) {
        obj_setFlags30(arg0, 0xA00);
    }
}

void TObjPlayer__sub_801AF904(s32 arg0) {
    s32 temp_r3;
    temp_r3 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x24);
    if (temp_r3 != 0) {
        __ct__20TPlayerReadyCallbackFP7TObjectUsPFP10TObjPlayer_v(temp_r3, arg0, ((s32 (*)(s32))get_entity_id)(arg0), (void (*)(int))set_flags_a00__10TObjPlayerFPv);
    }
}

void clamp_stats__10TObjPlayerFiPv(s32 arg0, void *arg1) {
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
    void *class_stat_caps;
    void *temp_r31;

    temp_r31 = get_quest_id__12TQuestListVMFv();
    ((s32 (*)(s32))get_class_index__10TObjPlayerFv)(arg0);
    class_stat_caps = get_class_stat_caps();
    temp_r4 = *(s16 *)((s8 *)temp_r31 + 0);
    if (temp_r4 < 0) {
        *(s16 *)((s8 *)arg1 + 0) = 1;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    } else {
        temp_r0 = *(s16 *)((s8 *)class_stat_caps + 0);
        if (temp_r4 > temp_r0) {
            *(s16 *)((s8 *)arg1 + 0) = temp_r0;
            ((TObjPlayer *)arg0)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 0) = temp_r4;
        }
    }
    temp_r3 = *(s16 *)((s8 *)temp_r31 + 2);
    if (temp_r3 < 0) {
        *(s16 *)((s8 *)arg1 + 2) = 1;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    } else {
        temp_r0_2 = *(s16 *)((s8 *)class_stat_caps + 2);
        if (temp_r3 > temp_r0_2) {
            *(s16 *)((s8 *)arg1 + 2) = temp_r0_2;
            ((TObjPlayer *)arg0)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 2) = temp_r3;
        }
    }
    temp_r3_2 = *(s16 *)((s8 *)temp_r31 + 4);
    if (temp_r3_2 < 0) {
        *(s16 *)((s8 *)arg1 + 4) = 1;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    } else {
        temp_r0_3 = *(s16 *)((s8 *)class_stat_caps + 4);
        if (temp_r3_2 > temp_r0_3) {
            *(s16 *)((s8 *)arg1 + 4) = temp_r0_3;
            ((TObjPlayer *)arg0)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 4) = temp_r3_2;
        }
    }
    if (*(s16 *)((s8 *)temp_r31 + 6) < 0) {
        *(s16 *)((s8 *)arg1 + 6) = 1;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    }
    temp_r3_3 = *(s16 *)((s8 *)temp_r31 + 6);
    temp_r0_4 = *(s16 *)((s8 *)class_stat_caps + 6);
    if (temp_r3_3 > temp_r0_4) {
        *(s16 *)((s8 *)arg1 + 6) = temp_r0_4;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    } else {
        *(s16 *)((s8 *)arg1 + 6) = temp_r3_3;
    }
    temp_r3_4 = *(s16 *)((s8 *)temp_r31 + 8);
    if (temp_r3_4 < 0) {
        *(s16 *)((s8 *)arg1 + 8) = 1;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    } else {
        temp_r0_5 = *(s16 *)((s8 *)class_stat_caps + 8);
        if (temp_r3_4 > temp_r0_5) {
            *(s16 *)((s8 *)arg1 + 8) = temp_r0_5;
            ((TObjPlayer *)arg0)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 8) = temp_r3_4;
        }
    }
    temp_r3_5 = *(s16 *)((s8 *)temp_r31 + 0xA);
    if (temp_r3_5 < 0) {
        *(s16 *)((s8 *)arg1 + 0xA) = 1;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    } else {
        temp_r0_6 = *(s16 *)((s8 *)class_stat_caps + 0xA);
        if (temp_r3_5 > temp_r0_6) {
            *(s16 *)((s8 *)arg1 + 0xA) = temp_r0_6;
            ((TObjPlayer *)arg0)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 0xA) = temp_r3_5;
        }
    }
    temp_r3_6 = *(s16 *)((s8 *)temp_r31 + 0xC);
    if (temp_r3_6 < 0) {
        *(s16 *)((s8 *)arg1 + 0xC) = 1;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    } else {
        temp_r0_7 = *(s16 *)((s8 *)class_stat_caps + 0xC);
        if (temp_r3_6 > temp_r0_7) {
            *(s16 *)((s8 *)arg1 + 0xC) = temp_r0_7;
            ((TObjPlayer *)arg0)->clamp_stat_41c();
        } else {
            *(s16 *)((s8 *)arg1 + 0xC) = temp_r3_6;
        }
    }
    temp_r3_7 = *(s16 *)((s8 *)temp_r31 + 0xE);
    if (temp_r3_7 < 0) {
        *(s16 *)((s8 *)arg1 + 0xE) = 1;
        ((TObjPlayer *)arg0)->clamp_stat_41c();
    } else {
        *(s16 *)((s8 *)arg1 + 0xE) = temp_r3_7;
    }
    *(f32 *)((s8 *)arg1 + 0x10) = (f32) *(f32 *)((s8 *)temp_r31 + 0x10);
    *(f32 *)((s8 *)arg1 + 0x14) = (f32) *(f32 *)((s8 *)temp_r31 + 0x14);
    temp_r28_2 = *(s32 *)((s8 *)temp_r31 + 0x18);
    max_level = TObjPlayer::get_max_level();
    if (temp_r28_2 < 0) {
        *(s32 *)((s8 *)arg1 + 0x18) = 0;
        ((TObjPlayer *)arg0)->set_flag_41c_bit1();
    } else if (temp_r28_2 > max_level) {
        *(s32 *)((s8 *)arg1 + 0x18) = max_level;
        ((TObjPlayer *)arg0)->set_flag_41c_bit1();
    } else {
        *(s32 *)((s8 *)arg1 + 0x18) = temp_r28_2;
    }
    temp_r28_2 = *(s32 *)((s8 *)temp_r31 + 0x1C);
    temp_r3_8 = get_current_state_field__10TObjPlayerFScl(((s32 (*)(s32))get_class_index__10TObjPlayerFv)(arg0), max_level);
    if (temp_r28_2 < 0) {
        *(s32 *)((s8 *)arg1 + 0x1C) = 0;
        ((TObjPlayer *)arg0)->check_flag_at_41c();
    } else if (temp_r28_2 > temp_r3_8) {
        *(s32 *)((s8 *)arg1 + 0x1C) = temp_r3_8;
        ((TObjPlayer *)arg0)->check_flag_at_41c();
    } else {
        *(s32 *)((s8 *)arg1 + 0x1C) = temp_r28_2;
    }
    temp_r4_2 = *(s32 *)((s8 *)temp_r31 + 0x20);
    if (temp_r4_2 < 0) {
        *(s32 *)((s8 *)arg1 + 0x20) = 0;
        ((TObjPlayer *)arg0)->check_stat_flag_41c();
        return;
    }
    if (temp_r4_2 > 0xF423F) {
        *(s32 *)((s8 *)arg1 + 0x20) = 0xF423F;
        ((TObjPlayer *)arg0)->check_stat_flag_41c();
        return;
    }
    *(s32 *)((s8 *)arg1 + 0x20) = temp_r4_2;
}

f32 TObjPlayer__vt20(s32 arg0, s32 att, f32 scale) {
    if (obj_isState2_324__13TUnk_804806E8Fv() != 0) {
        return (*(f32 *)&TObjPlayer__data_805DC278);
    }
    return receive_physical_attack__13TUnk_804806E8FPvf(arg0, att, scale);
}

s16 TObjPlayer::get_handle_value() { return (s16)(((TObjPlayer *)(*(void**)((char*)this + 0x380)))->sub_802a7290_fwd()); }

void TObjPlayer::set_action_provider_variant(s16 arg1) {
    if (arg1 != ((TObjPlayer *)(((Player_801AFCF4 *)this)->obj))->sub_802a7290_fwd() && fn_8000F740(main_phase_state) != 0) {
        ((Player_801AFCF4 *)this)->obj->m4(((u16 (*)(void *))get_entity_id)(((Player_801AFCF4 *)this)), ((TObjPlayer *)((Player_801AFCF4 *)this))->has_valid_handle(), arg1);
        this->apply_motion_entry();
    }
}

s32 TRaderMapCore::get_map_id() { return *(s32*)((char*)this + 0x3d0); }

s32 TObjPlayer__sub_801AFD8C(u8 *arg0) {
    s32 temp_r3;
    temp_r3 = *(s32 *)((s8 *)arg0 + 0x3BC);
    if ((temp_r3 < 0) || (temp_r3 >= 5)) {
        return 1;
    }
    return temp_r3;
}

s32 TObjPlayer::get_class_flags() { return this->class_flags; }

s8 TObjPlayer::get_class_index() {
    return (s8) this->m_88d;
}

s8 TObjPlayer__sub_801AFDBC(s8 arg0) {
    if ((arg0 < 0) || (arg0 >= 0xC)) {
        return 0;
    }
    return arg0;
}

s32 TObjPlayer::check_technique_castable(s32 arg0) {
    s32 global_state;

    if ((((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() != 0) || (is_camera_mode_active__10TObjPlayerFv() != 0) || (is_boss_area() != 0)) {
        ((TObjPlayer *)arg0)->check_technique_flag();
        return 0;
    }
    global_state = get_current_area();
    switch (global_state) {
    case 0:
    case 15:
    case 18:
        ((TObjPlayer *)arg0)->check_technique_flag();
        return 0;
    default:
        ((TObjPlayer *)arg0)->has_item_flag_4096();
        return 1;
    }
}

u8 is_key_machine_ready__10TObjPlayerFv(void) {
    s32 global_state;
    s32 var_r0;

    global_state = get_current_area();
    var_r0 = 0;
    if ((global_state == 0) || (global_state == 0x12)) {
        var_r0 = 1;
    }
    return (u8) var_r0;
}

u8 is_volopt_phase_final__10TObjPlayerFv(void) {
    return (u8) (get_field_3e0__12TBoss3VoloptFv() == 0xF);
}

u8 is_lobby_floor_15__15TFontSmallLobbyFv(void) {
    return (u8) (get_current_area() == 0xF);
}

u8 is_on_current_floor__10TObjPlayerFi(s32 arg0) {
    s32 current_floor;
    s32 temp_r3;
    current_floor = get_current_floor();
    temp_r3 = ((TObjPlayer *)arg0)->get_field_3e4();
    return (u8) (temp_r3 == current_floor);
}

void TObjPlayer::sync_current_floor() {
    this->m_3e4 = get_current_floor();
}

void TObjPlayer::sync_current_area() {
    *(s32 *)((s8 *)((u8 *)this) + 0x3E0) = TObjPlayer::get_key_machine_global_state(this);
}

int TObjPlayer::get_key_machine_global_state(void* p) { return ((int)get_current_area()); }

s32 TObjPlayer__sub_801AFFD0(u8 *arg0) {
    f32 v;

    v = (f32)TWindowDuelResult__sub_801C19AC(arg0 + 0x78C);
    v -= (f32)TWindowDuelResult__sub_801C19AC(arg0 + 0x77C);
    v += (f32)TWindowDuelResult__sub_801C19AC(arg0 + 0x75C);
    v -= (f32)TWindowDuelResult__sub_801C19AC(arg0 + 0x76C);
    if (obj_testFlags30__13TUnk_804AF8A0FUl((s32)arg0, 0x800) == 0) {
        v += (f32)obj_getPtr2B0_20(arg0) * fn_801C19A4(arg0 + 0x79C);
    }
    return (s32)v;
}

void TObjPlayer__sub_801B0124(u8 *self, s32 arg1) {
    if (((s32 (*)(s32))is_locally_controlled__10TObjPlayerFPv)((s32) self) == 0 || ((u8 (*)(void *))TLobby__sub_801D6FFC)(lobby_rule_settings) != 2 || ((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() == 0) {
        return;
    }
    TObjPlayer__sub_801C19C8(self + 0x79C, (f32) arg1);
}

void handle_6x8F_add_battle_damage_scores(s32 arg0) {
    Pkt_801B01AC pkt;
    u8 *player;
    u8 *target;
    u8 *other;
    ((TFontSmallLobby *)(&pkt))->init_packet_6x8f_battle_damage();
    TFontSmallLobby__sub_801C030C(&pkt, arg0);
    ((TFontSmallLobby *)(&pkt))->bswap_battle_damage_packet();
    if (validate_6x8F_add_battle_damage_scores((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    player = ((u8 * (*)(u16))get_player_by_client_id)(pkt.client);
    if (player == NULL) {
        return;
    }
    target = find_entity_by_id(pkt.target);
    if (target == NULL) {
        return;
    }
    if ((u16)((s32 (*)(u8 *))get_entity_id)(target) != (u16)((s32 (*)(u8 *))get_entity_id)(player)) {
        accumulate_damage_stats((s32)(player + 0x78C), (s32)target, pkt.amount);
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl((s32)target, 0x10000000) == 0) {
        return;
    }
    other = ((u8 * (*)(u16))get_player_by_client_id)((u16)((s32 (*)(u8 *))get_entity_id)(target));
    if (other != NULL) {
        accumulate_damage_stats((s32)(other + 0x77C), (s32)player, pkt.amount);
    }
}

void apply_camera_shake__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2) {
    if ((((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() != 0) && (obj_testFlags30__13TUnk_804AF8A0FUl(arg1, 0x10000000) == 0) && (((s32 (*)(s32))is_locally_controlled__10TObjPlayerFPv)(arg0) != 0)) {
        accumulate_damage_stats(arg0 + 0x78C, arg1, arg2);
    }
}

void handle_6x8E(void) {  }

void record_damage_stats__10TOMineTrapFUiUis(u32 arg0, u32 arg1, s16 arg2) {
  Pkt_801B0300 pkt;
  u32 temp_r3;
  u32 obj;
  if (((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() != 0)
  {
    obj = arg1;
    if ((((s32 (*)(u32, s32))check_value_equals__13TUnk_804B6C24Fl)(obj, TOMineTrap__data_805D3080) != 0) && (((TOMineTrap *)obj)->get_trap_type() != 0xFFFF))
    {
      obj = ((u32 (*)(void))find_entity_by_id)();
    }
    if (((s32 (*)(u32, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(obj, 0x10000000) == 0)
    {
      if (((s32 (*)(u32))is_locally_controlled__10TObjPlayerFPv)(arg0) != 0)
      {
        ((int (*)(u32, u32, s16)) accumulate_damage_stats)(arg0 + 0x77C, obj, arg2);
      }
    }
    else
      if ((((s32 (*)(u32))is_locally_controlled__10TObjPlayerFPv)(arg0) != 0) && ((arg0 == 0U) || (((s32 (*)(u32))obj_isState2_324__13TUnk_804806E8Fv)(arg0) == 0)))
    {
      ((int (*)(u32, u32, s16)) accumulate_damage_stats)(arg0 + 0x77C, obj, arg2);
      if (((u16 (*)(u32))get_entity_id)(obj) != ((u16 (*)(u32))get_entity_id)(arg0))
      {
        temp_r3 = ((u32 (*)(int))get_player_by_client_id)(((u16 (*)(u32))get_entity_id)(obj));
        if (temp_r3 != 0U)
        {
          ((int (*)(u32, u32, s16)) accumulate_damage_stats)(temp_r3 + 0x78C, arg0, arg2);
        }
      }
      if (is_final_phase__10TObjPlayerFv() != 0)
      {
        ((TFontSmallLobby *)(&pkt))->init_packet_6x8f_battle_damage();
        pkt.a = ((u16 (*)(u32))get_entity_id)(obj);
        pkt.b = ((u16 (*)(u32))get_entity_id)(arg0);
        pkt.c = arg2;
        TFontSmallLobby__sub_801C0378(&pkt);
      }
    }
  }
}

int TOMineTrap::update_trap_sub() { return ((int (*)(void*))accumulate_damage_stats)((char*)this + 0x76c); }

extern "C" void fn_801B0480(u8 *player, void *attacker, s32 amount) {
    if (check_value_equals__13TUnk_804B6C24Fl(attacker, lbl_805D3530) == 0
        || ((TLobby *)lobby_rule_settings)->get_rule_field_a() != 1
        || TLobby__sub_801C19D0(player + 0x828) != TLobby__sub_801C19D0((u8 *)attacker + 0x828)) {
        accumulate_damage_stats((s32)(player + 0x75C), (s32)attacker, amount);
        play_sound_effect(0x4004B20A, 0, 0, 0);
    }
}

void draw_player_status(s32 arg0, void *arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = (s32)((TUnk_804B6C24 *)arg1)->get_name();
    if (temp_r3 != 0) {
        if (check_value_equals__13TUnk_804B6C24Fl(arg1, lbl_805D3530) != 0) {
            ((s32 (*)(s32, s32, s32, s32))draw_status_line)(arg0, arg2, temp_r3, ((s32 (*)(void *))TObjPlayer__sub_801AFFD0)(arg1));
            return;
        }
        show_sub_status_window((void *)arg0, (s32 *)arg2, (s32 *)temp_r3);
    }
}

void show_sub_status_window(void *arg0, s32 *arg1, s32 *arg2) {
    text_builder_reset();
    text_builder_append((u8 *)arg1);
    text_builder_append((u8 *)arg2);
    text_builder_append((u8 *)&lbl_805DC27C);
    TWindowCtrl::init_all((void*)(get_shared_text_buffer()), (void*)0x200);
}

void draw_status_line(void *arg0, s32 *arg1, s32 *arg2, s32 arg3) {
    text_builder_reset();
    text_builder_append((u8 *)arg1);
    text_builder_append((u8 *)arg2);
    text_builder_append((u8 *)&lbl_805DC27C);
    TWindowSubStatusDisp__sub_80228F5C(arg3);
    text_builder_append((u8 *)&lbl_805DC27C);
    TWindowCtrl::init_all((void*)(get_shared_text_buffer()), (void*)0x200);
}

int TObjPlayer__sub_801B066C(void* p) { return TLobby__sub_801C19D0((char*)p + 0x828); }

void handle_6x90_set_player_battle_team(s32 arg0) {
    struct Cmd_801B0690 cmd;
    u8 *p;
    s32 team;
    TFontSmallLobby__sub_801C041C(&cmd);
    TFontSmallLobby__sub_801C03E0(&cmd, (void *) arg0);
    ((TFontSmallLobby *)(&cmd))->bswap_6x90_set_player_battle_team();
    if (validate_6x90_set_player_battle_team((G_ClientIDHeader *)&cmd) == 0) {
        return;
    }
    p = ((u8 * (*)(u16))get_player_by_client_id)(cmd.client);
    if (p == NULL) {
        return;
    }
    team = cmd.team;
    fn_801C19D8(p + 0x828, team);
    if (team == 1) {
        TMainCursor__sub_801540B8((int) p, *(s32 *)((s8 *)p + 0xA4), 0);
    } else {
        TMainCursor__sub_80154098((int) p, *(s32 *)((s8 *)p + 0xA4), 0);
    }
}

void check_flag_01000000__10TObjPlayerFPv(void *player) {
    check_flag__10TObjPlayerFl(player, 0x01000000);
}

void TObjPlayer::set_flag_drop_weapon_on_death() {
    sub_8011E204__10TObjPlayerFl(this, 0x01000000);
}

void handle_6x82_enable_drop_weapon_on_death(void *arg0) {
    struct pkt_801B1674 pkt;
    TFontSmallLobby__sub_801C0438(&pkt);
    TLobby__sub_801B07E0((s32)((s32)((s32) &pkt)), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x82_enable_drop_weapon_on_death((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_flag_drop_weapon_on_death();
        }
    }
}

s32 TLobby__sub_801B07E0(s32 arg0, void * _w1) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void TLobby::send_field1c_packet(s32 arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        TFontSmallLobby__sub_801C0438((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        TFontSmallLobby__sub_801C044C((s32 *)&sp8);
    }
}

void TObjPlayer::disable_drop_weapon_on_death(void *arg0) {
    ((s32 (*)(void *, s32))set_state_flags__10TObjPlayerFUl)(arg0, 0x01000000);
}

void handle_6x81_disable_drop_weapon_on_death(void *arg0) {
    struct pkt_801B1674 pkt;
    TFontSmallLobby__sub_801C0480(&pkt);
    TLobby__sub_801B08F0((s32)((s32)((s32) &pkt)), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x81_disable_drop_weapon_on_death((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            TObjPlayer::disable_drop_weapon_on_death(p);
        }
    }
}

s32 TLobby__sub_801B08F0(s32 arg0, void * _w1) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void TLobby::send_font_state(s32 arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        TFontSmallLobby__sub_801C0480((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TFontSmallLobby *)((s32 *)&sp8))->send_font_state_msg();
    }
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

void TLobby__sub_801B09A4(void) {
    VObj_801B09A4 *players[12];
    s32 i;
    VObj_801B09A4 *p;
    shared_state_flags |= 1;
    for (i = 0; i < 12; i++) {
        players[i] = NULL;
    }
    for (i = 0; i < 12; i++) {
        p = ((VObj_801B09A4 * (*)(s32))get_player_by_client_id)(i);
        if (p != NULL) {
            players[i] = p;
            if (p != NULL) {
                p->m0(1);
            }
        }
    }
    for (i = 0; i < 12; i++) {
        if (players[i] != NULL) {
            create_player_instance__10TObjPlayerFll(i, &lobby_char_slot_array[i]);
            TLobby__sub_8024AC20(i);
        }
    }
    shared_state_flags &= ~1;
}

s32 check_switch_available__6TLobbyFPvi(void *arg0, s32 arg1) {
    if (((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() != 0) {
        if (fn_801D71D0(((s32 *)&lobby_rule_settings)) == 2) {
            if (start_inventory_update__10TObjPlayerFi(*(s32 *)((s8 *)arg0 + 0xD00), arg1) == 0U) {
                return 0;
            }
            if (get_owner_if_alive__10TObjPlayerFv() == 0U) {
                return 0;
            }
            if (((u8 (*)(void))get_item_type__5TItemFv)() == 0) {
                return 0;
            }
            goto block_8;
        }
block_8:
        if (fn_801D719C(((s32 *)&lobby_rule_settings)) == 1) {
            if (start_inventory_update__10TObjPlayerFi(*(s32 *)((s8 *)arg0 + 0xD00), arg1) == 0U) {
                return 0;
            }
            if (get_owner_if_alive__10TObjPlayerFv() == 0U) {
                return 0;
            }
            if (((u8 (*)(void))get_item_type__5TItemFv)() == 2) {
                return 0;
            }
            goto block_15;
        }
        goto block_15;
    }
block_15:
    return 1;
}

void TLobby::apply_battle_rules_to_players() {
    s32 i;
    s32 *q;
    Pl_801B0B88 *p;
    s32 j;
    s32 lv;
    q = ((s32 *)&lobby_rule_settings);
    for (i = 0; i < 0xC; i++) {
        p = (Pl_801B0B88 *)((VObj_801B09A4 * (*)(s32))get_player_by_client_id)(i);
        if (p == NULL) {
            continue;
        }
        ((TLobby *)(p->f754))->update_all_children();
        if (((TLobby *)q)->get_rule_field_0() == 1) {
            ((TObjPlayer *)p)->set_state_flag_6043();
            if (((s32 (*)(Pl_801B0B88 *))is_locally_controlled__10TObjPlayerFPv)(p) != 0) {
                lobby_player_count = 1;
            }
        } else {
            return;
        }
        switch (fn_801D71D0(q)) {
        case 1:
        case 2:
        case 3:
            ((TLobby *)(p->fD00))->set_globals_and_update((int)p, 0);
            ((TLobby *)(p->fD00))->set_globals_and_update((int)p, 1);
            break;
        }
        switch (fn_801D719C(q)) {
        case 1:
            ((TLobby *)(p->fD00))->set_globals_and_update((int)p, 2);
            break;
        }
        if ((j = get_item_field_6__10TObjPlayerFPv(p)) != 0 && check_equip_requirements__5TItemFP10TObjPlayerPs(j, p, 0) == 0) {
            ((void (*)(Pl_801B0B88 *, s32))unequip_item__10TObjPlayerFiPv)(p, j);
        }
        switch (fn_801D7168(q)) {
        case 1:
        case 2:
            ((TLobby *)(p->fD00))->set_globals_and_update((int)p, 3);
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
            apply_battle_level_reset__10TObjPlayerFv(p, ((TLobby *)q)->clamp_player_index());
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
        if (((TLobby *)q)->normalize_battle_rule_value() == 1 && ((s32 (*)(Pl_801B0B88 *))is_locally_controlled__10TObjPlayerFPv)(p) != 0) {
            ((TObjPlayer *)(p->f424))->set_flags_bit2();
        }
        if (TLobby__sub_801D6FFC(q) != 0) {
            ((TObjPlayer *)p)->set_meseta(0);
        }
        if (((TLobby *)q)->clamp_value_below_2() == 1) {
            fn_801C5420(p->f7C8, TObjPlayer__sub_801D6D28(q));
        }
        if (TLobby__sub_801D6F94(q) == 1) {
            TLobby__sub_801D4C28(p->fD00, p, 3, 9);
        }
        ((TObjPlayer *)p)->check_technique_flag();
        ((void (*)(Pl_801B0B88 *))recover_full__10TObjPlayerFPv)(p);
        ((TObjPlayer *)p)->cancel_status_effects();
        ((TObjPlayer *)(&lobby_char_slot_array[i]))->copy_lobby_header((s32)p);
    }
}

u8 is_technique_ready__8TTecCtrlFv(void) {
    int var_r31;

    var_r31 = 0;
    if ((TObjPlayer::get_player_count() == 1) && (TObjPlayer::get_rule_field_0() == 1)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

s32 TObjPlayer::add_actor_exp(s32 arg1) {
    s32 temp_r31;
    s32 temp_r3;
    void *temp_r4;

    if (are_items_enabled_here() == 0) {
        return 0;
    }
    temp_r4 = this->m_2b0;
    temp_r31 = *(s32 *)((s8 *)temp_r4 + 0x1C);
    temp_r3 = TObjPlayer__sub_801D91B8(this, temp_r4);
    temp_r31 = temp_r31 + arg1;
    if (temp_r31 > temp_r3) {
        temp_r31 = temp_r3;
    }
    if (temp_r31 < 0) {
        temp_r31 = 0;
    }
    *(s32 *)(this->m_2b0 + 0x1C) = temp_r31;
    return 1;
}

void TObjPlayer::update_photon_chair() {
    s32 arg0 = (s32)this;
    ((TObjPlayer *)(arg0 + 0x634))->enter_battle_state();
    if (((s32 (*)(s32))obj_isState2_324__13TUnk_804806E8Fv)(arg0) != 0) {
        ((TObjPlayer *)arg0)->set_flag_400000();
    }
}

void TObjPlayer::refresh_equipment_slot() {
    u8 *temp_r3;
    temp_r3 = activate_d04_slot__10TObjPlayerFv(this);
    if (temp_r3 != NULL) {
        ((TItem *)temp_r3)->snap_to_owner();
    }
}

void check_flag_800000__10TObjPlayerFPv(void *player) {
    check_flag__10TObjPlayerFl(player, 0x800000);
}

void TObjPlayer::clear_stealth_suit_flags() {
    ((void (*)(void *, u32))sub_8011E204__10TObjPlayerFl)(this, 0x800000U);
    this->clear_player_status_flag(0, 0x08000000);
}

void handle_6x7B_disable_stealth_suit_effect(void *arg0) {
    struct pkt_801B1674 pkt;
    TFontSmallLobby__sub_801C04C8(&pkt);
    TFontSmallLobby::disable_stealth_suit_effect((s32)((s32)((s32) &pkt)), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x7B_disable_stealth_suit_effect((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->clear_stealth_suit_flags();
        }
    }
}

s32 TFontSmallLobby::disable_stealth_suit_effect(s32 arg0, void * _w1) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void draw_small_label__15TFontSmallLobbyFi(s32 arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        TFontSmallLobby__sub_801C04C8((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        fn_801C04DC((s32 *)&sp8);
    }
}

void TObjPlayer::set_stealth_suit_flags() {
    set_state_flags__10TObjPlayerFUl(this, 0x800000U);
    set_indexed_flags(0, 0x08000000);
}

void handle_6x7A_enable_stealth_suit_effect(void *arg0) {
    struct pkt_801B1674 pkt;
    fn_801C0510(&pkt);
    TFontSmallLobby__sub_801B1224((s32)((s32)((s32) &pkt)), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x7A_enable_stealth_suit_effect((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_stealth_suit_flags();
        }
    }
}

s32 TFontSmallLobby__sub_801B1224(s32 arg0, void * _w1) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void TLobby__sub_801B1254(s32 arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        fn_801C0510((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TLobby *)((s32 *)&sp8))->cleanup_small_font();
    }
}

void test_flag_2000000__10TObjPlayerFPv(void *arg0) {
    ((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x02000000);
}

void TObjPlayer::activate_body_collision() {
    obj_clearFlags30((u32)0x02000000U);
    set_indexed_flags(0, 1);
}

void TObjPlayer::deactivate_body_collision() {
    ((void (*)(void *, u32))obj_setFlags30)(this, 0x02000000U);
    this->clear_player_status_flag(0, 1U);
}

s32 TObjPlayer::is_actor_cadence_frame(s32 arg1) {
    return (u8) ((actor_frame_tick & arg1) == ((u16 (*)(void))get_entity_id)());
}

void TObjPlayer::send_field_state() {
    s32 arg0 = (s32)this;
    if ((((s32 (*)(void))test_flag_2000000__10TObjPlayerFPv)() == 0) && (((s32 (*)(s32))check_flag_800000__10TObjPlayerFPv)(arg0) == 0)) {
        ((TObjPlayer *)(arg0 + 0x384))->check_hit_by_id_431_from_packet();
    }
    ((s32 (*)(s32, s32))send_field_state_if_active__10TObjPlayerFP10TObjPlayerl)(arg0, 0x42D08);
}

void TObjPlayer::spawn_effect(s32 arg0) {
    if (((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0) {
        start_pad_rumble_client(0xC0, 0xF, ((s32 (*)(s32))get_entity_id)(arg0));
    }
}

void draw__10TObjPlayerFPvf(void *player, f32 farg0) {
    push_matrix();
    translate_matrix_vec3((u8 *)(0), (u8 *)(((s32 (*)(void *))get_position_ptr__10TObjPlayerFv)(player)));
    rotate_matrix_y(0, ((TObjPlayer *)player)->rotation_y);
    draw_model_with_callback__10TObjPlayerFllf(player, ((TObjPlayer *)player)->unknownF8, *(s32 *)((s8 *)player + 0xE0), farg0);
    pop_matrix();
}

void TObjPlayer::draw() {
    push_matrix();
    translate_matrix_vec3((u8 *)(0), (u8 *)(((s32 (*)(void *))get_position_ptr__10TObjPlayerFv)(this)));
    rotate_matrix_y(0, this->rotation_y);
    ((s32 (*)(void *, s32, f32, s32))draw_model_with_callback__10TObjPlayerFllf)(this, this->unknownF8, (*(f32 *)&TObjPlayer__data_805DC278), *(s32 *)((s8 *)this + 0xE0));
    pop_matrix();
}

s32 TObjPlayer::try_pickup_item() {
    s32 temp_r3;
    s32 arg0 = (s32)this;

    if (obj_isState2_324__13TUnk_804806E8Fv() != 0) {
        return 0;
    }
    if (((TObjPlayer*)arg0)->find_revival_item() != 0U) {
        temp_r3 = ((s32 (*)(void))get_owner_if_alive__10TObjPlayerFv)();
        if (temp_r3 == 0) {
            return 0;
        }
        ((s32 (*)(s32))recover_full__10TObjPlayerFPv)(arg0);
        ((FlagWord *)(arg0 + 0x858))->set(4);
        ((s32 (*)(s32, s32, s32))send_6x29_delete_item__10TObjPlayerFPvii)(arg0, ((s32 (*)(s32))get_item_id__5TItemFv)(temp_r3), 1);
        return 1;
    }
    return 0;
}
}
u32 TObjPlayer::find_revival_item() {
    typedef char sp8_offset[(offsetof(Stack_801B15A4, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_801B15A4, sp9) == 0x1) ? 1 : -1];
    typedef char spA_offset[(offsetof(Stack_801B15A4, spA) == 0x2) ? 1 : -1];
    Stack_801B15A4 stack;
    ((s32 (*)(void *))init__9TItemDataFv)(&stack.sp8);
    stack.sp8 = 1;
    stack.sp9 = 2;
    stack.spA = 0x52;
    u32 found = ((u32 (*)(int, void *))set_mode_and_refresh_object__10TObjPlayerFPvi)((int) inventory_objects, &stack.sp8);
    if (found == 0U) {
        ((s32 (*)(void *))init__9TItemDataFv)(&stack.sp8);
        stack.sp8 = 3;
        stack.sp9 = 9;
        found = ((u32 (*)(int, void *))set_mode_and_refresh_object__10TObjPlayerFPvi)((int) inventory_objects, &stack.sp8);
    }
    return found;
}

void TObjPlayer::set_state_flag_604B() {
    if (((s32 (*)(void))obj_isState3_324__13TUnk_804806E8Fv)() != 0) {
        this->m_698 = 0x604B;
    } else {
        this->m_698 = 0x200B;
    }
    fn_801C19E8(((u8 *)this) + 0x828);
}

void handle_6x1C_disable_pk_mode_for_player(void *arg0) {
    struct pkt_801B1674 pkt;
    fn_801C0558(&pkt);
    TObjPlayer::update_small_font((s32)((s32) &pkt), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x1C_disable_pk_mode_for_player((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_state_flag_604B();
        }
    }
}

s32 TObjPlayer::update_small_font(s32 arg0, void * _w1) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void TObjPlayer::send_item_pickup_request(s32 arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        fn_801C0558((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        fn_801C056C((s32 *)&sp8);
    }
}

void TObjPlayer::set_state_flag_6043() {
    if (((s32 (*)(void))obj_isState3_324__13TUnk_804806E8Fv)() != 0) {
        this->m_698 = 0x6043;
    } else {
        this->m_698 = 0x2003;
    }
    fn_801C19F4(((u8 *)this) + 0x828);
}

void handle_6x1B_enable_pk_mode_for_player(void *arg0) {
    struct pkt_801B1674 pkt;
    fn_801C05A0(&pkt);
    ((s32 (*)(s32, void *))draw_font__10TObjPlayerFPv)((s32)((s32) &pkt), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x1B_enable_pk_mode_for_player((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_state_flag_6043();
        }
    }
}

void* draw_font__10TObjPlayerFPv(void* p) { ((int (*)(void*))TFontSmallLobby__sub_801C0228)(p); return p; }

void TObjPlayer::notify_field1c(s32 arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        fn_801C05A0((s32 *)&sp8);
        *(s16 *)((s8 *)&sp8 + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        fn_801C05B4((s32 *)&sp8);
    }
}

int TObjPlayer::get_field_828() { return ((int (*)(void*))get_type__10TObjPlayerFPv)((char*)this + 0x828); }

void TObjPlayer__sub_801B18C0(s32 arg0, u32 arg1) {
    switch (arg1) {
    default:
        ((TObjPlayer *)arg0)->get_idle_animation();
        return;
    case 2:
    case 3:
        TObjPlayer__sub_801CFBFC((u8 *)arg0);
        return;
    case 4:
        ((TObjPlayer *)arg0)->get_vobj_state_28();
        return;
    case 5:
        ((TObjPlayer *)arg0)->call_subobject_m15();
        return;
    case 6:
        ((TObjPlayer *)arg0)->get_state();
        return;
    case 7:
        ((TObjPlayer *)arg0)->get_model_state();
        return;
    case 8:
        ((TObjPlayer *)arg0)->get_status();
        return;
    case 9:
        ((TObjPlayer *)arg0)->query_equip();
        return;
    case 10:
        ((TObjPlayer *)arg0)->query_child_state();
        return;
    case 11:
        ((TObjPlayer *)arg0)->call_obj_vt26();
        return;
    case 12:
        ((TObjPlayer *)arg0)->get_weapon_stat_c();
        return;
    case 13:
        ((TObjPlayer *)arg0)->call_model_m24();
        return;
    case 14:
        ((TObjPlayer *)arg0)->get_action_animation();
        return;
    case 15:
        ((TObjPlayer *)arg0)->get_model_field_m25();
        return;
    }
}

void unequip_by_field326__10TObjPlayerFPv(void *arg0) {
    TObjPlayer__sub_801B18C0((s32)arg0, (u32)(*(s16 *)((s8 *)arg0 + 0x326)));
}

void TObjPlayer::play_phase_transition_sound(s32 arg0) {
    if (((get_main_phase() == 0xE) || (get_main_phase() == 0xF)) && (((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() != 0)) {
        draw_chunk_object((void *)arg0);
        return;
    }
    draw_chunk_object((void *)arg0);
}

void reset_volopt_state__10TObjPlayerFv(void) { ((int (*)(void))get_field_3e0__12TBoss3VoloptFv)(); is_item_area_enabled(); }

void foreach_player__10TObjPlayerFv(s32 (*arg0)(u32)) {
    s32 (*var_r27)(u32);
    s32 var_r29;
    s32 *var_r30;
    s32 var_r31;
    u32 temp_r28;

    var_r27 = arg0;
    var_r29 = 0;
    var_r30 = ((s32 *)&player_slot_table);
    var_r31 = 0;
    do {
        temp_r28 = var_r30[var_r31];
        if ((temp_r28 != 0U) && (((s32 (*)(u32))is_locally_controlled__10TObjPlayerFPv)(temp_r28) != 0)) {
            var_r27(temp_r28);
        }
        var_r29 += 1;
        var_r31 += 1;
    } while (var_r29 < 0xC);
}

void for_each_player_slot__10TObjPlayerFv(void (*arg0)(void *)) {
    s32 i;
    void **p;
    p = (void **)((s32 *)&player_slot_table);
    for (i = 0; i < 12; i++, p++) {
        if (*p != NULL) {
            arg0(*p);
        }
    }
}

void TObjPlayer::check_flag_40000() {
    check_flag__10TObjPlayerFl(this, 0x40000);
}

struct Pkt_801B1B08 { u16 f0; u16 client; u32 pad; };
s32 validate_6x23_set_player_visible(G_ClientIDHeader *packet);
extern "C" {

void handle_6x23_set_player_visible(void *arg0) {
    Pkt_801B1B08 pkt;
    fn_801C05E8((Ctx_801B1BA4 *)&pkt);
    ((s32 (*)(Pkt_801B1B08 *, void *))handle_set_visible__10TObjPlayerFi)(&pkt, arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x23_set_player_visible((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.client);
        if (p != NULL) {
            sub_8011E204__10TObjPlayerFl(p, 0x40000);
        }
    }
}

s32 handle_set_visible__10TObjPlayerFi(s32 arg0) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void TObjPlayer__sub_801B1BA4(void) {
    Ctx_801B1BA4 ctx;
    void *p;
    fn_801C05E8(&ctx);
    p = update_battle_controller__10TObjPlayerFv();
    if (p != NULL && (p == NULL || obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        ctx.f2 = ((s16 (*)(void *))get_entity_id)(p);
        fn_801C05FC(&ctx);
    }
}
}

struct Pkt_801B1C00 { u16 f0; u16 client; u32 pad; };
s32 validate_6x22_set_player_invisible(G_ClientIDHeader *packet);
extern "C" {
void set_invisible__10TObjPlayerFv(Pkt_801B1C00 *, void *);

void handle_6x22_set_player_invisible(void *arg0) {
    Pkt_801B1C00 pkt;
    fn_801C0630((Ctx_801B1C8C *)&pkt);
    set_invisible__10TObjPlayerFv(&pkt, arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x22_set_player_invisible((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.client);
        if (p != NULL && check_flag_4__10TObjPlayerFv(p) == 0) {
            set_state_flags__10TObjPlayerFUl(p, 0x40000);
            ((TObjPlayer *)p)->deactivate_body_collision();
            ((TObjPlayer *)p)->set_flag_200000();
        }
    }
}

void TObjPlayer__sub_801B1C8C(void) {
    Ctx_801B1C8C ctx;
    void *p;
    fn_801C0630(&ctx);
    p = update_battle_controller__10TObjPlayerFv();
    if (p != NULL && (p == NULL || obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        ctx.f2 = ((s16 (*)(void *))get_entity_id)(p);
        fn_801C0644(&ctx);
    }
}

void send_field_state_if_active__10TObjPlayerFP10TObjPlayerl(s32 arg0, s32 arg1) {
    if (((s32 (*)(void))is_on_current_floor__10TObjPlayerFi)() != 0) {
        play_sound_effect(arg1, ((s32 (*)(s32))get_position_ptr__10TObjPlayerFv)(arg0), 0, 0);
    }
}

u8 TObjPlayer::is_in_tl03_state() {
    int var_r31;

    var_r31 = 0;
    if ((((s32 (*)(void))check_flag_4__10TObjPlayerFv)() == 0) && ((u32) *(u32 *)((s8 *)this + 0x10) == (u32) tl_03)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

void handle_6x2F_change_player_hp(s32 arg0) {
    Pkt_801B1D8C pkt;
    u32 player;
    ((TObjPlayer *)(&pkt))->init_6x2F_packet_header();
    TObjPlayer__sub_801C06BC(&pkt, arg0);
    ((TObjPlayer *)(&pkt))->bswap_change_hp_packet();
    if (validate_6x2F_change_player_hp((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    player = ((u32 (*)(s32))get_player_by_client_id)(pkt.client);
    if (player == 0) {
        return;
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(player, 0x800) != 0) {
        return;
    }
    switch (pkt.type) {
    case 0:
        ((void (*)(u32, s32))set_hp_clamped__10TObjPlayerFs)(player, pkt.amount);
        break;
    case 1:
        add_actor_hp((u8 *)player, pkt.amount);
        break;
    case 2:
        add_actor_hp((u8 *)player, *(s16 *)(player + 0x2B8));
        break;
    }
}

void send_6x2F_change_player_hp(s32 arg0, s32 arg1, s32 arg2) {
    Msg_801B1E54 m;

    if (((((u32 (*)(u16))get_player_by_client_id)((u16)arg0) == 0U) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) && ((((u32 (*)(u16))get_player_by_client_id)((u16)arg1) == 0U) || (((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0))) {
        ((TObjPlayer *)(&m))->init_6x2F_packet_header();
        m.a = arg0;
        m.b = 0;
        m.c = arg2;
        m.d = arg1;
        TObjPlayer__sub_801C0734(&m);
    }
}

void handle_6x24_teleport_player(s32 arg0) {
    Pkt_801B1EE0 pkt;
    u32 player;
    ((TObjPlayer *)(&pkt))->init_cmd_6x24();
    TObjPlayer__sub_801C07B4(&pkt, arg0);
    ((TObjPlayer *)(&pkt))->byteswap_packet_body();
    if (validate_6x24_teleport_player((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    player = ((u32 (*)(s32))get_player_by_client_id)(pkt.slot);
    if (player == 0) {
        return;
    }
    ((TUnk_804B9870 *)player)->set_position_from(pkt.pos);
    *(s32 *)(player + 0x60) = *(s32 *)(player + 0x3F0) = pkt.heading;
    ((TUnk_804806E8 *)player)->calc_attach_pos();
    ((TObjPlayer *)player)->clear_flag_4000();
    ((TObjPlayer *)player)->refresh_equipment_slot();
    create__15TPlyOnCountOverFPvPvPv(((s16 (*)(void *))get_entity_id)((void *)player), 2, clear_flag_4000_callback__10TObjPlayerFv);
    if (((s32 (*)(u32))is_locally_controlled__10TObjPlayerFPv)(player) != 0) {
        reset_cameras_to_actor((void *)player, 0);
    }
}

void send_6x24_teleport_player(u16 slot, void *pos, s32 heading) {
    struct pkt_801B1FA4 pkt;
    ((TObjPlayer *)(&pkt))->init_cmd_6x24();
    if (((u32 (*)(s32))get_player_by_client_id)(slot) != 0U && obj_isState2_324__13TUnk_804806E8Fv() == 0) {
        pkt.slot = slot;
        pkt.heading = heading;
        VecCopy((Vec *)&pkt.pos, (const Vec *)pos);
        ((TObjPlayer *)(&pkt))->send_lobby_update();
    }
}

void TObjPlayer__sub_801B2014(s32 arg0) {
    Item_801B2014 item;
    item.val = TObjPlayer__data_805DC278;
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 1) != 0) {
        item.id = 0xF;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(arg0, item);
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 2) != 0) {
        item.id = 0x10;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(arg0, item);
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x40) != 0) {
        item.id = 7;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(arg0, item);
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 8) != 0) {
        item.id = 0x11;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(arg0, item);
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x10) != 0) {
        item.id = 0x12;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(arg0, item);
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x20) != 0) {
        item.id = 2;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(arg0, item);
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 4) != 0) {
        item.id = 3;
        ((void (*)(s32, Item_801B2014))dispatch_status_effect_msg__10TObjPlayerFUiPv)(arg0, item);
    }
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

s32 TObjPlayer::update_defense_stat_status() {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return TUnk_804806E8::update_defense_stat_status();
    }
    return 0;
}

s32 TObjPlayer::update_attack_stat_status() {
    s32 player = (s32)this;
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return update_attack_stat_status__13TUnk_804806E8Fv(player);
    }
    return 0;
}

s32 TObjPlayer__vt38(s32 arg0) {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (((s32 (*)(s32))test_flag_2000000__10TObjPlayerFPv)(arg0) != 0)) {
        return 0;
    }
    return update_shock_clock__13TUnk_804806E8Fv(arg0);
}

s32 TObjPlayer__vt37(s32 arg0) {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (((s32 (*)(s32))test_flag_2000000__10TObjPlayerFPv)(arg0) != 0)) {
        return 0;
    }
    return update_movement_status__13TUnk_804806E8Fv(arg0);
}

s32 TObjPlayer__vt36(s32 arg0) {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (((s32 (*)(s32))test_flag_2000000__10TObjPlayerFPv)(arg0) != 0)) {
        return 0;
    }
    return update_flag30_timer__13TUnk_804806E8Fv(arg0);
}

s32 TObjPlayer::vfunc_37() {
    s32 player = (s32)this;
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (((s32 (*)(s32))test_flag_2000000__10TObjPlayerFPv)(player) != 0)) {
        return 0;
    }
    return vfunc_37__13TUnk_804806E8Fv(player);
}

s32 TObjPlayer__vt34(s32 arg0) {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (((s32 (*)(s32))test_flag_2000000__10TObjPlayerFPv)(arg0) != 0)) {
        return 0;
    }
    return update_action_hold_status__13TUnk_804806E8Fv(arg0);
}

s32 TObjPlayer__vt33(s32 arg0) {
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) || (((s32 (*)(s32))test_flag_2000000__10TObjPlayerFPv)(arg0) != 0)) {
        return 0;
    }
    return update_poison_status__13TUnk_804806E8Fv(arg0);
}

s32 check_flag30_bit20__10TObjPlayerFi(s32 arg0) {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x20);
    }
    return 0;
}

s32 is_flag30_10_set__10TObjPlayerFi(s32 arg0) {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x10);
    }
    return 0;
}

s32 is_flag30_8_set__10TObjPlayerFi(s32 arg0) {
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        return obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 8);
    }
    return 0;
}

struct Pl_801B0B88;
void TObjPlayer::cancel_status_effects() {
#define arg0 ((u8 *)((Pl_801B0B88 *)this))
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    f32 temp_f31_4;
    f32 temp_f31_5;
    f32 v;
    ((TUnk_804806E8 *)arg0)->actorFlags = (s32) (((TUnk_804806E8 *)arg0)->actorFlags & 0xFFFFFFFC);
    temp_f31 = -TObjPlayer__sub_800192C4(arg0, 0);
    v = ((TUnk_804806E8 *)arg0)->get_s16_2c4();
    ((TUnk_804806E8 *)arg0)->sub_800192B4((s32) (v * temp_f31));
    reset_status_effect_row(arg0 + 0x254);
    ((TUnk_804806E8 *)arg0)->actorFlags = (s32) (((TUnk_804806E8 *)arg0)->actorFlags & 0xFFFFFFC3);
    temp_f31_2 = -TObjPlayer__sub_800192C4(arg0, 1);
    v = ((TUnk_804806E8 *)arg0)->get_s16_2c4();
    ((TUnk_804806E8 *)arg0)->sub_800192B4((s32) (v * temp_f31_2));
    reset_status_effect_row(arg0 + 0x260);
    temp_f31_3 = -TObjPlayer__sub_800192C4(arg0, 2);
    v = ((TUnk_804806E8 *)arg0)->get_field_2c0();
    ((TUnk_804806E8 *)arg0)->add_to_field_2c8((s32) (v * temp_f31_3));
    temp_f31_4 = -TObjPlayer__sub_800192C4(arg0, 2);
    v = ((TUnk_804806E8 *)arg0)->get_field_2c2();
    ((TUnk_804806E8 *)arg0)->add_to_field_2ca((s32) (v * temp_f31_4));
    reset_status_effect_row(arg0 + 0x26C);
    temp_f31_5 = -TObjPlayer__sub_800192C4(arg0, 3);
    v = ((TUnk_804806E8 *)arg0)->get_atp();
    ((TUnk_804806E8 *)arg0)->add_to_field_2ce((s32) (v * temp_f31_5));
    reset_status_effect_row(arg0 + 0x278);
}
#undef arg0

void remove_status_effect__10TObjPlayerFUiPv(u32 arg0_, Pair_801B2C04 *arg1_) {
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
        ((TUnk_804806E8 *)arg0)->actorFlags = (s32) (((TUnk_804806E8 *)arg0)->actorFlags & 0xFFFFFFFC);
        temp_f31 = -TObjPlayer__sub_800192C4((void *) arg0, 0);
        v = ((TUnk_804806E8 *)arg0)->get_s16_2c4();
        v *= temp_f31;
        ((TUnk_804806E8 *)arg0)->sub_800192B4((s32) v);
        reset_status_effect_row(arg0 + 0x254);
        return;
    case 1:
        ((TUnk_804806E8 *)arg0)->actorFlags = (s32) (((TUnk_804806E8 *)arg0)->actorFlags & 0xFFFFFFC3);
        temp_f31_2 = -TObjPlayer__sub_800192C4((void *) arg0, 1);
        v = ((TUnk_804806E8 *)arg0)->get_s16_2c4();
        v *= temp_f31_2;
        ((TUnk_804806E8 *)arg0)->sub_800192B4((s32) v);
        reset_status_effect_row(arg0 + 0x260);
        return;
    case 2:
        temp_f31_3 = -TObjPlayer__sub_800192C4((void *) arg0, 2);
        v = ((TUnk_804806E8 *)arg0)->get_field_2c0();
        v *= temp_f31_3;
        ((TUnk_804806E8 *)arg0)->add_to_field_2c8((s32) v);
        temp_f31_4 = -TObjPlayer__sub_800192C4((void *) arg0, 2);
        v = ((TUnk_804806E8 *)arg0)->get_field_2c2();
        v *= temp_f31_4;
        ((TUnk_804806E8 *)arg0)->add_to_field_2ca((s32) v);
        reset_status_effect_row(arg0 + 0x26C);
        return;
    case 3:
        temp_f31_5 = -TObjPlayer__sub_800192C4((void *) arg0, 3);
        v = ((TUnk_804806E8 *)arg0)->get_atp();
        v *= temp_f31_5;
        ((TUnk_804806E8 *)arg0)->add_to_field_2ce((s32) v);
        reset_status_effect_row(arg0 + 0x278);
        return;
    }
}

void dispatch_status_effect_msg__10TObjPlayerFUiPv(u32 arg0, Pair_801B2AE8 *msg) {
    switch (msg->a) {
    case 15:
        ((TObjPlayer *)arg0)->apply_poison_status();
        break;
    case 16:
        ((TObjPlayer *)arg0)->apply_paralysis();
        break;
    case 17:
        ((TObjPlayer *)arg0)->apply_slow_status();
        break;
    case 18:
        ((TObjPlayer *)arg0)->apply_confusion_status();
        break;
    case 3:
        ((TObjPlayer *)arg0)->apply_shock_status();
        break;
    case 2:
        ((TObjPlayer *)arg0)->apply_movement_ailment(0);
        break;
    case 7:
        ((TObjPlayer *)arg0)->clear_harmful_statuses();
        break;
    case 9:
    case 11:
        {
            Pair_801B2AE8 tmp = *msg;
            ((VObj_801B2AE8 *)arg0)->m49(tmp);
        }
        break;
    case 10:
    case 12:
        {
            Pair_801B2AE8 tmp2 = *msg;
            ((VObj_801B2AE8 *)arg0)->m50(tmp2);
        }
        break;
    }
}

void handle_6x0D_add_or_remove_status_effect(void *arg0) {
    Eff_801B2C04 e;
    ((TObjPlayer *)(&e))->set_code_13_3();
    ((TObjPlayer *)(&e))->copy_6x0d_status_effect_packet(arg0);
    ((TObjPlayer *)(&e))->bswap_status_effect();
    if (fn_8036B748(&e) != 0) {
        u32 p = ((u32 (*)(s32))get_player_by_client_id)(e.f2);
        if (p != 0) {
            Pair_801B2C04 q;
            q.a = e.f4;
            q.b = e.f8;
            remove_status_effect__10TObjPlayerFUiPv(p, &q);
        }
    }
}

void send_code_13_3__10TObjPlayerFii(s32 arg0, s32 arg1) {
    s32 spC;
    s32 sp8;

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_13_3();
        *(s16 *)((s8 *)&sp8 + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        obj_copyVec2_0((u8 *)&spC, (u8 *)arg1);
        ((TObjPlayer *)(&sp8))->update_and_send();
    }
}

void handle_6x0E_clear_negative_status_effects(s32 arg0) {
    Eff_801B2CE4 e;
    ((TObjPlayer *)(&e))->set_code_14_1();
    ((void (*)(void *, s32))clear_negative_status_effects__10TObjPlayerFi)(&e, arg0);
    TFontSmallLobby__sub_801C01BC(&e);
    if (validate_6x0E_clear_negative_status_effects((G_ClientIDHeader *)&e) != 0) {
        VObj_801B2CE4 *p = (VObj_801B2CE4 *)((u32 (*)(s32))get_player_by_client_id)(e.f2);
        if (p != 0) {
            p->m48();
        }
    }
}

s32 clear_negative_status_effects__10TObjPlayerFi(s32 arg0) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void handle_6x0C_add_or_remove_status_effect(void *arg0) {
    Eff_801B2D88 e;
    ((TObjPlayer *)(&e))->set_code_12_3();
    TObjPlayer__sub_801C092C(&e, arg0);
    apply_status_effect__10TObjPlayerFPv(&e);
    if (fn_8036B770(&e) != 0) {
        u32 p = ((u32 (*)(s32))get_player_by_client_id)(e.f2);
        if (p != 0) {
            Pair_801B2D88 q;
            q.a = e.f4;
            q.b = e.f8;
            ((void (*)(u32, Pair_801B2D88 *))dispatch_status_effect_msg__10TObjPlayerFUiPv)(p, &q);
        }
    }
}

void TObjPlayer__vt76(s32 arg0, s32 arg1) {
    s32 spC;
    s32 sp8;

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_12_3();
        *(s16 *)((s8 *)&sp8 + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        obj_copyVec2_0((u8 *)&spC, (u8 *)arg1);
        ((TObjPlayer *)(&sp8))->reinit_update_sub4_and_send();
    }
}

s32 TObjPlayer::get_next_level_exp() {
    s32 actor_level_index;
    s32 max_level;
    max_level = TObjPlayer::get_max_level();
    if (this->get_actor_level_index() >= max_level) {
        return 0;
    }
    actor_level_index = this->get_actor_level_index();
    return ((s32 (*)(s8, s32))get_current_state_field__10TObjPlayerFScl)(((s8 (*)(void *))get_class_index__10TObjPlayerFv)(this), actor_level_index + 1);
}

s32 calc_scaled_value__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (((s32 (*)(void))is_flag30_10_set__10TObjPlayerFi)() != 0) {
        return (s32) (lbl_805DC280 * (lbl_805DC284 * (lbl_805DC288 * (f32) rand())));
    }
    return arg1;
}

void apply_speed_scale__10TObjPlayerFif(s32 arg0, f32 farg0) {
    f32 var_f1;

    if (((s32 (*)(void))is_flag30_8_set__10TObjPlayerFi)() != 0) {
        var_f1 = TObjPlayer__data_805DC28C * farg0;
    } else {
        var_f1 = farg0;
    }
    ((TObjEnemy *)arg0)->sub_800A7798(var_f1);
}

#pragma push
#pragma scheduling off
s32 build_player_class_stat_template(s32 arg0, s32 arg1) {
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
  temp_r31 = get_class_defense_template();
  new_var = (void *) arg0;
  temp_r30 = temp_r31;
  new_var2 = (int) temp_r30;
  temp_r31 = get_class_attack_template(new_var);
  set_params__10TObjPlayerFPvPvPviPv((void *) arg1, new_var, (void *) get_class_stat_entry__10TObjPlayerFPUc(new_var), (int) temp_r31, new_var2);
  return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
s32 build_player_equipment_requirement_stats(TObjPlayer *self, PlayerRequirementStats *player_requirement_stats) {
    set_params__10TObjPlayerFPvPvPviPv(player_requirement_stats, self, (void *) ((s32 (*)(void *))get_quest_id__12TQuestListVMFv)(self),
                                       get_class_attack_template(self), get_class_defense_template());
    return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
int fn_801B309C(void* p) { return ((int (*)(void*))recover_full__10TObjPlayerFPv)(p); }
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
#pragma scheduling on
void prepare_guild_return__10TObjPlayerFPv(void *player) {
    set_area__6TLobbyFl(((u8 *)&lbl_80515BA0), 0, get_floor_map_terrain(0));
    mark_area_change_pending();
    ((void (*)(s16, s32, s32))set_arrival_override_pos)(((s16 (*)(s32))get_entity_id)((s32) player), get_guild_return_yaw__10TObjPlayerFv(player), get_guild_return_position__10TObjPlayerFPv(player));
    set_state_flags__10TObjPlayerFUl(player, 0x800);
    ((void (*)(void *, int))set_battle_flag__10TObjPlayerFl)(player, 1);
    ((void (*)(void *, void *))send_6x21_inter_level_warp)(player, ((void * (*)(void *))get_dest_area__17TObjAreaWarpQuestFv)(((u8 *)&lbl_80515BA0)));
    TNpcPlayer::apply_to_players((s32)(((void * (*)(void *))get_dest_area__17TObjAreaWarpQuestFv)(((u8 *)&lbl_80515BA0))), (void *)(get_party_position()), (s32)(get_party_yaw()));
}
#pragma pop

int TLobby::player_flag_1() { return set_battle_flag__10TObjPlayerFl(this, 1); }

int TLobby::check_player_state_flag_2() { return test_flags_any((char*)this + 0x858, 2); }

void handle_6x34(void) {  }

void TObjPlayer::prepare_hospital_return() {
    ((s32 (*)(s32, int))send_6x21_inter_level_warp)((s32)this, 0);
    set_arrival_override_pos(((u16 (*)(void *))get_entity_id)(this), get_hospital_yaw__10TObjPlayerFv(this), get_hospital_position__10TObjPlayerFv(this));
    ((s32 (*)(void *, int))set_state_flags__10TObjPlayerFUl)(this, 0x800);
    set_battle_flag__10TObjPlayerFl(this, 0);
    TNpcPlayer::apply_to_players((s32)(get_dest_area__17TObjAreaWarpQuestFv(&lbl_80515BA0)), (void *)(TNpcPlayer::get_lobby_entry_ptr()), (s32)(TNpcPlayer__sub_8034DE40()));
}

void complete_deferred_player_death(void) {
    u8 lvl;
    s16 aim;
    u16 room;
    VObj_801B3274 *p;
    p = ((VObj_801B3274 * (*)(s32))get_player_by_client_id)(fn_801C1BA0());
    if (p == NULL) {
        return;
    }
    ((FlagWord *)((u8 *)p + 0x858))->clear(2);
    if (((TObjPlayer *)p)->try_pickup_item() != 0) {
        return;
    }
    if (((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() != 0) {
        if (((u8 (*)(void *))TLobby__sub_801D7100)(lobby_rule_settings) == 1) {
            TObjPlayer::send_6x4E_player_revivable((s32)p);
            return;
        }
        if (((u8 (*)(void *))TLobby__sub_801D7100)(lobby_rule_settings) == 2 && TObjPlayer::decrement_timer((s32 *)((u8 *)p + 0x754)) == 0) {
            TObjPlayer::send_6x4E_player_revivable((s32)p);
            return;
        }
        ((TObjPlayer *)p)->send_respawn_position();
        aim = ((TLobby *)lobby_rule_settings)->clamp_value_below_200();
        room = TObjRoomId__sub_801A1DB8(get_field_2d4__10TObjPlayerFv(p));
        if (aim != 0 && (room == 0 || room == 0x1000)) {
            ((TObjPlayer *)p)->update_aim_angle(aim);
        }
        if ((lvl = (u8)((TLobby *)lobby_rule_settings)->get_clamped_level()) != 0 && (room == 0 || room == 0x1000)) {
            ((s32 (*)(void *, u8))TObjPlayer__sub_801AF554)(p, lvl);
        }
        p->m62();
        return;
    }
    if (is_camera_mode_active__10TObjPlayerFv() != 0) {
        TObjPlayer::send_6x4E_player_revivable((s32)p);
        return;
    }
    if (get_main_phase() == 0xE) {
        if (check_camera_mode__10TObjPlayerFv() != 0) {
            if (((TObjPlayer *)p)->get_anim_id() == 1) {
                ((s32 (*)(void *, int))prepare_guild_return__10TObjPlayerFPv)(p, 0);
                return;
            }
            ((TObjPlayer *)p)->prepare_hospital_return();
            ((s32 (*)(void *, int, int))set_area__6TLobbyFl)(&lbl_80515BA0, 0, get_floor_map_terrain(0));
            ((s32 (*)(void))mark_area_change_pending)();
            TNpcPlayer::send_inter_level_warp_all(get_dest_area__17TObjAreaWarpQuestFv(&lbl_80515BA0));
            return;
        }
        ((TObjPlayer *)p)->create_return_city_window();
        TObjPlayer::send_6x4E_player_revivable((s32)p);
        return;
    }
    ((TObjPlayer *)p)->create_return_city_window();
    TObjPlayer::send_6x4E_player_revivable((s32)p);
}

int TObjPlayer::stop_battle() { return set_battle_flag__10TObjPlayerFl(this, 0); }

s32 TObjPlayer::create_return_city_window() {
    u32 var_r31;

    if ((((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0) && ((u32) this->m_36c == 0U) && ((u32) *(u32 *)((s8 *)this + 0x548) != 0U)) {
        var_r31 = __nw__7TObjectFUl(0x28);
        if (var_r31 != 0U) {
            var_r31 = TWindowReturnCity__ct(var_r31, tl_07, (u16) get_entity_id(this));
        }
        this->m_36c = var_r31;
        return 1;
    }
    return 0;
}

int TObjWarpBossMulti::is_flag_clear(void* p) { return (((int (*)(void*, int))check_flag__10TObjPlayerFl)(p, 4096)) == 0; }

int TObjPlayer::has_item_flag_4096() { return ((int (*)(void*, void*))sub_8011E204__10TObjPlayerFl)(this, (void*)(4096)); }

int TObjPlayer::check_technique_flag() { return ((int (*)(void*, void*))set_state_flags__10TObjPlayerFUl)(this, (void*)(4096)); }

int is_flag_400_set__10TObjPlayerFPv(void* p) { return ((int (*)(void*, int))check_flag__10TObjPlayerFl)(p, 1024); }

void enable_action_input__10TObjPlayerFPv(void* p) { ((int (*)(void*, void*))sub_8011E204__10TObjPlayerFl)(p, (void*)((void*)1024)); ((TChallenge4PResult *)p)->get_player_rank(); }

void TObjPlayer::disable_primary_action_input() { ((int (*)(void*, void*))set_state_flags__10TObjPlayerFUl)(this, (void*)((void*)1024)); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)1); }

void TObjPlayer::disable_action_input() { ((int (*)(void*, void*))set_state_flags__10TObjPlayerFUl)(this, (void*)((void*)1024)); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)1); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)2); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)3); }

int TObjPlayer::try_use_item_by_type(int arg1, int arg2, int arg3) {
    s8 sp8[24];
    init__9TItemDataFv(sp8);
    sp8[0] = arg1;
    sp8[1] = arg2;
    sp8[2] = arg3;
    if (set_mode_and_refresh_object__10TObjPlayerFPvi(*(s32 *)((s8 *)this + 0xD00), sp8) == 0U) {
        return 0;
    }
    if (get_owner_if_alive__10TObjPlayerFv() == 0U) {
        return 0;
    }
    if (try_send_6x27_use_item(this, get_item_id__5TItemFv()) == 0) {
        return 0;
    }
    if (set_mode_and_refresh_object__10TObjPlayerFPvi(*(s32 *)((s8 *)this + 0xD00), sp8) == 0U) {
        return 0;
    }
    if (get_owner_if_alive__10TObjPlayerFv() == 0U) {
        return 0;
    }
    return all_parents_unqueued_for_destruction__7TObjectFv() != 0 ? 1 : 0;
}

s32 TObjPlayer::check_can_add_item(s8 arg1, s8 arg2) {
    s8 sp8[24];

    init__9TItemDataFv(sp8);
    sp8[0] = arg1;
    sp8[1] = arg2;
    if (set_mode_and_refresh_object__10TObjPlayerFPvi(*(s32 *)((s8 *)this + 0xD00), sp8) == 0U) {
        return 0;
    }
    if (get_owner_if_alive__10TObjPlayerFv() == 0U) {
        return 0;
    }
    if (try_send_6x27_use_item(this, get_item_id__5TItemFv()) == 0) {
        return 0;
    }
    if (set_mode_and_refresh_object__10TObjPlayerFPvi(*(s32 *)((s8 *)this + 0xD00), sp8) == 0U) {
        return 0;
    }
    if (get_owner_if_alive__10TObjPlayerFv() == 0U) {
        return 0;
    }
    return all_parents_unqueued_for_destruction__7TObjectFv() != 0 ? 1 : 0;
}

s32 TObjPlayer::can_use_item(void *arg1) {
    u32 p;
    if (((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() != 0 && ((u8 (*)(void *))fn_801D7168)(lobby_rule_settings) == 2) {
        return 0;
    }
    switch (get_item_type__5TItemFv(arg1)) {
    case 3:
        switch (((TItem *)arg1)->get_item_group()) {
        case 0:
            if (this->hp >= this->hpmax) {
                return 0;
            }
            break;
        case 1:
            if (*(s16 *)&this->tp >= this->tpmax) {
                return 0;
            }
            break;
        case 6:
            switch (((TItem *)arg1)->get_item_index()) {
            case 0:
                if (((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)(this, 1) == 0) {
                    return 0;
                }
                break;
            case 1:
                if (((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)(this, 2) == 0) {
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
            if (*(u32 *)&this->m_424 != 0) {
                p = ((TMainCursor *)(*(u32 *)&this->m_424))->find_by_pos(4, 9);
                if (p == 0) {
                    return 0;
                }
                TObjPlayer__sub_80116620((void *)(p + 0x9C), 0);
                if (get_type_id__10TObjPlayerFv() == 0xFFFF) {
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

s32 TObjPlayer::can_use_camera_field() {
    s32 arg0 = (s32)this;
    if ((((s32 (*)(void))check_flag_100__10TObjPlayerFPv)() != 0) || (((TObjPlayer *)arg0)->get_camera_field() == 0) || (are_items_enabled_here() == 0)) {
        return 0;
    }
    return 1;
}

s32 TObjPlayer::dispatch_palette_action(u32 arg1) {
    s32 arg0 = (s32)this;
    switch (arg1) {
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
        ((TObjPlayer *)(arg0 + 0x428))->reset_slots();
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

int get_result_entry__18TChallenge4PResultFPv(void* p) { return TObjPlayer__sub_801BF460((char*)p + 0x340); }

int TChallenge4PResult::get_player_rank() { return TObjPlayer__sub_801BF47C((char*)this + 0x340); }

int get_field_340__18TChallenge4PResultFPv(void* p) { return TObjPlayer__sub_801BF488((char*)p + 0x340); }

int get_player_result__18TChallenge4PResultFPv(void* p) { return TObjPlayer__sub_801BF4A0((char*)p + 0x340); }

s32 TObjPlayer::handle_palette_button_input() {
    u8 *arg0 = (u8 *)this;
    if (((TObjPlayer *)(arg0 + 0x550))->check_action_usable(4) != 0 && ((int (*)(void *, s32))get_result_entry__18TChallenge4PResultFPv)(arg0, 1) != 0) {
        s32 mode;
        void *target;
        if (has_action_palette_entry() != 0) {
            target = find_entity_by_id(get_id__11TMainCursorFv(*(u8 **)(arg0 + 0x424) + 0x4F8));
            mode = 0;
        } else {
            target = 0;
            mode = 1;
        }
        if (execute_palette_action(mode, target) != 0) {
            dispatch_to_child__11TWindowCtrlFPv(get_entity_id(arg0), 1);
            return 1;
        }
    } else if (((TObjPlayer *)(arg0 + 0x550))->check_action_usable(0x400) != 0 && ((int (*)(void *, s32))get_result_entry__18TChallenge4PResultFPv)(arg0, 2) != 0) {
        if (TObjPlayer__sub_80354D5C(get_entity_id(arg0)) != 0 && ((TWindowActionPalette *)(arg0 + 0x500))->handle_input_forward() != 0) {
            if (TObjPlayer::is_player_valid_target(get_entity_id(arg0)) != 0) {
                TObjPlayer__sub_80354BE4(get_entity_id(arg0));
            }
        } else if (((TObjPlayer *)arg0)->execute_palette_action(2, 0) != 0) {
            dispatch_to_child__11TWindowCtrlFPv(get_entity_id(arg0), 2);
            return 1;
        }
    } else if (((TObjPlayer *)(arg0 + 0x550))->check_action_usable(2) != 0 && ((int (*)(void *, s32))get_result_entry__18TChallenge4PResultFPv)(arg0, 3) != 0 &&
               ((TObjPlayer *)arg0)->execute_palette_action(3, 0) != 0) {
        dispatch_to_child__11TWindowCtrlFPv(get_entity_id(arg0), 3);
        return 1;
    }
    return 0;
}

s32 TObjPlayer::execute_palette_action(s32 arg1, void *arg2) {
    u8 *self = (u8 *)this;
    s16 kind;
    s16 act;
    kind = ((s32 (*)(void *, s32))TObjPlayer__sub_801B5AF8)(this, arg1);
    act = get_action_palette_entry(arg1);
    set_action_palette_mode__10TObjPlayerFv((u8 *)&this->m_340, kind);
    update_action_palette__10TObjPlayerFv((u8 *)&this->m_340, act);
    switch (kind) {
    case 0:
        return 0;
    case 1:
        if (arg2 == NULL) {
            return 0;
        }
        if (is_target_valid() != 0) {
            ((VObj_801B3DD4 *)arg2)->m11(get_entity_id(this));
            return 1;
        }
        break;
    case 2:
        ((TObjPlayer *)(self + 0x7CC))->set_action_type(act);
        if (this->check_mode_action(act) != 0) {
            if (((TObjPlayer *)(self + 0x550))->get_attached_float_24() >= lbl_805DC290) {
                ((Player_801B3DD4 *)this)->f60 = ((s32 (*)(void *, s32))calc_scaled_value__10TObjPlayerFii)(this, ((TObjPlayer *)(self + 0x550))->get_target_field_1c());
            }
            run_action_state_phase__10TObjPlayerFisi(this, 5, 5);
            return 1;
        }
        break;
    case 3:
        if (TObjPlayer::try_camera_action((s32)this, (s32)act) != 0) {
            ((TObjPlayer *)(self + 0x428))->set_technique_id(act);
            run_action_state_phase__10TObjPlayerFisi(this, 8, 5);
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
            set_photon_blast_kind((u8 *)&this->m_4ac, act);
            run_action_state_phase__10TObjPlayerFisi(this, 9, 5);
            return 1;
        }
        break;
    case 6:
        if (TObjPlayer::is_player_valid_target(get_entity_id(this)) != 0) {
            TObjPlayer__sub_80354BE4(get_entity_id(this));
        }
        break;
    default:
        return 0;
    }
    return 0;
}

int TObjPlayer__sub_801B3FD8(void* p) { return reset_ring__10TObjPlayerFv((char*)p + 0x63c); }

int TObjPlayer::attach_battle_ctrl_sub() { return clear_target_lock__10TObjPlayerFv((char*)this + 0x63c); }

void TObjPlayer::forward_1BF500_at_63c() { ((TObjPlayer *)((char*)this + 0x63c))->clear_flag0_bit1(); }

void TObjPlayer__sub_801B4044(void* p) { ((TObjPlayer *)((char*)p + 0x63c))->set_flag_2(); }

s32 TObjPlayer::classify_action_state() {
    s8 temp_r3;

    temp_r3 = ((s8 (*)(void))get_class_index__10TObjPlayerFv)();
    switch (temp_r3) {
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

int TObjPlayer::update_foot_stamp(int arg1) {
    if (arg1 == 1) {
        TObjPlayer::clear_foot_stamp((s32)((u8 *)this + 0x384), (s32)this);
    } else if (arg1 == 2) {
        TObjPlayer::enable_foot_stamp((s32)((u8 *)this + 0x384), (s32)this);
    }
}

s32 test_ordered_anim_markers__10TObjPlayerFPvff(u8 *arg0, f32 farg0, f32 farg1) {
    if (objInBand((GameObj *)arg0, (f32)farg0) != 0) {
        return 1;
    }
    return (objInBand((GameObj *)arg0, (f32)farg1) != 0) ? 2 : 0;
}

void TObjPlayer::emit_footstep_effect(f32 farg0, f32 farg1) {
    s32 temp_r3;
    s32 contact_surface_type;
    s32 arg0 = (s32)this;
    if ((((s32 (*)(void))test_flag_2000000__10TObjPlayerFPv)() == 0) && (temp_r3 = ((s32)test_ordered_anim_markers__10TObjPlayerFPvff((u8 *)arg0, farg0, farg1)), ((temp_r3 == 0) == 0))) {
        contact_surface_type = get_contact_surface_type((void *)(arg0 + 0x360));
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
            ((s32)((TObjPlayer *)arg0)->update_foot_stamp(temp_r3));
            return;
        case 0:
            if (is_timer_running((void *)(arg0 + 0x360)) != 0) {
                ((TObjPlayer *)arg0)->update_foot_stamp(temp_r3);
            }
            break;
        }
    }
}

void TObjPlayer::play_footstep_sound() {
    s32 arg0 = (s32)this;
    if (((int (*)(void))test_ordered_anim_markers__10TObjPlayerFPvff)() != 0) {
        ((s32 (*)(s32, s32))send_field_state_if_active__10TObjPlayerFP10TObjPlayerl)(arg0, ((TObjPlayer *)arg0)->get_footstep_floor_index());
    }
}

void TObjPlayer::update_rotation() {
    if ((check_camera_mode__10TObjPlayerFv() == 0) && (((s32 (*)(void *))reset_volopt_state__10TObjPlayerFv)(this) != 0) && (((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() == 0) && (obj_isState3_324__13TUnk_804806E8Fv(this) == 0)) {
        set_hp_clamped__10TObjPlayerFs(this, (s16) ((s16) this->hpmax / 2));
        return;
    }
    set_hp_clamped__10TObjPlayerFs(this, this->hpmax);
    set_tp__10TObjPlayerFs(this, this->tpmax);
}

void TObjPlayer::revive() {
    struct VObj_801B4340_801B3FD8 *o = (struct VObj_801B4340_801B3FD8 *)this;
    ((s32 (*)(void))update_rotation__10TObjPlayerFv)();
    o->m53();
    obj_clearFlags30((u32)0xE00);
    sub_8011E204__10TObjPlayerFl(this, 1);
}

void handle_6xA1_revive_player_v3(void *arg0) {
    struct pkt_801B1674 pkt;
    ((TObjPlayer *)(&pkt))->set_code_161_1();
    TObjPlayer::revive_6xA1((s32)((s32)((s32) &pkt)), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6xA1_revive_player_v3((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            ((TObjPlayer *)p)->revive();
        }
    }
}

s32 TObjPlayer::revive_6xA1(s32 arg0, void * _w1) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void TObjPlayer__sub_801B4430(s32 arg0) {
    struct S801B4430_801b4430_801B3FD8 sp8;

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_161_1();
        sp8.h = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TObjPlayer *)(&sp8))->update_font();
    }
}

void handle_6x32_medical_center_revive_all_players(void) {
    s32 i;
    void *p;
    void **pp = player_slot_table;
    for (i = 0; i < 4; i++, pp++) {
        p = *pp;
        if (p != NULL && obj_isState3_324__13TUnk_804806E8Fv(p) != 0) {
            recover_full__10TObjPlayerFPv(p);
        }
    }
}

void send_code50_packet__10TObjPlayerFi(s32 arg0) {
    struct S801B44EC_801b44ec_801B3FD8 sp8;

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_50_1();
        sp8.h = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TObjPlayer *)(&sp8))->send_font_state();
    }
}

void recover_full__10TObjPlayerFPv(void *player) {
    struct VObj_801B4540_801B3FD8 *o = (struct VObj_801B4540_801B3FD8 *)player;
    ((s32 (*)(void))play_voice_pair__10TObjPlayerFPv)();
    o->m53();
    ((TUnk_804B9870 *)player)->obj_clearFlags30((u32)0xE00);
    sub_8011E204__10TObjPlayerFl(player, 1);
}

void handle_6x31_use_medical_center(void *arg0) {
    struct pkt_801B1674 pkt;
    ((TObjPlayer *)(&pkt))->set_code_49_1();
    TObjPlayer::update_medical_font((s32)((s32)((s32) &pkt)), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x31_use_medical_center((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            recover_full__10TObjPlayerFPv(p);
        }
    }
}

s32 TObjPlayer::update_medical_font(s32 arg0, void * _w1) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void send_code_49_1__10TObjPlayerFi(s32 arg0) {
    struct S801B4630_801B3FD8 sp8;

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_49_1();
        sp8.h = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TObjPlayer *)(&sp8))->bswap_font_lobby();
    }
}

s32 TObjPlayer::get_recovery_need_flags() {
    s32 var_r31;
    var_r31 = 0;
    if ((s16) this->hp < (s16) this->hpmax) {
        var_r31 |= 1;
    }
    if ((s16) *(s16 *)&this->tp < (s16) this->tpmax) {
        var_r31 |= 2;
    }
    if (((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(this, 0x3F) != 0) {
        var_r31 |= 4;
    }
    switch (obj_getArrWord_254(this, 2)) {
    case 0xB:
        var_r31 |= 4;
        break;
    }
    switch (obj_getArrWord_254(this, 3)) {
    case 0xC:
        var_r31 |= 4;
        break;
    }
    return var_r31;
}

s32 TObjPlayer::can_use_action() {
    s32 arg0 = (s32)this;
    if (((TObjPlayer *)(arg0 + 0x550))->check_action_usable(0x200) == 0) {
        return 0;
    }
    if (((s32 (*)(s32))check_flag_100__10TObjPlayerFPv)(arg0) != 0) {
        return 0;
    }
    if (test_action_mask__10TObjPlayerFl(arg0, 0x200) != 0) {
        return 0;
    }
    return ((TFontSmallLobby *)(arg0 + 0x4AC))->is_ready() != 0 ? 1 : 0;
}

void send_field_state__10TObjPlayerFPv(void* p) { ((TObjPlayer *)((char*)p + 0x384))->emit_photon_blast_feedback_from_packet(); ((int (*)(void*, void*))send_field_state_if_active__10TObjPlayerFP10TObjPlayerl)(p, (void*)142625); }

void TObjPlayer::update_target() {
    s32 current_target_id;
    s32 arg0 = (s32)this;

    current_target_id = TObjPlayer::get_current_target_id();
    if (((u16)current_target_id == 0xFFFF) || ((u16)current_target_id == ((u16 (*)(s32))get_entity_id)(arg0))) {
        ((TFontSmallLobby *)(arg0 + 0x4AC))->reset_targets();
        return;
    }
    fn_801C1F1C(arg0 + 0x4AC);
    if (((TObjPlayer *)arg0)->can_use_action() != 0) {
        draw_party_label__15TFontSmallLobbyFiUis(arg0 + 0x4AC, arg0, current_target_id);
    }
}

s32 TObjPlayer::is_target_valid() {
    if ((u32) this->m_424 == 0U) {
        return 0;
    }
    if (((u16) this->interactor != 0xFFFF) || (((s32 (*)(void))check_flag_100__10TObjPlayerFPv)() != 0) || (((TMainCursor *)(this->m_424))->is_cursor_clear() == 0) || (this->check_flag_0x40000000() != 0) || (((s32 (*)(void *, s32))test_action_mask__10TObjPlayerFl)(this, 0x1E) == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::update_subsystems() {
    s32 arg0 = (s32)this;
    if (((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0) {
        ((TObjPlayer *)arg0)->check_level_up();
        sync_status_effect_flags();
        clear_action_flag();
        ((TObjPlayer *)arg0)->update_target();
        if ((check_player_flag1__6TLobbyFv(arg0) != 0) && (TObjPlayer__sub_801BF57C((void *)(arg0 + 0x730)) >= 0) && (TObjPlayer__sub_801BF560((s16 *)(arg0 + 0x730)) == 0)) {
            TObjPlayer::send_code_45_1(arg0);
        }
        update_target_lock__10TObjPlayerFii(arg0 + 0x63C, arg0);
        if (((TItemMag *)(arg0 + 0x5B0))->check_state_flag_1() != 0) {
            update_player_scale_camera((PlayerScaleState *)(arg0 + 0x5B0));
        }
    }
}

s32 TObjPlayer::get_battle_ctrl_id(u16 arg0) {
    u32 temp_r3;
    void *temp_r3_2;

    temp_r3_2 = ((void * (*)(u32))get_player_by_client_id)(arg0);
    if (temp_r3_2 == NULL) {
        return 0xFFFF;
    }
    temp_r3 = *(u32 *)((s8 *)temp_r3_2 + 0x424);
    if (temp_r3 == 0U) {
        return 0xFFFF;
    }
    return ((s32 (*)(s32))get_id__11TMainCursorFv)(temp_r3 + 0x4F8);
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
                        try_add_target_candidate__11TMainCursorFPvPvPvPv(c, self, o, (u8 *)o->menu + 0x510);
                    }
                }
            }
        }
    }
}

void submit_target_to_player_cursor(void *target, s32 id) {
    s32 i;
    Player_801B4AC8 *player;
    Slot_801B4AC8 *entry;
    if (target == NULL || (u16)id == 0xFFFF || (u16)id >= 0x1000) {
        return;
    }
    player = ((Player_801B4AC8 *)((void * (*)(u32))get_player_by_client_id)((u16)id));
    if (player != NULL && player->cursor != NULL) {
        for (i = 0; i < 4; i++) {
            entry = &player->cursor->slots[i];
            if (((TMainCursor *)entry)->get_selected_entry() != 0) {
                try_add_target_candidate__11TMainCursorFPvPvPvPv(entry, target, player, &player->cursor->f510);
            }
        }
    }
}

void TObjPlayer::update_facing_vector() {
    this->m_404 = sin_table_lookup(this->rotation_y);
    *(f32 *)((s8 *)((u8 *)this) + 0x408) = (f32) TObjPlayer__data_805DC278;
    this->m_40c = cos_table_lookup(this->rotation_y);
    update_ground_contact();
    if ((u32) this->m_424 != 0U) {
        ((TMainCursor *)(*(void **)((s8 *)((u8 *)this) + 0x424)))->reset_slots();
    }
    TObjPlayer__sub_801BF584(((u8 *)this) + 0x360);
}

void TObjPlayer::clear_action_flag() {
    if ((TObjPlayer__sub_801C2044((s32 *)(*(s32 *)((s8 *)this + 0xD00) + 0x20)) == 0) && (((u32 (*)(void *))is_action_active__10TObjPlayerFv)(this) != 0U)) {
        this->clear_flag_0x2();
        TObjPlayer::send_code_45_1((s32)this);
    }
}

void TObjPlayer::apply_material_color_override() {
    s32 arg0 = (s32)this;
    if (!(((TObjPlayer *)arg0)->render_material_state.get_alpha() >= TObjPlayer__data_805DC294)) {
        set_default_alpha_blend();
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(-1, 0x800);
        set_constant_material((const NJS_ARGB *)((arg0 + 0x624)));
    }
}

s32 TObjPlayer::get_battle_ctrl_flag(u16 arg0) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(s32))get_player_by_client_id)((u16)arg0);
    if ((temp_r3 != 0) && (((s32 (*)(void))is_on_current_floor__10TObjPlayerFi)() != 0)) {
        return temp_r3;
    }
    return 0;
}

void fill_player_record__10TObjPlayerFPvPv(Src_801B4CE4 *src, Dst_801B4CE4 *dst) {
    s32 j;
    s32 i;
    s32 a;
    s32 b;
    u32 v;
    dst->f0 = ((s16 (*)(s32))get_entity_id)((s32)src);
    dst->f2 = src->f2E;
    dst->f4 = src->f30 & ~0x02000000;
    VecCopy((Vec *)dst->f8, (const Vec *)src->pos38);
    ((TObjPlayer *)(dst->f14))->copy_xyz(src->f5C);
    dst->f20 = src->f326;
    dst->f22 = src->f32C;
    for (i = 0; i < 5; i++) {
        TObjPlayer__sub_801BEF44(&dst->f28[i], &src->f254[i]);
    }
    ((TLobby *)(dst->f68))->copy_header_struct(src->fDAC);
    TObjPlayer__sub_801BEF30(dst->f70, src->f828);
    ((TObjPlayer *)(dst->f78))->copy_player_record_header(src->f830);
    TObjPlayer__sub_801BEEE0(dst->f94, src->f858);
    TObjPlayer__sub_801BEEAC(dst->f98, src->f730);
    dst->fAC = ((s32 (*)(void *))get_field_3e0__12TBoss3VoloptFv)(src);
    dst->f488 = ((TObjPlayer *)src)->get_field_3e4();
    dst->fB0 = src->f334;
    dst->f64 = ((s32 (*)(void *))TObjPlayer__sub_801AFD8C)(src);
    copy_player_visual_record(dst->fC8, src->f85C);
    dst->f13C = run_state_query__10TObjPlayerFi(src->fD00, dst->f140);
    a = get_actor_hp(src);
    b = get_actor_tp(src);
    for (i = 0; i != 0xD; i++) {
        TItem *e = ((TObjPlayer *)src)->get_equipped_item(i);
        if (e != NULL) {
            e->remove_equip_stats(1);
        }
    }
    copy_data__6TLobbyFPvPv(dst->f118, src->f2B0);
    dst->f24 = ((TObjPlayer *)src)->get_hp_bonus();
    dst->f26 = ((TObjPlayer *)src)->get_tp_bonus();
    TObjPlayer__sub_801BE864(dst, ((TObjPlayer *)src)->get_field_374());
    TObjPlayer__sub_801BE838(dst, ((TObjPlayer *)src)->get_field_374_state());
    TObjPlayer__sub_801BE80C(dst, ((TObjPlayer *)src)->get_inventory_state());
    TObjPlayer__sub_801BE7E0(dst, ((TObjPlayer *)src)->get_equip_flags());
    TObjPlayer__sub_801BE7B4(dst, TObjPlayer__sub_801BE7BC(src));
    for (i = 0; i < 0x13; i++) {
        split_capped_value__10TObjPlayerFUcPUcPSc(TObjPlayer__sub_801C0124(src->f428, i), &dst->fB4[i], &dst->f142[i]);
    }
    for (j = 0; j != 0xD; j++) {
        TItem *e = ((TObjPlayer *)src)->get_equipped_item(j);
        if (e != NULL) {
            e->add_equip_stats(1);
        }
    }
    ((void (*)(void *, s32))set_hp_clamped__10TObjPlayerFs)(src, a);
    ((void (*)(void *, s32))set_tp__10TObjPlayerFs)(src, b);
    encode_player_record_inventory(dst);
    v = TObjPlayer__sub_801BFFA0(src->f41C);
    dst->f142[0].b[1] = v;
    dst->f142[1].b[1] = v >> 8;
    dst->f142[2].b[1] = v >> 16;
    dst->f142[3].b[1] = v >> 24;
    TObjPlayer__sub_801BE7A4(dst, get_mag_level__10TObjPlayerFPv(src));
    TObjPlayer__sub_801BE794(dst, get_byte_339__10TObjPlayerFv(src));
    TObjPlayer__sub_801BE784(dst, get_battle_mode__10TObjPlayerFv(src));
    bswap_player_data__6TLobbyFi(dst);
}

Obj_801B4FD8 *init_player_join_record(Obj_801B4FD8 *self) {
    s32 i;
    __construct_array(self->f28, TObjPlayer::init_192dc_return_self, 0, 0xC, 5);
    ((TObjPlayer *)(self->f68))->clear_header_struct();
    TObjPlayer__sub_801C1A00(self->f70);
    init_player_telepipe_record(self->f78);
    __ct__8FlagWordFv((self->f94));
    TObjPlayer__sub_801BF660(self->f98);
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

#pragma push
#pragma fp_contract on
s32 TObjPlayer::is_outside_movement_hold(f32 *pos) {
    f32 *center;
    f32 x, y, z;
    f32 dx, dz;
    if (((s32 (*)(void))check_player_flag1__6TLobbyFv)() == 0) {
        return 0;
    }
    center = TObjPlayer__sub_801BF6B8((u8 *)&this->m_730);
    x = center[0];
    y = pos[0];
    z = center[1];
    dx = x - y;
    dz = z - pos[2];
    return (u32)__cntlzw(TObjPlayer__sub_801BF6B0((u8 *)&this->m_730, z, y, x) > (dx * dx + dz * dz)) >> 5;
}
#pragma pop

void handle_6x2D_release_hold(void *arg0) {
    struct pkt_801B5164 pkt;
    ((TObjPlayer *)(&pkt))->set_code_45_1();
    TObjPlayer::draw_small_font((s32)((s32) &pkt), arg0);
    TFontSmallLobby__sub_801C01BC(&pkt);
    if (validate_6x2D_release_hold((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((s32 (*)(s32))get_player_by_client_id)(pkt.player_id);
        if (p != NULL) {
            ((void (*)(u8 *, int))sub_8011E204__10TObjPlayerFl)(p, 1);
        }
    }
}

s32 TObjPlayer::draw_small_font(s32 arg0, void * _w1) {
    TFontSmallLobby__sub_801C0228();
    return arg0;
}

void TObjPlayer::send_code_45_1(s32 arg0) {
    struct S801B5200_801B3FD8 sp8;

    if ((arg0 == 0) || (obj_isState2_324__13TUnk_804806E8Fv() == 0)) {
        ((TObjPlayer *)(&sp8))->set_code_45_1();
        sp8.h = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TObjPlayer *)(&sp8))->send_lobby_update_font();
    }
}

void handle_6x2C_impose_hold(s32 arg0) {
    Pkt_801B5254 pkt;
    s32 player;
    ((TObjPlayer *)(&pkt))->build_6x2C_impose_hold_packet();
    ((TObjPlayer *)(&pkt))->copy_hold_params((u8 *)arg0);
    bswap_pkt_u16x2_u32__10TObjPlayerFPv(&pkt);
    if (validate_6x2C_impose_hold((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    player = ((s32 (*)(s32))get_player_by_client_id)(pkt.client);
    if (player == 0) {
        return;
    }
    TObjPlayer__sub_801BF6DC((void *)(player + 0x730), pkt.f6);
    TObjPlayer__sub_801BF6D4((void *)(player + 0x730), pkt.f4);
    TObjPlayer__sub_801BF6C8(player + 0x730, pkt.f8, pkt.fC);
    TObjPlayer__sub_801BF6C0((void *)(player + 0x730), pkt.f10);
    ((void (*)(s32, u32))set_state_flags__10TObjPlayerFUl)(player, 1);
    if (((s32 (*)(s32))check_flag_4__10TObjPlayerFv)(player) == 0 && ((s32 (*)(s32))is_on_current_floor__10TObjPlayerFi)(player) != 0) {
        TObjEneHoldEffect::create((void *)player, (void *)pkt.f6, (void *)pkt.f4);
    }
}

void send_6x2C_impose_hold(s32 arg0, struct Vec_801B5328 *pos, s16 arg2, s16 arg3, f32 radius) {
    struct Pkt_801B5328 pkt;
    if (arg0 == 0 || obj_isState2_324__13TUnk_804806E8Fv() == 0) {
        ((TObjPlayer *)(&pkt))->build_6x2C_impose_hold_packet();
        pkt.actor_id = ((s16 (*)(s32))get_entity_id)(arg0);
        pkt.b = arg3;
        pkt.a = arg2;
        pkt.x = pos->x;
        pkt.z = pos->z;
        pkt.radius_sq = radius * radius;
        ((TObjPlayer *)(&pkt))->bswap_and_send_packet();
    }
}

void TObjPlayer::play_effect(s32 arg0, s32 arg1, s32 arg2) {
    ((s32 (*)(s32, s32, s32, s32, f32))send_6x2C_impose_hold)(arg0, get_position_ptr__10TObjPlayerFv(), arg1, arg2, (*(f32 *)&TObjPlayer__data_805DC278));
}

void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1) {
    ((s32 (*)(s32, s32, s32, s32, f32))send_6x2C_impose_hold)(arg0, get_position_ptr__10TObjPlayerFv(), arg1, 0, (*(f32 *)&TObjPlayer__data_805DC278));
}

void TObjPlayer::init_trait_flags() {
    this->m_2e4 = 0;
    if (get_class_flags() & CLASS_FLAG_ANDROID) {
        this->add_flags_2e4(4);
    } else {
        this->add_flags_2e4(1);
    }
    if (get_class_flags() & CLASS_FLAG_RANGER) {
        this->add_flags_2e4(0x20);
    }
}

s32 TObjPlayer::get_clamped_index() {
    s32 temp_r3;

    temp_r3 = this->m_3d8;
    if ((temp_r3 < 0) || (temp_r3 >= 3)) {
        return 0;
    }
    return temp_r3;
}

void set_move_mode__10TObjPlayerFi(s32 arg0) {
    s32 temp_r3;

    temp_r3 = ((TObjPlayer *)arg0)->get_class_flags();
    if (temp_r3 & CLASS_FLAG_ANDROID) {
        ((TObjPlayer *)arg0)->set_move_mode(2);
        return;
    }
    if (temp_r3 & CLASS_FLAG_NEWMAN) {
        ((TObjPlayer *)arg0)->set_move_mode(1);
        return;
    }
    ((TObjPlayer *)arg0)->set_move_mode(0);
}

void TObjPlayer::apply_input_mode() {
    s32 arg0 = (s32)this;
    s32 class_flags;

    class_flags = get_class_flags();
    if (class_flags & CLASS_FLAG_HUNTER) {
        ((TObjPlayer *)arg0)->set_input_mode(0);
        return;
    }
    if (class_flags & CLASS_FLAG_RANGER) {
        ((TObjPlayer *)arg0)->set_input_mode(1);
        return;
    }
    ((TObjPlayer *)arg0)->set_input_mode(2);
}

void TObjPlayer::select_class_action_provider() {
  s8 temp_r3;
  temp_r3 = ((s8 (*)(void *))get_class_index__10TObjPlayerFv)((void *) ((u8 *)this));
  {
    switch (temp_r3)
    {
      case 0:
      case 2:
      case 3:
      case 4:
      case 7:
        forward_801C210C__10TObjPlayerFv((int) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x380))), 0);
        return;
      case 1:
      case 5:
      case 8:
        forward_801C210C__10TObjPlayerFv((int) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x380))), 1);
        return;
      case 6:
        forward_801C210C__10TObjPlayerFv((int) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x380))), 2);
        return;
      case 9:
        forward_801C210C__10TObjPlayerFv((int) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x380))), 4);
        return;
      case 10:
        forward_801C210C__10TObjPlayerFv((int) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x380))), 3);
        return;
      case 11:
        forward_801C210C__10TObjPlayerFv((int) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x380))), 5);
        break;
    }
  }
}

int TObjPlayer::has_valid_handle() { return ((TObjPlayer *)(*(void**)((char*)this + 0x380)))->is_handle_valid(); }

int check_flag_100__10TObjPlayerFPv(void* p) { return ((int (*)(void*, int))check_flag__10TObjPlayerFl)(p, 256); }

void TObjPlayer::init_parts() { fn_8019DD24((char*)this + 0x550, (u32)((void*)1030)); ((TChallenge4PResult *)this)->get_player_rank(); ((int (*)(void*, void*))sub_8011E204__10TObjPlayerFl)(this, (void*)256); }

void TObjPlayer::reset_equip_slots() { mask_action_buttons((char*)this + 0x550, (u32)((void*)1030)); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)0); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)1); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)2); ((int (*)(void*, void*))get_player_result__18TChallenge4PResultFPv)(this, (void*)3); ((int (*)(void*, void*))set_state_flags__10TObjPlayerFUl)(this, (void*)256); }

s32 TObjPlayer::get_camera_field() {
    void *p = *(void **)((s8 *)this + 0x424);
    if (p != 0) {
        return ((TMainCursor *)p)->is_cursor_clear();
    }
    return 0;
}

void TObjPlayer::release_attached_resource() { void* m = *(void**)((char*)this + 0x424); if (m) ((TObjPlayer *)m)->set_flags_bit1(); }

void TObjPlayer::action_enable_if_present() { void* m = *(void**)((char*)this + 0x424); if (m) ((TObjPlayer *)m)->clear_flag_1_at_1c(); }

void *TObjPlayer__sub_801B57E8(TObjPlayer *player) {
    s32 i;
    s32 cursor;
    if ((u32)player->m_424 == 0) {
        return NULL;
    }
    cursor = player->m_424 + 0x5C;
    for (i = 0; i < 4; i++) {
        if (try_move__11TMainCursorFiii(cursor, ((TObjPlayer *)&player->m_340)->update_main_cursor(), TObjPlayer__sub_801BF6E4(&player->m_340)) != 0) {
            return (void *)cursor;
        }
        cursor += 0x124;
    }
    return NULL;
}

s32 TObjPlayer::is_quest_interaction_blocked() {
    if (this->m_424 == 0U) {
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

s32 TObjPlayer::has_action_palette_entry() {
    if (((u32) this->m_424 != 0U) && (((u16)get_action_palette_entry(0)) != 0)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 is_action_channel_available__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        if (((s32 (*)(void))is_flag_400_set__10TObjPlayerFPv)() != 0) {
            return 1;
        }
        if (((TObjPlayer *)arg0)->has_action_palette_entry() != 0) {
            return 1;
        }
        goto block_5;
    }
block_5:
    return is_action_channel_active(((TObjPlayer *)arg0)->refresh_effect(), arg1);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjPlayer::is_effect_channel_active(s32 arg0, s32 arg1) {
    is_action_channel_active(((TObjPlayer *)arg0)->refresh_effect(), arg1);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjPlayer::refresh_party_cursors(s32 arg0) {
    TObjPlayer::update_party_cursors(((TObjPlayer *)arg0)->refresh_effect(), arg0);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer::set_action_palette_entry(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 arg0 = (s32)this;
    TWindowActionPalette::set_palette_entry((s32)((TObjPlayer*)arg0)->select_action_palette(arg1), arg2, arg3, arg4, arg5);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer__sub_801B5A44(s32 arg0, s32 secondary, s32 i, s32 arg3, s32 arg4) {
    TWindowActionPalette::set_slot_by_index((s32)((TObjPlayer*)arg0)->select_action_palette(secondary), i, arg3, arg4);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer::select_action_palette_and_apply(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    TWindowActionPalette__sub_801C1D7C((s32)((TObjPlayer*)arg0)->select_action_palette(arg1), arg2, arg3);
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjPlayer::get_action_palette_entry(s32 arg1) {
    s32 arg0 = (s32)this;
    return get_entry_by_index__20TWindowActionPaletteFPll(((TObjPlayer *)arg0)->refresh_effect(), arg1);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjPlayer__sub_801B5AF8(s32 arg0, s32 arg1) {
    TWindowActionPalette::get_slot_type_for_index((s32 *)(((TObjPlayer *)arg0)->refresh_effect()), (s32)arg1);
}
}
#pragma pop
TObjPlayer::ActionPalette* TObjPlayer::select_action_palette(int secondary) {
    if (secondary == 1) {
        return (ActionPalette*)fn_801C1E48((s32)action_palettes);
    }
    return (ActionPalette*)fn_801C1E44((s32)action_palettes);
}

s32 TObjPlayer::refresh_effect() {
    s32 arg0 = (s32)this;
    if (TObjPlayer__sub_801C1F50(arg0 + 0x4AC) != 0) {
        if (test_photon_blast_modifier(arg0 + 0x500) != 0) {
            return fn_801C1E44(arg0 + 0x500);
        }
        return fn_801C1E48(arg0 + 0x500);
    }
    return fn_801C1E44(arg0 + 0x500);
}

void TObjPlayer::select_contextual_pickup_action() {
    s32 type;
    s32 cursor;
    s32 ent;
    u32 obj;
    obj = this->m_424;
    if (obj != 0U) {
        cursor = obj + 0x4F8;
        type = 0;
        if (((u16 (*)(s32))get_id__11TMainCursorFv)(cursor) != 0xFFFF) {
            ent = ((s32 (*)(u16))find_entity_by_id)(((u16 (*)(s32))get_id__11TMainCursorFv)(cursor));
            if (ent != 0) {
                type = ((TUnk_804AF8A0 *)ent)->get_cursor_action();
                if (type != 0) {
                    switch (type) {
                    case 4:
                        if (((s32 (*)(void *, s32))test_action_mask__10TObjPlayerFl)(this, 0xE0) != 0) {
                            type = 0;
                        } else {
                            s32 item = ((s32 (*)(u16))find_entity_by_id)(((u16 (*)(s32))get_id__11TMainCursorFv)(cursor));
                            if (((s32 (*)(void *, s32))can_pickup_item_by_id__10TObjPlayerFP5TItem)(this, item) != 0) {
                                if ((((s32 (*)(void *))is_flag_400_set__10TObjPlayerFPv)(this)) != 0) {
                                    ((s32 (*)(void *, s32))get_field_340__18TChallenge4PResultFPv)(this, 1);
                                }
                            } else {
                                type = 0;
                                if (check_flag_100__10TObjPlayerFPv(this) == 0 && ((TObjPlayer *)(((u8 *)this) + 0x550))->check_action_usable(4) != 0) {
                                    play_sound_effect(0x3816, ((s32 (*)(s32))get_position_ptr__10TObjPlayerFv)(ent), 0, 1);
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

void TObjPlayer::update_ground_contact() {
    s32 arg0 = (s32)this;
    if (((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0) {
        if (((TObjPlayer *)(arg0 + 0x550))->try_ground_action(fn_8002AE08(((s32 (*)(s32))get_entity_id)(arg0))) != 0) {
            fn_801C1EF4(arg0 + 0x500);
            if (TObjPlayer__sub_801C1F50(arg0 + 0x4AC) != 0) {
                fn_801C1EC4(arg0 + 0x500);
            }
        } else {
            fn_801C1EA4(arg0 + 0x500);
            if (TObjPlayer__sub_801C1F50(arg0 + 0x4AC) != 0) {
                fn_801C1E74(arg0 + 0x500);
            }
        }
        TObjPlayer::refresh_party_cursors(arg0);
    }
}

s32 TObjPlayer::check_actor_blocking_move() {
    Obj_801B5DDC *self = (Obj_801B5DDC *)this;
    Vec_801B5DDC pos;
    Vec_801B5DDC diff;
    Hit_801B5DDC hit;
    pos.x = self->pos.x + self->f308.x;
    pos.y = TObjPlayer__data_805DC278;
    pos.z = self->pos.z + self->f308.z;
    if (test_player_overlap_with_players(self, self, &pos, &hit) != 0) {
        if (hit.flags & 0x100) {
            return 0;
        }
        diff.x = pos.x - hit.pos.x;
        diff.y = TObjPlayer__data_805DC278;
        diff.z = pos.z - hit.pos.z;
        if (vec3_dot(&diff, &self->f308) < TObjPlayer__data_805DC278) {
            return 1;
        }
    }
    return 0;
}

s32 TObjPlayer::resolve_move_collision() {
    Vec_801B5EA4 p;
    p.x = ((Obj_801B5EA4 *)this)->pos.x + ((Obj_801B5EA4 *)this)->vel.x;
    p.y = ((Obj_801B5EA4 *)this)->pos.y + ((Obj_801B5EA4 *)this)->vel.y;
    p.z = ((Obj_801B5EA4 *)this)->pos.z + ((Obj_801B5EA4 *)this)->vel.z;
    if (this->vfunc_18((u8 *)&p) == 0U) {
        TObjPlayer__sub_8001053C((u8 *)this);
        return 1;
    }
    if (apply_wall_response() != 0U) {
        TObjPlayer__sub_8001053C((u8 *)this);
        return 2;
    }
    if ((TObjPlayer__sub_801BE8F4(this, 0, 0x380000) != 0) && (TObjPlayer__sub_801BE8F4(this, 0, 0x01C00000) != 0)) {
        TObjPlayer__sub_8001053C((u8 *)this);
        return 4;
    }
    if (is_outside_movement_hold(&p.x) != 0) {
        TObjPlayer__sub_8001053C((u8 *)this);
        return 3;
    }
    return 0;
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

void TObjPlayer::rewind_position_history() {
    Stack_801B6024 stack;
    s32 temp_r0;
    u8 *temp_r3;
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x6AC) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x6AC) = temp_r0;
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)((u8 *)this) + 0x6AC) = 0xF;
    }
    TObjPlayer__sub_801BE918(this, *(s32 *)((s8 *)((u8 *)this) + 0x6AC), &stack.sp8, &stack.sp10);
    stack.spC = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
    temp_r3 = csnVectorUnder(&stack.sp8, ((u8 *)this) + 0x120, 0x41);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)((u8 *)this) + 0x38) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 4)) + 0);
        *(f32 *)((s8 *)((u8 *)this) + 0x3C) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 4)) + 4);
        *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 4)) + 8);
    }
}

s32 TObjPlayer::is_matching_id(s16 arg1) {
    if ((is_flag_b0_4__10TObjPlayerFv() != 0) && (arg1 == (s16) *(s16 *)((s8 *)this + 0xBC))) {
        return 1;
    }
    return 0;
}

void handle_6x2E_set_or_clear_player_flags(void *arg0) {
    Msg_801B6110 m;
    Player_801B6110 *p;
    TObjPlayer__sub_801C0C04((u8 *)&m);
    ((TObjPlayer *)(&m))->copy_pair_fields(arg0);
    ((TObjPlayer *)(&m))->bswap_body_dwords();
    if (validate_6x2E_set_or_clear_player_flags((G_ClientIDHeader *)&m) != 0) {
        p = ((Player_801B6110 * (*)(s32))get_player_by_client_id)(m.slot);
        if (p != NULL) {
            p->flags = p->flags & m.andMask;
            p->flags = p->flags | m.orMask;
        }
    }
}

s16 TObjPlayer::add_stat_clamped(s32 arg0, s16 *arg1, s16 arg2) {
    s16 temp_r3;
    s16 var_r6;

    var_r6 = 0;
    *arg1 += arg0;
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

void TObjPlayer::add_lck(s32 arg1) {
    TObjPlayer::add_stat_clamped(arg1, (s16 *)((s16 *)(*(s32 *)((s8 *)this + 0x2B0) + 0xC)), (s16)(*(s16 *)((s8 *)(((s16 * (*)(void))get_class_stat_entry__10TObjPlayerFPUc)()) + 0xC)));
}

void TObjPlayer::add_evp(s32 arg1) {
    TObjPlayer::add_stat_clamped(arg1, (s16 *)((s16 *)(*(s32 *)((s8 *)this + 0x2B0) + 4)), (s16)(*(s16 *)((s8 *)(((s16 * (*)(void))get_class_stat_entry__10TObjPlayerFPUc)()) + 4)));
}

void TObjPlayer::add_ata(s32 arg1) {
    TObjPlayer::add_stat_clamped(arg1, (s16 *)((s16 *)(*(s32 *)((s8 *)this + 0x2B0) + 0xA)), (s16)(*(s16 *)((s8 *)(((s16 * (*)(void))get_class_stat_entry__10TObjPlayerFPUc)()) + 0xA)));
}

void TObjPlayer::add_mst(s32 arg1) {
    TObjPlayer::add_stat_clamped(arg1, (s16 *)((s16 *)(*(s32 *)((s8 *)this + 0x2B0) + 2)), (s16)(*(s16 *)((s8 *)(((s16 * (*)(void))get_class_stat_entry__10TObjPlayerFPUc)()) + 2)));
}

void TObjPlayer::add_hp(s32 arg1) {
    TObjPlayer::add_stat_clamped(arg1, (s16 *)((s16 *)(*(s32 *)((s8 *)this + 0x2B0) + 6)), (s16)(*(s16 *)((s8 *)(((s16 * (*)(void))get_class_stat_entry__10TObjPlayerFPUc)()) + 6)));
}

void TObjPlayer::add_dfp(s32 arg1) {
    TObjPlayer::add_stat_clamped(arg1, (s16 *)((s16 *)(*(s32 *)((s8 *)this + 0x2B0) + 8)), (s16)(*(s16 *)((s8 *)(((s16 * (*)(void))get_class_stat_entry__10TObjPlayerFPUc)()) + 8)));
}

void TObjPlayer::add_stat(s32 arg1) {
    TObjPlayer::add_stat_clamped(arg1, (s16 *)((s16 *)(*(s32 *)((s8 *)this + 0x2B0))), (s16)(*((s16 * (*)(void))get_class_stat_entry__10TObjPlayerFPUc)()));
}

void TObjPlayer::recalc_stats() {
    f32 temp_f31;
    f32 xscale;
    s32 arg0 = (s32)this;

    temp_f31 = get_tp_class_factor__10TObjPlayerFv();
    xscale = ((TObjPlayer *)arg0)->get_class_hp_factor();
    ((TUnk_804806E8 *)arg0)->recalc_combat_stats((void *)0, (void *)0, (void *)0, (f32)xscale, (f32)temp_f31);
    ((TUnk_804806E8 *)arg0)->clamp_hp();
    ((TObjPlayer *)arg0)->clamp_tp();
}

void TObjPlayer::update_aim_angle(s32 arg1) {
    struct VObj_801B6414_801B3FD8 *obj = (struct VObj_801B6414_801B3FD8 *) this;
    s32 class_state_field;

    class_state_field = this->get_class_state_field(TObjPlayer::clamp_index_to_max(arg1 + obj->m14()));
    obj->m12(class_state_field - this->obj_getPtr2B0_1C());
}

void TObjPlayer__sub_801B67C4(void* p) { *(s16*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0x4) = 0; }

void TObjPlayer::copy_stats(void *arg1) {
    *(s16 *)((s8 *)this + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)this + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)((s8 *)this + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)this + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(s16 *)((s8 *)this + 0xC) = (s16) *(s16 *)((s8 *)arg1 + 0xC);
}

void TObjPlayer::notify_volopt_if_ready(void* p) { if (((int (*)(void*))is_locally_controlled__10TObjPlayerFPv)(p) != 0) { ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)335646, (void*)0, (void*)0, (void*)0); } }

void spawn_level_change_feedback__10TObjPlayerFv(s32 arg0, s32 arg1) {
    void *p;
    TObjPlayer::notify_volopt_if_ready((void *)arg0);
    p = ((void * (*)(u32))__nw__7TObjectFUl)(0x60);
    if (p != NULL) {
        __ct__14TFontSmallHelpFUlUllUl(p, ((s32 (*)(s32))get_entity_id)(arg0), -1, 0x3C, arg1);
    }
    TObjPlayer::new_child_object(((s32 (*)(s32))get_entity_id)(arg0));
    lbl_8050BEE0[0].x = 0.0f;
    lbl_8050BEE0[0].y = -1.0f;
    lbl_8050BEE0[0].z = 0.0f;
    player_feedback_light_color[0].r = 1.0f;
    player_feedback_light_color[0].g = 1.0f;
    player_feedback_light_color[0].b = 0.8f;
    player_feedback_light_color[0].a = 0.63f;
    p = ((void * (*)(u32))__nw__7TObjectFUl)(0x64);
    if (p != NULL) {
        ((void (*)(void *, Color_801B6964 *, f32, Vec_801B6964 *, s32, s32, s32))construct_actor_light_task)(p, player_feedback_light_color, 0.2f, lbl_8050BEE0, 10, arg0, tl_07);
    }
    publish_actor_light_scalars(((s32 (*)(s32))get_entity_id)(arg0), 1.0f, 0.5f);
}

void handle_6x30_change_player_level(void *arg0) {
    Pkt_801B6A5C pkt;
    Plr_801B6A5C *p;
    f32 f;
    ((TObjPlayer *)(&pkt))->build_6x30_change_level_packet();
    ((TObjPlayer *)(&pkt))->copy_fields(arg0);
    swap_endian__10TObjPlayerFi((s32)&pkt);
    if (validate_6x30_change_player_level((G_ClientIDHeader *)&pkt) == 0) {
        return;
    }
    p = ((Plr_801B6A5C * (*)(u16))get_player_by_client_id)(pkt.id);
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
    f = ((f32 (*)(Plr_801B6A5C *))get_tp_class_factor__10TObjPlayerFv)(p);
    ((TUnk_804806E8 *)p)->recalc_combat_stats((void *)((s32)p->stats), (void *)0, (void *)0, (f32)(((TObjPlayer *)p)->get_class_hp_factor()), (f32)f);
    p->a2 = p->a;
    p->b2 = p->b;
    if (((TObjPlayer *)p)->is_alive_and_ready() != 0) {
        ((TObjPlayer *)p)->refill_traps();
    }
    if (((s32 (*)(Plr_801B6A5C *))check_flag_4__10TObjPlayerFv)(p) == 0) {
        if (pkt.kind == 1) {
            spawn_level_change_feedback__10TObjPlayerFv((s32)p, (s32)lbl_80446F50);
        } else {
            spawn_level_change_feedback__10TObjPlayerFv((s32)p, (s32)lbl_80446F5C);
        }
    }
}

void *TObjPlayer::copy_fields(void *arg1) {
    TFontSmallLobby__sub_801C0228();
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)((s8 *)this + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)this + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(s16 *)((s8 *)this + 0xC) = (s16) *(s16 *)((s8 *)arg1 + 0xC);
    *(s16 *)((s8 *)this + 0xE) = (s16) *(s16 *)((s8 *)arg1 + 0xE);
    *(s16 *)((s8 *)this + 0x10) = (s16) *(s16 *)((s8 *)arg1 + 0x10);
    *(s16 *)((s8 *)this + 0x12) = (s16) *(s16 *)((s8 *)arg1 + 0x12);
    return this;
}

void send_6x30_change_player_level(Player_801B6C30 *arg0) {
    Msg_801B6C30 m;
    Src_801B6C30 *s;
    if ((((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) && ((arg0 == NULL) || (((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(arg0) == 0))) {
        ((TObjPlayer *)(&m))->build_6x30_change_level_packet();
        m.f2 = ((s16)((u16 (*)(void *))get_entity_id)(arg0));
        s = arg0->src;
        m.f4[0] = s->v[0];
        m.f4[1] = s->v[1];
        m.f4[2] = s->v[2];
        m.f4[3] = s->v[3];
        m.f4[4] = s->v[4];
        m.f4[5] = s->v[5];
        m.f10 = clamp_nested_index__10TObjPlayerFv(arg0, (int)s);
        m.f12 = 0;
        ((TObjPlayer *)(&m))->send_swapped_packet_6x30();
    }
}

s32 TObjPlayer::apply_exp_level_growth() {
    s32 i;
    s32 lvl;
    s32 cls;
    s32 e;
    cls = ((s8 (*)(void))get_class_index__10TObjPlayerFv)();
    lvl = ((s32 (*)(void *))clamp_nested_index__10TObjPlayerFv)(this) + 1;
    for (i = 0; i < TObjPlayer::get_max_level(); i++) {
        if (lvl > TObjPlayer::get_max_level()) {
            break;
        }
        e = get_ply_level_table_row(cls, lvl);
        if (e == 0) {
            break;
        }
        if (get_level_row_exp_threshold() > ((Obj_801B6CE0 *)this)->stats->exp) {
            break;
        }
        add_stat(((TObjPlayer *)e)->get_char_class());
        add_mst(((TObjPlayer *)e)->get_team_id());
        add_evp(TObjPlayer__sub_801C2134((void *)e));
        add_hp(TObjPlayer__sub_801C212C((void *)e));
        add_dfp(((TObjPlayer *)e)->get_byte_4());
        add_ata(((TObjPlayer *)e)->get_field_5());
        ((Obj_801B6CE0 *)this)->stats->level = lvl;
        lvl++;
    }
    return 1;
}

void TObjPlayer::check_level_up() {
    struct Buf1C sp40;
    struct Buf1C sp24;
    struct Buf1C sp8;
    s32 var_r31;
    u8 *temp_r31;
    s32 var_r30;
    s32 temp_r30;
    u8 *temp_r30_2;
    u8 *arg0 = (u8 *)this;
    if ((((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0) && (are_items_enabled_here() != 0)) {
        temp_r30 = ((s32 (*)(void *))clamp_nested_index__10TObjPlayerFv)(arg0) + 1;
        if (temp_r30 <= TObjPlayer::get_max_level()) {
            if (((s32 (*)(void *, int))get_current_state_field__10TObjPlayerFScl)((void *) (((s32 (*)(void *))get_class_index__10TObjPlayerFv)(arg0)), temp_r30) <= (s32) *(s32 *)(this->m_2b0 + 0x1C)) {
                ((TObjPlayer *)(&sp40))->reset_sub_status_disp();
                ((TObjPlayer *)(&sp24))->reset_sub_status_disp();
                ((TObjPlayer *)(&sp8))->reset_sub_status_disp();
                var_r30 = 0;
                do {
                    temp_r31 = get_slot_value__10TObjPlayerFPvi(this->equipped_items, var_r30);
                    if ((((s32 (*)(void))can_destroy_with_parents__10TObjPlayerFUi)() != 0) && (is_item_equipped((int)temp_r31) != 0)) {
                        ((VObj *)temp_r31)->m21(1);
                    }
                    var_r30 += 1;
                } while (var_r30 < 0xD);
                init_shield_params__10TObjPlayerFl(&sp40, arg0, this->m_2b0, this->m_318, (int) (*(s32 *)((s8 *)arg0 + 0x31C)));
                ((TObjPlayer *)arg0)->apply_exp_level_growth();
                init_shield_params__10TObjPlayerFl(&sp24, arg0, this->m_2b0, this->m_318, (int) (*(s32 *)((s8 *)arg0 + 0x31C)));
                var_r31 = 0;
                do {
                    temp_r30_2 = get_slot_value__10TObjPlayerFPvi(this->equipped_items, var_r31);
                    if ((((s32 (*)(void))can_destroy_with_parents__10TObjPlayerFUi)() != 0) && (is_item_equipped((int)temp_r30_2) != 0)) {
                        ((VObj *)temp_r30_2)->m20(1);
                    }
                    var_r31 += 1;
                } while (var_r31 < 0xD);
                ((TObjPlayer *)(&sp40))->calc_pos_delta(&sp24, &sp8);
                TWindowCtrl::create_level_up_window((s32)&sp8, (s32)((void *) (((u16 (*)(void *))get_entity_id)(arg0))));
                send_6x30_change_player_level((Player_801B6C30 *)((struct Player_801B6C30 *) (arg0)));
            }
        }
    }
}

void TObjPlayer::update_status_effects() {
    u8 *arg0 = (u8 *)this;
  update_player_appear_fade(((u8 *)&this->m_634));
  update_target_lock();
  if ((this->is_actor_cadence_frame(3)) != 0)
  {
    if (set_flag_02000000__10TObjPlayerFv((void *) arg0) == 0)
    {
      get_current_area();
      *((s16 *) (((s8 *) arg0) + 0x28)) = TScene::get_player_ctrl_field(((u16 (*)(void *))get_entity_id)(arg0));
    }
  }
  ((TObjPlayer *)arg0)->set_flag_2000000();
  (this->vfunc_43());
  (this->update_poison_status());
  (this->update_action_hold_status());
  (this->vfunc_37());
  (this->update_flag30_timer());
  (this->update_movement_status());
  (this->update_shock_clock());
  (this->update_attack_stat_status());
  (this->update_defense_stat_status());
  if (((TItemMag *)(arg0 + 0x644))->get_mag_id() <= 0)
  {
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)(0x04000100));
  }
  else
  {
    TObjPlayer::decrement_clamp((s32 *)(arg0 + 0x644), 1);
    ((s32 (*)(void *, int))obj_setFlags30)((void *) arg0, 0x04000000);
  }
  if ((this->hp) <= 0)
  {
    ((s32 (*)(void *, int))obj_setFlags30)((void *) arg0, 0xA00);
  }
  ((TObjPlayer *)(arg0 + 0x360))->update_timer();
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
        ((TObjPlayer *)arg0)->set_position_history_entry(*(s32 *)((s8 *)arg0 + 0x6AC), *(f32 *)((s8 *)arg0 + 0x38), *(f32 *)((s8 *)arg0 + 0x40));
    }
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)&this->position);
    ((TObjPlayer *)(arg0 + 0x360))->update_field8();
}

void TObjPlayer::clear_lobby_flag(void *arg0) {
    if ((s32) lbl_805D55C0 == 0) {
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)0x10000);
    }
}

void TObjPlayer::init_effect_5f0() {
    u8 *arg0 = (u8 *)this;
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    set_action_id__10TObjPlayerFs((u8 *)&this->m_5f0, 0x10);
    set_anim_state__10TObjPlayerFs((u8 *)&this->m_5f0, ((TObjPlayer *)arg0)->get_idle_animation());
    ((TObjPlayer *)(arg0 + 0x5F0))->set_state(0);
    ((TObjPlayer *)(arg0 + 0x5F0))->set_anim_state(this->rotation_y);
}

void TObjPlayer::get_hand_joint_position(s32 arg1) {
    this->get_anim_node_position(*(s32 *)((s8 *)(TObjPlayer__sub_801D8DCC()) + 0x10), (Vec *)arg1);
}

void TObjPlayer::calc_move(void* a1, void* a2) { vector_length(this); ((int (*)(void*, void*))calc_move_velocity__10TObjPlayerFPvPvf)(a1, a2); }

void calc_move_velocity__10TObjPlayerFPvPvf(void *arg0, void *arg1, f32 farg0) {
    f32 temp_f1;
    s32 temp_r31;

    temp_r31 = (s32) (lbl_80446F68 * atan2_float(*(f32 *)((s8 *)arg0 + 0), *(f32 *)((s8 *)arg0 + 8)));
    temp_f1 = farg0 * sin_table_lookup(temp_r31);
    *(f32 *)((s8 *)arg1 + 0) = temp_f1;
    *(f32 *)((s8 *)arg1 + 4) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg1 + 8) = (f32) (farg0 * ((f32 (*)(s32, f32))cos_table_lookup)(temp_r31, temp_f1));
}

#pragma push
#pragma fp_contract on
void TObjPlayer::calc_wall_slide_point(void *arg1, void *arg2) {
    f32 temp_f2;
    temp_f2 = -((f32 (*)(void))vec3_dot)();
    *(f32 *)((s8 *)arg2 + 0) = (f32) ((temp_f2 * *(f32 *)((s8 *)arg1 + 0)) + *(f32 *)((s8 *)this + 0));
    *(f32 *)((s8 *)arg2 + 4) = (f32) ((temp_f2 * *(f32 *)((s8 *)arg1 + 4)) + *(f32 *)((s8 *)this + 4));
    *(f32 *)((s8 *)arg2 + 8) = (f32) ((temp_f2 * *(f32 *)((s8 *)arg1 + 8)) + *(f32 *)((s8 *)this + 8));
}
#pragma pop

u8 *TObjPlayer::vfunc_18(u8 *arg1) {
    Stack_801B7998 stack;
    f32 temp_f1;
    s32 temp_r31;
    u8 *temp_r3;
    u8 *temp_r6;
    u8 *arg0 = (u8 *)this;
    stack.sp8 = *(f32 *)((s8 *)arg1 + 0);
    temp_r6 = (u8 *)(((TObjPlayer *)arg0)->m_2b0);
    temp_f1 = *(f32 *)((s8 *)arg1 + 4);
    stack.spC = temp_f1 + *(f32 *)((s8 *)temp_r6 + 0x10);
    stack.sp10 = *(f32 *)((s8 *)arg1 + 8);
    temp_r3 = (u8 *)(((u8 * (*)(f32 *, void *, s32, void *, f32))csnVectorUnder)(&stack.sp8, (u8 *)&this->m_120, 0x5F, temp_r6, temp_f1));
    if (temp_r3 == NULL) {
        return NULL;
    }
    TObjPlayer__sub_801BF8AC(((u8 *)&this->m_360));
    temp_r31 = *(s32 *)((s8 *)temp_r3 + 0);
    if (temp_r31 & 0x10) {
        ((TObjPlayer *)(arg0 + 0x360))->check_flag_2();
        copy_vec_at_18__10TObjPlayerFv((u8 *)&this->m_384, (void *) (*(u8 **)((s8 *)temp_r3 + 4) + 0x1C));
    }
    if ((temp_r31 & 4) && (player_auxiliary_surfaces_enabled() != 0)) {
        ((TObjPlayer *)(arg0 + 0x360))->set_flag_4();
        TObjPlayer__sub_801BF3A0((u8 *)&this->m_384, (void *) (*(u8 **)((s8 *)temp_r3 + 4) + 0x38));
    }
    if ((temp_r31 & 2) && (player_auxiliary_surfaces_enabled() != 0)) {
        TObjPlayer__sub_801BF840(((u8 *)&this->m_360));
        TObjPlayer__sub_801BF3A0((u8 *)&this->m_384, (void *) (*(u8 **)((s8 *)temp_r3 + 4) + 0x54));
    }
    if (temp_r31 & 8) {
        ((TObjPlayer *)(arg0 + 0x360))->test_flag_16();
    }
    if (!(temp_r31 & 1)) {
        return NULL;
    }
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 4);
    VecCopy((Vec *)(arg0 + 0x410), (const Vec *)(*(u8 **)((s8 *)temp_r3 + 4) + 0xC));
    return temp_r3;
}

u8 *TObjPlayer::update_actor_ground_y() {
    struct VObj_801B7AC8_801B3FD8 *o = (struct VObj_801B7AC8_801B3FD8 *)this;
    o->m16(get_position_ptr__10TObjPlayerFv());
}

void handle_6x99(void) {  }

void TObjPlayer::close_sub_window() {
    void *p;
    if (is_locally_controlled__10TObjPlayerFPv(this) != 0) {
        p = this->inventory_objects;
        if (p != 0) {
            TObjPlayer__sub_801D4368(p);
        }
    }
}

void handle_6x98(void) {  }

void TObjPlayer__sub_801B7B58(P_801B7B58 *arg0, s32 arg1, s32 arg2) {
    if (is_locally_controlled__10TObjPlayerFPv(arg0) == 0) {
        return;
    }
    if (arg1 == -1 || arg2 == -1) {
        return;
    }
    if (arg0->fD00 != 0) {
        TObjPlayer__sub_801D47EC(arg0->fD00, arg1, arg2);
    }
}

s32 can_destroy_with_parents__10TObjPlayerFUi(u32 arg0) {
    if ((arg0 != 0U) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0)) {
        return 1;
    }
    return 0;
}

s32 TWindowSubItem::is_usable(s32 arg0) {
    if ((is_action_active__10TObjPlayerFv() != 0U) || (test_action_mask__10TObjPlayerFl(arg0, 0x43001E) == 0) || (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x20) != 0) || (check_player_flag1__6TLobbyFv(arg0) != 0)) {
        return 0;
    }
    return 1;
}

s32 TObjPlayer::find_inventory_item_id(s8 arg1, s8 arg2) {
    struct ItemData_801B7C78 item;
    ((void (*)(void *))init__9TItemDataFv)(&item);
    item.kind = arg1;
    item.group = arg2;
    if (find_first_inventory_entry__10TObjPlayerFi(*(s32 *)((s8 *)((u8 *)this) + 0xD00), &item) == 0U) {
        return -1;
    }
    if (get_owner_if_alive__10TObjPlayerFv() == 0U) {
        return -1;
    }
    return get_item_id__5TItemFv();
}

s32 fn_801B7CEC(u8 *arg0, s8 arg1, s8 arg2, s8 arg3) {
    struct ItemData_801B7CEC item;
    ((void (*)(void *))init__9TItemDataFv)(&item);
    item.kind = arg1;
    item.group = arg2;
    item.sub = arg3;
    if (((u32 (*)(int, void *))set_mode_and_refresh_object__10TObjPlayerFPvi)(*(s32 *)((s8 *)arg0 + 0xD00), &item) == 0U) {
        return -1;
    }
    if (get_owner_if_alive__10TObjPlayerFv() == 0U) {
        return -1;
    }
    return get_item_id__5TItemFv();
}

void handle_6x28_feed_mag(s32 arg0) {
    Cmd_801B7D68 cmd;
    u8 *p;
    s32 a;
    s32 b;
    TObjPlayer__sub_801C0D7C((u8 *)&cmd);
    ((TObjPlayer *)(&cmd))->copy_pair_fields2((void *)arg0);
    ((TObjPlayer *)(&cmd))->bswap_body_dwords2();
    if (validate_6x28_feed_mag((G_ClientIDHeader *)&cmd) != 0) {
        p = ((u8 * (*)(u16))get_player_by_client_id)(cmd.client);
        if (p != NULL && ((u32 (*)(s32, u32))start_inventory_update__10TObjPlayerFi)(*(s32 *)((s8 *)p + 0xD00), cmd.item_a) != 0U) {
            a = ((s32 (*)(void))get_owner_if_alive__10TObjPlayerFv)();
            if (a != 0 && ((u32 (*)(s32, u32))start_inventory_update__10TObjPlayerFi)(*(s32 *)((s8 *)p + 0xD00), cmd.item_b) != 0U) {
                b = ((s32 (*)(void))get_owner_if_alive__10TObjPlayerFv)();
                if (b != 0) {
                    feed_item_to_mag((TItem *)a, (TItem *)b);
                }
            }
        }
    }
}

void send_6x28_feed_mag(void *arg0, s32 arg1, s32 arg2) {
    L_801B7E14 sp8;
    if (arg0 == 0 || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(arg0) == 0) {
        TObjPlayer__sub_801C0D7C((u8 *)&sp8);
        sp8.f2 = get_entity_id(arg0);
        sp8.f4 = arg1;
        sp8.f8 = arg2;
        ((TObjPlayer *)(&sp8))->bswap_and_send_body_dwords2();
    }
}

void TWindowSubMag::feed_mag(void* p, void* a1, void* a2) { ((int (*)(void*))send_6x28_feed_mag)(p); ((int (*)(void*, void*, void*))send_6x29_delete_item__10TObjPlayerFPvii)(p, a2, (void*)1); }

void handle_6x27_use_item(s32 arg0) {
    Pkt_801B7EB8 pkt;
    u8 *temp_r3;
    u8 *temp_r3_2;
    init_6x27_use_item_cmd((u8 *)&pkt);
    ((TObjPlayer *)(&pkt))->copy_field_4((void *)arg0);
    ((TObjPlayer *)(&pkt))->bswap_cmd_u32();
    if (validate_6x27_use_item((G_ClientIDHeader *)(&pkt)) != 0) {
        temp_r3 = ((u8 * (*)(u16))get_player_by_client_id)(pkt.client);
        if ((temp_r3 != NULL) && (((u32 (*)(int, int))start_inventory_update__10TObjPlayerFi)((int) (*(s32 *)((s8 *)temp_r3 + 0xD00)), pkt.item) != 0U)) {
            temp_r3_2 = ((u8 * (*)(void))get_owner_if_alive__10TObjPlayerFv)();
            if (temp_r3_2 != NULL) {
                ((VObj_801B7EB8 *)temp_r3_2)->m29();
            }
        }
    }
}

s32 try_send_6x27_use_item(void *player, s32 arg1) {
    struct S801B7F4C sp8;
    void *temp;
    if (((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() != 0) {
        return 0;
    }
    if (start_inventory_update__10TObjPlayerFi(*(s32 *)((s8 *)player + 0xD00), arg1) == 0U) {
        return 0;
    }
    temp = ((void * (*)(void))get_owner_if_alive__10TObjPlayerFv)();
    if (temp == NULL) {
        return 0;
    }
    if (((TObjPlayer *)player)->can_use_item(temp) == 0) {
        play_sound_effect(0x3816, 0, 0, 0);
        return 0;
    }
    if ((player != NULL) && (((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(player) != 0)) {
        return 0;
    }
    init_6x27_use_item_cmd((u8 *)&sp8);
    sp8.h = ((s16 (*)(void *))get_entity_id)(player);
    sp8.w = arg1;
    ((TObjPlayer *)(&sp8))->send_use_item_cmd();
    return 1;
}

void rebuild_player_inventory(void *arg0) {
    Buf_801B802C b;
    if ((u32) *(u32 *)((s8 *)arg0 + 0xD00) != 0U) {
        ((s32 (*)(s32 *))init_inventory_list__10TObjPlayerFPv)((s32 *)&b);
        b.n = ((s32 (*)(void *, s32 *))query_state_if_present__10TObjPlayerFPv)(arg0, (s32 *)b.ents);
        ((TObjPlayer *)(*(u32 *)((s8 *)arg0 + 0xD00)))->destroy_subobjects((int)arg0);
        queue_destruction__7TObjectFv(*(u32 *)((s8 *)arg0 + 0xD00));
        *(u32 *)((s8 *)arg0 + 0xD00) = 0U;
        ((TObjPlayer *)arg0)->create_inventory();
        assign_inventory_item_ids(arg0, (Ent_801B80C0 *)((Ent_801B80C0 *)b.ents), b.n);
        ((s32 (*)(void *, s32 *, s32))bind_saved_inventory_equipment__10TObjPlayerFPvPvi)(arg0, (s32 *)b.ents, b.n);
    }
}

void assign_inventory_item_ids(void *arg0, Ent_801B80C0 *arg1, s32 arg2) {
    s32 i;
    s16 v;
    if (arg1 != NULL) {
        v = ((s16 (*)(void *))get_entity_id)(arg0);
        for (i = 0; i < arg2; i++) {
            arg1->f14 = ((s32 (*)(s16))advance_item_id_counter)(v);
            arg1++;
        }
    }
}

void equip_saved_item_if_slot_empty__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1) {
    s32 temp_r3;
    temp_r3 = (s32)create_item((TItemData *)(arg1 + 8));
    if ((temp_r3 != 0) && (((u32 (*)(void *, void *))pickup_item__10TObjPlayerFP5TItem)(arg0, (void *) temp_r3) != 0) && (*(s32 *)((s8 *)arg1 + 4) & 8) && (((s32 (*)(void *, s32))get_slot_value__10TObjPlayerFPvi)(arg0 + 0xD04, (s32) ((VObj_18_e9153c *)(temp_r3))->m31()) == 0U)) {
        set_equip_slot_entry((s32)(arg0 + 0xD04), (s32) ((VObj_18_e9153c *)(temp_r3))->m31(), temp_r3);
        set_flag_20000__10TObjPlayerFi((s32) arg0);
        ((VObj_18_e9153c *)(temp_r3))->m18();
        TObjPlayer__sub_801BE9A8((s32) arg0);
    }
}

void bind_saved_inventory_equipment__10TObjPlayerFPvPvi(u8 *p, u8 *records, s32 count) {
    s32 i;
    if (records != NULL) {
        ((TObjPlayer *)p)->set_action_provider_variant((s16)(TObjPlayer__sub_801C2114()));
        for (i = 0; i < count; i++) {
            equip_saved_item_if_slot_empty__10TObjPlayerFPvPv(p, records);
            records += 0x1C;
        }
        if (are_items_enabled_here() == 0) {
            ((TObjPlayer *)p)->set_action_provider_variant((s16)(TObjPlayer__sub_801C2114()));
        }
    }
}

void TObjPlayer::create_inventory() {
    u8 *temp_r3;
    u8 *item_list;
    u8 *object;
    u8 *var_r0;
    u8 *var_r0_2;
    u8 *var_r0_3;
    if ((void *) this->inventory_objects == NULL) {
        temp_r3 = (u8 *)(((u8 * (*)(s32))__nw__7TObjectFUl)(0x1CC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TPlyItem__ct(temp_r3, this));
        }
        this->inventory_objects = var_r0;
    }
    item_list = (u8 *)(((u8 * (*)(s32))__nw__7TObjectFUl)(0x20));
    var_r0_2 = item_list;
    if (var_r0_2 != NULL) {
        var_r0_2 = (u8 *)(__ct__9TItemListFv(item_list, this->inventory_objects));
    }
    *(void **)((s8 *)this->inventory_objects + 0x1C4) = var_r0_2;
    object = (u8 *)(((u8 * (*)(s32))__nw__7TObjectFUl)(0x1C));
    var_r0_3 = object;
    if (var_r0_3 != NULL) {
        var_r0_3 = (u8 *)(__ct__7TObjectFP7TObject(object, this));
    }
    *(void **)((s8 *)this->inventory_objects + 0x1C8) = var_r0_3;
    TObjPlayer__sub_801BF8F8((s32 *)(((u8 *)this) + 0xD04));
}

s32 query_state_if_present__10TObjPlayerFPv(void *arg0) {
    void *temp_r3 = *(void **)((s8 *)arg0 + 0xD00);
    if (temp_r3 == NULL) {
        return 0;
    }
    return ((s32 (*)(void *))run_state_query__10TObjPlayerFi)(temp_r3);
}

void handle_6x2B_create_inventory_item(s32 arg0) {
    Pkt_801B8344 pkt;
    s32 player;
    s32 kind;
    u8 *item;
    ((TObjPlayer *)(&pkt))->init_pkt_6x2B();
    ((TObjPlayer *)(&pkt))->copy((void *)arg0);
    ((TObjPlayer *)(&pkt))->bswap_cmd_item_data();
    if (validate_6x2B_create_inventory_item((G_ClientIDHeader *)&pkt) != 0) {
        player = ((s32 (*)(int))get_player_by_client_id)(pkt.client);
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
            if ((item != NULL) && (((u32 (*)(int, int))pickup_item__10TObjPlayerFP5TItem)(player, (int)item) != 0U) && (kind == 2) && (pkt.f19 != 0) && (((u32 (*)(void *, void *))get_slot_value__10TObjPlayerFPvi)((void *)(player + 0xD04), (void *)(((VObj_18_p65 *)item)->m31())) == 0U)) {
                ((s32 (*)(void *, void *, int))set_equip_slot_entry)((void *)(player + 0xD04), (void *)(((VObj_18_p65 *)item)->m31()), (int)item);
                ((s32 (*)(int))set_flag_20000__10TObjPlayerFi)(player);
                ((VObj_18_p65 *)item)->m18();
                ((s32 (*)(int))TObjPlayer__sub_801BE9A8)(player);
            }
        }
    }
}

void TObjPlayer::request_inventory_item(TItemData* item) {
    TObjPlayer* player = this;
    InventoryCreatePacket_801B849C packet;
    if (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0) {
        if ((s32)item->id == -1) {
            item->id = ((u32 (*)(u16))advance_item_id_counter)((u16)local_client_id);
        }
        if (player == 0 || ((s32 (*)(TObjPlayer*))obj_isState2_324__13TUnk_804806E8Fv)(player) == 0) {
            ((TObjPlayer *)(&packet))->init_pkt_6x2B();
            packet.actor = ((u16 (*)(TObjPlayer*))get_entity_id)(player);
            ((TItemData *)(&packet.item))->copy_from((TItemData *)(item));
            ((TItemData *)&packet.item)->encode_for_network();
            ((TObjPlayer *)(&packet))->send_cmd_item_data();
        }
    }
}

extern "C" {
int TShopJudgmentItemWindow::get_item_record(void* p) { return ((int (*)(void*))send_6x29_delete_item__10TObjPlayerFPvii)(p); }

#pragma push
#pragma opt_propagation off
s32 TObjPlayer::try_add_sale_meseta(s32 arg1, s32 arg2, s32 arg3) {
    s32 max = 999999;
    if (max < ((Player_801B855C *)this)->data->meseta + arg2) {
        return 0;
    }
    ((TObjPlayer *)((Player_801B855C *)this))->add_meseta((s32)arg2);
    ((void (*)(void *, s32, s32))send_6x29_delete_item__10TObjPlayerFPvii)(((Player_801B855C *)this), arg1, arg3);
    return 1;
}
#pragma pop

s32 try_buy_item(s32 arg0, void *item) {
    if (((s32 (*)(void))can_pickup_item__10TObjPlayerFP9TItemData)() == 0) {
        return 1;
    }
    if (try_spend_actor_meseta((u8 *)arg0, *(s32 *)((s8 *)item + 0x10) * get_item_type_or_default__9TItemListFv(item)) != 0) {
        buy_item_for_client((TItemData *)item, ((u16 (*)(s32))get_entity_id)(arg0));
        return 0;
    }
    return 2;
}

void TObjPlayer::drop_items_on_death() {
    DeathDropRecord records[9];
    DeathDropRecord* record;
    s32 count;
    TItemData* item;
    void* equipped;
    PlayerDeathItemFields* fields=(PlayerDeathItemFields*)this;
    if (fields->inventory_owner==NULL || ((s32 (*)(TObjPlayer*))obj_isState3_324__13TUnk_804806E8Fv)(this)!=0 || is_script_controlled__10TObjPlayerFv(this)!=0) {
        return;
    }
    __construct_array(records,init_c2098_return_self__10TObjPlayerFv,NULL,sizeof(DeathDropRecord),9);
    count=0;
    if (((s32 (*)(void))is_technique_ready__8TTecCtrlFv)()!=0) {
        if (((s32 (*)(TObjPlayer*))check_flag_01000000__10TObjPlayerFPv)(this)==0) {
            count=((TLobby *)(fields->inventory_owner))->set_globals_and_notify((int)this, (int)records);
        }
        if (obj_getPtr2B0_20((u8 *)this)!=0) {
            record=&records[count];
            ((TObjPlayer *)record)->set_field4(-1);
            item=TObjPlayer__sub_801C2058(record);
            ((TObjPlayer *)item)->init_item_data((s32)((void*)obj_getPtr2B0_20((u8 *)this)));
            count+=1;
            item->id=-1;
        }
    } else if (((s32 (*)(TObjPlayer*))check_flag_01000000__10TObjPlayerFPv)(this)==0) {
        count=((TLobby *)(fields->inventory_owner))->set_globals_and_notify((int)this, (int)records);
    } else {
        equipped=((void* (*)(TObjPlayer*))get_item_field_6__10TObjPlayerFPv)(this);
        if (equipped!=NULL) {
            ((void (*)(TObjPlayer*, s32))send_6x26_unequip_item__10TObjPlayerFPvPv)(this,((s32 (*)(void*))get_item_id__5TItemFv)(equipped));
        }
    }
    if (count>0) {
        lbl_8050BF60.x=fields->position.x;
        lbl_8050BF60.y=TObjPlayer__data_805DC2BC+fields->position.y;
        lbl_8050BF60.z=fields->position.z;
        create_drop_nodes__9TItemListFPvPvPvPvi(fields->inventory_owner+0x20,&lbl_8050BF60,this,records,count);
        set_action_flag_2();
    }
}

void handle_6x2A_drop_item(void *arg0) {
    Msg_801B87E4 m;
    Player_801B87E4 *p;
    ((TObjPlayer *)(&m))->init_6x2A();
    TObjPlayer__sub_801C106C(&m, arg0);
    bswap_fields__10TObjPlayerFi(&m);
    if (validate_6x2A_drop_item((G_ClientIDHeader *)&m) != 0) {
        p = ((Player_801B87E4 * (*)(u16))get_player_by_client_id)(m.slot);
        if ((p != NULL) && (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0)) {
            ((TObjPlayer *)(p->inv))->update_inventory_item((s32)p, (s32)m.c, (s32)m.d, (s32)m.a, (s32)m.b);
        }
    }
}

void TObjPlayer::send_6x2A_drop_item(void *player, s32 arg1, void *arg2, s32 arg3) {
    Cmd_801B8870 cmd;
    if (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0 && (player == NULL || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(player) == 0)) {
        ((TObjPlayer *)(&cmd))->init_6x2A();
        cmd.client = ((s32 (*)(s32))get_entity_id)((s32)player);
        cmd.a = arg1;
        cmd.b = arg3;
        cmd.floor = ((s16 (*)(void))get_current_floor)();
        VecCopy((Vec *)&cmd.pos, (const Vec *)arg2);
        ((TObjPlayer *)(&cmd))->bswap_fields_and_send();
        ((TObjPlayer *)player)->send_unequip_held_item();
    }
}
}

struct Pkt_801B8908 { u16 f0; u16 client; s16 a; s16 b; };
s32 validate_6x83_place_trap(G_ClientIDHeader *packet);
extern "C" {
u32 create_placed_trap__10TOMineTrapFUiss(u8 *, s32, s32);

void handle_6x83_place_trap(void *arg0) {
    Pkt_801B8908 pkt;
    ((TObjPlayer *)(&pkt))->init_trap_packet();
    ((TObjPlayer *)(&pkt))->copy_short_fields(arg0);
    ((TObjPlayer *)(&pkt))->bswap_body_words();
    if (validate_6x83_place_trap((G_ClientIDHeader *)&pkt) != 0) {
        u8 *p = (u8 *) ((u32 (*)(int))get_player_by_client_id)(pkt.client);
        if (p != NULL && create_placed_trap__10TOMineTrapFUiss(p, pkt.a, pkt.b) != 0) {
            ((TObjPlayer *)(p + 0x7C4))->consume_trap_count(1, pkt.a);
            if (is_locally_controlled__10TObjPlayerFPv(p) != 0) {
                ((TWindowCtrl *)((u16)get_entity_id(p)))->call_window_method_with_default_vec();
            }
        }
    }
}

s8 clamp_char_at__10TObjPlayerFl(u8 *, s32);
s32 TWindowCtrl__sub_8024A228(u16);

s32 TObjPlayer::send_trap_packet(int arg1_) {
    s32 arg1 = arg1_;
    u8 *arg0 = (u8 *)this;
    Pkt_801B8908 pkt;

    if (arg0 != NULL && obj_isState2_324__13TUnk_804806E8Fv() != 0) {
        return 0;
    }
    if (TWindowCtrl__sub_8024A228((u16)get_entity_id(arg0)) == 0) {
        return 0;
    }
    if (((s32 (*)(void *))is_action_available__10TObjPlayerFi)(arg0) == 0) {
        return 0;
    }
    if (clamp_char_at__10TObjPlayerFl((u8 *)&this->m_7c4, arg1) <= 0) {
        return 0;
    }
    ((TObjPlayer *)(&pkt))->init_trap_packet();
    pkt.client = (u16)get_entity_id(arg0);
    pkt.a = arg1;
    pkt.b = clamp_char_at__10TObjPlayerFl((u8 *)&this->m_7c4, arg1);
    ((TObjPlayer *)(&pkt))->bswap_body_words_and_send();
    return 1;
}

void TObjPlayer::request_meseta_drop(s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_801B8A80, sp8) == 0x0) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_801B8A80, sp14) == 0xC) ? 1 : -1];
    Stack_801B8A80 stack;
    if (arg1 > 0) {
        ((s32 (*)(void *, int))play_effect_default__10TObjPlayerFii)(this, 0x384);
        set_action_flag_2();
        ((TObjPlayer *)(&stack.sp8))->init_item_data(arg1);
        stack.sp14 = -1;
        insert_item_node__10TObjPlayerFiiiii((int) (*(s32 *)((s8 *)((u8 *)this) + 0xD00) + 0x20), (void *) (TObjPlayer__sub_801BF914((void *) (((u8 *)this) + 0x84C))), this, &stack.sp8, -1);
    }
}

void TObjPlayer::request_item_drop(s32 arg1, s32 arg2) {
    Item_801B8AF8 item;
    VObj_801B8AF8 *owner;
    s32 id;
    if (check_player_action_allowed() != 0 &&
        (TAdPlayerLoadGC__sub_801E1B50(get_chr_select_state__23TAdSinglePlyChrSelectGCFv()) != 0 ||
         ((TAdPlayerLoadGC *)(get_chr_select_state__23TAdSinglePlyChrSelectGCFv()))->probe_card_slot() != 1)) {
        ((void (*)(s32, s32, s32, s32))play_sound_effect)(0x53F06, 0, 0, 0);
        return;
    }
    if (start_inventory_update__10TObjPlayerFi(*(s32 *)(((u8 *)this) + 0xD00), arg1) == 0) {
        return;
    }
    owner = ((VObj_801B8AF8 * (*)(void))get_owner_if_alive__10TObjPlayerFv)();
    if (owner == NULL) {
        return;
    }
    ((s32 (*)(void *, int))play_effect_default__10TObjPlayerFii)(this, 0x384);
    set_action_flag_2();
    ((TItem *)owner)->copy_to_item_data((TItemData *)&item);
    set_stack_count__24TShopEquipmentListWindowFSc(&item, arg2);
    id = item.id;
    if (owner->m34() - arg2 > 0) {
        item.id = -1;
    }
    insert_item_node__10TObjPlayerFiiiii(*(s32 *)(((u8 *)this) + 0xD00) + 0x20, (void *)TObjPlayer__sub_801BF914(((u8 *)this) + 0x84C), this, &item, id);
}

s32 TObjPlayer::count_items_of_type(s8 arg1, s8 arg2, s8 arg3) {
    TItemData item_data;
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0xD00) == 0U) {
        return 0;
    }
    ((s32 (*)(void *))init__9TItemDataFv)(&item_data.data1.data_u8[0]);
    item_data.data1.data_u8[0] = arg1;
    item_data.data1.data_u8[1] = arg2;
    item_data.data1.data_u8[2] = arg3;
    return ((TObjPlayer *)(*(u32 *)((s8 *)((u8 *)this) + 0xD00)))->count_items_by_id((s32)&item_data.data1.data_u8[0]);
}

void dispatch_input__10TObjPlayerFPvii(void *player, s32 arg1, s32 arg2) {
    TObjPlayer__sub_801D49F4(*(s32 *)((s8 *)player + 0xD00), player, arg1, arg2, player);
}

void handle_6xAC(void *arg0) {
    L_801B8CB0 sp8;
    ((TObjPlayer *)(&sp8))->init_6xAC_packet();
    TObjPlayer__sub_801C1268(&sp8, arg0);
    ((TObjPlayer *)(&sp8))->byteswap_data();
    if (validate_6xAC((G_ClientIDHeader *)&sp8) != 0) {
        s32 p = ((s32 (*)(s32))get_player_by_client_id)(sp8.f2);
        if (p != 0 && ((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() == 0) {
            ((void (*)(void *, void *, s32))dispatch_input__10TObjPlayerFPvii)((void *)p, sp8.f8, sp8.f4);
        }
    }
}

void TObjPlayer::dispatch_action(s32 arg1, s32 arg2) {
    use_item__6TLobbyFlll(*(s32 *)((s8 *)this + 0xD00), this, arg1, arg2, this);
}

void handle_6x29_delete_inventory_item(void *arg0) {
    L_801B8D68 sp8;
    ((TObjPlayer *)(&sp8))->init_cmd_6x29();
    ((TObjPlayer *)(&sp8))->copy_pair_fields3(arg0);
    ((TObjPlayer *)(&sp8))->bswap_body_dwords3();
    if (validate_6x29_delete_inventory_item((G_ClientIDHeader *)&sp8) != 0) {
        s32 p = ((s32 (*)(s32))get_player_by_client_id)(sp8.f2);
        if (p != 0 && ((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() == 0) {
            ((TObjPlayer *)p)->dispatch_action(sp8.f4, sp8.f8);
        }
    }
}

void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b) {
    Cmd_801B8DE8 cmd;
    if (((s32 (*)(void))is_volopt_phase_final__10TObjPlayerFv)() != 0) {
        return;
    }
    if (obj != 0 && ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(obj) != 0) {
        return;
    }
    ((TObjPlayer *)(&cmd))->init_cmd_6x29();
    cmd.id = ((s16 (*)(void *))get_entity_id)(obj);
    cmd.a = a;
    cmd.b = b;
    ((TObjPlayer *)(&cmd))->bswap_body_dwords3_and_send();
    ((TObjPlayer *)obj)->send_unequip_held_item();
}

void *pickup_item__10TObjPlayerFP5TItem(u8 *player, u8 *arg1) {
    u32 sp8[5];
    s32 id;
    void *o;
    void *list;
    s32 n;
    VObj_18_p72 *owner;
    u8 *inv;
    s16 idx;
    if (arg1 == NULL) {
        return 0;
    }
    if (get_item_type__5TItemFv(arg1) == 4) {
        ((TObjPlayer *)player)->add_meseta((s32)((void *)((TItem *)arg1)->calc_price()));
        ((s32 (*)(void *, void *))TObjPlayer__sub_801B0124)(player, (void *)((TItem *)arg1)->calc_price());
        ((TItem *)arg1)->destroy();
        ((s32 (*)(void *, int))send_field_state_if_active__10TObjPlayerFP10TObjPlayerl)(player, 0x52802);
        return 0;
    }
    if (((s32 (*)(void *, void *))can_pickup_item_by_id__10TObjPlayerFP5TItem)(player, arg1) == 0) {
        return 0;
    }
    ((void (*)(void *))TObjPlayer__sub_801C1B0C)(arg1);
    list = 0;
    switch (get_item_type__5TItemFv(arg1)) {
    case 0:
    case 1:
    case 2:
        o = ((void * (*)(u32))__nw__7TObjectFUl)(0x20);
        if (o != NULL) {
            o = ((void * (*)(void *, s32))__ct__9TItemListFv)(o, *(s32 *)((s8 *)(((TObjPlayer *)player)->inventory_objects) + 0x1C4));
        }
        list = o;
        break;
    case 3:
        if (TObjPlayer__sub_801C1AC8(arg1) != 0) {
            ((TItem *)arg1)->copy_to_item_data((TItemData *)&sp8);
            id = ((s32 (*)(void *, void *))set_mode_and_refresh_object__10TObjPlayerFPvi)(((TObjPlayer *)player)->inventory_objects, &sp8);
            if (id == 0) {
                o = ((void * (*)(u32))__nw__7TObjectFUl)(0x20);
                if (o != NULL) {
                    o = ((void * (*)(void *, s32))__ct__9TItemListFv)(o, *(s32 *)((s8 *)(((TObjPlayer *)player)->inventory_objects) + 0x1C4));
                }
                list = o;
                break;
            }
            n = ((TItem *)arg1)->get_amount();
            if (n == 0) {
                n = 1;
            }
            owner = ((VObj_18_p72 * (*)(s32))get_owner_if_alive__10TObjPlayerFv)(id);
            if (owner != NULL) {
                owner->m36(n);
            }
            ((TItem *)arg1)->destroy();
            return 0;
        }
        o = ((void * (*)(u32))__nw__7TObjectFUl)(0x20);
        if (o != NULL) {
            o = ((void * (*)(void *, s32))__ct__9TItemListFv)(o, *(s32 *)((s8 *)(((TObjPlayer *)player)->inventory_objects) + 0x1C4));
        }
        list = o;
        break;
    }
    if (list != NULL) {
        set_field_1c__10TObjPlayerFl(list, arg1);
        inv = *(u8 * *)&((TObjPlayer *)player)->inventory_objects;
        TObjPlayer__sub_801C1B0C(arg1, (*(s16 *)((s8 *)inv + 0x1C))++);
        ((TItem *)arg1)->set_mode(1);
        ((TObject *)arg1)->set_parent((TObject *)(*(void **)((s8 *)(((TObjPlayer *)player)->inventory_objects) + 0x1C8)));
        set_owner_client__5TItemFUs(arg1, ((s16 (*)(void *))get_entity_id)(player));
        return list;
    }
    return 0;
}

s32 can_pickup_item__10TObjPlayerFP9TItemData(void *arg0, u8 *item_data) {
    s32 temp_r31;
    s32 temp_r31_2;
    void *held;

    if (lookup_item_def__9TItemDataFPv(item_data) != 0) {
        if ((u8) *item_data == 4) {
            return obj_getPtr2B0_20((u8 *)arg0) < 0xF423F;
        }
        if (((u32 (*)(void *, u8 *))set_mode_and_refresh_object__10TObjPlayerFPvi)(*(void **)((s8 *)arg0 + 0xD00), item_data) != 0U) {
            held = ((void * (*)(void))get_owner_if_alive__10TObjPlayerFv)();
            if (held == NULL) {
                return 0;
            }
            temp_r31_2 = ((TItem *)held)->get_max_stack_size();
            temp_r31 = temp_r31_2 - ((V_B *)held)->m34();
            return ((s32) ((u32 (*)(u8 *))get_item_type_or_default__9TItemListFv)(item_data) <= temp_r31) ? 1 : 0;
        }
        goto block_7;
    }
block_7:
    if ((s16) *(s16 *)((s8 *)(*(void **)((s8 *)arg0 + 0xD00)) + 0x1C) >= 0x1E) {
        return 0;
    }
    return 1;
}

void can_pickup_item_by_id__10TObjPlayerFP5TItem(s32 arg0, s32 arg1) {
    s32 item_data[5];

    ((TItem *)arg1)->copy_to_item_data((TItemData *)item_data);
    can_pickup_item__10TObjPlayerFP9TItemData((void *)arg0, (u8 *)item_data);
}

s32 TObjPlayer::can_inventory_accept_item(u8 *item) {
    s32 max;
    s32 n;
    VObj_801B91F0 *owner;
    if (lookup_item_def__9TItemDataFPv(item) != 0) {
        if (item[0] == 4) {
            return 1;
        }
        if (((u32 (*)(Inv_801B91F0 *, u8 *))set_mode_and_refresh_object__10TObjPlayerFPvi)(((Player_801B91F0 *)this)->inv, item) == 0) {
            if (((Player_801B91F0 *)this)->inv->count >= 30) {
                return 0;
            }
            return ((TItemData *)item)->get_max_stack_size();
        }
        owner = ((VObj_801B91F0 * (*)(void))get_owner_if_alive__10TObjPlayerFv)();
        if (owner == NULL) {
            return 0;
        }
        n = ((TItem *)owner)->get_max_stack_size();
        n -= owner->m34();
        max = ((s32 (*)(u8 *))get_item_type_or_default__9TItemListFv)(item);
        return (n < max) ? 0 : n;
    }
    return ((Player_801B91F0 *)this)->inv->count < 30;
}

#pragma push
#pragma fp_contract on
bool TObjPlayer::is_target_in_facing_cone(void *target_arg) {
    Vec_801B92EC *target = (Vec_801B92EC *)target_arg;
    Vec_801B92EC to;
    Vec_801B92EC fwd = lbl_80446F2C;
    f32 x;
    f32 z;
    f32 dot;
    fwd.x = sin_table_lookup(((Obj_801B92EC *)this)->angle);
    fwd.y = TObjPlayer__data_805DC278;
    fwd.z = cos_table_lookup(((Obj_801B92EC *)this)->angle);
    x = TObjPlayer__data_805DC2BC * sin_table_lookup(((Obj_801B92EC *)this)->angle + 0x8000) + ((Obj_801B92EC *)this)->pos.x;
    z = TObjPlayer__data_805DC2BC * cos_table_lookup(((Obj_801B92EC *)this)->angle + 0x8000) + ((Obj_801B92EC *)this)->pos.z;
    to.x = target->x - x;
    to.y = TObjPlayer__data_805DC278;
    to.z = target->z - z;
    ((TObjBoss2Tunnel *)(&to))->update_scale();
    dot = ((f32 (*)(Vec_801B92EC *, Vec_801B92EC *))vec3_dot)(&fwd, &to);
    return !(dot < cos_table_lookup(0x1555));
}
#pragma pop

s32 TObjPlayer::update_target_lock() {
    f32 lock_target_distance_sq;
    u32 temp_r3;
    u16 lock_target_id;

    temp_r3 = this->m_424;
    if (temp_r3 == 0U) {
        return 0;
    }
    lock_target_id = get_lock_target_id((void *)(temp_r3 + 0x510));
    lock_target_distance_sq = get_lock_target_distance_sq(this->m_424 + 0x510, this->m_424);
    fn_801C1B88((void *)(this->m_424 + 0x510));
    if (!(this->actorFlags & 0x100000)) {
        if ((u16) lock_target_id == 0xFFFF) {
            return 0;
        }
        if (((u32 (*)(u16))find_entity_by_id)(lock_target_id) == 0U) {
            return 0;
        }
        if (!(lock_target_distance_sq < lbl_805DC2C0)) {
            goto block_17;
        }
        if (((s32 (*)(void *, s32))is_target_in_facing_cone__10TObjPlayerFPv)(this, get_position_ptr__10TObjPlayerFv()) == 0) {
            goto block_17;
        }
        this->actorFlags = (s32) (this->actorFlags | 0x100000);
        return 1;
    }
    if ((u16) lock_target_id == 0xFFFF) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFEFFFFF);
        return 0;
    }
    if (((u32 (*)(u16))find_entity_by_id)(lock_target_id) == 0U) {
        return 0;
    }
    if (lock_target_distance_sq > lbl_805DC2C4) {
        goto clear_and_return;
    }
    if (((s32 (*)(void *, s32))is_target_in_facing_cone__10TObjPlayerFPv)(this, get_position_ptr__10TObjPlayerFv()) != 0) {
        goto block_17;
    }
clear_and_return:
    this->actorFlags = (s32) (this->actorFlags & 0xFFEFFFFF);
    return 0;
block_17:
    return 0;
}

void TObjPlayer::get_anim_node_position(s32 arg1, Vec *arg2) {
    Stack_801B9544 stack;
    s32 arg0 = (s32)this;
    stack.sp10 = TObjPlayer__data_805DC278;
    stack.spC = TObjPlayer__data_805DC278;
    stack.sp8 = TObjPlayer__data_805DC278;
    push_matrix_from(0);
    TObjPlayer::copy_matrix((u32)(0), (u32)((void *) (((TObjMotion *)arg0)->get_item_ptr(arg1))));
    TCameraCtrl::concat_matrix(0, (int) (TCameraCtrl::get_view_matrix()));
    matrix_mult_vec(0, &stack.sp8, (void *)arg2);
    pop_matrix();
}

void TObjPlayer::use_current_item() {
    s32 sp8;
    void *temp_r3;

    temp_r3 = test_flag3__9TItemDataFv(this);
    if (temp_r3 != NULL) {
        ((TItem *)temp_r3)->perform_action();
        return;
    }
    this->get_anim_node_position(0x24, (Vec *)&sp8);
    TEffGuard::create((const Vec*)(&sp8));
}

void TObjPlayer::send_unequip_held_item() {
    Cmd_801B9634 cmd;
    s32 item;
    u32 arg0 = (u32)this;
    item = ((s32 (*)(void *))get_item_field_6__10TObjPlayerFPv)((void *)arg0);
    if ((item != 0) && (((s32 (*)(s32, u32, s32))check_equip_requirements__5TItemFP10TObjPlayerPs)(item, arg0, 0) == 0) && ((arg0 == 0U) || (((s32 (*)(u32))obj_isState2_324__13TUnk_804806E8Fv)(arg0) == 0))) {
        ((TObjPlayer *)(&cmd))->init_cmd_6x26();
        cmd.client = ((s16 (*)(u32))get_entity_id)(arg0);
        cmd.val = ((s32 (*)(s32))get_item_id__5TItemFv)(item);
        ((TObjPlayer *)(&cmd))->bswap_body_dwords4_and_send();
    }
}

#pragma push
#pragma fp_contract on
s32 preview_unequip_stats__10TObjPlayerFv(Self_801B96BC *self, Out_801B96BC *out, s32 arg2) {
    u8 a[0x34];
    Stats_801B96BC c;
    u8 b[0x20];
    VObj_801B96BC *owner;
    s32 i;
    s32 base;
    f32 k;
    s16 d;
    if (start_inventory_update__10TObjPlayerFi(self->fD00, arg2) == 0U) {
        return 0;
    }
    owner = ((VObj_801B96BC *)get_owner_if_alive__10TObjPlayerFv());
    if (owner == NULL) {
        return 0;
    }
    if (is_item_equipped((int)owner) == 0 && ((TObjPlayer *)self)->get_equipped_item(owner->m31()) == NULL) {
        return 1;
    }
    ((TLobby *)a)->copy_from((void *)self->f318);
    ((TLobby *)b)->copy_entry((void *)self->f31C);
    copy_data__6TLobbyFPvPv(&c, self->f2B0);
    owner->m23(a, b, &c);
    if (get_item_type__5TItemFv(owner) == 1 && ((TItem *)owner)->get_item_group() == 1) {
        for (i = 9; i <= 12; i++) {
            VObj_801B96BC *s = ((VObj_801B96BC *)get_slot_value__10TObjPlayerFPvi(self->fD04, i));
            if (s != NULL) {
                s->m23(a, b, &c);
            }
        }
    }
    set_params__10TObjPlayerFPvPvPviPv((void *)out, (void *)self, &c, (int)a, (int)b);
    k = TObjPlayer__sub_800192C4(self, 2);
    i = c.atp;
    {
        s16 sl = i;
        base = (s32)((f32)sl * k + (f32)(sl + (s16)get_attack_params_atp_min(a)));
    }
    d = get_attack_params_atp_max(a) - get_attack_params_atp_min(a);
    out->a = base + (s32)((f32)d * k + (f32)d);
    {
        f32 k2 = TObjPlayer__sub_800192C4(self, 3);
        out->b = (f32)out->b * k2 + (f32)out->b;
    }
    return 2;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 preview_equip_stats__10TObjPlayerFv(u8 *arg0, s16 *out, u8 *incoming) {
    Base_801B9954 b;
    Attack_801B9954 a;
    Defense_801B9954 d;
    Item_801B9954 *prev;
    s32 slot;
    s32 atp;
    f32 rate;
    if (incoming != NULL && out != NULL) {
    prev = NULL;
    copy_data__6TLobbyFPvPv(&b, (s32)(*(void **)(arg0 + 0x2B0)));
    ((TLobby *)(&a))->copy_from(*(void **)(arg0 + 0x318));
    ((TLobby *)(&d))->copy_entry(*(void **)(arg0 + 0x31C));
    switch (incoming[0]) {
    case 0:
        prev = ((Item_801B9954 *)get_item_field_6__10TObjPlayerFPv((Pl_801B0B88 *)(arg0)));
        break;
    case 1:
        if (incoming[1] == 1) {
            prev = get_item_field_2__9TItemDataFv(arg0);
        } else if (incoming[1] == 2) {
            prev = ((Item_801B9954 *)test_flag3__9TItemDataFv(arg0));
        }
        break;
    case 2:
        prev = ((Item_801B9954 *)activate_d04_slot__10TObjPlayerFv(arg0));
        break;
    }
    if (prev != NULL) {
        prev->subtract_applied(&a, &d, &b);
        if (get_item_type__5TItemFv(prev) == 1 && ((TItem *)prev)->get_item_group() == 1) {
            for (slot = 9; slot <= 12; slot++) {
                Item_801B9954 *unit = ((Item_801B9954 *)get_slot_value__10TObjPlayerFPvi(arg0 + 0xD04, slot));
                if (unit != NULL) {
                    unit->subtract_applied(&a, &d, &b);
                }
            }
        }
    }
    ((TItemData *)incoming)->apply_equip_effects((s32)arg0, (s32)&a, (s32)&d, (s32)&b, 0);
    b.field[0] = clamp_s32(b.field[0], 0, ((s16 *)get_class_stat_entry__10TObjPlayerFPUc(arg0))[0]);
    b.field[1] = clamp_s32(b.field[1], 0, ((s16 *)get_class_stat_entry__10TObjPlayerFPUc(arg0))[1]);
    b.field[2] = clamp_s32(b.field[2], 0, ((s16 *)get_class_stat_entry__10TObjPlayerFPUc(arg0))[2]);
    b.field[4] = clamp_s32(b.field[4], 0, ((s16 *)get_class_stat_entry__10TObjPlayerFPUc(arg0))[4]);
    b.field[5] = clamp_s32(b.field[5], 0, ((s16 *)get_class_stat_entry__10TObjPlayerFPUc(arg0))[5]);
    b.field[6] = clamp_s32(b.field[6], 0, ((s16 *)get_class_stat_entry__10TObjPlayerFPUc(arg0))[6]);
    set_params__10TObjPlayerFPvPvPviPv(out, arg0, (void *)&b, (int)&a, (int)&d);
    rate = TObjPlayer__sub_800192C4(arg0, 2);
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
    rate = TObjPlayer__sub_800192C4(arg0, 3);
    out[1] = (s32)((f32)out[1] * rate + (f32)out[1]);
    return 1;
    }
    return 0;
}
#pragma pop

void TObjPlayer::unequip_all_units() {
    s32 arg0 = (s32)this;
    s32 var_r31;
    void *temp_r3;

    var_r31 = 9;
    do {
        temp_r3 = ((void * (*)(s32, s32))get_slot_value__10TObjPlayerFPvi)(arg0 + 0xD04, var_r31);
        if (temp_r3 != NULL) {
            ((s32 (*)(s32, s32, s32))set_equip_slot_entry)(arg0 + 0xD04, var_r31, 0);
            ((VObj_801B9CE0*)temp_r3)->m19();
        }
        var_r31 += 1;
    } while (var_r31 <= 0xC);
}

void unequip_item__10TObjPlayerFiPv(s32 arg0, void *arg1) {
    VObj_801B9D50 *self = (VObj_801B9D50 *)arg1;

    ((s32 (*)(s32, s8, s32))set_equip_slot_entry)(arg0 + 0xD04, self->m31(), 0);
    self->m19();
    if ((get_item_type__5TItemFv(arg1) == 1) && (((TItem *)arg1)->get_item_group() == 1)) {
        ((TObjPlayer *)arg0)->unequip_all_units();
    }
    if (test_action_mask__10TObjPlayerFl(arg0, 2) != 0) {
        set_animation__10TObjMotionFs(arg0, ((s32 (*)(s32))unequip_by_field326__10TObjPlayerFPv)(arg0));
    }
}

void handle_6x26_unequip_item(void *arg0) {
    Msg_801B9E0C m;
    Player_801B9E0C *p;
    void *o;
    ((TObjPlayer *)(&m))->init_cmd_6x26();
    ((TObjPlayer *)(&m))->copy_unequip_fields(arg0);
    ((TObjPlayer *)(&m))->bswap_body_dwords4();
    if (validate_6x26_unequip_item((G_ClientIDHeader *)&m) != 0) {
        p = ((Player_801B9E0C * (*)(u16))get_player_by_client_id)(m.slot);
        if ((p != NULL) && (((u32 (*)(void *, s32))start_inventory_update__10TObjPlayerFi)(p->inv, m.c) != 0U) && ((o = ((void * (*)(void))get_owner_if_alive__10TObjPlayerFv)()) != NULL)) {
            ((void (*)(void *, void *))unequip_item__10TObjPlayerFiPv)(p, o);
        }
    }
}

void *TObjPlayer::copy_unequip_fields(void *arg1) {
    TFontSmallLobby__sub_801C0228();
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    return this;
}

void send_6x26_unequip_item__10TObjPlayerFPvPv(void *self, void *item) {
    if (self == 0 || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(self) == 0) {
        Cmd_801B9EDC cmd;
        ((TObjPlayer *)(&cmd))->init_cmd_6x26();
        cmd.id = ((u16 (*)(void *))get_entity_id)(self);
        cmd.item = item;
        ((TObjPlayer *)(&cmd))->bswap_body_dwords4_and_send();
        ((TObjPlayer *)self)->send_unequip_held_item();
    }
}

void TObjPlayer::equip_item_to_slot(void *item, s32 slot) {
    Player_801B9F40 *p = (Player_801B9F40 *)this;
    void *cur;
    if (is_state_ec1_ed3__10TObjPlayerFv(item) != 0) {
        if (slot < 9 || slot > 12) {
            slot = 9;
        }
        ((VObj_801B9F40 *)item)->m17((s8)slot);
    } else {
        slot = ((VObj_801B9F40 *)item)->m31();
    }
    cur = ((void * (*)(void *, s32))get_slot_value__10TObjPlayerFPvi)(p->slots, slot);
    if (cur == NULL) {
        ((void (*)(void *, s32, void *))set_equip_slot_entry)(p->slots, slot, item);
        ((VObj_801B9F40 *)item)->m18();
    } else if (cur != item) {
        ((void (*)(void *, void *))unequip_item__10TObjPlayerFiPv)(this, cur);
        ((void (*)(void *, s32, void *))set_equip_slot_entry)(p->slots, slot, item);
        ((VObj_801B9F40 *)item)->m18();
    }
    if (((s32 (*)(void *, int))test_action_mask__10TObjPlayerFl)(this, 2) != 0) {
        ((void (*)(void *, s16))set_animation__10TObjMotionFs)(this, ((s16 (*)(void *))unequip_by_field326__10TObjPlayerFPv)(this));
    }
}

void handle_6x25_equip_item(void *arg0) {
    Msg_801BA060 m;
    Player_801BA060 *p;
    void *o;
    ((TObjPlayer *)(&m))->init_command();
    ((TObjPlayer *)(&m))->copy_pair_fields4(arg0);
    ((TObjPlayer *)(&m))->bswap_body_dwords5();
    if (validate_6x25_equip_item((G_ClientIDHeader *)&m) != 0) {
        p = ((Player_801BA060 * (*)(u16))get_player_by_client_id)(m.slot);
        if ((p != NULL) && (((u32 (*)(void *, s32))start_inventory_update__10TObjPlayerFi)(p->inv, m.c) != 0U) && ((o = ((void * (*)(void))get_owner_if_alive__10TObjPlayerFv)()) != NULL)) {
            ((TObjPlayer *)p)->equip_item_to_slot(o, m.d);
        }
    }
}

void send_6x25_equip_item(void *arg0, s32 arg1, s32 arg2) {
    L_801BA0F0 sp8;
    if (((s32 (*)(void))check_switch_available__6TLobbyFPvi)() != 0 && (arg0 == 0 || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(arg0) == 0)) {
        ((TObjPlayer *)(&sp8))->init_command();
        sp8.f2 = ((u16 (*)(void *))get_entity_id)(arg0);
        sp8.f4 = arg1;
        sp8.f8 = arg2;
        ((TObjPlayer *)(&sp8))->bswap_body_dwords5_and_send();
    }
}

void TObjPlayer::handle_state2_transitions() {
    s16 temp_r0;
    u8 *arg0 = (u8 *)this;

    sub_8011E204__10TObjPlayerFl(arg0, 0x10);
    temp_r0 = ((TObjPlayer *)arg0)->m_324;
    switch (temp_r0) {
    case 1:
        if ((get_main_phase() != 0xE) && ((s32) lbl_805D55C0 != 0)) {
            goto call3;
        }
        ((TObjPlayer *)arg0)->select_contextual_pickup_action();
        ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 7);
        if (((TObjPlayer *)arg0)->check_flag_48() != 0) {
            break;
        }
        ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 2);
        if (((TObjPlayer *)arg0)->check_flag_48() != 0) {
            break;
        }
call3:
        ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 3);
        break;
    case 2:
        if ((((s32 (*)(void *))is_on_current_floor__10TObjPlayerFi)(arg0) == 0) && (check_flag_4__10TObjPlayerFv(arg0) == 0)) {
            ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0x16, 0);
            return;
        }
        if ((TObjPlayer__sub_801BF918((u8 *)&this->m_634) != 0) && (((s32 (*)(void *))test_flag_2000000__10TObjPlayerFPv)(arg0) != 0) && (((s32 (*)(void *, s32))test_action_mask__10TObjPlayerFl)(arg0, 4) != 0)) {
            set_flag_400000__10TObjPlayerFi(arg0);
            ((TObjPlayer *)(arg0 + 0x634))->enter_battle_state();
        }
        ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 8);
        return;
    case 3:
    case 6:
        ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 7);
        if (((TObjPlayer *)arg0)->check_flag_48() == 0) {
            ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 3);
        }
        break;
    }
}

s32 try_apply_status_action__10TObjPlayerFi(s32 arg0) {
    if (((s32 (*)(void))check_flag30_bit20__10TObjPlayerFi)() != 0) {
        ((s32 (*)(s32, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0x13, 5);
        return 1;
    }
    if (((TObjPlayer *)arg0)->is_status_flag_200() != 0) {
        if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x400) != 0) {
            ((s32 (*)(s32, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xE, 5);
        } else {
            ((s32 (*)(s32, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xD, 5);
        }
        return 1;
    }
    if (can_guard__10TObjPlayerFPv((u8 *)arg0) != 0) {
        ((s32 (*)(s32, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xA, 5);
        return 1;
    }
    if (((TObjPlayer *)arg0)->is_status_locked() != 0) {
        if (((TObjPlayer *)(arg0 + 0x5F0))->get_action_id() == 0x10) {
            ((s32 (*)(s32, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0x10, 5);
        } else {
            ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)0x10000);
            ((s32 (*)(s32, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)(arg0 + 0x5F0))->get_action_id(), 5);
            ((s32 (*)(s32, s32))set_action_id__10TObjPlayerFs)(arg0 + 0x5F0, 0);
        }
        return 1;
    }
    return 0;
}

void TObjPlayer__sub_801BA42C(void) {
    ((s32 (*)(void *))foreach_player__10TObjPlayerFv)(&TObjPlayer__sub_801BEABC.value);
    release_all_players_control_lock();
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

void TObjPlayer::freeze_all_players() {
    ((s32 (*)(s32 *))foreach_player__10TObjPlayerFv)(&start_freeze_self__10TObjPlayerFv.value);
}

s32 TObjPlayer::start_camera_pan(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x320) & 0x1E000) {
        return 0;
    }
    if ((s16) this->mode == arg1) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    ((s32 (*)(void *))set_action_id__10TObjPlayerFs)(arg0 + 0x5F0);
    ((s32 (*)(void *, s16))set_anim_state__10TObjPlayerFs)(arg0 + 0x5F0, this->m_b8);
    ((TObjPlayer *)(arg0 + 0x5F0))->set_state(0);
    ((TObjPlayer *)(arg0 + 0x5F0))->set_anim_state(this->rotation_y);
    return 1;
}

s32 TObjPlayer::init_photon_blast(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x320) & 0x1E000) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    set_action_id__10TObjPlayerFs((u8 *)&this->m_5f0, 0x10);
    set_anim_state__10TObjPlayerFs((u8 *)&this->m_5f0, arg1);
    ((TObjPlayer *)(arg0 + 0x5F0))->set_state(0);
    ((TObjPlayer *)(arg0 + 0x5F0))->set_anim_state(this->rotation_y);
    return 1;
}

s32 TObjPlayer::start_freeze() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x320) & 0x1E000) {
        return 0;
    }
    this->actorFlags = (s32) (this->actorFlags | 0x10000);
    set_action_id__10TObjPlayerFs((u8 *)&this->m_5f0, 0x10);
    set_anim_state__10TObjPlayerFs((u8 *)&this->m_5f0, ((TObjPlayer *)arg0)->get_idle_animation());
    ((TObjPlayer *)(arg0 + 0x5F0))->set_state(0);
    ((TObjPlayer *)(arg0 + 0x5F0))->set_anim_state(this->rotation_y);
    return 1;
}

void set_action_state__10TObjPlayerFPvss(void *arg0, s16 arg1, s16 arg2) {
    *(s16 *)((s8 *)arg0 + 0x32A) = (s16) *(s16 *)((s8 *)arg0 + 0x326);
    *(s16 *)((s8 *)arg0 + 0x326) = arg1;
    if (is_action_id_none(arg2) == 0) {
        *(s16 *)((s8 *)arg0 + 0xB8) = arg2;
    }
    *(s32 *)((s8 *)arg0 + 0x320) = (s32) (1 << arg1);
    ((s32 (*)(void *, s32))set_state_flags__10TObjPlayerFUl)(arg0, 0x10);
}

s32 TObjPlayer::register_player_slot() {
    Ctrl_801BA6BC *c = (Ctrl_801BA6BC *)get_player_by_client_id((u16)get_entity_id(this));
    if (c != 0) {
        delete c;
    }
    player_slot_table[(u16)get_entity_id(this)] = this;
    return register_entity_by_id(this) == (u16)0xFFFF ? 1 : 0;
}

void *get_player_by_client_id(s32 i) {
    if (i == 0xFFFF) {
        return 0;
    }
    if (i < 0 || i >= 12) {
        return 0;
    }
    return player_slot_table[i];
}

void handle_6xAE_set_animation_state(void *arg0) {
    Msg_801BA78C m;
    void *p;
    ((TObjPlayer *)(&m))->build_6xAE_set_animation_state_packet();
    ((TObjPlayer *)(&m))->copy_from(arg0);
    ((TObjPlayer *)(&m))->bswap_pkt_u16x2_u32x2();
    if (validate_6xAE_set_animation_state(&m) != 0) {
        p = get_player_by_client_id(m.slot);
        if (p != NULL && ((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() != 0 && ((s32 (*)(void *, u32))test_action_mask__10TObjPlayerFl)(p, 0x01000000) == 0 && (m.flags & 0x04000000)) {
            set_state_flags__10TObjPlayerFUl(p, m.flags & 0x1C000000);
            run_action_state_phase__10TObjPlayerFisi(p, 0x18, 0);
        }
    }
}

void handle_6x20_set_position(void *arg0) {
    Msg_801BA838 m;
    Player_801BA838 *p;
    ((TObjPlayer *)(&m))->init_cmd_6x20();
    TObjPlayer__sub_801C1664(&m, arg0);
    ((TObjPlayer *)(&m))->bswap_pkt_u32x5();
    if (validate_6x20_set_position((G_ClientIDHeader *)&m) != 0) {
        p = ((Player_801BA838 *)get_player_by_client_id(m.slot));
        if (p != NULL) {
            ((TUnk_804B9870 *)p)->set_position_from(m.vec);
            ((TObjPlayer *)p)->set_floor_index(TLobby::get_player_floor(m.floor));
            ((TObjPlayer *)p)->set_floor(m.floor);
            p->ang = m.ang;
            ((void (*)(void *))set_flag_400000__10TObjPlayerFi)(p);
        }
    }
}

void handle_6x1F_set_player_floor(void *arg0) {
    Msg1F_801BA8D4 m;
    Msg_801BA8D4 m2;
    Msg20_801BA8D4 m3;
    void *p;
    Player_801BA8D4 *pl;
    init_6x1F_floor_packet((u8 *)&m);
    ((TObjPlayer *)(&m))->handle_6x1F_set_floor(arg0);
    ((TObjPlayer *)(&m))->bswap_set_floor_packet();
    if (validate_6x1F_set_player_floor((G_ClientIDHeader *)&m) != 0) {
        p = get_player_by_client_id(m.slot);
        if (p != NULL) {
            ((TObjPlayer *)p)->set_floor_index(TLobby::get_player_floor(m.floor));
            ((TObjPlayer *)p)->set_floor(m.floor);
        }
        pl = ((Player_801BA8D4 * (*)(void))update_battle_controller__10TObjPlayerFv)();
        if (pl != NULL && (pl == NULL || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(pl) == 0)) {
            ((TObjPlayer *)(&m3))->init_cmd_6x20();
            m3.id = get_entity_id(pl);
            m3.f4 = ((TObjPlayer *)pl)->get_field_3e4();
            VecCopy((Vec *)m3.vec, (const Vec *)pl->pos);
            m3.ang = pl->ang;
            ((TObjPlayer *)(&m3))->send_player_floor_packet_u32x5();
            if (((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() != 0) {
                ((TObjPlayer *)(&m2))->build_6xAE_set_animation_state_packet();
                m2.id = get_entity_id(pl);
                m2.f8 = TObjPlayer__sub_801BEB0C(pl);
                m2.floor = ((TBoss7Crawfish *)pl)->get_floor();
                m2.speed = ((TUnk_804806E8 *)pl)->get_speed();
                ((TObjPlayer *)(&m2))->send_player_floor_packet((void*)m.slot);
            }
        }
    }
}

void TObjPlayer::apply_state_transform() {
    u32 arg0 = (u32)this;
    struct Sp8Struct_801baa00 sp8;

    ((s32 (*)(void))set_flag_400000__10TObjPlayerFi)();
    if ((arg0 == 0U) || (((s32 (*)(u32))obj_isState2_324__13TUnk_804806E8Fv)(arg0) == 0)) {
        init_6x1F_floor_packet((u8 *)((s32 *)&sp8));
        sp8.fA = ((s16 (*)(u32))get_entity_id)(arg0);
        sp8.fC = ((TObjPlayer *)arg0)->get_field_3e4();
        ((TObjPlayer *)((s32 *)&sp8))->bswap_and_send_set_floor();
    }
}

void handle_6x21_inter_level_warp(void *arg0) {
    Msg_801BAA6C m;
    void *p;

    init_6x21_inter_level_warp_packet((u8 *)&m);
    ((TObjPlayer *)(&m))->copy_warp_target(arg0);
    ((TObjPlayer *)(&m))->bswap_warp_packet();
    if (validate_6x21_inter_level_warp((G_ClientIDHeader *)&m) != 0) {
        p = ((void * (*)(u16))get_player_by_client_id)(m.slot);
        if (p != NULL) {
            if ((((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() != 0) && (m.floor != ((TObjPlayer *)p)->get_field_3e4())) {
                set_state_flags__10TObjPlayerFUl(p, 0x40000);
            }
            ((TObjPlayer *)p)->set_floor_index(TLobby::get_player_floor(m.floor));
            ((TObjPlayer *)p)->set_floor(m.floor);
        }
    }
}

void send_6x21_inter_level_warp(void *obj, s32 value) {
    if (obj == 0 || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(obj) == 0) {
        Msg_801BAB1C m;
        init_6x21_inter_level_warp_packet((u8 *)&m);
        m.id = ((u16 (*)(void *))get_entity_id)(obj);
        m.value = value;
        ((TObjPlayer *)(&m))->send_warp_packet();
    }
}

void draw_projected_shadow__10TObjPlayerFPvPvi(VObj_801BAB78 *self, f32 *pos, s32 arg2) {
    Vec_801BAB78 v;
    s32 a;
    s32 b;
    self->m63(1, &v);
    ((void (*)(void))push_matrix)();
    direction_to_rotation_xz(self->f248, &a, &b);
    translate_matrix(0, v.x, lbl_805DC2C8 + self->f3c, v.z);
    rotate_matrix_z(0, b);
    rotate_matrix_x(0, a);
    ((void (*)(int, s32))rotate_matrix_y)(0, self->f60);
    rotate_matrix_x(0, -0x4000);
    if (pos != NULL) {
        scale_matrix(0, pos[0], pos[2], (*(const f32 *)&TObjPlayer__data_805DC294));
    }
    draw_blob_shadow(arg2);
    ((void (*)(void))pop_matrix)();
}

void TObjPlayer__sub_801BAC48(void) {  }

void TObjPlayer::draw_head_attachments() {
    s32 var_r31;
    if ((u32) this->m_8b4 != 0U) {
        this->get_item_ptr(0x3A);
        ((s32 (*)(void))push_matrix_from)();
        TObjFish::set_global_param((s32)((void *) (((u8 *)this) + 0xB88)));
        if (this->m_flags & 0x400) {
            set_shadow_material_state();
        }
        TObjPlayer::play_phase_transition_sound(this->m_8b4);
        set_default_alpha_blend();
        pop_matrix();
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x8B0) != 0U) {
        this->get_item_ptr(0x3B);
        ((s32 (*)(void))push_matrix_from)();
        TObjFish::set_global_param((s32)((void *) (((u8 *)this) + 0xA1C)));
        if (this->m_flags & 0x400) {
            set_shadow_material_state();
        }
        TCharaMaking::enable_making();
        draw_chunk_object((void *)(*(u32 *)((s8 *)((u8 *)this) + 0x8B0)));
        TCharaMaking::clear_flag_bit0();
        set_default_alpha_blend();
        pop_matrix();
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x8AC) != 0U) {
        this->get_item_ptr(0x3B);
        ((s32 (*)(void))push_matrix_from)();
        TObjFish::set_global_param((s32)((void *) (((u8 *)this) + 0xA1C)));
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

void draw_body__10TObjPlayerFPvi(u8 *player, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_801BAD60, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801BAD60, spC) == 0x4) ? 1 : -1];
    Stack_801BAD60 stack;
    u8 *temp_r3;
    push_matrix();
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(player + 0x38));
    stack.spC += *(f32 *)((s8 *)player + 0x5FC);
    translate_matrix_vec3((u8 *)(0), (u8 *)&stack.sp8);
    ((s32 (*)(int, int))rotate_matrix_y)(0, (int) (((TObjPlayer *)player)->rotation_y));
    if (((TItemMag *)(player + 0x5B0))->check_state_flag_1() != 0) {
        temp_r3 = (u8 *)(TObjPlayer__sub_801BF934(player + 0x5B0));
        ((s32 (*)(int, f32, f32, f32))scale_matrix)(0, (f32) (*(f32 *)((s8 *)temp_r3 + 0)), (f32) (*(f32 *)((s8 *)temp_r3 + 4)), (f32) (*(f32 *)((s8 *)temp_r3 + 8)));
    }
    save_render_material_state((player + 0x608));
    set_model_render_flags(8);
    ((TObjPlayer *)player)->apply_material_color_override();
    if (((TObjPlayer *)player)->m_flags & 0x400) {
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(-1, 0x800);
        set_shadow_material_state();
    }
    TObjFish::set_global_param((s32)(player + 0xCF4));
    TObjPlayer::set_global_flag();
    if (arg1 == 2) {
        ((TObjPlayer *)player)->animationFlags = (s32) (((TObjPlayer *)player)->animationFlags | 0x400);
        draw_motion_model_saving_joints((TObjPlayer *)(player));
    } else {
        ((TObjPlayer *)player)->animationFlags = (s32) (((TObjPlayer *)player)->animationFlags & 0xFFFFFBFF);
        ((TObjPlayer *)player)->draw_model_with_callback();
    }
    TObjPlayer::clear_global_state();
    ((TObjPlayer *)player)->draw_head_attachments();
    ((TObjPlayer *)(player + 0x608))->write_ids();
    pop_matrix();
    if (((TItemMag *)(player + 0x5B0))->check_state_flag_1() != 0) {
        ((s32 (*)(void *, void *, int))draw_projected_shadow__10TObjPlayerFPvPvi)(player, (void *) (TObjPlayer__sub_801BF934(player + 0x5B0)), 0);
        return;
    }
    ((s32 (*)(void *, void *, int))draw_projected_shadow__10TObjPlayerFPvPvi)(player, NULL, 0);
}

void render__10TObjPlayerFv(u8 *arg0) {
    s32 spC;
    s32 sp8;
    f32 temp_f31;
    s32 temp_r3;

    if ((((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x02000000) == 0) && (((TObjPlayer *)arg0)->is_inactive() != 0) && ((check_flag_4__10TObjPlayerFv(arg0) == 0) || ((check_flag_4__10TObjPlayerFv(arg0) != 0) && (((TObjPlayer *)arg0)->phase == 0)))) {
        temp_r3 = ((VObj801BAEC8 *) arg0)->m9(lbl_805DC2CC, lbl_805DC2D0, TObjPlayer__data_805DC2BC);
        spC = temp_r3 ^ 0x80000000;
        sp8 = 0x43300000;
        temp_f31 = (f32) temp_r3;
        if (TObjPlayer__data_805DC278 != temp_f31) {
            if ((get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) && (TOKeyMachine01::is_state_active() != 0)) {
                if (TObjEneRecon::render_player_marker(((TObjPlayer *)arg0)->entity_id, 1) != 0) {
                    ((TObjPlayer *)arg0)->render_body_pass(temp_f31);
                    restore_render_scissor(1);
                }
            } else {
                ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)0x08000000);
                TParticleCtrl::end_effect_render();
                select_actor_lighting((s32)arg0);
                if ((((s32 (*)(void *))check_flag_800000__10TObjPlayerFPv)(arg0) != 0) && (((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(arg0) != 0)) {
                    ((TUnk_804806E8 *)arg0)->get_speed();
                    ((s32 (*)(void *))draw__10TObjPlayerFPvf)(arg0);
                } else if (!(((TObjPlayer *)arg0)->m_flags & 0x400)) {
                    model_render_flags |= 1;
                    ((s32 (*)(void *, s32))draw_body__10TObjPlayerFPvi)(arg0, (s32) temp_f31);
                    model_render_flags &= 0xFFFFFFFE;
                }
                save_render_material_state(arg0 + 0x608);
                ((TObjPlayer *)arg0)->apply_material_color_override();
                set_depth_buffer_settings_id(1);
                ((s32 (*)(void *))TObjPlayer__sub_801BAC48)(arg0);
                ((TObjPlayer *)(arg0 + 0x608))->write_ids();
                ((s32 (*)(void))restore_scene_lighting)();
            }
        } else {
            obj_setFlags30(arg0, 0x08000000);
            TObjPlayer::set_global_flag();
            ((TUnk_804806E8 *)arg0)->get_speed();
            ((s32 (*)(void *))draw__10TObjPlayerFPvf)(arg0);
            TObjPlayer::clear_global_state();
            save_render_material_state(arg0 + 0x608);
            ((TObjPlayer *)arg0)->apply_material_color_override();
            ((s32 (*)(void *))TObjPlayer__sub_801BAC48)(arg0);
            ((TObjPlayer *)(arg0 + 0x608))->write_ids();
        }
    } else {
        TObjPlayer::set_global_flag();
        ((TUnk_804806E8 *)arg0)->get_speed();
        ((s32 (*)(void *))draw__10TObjPlayerFPvf)(arg0);
        TObjPlayer::clear_global_state();
        save_render_material_state(arg0 + 0x608);
        ((TObjPlayer *)arg0)->apply_material_color_override();
        ((s32 (*)(void *))TObjPlayer__sub_801BAC48)(arg0);
        ((TObjPlayer *)(arg0 + 0x608))->write_ids();
    }
}

void TObjPlayer::render_body_pass(f32 f) {
    u8 *self = (u8 *)this;
    ((TUnk_804B9870 *)self)->obj_clearFlags30((u32)0x08000000);
    TParticleCtrl::end_effect_render();
    select_actor_lighting((s32)self);
    if (((s32 (*)(void *))check_flag_800000__10TObjPlayerFPv)(self) != 0 && ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(self) != 0) {
        draw__10TObjPlayerFPvf(self, ((TUnk_804806E8 *)self)->get_speed());
    } else if (!(*(u16 *)(self + 4) & 0x400)) {
        model_render_flags |= 1;
        draw_body__10TObjPlayerFPvi(self, (s32)f);
        model_render_flags &= ~1;
    }
    save_render_material_state((u8 *)&this->render_material_state);
    apply_material_color_override();
    set_depth_buffer_settings_id(1);
    ((void (*)(void *))TObjPlayer__sub_801BAC48)(self);
    ((TObjPlayer *)(self + 0x608))->write_ids();
    restore_scene_lighting();
}

void render_shadows__10TObjPlayerFv(u8 *self) {
    f32 f;

    if (is_in_shadow_range(self + 0x38, lbl_805DC2D4) != 0) {
        ((TUnk_804AF8A0 *)self)->set_shadow_flag();
        TParticleCtrl::begin_effect_render();
        if (((s32 (*)(void *, u32))obj_testFlags30__13TUnk_804AF8A0FUl)(self, 0x02000000) == 0 && ((TObjPlayer *)self)->is_inactive() != 0 &&
            (check_flag_4__10TObjPlayerFv(self) == 0 ||
             (check_flag_4__10TObjPlayerFv(self) != 0 && *(s16 *)(self + 0x328) == 0))) {
            f = ((VObj_801BB1F8 *)self)->m9(lbl_805DC2CC, lbl_805DC2D0, TObjPlayer__data_805DC2BC);
            ((TUnk_804B9870 *)self)->obj_clearFlags30((u32)0x08000000);
            draw_body__10TObjPlayerFPvi(self, (s32)f);
            save_render_material_state(self + 0x608);
            ((TObjPlayer *)self)->apply_material_color_override();
            ((void (*)(void *))TObjPlayer__sub_801BAC48)(self);
            ((TObjPlayer *)(self + 0x608))->write_ids();
        }
        TParticleCtrl::end_effect_render();
        ((TUnk_804AF8A0 *)self)->clear_shadow_flag();
    }
}

void run_task__10TObjPlayerFv(TObjPlayer *player) {
    s16 temp_r0;
    s16 temp_r0_2;

    ((s32 (*)(void))handle_state2_transitions__10TObjPlayerFv)();
    player->update_subsystems();
    player->update_position_history();
    player->update_status_effects();
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(player, player->mode, 1);
    advance_animation_playback(player);
    ((TUnk_804806E8 *)player)->calc_attach_pos();
    ((TBoss3VoloptHiraisin *)player)->copy_position();
    ((TObjPlayer *)((u8 *)player + 0x84C))->copy_offset_position(player);
    if (((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(player, 0x800) != 0) {
        ((TUnk_804AF8A0 *)player)->refresh_collision_body_centers();
    } else if (get_type__10TObjPlayerFPv((u8 *)player + 0x828) == 0) {
        temp_r0 = player->m_324;
        switch (temp_r0) {
        case 1:
            ((TUnk_804AF8A0 *)player)->refresh_collision_body_centers();
            check_enemy_body_collisions(player);
            player->update_enemy_collision_flags();
            break;
        case 6:
        case 2:
            ((TUnk_804AF8A0 *)player)->refresh_collision_body_centers();
            break;
        case 3:
            ((TUnk_804AF8A0 *)player)->refresh_collision_body_centers();
            check_enemy_body_collisions(player);
            player->update_enemy_collision_flags();
            break;
        }
    } else {
        temp_r0_2 = player->m_324;
        switch (temp_r0_2) {
        case 3:
        case 1:
            player->check_object_collisions();
            check_enemy_body_collisions(player);
            player->update_enemy_collision_flags();
            break;
        case 2:
            if (check_flag__10TObjPlayerFl(player, 4) != 0) {
                ((TUnk_804AF8A0 *)player)->refresh_collision_body_centers();
            } else {
                player->check_object_collisions();
            }
            break;
        case 6:
            ((TUnk_804AF8A0 *)player)->refresh_collision_body_centers();
            break;
        }
    }
    player->update_movement_effects();
    player->update_facing_vector();
}

void TObjPlayer::unregister() {
    s32 arg0 = (s32)this;
    ((s32 (*)(void))clear_links__10TObjPlayerFPv)();
    ((TObjPlayer *)arg0)->unregister_sub();
    ((s32 *)&player_slot_table)[(u16)((s32 (*)(s32))get_entity_id)(arg0)] = 0;
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

void TObjPlayer::reset_motion_fields() {
    s32 temp_r30;
    s32 temp_r31;
    s32 temp_r3;
    s32 arg0 = (s32)this;
    reset_motion_fields__13TUnk_804B9870Fv();
    ((TObjPlayer *)arg0)->TUnk_804AF8A0::reset_motion_fields();
    ((TObjPlayer *)arg0)->TObjMotion::reset_motion_fields();
    reset_motion_fields__13TUnk_804806E8Fv((void *)arg0);
    ((TObjPlayer *)arg0)->reset_state();
    TObjPlayer__sub_801BD3A4((void *)arg0);
    ((TObjPlayer *)arg0)->place_on_area_entry();
    ((TObjPlayer *)arg0)->update_input_and_draw();
    TObjPlayer__sub_801BCD50((void *)arg0);
    ((TObjPlayer *)arg0)->can_cast_technique();
    TObjPlayer::update_recobox(arg0);
    ((TObjPlayer *)arg0)->update_state();
    TObjPlayer__sub_801BCA0C((void *)arg0);
    ((TObjPlayer *)arg0)->reset_area_entry_state();
    ((TObjPlayer *)arg0)->update_lock_on_cursor();
    ((s32 (*)(void *))TObjPlayer__sub_801BBB74)((void *)arg0);
    ((TObjPlayer *)arg0)->sub_801BB950();
    ((s32 (*)(void *))TObjPlayer__sub_801BB8A8)((void *)arg0);
    if ((is_locally_controlled__10TObjPlayerFPv((void *)arg0) != 0) && (((s32 (*)(void))is_key_machine_ready__10TObjPlayerFv)() != 0) && (((s32 (*)(void *, int))check_flag__10TObjPlayerFl)((void *)arg0, 0x800) == 0) && ((((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)((void *)arg0, 0x800) != 0) || (((s16 (*)(void *))get_actor_hp)((void *)arg0) <= 0))) {
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)(0x800));
        if (check_camera_mode__10TObjPlayerFv() != 0) {
            ((s32 (*)(void *))send_code_49_1__10TObjPlayerFi)((void *)arg0);
        } else {
            if (is_single_screen__10TObjPlayerFv() == 0) {
                ((TObjPlayer *)arg0)->set_meseta(0);
            }
            ((s32 (*)(u16, s32, s32))send_6x24_teleport_player)(((u16 (*)(void *))get_entity_id)((void *)arg0), get_hospital_position__10TObjPlayerFv((void *)arg0), get_hospital_yaw__10TObjPlayerFv((void *)arg0));
            ((s32 (*)(void *, int))set_state_flags__10TObjPlayerFUl)((void *)arg0, 0x800);
            ((s32 (*)(void *, int))set_battle_flag__10TObjPlayerFl)((void *)arg0, 0);
        }
    }
    if ((is_locally_controlled__10TObjPlayerFPv((void *)arg0) != 0) && (((s32 (*)(void *, int))check_flag__10TObjPlayerFl)((void *)arg0, 0x800) != 0)) {
        ((s32 (*)(void *, int))sub_8011E204__10TObjPlayerFl)((void *)arg0, 0x800);
        ((s32 (*)(s32))TLobby__sub_8024AC20)(((u16 (*)(void *))get_entity_id)((void *)arg0));
        ((s32 (*)(void *, int))play_effect_default__10TObjPlayerFii)((void *)arg0, 0xF);
        ((TObjPlayer *)arg0)->update_position_from_target();
        ((s32 (*)(void *))send_code_49_1__10TObjPlayerFi)((void *)arg0);
        ((s32 (*)(void *))send_code50_packet__10TObjPlayerFi)((void *)arg0);
        if (((TObjPlayer *)arg0)->is_alive_and_ready() != 0) {
            ((TObjPlayer *)arg0)->refill_traps();
        }
        temp_r3 = ((TObjPlayer *)arg0)->get_anim_id();
        switch (temp_r3) {
        case 2:
            break;
        case 0:
            TObjPlayer::set_camera_mode(2);
            ((TObjPlayer *)arg0)->send_field_state();
            ((TObjPlayer *)arg0)->set_meseta(0);
            {
                void *m = ((void * (*)(int))__nw__7TObjectFUl)(0x234);
                if (m != 0) {
                    __ct__17TMedicalCenterMesFP7TObjectP10TObjPlayer(m, (void *)tl_05, (void *)arg0);
                }
            }
            break;
        case 1:
            TObjPlayer::set_camera_mode(1);
            break;
        }
        ((s32 (*)(void *, int))set_battle_flag__10TObjPlayerFl)((void *)arg0, 0);
    }
}

extern "C" void TObjPlayer__sub_801BB85C(TObjPlayer *player, u8 *record) {
    u32 state = record[0x143] | (record[0x15F] << 8);
    state |= (record[0x17B] << 16) & 0xFF0000;
    state |= record[0x197] << 24;
    ((TTecLuker *)&player->m_41c)->set_state(state);
}

void TObjPlayer__sub_801BB8A8(void) {  }

void TObjPlayer__sub_801BB8AC(void) {  }

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

void TObjPlayer::init_class_flags(s32 arg1) {
    *(s8 *)&this->unk_338 = TObjPlayer__sub_801BEB4C((void *)arg1);
    this->m_339 = TObjPlayer__sub_801BEB44((void *)arg1);
    *(s8 *)&this->unk_33A = TObjPlayer__sub_801BEB3C((void *)arg1);
}

void TObjPlayer::sub_801BB950() {
  u32 temp_r3_2;
  u8 *temp_r3;
    u8 *arg0 = (u8 *)this;
  if (are_items_enabled_here() != 0)
  {
    temp_r3 = (u8 *) ((u8 * (*)(void *))get_item_field_6__10TObjPlayerFPv)(arg0);
    if (temp_r3 != 0)
    {
      ((TObjPlayer *)arg0)->set_action_provider_variant((s16)((void *) ((s16) (((VObj_18_9c7036 *)(temp_r3))->m41()))));
    }
  }
  if ((is_locally_controlled__10TObjPlayerFPv((void *) arg0) != 0) && (((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() == 0))
  {
    if (are_items_enabled_here() == 0)
    {
      ((TItemMag *)(arg0 + 0x4AC))->init_feed_timer();
    }
    reinit_photon_blast_gauge((u16 *)(arg0 + 0x4AC));
    ((TFontSmallLobby *)(arg0 + 0x4AC))->update_if_ready();
    TObjPlayer::update_photon_blast_state();
  }
  if (((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() != 0)
  {
    temp_r3_2 = ((TObjPlayer *)arg0)->m_54c;
    if ((temp_r3_2 != 0U) && (((s32 (*)(int, void *))check_value_equals__13TUnk_804B6C24Fl)((int) temp_r3_2, (void *) lbl_805D2B28) != 0))
    {
      ((s32 (*)(int))queue_destruction__7TObjectFv)((int) (((TObjPlayer *)arg0)->m_54c));
    }
    ((TObjPlayer *)arg0)->m_54c = create__15TFontSmallLobbyFPv((void *) ((s32) (get_entity_id((void *) arg0) & 0xFFFFu)));
  }
  obj_clear_flag30_20000(arg0);
  if (is_locally_controlled__10TObjPlayerFPv((void *) arg0) != 0)
  {
    if (((s32 (*)(void *))check_flag_800000__10TObjPlayerFPv)((void *) arg0) != 0)
    {
      ((s32 (*)(void *))draw_small_label__15TFontSmallLobbyFi)((void *) arg0);
    }
    if (((TItemMag *)(arg0 + 0x5B0))->check_state_flag_1() != 0)
    {
      request_player_size_restore(arg0 + 0x5B0);
    }
  }
  TFontSmallLobby__sub_801C013C(((u8 *)&this->technique_levels));
  TObjPlayer__sub_80354E7C();
}

void TObjPlayer::setup_fresh_player_state(u8 *arg1) {
    this->hp = (s16) this->hpmax;
    this->tp = (s16) this->tpmax;
    if ((obj_isState2_324__13TUnk_804806E8Fv() != 0) && (((s32 (*)(void))is_lobby_floor_15__15TFontSmallLobbyFv)() == 0) && (check_camera_mode__10TObjPlayerFv() == 0)) {
        deactivate_body_collision();
    }
    if (this->is_android() != 0) {
        this->set_flag_10000();
    }
    if (is_alive_and_ready() != 0) {
        refill_traps();
    }
    this->set_play_time((int) (*(u8 *)((s8 *)arg1 + 3)));
    TObjPlayer__sub_801BF93C((void *) (((u8 *)this) + 0x5B0), (void *) (get_entity_id(this)));
    TObjPlayer::disable_drop_weapon_on_death(this);
    *(s8 *)&this->unk_338 = TObjPlayer__sub_801C21BC(arg1);
    this->m_339 = TObjPlayer__sub_801C21B4(arg1);
    *(s8 *)&this->unk_33A = TObjPlayer__sub_801C21AC(arg1);
}

void TObjPlayer__sub_801BBB70(void) {  }

int TObjPlayer__sub_801BBB74(void* p) { return ((int (*)(void*))enable_action_input__10TObjPlayerFPv)(p); }

void TObjPlayer__sub_801BBB94(void) {  }

void TObjPlayer::init_player_substructs() {
    TObjPlayer__sub_8013A748((void *)((char *)this + 1280));
    TObjPlayer::init_action_palette_defaults((s32)this);
}

void TObjPlayer::init_action_palette_defaults(s32 arg0) {
    ((TObjPlayer *)arg0)->set_action_palette_entry(0, 0, 0, 1, 0);
    ((TObjPlayer *)arg0)->set_action_palette_entry(0, 1, 0, 1, 0);
}

void TObjPlayer::sub_801BBC2C() { this->m_424 = 0; }

void TObjPlayer::update_lock_on_cursor() { void* m = *(void**)((char*)this + 0x424); if (m) ((TLockOnCursor *)m)->reset_and_spawn_cursors(); }

void TObjPlayer__sub_801BBC64(void) {  }

void TObjPlayer::create_lockon_cursor() {
    u32 var_r31;
    u32 var_r31_2;

    if (is_single_screen__10TObjPlayerFv() != 0) {
        if ((u32) this->m_424 == 0U) {
            var_r31 = __nw__7TObjectFUl(0x52C);
            if (var_r31 != 0U) {
                var_r31 = TLockOnCursor__ct(var_r31, this, get_entity_id(this));
            }
            this->m_424 = var_r31;
        }
    } else if (((is_locally_controlled__10TObjPlayerFPv(this) != 0) || (obj_isState3_324__13TUnk_804806E8Fv(this) != 0)) && ((u32) this->m_424 == 0U)) {
        var_r31_2 = __nw__7TObjectFUl(0x52C);
        if (var_r31_2 != 0U) {
            var_r31_2 = TLockOnCursor__ct(var_r31_2, this, get_entity_id(this));
        }
        this->m_424 = var_r31_2;
    }
}

int clear_links__10TObjPlayerFPv(void* p) { return clear_obj_links__13TUnk_804AF8A0Fv(p); }

void TObjPlayer::init_collision_body() {
    Player_801BBD58 *self = (Player_801BBD58 *)this;
    self->body.offset.x = TObjPlayer__data_805DC278;
    self->body.offset.y = TObjPlayer__data_805DC278;
    self->body.offset.z = TObjPlayer__data_805DC278;
    self->body.radius = lbl_805DC2B0;
    self->body.radius2 = lbl_805DC2B0;
    self->body.kind = 0;
    switch (this->m_324) {
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
    ((TUnk_804AF8A0 *)self)->initialize_linked_object_reference(&self->body);
}

struct Cand_801BBE54 { s16 val; Obj_801BC068 *obj; };
struct Cmd_801BBE54 { u16 hdr; u16 client; s32 area; u8 pos[12]; };
f32 horizontal_distance_squared(void *, void *);
extern const f32 lbl_805DC2D8;

s32 TObjPlayer::send_respawn_position() {
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
    for (obj = tl_06->head; obj != NULL; obj = obj->next) {
        if (check_value_equals__13TUnk_804B6C24Fl(obj, TObjPlayer__player_set_class_name) != 0 && obj->f84 == 0) {
            f32 range = lbl_805DC2C0;
            ok = 1;
            for (i = 0; i < 12; i++) {
                if (i != (u16)get_entity_id(this)) {
                    u8 *p = (u8 *)((u32 (*)(int))get_player_by_client_id)(i);
                    if (p != NULL && horizontal_distance_squared(obj->pos, p + 0x38) < range) {
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
    if (this == NULL || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(this) == 0) {
        cmd.client = get_entity_id(this);
        cmd.area = area;
        VecCopy((Vec *)cmd.pos, (const Vec *)pos);
        ((TObjPlayer *)(&cmd))->send_lobby_update();
    }
}

void TObjPlayer__sub_801BC050(O_801BC050 *p) {
    p->a = 0xFFFF;
    p->b = 0;
}

void TObjPlayer__send_selected_spawn_position(void *self, u16 id) {
    Msg_801BC068 m;
    s32 found;
    Obj_801BC068 *o;
    found = 0;
    for (o = tl_06->head; o != NULL; o = o->next) {
        if (check_value_equals__13TUnk_804B6C24Fl(o, TObjPlayer__player_set_class_name) != 0 && o->f84 == 0 &&
            (s32)o->f68 == id) {
            found = 1;
            break;
        }
    }
    if (found != 0 && (self == NULL || ((s32 (*)(void *))obj_isState2_324__13TUnk_804806E8Fv)(self) == 0)) {
        ((TObjPlayer *)(&m))->init_set_position_packet();
        m.id = get_entity_id(self);
        m.ang = o->ang;
        VecCopy((Vec *)m.vec, (const Vec *)o->pos);
        TObjPlayer__sub_801C18E0(&m);
    }
}
}
