#include "types.h"
#include "pso/unk/TLobby_80338E9C.h"
#include "pso/unk/text_80338F3C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *TLobby::create_object(void *arg0) {
    void *o = __nw__7TObjectFUl(0x8C);
    if (o != NULL) {
        o = fn_80338F3C((u8 *)o, (s32)arg0);
    }
    return o;
}

extern s32 lbl_804EF4E0[];

void *__dt__13TUnk_804EF4E0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EF4E0;
        ((TWindowSubStatusDisp *)arg0)->deleting_dtor(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
