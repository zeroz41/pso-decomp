#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/object/TObjWarpBossMulti.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804DDD28.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerAttackController.h"
#include "pso/TObject.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneHoldEffect.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TTecReverser.h"
#include "pso/misc/TWindowActionPalette.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/unk/text_80121180.h"
#include "pso/map/CurrentArea.h"
#include "pso/misc/TLobby_80207644.h"

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

struct Base_801C7538 { char pad[8]; };

struct VObj_801C7538 : Base_801C7538 {
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
    virtual int m74();
};

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

struct Base_801C841C { char pad[0x8]; };

struct VObj_801C841C : Base_801C841C {
    virtual void v0();
#define VV(n) virtual void v##n();
VV(1)VV(2)VV(3)VV(4)VV(5)VV(6)VV(7)VV(8)VV(9)VV(10)
VV(11)VV(12)VV(13)VV(14)VV(15)VV(16)VV(17)VV(18)VV(19)VV(20)
VV(21)VV(22)VV(23)VV(24)VV(25)VV(26)VV(27)VV(28)VV(29)VV(30)
VV(31)VV(32)VV(33)VV(34)VV(35)VV(36)VV(37)VV(38)VV(39)VV(40)
VV(41)VV(42)VV(43)VV(44)VV(45)VV(46)VV(47)VV(48)VV(49)VV(50)
VV(51)VV(52)VV(53)VV(54)VV(55)VV(56)VV(57)VV(58)VV(59)VV(60)
VV(61)VV(62)VV(63)VV(64)VV(65)VV(66)VV(67)VV(68)VV(69)VV(70)
VV(71)VV(72)VV(73)
#undef VV
    virtual s32 v76();
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

struct Pkt_801C8CCC { u16 hdr; u16 id; s32 c; f32 x1, y1, z1; f32 x2, y2, z2; };

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

typedef struct Vec_801C8FCC { f32 x, y, z; } Vec_801C8FCC;

typedef struct Cmd_801C8FCC {
    u8 cmd;
    u8 size;
    u16 client;
    s32 area;
    Vec_801C8FCC a;
    Vec_801C8FCC pos;
} Cmd_801C8FCC;

struct Pkt_801C9084 { u16 hdr; s16 id; s32 c; f32 x1, y1, z1; f32 x2, y2, z2; };

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

struct VBase_801cac08 {
    char pad[0x18];
};

struct VObj_801cac08 : VBase_801cac08 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
};

struct Pkt_801CADA4 { u8 hdr[2]; s16 id; s16 dir; s16 f6; f32 x; f32 z; };

struct Base_801cb0c4 { char pad[0x18]; };

struct VObj_801cb0c4 : Base_801cb0c4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

struct Pkt_801CB27C { u16 hdr; s16 id; s16 a; s16 b; f32 x; f32 z; };

struct Pkt_801CB4D0 { u16 hdr; s16 id; s32 c; };

struct SwitchActionMessage_801CB6A8 { u8 code; u8 words; u16 actor; s32 yaw; };

typedef struct Ctx_801CB748 { s16 f0; s16 f2; s32 f4; } Ctx_801CB748;

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

typedef struct Msg_801CC6B8 {
    u8 pad0[2];
    u16 id;
    s8 kind;
    u8 pad5;
    s16 count;
    s16 param;
    u8 padA[2];
    u32 techs[13];
} Msg_801CC6B8;

typedef struct Player_801CC6B8 {
    u8 pad0[0x4AC];
    u8 pb[4];
} Player_801CC6B8;

struct Slot_801CC558 { u16 id; s16 idx; };

struct Mylla_801CC558 { u8 pad[0xA4]; u8 *tbl; };

struct Pkt_801CC7F8 {
    u8 cmd;
    u8 size;
    s16 client;
    s8 index;
    u8 pad5;
    s16 count;
    s16 sub;
    u8 padA[2];
    s32 tech[11];
};

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
    u32 list;
} Player_801CCA84;

struct Rec_801CCEDC { u8 pad[0x10]; s16 cost; };

struct Pkt_801CCEDC { u16 hdr; u16 id; s16 tech; u16 level; };

struct Player_801CCEDC { u8 pad[0x328]; s16 f328; u8 pad32a[0x32E - 0x32A]; s16 tp; u8 pad330[0x428 - 0x330]; u8 techs[4]; };

struct Pkt_801CCD38 { u16 hdr; u16 id; s16 tech; s16 level; };

struct Rec_801CCD38 { u8 pad[0x20]; s16 state; };

struct Player_801CCD38 { u8 pad[0x10]; u32 f10; u8 pad14[0x328 - 0x14]; s16 f328; u8 pad32a[0x428 - 0x32A]; u8 techs[4]; };

struct Rec_801CD078 { u8 pad[0x10]; s16 cost; };

struct Player_801CD078 { u8 pad[0x32E]; s16 tp; u8 pad330[0x428 - 0x330]; u8 techs[4]; };

struct Node_801CD424 { u8 pad[0x1C]; f32 pos[3]; u8 pad28[0x2C - 0x28]; };

struct Obj_801CD424 { u8 pad[0xA4]; Node_801CD424 *nodes; };

struct TechData_801CD424 { u16 target; s16 node; };

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

typedef struct Msg2_801CD72C {
    u8 pad0[2];
    s16 id;
    u8 tech;
    u8 pad5;
    u8 lv;
    u8 count;
    u32 data[13];
} Msg2_801CD72C;

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

struct Item_801CE928 : VBase_801CE928 {
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
};

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
    u8 motion[0xc];
    u8 flags[4];
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
    u8 motion[0xc];
    u8 flags[4];
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
    virtual s16 m18();
    virtual void m19();
    virtual void m20();
    virtual s16 m21();
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
#pragma auto_inline off
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
#pragma auto_inline off
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

struct RecoveredGlobal_801D2CF4_lbl_804C43CC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801D2CF4_lbl_804C43D8 {
    s32 value;
    u8 remaining[0xC];
};

struct Ent_801D2AB0 { u8 d[4]; };

struct Obj_801D2AB0 { u8 pad[0x14]; Ent_801D2AB0 arr[1]; };

struct Pos_801D2964 { u8 bytes[0x8]; };

struct Pkt_801D2964 { u8 hdr[4]; Pos_801D2964 pos; };

struct Ent_801D32A0 { u16 a; s16 b; };

struct Self_801D32A0 { u8 pad[0x20]; f32 f20; f32 f24; f32 f28; f32 f2c; s32 count; Ent_801D32A0 ents[1]; };

struct Cur_801D32A0 { u8 pad[0x28]; f32 x28; f32 x2c; f32 x30; u8 pad2[8]; f32 x3c; u8 pad3[0x5C]; u8 lock[4]; };

struct Pl_801D32A0 { u8 pad[0x424]; void *cursor; };

struct E_801D2B2C { u8 d[4]; };

struct Obj_801D2B2C { s32 n; E_801D2B2C e[1]; };

struct E_801D2C18 { u8 d[4]; };

struct Obj_801D2C18 { s32 n; E_801D2C18 e[1]; };

struct Vec_801D3224 { f32 x, y, z; };

struct Rec_801D3224 { u8 pad[0x1C]; Vec_801D3224 pos; u8 pad28[4]; };

struct Obj_801D3224 { u8 pad[0xA4]; Rec_801D3224 *recs; };

struct Slot_801D3224 { s16 a; s16 idx; };

typedef char RecoveredGlobal_801D2CF4_lbl_804C43CC_size[sizeof(RecoveredGlobal_801D2CF4_lbl_804C43CC) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_801D2CF4_lbl_804C43D8_size[sizeof(RecoveredGlobal_801D2CF4_lbl_804C43D8) == 0x10 ? 1 : -1];

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

s32 get_main_phase();
s32 TObjPlayer__sub_8000FF4C(void *, s32);
s32 get_field_2d4__10TObjPlayerFv(void *);
s32 TObjPlayer__sub_8001053C(void *);
s32 add_actor_tp(s32, s32);
s32 add_actor_hp(s32, s32);
s32 trigger_switch_attack__10TObjPlayerFPvi(void *, s32);
void VecCopy__FP3VecPC3Vec(void *, void *);
s32 is_locally_controlled__10TObjPlayerFPv(void *);
s32 obj_isState2_324__13TUnk_804806E8Fv(void *);
s32 get_actor_hp(void * a0 = 0);
s32 obj_isState3_324__13TUnk_804806E8Fv();
s32 TObjPlayer__sub_8001943C(void *, s32);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(s32, s32);
s16 get_entity_id(void *);
void obj_setFlags30(void *, u32);
s32 get_current_floor(void);
Item_801CE928 * get_item_field_6__10TObjPlayerFPv(void *);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
s32 queue_destruction__7TObjectFv(void *);
void set__8FlagWordFUl(void *, u32);
s32 clear__8FlagWordFUl(void *, int);
s32 test_flags_any(void *, int);
s32 set_type__10TObjPlayerFl(void *, s32);
s32 check_value_equals__13TUnk_804B6C24Fl(int, void *);
s32 check_flag__10TObjPlayerFl(int, int);
s32 fn_800660B8(void *);
s32 test_action_mask__10TObjPlayerFl(void *, s32);
s32 TObjPlayer__sub_80082300(void *);
s32 is_inactive__10TObjPlayerFv();
s32 init_entry_fields__6TLobbyFiii(int, int, void *, void *);
u32 activate_d04_slot__10TObjPlayerFv(s32);
s32 spawn_appearance_effect__10TObjPlayerFl();
s32 is_active__8TItemMagFv();
s16 get_sub_value__8TItemMagFv(void *);
s16 get_type_id__10TObjPlayerFv(void* p);
void * TObjPlayer__sub_80116620(void *, s32);
int sub_8011E204__10TObjPlayerFl(void*, void*);
s32 weapon_has_extra_attack();
void set_action_type__10TObjPlayerFs(void *p, s16 v);
int get_captured_target_entry(void*, int);
s32 get_captured_target_count(s32 *arg0);
s32 increment_burst_counter(void *);
s32 get_burst_counter(void *);
s32 copy_attack_targets(void *, void *);
int TObjPlayer__sub_8012AF00(void*);
void TObjPlayer__sub_8012AF80(void *);
s32 publish_actor_light_scalars(u16, f32, f32);
s32 canSetMenuCursorAction(s32, void *, s32, u8);
void TMainCursor__sub_8013DFC4(u8 *arg0);
u8 TMainCursor__sub_8013E900(void *);
s32 approach_angle_adaptive(s32, s32);
s32 lerp_angle_half__10TObjPlayerFUsUs(s32, s32);
f32 sample_attack_root_motion(void *, void *, void *);
s32 is_anim_finished__10TObjPlayerFv(void *);
s32 objInBand__FP7GameObjf(void *);
s32 sub_80143960__10TObjMotionFl(void *, s32);
void init_6x45_attack_packet(u8 *arg0);
void init_6x44_attack_packet(u8 *arg0);
void init_6x43_attack_packet(u8 *arg0);
void *resolve_hittable_target(u16 actorId, s16 collider);
s32 get_type__10TObjPlayerFPv(void *);
s32 test_elt_flag__13TUnk_80493450Fll(void *, s32, s32);
s32 play_weapon_hit_sound(void *);
void apply_camera_shake__10TObjPlayerFiii(TObjPlayer *player, TUnk_804806E8 *target, s32 damage);
u8 * find_entity_by_id(s32);
s32 get_trap_type__10TOMineTrapFv(int);
s32 TKeyBoardControl__sub_801A58B0();
s32 TKeyBoardControl__sub_801A58D8();
s32 is_final_phase__10TObjPlayerFv();
s32 is_camera_mode_active__10TObjPlayerFv();
s32 is_single_screen__10TObjPlayerFv();
s32 TObjPlayer__sub_801AF290(s32);
s16 get_handle_value__10TObjPlayerFv();
s32 is_lobby_floor_15__15TFontSmallLobbyFv();
s32 is_on_current_floor__10TObjPlayerFi();
s32 update_trap_sub__10TOMineTrapFv(void *, int, int);
s32 fn_801B0480(int, void *, int);
s32 draw_player_status(void *, void *, void *);
s32 is_technique_ready__8TTecCtrlFv();
int deactivate_body_collision__10TObjPlayerFv(void*);
s32 draw__10TObjPlayerFPvf(void *, f32);
s32 reset_volopt_state__10TObjPlayerFv(void *obj);
s32 for_each_player_slot__10TObjPlayerFv(s32 *);
s32 is_in_tl03_state__10TObjPlayerFv(void *);
s32 send_6x2F_change_player_hp(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0);
int check_flag30_bit20__10TObjPlayerFi(void*);
s16 calc_scaled_value__10TObjPlayerFii(void *, int);
void apply_speed_scale__10TObjPlayerFif(s32 arg0, f32 farg0);
void complete_deferred_player_death();
s32 is_flag_400_set__10TObjPlayerFPv(void *);
s32 enable_action_input__10TObjPlayerFPv(void *);
s32 classify_action_state__10TObjPlayerFv(void *);
void play_footstep_sound__10TObjPlayerFv(void *, f32, f32);
s32 TObjPlayer__sub_801B4430(u32);
s32 send_code_49_1__10TObjPlayerFi(u32);
s32 check_flag_100__10TObjPlayerFPv(void *);
Cur_801D32A0 * TObjPlayer__sub_801B57E8(void *);
u16 get_action_palette_entry__10TObjPlayerFl(void *, s32);
u16 TObjPlayer__sub_801B5AF8(void *, s32);
u32 resolve_move_collision__10TObjPlayerFv(void *);
s32 damp_planar_velocity();
int try_apply_status_action__10TObjPlayerFi(void*);
s32 set_action_state__10TObjPlayerFPvss(void *, s32, s32);
u8 * get_player_by_client_id(u16);
s32 check_camera_mode__10TObjPlayerFv();
s32 get_model_field_m25__10TObjPlayerFv(void *);
s16 get_action_animation__10TObjPlayerFv(void *);
s32 call_model_m24__10TObjPlayerFv(void *);
s32 get_weapon_stat_c__10TObjPlayerFv(void * a0 = 0);
s32 call_obj_vt26__10TObjPlayerFv(void * a0 = 0);
s32 query_child_state__10TObjPlayerFv(void *);
s32 query_equip__10TObjPlayerFv(void *);
s32 get_model_state__10TObjPlayerFv(void *);
s32 get_state__10TObjPlayerFv(void *);
s32 call_subobject_m15__10TObjPlayerFv(void *);
s32 get_vobj_state_28__10TObjPlayerFv(void *);
s32 check_flag_4__10TObjPlayerFv(void *);
s32 clamp_nested_index__10TObjPlayerFv();
void TObjPlayer__sub_801BE9A8(s32 arg0);
void set_flag_20000__10TObjPlayerFi(s32 arg0);
void set_flag_400000__10TObjPlayerFi(s32 arg0);
s32 is_status_locked__10TObjPlayerFv();
s32 is_status_flag_200__10TObjPlayerFv(void);
s32 TObjPlayer__sub_801BEEE0(void *, void *);
s32 __ct__20TPlayerReadyCallbackFP7TObjectUsPFP10TObjPlayer_v(s32, s32, s32, void (*)(int));
void TObjPlayer__sub_801BF690(u8 *arg0);
s32 set_anim_state__10TObjPlayerFl(void *, int);
s32 set_anim_state__10TObjPlayerFs(void *, int);
f32 TObjPlayer__sub_801BF814(void *p);
s32 zero_vec3(void *);
s32 TObjPlayer__sub_801BFFA0(void *);
s32 is_action_id_none(int);
u8 TObjPlayer__sub_801C010C(s32, s32);
s32 set_technique_id__10TObjPlayerFs(s32, s32);
int TFontSmallLobby__sub_801C01BC(void*);
int TFontSmallLobby__sub_801C0228(void*);
void TObjPlayer__sub_801C0734(void *);
void TObjPlayer__sub_801C18E0(void *);
void set_photon_blast_kind(void *p, s16 v);
s32 TObjPlayer__sub_801C1F50(s32);
s32 send_neg50__6TLobbyFPvPv(void *, int);
s32 calc_death_pose_height_offset(s32, s32);
s32 apply_stat_multipliers_and_reset__10TObjPlayerFPv(void *, void *, f32);
s32 apply_stats_and_update__10TObjPlayerFPv(void *, void *);
f32 apply_stat_multipliers_default__10TObjPlayerFv(void *, void *);
s32 set_ring_action__10TObjPlayerFPvi(void *, int);
s32 interpolate_angle__10TObjPlayerFPvUsUsPl(void *, int, void *, void *);
void handle_6xB0_turn_or_move_lobby_chair(void *arg0);
void handle_6xAF_turn_or_move_lobby_chair(void *arg0);
void TObjPlayer__sub_801C75A4(u8 *arg0);
void TObjPlayer__sub_801C7858(void);
void TObjPlayer__sub_801C785C(u8 *arg0);
void TObjPlayer__sub_801C7874(u8 *arg0);
void TObjPlayer__sub_801C7A6C(s32 arg0, s16 arg1);
void handle_6xB1(void);
void TObjPlayer__sub_801C8478(void);
void handle_6x58_lobby_animation(void *arg0);
void TObjPlayer__sub_801C85BC(u8 *arg0);
void TObjPlayer__sub_801C862C(void);
void TObjPlayer__sub_801C8678(void);
void TObjPlayer__sub_801C869C(s32 arg0, s16 arg1);
int TObjPlayer__deactivate_off_floor_body(void* p);
void TObjPlayer__enter_off_floor_state(u8 *arg0);
void handle_6x57(void *arg0);
void draw_and_send_field1c__10TObjPlayerFi(s32 arg0);
void TObjPlayer__update_off_floor_state(u8 *arg0);
void TObjPlayer__sub_801C8998(u8 *arg0);
void TObjPlayer__sub_801C8A20(void);
void TObjPlayer__sub_801C8A24(void);
void TObjPlayer__sub_801C8A28(s32 arg0, s16 arg1);
void handle_6x56_set_player_position_and_angle(void *arg0);
void TObjPlayer__sub_801C8C50(s32 arg0, s16 arg1);
void send_6x55_intra_map_warp(u16 id, void *pos, s32 c);
void handle_6x55_intra_map_warp(s32 arg0);
void TObjPlayer__sub_801C90F8(void);
void TObjPlayer__sub_801C9128(void);
void TObjPlayer__sub_801C912C(void);
void run_warp_action_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void handle_6x53(void *arg0);
void TObjPlayer__sub_801C94B8(u8 *arg0);
void TObjPlayer__sub_801C959C(void);
void TObjPlayer__sub_801C9648(s32 arg0, s16 arg1);
void apply_velocity_if_free__10TObjPlayerFPv(void *arg0);
void handle_6x52_set_animation_state(s32 arg0);
void run_service_hold_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void notify_lobby__10TObjPlayerFi(s32 arg0);
void ensure_default__10TObjPlayerFPv(void *arg0);
s32 handle_6x4F_revived__10TObjPlayerFi(s32 arg0);
void update_timer_state__10TObjPlayerFPv(void *arg0);
void TObjPlayer__sub_801C9F64(void);
void TObjPlayer__sub_801C9F68(void);
void run_revival_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void handle_6x89_set_killer_entity_id(void *arg0);
void init_subobject__10TObjPlayerFi(s32 arg0);
void queue_player_injured_pose(s32 arg0);
s32 handle_revivable__10TObjPlayerFi(s32 arg0);
void handle_6x4D_player_died(void *arg0);
void TObjPlayer__sub_801CAA58(void);
void run_death_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void start_action_0e__10TObjPlayerFPv(u8 *arg0);
void TObjPlayer__sub_801CAEAC(void);
void TObjPlayer__sub_801CAF6C(void);
void run_fall_reaction_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void end_freeze_action__10TObjPlayerFPv(u8 *arg0);
void TObjPlayer__sub_801CB2F0(void);
void TObjPlayer__sub_801CB360(void);
void run_hurt_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void TObjPlayer__sub_801CB424(void);
void TObjPlayer__sub_801CB428(s32 arg0);
void TObjPlayer__sub_801CB4D0(u8 *arg0);
void TObjPlayer__sub_801CB52C(void);
void TObjPlayer__sub_801CB55C(void);
void TObjPlayer__sub_801CB580(s32 arg0, s16 arg1);
void TObjPlayer__sub_801CB5FC(void);
void handle_6x50_switch_interaction(const void *source);
void TObjPlayer__sub_801CB7A4(void);
void TObjPlayer__sub_801CB7D4(void);
int TObjPlayer__sub_801CB7D8(void* p);
void run_switch_interaction_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
s32 can_guard__10TObjPlayerFPv(u8 *arg0);
void start_use_item_action__10TObjPlayerFPv(u8 *arg0);
void send_object_id_packet__10TObjPlayerFi(s32 arg0);
void TObjPlayer__sub_801CBB10(void);
void TObjPlayer__sub_801CBB80(void);
void run_guard_reaction_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void update_active_instance__10TObjPlayerFi(s32 arg0);
void release_all_players_control_lock(void);
void release_photon_blast_player_holds(u16 *p);
void handle_6x36(void);
void handle_6x37_photon_blast(s32 arg0);
void handle_6x49_execute_photon_blast(void *arg0);
void copy_tech_params__10TObjPlayerFPvPv(void *arg0, void *arg1);
void TObjPlayer__sub_801CC9E4(void);
void dispatch_photon_blast_action__10TObjPlayerFis(s32 arg0, s16 arg1);
void handle_6x33_revive_player(void *arg0);
void send_6x33_revive_player(s32 arg0, s16 arg1);
void clamp_and_set_unit_value__10TObjPlayerFiUci(s32 arg0, u8 arg1, s32 arg2);
s32 try_equip_item__10TObjPlayerFii(s32 arg0, s32 arg1);
void handle_6x48_cast_technique_complete(void *arg);
s32 can_equip_item__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 can_start_technique__10TObjPlayerFPvi(Player_801CD078 *self, s32 tech);
void handle_6x8D_set_technique_level_override(void *arg0);
void TObjPlayer__sub_801CD904(void);
void dispatch_technique_cast_state__10TObjPlayerFis(s32 arg0, s16 arg1);
int TObjPlayer__sub_801CD9F0(void* p);
void enter_attack_stage3__10TObjPlayerFPv(u8 *arg0);
void handle_6x45_attack(void *src);
void TObjPlayer__sub_801CDC68(void);
void run_attack_stage3_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
int TObjPlayer__sub_801CDDEC(void* p);
void enter_attack_stage2__10TObjPlayerFPv(u8 *arg0);
void handle_6x44_attack(void *src);
void TObjPlayer__sub_801CE064(void);
void TObjPlayer__sub_801CE134(s32 arg0);
void run_attack_stage2_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void handle_6x46_attack_finished(s32 arg0);
s32 TObjPlayer__sub_801CEAC8(u8 *self);
void update_action_state__10TObjPlayerFPv(u8 *arg0);
void update_action_state__10TObjPlayerFv(void);
void enter_attack_stage1__10TObjPlayerFPv(u8 *arg0);
void handle_6x43_attack(void *src);
void TObjPlayer__sub_801CF2AC(void);
int TObjPlayer__sub_801CF3C0(void* p);
void run_attack_stage1_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
s32 update_aim_target__10TObjPlayerFPv(void *arg0);
void start_action__10TObjPlayerFPv(u8 *arg0);
void handle_6x42_move_to_position(void *pkt);
int TObjPlayer__sub_801CFAA4(void* p);
void dispatch_run_state__10TObjPlayerFis(s32 arg0, s16 arg1);
void TObjPlayer__sub_801CFB40(void);
void TObjPlayer__sub_801CFB44(void);
void TObjPlayer__sub_801CFB48(void);
void TObjPlayer__sub_801CFB50(void);
void TObjPlayer__sub_801CFB54(void);
void TObjPlayer__sub_801CFB58(void);
void TObjPlayer__sub_801CFB5C(void);
int TObjPlayer__sub_801CFB80(s32 arg0, s16 arg1);
u8 * TObjPlayer__sub_801CFBFC(u8 *arg0);
s32 update_combat_stats__10TObjPlayerFPv(u8 *arg0);
void set_attack_state__10TObjPlayerFPv(u8 *arg0);
void handle_6x40_walk_to_position(void *pkt);
int TObjPlayer__sub_801D03BC(void* p);
void run_walk_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
s32 get_idle_animation__10TObjPlayerFv(u8 *arg0);
void handle_6x3F_set_position(void *arg0);
void handle_6x3E_stop_at_position(void *arg0);
void update_position_from_target__10TObjPlayerFv(void* p);
void send_idle_return_event__10TObjPlayerFPvPvs(void *arg0, void *arg1, s16 arg2);
void TObjPlayer__sub_801D09F4(void);
void run_idle_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1);
void run_action_state_phase__10TObjPlayerFisi(s32 arg0, s16 arg1, s32 arg2);
int TObjPlayer__sub_801D0D58(void* p);
void TObjPlayer__sub_801D0D7C(void* p);
void TObjPlayer__sub_801D0D8C(void* p);
int TObjPlayer__sub_801D0DAC(void* p);
int TObjPlayer__sub_801D0DF4(void* p);
void TObjPlayer__sub_801D0E18(void* p);
void TObjPlayer__sub_801D0E74(void* p);
void TObjPlayer__sub_801D0E84(void* p);
int get_flag__10TObjPlayerFPv(void* p);
u8 * TObjPlayer__sub_801D0EA0(u8 *arg0, u8 *arg1);
short query_child_state2__10TObjPlayerFPv(void *arg0);
void release_control_lock__10TObjPlayerFPv(void* p);
void TObjPlayer__sub_801D0F70(void* p);
int copy_position__10TObjPlayerFPv(void* p);
int query_field_340__10TObjPlayerFPv(void* p);
int is_android_player(void* p);
void TObjPlayer__sub_801D1024(void* p, s32 v);
void TObjPlayer__sub_801D102C(void* p, s32 v);
s32 TObjPlayer__sub_801D1034(void* p);
s16 TObjPlayer__sub_801D103C(void* p);
void TObjPlayer__sub_801D1044(void* p, s16 v);
void TObjPlayer__sub_801D104C(void* p);
void TObjPlayer__sub_801D1058(u8 *arg0);
u8 TObjPlayer__sub_801D1078(u8 *arg0);
void TObjPlayer__sub_801D1090(void* p);
void TObjPlayer__sub_801D109C(u8 *arg0);
u8 TObjPlayer__sub_801D10BC(u8 *arg0);
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
void TObjPlayer__sub_801D1658(void* a0);
u8 * copy_6x4b_hit_by_enemy_packet__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
void TObjPlayer__sub_801D1BB0(u8 *arg0);
void* copy_font__10TObjPlayerFPvPv(void* p, void* a1);
void TObjPlayer__sub_801D1C70(u8 *arg0);
void * TObjPlayer__sub_801D1D44(void *arg0, void *arg1);
void TObjPlayer__sub_801D1D88(u8 *arg0);
s32 copy_photon_blast_data__10TObjPlayerFiPv(s32 arg0, u8 *arg1);
void TObjPlayer__sub_801D1F44(void* p);
u8 TObjPlayer__sub_801D2004(u8 *arg0);
void* TObjPlayer__sub_801D2058(void* p, void* a1);
u8 * TObjPlayer__sub_801D21CC(u8 *arg0, u8 *arg1);
void * TObjPlayer__sub_801D2348(void *arg0, void *arg1);
void TObjPlayer__sub_801D2448(void* p);
void * TObjPlayer__sub_801D24B0(void *arg0, void *arg1);
u8 * TObjPlayer__sub_801D2540(u8 *arg0, u8 *arg1);
u8 * TObjPlayer__sub_801D25AC(u8 *arg0, u8 *arg1);
void TObjPlayer__sub_801D2618(void* p, f32 v);
void clear_status_bit6__10TObjPlayerFPv(void* p);
f32 get_action_rate_entry(Obj_801D2640 *p);
int TObjPlayer__sub_801D2680(void *p);
int ret_801D26AC(void);
s16 TObjPlayer__sub_801D2824(void* p);
s16 TObjPlayer__sub_801D282C(void* p);
f32 TObjPlayer__sub_801D2858(void* p);
s32 TObjPlayer__sub_801D2870(void* p);
s32 TObjPlayer__sub_801D2878(void* p);
void* TObjPlayer__sub_801D28A0(void* p, void* a1);
void TObjPlayer__sub_801D28DC(void* p);
u8 * copy_6x4c_hit_by_enemy_packet__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
int TObjPlayer__sub_801D2A50(void* p);
void TObjPlayer__sub_801D2A78(void* p, f32 v);
s32 TObjPlayer__sub_801D2A80(void* p);
void TObjPlayer__sub_801D2A88(u8 *arg0);
f32 TObjPlayer__sub_801D2A98(void* p);
Ent_801D2AB0 * TObjPlayer__sub_801D2AB0(Obj_801D2AB0 *p, s32 i);
void* get_element__10TObjPlayerFPvi(void* a0, int a1);
int is_alt_photon_blast_bank_empty__10TObjPlayerFPv(void* p);
s32 TObjPlayer__sub_801D2BB8(s32 arg0, s32 arg1);
void TObjPlayer__sub_801D2CAC(u8 *arg0);
void TObjPlayer__sub_801D2CC4(void* p, f32 v);
void* get_technique_data__10TObjPlayerFPv(void* p);
void* get_anim_field_c__10TObjPlayerFPv(void* p);
int on_attack_finished__10TObjPlayerFPv(void* p);
void clear_lockon_list__10TObjPlayerFPvPvff(s32 *arg0, void * _w1, f32 _w2, f32 _w3);
s16 get_validated_attack_stage(u8 *arg0);
s32 TObjPlayer__sub_801D2EE8(s16 arg0);
s16 TObjPlayer__sub_801D2F0C(void *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
s32 TObjPlayer__sub_801D2F8C(s16 arg0);
void queue_physical_attack_input(PlayerAttackController *self, TObjPlayer *obj, s32 arg2, s16 arg3);
void apply_anim_action__10TObjPlayerFPvi(u8 *arg0, s32 arg1);
s32 get_first_target_position__10TObjPlayerFPvPv(void *arg0, Vec_801D3224 *out);
void * capture_lockon_targets(Self_801D32A0 *self, Pl_801D32A0 *player);
int TObjPlayer__sub_801D345C(void* p);
void handle_6x54(void);
void handle_6x8C(void);
void handle_6x65(void);
void handle_6x8B(void);
void handle_6x64(void);
s16 TAdSinglePlyChrSelectGC__sub_801D5DDC(void *);
s32 reset_photon_blast_gauge(void *);
int is_pb_palette_bank_empty(void*);
s32 get_getup_protection_ticks__10TObjPlayerFv(void *);
s32 get_hurt_protection_ticks__10TObjPlayerFv(void *);
s32 TObjPlayer__sub_801D8DCC(TObjPlayer *arg0);
void split_capped_value__10TObjPlayerFUcPUcPSc(u8 v, void *a, void *b);
u8 get_cast_technique_level(void *techs, s16 tech);
s32 set_technique_level_entry(s32, s32, u8);
s32 validate_and_clear_slot__10TObjPlayerFv(void *techs, s16 tech);
s32 is_invalid_slot__10TObjPlayerFUc(u8);
s32 check_technique_level__10TObjPlayerFllUc(void *, s32, u8);
int bswap_16__FPUs(void*);
int bswap_32__FPUl(void*);
void update_players__6TLobbyFv(s32 arg0);
u8 * get_character_save_record(u16);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u32 __nw__7TObjectFUl(s32);
s32 capture_technique_targets__10TObjPlayerFv(void *, void *);
void launch_technique__10TObjPlayerFv(s32, s32, void *);
Rec_801CCEDC * calc_technique_parameters(s32 tech, s32 level, s32 id);
s32 construct_actor_light_task(void *, f32 *, f32 *, int, void *, f32, s32);
s32 construct_revival_particle_effect(void *, void *, s32);
s32 TObjPlayer__sub_8024ABDC(void *);
void TLobby__sub_8024AC20(s32 arg0);
void dispatch_to_child__11TWindowCtrlFPv(u16, s32);
}
void reset_cameras_to_actor(void *actor, s32 arg1);
void bswap_6x45_packet(void *p);
void bswap_6x44_packet(void *p);
void bswap_6x43_packet(void *p);
void init_6x40_walk_packet(void *cmd);
void init_stick_escape_detector(void *arg0, void *arg1);
void admit_photon_blast_sequence(u8 *players, void *self);
void calc_death_sink_offset(void *arg0);
void reset_player_appearance_opacity(void *a0);
void remove_photon_blast_participant(s32 arg0);
void freeze_players_for_photon_blast(s16 arg0, u16 *arg1);
void send_photon_blast_targets_packet(u8 *arg0);
void init_6x48_cast_complete_packet(u8 *arg0);
void init_6x8D_technique_level_packet(u8 *arg0);
void send_6x46_attack_finished(u8 *arg0);
u8 get_6x46_strike_packet_size(s32 arg0);
void add_death_sink_progress(u8 *arg0, f32 farg0);
f32 get_attack_controller_rate(void* p);
void emit_heavy_attack_particles(s32 arg0, s32 arg1);
void begin_player_attack(u8 *arg0, s32 arg1, s16 arg2, s32 arg3);
void add_photon_blast_charge(u8 *arg0, f32 farg0);
void create_technique_charge_light(u32 kind, void *owner);
void release_photon_blast_requests(void *registry);
extern "C" {
u8 * find_by_section_id__10TObjPlayerFl(void *, int);
s32 find_first_valid_target_id__10TObjPlayerFv(void*);
void TObjPlayer__sub_80312E98(void *, s32);
s32 append_photon_blast_request(u32, s32, s32);
s32 send_6x3e_to_all_players__10TNpcPlayerFPvs(void *, int);
s32 TObjPlayer__sub_80354D5C(s16);
s32 dispatch_weapon_special_effect(void *, int, int, int);
int TBoss7LaserPtcl__sub_8035AF14(void*);
int fn_8035AF18(void*);
s32 fn_8036B798(void *);
s32 fn_8036B7C0(void *);
s32 validate_6x58_lobby_animation(void *);
s32 validate_6x56_set_player_position_and_angle(void *);
s32 validate_6x55_intra_map_warp(void *);
s32 validate_6x52_set_animation_state(void *);
s32 validate_6x50_switch_interaction(const void *);
s32 validate_6x89_set_killer_entity_id(void *);
s32 validate_6x4D_player_died(void *);
s32 validate_6x4C_hit_by_enemy(void *);
s32 validate_6x4B_hit_by_enemy(void *);
s32 validate_6x48_cast_technique_complete(void *);
s32 validate_6x8D_set_technique_level_override(void *);
s32 validate_6x46_attack_finished(void *);
s32 validate_6x45_attack(Pkt_801CDAD8 *);
s32 validate_6x44_attack(Pkt_801CDED4 *);
s32 validate_6x43_attack(Pkt_801CF128 *);
s32 validate_6x42_move_to_position(void *cmd);
s32 validate_6x40_walk_to_position(void *cmd);
s32 validate_6x3F_set_position(void *);
s32 validate_6x3E_stop_at_position(void *);
s32 validate_6x37_photon_blast(void *);
s32 validate_6x33_revive_player(void *);
void __construct_array(void *, void *, int, int, int);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);

