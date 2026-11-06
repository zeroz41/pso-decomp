#include "types.h"
#include "pso/unk/text_803CE568.h"
#include "pso/unk/TLobby.h"

typedef s32 (*RecoveredCallback_4873a87e26d6)(s32, s32 *, s32);

struct Ent_803CF958 { u32 a; char name[12]; };
struct Drv_803CFD2C {
    u8 pad[0x14];
    void (*close)(s32);
};
struct Slot_803CFD2C {
    Drv_803CFD2C *drv;
    s32 handle;
};
struct Rec_803CFD2C {
    u8 pad0[4];
    s8 used;
    u8 pad5[0xB];
};

struct V_803CEF60 { void (*fn)(); };

extern "C" {
extern s32 lbl_8047D7AC[];
extern s32 lbl_8047D7C8[];
extern RecoveredCallback_4873a87e26d6 cvfs_completion_callback;
extern s32 lbl_805D75FC;
extern s32 lbl_8047D7E4[];
extern s32 lbl_8047D800[];
extern s32 lbl_8047D8B8[];
extern s32 lbl_8047D8D4[];
extern s32 lbl_8047D8EC[];
extern s32 lbl_8047D908[];
extern s32 lbl_8047D850[];
extern s32 lbl_8047D86C[];
extern s32 lbl_8047D884[];
extern s32 lbl_8047D8A0[];
s32 strncmp(void *, void *, int);
void *memcpy(void *, void *, u32);
u32 strlen(void *);
extern s32 lbl_8047D9D4[];
extern s32 lbl_8047D9FC[];
extern s8 fs_default_device_name[];
extern Ent_803CF958 cvfs_entry_table[];
void *memset(void *, s32, u32);
extern s32 lbl_805D7600;
s32 TLobby::cv_fs_get_stat() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    s32 var_r31;
    var_r31 = 3;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D7AC, 0);
        }
        return 3;
    }
    temp_r12 = *(s32 (**)(s32))((s8 *)(*(u8 * *)&this->m_name) + 0x2C);
    if (temp_r12 != NULL) {
        var_r31 = temp_r12(*(s32 *)&this->m_flags);
    } else if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
        cvfs_completion_callback(lbl_805D75FC, lbl_8047D7C8, 0);
    }
    return var_r31;
}

void TLobby__sub_803CEF60(void) {
    s32 i;
    Ent_803CF958 *p;
    for (i = 0; i < 0x20; i++) {
        p = &cvfs_entry_table[i];
        if ((V_803CEF60 *)p->a != 0 && ((V_803CEF60 *)p->a)->fn != 0) {
            ((V_803CEF60 *)p->a)->fn();
        }
    }
}

void TLobby::cvfs_stop_tr() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D7E4, 0);
        }
    } else {
        temp_r12 = *(s32 (**)(s32))((s8 *)(*(u8 * *)&this->m_name) + 0x28);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)&this->m_flags);
            return;
        }
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D800, 0);
        }
    }
}

s32 TLobby::cv_fs_req_rd(s32 error_context, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32, s32, s32);
    s32 var_r31;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D850, 0);
        }
        return 0;
    }
    temp_r12 = *(s32 (**)(s32, s32, s32))((s8 *)(*(u8 * *)&this->m_name) + 0x20);
    if (temp_r12 != NULL) {
        var_r31 = temp_r12(*(s32 *)&this->m_flags, error_context, arg2);
    } else {
        var_r31 = 0;
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D86C, 0);
        }
    }
    return var_r31;
}

s32 TLobby::cv_fs_seek(s32 error_context, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32, s32, s32);
    s32 var_r31;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D884, 0);
        }
        return 0;
    }
    temp_r12 = *(s32 (**)(s32, s32, s32))((s8 *)(*(u8 * *)&this->m_name) + 0x18);
    if (temp_r12 != NULL) {
        var_r31 = temp_r12(*(s32 *)&this->m_flags, error_context, arg2);
    } else {
        var_r31 = 0;
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D8A0, 0);
        }
    }
    return var_r31;
}

