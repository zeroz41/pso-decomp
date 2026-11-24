#include "pso/player/PhotonBlastRequests.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/ui/window/TWindowReturnCity.h"
#include "pso/object/TActorLight.h"
#include "pso/player/PlayerState.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/ControllerInput.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/unk/TLobby_801C25B4.h"
#include "pso/network/protocol/subcommand_validation.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/system/vector.h"
#include "pso/system/data/FlagWord.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/technique/TTecReverserEff.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/player/TObjPlayer_801D2E20.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/weapon/SpecialProjectileWeapons_80124760.h"
#include "pso/player/PlayerAttackController.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TDeathTintFade.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/network/protocol/subcommand_validation_photon_blast.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecReverser.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/weapon/WeaponSpecialSelection.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/system/SoundEffect.h"


#pragma readonly_strings on

struct L_801C74BC { u16 f0; u16 f2; s32 f4; };

typedef struct Msg_801C7430 {
    u8 pad0[2];
    u16 slot;
    s32 c;
} Msg_801C7430;

typedef struct Player_801C7430 {
    u8 pad0[0x60];
    s32 dir;
    u8 pad64[0x308 - 0x64];
    u8 vec[12];
} Player_801C7430;

struct VBase8_801c7630 { char pad[8]; };

struct VObj8_801c7630 : VBase8_801c7630 {
    virtual void vpad0();
    virtual void vpad1();
    virtual void vpad2();
    virtual void vpad3();
    virtual void vpad4();
    virtual void vpad5();
    virtual void vpad6();
    virtual void vpad7();
    virtual void vpad8();
    virtual void vpad9();
    virtual void vpad10();
    virtual void vpad11();
    virtual void vpad12();
    virtual void vpad13();
    virtual void vpad14();
    virtual void vpad15();
    virtual void vpad16();
    virtual void vpad17();
    virtual void vpad18();
    virtual void vpad19();
    virtual void vpad20();
    virtual void vpad21();
    virtual void vpad22();
    virtual void vpad23();
    virtual void vpad24();
    virtual void vpad25();
    virtual void vpad26();
    virtual void vpad27();
    virtual void vpad28();
    virtual void vpad29();
    virtual void vpad30();
    virtual void vpad31();
    virtual void vpad32();
    virtual void vpad33();
    virtual void vpad34();
    virtual void vpad35();
    virtual void vpad36();
    virtual void vpad37();
    virtual void vpad38();
    virtual void vpad39();
    virtual void vpad40();
    virtual void vpad41();
    virtual void vpad42();
    virtual void vpad43();
    virtual void vpad44();
    virtual void vpad45();
    virtual void vpad46();
    virtual void vpad47();
    virtual void vpad48();
    virtual void vpad49();
    virtual void vpad50();
    virtual void vpad51();
    virtual void vpad52();
    virtual void vpad53();
    virtual void vpad54();
    virtual void vpad55();
    virtual void vpad56();
    virtual void vpad57();
    virtual void vpad58();
    virtual void vpad59();
    virtual void vpad60();
    virtual void vpad61();
    virtual void vpad62();
    virtual void vpad63();
    virtual void vpad64();
    virtual int vf10C();
    virtual int vf110();
};

struct VBase_inner_801c77c8 { char pad[8]; };

struct VBase_380_801c77c8 : VBase_inner_801c77c8 { virtual s32 m0(); virtual s32 m1(); virtual s32 m2(); virtual s32 m3(); virtual s32 m4(); virtual s32 m5(); virtual s32 m6(); virtual s32 m7(); virtual s32 m8(); virtual s32 m9(); virtual s32 m10(); virtual s32 m11(); virtual s32 m12(); virtual s32 m13(); virtual s32 m14(); virtual s32 m15(); virtual s32 m16(); virtual s32 m17(); virtual s32 m18(); virtual s32 m19(); virtual s32 m20(); virtual s32 m21(); virtual s32 m22(); virtual s32 m23(); virtual s32 m24(); virtual s32 m25(); virtual s32 m26(); virtual s32 m27(); virtual s32 m28(); virtual s32 m29(); virtual s32 m30(); virtual s32 m31(); virtual s32 m32(); virtual s32 m33(); virtual s32 m34(); virtual s32 m35(); virtual s32 m36(); virtual s32 m37(); virtual s32 m38(); virtual s32 m39(); virtual s32 m40(); virtual s32 m41(); virtual s32 m42(); virtual s32 m43(); virtual s32 m44(); virtual s32 m45(); virtual s32 m46(); virtual s32 m47(); virtual s32 m48(); virtual s32 m49(); virtual s32 m50(); virtual s32 m51(); virtual s32 m52(); virtual s32 m53(); virtual s32 m54(); virtual s32 m55(); virtual s32 m56(); virtual s32 m57(); virtual s32 m58(); virtual s32 m59(); virtual s32 m60(); virtual s32 m61(); virtual s32 m62(); virtual s32 m63(); virtual s32 m64(); virtual s32 m65(); virtual s32 m66(); };

struct Pkt_801C7874 { s16 hdr; s16 id; s32 val; };

struct Player_801C7874 {
    u8 pad0[0x328];
    s16 f328;
};

struct VBase_8_1cc697 { char pad[0x8]; };

struct VObj_8_1cc697 : VBase_8_1cc697 {
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
    virtual s32 m19();
    virtual void m20();
    virtual void m21();
    virtual s32 m22();
    virtual void m23();
    virtual s32 m24();
    virtual s32 m25();
    virtual s32 m26();
    virtual void m27();
    virtual void m28();
    virtual s32 m29();
    virtual s32 m30();
    virtual s32 m31();
    virtual s32 m32();
    virtual s32 m33();
    virtual s32 m34();
    virtual s32 m35();
    virtual s32 m36();
    virtual s32 m37();
    virtual s32 m38();
    virtual s32 m39();
    virtual s32 m40();
    virtual s32 m41();
    virtual s32 m42();
    virtual s32 m43();
    virtual s32 m44();
    virtual s32 m45();
    virtual s32 m46();
    virtual s32 m47();
    virtual s32 m48();
    virtual s32 m49();
    virtual s32 m50();
    virtual s32 m51();
    virtual s32 m52();
    virtual s32 m53();
    virtual s32 m54();
    virtual s32 m55();
    virtual s32 m56();
    virtual s32 m57();
    virtual s32 m58();
    virtual s32 m59();
    virtual s32 m60();
    virtual s32 m61();
    virtual s32 m62();
    virtual s32 m63();
    virtual s32 m64();
    virtual s32 m65();
    virtual s32 m66();
    virtual s32 m67();
    virtual s32 m68();
    virtual s32 m69();
    virtual s32 m70();
};

typedef struct Msg_801C851C {
    u8 pad0[2];
    u16 slot;
    s16 c;
} Msg_801C851C;

typedef struct Player_801C851C {
    u8 pad0[0x3C0];
    s16 anim;
} Player_801C851C;

struct Pkt_801C85BC { u16 hdr; s16 id; s16 c; };


struct Pkt_801C8BE8 { u16 hdr; s16 id; s32 c; f32 x1, y1, z1; };

typedef struct Msg_801C8B5C {
    u8 pad0[2];
    u16 slot;
    s32 c;
    u8 vec[12];
} Msg_801C8B5C;

typedef struct Player_801C8B5C {
    u8 pad0[0x60];
    s32 ang;
} Player_801C8B5C;


typedef struct MsgA_801C9400 {
    u8 pad0[2];
    s16 f2;
} MsgA_801C9400;

typedef struct MsgB_801C9400 {
    u8 pad0[2];
    s16 f2;
    s32 f4;
    s16 f8;
    s16 fa;
} MsgB_801C9400;

struct Pkt_801C9838 {
    u8 hdr[2];
    u16 client;
    s16 c;
    s16 e;
    s32 g;
};

struct Pkt_801C9924 { u16 hdr; s16 id; s16 a; s16 b; s32 c; };

struct Local801C9D3C {
    s16 field0;
    s16 fieldA;
};

struct Pkt_801C9FE8 { u16 hdr; u16 id; u16 c; };

struct S801CA274 { s8 b[2]; s16 h; };

struct Cmd_801CA724 {
    u8 cmd;
    u8 size;
    u16 client;
    u8 data[0xC];
};

struct Cmd_801CA7BC {
    u8 cmd;
    u8 size;
    u16 client;
    s16 val;
    u16 pad;
};

struct Cmd2_801CA7BC {
    u8 cmd;
    u8 size;
    u16 client;
    u8 data[4];
};

struct Pkt_801CADA4 { u8 hdr[2]; s16 id; s16 dir; s16 f6; f32 x; f32 z; };


struct Pkt_801CB27C { u16 hdr; s16 id; s16 a; s16 b; f32 x; f32 z; };

struct Pkt_801CB4D0 { u16 hdr; s16 id; s32 c; };

struct SwitchActionMessage_801CB6A8 { u8 code; u8 words; u16 actor; s32 yaw; };

typedef struct Ctx_801CB748 { s16 f0; s16 f2; s32 f4; } Ctx_801CB748;

struct PbPacket37_801CC194 {
    u8 hdr[2];
    s16 player;
    s16 gauge;
};

struct Pkt_801CC0F4 {
    u16 f0;
    u16 player;
    u8 pad[0x10 - 4];
};


typedef struct Player_801CC6B8 {
    u8 pad0[0x4AC];
    u8 pb[4];
} Player_801CC6B8;


struct Mylla_801CC558 { u8 pad[0xA4]; u8 *tbl; };


struct Pkt_801CCB58 { u16 hdr; u16 id; s16 c; };

typedef struct Msg_801CCA84 {
    u8 pad0[2];
    u16 id;
    u16 target;
    u8 pad6[2];
} Msg_801CCA84;

typedef struct Tech_801CCA84 {
    s32 kind;
    u16 target;
    s16 f6;
    f32 f8;
    u8 padc[0x60 - 0xC];
} Tech_801CCA84;

typedef struct Player_801CCA84 {
    u8 pad0[0x10];
    TObject *list;
} Player_801CCA84;


struct Pkt_801CCEDC { u16 hdr; u16 id; s16 tech; u16 level; };

struct Player_801CCEDC { u8 pad[0x328]; s16 f328; u8 pad32a[0x32E - 0x32A]; s16 tp; u8 pad330[0x428 - 0x330]; u8 techs[4]; };

struct Pkt_801CCD38 { u16 hdr; u16 id; s16 tech; s16 level; };


struct Player_801CCD38 { u8 pad[0x10]; TObject *f10; u8 pad14[0x328 - 0x14]; s16 f328; u8 pad32a[0x428 - 0x32A]; u8 techs[4]; };


struct Player_801CD078 { u8 pad[0x32E]; s16 tp; u8 pad330[0x428 - 0x330]; u8 techs[4]; };

struct Node_801CD424 { u8 pad[0x1C]; f32 pos[3]; u8 pad28[0x2C - 0x28]; };

struct Obj_801CD424 { u8 pad[0xA4]; Node_801CD424 *nodes; };

struct Player_801CD424 {
    u8 pad[0x60];
    s32 f60;
    u8 pad64[0xBA - 0x64];
    s16 fba;
    u8 padbc[0x326 - 0xBC];
    s16 f326;
    s16 f328;
    u8 pad32a[0x33C - 0x32A];
    s32 f33c;
    u8 pad340[0x3F0 - 0x340];
    s32 f3f0;
    u8 pad3f4[0x428 - 0x3F4];
    u8 techs[0x744 - 0x428];
    u8 f744[4];
};

struct Sub_801CD188 { u8 pad[0x508]; u16 f508; };

struct Player_801CD188 { u8 pad[0xB0]; u32 flags; u8 padb4[0x424 - 0xB4]; Sub_801CD188 *sub; };

typedef struct Msg1_801CD72C {
    u8 pad0[2];
    u16 id;
    u8 level;
    u8 pad5[3];
} Msg1_801CD72C;


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

struct Pkt_801CDAD8 { u8 cmd; u8 size; u16 player; s16 heading; s16 kind; };

struct Rec_801CDBA0 { u8 pad[0x1C]; f32 pos[3]; u8 pad2[0x2C - 0x28]; };

struct Pkt_801CDED4 { u8 cmd; u8 size; u16 player; s16 heading; s16 kind; };

struct Rec_801CDF9C { u8 pad[0x1C]; f32 pos[3]; u8 pad2[0x2C - 0x28]; };

typedef struct Player_801CE068 {
    u8 pad0[0xB0];
    u32 flags;
    u8 padb4[0xB8 - 0xB4];
    s16 anim;
    u8 padba[0x328 - 0xBA];
    s16 state;
    u8 pad32a[0x7CC - 0x32A];
    u8 act[4];
} Player_801CE068;

struct VBase_801CE928 { u8 pad[0x18]; };

struct Player_801CE928 : VBase_801CE928 {
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
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual s32 v65(f32);
};

struct Pkt_801CF128 { u8 cmd; u8 size; u16 player; s16 heading; s16 kind; };

typedef struct Player_801CF2B0 {
    u8 pad0[0xB0];
    u32 flags;
    u8 padb4[0xB8 - 0xB4];
    s16 anim;
    u8 padba[0x328 - 0xBA];
    s16 state;
    u8 pad32a[0x7CC - 0x32A];
    u8 act[4];
} Player_801CF2B0;

struct Plr_801CF56C {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x1c];
    s32 rot;
    u8 pad64[0x2a4];
    f32 vx;
    f32 vy;
    f32 vz;
    u8 pad314[0xdc];
    s32 target_rot;
    u8 pad3f4[4];
    f32 tx;
    f32 ty;
    f32 tz;
    u8 pad404[0x1dc];
    PlayerMoveSpeed move_speed;
};

struct Cmd_801CF780 { u16 hdr; u16 id; f32 x; f32 z; };

struct Player_801CF780 { u8 pad[0x3F8]; f32 x; u8 pad3fc[4]; f32 z; };

typedef struct Msg_801CF824 {
    u8 pad0[2];
    s16 f2;
    f32 x;
    f32 z;
} Msg_801CF824;

typedef struct Npc_801CF824 {
    u8 pad0[0x3F0];
    s32 f3f0;
    u8 pad3f4[4];
    f32 x;
    u8 pad3fc[4];
    f32 z;
} Npc_801CF824;

struct Plr_801CFDF8 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x1c];
    s32 rot;
    u8 pad64[0x2a4];
    f32 vx;
    f32 vy;
    f32 vz;
    u8 pad314[0xdc];
    s32 target_rot;
    u8 pad3f4[4];
    f32 tx;
    f32 ty;
    f32 tz;
    u8 pad404[0x1dc];
    PlayerMoveSpeed move_speed;
};

struct Cmd_801D0000 { u16 hdr; u16 id; f32 x; f32 z; s32 state; };

struct Player_801D0000 { u8 pad[0x3F8]; f32 x; u8 pad3fc[4]; f32 z; u8 pad404[0x5EC - 0x404]; u8 luker[4]; };

typedef struct Msg_801D00B0 {
    u8 pad0[2];
    s16 f2;
    f32 x;
    f32 z;
    s32 v;
} Msg_801D00B0;

typedef struct Npc_801D00B0 {
    u8 pad0[0x3F0];
    s32 f3f0;
    u8 pad3f4[4];
    f32 x;
    u8 pad3fc[4];
    f32 z;
    u8 pad404[0x5EC - 0x404];
    u8 sub[4];
} Npc_801D00B0;

struct VBase_8_e57d67 { char pad[0x8]; };

struct VObj_8_e57d67 : VBase_8_e57d67 {
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
    virtual s32 m21();
};

typedef struct Msg_801D0634 {
    u8 pad0[2];
    u16 id;
    s16 flag;
    s16 ang;
    s16 floor;
    s16 room;
    u8 vec[12];
} Msg_801D0634;

typedef struct Player_801D0634 {
    u8 pad0[0x60];
    s32 ang;
} Player_801D0634;

struct Player_801D0724 {
    u8 pad0[0x60];
    s32 ang;
    u8 pad64[0x328 - 0x64];
    s16 f328;
};

typedef struct Msg_801D08B0 {
    u8 pad0[2];
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fa;
    u8 vec[12];
} Msg_801D08B0;

typedef struct Msg_801D094C {
    u8 pad0[2];
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fa;
    u8 vec[12];
} Msg_801D094C;

typedef struct Player_801D094C {
    u8 pad0[0x38];
    u8 vec[12];
    u8 pad44[0x60 - 0x44];
    s32 f60;
} Player_801D094C;

struct VBase_8_684c72 { char pad[0x8]; };

struct VObj_8_684c72 : VBase_8_684c72 {
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
    virtual s32 m65();
    virtual s32 m66();
};

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };
#pragma pop
struct Base_801D0F0C { char pad[0x8]; };

struct VObj_801D0F0C : Base_801D0F0C {
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
    virtual int m23();
};

struct Pkt_801D1888 { u8 cmd; u8 size; u8 pad[2]; u16 a; u16 b; };

struct VOff_801D192C_arg0_801D18B0 { char pad_0[0x4]; char f_4[1]; };
#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
struct ByteBlock_8 { u8 bytes[0x8]; };
#pragma pop
struct Target_801D1DDC { u16 id; s16 part; };

struct Packet_801D1DDC {
    u8 command, size;
    u16 player;
    s8 kind, flags;
    s16 count, gauge, unused;
    struct Target_801D1DDC targets[10];
};

struct ByteBlock_28
{
  u8 bytes[0x28];
};

typedef struct ByteBlock_28 ByteBlock_28;

struct E_801D1FA4 { u8 d[4]; };

struct Obj_801D1FA4 { u16 a; u16 b; s16 n0; s16 n; u8 pad[4]; E_801D1FA4 e[1]; };

struct Pkt_801D209C { u8 cmd; u8 size; u8 pad[2]; u16 a; u16 b; };

struct Vec_801D24F4 { u8 bytes[0xC]; };

struct Pkt_801D24F4 { u8 hdr[4]; Vec_801D24F4 pos; };

struct Ent_801D2640 { u8 pad[8]; f32 f; u8 pad2[4]; };

struct Obj_801D2640 {
    u8 pad[0xB8];
    s16 idx;
    u8 pad2[0xD8 - 0xBA];
    Ent_801D2640 *arr;
};

struct ByteBlock_2C { u8 bytes[0x2C]; };


struct Pos_801D2964 { u8 bytes[0x8]; };

struct Pkt_801D2964 { u8 hdr[4]; Pos_801D2964 pos; };

struct E_801D2B2C { u8 d[4]; };

struct Obj_801D2B2C { s32 n; E_801D2B2C e[1]; };

struct E_801D2C18 { u8 d[4]; };

struct Obj_801D2C18 { s32 n; E_801D2C18 e[1]; };

typedef struct Msg_801CACD8 {
    u8 pad0[2];
    u16 id;
    s16 ang;
    s16 kind;
    f32 x;
    f32 z;
} Msg_801CACD8;

typedef struct Player_801CACD8 {
    u8 pad0[0x60];
    s32 ang;
    u8 pad64[0x308 - 0x64];
    f32 x;
    u8 pad30c[4];
    f32 z;
} Player_801CACD8;

typedef struct Msg_801CB1B0 {
    u8 pad0[2];
    u16 id;
    s16 ang;
    s16 kind;
    f32 x;
    f32 z;
} Msg_801CB1B0;

typedef struct Player_801CB1B0 {
    u8 pad0[0x60];
    s32 ang;
    u8 pad64[0x308 - 0x64];
    f32 x;
    u8 pad30c[4];
    f32 z;
} Player_801CB1B0;
extern "C" {

s32 clear_velocity(void *);
s32 get_actor_hp__9TObjCharaFv(void * a0 = 0);
s32 TObjPlayer__sub_8001943C(void *, s32);
void obj_setFlags30(void *, u32);
s32 get_current_floor(void);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
s32 test_flags_any(void *, int);
s32 TObjPlayer__sub_80082300(void *);
s32 copy_attack_targets(void *, void *);
s32 publish_actor_light_scalars(u32, f32, f32);
s32 canSetMenuCursorAction(void *, void *, s32, u8);
void TMainCursor__sub_8013DFC4(u8 *arg0);
u8 get_cursor_palette_mode(void *);
s32 approach_angle_adaptive(s32, s32);
s32 lerp_angle_half__Fll(s32, s32);
void *resolve_hittable_target(u16 actorId, s16 collider);
s32 get_type__10TObjPlayerFPv(void *);
s32 play_weapon_hit_sound(void *);
void apply_camera_shake__10TObjPlayerFiii(TObjPlayer *player, TObjChara *target, s32 damage);
u8 * find_entity_by_id(s32);
s32 is_on_current_floor__10TObjPlayerFi();
s32 get_trap_type__10TOMineTrapFv(int);
s32 accumulate_damage_stats_at_76c(s32, s32, s32);
s32 fn_801B0480(int, void *, int);
s32 draw_player_status(void *, void *, const char *);
s32 reset_volopt_state__10TObjPlayerFv(void *obj);
void send_6x2F_change_player_hp(u16 sender, u16 client, s16 hp);
s16 calc_scaled_value__10TObjPlayerFii(void *, int);
void apply_speed_scale__10TObjPlayerFif(saddr arg0, f32 farg0);
void complete_deferred_player_death();
int is_flag_400_set__10TObjPlayerFPv(void *p);
void enable_action_input__10TObjPlayerFPv(void *p);
void send_code_49_1__10TObjPlayerFi(saddr player);
u16 TObjPlayer__sub_801B5AF8(void *, s32);
u32 resolve_move_collision__10TObjPlayerFv(void *);
s32 damp_planar_velocity();
s32 get_vobj_state_28__10TObjPlayerFv(void *);
void TObjPlayer__sub_801BEEE0(void *p, void *q);
s32 is_action_id_none(int);
u8 TObjPlayer__sub_801C010C(const PlayerTechniqueState *state, s32 technique);
void bswap_g_client_id_header(void *p);
int copy_subcommand_header(void*);
void TObjPlayer__sub_801C0734(void *);
void TObjPlayer__sub_801C18E0(void *);
void set_photon_blast_kind(void *p, s16 v);
s32 interpolate_angle__10TObjPlayerFPvUsUsPl(void *, int, int, s32 *);
void handle_6xB0_turn_or_move_lobby_chair(void *command);
void handle_6xAF_turn_or_move_lobby_chair(void *command);
void TObjPlayer__sub_801C75A4(u8 *player);
void TObjPlayer__sub_801C7874(TObjPlayer *player);
void handle_6xB1(void);
void handle_6x58_lobby_animation(void *command);
void TObjPlayer__deactivate_off_floor_body(void* p);
void handle_6x57(void *command);
void draw_and_send_field1c__10TObjPlayerFi(TObjPlayer *player);
void handle_6x56_set_player_position_and_angle(void *command);
void handle_6x53(void *command);
void apply_velocity_if_free__10TObjPlayerFPv(void *player);
void handle_6x52_set_animation_state(saddr command);
s32 handle_6x4F_revived__10TObjPlayerFi(s32 arg0);
void handle_6x89_set_killer_entity_id(void *command);
s32 handle_revivable__10TObjPlayerFi(s32 arg0);
void handle_6x4D_player_died(void *command);
void start_action_0e__10TObjPlayerFPv(u8 *arg0);
void end_freeze_action__10TObjPlayerFPv(u8 *arg0);
void handle_6x50_switch_interaction(const void *source);
void start_use_item_action__10TObjPlayerFPv(u8 *arg0);
void send_object_id_packet__10TObjPlayerFi(TObjPlayer *player);
void release_all_players_control_lock(void);
void handle_6x36(void);
void handle_6x37_photon_blast(saddr command);
void handle_6x49_execute_photon_blast(void *command);
void copy_tech_params__10TObjPlayerFPvPv(void *arg0, void *arg1);
void handle_6x33_revive_player(void *command);
s32 try_equip_item__10TObjPlayerFii(TObjPlayer *player, s16 tech);
void handle_6x48_cast_technique_complete(void *arg);
s32 can_start_technique__10TObjPlayerFPvi(Player_801CD078 *self, s32 tech);
void handle_6x8D_set_technique_level_override(void *command);
void enter_attack_stage3__10TObjPlayerFPv(u8 *player);
void handle_6x45_attack(void *src);
void enter_attack_stage2__10TObjPlayerFPv(u8 *player);
void handle_6x44_attack(void *src);
void handle_6x46_attack_finished(s32 command);
void update_action_state__10TObjPlayerFPv(u8 *player);
void update_action_state__10TObjPlayerFv(void);
void enter_attack_stage1__10TObjPlayerFPv(u8 *player);
void handle_6x43_attack(void *src);
void handle_6x42_move_to_position(void *pkt);
s32 TObjPlayer__sub_801CFBFC(u8 *arg0);
void handle_6x40_walk_to_position(void *pkt);
void handle_6x3F_set_position(void *command);
void handle_6x3E_stop_at_position(void *command);
void send_idle_return_event__10TObjPlayerFPvPvs(void *arg0, void *arg1, s16 arg2);
int TObjPlayer__sub_801D0DAC(void* p);
void TObjPlayer__sub_801D0E74(void* p);
G_IntraMapWarp_6x55 *TObjPlayer__sub_801D0EA0(G_IntraMapWarp_6x55 *destination, G_IntraMapWarp_6x55 *source);
void release_control_lock__10TObjPlayerFPv(void* p);
void TObjPlayer__sub_801D0F70(void* p);
int copy_position__10TObjPlayerFPv(void* p);
void update_player_action_palette(TObjPlayer *player, u8 slot);
void TObjPlayer__sub_801D10D4(void* p);
void TObjPlayer__sub_801D1144(u8 *arg0);
void * TObjPlayer__sub_801D1194(void *arg0, void *arg1);
void TObjPlayer__sub_801D11D0(u8 *arg0);
int TObjPlayer__sub_801D11EC(void* p);
int TObjPlayer__sub_801D11F8(void* p);
void TObjPlayer__sub_801D1284(u8 *arg0);
void TObjPlayer__sub_801D12D8(void* p);
void TObjPlayer__sub_801D12E8(void* p);
int TObjPlayer__sub_801D1360(void* p);
void TObjPlayer__sub_801D13EC(u8 *arg0);
void TObjPlayer__sub_801D1440(void* p);
void* handle_6x57__10TObjPlayerFPv(void* p);
u8 * TObjPlayer__sub_801D1514(u8 *arg0, u8 *arg1);
u8 * copy_6x4b_hit_by_enemy_packet__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
void TObjPlayer__sub_801D1BB0(u8 *arg0);
void* copy_font__10TObjPlayerFPvPv(void* p, void* a1);
void TObjPlayer__sub_801D1C70(u8 *arg0);
void * TObjPlayer__sub_801D1D44(void *arg0, void *arg1);
void TObjPlayer__sub_801D1D88(u8 *arg0);
s32 copy_photon_blast_data__10TObjPlayerFiPv(saddr arg0, u8 *arg1);
u8 TObjPlayer__sub_801D2004(u8 *arg0);
void* TObjPlayer__sub_801D2058(void* p, void* a1);
u8 * TObjPlayer__sub_801D21CC(u8 *arg0, u8 *arg1);
void * TObjPlayer__sub_801D2348(void *arg0, void *arg1);
void TObjPlayer__sub_801D2448(void* p);
void * TObjPlayer__sub_801D24B0(void *arg0, void *arg1);
u8 * TObjPlayer__sub_801D2540(u8 *arg0, u8 *arg1);
u8 * TObjPlayer__sub_801D25AC(u8 *arg0, u8 *arg1);
void clear_status_bit6__10TObjPlayerFPv(void* p);
f32 get_action_rate_entry(Obj_801D2640 *p);
void* TObjPlayer__sub_801D28A0(void* p, void* a1);
void TObjPlayer__sub_801D28DC(void* p);
u8 * copy_6x4c_hit_by_enemy_packet__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
int TObjPlayer__sub_801D2A50(void* p);
void TObjPlayer__sub_801D2A78(void* p, f32 v);
s32 TObjPlayer__sub_801D2A80(void* p);
void TObjPlayer__sub_801D2A88(u8 *arg0);
f32 TObjPlayer__sub_801D2A98(void* p);
int is_alt_photon_blast_bank_empty__10TObjPlayerFPv(void* p);
s32 TObjPlayer__sub_801D2BB8(saddr arg0, saddr arg1);
void TObjPlayer__sub_801D2CAC(u8 *arg0);
void TObjPlayer__sub_801D2CC4(void* p, f32 v);
int on_attack_finished__10TObjPlayerFPv(void* p);
int is_pb_palette_bank_empty(void*);
u8 get_cast_technique_level(void *techs, s16 tech);
s32 set_technique_level_entry(void *, s32, u8);
int bswap_16__FPUs(void*);
int bswap_32__FPUl(void*);
u8 * get_character_save_record(u16);
}
int is_android_player(void* p);
void reset_player_appearance_opacity(void *a0);
void remove_photon_blast_participant(s32 id);
void send_photon_blast_targets_packet(u8 *player);
void init_6x48_cast_complete_packet(u8 *arg0);
void init_6x8D_technique_level_packet(u8 *arg0);
void send_6x46_attack_finished(u8 *arg0);
u8 get_6x46_strike_packet_size(saddr arg0);
f32 get_attack_controller_rate(void* p);
void emit_heavy_attack_particles(saddr owner, u16 target_id);
void create_technique_charge_light(u32 kind, void *owner);
extern "C" {
s32 is_palettex_activated(u16);
s32 dispatch_weapon_special_effect(void *, int, int, int);
s32 fn_8036B798(void *);
s32 fn_8036B7C0(void *);
s32 validate_6x55_intra_map_warp(G_ClientIDHeader *);
f32 cos_table_lookup(s32);

extern const char *TOMineTrap__data_805D3080;
const f64 lbl_80447128 = 0.1;
const f64 lbl_80447148 = 10430.38043493439;
extern f32 scratch_vec[];
extern f32 player_feedback_light_color[];
extern void *player_slot_table[];
extern const char *lbl_805D3530;
extern const char *TWindowReturnCity__class_name;

void handle_6xB0_turn_or_move_lobby_chair(void *command) {
    Msg_801C7430 m;
    Player_801C7430 *p;
    ((void (*)(void *))TObjPlayer__sub_801D1144)(&m);
    ((TObjPlayer *)(&m))->copy_lobby_font_header(command);
    TObjPlayer__sub_801D10D4(&m);
    if (fn_8036B798(&m) != 0) {
        p = (Player_801C7430 *)get_player_by_client_id(m.slot);
        if ((p != NULL) && (((TObjPlayer *)p)->is_in_tl03_state() != 0)) {
            ((TObjPlayer *)p)->update_lobby_chair(m.c);
            calc_direction_vector(p->dir, (Vec *)p->vec, 1.0f);
        }
    }
}

void handle_6xAF_turn_or_move_lobby_chair(void *command) {
    L_801C74BC sp8;
    ((void (*)(void *))TObjPlayer__sub_801D11D0)(&sp8);
    ((void (*)(void *, void *))TObjPlayer__sub_801D1194)(&sp8, command);
    ((TObjPlayer *)(&sp8))->swap_endian32();
    if (fn_8036B7C0(&sp8) != 0) {
        TObjPlayer *p = get_player_by_client_id(sp8.f2);
        if (p != NULL && p->is_in_tl03_state() != 0) {
            p->get_chair_state(sp8.f4);
        }
    }
}

void TObjPlayer::update_state_group() {

    ((s32 (*)(void))clear_velocity)();
    clear_state_flag();
    clear_anim_flag();
    clear_chair_seated();
    leave_chair_seat();
    set_motion_list(action_provider->vfunc_76());
}

void TObjPlayer__sub_801C75A4(u8 *player) {
    s32 sp8;
    f32 length;
    ((TObjPlayer *)player)->rotation_y = interpolate_angle__10TObjPlayerFPvUsUsPl(player, ((TObjPlayer *)player)->rotation_y, TObjPlayer__sub_801D0DAC(player), &sp8);
    length = normalize_vector_safe((Vec *)(player + 0x308)) - 0.04f;
    if (length < 0.04f) {
        clear_velocity((void *) (player));
    } else {
        calc_direction_vector((int) (((TObjPlayer *)player)->rotation_y), (Vec *)((void *) (player + 0x308)), (f32) (length));
    }
    if (((TObjPlayer *)player)->resolve_move_collision() == 0U) {
        ((TObjPlayer *)player)->apply_velocity();
    }
}

void TObjPlayer::start_action_18() {
    s16 var_r4;

    this->action_state = 0x18;
    run_action_state_phase(this->mode, 6);
    if (is_action_flag_28() != 0) {
        var_r4 = ((VObj8_801c7630 *) *(void **)((s8 *)this + 0x380))->vf110();
    } else {
        var_r4 = ((VObj8_801c7630 *) *(void **)((s8 *)this + 0x380))->vf10C();
    }
    forward_1D1044_at_34c(var_r4);
    if (get_action_flag() != 0) {
        update_facing_from_lock();
    }
    set_chair_seated();
    this->phase = 0;
    get_chair_state(this->rotation_y);
    create_photon_chair();
    this->set_action_state(0x18, start_action18_sub());
}

typedef struct Msg_801C770C {
    u8 pad0[2];
    u16 id;
    u16 a;
    u16 flags;
} Msg_801C770C;

void handle_6xAB(void *command) {
    Msg_801C770C m;
    void *p;

    TObjPlayer__sub_801D1284((u8 *)&m);
    ((TObjPlayer *)(&m))->copy_packet_header_6xAB(command);
    ((TObjPlayer *)(&m))->swap_bytes();
    if (validate_6xAB(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = get_player_by_client_id(m.id);
        if (p != NULL && ((TObjPlayer *)p)->is_in_tl03_state() != 0) {
            if (TObjPlayer__sub_801D11F8(&m) == 0) {
                ((TObjPlayer *)p)->clear_state_flag();
            } else {
                TObjPlayer__sub_801D0E74(p);
            }
            if (TObjPlayer__sub_801D11EC(&m) != 0) {
                ((TObjPlayer *)p)->set_anim_flag();
            }
            ((TObjPlayer *)p)->run_action_state_phase(0x18, 0);
        }
    }
}

void TObjPlayer::send_state_sync() {
    s32 sp8[2];

    if (this == NULL || ((TObjChara *)this)->obj_isState2_324() == 0) {
        ((s32 (*)(s32 *))TObjPlayer__sub_801D1284)(sp8);
        *(s16 *)((s8 *)sp8 + 2) = this->get_entity_id();
        if (this->lobby_animation == (((VBase_380_801c77c8*)(*(void **)((s8 *)this + 0x380)))->m66())) {
            ((s32 (*)(s32 *))TObjPlayer__sub_801D12E8)(sp8);
        }
        if (TKeyBoardControl__sub_801A58D8() != 0) {
            ((s32 (*)(s32 *))TObjPlayer__sub_801D12D8)(sp8);
        }
        ((TObjPlayer *)sp8)->send_swapped_bytes();
    }
}

void TObjPlayer::lobby_chair_phase8_nop() {  }

void TObjPlayer::finish_chair_sit_down() {
    if (this->motion_flags & MOTION_CHAINED) {
        this->phase = 1;
    }
}

void TObjPlayer__sub_801C7874(TObjPlayer *player) {
    Pkt_801C7874 a;
    Pkt_801C7874 b;
    s32 target;
    f32 amount;
    if (player->is_controls_locked() == 0 && ((Player_801C7874 *)player)->f328 != 0 &&
        (player->pad_binding.is_button_pressed(2) != 0 ||
         (player->is_action_flag_28() == 0 && TKeyBoardControl__sub_801A58B0() != 0 && TKeyBoardControl::is_key_down(0x24) != 0) ||
         (player->is_action_flag_28() != 0 && TKeyBoardControl__sub_801A58B0() != 0 && TKeyBoardControl::is_key_down(0x18) != 0))) {
        player->run_action_state_phase(1, 5);
        return;
    }
    target = player->pad_binding.get_stick_angle();
    amount = player->pad_binding.get_stick_magnitude();
    if (player->chair_seat.is_delay_6xB0_over() == 0) {
        player->chair_seat.tick_delay_6xB0();
        return;
    }
    if (player->is_controls_locked() == 0 && player->pad_binding.is_button_pressed(4) != 0) {
        if (player == NULL || player->obj_isState2_324() == 0) {
            player->chair_seat.start_delay_6xB0();
            ((s32 (*)(void *))TObjPlayer__sub_801D1144)(&a);
            a.id = player->get_entity_id();
            a.val = target;
            ((TObjPlayer *)(&a))->bswap_and_send();
        }
    } else {
        if (player->chair_seat.is_delay_6xAF_over() == 0) {
            player->chair_seat.tick_delay_6xAF();
            return;
        }
        if (amount >= 0.1f && (player == NULL || player->obj_isState2_324() == 0)) {
            player->chair_seat.start_delay_6xAF();
            ((s32 (*)(void *))TObjPlayer__sub_801D11D0)(&b);
            b.id = player->get_entity_id();
            b.val = target;
            ((TObjPlayer *)(&b))->send_swapped_packet();
        }
    }
}

int TObjPlayer::try_change_action(void* p) { return ((TObjPlayer *)p)->try_change_action(); }

void TObjPlayer::run_lobby_chair_state_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  uaddr new_var2;
  unsigned int new_var;
  {
    switch (phase)
    {
      case 7:
        TObjPlayer::try_change_action(this);
        return;
      new_var2 = (new_var = arg0);
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801C7874)();
        return;
      case 3:
        ((TObjPlayer *)new_var2)->finish_chair_sit_down();
 do { } while (0 != 0);
        return;
      case 8:
        lobby_chair_phase8_nop();
        return;
      case 5:
        this->send_state_sync();
        return;
      case 0:
        this->start_action_18();
        return;
      case 1:
        ((s32 (*)(void))TObjPlayer__sub_801C75A4)();
        return;
      case 6:
        this->update_state_group();
        break;
    }
  }
}