extern s32 TOMineTrap__data_805D3080;
extern const f32 TObjPlayer__data_805DC360;
extern const f32 TObjPlayer__data_805DC368;
extern const f32 TObjPlayer__data_805DC36C;
extern const f32 TObjPlayer__data_805DC378;
extern const f32 TObjPlayer__data_805DC39C;
extern const f32 TObjPlayer__data_805DC3AC;
extern s32 fn_80152EF8[];
extern const f64 lbl_80447128;
extern u8 lbl_80447138[0x20];
extern const f64 lbl_80447148;
extern RecoveredGlobal_801D2CF4_lbl_804C43CC attack_type_accuracy_scales;
extern RecoveredGlobal_801D2CF4_lbl_804C43D8 attack_combo_accuracy_multipliers;
extern f32 lbl_8050BEE0[];
extern f32 player_feedback_light_color[];
extern void *player_slot_table[];
extern u8 *lbl_805D3530;
extern s32 TWindowReturnCity__class_name;
extern u8 *TObjPlayer__shared_photon_blast_state;
extern const f32 lbl_805DC364;
extern const f32 lbl_805DC370;
extern const f32 lbl_805DC374;
extern const f32 lbl_805DC37C;
extern s32 lbl_805DC380;
extern s32 lbl_805DC384;
extern const f32 lbl_805DC388;
extern const f32 lbl_805DC38C;
extern const f32 lbl_805DC390;
extern const f32 lbl_805DC394;
extern const f32 lbl_805DC398;
extern const f32 lbl_805DC3A0;
extern const f32 lbl_805DC3A4;
extern const f32 lbl_805DC3A8;
extern const f32 lbl_805DC3B0;
extern const f32 lbl_805DC3B4;
extern const f32 lbl_805DC3B8;
extern const f32 lbl_805DC3BC;
extern const f32 lbl_805DC3C0;
extern const f32 lbl_805DC3C4;
extern u32 tl_03;
extern s32 tl_07;
extern s32 tl_particlemodel;

void handle_6xB0_turn_or_move_lobby_chair(void *arg0) {
    Msg_801C7430 m;
    Player_801C7430 *p;
    ((void (*)(void *))TObjPlayer__sub_801D1144)(&m);
    ((TObjPlayer *)(&m))->copy_lobby_font_header(arg0);
    TObjPlayer__sub_801D10D4(&m);
    if (fn_8036B798(&m) != 0) {
        p = ((Player_801C7430 *)((s32 (*)(s32))get_player_by_client_id)((s32)(m.slot)));
        if ((p != NULL) && (((s32 (*)(void))is_in_tl03_state__10TObjPlayerFv)() != 0)) {
            ((TObjPlayer *)p)->update_lobby_chair(m.c);
            TObjPlayer::calc_direction_vector(p->dir, p->vec, TObjPlayer__data_805DC360);
        }
    }
}

void handle_6xAF_turn_or_move_lobby_chair(void *arg0) {
    L_801C74BC sp8;
    ((void (*)(void *))TObjPlayer__sub_801D11D0)(&sp8);
    ((void (*)(void *, void *))TObjPlayer__sub_801D1194)(&sp8, arg0);
    ((TObjPlayer *)(&sp8))->swap_endian32();
    if (fn_8036B7C0(&sp8) != 0) {
        s32 p = ((s32 (*)(s32))get_player_by_client_id)(sp8.f2);
        if (p != 0 && ((s32 (*)(void))is_in_tl03_state__10TObjPlayerFv)() != 0) {
            ((TObjPlayer *)p)->get_chair_state(sp8.f4);
        }
    }
}

void TObjPlayer::update_state_group() {

    ((s32 (*)(void))TObjPlayer__sub_8001053C)();
    clear_state_flag();
    ((s32 (*)(void *))TObjPlayer__sub_801D0D8C)(this);
    ((s32 (*)(void *))TObjPlayer__sub_801D0D7C)(this);
    ((s32 (*)(void *))TObjPlayer__sub_801D0D58)(this);
    set_field_dc(((VObj_801C7538 *)(*(void **)((s8 *)this + 0x380)))->m74());
}

void TObjPlayer__sub_801C75A4(u8 *player) {
    s32 sp8;
    f32 temp_f1;
    ((TObjPlayer *)player)->rotation_y = interpolate_angle__10TObjPlayerFPvUsUsPl((void *) (player), (int) (((TObjPlayer *)player)->rotation_y), (void *) (((s32 (*)(void *))TObjPlayer__sub_801D0DAC)((void *) (player))), (void *) (&sp8));
    temp_f1 = ((TObjBoss2Tunnel *)(player + 0x308))->update_scale() - lbl_805DC364;
    if (temp_f1 < lbl_805DC364) {
        TObjPlayer__sub_8001053C((void *) (player));
    } else {
        TObjPlayer::calc_direction_vector((int) (((TObjPlayer *)player)->rotation_y), (void *) (player + 0x308), (f32) (temp_f1));
    }
    if (resolve_move_collision__10TObjPlayerFv((void *) (player)) == 0U) {
        ((TObjPlayer *)player)->apply_velocity();
    }
}

void TObjPlayer::start_action_18() {
    s16 var_r4;

    *(s32 *)((s8 *)this + 0x33C) = 0x18;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(this, this->mode, 6);
    if (is_action_flag_28() != 0) {
        var_r4 = ((VObj8_801c7630 *) *(void **)((s8 *)this + 0x380))->vf110();
    } else {
        var_r4 = ((VObj8_801c7630 *) *(void **)((s8 *)this + 0x380))->vf10C();
    }
    forward_1D1044_at_34c(var_r4);
    if (get_action_flag() != 0) {
        update_facing_from_lock();
    }
    ((s32 (*)(void *))TObjPlayer__sub_801D0E18)(this);
    this->phase = 0;
    get_chair_state(this->rotation_y);
    ((s32 (*)(void *))TObjPlayer__sub_801D0DF4)(this);
    set_action_state__10TObjPlayerFPvss(this, 0x18, start_action18_sub());
}

typedef struct Msg_801C770C {
    u8 pad0[2];
    u16 id;
    u16 a;
    u16 flags;
} Msg_801C770C;
s32 validate_6xAB(void *);

void handle_6xAB(void *arg0) {
    Msg_801C770C m;
    void *p;

    TObjPlayer__sub_801D1284((u8 *)&m);
    ((TObjPlayer *)(&m))->copy_packet_header_6xAB(arg0);
    ((TObjPlayer *)(&m))->swap_bytes();
    if (validate_6xAB(&m) != 0) {
        p = ((void * (*)(s32))get_player_by_client_id)(m.id);
        if (p != NULL && is_in_tl03_state__10TObjPlayerFv(p) != 0) {
            if (TObjPlayer__sub_801D11F8(&m) == 0) {
                ((TObjPlayer *)p)->clear_state_flag();
            } else {
                TObjPlayer__sub_801D0E74(p);
            }
            if (TObjPlayer__sub_801D11EC(&m) != 0) {
                ((TObjPlayer *)p)->set_anim_flag();
            }
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0x18, 0);
        }
    }
}

void TObjPlayer::send_state_sync() {
    s32 sp8[2];

    if (this == NULL || ((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0) {
        ((s32 (*)(s32 *))TObjPlayer__sub_801D1284)(sp8);
        *(s16 *)((s8 *)sp8 + 2) = get_entity_id(this);
        if ((s16) *(s16 *)((s8 *)this + 0x3C0) == (((VBase_380_801c77c8*)(*(void **)((s8 *)this + 0x380)))->m66())) {
            ((s32 (*)(s32 *))TObjPlayer__sub_801D12E8)(sp8);
        }
        if (TKeyBoardControl__sub_801A58D8() != 0) {
            ((s32 (*)(s32 *))TObjPlayer__sub_801D12D8)(sp8);
        }
        ((TObjPlayer *)sp8)->send_swapped_bytes();
    }
}

void TObjPlayer__sub_801C7858(void) {  }

void TObjPlayer__sub_801C785C(u8 *arg0) {
    if (*(s32 *)((s8 *)arg0 + 0xB0) & 0x800) {
        *(s16 *)((s8 *)arg0 + 0x328) = 1;
    }
}

void TObjPlayer__sub_801C7874(u8 *arg0) {
    Pkt_801C7874 a;
    Pkt_801C7874 b;
    s32 target;
    f32 amount;
    if (check_flag_100__10TObjPlayerFPv(arg0) == 0 && ((Player_801C7874 *)arg0)->f328 != 0 &&
        (((TObjPlayer *)(arg0 + 0x550))->check_action_usable(2) != 0 ||
         (((TObjPlayer *)arg0)->is_action_flag_28() == 0 && TKeyBoardControl__sub_801A58B0() != 0 && TKeyBoardControl::is_key_down(0x24) != 0) ||
         (((TObjPlayer *)arg0)->is_action_flag_28() != 0 && TKeyBoardControl__sub_801A58B0() != 0 && TKeyBoardControl::is_key_down(0x18) != 0))) {
        ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 5);
        return;
    }
    target = ((TObjPlayer *)(arg0 + 0x550))->get_target_field_1c();
    amount = ((TObjPlayer *)(arg0 + 0x550))->get_attached_float_24();
    if (((s32 (*)(void *))TObjPlayer__sub_801D10BC)(arg0 + 0x34C) == 0) {
        ((s32 (*)(void *))TObjPlayer__sub_801D109C)(arg0 + 0x34C);
        return;
    }
    if (check_flag_100__10TObjPlayerFPv(arg0) == 0 && ((TObjPlayer *)(arg0 + 0x550))->check_action_usable(4) != 0) {
        if (arg0 == NULL || obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0) {
            ((s32 (*)(void *))TObjPlayer__sub_801D1090)(arg0 + 0x34C);
            ((s32 (*)(void *))TObjPlayer__sub_801D1144)(&a);
            a.id = get_entity_id(arg0);
            a.val = target;
            ((TObjPlayer *)(&a))->bswap_and_send();
        }
    } else {
        if (((s32 (*)(void *))TObjPlayer__sub_801D1078)(arg0 + 0x34C) == 0) {
            ((s32 (*)(void *))TObjPlayer__sub_801D1058)(arg0 + 0x34C);
            return;
        }
        if (amount >= TObjPlayer__data_805DC368 && (arg0 == NULL || obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0)) {
            ((s32 (*)(void *))TObjPlayer__sub_801D104C)(arg0 + 0x34C);
            ((s32 (*)(void *))TObjPlayer__sub_801D11D0)(&b);
            b.id = get_entity_id(arg0);
            b.val = target;
            ((TObjPlayer *)(&b))->send_swapped_packet();
        }
    }
}

int TObjPlayer::try_change_action(void* p) { return ((TObjPlayer *)p)->try_change_action(); }

void TObjPlayer__sub_801C7A6C(s32 arg0, s16 arg1) {
  unsigned int new_var2;
  unsigned int new_var;
  {
    switch (arg1)
    {
      case 7:
        TObjPlayer::try_change_action((void *) arg0);
        return;
      new_var2 = (new_var = arg0);
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801C7874)();
        return;
      case 3:
        ((s32 (*)(void *))TObjPlayer__sub_801C785C)((void *) new_var2);
 do { } while (0 != 0);
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801C7858)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_state_sync();
        return;
      case 0:
        ((TObjPlayer *)arg0)->start_action_18();
        return;
      case 1:
        ((s32 (*)(void))TObjPlayer__sub_801C75A4)();
        return;
      case 6:
        ((TObjPlayer *)arg0)->update_state_group();
        break;
    }
  }
}

s16 TObjPlayer::select_idle_action() {
    u8 *arg0 = (u8 *)this;
    if ((void *) *(u8 **)((s8 *)arg0 + 0x380) == NULL) {
        return -1;
    }
    if ((TObjPlayer::get_hold_effect_count() == 0) && (is_lobby_floor_15__15TFontSmallLobbyFv() != 0)) {
        if (((TKeyBoardControl__sub_801A58B0() != 0) && (TKeyBoardControl::is_key_down(0x24) != 0)) || ((check_flag_100__10TObjPlayerFPv((void *) (arg0)) == 0) && (((TObjPlayer *)(arg0 + 0x550))->try_ground_action(0x400) != 0) && (((TObjPlayer *)(arg0 + 0x550))->check_action_usable(4) != 0))) {
            return ((VObj_8_1cc697 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x380))))->m65();
        }
        if (((TKeyBoardControl__sub_801A58B0() != 0) && (TKeyBoardControl::is_key_down(0x18) != 0)) || ((check_flag_100__10TObjPlayerFPv((void *) (arg0)) == 0) && (((TObjPlayer *)(arg0 + 0x550))->try_ground_action(0x400) != 0) && (((TObjPlayer *)(arg0 + 0x550))->check_action_usable(2) != 0))) {
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

    ((s32 (*)(void))TObjPlayer__sub_8001053C)();
    ((s32 (*)(void *))TObjPlayer__sub_801D0D8C)(this);
    ((s32 (*)(void *))TObjPlayer__sub_801D0E84)(this);
    set_field_dc(((VObj_801C841C *)(*(void **)((s8 *)this + 0x380)))->v76());
}

void TObjPlayer__sub_801C8478(void) {  }

void TObjPlayer::do_action() {
    *(s32 *)((s8 *)this + 0x33C) = 0x17;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(this, this->mode, 6);
    if (get_action_flag() != 0) {
        update_facing_from_lock();
    }
    if (obj_isState2_324__13TUnk_804806E8Fv(this) != 0) {
        this->m_ba = ((s16 (*)(void))ret_801D26AC)();
    }
    ((s32 (*)(void *, s32, s16))set_action_state__10TObjPlayerFPvss)(this, 0x17, *(s16 *)((s8 *)this + 0x3C0));
    if (((s32 (*)(void *))get_flag__10TObjPlayerFPv)(this) != 0) {
        set_action_flag_40();
        ((s32 (*)(void *, f32))TObjPlayer__sub_801D2618)(this, *(f32 *)((s8 *)this + 0x3C4));
    }
}

void handle_6x58_lobby_animation(void *arg0) {
    Msg_801C851C m;
    Player_801C851C *p;
    ((void (*)(void *))TObjPlayer__sub_801D13EC)(&m);
    ((TObjPlayer *)(&m))->copy_packet_header_6x58(arg0);
    ((TObjPlayer *)(&m))->bswap_packet();
    if (validate_6x58_lobby_animation(&m) != 0) {
        p = ((Player_801C851C * (*)(u16))get_player_by_client_id)(m.slot);
        if ((p != NULL) && (((s32 (*)(void))is_in_tl03_state__10TObjPlayerFv)() != 0)) {
            p->anim = m.c;
            if (((s32 (*)(void *))TObjPlayer__sub_801D1360)(&m) != 0) {
                ((TObjPlayer *)p)->set_anim_flag();
            }
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0x17, 0);
        }
    }
}

void TObjPlayer__sub_801C85BC(u8 *arg0) {
    struct Pkt_801C85BC pkt;
    if (arg0 == NULL || ((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0) {
        ((void (*)(void *))TObjPlayer__sub_801D13EC)(&pkt);
        pkt.id = get_entity_id(arg0);
        pkt.c = *(s16 *)(arg0 + 0x3C0);
        if (TKeyBoardControl__sub_801A58D8() != 0) {
            TObjPlayer__sub_801D1440(&pkt);
        }
        ((TObjPlayer *)(&pkt))->handle_recv_packet();
    }
}

void TObjPlayer__sub_801C862C(void) {  }

void TObjPlayer::update_if_flagged() {
    if ((((s32 (*)(void))get_flag__10TObjPlayerFPv)() == 0) && (this->animationFlags & 0x10)) {
        ((s32 (*)(void *))update_position_from_target__10TObjPlayerFv)(this);
    }
}

void TObjPlayer__sub_801C8678(void) {  }

int TObjPlayer::try_change_action_wrapper(void* p) { return ((TObjPlayer *)p)->try_change_action(); }

void TObjPlayer__sub_801C869C(s32 arg0, s16 arg1) {
  unsigned int new_var2;
  unsigned int new_var;
  {
    switch (arg1)
    {
      case 7:
        TObjPlayer::try_change_action_wrapper((void *) arg0);
        return;
      new_var2 = (new_var = arg0);
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801C8678)();
        return;
      case 3:
        ((TObjPlayer *)new_var2)->update_if_flagged();
 do { } while (0 != 0);
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801C862C)();
        return;
      case 5:
        ((s32 (*)(void *))TObjPlayer__sub_801C85BC)((void *) arg0);
        return;
      case 0:
        ((TObjPlayer *)arg0)->do_action();
        return;
      case 1:
        ((s32 (*)(void))TObjPlayer__sub_801C8478)();
        return;
      case 6:
        ((TObjPlayer *)arg0)->update_dispatch_v76();
        break;
    }
  }
}

void TObjPlayer::init_effects() { TObjPlayer__sub_801BE9A8((s32)this); sub_8011E204__10TObjPlayerFl(this, (void*)5); activate_body_collision(); set_indexed_flags((s32)((void*)0), (s32)((void*)1)); reset_player_appearance_opacity(((char*)this + 0x608)); }

int TObjPlayer__deactivate_off_floor_body(void* p) { return deactivate_body_collision__10TObjPlayerFv(p); }

void TObjPlayer__enter_off_floor_state(u8 *player) {
    TObjPlayer__sub_801BF690((player + 0x730));
    zero_vec3((void *) (player + 0x5FC));
    ((TObjPlayer *)(player + 0x644))->reset_lobby_model();
    ((TObjPlayer *)player)->set_state_flags(4);
    deactivate_body_collision__10TObjPlayerFv((void *) (player));
    set_flag_20000__10TObjPlayerFi((s32)(player));
    ((TObjPlayer *)player)->phase = 0;
    ((s32 (*)(void *, int, int))set_action_state__10TObjPlayerFPvss)((void *) (player), 0x16, (int) (((s16 (*)(void))ret_801D26AC)()));
}

typedef struct Msg_801C8808 {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801C8808;
s32 validate_6x57(void *);

void handle_6x57(void *arg0) {
    Msg_801C8808 m;
    u8 *p;

    ((TObjPlayer *)(&m))->set_cmd_87();
    ((void (*)(void *, void *))handle_6x57__10TObjPlayerFPv)(&m, arg0);
    TFontSmallLobby__sub_801C01BC(&m);
    if (validate_6x57(&m) != 0) {
        p = get_player_by_client_id(m.id);
        if (p != NULL) {
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0x16, 0);
        }
    }
}

void draw_and_send_field1c__10TObjPlayerFi(s32 arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        ((TObjPlayer *)((s32 *)&sp8))->set_cmd_87();
        *(s16 *)((s8 *)(&sp8) + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TObjPlayer *)((s32 *)&sp8))->draw_and_send();
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TObjPlayer__update_off_floor_state(u8 *player) {
  f32 var_f31;
  s16 *new_var;
  if (is_on_current_floor__10TObjPlayerFi() != 0)
  {
    ((s32 (*)(int, int))sub_8011E204__10TObjPlayerFl)((int)((void *) player), 4);
    ((TObjPlayer *)player)->update_active_state();
    set_flag_400000__10TObjPlayerFi((s32)player);
    ((TObjPlayer *)(player + 0x634))->enter_battle_state();
    return;
  }
  switch (((TObjPlayer *)player)->phase)
  {
    case 0:
      var_f31 = ((TObjPlayer *)player)->render_material_state.alpha;
      var_f31 = var_f31 - (*(f32 *)&TObjPlayer__data_805DC368);
      if (var_f31 < (*(f32 *)&TObjPlayer__data_805DC36C))
    {
      var_f31 = (*(f32 *)&TObjPlayer__data_805DC36C);
      new_var = (s16 *) (((s8 *) player) + 0x328);
      *new_var = 1;
      ((s32 (*)(void *, int))obj_setFlags30)((void *) player, 0x02000000);
      ((TUnk_804AF8A0 *)player)->clear_player_status_flag(0, 1);
    }
      ((TObjPlayer *)player)->render_material_state.alpha = var_f31;
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
void TObjPlayer__sub_801C8998(u8 *arg0) {
  f32 var_f0;
  f32 var_f1;
  f32 var_f2;
  s32 var_r4;
  u8 *var_r31;
  u8 *var_r3;
  var_r31 = (u8 *) arg0;
  if (((s32) is_on_current_floor__10TObjPlayerFi()) != 0)
  {
    var_r3 = (u8 *) var_r31;
    var_r4 = 4;
    ((s32 (*)(int, int))sub_8011E204__10TObjPlayerFl)((int) var_r3, 4);
    return;
  }
  switch (*((s16 *) (((s8 *) var_r31) + 0x328)))
  {
    case 0:
      var_f2 = *((f32 *) (((s8 *) var_r31) + 0x624));
      var_f1 = TObjPlayer__data_805DC368;
      var_f0 = TObjPlayer__data_805DC36C;
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

void TObjPlayer__sub_801C8A20(void) {  }

void TObjPlayer__sub_801C8A24(void) {  }

void TObjPlayer__sub_801C8A28(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void))TObjPlayer__sub_801C8A24)();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801C8A20)();
        return;
      case 3:
        ((s32 (*)(void *))TObjPlayer__sub_801C8998)((void *) arg0);
        return;
      case 8:
        ((s32 (*)(void *))TObjPlayer__update_off_floor_state)((void *) arg0);
        return;
      case 5:
        ((s32 (*)(void *))draw_and_send_field1c__10TObjPlayerFi)((void *) arg0);
        return;
      case 0:
        ((s32 (*)(void *))TObjPlayer__enter_off_floor_state)((void *) arg0);
        return;
      case 1:
        ((s32 (*)(void *))TObjPlayer__deactivate_off_floor_body)((void *) arg0);
        return;
      case 6:
        ((TObjPlayer *)arg0)->init_effects();
        break;
    }
  }
}

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
void TObjPlayer::start_action_21() {
    *(s32 *)((s8 *)this + 0x33C) = 0x15;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(this, this->mode, 6);
    cleanup_idle_entry();
    clear_player_status_flag(0, 1);
    this->render_material_state.alpha = (f32) TObjPlayer__data_805DC36C;
    refresh_equipment_slot();
    this->update_actor_ground_y();
    if (is_locally_controlled__10TObjPlayerFPv(this) != 0) {
        this->play_sound_if_on_floor(0x40003206);
    }
    this->phase = 1;
    set_action_state__10TObjPlayerFPvss(this, 0x15, ((s32 (*)(void *))get_idle_animation__10TObjPlayerFv)(this));
}

#undef CAT2
#undef CAT
void handle_6x56_set_player_position_and_angle(void *arg0) {
    Msg_801C8B5C m;
    Player_801C8B5C *p;
    ((TObjPlayer *)(&m))->init_position_packet();
    ((void (*)(void *, void *))TObjPlayer__sub_801D1514)(&m, arg0);
    ((TObjPlayer *)(&m))->swap_endian_words();
    if (validate_6x56_set_player_position_and_angle(&m) != 0) {
        p = ((Player_801C8B5C *)((u8 * (*)(s32))get_player_by_client_id)((s32)(m.slot)));
        if (p != NULL) {
            p->ang = m.c;
            ((TUnk_804B9870 *)p)->set_position_from(m.vec);
            ((TUnk_804806E8 *)p)->calc_attach_pos();
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0x15, 0);
        }
    }
}

void TObjPlayer::send_position_update() {
    u8 *arg0 = (u8 *)this;
    struct Pkt_801C8BE8 pkt;
    if (arg0 == NULL || ((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0) {
        ((TObjPlayer *)(&pkt))->init_position_packet();
        pkt.id = get_entity_id(arg0);
        pkt.c = *(s32 *)(arg0 + 0x60);
        VecCopy__FP3VecPC3Vec(&pkt.x1, (u8 *)&this->position);
        ((TObjPlayer *)(&pkt))->update_and_send2();
    }
}

void TObjPlayer__sub_801C8C50(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void))TObjPlayer__sub_801C912C)();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801C9128)();
        return;
      case 3:
        ((TObjPlayer *)arg0)->check_state_dead();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801C90F8)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_position_update();
        return;
      case 0:
        ((TObjPlayer *)arg0)->start_action_21();
        return;
      case 1:
        ((TObjPlayer *)arg0)->update_warp_relocation();
        return;
      case 6:
        ((TObjPlayer *)arg0)->init_flags_vec4();
        break;
    }
  }
}

void send_6x55_intra_map_warp(u16 id, void *pos, s32 c) {
    struct Pkt_801C8CCC pkt;
    u8 *p;
    p = ((u8 * (*)(s32))get_player_by_client_id)(id);
    if (p != NULL && (p == NULL || ((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        TObjPlayer__sub_801D1658(&pkt);
        pkt.id = id;
        pkt.c = c;
        VecCopy__FP3VecPC3Vec(&pkt.x1, p + 0x38);
        VecCopy__FP3VecPC3Vec(&pkt.x2, pos);
        ((TObjPlayer *)(&pkt))->swap_and_send();
    }
}

void TObjPlayer::init_flags_vec4() { set_indexed_flags((s32)((void*)0), (s32)((void*)1)); ((TObjPlayer *)((char*)this + 0x608))->set_vec4_const(); }

void TObjPlayer::update_warp_relocation() {
    s32 sp8;
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
            this->rotation_y = *(s32 *)((s8 *)((u8 *)this) + 0x65C);
            ((TUnk_804B9870 *)((u8 *)this))->set_position_from(((u8 *)this) + 0x660);
            refresh_equipment_slot();
            this->clear_flag_4000();
            this->update_actor_ground_y();
            if (((s32 (*)(void *))is_on_current_floor__10TObjPlayerFi)(this) != 0) {
                this->play_sound_if_on_floor(0x40003206);
            }
            if (is_locally_controlled__10TObjPlayerFPv(this) != 0) {
                TObjPlayer::calc_circle_offset_pos(this->rotation_y + 0x8000, (void *)this->get_position_ptr(), &sp8, 10.0f);
                send_6x3e_to_all_players__10TNpcPlayerFPvs(&sp8, this->rotation_y);
                reset_cameras_to_actor(this, 1);
            }
        }
        this->render_material_state.alpha = var_f31;
        break;
    case 1:
        if (((s32 (*)(void *))is_inactive__10TObjPlayerFv)(this) != 0) {
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
                ((s32 (*)(void *))get_entity_id)(this);
                spawn_appearance_effect__10TObjPlayerFl();
            }
        }
        break;
    case 3:
        this->set_flag_4000();
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
    *(s32 *)((s8 *)this + 0x33C) = 0x14;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(this, this->mode, 6);
    TObjPlayer__sub_8001053C(this);
    clear_player_status_flag(0, 1);
    this->phase = 0;
    this->play_sound_if_on_floor(0x40003205);
    set_action_state__10TObjPlayerFPvss(this, 0x14, ((s32 (*)(void *))get_idle_animation__10TObjPlayerFv)(this));
}

void handle_6x55_intra_map_warp(s32 arg0) {
    Cmd_801C8FCC cmd;
    u8 *p;
    TObjPlayer__sub_801D1658(&cmd);
    ((void (*)(void *, void *))TObjPlayer__sub_801D0EA0)(&cmd, (void *)arg0);
    ((TObjPlayer *)(&cmd))->swap_endian();
    if (validate_6x55_intra_map_warp(&cmd) != 0) {
        p = get_player_by_client_id(cmd.client);
        if (p != NULL && is_in_tl03_state__10TObjPlayerFv(p) != 0 && test_action_mask__10TObjPlayerFl(p, 0x8200) == 0) {
            *(s32 *)(p + 0x65C) = cmd.area;
            ((TUnk_804B9870 *)p)->set_position_from(&cmd.a);
            VecCopy__FP3VecPC3Vec(p + 0x660, &cmd.pos);
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0x14, 0);
        }
    }
}

void TObjPlayer::send_warp_position() {
    u8 *arg0 = (u8 *)this;
    struct Pkt_801C9084 pkt;
    if (arg0 == NULL || ((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0) {
        TObjPlayer__sub_801D1658(&pkt);
        pkt.id = get_entity_id(arg0);
        pkt.c = *(s32 *)(arg0 + 0x60);
        VecCopy__FP3VecPC3Vec(&pkt.x1, (u8 *)&this->position);
        VecCopy__FP3VecPC3Vec(&pkt.x2, (u8 *)&this->position);
        ((TObjPlayer *)(&pkt))->swap_and_send();
    }
}

void TObjPlayer__sub_801C90F8(void) {  }

void TObjPlayer::check_state_dead() { if (this->phase == 4) { ((int (*)(void*))update_position_from_target__10TObjPlayerFv)(this); } }

void TObjPlayer__sub_801C9128(void) {  }

void TObjPlayer__sub_801C912C(void) {  }

void run_warp_action_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  s32 new_var;
  {
    new_var = arg0;
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void))TObjPlayer__sub_801C912C)();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801C9128)();
        return;
      case 3:
        ((TObjPlayer *)new_var)->check_state_dead();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801C90F8)();
        return;
      case 5:
        ((TObjPlayer *)new_var)->send_warp_position();
        return;
      case 0:
        ((TObjPlayer *)arg0)->set_dead_state();
        return;
      case 1:
        ((TObjPlayer *)new_var)->update_warp_relocation();
        return;
      case 6:
        ((TObjPlayer *)arg0)->init_flags_vec4();
        break;
    }
  }
}

