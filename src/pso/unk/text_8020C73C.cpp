#include "types.h"
#include "pso/unk/TLobby.h"
struct Set_8020C73C {
    s16 f0;
    s16 flags;
    s16 f4;
    u8 pad6[6];
    s16 x;
    s16 z;
    u8 pad10[0x34];
    void *obj;
};

struct ObjBase_8020C73C { u8 pad[0x18]; };

struct Obj_8020C73C : ObjBase_8020C73C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(void *);
    u8 pad1c[0xC];
    s16 x;
    s16 z;
    s16 kind;
    u8 pad2e[0x52];
    Set_8020C73C *set;
};

extern "C" {
s32 get_current_floor();
s32 set_flags_on_matching_entries__6TLobbyFlssl(s32, s32, s32, s32);
Set_8020C73C *resolve_matching_object__6TLobbyFv(s32);
}
s32 construct_enemy_from_set_row(u8 *row);
extern u8 *TLobby__data_805D6144;

s32 TLobby::unhide_enemies_at(s32 arg0, s32 arg1, s32 arg2) {
    s32 n;
    s32 count;
    s32 local;
    Set_8020C73C *set;
    s32 i;
    Obj_8020C73C *obj;
    count = 0;
    local = 0;
    if (arg0 == get_current_floor()) {
        local = 1;
    }
    if (local == 0) {
        return set_flags_on_matching_entries__6TLobbyFlssl(arg0, arg1, arg2, 1);
    }
    set = resolve_matching_object__6TLobbyFv(arg0);
    n = TLobby::get_object_type(arg0);
    for (i = 0; i < n; i++, set++) {
        if (set->flags & 8) continue;
        if (set->flags & 2) continue;
        if (set->flags & 1) continue;
        if (set->x != (s16)arg1) continue;
        if (set->z != (s16)arg2) continue;
        if (local != 0) {
            obj = (Obj_8020C73C *)construct_enemy_from_set_row((u8 *)set);
            if (obj != NULL) {
                set->obj = obj;
                set->flags |= 2;
                obj->x = set->x;
                obj->z = set->z;
                obj->kind = set->f4;
                obj->set = set;
                if (obj->kind != -1) {
                    obj->v77(TLobby__data_805D6144 + obj->kind * 0xC);
                }
                count++;
            } else {
                set->obj = NULL;
            }
        } else {
            set->flags |= 1;
            count++;
        }
    }
    return count;
}