s32 TLobby::cv_fs_tell() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    s32 var_r31;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D8B8, 0);
        }
        return 0;
    }
    temp_r12 = *(s32 (**)(s32))((s8 *)(*(u8 * *)&this->m_name) + 0x1C);
    if (temp_r12 != NULL) {
        var_r31 = temp_r12(*(s32 *)&this->m_flags);
    } else {
        var_r31 = 0;
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D8D4, 0);
        }
    }
    return var_r31;
}
void TLobby::cv_fs_close() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D8EC, 0);
        }
    } else {
        temp_r12 = *(s32 (**)(s32))((s8 *)(*(u8 * *)&this->m_name) + 0x14);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)&this->m_flags);
            *(s32 *)&this->m_flags = 0;
            *(u8 * *)&this->m_name = NULL;
            return;
        }
        if (((s32 (*)(s32, s32 *, s32)) cvfs_completion_callback) != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D908, 0);
        }
    }
}
typedef s32 (*RecoveredCallback_4873a87e26d6)(s32, s32 *, s32);
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 find_803CF958(char *s, s32 len) {
    Ent_803CF958 *p;
    s32 i;
    for (p = cvfs_entry_table, i = 0; i < 32; i++, p++) {
        if (strncmp(s, p->name, len) == 0) {
            return 1;
        }
    }
    return 0;
}
void TLobby::cvFsSetDefDev() {
    char *arg0 = (char *)this;
    s32 len;
    u32 j;
    u32 n;
    if (arg0 == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, lbl_8047D9D4, 0);
        }
        return;
    }
    len = strlen(arg0);
    if (len == 0) {
        fs_default_device_name[0] = 0;
        return;
    }
    n = strlen(arg0) + 1;
    for (j = 0; j < n; j++) {
        if (arg0[j] >= 'a' && arg0[j] <= 'z') {
            arg0[j] -= 0x20;
        }
    }
    if (find_803CF958(arg0, len) == 1) {
        memcpy(fs_default_device_name, arg0, len + 1);
        return;
    }
    if (cvfs_completion_callback != NULL) {
        cvfs_completion_callback(lbl_805D75FC, lbl_8047D9FC, 0);
    }
}

struct CvFsDevIf {
    u8 pad0[4];
    void (*set_callback)(void (*)(), s32);
};

extern char lbl_8047CF30[];
inline u32 cvfs_find_device_if(char *s, s32 len) {
    Ent_803CF958 *p;
    u32 i;
    for (p = cvfs_entry_table, i = 0; i < 32; i++, p++) {
        if (strncmp(s, p->name, len) == 0) {
            return cvfs_entry_table[i].a;
        }
    }
    return 0;
}
extern char *const volatile lbl_805E0DA0;

inline CvFsDevIf *cvfs_add_device(char *name, CvFsDevIf *dev) {
    s32 k;
    if (cvfs_find_device_if(name, strlen(name)) != 0) {
        return dev;
    }
    for (k = 0; k < 32; k++) {
        if (cvfs_entry_table[k].name[0] == 0) {
            break;
        }
    }
    if (k == 32) {
        return NULL;
    }
    cvfs_entry_table[k].a = (u32)dev;
    memcpy(cvfs_entry_table[k].name, name, strlen(name) + 1);
    return dev;
}
void TLobby__sub_803CFAA8(char *name, CvFsDevIf *(*getif)(void), s32 arg) {
    CvFsDevIf *dev;
    u32 n;
    u32 i;
    char *messages = lbl_8047CF30;
    lbl_805E0DA0;
    if (name == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, (s32 *)(messages + 0xB18), 0);
        }
        return;
    }
    if (getif == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, (s32 *)(messages + 0xB3C), 0);
        }
        return;
    }
    n = strlen(name) + 1;
    for (i = 0; i < n; i++) {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] -= 0x20;
        }
    }
    dev = cvfs_add_device(name, getif());
    if (dev == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, (s32 *)(messages + 0xB60), 0);
        }
        return;
    }
    if (dev->set_callback != NULL) {
        dev->set_callback(TLobby::call_callback, 0);
    }
}

u32 lbl_80581A30[75];
s8 fs_default_device_name[12];
Ent_803CF958 cvfs_entry_table[32];
u32 si_type_info_table[80];

void SIGetTypeAsync(void) {
    Slot_803CFD2C *s;
    Rec_803CFD2C *r;
    s32 i;

    if (--lbl_805D7600 == 0) {
        for (s = (Slot_803CFD2C *)si_type_info_table, i = 0; i < 40; i++, s++) {
            if (s->drv != NULL) {
                s->drv->close(s->handle);
            }
            s->drv = NULL;
            s->handle = 0;
        }
        for (i = 0; i < 32; i++) {
            ((Rec_803CFD2C *)cvfs_entry_table)[i].used = 0;
        }
        memset(fs_default_device_name, 0, 9);
        ((s8 *)fs_default_device_name)[0] = 0;
    }
}

}