void TObjPlayer::reset_lobby_state() {
    u8 *arg0 = (u8 *)this;
    ((s32 (*)(void))clear_status_bit6__10TObjPlayerFPv)();
    TObjPlayer__sub_8001053C(arg0);
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)0x20);
    if (((s16) this->phase == 1) && (is_locally_controlled__10TObjPlayerFPv(arg0) != 0)) {
        ((TObjPlayer *)(arg0 + 0x644))->reset_lobby_model();
    }
}

void TObjPlayer::try_use_mag() {
    u8 *arg0 = (u8 *)this;
    if ((is_active__8TItemMagFv() == 0) && (is_locally_controlled__10TObjPlayerFPv(arg0) != 0) && (((TKeyBoardControl *)(arg0 + 0x64C))->check_input_angle() != 0)) {
        ((TObjPlayer *)arg0)->add_status_effect_timer(1, *(s32 *)((s8 *)arg0 + 0x3D4));
    }
}

void TObjPlayer::enter_freeze_action() {
    *(s32 *)((s8 *)this + 0x33C) = 0x13;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(this, this->mode, 6);
    TObjPlayer__sub_8001053C(this);
    obj_clearFlags30((u32)0x200);
    set_action_flag_40();
    if (((s32 (*)(void *))is_active__8TItemMagFv)(this) != 0) {
        this->phase = 1;
    } else {
        this->phase = 0;
        *(s32 *)((s8 *)this + 0x3D4) = (s32) -(lbl_80447128 * (f64) TObjPlayer__sub_8001943C(this, 1));
    }
    set_action_state__10TObjPlayerFPvss(this, 0x13, (s16) ((s16 (*)(void))ret_801D26AC)());
}

typedef struct Msg_801C9350 {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801C9350;
s32 validate_6x53(void *);
void* update_small_font2__10TObjPlayerFPv(void* p);

void handle_6x53(void *arg0) {
    Msg_801C9350 m;
    u8 *p;

    ((TObjPlayer *)(&m))->set_type_53();
    ((void (*)(void *, void *))update_small_font2__10TObjPlayerFPv)(&m, arg0);
    TFontSmallLobby__sub_801C01BC(&m);
    if (validate_6x53(&m) != 0) {
        p = get_player_by_client_id(m.id);
        if (p != NULL && is_in_tl03_state__10TObjPlayerFv(p) != 0) {
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0x13, 0);
        }
    }
}

void* update_small_font2__10TObjPlayerFPv(void* p) { TFontSmallLobby__sub_801C0228(p); return p; }

void TObjPlayer::send_name_and_state() {
    u8 *arg0 = (u8 *)this;
    MsgA_801C9400 a;
    MsgB_801C9400 b;
    if (is_active__8TItemMagFv() == 0) {
        init_stick_escape_detector((u8 *)&this->m_64c, (void *)(TObjPlayer__sub_801D2878((u8 *)&this->m_550)));
    }
    if ((arg0 == NULL) || (obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0)) {
        ((TObjPlayer *)(&a))->set_type_53();
        a.f2 = ((s16)((s32 (*)(void *))get_entity_id)(arg0));
        ((TObjPlayer *)(&a))->send_name();
        ((TObjPlayer *)(&b))->init_6x2F_packet_header();
        b.f2 = ((s16)((s32 (*)(void *))get_entity_id)(arg0));
        b.f4 = 0;
        b.f8 = ((s16)get_actor_hp(arg0));
        b.fa = ((s16)((s32 (*)(void *))get_entity_id)(arg0));
        TObjPlayer__sub_801C0734(&b);
    }
}

void TObjPlayer__sub_801C94B8(u8 *arg0) {
    switch (*(s16 *)(arg0 + 0x328)) {
    case 1:
        if (is_active__8TItemMagFv() == 0) {
            ((void (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 0);
        }
        break;
    }
}

void TObjPlayer::update_gated_action() {
    s32 temp_r31;

    if (this->phase == 0) {
        if (is_status_flag_200__10TObjPlayerFv() != 0) {
            temp_r31 = ((s32 (*)(void *))get_entity_id)(this);
            send_6x2F_change_player_hp(temp_r31, temp_r31, get_actor_hp(this));
            obj_clearFlags30((u32)0x200);
            return;
        }
        if (((s32 (*)(void *))can_guard__10TObjPlayerFPv)(this) != 0) {
            use_current_item();
        }
    }
}

void TObjPlayer__sub_801C959C(void) {  }

void TObjPlayer::update_frozen_release() {
    u8 *arg0 = (u8 *)this;
  s16 temp_r0;
  if (((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x800) != 0)
  {
    ((FlagWord *)(arg0 + 0x858))->clear(1);
    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *) arg0, 0xF, 5);
    return;
  }
  ;
  switch (this->phase)
  {
    return;
    case 0:
      if (((s32 (*)(s32))check_flag30_bit20__10TObjPlayerFi)((s32) arg0) == 0)
    {
      update_position_from_target__10TObjPlayerFv(arg0);
    }
      return;
    case 1:
      if (((s32 (*)(void *))is_active__8TItemMagFv)(arg0) == 0)
    {
      update_position_from_target__10TObjPlayerFv(arg0);
    }
      break;
  }
}

void TObjPlayer__sub_801C9648(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->update_frozen_release();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801C959C)();
        return;
      case 3:
        ((TObjPlayer *)arg0)->update_gated_action();
        return;
      case 8:
        ((s32 (*)(void *))TObjPlayer__sub_801C94B8)((void *) arg0);
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_name_and_state();
        return;
      case 0:
        ((TObjPlayer *)arg0)->enter_freeze_action();
        return;
      case 1:
        ((TObjPlayer *)arg0)->try_use_mag();
        return;
      case 6:
        ((TObjPlayer *)arg0)->reset_lobby_state();
        break;
    }
  }
}

s32 TObjPlayer::try_change_action() {
    s32 arg0 = (s32)this;
    if (is_status_locked__10TObjPlayerFv() != 0) {
        if (((TObjPlayer *)(arg0 + 0x5F0))->get_action_id() == 0x10) {
            ((s32 (*)(s32, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0x10, 5);
        } else {
            ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)((void*)(0x10000)));
            ((s32 (*)(s32, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)(arg0 + 0x5F0))->get_action_id(), 5);
            ((TObjPlayer *)(arg0 + 0x5F0))->set_action_id(0);
        }
        return 1;
    }
    return 0;
}

void TObjPlayer::clear_flag() { obj_clearFlags30((u32)((void*)((void*)65536))); ((int (*)(void*))TObjPlayer__sub_8001053C)(this); }

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
    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *)(arg0), (int) (this->mode), 6);
    this->m_b8 = TObjPlayer__sub_801D2824((void *) (arg0 + 0x5F0));
    this->rotation_y = ((TObjPlayer *)(arg0 + 0x5F0))->get_field_4();
    ((s32 (*)(void *, int, int))set_action_state__10TObjPlayerFPvss)((void *) (arg0), 0x10, (int) (((s16 (*)(void))ret_801D26AC)()));
}

void handle_6x52_set_animation_state(s32 arg0) {
    Pkt_801C9838 pkt;
    s32 temp_r3;
    ((TObjPlayer *)(&pkt))->init_6x52_packet();
    ((TObjPlayer *)(&pkt))->copy_font_state((void *) (arg0));
    ((TObjPlayer *)(&pkt))->swap_stats_bytes();
    if (validate_6x52_set_animation_state((void *) (&pkt)) != 0) {
        temp_r3 = ((s32 (*)(int))get_player_by_client_id)((int) (pkt.client));
        if ((temp_r3 != 0) && (((s32 (*)(void))is_in_tl03_state__10TObjPlayerFv)() != 0) && (((s32 (*)(int, int))test_action_mask__10TObjPlayerFl)((int) (temp_r3), 0x8000) == 0) && ((is_lobby_floor_15__15TFontSmallLobbyFv() == 0) || (((s32 (*)(int))obj_isState2_324__13TUnk_804806E8Fv)((int) (temp_r3)) == 0) || (check_flag__10TObjPlayerFl((int) (temp_r3), 0x04000000) == 0))) {
            set_anim_state__10TObjPlayerFs((void *) (temp_r3 + 0x5F0), (int) (pkt.c));
            set_anim_state__10TObjPlayerFl((void *) (temp_r3 + 0x5F0), (int) (pkt.g));
            ((TObjPlayer *)(temp_r3 + 0x5F0))->set_state((int) (pkt.e));
            ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *) (temp_r3), 0x10, 0);
        }
    }
}

void TObjPlayer::send_6x52_animation_state() {
    u8 *arg0 = (u8 *)this;
    struct Pkt_801C9924 pkt;
    if (arg0 == NULL || ((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0) {
        ((TObjPlayer *)(&pkt))->init_6x52_packet();
        pkt.id = get_entity_id(arg0);
        pkt.a = TObjPlayer__sub_801D2824((u8 *)&this->m_5f0);
        pkt.c = ((TObjPlayer *)(arg0 + 0x5F0))->get_field_4();
        pkt.b = TObjPlayer__sub_801D282C((u8 *)&this->m_5f0);
        ((TObjPlayer *)(&pkt))->update_display();
    }
}

void TObjPlayer::service_hold_phase8_nop() {  }

void TObjPlayer::update_service_hold() {
    u8 *arg0 = (u8 *)this;
    if (!(this->actorFlags & 0x10000)) {
        if (((TObjPlayer *)(arg0 + 0x5F0))->get_action_id() == 0) {
            ((s32 (*)(void *))update_position_from_target__10TObjPlayerFv)((void *) (arg0));
            return;
        }
        ((s32 (*)(void *, s16, int))run_action_state_phase__10TObjPlayerFisi)((void *) (arg0), ((TObjPlayer *)(arg0 + 0x5F0))->get_action_id(), 5);
        ((TObjPlayer *)(arg0 + 0x5F0))->set_action_id(0);
    }
}

void TObjPlayer::service_hold_phase2_nop() {  }

void TObjPlayer::set_motion(s32 arg0) {
    if (is_status_flag_200__10TObjPlayerFv() != 0) {
        if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x400) != 0) {
            ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xE, 5);
            return;
        }
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xD, 5);
        return;
    }
    if (((s32 (*)(s32))can_guard__10TObjPlayerFPv)(arg0) != 0) {
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xA, 5);
        return;
    }
    if (((s32 (*)(s32))check_flag30_bit20__10TObjPlayerFi)(arg0) != 0) {
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0x13, 5);
    }
}

void run_service_hold_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  unsigned int new_var2;
  unsigned int new_var;
  {
    switch (arg1)
    {
      case 7:
        TObjPlayer::set_motion(arg0);
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
        ((TObjPlayer *)arg0)->send_6x52_animation_state();
        return;
      case 0:
        ((TObjPlayer *)arg0)->enter_service_hold_action();
        return;
      case 1:
        ((s32 (*)(void))apply_velocity_if_free__10TObjPlayerFPv)();
        return;
      case 6:
        ((TObjPlayer *)arg0)->clear_flag();
        break;
    }
  }
}

void notify_lobby__10TObjPlayerFi(s32 arg0) {
    ((s32 (*)(void))clear_status_bit6__10TObjPlayerFPv)();
    TLobby__sub_8024AC20(((u16 (*)(s32))get_entity_id)(arg0));
}

void ensure_default__10TObjPlayerFPv(void *player) {
    void *x;
    x = ((void * (*)(void *))resolve_move_collision__10TObjPlayerFv)(player);
    if (x == NULL) {
        ((TObjPlayer *)player)->apply_velocity();
    }
}

void TObjPlayer::init_action() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x33C) = 0x12;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, this->mode, 6);
    TObjPlayer__sub_8001053C(arg0);
    set_type__10TObjPlayerFl((u8 *)&this->m_644, 0x12C);
    this->phase = 0;
    this->m_2b4 = (f32) lbl_805DC374;
    TObjPlayer__sub_8000FF4C(arg0, 0xFFFF);
    ((s32 (*)(void *, s32, s16))set_action_state__10TObjPlayerFPvss)(arg0, 0x12, (s16) ((s32 (*)(void))ret_801D26AC)());
    fn_800660B8(arg0);
    if (are_items_enabled_here() != 0) {
        void *new_obj = (void *)(size_t)__nw__7TObjectFUl(0x38);
        if (new_obj != 0U) {
            construct_revival_particle_effect(new_obj, arg0, tl_07);
        }
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x548) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x548));
        *(u32 *)((s8 *)arg0 + 0x548) = 0U;
    }
}

typedef struct Msg_801C9C8C {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801C9C8C;
s32 validate_6x4F_player_revived(void *);

void handle_6x4F_player_revived(void *arg0) {
    Msg_801C9C8C m;
    u8 *p;

    ((TObjPlayer *)(&m))->set_revived_state();
    ((void (*)(void *, void *))handle_6x4F_revived__10TObjPlayerFi)(&m, arg0);
    TFontSmallLobby__sub_801C01BC(&m);
    if (validate_6x4F_player_revived(&m) != 0) {
        p = get_player_by_client_id(m.id);
        if (p != NULL && is_in_tl03_state__10TObjPlayerFv(p) != 0) {
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0x12, 0);
        }
    }
}

s32 handle_6x4F_revived__10TObjPlayerFi(s32 arg0) {
    ((s32 (*)(void))TFontSmallLobby__sub_801C0228)();
    return arg0;
}

void TObjPlayer::send_6x4F_revived() {
    u32 arg0 = (u32)this;
    struct Local801C9D3C sp8;

    if (((s32 (*)(s32, s32))test_flags_any)(arg0 + 0x858, 4) != 0) {
        send_code_49_1__10TObjPlayerFi(arg0);
        if (((TObjPlayer *)arg0)->is_alive_and_ready() != 0) {
            ((TObjPlayer *)arg0)->refill_traps();
        }
    } else {
        TObjPlayer__sub_801B4430(arg0);
    }
    ((TFontSmallLobby *)(arg0 + 0x4AC))->update_if_ready();
    if ((arg0 == 0U) || (((s32 (*)(u32))obj_isState2_324__13TUnk_804806E8Fv)(arg0) == 0)) {
        ((TObjPlayer *)((s32 *)&sp8))->set_revived_state();
        sp8.fieldA = ((s16 (*)(u32))get_entity_id)(arg0);
        ((TObjPlayer *)((s32 *)&sp8))->broadcast_lobby_display();
    }
}

void update_timer_state__10TObjPlayerFPv(void *arg0) {
    f32 temp_f1;
    f32 temp_f1_2;

    switch (*(s16 *)((s8 *)arg0 + 0x328)) {
    case 0:
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x2B4) - TObjPlayer__data_805DC360;
        *(f32 *)((s8 *)arg0 + 0x2B4) = temp_f1;
        if (temp_f1 < TObjPlayer__data_805DC36C) {
            *(s16 *)((s8 *)arg0 + 0x328) = 1;
            ((TObjEnePanarms *)arg0)->init((void*)(((s32 (*)(void))get_idle_animation__10TObjPlayerFv)()));
            ((TObjPlayer *)arg0)->set_action_flag_40();
            *(f32 *)((s8 *)arg0 + 0x2B4) = (f32) TObjPlayer__data_805DC378;
        }
        break;
    case 1:
        temp_f1_2 = *(f32 *)((s8 *)arg0 + 0x2B4) - TObjPlayer__data_805DC360;
        *(f32 *)((s8 *)arg0 + 0x2B4) = temp_f1_2;
        if (temp_f1_2 < TObjPlayer__data_805DC36C) {
            ((s32 (*)(void))clear_status_bit6__10TObjPlayerFPv)();
            ((s32 (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 0);
        }
        break;
    }
}

void TObjPlayer::update_timer_action() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f1_2;

    switch (this->phase) {
    case 0:
        temp_f1 = this->m_2b4 - TObjPlayer__data_805DC360;
        this->m_2b4 = temp_f1;
        if (temp_f1 < TObjPlayer__data_805DC36C) {
            this->phase = 1;
            ((TObjEnePanarms *)arg0)->init((void*)(((s32 (*)(void))get_idle_animation__10TObjPlayerFv)()));
            set_action_flag_40();
            this->m_2b4 = (f32) TObjPlayer__data_805DC378;
        }
        break;
    case 1:
        temp_f1_2 = this->m_2b4 - TObjPlayer__data_805DC360;
        this->m_2b4 = temp_f1_2;
        if (temp_f1_2 < TObjPlayer__data_805DC36C) {
            ((s32 (*)(void))clear_status_bit6__10TObjPlayerFPv)();
            set_type__10TObjPlayerFl((u8 *)&this->m_644, get_getup_protection_ticks__10TObjPlayerFv(arg0));
            ((s32 (*)(void *))update_position_from_target__10TObjPlayerFv)(arg0);
        }
        break;
    }
}

void TObjPlayer__sub_801C9F64(void) {  }

void TObjPlayer__sub_801C9F68(void) {  }

void run_revival_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  unsigned int new_var2;
  unsigned int new_var;
  {
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void *))TObjPlayer__sub_801C9F68)((void *) arg0);
        return;
      new_var2 = (new_var = arg0);
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801C9F64)();
        return;
      case 3:
        ((TObjPlayer *)new_var2)->update_timer_action();
 do { } while (0 != 0);
        return;
      case 8:
        ((s32 (*)(void))update_timer_state__10TObjPlayerFPv)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_6x4F_revived();
        return;
      case 0:
        ((TObjPlayer *)arg0)->init_action();
        return;
      case 1:
        ((s32 (*)(void))ensure_default__10TObjPlayerFPv)();
        return;
      case 6:
        ((s32 (*)(void *))notify_lobby__10TObjPlayerFi)((void *) arg0);
        break;
    }
  }
}

void handle_6x89_set_killer_entity_id(void *arg0) {
    struct Pkt_801C9FE8 pkt;
    u8 *p;
    ((TObjPlayer *)(&pkt))->init_6x89_packet();
    ((TObjPlayer *)(&pkt))->copy_head_fields(arg0);
    ((TObjPlayer *)(&pkt))->bswap_fields();
    if (validate_6x89_set_killer_entity_id(&pkt) != 0) {
        p = get_player_by_client_id(pkt.id);
        if (p != NULL) {
            *(u16 *)(p + 0x2D4) = pkt.c;
        }
    }
}

void init_subobject__10TObjPlayerFi(s32 arg0) {
    if (arg0 != 0) {
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xF, 0);
        ((TObjPlayer *)arg0)->update_action_render();
        ((s32 (*)(s32))zero_vec3)(arg0 + 0x5FC);
        calc_death_pose_height_offset(arg0 + 0x5FC, arg0);
        ((TObjPlayer *)(arg0 + 0x5FC))->set_pos_z((*(f32 *)&TObjPlayer__data_805DC360));
    }
}

void queue_player_injured_pose(s32 arg0) {
    s32 temp_r3;
    temp_r3 = ((s32 (*)(s32))__nw__7TObjectFUl)(0x24);
    if (temp_r3 != 0) {
        __ct__20TPlayerReadyCallbackFP7TObjectUsPFP10TObjPlayer_v(temp_r3, arg0, ((s32 (*)(s32))get_entity_id)(arg0), (void (*)(int))init_subobject__10TObjPlayerFi);
    }
}

void TObjPlayer::update_active_state() {
    u8 *arg0 = (u8 *)this;
    if (is_on_current_floor__10TObjPlayerFi() != 0) {
        ((s32 (*)(void *, s32))sub_8011E204__10TObjPlayerFl)(arg0, 4);
        if (((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x800) == 0) {
            ((s32 (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 0);
            return;
        }
        ((s32 (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xF, 0);
        if (((s32 (*)(void *, s32))test_flags_any)(arg0 + 0x858, 1) != 0) {
            this->m_b8 = get_action_animation__10TObjPlayerFv(arg0);
        } else {
            ((TObjPlayer *)arg0)->restart_death_pose();
        }
        ((TObjPlayer *)(arg0 + 0x5FC))->set_pos_z(TObjPlayer__data_805DC360);
        ((TObjPlayer *)arg0)->revive_or_spawn_marker();
    }
}

typedef struct Msg_801CA1C4 {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801CA1C4;
s32 validate_6x4E_player_revivable(void *);

void handle_6x4E_player_revivable(void *arg0) {
    Msg_801CA1C4 m;
    u8 *p;

    ((TObjPlayer *)(&m))->init_revive_packet();
    ((void (*)(void *, void *))handle_revivable__10TObjPlayerFi)(&m, arg0);
    TFontSmallLobby__sub_801C01BC(&m);
    if (validate_6x4E_player_revivable(&m) != 0) {
        p = get_player_by_client_id(m.id);
        if (p != NULL && is_in_tl03_state__10TObjPlayerFv(p) != 0) {
            ((TObjPlayer *)p)->update_action_render();
            ((TObjPlayer *)p)->revive_or_spawn_marker();
        }
    }
}

s32 handle_revivable__10TObjPlayerFi(s32 arg0) {
    ((s32 (*)(void))TFontSmallLobby__sub_801C0228)();
    return arg0;
}

void TObjPlayer::send_6x4E_player_revivable(s32 arg0) {
    struct S801CA274 sp8;

    if ((arg0 == 0) || (((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        ((TObjPlayer *)(&sp8))->init_revive_packet();
        sp8.h = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TObjPlayer *)(&sp8))->bswap_font_lobby2();
    }
}

void TObjPlayer::update_action_render() {
    u8 *arg0 = (u8 *)this;
    if (test_flags_any((void *) (arg0 + 0x858), 1) != 0) {
        this->m_b8 = get_action_animation__10TObjPlayerFv((void *) (arg0));
    } else {
        this->m_b8 = ((s16 (*)(void *))get_model_field_m25__10TObjPlayerFv)((void *) (arg0));
    }
    ((TObjMotion *)arg0)->set_animation((int) (this->m_b8));
    this->m_c0 = (f32) (*(f32 *)((s8 *)arg0 + 0xC4) - TObjPlayer__data_805DC360);
    draw__10TObjPlayerFPvf((void *) (arg0), (f32) (this->m_c0));
    set_action_flag_40();
    this->animationFlags = (s32) (this->animationFlags & 0xFFFFFFDF);
}

void TObjPlayer::restart_death_pose() {
    s32 var_r31;
    u8 *arg0 = (u8 *)this;
    ((TObjPlayer *)arg0)->update_action_render();
    ((void (*)(void *))zero_vec3)((void *) (arg0 + 0x5FC));
    ((s32 (*)(void *, void *))calc_death_pose_height_offset)((void *) (arg0 + 0x5FC), (void *) (arg0));
    if (is_locally_controlled__10TObjPlayerFPv((void *) (arg0)) != 0) {
        var_r31 = ((s32 (*)(int))__nw__7TObjectFUl)(0x2C);
        if (var_r31 != 0) {
            var_r31 = init_entry_fields__6TLobbyFiii((int) (var_r31), (int) (tl_particlemodel), (void *) (&complete_deferred_player_death), (void *) (((u16 (*)(void *))get_entity_id)((void *) (arg0))));
        }
        *(s32 *)((s8 *)arg0 + 0x548) = var_r31;
    }
}

void TObjPlayer::reset_on_death() {
    u8 *arg0 = (u8 *)this;
    obj_setFlags30(arg0, 0x800U);
    this->hp = 0;
    this->clear_all_status_effects();
    ((TObjPlayer *)(arg0 + 0x644))->reset_lobby_model();
    ((void (*)(void *))zero_vec3)(arg0 + 0x5FC);
}

void TObjPlayer::exit_death_state() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)arg0 + 0x30) & 0xFFFFFDFF;
    *(s32 *)((s8 *)arg0 + 0x30) = temp_r4;
    *(s32 *)((s8 *)arg0 + 0x36C) = 0;
    ((s32 (*)(void *, s32))zero_vec3)(arg0 + 0x5FC, temp_r4);
    ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(arg0);
}

void TObjPlayer::update_death_pose() {
    u8 *arg0 = (u8 *)this;
    if ((sub_80143960__10TObjMotionFl(arg0, 0x20) != 0) && ((s16) this->m_b8 == (s16) this->m_ba)) {
        ((TObjPlayer *)arg0)->restart_death_pose();
    }
    ((s32 (*)(void *, f32))add_death_sink_progress)(arg0 + 0x5FC, lbl_805DC37C);
    calc_death_sink_offset((u8 *)&this->m_5fc);
    if (resolve_move_collision__10TObjPlayerFv(arg0) == 0U) {
        ((TObjPlayer *)arg0)->apply_velocity();
    }
}

void TObjPlayer::enter_death_state() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r31;
    u32 other;
    s32 killer;
    u8 *culprit;
    u8 *entity;
    u8 *character_save_record;
    u8 *temp_r3_3;
    *(s32 *)((s8 *)arg0 + 0x33C) = 0xF;
    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *)(arg0), (int) (this->mode), 6);
    reset_on_death();
    TObjPlayer__sub_8001053C((void *) (arg0));
    this->phase = 0;
    if (test_flags_any((void *) (arg0 + 0x858), 1) != 0) {
        ((s32 (*)(void *, int, void *))set_action_state__10TObjPlayerFPvss)((void *) (arg0), 0xF, (void *) (((s16 (*)(void))ret_801D26AC)()));
        ((TObjPlayer *)arg0)->restart_death_pose();
    } else {
        ((s32 (*)(void *, int, void *))set_action_state__10TObjPlayerFPvss)((void *) (arg0), 0xF, (void *) (get_model_field_m25__10TObjPlayerFv((void *) (arg0))));
    }
    ((TObjPlayer *)(arg0 + 0x4AC))->clear_photon_blast_state();
    if (is_technique_ready__8TTecCtrlFv() != 0) {
        entity = find_entity_by_id(get_field_2d4__10TObjPlayerFv(arg0));
        if (entity != NULL) {
            if (check_value_equals__13TUnk_804B6C24Fl((int)entity, lbl_805D3530) != 0) {
                temp_r31 = (u16)((s32 (*)(void *))get_entity_id)(arg0);
                other = (u16)((s32 (*)(void *))get_entity_id)(entity);
                if (other != temp_r31) {
                    fn_801B0480((int) (entity), (void *) (arg0), 1);
                }
            }
            if (check_value_equals__13TUnk_804B6C24Fl((int) (entity), (void *) (TOMineTrap__data_805D3080)) == 0) {
                update_trap_sub__10TOMineTrapFv((void *) (arg0), (int) (entity), 1);
            } else if ((u16)(killer = get_trap_type__10TOMineTrapFv((int)entity)) == 0xffffU) {
                update_trap_sub__10TOMineTrapFv((void *) (arg0), (int) (entity), 1);
            } else {
                culprit = find_entity_by_id(killer);
                update_trap_sub__10TOMineTrapFv(arg0, (s32)culprit, 1);
            }
            draw_player_status((void *) (arg0), (void *) (entity), (void *) (&lbl_805DC380));
        }
        draw_player_status((void *) (arg0), (void *) (arg0), (void *) (&lbl_805DC384));
        if (is_locally_controlled__10TObjPlayerFPv((void *) (arg0)) != 0) {
            send_neg50__6TLobbyFPvPv((void *) (&lbl_80447138), 0x96);
        }
    }
    if ((is_locally_controlled__10TObjPlayerFPv((void *) (arg0)) != 0) && (is_camera_mode_active__10TObjPlayerFv() == 0) && (is_technique_ready__8TTecCtrlFv() == 0)) {
        if (is_single_screen__10TObjPlayerFv() != 0) {
            character_save_record = get_character_save_record(((s32 (*)(void *))get_entity_id)((void *) (arg0)));
            *(s32 *)((s8 *)character_save_record + 0x244) = (s32) (*(s32 *)((s8 *)character_save_record + 0x244) + 1);
            return;
        }
        temp_r3_3 = get_character_save_record(0xFFFFU);
        *(s32 *)((s8 *)temp_r3_3 + 0x244) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0x244) + 1);
    }
}

void handle_6x4D_player_died(void *arg0) {
    Cmd_801CA724 cmd;
    u8 *p;
    ((TObjPlayer *)(&cmd))->init_6x4D_packet();
    ((s32 (*)(void *, void *))TObjPlayer__sub_801D28A0)(&cmd, arg0);
    ((TObjPlayer *)(&cmd))->init_field_4();
    if (validate_6x4D_player_died(&cmd) != 0) {
        p = ((u8 * (*)(s32))get_player_by_client_id)(cmd.client);
        if (p != NULL) {
            TObjPlayer__sub_801BEEE0(p + 0x858, cmd.data);
            ((TObjPlayer *)p)->reset_on_death();
            if (is_in_tl03_state__10TObjPlayerFv(p) != 0) {
                ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(p, 0xF, 0);
            }
        }
    }
}

void TObjPlayer::prepare_death() {
    u8 *arg0 = (u8 *)this;
    Cmd_801CA7BC c1;
    Cmd2_801CA7BC c2;
    if (is_locally_controlled__10TObjPlayerFPv(arg0) != 0) {
        TObjPlayer__sub_8024ABDC((void *)(u16)((s32 (*)(void *))get_entity_id)(arg0));
        *(s32 *)(arg0 + 0x36C) = 0;
        *(s32 *)(arg0 + 0x548) = 0;
        ((FlagWord *)(arg0 + 0x858))->clear(4);
        if (((TObjPlayer *)arg0)->find_revival_item() == 0) {
            ((FlagWord *)(arg0 + 0x858))->set(2);
        }
    }
    if (test_flags_any((u8 *)&this->m_858, 1) == 0) {
        ((TObjPlayer *)arg0)->drop_items_on_death();
    }
    if (is_flag_400_set__10TObjPlayerFPv(arg0) != 0) {
        enable_action_input__10TObjPlayerFPv(arg0);
    }
    if (*(void **)(arg0 + 0x424) != NULL && ((TMainCursor *)(*(void **)(arg0 + 0x424)))->is_cursor_clear() == 0) {
        ((TObjPlayer *)(*(void **)(arg0 + 0x424)))->clear_flag_1_at_1c();
    }
    if (arg0 == NULL || obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0) {
        ((TObjPlayer *)(&c1))->init_6x89_packet();
        c1.client = ((s32 (*)(void *))get_entity_id)(arg0);
        c1.val = get_field_2d4__10TObjPlayerFv(arg0);
        ((TObjPlayer *)(&c1))->update_and_send3();
        ((TObjPlayer *)(&c2))->init_6x4D_packet();
        c2.client = ((s32 (*)(void *))get_entity_id)(arg0);
        TObjPlayer__sub_801BEEE0(c2.data, (u8 *)&this->m_858);
        ((TObjPlayer *)(&c2))->init_and_send();
    }
}

void TObjPlayer::set_death_marker_pos() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)(this->bodies) + 0x1C) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)(this->bodies) + 0x20) = (f32) (lbl_805DC388 + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)(this->bodies) + 0x24) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    obj_setFlags30(arg0, 0x800U);
}

void TObjPlayer::request_revival_if_not_dead() {
    u8 *arg0 = (u8 *)this;
    if (((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x800) == 0) {
        ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *) (arg0), 0x12, 5);
    }
}

void TObjPlayer::check_reopen_return_city_window() {
    u8 *arg0 = (u8 *)this;
  unsigned short new_var;
  u32 temp_r3;
  new_var = (s32) ((s32 (*)(void *))get_entity_id)((void *) arg0);
  TObjPlayer__sub_8024ABDC((void *) new_var);
  temp_r3 = this->m_36c;
  new_var = 0U;
  if ((temp_r3 != new_var) && ((((TObject *)temp_r3)->all_parents_unqueued_for_destruction() == 0) || (check_value_equals__13TUnk_804B6C24Fl((int) (this->m_36c), (void *) TWindowReturnCity__class_name) == 0)))
  {
    this->m_36c = 0U;
  }
  if (((((((TObjPlayer *)(arg0 + 0x550))->check_action_usable(4) != 0) && (is_camera_mode_active__10TObjPlayerFv() == 0)) && (is_technique_ready__8TTecCtrlFv() == 0)) && ((check_camera_mode__10TObjPlayerFv() == 0) || ((check_camera_mode__10TObjPlayerFv() != 0) && (get_main_phase() == 0xF)))) && (check_flag_100__10TObjPlayerFPv((void *) arg0) == 0))
  {
    ((TObjPlayer *)arg0)->create_return_city_window();
  }
}

void TObjPlayer__sub_801CAA58(void) {  }