s16 TObjPlayer::select_idle_action() {
    u8 *arg0 = (u8 *)this;
    if ((void *) *(u8 **)((s8 *)arg0 + 0x380) == NULL) {
        return -1;
    }
    if ((TObjPlayer::get_hold_effect_count() == 0) && (TFontSmallLobby::is_lobby_floor_15() != 0)) {
        if (((TKeyBoardControl__sub_801A58B0() != 0) && (TKeyBoardControl::is_key_down(0x24) != 0)) || ((is_controls_locked() == 0) && (pad_binding.is_button_held(0x400) != 0) && (pad_binding.is_button_pressed(4) != 0))) {
            return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m65();
        }
        if (((TKeyBoardControl__sub_801A58B0() != 0) && (TKeyBoardControl::is_key_down(0x18) != 0)) || ((is_controls_locked() == 0) && (pad_binding.is_button_held(0x400) != 0) && (pad_binding.is_button_pressed(2) != 0))) {
            return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m66();
        }
        if (TKeyBoardControl__sub_801A58B0() != 0) {
            if (TKeyBoardControl::is_key_down(0x40) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m22();
            }
            if (TKeyBoardControl::is_key_down(0x41) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m24();
            }
            if (TKeyBoardControl::is_key_down(0x42) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m26();
            }
            if (TKeyBoardControl::is_key_down(0x43) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m19();
            }
            if (TKeyBoardControl::is_key_down(0x44) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m29();
            }
            if (TKeyBoardControl::is_key_down(0x45) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m30();
            }
            if (TKeyBoardControl::is_key_down(0x46) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m31();
            }
            if (TKeyBoardControl::is_key_down(0x47) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m32();
            }
            if (TKeyBoardControl::is_key_down(0x48) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m33();
            }
            if (TKeyBoardControl::is_key_down(0x49) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m34();
            }
            if (TKeyBoardControl::is_key_down(0x4A) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m35();
            }
            if (TKeyBoardControl::is_key_down(0x4B) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m36();
            }
            if (TKeyBoardControl::is_key_down(0x1C) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m25();
            }
            if (TKeyBoardControl::is_key_down(0x2E) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m18();
            }
            if (TKeyBoardControl::is_key_down(0x2F) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m37();
            }
            if (TKeyBoardControl::is_key_down(0x30) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m38();
            }
            if (TKeyBoardControl::is_key_down(0x31) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m39();
            }
            if (TKeyBoardControl::is_key_down(0x32) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m40();
            }
            if (TKeyBoardControl::is_key_down(0x33) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m41();
            }
            if (TKeyBoardControl::is_key_down(0x17) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m42();
            }
            if (TKeyBoardControl::is_key_down(0x11) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m43();
            }
            if (TKeyBoardControl::is_key_down(0x1E) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m44();
            }
            if (TKeyBoardControl::is_key_down(0x1D) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m45();
            }
            if (TKeyBoardControl::is_key_down(0x20) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m46();
            }
            if (TKeyBoardControl::is_key_down(0x19) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m47();
            }
            if (TKeyBoardControl::is_key_down(0x21) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m48();
            }
            if (TKeyBoardControl::is_key_down(0x1A) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m49();
            }
            if (TKeyBoardControl::is_key_down(0x26) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m50();
            }
            if (TKeyBoardControl::is_key_down(0x22) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m51();
            }
            if (TKeyBoardControl::is_key_down(0x23) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m52();
            }
            if (TKeyBoardControl::is_key_down(0x12) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m53();
            }
            if (TKeyBoardControl::is_key_down(0x13) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m54();
            }
            if (TKeyBoardControl::is_key_down(0x15) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m55();
            }
            if (TKeyBoardControl::is_key_down(0x16) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m56();
            }
            if (TKeyBoardControl::is_key_down(0x28) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m57();
            }
            if (TKeyBoardControl::is_key_down(0x1F) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m58();
            }
            if (TKeyBoardControl::is_key_down(0x10) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m59();
            }
            if (TKeyBoardControl::is_key_down(0x14) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m60();
            }
            if (TKeyBoardControl::is_key_down(0x29) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m61();
            }
            if (TKeyBoardControl::is_key_down(0x27) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m62();
            }
            if (TKeyBoardControl::is_key_down(0x25) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m63();
            }
            if (TKeyBoardControl::is_key_down(0x1B) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m64();
            }
            if (TKeyBoardControl::is_key_down(0x2A) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m67();
            }
            if (TKeyBoardControl::is_key_down(0x2B) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m68();
            }
            if (TKeyBoardControl::is_key_down(0x2C) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m69();
            }
            if (TKeyBoardControl::is_key_down(0x2D) != 0) {
                return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m70();
            }
            goto block_109;
        }
        goto block_109;
    }
block_109:
    return ((s32 (*)(void))ret_801D26AC)();
}

void handle_6xB1(void) {  }

void TObjPlayer::update_dispatch_v76() {

    ((s32 (*)(void))clear_velocity)();
    clear_anim_flag();
    clear_lobby_pose_hold();
    set_motion_list(action_provider->vfunc_76());
}

void TObjPlayer::lobby_animation_phase1_nop() {  }

void TObjPlayer::do_action() {
    this->action_state = 0x17;
    run_action_state_phase(this->mode, 6);
    if (get_action_flag() != 0) {
        update_facing_from_lock();
    }
    if (obj_isState2_324() != 0) {
        this->current_action = ((s16 (*)(void))ret_801D26AC)();
    }
    this->set_action_state(0x17, this->lobby_animation);
    if (get_flag() != 0) {
        set_action_flag_40();
        set_frame(*(f32 *)((s8 *)this + 0x3C4));
    }
}

void handle_6x58_lobby_animation(void *command) {
    Msg_801C851C m;
    Player_801C851C *p;
    ((void (*)(void *))TObjPlayer__sub_801D13EC)(&m);
    ((TObjPlayer *)(&m))->copy_packet_header_6x58(command);
    ((TObjPlayer *)(&m))->bswap_packet();
    if (validate_6x58_lobby_animation(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = (Player_801C851C *)get_player_by_client_id((u16)m.slot);
        if ((p != NULL) && (((TObjPlayer *)p)->is_in_tl03_state() != 0)) {
            p->anim = m.c;
            if (((s32 (*)(void *))TObjPlayer__sub_801D1360)(&m) != 0) {
                ((TObjPlayer *)p)->set_anim_flag();
            }
            ((TObjPlayer *)p)->run_action_state_phase(0x17, 0);
        }
    }
}

void TObjPlayer::send_6x58_lobby_animation() {
    struct Pkt_801C85BC pkt;
    if (this == NULL || this->obj_isState2_324() == 0) {
        ((void (*)(void *))TObjPlayer__sub_801D13EC)(&pkt);
        pkt.id = this->get_entity_id();
        pkt.c = this->lobby_animation;
        if (TKeyBoardControl__sub_801A58D8() != 0) {
            TObjPlayer__sub_801D1440(&pkt);
        }
        ((TObjPlayer *)(&pkt))->handle_recv_packet();
    }
}

void TObjPlayer::lobby_animation_phase8_nop() {  }

void TObjPlayer::update_if_flagged() {
    if ((get_flag() == 0) && (this->motion_flags & 0x10)) {
        update_position_from_target();
    }
}

void TObjPlayer::lobby_animation_phase2_nop() {  }

int TObjPlayer::try_change_action_wrapper(void* p) { return ((TObjPlayer *)p)->try_change_action(); }

void TObjPlayer::run_lobby_animation_state_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  uaddr new_var2;
  unsigned int new_var;
  {
    switch (phase)
    {
      case 7:
        TObjPlayer::try_change_action_wrapper(this);
        return;
      new_var2 = (new_var = arg0);
      case 2:
        lobby_animation_phase2_nop();
        return;
      case 3:
        ((TObjPlayer *)new_var2)->update_if_flagged();
 do { } while (0 != 0);
        return;
      case 8:
        lobby_animation_phase8_nop();
        return;
      case 5:
        send_6x58_lobby_animation();
        return;
      case 0:
        this->do_action();
        return;
      case 1:
        lobby_animation_phase1_nop();
        return;
      case 6:
        this->update_dispatch_v76();
        break;
    }
  }
}

void TObjPlayer::init_effects() { clear_flag_20000(); clear_state_flags((s32)(5)); activate_body_collision(); set_indexed_flags((saddr)((void*)0), (saddr)((void*)1)); reset_player_appearance_opacity(((char*)this + 0x608)); }

void TObjPlayer__deactivate_off_floor_body(void* p) { ((TObjPlayer *)p)->deactivate_body_collision(); }

void TObjPlayer::enter_off_floor_state() {
    this->movement_hold.reset();
    death_sink.reset();
    this->protection.reset_lobby_model();
    this->set_state_flags(4);
    this->deactivate_body_collision();
    this->set_flag_20000();
    this->phase = 0;
    this->set_action_state(0x16, (int) (((s16 (*)(void))ret_801D26AC)()));
}

typedef struct Msg_801C8808 {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801C8808;

void handle_6x57(void *command) {
    Msg_801C8808 m;
    u8 *p;

    ((TObjPlayer *)(&m))->set_cmd_87();
    ((void (*)(void *, void *))handle_6x57__10TObjPlayerFPv)(&m, command);
    bswap_g_client_id_header(&m);
    if (validate_6x57(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = reinterpret_cast<u8 *>(get_player_by_client_id(m.id));
        if (p != NULL) {
            ((TObjPlayer *)p)->run_action_state_phase(0x16, 0);
        }
    }
}

void draw_and_send_field1c__10TObjPlayerFi(TObjPlayer *player) {
    s8 sp8[8];

    if ((player == NULL) || (player->obj_isState2_324() == 0)) {
        ((TObjPlayer *)((s32 *)&sp8))->set_cmd_87();
        *(s16 *)((s8 *)(&sp8) + 2) = player->get_entity_id();
        ((TObjPlayer *)((s32 *)&sp8))->draw_and_send();
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TObjPlayer::update_off_floor_state() {
  f32 var_f31;
  s16 *new_var;
  if (is_on_current_floor__10TObjPlayerFi() != 0)
  {
    this->clear_state_flags(4);
    this->update_active_state();
    ::set_flag_400000((TObjPlayer *)this);
    ((TObjPlayer *)(((u8 *)this) + 0x634))->enter_battle_state();
    return;
  }
  switch (this->phase)
  {
    case 0:
      var_f31 = this->render_material_state.alpha;
      var_f31 = var_f31 - 0.1f;
      if (var_f31 < 0.0f)
    {
      var_f31 = 0.0f;
      new_var = &this->phase;
      *new_var = 1;
      this->set_actor_flags(0x02000000);
      this->clear_player_status_flag(0, 1);
    }
      this->render_material_state.alpha = var_f31;
    case 1:
      return;
  }
}
extern int fold_flush_0;
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TObjPlayer::fade_out_off_floor() {
  f32 var_f0;
  f32 var_f1;
  f32 var_f2;
  s32 var_r4;
  u8 *var_r31;
  u8 *var_r3;
  var_r31 = (u8 *) this;
  if (((s32) is_on_current_floor__10TObjPlayerFi()) != 0)
  {
    var_r3 = (u8 *) var_r31;
    var_r4 = 4;
    ((TObjPlayer *)var_r3)->clear_state_flags(4);
    return;
  }
  switch (*((s16 *) (((s8 *) var_r31) + 0x328)))
  {
    case 0:
      var_f2 = *((f32 *) (((s8 *) var_r31) + 0x624));
      var_f1 = 0.1f;
      var_f0 = 0.0f;
      if (((!var_f0) && (!var_f0)) && (!var_f0))
    {
    }
      var_f2 -= var_f1;
      if (var_f2 < var_f0)
    {
      var_f2 = var_f0;
      *((s16 *) (((s8 *) var_r31) + 0x328)) = 1;
    }
      *((f32 *) (((s8 *) var_r31) + 0x624)) = var_f2;
    case 1:
      return;
  }
}
extern int fold_flush_1;
#pragma pop

void TObjPlayer::off_floor_phase2_nop() {  }

void TObjPlayer::off_floor_phase7_nop() {  }

void TObjPlayer::run_off_floor_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        off_floor_phase7_nop();
        return;
      case 2:
        off_floor_phase2_nop();
        return;
      case 3:
        fade_out_off_floor();
        return;
      case 8:
        update_off_floor_state();
        return;
      case 5:
        draw_and_send_field1c__10TObjPlayerFi(this);
        return;
      case 0:
        enter_off_floor_state();
        return;
      case 1:
        TObjPlayer__deactivate_off_floor_body(this);
        return;
      case 6:
        this->init_effects();
        break;
    }
  }
}

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
void TObjPlayer::start_action_21() {
    this->action_state = 0x15;
    run_action_state_phase(this->mode, 6);
    cleanup_idle_entry();
    clear_player_status_flag(0, 1);
    this->render_material_state.alpha = 0.0f;
    refresh_equipment_slot();
    this->update_actor_ground_y();
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        this->play_sound_if_on_floor(0x40003206);
    }
    this->phase = 1;
    this->set_action_state(0x15, this->get_idle_animation());
}

#undef CAT2
#undef CAT
void handle_6x56_set_player_position_and_angle(void *command) {
    Msg_801C8B5C m;
    Player_801C8B5C *p;
    ((TObjPlayer *)(&m))->init_position_packet();
    ((void (*)(void *, void *))TObjPlayer__sub_801D1514)(&m, command);
    ((TObjPlayer *)(&m))->swap_endian_words();
    if (validate_6x56_set_player_position_and_angle(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = (Player_801C8B5C *)get_player_by_client_id((s32)(m.slot));
        if (p != NULL) {
            p->ang = m.c;
            ((TObjBase *)p)->set_position_from(m.vec);
            ((TObjChara *)p)->calc_attach_pos();
            ((TObjPlayer *)p)->run_action_state_phase(0x15, 0);
        }
    }
}

void TObjPlayer::send_position_update() {
    u8 *arg0 = (u8 *)this;
    struct Pkt_801C8BE8 pkt;
    if (arg0 == NULL || this->obj_isState2_324() == 0) {
        ((TObjPlayer *)(&pkt))->init_position_packet();
        pkt.id = ((TObjBase *)arg0)->get_entity_id();
        pkt.c = *(s32 *)(arg0 + 0x60);
        VecCopy__FP3VecPC3Vec(&pkt.x1, (u8 *)&this->position);
        ((TObjPlayer *)(&pkt))->update_and_send2();
    }
}

void TObjPlayer::sub_801C8C50(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        warp_phase7_nop();
        return;
      case 2:
        warp_phase2_nop();
        return;
      case 3:
        this->check_state_dead();
        return;
      case 8:
        warp_phase8_nop();
        return;
      case 5:
        this->send_position_update();
        return;
      case 0:
        this->start_action_21();
        return;
      case 1:
        this->update_warp_relocation();
        return;
      case 6:
        this->init_flags_vec4();
        break;
    }
  }
}

void send_6x55_intra_map_warp(u16 id, const Vec *destination, s32 yaw) {
    G_IntraMapWarp_6x55 packet;
    TObjPlayer *player = get_player_by_client_id(id);
    if (player != NULL && (player == NULL || player->obj_isState2_324() == 0)) {
        packet.init();
        packet.header.client_id = id;
        packet.angle_y = yaw;
        VecCopy(&packet.from_pos, &player->position);
        VecCopy(&packet.pos, destination);
        packet.send();
    }
}

void TObjPlayer::init_flags_vec4() { set_indexed_flags((saddr)((void*)0), (saddr)((void*)1)); ((TObjPlayer *)((char*)this + 0x608))->set_vec4_const(); }

void TObjPlayer::update_warp_relocation() {
    Vec pos;
    f32 var_f2;
    f32 var_f31;
    s32 temp;

    switch (this->phase) {
    case 0:
        var_f31 = this->render_material_state.alpha;
        var_f31 -= 0.1f;
        if (var_f31 < 0.0f) {
            var_f31 = 0.0f;
            this->phase = 3;
            this->rotation_y = warp_yaw;
            this->set_position_from(&warp_destination);
            refresh_equipment_slot();
            this->set_flag_4000();
            this->update_actor_ground_y();
            if (((s32 (*)(void *))is_on_current_floor__10TObjPlayerFi)(this) != 0) {
                this->play_sound_if_on_floor(0x40003206);
            }
            if (TObjPlayer::is_locally_controlled(this) != 0) {
                calc_circle_offset_pos(this->rotation_y + 0x8000, this->get_position_ptr(), &pos, 10.0f);
                send_6x3e_to_all_players(&pos, this->rotation_y);
                reset_cameras_to_actor(this, 1);
            }
        }
        this->render_material_state.alpha = var_f31;
        break;
    case 1:
        if (this->is_inactive() != 0) {
            this->phase = 2;
            *(s32 *)((s8 *)((u8 *)this) + 0x658) = 4;
        }
        break;
    case 4:
        break;
    case 2:
        temp = *(s32 *)((s8 *)((u8 *)this) + 0x658) - 1;
        *(s32 *)((s8 *)((u8 *)this) + 0x658) = temp;
        if (temp <= 0) {
            this->phase = 3;
            activate_body_collision();
            if (((s32 (*)(void *))is_on_current_floor__10TObjPlayerFi)(this) != 0) {
                spawn_appearance_effect(get_entity_id());
            }
        }
        break;
    case 3:
        this->clear_flag_4000();
        var_f2 = this->render_material_state.alpha;
        var_f2 += 0.1f;
        if (var_f2 >= 1.0f) {
            var_f2 = 1.0f;
            this->phase = 4;
        }
        this->render_material_state.alpha = var_f2;
        break;
    }
}

void TObjPlayer::set_dead_state() {
    this->action_state = 0x14;
    run_action_state_phase(this->mode, 6);
    clear_velocity(this);
    clear_player_status_flag(0, 1);
    this->phase = 0;
    this->play_sound_if_on_floor(0x40003205);
    this->set_action_state(0x14, this->get_idle_animation());
}

void handle_6x55_intra_map_warp(game_command_header *command) {
    G_IntraMapWarp_6x55 packet;
    packet.init();
    TObjPlayer__sub_801D0EA0(&packet, reinterpret_cast<G_IntraMapWarp_6x55 *>(command));
    packet.bswap();
    if (validate_6x55_intra_map_warp(&packet.header) != 0) {
        TObjPlayer *player = get_player_by_client_id(packet.header.client_id);
        if (player != NULL && player->is_in_tl03_state() != 0 && player->test_action_mask(0x8200) == 0) {
            player->warp_yaw = packet.angle_y;
            player->set_position_from(&packet.from_pos);
            VecCopy(&player->warp_destination, &packet.pos);
            player->run_action_state_phase(0x14, 0);
        }
    }
}

void TObjPlayer::send_warp_position() {
    G_IntraMapWarp_6x55 packet;
    if (this == NULL || obj_isState2_324() == 0) {
        packet.init();
        packet.header.client_id = this->get_entity_id();
        packet.angle_y = rotation_y;
        VecCopy(&packet.from_pos, &position);
        VecCopy(&packet.pos, &position);
        packet.send();
    }
}

void TObjPlayer::warp_phase8_nop() {  }

void TObjPlayer::check_state_dead() { if (this->phase == 4) { update_position_from_target(); } }

void TObjPlayer::warp_phase2_nop() {  }

void TObjPlayer::warp_phase7_nop() {  }

void TObjPlayer::run_warp_action_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  saddr new_var;
  {
    new_var = arg0;
    switch (phase)
    {
      case 7:
        warp_phase7_nop();
        return;
      case 2:
        warp_phase2_nop();
        return;
      case 3:
        ((TObjPlayer *)new_var)->check_state_dead();
        return;
      case 8:
        warp_phase8_nop();
        return;
      case 5:
        ((TObjPlayer *)new_var)->send_warp_position();
        return;
      case 0:
        this->set_dead_state();
        return;
      case 1:
        ((TObjPlayer *)new_var)->update_warp_relocation();
        return;
      case 6:
        this->init_flags_vec4();
        break;
    }
  }
}

