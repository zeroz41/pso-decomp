#include "types.h"
#include "pso/unk/text_8034DAA0.h"
struct Vec2i_8034DAA0 {
    s32 x;
    s32 y;
};

struct Base_8034DAA0 {
    u8 pad0[0x18];
};

class Player_8034DAA0 : public Base_8034DAA0 {
public:
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
    virtual void v49(Vec2i_8034DAA0 *);
    virtual void v50(Vec2i_8034DAA0 *);
};

extern "C" {
void set_hp_clamped__10TObjPlayerFs(Player_8034DAA0 *, s32);
s32 obj_getS16_2BA(Player_8034DAA0 *);
void obj_setFlags30(void *, u32);
s32 get_field_2b8__14TItemProShieldFv(Player_8034DAA0 *);
void set_tp__10TObjPlayerFs(Player_8034DAA0 *, s32);
Player_8034DAA0 *get_player_by_client_id(s32);
extern Vec2i_8034DAA0 lbl_80478C90[];
extern Vec2i_8034DAA0 lbl_80478C98[];
extern Vec2i_8034DAA0 lbl_80478CA0[];
extern Vec2i_8034DAA0 lbl_80478CA8[];
void TLobby__sub_8034DAA0(s32 arg0, u32 arg1) {
    Player_8034DAA0 *p;
    p = get_player_by_client_id(arg0);
    if (p == NULL) {
        return;
    }
    switch (arg1) {
    case 0:
        obj_setFlags30(p, 1);
        break;
    case 1:
        obj_setFlags30(p, 2);
        break;
    case 2:
        obj_setFlags30(p, 4);
        break;
    case 3:
        obj_setFlags30(p, 0x20);
        break;
    case 4:
        obj_setFlags30(p, 8);
        break;
    case 5:
        obj_setFlags30(p, 0x10);
        break;
    case 6: {
        Vec2i_8034DAA0 v = lbl_80478C90[0];
        p->v49(&v);
        break;
    }
    case 7: {
        Vec2i_8034DAA0 v = lbl_80478C98[0];
        p->v50(&v);
        break;
    }
    case 8: {
        Vec2i_8034DAA0 v = lbl_80478CA0[0];
        p->v49(&v);
        break;
    }
    case 9: {
        Vec2i_8034DAA0 v = lbl_80478CA8[0];
        p->v50(&v);
        break;
    }
    case 10:
        set_hp_clamped__10TObjPlayerFs(p, get_field_2b8__14TItemProShieldFv(p));
        break;
    case 11:
        set_tp__10TObjPlayerFs(p, obj_getS16_2BA(p));
        break;
    }
}

}
