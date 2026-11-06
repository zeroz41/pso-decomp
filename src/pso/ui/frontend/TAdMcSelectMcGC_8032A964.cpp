#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/frontend/TAdMcSelectMcGC_8032A964.h"
class TAdMcSelectMcGC : public TObject {
public:
    virtual ~TAdMcSelectMcGC();
    virtual void run_task();
    virtual void render();
};

TAdMcSelectMcGC::~TAdMcSelectMcGC() {}

#include "types.h"

struct Ent_8032A9BC { f32 a, b, c, d; u8 pad[0x10]; };

struct Obj_8032A9BC {
    s32 f0; u8 pad[0x14]; void *vt; s32 f1C; u8 pad2[0x30 - 0x20];
    Ent_8032A9BC ents[8];
};

struct Alt_8032A9BC { u8 pad[0x120]; s32 f120, f124, f128, f12C, f130; };

extern "C" {
s32 release_texture_list(void *, s32);
extern int TAdMcSelectMcGC__texture_list_ptr;
void __ct__7TObjectFP7TObject(void *, void *);
extern u8 __vt__15TAdMcSelectMcGC[];
extern s32 lbl_805D41D8;
extern const f32 lbl_805DF75C;
extern const f32 lbl_805DF760;
Obj_8032A9BC *__ct__15TAdMcSelectMcGCFv(Obj_8032A9BC *arg0, void *arg1, s32 arg2);

    extern unsigned char lbl_80477150[];
    struct McCardName_804ED9C0 { void *name; s32 a; s32 b; };
    struct McCardRef_804ED9CC { void *card; s32 n; };
    McCardName_804ED9C0 lbl_804ED9C0 = { lbl_80477150, 0, 0 };
    __declspec(section ".data") McCardRef_804ED9CC mc_select_memorycard_texture_list = { &lbl_804ED9C0, 1 };

Obj_8032A9BC *__ct__15TAdMcSelectMcGCFv(Obj_8032A9BC *arg0, void *arg1, s32 arg2) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0, arg1);
    arg0->vt = __vt__15TAdMcSelectMcGC;
    arg0->f0 = lbl_805D41D8;
    ((Alt_8032A9BC *)arg0)->f130 = 0;
    ((Alt_8032A9BC *)arg0)->f124 = 0;
    ((Alt_8032A9BC *)arg0)->f128 = 0;
    ((Alt_8032A9BC *)arg0)->f12C = arg2;
    ((Alt_8032A9BC *)arg0)->f120 = 0xFF;
    arg0->f1C = 1;
    for (i = 0; i < 8; i++) {
        arg0->ents[i].a = lbl_805DF75C;
        arg0->ents[i].b = lbl_805DF75C;
        arg0->ents[i].c = lbl_805DF760;
        arg0->ents[i].d = lbl_805DF760;
    }
    return arg0;
}

void release_selected_entry__15TAdMcSelectMcGCFv(void) {
    u8 *temp_r4;
    if ((void **) (*(void ** *)&TAdMcSelectMcGC__texture_list_ptr) != NULL) {
        temp_r4 = (u8 *)(*(*(void ** *)&TAdMcSelectMcGC__texture_list_ptr));
        if ((u32) *(u32 *)((s8 *)temp_r4 + 8) != 0U) {
            release_texture_list((*(void ** *)&TAdMcSelectMcGC__texture_list_ptr), (s32) temp_r4);
        }
    }
}

void init_memorycard__15TAdMcSelectMcGCFv(void) { TAdMcSelectMcGC__texture_list_ptr = (int)&mc_select_memorycard_texture_list; TLobby__sub_8023E4B4((s32)lbl_80477150, (s32)&mc_select_memorycard_texture_list); }

s32 TAdMcSelectMcGC__sub_8032AAC4(void* p) { return *(s32*)((char*)p + 0x20); }

}