void TObjPlayer::reset_lobby_state() {
    u8 *arg0 = (u8 *)this;
    ((s32 (*)(void))clear_status_bit6__10TObjPlayerFPv)();
    clear_velocity(arg0);
    this->clear_actor_flags((u32)0x20);
    if (((s16) this->phase == 1) && (TObjPlayer::is_locally_controlled(arg0) != 0)) {
        ((TObjPlayer *)arg0)->protection.reset_lobby_model();
    }
}

void TObjPlayer::try_use_mag() {
    u8 *arg0 = (u8 *)this;
    if ((((TObjPlayer *)this)->is_frozen() == 0) && (TObjPlayer::is_locally_controlled(arg0) != 0) && (stick_escape_detector.check_input_angle() != 0)) {
        this->add_status_effect_timer(1, *(s32 *)((s8 *)arg0 + 0x3D4));
    }
}

void TObjPlayer::enter_freeze_action() {
    this->action_state = 0x13;
    run_action_state_phase(this->mode, 6);
    clear_velocity(this);
    clear_actor_flags((u32)0x200);
    set_action_flag_40();
    if (this->is_frozen() != 0) {
        this->phase = 1;
    } else {
        this->phase = 0;
        *(s32 *)((s8 *)this + 0x3D4) = (s32) -(lbl_80447128 * (f64) this->get_status_effect_timer(1));
    }
    this->set_action_state(0x13, (s16) ((s16 (*)(void))ret_801D26AC)());
}

typedef struct Msg_801C9350 {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801C9350;
void* update_small_font2__10TObjPlayerFPv(void* p);

void handle_6x53(void *command) {
    Msg_801C9350 m;
    u8 *p;

    ((TObjPlayer *)(&m))->set_type_53();
    ((void (*)(void *, void *))update_small_font2__10TObjPlayerFPv)(&m, command);
    bswap_g_client_id_header(&m);
    if (validate_6x53(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = reinterpret_cast<u8 *>(get_player_by_client_id(m.id));
        if (p != NULL && ((TObjPlayer *)p)->is_in_tl03_state() != 0) {
            ((TObjPlayer *)p)->run_action_state_phase(0x13, 0);
        }
    }
}

void* update_small_font2__10TObjPlayerFPv(void* p) { copy_subcommand_header(p); return p; }

void TObjPlayer::send_name_and_state() {
    u8 *arg0 = (u8 *)this;
    MsgA_801C9400 a;
    MsgB_801C9400 b;
    if (((TObjPlayer *)this)->is_frozen() == 0) {
        init_stick_escape_detector(&stick_escape_detector, pad_binding.get_controller());
    }
    if ((arg0 == NULL) || (this->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&a))->set_type_53();
        a.f2 = ((s16)((TObjBase *)arg0)->get_entity_id());
        ((TObjPlayer *)(&a))->send_name();
        ((TObjPlayer *)(&b))->init_6x2F_packet_header();
        b.f2 = ((s16)((TObjBase *)arg0)->get_entity_id());
        b.f4 = 0;
        b.f8 = ((s16)this->get_actor_hp());
        b.fa = ((s16)((TObjBase *)arg0)->get_entity_id());
        TObjPlayer__sub_801C0734(&b);
    }
}

void TObjPlayer::return_to_idle_when_unfrozen() {
    switch (this->phase) {
    case 1:
        if (this->is_frozen() == 0) {
            this->run_action_state_phase(1, 0);
        }
        break;
    }
}

void TObjPlayer::update_gated_action() {
    u16 temp_r31;

    if (this->phase == 0) {
        if (((TObjPlayer *)this)->is_status_flag_200() != 0) {
            temp_r31 = this->get_entity_id();
            send_6x2F_change_player_hp(temp_r31, temp_r31, get_actor_hp());
            clear_actor_flags((u32)0x200);
            return;
        }
        if (can_guard() != 0) {
            use_current_item();
        }
    }
}

void TObjPlayer::freeze_phase2_nop() {  }

void TObjPlayer::update_frozen_release() {
    u8 *arg0 = (u8 *)this;
  s16 temp_r0;
  if (this->test_actor_flags(0x800) != 0)
  {
    ((FlagWord *)(arg0 + 0x858))->clear(1);
    run_action_state_phase(0xF, 5);
    return;
  }
  ;
  switch (this->phase)
  {
    return;
    case 0:
      if (check_flag30_bit20() == 0)
    {
      this->update_position_from_target();
    }
      return;
    case 1:
      if (this->is_frozen() == 0)
    {
      this->update_position_from_target();
    }
      break;
  }
}

void TObjPlayer::run_freeze_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->update_frozen_release();
        return;
      case 2:
        freeze_phase2_nop();
        return;
      case 3:
        this->update_gated_action();
        return;
      case 8:
        return_to_idle_when_unfrozen();
        return;
      case 5:
        this->send_name_and_state();
        return;
      case 0:
        this->enter_freeze_action();
        return;
      case 1:
        this->try_use_mag();
        return;
      case 6:
        this->reset_lobby_state();
        break;
    }
  }
}

s32 TObjPlayer::try_change_action() {
    if (this->is_status_locked() != 0) {
        if (anim_state.get_action_id() == 0x10) {
            run_action_state_phase(0x10, 5);
        } else {
            this->clear_actor_flags((uaddr)((void*)(0x10000)));
            run_action_state_phase(anim_state.get_action_id(), 5);
            anim_state.set_action_id(0);
        }
        return 1;
    }
    return 0;
}

void TObjPlayer::clear_flag() { clear_actor_flags((uaddr)((void*)((void*)65536))); ((int (*)(void*))clear_velocity)(this); }

void apply_velocity_if_free__10TObjPlayerFPv(void *player) {
    void *x;
    x = ((void * (*)(void *))resolve_move_collision__10TObjPlayerFv)(player);
    if (x == NULL) {
        ((TObjPlayer *)player)->apply_velocity();
    }
}

void TObjPlayer::enter_service_hold_action() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x33C) = 0x10;
    run_action_state_phase(this->mode, 6);
    this->requested_action = anim_state.get_animation();
    this->rotation_y = anim_state.get_angle();
    this->set_action_state(0x10, (int) (((s16 (*)(void))ret_801D26AC)()));
}

void handle_6x52_set_animation_state(saddr command) {
    Pkt_801C9838 pkt;
    TObjPlayer *player;
    ((TObjPlayer *)(&pkt))->init_6x52_packet();
    ((TObjPlayer *)(&pkt))->copy_font_state((void *) (command));
    ((TObjPlayer *)(&pkt))->swap_stats_bytes();
    if (validate_6x52_set_animation_state(reinterpret_cast<G_ClientIDHeader *>(&pkt)) != 0) {
        player = get_player_by_client_id(pkt.client);
        if ((player != NULL) && (player->is_in_tl03_state() != 0) && (player->test_action_mask(0x8000) == 0) && ((TFontSmallLobby::is_lobby_floor_15() == 0) || (player->obj_isState2_324() == 0) || (player->check_flag(0x04000000) == 0))) {
            player->anim_state.set_animation(pkt.c);
            player->anim_state.set_angle(pkt.g);
            player->anim_state.set_state(pkt.e);
            player->run_action_state_phase(0x10, 0);
        }
    }
}

void TObjPlayer::send_6x52_animation_state() {
    u8 *arg0 = (u8 *)this;
    struct Pkt_801C9924 pkt;
    if (arg0 == NULL || this->obj_isState2_324() == 0) {
        ((TObjPlayer *)(&pkt))->init_6x52_packet();
        pkt.id = ((TObjBase *)arg0)->get_entity_id();
        pkt.a = anim_state.get_animation();
        pkt.c = anim_state.get_angle();
        pkt.b = anim_state.get_state();
        ((TObjPlayer *)(&pkt))->update_display();
    }
}

void TObjPlayer::service_hold_phase8_nop() {  }

void TObjPlayer::update_service_hold() {
    if (!(this->actorFlags & 0x10000)) {
        if (anim_state.get_action_id() == 0) {
            update_position_from_target();
            return;
        }
        run_action_state_phase(anim_state.get_action_id(), 5);
        anim_state.set_action_id(0);
    }
}

void TObjPlayer::service_hold_phase2_nop() {  }

void TObjPlayer::set_motion() {
    if (is_status_flag_200() != 0) {
        if (test_actor_flags(0x400) != 0) {
            run_action_state_phase(0xE, 5);
            return;
        }
        run_action_state_phase(0xD, 5);
        return;
    }
    if (can_guard() != 0) {
        run_action_state_phase(0xA, 5);
        return;
    }
    if (check_flag30_bit20() != 0) {
        run_action_state_phase(0x13, 5);
    }
}

void TObjPlayer::run_service_hold_state_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  uaddr new_var2;
  unsigned int new_var;
  {
    switch (phase)
    {
      case 7:
        set_motion();
        return;
      new_var2 = (new_var = arg0);
      case 2:
        TObjPlayer::service_hold_phase2_nop();
        return;
      case 3:
        ((TObjPlayer *)new_var2)->update_service_hold();
 do { } while (0 != 0);
        return;
      case 8:
        TObjPlayer::service_hold_phase8_nop();
        return;
      case 5:
        this->send_6x52_animation_state();
        return;
      case 0:
        this->enter_service_hold_action();
        return;
      case 1:
        ((s32 (*)(void))apply_velocity_if_free__10TObjPlayerFPv)();
        return;
      case 6:
        this->clear_flag();
        break;
    }
  }
}

void TObjPlayer::notify_lobby() {
    ((s32 (*)(void))clear_status_bit6__10TObjPlayerFPv)();
    TWindowCtrl::enable_client_main_menu(this->get_entity_id());
}

void TObjPlayer::ensure_default() {
    void *x;
    x = ((void * (*)(void *))resolve_move_collision__10TObjPlayerFv)(this);
    if (x == NULL) {
        this->apply_velocity();
    }
}

void TObjPlayer::init_action() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x33C) = 0x12;
    run_action_state_phase(this->mode, 6);
    clear_velocity(arg0);
    this->protection.set_frames(0x12C);
    this->phase = 0;
    this->frame_timer = 44.0f;
    this->set_attacker_id(0xFFFF);
    this->set_action_state(0x12, (s16) ((s32 (*)(void))ret_801D26AC)());
    disable_motion_blend();
    if (is_current_area_item_enabled() != 0) {
        new TTecReverserEff(this, tl_07);
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x548) != 0U) {
        ((TObject *)(*(void **)((s8 *)arg0 + 0x548)))->queue_destruction();
        *(u32 *)((s8 *)arg0 + 0x548) = 0U;
    }
}

typedef struct Msg_801C9C8C {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801C9C8C;

void handle_6x4F_player_revived(void *command) {
    Msg_801C9C8C m;
    u8 *p;

    ((TObjPlayer *)(&m))->set_revived_state();
    ((void (*)(void *, void *))handle_6x4F_revived__10TObjPlayerFi)(&m, command);
    bswap_g_client_id_header(&m);
    if (validate_6x4F_player_revived(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = reinterpret_cast<u8 *>(get_player_by_client_id(m.id));
        if (p != NULL && ((TObjPlayer *)p)->is_in_tl03_state() != 0) {
            ((TObjPlayer *)p)->run_action_state_phase(0x12, 0);
        }
    }
}

s32 handle_6x4F_revived__10TObjPlayerFi(s32 arg0) {
    ((s32 (*)(void))copy_subcommand_header)();
    return arg0;
}

void TObjPlayer::send_6x4F_revived() {
    uaddr arg0 = (uaddr)this;
    struct Local801C9D3C sp8;

    if (((s32 (*)(s32, s32))test_flags_any)(arg0 + 0x858, 4) != 0) {
        send_code_49_1__10TObjPlayerFi(arg0);
        if (this->is_alive_and_ready() != 0) {
            this->refill_traps();
        }
    } else {
        ((TObjPlayer *)arg0)->send_6xA1_player_id();
    }
    ((TObjPlayer *)arg0)->photon_blast_gauge.update_if_ready();
    if ((arg0 == 0U) || (this->obj_isState2_324() == 0)) {
        ((TObjPlayer *)((s32 *)&sp8))->set_revived_state();
        sp8.fieldA = ((TObjBase *)arg0)->get_entity_id();
        ((TObjPlayer *)((s32 *)&sp8))->broadcast_lobby_display();
    }
}

void TObjPlayer::update_timer_state() {
    f32 temp_f1;
    f32 temp_f1_2;

    switch (this->phase) {
    case 0:
        temp_f1 = this->frame_timer - 1.0f;
        this->frame_timer = temp_f1;
        if (temp_f1 < 0.0f) {
            this->phase = 1;
            this->TObjMotion::init(this->get_idle_animation());
            this->set_action_flag_40();
            this->frame_timer = 24.0f;
        }
        break;
    case 1:
        temp_f1_2 = this->frame_timer - 1.0f;
        this->frame_timer = temp_f1_2;
        if (temp_f1_2 < 0.0f) {
            ((s32 (*)(void))clear_status_bit6__10TObjPlayerFPv)();
            this->run_action_state_phase(1, 0);
        }
        break;
    }
}

void TObjPlayer::update_timer_action() {
    u8 *arg0 = (u8 *)this;
    f32 frame_timer;
    f32 temp_f1_2;

    switch (this->phase) {
    case 0:
        frame_timer = this->frame_timer - 1.0f;
        this->frame_timer = frame_timer;
        if (frame_timer < 0.0f) {
            this->phase = 1;
            TObjMotion::init(this->get_idle_animation());
            set_action_flag_40();
            this->frame_timer = 24.0f;
        }
        break;
    case 1:
        temp_f1_2 = this->frame_timer - 1.0f;
        this->frame_timer = temp_f1_2;
        if (temp_f1_2 < 0.0f) {
            ((s32 (*)(void))clear_status_bit6__10TObjPlayerFPv)();
            this->protection.set_frames((saddr)this->get_getup_protection_ticks());
            ((TObjPlayer *)arg0)->update_position_from_target();
        }
        break;
    }
}

void TObjPlayer::revival_phase2_nop() {  }

void TObjPlayer::revival_phase7_nop() {  }

void TObjPlayer::run_revival_state_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  uaddr new_var2;
  unsigned int new_var;
  {
    switch (phase)
    {
      case 7:
        revival_phase7_nop();
        return;
      new_var2 = (new_var = arg0);
      case 2:
        revival_phase2_nop();
        return;
      case 3:
        ((TObjPlayer *)new_var2)->update_timer_action();
 do { } while (0 != 0);
        return;
      case 8:
        update_timer_state();
        return;
      case 5:
        this->send_6x4F_revived();
        return;
      case 0:
        this->init_action();
        return;
      case 1:
        ensure_default();
        return;
      case 6:
        notify_lobby();
        break;
    }
  }
}

void handle_6x89_set_killer_entity_id(void *command) {
    struct Pkt_801C9FE8 pkt;
    u8 *p;
    ((TObjPlayer *)(&pkt))->init_6x89_packet();
    ((TObjPlayer *)(&pkt))->copy_head_fields(command);
    ((TObjPlayer *)(&pkt))->bswap_fields();
    if (validate_6x89_set_killer_entity_id(reinterpret_cast<G_ClientIDHeader *>(&pkt)) != 0) {
        p = reinterpret_cast<u8 *>(get_player_by_client_id(pkt.id));
        if (p != NULL) {
            *(u16 *)(p + 0x2D4) = pkt.c;
        }
    }
}
}
s32 validate_6x45_attack(G_ClientIDHeader *packet);
s32 validate_6x44_attack(G_ClientIDHeader *packet);
s32 validate_6x43_attack(G_ClientIDHeader *packet);
s32 validate_6x42_move_to_position(G_ClientIDHeader *packet);
s32 validate_6x40_walk_to_position(G_ClientIDHeader *packet);
s32 validate_6x3F_set_position(G_ClientIDHeader *packet);
s32 validate_6x3E_stop_at_position(G_ClientIDHeader *packet);
s32 validate_6x37_photon_blast(G_ClientIDHeader *packet);
s32 validate_6x33_revive_player(G_ClientIDHeader *packet);
void init_subobject(TObjPlayer *player) {
    if (player != NULL) {
        player->run_action_state_phase(0xF, 0);
        player->update_action_render();
        player->death_sink.reset();
        player->death_sink.calc_height(player);
        player->death_sink.set_progress(1.0f);
    }
}

void queue_player_injured_pose(TObjPlayer *player) {
    new TPlayerReadyCallback(player, player->get_entity_id(), init_subobject);
}

extern "C" {

void TObjPlayer::update_active_state() {
    u8 *arg0 = (u8 *)this;
    if (is_on_current_floor__10TObjPlayerFi() != 0) {
        this->clear_state_flags(4);
        if (this->test_actor_flags(0x800) == 0) {
            run_action_state_phase(1, 0);
            return;
        }
        run_action_state_phase(0xF, 0);
        if (((s32 (*)(void *, s32))test_flags_any)(arg0 + 0x858, 1) != 0) {
            this->requested_action = this->get_action_animation();
        } else {
            this->restart_death_pose();
        }
        death_sink.set_progress(1.0f);
        this->revive_or_spawn_marker();
    }
}

typedef struct Msg_801CA1C4 {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801CA1C4;

void handle_6x4E_player_revivable(void *command) {
    Msg_801CA1C4 m;
    u8 *p;

    ((TObjPlayer *)(&m))->init_revive_packet();
    ((void (*)(void *, void *))handle_revivable__10TObjPlayerFi)(&m, command);
    bswap_g_client_id_header(&m);
    if (validate_6x4E_player_revivable(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = reinterpret_cast<u8 *>(get_player_by_client_id(m.id));
        if (p != NULL && ((TObjPlayer *)p)->is_in_tl03_state() != 0) {
            ((TObjPlayer *)p)->update_action_render();
            ((TObjPlayer *)p)->revive_or_spawn_marker();
        }
    }
}

s32 handle_revivable__10TObjPlayerFi(s32 arg0) {
    ((s32 (*)(void))copy_subcommand_header)();
    return arg0;
}

void TObjPlayer::send_6x4E_player_revivable(saddr arg0) {
    struct S801CA274 sp8;

    if ((arg0 == 0) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&sp8))->init_revive_packet();
        sp8.h = ((TObjBase *)arg0)->get_entity_id();
        ((TObjPlayer *)(&sp8))->bswap_font_lobby2();
    }
}

void TObjPlayer::update_action_render() {
    u8 *arg0 = (u8 *)this;
    if (test_flags_any((void *) (arg0 + 0x858), 1) != 0) {
        this->requested_action = this->get_action_animation();
    } else {
        this->requested_action = this->get_model_field_m25();
    }
    this->set_animation((int) (this->requested_action));
    this->frame = (f32) (this->frame_count - 1.0f);
    TObjPlayer::draw(arg0, (f32) (this->frame));
    set_action_flag_40();
    this->motion_flags = (s32) (this->motion_flags & 0xFFFFFFDF);
}

void TObjPlayer::restart_death_pose() {
    u8 *arg0 = (u8 *)this;
    this->update_action_render();
    death_sink.reset();
    death_sink.calc_height(this);
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        *(TObject **)((s8 *)arg0 + 0x548) = new TDeathTintFade(tl_particlemodel, complete_deferred_player_death, get_entity_id());
    }
}

void TObjPlayer::reset_on_death() {
    set_actor_flags(0x800U);
    this->hp = 0;
    this->clear_all_status_effects();
    protection.reset_lobby_model();
    death_sink.reset();
}

void TObjPlayer::exit_death_state() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)arg0 + 0x30) & 0xFFFFFDFF;
    *(s32 *)((s8 *)arg0 + 0x30) = temp_r4;
    *(s32 *)((s8 *)arg0 + 0x36C) = 0;
    ((TObjPlayer *)arg0)->death_sink.reset();
    ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(arg0);
}

void TObjPlayer::update_death_pose() {
    if ((test_motion_flags(0x20) != 0) && ((s16) this->requested_action == (s16) this->current_action)) {
        this->restart_death_pose();
    }
    death_sink.add_progress(0.002f);
    death_sink.update_offset();
    if (this->resolve_move_collision() == 0U) {
        this->apply_velocity();
    }
}

void TObjPlayer::enter_death_state() {
    TObjCollidable *entity;
    u8 *arg0 = (u8 *)this;
    u32 entity_id;
    u32 other;
    s32 killer;
    u8 *culprit;
    u8 *character_save_record;
    u8 *temp_r3_3;
    *(s32 *)((s8 *)arg0 + 0x33C) = 0xF;
    run_action_state_phase(this->mode, 6);
    reset_on_death();
    clear_velocity(this);
    this->phase = 0;
    if (test_flags_any((void *) (arg0 + 0x858), 1) != 0) {
        this->set_action_state(0xF, (s32)(((s16 (*)(void))ret_801D26AC)()));
        this->restart_death_pose();
    } else {
        this->set_action_state(0xF, this->get_model_field_m25());
    }
    ((TObjPlayer *)arg0)->photon_blast_gauge.clear_photon_blast_state();
    if (TTecCtrl::is_technique_ready() != 0) {
        entity = reinterpret_cast<TObjCollidable *>(find_entity_by_id(this->get_attacker_id()));
        if (entity != NULL) {
            if (entity->check_value_equals(lbl_805D3530) != 0) {
                entity_id = (u16)((TObjBase *)arg0)->get_entity_id();
                other = (u16)((TObjBase *)entity)->get_entity_id();
                if (other != entity_id) {
                    fn_801B0480((saddr) (entity), this, 1);
                }
            }
            if (entity->check_value_equals(TOMineTrap__data_805D3080) == 0) {
                accumulate_damage_stats_at_76c((saddr)arg0, (saddr)entity, 1);
            } else if ((u16)(killer = get_trap_type__10TOMineTrapFv((saddr)entity)) == 0xffffU) {
                accumulate_damage_stats_at_76c((saddr)arg0, (saddr)entity, 1);
            } else {
                culprit = find_entity_by_id(killer);
                accumulate_damage_stats_at_76c((saddr)arg0, (saddr)culprit, 1);
            }
            draw_player_status(this, (void *) (entity), "\tC9");
        }
        draw_player_status(this, this, "\tC8");
        if (TObjPlayer::is_locally_controlled(this) != 0) {
            play_duel_result_stream("death.adx", 0x96);
        }
    }
    if ((TObjPlayer::is_locally_controlled(this) != 0) && (TObjPlayer::is_camera_mode_active() == 0) && (TTecCtrl::is_technique_ready() == 0)) {
        if (TObjPlayer::is_single_screen() != 0) {
            character_save_record = ((u8 *)get_character_save_record((u16)(this->get_entity_id())));
            *(s32 *)((s8 *)character_save_record + 0x244) = (s32) (*(s32 *)((s8 *)character_save_record + 0x244) + 1);
            return;
        }
        temp_r3_3 = ((u8 *)get_character_save_record((u16)(0xFFFFU)));
        *(s32 *)((s8 *)temp_r3_3 + 0x244) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0x244) + 1);
    }
}

void handle_6x4D_player_died(void *command) {
    Cmd_801CA724 cmd;
    u8 *p;
    ((TObjPlayer *)(&cmd))->init_6x4D_packet();
    ((s32 (*)(void *, void *))TObjPlayer__sub_801D28A0)(&cmd, command);
    ((TObjPlayer *)(&cmd))->init_field_4();
    if (validate_6x4D_player_died(reinterpret_cast<G_ClientIDHeader *>(&cmd)) != 0) {
        p = (u8 *)get_player_by_client_id(cmd.client);
        if (p != NULL) {
            TObjPlayer__sub_801BEEE0(p + 0x858, cmd.data);
            ((TObjPlayer *)p)->reset_on_death();
            if (((TObjPlayer *)p)->is_in_tl03_state() != 0) {
                ((TObjPlayer *)p)->run_action_state_phase(0xF, 0);
            }
        }
    }
}

void TObjPlayer::prepare_death() {
    u8 *arg0 = (u8 *)this;
    Cmd_801CA7BC c1;
    Cmd2_801CA7BC c2;
    if (TObjPlayer::is_locally_controlled(arg0) != 0) {
        TWindowCtrl::disable_client_main_menu((u16)((TObjBase *)arg0)->get_entity_id());
        *(s32 *)(arg0 + 0x36C) = 0;
        *(s32 *)(arg0 + 0x548) = 0;
        ((FlagWord *)(arg0 + 0x858))->clear(4);
        if (this->find_revival_item() == 0) {
            ((FlagWord *)(arg0 + 0x858))->set(2);
        }
    }
    if (test_flags_any((u8 *)&this->m_858, 1) == 0) {
        this->drop_items_on_death();
    }
    if (is_flag_400_set__10TObjPlayerFPv(arg0) != 0) {
        enable_action_input__10TObjPlayerFPv(arg0);
    }
    if (this->lock_on_cursor != NULL && ((TMainCursor *)this->lock_on_cursor)->is_cursor_clear() == 0) {
        ((TObjPlayer *)this->lock_on_cursor)->clear_flag_1_at_1c();
    }
    if (arg0 == NULL || this->obj_isState2_324() == 0) {
        ((TObjPlayer *)(&c1))->init_6x89_packet();
        c1.client = ((TObjBase *)arg0)->get_entity_id();
        c1.val = this->get_attacker_id();
        ((TObjPlayer *)(&c1))->update_and_send3();
        ((TObjPlayer *)(&c2))->init_6x4D_packet();
        c2.client = ((TObjBase *)arg0)->get_entity_id();
        TObjPlayer__sub_801BEEE0(c2.data, &this->m_858);
        ((TObjPlayer *)(&c2))->init_and_send();
    }
}

void TObjPlayer::set_death_marker_pos() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)(this->bodies) + 0x1C) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)(this->bodies) + 0x20) = (f32) (8.0f + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)(this->bodies) + 0x24) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    ((TObjBase *)arg0)->set_actor_flags(0x800U);
}

void TObjPlayer::request_revival_if_not_dead() {
    if (this->test_actor_flags(0x800) == 0) {
        run_action_state_phase(0x12, 5);
    }
}

void TObjPlayer::check_reopen_return_city_window() {
    u8 *arg0 = (u8 *)this;
  unsigned short new_var;
  uaddr temp_r3;
  new_var = (s32) this->get_entity_id();
  TWindowCtrl::disable_client_main_menu(new_var);
  temp_r3 = this->m_36c;
  new_var = 0U;
  if ((temp_r3 != new_var) && ((((TObject *)temp_r3)->all_parents_unqueued_for_destruction() == 0) || (reinterpret_cast<TObject *>(m_36c)->check_value_equals(TWindowReturnCity::class_name) == 0)))
  {
    this->m_36c = 0U;
  }
  if (((((pad_binding.is_button_pressed(4) != 0) && (TObjPlayer::is_camera_mode_active() == 0)) && (TTecCtrl::is_technique_ready() == 0)) && ((TObjPlayer::check_camera_mode() == 0) || ((TObjPlayer::check_camera_mode() != 0) && (get_main_phase() == 0xF)))) && (is_controls_locked() == 0))
  {
    this->create_return_city_window();
  }
}

void TObjPlayer::death_phase7_nop() {  }

void TObjPlayer::run_death_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        death_phase7_nop();
        return;
      case 2:
        this->check_reopen_return_city_window();
        return;
      case 3:
        this->request_revival_if_not_dead();
        return;
      case 8:
        this->set_death_marker_pos();
        return;
      case 5:
        this->prepare_death();
        return;
      case 0:
        this->enter_death_state();
        return;
      case 1:
        this->update_death_pose();
        return;
      case 6:
        this->exit_death_state();
        break;
    }
  }
}

int TObjPlayer::exit_fall_reaction(void* p) { return ((int (*)(void*))clear_velocity)(p); }

void TObjPlayer::update_fall_reaction() {
    f32 frame_timer;
    switch (this->phase) {
    case 0:
        if (is_passing_frame(10.0f) != 0) {
            if (classify_action_state() == 2) {
                this->play_sound_if_on_floor(0x40002320);
            } else {
                this->play_sound_if_on_floor(0x40009E14);
            }
        }
        if (this->motion_flags & 0x10) {
            this->phase = 1;
            this->frame_timer = 30.0f;
        }
        break;
    case 1:
        frame_timer = this->frame_timer - 1.0f;
        this->frame_timer = frame_timer;
        if (frame_timer < 0.0f) {
            this->phase = 2;
            this->requested_action = query_child_state2();
        }
        break;
    case 2:
        break;
    }
    ((s32 (*)(void *))damp_planar_velocity)(this);
    if (check_actor_blocking_move() != 0) {
        clear_velocity(this);
    }
    if (resolve_move_collision() == 0U) {
        apply_velocity();
    }
}

