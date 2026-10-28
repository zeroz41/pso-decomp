#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/unk/text_801BDE60.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"

struct VBase_801BDE60 { u8 pad[0x18]; };

struct Obj_801BDE60 : VBase_801BDE60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6();
};

extern "C" {
u8 * construct_player_instance__10TObjPlayerFlslPUc(void *, s32, s16, s32, void *);
u8 *__nw__7TObjectFUl(s32);
extern s32 tl_03;
s32 get_char_data__10TObjPlayerFv(void *);

u8 *TObjPlayer::create_player_instance(s32 arg0, s32 arg1) {
    u8 *p;
    p = __nw__7TObjectFUl(0xDB8);
    if (p != NULL) {
        p = ((u8 *(*)(void *, s32, u16, s32, s32))construct_player_instance__10TObjPlayerFlslPUc)(
            p, tl_03, arg0, TObjPlayer__sub_801C22B4((void *)arg1), get_char_data__10TObjPlayerFv((void *)arg1));
    }
    ((TLobby *)(p + 0xDAC))->copy_header_struct((void *)((TObjPlayer *)arg1)->get_sub_obj());
    ((Obj_801BDE60 *)p)->v6();
    return p;
}

u8 *create_player_object(s16 slot, s32 role, u8 *arg2) {
    u8 *player;
    u8 *var_r0;
    decode_created_player_inventory(arg2);
    player = (u8 *)(__nw__7TObjectFUl(0xDB8));
    var_r0 = player;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(construct_player_instance__10TObjPlayerFlslPUc(player, tl_03, slot, role, arg2));
    }
    return var_r0;
}

}
