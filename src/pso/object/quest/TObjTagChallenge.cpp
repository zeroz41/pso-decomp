#include "pso/object/quest/TObjTagChallenge.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TObjNewFloorWin.h"

extern "C" {
s32 TWindowCtrlMain__sub_8024CE58(void);
}

void TObjTagChallenge::run_task() {
    if (TWindowCtrlMain__sub_8024CE58() != 0) {
        TWindowCtrl::close_active_window();
        fn_800740DC();
        TWindowCtrl::open_status_111();
        queue_destruction__7TObjectFv(this);
    }
}

TObjTagChallenge::~TObjTagChallenge() {}

#include "types.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__16TObjTagChallenge[];
extern void *TObjTagChallenge__class_name;

void *TObjTagChallenge__ct(void *tag_challenge) {
    __ct__7TObjectFP7TObject(tag_challenge);
    *(s32 **)((s8 *)tag_challenge + 0x18) = __vt__16TObjTagChallenge;
    *(void * *)&((TObjTagChallenge *)tag_challenge)->m_name = TObjTagChallenge__class_name;
    return tag_challenge;
}

#define TObjTagChallenge__ct (*(void * (*)(void *, void *))&TObjTagChallenge__ct)

void *__nw__7TObjectFUl(int);
}

void *create_obj_tag_challenge(void *tag_challenge) {
    void *o = __nw__7TObjectFUl(0x1C);
    if (o != NULL) {
        o = TObjTagChallenge__ct(o, tag_challenge);
    }
    return o;
}

#undef TObjTagChallenge__ct