void start_action_0e__10TObjPlayerFPv(u8 *arg0) {
    s32 sp8;

    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&sp8, arg0 + 0x308);
    *(s32 *)((s8 *)arg0 + 0x33C) = 0xE;
    ((TObjPlayer *)arg0)->run_action_state_phase(((TObjPlayer *)arg0)->mode, 6);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x308, &sp8);
    ((ProtectionTimer *)(arg0 + 0x644))->set_frames(0x12C);
    ((TObjBase *)arg0)->clear_actor_flags((u32)0x10000);
    ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x4000AD13);
    if (((TObjChara *)arg0)->obj_isState2_324() != 0) {
        ((TObjChara *)arg0)->trigger_switch_attack((const Vec *)((TObjChara *)arg0)->get_center());
    }
    ((TObjPlayer *)arg0)->phase = 0;
    ((TObjPlayer *)arg0)->set_action_state(0xE, ((TObjPlayer *)arg0)->get_action_animation());
}

void handle_6x4C_hit_by_enemy(void *command) {
    Msg_801CACD8 m;
    Player_801CACD8 *p;

    ((TObjPlayer *)(&m))->init_6x4C_packet();
    ((void (*)(void *, void *))copy_6x4c_hit_by_enemy_packet__10TObjPlayerFPvPv)(&m, command);
    ((TObjPlayer *)(&m))->bswap_head_pair();
    if (validate_6x4C_hit_by_enemy(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = (Player_801CACD8 *)get_player_by_client_id(m.id);
        if (p != NULL && ((TObjPlayer *)p)->test_action_mask(0x8000) == 0) {
            ((TObjPlayer *)p)->set_hp_clamped(m.kind);
            if (((TObjPlayer *)p)->is_in_tl03_state() != 0 && reset_volopt_state__10TObjPlayerFv(p) != 0) {
                p->ang = m.ang;
                p->x = m.x;
                p->z = m.z;
                ((TObjPlayer *)p)->run_action_state_phase(0xE, 0);
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjPlayer::begin_fall_reaction() {
    f32 x;
    f32 z;
    Pkt_801CADA4 pkt;
    z = this->velocity.z;
    x = *(f32 *)((s8 *)this + 0x308);
    if (newton_sqrtf(x * x + z * z) > 1e-05f) {
        this->rotation_y = (s32) ((s32) (lbl_80447148 * atan2_float(x, z)) + 0x8000);
    }
    if (test_actor_flags(0x800) != 0) {
        drop_items_on_death();
    }
    TObjPlayer::spawn_effect((saddr)this);
    if ((this == NULL) || (obj_isState2_324() == 0)) {
        ((TObjPlayer *)(&pkt))->init_6x4C_packet();
        pkt.id = this->get_entity_id();
        pkt.dir = (s16) this->rotation_y;
        pkt.f6 = this->hp;
        pkt.x = x;
        pkt.z = z;
        ((TObjPlayer *)(&pkt))->send_head_pair_packet();
    }
}
extern int fold_flush_2;
#pragma pop

void TObjPlayer::fall_reaction_phase8_nop() {  }

void TObjPlayer::complete_fall_reaction() {
    u8 *arg0 = (u8 *)this;
    switch (this->phase) {
    case 1:
        if (((s16) this->requested_action == this->get_action_animation()) && (this->motion_flags & 0x10) && (this->test_actor_flags(0x800) != 0)) {
            ((FlagWord *)(arg0 + 0x858))->set(1);
            run_action_state_phase(0xF, 5);
        }
        break;
    case 2:
        if (this->motion_flags & 0x10) {
            ((ProtectionTimer *)(arg0 + 0x644))->set_frames((saddr)get_getup_protection_ticks());
            update_position_from_target();
        }
        break;
    }
}

void TObjPlayer::fall_reaction_phase2_nop() {  }

void TObjPlayer::check_and_trigger_19_5() { if (check_flag30_bit20() != 0) { run_action_state_phase(19, 5); } }

void TObjPlayer::run_fall_reaction_phase(s16 phase) {
  void *new_var;
  {
    switch (phase)
    {
      case 7:
        this->check_and_trigger_19_5();
        return;
      case 2:
        fall_reaction_phase2_nop();
        return;
      case 3:
        ((TObjPlayer *)(new_var = this))->complete_fall_reaction();
        return;
      case 8:
        fall_reaction_phase8_nop();
        return;
      case 5:
        this->begin_fall_reaction();
        return;
      new_var = this;
      case 0:
        ((s32 (*)(void *))start_action_0e__10TObjPlayerFPv)(new_var);
        return;
      case 1:
        ((TObjPlayer *)new_var)->update_fall_reaction();
        return;
      case 6:
        TObjPlayer::exit_fall_reaction(new_var);
        break;
    }
  }
}

void TObjPlayer::set_flag_100000() { ((int (*)(void*))clear_velocity)((void*)(this)); set_actor_flags(0x100000); }

void TObjPlayer::update_move_state() {
    saddr arg0 = (saddr)this;
    damp_planar_velocity();
    if (this->check_actor_blocking_move() != 0) {
        ((int (*)(void*))clear_velocity)(this);
    }
    if (((u32 (*)(s32))resolve_move_collision__10TObjPlayerFv)(arg0) == 0U) {
        this->apply_velocity();
    }
}

void end_freeze_action__10TObjPlayerFPv(u8 *arg0) {
    s32 sp8;

    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&sp8, arg0 + 0x308);
    *(s32 *)((s8 *)arg0 + 0x33C) = 0xD;
    ((TObjPlayer *)arg0)->run_action_state_phase(((TObjPlayer *)arg0)->mode, 6);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x308, &sp8);
    if (TTecCtrl::is_technique_ready() != 0) {
        ((ProtectionTimer *)(arg0 + 0x644))->set_frames(0x1E);
    } else {
        ((ProtectionTimer *)(arg0 + 0x644))->set_frames((saddr)((TObjPlayer *)arg0)->get_hurt_protection_ticks());
    }
    ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x4000AD12);
    if (((TObjChara *)arg0)->obj_isState2_324() != 0) {
        ((TObjChara *)arg0)->trigger_switch_attack((const Vec *)((TObjChara *)arg0)->get_center());
    }
    ((TObjBase *)arg0)->clear_actor_flags((u32)0x10000);
    ((TObjPlayer *)arg0)->set_action_state(0xD, ((TObjPlayer *)arg0)->call_model_m24());
}

void handle_6x4B_hit_by_enemy(void *command) {
    Msg_801CB1B0 m;
    Player_801CB1B0 *p;

    ((TObjPlayer *)(&m))->reset_action_state();
    ((void (*)(void *, void *))copy_6x4b_hit_by_enemy_packet__10TObjPlayerFPvPv)(&m, command);
    ((TObjPlayer *)(&m))->read_swapped_fields();
    if (validate_6x4B_hit_by_enemy(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = (Player_801CB1B0 *)get_player_by_client_id(m.id);
        if (p != NULL && ((TObjPlayer *)p)->test_action_mask(0x8000) == 0) {
            ((TObjPlayer *)p)->set_hp_clamped(m.kind);
            if (((TObjPlayer *)p)->is_in_tl03_state() != 0 && reset_volopt_state__10TObjPlayerFv(p) != 0) {
                p->ang = m.ang;
                p->x = m.x;
                p->z = m.z;
                ((TObjPlayer *)p)->run_action_state_phase(0xD, 0);
            }
        }
    }
}

void TObjPlayer::send_6x4B_hurt_reaction() {
    u8 *arg0 = (u8 *)this;
    struct Pkt_801CB27C pkt;
    if (arg0 == NULL || this->obj_isState2_324() == 0) {
        ((TObjPlayer *)(&pkt))->reset_action_state();
        pkt.id = ((TObjBase *)arg0)->get_entity_id();
        pkt.a = *(s32 *)(arg0 + 0x60);
        pkt.b = *(s16 *)(arg0 + 0x32C);
        pkt.x = *(f32 *)(arg0 + 0x308);
        pkt.z = *(f32 *)(arg0 + 0x310);
        ((TObjPlayer *)(&pkt))->handle_recv_state();
    }
}

void TObjPlayer::hurt_phase8_nop() {  }

void TObjPlayer::complete_hurt_reaction() {
    u8 *arg0 = (u8 *)this;
    if (this->motion_flags & 0x10) {
        if (this->test_actor_flags(0x800) != 0) {
            ((FlagWord *)(arg0 + 0x858))->clear(1);
            run_action_state_phase(0xF, 5);
            return;
        }
        update_position_from_target();
    }
}

void TObjPlayer::hurt_phase2_nop() {  }

void TObjPlayer::do_action_19_5_if_flag30() { if (check_flag30_bit20() != 0) { run_action_state_phase(19, 5); } }

void TObjPlayer::run_hurt_state_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->do_action_19_5_if_flag30();
        return;
      case 2:
        hurt_phase2_nop();
        return;
      case 3:
        this->complete_hurt_reaction();
        return;
      case 8:
        hurt_phase8_nop();
        return;
      case 5:
        this->send_6x4B_hurt_reaction();
        return;
      case 0:
        ((s32 (*)(void *))end_freeze_action__10TObjPlayerFPv)(this);
        return;
      case 1:
        this->update_move_state();
        return;
      case 6:
        this->set_flag_100000();
        break;
    }
  }
}

void TObjPlayer::action11_phase6_nop() {  }

void TObjPlayer::update_action11_movement() {
    if (((u32 (*)(void))resolve_move_collision__10TObjPlayerFv)() == 0U) {
        this->apply_velocity();
    }
}

void TObjPlayer::begin_action_0xB() {
    this->action_state = 0xB;
    run_action_state_phase(this->mode, 6);
    if (obj_isState2_324() != 0) {
        this->current_action = ((s16 (*)(void))ret_801D26AC)();
    }
    this->set_action_state(0xB, this->call_obj_vt26());
}

void TObjPlayer::send_6x51_set_player_angle() {
    struct Pkt_801CB4D0 pkt;
    if (this == NULL || this->obj_isState2_324() == 0) {
        ((void (*)(void *))TObjPlayer__sub_801D1BB0)(&pkt);
        pkt.id = this->get_entity_id();
        pkt.c = this->rotation_y;
        ((TObjPlayer *)(&pkt))->refresh_players();
    }
}

void TObjPlayer::action11_phase8_nop() {  }

void TObjPlayer::run_if_flag_10() {
    if (this->motion_flags & 0x10) {
        update_position_from_target();
    }
}

void TObjPlayer::action11_phase2_nop() {  }

int TObjPlayer::try_apply_status_action() { return TObjPlayer::try_apply_status_action(this); }

void TObjPlayer::run_action11_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  void *new_var;
  {
    switch (phase)
    {
      case 7:
        this->try_apply_status_action();
        return;
      case 2:
        action11_phase2_nop();
        return;
      case 3:
        this->run_if_flag_10();
        return;
      case 8:
        action11_phase8_nop();
        return;
      case 5:
        new_var = this;
        ((TObjPlayer *)new_var)->send_6x51_set_player_angle();
        return;
      case 0:
        this->begin_action_0xB();
        return;
      case 1:
        arg0 = arg0;
        update_action11_movement();
        return;
      case 6:
        action11_phase6_nop();
        break;
    }
  }
}

void TObjPlayer::switch_interaction_phase6_nop() {  }

void TObjPlayer::apply_velocity_if_ready(saddr player) {
    if (((u32 (*)(void))resolve_move_collision__10TObjPlayerFv)() == 0U) {
        ((TObjPlayer *)player)->apply_velocity();
    }
}

void TObjPlayer::start_action_c() {
    this->action_state = 0xC;
    run_action_state_phase(this->mode, 6);
    if (obj_isState2_324() != 0) {
        this->current_action = ((s16 (*)(void))ret_801D26AC)();
    }
    this->set_action_state(0xC, this->get_weapon_stat_c());
}

void handle_6x50_switch_interaction(const void *source) {
    struct SwitchActionMessage_801CB6A8 packet;
    ((void (*)(void *))TObjPlayer__sub_801D1C70)(&packet);
    ((void (*)(void *, const void *))copy_font__10TObjPlayerFPvPv)(&packet, source);
    ((TObjPlayer *)(&packet))->bswap_field4();
    if (validate_6x50_switch_interaction(reinterpret_cast<G_ClientIDHeader *>(&packet))) {
        u8 *player = reinterpret_cast<u8 *>(get_player_by_client_id(packet.actor));
        if (player && ((TObjPlayer *)player)->is_in_tl03_state() && !((TObjPlayer *)player)->test_action_mask(0x8200)) {
            *(s32 *)(player + 0x60) = packet.yaw;
            ((TObjPlayer *)player)->run_action_state_phase(12, 0);
        }
    }
}

void TObjPlayer::send_6x50_switch_interaction() {
    u8 *arg0 = (u8 *)this;
    Ctx_801CB748 ctx;
    if ((arg0 == NULL) || (this->obj_isState2_324() == 0)) {
        ((s32 (*)(Ctx_801CB748 *))TObjPlayer__sub_801D1C70)(&ctx);
        ctx.f2 = ((TObjBase *)arg0)->get_entity_id();
        ctx.f4 = this->rotation_y;
        ((TObjPlayer *)(&ctx))->sync_players();
    }
}

void TObjPlayer::switch_interaction_phase8_nop() {  }

void TObjPlayer::update_if_flag_set() {
    if (this->motion_flags & 0x10) {
        update_position_from_target();
    }
}

void TObjPlayer::switch_interaction_phase2_nop() {  }

int TObjPlayer::try_switch_interaction_status_action() { return TObjPlayer::try_apply_status_action((TObjPlayer *)this); }

void TObjPlayer::run_switch_interaction_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  {
    switch (phase)
    {
      case 7:
        try_switch_interaction_status_action();
        return;
      case 2:
        switch_interaction_phase2_nop();
        return;
      case 3:
        this->update_if_flag_set();
        return;
      case 8:
        switch_interaction_phase8_nop();
        return;
      case 5:
        this->send_6x50_switch_interaction();
        return;
      case 0:
        this->start_action_c();
        return;
      case 1:
        TObjPlayer::apply_velocity_if_ready(arg0);
        return;
      case 6:
        switch_interaction_phase6_nop();
        break;
    }
  }
}

s32 TObjPlayer::can_guard() {
    if ((((TObjCollidable *)((u8 *)this))->test_actor_flags(0x100) != 0) && (((TObjCollidable *)((u8 *)this))->test_actor_flags(0x04000000) == 0)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::set_flag_0x100000(void* p) { ((int (*)(void*))clear_velocity)(p); ((TObjBase *)p)->set_actor_flags(0x100000); }

void TObjPlayer::apply_velocity_if_free(saddr arg0) {
    damp_planar_velocity();
    if (((u32 (*)(s32))resolve_move_collision__10TObjPlayerFv)(arg0) == 0U) {
        ((TObjPlayer *)arg0)->apply_velocity();
    }
}

void start_use_item_action__10TObjPlayerFPv(u8 *arg0) {
    s32 sp8;

    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&sp8, arg0 + 0x308);
    *(s32 *)((s8 *)arg0 + 0x33C) = 0xA;
    ((TObjPlayer *)arg0)->run_action_state_phase(((TObjPlayer *)arg0)->mode, 6);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x308, &sp8);
    ((TObjBase *)arg0)->clear_actor_flags((u32)0x10000);
    ((TObjPlayer *)arg0)->use_current_item();
    if (((TObjChara *)arg0)->obj_isState2_324() != 0) {
        ((TObjPlayer *)arg0)->current_action = ((s16 (*)(void))ret_801D26AC)();
    }
    ((TObjPlayer *)arg0)->set_action_state(0xA, ((TObjPlayer *)arg0)->query_child_state());
}

typedef struct Msg_801CB9E4 {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801CB9E4;
void* shield_attack__10TObjPlayerFPv(void* p);

void handle_6x4A_shield_attack(void *command) {
    Msg_801CB9E4 m;
    u8 *p;

    ((TObjPlayer *)(&m))->init_shield_attack_packet();
    ((void (*)(void *, void *))shield_attack__10TObjPlayerFPv)(&m, command);
    bswap_g_client_id_header(&m);
    if (validate_6x4A_shield_attack(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = reinterpret_cast<u8 *>(get_player_by_client_id(m.id));
        if (p != NULL && ((TObjPlayer *)p)->is_in_tl03_state() != 0 && reset_volopt_state__10TObjPlayerFv(p) != 0 &&
            ((TObjPlayer *)p)->test_action_mask(0x8000) == 0) {
            ((TObjPlayer *)p)->run_action_state_phase(0xA, 0);
        }
    }
}

void* shield_attack__10TObjPlayerFPv(void* p) { copy_subcommand_header(p); return p; }

void send_object_id_packet__10TObjPlayerFi(TObjPlayer *player) {
    s8 sp8[8];

    if ((player == NULL) || (player->obj_isState2_324() == 0)) {
        ((TObjPlayer *)((s32 *)&sp8))->init_shield_attack_packet();
        *(s16 *)((s8 *)(&sp8) + 2) = player->get_entity_id();
        ((TObjPlayer *)((s32 *)&sp8))->draw_font_and_send();
    }
}

void TObjPlayer::guard_reaction_phase8_nop() {  }

void TObjPlayer::complete_guard_reaction() {
    u8 *arg0 = (u8 *)this;
    if (this->motion_flags & 0x10) {
        if (this->test_actor_flags(0x800) != 0) {
            ((FlagWord *)(arg0 + 0x858))->clear(1);
            run_action_state_phase(0xF, 5);
            return;
        }
        update_position_from_target();
    }
}

void TObjPlayer::guard_reaction_phase2_nop() {  }

void TObjPlayer::select_hit_action() {
    if (check_flag30_bit20() != 0) {
        run_action_state_phase(0x13, 5);
        return;
    }
    if (is_status_flag_200() != 0) {
        if (test_actor_flags(0x400) != 0) {
            run_action_state_phase(0xE, 5);
            return;
        }
        run_action_state_phase(0xD, 5);
    }
}

void TObjPlayer::run_guard_reaction_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  {
    switch (phase)
    {
      case 7:
        select_hit_action();
        return;
      case 2:
        guard_reaction_phase2_nop();
        return;
      case 3:
        this->complete_guard_reaction();
        return;
      case 8:
        guard_reaction_phase8_nop();
        return;
      case 5:
        send_object_id_packet__10TObjPlayerFi(this);
        return;
      case 0:
        ((s32 (*)(void *))start_use_item_action__10TObjPlayerFPv)(this);
        if (arg0 && arg0)
      {
      }
        return;
      case 1:
        TObjPlayer::apply_velocity_if_free(arg0);
        return;
      case 6:
        TObjPlayer::set_flag_0x100000(this);
        break;
    }
  }
}
}

void TObjPlayer::create_photon_blast_party_effects(u16 id) {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        TObjPlayer__shared_photon_blast_state->create_party_effects(id);
    }
}

PhotonBlastRequestSlot *TObjPlayer::find_photon_blast_by_section_id(u16 section_id) {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        return TObjPlayer__shared_photon_blast_state->find_by_section_id(section_id);
    }
    return NULL;
}

u16 TObjPlayer::get_current_target_id() {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        return TObjPlayer__shared_photon_blast_state->find_first_valid_target_id();
    }
    return 0xFFFF;
}

void remove_photon_blast_participant(s32 id) {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        TObjPlayer__sub_80312E98(TObjPlayer__shared_photon_blast_state, id);
    }
}

void TObjPlayer::update_photon_blast_state() {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        TObjPlayer__shared_photon_blast_state->process_all_elements();
    }
}

PhotonBlastRequest *TObjPlayer::get_photon_blast_element(s32 arg0) {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        return TObjPlayer__shared_photon_blast_state->get_element(arg0);
    }
    return NULL;
}

void TObjPlayer::apply_photon_blast(u32 id, s16 kind) {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        append_photon_blast_request(TObjPlayer__shared_photon_blast_state, id, kind);
    }
}

// index (the 0x4AC slot's valid index the caller passes in r4) is not read.
void TObjPlayer::update_active_instance(int index) {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) {
            TObjPlayer__shared_photon_blast_state->process_all_elements();
            return;
        }
        release_photon_blast_requests(TObjPlayer__shared_photon_blast_state);
        admit_photon_blast_sequence(TObjPlayer::get_photon_blast_element(0), this);
    }
}

void TObjPlayer::gain_photon_blast_charge(f32 amount) {
    saddr arg0 = (saddr)this;
    if (TObjPlayer::is_locally_controlled(this) == 0 || this->test_actor_flags(0x800) != 0 ||
        (u32)this->activate_d04_slot() == 0 || ((s32 (*)(s32, s32))is_alt_photon_blast_bank_empty__10TObjPlayerFPv)(arg0 + 0x500, 1) != 0 ||
        is_current_area_item_enabled() == 0) {
        return;
    }
    this->photon_blast_gauge.add_photon_blast_charge(amount);
}

f32 TObjPlayer::calc_photon_blast_charge(void *player, s32 damage) {
    return (f32) damage / (15.0f * (1.0f + (f32) ((TObjPlayer *)player)->clamp_nested_index()));
}

void release_all_players_control_lock(void) {
    TObjPlayer::for_each_player_slot(release_control_lock__10TObjPlayerFPv);
}

void release_photon_blast_player_holds(u16 *p) {
    s32 i;
    uaddr obj;
    if (p != NULL) {
        i = 0;
        while (*p != 0xFFFF) {
            u32 id = *p++;
            if (id >= 12) {
                break;
            }
            obj = (uaddr)get_player_by_client_id(id);
            if (obj != 0) {
                ((TObjPlayer *)obj)->clear_flag_200();
            }
            i++;
            if (i >= 12) {
                break;
            }
        }
    }
}

void freeze_players_for_photon_blast(s16 arg0, u16 *arg1) {
    s32 i;
    void *obj;
    void **tbl;
    tbl = player_slot_table;
    i = 0;
    do {
        obj = *tbl;
        if (obj != NULL && ((s32 (*)(void *))is_on_current_floor__10TObjPlayerFi)(obj) != 0 && ((TObjPlayer *)obj)->test_action_mask(0x8000) == 0 &&
            (TObjPlayer::is_single_screen() != 0 ||
             (TObjPlayer::is_single_screen() == 0 && arg0 == ((TObjBase *)obj)->get_room()))) {
            TObjPlayer__sub_801D0F70(obj);
            if (arg1 != NULL) {
                *arg1 = ((TObjBase *)obj)->get_entity_id();
                arg1++;
            }
            ((TObjPlayer *)obj)->run_action_state_phase(0x13, 0);
        }
        i++;
        tbl++;
    } while (i < 4);
}
extern "C" {

void handle_6x36(void) {  }

void handle_6x37_photon_blast(saddr command) {
    struct Pkt_801CC0F4 pkt;
    TObjPlayer *player;
    ((void (*)(struct PbPacket37_801CC194 *))TObjPlayer__sub_801D1D88)((struct PbPacket37_801CC194 *)((void *) (&pkt)));
    ((s32 (*)(void *, void *))TObjPlayer__sub_801D1D44)((void *) (&pkt), (void *) (command));
    ((TObjPlayer *)(&pkt))->swap_endian16();
    if (validate_6x37_photon_blast((G_ClientIDHeader *)(&pkt)) != 0) {
        player = get_player_by_client_id(pkt.player);
        if ((player != NULL) && (player->check_flag_4() == 0) && (player->m_up == tl_03) && (((s32 (*)(int))reset_volopt_state__10TObjPlayerFv)((saddr) (player)) != 0)) {
            player->photon_blast_gauge.check_photon_blast_flag();
            player->photon_blast_gauge.trigger_photon_blast();
        }
    }
}

void TObjPlayer::send_6x37_photon_blast() {
    struct PbPacket37_801CC194 packet;
    if (this == NULL || obj_isState2_324() == 0) {
        ((void (*)(struct PbPacket37_801CC194 *))TObjPlayer__sub_801D1D88)(&packet);
        packet.player = this->get_entity_id();
        packet.gauge = get_photon_blast_charge();
        ((TObjPlayer *)(&packet))->update_and_send4();
    }
}

s32 TObjPlayer::check_conditions() {
    saddr arg0 = (saddr)this;
    if ((this->test_actor_flags(0x20006) != 0) || (this->test_action_mask(0x11E) == 0) || (this->photon_blast_gauge.has_ready_flag() == 0) || (this->photon_blast_gauge.check_flag_clear() == 0) || ((TObjPlayer::is_locally_controlled(this) != 0) && ((is_controls_locked() != 0) || (this->get_camera_field() == 0))) || (((s32 (*)(s32))reset_volopt_state__10TObjPlayerFv)(arg0) == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::exit_photon_blast_action() {
    u8 *arg0 = (u8 *)this;
    TLockOnCursor *lock_on_cursor;
    this->motion_flags &= ~0x40;
    this->clear_state_flags(0x80);
    this->clear_actor_flags((u32)(0x400000));
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
    this->photon_blast_gauge.reset_photon_blast_gauge();
    if (TObjPlayer::is_final_phase() != 0) {
        this->get_entity_id();
        ((s32 (*)(void))remove_photon_blast_participant)();
    } else {
        TObjPlayer::update_photon_blast_state();
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x33C) != 0x13) {
        ((TObjPlayer *)arg0)->protection.reset_lobby_model();
    }
}

void TObjPlayer::update_photon_blast_action() {
    u8 *arg0 = (u8 *)this;
  this->rotation_y = ((s32 (*)(int, int))lerp_angle_half__Fll)((int) (this->rotation_y), (int) (*((s32 *) (((s8 *) arg0) + 0x3F0))));
  switch (this->phase)
  {
    case 2:
    case 4:
      break;
    case 0:
      if (is_passing_frame(get_photon_blast_hold_frame()) != 0)
    {
      this->phase = 1;
      this->motion_flags = (s32) ((this->motion_flags) | 0x40);
      this->photon_blast_gauge.set_field8((int) (*((s16 *) (((s8 *) get_photon_blast_entry(((TObjPlayer *)arg0)->photon_blast_gauge.get_valid_index())) + 0x12))));
      this->photon_blast_gauge.set_field_0c(-0.2f);
    }
      play_persistent_sound(0x4002A823, arg0, NULL, 0, 0);
      break;
    case 1:
      this->frame = (f32) ((this->frame) + this->photon_blast_gauge.get_frame_step());
      if (this->photon_blast_gauge.get_frame_step() > 0.0f)
    {
      if ((this->frame) >= this->get_photon_blast_upper_bound())
      {
        this->photon_blast_gauge.set_field_0c(-0.2f);
      }
    }
    else
      if ((this->frame) <= (this->get_photon_blast_hold_frame() - 1.0f))
    {
      if (1)
      {
        this->photon_blast_gauge.set_field_0c(0.2f);
      }
    }
      this->photon_blast_gauge.decrement_countdown();
      if (this->photon_blast_gauge.get_countdown() < 0)
    {
      this->phase = 2;
      this->motion_flags = (s32) ((this->motion_flags) & 0xFFFFFFBF);
      this->photon_blast_gauge.set_complete_threshold(this->get_photon_blast_complete_threshold());
    }
      play_persistent_sound(0x4002A823, arg0, NULL, 0, 0);
      break;
    case 3:
      if (this->photon_blast_gauge.is_blast_launched() != 0)
    {
      this->phase = 4;
      this->clear_state_flags(0x80);
      ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(this);
      this->update_active_instance(((TObjPlayer *)arg0)->photon_blast_gauge.get_valid_index());
    }
      break;
  }
  if (this->resolve_move_collision() == 0U)
  {
    this->apply_velocity();
  }
}

void TObjPlayer::enter_photon_blast_action() {
    PhotonBlastTarget *slot;
    u16 id;
    Mylla_801CC558 *m;
    u8 *arg0 = (u8 *)this;
    *(s32 *)(arg0 + 0x33C) = 9;
    run_action_state_phase(*(s16 *)(arg0 + 0x326), 6);
    slot = this->photon_blast_gauge.get_target(0);
    id = slot->entity_id;
    if (id != 0xFFFF) {
        m = ((Mylla_801CC558 * (*)(u16))find_entity_by_id)(id);
        if (m == NULL) {
            slot->entity_id = id = 0xFFFF;
        } else {
            ((s32 (*)(void *, void *))copy_position__10TObjPlayerFPv)(arg0 + 0x744, m->tbl + slot->index * 0x2C + 0x1C);
        }
    }
    if (id == 0xFFFF) {
        *(s32 *)(arg0 + 0x3F0) = *(s32 *)(arg0 + 0x60);
    } else {
        slot = (PhotonBlastTarget *)((TObjPlayer *)(arg0 + 0x744))->get_field4_ptr();
        *(s32 *)(arg0 + 0x3F0) = calc_angle_to(((TObjPlayer *)arg0)->get_position_ptr(), (Vec *)slot);
    }
    ((TObjBase *)arg0)->set_actor_flags(0x400000);
    clear_velocity(arg0);
    if (((TObjChara *)arg0)->obj_isState2_324() != 0) {
        ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x22824);
    } else {
        ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x22322);
    }
    *(s16 *)(arg0 + 0x328) = 0;
    ((TObjPlayer *)arg0)->set_action_state(9, ((TObjPlayer *)arg0)->query_equip());
    ((TObjPlayer *)arg0)->set_state_flags(0x80);
    TObjPlayer::start_photon_blast(((TObjPlayer *)arg0)->photon_blast_gauge.get_valid_index(), (u16)((TObjBase *)arg0)->get_entity_id());
}

void handle_6x49_execute_photon_blast(void *command) {
    s32 i;
    Player_801CC6B8 *p;
    G_ExecutePhotonBlast_6x49 cmd;
    ((void (*)(void *, void *))copy_photon_blast_data__10TObjPlayerFiPv)(&cmd, command);
    ((TObjPlayer *)(&cmd))->byteswap_6x49_packet();
    if (validate_6x49_execute_photon_blast(&cmd) != 0) {
        p = (Player_801CC6B8 *)get_player_by_client_id(cmd.header.client_id);
        if (p != NULL && ((TObjPlayer *)p)->test_action_mask(0x8000) == 0 && is_current_area_item_enabled() != 0) {
            if (get_current_floor() == ((TObjPlayer *)p)->get_floor()) {
                s32 count;
                PhotonBlastTarget *dst;
                PhotonBlastTarget *src;
                ((PhotonBlastGauge *)p->pb)->start_photon_blast_action();
                TObjPlayer::apply_photon_blast(cmd.header.client_id, cmd.params.photon_blast);
                set_photon_blast_kind(p->pb, cmd.params.photon_blast);
                count = cmd.params.target_count;
                ((PhotonBlastGauge *)p->pb)->set_section_index(count);
                ((TObjPlayer *)p)->set_float_param(cmd.params.pb_meter_value);
                dst = ((TObjPlayer *)p)->photon_blast_gauge.get_target(0);
                src = cmd.targets;
                for (i = 0; i < count; i++) {
                    copy_tech_params(dst++, src++);
                }
                ((TObjPlayer *)p)->run_action_state_phase(9, 0);
            }
        }
    }
}

extern "C++" void copy_tech_params(PhotonBlastTarget *dst, PhotonBlastTarget *src) {
    dst->entity_id = src->entity_id;
    dst->index = src->index;
}

void TObjPlayer::prepare_photon_blast_action() {
    s32 i;
    s16 n;
    PhotonBlastTarget *src;
    PhotonBlastTarget *dst;
    u8 *arg0 = (u8 *)this;
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        ((ProtectionTimer *)(arg0 + 0x644))->set_frames(0x708);
        capture_technique_targets(this->photon_blast_gauge.get_valid_index(), this);
        if (this->lock_on_cursor != NULL) {
            PhotonBlastTarget *e = this->photon_blast_gauge.get_target(0);
            ((TMainCursor *)this->lock_on_cursor)->set_cursor_pos(e->entity_id, e->index);
        }
        if (arg0 == NULL || ((TObjChara *)arg0)->obj_isState2_324() == 0) {
            G_ExecutePhotonBlast_6x49 cmd;
            cmd.header.client_id = ((TObjBase *)arg0)->get_entity_id();
            cmd.params.photon_blast = this->photon_blast_gauge.get_valid_index();
            cmd.params.target_count = n = this->photon_blast_gauge.get_target_count();
            cmd.params.pb_meter_value = ((TObjPlayer *)arg0)->get_photon_blast_charge();
            src = this->photon_blast_gauge.get_target(0);
            dst = cmd.targets;
            for (i = 0; i < n; i++) {
                copy_tech_params(dst++, src++);
            }
            ((s32 (*)(void *))send_photon_blast_targets_packet)(&cmd);
        }
    }
}