void run_death_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void))TObjPlayer__sub_801CAA58)();
        return;
      case 2:
        ((TObjPlayer *)arg0)->check_reopen_return_city_window();
        return;
      case 3:
        ((TObjPlayer *)arg0)->request_revival_if_not_dead();
        return;
      case 8:
        ((TObjPlayer *)arg0)->set_death_marker_pos();
        return;
      case 5:
        ((TObjPlayer *)arg0)->prepare_death();
        return;
      case 0:
        ((TObjPlayer *)arg0)->enter_death_state();
        return;
      case 1:
        ((TObjPlayer *)arg0)->update_death_pose();
        return;
      case 6:
        ((TObjPlayer *)arg0)->exit_death_state();
        break;
    }
  }
}

int TObjPlayer::exit_fall_reaction(void* p) { return ((int (*)(void*))TObjPlayer__sub_8001053C)(p); }

void TObjPlayer::update_fall_reaction() {
    f32 temp_f1;
    switch (this->phase) {
    case 0:
        if (((s32 (*)(f32))objInBand__FP7GameObjf)(lbl_805DC370) != 0) {
            if (classify_action_state__10TObjPlayerFv(this) == 2) {
                this->play_sound_if_on_floor(0x40002320);
            } else {
                this->play_sound_if_on_floor(0x40009E14);
            }
        }
        if (this->animationFlags & 0x10) {
            this->phase = 1;
            this->m_2b4 = (f32) lbl_805DC38C;
        }
        break;
    case 1:
        temp_f1 = this->m_2b4 - TObjPlayer__data_805DC360;
        this->m_2b4 = temp_f1;
        if (temp_f1 < TObjPlayer__data_805DC36C) {
            this->phase = 2;
            this->m_b8 = ((s16 (*)(void))query_child_state2__10TObjPlayerFPv)();
        }
        break;
    case 2:
        break;
    }
    ((s32 (*)(void *))damp_planar_velocity)(this);
    if (check_actor_blocking_move() != 0) {
        TObjPlayer__sub_8001053C(this);
    }
    if (resolve_move_collision__10TObjPlayerFv(this) == 0U) {
        apply_velocity();
    }
}

void start_action_0e__10TObjPlayerFPv(u8 *arg0) {
    s32 sp8;

    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&sp8, arg0 + 0x308);
    *(s32 *)((s8 *)arg0 + 0x33C) = 0xE;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 6);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x308, &sp8);
    set_type__10TObjPlayerFl(arg0 + 0x644, 0x12C);
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)0x10000);
    ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x4000AD13);
    if (obj_isState2_324__13TUnk_804806E8Fv(arg0) != 0) {
        trigger_switch_attack__10TObjPlayerFPvi(arg0, ((VObj_801cac08 *)arg0)->m7());
    }
    ((TObjPlayer *)arg0)->phase = 0;
    set_action_state__10TObjPlayerFPvss(arg0, 0xE, ((s32 (*)(void *))get_action_animation__10TObjPlayerFv)(arg0));
}

void handle_6x4C_hit_by_enemy(void *arg0) {
    Msg_801CACD8 m;
    Player_801CACD8 *p;

    ((TObjPlayer *)(&m))->bswap_head_pair();
    ((void (*)(void *, void *))copy_6x4c_hit_by_enemy_packet__10TObjPlayerFPvPv)(&m, arg0);
    ((TObjPlayer *)(&m))->init_6x4C_packet();
    if (validate_6x4C_hit_by_enemy(&m) != 0) {
        p = ((Player_801CACD8 * (*)(s32))get_player_by_client_id)(m.id);
        if (p != NULL && test_action_mask__10TObjPlayerFl(p, 0x8000) == 0) {
            ((TObjPlayer *)p)->set_hp_clamped(m.kind);
            if (is_in_tl03_state__10TObjPlayerFv(p) != 0 && reset_volopt_state__10TObjPlayerFv(p) != 0) {
                p->ang = m.ang;
                p->x = m.x;
                p->z = m.z;
                ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0xE, 0);
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
    z = this->m_310;
    x = *(f32 *)((s8 *)this + 0x308);
    if (newton_sqrtf(x * x + z * z) > lbl_805DC390) {
        this->rotation_y = (s32) ((s32) (lbl_80447148 * atan2_float(x, z)) + 0x8000);
    }
    if (((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(this, 0x800) != 0) {
        drop_items_on_death();
    }
    TObjPlayer::spawn_effect((s32)this);
    if ((this == NULL) || (obj_isState2_324__13TUnk_804806E8Fv(this) == 0)) {
        ((TObjPlayer *)(&pkt))->init_6x4C_packet();
        pkt.id = get_entity_id(this);
        pkt.dir = (s16) this->rotation_y;
        pkt.f6 = this->hp;
        pkt.x = x;
        pkt.z = z;
        ((TObjPlayer *)(&pkt))->send_head_pair_packet();
    }
}
extern int fold_flush_2;
#pragma pop

void TObjPlayer__sub_801CAEAC(void) {  }

void TObjPlayer::complete_fall_reaction() {
    u8 *arg0 = (u8 *)this;
    switch (this->phase) {
    case 1:
        if (((s16) this->m_b8 == ((s16 (*)(void))get_action_animation__10TObjPlayerFv)()) && (this->animationFlags & 0x10) && (((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)((void *) (arg0), 0x800) != 0)) {
            ((FlagWord *)(arg0 + 0x858))->set(1);
            ((int (*)(void*, void*, void*))run_action_state_phase__10TObjPlayerFisi)((void*)((void *) (arg0)), (void*)(0xF), (void*)(5));
        }
        break;
    case 2:
        if (this->animationFlags & 0x10) {
            ((s32 (*)(void *, int))set_type__10TObjPlayerFl)((void *) (arg0 + 0x644), (int) (((s32 (*)(void))get_getup_protection_ticks__10TObjPlayerFv)()));
            ((s32 (*)(void *))update_position_from_target__10TObjPlayerFv)((void *) (arg0));
        }
        break;
    }
}

void TObjPlayer__sub_801CAF6C(void) {  }

void TObjPlayer::check_and_trigger_19_5() { if (check_flag30_bit20__10TObjPlayerFi(this) != 0) { ((int (*)(void*, void*, void*))run_action_state_phase__10TObjPlayerFisi)(this, (void*)19, (void*)5); } }

void run_fall_reaction_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  void *new_var;
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->check_and_trigger_19_5();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801CAF6C)();
        return;
      case 3:
        ((TObjPlayer *)(new_var = (void *) arg0))->complete_fall_reaction();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CAEAC)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->begin_fall_reaction();
        return;
      new_var = (void *) arg0;
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

void TObjPlayer::set_flag_100000() { ((int (*)(void*))TObjPlayer__sub_8001053C)((void*)(this)); ((int (*)(void*, void*))obj_setFlags30)(this, (void*)1048576); }

void TObjPlayer::update_move_state() {
    s32 arg0 = (s32)this;
    damp_planar_velocity();
    if (((TObjPlayer *)arg0)->check_actor_blocking_move() != 0) {
        ((int (*)(void*))TObjPlayer__sub_8001053C)((void*)(arg0));
    }
    if (((u32 (*)(s32))resolve_move_collision__10TObjPlayerFv)(arg0) == 0U) {
        ((TObjPlayer *)arg0)->apply_velocity();
    }
}

void end_freeze_action__10TObjPlayerFPv(u8 *arg0) {
    s32 sp8;

    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&sp8, arg0 + 0x308);
    *(s32 *)((s8 *)arg0 + 0x33C) = 0xD;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 6);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x308, &sp8);
    if (is_technique_ready__8TTecCtrlFv() != 0) {
        set_type__10TObjPlayerFl(arg0 + 0x644, 0x1E);
    } else {
        set_type__10TObjPlayerFl(arg0 + 0x644, get_hurt_protection_ticks__10TObjPlayerFv(arg0));
    }
    ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x4000AD12);
    if (obj_isState2_324__13TUnk_804806E8Fv(arg0) != 0) {
        trigger_switch_attack__10TObjPlayerFPvi(arg0, ((VObj_801cb0c4 *)arg0)->m7());
    }
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)0x10000);
    set_action_state__10TObjPlayerFPvss(arg0, 0xD, call_model_m24__10TObjPlayerFv(arg0));
}

void handle_6x4B_hit_by_enemy(void *arg0) {
    Msg_801CB1B0 m;
    Player_801CB1B0 *p;

    ((TObjPlayer *)(&m))->read_swapped_fields();
    ((void (*)(void *, void *))copy_6x4b_hit_by_enemy_packet__10TObjPlayerFPvPv)(&m, arg0);
    ((TObjPlayer *)(&m))->reset_action_state();
    if (validate_6x4B_hit_by_enemy(&m) != 0) {
        p = ((Player_801CB1B0 * (*)(s32))get_player_by_client_id)(m.id);
        if (p != NULL && test_action_mask__10TObjPlayerFl(p, 0x8000) == 0) {
            ((TObjPlayer *)p)->set_hp_clamped(m.kind);
            if (is_in_tl03_state__10TObjPlayerFv(p) != 0 && reset_volopt_state__10TObjPlayerFv(p) != 0) {
                p->ang = m.ang;
                p->x = m.x;
                p->z = m.z;
                ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0xD, 0);
            }
        }
    }
}

void TObjPlayer::send_6x4B_hurt_reaction() {
    u8 *arg0 = (u8 *)this;
    struct Pkt_801CB27C pkt;
    if (arg0 == NULL || ((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0) {
        ((TObjPlayer *)(&pkt))->reset_action_state();
        pkt.id = get_entity_id(arg0);
        pkt.a = *(s32 *)(arg0 + 0x60);
        pkt.b = *(s16 *)(arg0 + 0x32C);
        pkt.x = *(f32 *)(arg0 + 0x308);
        pkt.z = *(f32 *)(arg0 + 0x310);
        ((TObjPlayer *)(&pkt))->handle_recv_state();
    }
}

void TObjPlayer__sub_801CB2F0(void) {  }

void TObjPlayer::complete_hurt_reaction() {
    u8 *arg0 = (u8 *)this;
    if (this->animationFlags & 0x10) {
        if (((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x800) != 0) {
            ((FlagWord *)(arg0 + 0x858))->clear(1);
            ((int (*)(void*, void*, void*))run_action_state_phase__10TObjPlayerFisi)((void*)((void *) (arg0)), (void*)(0xF), (void*)(5));
            return;
        }
        ((s32 (*)(void *))update_position_from_target__10TObjPlayerFv)((void *) (arg0));
    }
}

void TObjPlayer__sub_801CB360(void) {  }

void TObjPlayer::do_action_19_5_if_flag30() { if (check_flag30_bit20__10TObjPlayerFi(this) != 0) { ((int (*)(void*, void*, void*))run_action_state_phase__10TObjPlayerFisi)(this, (void*)19, (void*)5); } }

void run_hurt_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->do_action_19_5_if_flag30();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801CB360)();
        return;
      case 3:
        ((TObjPlayer *)arg0)->complete_hurt_reaction();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CB2F0)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_6x4B_hurt_reaction();
        return;
      case 0:
        ((s32 (*)(void *))end_freeze_action__10TObjPlayerFPv)((void *) arg0);
        return;
      case 1:
        ((TObjPlayer *)arg0)->update_move_state();
        return;
      case 6:
        ((TObjPlayer *)arg0)->set_flag_100000();
        break;
    }
  }
}

void TObjPlayer__sub_801CB424(void) {  }

void TObjPlayer__sub_801CB428(s32 arg0) {
    if (((u32 (*)(void))resolve_move_collision__10TObjPlayerFv)() == 0U) {
        ((TObjPlayer *)arg0)->apply_velocity();
    }
}

void TObjPlayer::begin_action_0xB() {
    *(s32 *)((s8 *)this + 0x33C) = 0xB;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(this, this->mode, 6);
    if (obj_isState2_324__13TUnk_804806E8Fv(this) != 0) {
        this->m_ba = ((s16 (*)(void))ret_801D26AC)();
    }
    set_action_state__10TObjPlayerFPvss(this, 0xB, call_obj_vt26__10TObjPlayerFv(this));
}

void TObjPlayer__sub_801CB4D0(u8 *arg0) {
    struct Pkt_801CB4D0 pkt;
    if (arg0 == NULL || obj_isState2_324__13TUnk_804806E8Fv((void *)(arg0)) == 0) {
        ((void (*)(void *))TObjPlayer__sub_801D1BB0)(&pkt);
        pkt.id = get_entity_id(arg0);
        pkt.c = *(s32 *)(arg0 + 0x60);
        ((TObjPlayer *)(&pkt))->refresh_players();
    }
}

void TObjPlayer__sub_801CB52C(void) {  }

void TObjPlayer::run_if_flag_10() {
    if (this->animationFlags & 0x10) {
        ((s32 (*)(void))update_position_from_target__10TObjPlayerFv)();
    }
}

void TObjPlayer__sub_801CB55C(void) {  }

int TObjPlayer::try_apply_status_action() { return try_apply_status_action__10TObjPlayerFi(this); }

void TObjPlayer__sub_801CB580(s32 arg0, s16 arg1) {
  void *new_var;
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->try_apply_status_action();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801CB55C)();
        return;
      case 3:
        ((TObjPlayer *)arg0)->run_if_flag_10();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CB52C)();
        return;
      case 5:
        new_var = (void *) arg0;
        ((s32 (*)(void *))TObjPlayer__sub_801CB4D0)(new_var);
        return;
      case 0:
        ((TObjPlayer *)arg0)->begin_action_0xB();
        return;
      case 1:
        arg0 = arg0;
        ((s32 (*)(void *))TObjPlayer__sub_801CB428)((void *) arg0);
        return;
      case 6:
        ((s32 (*)(void))TObjPlayer__sub_801CB424)();
        break;
    }
  }
}

void TObjPlayer__sub_801CB5FC(void) {  }

void TObjPlayer::apply_velocity_if_ready(s32 arg0) {
    if (((u32 (*)(void))resolve_move_collision__10TObjPlayerFv)() == 0U) {
        ((TObjPlayer *)arg0)->apply_velocity();
    }
}

void TObjPlayer::start_action_c() {
    *(s32 *)((s8 *)this + 0x33C) = 0xC;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(this, this->mode, 6);
    if (obj_isState2_324__13TUnk_804806E8Fv(this) != 0) {
        this->m_ba = ((s16 (*)(void))ret_801D26AC)();
    }
    set_action_state__10TObjPlayerFPvss(this, 0xC, get_weapon_stat_c__10TObjPlayerFv(this));
}

void handle_6x50_switch_interaction(const void *source) {
    struct SwitchActionMessage_801CB6A8 packet;
    ((void (*)(void *))TObjPlayer__sub_801D1C70)(&packet);
    ((void (*)(void *, const void *))copy_font__10TObjPlayerFPvPv)(&packet, source);
    ((TObjPlayer *)(&packet))->bswap_field4();
    if (validate_6x50_switch_interaction(&packet)) {
        u8 *player = get_player_by_client_id(packet.actor);
        if (player && ((s32 (*)(void))is_in_tl03_state__10TObjPlayerFv)() && !((s32 (*)(u8 *, u32))test_action_mask__10TObjPlayerFl)(player, 0x8200)) {
            *(s32 *)(player + 0x60) = packet.yaw;
            ((void (*)(u8 *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(player, 12, 0);
        }
    }
}

void TObjPlayer::send_6x50_switch_interaction() {
    u8 *arg0 = (u8 *)this;
    Ctx_801CB748 ctx;
    if ((arg0 == NULL) || (((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        ((s32 (*)(Ctx_801CB748 *))TObjPlayer__sub_801D1C70)(&ctx);
        ctx.f2 = get_entity_id(arg0);
        ctx.f4 = this->rotation_y;
        ((TObjPlayer *)(&ctx))->sync_players();
    }
}

void TObjPlayer__sub_801CB7A4(void) {  }

void TObjPlayer::update_if_flag_set() {
    if (this->animationFlags & 0x10) {
        ((s32 (*)(void))update_position_from_target__10TObjPlayerFv)();
    }
}

void TObjPlayer__sub_801CB7D4(void) {  }

int TObjPlayer__sub_801CB7D8(void* p) { return try_apply_status_action__10TObjPlayerFi(p); }

void run_switch_interaction_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void *))TObjPlayer__sub_801CB7D8)((void *) arg0);
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801CB7D4)();
        return;
      case 3:
        ((TObjPlayer *)arg0)->update_if_flag_set();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CB7A4)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_6x50_switch_interaction();
        return;
      case 0:
        ((TObjPlayer *)arg0)->start_action_c();
        return;
      case 1:
        TObjPlayer::apply_velocity_if_ready(arg0);
        return;
      case 6:
        ((s32 (*)(void))TObjPlayer__sub_801CB5FC)();
        break;
    }
  }
}

s32 can_guard__10TObjPlayerFPv(u8 *arg0) {
    if ((((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x100) != 0) && (((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x04000000) == 0)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::set_flag_0x100000(void* p) { ((int (*)(void*))TObjPlayer__sub_8001053C)(p); ((int (*)(void*, void*))obj_setFlags30)(p, (void*)1048576); }

void TObjPlayer::apply_velocity_if_free(s32 arg0) {
    damp_planar_velocity();
    if (((u32 (*)(s32))resolve_move_collision__10TObjPlayerFv)(arg0) == 0U) {
        ((TObjPlayer *)arg0)->apply_velocity();
    }
}

void start_use_item_action__10TObjPlayerFPv(u8 *arg0) {
    s32 sp8;

    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&sp8, arg0 + 0x308);
    *(s32 *)((s8 *)arg0 + 0x33C) = 0xA;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, ((TObjPlayer *)arg0)->mode, 6);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x308, &sp8);
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)0x10000);
    ((TObjPlayer *)arg0)->use_current_item();
    if (obj_isState2_324__13TUnk_804806E8Fv(arg0) != 0) {
        ((TObjPlayer *)arg0)->m_ba = ((s16 (*)(void))ret_801D26AC)();
    }
    set_action_state__10TObjPlayerFPvss(arg0, 0xA, query_child_state__10TObjPlayerFv(arg0));
}

typedef struct Msg_801CB9E4 {
    u8 pad0[2];
    u16 id;
    u8 pad4[4];
} Msg_801CB9E4;
s32 validate_6x4A_shield_attack(void *);
void* shield_attack__10TObjPlayerFPv(void* p);

void handle_6x4A_shield_attack(void *arg0) {
    Msg_801CB9E4 m;
    u8 *p;

    ((TObjPlayer *)(&m))->init_shield_attack_packet();
    ((void (*)(void *, void *))shield_attack__10TObjPlayerFPv)(&m, arg0);
    TFontSmallLobby__sub_801C01BC(&m);
    if (validate_6x4A_shield_attack(&m) != 0) {
        p = get_player_by_client_id(m.id);
        if (p != NULL && is_in_tl03_state__10TObjPlayerFv(p) != 0 && reset_volopt_state__10TObjPlayerFv(p) != 0 &&
            test_action_mask__10TObjPlayerFl(p, 0x8000) == 0) {
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 0xA, 0);
        }
    }
}

void* shield_attack__10TObjPlayerFPv(void* p) { TFontSmallLobby__sub_801C0228(p); return p; }

void send_object_id_packet__10TObjPlayerFi(s32 arg0) {
    s8 sp8[8];

    if ((arg0 == 0) || (((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        ((TObjPlayer *)((s32 *)&sp8))->init_shield_attack_packet();
        *(s16 *)((s8 *)(&sp8) + 2) = ((s16 (*)(s32))get_entity_id)(arg0);
        ((TObjPlayer *)((s32 *)&sp8))->draw_font_and_send();
    }
}

void TObjPlayer__sub_801CBB10(void) {  }

void TObjPlayer::complete_guard_reaction() {
    u8 *arg0 = (u8 *)this;
    if (this->animationFlags & 0x10) {
        if (obj_testFlags30__13TUnk_804AF8A0FUl((s32)(arg0), 0x800) != 0) {
            ((FlagWord *)(arg0 + 0x858))->clear(1);
            ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)((s32)((void *) (arg0)), 0xF, 5);
            return;
        }
        ((s32 (*)(void *))update_position_from_target__10TObjPlayerFv)((void *) (arg0));
    }
}

void TObjPlayer__sub_801CBB80(void) {  }

void TObjPlayer::select_hit_action(s32 arg0) {
    if (((s32 (*)(void))check_flag30_bit20__10TObjPlayerFi)() != 0) {
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0x13, 5);
        return;
    }
    if (((s32 (*)(s32))is_status_flag_200__10TObjPlayerFv)(arg0) != 0) {
        if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x400) != 0) {
            ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xE, 5);
            return;
        }
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 0xD, 5);
    }
}

void run_guard_reaction_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        TObjPlayer::select_hit_action(arg0);
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801CBB80)();
        return;
      case 3:
        ((TObjPlayer *)arg0)->complete_guard_reaction();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CBB10)();
        return;
      case 5:
        ((s32 (*)(void *))send_object_id_packet__10TObjPlayerFi)((void *) arg0);
        return;
      case 0:
        ((s32 (*)(void *))start_use_item_action__10TObjPlayerFPv)((void *) arg0);
        if (arg0 && arg0)
      {
      }
        return;
      case 1:
        TObjPlayer::apply_velocity_if_free(arg0);
        return;
      case 6:
        TObjPlayer::set_flag_0x100000((void *) arg0);
        break;
    }
  }
}

void TObjPlayer::create_photon_blast_party_effects(s32 arg0) {
    if ((void *) TObjPlayer__shared_photon_blast_state != NULL) {
        ((TObjPlayer *)TObjPlayer__shared_photon_blast_state)->create_party_effects(arg0);
    }
}

u8 *TObjPlayer::find_photon_blast_by_section_id(s32 arg0) {
    if ((void *) TObjPlayer__shared_photon_blast_state != NULL) {
        return find_by_section_id__10TObjPlayerFl(TObjPlayer__shared_photon_blast_state, arg0);
    }
    return NULL;
}

s32 TObjPlayer::get_current_target_id() {
    if ((u32) (*(u32 *)&TObjPlayer__shared_photon_blast_state) != 0U) {
        return find_first_valid_target_id__10TObjPlayerFv((void*)(*(u32 *)&TObjPlayer__shared_photon_blast_state));
    }
    return 0xFFFF;
}
}

void remove_photon_blast_participant(s32 id) {
    if ((void *) TObjPlayer__shared_photon_blast_state != NULL) {
        TObjPlayer__sub_80312E98(TObjPlayer__shared_photon_blast_state, id);
    }
}

void TObjPlayer::update_photon_blast_state() {
    if ((u32) (*(u32 *)&TObjPlayer__shared_photon_blast_state) != 0U) {
        ((TObjPlayer *)(*(u32 *)&TObjPlayer__shared_photon_blast_state))->process_all_elements();
    }
}

u8 *TObjPlayer::get_photon_blast_element(s32 arg0) {
    if ((void *) TObjPlayer__shared_photon_blast_state != NULL) {
        return ((u8 * (*)(void *, int))get_element__10TObjPlayerFPvi)(TObjPlayer__shared_photon_blast_state, arg0);
    }
    return NULL;
}

void TObjPlayer::apply_photon_blast(s32 arg0, s32 arg1) {
    if ((u32) (*(u32 *)&TObjPlayer__shared_photon_blast_state) != 0U) {
        append_photon_blast_request((*(u32 *)&TObjPlayer__shared_photon_blast_state), arg0, arg1);
    }
}

void update_active_instance__10TObjPlayerFi(s32 arg0) {
    if ((u32) (*(u32 *)&TObjPlayer__shared_photon_blast_state) != 0U) {
        if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() == 0) {
            ((TObjPlayer *)(*(u32 *)&TObjPlayer__shared_photon_blast_state))->process_all_elements();
            return;
        }
        release_photon_blast_requests((void *)(*(u32 *)&TObjPlayer__shared_photon_blast_state));
        admit_photon_blast_sequence((TObjPlayer::get_photon_blast_element(0)), (void *)arg0);
    }
}

void TObjPlayer::vfunc_75(f32 farg0) {
    s32 arg0 = (s32)this;
    if (((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() == 0 || obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x800) != 0 ||
        activate_d04_slot__10TObjPlayerFv(arg0) == 0 || ((s32 (*)(s32, s32))is_alt_photon_blast_bank_empty__10TObjPlayerFPv)(arg0 + 0x500, 1) != 0 ||
        are_items_enabled_here() == 0) {
        return;
    }
    add_photon_blast_charge((u8 *)(arg0 + 0x4AC), farg0);
}

f32 TObjPlayer::calc_photon_blast_charge(void *arg0, s32 arg1) {
    return (f32) arg1 / (lbl_805DC394 * (TObjPlayer__data_805DC360 + (f32) clamp_nested_index__10TObjPlayerFv()));
}

void release_all_players_control_lock(void) {
    for_each_player_slot__10TObjPlayerFv((s32 *)release_control_lock__10TObjPlayerFPv);
}

void release_photon_blast_player_holds(u16 *p) {
    s32 i;
    u32 obj;
    if (p != NULL) {
        i = 0;
        while (*p != 0xFFFF) {
            u32 id = *p++;
            if (id >= 12) {
                break;
            }
            obj = ((u32 (*)(u32))get_player_by_client_id)(id);
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
        if (obj != NULL && ((s32 (*)(void *))is_on_current_floor__10TObjPlayerFi)(obj) != 0 && test_action_mask__10TObjPlayerFl(obj, 0x8000) == 0 &&
            (is_single_screen__10TObjPlayerFv() != 0 ||
             (is_single_screen__10TObjPlayerFv() == 0 && arg0 == ((TUnk_804B9870 *)obj)->get_stat_by_key_state()))) {
            TObjPlayer__sub_801D0F70(obj);
            if (arg1 != NULL) {
                *arg1 = ((u16 (*)(void *))get_entity_id)(obj);
                arg1++;
            }
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(obj, 0x13, 0);
        }
        i++;
        tbl++;
    } while (i < 4);
}
extern "C" {

void handle_6x36(void) {  }

void handle_6x37_photon_blast(s32 arg0) {
    struct Pkt_801CC0F4 pkt;
    u8 *temp_r3;
    ((void (*)(struct PbPacket37_801CC194 *))TObjPlayer__sub_801D1D88)((struct PbPacket37_801CC194 *)((void *) (&pkt)));
    ((s32 (*)(void *, void *))TObjPlayer__sub_801D1D44)((void *) (&pkt), (void *) (arg0));
    ((TObjPlayer *)(&pkt))->swap_endian16();
    if (validate_6x37_photon_blast((void *) (&pkt)) != 0) {
        temp_r3 = get_player_by_client_id(pkt.player);
        if ((temp_r3 != NULL) && (((s32 (*)(void))check_flag_4__10TObjPlayerFv)() == 0) && ((u32) *(u32 *)((s8 *)temp_r3 + 0x10) == (u32) tl_03) && (((s32 (*)(int))reset_volopt_state__10TObjPlayerFv)((int) (temp_r3)) != 0)) {
            ((TObjPlayer *)(temp_r3 + 0x4AC))->check_photon_blast_flag();
            ((TObjPlayer *)(temp_r3 + 0x4AC))->trigger_photon_blast();
        }
    }
}

void TObjPlayer::send_6x37_photon_blast() {
    struct PbPacket37_801CC194 packet;
    if (this == NULL || obj_isState2_324__13TUnk_804806E8Fv(this) == 0) {
        ((void (*)(struct PbPacket37_801CC194 *))TObjPlayer__sub_801D1D88)(&packet);
        packet.player = get_entity_id(this);
        packet.gauge = get_sub_value__8TItemMagFv(this);
        ((TObjPlayer *)(&packet))->update_and_send4();
    }
}

s32 TObjPlayer::check_conditions() {
    s32 arg0 = (s32)this;
    if ((obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x20006) != 0) || (((s32 (*)(s32, s32))test_action_mask__10TObjPlayerFl)(arg0, 0x11E) == 0) || (TObjPlayer__sub_801C1F50(arg0 + 0x4AC) == 0) || (((TObjPlayer *)(arg0 + 0x4AC))->check_flag_clear() == 0) || ((((s32 (*)(s32))is_locally_controlled__10TObjPlayerFPv)(arg0) != 0) && ((((s32 (*)(s32))check_flag_100__10TObjPlayerFPv)(arg0) != 0) || (((TObjPlayer *)arg0)->get_camera_field() == 0))) || (((s32 (*)(s32))reset_volopt_state__10TObjPlayerFv)(arg0) == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::exit_photon_blast_action() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;
    this->animationFlags &= ~0x40;
    ((s32 (*)(void *, int))sub_8011E204__10TObjPlayerFl)((void *) (arg0), 0x80);
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30((u32)(0x400000));
    temp_r4 = (unsigned char *) (*(void **)((s8 *)arg0 + 0x424));
    if (temp_r4 != NULL) {
        *(u16 *)((s8 *)temp_r4 + 0x508) = 0xFFFF;
    }
    reset_photon_blast_gauge((void *) (arg0 + 0x4AC));
    if (is_final_phase__10TObjPlayerFv() != 0) {
        ((s32 (*)(void *))get_entity_id)((void *) (arg0));
        ((s32 (*)(void))remove_photon_blast_participant)();
    } else {
        TObjPlayer::update_photon_blast_state();
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x33C) != 0x13) {
        ((TObjPlayer *)(arg0 + 0x644))->reset_lobby_model();
    }
}

void TObjPlayer::update_photon_blast_action() {
    u8 *arg0 = (u8 *)this;
  this->rotation_y = ((s32 (*)(int, int))lerp_angle_half__10TObjPlayerFUsUs)((int) (this->rotation_y), (int) (*((s32 *) (((s8 *) arg0) + 0x3F0))));
  switch (this->phase)
  {
    case 2:
    case 4:
      break;
    case 0:
      ((TObjPlayer *)arg0)->get_photon_blast_hold_frame();
      if (objInBand__FP7GameObjf((void *) arg0) != 0)
    {
      this->phase = 1;
      this->animationFlags = (s32) ((this->animationFlags) | 0x40);
      ((TObjPlayer *)(arg0 + 0x4AC))->set_field8((int) (*((s16 *) (((s8 *) TObjPlayer::get_photon_blast_entry(((TFontSmallLobby *)(arg0 + 0x4AC))->get_valid_index())) + 0x12))));
      ((TObjPlayer *)(arg0 + 0x4AC))->set_field_0c((f32) lbl_805DC398);
    }
      play_persistent_sound(0x4002A823, (s32)arg0, 0, 0, 0);
      break;
    case 1:
      this->m_c0 = (f32) ((this->m_c0) + TObjPlayer__sub_801D2A98((void *) (arg0 + 0x4AC)));
      if (TObjPlayer__sub_801D2A98((void *) (arg0 + 0x4AC)) > (*(f32 *)&TObjPlayer__data_805DC36C))
    {
      if ((this->m_c0) >= ((TObjPlayer *)arg0)->get_photon_blast_upper_bound())
      {
        ((TObjPlayer *)(arg0 + 0x4AC))->set_field_0c((f32) lbl_805DC398);
      }
    }
    else
      if ((this->m_c0) <= (((TObjPlayer *)arg0)->get_photon_blast_hold_frame() - (*(f32 *)&TObjPlayer__data_805DC360)))
    {
      if (1)
      {
        ((TObjPlayer *)(arg0 + 0x4AC))->set_field_0c((f32) (*(f32 *)&TObjPlayer__data_805DC39C));
      }
    }
      ((s32 (*)(void *))TObjPlayer__sub_801D2A88)((void *) (arg0 + 0x4AC));
      if (TObjPlayer__sub_801D2A80((void *) (arg0 + 0x4AC)) < 0)
    {
      this->phase = 2;
      this->animationFlags = (s32) ((this->animationFlags) & 0xFFFFFFBF);
      ((TObjPlayer *)arg0)->get_photon_blast_complete_threshold();
      ((s32 (*)(void *))TObjPlayer__sub_801D2A78)((void *) (arg0 + 0x4AC));
    }
      play_persistent_sound(0x4002A823, (s32)arg0, 0, 0, 0);
      break;
    case 3:
      if (((s32 (*)(void *))TObjPlayer__sub_801D2A50)((void *) (arg0 + 0x4AC)) != 0)
    {
      this->phase = 4;
      ((s32 (*)(void *, int))sub_8011E204__10TObjPlayerFl)((void *) arg0, 0x80);
      ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)((void *) arg0);
      ((s32 (*)(void *, void *))update_active_instance__10TObjPlayerFi)((void *) arg0, (void *) ((TFontSmallLobby *)(arg0 + 0x4AC))->get_valid_index());
    }
      break;
  }
  if (resolve_move_collision__10TObjPlayerFv((void *) arg0) == 0U)
  {
    ((TObjPlayer *)arg0)->apply_velocity();
  }
}

void TObjPlayer::enter_photon_blast_action() {
    Slot_801CC558 *slot;
    u16 id;
    Mylla_801CC558 *m;
    u8 *arg0 = (u8 *)this;
    *(s32 *)(arg0 + 0x33C) = 9;
    ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, *(s16 *)(arg0 + 0x326), 6);
    slot = (Slot_801CC558 *)((u32 * (*)(void *, s32))TObjPlayer__sub_801D2AB0)(arg0 + 0x4AC, 0);
    id = slot->id;
    if (id != 0xFFFF) {
        m = ((Mylla_801CC558 * (*)(u16))find_entity_by_id)(id);
        if (m == NULL) {
            slot->id = id = 0xFFFF;
        } else {
            ((s32 (*)(void *, void *))copy_position__10TObjPlayerFPv)(arg0 + 0x744, m->tbl + slot->idx * 0x2C + 0x1C);
        }
    }
    if (id == 0xFFFF) {
        *(s32 *)(arg0 + 0x3F0) = *(s32 *)(arg0 + 0x60);
    } else {
        slot = (Slot_801CC558 *)((TObjPlayer *)(arg0 + 0x744))->get_field4_ptr();
        *(s32 *)(arg0 + 0x3F0) = ((TObjPlayer *)(((TObjPlayer *)arg0)->get_position_ptr()))->calc_angle_to(slot);
    }
    ((s32 (*)(void *, s32))obj_setFlags30)(arg0, 0x400000);
    TObjPlayer__sub_8001053C(arg0);
    if (obj_isState2_324__13TUnk_804806E8Fv(arg0) != 0) {
        ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x22824);
    } else {
        ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x22322);
    }
    *(s16 *)(arg0 + 0x328) = 0;
    set_action_state__10TObjPlayerFPvss(arg0, 9, query_equip__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg0)->set_state_flags(0x80);
    TObjPlayer::start_photon_blast(((TFontSmallLobby *)(arg0 + 0x4AC))->get_valid_index(), ((s32 (*)(void *))get_entity_id)(arg0));
}

