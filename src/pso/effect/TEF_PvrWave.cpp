#include "types.h"
#include "pso/effect/TEF_PvrWave.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Tex_80081A30 {
    u32 a;
    u32 b;
    u32 c;
};

struct TexList_80081A30 {
    Tex_80081A30 *entries;
};

struct Scene_80081A30 {
    u8 pad0[0x14];
    TexList_80081A30 *texList;
};

struct Wave_80081A30 {
    void *name;
    u8 pad4[0x14];
    void *vtable;
    void *wave;
    s32 index;
    Tex_80081A30 *tex;
    u8 pad28[4];
    Tex_80081A30 saved;
};

extern "C" {
Scene_80081A30 *TScene__sub_80081B24(void);
}

TEF_PvrWave::~TEF_PvrWave() {
    TexList_80081A30 *list;
    list = TScene__sub_80081B24()->texList;
    list->entries[((Wave_80081A30 *)this)->index].c = ((Wave_80081A30 *)this)->saved.c;
    list->entries[((Wave_80081A30 *)this)->index].b = ((Wave_80081A30 *)this)->saved.b;
    list->entries[((Wave_80081A30 *)this)->index].a = ((Wave_80081A30 *)this)->saved.a;
    ((TAdSinglePlyChrSelectGC *)(((Wave_80081A30 *)this)->wave))->destroy_and_free(1);
}

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
void *construct_texture_wave(void *, void *);
extern u8 __vt__11TEF_PvrWave[];
extern void *TEF_PvrWave__class_name;
Wave_80081A30 *construct_pvr_wave__6TSceneFPvPvPvii(Wave_80081A30 *self, void *parent, void *image, s32 size, s32 index);
extern Scene_80081A30 *TScene__data_805D5FCC;

Wave_80081A30 *construct_pvr_wave__6TSceneFPvPvPvii(Wave_80081A30 *self, void *parent, void *image, s32 size, s32 index) {
    void *p;
    TexList_80081A30 *list;
    __ct__7TObjectFP7TObject(self, parent);
    self->vtable = __vt__11TEF_PvrWave;
    self->name = TEF_PvrWave__class_name;
    self->index = index;
    p = ::operator new(0x54);
    if (p != NULL) {
        p = construct_texture_wave(p, &self->tex);
    }
    self->wave = p;
    ((TAdSinglePlyChrSelectGC *)(self->wave))->init_image_buffer((u8 *)image, (s32)size);
    list = TScene__sub_80081B24()->texList;
    self->saved.c = list->entries[index].c;
    self->saved.b = list->entries[index].b;
    self->saved.a = list->entries[index].a;
    list->entries[index].c = self->tex->c;
    list->entries[index].b = self->tex->b;
    list->entries[index].a = self->tex->a;
    return self;
}

Scene_80081A30 *TScene__sub_80081B24(void) {
    return TScene__data_805D5FCC;
}

}