void TObjPlayer::update_band_state() {
    u8 *arg0 = (u8 *)this;
    if ((s16) this->phase == 2) {
        if (is_passing_frame(this->photon_blast_gauge.get_dist()) != 0) {
            this->phase = 3;
            set_action_flag_40();
        }
    }
}

void TObjPlayer::update_target_approach() {
    u8 *arg0 = (u8 *)this;
    if (this->motion_flags & 0x10) {
        update_position_from_target();
        return;
    }
    if ((s16) this->phase == 2) {
        if (is_passing_frame(this->photon_blast_gauge.get_dist()) != 0) {
            this->phase = 3;
            set_action_flag_40();
            send_6x37_photon_blast();
        }
    }
}

void TObjPlayer::photon_blast_phase2_nop() {  }

int TObjPlayer::try_apply_status_action_default() { return TObjPlayer::try_apply_status_action(this); }

void TObjPlayer::dispatch_photon_blast_action(s16 phase) {
    saddr arg0 = (saddr)this;
  saddr *new_var;
  {
    switch (phase)
    {
      case 7:
        this->try_apply_status_action_default();
        return;
      case 2:
        photon_blast_phase2_nop();
        return;
      case 3:
        this->update_target_approach();
        arg0 = arg0;
        if (1)
      {
      }
        return;
      case 8:
        this->update_band_state();
        return;
      case 5:
        ((TObjPlayer *)(*(new_var = &arg0)))->prepare_photon_blast_action();
        return;
      case 0:
        this->enter_photon_blast_action();
        return;
      case 1:
        this->update_photon_blast_action();
        return;
      case 6:
        this->exit_photon_blast_action();
        break;
    }
  }
}

void handle_6x33_revive_player(void *command) {
    Msg_801CCA84 m;
    Tech_801CCA84 t;
    Player_801CCA84 *p;
    Player_801CCA84 *q;
    ((TObjPlayer *)(&m))->init_6x33_packet();
    ((void (*)(void *, void *))TObjPlayer__sub_801D2058)(&m, command);
    ((TObjPlayer *)(&m))->bswap_coords();
    if (validate_6x33_revive_player((G_ClientIDHeader *)&m) != 0) {
        p = (Player_801CCA84 *)get_player_by_client_id(m.id);
        if (p != NULL) {
            q = (Player_801CCA84 *)get_player_by_client_id(m.target);
            if (q != NULL && ((TObjPlayer *)q)->check_flag_4() == 0 && q->list == tl_03) {
                __ct__16TargetCursorListFv((&t));
                t.kind = 1;
                t.target = m.target;
                t.f6 = 0;
                t.f8 = 10.0f;
                TTecReverser::create(p, ((TObjPlayer *)p)->get_position_ptr(), &t, 0x1D);
            }
        }
    }
}

void send_6x33_revive_player(u16 client_id, s16 type) {
    struct Pkt_801CCB58 pkt;
    TObjChara *chara = (TObjChara *)get_player_by_client_id(static_cast<u16>(client_id));
    if (chara == NULL || chara->obj_isState2_324() == 0) {
        ((TObjPlayer *)(&pkt))->init_6x33_packet();
        pkt.id = client_id;
        pkt.c = type;
        ((TObjPlayer *)(&pkt))->send_coords();
    }
}

void TObjPlayer::set_technique_level_clamped(TObjPlayer *player, u8 level, int tech) {
    if (player->obj_isState3_324() != 0 && TObjPlayer::is_invalid_slot(level) == 0 &&
        level > (u8)TObjPlayer__sub_801C010C(&player->technique_state, tech)) {
        level = TObjPlayer__sub_801C010C(&player->technique_state, tech);
    }
    set_technique_level_entry(&player->technique_state, tech, level);
}

void TObjPlayer::update_cursor(s32 parameter) {
    TLockOnCursor *cursor;

    cursor = this->lock_on_cursor;
    if ((cursor != NULL) && (canSetMenuCursorAction(&cursor->palette_override, this, 3, (u8) parameter) != 0)) {
        set_action_palette_tag_mode(&lock_on_cursor->palette_override, 3);
        set_action_palette_tag_slot(&lock_on_cursor->palette_override, static_cast<u8>(parameter));
        TMainCursor__sub_8013DFC4((u8 *)&this->lock_on_cursor->palette_override);
    }
}

s32 try_equip_item__10TObjPlayerFii(TObjPlayer *player, s16 tech) {
    if (player->test_action_mask(0x100) == 0) {
        if (player->can_equip_item(tech) == 0) {
            return 0;
        }
        player->technique_state.set_technique_id(tech);
        player->request_technique_cast();
        return 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void tail_801CCD38(Player_801CCD38 *p, s32 t, s8 lvl) {
    switch (t) {
    case 10:
    case 11:
    case 12:
    case 13:
    case 15:
    case 16:
        ((PlayerTechniqueState *)(p->techs))->set_technique_state(calc_technique_parameters(t, lvl, ((TObjBase *)p)->get_entity_id())->pad_20);
        p->f328 = 4;
        launch_technique(t, lvl, (TObjPlayer *)p);
        return;
    }
    if (((TObjPlayer *)p)->check_flag_4() == 0 && p->f10 == tl_03) {
        ((PlayerTechniqueState *)(p->techs))->set_technique_state(calc_technique_parameters(t, lvl, ((TObjBase *)p)->get_entity_id())->pad_20);
        p->f328 = 4;
        launch_technique(t, lvl, (TObjPlayer *)p);
    }
}
extern int fold_flush_3;
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void handle_6x48_cast_technique_complete(void *arg) {
    Pkt_801CCD38 pkt;
    s8 lvl;
    u8 ul;
    Player_801CCD38 *p;
    s16 tech;
    ((void (*)(void *))init_6x48_cast_complete_packet)(&pkt);
    ((TObjPlayer *)(&pkt))->copy_6x48_cast_technique_complete_packet(arg);
    ((TObjPlayer *)(&pkt))->swap_header();
    if (validate_6x48_cast_technique_complete(reinterpret_cast<G_ClientIDHeader *>(&pkt)) == 0) {
        return;
    }
    p = (Player_801CCD38 *)get_player_by_client_id((u16)pkt.id);
    if (p == NULL) {
        return;
    }
    if (reset_volopt_state__10TObjPlayerFv(p) == 0) {
        return;
    }
    tech = pkt.tech;
    ((PlayerTechniqueState *)(p->techs))->set_technique_id(tech);
    lvl = pkt.level;
    if (lvl == 0xE) {
        lvl += ((PlayerTechniqueState *)p->techs)->get_valid_technique();
    }
    if (reinterpret_cast<PlayerTechniqueState *>(p->techs)->check_technique_level((s16)tech, (u8)lvl) == 0) {
        lvl = 0;
    }
    ul = lvl;
    ((PlayerTechniqueState *)(p->techs))->set_level(ul);
    ((void (*)(void *, u8, s16))TObjPlayer::set_technique_level_clamped)(p, ul, tech);
    tail_801CCD38(p, tech, lvl);
}
extern int fold_flush_4;
#pragma pop

void TObjPlayer::pay_tp_and_send_6x48_cast() {
    Player_801CCEDC *self = (Player_801CCEDC *)this;
    s16 tech;
    u8 hi;
    u8 lo;
    if (reset_volopt_state__10TObjPlayerFv(self) != 0) {
        if (self == 0 || ((TObjChara *)self)->obj_isState2_324() == 0) {
            Pkt_801CCEDC pkt;
            this->phase = 4;
            tech = ((PlayerTechniqueState *)self->techs)->get_or_init_field_4();
            this->tp -= calc_technique_parameters(tech, ((PlayerTechniqueState *)self->techs)->get_castable_technique_level(), get_entity_id())->tp_cost;
            if (this->tp < 0) {
                this->tp = 0;
            }
            TObjPlayer::split_capped_value(((PlayerTechniqueState *)self->techs)->get_castable_technique_level(), &hi, &lo);
            ((void (*)(void *))init_6x48_cast_complete_packet)(&pkt);
            pkt.id = ((TObjBase *)self)->get_entity_id();
            pkt.tech = tech;
            pkt.level = hi;
            ((TObjPlayer *)(&pkt))->send_swapped_header();
        }
    }
}

s32 TObjPlayer::try_camera_action(saddr player, s32 arg1) {
    if ((TObjPlayer::is_locally_controlled((void *)player) != 0) && ((((TObjPlayer *)player)->is_controls_locked() != 0) || (((TObjPlayer *)player)->get_camera_field() == 0))) {
        return 0;
    }
    return ((s32 (*)(s32, s32))can_start_technique__10TObjPlayerFPvi)(player, arg1);
}

s32 TObjPlayer::can_equip_item(s32 tech) {
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        return can_start_technique__10TObjPlayerFPvi((Player_801CD078 *)this, tech);
    }
    return 0;
}

s32 can_start_technique__10TObjPlayerFPvi(Player_801CD078 *self, s32 tech) {
    if (((TObjPlayer *)(self->techs))->test_bit1_at_10() != 0 ||
        ((TObjCollidable *)self)->test_actor_flags(0x20006) != 0 ||
        ((TObjCollidable *)self)->test_actor_flags(0x2000000) != 0 ||
        ((TObjPlayer *)self)->test_action_mask(0x11E) == 0 ||
        (tech == 0xE && TObjWarpBossMulti::is_flag_clear(self) == 0) ||
        (tech == 0x11 && TObjPlayer::is_camera_mode_active() != 0) ||
        TObjPlayer::validate_and_clear_slot(self->techs, tech) != 0 ||
        reset_volopt_state__10TObjPlayerFv(self) == 0) {
        return 0;
    }
    return self->tp - calc_technique_parameters(tech, get_cast_technique_level(self->techs, tech), ((TObjBase *)self)->get_entity_id())->tp_cost >= 0 ? 1 : 0;
}

void TObjPlayer::exit_technique_cast() {
    Player_801CD188 *self = (Player_801CD188 *)this;
    this->motion_flags &= ~0x40;
    ((TObjPlayer *)self)->clear_state_flags(0x80);
    ((TObjBase *)self)->clear_actor_flags((u32)0x400000);
    clear_status_bit6__10TObjPlayerFPv(self);
    if (self->sub != 0) {
        self->sub->f508 = 0xFFFF;
    }
}

void TObjPlayer::update_technique_cast() {
    u8 *arg0 = (u8 *)this;
    s16 phase;
    s32 temp_r30;
    u8 temp_r31;
    u8 *temp_r3;
    this->rotation_y = ((s32 (*)(int, int))lerp_angle_half__Fll)((int) (this->rotation_y), (int) (*(s32 *)((s8 *)arg0 + 0x3F0)));
    temp_r3 = get_cast_motion_record();
    phase = this->phase;
    switch (phase) {
    case 3:
    case 5:
        break;
    case 0:
        this->phase = 1;
        this->set_state_flags(0x80);
        create_technique_charge_light((s16) (technique_state.get_or_init_field_4()), (arg0));
        technique_state.set_technique_state(calc_technique_parameters(technique_state.get_or_init_field_4(), technique_state.get_castable_technique_level(), this->get_entity_id())->pad_12);
        ((s32 (*)(void *, f32))TObjPlayer__sub_801D2CC4)((void *) (arg0 + 0x428), 0.05f);
        break;
    case 1:
        if (this->is_flag_b0_4() == 0) {
            this->motion_flags = (s32) (this->motion_flags | 0x40);
            this->frame = (f32) (this->frame + ((TObjPlayer *)(arg0 + 0x428))->get_float_14());
            if (((TObjPlayer *)(arg0 + 0x428))->get_float_14() > 0.0f) {
                if (this->frame >= 0.2f) {
                    ((s32 (*)(void *, f32))TObjPlayer__sub_801D2CC4)((void *) (arg0 + 0x428), -0.05f);
                }
            } else if (this->frame < 0.0f) {
                ((s32 (*)(void *, f32))TObjPlayer__sub_801D2CC4)((void *) (arg0 + 0x428), 0.05f);
            }
        }
        ((s32 (*)(void *))TObjPlayer__sub_801D2CAC)((void *) (arg0 + 0x428));
        if (TObjPlayer__sub_80082300((void *) (arg0 + 0x428)) < 0) {
            this->phase = 2;
            this->motion_flags = (s32) (this->motion_flags & 0xFFFFFFBF);
        }
        break;
    case 2:
        if (this->is_passing_frame((f32) (*(f32 *)((s8 *)temp_r3 + 0xC))) != 0) {
            this->phase = 3;
            this->clear_state_flags(0x80);
            set_action_flag_40();
            if (this->obj_isState2_324() == 0) {
                pay_tp_and_send_6x48_cast();
            }
        }
        break;
    case 4:
        ((s32 (*)(void *))TObjPlayer__sub_801D2CAC)((void *) (arg0 + 0x428));
        if (TObjPlayer__sub_80082300((void *) (arg0 + 0x428)) < 0) {
            this->phase = 5;
            this->requested_action = this->get_idle_animation();
            clear_status_bit6__10TObjPlayerFPv(this);
        }
        break;
    }
    if (this->resolve_move_collision() == 0U) {
        this->apply_velocity();
    }
}

void TObjPlayer::enter_technique_cast() {
    PhotonBlastTarget *td;
    u16 target;
    Obj_801CD424 *o;
    Player_801CD424 *self = (Player_801CD424 *)this;
    self->f33c = 8;
    run_action_state_phase(this->mode, 6);
    td = technique_state.get_technique_data();
    target = td->entity_id;
    if (target == 0xFFFF || target == (u16)((TObjBase *)self)->get_entity_id() ||
        technique_state.get_section_clamped() == 0) {
        self->f3f0 = this->rotation_y;
    } else {
        o = ((Obj_801CD424 * (*)(u16))find_entity_by_id)(target);
        if (o == 0) {
            td->entity_id = 0xFFFF;
        } else {
            ((void (*)(void *, void *))copy_position__10TObjPlayerFPv)(self->f744, o->nodes[td->index].pos);
            self->f3f0 = calc_angle_to(((TObjPlayer *)self)->get_position_ptr(), (Vec *)((TObjPlayer *)(self->f744))->get_field4_ptr());
        }
    }
    ((TObjBase *)self)->set_actor_flags(0x400000);
    ((void (*)(void *))clear_velocity)(self);
    this->phase = 0;
    if (((TObjChara *)self)->obj_isState2_324() != 0) {
        this->current_action = ((s16 (*)(void))ret_801D26AC)();
    }
    ((TObjPlayer *)self)->set_action_state(8, ((TObjPlayer *)self)->get_status());
}

void handle_6x47_cast_technique(u8* self) {
    G_CastTechnique_6x47 cmd;
    TObjPlayer *p;
    s32 i;
    s32 lim;
    s8 n;
    PhotonBlastTarget *d;
    PhotonBlastTarget *s;
    s32 c;
    s8 e;

    TObjPlayer__sub_801D21CC((u8 *)&cmd, self);
    cmd.bswap();
    if (validate_6x47_cast_technique(&cmd) == 0) {
        return;
    }
    p = get_player_by_client_id(cmd.header.client_id);
    if (p == NULL) {
        return;
    }
    if (reset_volopt_state__10TObjPlayerFv(p) == 0) {
        return;
    }
    if (p->test_action_mask(0x8200) != 0) {
        return;
    }
    const s16 technique = cmd.params.technique_number;
    c = technique;
    p->technique_state.set_technique_id(technique);
    e = cmd.params.level;
    n = p->technique_state.get_valid_technique();
    if (TObjPlayer::is_valid_technique_slot((u8)n) == 0) {
        n = 0;
    }
    if (e == 14) {
        e += n;
    }
    if (p->technique_state.check_technique_level(c, e) == 0) {
        e = 0;
    }
    p->technique_state.set_level((u8)e);
    TObjPlayer::set_technique_level_clamped(p, (u8)e, c);
    lim = cmd.params.target_count;
    p->technique_state.set_tech_level(lim);
    d = p->technique_state.get_technique_data();
    s = cmd.targets;
    for (i = 0; i < lim; i++) {
        copy_tech_params(d++, s++);
    }
    p->run_action_state_phase(8, 0);
}


void handle_6x8D_set_technique_level_override(void *command) {
    Msg_801CD6BC m;
    TObjPlayer *p;
    ((void (*)(void *))init_6x8D_technique_level_packet)(&m);
    ((TObjPlayer *)(&m))->copy_6x8d_technique_level_packet(command);
    ((TObjPlayer *)(&m))->swap_field6();
    if (validate_6x8D_set_technique_level_override(reinterpret_cast<G_ClientIDHeader *>(&m)) != 0) {
        p = get_player_by_client_id(m.id);
        if (p != NULL) {
            p->technique_state.set_tech_override(m.level);
        }
    }
}

void TObjPlayer::request_technique_cast() {
    u8 hi;
    u8 lo;
    Msg1_801CD72C m1;
    PhotonBlastTarget *td;
    s16 tech;
    s32 i;
    s32 count;
    PhotonBlastTarget *src;
    PhotonBlastTarget *dst;
    Player_801CD72C *self = (Player_801CD72C *)this;
    capture_technique_targets(((PlayerTechniqueState *)(self->techs))->get_or_init_field_4(), this);
    if (self->cursor != NULL) {
        td = ((PlayerTechniqueState *)self->techs)->get_technique_data();
        ((TMainCursor *)(self->cursor))->set_cursor_pos(td->entity_id, td->index);
    }
    tech = ((PlayerTechniqueState *)(self->techs))->get_or_init_field_4();
    TObjPlayer::split_capped_value(get_cast_technique_level(self->techs, tech), &hi, &lo);
    if (self == NULL || ((TObjChara *)self)->obj_isState2_324() == 0) {
        ((void (*)(void *))init_6x8D_technique_level_packet)(&m1);
        m1.id = ((TObjBase *)self)->get_entity_id();
        m1.level = lo;
        ((TObjPlayer *)(&m1))->send_swap_field6();
        G_CastTechnique_6x47 cmd;
        cmd.header.client_id = ((TObjBase *)self)->get_entity_id();
        cmd.params.technique_number = tech;
        cmd.params.level = hi;
        count = technique_state.get_section_clamped();
        cmd.params.target_count = count;
        src = technique_state.get_technique_data();
        dst = cmd.targets;
        for (i = 0; i < count; i++) {
            copy_tech_params(dst++, src++);
        }
        cmd.send();
    }
}

void TObjPlayer::check_anim_done() {
    if (((s16) this->phase == 5) && (this->is_anim_finished() != 0)) {
        run_action_state_phase(1, 0);
    }
}

void TObjPlayer::update_state5_action() {
    if (((s16) this->phase == 5) && (this->is_anim_finished() != 0)) {
        run_action_state_phase(1, 0);
    }
}

void TObjPlayer::technique_cast_phase2_nop() {  }

int TObjPlayer::apply_status_action_a() { return TObjPlayer::try_apply_status_action(this); }

void TObjPlayer::dispatch_technique_cast_state(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->apply_status_action_a();
        return;
      case 2:
        technique_cast_phase2_nop();
        return;
      case 3:
        this->update_state5_action();
        return;
      case 8:
        this->check_anim_done();
        return;
      case 5:
        this->request_technique_cast();
        return;
      case 0:
        this->enter_technique_cast();
        return;
      case 1:
        this->update_technique_cast();
        return;
      case 6:
        this->exit_technique_cast();
        break;
    }
  }
}

void TObjPlayer::reset_linked_obj() {
    TLockOnCursor *lock_on_cursor;

    ((s32 (*)(void))clear_velocity)();
    ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(this);
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
}

int TObjPlayer::update_attack_stage3() { return ((int (*)(void*))update_action_state__10TObjPlayerFPv)(this); }

void enter_attack_stage3__10TObjPlayerFPv(u8 *player) {
    *(s32 *)((s8 *)player + 0x33C) = 7;
    ((TObjPlayer *)player)->run_action_state_phase(((TObjPlayer *)player)->mode, 6);
    ((TObjPlayer *)(player + 0x7CC))->set_action_type(TObjPlayer__sub_801D2F0C(player + 0x7CC));
    update_player_action_palette(reinterpret_cast<TObjPlayer *>(player), static_cast<u8>(TObjPlayer__sub_801D2F4C(reinterpret_cast<s16 *>(player + 0x7CC))));
    ((s32 (*)(void *, void *, int, int))begin_player_attack)((void *) (player + 0x7CC), (void *) (player), 2, 2);
    ((TObjPlayer *)player)->setup_attack_stage();
    ((TObjPlayer *)player)->set_action_state(7, ((TObjPlayer *)player)->get_model_state());
    apply_speed_scale__10TObjPlayerFif((saddr)(player), (f32) (((f32 (*)(void *))get_action_rate_entry)((void *) (player)) * get_attack_controller_rate((void *) (player + 0x7CC))));
}

void handle_6x45_attack(void *src) {
    Pkt_801CDAD8 pkt;
    u8 *player;
    ((G_Attack_6x45 *)&pkt)->init();
    ((TObjPlayer *)(&pkt))->copy_6x45_attack_packet(src);
    ((G_Attack_6x45 *)&pkt)->bswap();
    if (validate_6x45_attack((G_ClientIDHeader *)&pkt) == 0) return;
    player = reinterpret_cast<u8 *>(get_player_by_client_id(pkt.player));
    if (player == 0) return;
    if (((TObjPlayer *)player)->is_in_tl03_state() == 0) return;
    if (reset_volopt_state__10TObjPlayerFv(player) == 0) return;
    if (((TObjPlayer *)player)->test_action_mask(0x8200) != 0) return;
    ((TObjPlayer *)(player + 0x7CC))->set_action_type(pkt.kind);
        ((TObjPlayer *)(player + 0x7CC))->set_attack_target(pkt.kind);
    *(s32 *)(player + 0x3F0) = pkt.heading;
    ((TObjPlayer *)player)->run_action_state_phase(7, 0);
}

void TObjPlayer::send_attack_stage3_request() {
    u8 *arg0 = (u8 *)this;
    G_Attack_6x45 cmd;
    s16 temp_r31;
    void *position;
    s32 var_r4;
    u8 *temp_r3;
    TLockOnCursor *lock_on_cursor;
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        temp_r3 = (u8 *)(resolve_hittable_target(lock_on_cursor->target_part.actor_id, lock_on_cursor->target_part.collider));
        if (temp_r3 != NULL) {
            position = this->get_position_ptr();
            var_r4 = calc_angle_to((Vec *)position, (Vec *)&((Rec_801CDBA0 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)))[*(s16 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x424)) + 0x50A)].pos);
        } else {
            var_r4 = this->rotation_y;
        }
        temp_r31 = calc_scaled_value__10TObjPlayerFii(this, (int) (var_r4));
        if ((arg0 == NULL) || (this->obj_isState2_324() == 0)) {
            cmd.init();
            cmd.header.client_id = this->get_entity_id();
            cmd.angle_y = temp_r31;
            cmd.action_type = TObjPlayer__sub_801D2F0C((void *) (arg0 + 0x7CC));
            cmd.send();
        }
    }
}

void TObjPlayer::attack_stage3_phase8_nop() {  }

void TObjPlayer::finish_attack_stage3() {
    u8 *arg0 = (u8 *)this;
    if ((s16) this->phase == 4) {
        if (this->is_anim_finished() != 0) {
            run_action_state_phase(1, 5);
        }
    } else if (this->motion_flags & 0x10) {
        if (test_flags_any(get_anim_field_c__10TObjPlayerFPv(arg0 + 0x7CC), 1) != 0) {
            this->phase = 4;
            this->requested_action = this->get_idle_animation();
            ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(this);
        }
    }
}

void TObjPlayer::check_attack_stage3_input() {  }

int TObjPlayer::try_apply_status_action_1() { return TObjPlayer::try_apply_status_action(this); }

void TObjPlayer::run_attack_stage3_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->try_apply_status_action_1();
        return;
      case 2:
        TObjPlayer::check_attack_stage3_input();
        return;
      case 3:
        this->finish_attack_stage3();
        return;
      case 8:
        attack_stage3_phase8_nop();
        return;
      case 5:
        this->send_attack_stage3_request();
        return;
      case 0:
        ((s32 (*)(void *))enter_attack_stage3__10TObjPlayerFPv)(this);
        return;
      case 1:
        update_attack_stage3();
        return;
      case 6:
        this->reset_linked_obj();
        break;
    }
  }
}

void TObjPlayer::reset_target_link() {
    TLockOnCursor *lock_on_cursor;

    ((s32 (*)(void))clear_velocity)();
    ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(this);
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
}

int TObjPlayer::update_attack_stage2() { return ((int (*)(void*))update_action_state__10TObjPlayerFPv)(this); }