void handle_6x49_execute_photon_blast(void *arg0) {
    s32 i;
    Player_801CC6B8 *p;
    Msg_801CC6B8 m;
    ((TObjPlayer *)(&m))->init_6x49_packet();
    ((void (*)(void *, void *))copy_photon_blast_data__10TObjPlayerFiPv)(&m, arg0);
    ((TObjPlayer *)(&m))->byteswap_6x49_packet();
    if (((TObjEneHoldEffect *)(&m))->validate_6x49_packet() != 0) {
        p = ((Player_801CC6B8 * (*)(s32))get_player_by_client_id)(m.id);
        if (p != NULL && test_action_mask__10TObjPlayerFl(p, 0x8000) == 0 && are_items_enabled_here() != 0) {
            if (get_current_floor() == ((TObjPlayer *)p)->get_field_3e4()) {
                s32 count;
                u32 *dst;
                u32 *src;
                ((TObjPlayer *)(p->pb))->start_photon_blast_action();
                TObjPlayer::apply_photon_blast(m.id, m.kind);
                set_photon_blast_kind(p->pb, m.kind);
                count = m.count;
                ((TFontSmallLobby *)(p->pb))->set_section_index(count);
                ((TObjPlayer *)p)->set_float_param(m.param);
                dst = ((u32 * (*)(void *, s32))TObjPlayer__sub_801D2AB0)(p->pb, 0);
                src = m.techs;
                for (i = 0; i < count; i++) {
                    ((void (*)(u32 *, u32 *))copy_tech_params__10TObjPlayerFPvPv)(dst++, src++);
                }
                ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 9, 0);
            }
        }
    }
}

void copy_tech_params__10TObjPlayerFPvPv(void *arg0, void *arg1) {
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

void TObjPlayer::prepare_photon_blast_action() {
    Pkt_801CC7F8 pkt;
    s32 i;
    s16 n;
    s32 *src;
    s32 *dst;
    u8 *arg0 = (u8 *)this;
    if (((s32 (*)(void))reset_volopt_state__10TObjPlayerFv)() != 0) {
        ((s32 (*)(void *, int))set_type__10TObjPlayerFl)(arg0 + 0x644, 0x708);
        capture_technique_targets__10TObjPlayerFv((void *)((TFontSmallLobby *)(arg0 + 0x4AC))->get_valid_index(), arg0);
        if (this->m_424 != 0U) {
            u8 *e = ((u8 * (*)(void *, s32))TObjPlayer__sub_801D2AB0)(arg0 + 0x4AC, 0);
            ((TMainCursor *)(this->m_424))->set_cursor_pos(*(u16 *)((s8 *)e + 0), *(s16 *)((s8 *)e + 2));
        }
        if (arg0 == NULL || obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0) {
            ((TObjPlayer *)(&pkt))->init_6x49_packet();
            pkt.client = get_entity_id(arg0);
            pkt.index = ((TFontSmallLobby *)(arg0 + 0x4AC))->get_valid_index();
            pkt.count = n = ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_801D5DDC)(arg0 + 0x4AC);
            pkt.sub = get_sub_value__8TItemMagFv(arg0);
            src = (s32 *)((u8 * (*)(void *, s32))TObjPlayer__sub_801D2AB0)(arg0 + 0x4AC, 0);
            dst = pkt.tech;
            for (i = 0; i < n; i++) {
                ((s32 (*)(int, int))copy_tech_params__10TObjPlayerFPvPv)((int)dst++, (int)src++);
            }
            ((s32 (*)(void *))send_photon_blast_targets_packet)(&pkt);
        }
    }
}

void TObjPlayer::update_band_state() {
    u8 *arg0 = (u8 *)this;
    if ((s16) this->phase == 2) {
        ((TObjPlayer *)(arg0 + 0x4AC))->get_dist();
        if (objInBand__FP7GameObjf((void *) (arg0)) != 0) {
            this->phase = 3;
            set_action_flag_40();
        }
    }
}

void TObjPlayer::update_target_approach() {
    u8 *arg0 = (u8 *)this;
    if (this->animationFlags & 0x10) {
        ((s32 (*)(void))update_position_from_target__10TObjPlayerFv)();
        return;
    }
    if ((s16) this->phase == 2) {
        ((TObjPlayer *)(arg0 + 0x4AC))->get_dist();
        if (objInBand__FP7GameObjf((void *) (arg0)) != 0) {
            this->phase = 3;
            set_action_flag_40();
            send_6x37_photon_blast();
        }
    }
}

void TObjPlayer__sub_801CC9E4(void) {  }

int TObjPlayer::try_apply_status_action_default() { return try_apply_status_action__10TObjPlayerFi(this); }

void dispatch_photon_blast_action__10TObjPlayerFis(s32 arg0, s16 arg1) {
  s32 *new_var;
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->try_apply_status_action_default();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801CC9E4)();
        return;
      case 3:
        ((TObjPlayer *)arg0)->update_target_approach();
        arg0 = arg0;
        if (1)
      {
      }
        return;
      case 8:
        ((TObjPlayer *)arg0)->update_band_state();
        return;
      case 5:
        ((TObjPlayer *)(*(new_var = &arg0)))->prepare_photon_blast_action();
        return;
      case 0:
        ((TObjPlayer *)arg0)->enter_photon_blast_action();
        return;
      case 1:
        ((TObjPlayer *)arg0)->update_photon_blast_action();
        return;
      case 6:
        ((TObjPlayer *)arg0)->exit_photon_blast_action();
        break;
    }
  }
}

void handle_6x33_revive_player(void *arg0) {
    Msg_801CCA84 m;
    Tech_801CCA84 t;
    Player_801CCA84 *p;
    Player_801CCA84 *q;
    ((TObjPlayer *)(&m))->init_6x33_packet();
    ((void (*)(void *, void *))TObjPlayer__sub_801D2058)(&m, arg0);
    ((TObjPlayer *)(&m))->bswap_coords();
    if (validate_6x33_revive_player(&m) != 0) {
        p = (Player_801CCA84 *)get_player_by_client_id(m.id);
        if (p != NULL) {
            q = (Player_801CCA84 *)get_player_by_client_id(m.target);
            if (q != NULL && check_flag_4__10TObjPlayerFv(q) == 0 && q->list == tl_03) {
                ((TObjPlayer *)(&t))->construct_target_cursor_records();
                t.kind = 1;
                t.target = m.target;
                t.f6 = 0;
                t.f8 = lbl_805DC370;
                TTecReverser::create((void *)p, (void *)(((TObjPlayer *)p)->get_position_ptr()), (void *)(&t), (void *)0x1D);
            }
        }
    }
}

void send_6x33_revive_player(s32 arg0, s16 arg1) {
    struct Pkt_801CCB58 pkt;
    if (get_player_by_client_id(arg0) == NULL || ((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0) {
        ((TObjPlayer *)(&pkt))->init_6x33_packet();
        pkt.id = arg0;
        pkt.c = arg1;
        ((TObjPlayer *)(&pkt))->send_coords();
    }
}

void clamp_and_set_unit_value__10TObjPlayerFiUci(s32 arg0, u8 arg1, s32 i) {
    if (obj_isState3_324__13TUnk_804806E8Fv() != 0 && is_invalid_slot__10TObjPlayerFUc(arg1) == 0 &&
        arg1 > (u8)TObjPlayer__sub_801C010C(arg0 + 0x428, i)) {
        arg1 = TObjPlayer__sub_801C010C(arg0 + 0x428, i);
    }
    set_technique_level_entry(arg0 + 0x428, i, arg1);
}

void TObjPlayer::update_cursor(s32 parameter) {
    u32 temp_r3;

    temp_r3 = this->m_424;
    if ((temp_r3 != 0U) && (canSetMenuCursorAction(temp_r3 + 0x520, this, 3, (u8) parameter) != 0)) {
        ((TWindowActionPalette *)(this->m_424 + 0x520))->set_mode(3);
        ((TWindowActionPalette *)(this->m_424 + 0x520))->set_slot((u8) parameter);
        TMainCursor__sub_8013DFC4((u8 *)(this->m_424 + 0x520));
    }
}

s32 try_equip_item__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (((s32 (*)(s32, s32))test_action_mask__10TObjPlayerFl)(arg0, 0x100) == 0) {
        if (((s32 (*)(s32, s16))can_equip_item__10TObjPlayerFii)(arg0, arg1) == 0) {
            return 0;
        }
        set_technique_id__10TObjPlayerFs(arg0 + 0x428, arg1);
        ((TObjPlayer *)arg0)->request_technique_cast();
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
        ((TObjPlayer *)(p->techs))->set_technique_state(((Rec_801CCD38 *)calc_technique_parameters(t, lvl, ((s32 (*)(void *))get_entity_id)(p)))->state);
        p->f328 = 4;
        launch_technique__10TObjPlayerFv(t, lvl, p);
        return;
    }
    if (check_flag_4__10TObjPlayerFv(p) == 0 && p->f10 == tl_03) {
        ((TObjPlayer *)(p->techs))->set_technique_state(((Rec_801CCD38 *)calc_technique_parameters(t, lvl, ((s32 (*)(void *))get_entity_id)(p)))->state);
        p->f328 = 4;
        launch_technique__10TObjPlayerFv(t, lvl, p);
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
    if (validate_6x48_cast_technique_complete(&pkt) == 0) {
        return;
    }
    p = ((Player_801CCD38 * (*)(u16))get_player_by_client_id)(pkt.id);
    if (p == NULL) {
        return;
    }
    if (reset_volopt_state__10TObjPlayerFv(p) == 0) {
        return;
    }
    tech = pkt.tech;
    ((void (*)(void *, s16))set_technique_id__10TObjPlayerFs)(p->techs, tech);
    lvl = pkt.level;
    if (lvl == 0xE) {
        lvl += ((TObjPlayer *)(p->techs))->get_valid_technique();
    }
    if (((s32 (*)(void *, s16, u8))check_technique_level__10TObjPlayerFllUc)(p->techs, tech, (u8)lvl) == 0) {
        lvl = 0;
    }
    ul = lvl;
    ((TObjPlayer *)(p->techs))->set_technique_id(ul);
    ((void (*)(void *, u8, s16))clamp_and_set_unit_value__10TObjPlayerFiUci)(p, ul, tech);
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
        if (self == 0 || obj_isState2_324__13TUnk_804806E8Fv(self) == 0) {
            Pkt_801CCEDC pkt;
            this->phase = 4;
            tech = ((TObjPlayer *)(self->techs))->get_or_init_field_4();
            *(s16 *)&this->tp -= calc_technique_parameters(tech, ((TObjPlayer *)(self->techs))->get_castable_technique_level(), ((s32 (*)(void *))get_entity_id)(self))->cost;
            if (*(s16 *)&this->tp < 0) {
                *(s16 *)&this->tp = 0;
            }
            split_capped_value__10TObjPlayerFUcPUcPSc(((TObjPlayer *)(self->techs))->get_castable_technique_level(), &hi, &lo);
            ((void (*)(void *))init_6x48_cast_complete_packet)(&pkt);
            pkt.id = ((s32 (*)(void *))get_entity_id)(self);
            pkt.tech = tech;
            pkt.level = hi;
            ((TObjPlayer *)(&pkt))->send_swapped_header();
        }
    }
}

s32 TObjPlayer::try_camera_action(s32 arg0, s32 arg1) {
    if ((((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0) && ((((s32 (*)(s32))check_flag_100__10TObjPlayerFPv)(arg0) != 0) || (((TObjPlayer *)arg0)->get_camera_field() == 0))) {
        return 0;
    }
    return ((s32 (*)(s32, s32))can_start_technique__10TObjPlayerFPvi)(arg0, arg1);
}

s32 can_equip_item__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (((s32 (*)(void))is_locally_controlled__10TObjPlayerFPv)() != 0) {
        return ((s32 (*)(s32, s32))can_start_technique__10TObjPlayerFPvi)(arg0, arg1);
    }
    return 0;
}

s32 can_start_technique__10TObjPlayerFPvi(Player_801CD078 *self, s32 tech) {
    if (((TObjPlayer *)(self->techs))->test_bit1_at_10() != 0 ||
        ((s32 (*)(void *, u32))obj_testFlags30__13TUnk_804AF8A0FUl)(self, 0x20006) != 0 ||
        ((s32 (*)(void *, u32))obj_testFlags30__13TUnk_804AF8A0FUl)(self, 0x2000000) != 0 ||
        test_action_mask__10TObjPlayerFl(self, 0x11E) == 0 ||
        (tech == 0xE && TObjWarpBossMulti::is_flag_clear(self) == 0) ||
        (tech == 0x11 && is_camera_mode_active__10TObjPlayerFv() != 0) ||
        validate_and_clear_slot__10TObjPlayerFv(self->techs, tech) != 0 ||
        reset_volopt_state__10TObjPlayerFv(self) == 0) {
        return 0;
    }
    return self->tp - ((Rec_801CD078 * (*)(s32, s32, s32))calc_technique_parameters)(tech, get_cast_technique_level(self->techs, tech), ((s32 (*)(void *))get_entity_id)(self))->cost >= 0 ? 1 : 0;
}

void TObjPlayer::exit_technique_cast() {
    Player_801CD188 *self = (Player_801CD188 *)this;
    this->animationFlags &= ~0x40;
    ((void (*)(void *, s32))sub_8011E204__10TObjPlayerFl)(self, 0x80);
    ((TUnk_804B9870 *)self)->obj_clearFlags30((u32)0x400000);
    clear_status_bit6__10TObjPlayerFPv(self);
    if (self->sub != 0) {
        self->sub->f508 = 0xFFFF;
    }
}

void TObjPlayer::update_technique_cast() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    s32 temp_r30;
    u8 temp_r31;
    u8 *temp_r3;
    this->rotation_y = ((s32 (*)(int, int))lerp_angle_half__10TObjPlayerFUsUs)((int) (this->rotation_y), (int) (*(s32 *)((s8 *)arg0 + 0x3F0)));
    temp_r3 = (u8 *)(TObjPlayer__sub_801D8DCC((TObjPlayer *)arg0));
    temp_r0 = this->phase;
    switch (temp_r0) {
    case 3:
    case 5:
        break;
    case 0:
        this->phase = 1;
        ((TObjPlayer *)arg0)->set_state_flags(0x80);
        create_technique_charge_light((s16) (((TObjPlayer *)(arg0 + 0x428))->get_or_init_field_4()), (arg0));
        ((TObjPlayer *)(arg0 + 0x428))->set_technique_state((int) (*(s16 *)((s8 *)(((Rec_801CD078 * (*)(s32, s32, s32))calc_technique_parameters)(((TObjPlayer *)(arg0 + 0x428))->get_or_init_field_4(), ((TObjPlayer *)(arg0 + 0x428))->get_castable_technique_level(), ((s32 (*)(void *))get_entity_id)((void *) (arg0)))) + 0x12)));
        ((s32 (*)(void *, f32))TObjPlayer__sub_801D2CC4)((void *) (arg0 + 0x428), (f32) (lbl_805DC3A0));
        break;
    case 1:
        if (((TObjPlayer *)arg0)->is_flag_b0_4() == 0) {
            this->animationFlags = (s32) (this->animationFlags | 0x40);
            this->m_c0 = (f32) (this->m_c0 + ((TObjPlayer *)(arg0 + 0x428))->get_float_14());
            if (((TObjPlayer *)(arg0 + 0x428))->get_float_14() > TObjPlayer__data_805DC36C) {
                if (this->m_c0 >= TObjPlayer__data_805DC39C) {
                    ((s32 (*)(void *, f32))TObjPlayer__sub_801D2CC4)((void *) (arg0 + 0x428), (f32) (lbl_805DC3A4));
                }
            } else if (this->m_c0 < TObjPlayer__data_805DC36C) {
                ((s32 (*)(void *, f32))TObjPlayer__sub_801D2CC4)((void *) (arg0 + 0x428), (f32) (lbl_805DC3A0));
            }
        }
        ((s32 (*)(void *))TObjPlayer__sub_801D2CAC)((void *) (arg0 + 0x428));
        if (TObjPlayer__sub_80082300((void *) (arg0 + 0x428)) < 0) {
            this->phase = 2;
            this->animationFlags = (s32) (this->animationFlags & 0xFFFFFFBF);
        }
        break;
    case 2:
        if (((s32 (*)(void *, f32))objInBand__FP7GameObjf)((void *) (arg0), (f32) (*(f32 *)((s8 *)temp_r3 + 0xC))) != 0) {
            this->phase = 3;
            ((void (*)(void *, s32))sub_8011E204__10TObjPlayerFl)((void *) (arg0), 0x80);
            set_action_flag_40();
            if (obj_isState2_324__13TUnk_804806E8Fv((void *) (arg0)) == 0) {
                pay_tp_and_send_6x48_cast();
            }
        }
        break;
    case 4:
        ((s32 (*)(void *))TObjPlayer__sub_801D2CAC)((void *) (arg0 + 0x428));
        if (TObjPlayer__sub_80082300((void *) (arg0 + 0x428)) < 0) {
            this->phase = 5;
            this->m_b8 = ((s16 (*)(void *))get_idle_animation__10TObjPlayerFv)((void *) (arg0));
            clear_status_bit6__10TObjPlayerFPv((void *) (arg0));
        }
        break;
    }
    if (resolve_move_collision__10TObjPlayerFv((void *) (arg0)) == 0U) {
        ((TObjPlayer *)arg0)->apply_velocity();
    }
}

void TObjPlayer::enter_technique_cast() {
    TechData_801CD424 *td;
    u16 target;
    Obj_801CD424 *o;
    Player_801CD424 *self = (Player_801CD424 *)this;
    self->f33c = 8;
    ((void (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(self, this->mode, 6);
    td = ((TechData_801CD424 * (*)(void *))get_technique_data__10TObjPlayerFPv)(self->techs);
    target = td->target;
    if (target == 0xFFFF || target == (u16)((s32 (*)(void *))get_entity_id)(self) ||
        ((TObjPlayer *)(self->techs))->get_section_clamped() == 0) {
        self->f3f0 = this->rotation_y;
    } else {
        o = ((Obj_801CD424 * (*)(u16))find_entity_by_id)(target);
        if (o == 0) {
            td->target = 0xFFFF;
        } else {
            ((void (*)(void *, void *))copy_position__10TObjPlayerFPv)(self->f744, o->nodes[td->node].pos);
            self->f3f0 = ((TObjPlayer *)(((TObjPlayer *)self)->get_position_ptr()))->calc_angle_to(((TObjPlayer *)(self->f744))->get_field4_ptr());
        }
    }
    obj_setFlags30(self, 0x400000);
    ((void (*)(void *))TObjPlayer__sub_8001053C)(self);
    this->phase = 0;
    if (obj_isState2_324__13TUnk_804806E8Fv(self) != 0) {
        this->m_ba = ((s16 (*)(void))ret_801D26AC)();
    }
    ((void (*)(void *, s16, s16))set_action_state__10TObjPlayerFPvss)(self, 8, ((TObjPlayer *)self)->get_status());
}

void handle_6x8D_set_technique_level_override(void *arg0) {
    Msg_801CD6BC m;
    u8 *p;
    ((void (*)(void *))init_6x8D_technique_level_packet)(&m);
    ((TObjPlayer *)(&m))->copy_6x8d_technique_level_packet(arg0);
    ((TObjPlayer *)(&m))->swap_field6();
    if (validate_6x8D_set_technique_level_override(&m) != 0) {
        p = get_player_by_client_id(m.id);
        if (p != NULL) {
            ((TObjPlayer *)(p + 0x428))->set_tech_override(m.level);
        }
    }
}

void TObjPlayer::request_technique_cast() {
    u8 hi;
    u8 lo;
    Msg1_801CD72C m1;
    Msg2_801CD72C m2;
    TechData_801CD424 *td;
    s16 tech;
    s32 i;
    s32 count;
    TechData_801CD424 *src;
    u32 *dst;
    Player_801CD72C *self = (Player_801CD72C *)this;
    ((void (*)(s32, void *))capture_technique_targets__10TObjPlayerFv)(((TObjPlayer *)(self->techs))->get_or_init_field_4(), self);
    if (self->cursor != NULL) {
        td = ((TechData_801CD424 * (*)(void *))get_technique_data__10TObjPlayerFPv)(self->techs);
        ((TMainCursor *)(self->cursor))->set_cursor_pos(td->target, td->node);
    }
    tech = ((TObjPlayer *)(self->techs))->get_or_init_field_4();
    ((void (*)(u8, u8 *, u8 *))split_capped_value__10TObjPlayerFUcPUcPSc)(get_cast_technique_level(self->techs, tech), &hi, &lo);
    if (self == NULL || obj_isState2_324__13TUnk_804806E8Fv(self) == 0) {
        ((void (*)(void *))init_6x8D_technique_level_packet)(&m1);
        m1.id = ((s32 (*)(void *))get_entity_id)(self);
        m1.level = lo;
        ((TObjPlayer *)(&m1))->send_swap_field6();
        ((TNpcPlayer *)(&m2))->init_cast_technique_cmd();
        m2.id = ((s32 (*)(void *))get_entity_id)(self);
        m2.tech = tech;
        m2.lv = hi;
        count = ((TObjPlayer *)(self->techs))->get_section_clamped();
        m2.count = count;
        src = ((TechData_801CD424 * (*)(void *))get_technique_data__10TObjPlayerFPv)(self->techs);
        dst = m2.data;
        for (i = 0; i < count; i++) {
            copy_tech_params__10TObjPlayerFPvPv(dst++, src++);
        }
        ((TNpcPlayer *)(&m2))->finalize_and_send_packet();
    }
}

void TObjPlayer::check_anim_done() {
    if (((s16) this->phase == 5) && (((s32 (*)(void))is_anim_finished__10TObjPlayerFv)() != 0)) {
        ((s32 (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(this, 1, 0);
    }
}

void TObjPlayer::update_state5_action() {
    if (((s16) this->phase == 5) && (((s32 (*)(void))is_anim_finished__10TObjPlayerFv)() != 0)) {
        ((s32 (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(this, 1, 0);
    }
}

void TObjPlayer__sub_801CD904(void) {  }

int TObjPlayer::apply_status_action_a() { return try_apply_status_action__10TObjPlayerFi(this); }

void dispatch_technique_cast_state__10TObjPlayerFis(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->apply_status_action_a();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801CD904)();
        return;
      case 3:
        ((TObjPlayer *)arg0)->update_state5_action();
        return;
      case 8:
        ((TObjPlayer *)arg0)->check_anim_done();
        return;
      case 5:
        ((TObjPlayer *)arg0)->request_technique_cast();
        return;
      case 0:
        ((TObjPlayer *)arg0)->enter_technique_cast();
        return;
      case 1:
        ((TObjPlayer *)arg0)->update_technique_cast();
        return;
      case 6:
        ((TObjPlayer *)arg0)->exit_technique_cast();
        break;
    }
  }
}

void TObjPlayer::reset_linked_obj() {
    void *temp_r4;

    ((s32 (*)(void))TObjPlayer__sub_8001053C)();
    ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(this);
    temp_r4 = *(void **)((s8 *)this + 0x424);
    if (temp_r4 != NULL) {
        *(u16 *)((s8 *)temp_r4 + 0x508) = 0xFFFF;
    }
}

int TObjPlayer__sub_801CD9F0(void* p) { return ((int (*)(void*))update_action_state__10TObjPlayerFPv)(p); }

void enter_attack_stage3__10TObjPlayerFPv(u8 *player) {
    *(s32 *)((s8 *)player + 0x33C) = 7;
    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(player, (int) (((TObjPlayer *)player)->mode), 6);
    ((s32 (*)(void *, void *))set_action_type__10TObjPlayerFs)((void *) (player + 0x7CC), (void *) (((s32 (*)(void *))TObjPlayer__sub_801D2F0C)((void *) (player + 0x7CC))));
    ((s32 (*)(void *, void *))query_field_340__10TObjPlayerFPv)((void *) (player), (void *) (((u8 (*)(void *))TObjPlayer__sub_801D2F4C)((void *) (player + 0x7CC))));
    ((s32 (*)(void *, void *, int, int))begin_player_attack)((void *) (player + 0x7CC), (void *) (player), 2, 2);
    ((TObjPlayer *)player)->setup_attack_stage();
    ((s32 (*)(void *, int, void *))set_action_state__10TObjPlayerFPvss)((void *) (player), 7, (void *) (get_model_state__10TObjPlayerFv((void *) (player))));
    apply_speed_scale__10TObjPlayerFif((s32)(player), (f32) (((f32 (*)(void *))get_action_rate_entry)((void *) (player)) * get_attack_controller_rate((void *) (player + 0x7CC))));
}

void handle_6x45_attack(void *src) {
    Pkt_801CDAD8 pkt;
    u8 *player;
    init_6x45_attack_packet((u8 *)&pkt);
    ((TObjPlayer *)(&pkt))->copy_6x45_attack_packet(src);
    bswap_6x45_packet(&pkt);
    if (validate_6x45_attack(&pkt) == 0) return;
    player = get_player_by_client_id(pkt.player);
    if (player == 0) return;
    if (is_in_tl03_state__10TObjPlayerFv(player) == 0) return;
    if (reset_volopt_state__10TObjPlayerFv(player) == 0) return;
    if (test_action_mask__10TObjPlayerFl(player, 0x8200) != 0) return;
    set_action_type__10TObjPlayerFs(player + 0x7CC, pkt.kind);
        ((TObjPlayer *)(player + 0x7CC))->set_attack_target(pkt.kind);
    *(s32 *)(player + 0x3F0) = pkt.heading;
    ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(player, 7, 0);
}

void TObjPlayer::send_attack_stage3_request() {
    u8 *arg0 = (u8 *)this;
    s16 sp8[4];
    s16 temp_r31;
    void *position;
    s32 var_r4;
    u8 *temp_r3;
    u8 *temp_r4;
    temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x424));
    if (temp_r4 != NULL) {
        temp_r3 = (u8 *)(resolve_hittable_target(*(u16 *)((s8 *)temp_r4 + 0x508), *(s16 *)((s8 *)temp_r4 + 0x50A)));
        if (temp_r3 != NULL) {
            position = ((TObjPlayer *)arg0)->get_position_ptr();
            var_r4 = ((TObjPlayer *)position)->calc_angle_to(&((Rec_801CDBA0 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)))[*(s16 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x424)) + 0x50A)].pos);
        } else {
            var_r4 = this->rotation_y;
        }
        temp_r31 = calc_scaled_value__10TObjPlayerFii((void *) (arg0), (int) (var_r4));
        if ((arg0 == NULL) || (obj_isState2_324__13TUnk_804806E8Fv((void *) (arg0)) == 0)) {
            init_6x45_attack_packet((u8 *)(&sp8));
            sp8[1] = get_entity_id((void *) (arg0));
            sp8[2] = temp_r31;
            sp8[3] = TObjPlayer__sub_801D2F0C((void *) (arg0 + 0x7CC));
            ((TNpcPlayer *)(&sp8))->update();
        }
    }
}

void TObjPlayer__sub_801CDC68(void) {  }

void TObjPlayer::finish_attack_stage3() {
    u8 *arg0 = (u8 *)this;
    if ((s16) this->phase == 4) {
        if (((s32 (*)(void))is_anim_finished__10TObjPlayerFv)() != 0) {
            ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *) (arg0), 1, 5);
        }
    } else if (this->animationFlags & 0x10) {
        if (test_flags_any((void *)(((s32 (*)(void *))get_anim_field_c__10TObjPlayerFPv)((void *) (arg0 + 0x7CC))), 1) != 0) {
            this->phase = 4;
            this->m_b8 = ((s16 (*)(void *))get_idle_animation__10TObjPlayerFv)((void *) (arg0));
            ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)((void *) (arg0));
        }
    }
}

void TObjPlayer::check_attack_stage3_input() {  }

int TObjPlayer::try_apply_status_action_1() { return try_apply_status_action__10TObjPlayerFi(this); }

void run_attack_stage3_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->try_apply_status_action_1();
        return;
      case 2:
        TObjPlayer::check_attack_stage3_input();
        return;
      case 3:
        ((TObjPlayer *)arg0)->finish_attack_stage3();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CDC68)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_attack_stage3_request();
        return;
      case 0:
        ((s32 (*)(void *))enter_attack_stage3__10TObjPlayerFPv)((void *) arg0);
        return;
      case 1:
        ((s32 (*)(void *))TObjPlayer__sub_801CD9F0)((void *) arg0);
        return;
      case 6:
        ((TObjPlayer *)arg0)->reset_linked_obj();
        break;
    }
  }
}

void TObjPlayer::reset_target_link() {
    void *temp_r4;

    ((s32 (*)(void))TObjPlayer__sub_8001053C)();
    ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(this);
    temp_r4 = *(void **)((s8 *)this + 0x424);
    if (temp_r4 != NULL) {
        *(u16 *)((s8 *)temp_r4 + 0x508) = 0xFFFF;
    }
}

int TObjPlayer__sub_801CDDEC(void* p) { return ((int (*)(void*))update_action_state__10TObjPlayerFPv)(p); }

void enter_attack_stage2__10TObjPlayerFPv(u8 *player) {
    *(s32 *)((s8 *)player + 0x33C) = 6;
    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(player, (int) (((TObjPlayer *)player)->mode), 6);
    ((s32 (*)(void *, void *))set_action_type__10TObjPlayerFs)((void *) (player + 0x7CC), (void *) (((s32 (*)(void *))TObjPlayer__sub_801D2F0C)((void *) (player + 0x7CC))));
    ((s32 (*)(void *, void *))query_field_340__10TObjPlayerFPv)((void *) (player), (void *) (((u8 (*)(void *))TObjPlayer__sub_801D2F4C)((void *) (player + 0x7CC))));
    ((s32 (*)(void *, void *, int, int))begin_player_attack)((void *) (player + 0x7CC), (void *) (player), 1, 1);
    ((TObjPlayer *)player)->setup_attack_stage();
    ((s32 (*)(void *, int, void *))set_action_state__10TObjPlayerFPvss)((void *) (player), 6, (void *) (get_state__10TObjPlayerFv((void *) (player))));
    apply_speed_scale__10TObjPlayerFif((s32)(player), (f32) (((f32 (*)(void *))get_action_rate_entry)((void *) (player)) * get_attack_controller_rate((void *) (player + 0x7CC))));
}

