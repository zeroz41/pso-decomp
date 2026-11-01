#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/misc/TLobby.h"

struct RecoveredGlobal_8001EDF4_lbl_804FE148 {
    s8 value;
    u8 remaining[0x1F];
};







struct List_8001EDD8 { u8 pad[0x18]; s32 items[0x100]; s32 count; };

struct Glob_8001EE48 { s8 value; u8 remaining[0x1F]; };

extern "C" {
s32 strcmp(void *, void *);
extern RecoveredGlobal_8001EDF4_lbl_804FE148 TLobby__tmp_buf_name;
extern s32 tmp_buf_in_use_flag;
void TLobby__sub_8001EDD8(List_8001EDD8 *self, s32 item);
char *strncpy(char *d, const char *s, u32 n);
extern char lbl_80434AE8[];
extern s32 lobby_download_buffer;
extern char lbl_80434AA0[];
extern char lbl_80434AC0[];

int fn_8001ED90(void* p) { return (*(u32*)((char*)p + 0x0) >> 10) & 0x1; }

AnimationMotion *get_bml_motion(BmlResource *resource, s32 index) {
    return resource->motions[index].motion;
}

s32 TObjFish__sub_8001EDB0(BmlResource *resource, s32 index) {
    return resource->models[index].m_c;
}

s32 get_bml_model(BmlResource *resource, s32 index) {
    return resource->models[index].model;
}

typedef char RecoveredGlobal_8001EDF4_lbl_804FE148_size[sizeof(RecoveredGlobal_8001EDF4_lbl_804FE148) == 0x20 ? 1 : -1];

void TLobby__sub_8001EDD8(List_8001EDD8 *self, s32 item) {
    self->items[self->count++] = item;
}

void TLobby::tmp_buf_release_if_owner(const char *name) {
    if (((s32) tmp_buf_in_use_flag == 0) && (strcmp(&TLobby__tmp_buf_name.value, (void *)name) == 0)) {
        tmp_buf_in_use_flag = 1;
        TLobby__tmp_buf_name.value = 0;
    }
}

s32 TLobby::tmp_buf_release(const char *name) {
    s32 arg0 = (s32)name;
    if (arg0 != 0) {
        if (tmp_buf_in_use_flag == 1) {
            TLobby::debug_print((s32)lbl_80434AA0, arg0);
            return 0;
        }
        if (strcmp(&TLobby__tmp_buf_name, (void *)arg0) != 0) {
            TLobby::debug_print((s32)lbl_80434AC0, arg0, &TLobby__tmp_buf_name);
            return 0;
        }
    }
    tmp_buf_in_use_flag = 1;
    (*(Glob_8001EE48 *)&TLobby__tmp_buf_name).value = 0;
    return 1;
}

s32 TLobby::tmp_buf_is_free() {
    return tmp_buf_in_use_flag;
}
s32 TLobby::tmp_buf_use_req(const char *name) {
    if (tmp_buf_in_use_flag != 0) {
        tmp_buf_in_use_flag = 0;
        strncpy(((char *)&TLobby__tmp_buf_name), name, 0x20);
        return lobby_download_buffer;
    }
    TLobby::debug_print((s32)lbl_80434AE8);
    return 0;
}

}