void enter_attack_stage2__10TObjPlayerFPv(u8 *player) {
    *(s32 *)((s8 *)player + 0x33C) = 6;
    ((TObjPlayer *)player)->run_action_state_phase(((TObjPlayer *)player)->mode, 6);
    ((TObjPlayer *)(player + 0x7CC))->set_action_type(TObjPlayer__sub_801D2F0C(player + 0x7CC));
    update_player_action_palette(reinterpret_cast<TObjPlayer *>(player), static_cast<u8>(TObjPlayer__sub_801D2F4C(reinterpret_cast<s16 *>(player + 0x7CC))));
    ((s32 (*)(void *, void *, int, int))begin_player_attack)((void *) (player + 0x7CC), (void *) (player), 1, 1);
    ((TObjPlayer *)player)->setup_attack_stage();
    ((TObjPlayer *)player)->set_action_state(6, ((TObjPlayer *)player)->get_state());
    apply_speed_scale__10TObjPlayerFif((saddr)(player), (f32) (((f32 (*)(void *))get_action_rate_entry)((void *) (player)) * get_attack_controller_rate((void *) (player + 0x7CC))));
}

void handle_6x44_attack(void *src) {
    Pkt_801CDED4 pkt;
    u8 *player;
    ((G_Attack_6x44 *)&pkt)->init();
    ((void (*)(Pkt_801CDED4 *, void *))TObjPlayer__sub_801D2348)(&pkt, src);
    ((G_Attack_6x44 *)&pkt)->bswap();
    if (validate_6x44_attack((G_ClientIDHeader *)&pkt) == 0) return;
    player = reinterpret_cast<u8 *>(get_player_by_client_id(pkt.player));
    if (player == 0) return;
    if (((TObjPlayer *)player)->is_in_tl03_state() == 0) return;
    if (reset_volopt_state__10TObjPlayerFv(player) == 0) return;
    if (((TObjPlayer *)player)->test_action_mask(0x8200) != 0) return;
    ((TObjPlayer *)(player + 0x7CC))->set_action_type(pkt.kind);
        ((TObjPlayer *)(player + 0x7CC))->set_attack_target(pkt.kind);
    *(s32 *)(player + 0x3F0) = pkt.heading;
    ((TObjPlayer *)player)->run_action_state_phase(6, 0);
}

void TObjPlayer::send_attack_stage2_request() {
    u8 *arg0 = (u8 *)this;
    G_Attack_6x44 cmd;
    s16 temp_r31;
    void *position;
    s32 var_r4;
    u8 *temp_r3;
    TLockOnCursor *lock_on_cursor;
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        temp_r3 = (u8 *)(resolve_hittable_target(lock_on_cursor->target_part.actor_id, lock_on_cursor->target_part.collider));
        if (temp_r3 != NULL) {
            position = this->get_position_ptr();
            var_r4 = calc_angle_to((Vec *)position, (Vec *)&((Rec_801CDF9C *)(*(u8 **)((s8 *)temp_r3 + 0xA4)))[*(s16 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x424)) + 0x50A)].pos);
        } else {
            var_r4 = this->rotation_y;
        }
        temp_r31 = calc_scaled_value__10TObjPlayerFii(this, (int) (var_r4));
        if ((arg0 == NULL) || (this->obj_isState2_324() == 0)) {
            cmd.init();
            cmd.header.client_id = this->get_entity_id();
            cmd.angle_y = temp_r31;
            cmd.action_type = TObjPlayer__sub_801D2F0C((void *) (arg0 + 0x7CC));
            cmd.send();
        }
    }
}

void TObjPlayer::attack_stage2_phase8_nop() {  }

void TObjPlayer::finish_attack_stage2() {
    Player_801CE068 *self = (Player_801CE068 *)this;
    if (this->phase == 4) {
        if (((TObjMotion *)self)->is_anim_finished() != 0) {
            run_action_state_phase(1, 5);
        }
    } else if ((this->motion_flags & 0x10) &&
               ((s32 (*)(void *, s32))test_flags_any)(get_anim_field_c__10TObjPlayerFPv(self->act), 1) != 0) {
        switch (attack_state.get_validated_attack_stage()) {
        case 0:
        case 1:
            this->phase = 4;
            clear_status_bit6__10TObjPlayerFPv(self);
            this->requested_action = ((TObjPlayer *)self)->get_idle_animation();
            break;
        case 2:
            run_action_state_phase(7, 5);
            break;
        }
    }
}

void TObjPlayer::check_attack_stage2_input() {
    s32 temp_r3;

    temp_r3 = select_attack_palette_slot();
    if (temp_r3 != -1) {
        ((s32 (*)(s32, s32, s32, s32))queue_physical_attack_input)(((saddr)this) + 0x7CC, ((saddr)this), temp_r3, 2);
    }
}

int TObjPlayer::apply_status_action() { return TObjPlayer::try_apply_status_action(this); }

void TObjPlayer::run_attack_stage2_phase(s16 phase) {
  uaddr new_var2;
  void *new_var;
  new_var2 = ((u32) phase) <= 8U;
  {
    new_var = this;
    switch (phase)
    {
      case 7:
        this->apply_status_action();
        return;
      case 2:
        check_attack_stage2_input();
        return;
      case 3:
        ((TObjPlayer *)new_var)->finish_attack_stage2();
        return;
      case 8:
        attack_stage2_phase8_nop();
        return;
      case 5:
        this->send_attack_stage2_request();
        return;
      case 0:
        ((s32 (*)(void *))enter_attack_stage2__10TObjPlayerFPv)(new_var);
        return;
      case 1:
        ((TObjPlayer *)new_var)->update_attack_stage2();
        return;
      case 6:
        ((TObjPlayer *)new_var)->reset_target_link();
        break;
    }
  }
}

void TObjPlayer::start_attack_preparation() {
    u8 *arg0 = (u8 *)this;
    switch (((s16 (*)(void *))TObjPlayer__sub_801D2F4C)(arg0 + 0x7CC)) {
    case 0:
        *(s16 *)(arg0 + 0x328) = 3;
        break;
    case 1:
        *(s16 *)(arg0 + 0x328) = 1;
        this->set_state_flags(0x80);
        ((TObjPlayer *)(arg0 + 0x384))->request_heavy_attack_particles();
        scratch_vec[1] = scratch_vec[0] = 0.0f;
        player_feedback_light_color[0] = scratch_vec[2] = 1.0f;
        player_feedback_light_color[2] = player_feedback_light_color[1] = 0.8f;
        player_feedback_light_color[3] = 1.0f;
        new TActorLight(0.2f, (NJS_ARGB *)player_feedback_light_color, (Vec *)scratch_vec, 8, this, tl_07);
        publish_actor_light_scalars(((TObjBase *)arg0)->get_entity_id(), 1.0f, 0.5f);
        this->play_sound_if_on_floor(0x1AD1C);
        break;
    case 2:
        *(s16 *)(arg0 + 0x328) = 1;
        this->set_state_flags(0x80);
        dispatch_weapon_special_effect(arg0, 0, 0, 0);
        scratch_vec[1] = scratch_vec[0] = 0.0f;
        player_feedback_light_color[0] = scratch_vec[2] = 1.0f;
        player_feedback_light_color[2] = player_feedback_light_color[1] = 0.8f;
        player_feedback_light_color[3] = 1.0f;
        new TActorLight(0.2f, (NJS_ARGB *)player_feedback_light_color, (Vec *)scratch_vec, 8, this, tl_07);
        publish_actor_light_scalars(((TObjBase *)arg0)->get_entity_id(), 1.0f, 0.5f);
        this->play_sound_if_on_floor(0x1AD1D);
        break;
    }
}

void TObjPlayer::setup_attack_stage() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)(arg0 + 0x328) = 0;
    switch (((s16 (*)(void *))TObjPlayer__sub_801D2F4C)(arg0 + 0x7CC)) {
    case 0:
        if (attack_state.get_validated_attack_stage() == 0) {
            set_field_d4_and_flag_200(0.5f);
        }
        break;
    case 1:
    case 2:
        if (attack_state.get_validated_attack_stage() == 0) {
            set_field_d4_and_flag_200(0.2f);
        }
        break;
    }
}

struct TargetCollider {
    u8 pad0[0x18];
    u32 flags;
    u8 pad1C[0x10];
};

struct KnockbackReceiver : VBase_801CE928 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void apply_knockback(TObjPlayer *attacker, f32 force);
};

struct WeaponHitSound {
    s8 kind;
    s8 variant;
    u8 pad2[2];
    TObjPlayer *attacker;
    u8 pad8[4];
    TObjChara *target;
    s32 collider;
};

int TObjPlayer::deliver_attack_hits(f32 damage_scale) {
    s32 count;
    s32 i;
    int hit = 0;
    CapturedTarget *entry;
    count = ((CapturedTargetList *)((TObjPlayer *)&attack_state)->get_state_ptr())->get_captured_target_count();
    entry = ((CapturedTargetList *)((TObjPlayer *)&attack_state)->get_state_ptr())->get_captured_target_entry(0);
    for (i = 0; i < count; i++) {
        u16 uid = entry->get_uid();
        s16 collider = entry->get_captured_target_collider_index();
        TObjChara *target = (TObjChara *)resolve_hittable_target(uid, collider);
        if (target == NULL) {
            continue;
        }
        if (get_type__10TObjPlayerFPv(&m_828) != 0 && obj_isState2_324() != 0 &&
            ((TUnk_80493450 *)target)->test_elt_flag(collider, 0x2000) == 0) {
            continue;
        }
        if ((((TargetCollider *)bodies)->flags ^ ((TargetCollider *)target->bodies)[collider].flags) & 6) {
            continue;
        }
        f32 accuracy;
        if (TObjPlayer__sub_801D2F4C((s16 *)&attack_state) == 2 && get_equipped_weapon(this) != NULL &&
            get_equipped_weapon(this)->is_identified() == 0) {
            if ((f32)get_ata() < 0.0f) {
                accuracy = 0.0f;
            } else {
                accuracy = 0.1f;
            }
        } else {
            accuracy = attack_state.get_attack_accuracy_scale();
        }
        if (target->roll_physical_accuracy(this, collider, accuracy) != 0) {
            s32 damage;
            f32 dealt;
            switch (TObjPlayer__sub_801D2F4C((s16 *)&attack_state)) {
            case 0:
                damage = target->receive_physical_attack(this, damage_scale * attack_state.get_attack_damage_scale());
                gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, damage));
                apply_camera_shake__10TObjPlayerFiii(this, target, damage);
                break;
            case 1:
                dealt = target->receive_physical_attack(this, damage_scale * attack_state.get_attack_damage_scale());
                damage = dealt;
                gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, damage));
                apply_camera_shake__10TObjPlayerFiii(this, target, damage);
                ((KnockbackReceiver *)target)->apply_knockback(this, 0.1f * dealt);
                break;
            case 2:
                target->receive_weapon_special_attack(this, &((TargetCollider *)target->bodies)[collider]);
                break;
            }
            hit = 1;
            WeaponHitSound sound;
            ((TObjPlayer *)&sound)->reset_status_block();
            TItem *item = get_equipped_weapon(this);
            if (item != NULL) {
                sound.kind = item->get_item_group();
                sound.variant = item->get_item_index();
            }
            sound.attacker = this;
            sound.target = target;
            sound.collider = collider;
            play_weapon_hit_sound(&sound);
        } else {
            switch (obj_getS16_116()) {
            case 4:
            case 5:
            case 6:
            case 9:
            case 10:
            case 13:
                ((TObjPlayer *)target)->show_miss_for_collider(collider);
                break;
            default:
                switch (TObjPlayer__sub_801D2F4C((s16 *)&attack_state)) {
                case 2:
                    if (target->roll_physical_accuracy(this, collider,
                                                       attack_state.calc_attack_stage_multiplier(2)) != 0) {
                        s32 damage = target->receive_physical_attack(this, damage_scale * attack_state.get_attack_damage_scale());
                        gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, damage));
                        apply_camera_shake__10TObjPlayerFiii(this, target, damage);
                        hit = 1;
                        WeaponHitSound sound;
                        ((TObjPlayer *)&sound)->reset_status_block();
                        TItem *item = get_equipped_weapon(this);
                        if (item != NULL) {
                            sound.kind = item->get_item_group();
                        }
                        sound.attacker = this;
                        sound.target = target;
                        sound.collider = collider;
                        play_weapon_hit_sound(&sound);
                    } else {
                        ((TObjPlayer *)target)->show_miss_for_collider(collider);
                    }
                    break;
                default:
                    ((TObjPlayer *)target)->show_miss_for_collider(collider);
                    break;
                }
                break;
            }
        }
        entry++;
    }
    return hit;
}

void handle_6x46_attack_finished(s32 command) {
    u16 packet[0x18];
    Player_801CE928 *pl;
    TItem *it;
    ((TObjPlayer *)packet)->build_packet_header();
    ((s32 (*)(void *, s32))TObjPlayer__sub_801D2BB8)(packet, command);
    ((TObjPlayer *)packet)->bswap_field4_sub();
    if (validate_6x46_attack_finished(reinterpret_cast<G_ClientIDHeader *>(packet)) != 0 && (pl = ((Player_801CE928 *)get_player_by_client_id((u16)packet[1]))) != NULL &&
        ((TObjPlayer *)pl)->is_in_tl03_state() != 0 && reset_volopt_state__10TObjPlayerFv(pl) != 0) {
        ((s32 (*)(void *, void *))on_attack_finished__10TObjPlayerFPv)((u8 *)pl + 0x7CC, &packet[2]);
        it = TObjPlayer::get_equipped_weapon(pl);
        if (it != NULL) {
            it->perform_action();
            return;
        }
        if (pl->v65(1.0f) == 0) {
            ((TObjPlayer *)pl)->play_sound_if_on_floor(0x4001A80C);
        }
    }
}

void TObjPlayer::send_attack_target_packet() {
    uaddr arg0 = (uaddr)this;
    s16 sp8[0x14];
    if (((this->obj_isState2_324() == 0) || (reset_volopt_state__10TObjPlayerFv(this) != 0)) && ((this->obj_isState3_324() != 0) || (((u32 (*)(void *, void *))capture_lockon_targets)((void *) (arg0 + 0x7CC), this) != 0U)) && (this->is_body_collision_inactive() == 0) && ((arg0 == 0U) || (this->obj_isState2_324() == 0))) {
        ((TObjPlayer *)sp8)->build_packet_header();
        sp8[1] = this->get_entity_id();
        copy_attack_targets((void *) (&sp8[2]), (void *) (((TObjPlayer *)(arg0 + 0x7CC))->get_state_ptr()));
        ((s32 (*)(void *))send_6x46_attack_finished)((void *) (sp8));
    }
}

s32 TObjPlayer::select_attack_palette_slot() {
    s32 r = -1;
    if (TObjPlayer__sub_801B5AF8(((u8 *)this), 1) == 2 && pad_binding.is_button_pressed(4) != 0) {
        r = 1;
    }
    if (TObjPlayer__sub_801B5AF8(((u8 *)this), 2) == 2 && pad_binding.is_button_pressed(0x400) != 0 &&
        is_palettex_activated(this->get_entity_id()) == 0) {
        r = 2;
    }
    if (TObjPlayer__sub_801B5AF8(((u8 *)this), 3) == 2 && pad_binding.is_button_pressed(2) != 0) {
        r = 3;
    }
    return this->check_mode_action(get_action_palette_entry__10TObjPlayerFl(((u8 *)this), r)) != 0 ? r : -1;
}

s32 TObjPlayer::check_mode_action(s32 arg1) {
    if (arg1 == 2) {
        TItem *weapon = get_equipped_weapon(this);
        if (weapon != NULL) {
            if (weapon_has_extra_attack((TItemWeapon *)weapon) == 0) {
                return 0;
            }
            goto block_5;
        }
        return 0;
    }
block_5:
    return can_perform_physical_action();
}

s32 TObjPlayer::can_perform_physical_action() {
    if ((this->test_actor_flags(0x20006) != 0) || (this->test_actor_flags(0x02000000) != 0) || (this->check_flag(2) != 0) || (this->test_action_mask(0x548000) != 0) || ((TObjPlayer::is_locally_controlled(this) != 0) && ((is_controls_locked() != 0) || (this->get_camera_field() == 0))) || (reset_volopt_state__10TObjPlayerFv(this) == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::update_by_state() {
    u8 *arg0 = (u8 *)this;

    switch (((TObjPlayer *)this)->get_handle_value()) {
    case 0:
        if (this->motion_flags & 0x10) {
            ((TObjPlayer *)(arg0 + 0x7CC))->set_flag_1_at_c();
        }
        return;
    case 8:
        ((TObjPlayer *)(arg0 + 0x7CC))->update_if_flag8_set();
        return;
    default:
        if (this->motion_flags & 0x10) {
            ((TObjPlayer *)(arg0 + 0x7CC))->tick_countdown_timer();
        }
        break;
    }
}

void TObjPlayer::apply_movement_if_ready() {
    u8 *arg0 = (u8 *)this;
    s16 handle_value;

    handle_value = ((TObjPlayer *)this)->get_handle_value();
    if ((handle_value != 0x11) && ((handle_value >= 0x11) || (handle_value >= 0xA) || (handle_value < 6)) && (this->is_flag_b0_4() == 0) && ((s16) this->requested_action == (s16) this->current_action) && (this->action_flags & 0x20000000) && (((TObjPlayer *)arg0)->is_motion_paused() == 0)) {
        if (0.0f > get_root_motion_step(&this->velocity.x, &this->velocity.z)) {
            clear_velocity(arg0);
        }
        if (this->check_actor_blocking_move() != 0) {
            clear_velocity(arg0);
        }
        if (this->resolve_move_collision() == 0U) {
            this->apply_velocity();
        }
    }
}

void TObjPlayer::update_anim_action() {
    u8 *arg0 = (u8 *)this;
    get_equipped_weapon(this);
    if (((TObjPlayer *)arg0)->get_handle_value() != 8) {
        if (is_passing_frame(select_normal_attack_marker()) != 0) {
            send_attack_target_packet();
            ((TObjPlayer *)(arg0 + 0x7CC))->increment_strike_counter();
            ((s32 (*)(void *, void *))apply_anim_action__10TObjPlayerFPvi)(arg0 + 0x7CC, arg0);
        }
    } else {
        if (test_flags_any(get_anim_field_c__10TObjPlayerFPv(arg0 + 0x7CC), 8) == 0) {
            if (is_passing_frame(select_normal_attack_marker()) != 0) {
                send_attack_target_packet();
                increment_burst_counter((u8 *)&this->attack_state);
                if (get_burst_counter(&this->attack_state) >= 3) {
                    ((FlagWord *)get_anim_field_c__10TObjPlayerFPv(arg0 + 0x7CC))->set(8);
                    ((s32 (*)(void *, void *))apply_anim_action__10TObjPlayerFPvi)(arg0 + 0x7CC, arg0);
                    set_action_flag_40();
                    this->motion_flags = (s32) (this->motion_flags | 0x10);
                }
            }
        }
    }
}

void update_action_state__10TObjPlayerFPv(u8 *player) {
    s32 temp_r31;

    ((TObjPlayer *)player)->rotation_y = lerp_angle_half__Fll(((TObjPlayer *)player)->rotation_y, *(s32 *)((s8 *)player + 0x3F0));
    switch (((TObjPlayer *)player)->phase) {
    case 0:
        ((TObjPlayer *)player)->start_attack_preparation();
    case 1:
        if (((TObjMotion *)player)->is_anim_finished() != 0) {
            ((TObjPlayer *)player)->phase = 2;
            ((TObjPlayer *)player)->set_action_flag_40();
        }
    case 4:
        return;
    case 2:
        temp_r31 = ((TObjPlayer *)(player + 0x7CC))->get_field_1c() - 1;
        if (temp_r31 < 0) {
            ((TObjPlayer *)player)->phase = 3;
            ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(player);
        }
        ((TObjPlayer *)(player + 0x7CC))->set_action_type(temp_r31);
        return;
    case 3:
        ((TObjPlayer *)player)->update_anim_action();
        ((TObjPlayer *)player)->apply_movement_if_ready();
        ((TObjPlayer *)player)->update_by_state();
        break;
    }
}

void TObjPlayer::reset_lockon() {
    TLockOnCursor *lock_on_cursor;

    ((s32 (*)(void))clear_velocity)();
    ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(this);
    lock_on_cursor = this->lock_on_cursor;
    if (lock_on_cursor != NULL) {
        lock_on_cursor->target_part.actor_id = 0xFFFF;
    }
}

void update_action_state__10TObjPlayerFv(void) {
    ((s32 (*)(void))update_action_state__10TObjPlayerFPv)();
}

void enter_attack_stage1__10TObjPlayerFPv(u8 *player) {
    *(s32 *)((s8 *)player + 0x33C) = 5;
    ((TObjPlayer *)player)->run_action_state_phase(((TObjPlayer *)player)->mode, 6);
    clear_velocity((void *) (player));
    ((s32 (*)(void *, void *, int, int))begin_player_attack)((void *) (player + 0x7CC), (void *) (player), 0, 0);
    ((TObjPlayer *)player)->setup_attack_stage();
    ((TObjPlayer *)player)->set_action_state(5, ((TObjPlayer *)player)->call_subobject_m15());
    apply_speed_scale__10TObjPlayerFif((saddr)(player), (f32) (((f32 (*)(void *))get_action_rate_entry)((void *) (player)) * get_attack_controller_rate((void *) (player + 0x7CC))));
}

void handle_6x43_attack(void *src) {
    Pkt_801CF128 pkt;
    u8 *player;
    ((G_Attack_6x43 *)&pkt)->init();
    ((void (*)(Pkt_801CF128 *, void *))TObjPlayer__sub_801D24B0)(&pkt, src);
    ((G_Attack_6x43 *)&pkt)->bswap();
    if (validate_6x43_attack((G_ClientIDHeader *)&pkt) == 0) return;
    player = reinterpret_cast<u8 *>(get_player_by_client_id(pkt.player));
    if (player == 0) return;
    if (((TObjPlayer *)player)->is_in_tl03_state() == 0) return;
    if (reset_volopt_state__10TObjPlayerFv(player) == 0) return;
    if (((TObjPlayer *)player)->test_action_mask(0x8200) != 0) return;
    ((TObjPlayer *)(player + 0x7CC))->set_action_type(pkt.kind);
    *(s32 *)(player + 0x3F0) = pkt.heading;
    ((TObjPlayer *)player)->run_action_state_phase(5, 0);
}
}
void TObjPlayer::request_normal_attack_stage1() {
    u8* arg0 = reinterpret_cast<u8*>(this);
    f32 sp10[3];
    G_Attack_6x43 cmd;
    s16 temp_r31;
    s32 var_r4;
    if ((reset_volopt_state__10TObjPlayerFv(arg0) != 0) && (((u32 (*)(void *, void *))capture_lockon_targets)((void *) (arg0 + 0x7CC), (void *) (arg0)) != 0U)) {
        if (((s32 (*)(void *, void *))get_first_target_position__10TObjPlayerFPvPv)((void *) (arg0 + 0x7CC), (void *) (&sp10)) != 0) {
            var_r4 = calc_angle_to(((TObjPlayer *)arg0)->get_position_ptr(), (Vec *)sp10);
        } else {
            var_r4 = ((TObjPlayer *)arg0)->rotation_y;
        }
        temp_r31 = calc_scaled_value__10TObjPlayerFii((void *) (arg0), (int) (var_r4));
        if ((arg0 == NULL) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
            cmd.init();
            cmd.header.client_id = ((TObjBase *)(arg0))->get_entity_id();
            cmd.angle_y = temp_r31;
            cmd.action_type = ((s16 (*)(void *))TObjPlayer__sub_801D2F4C)((void *) (arg0 + 0x7CC));
            cmd.send();
        }
    }
}

extern "C" {
void TObjPlayer::attack_stage1_phase8_nop() {  }

void TObjPlayer::finish_attack_stage1() {
    Player_801CF2B0 *self = (Player_801CF2B0 *)this;
    if (this->phase == 4) {
        if (((TObjMotion *)self)->is_anim_finished() != 0) {
            run_action_state_phase(1, 5);
        }
    } else if ((this->motion_flags & 0x10) &&
               ((s32 (*)(void *, s32))test_flags_any)(get_anim_field_c__10TObjPlayerFPv(self->act), 1) != 0) {
        switch (attack_state.get_validated_attack_stage()) {
        case 0:
            this->phase = 4;
            clear_status_bit6__10TObjPlayerFPv(self);
            this->requested_action = ((TObjPlayer *)self)->get_idle_animation();
            break;
        case 1:
        case 2:
            run_action_state_phase(6, 5);
            break;
        }
    }
}

void TObjPlayer::update_active_item() {
    s32 arg0 = (saddr)this;
    s32 temp_r3;

    temp_r3 = select_attack_palette_slot();
    if (temp_r3 != -1) {
        ((s32 (*)(s32, s32, s32, s32))queue_physical_attack_input)(arg0 + 0x7CC, arg0, temp_r3, 1);
    }
}

int TObjPlayer::try_attack_stage1_status_action() { return TObjPlayer::try_apply_status_action((TObjPlayer *)this); }

void TObjPlayer::run_attack_stage1_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        try_attack_stage1_status_action();
        return;
      case 2:
        this->update_active_item();
        return;
      case 3:
        this->finish_attack_stage1();
        return;
      case 8:
        attack_stage1_phase8_nop();
        return;
      case 5:
        this->request_normal_attack_stage1();
        return;
      case 0:
        ((s32 (*)(void *))enter_attack_stage1__10TObjPlayerFPv)(this);
        return;
      case 1:
        ((s32 (*)(void *))update_action_state__10TObjPlayerFv)(this);
        return;
      case 6:
        this->reset_lockon();
        break;
    }
  }
}

s32 TObjPlayer::update_aim_target() {
    f32 x;
    s32 temp_r3;

    if (this->is_inactive() == 0) {
        return 0;
    }
    x = 1.5f * sin_table_lookup(this->target_heading);
    this->velocity.x = x;
    this->velocity.y = 0.0f;
    this->velocity.z = (f32) (1.5f * ((f32 (*)(s32, f32, f32))cos_table_lookup)(this->target_heading, x, 1.5f));
    if (this->check_actor_blocking_move() != 0) {
        ((int (*)(void*))clear_velocity)((void*)(this));
        return 0;
    }
    temp_r3 = ((s32 (*)(void *))resolve_move_collision__10TObjPlayerFv)(this);
    if (temp_r3 == 0) {
        return 1;
    }
    if ((TObjPlayer::is_locally_controlled(this) != 0) && (this->check_player_flag1() == 0) && (temp_r3 == 4)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::apply_damage_and_reset() { clear_motion_flags((saddr)((void*)256)); ((int (*)(void*))clear_velocity)((void*)(this)); }

void TObjPlayer::update_run_movement() {
    s32 ang;
    f32 dist;
    Plr_801CF56C *self = (Plr_801CF56C *)this;
    self->target_rot = calc_angle_to(((TObjPlayer *)self)->get_position_ptr(), (Vec *)&self->tx);
    self->rot = approach_angle_adaptive(self->rot, self->target_rot);
    ang = lerp_angle_half__Fll(self->rot, self->target_rot);
    self->vx = self->move_speed.get_speed() * sin_table_lookup(ang);
    self->vy = 0.0f;
    self->vz = self->move_speed.get_speed() * cos_table_lookup(ang);
    dist = (self->tx - self->x) * (self->tx - self->x) + (self->tz - self->z) * (self->tz - self->z);
    if ((2.0f * self->move_speed.get_speed()) * (2.0f * self->move_speed.get_speed()) > dist) {
        self->move_speed.flags.set(4);
    }
    if (((void * (*)(void *))resolve_move_collision__10TObjPlayerFv)(self) == NULL) {
        ((TObjPlayer *)self)->apply_velocity();
    } else {
        self->move_speed.flags.set(4);
    }
    ((TObjPlayer *)self)->play_footstep_sound(1.0f, 10.0f);
    ((TObjPlayer *)self)->emit_footstep_effect(1.0f, 10.0f);
}

void TObjPlayer::start_action() {
    f32 unscaled_speed;
    f32 rate;
    s16 action;

    this->action_state = 4;
    run_action_state_phase(this->mode, 6);
    move_speed.flags.reset();
    action = get_vobj_state_28__10TObjPlayerFv(this);
    if (is_matching_id(action) != 0) {
        set_action_flag();
    }
    move_speed.update(this, 1.5f);
    set_action_state(4, action);
    unscaled_speed = move_speed.get_unscaled_speed();
    rate = ((f32 (*)(void *))get_action_rate_entry)(this);
    set_override_speed(rate * unscaled_speed);
}

void handle_6x42_move_to_position(void *pkt) {
    Cmd_801CF780 cmd;
    Player_801CF780 *p;
    ((G_MoveToPosition_6x41_6x42 *)&cmd)->init();
    ((TObjPlayer *)(&cmd))->copy_packet_pos_6x42(pkt);
    ((G_MoveToPosition_6x41_6x42 *)&cmd)->bswap();
    if (validate_6x42_move_to_position((G_ClientIDHeader *)&cmd) != 0) {
        p = (Player_801CF780 *)get_player_by_client_id(cmd.id);
        if (p != 0 && ((TObjPlayer *)p)->is_in_tl03_state() != 0 && ((TObjPlayer *)p)->test_action_mask(0x1E) != 0) {
            p->x = cmd.x;
            p->z = cmd.z;
            ((TObjPlayer *)p)->run_action_state_phase(4, 0);
        }
    }
}

void TObjPlayer::send_6x42_run_to_position() {
    Npc_801CF824 *arg0 = (Npc_801CF824 *)this;
    Msg_801CF824 m;
    if (update_aim_target() != 0) {
        calc_movement_target(arg0->f3f0, &arg0->x, &arg0->z);
        if ((arg0 == NULL) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
            ((G_MoveToPosition_6x41_6x42 *)&m)->init();
            m.f2 = ((TObjBase *)arg0)->get_entity_id();
            m.x = arg0->x;
            m.z = arg0->z;
            ((G_MoveToPosition_6x41_6x42 *)&m)->send();
        }
    }
}

void TObjPlayer::handle_ring_release() {
    if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
        move_speed.flags.clear(4);
        run_action_state_phase(1, 0);
    }
}

void TObjPlayer::try_trigger_effect() {
    if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
        move_speed.flags.clear(4);
        run_action_state_phase(1, 5);
    }
}

