#include "pso/ui/MenuText.h"
#include "types.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/misc/TCameraCtrl_803D6538.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby_800F8AA8.h"
#include "pso/misc/TPlyJoinLobbyEntry.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/misc/pso_date.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/unk/text_80141A30.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/render/depth_buffer.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

extern "C" {
s32 *lobby_checked_read_ptr_table[4] = { 0, 0, 0, 0 };
s32 lbl_80499A10[4] = { 0, 0, 0, 0 };
u32 lbl_80499A20[4] = { 0, 0, 0, 0 };
u32 lbl_80499A30[4] = { 0, 0, 0, 0 };
    extern unsigned char area_transfer_pending_flag;
extern "C" u8 lbl_8043D7A8[];
extern "C" u8 lbl_8043D820[];
extern "C" u8 lbl_8043D854[];
extern "C" u8 lbl_8043D8AC[];
extern "C" u8 lbl_8043D914[];
extern "C" u8 lbl_8043D984[];
extern "C" u8 lbl_8043D9B8[];
extern "C" u8 lbl_8043D9C4[];
extern "C" u8 lbl_8043D9D0[];
extern "C" u8 lbl_8043D9DC[];
extern "C" u8 lbl_8043D9E8[];
extern void *lbl_8049C5E0[15];
char lbl_80499A40[] = "MallocLoadFilePrc";
void *TLobby__disk_error_msg_table[15] = {
    (void *)&lbl_8043D7A8, (void *)0x42a00000, (void *)0x43660000, (void *)&lbl_8043D820,
    (void *)0x42a00000, (void *)0x43660000, (void *)&lbl_8043D854, (void *)0x42a00000,
    (void *)0x43660000, (void *)&lbl_8043D8AC, (void *)0x42a00000, (void *)0x43660000,
    (void *)&lbl_8043D914, (void *)0x42a00000, (void *)0x43660000,
};
void *TLobby__disk_error_msg_last[4] = {
    (void *)&lbl_8043D984, (void *)0x43020000, (void *)0x43700000, (void *)0x0,
};
void *lobby_font_texture_prs_data[2768] = {
    (void *)0x3f47564d, (void *)0x48c8001e, (void *)0xff0f0005, (void *)0xfefb6572,
    (void *)0x5f6d6573, (void *)0x30fb3100, (void *)0xf8ff130e, (void *)0x660007,
    (void *)0x1b274fc, (void *)0x7bd5fe32, (void *)0xd0fe1a75, (void *)0x27bd5,
    (void *)0xfe33d0fe, (void *)0x1a760003, (void *)0x7bd5fe34, (void *)0xd0fe1a77,
    (void *)0x45bd5, (void *)0xfe35d0fe, (void *)0x1a789cff, (void *)0x78305254,
    (void *)0x8800344, (void *)0xff01e955, (void *)0xf801c5fe, (void *)0xc0ffff55,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0x55c0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xff55c0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffc0, (void *)0xffff55c0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffff55, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0x55c0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xff55c0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffff55c0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffff55, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0x55c0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xff55c0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffd5c0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ff2cff, (void *)0x7fff0020,
    (void *)0x55555d73, (void *)0x700f9d7, (void *)0xb596fc58, (void *)0x20f585c0,
    (void *)0xf0ff77c0, (void *)0xff3773ae, (void *)0x2f67d41, (void *)0xddc0f7ff,
    (void *)0xc0ffc163, (void *)0x2ca4ffd6, (void *)0xffba1591, (void *)0x6240f79e,
    (void *)0x7f2054, (void *)0x5c5b59be, (void *)0x1778ee2a, (void *)0xff5555fc,
    (void *)0xe8da0080, (void *)0x40607bb5, (void *)0xb681f0be, (void *)0x20580da,
    (void *)0xf805a7cd, (void *)0x6159f025, (void *)0x70ffb5c6, (void *)0x58bce8b5,
    (void *)0x8d6147e5, (void *)0x18e861fa, (void *)0xff7986ff, (void *)0xef5d0841,
    (void *)0xf555f63, (void *)0x45aac3d6, (void *)0x9ab89824, (void *)0xc3ce59ec,
    (void *)0xc0c50f43, (void *)0x58bdf7ee, (void *)0xff0979c9, (void *)0x25ffff10,
    (void *)0x820f55df, (void *)0x8ba59abf, (void *)0x821557f, (void *)0x606146fd,
    (void *)0x46c6fdce, (void *)0xb618a0b6, (void *)0x5cf0c2b8, (void *)0xeb3c55f4,
    (void *)0x90585c54, (void *)0x553e04e2, (void *)0x3c82f7be, (void *)0x1ef8579c,
    (void *)0x3cffd820, (void *)0x556d2dd5, (void *)0xef9df0d8, (void *)0xbc3c1c56,
    (void *)0xec0f80f, (void *)0x861be6f, (void *)0x90929690, (void *)0xc0fa0b85,
    (void *)0x8ffe5fa, (void *)0xfdf1b00, (void *)0xa068f0ca, (void *)0xdefb000a,
    (void *)0x531a20b0, (void *)0x7138ff59, (void *)0xc6183c70, (void *)0x60858f60,
    (void *)0xc2b068d5, (void *)0x85014de0, (void *)0xef9e2a9a, (void *)0x6042d78d,
    (void *)0x4dff8df9, (void *)0xf79e10a2, (void *)0x60d58faf, (void *)0x7adf3b80,
    (void *)0x17d535f5, (void *)0x74e7faa4, (void *)0xad71f635, (void *)0x85059574,
    (void *)0x60545657, (void *)0x38f220c6, (void *)0x383cc85a, (void *)0x40ef7d1e,
    (void *)0xb85535c6, (void *)0xe0a0b6d5, (void *)0x953fe96a, (void *)0xb84e46a7,
    (void *)0x9d5f0e6, (void *)0x82e9540, (void *)0x551b143c, (void *)0xd1f600fe,
    (void *)0xe02ee210, (void *)0x82e71c0a, (void *)0xed8909e5, (void *)0x2071f4a8,
    (void *)0x691102d0, (void *)0xe985dd3, (void *)0xd3b83410, (void *)0xbcab3df8,
    (void *)0x53d3d857, (void *)0xfcfabdd7, (void *)0x20101, (void *)0xc281f5e8,
    (void *)0xdb90f190, (void *)0x40205654, (void *)0xc3f8af20, (void *)0x801e192,
    (void *)0xffdba534, (void *)0xf8e8af27, (void *)0x57f77fde, (void *)0x86155df,
    (void *)0xf3518f2, (void *)0x422872d2, (void *)0x1b01528, (void *)0xff9500f3,
    (void *)0x1f08f242, (void *)0xf708c3b5, (void *)0xd6f669e9, (void *)0xe30949b8,
    (void *)0x21158735, (void *)0xcf7af2e7, (void *)0xdf5c2828, (void *)0x98a840d5,
    (void *)0x1605ba40, (void *)0xe5ffc0ff, (void *)0xa76b6d82, (void *)0xf24f5e50,
    (void *)0xc618f87b, (void *)0xff82c0e1, (void *)0xe616b8d, (void *)0xaae8a580,
    (void *)0xf10a84ec, (void *)0xde03d0d5, (void *)0x151500f0, (void *)0x14e77b86,
    (void *)0x86c2de55, (void *)0xfb0bf700, (void *)0xff100020, (void *)0x31ea2216,
    (void *)0x18e30841, (void *)0xdea0a41d, (void *)0x600ff09, (void *)0x21044bfb,
    (void *)0x986ff70, (void *)0xef586070, (void *)0x5803e155, (void *)0x571d5c46,
    (void *)0xfff7dede, (void *)0xfc5cfcfc, (void *)0x5c01e941, (void *)0xef556a2c,
    (void *)0xd500fd0f, (void *)0xe75cbec2, (void *)0xe5163408, (void *)0x2141da4a,
    (void *)0x41e640f8, (void *)0x11260b80, (void *)0x4003b9a9, (void *)0x855cc0de,
    (void *)0x12682ac5, (void *)0x6952e888, (void *)0x16753c00, (void *)0xff0fc6db,
    (void *)0xe71c5cc0, (void *)0x5d9a00ff, (void *)0x107f02d6, (void *)0x555f5852,
    (void *)0xef5d5aa0, (void *)0xd49c00ff, (void *)0xf43c1df, (void *)0x61e85280,
    (void *)0x9f1e38b0, (void *)0x940600, (void *)0xfe10f1be, (void *)0xe077c3cd,
    (void *)0xf0f65aeb, (void *)0x408b40, (void *)0xfd12, (void *)0x68bb5c5b,
    (void *)0x43d7a9b8, (void *)0xc1d8d342, (void *)0x28e4e73c, (void *)0xf643e42d,
    (void *)0x2f45658, (void *)0xdcf116a2, (void *)0x152fa3, (void *)0x2f153281,
    (void *)0xf7fb5f4a, (void *)0x40b10bc5, (void *)0x8f8fc582, (void *)0x80ef1722,
    (void *)0xf1f51702, (void *)0x608c2d5, (void *)0x16b1e153, (void *)0xf811ef,
    (void *)0xb07d6061, (void *)0x43d6a8a6, (void *)0x9e81f221, (void *)0x4500d48,
    (void *)0xc3f254fa, (void *)0x1ef1dd02, (void *)0x524e098, (void *)0xc054f4f8,
    (void *)0x855c00ad, (void *)0x1ad05f3b, (void *)0x585a40ff, (void *)0xf9d135e,
    (void *)0xe8ad2754, (void *)0xc1dca143, (void *)0xd7f21063, (void *)0xeb9a91f1,
    (void *)0x82bc291e, (void *)0xf8575e1e, (void *)0x375fa021, (void *)0x153d3d00,
    (void *)0xed11bd85, (void *)0xda03ecd7, (void *)0x264600fa, (void *)0x108e40eb,
    (void *)0x103186fb, (void *)0x850400ed, (void *)0x9885377, (void *)0x72725343,
    (void *)0xd3d5dcbd, (void *)0xf81083, (void *)0xd1a8a501, (void *)0x85d05540,
    (void *)0x80a7c847, (void *)0xc2c3e3dd, (void *)0x4e183f1, (void *)0xbdd789ce,
    (void *)0x7e81bf, (void *)0x2095953e, (void *)0xc2eb04d1, (void *)0xd507f6c1,
    (void *)0xe2208657, (void *)0x8606e751, (void *)0xdf83cd21, (void *)0x80e911fc,
    (void *)0x4da4ff65, (void *)0xa052d0ff, (void *)0x5bc6c6ff, (void *)0xb9dfb825,
    (void *)0x80e00cd0, (void *)0xff5604fd, (void *)0x5fed52c5, (void *)0xfe1483e0,
    (void *)0x5cfca5b6, (void *)0x40fa17a0, (void *)0x3cf73c36, (void *)0x9581ca40,
    (void *)0x575b3c, (void *)0x8205fa18, (void *)0x40fd0b98, (void *)0x489555c0,
    (void *)0xd8b880e0, (void *)0x9ad86b1, (void *)0xc75c9755, (void *)0xbbd67a02,
    (void *)0xe73ee282, (void *)0xc02f282c, (void *)0x145580c9, (void *)0x15f8a882,
    (void *)0xe4243617, (void *)0x55ae44f7, (void *)0x5f5006ff, (void *)0xc2de0fe9,
    (void *)0x8d05b530, (void *)0xbf10621b, (void *)0xb1c96d00, (void *)0xfe0f3ec2,
    (void *)0xe3404972, (void *)0x5e3ea041, (void *)0x35be1ea, (void *)0x10f2be86,
    (void *)0xe27f2814, (void *)0x68c54aff, (void *)0x6540fe09, (void *)0x96d240ed,
    (void *)0x900535b, (void *)0xd35c57d8, (void *)0x57570bfc, (void *)0xabc0e511,
    (void *)0x48af1797, (void *)0xd75702c0, (void *)0xf413aa, (void *)0xc2e400fd,
    (void *)0xdc0e70a, (void *)0xb9ddbe02, (void *)0xf2586163, (void *)0x5882e2ef,
    (void *)0xa353e3be, (void *)0x44d8fd20, (void *)0xd645af40, (void *)0x46ef05f6,
    (void *)0x564e40f7, (void *)0xd5754c0, (void *)0x4f696150, (void *)0x56986f54,
    (void *)0x54f8ae04, (void *)0xf7d51540, (void *)0xcf1107f0, (void *)0x40ff11b6,
    (void *)0xc85755c2, (void *)0xf60041b8, (void *)0x4ac6dd52, (void *)0xd9b8c3c6,
    (void *)0x582037b7, (void *)0x6b175586, (void *)0xbac08a13, (void *)0x2a0181bb,
    (void *)0x705e4006, (void *)0x46069740, (void *)0xe10f0d40, (void *)0xeb1700f7,
    (void *)0xb53ff87, (void *)0x5ee75cc0, (void *)0x71f751d8, (void *)0x9780d312,
    (void *)0x41575613, (void *)0xfca9102c, (void *)0xbad55580, (void *)0xe521b788,
    (void *)0x4005ea50, (void *)0xe0a17f, (void *)0xce790109, (void *)0x901ad5f,
    (void *)0xf1f6962e, (void *)0x269643aa, (void *)0xc779f3ad, (void *)0x75f096fb,
    (void *)0x3e0f41a8, (void *)0x99404a5a, (void *)0x6d4081ea, (void *)0x2089e2c5,
    (void *)0x5d86f5c2, (void *)0xf2c7c742, (void *)0xedbce62a, (void *)0x9a4081e1,
    (void *)0xeec1e535, (void *)0xe5c1ed61, (void *)0x2af715af, (void *)0x7a82eb25,
    (void *)0xe525b8aa, (void *)0x73ae81ac, (void *)0x7d0102f1, (void *)0x9331814,
    (void *)0xb152f7a0, (void *)0x56c6fda6, (void *)0x45ef12f8, (void *)0x69f77d49,
    (void *)0x4901cc1c, (void *)0x66161326, (void *)0xaf0acf2, (void *)0x4969469c,
    (void *)0xc69ce200, (void *)0x9f0f6059, (void *)0x18a057d1, (void *)0xeb44cc04,
    (void *)0x40c98343, (void *)0x70f201a2, (void *)0xf76152d6, (void *)0xc3d1f5e1,
    (void *)0x5bfa46bc, (void *)0x819c62ab, (void *)0x5ff1b5ad, (void *)0x46dbc7bb,
    (void *)0x2081c917, (void *)0x22618c6, (void *)0xea3fc821, (void *)0x454d735e,
    (void *)0x3d585aba, (void *)0xc2529fb8, (void *)0x57734d1e, (void *)0xe05a52e2,
    (void *)0x2abfb220, (void *)0xc545635e, (void *)0x81cf0518, (void *)0xc0c10b18,
    (void *)0xb8d8585a, (void *)0xe147d9fe, (void *)0x42e55a71, (void *)0x7979bdf7,
    (void *)0x78c0555f, (void *)0x600f82a4, (void *)0x71535c35, (void *)0xdd7682f6,
    (void *)0x3c8241ec, (void *)0x21ef2575, (void *)0xd78742f6, (void *)0x557ffb3e,
    (void *)0xd7c1dd82, (void *)0x4dce8e7d, (void *)0x6502a18a, (void *)0x97bcabdf,
    (void *)0xc4ba9616, (void *)0xf7fe019e, (void *)0xff1b3c96, (void *)0x82e01652,
    (void *)0xffa77894, (void *)0xe8ffd643, (void *)0xb26b28d1, (void *)0x94a8019d,
    (void *)0xd47dda40, (void *)0xff0b9092, (void *)0x9cd7f743, (void *)0x9dadb0c3,
    (void *)0xe2526149, (void *)0x7dc9c2db, (void *)0x56b889, (void *)0xef02dce9,
    (void *)0xf358019e, (void *)0x632c0457, (void *)0xeaf0a640, (void *)0x820101de,
    (void *)0x839855fc, (void *)0xabc2b9f4, (void *)0x57349655, (void *)0xc3e3c1b0,
    (void *)0x3fc1f720, (void *)0x54f42424, (void *)0xbdf8d5d5, (void *)0x3c8382f4,
    (void *)0xf601f4a2, (void *)0xc2f095ba, (void *)0xec51541, (void *)0xb92035c9,
    (void *)0xc6600199, (void *)0xfabe02f5, (void *)0xc6c637d5, (void *)0xc6c1ae84,
    (void *)0xdc1535c6, (void *)0xe091f22f, (void *)0x2035b515, (void *)0x81e5e8ce,
    (void *)0x2efc2f4, (void *)0xd5dbbbd0, (void *)0xd0c4dd54, (void *)0x5602b1a1,
    (void *)0xd2ff5b43, (void *)0x99e7eb28, (void *)0x56f856eb, (void *)0xd81206ee,
    (void *)0x2eb1c1b, (void *)0x4f1096ce, (void *)0x9920ebf3, (void *)0x5f47c241,
    (void *)0x93095ecb, (void *)0xfaad46e1, (void *)0xc8ef9b90, (void *)0x50a5b1c9,
    (void *)0x55af8526, (void *)0x1cdd852, (void *)0x5752d21b, (void *)0xc4fd0193,
    (void *)0xf782a980, (void *)0x4084af75, (void *)0xc5c78242, (void *)0xf612c1db,
    (void *)0x7fde1062, (void *)0xc7c70565, (void *)0x583d301, (void *)0x92987828,
    (void *)0x575e36a7, (void *)0xdf82b595, (void *)0x152f62d1, (void *)0xb6008357,
    (void *)0xf720c6bb, (void *)0xf498a5f5, (void *)0x2624eec4, (void *)0xda3de9c2,
    (void *)0xecbcb42b, (void *)0xb6f502f0, (void *)0x41f1f9d8, (void *)0x1ee94b4,
    (void *)0xb5d6ee02, (void *)0xf53e8282, (void *)0xcee4b4fb, (void *)0x145642c5,
    (void *)0x556a2e95, (void *)0x7ce05515, (void *)0xb56182b1, (void *)0x72408015,
    (void *)0xc6e800e0, (void *)0x5fc3adea, (void *)0x675881f5, (void *)0x81ebffa8,
    (void *)0x46c28f09, (void *)0xff7734c5, (void *)0xaaaac45f, (void *)0x5535c307,
    (void *)0xa53c40c5, (void *)0xc5333736, (void *)0xc8ba4800, (void *)0xab1537e6,
    (void *)0x6ffeac6, (void *)0xce46cfc2, (void *)0xf65454fb, (void *)0x3484c2ef,
    (void *)0x95969883, (void *)0xee84d05f, (void *)0x5880c10b, (void *)0x5cdcabdc,
    (void *)0x5cc6ad80, (void *)0xd10f86e1, (void *)0xbec28b71, (void *)0xe3637100,
    (void *)0xff093ac4, (void *)0xae46a6a5, (void *)0x14584809, (void *)0xa15746ae,
    (void *)0xed80ce0b, (void *)0x81f21783, (void *)0xea7f8f7a, (void *)0xc0ca1003,
    (void *)0xc8d5274f, (void *)0xf5808609, (void *)0x40ce17c1, (void *)0xf15f7271,
    (void *)0x7e40c512, (void *)0x2055a7e0, (void *)0x71bee0f5, (void *)0xe97100ae,
    (void *)0x12df1800, (void *)0xa169004, (void *)0xadcdbd71, (void *)0x80f314fe,
    (void *)0x8285039d, (void *)0xd7d7d851, (void *)0xfe11f1, (void *)0xa3a0b5a6,
    (void *)0xc79685bd, (void *)0x2440c30b, (void *)0x6f717961, (void *)0x61437ea2,
    (void *)0x5d807809, (void *)0x44975752, (void *)0xd1d8f7c1, (void *)0xd5c97142,
    (void *)0xbd71e3e3, (void *)0x577173ce, (void *)0x80c20d84, (void *)0x78d541a8,
    (void *)0xc7a800fc, (void *)0xff1f208, (void *)0x7b058643, (void *)0xd3a7a656,
    (void *)0xe140f712, (void *)0x28ff2e97, (void *)0xde33b82a, (void *)0x594200f9,
    (void *)0x1457f39c, (void *)0x1fd8fdfa, (void *)0x155c45f1, (void *)0x86a5aef8,
    (void *)0x20ffdf83, (void *)0xcb81ebaf, (void *)0xd62724d4, (void *)0xc0a40f03,
    (void *)0x765060d3, (void *)0xfb19d1, (void *)0x31d66003, (void *)0xf5fd55b8,
    (void *)0xfb1000, (void *)0xbb17c0ff, (void *)0xf7ad42d4, (void *)0x41a45c42,
    (void *)0xd101e07e, (void *)0x808c1210, (void *)0x62444e87, (void *)0xdf83c0d5,
    (void *)0xd53fea00, (void *)0xb613c4f5, (void *)0xe6c1d000, (void *)0xff180821,
    (void *)0xc61fe636, (void *)0xd7dedbde, (void *)0xf8019894, (void *)0xd500ff12,
    (void *)0x61af5c5c, (void *)0x9c96c2ca, (void *)0x81c24a80, (void *)0xed1284c2,
    (void *)0x986f7171, (void *)0x735ec0f9, (void *)0x118c57e1, (void *)0xe68040c2,
    (void *)0xca42baef, (void *)0xfb1317, (void *)0x1715029f, (void *)0x2015d715,
    (void *)0xf6000f8, (void *)0x1041c34b, (void *)0x574f0795, (void *)0xad1740,
    (void *)0xdb0bd542, (void *)0x5f40ff17, (void *)0xff1782, (void *)0xbf25f7a5,
    (void *)0x4b5882be, (void *)0x5351c9d5, (void *)0xb500a813, (void *)0xc25b42e7,
    (void *)0x704b7150, (void *)0xf81048, (void *)0xaf025ef2, (void *)0x900f21b,
    (void *)0xc2b7aa80, (void *)0x590900fb, (void *)0x1504f600, (void *)0xfb11bec2,
    (void *)0x7a715158, (void *)0x57c6a8be, (void *)0x80e11393, (void *)0xd3535946,
    (void *)0xc45a00fa, (void *)0x1381bb97, (void *)0xc6ff3f00, (void *)0x9612201c,
    (void *)0x121096bd, (void *)0x78285cf0, (void *)0xae807613, (void *)0x88a8c0f0,
    (void *)0x98d4d4b4, (void *)0x6be00ef, (void *)0x13f1d1da, (void *)0xd700fb1f,
    (void *)0xac2f700, (void *)0xfb15e0b6, (void *)0x190d0c0, (void *)0x6c0b0540,
    (void *)0xe0ffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffea3f, (void *)0x47565254,
    (void *)0x880aff0, (void *)0xe016cff, (void *)0x40f7ffaa, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0,
    (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0x1cc3c618, (void *)0xfc55578f, (void *)0x5858c658, (void *)0xf81fffa8,
    (void *)0x55bdf700, (void *)0xf8f2feff, (void *)0xf7be0020, (void *)0x5555a01f,
    (void *)0x55ce7908, (void *)0x2186e01c, (void *)0x24ea7361, (void *)0xaefc4040,
    (void *)0x7ae08424, (void *)0x945480d0, (void *)0xe895f794, (void *)0x9a9080fd,
    (void *)0x13a9b054, (void *)0x8700defb, (void *)0xf85ef773, (void *)0xfdf800ff,
    (void *)0xfffff08, (void *)0x9f41f5e9, (void *)0x71a1def8, (void *)0x5f6b4d78,
    (void *)0xff0fe7, (void *)0x7f3c1082, (void *)0xd5c57527, (void *)0x8080f87f,
    (void *)0x778f152a, (void *)0xff0921, (void *)0x40cf501, (void *)0xe8f87035,
    (void *)0xe5a54261, (void *)0x28f25754, (void *)0x18ffb596, (void *)0xa148ef35,
    (void *)0xfd0a87, (void *)0x21d71cff, (void *)0xb5e1b640, (void *)0x6a2cd5fd,
    (void *)0x5500fd10, (void *)0x5c086155, (void *)0x14bb3c37, (void *)0xc4fad602,
    (void *)0x40f711f0, (void *)0xe020524, (void *)0x2500b880, (void *)0xaff5e15b,
    (void *)0xab46ff81, (void *)0xf708988e, (void *)0xf8f69e22, (void *)0x1618f0c2,
    (void *)0x20f7de89, (void *)0x1897068, (void *)0xf0760040, (void *)0x87c6fea5,
    (void *)0x14e62557, (void *)0x25d5d540, (void *)0xedffc0ff, (void *)0xffb5c0ff,
    (void *)0xa7c1e681, (void *)0xe05ec7e6, (void *)0x2e84e557, (void *)0x5492e01e,
    (void *)0xf914bdb7, (void *)0xfef85454, (void *)0x5655ffff, (void *)0x7f20db,
    (void *)0xdcd755bd, (void *)0xd7bce8d5, (void *)0x151586fe, (void *)0xc3ce79e8,
    (void *)0x56b8c389, (void *)0x55c80821, (void *)0x17c94358, (void *)0x80e412de,
    (void *)0xfc71c1ba, (void *)0x5582e465, (void *)0x894be0de, (void *)0xa60101c6,
    (void *)0x3882dc2a, (void *)0x8715ad75, (void *)0xf8cb03c9, (void *)0x25e0bcf0,
    (void *)0x20150f60, (void *)0x81dcf4a0, (void *)0x549d6ba, (void *)0x78f85fc2,
    (void *)0xa58f82dc, (void *)0xe52595c8, (void *)0xc34228ca, (void *)0x200d3d6,
    (void *)0x9ae00973, (void *)0x30d2ef7d, (void *)0x8cf60924, (void *)0x68df001c,
    (void *)0x1c965580, (void *)0xfb0b5507, (void *)0xf50056fa, (void *)0xfff2db00,
    (void *)0x40f7de10, (void *)0x62378134, (void *)0xc00e785c, (void *)0xfcab5839,
    (void *)0x76285461, (void *)0x880951a, (void *)0x90e1d2c3, (void *)0x20dff85f,
    (void *)0xf38fad55, (void *)0x6b8de8f7, (void *)0xa50d5540, (void *)0xe00b4d4d,
    (void *)0x650955f8, (void *)0xaca5700, (void *)0xf90ad4b0, (void *)0xfc606081,
    (void *)0xf65f20d5, (void *)0xb5055580, (void *)0xf347ef03, (void *)0xf5575c5c,
    (void *)0xc0fd3952, (void *)0xaa34f4ef, (void *)0x9d5eb875, (void *)0x4505c0fe,
    (void *)0x17f552da, (void *)0x84d900d3, (void *)0xf108255, (void *)0x577d2a94,
    (void *)0xc0fc1fc2, (void *)0xd458c172, (void *)0x4d40ff0f, (void *)0x5d01f301,
    (void *)0xf4815200, (void *)0xfe197a1e, (void *)0x105e71c, (void *)0x5cd87f28,
    (void *)0x40f6105d, (void *)0x41f041cc, (void *)0x152580e7, (void *)0x78ff02e8,
    (void *)0x5f5052ef, (void *)0x9d084177, (void *)0x55fdf800, (void *)0xfb10ce59,
    (void *)0xd742f615, (void *)0x8506f0c0, (void *)0xdfc1ce7f, (void *)0x79090901,
    (void *)0x1ad9578, (void *)0xf62e2696, (void *)0x96d200c2, (void *)0xe842e396,
    (void *)0xff3e0f55, (void *)0x841ce99, (void *)0x4adf5a40, (void *)0x40ef5dc1,
    (void *)0xe8257bc5, (void *)0xc782df15, (void *)0x15955783, (void *)0xe7c7c542,
    (void *)0xe7c4c275, (void *)0x46c3c6e1, (void *)0x40e20973, (void *)0xae00a2ff,
    (void *)0x7f02de95, (void *)0x95289573, (void *)0xce8584dd, (void *)0xc6fdcade,
    (void *)0xeffb2418, (void *)0x6043f525, (void *)0xc21d5e47, (void *)0xc6f79eee,
    (void *)0xd035cf7a, (void *)0x43de5db5, (void *)0xfb015282, (void *)0xbb4dc5c5,
    (void *)0x455e82e2, (void *)0x5ae32d81, (void *)0xdb586669, (void *)0x5280e309,
    (void *)0x7ad82585, (void *)0x85a5aa68, (void *)0x57c1e012, (void *)0xdf0135a1,
    (void *)0x27e0bdd7, (void *)0x80843080, (void *)0x2a1b3f95, (void *)0x84ff0200,
    (void *)0xfa60def0, (void *)0xbf00556b, (void *)0xf1e95707, (void *)0x6b656b2,
    (void *)0x88ce8a18, (void *)0xbe12eb57, (void *)0xf70f5742, (void *)0xdd87152f,
    (void *)0x3ad020f0, (void *)0x66805018, (void *)0x187bef9d, (void *)0x41bb343c,
    (void *)0x37c702e9, (void *)0x498500de, (void *)0xa0f042dd, (void *)0xc6bdf460,
    (void *)0x57726d4d, (void *)0xe2c6dc40, (void *)0xed0bf3, (void *)0x5e01f71e,
    (void *)0xff5e35e, (void *)0x5cf0f09e, (void *)0x5752696d, (void *)0xd4a85ec1,
    (void *)0xdcdee1db, (void *)0xf869725e, (void *)0xbec3f6ac, (void *)0xe0585cc1,
    (void *)0xb4834156, (void *)0xe003b577, (void *)0x58e02e83, (void *)0xdb6d73df,
    (void *)0x4ffa5c1, (void *)0x530300ec, (void *)0xa20b75b, (void *)0xe125c0db,
    (void *)0xc05c5da, (void *)0x8385c5ff, (void *)0x40da0b50, (void *)0xf265c7fe,
    (void *)0xdd81e981, (void *)0xe2545e07, (void *)0xffdef878, (void *)0x5c575510,
    (void *)0x7f61e73c, (void *)0x66589806, (void *)0x7a505555, (void *)0x75c59341,
    (void *)0xf62040b2, (void *)0xb3576058, (void *)0x2840b30a, (void *)0x81f190df,
    (void *)0x47dbce38, (void *)0x63cfea20, (void *)0x6f5b738d, (void *)0x9500da0a,
    (void *)0x20a84300, (void *)0x47fcc2f2, (void *)0xef717979, (void *)0x7182f455,
    (void *)0x5fd36055, (void *)0x78535c85, (void *)0x55c2d3f0, (void *)0x3c7d82c3,
    (void *)0xf555d585, (void *)0x4df8a018, (void *)0xe37f3ed5, (void *)0xe982d0cf,
    (void *)0x8f65cec2, (void *)0xcc2015e0, (void *)0xde41f617, (void *)0x373742db,
    (void *)0xff172e97, (void *)0x9742dcf6, (void *)0xf2e75502, (void *)0xd2161697,
    (void *)0xf09820c6, (void *)0x382adf59, (void *)0x4242ce59, (void *)0x81e2944b,
    (void *)0x1a1046ff, (void *)0x60b79b9c, (void *)0xd705f354, (void *)0x85d87515,
    (void *)0x82d083ca, (void *)0x3186e701, (void *)0xf1d555b8, (void *)0x52a8ff86,
    (void *)0xfa42e83f, (void *)0x52505855, (void *)0xc5f8ee60, (void *)0xfe0201eb,
    (void *)0xd6da9718, (void *)0x182807f0, (void *)0xae60c535, (void *)0x5500f011,
    (void *)0x5f17a06, (void *)0xf012cce9, (void *)0xf25eaaa0, (void *)0x2001f2c0,
    (void *)0xea09ea41, (void *)0xa602f204, (void *)0xd3cd75aa, (void *)0xbcffc0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0,
    (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xfffffec0,
    (void *)0xff5f4756, (void *)0x52540880, (void *)0xbcf00e01, (void *)0x6cffaa40,
    (void *)0xf7ffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0,
    (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xfec0ff54, (void *)0xad750020, (void *)0x80f83b5c,
    (void *)0x5c40ff0f, (void *)0x8c71fce8, (void *)0xff45454, (void *)0xc618f0f4,
    (void *)0xd595bb2c, (void *)0x7e00ff12, (void *)0x555556, (void *)0x90c4c0f8,
    (void *)0xb57dc900, (void *)0xfd11bdf7, (void *)0x20118ff, (void *)0x94d2deb8,
    (void *)0x3e9595, (void *)0xff0fc5, (void *)0xfff80861, (void *)0x57348744,
    (void *)0x94e192e0, (void *)0x55d55a3d, (void *)0x4300fe10, (void *)0x20b5963c,
    (void *)0xfb8061ad, (void *)0x55eda0ad, (void *)0xa300ff0f, (void *)0x4228f4e8,
    (void *)0x5754d6ba, (void *)0xbf08217a, (void *)0xcd351500, (void *)0xff0fc3c6,
    (void *)0x38e89585, (void *)0xf6d5708, (void *)0x41f6b0f2, (void *)0x286900ff,
    (void *)0x100828c0, (void *)0xc37df198, (void *)0xbdd7b0f6, (void *)0x82400ff,
    (void *)0xf00c840, (void *)0x34c8dedb, (void *)0xedd87ff2, (void *)0xff0f4a,
    (void *)0x89f4e815, (void *)0x958430f0, (void *)0xf87d497d, (void *)0x4a7240f5,
    (void *)0x1048e944, (void *)0x840068ff, (void *)0x4000fd10, (void *)0x217a680a,
    (void *)0x1affffda, (void *)0xd8d7b400, (void *)0xff0f9cf9, (void *)0xf3c020b5,
    (void *)0xb6b4f85e, (void *)0x7300ff0f, (void *)0x184a2063, (void *)0xc8842018,
    (void *)0x6100f913, (void *)0xff3186d5, (void *)0x40fc13c0, (void *)0xffffc0ff,
    (void *)0xff82ed5c, (void *)0xd0ff5ec7, (void *)0xecd33ec2, (void *)0xed0706d6,
    (void *)0xba84f456, (void *)0xff57437b, (void *)0xeff816d8, (void *)0xff97ad71,
    (void *)0xe2553bf5, (void *)0x2541e508, (void *)0x411ed904, (void *)0xdefbded8,
    (void *)0xb3b39ad6, (void *)0x42eb8177, (void *)0xe9c92546, (void *)0xff1082d7,
    (void *)0x2eb5561, (void *)0x82e089e0, (void *)0x2f4b095, (void *)0x953c0276,
    (void *)0x45e804c6, (void *)0xffc618f8, (void *)0xd6448414, (void *)0x568ce191,
    (void *)0xf8427e43, (void *)0xed5845ff, (void *)0x1c6ffa5, (void *)0x14bf10a2,
    (void *)0xd8280495, (void *)0x52e4af5f, (void *)0x5fb3ad46, (void *)0xff05fd87,
    (void *)0x5241e8f8, (void *)0x546157f7, (void *)0xd69a78f8, (void *)0x1535cb7a,
    (void *)0xe940f909, (void *)0xde0018ad, (void *)0xe1557054, (void *)0x4c070195,
    (void *)0xe09ef897, (void *)0xd73ceb60, (void *)0xb8d25d53, (void *)0xfc5fa40,
    (void *)0xbdb7fb3f, (void *)0x131c9457, (void *)0xffffbc98, (void *)0x67e715d5,
    (void *)0x41dbd4e0, (void *)0x6105fe01, (void *)0xffbe1739, (void *)0xc73c1734,
    (void *)0x69c394b2, (void *)0xf3a1e1eb, (void *)0xe17946fe, (void *)0x40e310b3,
    (void *)0x8df614b, (void *)0x494b7d45, (void *)0xfbc5fec5, (void *)0xff58b5d6,
    (void *)0x31863d1f, (void *)0x781ce918, (void *)0xe3aff0d5, (void *)0x155586fe,
    (void *)0x6f7f448, (void *)0xa5a5cf7a, (void *)0xff18c3ce, (void *)0x79111161,
    (void *)0x81bbb576, (void *)0x4fb6b8d, (void *)0x41f410e1, (void *)0x79f05040,
    (void *)0x54b8a9be, (void *)0xc2f6cbcb, (void *)0x735e46fd, (void *)0x8647f296,
    (void *)0xe08c1fe4, (void *)0x84968c51, (void *)0x5ef494d4, (void *)0xd4d600f6,
    (void *)0x90d04fa, (void *)0x92d695ff, (void *)0x61d5fa6b, (void *)0x4deb81df,
    (void *)0x1446dc04, (void *)0xd35754ee, (void *)0xc0f90fdf, (void *)0x1b42f05e,
    (void *)0xde56c5fc, (void *)0x4d80ee11, (void *)0x44fd6d80, (void *)0xed1f05fe,
    (void *)0x3640ff16, (void *)0x52b900fe, (void *)0x19a090c5, (void *)0xff76c0da,
    (void *)0x120821f3, (void *)0x14fd80, (void *)0xe2ffc0ff, (void *)0x4fbdd708,
    (void *)0x412c4127, (void *)0xff86ffd7, (void *)0x41e020a7, (void *)0xb9f2c2c8,
    (void *)0x25faf9ed, (void *)0x42e65a5c, (void *)0x56550ec1, (void *)0xe72015e9,
    (void *)0x1d5cc2c3, (void *)0x209c3d8, (void *)0x9af6794f, (void *)0xfb2636c2,
    (void *)0xeb881695, (void *)0x160ec2e6, (void *)0x15d5df63, (void *)0xa534bb7d,
    (void *)0xf0f841ea, (void *)0xa2591140, (void *)0xffc06f5b, (void *)0x535373c2,
    (void *)0xdcd81ca8, (void *)0xa554a2c8, (void *)0x3d871c6, (void *)0x3b490151,
    (void *)0xdfdf1bdc, (void *)0xc0941cbb, (void *)0x80be0920, (void *)0xfbe6fcf9,
    (void *)0xc900e71c, (void *)0x81f61de, (void *)0x9bb1c9e0, (void *)0xa8b840e7,
    (void *)0x428705ef, (void *)0x5de64dfd, (void *)0x5583e020, (void *)0xca5d5579,
    (void *)0xffe73c18, (void *)0xe3d61416, (void *)0x167e51c6, (void *)0x20a3dc54,
    (void *)0x544702db, (void *)0x2c75a869, (void *)0x1c2b7ce, (void *)0x7918c062,
    (void *)0x51e0fff6, (void *)0x39e7409e, (void *)0x44b90050, (void *)0x57138869,
    (void *)0xf00d8862, (void *)0x79ff7e01, (void *)0xdf615a4d, (void *)0x454da382,
    (void *)0xe670e0d2, (void *)0xc3857243, (void *)0xdde0b51f, (void *)0x4d694dce,
    (void *)0x59eef857, (void *)0x545c42b8, (void *)0x2025baf9, (void *)0xbe91f7eb,
    (void *)0x1c4d61f, (void *)0x3da55, (void *)0xd8bf1020, (void *)0x60852585,
    (void *)0x52c4b123, (void *)0x80a5f1ea, (void *)0x3405ff8, (void *)0xc0804896,
    (void *)0xa40f44c4, (void *)0xd67ac04f, (void *)0xaa945656, (void *)0x58e134e9,
    (void *)0x7a8c9110, (void *)0xf85476f8, (void *)0xdf771d4, (void *)0x72db70ff,
    (void *)0x42f6f961, (void *)0x30ffc2f6, (void *)0xd8088811, (void *)0xb4ee85a4,
    (void *)0x4fac825, (void *)0xfb1515c2, (void *)0xde9e3ebe, (void *)0xbc442848,
    (void *)0xd4e06185, (void *)0xb956f009, (void *)0x58ce3910, (void *)0xdf825a49,
    (void *)0x4a4d02bd, (void *)0x27f555, (void *)0x57b0ec38, (void *)0x301d300,
    (void *)0xb55fc5a5, (void *)0xe5ffbf01, (void *)0xd1edb9d1, (void *)0xb2f060fb,
    (void *)0xf48c7134, (void *)0x40d6dabc, (void *)0xfcbcdcde, (void *)0xdec2dc0e,
    (void *)0x2f6c658, (void *)0xa60b3ed5, (void *)0xf60930, (void *)0xf0e8724d,
    (void *)0xca4d3480, (void *)0xb58548b8, (void *)0x46f758fb, (void *)0x3555c3f6,
    (void *)0x20565c5c, (void *)0xfd5801f3, (void *)0x62024105, (void *)0x29c39d13,
    (void *)0xe8525ce8, (void *)0x881f673, (void *)0xa900f8e8, (void *)0xbb18c342,
    (void *)0xf2e71cc4, (void *)0xf2aec2f6, (void *)0xc05d31b2, (void *)0xc5f23e42,
    (void *)0xf4aa5351, (void *)0x513de805, (void *)0x4e4c4e76, (void *)0x88b71acf,
    (void *)0xa574e1c4, (void *)0xf09810a2, (void *)0xaadf1428, (void *)0x1673ae41,
    (void *)0xde95ab95, (void *)0xc9c2cc42, (void *)0xed02f551, (void *)0x41f840e2,
    (void *)0xfffdc0ff, (void *)0x47c1e020, (void *)0x55ff8fa5, (void *)0xe86ffce,
    (void *)0x79f0efa5, (void *)0x8faad541, (void *)0xdf2154f7, (void *)0xd434c442,
    (void *)0xe6d5def3, (void *)0x7dc3d1ef, (void *)0xd6916182, (void *)0x5f42e000,
    (void *)0xebf35e01, (void *)0xe1f8e055, (void *)0xd586cf9c, (void *)0xbdb301f3,
    (void *)0xa932a081, (void *)0xebef61e6, (void *)0xc49743ef, (void *)0xbaf023ae,
    (void *)0x55e85ca8, (void *)0x5a434202, (void *)0xedd8d834, (void *)0xd842a17e,
    (void *)0x3b43d803, (void *)0xdf280c78, (void *)0xd802c455, (void *)0xadb327c1,
    (void *)0xa539c784, (void *)0x7702edfb, (void *)0xf3d2e942, (void *)0x88e7720,
    (void *)0x86f72a59, (void *)0x4041e540, (void *)0x7151e391, (void *)0xd1d02015,
    (void *)0x232c6a88, (void *)0xbcf8d191, (void *)0x595533ba, (void *)0xf72a9a60,
    (void *)0x43a5d738, (void *)0x887e81e6, (void *)0x2135cf7a, (void *)0x555f029a,
    (void *)0x8738d655, (void *)0x41c7b880, (void *)0xa5c1af42, (void *)0xdeef557f,
    (void *)0xae3e82e5, (void *)0xebf1e3a5, (void *)0x55ca203e, (void *)0xe8b884a3,
    (void *)0x9515c3d6, (void *)0x7af05972, (void *)0x8573c1de, (void *)0xde808580,
    (void *)0x42e5f051, (void *)0xfb525ec2, (void *)0xe961696b, (void *)0x63c282a0,
    (void *)0xc0f5cd77, (void *)0x7b7bcf41, (void *)0xecc1e908, (void *)0xa891f8af,
    (void *)0x63617955, (void *)0x46fdc6fd, (void *)0x4460a83a, (void *)0xc6fdd29d,
    (void *)0x4b4900ff, (void *)0xb82ce8e3, (void *)0x5801e5de, (void *)0x20494b7a,
    (void *)0x43dd5ae9, (void *)0xe1781082, (void *)0x45df7544, (void *)0x4694b2c1,
    (void *)0xf5add332, (void *)0x2d284746, (void *)0xfb6555c1, (void *)0xe820e2b0,
    (void *)0x89bd5583, (void *)0x9c0a1a90, (void *)0x43baa7d5, (void *)0x35f5c0a5,
    (void *)0xe8c0c2dc, (void *)0xf53511d5, (void *)0x60def858, (void *)0x53717182,
    (void *)0xf2d83d56, (void *)0x84d2535c, (void *)0x57df2054, (void *)0xb0a9c3f4,
    (void *)0xd51fde72, (void *)0x49c5d83f, (void *)0x58b7cf71, (void *)0xe6fc2cf8,
    (void *)0xed7342f2, (void *)0xfcf871c9, (void *)0xb555be17, (void *)0x74a81634,
    (void *)0x83f32dc, (void *)0x824626ff, (void *)0xffdc8eee, (void *)0x617d03e1,
    (void *)0x63e8d883, (void *)0xbbb7cec7, (void *)0xcae71cf8, (void *)0xfdfb2d95,
    (void *)0x2d2eece, (void *)0xb7555e02, (void *)0x99151597, (void *)0xe410b1,
    (void *)0x81f7b095, (void *)0x40e3ffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0,
    (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xfffec0ff,
    (void *)0x68475652, (void *)0x540880bc, (void *)0xf00e016c, (void *)0xffaa40f7,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0,
    (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xff0ec0ff, (void *)0x2c6b6dfc,
    (void *)0x3f55555e, (void *)0x50c618ed, (void *)0xf8ff8200, (void *)0xff0fb5b6,
    (void *)0xf4e8f7a4, (void *)0x73aeb4f8, (void *)0xd515c0fd, (void *)0x113b52aa,
    (void *)0xa4ffad55, (void *)0x76f84000, (void *)0xfc2fad35, (void *)0xdaa85573,
    (void *)0xc0f77931, (void *)0xb186fb10, (void *)0xc0efff6a, (void *)0xc0ffffc0,
    (void *)0xffef42e1, (void *)0x6134ff80, (void *)0xff0e791c, (void *)0xfabdd701,
    (void *)0xe9fff095, (void *)0xba0a0115, (void *)0xf242f854, (void *)0xff56c302,
    (void *)0xe015ff95, (void *)0xcee159f8, (void *)0x57d736e9, (void *)0x86e01596,
    (void *)0x18e112f8, (void *)0x8018670, (void *)0xffe7b596, (void *)0xf8f01c1b,
    (void *)0x1096ce7f, (void *)0x99002055, (void *)0xadf35fff, (void *)0x46fdf79e,
    (void *)0x10a2095e, (void *)0xfafdad86, (void *)0xffffff08, (void *)0x4159df5d,
    (void *)0x7171bdf7, (void *)0x41e07a03, (void *)0xcb8df0c0, (void *)0xf8f27159,
    (void *)0xc3ef5dc8, (void *)0x60f5c3cf, (void *)0x7af2d6ba, (void *)0xf008060,
    (void *)0x20f80f42, (void *)0x28000278, (void *)0xfff7be08, (void *)0x21b5c5c5,
    (void *)0x9584f069, (void *)0xf102c021, (void *)0x55df232b, (void *)0x35c89c98,
    (void *)0xd5a54d08, (void *)0xc068e0d8, (void *)0xf84f4d4d, (void *)0xf165d041,
    (void *)0x555f23cf, (void *)0x35489ce0, (void *)0x970549e0, (void *)0xd0e1af7a,
    (void *)0xc6e138e8, (void *)0x616985e9, (void *)0x95c8c58f, (void *)0x8f45c507,
    (void *)0xfbc820a1, (void *)0x887540ef, (void *)0xffc0ffff, (void *)0xc0ffe721,
    (void *)0x472f484, (void *)0xc15754f8, (void *)0xface7901, (void *)0x909fb01,
    (void *)0xadf1e496, (void *)0x2e2696fa, (void *)0xc2e1c0c0, (void *)0xb0841ce,
    (void *)0x99bf404a, (void *)0x5a40e73c, (void *)0x82e48b25, (void *)0xc580fd11,
    (void *)0xe61f2a9a, (void *)0x40ffdf0f, (void *)0xe05535e5, (void *)0xf004a6e4,
    (void *)0x9bc65883, (void *)0xbd2a34f0, (void *)0x82dd42e4, (void *)0x959cff28,
    (void *)0xd69a8ba0, (void *)0x5d1e0f8, (void *)0x35fc282, (void *)0xbce84961,
    (void *)0x492502bc, (void *)0x3f2525c2, (void *)0x5eef7d0d, (void *)0xb8d589f2,
    (void *)0x8f6ff3f, (void *)0x9f7de18, (void *)0xa351faf0, (void *)0xc2e2734d,
    (void *)0xc5c56201, (void *)0xdce0f59d, (void *)0xc6f981bc, (void *)0x9cd3e877,
    (void *)0xc0152585, (void *)0x5785a534, (void *)0x44f944ba, (void *)0x728084d9,
    (void *)0xad757a80, (void *)0x2a3f6b8d, (void *)0xdae8a50d, (void *)0xb80c57,
    (void *)0x306b618, (void *)0xae908a5a, (void *)0xba0a83, (void *)0xb9fd6001,
    (void *)0xf7990080, (void *)0x5018ffef, (void *)0x9d1062b5, (void *)0xd5343c7e,
    (void *)0xb714a9, (void *)0xb0d6d6da, (void *)0xbcf85672, (void *)0x6900ff0f,
    (void *)0x1e43b5a5, (void *)0xe358bca2, (void *)0x41db5752, (void *)0x6982d558,
    (void *)0x605c06ff, (void *)0xfc2d75c, (void *)0xace0e0f5, (void *)0x5d04ff00,
    (void *)0xf511c638, (void *)0x57a094, (void *)0x640ff0f, (void *)0x82f798b8,
    (void *)0x75451658, (void *)0x205c2d4, (void *)0x6efc0585, (void *)0xc500f30a,
    (void *)0x1079a6b1, (void *)0xf0e71ce8, (void *)0x5741f7, (void *)0xffdf7898,
    (void *)0x557d2a01, (void *)0x46ff2a5e, (void *)0xe6416658, (void *)0x98c0b70f,
    (void *)0xb142d558, (void *)0x72c0d109, (void *)0x30c04de5, (void *)0xf0ee1855,
    (void *)0xf58581c0, (void *)0xfb09b053, (void *)0xb75b738d, (void *)0x40f60e01,
    (void *)0x51efb8d8, (void *)0x7f2882d0, (void *)0xf5a7179, (void *)0x7918d488,
    (void *)0x5f82f579, (void *)0x2c0ae0b, (void *)0xe03c7ea5, (void *)0x55d585fc,
    (void *)0xe2df1b00, (void *)0x2a6a80f6, (void *)0xc0f810de, (void *)0x81d05717,
    (void *)0x37f4b855, (void *)0xff2e97de, (void *)0xf7142a, (void *)0x594243d0,
    (void *)0x55ebd49a, (void *)0xff0f02, (void *)0xed55ad8b, (void *)0xb05483cd,
    (void *)0x88dbb576, (void *)0x43ec5004, (void *)0xecfd8da8, (void *)0x2f252ff,
    (void *)0x2a82f63c, (void *)0xfef2f249, (void *)0x6004f0c0, (void *)0xaf854d49,
    (void *)0x6900f01f, (void *)0xf21708, (void *)0xe080b7a5, (void *)0xc15340c0,
    (void *)0x889683c1, (void *)0xfd5781e7, (void *)0x96963e, (void *)0xfda92f3,
    (void *)0xc1f05885, (void *)0xe2a8e402, (void *)0x86c5c7c7, (void *)0xefc565de,
    (void *)0xfb82e457, (void *)0x1c7645e1, (void *)0x40c1f361, (void *)0x2a7d81c5,
    (void *)0x42ea25e5, (void *)0x25954900, (void *)0xfd0fda82, (void *)0xbe1dc6fd,
    (void *)0xc0fb17ef, (void *)0x9dd6fcd5, (void *)0x3540c411, (void *)0x2bd52a7,
    (void *)0x5ae32d98, (void *)0x45d76952, (void *)0x5740da0f, (void *)0x43e857fb,
    (void *)0xfcab02ed, (void *)0xa5359555, (void *)0xae84da55, (void *)0x35c0fe09,
    (void *)0x83e05d02, (void *)0x3ba953f, (void *)0x40fc10df, (void *)0x42bf5757,
    (void *)0xf70f44be, (void *)0x2f753a42, (void *)0xe8fcfead, (void *)0x55fd5aeb,
    (void *)0x1db2069, (void *)0x498595be, (void *)0x42dc3737, (void *)0x3495c09e,
    (void *)0xe7d0142, (void *)0xee025cfc, (void *)0x8b7a784d, (void *)0xedf35ee9,
    (void *)0xfd0fa8, (void *)0x5c5ef3bd, (void *)0xadc2d84d, (void *)0x697200ff,
    (void *)0x10de83e0, (void *)0x58e02e51, (void *)0xea00fb40, (void *)0x4900ff11,
    (void *)0xc6180841, (void *)0xaf035be1, (void *)0x25c0f11f, (void *)0x44ba4bc5,
    (void *)0x6500ff17, (void *)0x786f5e5e, (void *)0x5c5740f4, (void *)0x107d7828,
    (void *)0x5354fcab, (void *)0x5f82e6c5, (void *)0x350d7d00, (void *)0xfe18df81,
    (void *)0xd15c63cf, (void *)0xea00ee12, (void *)0x20d71555, (void *)0xff40fb18,
    (void *)0xc2e771d7, (void *)0x535c55c1, (void *)0xe441ee3c, (void *)0xfa808d10,
    (void *)0x82e04dcf, (void *)0x8f655ec1, (void *)0xf7208015, (void *)0xff1308,
    (void *)0xc037ff0d, (void *)0xe702f216, (void *)0xff259780, (void *)0xe413e8df,
    (void *)0x42d51012, (void *)0x1c9700f6, (void *)0x1300f756, (void *)0xb88992f2,
    (void *)0x1515d5fd, (void *)0x5500e813, (void *)0x52525058, (void *)0xc569f860,
    (void *)0xfe02bf00, (void *)0xfc12616d, (void *)0xc5355500, (void *)0xf011eac4,
    (void *)0xff07f081, (void *)0xd46de9ae, (void *)0xf011c6, (void *)0x5881da01,
    (void *)0xf2f605d3, (void *)0xcd00ff09, (void *)0x4228101a, (void *)0xe08202,
    (void *)0xec5811ff, (void *)0x60170055, (void *)0xa082f5f5, (void *)0xf1c7f941,
    (void *)0xf7002484, (void *)0xf249408, (void *)0x41deaf80, (void *)0x80818a06,
    (void *)0xa041f2df, (void *)0x82dadbdc, (void *)0xd586d5de, (void *)0xf1db205e,
    (void *)0x73fdf686, (void *)0xf4e771c9, (void *)0xf8e96bbd, (void *)0x5a03a3f5,
    (void *)0xe97183d2, (void *)0xf75f6b4d, (void *)0x42cea171, (void *)0xc17dba82,
    (void *)0xec78754b, (void *)0x5ef0fa71, (void *)0xdd809020, (void *)0xe46beb5,
    (void *)0x96eeaf07, (void *)0x4bc92546, (void *)0xddc6bd0e, (void *)0x92d25757,
    (void *)0x87fac0dc, (void *)0x907a061, (void *)0x95d71cbd, (void *)0x1c43d56a,
    (void *)0x2cd5c2e8, (void *)0xb0f21c96, (void *)0xc7c8dd3c, (void *)0xc2cf143c,
    (void *)0x46d3f741, (void *)0xde48c2f1, (void *)0xbd46f2f3, (void *)0xdc020524,
    (void *)0x83cef7f5, (void *)0xe15b82bd, (void *)0x60e1d2f4, (void *)0x2062ab5f,
    (void *)0xf1c1adf2, (void *)0x31f722e3, (void *)0x1618f8de, (void *)0x1db8989,
    (void *)0x83dc4d42, (void *)0x9dde0e44, (void *)0xd6a514e6, (void *)0xefd52525,
    (void *)0xd580e70b, (void *)0xd5d5abb5, (void *)0x540adff, (void *)0xc0ffff00,
    (void *)0xa0ffaa00, (void *)0xa0ff00a0, (void *)0xff00a0ff, (void *)0xa0b7aa,
    (void *)0xa71200, (void *)0xa00c00b7, (void *)0x1300a075, (void *)0xaa40e80a,
    (void *)0xa00a00, (void *)0xfd1100a0, (void *)0x57aa00b0, (void *)0xe00a0ff,
    (void *)0xa0ff00, (void *)0xa0b6aac0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0,
    (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0,
    (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffdf3f,
    (void *)0x47565254, (void *)0x880aff0, (void *)0xe016cff, (void *)0x40f7ffaa,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0,
    (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ff2cc3, (void *)0x6b6dfc55,
    (void *)0x554f5e50, (void *)0xc618f83b, (void *)0xff8200ff, (void *)0xfb5b63d,
    (void *)0xe8f7a473, (void *)0xaeedf8d5, (void *)0x1500fc4f, (void *)0xdedbf4a8,
    (void *)0x5fc2ffff, (void *)0xdca08d80, (void *)0xf7793175, (void *)0x86a5ff40,
    (void *)0xff0cd6ba, (void *)0xcf43f72a, (void *)0xdf1b6075, (void *)0xd40fe11,
    (void *)0x32f70014, (void *)0x1fc0f09f, (void *)0xf79e0020, (void *)0x76405d73,
    (void *)0xff17bd, (void *)0xd75a2057, (void *)0x5c00f56f, (void *)0xe7c6ff42,
    (void *)0x28805456, (void *)0x40fa10be, (void *)0x40ec5500, (void *)0xf5505e58,
    (void *)0x754540e0, (void *)0xa7a342e1, (void *)0x61ff80ff, (void *)0xe8d79b2,
    (void *)0xef01fff4, (void *)0xf095ba0a, (void *)0x158642ef, (void *)0x54ff5686,
    (void *)0xd2e815ff, (void *)0x95fbef5d, (void *)0xc1edd535, (void *)0xa6f77fde,
    (void *)0x841557f, (void *)0x2e95fad8, (void *)0x848487e5, (void *)0xc6f138bb,
    (void *)0x952ee2ee, (void *)0x84e61535, (void *)0x82e15756, (void *)0x30c7ce59,
    (void *)0x3cd035b5, (void *)0x1555bcf2, (void *)0xdf1b0102, (void *)0xc3eb7f00,
    (void *)0x3595d7de, (void *)0xf79d0f31, (void *)0xe65dfda2, (void *)0xf0f0b8d5,
    (void *)0x158f7a00, (void *)0xd8f80f58, (void *)0x50c0bed2, (void *)0xe1ce7c0a,
    (void *)0x2620e3be, (void *)0x17b8b589, (void *)0x7d6142f5, (void *)0x784d4f7a,
    (void *)0x7af00161, (void *)0x81b284a8, (void *)0x807fef43, (void *)0x4d082171,
    (void *)0xe3829629, (void *)0x18e04d94, (void *)0xff65c7ff, (void *)0xe68d5c5,
    (void *)0x4df23fe7, (void *)0x3c002a9a, (void *)0x400de84f, (void *)0x4fe8f0c8,
    (void *)0x8612a15, (void *)0xefaf7aff, (void *)0xdfc2e735, (void *)0xe5d272ec,
    (void *)0x18bdf7f0, (void *)0xf625e525, (void *)0x956202ec, (void *)0x185780fa,
    (void *)0xd64038ff, (void *)0xef9d3c9e, (void *)0x735c5c54, (void *)0xc138093f,
    (void *)0xaac3d6da, (void *)0xf05c52d3, (void *)0x81b51069, (void *)0x7d134949,
    (void *)0xb04c78af, (void *)0x35f0f0f2, (void *)0x4969ef7d, (void *)0x3f1082e0,
    (void *)0xd52f7ae0, (void *)0xf8e85516, (void *)0x11d4f80e, (void *)0x78ff3c57,
    (void *)0xd8f0e89e, (void *)0xb4b6d500, (void *)0x98c070e8, (void *)0x3c82a561,
    (void *)0xb1def895, (void *)0x158734dd, (void *)0x109fc8c, (void *)0x3510091,
    (void *)0x84f92050, (void *)0xa8d09a9, (void *)0xf320e807, (void *)0xa8690290,
    (void *)0x3cd857d8, (void *)0xb1d0b8f8, (void *)0xbcabf858, (void *)0x2061b1d0,
    (void *)0xf956a8fd, (void *)0xf2549e83, (void *)0xec5d71f1, (void *)0x60e849f0,
    (void *)0x91f02db, (void *)0xb1f15256, (void *)0xa1401e02, (void *)0x4f20352,
    (void *)0xd2ffc140, (void *)0xe0f8ae84, (void *)0xf0f1f9da, (void *)0xc0575269,
    (void *)0xf4085cac, (void *)0xe0587bd6, (void *)0x9a41f669, (void *)0x725ebef0,
    (void *)0x58e02ec0, (void *)0xee097886, (void *)0x8050643, (void *)0xe90b53,
    (void *)0xff59a0f8, (void *)0x80b81078, (void *)0xbdaff855, (void *)0x5cd306ef,
    (void *)0x82f787f1, (void *)0xd1daf220, (void *)0x1eb1efa8, (void *)0xa5013fd0,
    (void *)0x205c7858, (void *)0xdc3dd057, (void *)0x56fca9fd, (void *)0xe09cdc54,
    (void *)0x57738e78, (void *)0x48052555, (void *)0xdd06f444, (void *)0xccf52585,
    (void *)0xff02f0d2, (void *)0xef9d404a, (void *)0xfd5a79f7, (void *)0xce990080,
    (void *)0x501d1a04, (void *)0xf42fba7e, (void *)0x9808214a, (void *)0x4a05953f,
    (void *)0x11ef2055, (void *)0x7a0e15d0, (void *)0xf26e40a0, (void *)0xf4a02a95,
    (void *)0x2f6af4d8, (void *)0xb5f535d5, (void *)0xaca041ec, (void *)0xc3eb97fb,
    (void *)0xb1542ea, (void *)0x48605802, (void *)0xeafca859, (void *)0xa1690,
    (void *)0x80c0ce07, (void *)0x80902852, (void *)0x78f68085, (void *)0x4b583f02,
    (void *)0xf7096b8f, (void *)0x35ad4066, (void *)0xa06ad0a0, (void *)0x42f7c1e8,
    (void *)0x27ffef5d, (void *)0x10a2c215, (void *)0x3eebf8ca, (void *)0x262625,
    (void *)0xdcd03eb, (void *)0x2a60f490, (void *)0x454585c5, (void *)0xf4c09515,
    (void *)0xf621685, (void *)0xffe5c0e4, (void *)0xf6358de, (void *)0xf960d140,
    (void *)0xe08742c2, (void *)0xd458dbc6, (void *)0x5843c9a8, (void *)0x42f05828,
    (void *)0xff82f23c, (void *)0xf055a0de, (void *)0xfbedf857, (void *)0x1c45c940,
    (void *)0xc5e1f8fb, (void *)0x24842487, (void *)0x940841de, (void *)0x80178081,
    (void *)0x8a80fd12, (void *)0xeed0adb0, (void *)0x54c3c15e, (void *)0x73f5fd00,
    (void *)0xff0f41f0, (void *)0x2155f5e3, (void *)0xe971f841, (void *)0x55375f6b,
    (void *)0x4d00f710, (void *)0x415e8e80, (void *)0x902086e2, (void *)0xd500fe10,
    (void *)0x80e20a42, (void *)0xe940d410, (void *)0xde7e81e4, (void *)0xdf0f35ef,
    (void *)0x5d6aa063, (void *)0xd41120, (void *)0xefb1f180, (void *)0x982444f2,
    (void *)0x9a80ea00, (void *)0xff0f91ea, (void *)0x81d92585, (void *)0x5684e1cf,
    (void *)0x83d8c1d1, (void *)0x1c7faca, (void *)0xee404d4d, (void *)0xd40fa0a,
    (void *)0x2104a8fb, (void *)0x43dc81c5, (void *)0xe1718ace, (void *)0x59180d96,
    (void *)0xc1dbdeb8, (void *)0x2f717172, (void *)0x7300f812, (void *)0x1ca8fdba,
    (void *)0x54e12298, (void *)0x5758d1de, (void *)0xfb14a0, (void *)0xa60986ff,
    (void *)0xe7395ca8, (void *)0x70d4fa10, (void *)0xa2b303da, (void *)0x72d0a771,
    (void *)0x2f595df, (void *)0x25cd61b5, (void *)0x9683e687, (void *)0x20fab1ea,
    (void *)0xfae042ea, (void *)0x87878686, (void *)0xbe42d895, (void *)0xdf9c9c00,
    (void *)0xfd091cc0, (void *)0x18642c6, (void *)0x7808697d, (void *)0x242d657,
    (void *)0x5e9e17f5, (void *)0x5fac7f4, (void *)0x2e4152d, (void *)0x2df51646,
    (void *)0xe500ea14, (void *)0x241a1ba, (void *)0x1d441e7, (void *)0x2e9500ff,
    (void *)0xf3ac1d6, (void *)0xc1df17b4, (void *)0xc2b8e06b, (void *)0x2cdd95c4,
    (void *)0xaef50540, (void *)0xcd0ba557, (void *)0xa5272443, (void *)0xec00fe12,
    (void *)0xd582cf02, (void *)0xf146e2c4, (void *)0xba578562, (void *)0x3e4b881,
    (void *)0xbe42eea5, (void *)0x15959602, (void *)0xe5af5a57, (void *)0xfda800ee,
    (void *)0x1171f6e7, (void *)0x2060878, (void *)0xf57be153, (void *)0xec147f,
    (void *)0x7279afb3, (void *)0xf0a29524, (void *)0x40e71131, (void *)0xe1f7a098,
    (void *)0x2443d75f, (void *)0x4ba58e40, (void *)0xfb0d5f62, (void *)0xc87f5800,
    (void *)0x82521ace, (void *)0x39a86805, (void *)0xf9dd85bb, (void *)0x7d8900f2,
    (void *)0x9e71c06, (void *)0xac298e8, (void *)0x755b4d4d, (void *)0xd2b835b9,
    (void *)0xe5f7c4f2, (void *)0x7d6183ed, (void *)0x5f525200, (void *)0xa22eef24,
    (void *)0x24252400, (void *)0xad14ade2, (void *)0x555c03ea, (void *)0x41d300fb,
    (void *)0x11bc48a0, (void *)0x940640c0, (void *)0x4b9689e0, (void *)0x5e87ffd7,
    (void *)0x585758c0, (void *)0xaf0b84d1, (void *)0x10df82da, (void *)0xdbdcd580,
    (void *)0xe61018f0, (void *)0x580056b8, (void *)0x89bec2ea, (void *)0xf8e96b5a,
    (void *)0x40e710be, (void *)0x1f2a171, (void *)0xc1ba42d3, (void *)0x6f78754b,
    (void *)0x5e00fc10, (void *)0x9678e807, (void *)0x4bc92555, (void *)0x86c3c0ab,
    (void *)0x1085c386, (void *)0xcfbb00fd, (void *)0xe0184cf, (void *)0x159582d3,
    (void *)0x5fc0c543, (void *)0x585271db, (void *)0xeb89f4d4, (void *)0x86e782c7,
    (void *)0x97900a0, (void *)0x78bf10a2, (void *)0xe2353f6a, (void *)0xfa11f0,
    (void *)0xfc078705, (void *)0xc98641f4, (void *)0x20b98fa5, (void *)0x6200ff0f,
    (void *)0x286d774d, (void *)0x8ded86ff, (void *)0xa534dd44, (void *)0xabc497ff,
    (void *)0x2a82f649, (void *)0xd7494370, (void *)0xc2ef49e3, (void *)0xd9eac3c2,
    (void *)0x409f0a84, (void *)0xc45456be, (void *)0x82e5f0f1, (void *)0xd05600f9,
    (void *)0x12df2002, (void *)0x5ef209c0, (void *)0xa81635a6, (void *)0x45fd5978,
    (void *)0x5a575457, (void *)0x5511d704, (void *)0xfcf7c3f2, (void *)0xd51542f3,
    (void *)0xe727271d, (void *)0xf7c1f220, (void *)0x18daff9e, (void *)0xf70e09,
    (void *)0x47f62010, (void *)0xd642faff, (void *)0x8000f513, (void *)0x16163d89,
    (void *)0xa46c680, (void *)0xe611fc4f, (void *)0xb4f434d6, (void *)0xb84ac9b7,
    (void *)0xfe1080, (void *)0xefb4b4b7, (void *)0xf543e5d5, (void *)0x3ffdeb00,
    (void *)0xff1262f4, (void *)0xb637f514, (void *)0x38d50ae0, (void *)0xea80d211,
    (void *)0xfcf7c5e5, (void *)0x3541ed63, (void *)0x2c01c2c0, (void *)0x9a146815,
    (void *)0x35fbcb5e, (void *)0x42e0545c, (void *)0xe8b63e00, (void *)0xec13d8e1,
    (void *)0xe358bde0, (void *)0xa353e3be, (void *)0x40a916d5, (void *)0x7980a909,
    (void *)0xff15c2, (void *)0xef00f725, (void *)0xcb7800fd, (void *)0x130e6d85,
    (void *)0xc59582df, (void *)0x785ac2c0, (void *)0x9611085e, (void *)0x5275c101,
    (void *)0xea82ac6b, (void *)0x5e4380cb, (void *)0x135b68bf, (void *)0xdfc2f779,
    (void *)0x79727f80, (void *)0xdb1354f7, (void *)0x54faad82, (void *)0xa6c0c972,
    (void *)0xd200fe10, (void *)0x80035bab, (void *)0xe12540a0, (void *)0x5b82c001,
    (void *)0xd55f2055, (void *)0x7d606186, (void *)0xdffd80f6, (void *)0x9b1ada8,
    (void *)0xa609ffbf, (void *)0x78e05f73, (void *)0x7bc3c2f1, (void *)0x5cff56e7,
    (void *)0xe11cf058, (void *)0x7d735d5e, (void *)0x84ca9808, (void *)0x40c80978,
    (void *)0xf62d71f1, (void *)0xa56d46e7, (void *)0xc1d36109, (void *)0xca732f03,
    (void *)0xaea2a101, (void *)0xc6e6e906, (void *)0x4aebc390, (void *)0xd515bd15,
    (void *)0x83cef527, (void *)0x24c2e96f, (void *)0xd5d53c83, (void *)0x31e41c78,
    (void *)0x8162a008, (void *)0x21ef71e5, (void *)0x2a698002, (void *)0xe65458f3,
    (void *)0x9c1478d5, (void *)0x3ef7ebbd, (void *)0xb741e514, (void *)0x14575e02,
    (void *)0xde972726, (void *)0x81cff898, (void *)0x95d5949b, (void *)0xad0175e8,
    (void *)0xf6793e0f, (void *)0x82f3939b, (void *)0x9cbd97c3, (void *)0xcca9b856,
    (void *)0x43e3a75f, (void *)0xd8988057, (void *)0xf757fcab, (void *)0x82f31e9e,
    (void *)0xde755f86, (void *)0xc7b4e880, (void *)0x401586e6, (void *)0x46dd0798,
    (void *)0xdf309595, (void *)0x2a2a85ff, (void *)0x2de8397, (void *)0x953f0082,
    (void *)0xe369f769, (void *)0x8d8dc3a7, (void *)0x5fcf356e, (void *)0x2d26371,
    (void *)0x83d921d8, (void *)0xc1af7a83, (void *)0xd0953b05, (void *)0x4b83cd7f,
    (void *)0x8f841838, (void *)0xf862176b, (void *)0x859542e0, (void *)0xf6e00f60,
    (void *)0x83e1d525, (void *)0x4d7bef9d, (void *)0x41973534, (void *)0x32ff4299,
    (void *)0x494d0595, (void *)0xf7de109f, (void *)0x82023635, (void *)0x956ec056,
    (void *)0xb61682a5, (void *)0x41d89094, (void *)0x9ac2d856, (void *)0xf79626c7,
    (void *)0x82ea1012, (void *)0x1ca59786, (void *)0xb4f058d7, (void *)0x6070d886,
    (void *)0xd342e1d8, (void *)0x7bd858c3, (void *)0x92552535, (void *)0x55a2d783,
    (void *)0xf002f704, (void *)0xa5558068, (void *)0xffc0ffff, (void *)0xc6fff2e3,
    (void *)0xd0f481ab, (void *)0x42ef2dbe, (void *)0x72dc0209, (void *)0x902c6af,
    (void *)0xea00ab11, (void *)0xb1da8198, (void *)0xe75cae02, (void *)0x8a37c700,
    (void *)0xa41780fc, (void *)0x17ba00b4, (void *)0x27c38f5a, (void *)0xcbc0ea10,
    (void *)0xdec3e195, (void *)0x8d6943e1, (void *)0xfeeb8285, (void *)0xff0fc3,
    (void *)0x7ed6d0bd, (void *)0x6183e3f5, (void *)0xe15b00ff, (void *)0x97683bf,
    (void *)0x24c0b80b, (void *)0x71790d80, (void *)0x780900a4, (void *)0xaba687b,
    (void *)0x96900361, (void *)0xb5c971bd, (void *)0x41c402ac, (void *)0x5273ce84,
    (void *)0xc4be82ca, (void *)0x71e3e371, (void *)0x83f657d7, (void *)0xd87100a8,
    (void *)0x108583f5, (void *)0x2978086, (void *)0xb00560c, (void *)0xa6a4547b,
    (void *)0xf7fec1f7, (void *)0xff3c96df, (void *)0x80bb1355, (void *)0x6b289403,
    (void *)0xa557abd8, (void *)0x9980660f, (void *)0x42de01af, (void *)0xb6029300,
    (void *)0x81855c45, (void *)0xf9b8dc52, (void *)0xaa82b83e, (void *)0x2f556f7,
    (void *)0xf4540e40, (void *)0x20d5c0ad, (void *)0xf100fb18, (void *)0x2180810d,
    (void *)0x40bc09aa, (void *)0x84810051, (void *)0x57c0ffff, (void *)0xc0ff8fbe,
    (void *)0x80770b14, (void *)0x16179580, (void *)0xef13ffd5, (void *)0x953f6ae7,
    (void *)0x3c0821af, (void *)0x4f4727d5, (void *)0xaf13c4, (void *)0xc64a405d,
    (void *)0x1c00b420, (void *)0xb8ef35b5, (void *)0xcf7a00af, (void *)0x1371795d,
    (void *)0xcdc36485, (void *)0x85807511, (void *)0xef02c860, (void *)0x6152029b,
    (void *)0x62ab575f, (void *)0xf1ad8049, (void *)0x1b00fc17, (void *)0x52a8c6a4,
    (void *)0xf913f2, (void *)0xe842dd61, (void *)0x7150ea00, (void *)0xa2148264,
    (void *)0x427bd3d3, (void *)0x955300fe, (void *)0x10069642, (void *)0x9894ffd6,
    (void *)0x900fc13, (void *)0xe80e8010, (void *)0xa2debf75, (void *)0xd6807b12,
    (void *)0x39c1e02c, (void *)0xb27841b4, (void *)0xd7807712, (void *)0x38a0f4a6,
    (void *)0xbd60e1f1, (void *)0xd0d600fb, (void *)0x37aa8651, (void *)0x80e7ffc0,
    (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffffc0,
    (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xc0ffffaa,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff, (void *)0xaac0ffff,
    (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffc0ffff,
    (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff, (void *)0xffaac0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffc0, (void *)0xffffaac0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xc0ffffaa, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffc0ffff, (void *)0xaac0ffff, (void *)0xc0ffffc0, (void *)0xffffc0ff,
    (void *)0xffaac0ff, (void *)0xffc0ffff, (void *)0xc0ffcf00, (void *)0x0,
};
void *lbl_8049C5E0[15] = {
    (void *)&lbl_8043D9B8, (void *)0x0, (void *)0x0, (void *)&lbl_8043D9C4,
    (void *)0x0, (void *)0x0, (void *)&lbl_8043D9D0, (void *)0x0,
    (void *)0x0, (void *)&lbl_8043D9DC, (void *)0x0, (void *)0x0,
    (void *)&lbl_8043D9E8, (void *)0x0, (void *)0x0,
};
__declspec(section ".data") void *lbl_8049C61C[2] = {
    (void *)&lbl_8049C5E0, (void *)0x5,
};
#define TLobby__disk_error_msg_table ((Msg_800F8FB8 *)TLobby__disk_error_msg_table)
#define TLobby__disk_error_msg_last ((Msg_800F8FB8 *)TLobby__disk_error_msg_last)
#define lobby_font_texture_prs_data ((u8 *)lobby_font_texture_prs_data)
#define lbl_8049C61C ((u8 *)lbl_8049C61C)

void TLobby::reset_keyboard_state() { area_transfer_pending_flag = 0; TKeyBoardControl::reset(); }

extern u32 main_phase_deferred_callback;

void TLobby__sub_800F8AD0(void) {
    if ((u32) main_phase_deferred_callback != 0U) {
        (*(s8 *)&area_transfer_pending_flag) = 1;
    }
}

bool is_area_transfer_pending(void) {
    return (*(u8 *)&(*(s8 *)&area_transfer_pending_flag)) != 0;
}

void TLobby::clear_callback_and_reset_keyboard() { TLobby::set_keyboard_mode(0); TKeyBoardControl::reset(); }

int is_quest_active(void);
#define main_phase_deferred_callback (*(s32 (**)())&main_phase_deferred_callback)

void apply_phase_keyboard_mode(void) {
    switch (get_main_phase()) {
    case 15:
        if (is_quest_active() != 0) {
            TLobby::set_keyboard_mode((int)(TLobby::init_chr_select));
        } else {
            TLobby::set_keyboard_mode((int)(TLobby::reset_to_chr_select));
        }
        break;
    case 14:
        if (is_quest_active() != 0) {
            TLobby::set_keyboard_mode((int)(TLobby::shutdown_keyboard_control));
        } else {
            TLobby::set_keyboard_mode((int)(TLobby::reset_keyboard_input));
        }
        break;
    case 1:
    case 2:
        TLobby::set_keyboard_mode((int)TLobby__sub_800F8BD8);
        break;
    default:
        TLobby::set_keyboard_mode(0);
        break;
    }
}

void TLobby__sub_800F8BD8(void) { TKeyBoardControl::reset(); TKeyBoardControl__sub_8000F92C(); }

void TLobby::invoke_callback() {
    if (((s32 (*)()) main_phase_deferred_callback) != NULL) {
        main_phase_deferred_callback();
    }
}

#undef main_phase_deferred_callback

void TLobby::set_keyboard_mode(int a0) { (*(int *)&main_phase_deferred_callback) = a0; }
extern s32 *pending_file_read_handle_ref;
extern s32 pending_file_read_sector_count;
extern u32 pending_file_read_destination;
extern s32 pending_file_read_flush_requested;

void TLobby::flush_pending() {
    u32 temp_r5;
    s32 count;
    if ((s32) pending_file_read_flush_requested != 0) {
        temp_r5 = pending_file_read_destination;
        pending_file_read_flush_requested = 0;
        if ((temp_r5 != 0U)) {
            count = pending_file_read_sector_count;
            if (count != 0) {
                TLobby::read_checked_align(*pending_file_read_handle_ref, count, temp_r5);
            }
        }
        TLobby::flush_checked_reads();
    }
}

void TLobby::flush_checked_reads() {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (lobby_checked_read_ptr_table[i] != NULL && lbl_80499A10[i] != 0 && lbl_80499A20[i] != 0) {
            TLobby::read_checked_align(*lobby_checked_read_ptr_table[i], lbl_80499A10[i], lbl_80499A20[i]);
        }
    }
}

void TLobby::reset_read_state() { (*(int *)&pending_file_read_handle_ref) = 0; (*(int *)&pending_file_read_sector_count) = 0; (*(int *)&pending_file_read_destination) = 0; }
void TLobby::clear_player_slot_tables(s32 n) {
    s32 i;
    if (n == -1) {
        for (i = 0; i < 4; i++) {
            lobby_checked_read_ptr_table[i] = 0;
            lbl_80499A10[i] = 0;
            lbl_80499A20[i] = 0;
            lbl_80499A30[i] = 0;
        }
        return;
    }
    lobby_checked_read_ptr_table[n] = 0;
    lbl_80499A10[n] = 0;
    lbl_80499A20[n] = 0;
    lbl_80499A30[n] = 0;
}

void TLobby::set_entry_params(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    lobby_checked_read_ptr_table[arg1] = (s32 *)arg0;
    lbl_80499A10[arg1] = arg2;
    lbl_80499A20[arg1] = arg3;
}

#pragma push
extern u8 lobby_font_texture_loaded;
void release_texture_list(void *p);
extern const char lbl_8043D9F4[];
void *tmp_buf_use_req__6TLobbyFPCc(const char *);
s32 load_gvm_texture_archive(void *, void *);

void TLobby::set_read_params(int a0, int a1, int a2) { (*(int *)&pending_file_read_handle_ref) = a0; (*(int *)&pending_file_read_sector_count) = a1; (*(int *)&pending_file_read_destination) = a2; }

void TLobby__sub_800F8DD8(void) { (*(int *)&pending_file_read_flush_requested) = 1; }

    extern unsigned char lobby_state_byte_flag;

void TLobby::draw_fullscreen_texture_quad() {
    f32 v[8];
    v[0] = 128.0f;
    v[1] = 48.0f;
    v[2] = 512.0f;
    v[3] = 432.0f;
    v[5] = v[4] = 0.0f;
    v[7] = v[6] = 1.0f;
    TObjFish::set_global_param((s32)lbl_8049C61C);
    begin_screen_draw(0);
    set_draw_texture_and_color((s32)this, -1);
    draw_textured_quad_at_depth(v, (0.5f));
    TWindowSubStatusDisp::get_player();
}

void TLobby::release_menu_font() {
    if (lobby_font_texture_loaded) {
        release_texture_list(lbl_8049C61C);
    }
    lobby_font_texture_loaded = 0;
}

void TLobby::load_font_texture() {
    void *file = tmp_buf_use_req__6TLobbyFPCc(lbl_8043D9F4);
    if (file != 0) {
        s32 r;
        prs_decompress_buffer((s32)lobby_font_texture_prs_data, (s32)file);
        r = load_gvm_texture_archive(file, lbl_8049C61C);
        ((TLobby *)lbl_8043D9F4)->tmp_buf_release();
        lobby_font_texture_loaded = 1;
        if (r == -1) {
            lobby_font_texture_loaded = 0;
        }
    }
}

void TLobby__sub_800F8F34(void) { lobby_state_byte_flag = 1; }

#pragma pop

#pragma push

extern u8 lobby_wait_ready_flag;

void TLobby::reset_state_byte() {
    if ((u8) lobby_wait_ready_flag == 0) {
        (*(s8 *)&lobby_state_byte_flag) = 0;
    }
}

}

#pragma pop

#pragma push

#include "pso/TAdPlayerLoadGC.h"
#include "pso/TObjCMHairMenu.h"
#include "pso/misc/TCameraCtrl.h"

extern "C" {

void TLobby::wait_ready_loop() {
    (*(s8 *)&lobby_wait_ready_flag) = 0;
loop_1:
    if (TLobby::run_disk_error_check() != 1) {
        if (get_main_phase() == 0xF) {
            TLobby__sub_801384E4();
        }
        TAdPlayerLoadGC::set_state(1);
        (*(s8 *)&lobby_wait_ready_flag) = 1;
        render_tick();
        goto loop_1;
    }
}

typedef struct {
    f32 *pos;
    s32 *ids;
    s32 a;
    s32 n;
} Desc_800F8FB8;

typedef struct {
    u8 *str;
    f32 x;
    f32 y;
} Msg_800F8FB8;

s32 DVDGetDriveStatus(void);
void TCameraCtrl__sub_80068EF0(void);

s8 func_801A5E54__Fv(void);
s32 DVDCheckDisk(void);

#define show_msg_800F8FB8(arr, i) draw_menu_text(arr[i].x, arr[i].y, (const char *)arr[i].str, 0x8FFFFFFF)

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby::run_disk_error_check() {
    f32 pos[8];
    Desc_800F8FB8 d;
    s32 ids[4];
    s32 status;
    Desc_800F8FB8 *pd = &d;

    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 6);
    d.pos = pos;
    d.ids = ids;
    d.a = 0;
    d.n = 4;
    pd->pos[0] = (0.0f);
    pd->pos[1] = (0.0f);
    pd->ids[0] = -1;
    pd->pos[2] = (6.4e+02f);
    pd->pos[3] = (0.0f);
    pd->ids[1] = -1;
    pd->pos[4] = (6.4e+02f);
    pd->pos[5] = (4.8e+02f);
    pd->ids[2] = -1;
    pd->pos[6] = (0.0f);
    pd->pos[7] = (4.8e+02f);
    pd->ids[3] = -1;
    set_depth_buffer_settings_1();
    ((TObjCMHairMenu *)(&d))->draw_tri_fan_2d(4, 0x12, (-0.9f));
    status = DVDGetDriveStatus();
    TCameraCtrl::restore_full_screen_view();
    if (DVDCheckDisk() == 0 && (TKeyBoardControl::check_reset_button() != 0 || func_801A5E54__Fv() != 0)) {
        reset_system();
    }
    switch (status) {
    case -1:
        func_803DCDFC__Fv();
        set_perspective_projection_from_fov(0x3555, (1.1333334f), (1.0f), (2.1e+04f));
        if (lobby_font_texture_loaded != 0) {
            ((TLobby *)0)->draw_fullscreen_texture_quad();
        } else {
            show_msg_800F8FB8(TLobby__disk_error_msg_table, 0);
        }
        break;
    case 1:
        controller_stuff();
        if ((*(int *)&pending_file_read_flush_requested) != 0 && (TKeyBoardControl::check_reset_button() != 0 || func_801A5E54__Fv() != 0)) {
            system_reset();
        }
        break;
    case 4:
        func_803DCDFC__Fv();
        set_perspective_projection_from_fov(0x3555, (1.1333334f), (1.0f), (2.1e+04f));
        controller_stuff();
        if (lobby_font_texture_loaded != 0) {
            ((TLobby *)1)->draw_fullscreen_texture_quad();
        } else {
            show_msg_800F8FB8(TLobby__disk_error_msg_table, 1);
        }
        if (TKeyBoardControl::check_reset_button() != 0 || func_801A5E54__Fv() != 0) {
            system_reset();
        }
        break;
    case 5:
        func_803DCDFC__Fv();
        set_perspective_projection_from_fov(0x3555, (1.1333334f), (1.0f), (2.1e+04f));
        controller_stuff();
        if (lobby_font_texture_loaded != 0) {
            ((TLobby *)2)->draw_fullscreen_texture_quad();
        } else if (get_main_phase() == 0xF) {
            show_msg_800F8FB8(TLobby__disk_error_msg_last, 0);
        } else {
            show_msg_800F8FB8(TLobby__disk_error_msg_table, 2);
        }
        if (TKeyBoardControl::check_reset_button() != 0 || func_801A5E54__Fv() != 0) {
            system_reset();
        }
        break;
    case 6:
        func_803DCDFC__Fv();
        set_perspective_projection_from_fov(0x3555, (1.1333334f), (1.0f), (2.1e+04f));
        controller_stuff();
        if (lobby_font_texture_loaded != 0) {
            ((TLobby *)3)->draw_fullscreen_texture_quad();
        } else {
            show_msg_800F8FB8(TLobby__disk_error_msg_table, 3);
        }
        if (TKeyBoardControl::check_reset_button() != 0 || func_801A5E54__Fv() != 0) {
            system_reset();
        } else {
            TLobby__sub_800F8DD8();
        }
        break;
    case 11:
        func_803DCDFC__Fv();
        set_perspective_projection_from_fov(0x3555, (1.1333334f), (1.0f), (2.1e+04f));
        if (lobby_font_texture_loaded != 0) {
            ((TLobby *)4)->draw_fullscreen_texture_quad();
        } else {
            show_msg_800F8FB8(TLobby__disk_error_msg_table, 4);
        }
        if (TKeyBoardControl::check_reset_button() != 0 || func_801A5E54__Fv() != 0) {
            system_reset();
        } else {
            TLobby__sub_800F8DD8();
        }
        break;
    }
    restore_saved_depth_alpha_state();
    TCameraCtrl__sub_80068EF0();
    if (status == 4 || status == 5 || status == 6 || status == -1 || status == 11) {
        return 0;
    }
    if (status == 0) {
        TLobby::flush_pending();
    }
    return 1;
}
#pragma pop

}

#pragma pop

#undef pending_file_read_flush_requested
