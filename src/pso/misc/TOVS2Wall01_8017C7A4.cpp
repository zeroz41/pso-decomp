#include "types.h"
struct TObjGoalWarpAncient;
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TOVS2Wall01_8017C7A4.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/byteswap.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOVS2Wall01.h"
#include "pso/misc/TMotorcycle.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOVS2.h"

struct RecoveredGlobal_8017C8EC_lbl_804B4ECC {
    s32 value;
    u8 remaining[0x130];
};

struct RecoveredGlobal_8017C7DC_lbl_804B4EBC
{
  s32 value;
  u8 remaining[0xC];
};

extern "C" {
int take_hit__11TOVS2Wall01FPvUi(void*);
s32 TObjFish__sub_8001EDB0(int, void *);
u8 *get_bml_model(s32, s32);
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_8017C8EC_lbl_804B4ECC ovs2wall01_collision_parts;
extern const char *lbl_805D31C4;
extern u32 TOVS2Wall01__bml_resource;
extern void *tl_05;
extern const f32 lbl_805DBAB0;
s32 load_resource_from_descriptor(int, int, void *, int, int, int);
extern RecoveredGlobal_8017C7DC_lbl_804B4EBC bm_o_vs2_resource_descriptor;
extern const f32 lbl_805DBAA8;
extern const f32 lbl_805DBAB4;
void TLobby__sub_8001FE7C(void*, int);
void free_collision_body_parts(void *);
u8 *TObjGoalWarpAncient__ct(TObjGoalWarpAncient *arg0, s32 arg1, s32 arg2);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
int bswap_header__6TLobbyFv(void*);
int init__17TOBarrierEnergy01Fv(void*);

void TOVS2Wall01::release_model() {
    if ((u32) TOVS2Wall01__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOVS2Wall01__bml_resource, 1);
        TOVS2Wall01__bml_resource = 0U;
    }
}

typedef struct RecoveredGlobal_8017C7DC_lbl_804B4EBC RecoveredGlobal_8017C7DC_lbl_804B4EBC;
void TOVS2Wall01::load_resources() {
  s32 temp_r31;
  s32 temp_r3;
  s32 var_r0;
  temp_r3 = (int)::operator new(0x440);
  var_r0 = temp_r3;
  if (var_r0 != 0)
  {
    var_r0 = load_resource_from_descriptor((int) temp_r3, 1, &bm_o_vs2_resource_descriptor.value, 0, 0, 0);
  }
  (*(s32 *)&TOVS2Wall01__bml_resource) = var_r0;
  ;
  TMotorcycle::add_entry(0x3A, (int) ((s32)get_bml_model((s32)((int) (*(s32 *)&TOVS2Wall01__bml_resource)), 5)), (int) TObjFish__sub_8001EDB0((int)((int) var_r0), (void *)(5)), (f32) lbl_805DBAB4, (f32) lbl_805DBAA8);
}

}

// The destructor is still written out by hand: compiled, its vtable would
// open the unit's .data, which the original fills first with the object's
// resource and collision tables (not owned by this unit yet).
extern "C" {
extern void *__vt__5TOVS2[];
void __dl__7TObjectFPv(void *);

void *__dt__5TOVS2Fv(void *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__5TOVS2;
        if ((void *)((TOVS2 *)self)->m_c8 != NULL) {
            queue_destruction__7TObjectFv((void *)((TOVS2 *)self)->m_c8);
            ((TOVS2 *)self)->m_c8 = 0;
        }
        ((TOVS2 *)self)->unregister_object_by_id();
        free_collision_body_parts((TOVS2 *)self);
        __dt__13TUnk_804AFBF8Fv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

TOVS2::TOVS2(void *set_data, s32 index) : TUnk_804AFBF8((TObject *)tl_05) {
    m_name = lbl_805D31C4;
    apply_object_set_data(set_data);
    model = get_bml_model(TOVS2Wall01__bml_resource, index);
    model_radius = lbl_805DBAB0 + *(f32 *)((s8 *)(*(void **)((s8 *)model + 4)) + 0x14);
    texlist = TObjFish__sub_8001EDB0(TOVS2Wall01__bml_resource, (void *)index);
    init_collision_body_parts(this, (void *)((u8 *)&ovs2wall01_collision_parts.value + (index * 0x2C)), 1);
    register_object_by_id();
    m_c8 = TObjMapCsn::create((s32)set_data);
    m_cc = 1;
}

extern "C" {

int TOVS2Wall01__vt24(void) { return 1; }

int TOVS2Wall01__vt25(void) { return 1; }

int TOVS2Wall01__vt18(void) { return 1; }

int TOVS2Wall01__vt19(void) { return 1; }

int TOVS2Wall01__vt20(void* p) { return take_hit__11TOVS2Wall01FPvUi(p); }

int TOVS2Wall01__vt21(void* p) { return take_hit__11TOVS2Wall01FPvUi(p); }

int TOVS2Wall01__vt22(void* p) { return take_hit__11TOVS2Wall01FPvUi(p); }

void TOVS2Wall01__vt23(void) {  }

void TOVS2Wall01__sub_8017CA48(void* p, s32 v) { *(s32*)((char*)p + 0x33c) = v; }
s32 TOVS2Wall01__sub_8017CA50(void* p) { return *(s32*)((char*)p + 0x33c); }
void TOVS2Wall01::byteswap_hit_packet() { bswap_header__6TLobbyFv(this); bswap_16((u16 *)((char*)this + 0xc)); bswap_16((u16 *)((char*)this + 0xe)); }
void TOVS2Wall01::update_and_send() { byteswap_hit_packet(); send_subcommand((u8 *)this); }
void*TOVS2Wall01::init() { init__17TOBarrierEnergy01Fv(this); *(short *)&this->m_next = 0; *(short*)((char*)this + 0xe) = 0; *(unsigned char*)(this) = 134; *(unsigned char*)((char*)this + 0x1) = 4; return this; }

void *TObjGoalWarpAncient__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xEC);
    if (o != NULL) {
        o = TObjGoalWarpAncient__ct((TObjGoalWarpAncient *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

}