void TObjPlayer::select_run_request() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    s32 temp_r31;
    s32 temp_r31_2;
    temp_r31 = pad_binding.get_stick_angle();
    temp_f31 = pad_binding.get_stick_magnitude();
    if ((this->handle_palette_button_input() == 0) || (this->check_flag_48() == 0)) {
        if (temp_f31 < 0.1f) {
            if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                run_action_state_phase(1, 5);
                return;
            }
            return;
        } else {
            temp_r31_2 = ((s32 (*)(void *, int))calc_scaled_value__10TObjPlayerFii)(arg0, temp_r31);
            if ((this->test_actor_flags(0x100000) != 0) || (temp_f31 < 0.5f)) {
                move_speed.set_run_counter(0);
                if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x3F0) = temp_r31_2;
                    run_action_state_phase(2, 5);
                }
            } else {
                move_speed.increment_run_counter();
                if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x3F0) = temp_r31_2;
                    run_action_state_phase(4, 5);
                }
            }
        }
    }
}

int TObjPlayer::try_run_status_action() { return TObjPlayer::try_apply_status_action((TObjPlayer *)this); }

void TObjPlayer::dispatch_run_state(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        try_run_status_action();
        return;
      case 2:
        this->select_run_request();
        return;
      case 3:
        this->try_trigger_effect();
        return;
      case 8:
        this->handle_ring_release();
        return;
      case 5:
        this->send_6x42_run_to_position();
        return;
      case 0:
        start_action();
        return;
      case 1:
        this->update_run_movement();
        return;
      case 6:
        this->apply_damage_and_reset();
        break;
    }
  }
}

void TObjPlayer::action3_phase6_nop() {  }

void TObjPlayer::action3_phase1_nop() {  }

void TObjPlayer::action3_phase0_nop() {  }

void handle_6x41_move_to_position(void) {

}

void TObjPlayer::action3_phase5_nop() {  }

void TObjPlayer::action3_phase8_nop() {  }

void TObjPlayer::action3_phase3_nop() {  }

void TObjPlayer::action3_phase2_nop() {  }

int TObjPlayer::apply_status_action_b() { return TObjPlayer::try_apply_status_action(this); }

#pragma push
#pragma opt_lifetimes off
void TObjPlayer::run_action3_phase(s16 phase) {
  {
    switch (phase)
    {
      case 7:
        this->apply_status_action_b();
        return;
      case 2:
        action3_phase2_nop();
        return;
      case 3:
        action3_phase3_nop();
        return;
      case 8:
        action3_phase8_nop();
        return;
      case 5:
        action3_phase5_nop();
        return;
      case 0:
        action3_phase0_nop();
        return;
      case 1:
        action3_phase1_nop();
        return;
      case 6:
        action3_phase6_nop();
        break;
    }
  }
}
extern int fold_flush_5;
#pragma pop

#pragma push
#pragma opt_lifetimes off
s32 TObjPlayer__sub_801CFBFC(u8 *arg0) {
  s16 (*var_r12)(void *);
  s32 var_r4;
  u8 *var_r31;
  u8 *var_r3;
  var_r4 = 8;
  var_r31 = (u8 *) arg0;
  var_r3 = (u8 *) (var_r31 + 0x5EC);
  if (((volatile int (*)(void *, s32))test_flags_any)(var_r3, 8) != 0)
  {
    var_r3 = (u8 *) (*((u8 **) (((s8 *) var_r31) + 0x380)));
    var_r12 = *((s16 (**)(void *)) (((s8 *) var_r3) + 8));
    var_r12 = *((s16 (**)(void *)) (((s8 *) var_r12) + 0x3C));
    return var_r12(var_r3);
  }
  var_r3 = (u8 *) (*((u8 **) (((s8 *) var_r31) + 0x380)));
  var_r12 = *((s16 (**)(void *)) (((s8 *) var_r3) + 8));
  var_r12 = *((s16 (**)(void *)) (((s8 *) var_r12) + 0x58));
  return var_r12(var_r3);
}
extern int fold_flush_6;
#pragma pop

s32 TObjPlayer::update_combat_stats() {
    f32 x;
    f32 temp_f31;
    s32 temp_r3;

    if (this->is_inactive() == 0) {
        return 0;
    }
    temp_f31 = move_speed.calc_speed(this);
    x = temp_f31 * sin_table_lookup(this->target_heading);
    this->velocity.x = x;
    this->velocity.y = 0.0f;
    this->velocity.z = (f32) (temp_f31 * ((f32 (*)(int, f32))cos_table_lookup)(this->target_heading, (f32) (x)));
    if (this->check_actor_blocking_move() != 0) {
        clear_velocity((void *) (((u8 *)this)));
        return 0;
    }
    temp_r3 = ((s32 (*)(void *))resolve_move_collision__10TObjPlayerFv)((void *) (((u8 *)this)));
    if (temp_r3 == 0) {
        return 1;
    }
    if ((TObjPlayer::is_locally_controlled((void *) (((u8 *)this))) != 0) && (this->check_player_flag1() == 0) && (temp_r3 == 4)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void TObjPlayer::calc_movement_target(s32 angle, f32 *arg2, f32 *arg3) {
    u8 *arg0 = (u8 *)this;
    *arg2 = (8.0f * sin_table_lookup(angle)) + *(f32 *)((s8 *)arg0 + 0x38);
    *arg3 = (8.0f * cos_table_lookup(angle)) + *(f32 *)((s8 *)arg0 + 0x40);
}
extern int fold_flush_7;
#pragma pop

void TObjPlayer::reset_and_flag() { ((int (*)(void*))clear_velocity)(this); clear_motion_flags((saddr)((void*)256)); }

void TObjPlayer::update_walk_movement() {
    s32 ang;
    f32 dist;
    Plr_801CFDF8 *self = (Plr_801CFDF8 *)this;
    self->target_rot = calc_angle_to(((TObjPlayer *)self)->get_position_ptr(), (Vec *)&self->tx);
    self->rot = approach_angle_adaptive(self->rot, self->target_rot);
    ang = lerp_angle_half__Fll(self->rot, self->target_rot);
    self->vx = self->move_speed.get_speed() * sin_table_lookup(ang);
    self->vy = 0.0f;
    self->vz = self->move_speed.get_speed() * cos_table_lookup(ang);
    dist = (self->tx - self->x) * (self->tx - self->x) + (self->tz - self->z) * (self->tz - self->z);
    if ((2.0f * self->move_speed.get_speed()) * (2.0f * self->move_speed.get_speed()) > dist) {
        self->move_speed.flags.set(4);
    }
    if (((void * (*)(void *))resolve_move_collision__10TObjPlayerFv)(self) == NULL) {
        ((TObjPlayer *)self)->apply_velocity();
    } else {
        self->move_speed.flags.set(4);
    }
    ((TObjPlayer *)self)->play_footstep_sound(1.0f, 15.0f);
    ((TObjPlayer *)self)->emit_footstep_effect(1.0f, 15.0f);
}

void TObjPlayer::set_attack_state() {
    f32 unscaled_speed;
    f32 rate;
    s16 action;

    this->action_state = 2;
    run_action_state_phase(this->mode, 6);
    action = TObjPlayer__sub_801CFBFC((u8 *)this);
    if (is_matching_id(action) != 0) {
        set_action_flag();
    }
    move_speed.update(this);
    set_action_state(2, action);
    unscaled_speed = move_speed.get_unscaled_speed();
    rate = ((f32 (*)(void *))get_action_rate_entry)(this);
    set_override_speed(rate * unscaled_speed);
}

void handle_6x40_walk_to_position(void *pkt) {
    Cmd_801D0000 cmd;
    Player_801D0000 *p;
    ((G_WalkToPosition_6x40 *)&cmd)->init();
    ((TObjPlayer *)(&cmd))->copy_6x40_walk_to_position_packet(pkt);
    ((G_WalkToPosition_6x40 *)&cmd)->bswap();
    if (validate_6x40_walk_to_position((G_ClientIDHeader *)&cmd) != 0) {
        p = (Player_801D0000 *)get_player_by_client_id(cmd.id);
        if (p != 0 && ((TObjPlayer *)p)->is_in_tl03_state() != 0 && ((TObjPlayer *)p)->test_action_mask(0x1E) != 0) {
            p->x = cmd.x;
            p->z = cmd.z;
            ((TTecLuker *)(p->luker))->set_state(cmd.state);
            ((TObjPlayer *)p)->run_action_state_phase(2, 0);
        }
    }
}

void TObjPlayer::send_6x40_walk_to_position() {
    Npc_801D00B0 *arg0 = (Npc_801D00B0 *)this;
    Msg_801D00B0 m;
    if (update_combat_stats() != 0) {
        calc_movement_target(arg0->f3f0, &arg0->x, &arg0->z);
        ((FlagWord *)(arg0->sub))->reset();
        if (((TObjCollidable *)arg0)->test_actor_flags(0x100000) != 0) {
            ((FlagWord *)(arg0->sub))->set(8);
        }
        if ((arg0 == NULL) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
            ((G_WalkToPosition_6x40 *)&m)->init();
            m.f2 = ((TObjBase *)arg0)->get_entity_id();
            m.x = arg0->x;
            m.z = arg0->z;
            m.v = TObjPlayer__sub_801BFFA0(arg0->sub);
            ((G_WalkToPosition_6x40 *)&m)->send();
        }
    }
}

void TObjPlayer::handle_ring_hit() {
    if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
        move_speed.flags.clear(4);
        this->clear_player_status_flag(0, 0x01C00000);
        run_action_state_phase(1, 0);
    }
}

void TObjPlayer::check_ring_action() {
    if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
        move_speed.flags.clear(4);
        move_speed.set_run_counter(0);
        run_action_state_phase(1, 5);
    }
}

void TObjPlayer::select_walk_request() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    s32 temp_r31;
    s32 temp_r31_2;

    temp_r31 = pad_binding.get_stick_angle();
    temp_f31 = pad_binding.get_stick_magnitude();
    if ((this->handle_palette_button_input() == 0) || (this->check_flag_48() == 0)) {
        if (temp_f31 < 0.1f) {
            if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                run_action_state_phase(1, 5);
                return;
            }
            return;
        } else {
            temp_r31_2 = ((s32 (*)(void *, int))calc_scaled_value__10TObjPlayerFii)(arg0, temp_r31);
            if (temp_f31 > 0.5f) {
                move_speed.increment_run_counter();
            }
            if (this->test_actor_flags(0x100000) != 0) {
                if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x3F0) = temp_r31_2;
                    run_action_state_phase(2, 5);
                }
            } else if (test_flags_any(&move_speed.flags.bits, 4) != 0) {
                *(s32 *)((s8 *)arg0 + 0x3F0) = temp_r31_2;
                if ((f32) move_speed.get_run_counter() < 24.0f) {
                    run_action_state_phase(2, 5);
                    return;
                }
                run_action_state_phase(4, 5);
            }
        }
    }
}

int TObjPlayer::try_walk_status_action() { return TObjPlayer::try_apply_status_action((TObjPlayer *)this); }

void TObjPlayer::run_walk_state_phase(s16 phase) {
  int new_var;
  new_var = ((u32) phase) <= 8U;
  {
    switch (phase)
    {
      case 7:
        try_walk_status_action();
        return;
      case 2:
        this->select_walk_request();
        return;
      case 3:
        this->check_ring_action();
        return;
      case 8:
        this->handle_ring_hit();
        return;
      case 5:
        this->send_6x40_walk_to_position();
        return;
      case 0:
        set_attack_state();
        return;
      case 1:
        this->update_walk_movement();
        return;
      case 6:
        this->reset_and_flag();
        break;
    }
  }
}

s16 TObjPlayer::get_idle_animation() {
    if (this->actorFlags & 0x100000) {
        return ((VObj_8_e57d67 *)((u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x380))))->m18();
    }
    return ((VObj_8_e57d67 *)((u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x380))))->m21();
}

void TObjPlayer::cleanup_idle_entry() { clear_actor_flags((uaddr)((void*)3840)); clear_state_flags((s32)(128)); move_speed.set_run_counter(0); ((int (*)(void*))clear_status_bit6__10TObjPlayerFPv)(this); ((int (*)(void*))clear_velocity)(this); death_sink.reset(); }

void TObjPlayer::exit_idle_state() {  }

void TObjPlayer::update_action(saddr owner) {
    u32 temp_r3;

    temp_r3 = ((u32 (*)(void))resolve_move_collision__10TObjPlayerFv)();
    if (temp_r3 == 0U) {
        ((TObjPlayer *)owner)->apply_velocity();
    } else if (temp_r3 == 1U) {
        ((TObjPlayer *)owner)->rewind_position_history();
    }
    if ((((TObjPlayer *)owner)->is_newman() != 0) && (TFontSmallLobby::is_lobby_floor_15() == 0) && (((TObjPlayer *)owner)->tick_regen_timer() != 0)) {
        add_actor_tp(reinterpret_cast<TObjChara *>(owner), 1);
    }
    if ((((s32 (*)(s32))is_android_player)(owner) != 0) && (TFontSmallLobby::is_lobby_floor_15() == 0) && (((TObjPlayer *)owner)->tick_regen_timer() != 0)) {
        add_actor_hp(reinterpret_cast<TObjChara *>(owner), 1);
    }
}

void TObjPlayer::start_animation() {
    this->action_state = 1;
    run_action_state_phase(this->mode, 6);
    cleanup_idle_entry();
    this->set_action_state(1, this->get_idle_animation());
}

void handle_6x3F_set_position(void *command) {
    Msg_801D0634 m;
    Player_801D0634 *p;
    ((TObjPlayer *)(&m))->init_set_position_packet();
    ((void (*)(void *, void *))TObjPlayer__sub_801D2540)(&m, command);
    ((TObjPlayer *)(&m))->byteswap_set_position_cmd();
    if (validate_6x3F_set_position((G_ClientIDHeader *)&m) != 0) {
        p = (Player_801D0634 *)get_player_by_client_id(m.id);
        if (p != NULL) {
            ((TObjBase *)p)->set_position_from(m.vec);
            ::set_flag_400000((TObjPlayer *)p);
            if (m.floor >= 0) {
                ((TObjPlayer *)p)->set_floor(m.floor);
                ((TObjPlayer *)p)->set_floor_index(get_floor_area(m.floor));
            }
            if (m.room >= 0) {
                ((TObjPlayer *)p)->set_room(m.room);
            }
            p->ang = m.ang;
            if (m.flag != 1) {
                ((TObjBase *)p)->clear_actor_flags((u32)0x100000);
            } else {
                ((TObjBase *)p)->set_actor_flags(0x100000);
            }
            ((TObjPlayer *)p)->run_action_state_phase(1, 0);
        }
    }
}

void handle_6x3E_stop_at_position(void *command) {
    Msg_801D0634 m;
    Player_801D0724 *p;
    ((G_StopAtPosition_6x3E *)(&m))->init();
    ((void (*)(void *, void *))TObjPlayer__sub_801D25AC)(&m, command);
    ((G_StopAtPosition_6x3E *)(&m))->bswap();
    if (validate_6x3E_stop_at_position((G_ClientIDHeader *)&m) == 0) {
        return;
    }
    p = (Player_801D0724 *)get_player_by_client_id(m.id);
    if (p == NULL) {
        return;
    }
    ((TObjBase *)p)->set_position_from(m.vec);
    if (m.floor >= 0) {
        ((TObjPlayer *)p)->set_floor(m.floor);
        ((TObjPlayer *)p)->set_floor_index(get_floor_area(m.floor));
    }
    p->ang = m.ang;
    if (((TObjPlayer *)p)->is_in_tl03_state() == 0 || ((TObjPlayer *)p)->test_action_mask(0x8100) != 0 ||
        (((TObjPlayer *)p)->test_action_mask(0x200) != 0 && p->f328 <= 2) ||
        (((TObjPlayer *)p)->test_action_mask(0x4000) != 0 && p->f328 == 0)) {
        return;
    }
    if (m.room >= 0) {
        ((TObjPlayer *)p)->set_room(m.room);
    }
    switch (m.flag) {
    case 0:
        ((TObjBase *)p)->clear_actor_flags((u32)0x100000);
        break;
    case 1:
        ((TObjBase *)p)->set_actor_flags(0x100000);
        break;
    }
    ((TObjPlayer *)p)->run_action_state_phase(1, 0);
}

void TObjPlayer::update_position_from_target() { ((int (*)(void*, void*, void*))send_idle_return_event__10TObjPlayerFPvPvs)(this, (char*)this + 0x38, *(void**)((char*)this + 0x60)); }

void send_idle_return_event__10TObjPlayerFPvPvs(void *player, void *arg1, s16 arg2) {
    Msg_801D08B0 m;
    s32 t;
    if ((player == NULL) || (((TObjChara *)player)->obj_isState2_324() == 0)) {
        t = ((TObjCollidable *)player)->test_actor_flags(0x100000) != 0 ? 1 : 0;
        ((TObjPlayer *)(&m))->init_set_position_packet();
        m.f2 = ((TObjBase *)player)->get_entity_id();
        m.f4 = t;
        m.f6 = arg2;
        m.f8 = ((TObjPlayer *)player)->get_floor();
        m.fa = ((TObjBase *)player)->get_room();
        VecCopy__FP3VecPC3Vec(m.vec, arg1);
        TObjPlayer__sub_801C18E0(&m);
    }
}

void TObjPlayer::send_6x3E_stop_at_position() {
    Player_801D094C *arg0 = (Player_801D094C *)this;
    Msg_801D094C m;
    s32 t;
    if ((arg0 == NULL) || (((TObjChara *)arg0)->obj_isState2_324() == 0)) {
        t = ((TObjCollidable *)arg0)->test_actor_flags(0x100000) != 0 ? 1 : 0;
        ((G_StopAtPosition_6x3E *)(&m))->init();
        m.f2 = ((TObjBase *)arg0)->get_entity_id();
        m.f4 = t;
        m.f6 = this->rotation_y;
        ((TObjPlayer *)arg0)->sync_current_floor();
        ((TObjPlayer *)arg0)->sync_current_area();
        m.f8 = ((TObjPlayer *)arg0)->get_floor();
        m.fa = ((TObjBase *)arg0)->get_room();
        VecCopy__FP3VecPC3Vec(m.vec, arg0->vec);
        ((G_StopAtPosition_6x3E *)(&m))->send();
    }
}

void TObjPlayer::idle_phase8_nop() {  }

void TObjPlayer::complete_idle_state() {  }

void TObjPlayer::check_idle_movement_request() {
    f32 temp_f31;
    s32 temp_r31;
    u8 *arg0 = (u8 *)this;
    temp_f31 = pad_binding.get_stick_magnitude();
    temp_r31 = pad_binding.get_stick_angle();
    if ((this->handle_palette_button_input() == 0) || (this->check_flag_48() == 0)) {
        *(s16 *)((s8 *)arg0 + 0x3C0) = this->select_idle_action();
        if (is_action_id_none((int) (*(s16 *)((s8 *)arg0 + 0x3C0))) == 0) {
            if (*(s16 *)((s8 *)arg0 + 0x3C0) == (*(VObj_8_684c72 **)(arg0 + 0x380))->m65() ||
                *(s16 *)((s8 *)arg0 + 0x3C0) == (*(VObj_8_684c72 **)(arg0 + 0x380))->m66()) {
                run_action_state_phase(0x18, 5);
            } else {
                run_action_state_phase(0x17, 5);
            }
            return;
        }
        if (temp_f31 >= 0.1f) {
            *(s32 *)((s8 *)arg0 + 0x3F0) = ((s32 (*)(void *, int))calc_scaled_value__10TObjPlayerFii)(this, (int) (temp_r31));
            run_action_state_phase(2, 5);
        }
    }
}

int TObjPlayer::try_apply_status_action_2() { return TObjPlayer::try_apply_status_action(this); }

void TObjPlayer::run_idle_state_phase(s16 phase) {
    saddr arg0 = (saddr)this;
  saddr new_var;
  {
    switch (phase)
    {
      case 7:
        this->try_apply_status_action_2();
        return;
      new_var = arg0;
      case 2:
        ((TObjPlayer *)new_var)->check_idle_movement_request();
        return;
      case 3:
        TObjPlayer::complete_idle_state();
        return;
      case 8:
        idle_phase8_nop();
        return;
      case 5:
        ((TObjPlayer *)new_var)->send_6x3E_stop_at_position();
        return;
      case 0:
        ((TObjPlayer *)new_var)->start_animation();
        return;
      case 1:
        TObjPlayer::update_action(new_var);
        return;
      case 6:
        TObjPlayer::exit_idle_state();
        break;
    }
  }
}

void TObjPlayer::run_action_state_phase(s16 state, s16 phase) {
    switch (state) {
    case 1:
        run_idle_state_phase(phase);
        break;
    case 2:
        run_walk_state_phase(phase);
        break;
    case 3:
        run_action3_phase(phase);
        break;
    case 4:
        dispatch_run_state(phase);
        break;
    case 5:
        run_attack_stage1_phase(phase);
        break;
    case 6:
        run_attack_stage2_phase(phase);
        break;
    case 7:
        run_attack_stage3_phase(phase);
        break;
    case 8:
        dispatch_technique_cast_state(phase);
        break;
    case 9:
        dispatch_photon_blast_action(phase);
        break;
    case 10:
        run_guard_reaction_phase(phase);
        break;
    case 11:
        run_action11_phase(phase);
        break;
    case 12:
        run_switch_interaction_phase(phase);
        break;
    case 13:
        run_hurt_state_phase(phase);
        break;
    case 14:
        run_fall_reaction_phase(phase);
        break;
    case 15:
        run_death_state_phase(phase);
        break;
    case 18:
        run_revival_state_phase(phase);
        break;
    case 16:
        run_service_hold_state_phase(phase);
        break;
    case 19:
        run_freeze_state_phase(phase);
        break;
    case 20:
        run_warp_action_phase(phase);
        break;
    case 21:
        sub_801C8C50(phase);
        break;
    case 22:
        run_off_floor_state_phase(phase);
        break;
    case 23:
        run_lobby_animation_state_phase(phase);
        break;
    case 24:
        run_lobby_chair_state_phase(phase);
        break;
    }
}

void TObjPlayer::update_lobby_chair(s32 value) { chair_seat.set_move_angle(value); }

void TObjPlayer::get_chair_state(s32 value) { chair_seat.set_target_angle(value); }

void TObjPlayer::leave_chair_seat() { this->chair_seat.update(); }

void TObjPlayer::clear_chair_seated() { this->state_flags &= 0xfbffffff; }

void TObjPlayer::clear_anim_flag() { this->state_flags &= 0xf7ffffff; }

void TObjPlayer::clear_state_flag() { this->state_flags &= 0xefffffff; }

int TObjPlayer__sub_801D0DAC(void* p) { return ((TObjPlayer *)p)->chair_seat.get_target_angle(); }

short TObjPlayer::start_action18_sub() { return chair_seat.get_animation(); }

int TObjPlayer::create_photon_chair() { return this->chair_seat.create_chair(); }

void TObjPlayer::set_chair_seated() { this->state_flags |= 0x4000000; }

int TObjPlayer::get_action_flag() { return (this->state_flags >> 27) & 0x1; }

void TObjPlayer::forward_1D1044_at_34c(s16 value) { chair_seat.set_animation(value); }

int TObjPlayer::is_action_flag_28() { return (this->state_flags >> 28) & 0x1; }

void TObjPlayer::set_anim_flag() { this->state_flags |= 0x8000000; }

void TObjPlayer__sub_801D0E74(void* p) { *(u32*)((char*)p + 0x334) |= 0x10000000; }

void TObjPlayer::clear_lobby_pose_hold() { this->state_flags &= 0xdfffffff; }

int TObjPlayer::get_flag() { return (this->state_flags >> 29) & 0x1; }

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_IntraMapWarp_6x55 *TObjPlayer__sub_801D0EA0(G_IntraMapWarp_6x55 *destination, G_IntraMapWarp_6x55 *source) {
    reinterpret_cast<void *(*)(void *, void *)>(copy_subcommand_header)(&destination->header, &source->header);
    destination->angle_y = source->angle_y;
    __memcpy(&destination->from_pos, &source->from_pos, sizeof(Vec));
    __memcpy(&destination->pos, &source->pos, sizeof(Vec));
    return destination;
}
extern int fold_flush_8;
#pragma pop

short TObjPlayer::query_child_state2() {
    struct VObj_801D0F0C *o = (struct VObj_801D0F0C *)this->action_provider;
    return o->m23();
}

void release_control_lock__10TObjPlayerFPv(void* p) { ((TObjPlayer *)p)->clear_flag_200(); }

void TObjPlayer::clear_flag_200() { this->state_flags &= 0xfffffdff; }

void TObjPlayer__sub_801D0F70(void* p) { *(u32*)((char*)p + 0x334) |= 0x200; }

void*TObjPlayer::get_field4_ptr() { return (char*)this + 0x4; }

int copy_position__10TObjPlayerFPv(void* p) { return ((int (*)(void*))VecCopy__FP3VecPC3Vec)((char*)p + 0x4); }

void TObjPlayer::set_float_param(s16 arg1) {
    saddr arg0 = (saddr)this;
    ((TObjPlayer *)arg0)->photon_blast_gauge.set_field_3c((f32) (s32) arg1);
}

void update_player_action_palette(TObjPlayer *player, u8 slot) {
    set_player_action_palette_slot(&player->action_palette_state, slot);
}
}

int is_android_player(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_ANDROID) != 0; }


void PhotonChairSeat::set_move_angle(s32 v) { move_angle = v; }

void PhotonChairSeat::set_target_angle(s32 angle) { target_angle = angle; }

s32 PhotonChairSeat::get_target_angle() { return target_angle; }

s16 PhotonChairSeat::get_animation() { return animation; }

void PhotonChairSeat::set_animation(s16 v) { animation = v; }

void PhotonChairSeat::start_delay_6xAF() { delay_6xAF = 8; }

void PhotonChairSeat::tick_delay_6xAF() {
    if (--delay_6xAF < 0) {
        delay_6xAF = 0;
    }
}

s32 PhotonChairSeat::is_delay_6xAF_over() { return delay_6xAF <= 0; }

void PhotonChairSeat::start_delay_6xB0() { delay_6xB0 = 8; }

void PhotonChairSeat::tick_delay_6xB0() {
    if (--delay_6xB0 < 0) {
        delay_6xB0 = 0;
    }
}

s32 PhotonChairSeat::is_delay_6xB0_over() { return delay_6xB0 <= 0; }

void TObjPlayer__sub_801D10D4(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_32__FPUl((char*)p + 0x4); }

void *TObjPlayer::copy_lobby_font_header(void *command) {
    copy_subcommand_header((void*)(this));
    *(void **)((s8 *)this + 0x4) = *(void **)((s8 *)command + 0x4);
    return this;
}

void TObjPlayer__sub_801D1144(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0xB0;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::swap_endian32() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); }

void *TObjPlayer__sub_801D1194(void *arg0, void *arg1) {
    copy_subcommand_header((void*)(arg0));
    *(void **)((s8 *)arg0 + 0x4) = *(void **)((s8 *)arg1 + 0x4);
    return arg0;
}