void handle_6x44_attack(void *src) {
    Pkt_801CDED4 pkt;
    u8 *player;
    init_6x44_attack_packet((u8 *)&pkt);
    ((void (*)(Pkt_801CDED4 *, void *))TObjPlayer__sub_801D2348)(&pkt, src);
    bswap_6x44_packet(&pkt);
    if (validate_6x44_attack(&pkt) == 0) return;
    player = get_player_by_client_id(pkt.player);
    if (player == 0) return;
    if (is_in_tl03_state__10TObjPlayerFv(player) == 0) return;
    if (reset_volopt_state__10TObjPlayerFv(player) == 0) return;
    if (test_action_mask__10TObjPlayerFl(player, 0x8200) != 0) return;
    set_action_type__10TObjPlayerFs(player + 0x7CC, pkt.kind);
        ((TObjPlayer *)(player + 0x7CC))->set_attack_target(pkt.kind);
    *(s32 *)(player + 0x3F0) = pkt.heading;
    ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(player, 6, 0);
}

void TObjPlayer::send_attack_stage2_request() {
    u8 *arg0 = (u8 *)this;
    s16 sp8[4];
    s16 temp_r31;
    void *position;
    s32 var_r4;
    u8 *temp_r3;
    u8 *temp_r4;
    temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x424));
    if (temp_r4 != NULL) {
        temp_r3 = (u8 *)(resolve_hittable_target(*(u16 *)((s8 *)temp_r4 + 0x508), *(s16 *)((s8 *)temp_r4 + 0x50A)));
        if (temp_r3 != NULL) {
            position = ((TObjPlayer *)arg0)->get_position_ptr();
            var_r4 = ((TObjPlayer *)position)->calc_angle_to(&((Rec_801CDF9C *)(*(u8 **)((s8 *)temp_r3 + 0xA4)))[*(s16 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x424)) + 0x50A)].pos);
        } else {
            var_r4 = this->rotation_y;
        }
        temp_r31 = calc_scaled_value__10TObjPlayerFii((void *) (arg0), (int) (var_r4));
        if ((arg0 == NULL) || (obj_isState2_324__13TUnk_804806E8Fv((void *) (arg0)) == 0)) {
            init_6x44_attack_packet((u8 *)(&sp8));
            sp8[1] = get_entity_id((void *) (arg0));
            sp8[2] = temp_r31;
            sp8[3] = TObjPlayer__sub_801D2F0C((void *) (arg0 + 0x7CC));
            ((TNpcPlayer *)(&sp8))->update_players();
        }
    }
}

void TObjPlayer__sub_801CE064(void) {  }

void TObjPlayer::finish_attack_stage2() {
    Player_801CE068 *self = (Player_801CE068 *)this;
    if (this->phase == 4) {
        if (is_anim_finished__10TObjPlayerFv(self) != 0) {
            ((void (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(self, 1, 5);
        }
    } else if ((this->animationFlags & 0x10) &&
               ((s32 (*)(void *, s32))test_flags_any)(get_anim_field_c__10TObjPlayerFPv(self->act), 1) != 0) {
        switch (((s16 (*)(void *))get_validated_attack_stage)(self->act)) {
        case 0:
        case 1:
            this->phase = 4;
            clear_status_bit6__10TObjPlayerFPv(self);
            this->m_b8 = ((s16 (*)(void *))get_idle_animation__10TObjPlayerFv)(self);
            break;
        case 2:
            ((void (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(self, 7, 5);
            break;
        }
    }
}

void TObjPlayer__sub_801CE134(s32 arg0) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(void))TObjPlayer__sub_801CEAC8)();
    if (temp_r3 != -1) {
        ((s32 (*)(s32, s32, s32, s32))queue_physical_attack_input)(arg0 + 0x7CC, arg0, temp_r3, 2);
    }
}

int TObjPlayer::apply_status_action() { return try_apply_status_action__10TObjPlayerFi(this); }

void run_attack_stage2_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  int new_var2;
  void *new_var;
  new_var2 = ((u32) arg1) <= 8U;
  {
    new_var = (void *) arg0;
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->apply_status_action();
        return;
      case 2:
        ((s32 (*)(void *))TObjPlayer__sub_801CE134)((void *) arg0);
        return;
      case 3:
        ((TObjPlayer *)new_var)->finish_attack_stage2();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CE064)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_attack_stage2_request();
        return;
      case 0:
        ((s32 (*)(void *))enter_attack_stage2__10TObjPlayerFPv)(new_var);
        return;
      case 1:
        ((s32 (*)(void *))TObjPlayer__sub_801CDDEC)(new_var);
        return;
      case 6:
        ((TObjPlayer *)new_var)->reset_target_link();
        break;
    }
  }
}

void TObjPlayer::start_attack_preparation() {
    u8 *arg0 = (u8 *)this;
    void *p;
    switch (((s16 (*)(void *))TObjPlayer__sub_801D2F4C)(arg0 + 0x7CC)) {
    case 0:
        *(s16 *)(arg0 + 0x328) = 3;
        break;
    case 1:
        *(s16 *)(arg0 + 0x328) = 1;
        ((TObjPlayer *)arg0)->set_state_flags(0x80);
        ((TObjPlayer *)(arg0 + 0x384))->request_heavy_attack_particles();
        lbl_8050BEE0[1] = lbl_8050BEE0[0] = 0.0f;
        player_feedback_light_color[0] = lbl_8050BEE0[2] = 1.0f;
        player_feedback_light_color[2] = player_feedback_light_color[1] = lbl_805DC3A8;
        player_feedback_light_color[3] = 1.0f;
        p = ((void * (*)(u32))__nw__7TObjectFUl)(0x64);
        if (p != NULL) {
            construct_actor_light_task(p, player_feedback_light_color, lbl_8050BEE0, 8, arg0, TObjPlayer__data_805DC39C, tl_07);
        }
        publish_actor_light_scalars(get_entity_id(arg0), TObjPlayer__data_805DC360, TObjPlayer__data_805DC3AC);
        ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x1AD1C);
        break;
    case 2:
        *(s16 *)(arg0 + 0x328) = 1;
        ((TObjPlayer *)arg0)->set_state_flags(0x80);
        dispatch_weapon_special_effect(arg0, 0, 0, 0);
        lbl_8050BEE0[1] = lbl_8050BEE0[0] = 0.0f;
        player_feedback_light_color[0] = lbl_8050BEE0[2] = 1.0f;
        player_feedback_light_color[2] = player_feedback_light_color[1] = lbl_805DC3A8;
        player_feedback_light_color[3] = 1.0f;
        p = ((void * (*)(u32))__nw__7TObjectFUl)(0x64);
        if (p != NULL) {
            construct_actor_light_task(p, player_feedback_light_color, lbl_8050BEE0, 8, arg0, TObjPlayer__data_805DC39C, tl_07);
        }
        publish_actor_light_scalars(get_entity_id(arg0), TObjPlayer__data_805DC360, TObjPlayer__data_805DC3AC);
        ((TObjPlayer *)arg0)->play_sound_if_on_floor(0x1AD1D);
        break;
    }
}

void TObjPlayer::setup_attack_stage() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)(arg0 + 0x328) = 0;
    switch (((s16 (*)(void *))TObjPlayer__sub_801D2F4C)(arg0 + 0x7CC)) {
    case 0:
        if (((s16 (*)(void *))get_validated_attack_stage)(arg0 + 0x7CC) == 0) {
            set_field_d4_and_flag_200(TObjPlayer__data_805DC3AC);
        }
        break;
    case 1:
    case 2:
        if (((s16 (*)(void *))get_validated_attack_stage)(arg0 + 0x7CC) == 0) {
            set_field_d4_and_flag_200(TObjPlayer__data_805DC39C);
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
    TUnk_804806E8 *target;
    s32 collider;
};

int TObjPlayer::vfunc_67(f32 damage_scale) {
    s32 count;
    s32 i;
    int hit = 0;
    s32 *entry;
    count = get_captured_target_count((s32 *)((TObjPlayer *)&attack_state)->get_state_ptr());
    entry = (s32 *)get_captured_target_entry(((TObjPlayer *)&attack_state)->get_state_ptr(), 0);
    for (i = 0; i < count; i++) {
        u16 uid = ((TObjPlayer *)entry)->get_uid();
        s16 collider = get_captured_target_collider_index(entry);
        TUnk_804806E8 *target = (TUnk_804806E8 *)resolve_hittable_target(uid, collider);
        if (target == NULL) {
            continue;
        }
        if (get_type__10TObjPlayerFPv(&m_828) != 0 && obj_isState2_324__13TUnk_804806E8Fv(this) != 0 &&
            test_elt_flag__13TUnk_80493450Fll(target, collider, 0x2000) == 0) {
            continue;
        }
        if ((((TargetCollider *)bodies)->flags ^ ((TargetCollider *)target->bodies)[collider].flags) & 6) {
            continue;
        }
        f32 accuracy;
        if (TObjPlayer__sub_801D2F4C((s16 *)&attack_state) == 2 && get_item_field_6__10TObjPlayerFPv(this) != NULL &&
            ((TItem *)get_item_field_6__10TObjPlayerFPv(this))->is_identified() == 0) {
            if ((f32)get_ata() < 0.0f) {
                accuracy = 0.0f;
            } else {
                accuracy = 0.1f;
            }
        } else {
            accuracy = get_attack_accuracy_scale((s16 *)&attack_state);
        }
        if (target->roll_physical_accuracy(this, collider, accuracy) != 0) {
            s32 damage;
            f32 dealt;
            switch (TObjPlayer__sub_801D2F4C((s16 *)&attack_state)) {
            case 0:
                damage = target->receive_physical_attack(this, damage_scale * get_attack_damage_scale((s16 *)&attack_state));
                vfunc_75(TObjPlayer::calc_photon_blast_charge(this, damage));
                apply_camera_shake__10TObjPlayerFiii(this, target, damage);
                break;
            case 1:
                dealt = target->receive_physical_attack(this, damage_scale * get_attack_damage_scale((s16 *)&attack_state));
                damage = dealt;
                vfunc_75(TObjPlayer::calc_photon_blast_charge(this, damage));
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
            TItem *item = (TItem *)get_item_field_6__10TObjPlayerFPv(this);
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
                                                       ((TObjPlayer *)&attack_state)->calc_attack_stage_multiplier(2)) != 0) {
                        s32 damage = target->receive_physical_attack(this, damage_scale * get_attack_damage_scale((s16 *)&attack_state));
                        vfunc_75(TObjPlayer::calc_photon_blast_charge(this, damage));
                        apply_camera_shake__10TObjPlayerFiii(this, target, damage);
                        hit = 1;
                        WeaponHitSound sound;
                        ((TObjPlayer *)&sound)->reset_status_block();
                        TItem *item = (TItem *)get_item_field_6__10TObjPlayerFPv(this);
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

void handle_6x46_attack_finished(s32 arg0) {
    u16 packet[0x18];
    Player_801CE928 *pl;
    Item_801CE928 *it;
    ((TObjPlayer *)packet)->build_packet_header();
    ((s32 (*)(void *, s32))TObjPlayer__sub_801D2BB8)(packet, arg0);
    ((TObjPlayer *)packet)->bswap_field4_sub();
    if (validate_6x46_attack_finished(packet) != 0 && (pl = ((Player_801CE928 * (*)(u16))get_player_by_client_id)(packet[1])) != NULL &&
        ((s32 (*)(void))is_in_tl03_state__10TObjPlayerFv)() != 0 && reset_volopt_state__10TObjPlayerFv(pl) != 0) {
        ((s32 (*)(void *, void *))on_attack_finished__10TObjPlayerFPv)((u8 *)pl + 0x7CC, &packet[2]);
        it = get_item_field_6__10TObjPlayerFPv(pl);
        if (it != NULL) {
            ((TItem *)it)->perform_action();
            return;
        }
        if (pl->v65((*(f32 *)&TObjPlayer__data_805DC360)) == 0) {
            ((TObjPlayer *)pl)->play_sound_if_on_floor(0x4001A80C);
        }
    }
}

void TObjPlayer::send_attack_target_packet() {
    u32 arg0 = (u32)this;
    s16 sp8[0x14];
    if (((obj_isState2_324__13TUnk_804806E8Fv((void *) (arg0)) == 0) || (reset_volopt_state__10TObjPlayerFv((void *) (arg0)) != 0)) && ((((s32 (*)(void *))obj_isState3_324__13TUnk_804806E8Fv)((void *) (arg0)) != 0) || (((u32 (*)(void *, void *))capture_lockon_targets)((void *) (arg0 + 0x7CC), (void *) (arg0)) != 0U)) && (((TObjPlayer *)(arg0))->is_body_collision_inactive() == 0) && ((arg0 == 0U) || (obj_isState2_324__13TUnk_804806E8Fv((void *) (arg0)) == 0))) {
        ((TObjPlayer *)sp8)->build_packet_header();
        sp8[1] = get_entity_id((void *) (arg0));
        copy_attack_targets((void *) (&sp8[2]), (void *) (((TObjPlayer *)(arg0 + 0x7CC))->get_state_ptr()));
        ((s32 (*)(void *))send_6x46_attack_finished)((void *) (sp8));
    }
}

s32 TObjPlayer__sub_801CEAC8(u8 *self) {
    s32 r = -1;
    if (TObjPlayer__sub_801B5AF8(self, 1) == 2 && ((TObjPlayer *)(self + 0x550))->check_action_usable(4) != 0) {
        r = 1;
    }
    if (TObjPlayer__sub_801B5AF8(self, 2) == 2 && ((TObjPlayer *)(self + 0x550))->check_action_usable(0x400) != 0 &&
        TObjPlayer__sub_80354D5C(get_entity_id(self)) == 0) {
        r = 2;
    }
    if (TObjPlayer__sub_801B5AF8(self, 3) == 2 && ((TObjPlayer *)(self + 0x550))->check_action_usable(2) != 0) {
        r = 3;
    }
    return ((TObjPlayer *)self)->check_mode_action(get_action_palette_entry__10TObjPlayerFl(self, r)) != 0 ? r : -1;
}

s32 TObjPlayer::check_mode_action(s32 arg1) {
    if (arg1 == 2) {
        if (((u32 (*)(void))get_item_field_6__10TObjPlayerFPv)() != 0U) {
            if (weapon_has_extra_attack() == 0) {
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
    s32 arg0 = (s32)this;
    if ((((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)((void *) (arg0), 0x20006) != 0) || (((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)((void *) (arg0), 0x02000000) != 0) || (((s32 (*)(void *, int))check_flag__10TObjPlayerFl)((void *) (arg0), 2) != 0) || (((s32 (*)(void *, int))test_action_mask__10TObjPlayerFl)((void *) (arg0), 0x548000) != 0) || ((is_locally_controlled__10TObjPlayerFPv((void *) (arg0)) != 0) && ((check_flag_100__10TObjPlayerFPv((void *) (arg0)) != 0) || (((TObjPlayer *)arg0)->get_camera_field() == 0))) || (reset_volopt_state__10TObjPlayerFv((void *) (arg0)) == 0)) {
        return 0;
    }
    return 1;
}

void TObjPlayer::update_by_state() {
    u8 *arg0 = (u8 *)this;

    switch (get_handle_value__10TObjPlayerFv()) {
    case 0:
        if (this->animationFlags & 0x10) {
            ((TObjPlayer *)(arg0 + 0x7CC))->set_flag_1_at_c();
        }
        return;
    case 8:
        ((TObjPlayer *)(arg0 + 0x7CC))->update_if_flag8_set();
        return;
    default:
        if (this->animationFlags & 0x10) {
            ((TObjPlayer *)(arg0 + 0x7CC))->tick_countdown_timer();
        }
        break;
    }
}

void TObjPlayer::apply_movement_if_ready() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r3;

    temp_r3 = get_handle_value__10TObjPlayerFv();
    if ((temp_r3 != 0x11) && ((temp_r3 >= 0x11) || (temp_r3 >= 0xA) || (temp_r3 < 6)) && (((TObjPlayer *)arg0)->is_flag_b0_4() == 0) && ((s16) this->m_b8 == (s16) this->m_ba) && (this->m_b4 & 0x20000000) && (((s32 (*)(void *))TObjPlayer__sub_801D2680)(arg0) == 0)) {
        if (TObjPlayer__data_805DC36C > sample_attack_root_motion(arg0, (u8 *)&this->unk_308, (u8 *)&this->m_310)) {
            TObjPlayer__sub_8001053C(arg0);
        }
        if (((TObjPlayer *)arg0)->check_actor_blocking_move() != 0) {
            TObjPlayer__sub_8001053C(arg0);
        }
        if (resolve_move_collision__10TObjPlayerFv(arg0) == 0U) {
            ((TObjPlayer *)arg0)->apply_velocity();
        }
    }
}

void TObjPlayer::update_anim_action() {
    u8 *arg0 = (u8 *)this;
    ((s32 (*)(void))get_item_field_6__10TObjPlayerFPv)();
    if (((s16 (*)(void *))get_handle_value__10TObjPlayerFv)(arg0) != 8) {
        ((TObjPlayer *)arg0)->select_normal_attack_marker();
        if (objInBand__FP7GameObjf(arg0) != 0) {
            send_attack_target_packet();
            ((TObjPlayer *)(arg0 + 0x7CC))->increment_strike_counter();
            ((s32 (*)(void *, void *))apply_anim_action__10TObjPlayerFPvi)(arg0 + 0x7CC, arg0);
        }
    } else {
        if (((s32 (*)(s32, s32))test_flags_any)(((s32 (*)(void *))get_anim_field_c__10TObjPlayerFPv)(arg0 + 0x7CC), 8) == 0) {
            ((TObjPlayer *)arg0)->select_normal_attack_marker();
            if (objInBand__FP7GameObjf(arg0) != 0) {
                send_attack_target_packet();
                increment_burst_counter((u8 *)&this->attack_state);
                if (get_burst_counter((u8 *)&this->attack_state) >= 3) {
                    ((FlagWord *)(((s32 (*)(void *))get_anim_field_c__10TObjPlayerFPv)(arg0 + 0x7CC)))->set(8);
                    ((s32 (*)(void *, void *))apply_anim_action__10TObjPlayerFPvi)(arg0 + 0x7CC, arg0);
                    set_action_flag_40();
                    this->animationFlags = (s32) (this->animationFlags | 0x10);
                }
            }
        }
    }
}

void update_action_state__10TObjPlayerFPv(u8 *player) {
    s32 temp_r31;

    ((TObjPlayer *)player)->rotation_y = lerp_angle_half__10TObjPlayerFUsUs(((TObjPlayer *)player)->rotation_y, *(s32 *)((s8 *)player + 0x3F0));
    switch (((TObjPlayer *)player)->phase) {
    case 0:
        ((TObjPlayer *)player)->start_attack_preparation();
    case 1:
        if (is_anim_finished__10TObjPlayerFv(player) != 0) {
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
    void *temp_r4;

    ((s32 (*)(void))TObjPlayer__sub_8001053C)();
    ((s32 (*)(void *))clear_status_bit6__10TObjPlayerFPv)(this);
    temp_r4 = *(void **)((s8 *)this + 0x424);
    if (temp_r4 != NULL) {
        *(u16 *)((s8 *)temp_r4 + 0x508) = 0xFFFF;
    }
}

void update_action_state__10TObjPlayerFv(void) {
    ((s32 (*)(void))update_action_state__10TObjPlayerFPv)();
}

void enter_attack_stage1__10TObjPlayerFPv(u8 *player) {
    *(s32 *)((s8 *)player + 0x33C) = 5;
    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *) (player), (int) (((TObjPlayer *)player)->mode), 6);
    TObjPlayer__sub_8001053C((void *) (player));
    ((s32 (*)(void *, void *, int, int))begin_player_attack)((void *) (player + 0x7CC), (void *) (player), 0, 0);
    ((TObjPlayer *)player)->setup_attack_stage();
    ((s32 (*)(void *, int, void *))set_action_state__10TObjPlayerFPvss)((void *) (player), 5, (void *) (call_subobject_m15__10TObjPlayerFv((void *) (player))));
    apply_speed_scale__10TObjPlayerFif((s32)(player), (f32) (((f32 (*)(void *))get_action_rate_entry)((void *) (player)) * get_attack_controller_rate((void *) (player + 0x7CC))));
}

void handle_6x43_attack(void *src) {
    Pkt_801CF128 pkt;
    u8 *player;
    init_6x43_attack_packet((u8 *)&pkt);
    ((void (*)(Pkt_801CF128 *, void *))TObjPlayer__sub_801D24B0)(&pkt, src);
    bswap_6x43_packet(&pkt);
    if (validate_6x43_attack(&pkt) == 0) return;
    player = get_player_by_client_id(pkt.player);
    if (player == 0) return;
    if (is_in_tl03_state__10TObjPlayerFv(player) == 0) return;
    if (reset_volopt_state__10TObjPlayerFv(player) == 0) return;
    if (test_action_mask__10TObjPlayerFl(player, 0x8200) != 0) return;
    set_action_type__10TObjPlayerFs(player + 0x7CC, pkt.kind);
    *(s32 *)(player + 0x3F0) = pkt.heading;
    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(player, 5, 0);
}
}
void TObjPlayer::request_normal_attack_stage1() {
    u8* arg0 = reinterpret_cast<u8*>(this);
    f32 sp10[3];
    s16 sp8[4];
    s16 temp_r31;
    s32 var_r4;
    if ((reset_volopt_state__10TObjPlayerFv(arg0) != 0) && (((u32 (*)(void *, void *))capture_lockon_targets)((void *) (arg0 + 0x7CC), (void *) (arg0)) != 0U)) {
        if (((s32 (*)(void *, void *))get_first_target_position__10TObjPlayerFPvPv)((void *) (arg0 + 0x7CC), (void *) (&sp10)) != 0) {
            var_r4 = ((TObjPlayer *)(((TObjPlayer *)arg0)->get_position_ptr()))->calc_angle_to(sp10);
        } else {
            var_r4 = ((TObjPlayer *)arg0)->rotation_y;
        }
        temp_r31 = calc_scaled_value__10TObjPlayerFii((void *) (arg0), (int) (var_r4));
        if ((arg0 == NULL) || (obj_isState2_324__13TUnk_804806E8Fv((void *) (arg0)) == 0)) {
            init_6x43_attack_packet((u8 *)(&sp8));
            sp8[1] = get_entity_id((void *) (arg0));
            sp8[2] = temp_r31;
            sp8[3] = ((s16 (*)(void *))TObjPlayer__sub_801D2F4C)((void *) (arg0 + 0x7CC));
            ((TNpcPlayer *)(&sp8))->update_lobby();
        }
    }
}

extern "C" {
void TObjPlayer__sub_801CF2AC(void) {  }

void TObjPlayer::finish_attack_stage1() {
    Player_801CF2B0 *self = (Player_801CF2B0 *)this;
    if (this->phase == 4) {
        if (is_anim_finished__10TObjPlayerFv(self) != 0) {
            ((void (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(self, 1, 5);
        }
    } else if ((this->animationFlags & 0x10) &&
               ((s32 (*)(void *, s32))test_flags_any)(get_anim_field_c__10TObjPlayerFPv(self->act), 1) != 0) {
        switch (((s16 (*)(void *))get_validated_attack_stage)(self->act)) {
        case 0:
            this->phase = 4;
            clear_status_bit6__10TObjPlayerFPv(self);
            this->m_b8 = ((s16 (*)(void *))get_idle_animation__10TObjPlayerFv)(self);
            break;
        case 1:
        case 2:
            ((void (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(self, 6, 5);
            break;
        }
    }
}

void TObjPlayer::update_active_item() {
    s32 arg0 = (s32)this;
    s32 temp_r3;

    temp_r3 = ((s32 (*)(void))TObjPlayer__sub_801CEAC8)();
    if (temp_r3 != -1) {
        ((s32 (*)(s32, s32, s32, s32))queue_physical_attack_input)(arg0 + 0x7CC, arg0, temp_r3, 1);
    }
}

int TObjPlayer__sub_801CF3C0(void* p) { return try_apply_status_action__10TObjPlayerFi(p); }

void run_attack_stage1_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void *))TObjPlayer__sub_801CF3C0)((void *) arg0);
        return;
      case 2:
        ((TObjPlayer *)arg0)->update_active_item();
        return;
      case 3:
        ((TObjPlayer *)arg0)->finish_attack_stage1();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CF2AC)();
        return;
      case 5:
        ((TObjPlayer *)arg0)->request_normal_attack_stage1();
        return;
      case 0:
        ((s32 (*)(void *))enter_attack_stage1__10TObjPlayerFPv)((void *) arg0);
        return;
      case 1:
        ((s32 (*)(void *))update_action_state__10TObjPlayerFv)((void *) arg0);
        return;
      case 6:
        ((TObjPlayer *)arg0)->reset_lockon();
        break;
    }
  }
}

s32 update_aim_target__10TObjPlayerFPv(void *arg0) {
    f32 temp_f1;
    s32 temp_r3;

    if (is_inactive__10TObjPlayerFv() == 0) {
        return 0;
    }
    temp_f1 = lbl_805DC3B0 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x3F0));
    *(f32 *)((s8 *)arg0 + 0x308) = temp_f1;
    *(f32 *)((s8 *)arg0 + 0x30C) = (f32) TObjPlayer__data_805DC36C;
    *(f32 *)((s8 *)arg0 + 0x310) = (f32) (lbl_805DC3B0 * ((f32 (*)(s32, f32, f32))cos_table_lookup)(*(s32 *)((s8 *)arg0 + 0x3F0), temp_f1, lbl_805DC3B0));
    if (((TObjPlayer *)arg0)->check_actor_blocking_move() != 0) {
        ((int (*)(void*))TObjPlayer__sub_8001053C)((void*)(arg0));
        return 0;
    }
    temp_r3 = ((s32 (*)(void *))resolve_move_collision__10TObjPlayerFv)(arg0);
    if (temp_r3 == 0) {
        return 1;
    }
    if ((is_locally_controlled__10TObjPlayerFPv(arg0) != 0) && (((TLobby *)arg0)->check_player_flag1() == 0) && (temp_r3 == 4)) {
        return 1;
    }
    return 0;
}

void TObjPlayer::apply_damage_and_reset() { sub_800E2DE4((s32)((void*)256)); ((int (*)(void*))TObjPlayer__sub_8001053C)((void*)(this)); }

void TObjPlayer::update_run_movement() {
    s32 ang;
    f32 dist;
    Plr_801CF56C *self = (Plr_801CF56C *)this;
    self->target_rot = ((TObjPlayer *)(((TObjPlayer *)self)->get_position_ptr()))->calc_angle_to(&self->tx);
    self->rot = approach_angle_adaptive(self->rot, self->target_rot);
    ang = lerp_angle_half__10TObjPlayerFUsUs(self->rot, self->target_rot);
    self->vx = TObjPlayer__sub_801BF814(self->motion) * sin_table_lookup(ang);
    self->vy = TObjPlayer__data_805DC36C;
    self->vz = TObjPlayer__sub_801BF814(self->motion) * cos_table_lookup(ang);
    dist = (self->tx - self->x) * (self->tx - self->x) + (self->tz - self->z) * (self->tz - self->z);
    if ((lbl_805DC3B4 * TObjPlayer__sub_801BF814(self->motion)) * (lbl_805DC3B4 * TObjPlayer__sub_801BF814(self->motion)) > dist) {
        ((FlagWord *)(self->flags))->set(4);
    }
    if (((void * (*)(void *))resolve_move_collision__10TObjPlayerFv)(self) == NULL) {
        ((TObjPlayer *)self)->apply_velocity();
    } else {
        ((FlagWord *)(self->flags))->set(4);
    }
    play_footstep_sound__10TObjPlayerFv(self, TObjPlayer__data_805DC360, lbl_805DC370);
    ((TObjPlayer *)self)->emit_footstep_effect(TObjPlayer__data_805DC360, lbl_805DC370);
}

void start_action__10TObjPlayerFPv(u8 *arg0) {
    f32 temp_f31;
    f32 temp_f1;
    s16 temp_r3;

    *(s32 *)((s8 *)arg0 + 0x33C) = 4;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, *(s16 *)((s8 *)arg0 + 0x326), 6);
    ((FlagWord *)(arg0 + 0x5EC))->reset();
    temp_r3 = get_vobj_state_28__10TObjPlayerFv(arg0);
    if (((TObjPlayer *)arg0)->is_matching_id(temp_r3) != 0) {
        ((TObjPlayer *)arg0)->set_action_flag();
    }
    apply_stat_multipliers_and_reset__10TObjPlayerFPv(arg0 + 0x5E0, arg0, lbl_805DC3B0);
    ((s32 (*)(void *, s32, s16))set_action_state__10TObjPlayerFPvss)(arg0, 4, temp_r3);
    temp_f31 = TObjPlayer__sub_801D2858(arg0 + 0x5E0);
    temp_f1 = ((f32 (*)(void *))get_action_rate_entry)(arg0);
    ((TObjEnemy *)arg0)->sub_800A7798(temp_f1 * temp_f31);
}

void handle_6x42_move_to_position(void *pkt) {
    Cmd_801CF780 cmd;
    Player_801CF780 *p;
    ((TNpcPlayer *)(&cmd))->reset_move_state();
    ((TObjPlayer *)(&cmd))->copy_packet_pos_6x42(pkt);
    ((TNpcPlayer *)(&cmd))->init_model();
    if (validate_6x42_move_to_position(&cmd) != 0) {
        p = (Player_801CF780 *)((void * (*)(s32))get_player_by_client_id)(cmd.id);
        if (p != 0 && is_in_tl03_state__10TObjPlayerFv(p) != 0 && test_action_mask__10TObjPlayerFl(p, 0x1E) != 0) {
            p->x = cmd.x;
            p->z = cmd.z;
            ((void (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(p, 4, 0);
        }
    }
}

void TObjPlayer::send_6x42_run_to_position() {
    Npc_801CF824 *arg0 = (Npc_801CF824 *)this;
    Msg_801CF824 m;
    if (((s32 (*)(void))update_aim_target__10TObjPlayerFPv)() != 0) {
        calc_movement_target(arg0->f3f0, &arg0->x, &arg0->z);
        if ((arg0 == NULL) || (obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0)) {
            ((TNpcPlayer *)(&m))->reset_move_state();
            m.f2 = get_entity_id(arg0);
            m.x = arg0->x;
            m.z = arg0->z;
            ((TNpcPlayer *)(&m))->reset_model();
        }
    }
}

void TObjPlayer::handle_ring_release() {
    s32 arg0 = (s32)this;
    if (((s32 (*)(s32, s32))test_flags_any)(arg0 + 0x5EC, 4) != 0) {
        ((FlagWord *)(arg0 + 0x5EC))->clear(4);
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 0);
    }
}

void TObjPlayer::try_trigger_effect() {
    s32 arg0 = (s32)this;
    if (((s32 (*)(s32, s32))test_flags_any)(arg0 + 0x5EC, 4) != 0) {
        ((FlagWord *)(arg0 + 0x5EC))->clear(4);
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 5);
    }
}

void TObjPlayer::select_run_request() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    s32 temp_r31;
    s32 temp_r31_2;
    temp_r31 = ((TObjPlayer *)(arg0 + 0x550))->get_target_field_1c();
    temp_f31 = ((TObjPlayer *)(arg0 + 0x550))->get_attached_float_24();
    if ((((TObjPlayer *)arg0)->handle_palette_button_input() == 0) || (((TObjPlayer *)arg0)->check_flag_48() == 0)) {
        if (temp_f31 < TObjPlayer__data_805DC368) {
            if (test_flags_any(arg0 + 0x5EC, 4) != 0) {
                ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 5);
                return;
            }
            return;
        } else {
            temp_r31_2 = ((s32 (*)(void *, int))calc_scaled_value__10TObjPlayerFii)(arg0, temp_r31);
            if ((((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x100000) != 0) || (temp_f31 < TObjPlayer__data_805DC3AC)) {
                set_ring_action__10TObjPlayerFPvi((u8 *)&this->m_5e0, 0);
                if (test_flags_any(arg0 + 0x5EC, 4) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x3F0) = temp_r31_2;
                    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 2, 5);
                }
            } else {
                ((TObjPlayer *)(arg0 + 0x5E0))->increment_run_counter();
                if (test_flags_any(arg0 + 0x5EC, 4) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x3F0) = temp_r31_2;
                    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 4, 5);
                }
            }
        }
    }
}

int TObjPlayer__sub_801CFAA4(void* p) { return try_apply_status_action__10TObjPlayerFi(p); }

void dispatch_run_state__10TObjPlayerFis(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void *))TObjPlayer__sub_801CFAA4)((void *) arg0);
        return;
      case 2:
        ((TObjPlayer *)arg0)->select_run_request();
        return;
      case 3:
        ((TObjPlayer *)arg0)->try_trigger_effect();
        return;
      case 8:
        ((TObjPlayer *)arg0)->handle_ring_release();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_6x42_run_to_position();
        return;
      case 0:
        ((s32 (*)(void *))start_action__10TObjPlayerFPv)((void *) arg0);
        return;
      case 1:
        ((TObjPlayer *)arg0)->update_run_movement();
        return;
      case 6:
        ((TObjPlayer *)arg0)->apply_damage_and_reset();
        break;
    }
  }
}

void TObjPlayer__sub_801CFB40(void) {  }

void TObjPlayer__sub_801CFB44(void) {  }

void TObjPlayer__sub_801CFB48(void) {  }

void handle_6x41_move_to_position(void) {

}

void TObjPlayer__sub_801CFB50(void) {  }

void TObjPlayer__sub_801CFB54(void) {  }

void TObjPlayer__sub_801CFB58(void) {  }

void TObjPlayer__sub_801CFB5C(void) {  }

int TObjPlayer::apply_status_action_b() { return try_apply_status_action__10TObjPlayerFi(this); }

#pragma push
#pragma opt_lifetimes off
int TObjPlayer__sub_801CFB80(s32 arg0, s16 arg1) {
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->apply_status_action_b();
        return;
      case 2:
        ((s32 (*)(void))TObjPlayer__sub_801CFB5C)();
        return;
      case 3:
        ((s32 (*)(void))TObjPlayer__sub_801CFB58)();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801CFB54)();
        return;
      case 5:
        ((s32 (*)(void))TObjPlayer__sub_801CFB50)();
        return;
      case 0:
        ((s32 (*)(void))TObjPlayer__sub_801CFB48)();
        return;
      case 1:
        ((s32 (*)(void))TObjPlayer__sub_801CFB44)();
        return;
      case 6:
        ((s32 (*)(void))TObjPlayer__sub_801CFB40)();
        break;
    }
  }
}
extern int fold_flush_5;
#pragma pop

#pragma push
#pragma opt_lifetimes off
u8 *TObjPlayer__sub_801CFBFC(u8 *arg0) {
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
    var_r3 = (u8 *) ((void *) var_r12(var_r3));
    return var_r3;
  }
  var_r3 = (u8 *) (*((u8 **) (((s8 *) var_r31) + 0x380)));
  var_r12 = *((s16 (**)(void *)) (((s8 *) var_r3) + 8));
  var_r12 = *((s16 (**)(void *)) (((s8 *) var_r12) + 0x58));
  var_r3 = (u8 *) ((void *) var_r12(var_r3));
  return var_r3;
}
extern int fold_flush_6;
#pragma pop

s32 update_combat_stats__10TObjPlayerFPv(u8 *arg0) {
    f32 temp_f1;
    f32 temp_f31;
    s32 temp_r3;

    if (is_inactive__10TObjPlayerFv() == 0) {
        return 0;
    }
    temp_f31 = apply_stat_multipliers_default__10TObjPlayerFv((void *) (arg0 + 0x5E0), (void *) (arg0));
    temp_f1 = temp_f31 * ((f32 (*)(int))sin_table_lookup)((int) (*(s32 *)((s8 *)arg0 + 0x3F0)));
    *(f32 *)((s8 *)arg0 + 0x308) = temp_f1;
    *(f32 *)((s8 *)arg0 + 0x30C) = (f32) TObjPlayer__data_805DC36C;
    *(f32 *)((s8 *)arg0 + 0x310) = (f32) (temp_f31 * ((f32 (*)(int, f32))cos_table_lookup)((int) (*(s32 *)((s8 *)arg0 + 0x3F0)), (f32) (temp_f1)));
    if (((TObjPlayer *)arg0)->check_actor_blocking_move() != 0) {
        TObjPlayer__sub_8001053C((void *) (arg0));
        return 0;
    }
    temp_r3 = ((s32 (*)(void *))resolve_move_collision__10TObjPlayerFv)((void *) (arg0));
    if (temp_r3 == 0) {
        return 1;
    }
    if ((is_locally_controlled__10TObjPlayerFPv((void *) (arg0)) != 0) && (((TLobby *)arg0)->check_player_flag1() == 0) && (temp_r3 == 4)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void TObjPlayer::calc_movement_target(s32 arg1, f32 *arg2, f32 *arg3) {
    u8 *arg0 = (u8 *)this;
    *arg2 = (lbl_805DC388 * sin_table_lookup(arg1)) + *(f32 *)((s8 *)arg0 + 0x38);
    *arg3 = (lbl_805DC388 * cos_table_lookup(arg1)) + *(f32 *)((s8 *)arg0 + 0x40);
}
extern int fold_flush_7;
#pragma pop

void TObjPlayer::reset_and_flag() { ((int (*)(void*))TObjPlayer__sub_8001053C)(this); sub_800E2DE4((s32)((void*)256)); }

void TObjPlayer::update_walk_movement() {
    s32 ang;
    f32 dist;
    Plr_801CFDF8 *self = (Plr_801CFDF8 *)this;
    self->target_rot = ((TObjPlayer *)(((TObjPlayer *)self)->get_position_ptr()))->calc_angle_to(&self->tx);
    self->rot = approach_angle_adaptive(self->rot, self->target_rot);
    ang = lerp_angle_half__10TObjPlayerFUsUs(self->rot, self->target_rot);
    self->vx = TObjPlayer__sub_801BF814(self->motion) * sin_table_lookup(ang);
    self->vy = TObjPlayer__data_805DC36C;
    self->vz = TObjPlayer__sub_801BF814(self->motion) * cos_table_lookup(ang);
    dist = (self->tx - self->x) * (self->tx - self->x) + (self->tz - self->z) * (self->tz - self->z);
    if ((lbl_805DC3B4 * TObjPlayer__sub_801BF814(self->motion)) * (lbl_805DC3B4 * TObjPlayer__sub_801BF814(self->motion)) > dist) {
        ((FlagWord *)(self->flags))->set(4);
    }
    if (((void * (*)(void *))resolve_move_collision__10TObjPlayerFv)(self) == NULL) {
        ((TObjPlayer *)self)->apply_velocity();
    } else {
        ((FlagWord *)(self->flags))->set(4);
    }
    play_footstep_sound__10TObjPlayerFv(self, TObjPlayer__data_805DC360, lbl_805DC394);
    ((TObjPlayer *)self)->emit_footstep_effect(TObjPlayer__data_805DC360, lbl_805DC394);
}

void set_attack_state__10TObjPlayerFPv(u8 *arg0) {
    f32 temp_f31;
    f32 temp_f1;
    s16 temp_r3;

    *(s32 *)((s8 *)arg0 + 0x33C) = 2;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, *(s16 *)((s8 *)arg0 + 0x326), 6);
    temp_r3 = ((s32 (*)(void *))TObjPlayer__sub_801CFBFC)(arg0);
    if (((TObjPlayer *)arg0)->is_matching_id(temp_r3) != 0) {
        ((TObjPlayer *)arg0)->set_action_flag();
    }
    apply_stats_and_update__10TObjPlayerFPv(arg0 + 0x5E0, arg0);
    ((s32 (*)(void *, s32, s16))set_action_state__10TObjPlayerFPvss)(arg0, 2, temp_r3);
    temp_f31 = TObjPlayer__sub_801D2858(arg0 + 0x5E0);
    temp_f1 = ((f32 (*)(void *))get_action_rate_entry)(arg0);
    ((TObjEnemy *)arg0)->sub_800A7798(temp_f1 * temp_f31);
}

void handle_6x40_walk_to_position(void *pkt) {
    Cmd_801D0000 cmd;
    Player_801D0000 *p;
    init_6x40_walk_packet(&cmd);
    ((TObjPlayer *)(&cmd))->copy_6x40_walk_to_position_packet(pkt);
    ((TNpcPlayer *)(&cmd))->swap_endian();
    if (validate_6x40_walk_to_position(&cmd) != 0) {
        p = (Player_801D0000 *)((void * (*)(s32))get_player_by_client_id)(cmd.id);
        if (p != 0 && is_in_tl03_state__10TObjPlayerFv(p) != 0 && test_action_mask__10TObjPlayerFl(p, 0x1E) != 0) {
            p->x = cmd.x;
            p->z = cmd.z;
            ((TTecLuker *)(p->luker))->set_state(cmd.state);
            ((void (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(p, 2, 0);
        }
    }
}

void TObjPlayer::send_6x40_walk_to_position() {
    Npc_801D00B0 *arg0 = (Npc_801D00B0 *)this;
    Msg_801D00B0 m;
    if (((s32 (*)(void))update_combat_stats__10TObjPlayerFPv)() != 0) {
        calc_movement_target(arg0->f3f0, &arg0->x, &arg0->z);
        ((FlagWord *)(arg0->sub))->reset();
        if (((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x100000) != 0) {
            ((FlagWord *)(arg0->sub))->set(8);
        }
        if ((arg0 == NULL) || (obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0)) {
            init_6x40_walk_packet(&m);
            m.f2 = get_entity_id(arg0);
            m.x = arg0->x;
            m.z = arg0->z;
            m.v = TObjPlayer__sub_801BFFA0(arg0->sub);
            ((TNpcPlayer *)(&m))->sync_from_lobby();
        }
    }
}

void TObjPlayer::handle_ring_hit() {
    s32 arg0 = (s32)this;
    if (((s32 (*)(s32, s32))test_flags_any)(arg0 + 0x5EC, 4) != 0) {
        ((FlagWord *)(arg0 + 0x5EC))->clear(4);
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0x01C00000);
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 0);
    }
}

void TObjPlayer::check_ring_action() {
    s32 arg0 = (s32)this;
    if (((s32 (*)(s32, s32))test_flags_any)(arg0 + 0x5EC, 4) != 0) {
        ((FlagWord *)(arg0 + 0x5EC))->clear(4);
        ((s32 (*)(s32, s32))set_ring_action__10TObjPlayerFPvi)(arg0 + 0x5E0, 0);
        ((s32 (*)(s32, s32, s32))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 5);
    }
}

void TObjPlayer::select_walk_request() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    s32 temp_r31;
    s32 temp_r31_2;

    temp_r31 = ((TObjPlayer *)(arg0 + 0x550))->get_target_field_1c();
    temp_f31 = ((TObjPlayer *)(arg0 + 0x550))->get_attached_float_24();
    if ((((TObjPlayer *)arg0)->handle_palette_button_input() == 0) || (((TObjPlayer *)arg0)->check_flag_48() == 0)) {
        if (temp_f31 < TObjPlayer__data_805DC368) {
            if (test_flags_any(arg0 + 0x5EC, 4) != 0) {
                ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 1, 5);
                return;
            }
            return;
        } else {
            temp_r31_2 = ((s32 (*)(void *, int))calc_scaled_value__10TObjPlayerFii)(arg0, temp_r31);
            if (temp_f31 > TObjPlayer__data_805DC3AC) {
                ((TObjPlayer *)(arg0 + 0x5E0))->increment_run_counter();
            }
            if (((s32 (*)(void *, int))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x100000) != 0) {
                if (test_flags_any(arg0 + 0x5EC, 4) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x3F0) = temp_r31_2;
                    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 2, 5);
                }
            } else if (test_flags_any(arg0 + 0x5EC, 4) != 0) {
                *(s32 *)((s8 *)arg0 + 0x3F0) = temp_r31_2;
                if ((f32) TObjPlayer__sub_801D2870((u8 *)&this->m_5e0) < TObjPlayer__data_805DC378) {
                    ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 2, 5);
                    return;
                }
                ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)(arg0, 4, 5);
            }
        }
    }
}

int TObjPlayer__sub_801D03BC(void* p) { return try_apply_status_action__10TObjPlayerFi(p); }

void run_walk_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  int new_var;
  new_var = ((u32) arg1) <= 8U;
  {
    switch (arg1)
    {
      case 7:
        ((s32 (*)(void *))TObjPlayer__sub_801D03BC)((void *) arg0);
        return;
      case 2:
        ((TObjPlayer *)arg0)->select_walk_request();
        return;
      case 3:
        ((TObjPlayer *)arg0)->check_ring_action();
        return;
      case 8:
        ((TObjPlayer *)arg0)->handle_ring_hit();
        return;
      case 5:
        ((TObjPlayer *)arg0)->send_6x40_walk_to_position();
        return;
      case 0:
        ((s32 (*)(void *))set_attack_state__10TObjPlayerFPv)((void *) arg0);
        return;
      case 1:
        ((TObjPlayer *)arg0)->update_walk_movement();
        return;
      case 6:
        ((TObjPlayer *)arg0)->reset_and_flag();
        break;
    }
  }
}

s32 TObjPlayer::get_idle_animation() {
    if (this->actorFlags & 0x100000) {
        return ((VObj_8_e57d67 *)((u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x380))))->m18();
    }
    return ((VObj_8_e57d67 *)((u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x380))))->m21();
}

void TObjPlayer::cleanup_idle_entry() { obj_clearFlags30((u32)((void*)3840)); sub_8011E204__10TObjPlayerFl(this, (void*)128); ((int (*)(void*, void*))set_ring_action__10TObjPlayerFPvi)((char*)this + 0x5e0, (void*)0); ((int (*)(void*))clear_status_bit6__10TObjPlayerFPv)(this); ((int (*)(void*))TObjPlayer__sub_8001053C)(this); ((int (*)(void*))zero_vec3)((char*)this + 0x5fc); }

void TObjPlayer::exit_idle_state() {  }

void TObjPlayer::update_action(s32 arg0) {
    u32 temp_r3;

    temp_r3 = ((u32 (*)(void))resolve_move_collision__10TObjPlayerFv)();
    if (temp_r3 == 0U) {
        ((TObjPlayer *)arg0)->apply_velocity();
    } else if (temp_r3 == 1U) {
        ((TObjPlayer *)arg0)->rewind_position_history();
    }
    if ((((TObjPlayer *)arg0)->is_newman() != 0) && (is_lobby_floor_15__15TFontSmallLobbyFv() == 0) && (TObjPlayer__sub_801AF290(arg0) != 0)) {
        add_actor_tp(arg0, 1);
    }
    if ((((s32 (*)(s32))is_android_player)(arg0) != 0) && (is_lobby_floor_15__15TFontSmallLobbyFv() == 0) && (TObjPlayer__sub_801AF290(arg0) != 0)) {
        add_actor_hp(arg0, 1);
    }
}

void TObjPlayer::start_animation() {
    *(s32 *)((s8 *)this + 0x33C) = 1;
    ((s32 (*)(void *, s16, s32))run_action_state_phase__10TObjPlayerFisi)(this, this->mode, 6);
    cleanup_idle_entry();
    set_action_state__10TObjPlayerFPvss(this, 1, ((s32 (*)(void *))get_idle_animation__10TObjPlayerFv)(this));
}

void handle_6x3F_set_position(void *arg0) {
    Msg_801D0634 m;
    Player_801D0634 *p;
    ((TObjPlayer *)(&m))->init_set_position_packet();
    ((void (*)(void *, void *))TObjPlayer__sub_801D2540)(&m, arg0);
    ((TObjPlayer *)(&m))->byteswap_set_position_cmd();
    if (validate_6x3F_set_position(&m) != 0) {
        p = (Player_801D0634 *)((void * (*)(s32))get_player_by_client_id)(m.id);
        if (p != NULL) {
            ((TUnk_804B9870 *)p)->set_position_from(m.vec);
            set_flag_400000__10TObjPlayerFi((s32)p);
            if (m.floor >= 0) {
                ((TObjPlayer *)p)->set_floor(m.floor);
                ((TObjPlayer *)p)->set_floor_index(get_floor_area(m.floor));
            }
            if (m.room >= 0) {
                ((TObjPlayer *)p)->set_room(m.room);
            }
            p->ang = m.ang;
            if (m.flag != 1) {
                ((TUnk_804B9870 *)p)->obj_clearFlags30((u32)0x100000);
            } else {
                obj_setFlags30(p, 0x100000);
            }
            ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 1, 0);
        }
    }
}

void handle_6x3E_stop_at_position(void *arg0) {
    Msg_801D0634 m;
    Player_801D0724 *p;
    ((TNpcPlayer *)(&m))->init_6x3E_packet();
    ((void (*)(void *, void *))TObjPlayer__sub_801D25AC)(&m, arg0);
    ((TNpcPlayer *)(&m))->bswap_6x3E();
    if (validate_6x3E_stop_at_position(&m) == 0) {
        return;
    }
    p = (Player_801D0724 *)((void * (*)(s32))get_player_by_client_id)(m.id);
    if (p == NULL) {
        return;
    }
    ((TUnk_804B9870 *)p)->set_position_from(m.vec);
    if (m.floor >= 0) {
        ((TObjPlayer *)p)->set_floor(m.floor);
        ((TObjPlayer *)p)->set_floor_index(get_floor_area(m.floor));
    }
    p->ang = m.ang;
    if (is_in_tl03_state__10TObjPlayerFv(p) == 0 || test_action_mask__10TObjPlayerFl(p, 0x8100) != 0 ||
        (test_action_mask__10TObjPlayerFl(p, 0x200) != 0 && p->f328 <= 2) ||
        (test_action_mask__10TObjPlayerFl(p, 0x4000) != 0 && p->f328 == 0)) {
        return;
    }
    if (m.room >= 0) {
        ((TObjPlayer *)p)->set_room(m.room);
    }
    switch (m.flag) {
    case 0:
        ((TUnk_804B9870 *)p)->obj_clearFlags30((u32)0x100000);
        break;
    case 1:
        obj_setFlags30(p, 0x100000);
        break;
    }
    ((void (*)(void *, s32, s32))run_action_state_phase__10TObjPlayerFisi)(p, 1, 0);
}

void TObjPlayer::update_position_from_target() { ((int (*)(void*, void*, void*))send_idle_return_event__10TObjPlayerFPvPvs)(this, (char*)this + 0x38, *(void**)((char*)this + 0x60)); }