void TObjPlayer__sub_801D11D0(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0xAF;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

int TObjPlayer__sub_801D11EC(void* p) { return *(u16*)((char*)p + 0x6) & 0x1; }

int TObjPlayer__sub_801D11F8(void* p) { return (*(u16*)((char*)p + 0x6) >> 1) & 0x1; }

void TObjPlayer::swap_bytes() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void *TObjPlayer::copy_packet_header_6xAB(void *command) {
    copy_subcommand_header((void*)(this));
    *(u16 *)((s8 *)this + 0x4) = *(s16 *)((s8 *)command + 0x4);
    this->m_id = *(u16 *)((s8 *)command + 0x6);
    return this;
}

void TObjPlayer__sub_801D1284(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0xAB;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::send_swapped_bytes() { swap_bytes(); send_subcommand(this); }

void TObjPlayer__sub_801D12D8(void* p) { *(u16*)((char*)p + 0x6) |= 0x1; }

void TObjPlayer__sub_801D12E8(void* p) { *(u16*)((char*)p + 0x6) |= 0x2; }

void TObjPlayer::send_swapped_packet() { swap_endian32(); send_subcommand(this); }

void TObjPlayer::bswap_and_send() { TObjPlayer__sub_801D10D4(this); send_subcommand(this); }

int TObjPlayer__sub_801D1360(void* p) { return *(u16*)((char*)p + 0x6) & 0x1; }

void TObjPlayer::bswap_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void *TObjPlayer::copy_packet_header_6x58(void *command) {
    copy_subcommand_header((void*)(this));
    *(u16 *)((s8 *)this + 0x4) = *(s16 *)((s8 *)command + 0x4);
    this->m_id = *(u16 *)((s8 *)command + 0x6);
    return this;
}

void TObjPlayer__sub_801D13EC(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x58;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::handle_recv_packet() { bswap_packet(); broadcast_subcommand(this); }

void TObjPlayer__sub_801D1440(void* p) { *(u16*)((char*)p + 0x6) |= 0x1; }

void* handle_6x57__10TObjPlayerFPv(void* p) { copy_subcommand_header(p); return p; }

void TObjPlayer::set_cmd_87() { *(u8*)((char*)this + 0x0) = 87; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::draw_and_send() { bswap_g_client_id_header(this); send_subcommand(this); }

void TObjPlayer::swap_endian_words() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); bswap_32__FPUl((char*)this + 0x8); bswap_32__FPUl((char*)this + 0xc); bswap_32__FPUl((char*)this + 0x10); }

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
u8 *TObjPlayer__sub_801D1514(u8 *arg0, u8 *arg1) {
    copy_subcommand_header((void*)(arg0));
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_C *)((saddr) arg0 + 8) = *(const ByteBlock_C *)((saddr) arg1 + 8);
    return arg0;
}
extern int fold_flush_9;
#pragma pop

void TObjPlayer::init_position_packet() { *(float*)((char*)this + 0x10) = 0.0f; *(float*)((char*)this + 0xc) = 0.0f; *(float*)((char*)this + 0x8) = 0.0f; *(unsigned char*)((char*)this + 0x0) = 86; *(unsigned char*)((char*)this + 0x1) = 5; }

void TObjPlayer::update_and_send2() { swap_endian_words(); send_subcommand(this); }

void G_IntraMapWarp_6x55::send() { bswap(); send_subcommand(this); }

void G_IntraMapWarp_6x55::bswap() {
    header.bswap();
    bswap_32__FPUl(&angle_y);
    bswap_32__FPUl(&from_pos.x);
    bswap_32__FPUl(&from_pos.y);
    bswap_32__FPUl(&from_pos.z);
    bswap_32__FPUl(&pos.x);
    bswap_32__FPUl(&pos.y);
    bswap_32__FPUl(&pos.z);
}

void G_IntraMapWarp_6x55::init() {
    angle_y = 0;
    from_pos.z = 0.0f;
    from_pos.y = 0.0f;
    from_pos.x = 0.0f;
    pos.z = 0.0f;
    pos.y = 0.0f;
    pos.x = 0.0f;
    header.subcommand = 0x55;
    header.size = 8;
}

void TObjPlayer::set_type_53() { *(u8*)((char*)this + 0x0) = 83; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::send_name() { bswap_g_client_id_header(this); send_subcommand(this); }

void TObjPlayer::swap_stats_bytes() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); bswap_32__FPUl((char*)this + 0x8); }

void*TObjPlayer::copy_font_state(void* a1) { copy_subcommand_header(this); *(short*)((char*)this + 0x4) = *(short*)((char*)a1 + 0x4); *(short *)&this->m_id = *(short*)((char*)a1 + 0x6); *(void* *)&this->m_prev = *(void**)((char*)a1 + 0x8); return this; }

void TObjPlayer::init_6x52_packet() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 4) = 0;
    this->m_id = 0;
    *(s32 *)((s8 *)arg0 + 8) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x52;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}

void TObjPlayer::update_display() { swap_stats_bytes(); send_subcommand(this); }

void TObjPlayer::set_revived_state() { *(u8*)((char*)this + 0x0) = 79; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::broadcast_lobby_display() { bswap_g_client_id_header(this); send_subcommand(this); }

void TObjPlayer::bswap_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void*TObjPlayer::copy_head_fields(void* command) { copy_subcommand_header(this); *(short*)((char*)this + 0x4) = *(unsigned short*)((char*)command + 0x4); this->m_id = *(short*)((char*)command + 0x6); return this; }

void TObjPlayer::init_6x89_packet() {
    Pkt_801D1888 *p = (Pkt_801D1888 *)this;
    p->a = 0xFFFF;
    p->b = 0;
    p->cmd = 0x89;
    p->size = 2;
}

void TObjPlayer::init_revive_packet() { *(u8*)((char*)this + 0x0) = 78; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::bswap_font_lobby2() { bswap_g_client_id_header(this); send_subcommand(this); }

void TObjPlayer::init_field_4() { ((G_ClientIDHeader *)this)->bswap(); ((TObjPlayer *)((char*)this + 0x4))->bswap_field_u32(); }

void *TObjPlayer::init_6x4D_packet() {
    struct VOff_801D192C_arg0_801D18B0 *self = (struct VOff_801D192C_arg0_801D18B0 *)this;
    __ct__8FlagWordFv((self->f_4));
    ((FlagWord *)(self->f_4))->reset();
    *(u8 *)((s8 *)this + 0x0) = 77;
    *(u8 *)((s8 *)this + 0x1) = 2;
    return this;
}

void TObjPlayer::init_and_send() { init_field_4(); send_subcommand(this); }

void TObjPlayer::update_and_send3() { bswap_fields(); send_subcommand(this); }

void TObjPlayer::bswap_head_pair() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); ((int (*)(void*))TObjPlayer__sub_801D28DC)((char*)this + 0x8); }

void TObjPlayer::init_6x4C_packet() { this->m_id = 0; *(short*)((char*)this + 0x4) = 0; *(float*)((char*)this + 0xc) = 0.0f; *(float*)((char*)this + 0x8) = 0.0f; *(unsigned char*)((char*)this + 0x0) = 76; *(unsigned char*)((char*)this + 0x1) = 4; }

void TObjPlayer::send_head_pair_packet() { bswap_head_pair(); send_subcommand(this); }

void TObjPlayer::read_swapped_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); ((int (*)(void*))TObjPlayer__sub_801D28DC)((char*)this + 0x8); }

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
u8 *copy_6x4b_hit_by_enemy_packet__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1) {
    ((u8 * (*)(void *))copy_subcommand_header)(arg0);
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(ByteBlock_8 *)((saddr) arg0 + 8) = *(const ByteBlock_8 *)((saddr) arg1 + 8);
    return arg0;
}
extern int fold_flush_10;
#pragma pop

void TObjPlayer::reset_action_state() { this->m_id = 0; *(short*)((char*)this + 0x4) = 0; *(float*)((char*)this + 0xc) = 0.0f; *(float*)((char*)this + 0x8) = 0.0f; *(unsigned char*)((char*)this + 0x0) = 75; *(unsigned char*)((char*)this + 0x1) = 4; }

void TObjPlayer::handle_recv_state() { read_swapped_fields(); send_subcommand(this); }

void TObjPlayer::swap_endian_field() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); }

void TObjPlayer__sub_801D1BB0(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x51;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::refresh_players() { swap_endian_field(); broadcast_subcommand(this); }

void TObjPlayer::bswap_field4() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); }

void* copy_font__10TObjPlayerFPvPv(void* p, void* a1) { copy_subcommand_header(p); *(void**)((char*)p + 0x4) = *(void**)((char*)a1 + 0x4); return p; }

void TObjPlayer__sub_801D1C70(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x50;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::sync_players() { bswap_field4(); broadcast_subcommand(this); }

void TObjPlayer::init_shield_attack_packet() { *(u8*)((char*)this + 0x0) = 74; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::draw_font_and_send() { bswap_g_client_id_header(this); send_subcommand(this); }

void TObjPlayer::swap_endian16() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void *TObjPlayer__sub_801D1D44(void *arg0, void *arg1) {
    copy_subcommand_header((void*)(arg0));
    *(u16 *)((s8 *)arg0 + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    *(u16 *)((s8 *)arg0 + 0x6) = *(s16 *)((s8 *)arg1 + 0x6);
    return arg0;
}

void TObjPlayer__sub_801D1D88(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x37;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::update_and_send4() { swap_endian16(); send_subcommand(this); }

void TObjPlayer::byteswap_6x49_packet() {
    struct Packet_801D1DDC *pkt = (struct Packet_801D1DDC *)this;
    s32 i;
    ((G_ClientIDHeader *)pkt)->bswap();
    ((TObjPlayer *)(&pkt->kind))->swap_endian_shorts();
    for (i = 0; i < pkt->count; i++) {
        ((PhotonBlastTarget *)&pkt->targets[i])->bswap();
    }
}

void TObjPlayer::swap_endian_shorts() { bswap_16__FPUs((char*)this + 0x2); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
s32 copy_photon_blast_data__10TObjPlayerFiPv(saddr arg0, u8 *arg1) {
  saddr var_r30;
  s32 var_r3;
  saddr var_r5;
  s32 var_r6;
  u8 *var_r31;
  u8 *var_r4;
  var_r30 = arg0;
  var_r31 = (u8 *) arg1;
  copy_subcommand_header((void*)(arg0));
  var_r6 = *((s32 *) (((s8 *) var_r31) + 4));
  var_r3 = *((s32 *) (((s8 *) var_r31) + 8));
  if ((arg0 && arg0) && arg0)
  {
  }
  var_r5 = var_r30 + 8;
  var_r4 = (u8 *) (var_r31 + 8);
  *((s32 *) (((s8 *) var_r30) + 4)) = var_r6;
  *((s32 *) (((s8 *) var_r30) + 8)) = var_r3;
  *((ByteBlock_28 *) (var_r5 + 4)) = *((const ByteBlock_28 *) (((saddr) var_r4) + 4));
  var_r5 += 0x28;
  var_r4 += 0x28;
  var_r3 = var_r30;
  return var_r3;
}
extern int fold_flush_11;
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
G_ExecutePhotonBlast_6x49::G_ExecutePhotonBlast_6x49() {
    header.subcommand = 0x49;
    header.size = sizeof(G_ExecutePhotonBlast_6x49) / 4;
}
extern int fold_flush_12;
#pragma pop

G_ExecutePhotonBlastParams_6x49::G_ExecutePhotonBlastParams_6x49() {
    unused2 = 0;
    pb_meter_value = 0;
    target_count = 0;
    unused1 = 0;
    photon_blast = 0;
}

void send_photon_blast_targets_packet(u8 *player) {
    *(s8 *)((s8 *)player + 1) = (s8) ((((u32)TObjPlayer__sub_801D2004((u8 *)(player))) >> 2U) & 0x3F);
    ((TObjPlayer *)player)->byteswap_pb_targets_packet();
    send_subcommand(player);
}

void TObjPlayer::byteswap_pb_targets_packet() {
    Obj_801D1FA4 *arg0 = (Obj_801D1FA4 *)this;
    s32 i;
    ((G_ClientIDHeader *)arg0)->bswap();
    for (i = 0; i < *(s16 *)&this->m_id; i++) {
        ((PhotonBlastTarget *)&arg0->e[i])->bswap();
    }
    ((TObjPlayer *)((u8 *)arg0 + 4))->swap_endian_shorts();
}

u8 TObjPlayer__sub_801D2004(u8 *arg0) {
    return (u8) (0x34 - ((0xA - *(s16 *)((s8 *)arg0 + 6)) * 4));
}

void TObjPlayer::bswap_coords() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void* TObjPlayer__sub_801D2058(void* p, void* a1) { copy_subcommand_header(p); *(short*)((char*)p + 0x4) = *(unsigned short*)((char*)a1 + 0x4); *(short*)((char*)p + 0x6) = *(short*)((char*)a1 + 0x6); return p; }

void TObjPlayer::init_6x33_packet() {
    Pkt_801D209C *p = (Pkt_801D209C *)this;
    p->a = 0xFFFF;
    p->b = 0;
    p->cmd = 0x33;
    p->size = 2;
}

void TObjPlayer::send_coords() { bswap_coords(); send_subcommand(this); }

void TObjPlayer::swap_header() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void *TObjPlayer::copy_6x48_cast_technique_complete_packet(void *arg1) {
    copy_subcommand_header((void*)(this));
    *(u16 *)((s8 *)this + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    this->m_id = *(s16 *)((s8 *)arg1 + 0x6);
    return this;
}

void init_6x48_cast_complete_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x48;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::send_swapped_header() { swap_header(); send_subcommand(this); }

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
u8 *TObjPlayer__sub_801D21CC(u8 *buf, u8 *arg1) {
    copy_subcommand_header((void*)(buf));
    *(s32 *)((s8 *)buf + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_28 *)(buf + 4 + 4) = *(const ByteBlock_28 *)((saddr) (arg1 + 4) + 4);
    return buf;
}
extern int fold_flush_13;
#pragma pop

void TObjPlayer::swap_field6() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x6); }

void *TObjPlayer::copy_6x8d_technique_level_packet(void *command) {
    copy_subcommand_header((void*)(this));
    *(u8 *)((s8 *)this + 0x4) = *(u8 *)((s8 *)command + 0x4);
    *(u8 *)((s8 *)this + 0x5) = *(u8 *)((s8 *)command + 0x5);
    this->m_id = *(s16 *)((s8 *)command + 0x6);
    return this;
}

void init_6x8D_technique_level_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 5) = 0;
    *(s8 *)((s8 *)arg0 + 4) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0x8D;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::send_swap_field6() { swap_field6(); send_subcommand(this); }

void *TObjPlayer::copy_6x45_attack_packet(void *src) {
    copy_subcommand_header((void*)(this));
    *(u16 *)((s8 *)this + 0x4) = *(s16 *)((s8 *)src + 0x4);
    this->m_id = *(s16 *)((s8 *)src + 0x6);
    return this;
}

void *TObjPlayer__sub_801D2348(void *arg0, void *arg1) {
    copy_subcommand_header((void*)(arg0));
    *(u16 *)((s8 *)arg0 + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    *(u16 *)((s8 *)arg0 + 0x6) = *(s16 *)((s8 *)arg1 + 0x6);
    return arg0;
}

void TObjPlayer::bswap_field4_sub() { ((G_ClientIDHeader *)this)->bswap(); ((TObjPlayer *)((char*)this + 0x4))->bswap_u16_pair_list(); }

void*TObjPlayer::build_packet_header() { TObjPlayer__sub_8012AF00((CapturedTargetList *)((char*)this + 0x4)); *(unsigned char*)(this) = 70; *(unsigned char*)((char*)this + 0x1) = 12; return this; }

void send_6x46_attack_finished(u8 *arg0) {
    *(s8 *)((s8 *)arg0 + 1) = (s8) ((((u32 (*)(void))get_6x46_strike_packet_size)() >> 2U) & 0x3F);
    TObjPlayer__sub_801D2448((void*)((void *) (arg0)));
    send_subcommand((void*)((void *) (arg0)));
}

void TObjPlayer__sub_801D2448(void* p) { ((G_ClientIDHeader *)p)->bswap(); ((TObjPlayer *)((char*)p + 0x4))->bswap_entry_list(); }

#pragma push
#pragma dont_inline off
#pragma dont_inline off
#pragma dont_inline off
u8 get_6x46_strike_packet_size(saddr arg0) {
    return (u8) (0x30 - ((0xA - ((CapturedTargetList *)(arg0 + 4))->get_captured_target_count()) * 4));
}
extern int fold_flush_14;
#pragma pop

#pragma push
#pragma dont_inline off
#pragma dont_inline off
#pragma dont_inline off

void *TObjPlayer__sub_801D24B0(void *arg0, void *arg1) {
    copy_subcommand_header((void*)((void*)((void*)(arg0))));
    *(u16 *)((s8 *)arg0 + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    *(u16 *)((s8 *)arg0 + 0x6) = *(s16 *)((s8 *)arg1 + 0x6);
    return arg0;
}
extern int fold_flush_15;
#pragma pop

#pragma push
#pragma dont_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
void *TObjPlayer::copy_6x40_walk_to_position_packet(void *pkt) {
    copy_subcommand_header(this);
    ((Pkt_801D24F4 *)this)->pos = ((Pkt_801D24F4 *)pkt)->pos;
    return this;
}
extern int fold_flush_16;
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
u8 *TObjPlayer__sub_801D2540(u8 *arg0, u8 *arg1) {
    copy_subcommand_header((void*)((void*)(arg0)));
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)((s8 *)arg0 + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(ByteBlock_C *)((saddr) arg0 + 0xC) = *(const ByteBlock_C *)((saddr) arg1 + 0xC);
    return arg0;
}
extern int fold_flush_17;
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
u8 *TObjPlayer__sub_801D25AC(u8 *arg0, u8 *arg1) {
    copy_subcommand_header((void*)(arg0));
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)((s8 *)arg0 + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(ByteBlock_C *)((saddr) arg0 + 0xC) = *(const ByteBlock_C *)((saddr) arg1 + 0xC);
    return arg0;
}
extern int fold_flush_18;
#pragma pop

void TObjPlayer::set_frame(f32 v) { this->frame = v; }

void TObjPlayer::set_action_flag_40() { this->motion_flags |= 0x40; }

void clear_status_bit6__10TObjPlayerFPv(void* p) { *(u32*)((char*)p + 0xb0) &= 0xffffffbf; }

f32 get_action_rate_entry(Obj_801D2640 *p) {
    return p->arr[p->idx].f;
}

void TObjPlayer::set_field_d4_and_flag_200(f32 value) {
    u8 *p = (u8 *)this;
    *(f32 *)(p + 0xD4) = value;
    set_motion_flags(MOTION_OVERRIDE_BLEND_SPEED);
}

int TObjPlayer::is_motion_paused() {
    return (this->motion_flags >> 6) & 1;
}

void TObjPlayer::set_action_flag() {
    this->motion_flags |= 0x80;
}

int TUnk_804DDD28::vfunc_68() { return -1; }

int TUnk_804DDD28::vfunc_67() { return -1; }

int ret_801D26AC(void) { return -1; }

int TUnk_804DDD28::vfunc_72() { return -1; }

int TUnk_804DDD28::vfunc_71() { return -1; }

int TUnk_804DDD28::vfunc_70() { return -1; }

int TUnk_804DDD28::vfunc_69() { return -1; }

int TUnk_804DDD28::vfunc_66() { return -1; }

int TUnk_804DDD28::vfunc_65() { return -1; }

int TUnk_804DDD28::vfunc_64() { return -1; }

int TUnk_804DDD28::vfunc_63() { return -1; }

int TUnk_804DDD28::vfunc_62() { return -1; }

int TUnk_804DDD28::vfunc_61() { return -1; }

int TUnk_804DDD28::vfunc_60() { return -1; }

int TUnk_804DDD28::vfunc_59() { return -1; }

int TUnk_804DDD28::vfunc_58() { return -1; }

int TUnk_804DDD28::vfunc_57() { return -1; }

int TUnk_804DDD28::vfunc_56() { return -1; }

int TUnk_804DDD28::vfunc_55() { return -1; }

int TUnk_804DDD28::vfunc_54() { return -1; }

int TUnk_804DDD28::vfunc_53() { return -1; }

int TUnk_804DDD28::vfunc_52() { return -1; }

int TUnk_804DDD28::vfunc_51() { return -1; }

int TUnk_804DDD28::vfunc_50() { return -1; }

int TUnk_804DDD28::vfunc_49() { return -1; }

int TUnk_804DDD28::vfunc_48() { return -1; }

int TUnk_804DDD28::vfunc_47() { return -1; }

int TUnk_804DDD28::vfunc_46() { return -1; }

int TUnk_804DDD28::vfunc_45() { return -1; }

int TUnk_804DDD28::vfunc_44() { return -1; }

int TUnk_804DDD28::vfunc_43() { return -1; }

int TUnk_804DDD28::vfunc_42() { return -1; }

int TUnk_804DDD28::vfunc_41() { return -1; }

int TUnk_804DDD28::vfunc_40() { return -1; }

int TUnk_804DDD28::vfunc_39() { return -1; }

int TUnk_804DDD28::vfunc_20() { return -1; }

int TUnk_804DDD28::vfunc_38() { return -1; }

int TUnk_804DDD28::vfunc_37() { return -1; }

int TUnk_804DDD28::vfunc_36() { return -1; }

int TUnk_804DDD28::vfunc_35() { return -1; }

int TUnk_804DDD28::vfunc_34() { return -1; }

int TUnk_804DDD28::vfunc_33() { return -1; }

int TUnk_804DDD28::vfunc_32() { return -1; }

int TUnk_804DDD28::vfunc_31() { return -1; }

int TUnk_804DDD28::vfunc_25() { return -1; }

int TUnk_804DDD28::vfunc_22() { return -1; }

int TUnk_804DDD28::vfunc_15() { return -1; }

int TUnk_804DDD28::vfunc_23() { return -1; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 PlayerAnimationState::get_angle() { return angle; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s16 PlayerAnimationState::get_animation() { return animation; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s16 PlayerAnimationState::get_state() { return state; }
#pragma pop

#pragma push
#pragma opt_common_subs off
void PlayerDeathSink::add_progress(f32 step) {
    progress += step;
    if (progress > 1.0f) {
        progress = 1.0f;
    }
}
extern int fold_flush_19;
#pragma pop


f32 PlayerMoveSpeed::get_unscaled_speed() { return unscaled_speed; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PlayerMoveSpeed::increment_run_counter() { run_counter++; }
extern int fold_flush_20;

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 PlayerMoveSpeed::get_run_counter() { return run_counter; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
ControllerInputContext *PlayerPadBinding::get_controller() { return controller; }
#pragma pop

int TObjPlayer::bswap_field_u32() { return bswap_32__FPUl(this); }

void* TObjPlayer__sub_801D28A0(void* p, void* a1) { copy_subcommand_header((void*)(p)); *(void**)((char*)p + 0x4) = *(void**)((char*)a1 + 0x4); return p; }

#pragma push
#pragma dont_inline off
#pragma dont_inline off
void TObjPlayer__sub_801D28DC(void* p) { bswap_32__FPUl(p); bswap_32__FPUl((char*)p + 0x4); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
u8 *copy_6x4c_hit_by_enemy_packet__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1) {
    copy_subcommand_header((void*)((void*)(arg0)));
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(ByteBlock_8 *)((saddr) arg0 + 8) = *(const ByteBlock_8 *)((saddr) arg1 + 8);
    return arg0;
}
extern int fold_flush_21;
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
void *TObjPlayer::copy_packet_pos_6x42(void *pkt) {
    copy_subcommand_header(this);
    ((Pkt_801D2964 *)this)->pos = ((Pkt_801D2964 *)pkt)->pos;
    return this;
}
extern int fold_flush_22;
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::clear_photon_blast_state() { ((FlagWord *)&flags)->clear(62); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::trigger_photon_blast() { ((FlagWord *)&flags)->clear(4); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::check_photon_blast_flag() { ((FlagWord *)&flags)->set(8); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int PhotonBlastGauge::check_flag_clear() { return test_flags_any(&flags, 1) == 0; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int PhotonBlastGauge::is_blast_launched() { return test_flags_any(&flags, 8); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::set_complete_threshold(f32 threshold) { complete_threshold = threshold; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 PhotonBlastGauge::get_countdown() { return countdown; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::decrement_countdown() {
    countdown--;
}
extern int fold_flush_23;

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
f32 PhotonBlastGauge::get_frame_step() { return frame_step; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::set_field_0c(f32 v) { frame_step = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::set_field8(s32 v) { countdown = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
PhotonBlastTarget *PhotonBlastGauge::get_target(s32 i) {
    return &targets[i];
}
extern int fold_flush_24;

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::set_field_3c(f32 v) { charge = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PhotonBlastGauge::start_photon_blast_action() { ((FlagWord *)&flags)->set(4); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
f32 PhotonBlastGauge::get_dist() { return complete_threshold; }
#pragma pop

PhotonBlastRequest *PhotonBlastRegistry::get_element(s32 index) { return &slots[index]; }

int is_alt_photon_blast_bank_empty__10TObjPlayerFPv(void* p) { return is_pb_palette_bank_empty((char*)p + 0x24); }

void TObjPlayer::bswap_u16_pair_list() {
    Obj_801D2B2C *arg0 = (Obj_801D2B2C *)this;
    s32 i;
    bswap_32__FPUl((void*)(arg0));
    for (i = 0; i < arg0->n; i++) {
        ((TObjPlayer *)(&arg0->e[i]))->bswap_u16_pair();
    }
}
extern int fold_flush_25;

void TObjPlayer::bswap_u16_pair() { bswap_16__FPUs(this); bswap_16__FPUs((char*)this + 0x2); }

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
#pragma fp_contract on
s32 TObjPlayer__sub_801D2BB8(saddr arg0, saddr arg1) {
    copy_subcommand_header((void*)(arg0));
    *(ByteBlock_2C *)(arg0 + 4) = *(const ByteBlock_2C *)(arg1 + 4);
    return arg0;
}
extern int fold_flush_26;
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
void TObjPlayer::bswap_entry_list() {
    s32 i;
    for (i = 0; i < ((Obj_801D2C18 *)this)->n; i++) {
        ((TObjPlayer *)(&((Obj_801D2C18 *)this)->e[i]))->bswap_u16_pair();
    }
    bswap_32__FPUl((void*)(((Obj_801D2C18 *)this)));
}
extern int fold_flush_27;
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma dont_inline off
void PlayerTechniqueState::set_technique_state(s32 v) { state = v; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PlayerTechniqueState::set_level(u8 v) { level = v; }
#pragma pop

int TObjPlayer::test_bit1_at_10() { return ((int (*)(void*, int))test_flags_any)((void*)((char*)this + 0x10), 2); }

void TObjPlayer__sub_801D2CAC(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0xC) = (s32) (*(s32 *)((s8 *)arg0 + 0xC) - 1);
}
extern int fold_flush_28;

f32 TObjPlayer::get_float_14() { return *(f32*)((char*)this + 0x14); }

void TObjPlayer__sub_801D2CC4(void* p, f32 v) { *(f32*)((char*)p + 0x14) = v; }

PhotonBlastTarget *PlayerTechniqueState::get_technique_data() { return targets; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void PlayerTechniqueState::set_tech_override(u8 v) { level_override = v; }
#pragma pop

f32 get_attack_controller_rate(void* p) { return *(f32*)((char*)p + 0x4); }


void TObjPlayer::set_attack_target(s16 v) { *(s16*)((char*)this + 0x2) = v; }

void* get_anim_field_c__10TObjPlayerFPv(void* p) { return (char*)p + 0xc; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
f32 PlayerAttackController::calc_attack_stage_multiplier(s32 kind) {
    return attack_type_accuracy_scales[kind] * attack_combo_accuracy_multipliers[get_validated_attack_stage()];
}
extern int fold_flush_29;

int on_attack_finished__10TObjPlayerFPv(void* p) { return ((int (*)(void*))copy_attack_targets)((char*)p + 0x30); }

void TObjPlayer::set_flag_1_at_c() { ((FlagWord *)((void*)((char*)this + 0xc)))->set(1); }

void TObjPlayer::increment_strike_counter() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 0x12) = (s16) (*(s16 *)((s8 *)arg0 + 0x12) + 1);
}
extern int fold_flush_30;

void TObjPlayer::set_action_type(s32 v) { *(s32*)((char*)this + 0x1c) = v; }

s32 TObjPlayer::get_field_1c() { return *(s32*)((char*)this + 0x1c); }

void TObjPlayer::request_heavy_attack_particles() {
    u16 *arg0 = (u16 *)this;
    emit_heavy_attack_particles((saddr)((s8 *)arg0 + 4), *arg0);
}
extern int fold_flush_31;

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void emit_heavy_attack_particles(s32 owner, u16 target_id) {
    TObjPlayer::check_hit_by_id(owner, target_id, 0xBB);
    TObjPlayer::check_hit_by_id(owner, target_id, 0x1B7);
}
extern int fold_flush_32;

f32 attack_damage_scale_table[3] = { 0.9f, 1.7f, 0.5f };
f32 attack_type_accuracy_scales[3] = { 1.0f, 0.7f, 0.5f };
f32 attack_combo_accuracy_multipliers[4] = { 1.0f, 1.3f, 1.69f, 0.0f };