void send_idle_return_event__10TObjPlayerFPvPvs(void *player, void *arg1, s16 arg2) {
    Msg_801D08B0 m;
    s32 t;
    if ((player == NULL) || (((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        t = ((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(player, 0x100000) != 0 ? 1 : 0;
        ((TObjPlayer *)(&m))->init_set_position_packet();
        m.f2 = get_entity_id(player);
        m.f4 = t;
        m.f6 = arg2;
        m.f8 = ((TObjPlayer *)player)->get_field_3e4();
        m.fa = ((TUnk_804B9870 *)player)->get_stat_by_key_state();
        VecCopy__FP3VecPC3Vec(m.vec, arg1);
        TObjPlayer__sub_801C18E0(&m);
    }
}

void TObjPlayer::send_6x3E_stop_at_position() {
    Player_801D094C *arg0 = (Player_801D094C *)this;
    Msg_801D094C m;
    s32 t;
    if ((arg0 == NULL) || (((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        t = ((s32 (*)(void *, s32))obj_testFlags30__13TUnk_804AF8A0FUl)(arg0, 0x100000) != 0 ? 1 : 0;
        ((TNpcPlayer *)(&m))->init_6x3E_packet();
        m.f2 = get_entity_id(arg0);
        m.f4 = t;
        m.f6 = this->rotation_y;
        ((TObjPlayer *)arg0)->sync_current_floor();
        ((TObjPlayer *)arg0)->sync_current_area();
        m.f8 = ((TObjPlayer *)arg0)->get_field_3e4();
        m.fa = ((TUnk_804B9870 *)arg0)->get_stat_by_key_state();
        VecCopy__FP3VecPC3Vec(m.vec, arg0->vec);
        ((TNpcPlayer *)(&m))->send_6x3E();
    }
}

void TObjPlayer__sub_801D09F4(void) {  }

void TObjPlayer::complete_idle_state() {  }

void TObjPlayer::check_idle_movement_request() {
    f32 temp_f31;
    s32 temp_r31;
    u8 *arg0 = (u8 *)this;
    temp_f31 = ((TObjPlayer *)(arg0 + 0x550))->get_attached_float_24();
    temp_r31 = ((TObjPlayer *)(arg0 + 0x550))->get_target_field_1c();
    if ((((TObjPlayer *)arg0)->handle_palette_button_input() == 0) || (((TObjPlayer *)arg0)->check_flag_48() == 0)) {
        *(s16 *)((s8 *)arg0 + 0x3C0) = ((TObjPlayer *)arg0)->select_idle_action();
        if (is_action_id_none((int) (*(s16 *)((s8 *)arg0 + 0x3C0))) == 0) {
            if (*(s16 *)((s8 *)arg0 + 0x3C0) == (*(VObj_8_684c72 **)(arg0 + 0x380))->m65() ||
                *(s16 *)((s8 *)arg0 + 0x3C0) == (*(VObj_8_684c72 **)(arg0 + 0x380))->m66()) {
                ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *) (arg0), 0x18, 5);
            } else {
                ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *) (arg0), 0x17, 5);
            }
            return;
        }
        if (temp_f31 >= TObjPlayer__data_805DC368) {
            *(s32 *)((s8 *)arg0 + 0x3F0) = ((s32 (*)(void *, int))calc_scaled_value__10TObjPlayerFii)((void *) (arg0), (int) (temp_r31));
            ((s32 (*)(void *, int, int))run_action_state_phase__10TObjPlayerFisi)((void *) (arg0), 2, 5);
        }
    }
}

int TObjPlayer::try_apply_status_action_2() { return try_apply_status_action__10TObjPlayerFi(this); }

void run_idle_state_phase__10TObjPlayerFis(s32 arg0, s16 arg1) {
  s32 new_var;
  {
    switch (arg1)
    {
      case 7:
        ((TObjPlayer *)arg0)->try_apply_status_action_2();
        return;
      new_var = arg0;
      case 2:
        ((TObjPlayer *)new_var)->check_idle_movement_request();
        return;
      case 3:
        TObjPlayer::complete_idle_state();
        return;
      case 8:
        ((s32 (*)(void))TObjPlayer__sub_801D09F4)();
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

void run_action_state_phase__10TObjPlayerFisi(s32 arg0, s16 arg1, s32 arg2) {
    switch (arg1) {
    case 1:
        ((void (*)(s32, s32))run_idle_state_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 2:
        ((void (*)(s32, s32))run_walk_state_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 3:
        ((void (*)(s32, s32))TObjPlayer__sub_801CFB80)(arg0, arg2);
        break;
    case 4:
        ((void (*)(s32, s32))dispatch_run_state__10TObjPlayerFis)(arg0, arg2);
        break;
    case 5:
        ((void (*)(s32, s32))run_attack_stage1_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 6:
        ((void (*)(s32, s32))run_attack_stage2_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 7:
        ((void (*)(s32, s32))run_attack_stage3_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 8:
        ((void (*)(s32, s32))dispatch_technique_cast_state__10TObjPlayerFis)(arg0, arg2);
        break;
    case 9:
        ((void (*)(s32, s32))dispatch_photon_blast_action__10TObjPlayerFis)(arg0, arg2);
        break;
    case 10:
        ((void (*)(s32, s32))run_guard_reaction_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 11:
        ((void (*)(s32, s32))TObjPlayer__sub_801CB580)(arg0, arg2);
        break;
    case 12:
        ((void (*)(s32, s32))run_switch_interaction_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 13:
        ((void (*)(s32, s32))run_hurt_state_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 14:
        ((void (*)(s32, s32))run_fall_reaction_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 15:
        ((void (*)(s32, s32))run_death_state_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 18:
        ((void (*)(s32, s32))run_revival_state_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 16:
        ((void (*)(s32, s32))run_service_hold_state_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 19:
        ((void (*)(s32, s32))TObjPlayer__sub_801C9648)(arg0, arg2);
        break;
    case 20:
        ((void (*)(s32, s32))run_warp_action_phase__10TObjPlayerFis)(arg0, arg2);
        break;
    case 21:
        ((void (*)(s32, s32))TObjPlayer__sub_801C8C50)(arg0, arg2);
        break;
    case 22:
        ((void (*)(s32, s32))TObjPlayer__sub_801C8A28)(arg0, arg2);
        break;
    case 23:
        ((void (*)(s32, s32))TObjPlayer__sub_801C869C)(arg0, arg2);
        break;
    case 24:
        ((void (*)(s32, s32))TObjPlayer__sub_801C7A6C)(arg0, arg2);
        break;
    }
}

void TObjPlayer::update_lobby_chair(s32 value) { TObjPlayer__sub_801D1024((char*)this + 0x34c, value); }

void TObjPlayer::get_chair_state(s32 value) { TObjPlayer__sub_801D102C((char*)this + 0x34c, value); }

int TObjPlayer__sub_801D0D58(void* p) { return TBoss7LaserPtcl__sub_8035AF14((char*)p + 0x34c); }

void TObjPlayer__sub_801D0D7C(void* p) { *(u32*)((char*)p + 0x334) &= 0xfbffffff; }

void TObjPlayer__sub_801D0D8C(void* p) { *(u32*)((char*)p + 0x334) &= 0xf7ffffff; }

void TObjPlayer::clear_state_flag() { this->m_334 &= 0xefffffff; }

int TObjPlayer__sub_801D0DAC(void* p) { return ((int (*)(void*))TObjPlayer__sub_801D1034)((char*)p + 0x34c); }

int TObjPlayer::start_action18_sub() { return ((int (*)(void*))TObjPlayer__sub_801D103C)((char*)this + 0x34c); }

int TObjPlayer__sub_801D0DF4(void* p) { return fn_8035AF18((char*)p + 0x34c); }

void TObjPlayer__sub_801D0E18(void* p) { *(u32*)((char*)p + 0x334) |= 0x4000000; }

int TObjPlayer::get_action_flag() { return (this->m_334 >> 27) & 0x1; }

void TObjPlayer::forward_1D1044_at_34c(s16 value) { TObjPlayer__sub_801D1044((char*)this + 0x34c, value); }

int TObjPlayer::is_action_flag_28() { return (this->m_334 >> 28) & 0x1; }

void TObjPlayer::set_anim_flag() { this->m_334 |= 0x8000000; }

void TObjPlayer__sub_801D0E74(void* p) { *(u32*)((char*)p + 0x334) |= 0x10000000; }

void TObjPlayer__sub_801D0E84(void* p) { *(u32*)((char*)p + 0x334) &= 0xdfffffff; }

int get_flag__10TObjPlayerFPv(void* p) { return (*(u32*)((char*)p + 0x334) >> 29) & 0x1; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
u8 *TObjPlayer__sub_801D0EA0(u8 *arg0, u8 *arg1) {
    ((s32 (*)(void))TFontSmallLobby__sub_801C0228)();
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_C *)((s32) arg0 + 8) = *(const ByteBlock_C *)((s32) arg1 + 8);
    *(ByteBlock_C *)((s32) arg0 + 0x14) = *(const ByteBlock_C *)((s32) arg1 + 0x14);
    return arg0;
}
extern int fold_flush_8;
#pragma pop

short query_child_state2__10TObjPlayerFPv(void *arg0) {
    struct VObj_801D0F0C *o = (struct VObj_801D0F0C *)*(void **)((s8 *)arg0 + 0x380);
    return o->m23();
}

void release_control_lock__10TObjPlayerFPv(void* p) { ((TObjPlayer *)p)->clear_flag_200(); }

void TObjPlayer::clear_flag_200() { this->m_334 &= 0xfffffdff; }

void TObjPlayer__sub_801D0F70(void* p) { *(u32*)((char*)p + 0x334) |= 0x200; }

void*TObjPlayer::get_field4_ptr() { return (char*)this + 0x4; }

int copy_position__10TObjPlayerFPv(void* p) { return ((int (*)(void*))VecCopy__FP3VecPC3Vec)((char*)p + 0x4); }

void TObjPlayer::set_float_param(s16 arg1) {
    s32 arg0 = (s32)this;
    ((TObjPlayer *)(arg0 + 0x4AC))->set_field_3c((f32) (s32) arg1);
}

int query_field_340__10TObjPlayerFPv(void* p) { return ((TObjPlayer *)((char*)p + 0x340))->update_action_palette(); }

int is_android_player(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_ANDROID) != 0; }

void TObjPlayer__sub_801D1024(void* p, s32 v) { *(s32*)((char*)p + 0x10) = v; }

void TObjPlayer__sub_801D102C(void* p, s32 v) { *(s32*)((char*)p + 0xc) = v; }

s32 TObjPlayer__sub_801D1034(void* p) { return *(s32*)((char*)p + 0xc); }

s16 TObjPlayer__sub_801D103C(void* p) { return *(s16*)((char*)p + 0x0); }

void TObjPlayer__sub_801D1044(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }

void TObjPlayer__sub_801D104C(void* p) { *(s16*)((char*)p + 0x6) = 8; }

void TObjPlayer__sub_801D1058(u8 *arg0) {
  s16 temp_r4;
  temp_r4 = (*((s16 *) (((s8 *) arg0) + 6)) = (*((s16 *) (((s8 *) arg0) + 6))) - 1);
  if (temp_r4 < 0)
  {
    *((s16 *) (((s8 *) arg0) + 6)) = 0;
  }
}

u8 TObjPlayer__sub_801D1078(u8 *arg0) {
    return (u8) (*(s16 *)((s8 *)arg0 + 6) <= 0);
}

void TObjPlayer__sub_801D1090(void* p) { *(s16*)((char*)p + 0x8) = 8; }

void TObjPlayer__sub_801D109C(u8 *arg0) {
  s16 temp_r4;
  s8 *new_var;
  temp_r4 = (*((s16 *) (new_var + 8)) = (*((s16 *) (((s8 *) arg0) + 8))) - 1);
  new_var = (s8 *) arg0;
  if (temp_r4 < 0)
  {
    *((s16 *) (((s8 *) arg0) + 8)) = 0;
  }
}

u8 TObjPlayer__sub_801D10BC(u8 *arg0) {
    return (u8) (*(s16 *)((s8 *)arg0 + 8) <= 0);
}

void TObjPlayer__sub_801D10D4(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_32__FPUl((char*)p + 0x4); }

void *TObjPlayer::copy_lobby_font_header(void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(this));
    *(void **)((s8 *)this + 0x4) = *(void **)((s8 *)arg1 + 0x4);
    return this;
}

void TObjPlayer__sub_801D1144(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0xB0;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::swap_endian32() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); }

void *TObjPlayer__sub_801D1194(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(arg0));
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

void *TObjPlayer::copy_packet_header_6xAB(void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(this));
    *(u16 *)((s8 *)this + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    this->m_id = *(u16 *)((s8 *)arg1 + 0x6);
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

void *TObjPlayer::copy_packet_header_6x58(void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(this));
    *(u16 *)((s8 *)this + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    this->m_id = *(u16 *)((s8 *)arg1 + 0x6);
    return this;
}

void TObjPlayer__sub_801D13EC(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x58;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::handle_recv_packet() { bswap_packet(); update_players__6TLobbyFv((s32)this); }

void TObjPlayer__sub_801D1440(void* p) { *(u16*)((char*)p + 0x6) |= 0x1; }

void* handle_6x57__10TObjPlayerFPv(void* p) { TFontSmallLobby__sub_801C0228(p); return p; }

void TObjPlayer::set_cmd_87() { *(u8*)((char*)this + 0x0) = 87; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::draw_and_send() { TFontSmallLobby__sub_801C01BC(this); send_subcommand(this); }

void TObjPlayer::swap_endian_words() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); bswap_32__FPUl((char*)this + 0x8); bswap_32__FPUl((char*)this + 0xc); bswap_32__FPUl((char*)this + 0x10); }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
u8 *TObjPlayer__sub_801D1514(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(arg0));
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_C *)((s32) arg0 + 8) = *(const ByteBlock_C *)((s32) arg1 + 8);
    return arg0;
}
extern int fold_flush_9;
#pragma pop

void TObjPlayer::init_position_packet() { *(float*)((char*)this + 0x10) = TObjPlayer__data_805DC36C; *(float*)((char*)this + 0xc) = TObjPlayer__data_805DC36C; *(float*)((char*)this + 0x8) = TObjPlayer__data_805DC36C; *(unsigned char*)((char*)this + 0x0) = 86; *(unsigned char*)((char*)this + 0x1) = 5; }

void TObjPlayer::update_and_send2() { swap_endian_words(); send_subcommand(this); }

void TObjPlayer::swap_and_send() { swap_endian(); send_subcommand(this); }

void TObjPlayer::swap_endian() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); bswap_32__FPUl((char*)this + 0x8); bswap_32__FPUl((char*)this + 0xc); bswap_32__FPUl((char*)this + 0x10); bswap_32__FPUl((char*)this + 0x14); bswap_32__FPUl((char*)this + 0x18); bswap_32__FPUl((char*)this + 0x1c); }

void TObjPlayer__sub_801D1658(void* a0) { *(int*)((char*)a0 + 0x4) = 0; *(float*)((char*)a0 + 0x10) = TObjPlayer__data_805DC36C; *(float*)((char*)a0 + 0xc) = TObjPlayer__data_805DC36C; *(float*)((char*)a0 + 0x8) = TObjPlayer__data_805DC36C; *(float*)((char*)a0 + 0x1c) = TObjPlayer__data_805DC36C; *(float*)((char*)a0 + 0x18) = TObjPlayer__data_805DC36C; *(float*)((char*)a0 + 0x14) = TObjPlayer__data_805DC36C; *(unsigned char*)((char*)a0 + 0x0) = 85; *(unsigned char*)((char*)a0 + 0x1) = 8; }

void TObjPlayer::set_type_53() { *(u8*)((char*)this + 0x0) = 83; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::send_name() { TFontSmallLobby__sub_801C01BC(this); send_subcommand(this); }

void TObjPlayer::swap_stats_bytes() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); bswap_32__FPUl((char*)this + 0x8); }

void*TObjPlayer::copy_font_state(void* a1) { TFontSmallLobby__sub_801C0228(this); *(short*)((char*)this + 0x4) = *(short*)((char*)a1 + 0x4); *(short *)&this->m_id = *(short*)((char*)a1 + 0x6); *(void* *)&this->m_prev = *(void**)((char*)a1 + 0x8); return this; }

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

void TObjPlayer::broadcast_lobby_display() { TFontSmallLobby__sub_801C01BC(this); send_subcommand(this); }

void TObjPlayer::bswap_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void*TObjPlayer::copy_head_fields(void* a1) { TFontSmallLobby__sub_801C0228(this); *(short*)((char*)this + 0x4) = *(unsigned short*)((char*)a1 + 0x4); this->m_id = *(short*)((char*)a1 + 0x6); return this; }

void TObjPlayer::init_6x89_packet() {
    Pkt_801D1888 *p = (Pkt_801D1888 *)this;
    p->a = 0xFFFF;
    p->b = 0;
    p->cmd = 0x89;
    p->size = 2;
}

void TObjPlayer::init_revive_packet() { *(u8*)((char*)this + 0x0) = 78; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::bswap_font_lobby2() { TFontSmallLobby__sub_801C01BC(this); send_subcommand(this); }

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

void TObjPlayer::init_6x4C_packet() { this->m_id = 0; *(short*)((char*)this + 0x4) = 0; *(float*)((char*)this + 0xc) = TObjPlayer__data_805DC36C; *(float*)((char*)this + 0x8) = TObjPlayer__data_805DC36C; *(unsigned char*)((char*)this + 0x0) = 76; *(unsigned char*)((char*)this + 0x1) = 4; }

void TObjPlayer::send_head_pair_packet() { bswap_head_pair(); send_subcommand(this); }

void TObjPlayer::read_swapped_fields() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); ((int (*)(void*))TObjPlayer__sub_801D28DC)((char*)this + 0x8); }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
u8 *copy_6x4b_hit_by_enemy_packet__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1) {
    ((u8 * (*)(void *))TFontSmallLobby__sub_801C0228)(arg0);
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(ByteBlock_8 *)((s32) arg0 + 8) = *(const ByteBlock_8 *)((s32) arg1 + 8);
    return arg0;
}
extern int fold_flush_10;
#pragma pop

void TObjPlayer::reset_action_state() { this->m_id = 0; *(short*)((char*)this + 0x4) = 0; *(float*)((char*)this + 0xc) = TObjPlayer__data_805DC36C; *(float*)((char*)this + 0x8) = TObjPlayer__data_805DC36C; *(unsigned char*)((char*)this + 0x0) = 75; *(unsigned char*)((char*)this + 0x1) = 4; }

void TObjPlayer::handle_recv_state() { read_swapped_fields(); send_subcommand(this); }

void TObjPlayer::swap_endian_field() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); }

void TObjPlayer__sub_801D1BB0(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x51;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::refresh_players() { swap_endian_field(); update_players__6TLobbyFv((s32)this); }

void TObjPlayer::bswap_field4() { ((G_ClientIDHeader *)this)->bswap(); bswap_32__FPUl((char*)this + 0x4); }

void* copy_font__10TObjPlayerFPvPv(void* p, void* a1) { TFontSmallLobby__sub_801C0228(p); *(void**)((char*)p + 0x4) = *(void**)((char*)a1 + 0x4); return p; }

void TObjPlayer__sub_801D1C70(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x50;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::sync_players() { bswap_field4(); update_players__6TLobbyFv((s32)this); }

void TObjPlayer::init_shield_attack_packet() { *(u8*)((char*)this + 0x0) = 74; *(u8*)((char*)this + 0x1) = 1; }

void TObjPlayer::draw_font_and_send() { TFontSmallLobby__sub_801C01BC(this); send_subcommand(this); }

void TObjPlayer::swap_endian16() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void *TObjPlayer__sub_801D1D44(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(arg0));
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
        ((TNpcPlayer *)(&pkt->targets[i]))->byteswap_pos();
    }
}

void TObjPlayer::swap_endian_shorts() { bswap_16__FPUs((char*)this + 0x2); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 copy_photon_blast_data__10TObjPlayerFiPv(s32 arg0, u8 *arg1) {
  s32 var_r30;
  s32 var_r3;
  s32 var_r5;
  s32 var_r6;
  u8 *var_r31;
  u8 *var_r4;
  var_r30 = arg0;
  var_r31 = (u8 *) arg1;
  TFontSmallLobby__sub_801C0228((void*)(arg0));
  var_r6 = *((s32 *) (((s8 *) var_r31) + 4));
  var_r3 = *((s32 *) (((s8 *) var_r31) + 8));
  if ((arg0 && arg0) && arg0)
  {
  }
  var_r5 = var_r30 + 8;
  var_r4 = (u8 *) (var_r31 + 8);
  *((s32 *) (((s8 *) var_r30) + 4)) = var_r6;
  *((s32 *) (((s8 *) var_r30) + 8)) = var_r3;
  *((ByteBlock_28 *) (var_r5 + 4)) = *((const ByteBlock_28 *) (((s32) var_r4) + 4));
  var_r5 += 0x28;
  var_r4 += 0x28;
  var_r3 = var_r30;
  return var_r3;
}
extern int fold_flush_11;
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void *TObjPlayer::init_6x49_packet() {
    TObjPlayer__sub_801D1F44((void*)((void *)((char *)this + 4)));
    __construct_array((void *)((char *)this + 12), fn_80152EF8, 0, 4, 10);
    *(u8 *)((s8 *)this + 0x0) = 73;
    *(u8 *)((s8 *)this + 0x1) = 13;
    return this;
}
extern int fold_flush_12;
#pragma pop

void TObjPlayer__sub_801D1F44(void* p) { *(s16*)((char*)p + 0x6) = 0; *(s16*)((char*)p + 0x4) = 0; *(s16*)((char*)p + 0x2) = 0; *(u8*)((char*)p + 0x1) = 0; *(u8*)((char*)p + 0x0) = 0; }
}

void send_photon_blast_targets_packet(u8 *player) {
    *(s8 *)((s8 *)player + 1) = (s8) ((((u32)TObjPlayer__sub_801D2004((u8 *)(player))) >> 2U) & 0x3F);
    ((s32)((TObjPlayer *)player)->byteswap_pb_targets_packet());
    send_subcommand(player);
}

int TObjPlayer::byteswap_pb_targets_packet() {
    Obj_801D1FA4 *arg0 = (Obj_801D1FA4 *)this;
    s32 i;
    ((G_ClientIDHeader *)arg0)->bswap();
    for (i = 0; i < *(s16 *)&this->m_id; i++) {
        ((TNpcPlayer *)(&arg0->e[i]))->byteswap_pos();
    }
    ((TObjPlayer *)((u8 *)arg0 + 4))->swap_endian_shorts();
}

u8 TObjPlayer__sub_801D2004(u8 *arg0) {
    return (u8) (0x34 - ((0xA - *(s16 *)((s8 *)arg0 + 6)) * 4));
}

void TObjPlayer::bswap_coords() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); }

void* TObjPlayer__sub_801D2058(void* p, void* a1) { TFontSmallLobby__sub_801C0228(p); *(short*)((char*)p + 0x4) = *(unsigned short*)((char*)a1 + 0x4); *(short*)((char*)p + 0x6) = *(short*)((char*)a1 + 0x6); return p; }

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
    TFontSmallLobby__sub_801C0228((void*)(this));
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
#pragma auto_inline on
#pragma dont_inline off
u8 *TObjPlayer__sub_801D21CC(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(arg0));
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_28 *)(arg0 + 4 + 4) = *(const ByteBlock_28 *)((s32) (arg1 + 4) + 4);
    return arg0;
}
extern int fold_flush_13;
#pragma pop

void TObjPlayer::swap_field6() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x6); }

void *TObjPlayer::copy_6x8d_technique_level_packet(void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(this));
    *(u8 *)((s8 *)this + 0x4) = *(u8 *)((s8 *)arg1 + 0x4);
    *(u8 *)((s8 *)this + 0x5) = *(u8 *)((s8 *)arg1 + 0x5);
    this->m_id = *(s16 *)((s8 *)arg1 + 0x6);
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

void *TObjPlayer::copy_6x45_attack_packet(void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(this));
    *(u16 *)((s8 *)this + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    this->m_id = *(s16 *)((s8 *)arg1 + 0x6);
    return this;
}

void *TObjPlayer__sub_801D2348(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(arg0));
    *(u16 *)((s8 *)arg0 + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    *(u16 *)((s8 *)arg0 + 0x6) = *(s16 *)((s8 *)arg1 + 0x6);
    return arg0;
}

void TObjPlayer::bswap_field4_sub() { ((G_ClientIDHeader *)this)->bswap(); ((TObjPlayer *)((char*)this + 0x4))->bswap_u16_pair_list(); }

void*TObjPlayer::build_packet_header() { TObjPlayer__sub_8012AF00((char*)this + 0x4); *(unsigned char*)(this) = 70; *(unsigned char*)((char*)this + 0x1) = 12; return this; }

void send_6x46_attack_finished(u8 *arg0) {
    *(s8 *)((s8 *)arg0 + 1) = (s8) ((((u32 (*)(void))get_6x46_strike_packet_size)() >> 2U) & 0x3F);
    TObjPlayer__sub_801D2448((void*)((void *) (arg0)));
    send_subcommand((void*)((void *) (arg0)));
}

void TObjPlayer__sub_801D2448(void* p) { ((G_ClientIDHeader *)p)->bswap(); ((TObjPlayer *)((char*)p + 0x4))->bswap_entry_list(); }

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
u8 get_6x46_strike_packet_size(s32 arg0) {
    return (u8) (0x30 - ((0xA - get_captured_target_count((s32 *)((void *) (arg0 + 4)))) * 4));
}
extern int fold_flush_14;
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

void *TObjPlayer__sub_801D24B0(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228((void*)((void*)((void*)(arg0))));
    *(u16 *)((s8 *)arg0 + 0x4) = *(s16 *)((s8 *)arg1 + 0x4);
    *(u16 *)((s8 *)arg0 + 0x6) = *(s16 *)((s8 *)arg1 + 0x6);
    return arg0;
}
extern int fold_flush_15;
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
void *TObjPlayer::copy_6x40_walk_to_position_packet(void *arg1) {
    TFontSmallLobby__sub_801C0228(this);
    ((Pkt_801D24F4 *)this)->pos = ((Pkt_801D24F4 *)arg1)->pos;
    return this;
}
extern int fold_flush_16;
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
u8 *TObjPlayer__sub_801D2540(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228((void*)((void*)(arg0)));
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)((s8 *)arg0 + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(ByteBlock_C *)((s32) arg0 + 0xC) = *(const ByteBlock_C *)((s32) arg1 + 0xC);
    return arg0;
}
extern int fold_flush_17;
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
u8 *TObjPlayer__sub_801D25AC(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228((void*)(arg0));
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)((s8 *)arg0 + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(ByteBlock_C *)((s32) arg0 + 0xC) = *(const ByteBlock_C *)((s32) arg1 + 0xC);
    return arg0;
}
extern int fold_flush_18;
#pragma pop

void TObjPlayer__sub_801D2618(void* p, f32 v) { *(f32*)((char*)p + 0xc0) = v; }

void TObjPlayer::set_action_flag_40() { this->animationFlags |= 0x40; }

void clear_status_bit6__10TObjPlayerFPv(void* p) { *(u32*)((char*)p + 0xb0) &= 0xffffffbf; }

f32 get_action_rate_entry(Obj_801D2640 *p) {
    return p->arr[p->idx].f;
}

void TObjPlayer::set_field_d4_and_flag_200(f32 value) {
    u8 *p = (u8 *)this;
    *(f32 *)(p + 0xD4) = value;
    ((TObjEnemy *)p)->set_flags_B0(0x200U);
}

int TObjPlayer__sub_801D2680(void *p) {
    return (*(u32 *)((char *)p + 0xB0) >> 6) & 1;
}

void TObjPlayer::set_action_flag() {
    this->animationFlags |= 0x80;
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
s32 TObjPlayer::get_field_4() { return *(s32*)((char*)this + 0x4); }
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
s16 TObjPlayer__sub_801D2824(void* p) { return *(s16*)((char*)p + 0x8); }
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
s16 TObjPlayer__sub_801D282C(void* p) { return *(s16*)((char*)p + 0x0); }
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
#pragma opt_common_subs off
void add_death_sink_progress(u8 *arg0, f32 farg0) {
    *(f32 *)((s8 *)arg0 + 8) = (f32) (*(f32 *)((s8 *)arg0 + 8) + farg0);
    if (*(f32 *)((s8 *)arg0 + 8) > TObjPlayer__data_805DC360) {
        *(f32 *)((s8 *)arg0 + 8) = (f32) TObjPlayer__data_805DC360;
    }
}
extern int fold_flush_19;
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

f32 TObjPlayer__sub_801D2858(void* p) { return *(f32*)((char*)p + 0x8); }
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
void TObjPlayer::increment_run_counter() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 4) = (s32) (*(s32 *)((s8 *)arg0 + 4) + 1);
}
extern int fold_flush_20;
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
s32 TObjPlayer__sub_801D2870(void* p) { return *(s32*)((char*)p + 0x4); }
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
s32 TObjPlayer__sub_801D2878(void* p) { return *(s32*)((char*)p + 0xc); }
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
int TObjPlayer::bswap_field_u32() { return bswap_32__FPUl(this); }
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
void* TObjPlayer__sub_801D28A0(void* p, void* a1) { TFontSmallLobby__sub_801C0228((void*)(p)); *(void**)((char*)p + 0x4) = *(void**)((char*)a1 + 0x4); return p; }
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
void TObjPlayer__sub_801D28DC(void* p) { bswap_32__FPUl(p); bswap_32__FPUl((char*)p + 0x4); }
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
u8 *copy_6x4c_hit_by_enemy_packet__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228((void*)((void*)(arg0)));
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(ByteBlock_8 *)((s32) arg0 + 8) = *(const ByteBlock_8 *)((s32) arg1 + 8);
    return arg0;
}
extern int fold_flush_21;
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
void *TObjPlayer::copy_packet_pos_6x42(void *arg1) {
    TFontSmallLobby__sub_801C0228(this);
    ((Pkt_801D2964 *)this)->pos = ((Pkt_801D2964 *)arg1)->pos;
    return this;
}
extern int fold_flush_22;
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
int TObjPlayer::clear_photon_blast_state() { return ((int (*)(void*, int))clear__8FlagWordFUl)((char*)this + 0x40, 62); }
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
int TObjPlayer::trigger_photon_blast() { return ((int (*)(void*, int))clear__8FlagWordFUl)((char*)this + 0x40, 4); }
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
int TObjPlayer::check_photon_blast_flag() { return ((int (*)(void*, int))set__8FlagWordFUl)((void*)((char*)this + 0x40), 8); }
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
int TObjPlayer::check_flag_clear() { return (((int (*)(void*, int))test_flags_any)((void*)((char*)this + 0x40), 1)) == 0; }
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
int TObjPlayer__sub_801D2A50(void* p) { return ((int (*)(void*, int))test_flags_any)((void*)((char*)p + 0x40), 8); }
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
void TObjPlayer__sub_801D2A78(void* p, f32 v) { *(f32*)((char*)p + 0x10) = v; }
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
s32 TObjPlayer__sub_801D2A80(void* p) { return *(s32*)((char*)p + 0x8); }
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
void TObjPlayer__sub_801D2A88(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 8) = (s32) (*(s32 *)((s8 *)arg0 + 8) - 1);
}
extern int fold_flush_23;
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
f32 TObjPlayer__sub_801D2A98(void* p) { return *(f32*)((char*)p + 0xc); }
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
void TObjPlayer::set_field_0c(f32 v) { *(f32*)((char*)this + 0xc) = v; }
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
void TObjPlayer::set_field8(s32 v) { *(s32*)((char*)this + 0x8) = v; }
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
Ent_801D2AB0 *TObjPlayer__sub_801D2AB0(Obj_801D2AB0 *p, s32 i) {
    return &p->arr[i];
}
extern int fold_flush_24;
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
void TObjPlayer::set_field_3c(f32 v) { *(f32*)((char*)this + 0x3c) = v; }
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
int TObjPlayer::start_photon_blast_action() { return ((int (*)(void*, int))set__8FlagWordFUl)((void*)((char*)this + 0x40), 4); }
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
f32 TObjPlayer::get_dist() { return *(f32*)((char*)this + 0x10); }
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
void* get_element__10TObjPlayerFPvi(void* a0, int a1) {  return (char*)a0 + a1 * 24; }
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
int is_alt_photon_blast_bank_empty__10TObjPlayerFPv(void* p) { return is_pb_palette_bank_empty((char*)p + 0x24); }
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
void TObjPlayer::bswap_u16_pair_list() {
    Obj_801D2B2C *arg0 = (Obj_801D2B2C *)this;
    s32 i;
    bswap_32__FPUl((void*)(arg0));
    for (i = 0; i < arg0->n; i++) {
        ((TObjPlayer *)(&arg0->e[i]))->bswap_u16_pair();
    }
}
extern int fold_flush_25;
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
void TObjPlayer::bswap_u16_pair() { bswap_16__FPUs(this); bswap_16__FPUs((char*)this + 0x2); }
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
#pragma fp_contract on
s32 TObjPlayer__sub_801D2BB8(s32 arg0, s32 arg1) {
    TFontSmallLobby__sub_801C0228((void*)(arg0));
    *(ByteBlock_2C *)(arg0 + 4) = *(const ByteBlock_2C *)(arg1 + 4);
    return arg0;
}
extern int fold_flush_26;
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
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TObjPlayer::set_technique_state(s32 v) { *(s32*)((char*)this + 0xc) = v; }
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
void TObjPlayer::set_technique_id(u8 v) { *(u8*)((char*)this + 0x0) = v; }
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
int TObjPlayer::test_bit1_at_10() { return ((int (*)(void*, int))test_flags_any)((void*)((char*)this + 0x10), 2); }
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
void TObjPlayer__sub_801D2CAC(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0xC) = (s32) (*(s32 *)((s8 *)arg0 + 0xC) - 1);
}
extern int fold_flush_28;
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
f32 TObjPlayer::get_float_14() { return *(f32*)((char*)this + 0x14); }
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
void TObjPlayer__sub_801D2CC4(void* p, f32 v) { *(f32*)((char*)p + 0x14) = v; }
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
void* get_technique_data__10TObjPlayerFPv(void* p) { return (char*)p + 0x20; }
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
void TObjPlayer::set_tech_override(u8 v) { *(u8*)((char*)this + 0x1) = v; }
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
f32 get_attack_controller_rate(void* p) { return *(f32*)((char*)p + 0x4); }
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

void TObjPlayer::set_attack_target(s16 v) { *(s16*)((char*)this + 0x2) = v; }
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
void* get_anim_field_c__10TObjPlayerFPv(void* p) { return (char*)p + 0xc; }
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
f32 TObjPlayer::calc_attack_stage_multiplier(s32 arg1) {
    s32 arg0 = (s32)this;
    return *(f32 *)((s8 *)((u8 *)(&attack_type_accuracy_scales.value) + (arg1 * 4)) + 0) * *(f32 *)((s8 *)((u8 *)(&attack_combo_accuracy_multipliers.value) + (get_validated_attack_stage((u8 *)(arg0)) * 4)) + 0);
}
extern int fold_flush_29;
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
int on_attack_finished__10TObjPlayerFPv(void* p) { return ((int (*)(void*))copy_attack_targets)((char*)p + 0x30); }
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
int TObjPlayer::set_flag_1_at_c() { return ((int (*)(void*, int))set__8FlagWordFUl)((void*)((char*)this + 0xc), 1); }
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
void TObjPlayer::increment_strike_counter() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 0x12) = (s16) (*(s16 *)((s8 *)arg0 + 0x12) + 1);
}
extern int fold_flush_30;
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
void TObjPlayer::set_action_type(s32 v) { *(s32*)((char*)this + 0x1c) = v; }
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
s32 TObjPlayer::get_field_1c() { return *(s32*)((char*)this + 0x1c); }
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
void TObjPlayer::request_heavy_attack_particles() {
    u16 *arg0 = (u16 *)this;
    emit_heavy_attack_particles((s32)((s8 *)arg0 + 4), (s32)(*arg0));
}
extern int fold_flush_31;
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
void emit_heavy_attack_particles(s32 arg0, s32 arg1) {
    TObjPlayer::check_hit_by_id(arg0, arg1, 0xBB);
    TObjPlayer::check_hit_by_id(arg0, arg1, 0x1B7);
}
extern int fold_flush_32;
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

void clear_lockon_list__10TObjPlayerFPvPvff(s32 *arg0, void * _w1, f32 _w2, f32 _w3) {
    s32 var_r31;
    u8 *var_r30;
    var_r30 = (u8 *)((void *)((u8 *)(arg0) + 4));
    var_r31 = 0;
    *(s32 *)((s8 *)arg0 + 0) = 0;
    do {
        TObjPlayer__sub_8012AF80(var_r30);
        var_r31 += 1;
        var_r30 = (u8 *)((void *)((u8 *)(var_r30) + 4));
    } while (var_r31 < 0xA);
}
extern int fold_flush_33;
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
void TObjPlayer::advance_and_clamp_state() {
    if ((*(s16 *)((s8 *)this + 0x10) = *(s16 *)((s8 *)this + 0x10) + 1) > 2) {
        set_saved_attack_stage((s16)(2));
    }
}
extern int fold_flush_34;
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
s16 get_validated_attack_stage(u8 *arg0) {
    s16 var_r31;
    var_r31 = *(s16 *)((s8 *)arg0 + 0x10);
    if (TObjPlayer__sub_801D2EE8((s16)((void*)((int) (var_r31)))) == 0) {
        var_r31 = 0;
    }
    return var_r31;
}
extern int fold_flush_35;
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
s32 TObjPlayer__sub_801D2EE8(s16 arg0) {
    if ((arg0 < 0) || (arg0 >= 3)) {
        return 0;
    }
    return 1;
}
extern int fold_flush_36;
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
s16 TObjPlayer__sub_801D2F0C(void *arg0) {
    s16 var_r31;
    var_r31 = *(s16 *)((s8 *)arg0 + 2);
    if (TObjPlayer__sub_801D2F8C((s16)(var_r31)) == 0) {
        var_r31 = 0;
    }
    return var_r31;
}
extern int fold_flush_37;
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
s16 TObjPlayer__sub_801D2F4C(s16 *arg0) {
    s16 var_r31;
    var_r31 = *arg0;
    if (TObjPlayer__sub_801D2F8C((s16)((s16)((int) (var_r31)))) == 0) {
        var_r31 = 0;
    }
    return var_r31;
}
extern int fold_flush_38;
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
s32 TObjPlayer__sub_801D2F8C(s16 arg0) {
    if ((arg0 < 0) || (arg0 >= 3)) {
        return 0;
    }
    return 1;
}
extern int fold_flush_39;
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
void queue_physical_attack_input(PlayerAttackController *self, TObjPlayer *obj, s32 arg2, s16 arg3) {
    s16 t;
    if (((int (*)(void*, int))test_flags_any)((void*)(((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self)))), 2) == 0 ||
        ((TObjPlayer *)self)->is_flag32_clear() == 0) {
        ((FlagWord *)((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self))))->set(4);
    }
    if (((int (*)(void*, int))test_flags_any)((void*)(((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self)))), 2) != 0 &&
        ((int (*)(void*, int))test_flags_any)((void*)(((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self)))), 4) == 0) {
        ((FlagWord *)((void *)get_anim_field_c__10TObjPlayerFPv((void*)(self))))->set(1);
        ((TObjPlayer *)self)->advance_and_clamp_state();
        if (get_validated_attack_stage((u8 *)self) > arg3) {
            ((TObjPlayer *)self)->set_saved_attack_stage(arg3);
        }
        t = get_action_palette_entry__10TObjPlayerFl(obj, arg2);
        ((TObjPlayer *)obj)->get_field_340(2);
        ((TObjPlayer *)self)->set_attack_target((s16)(t));
        dispatch_to_child__11TWindowCtrlFPv(((s32 (*)(void *))get_entity_id)(obj), arg2);
    }
}
extern int fold_flush_40;
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
s32 TObjPlayer::update_if_flag8_set() {
    s32 arg0 = (s32)this;
    if (((int (*)(void*, int))test_flags_any)((void*)(arg0 + 0xC), 8) != 0) {
        return tick_countdown_timer();
    }
    return 0;
}
extern int fold_flush_41;
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
s32 TObjPlayer::tick_countdown_timer() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) - 1;
    *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
    if (temp_r0 < 0) {
        ((FlagWord *)(arg0 + 0xC))->set(1);
        return 1;
    }
    return 0;
}
extern int fold_flush_42;
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
void apply_anim_action__10TObjPlayerFPvi(u8 *arg0, s32 arg1) {
    ((FlagWord *)((void *) (arg0 + 0xC)))->set(2);
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) ((TObjPlayer *)arg1)->get_attack_recovery_count();
    TObjPlayer::check_status_flag_128((void*)((void *) (arg1)));
}
extern int fold_flush_43;
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
void begin_player_attack(u8 *player, s32 arg1, s16 arg2, s32 arg3) {
  s8 *new_var;
  ((TObjPlayer *)player)->set_saved_attack_stage((s16)((void *) arg2));
  *((s32 *) (((s8 *) player) + 0x14)) = arg3;
  *((s16 *) (((s8 *) player) + 0x12)) = 0;
  new_var = (s8 *) player;
  *((s32 *) (((s8 *) player) + 0x18)) = 0;
  ((FlagWord *)((void *) (player + 0xC)))->clear(0x1F);
  *((s32 *) (new_var + 0x1C)) = 6;
  *((f32 *) (new_var + 4)) = (f32) (*((f32 *) (((s8 *) player) + 8)));
  if ((s16) (*((s16 *) (((s8 *) player) + 0))))
  {
    *((f32 *) (((s8 *) player) + 4)) = (f32) ((*((f32 *) (new_var + 4))) * lbl_805DC3B8);
  }
}
extern int fold_flush_44;
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

s32 get_first_target_position__10TObjPlayerFPvPv(void *arg0, Vec_801D3224 *out) {
    Slot_801D3224 *s = (Slot_801D3224 *)TObjPlayer__sub_801D345C((void*)(arg0));
    u16 uid = ((TObjPlayer *)s)->get_uid();
    Obj_801D3224 *o;
    if (uid == 0xFFFF) {
        return 0;
    }
    o = ((Obj_801D3224 * (*)(u16))find_entity_by_id)(uid);
    if (o == NULL) {
        return 0;
    }
    ((void (*)(Vec_801D3224 *, Vec_801D3224 *))VecCopy__FP3VecPC3Vec)(out, &o->recs[s->idx].pos);
    return 1;
}
extern int fold_flush_45;
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
void *capture_lockon_targets(Self_801D32A0 *self, Pl_801D32A0 *player) {
    Cur_801D32A0 *cur;
    s32 n;
    Ent_801D32A0 *e;
    s32 i;
    void *obj;
    if (player->cursor == 0) return 0;
    ((void (*)(void *))clear_lockon_list__10TObjPlayerFPvPvff)(&self->count);
    cur = TObjPlayer__sub_801B57E8(player);
    if (cur == 0) return 0;
    if (TMainCursor__sub_8013E900(cur) != 2) return 0;
    self->f20 = cur->x28;
    self->f24 = cur->x2c;
    self->f28 = cur->x30;
    self->f2c = cur->x3c;
    n = ((TLockOnCursor *)(cur->lock))->get_target();
    e = self->ents;
    ((TNpcPlayer *)(&self->count))->set_state(n);
    for (i = 0; i != n; i++) {
        obj = TObjPlayer__sub_80116620(cur->lock, i);
        ((TNpcPlayer *)e)->set_field_0(get_type_id__10TObjPlayerFv(obj));
        ((TNpcPlayer *)e)->set_field2(((TObjPlayer *)obj)->get_obj_id());
        e++;
    }
    ((TMainCursor *)(player->cursor))->set_cursor_pos(self->ents[0].a, self->ents[0].b);
    return &self->count;
}
extern int fold_flush_46;
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
void TObjPlayer::reset_movement_state() {
    *(s16 *)((s8 *)((u8 *)this) + 2) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 4) = (f32) lbl_805DC3BC;
    *(s16 *)((s8 *)((u8 *)this) + 0x12) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x10) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x14) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x20) = (f32) lbl_805DC3C0;
    *(f32 *)((s8 *)((u8 *)this) + 0x24) = (f32) lbl_805DC3BC;
    *(f32 *)((s8 *)((u8 *)this) + 0x28) = (f32) lbl_805DC3BC;
    *(f32 *)((s8 *)((u8 *)this) + 0x2C) = (f32) lbl_805DC3C4;
    clear_lockon_list__10TObjPlayerFPvPvff((s32 *)((void *)(((u8 *)this) + 0x30)), (void *)this, lbl_805DC3C0, lbl_805DC3BC);
}
extern int fold_flush_47;
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
s16 TObjPlayer::get_obj_id() { return *(s16*)((char*)this + 0x2); }
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
void TObjPlayer::set_saved_attack_stage(s16 v) { *(s16*)((char*)this + 0x10) = v; }
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
int TObjPlayer::is_flag32_clear() { return (((int (*)(void*, int))test_flags_any)((void*)((char*)this + 0xc), 32)) == 0; }
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
int TObjPlayer__sub_801D345C(void* p) { return get_captured_target_entry((char*)p + 0x30, 0); }
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
int TObjPlayer::get_field_340(int _w1) { return ((TObjPlayer *)((char*)this + 0x340))->set_action_palette_mode(); }
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
int TObjPlayer::check_status_flag_128(void* p) { return ((int (*)(void*, int))sub_8011E204__10TObjPlayerFl)(p, 128); }
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
void handle_6x54(void) {  }
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
void handle_6x8C(void) {  }
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
void handle_6x65(void) {  }
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
void handle_6x8B(void) {  }
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
void handle_6x64(void) {  }
#pragma pop
