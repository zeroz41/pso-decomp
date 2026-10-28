#include "types.h"
#include "pso/misc/TPhotonRainbow_801AE640.h"
#include "pso/misc/TPhotonRainbow.h"
#include "pso/system/vector.h"
#include "pso/misc/TPhotonYoulla.h"

extern "C" {

s32 __ct__8TObjBaseFP7TObject();

extern void *__vt__14TPhotonRainbow[];
extern s32 lbl_805D3520;
extern u8 *photon_blast_shared_resource;

u8 *TPhotonRainbow__ct(u8 *photon_rainbow, s32 arg1_unused, s32 arg2) {
    __ct__8TObjBaseFP7TObject();
    *(s32 **)((s8 *)photon_rainbow + 0x18) = (s32 *)&__vt__14TPhotonRainbow;
    *(s32 *)((s8 *)photon_rainbow + 0) = (s32) lbl_805D3520;
    if ((s32) ((TPhotonRainbow *)photon_rainbow)->m_a8 == 1) {
        ((TPhotonRainbow *)photon_rainbow)->m_90 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x6C);
        ((TPhotonRainbow *)photon_rainbow)->m_94 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x8C);
        ((TPhotonRainbow *)photon_rainbow)->m_98 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x68);
        ((TPhotonRainbow *)photon_rainbow)->m_9c = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x88);
    } else {
        ((TPhotonRainbow *)photon_rainbow)->m_90 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x5C);
        ((TPhotonRainbow *)photon_rainbow)->m_94 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x7C);
        ((TPhotonRainbow *)photon_rainbow)->m_98 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x58);
        ((TPhotonRainbow *)photon_rainbow)->m_9c = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)photon_blast_shared_resource + 0x42C)) + 0x78);
    }
    VecCopy((Vec *)(photon_rainbow + 0x38), (const Vec *)arg2);
    return photon_rainbow;
}

void TObjPlayer__sub_801AE724(void) {  }
void TObjPlayer__sub_801AE728(void) {  }

    extern const float lbl_805DC260;
void TPhotonYoulla::sub_801AE72C() { *(float *)&this->m_184 = lbl_805DC260; *(float*)((char*)this + 0x188) = lbl_805DC260; this->m_18c = lbl_805DC260; *(float *)&this->unk_190 = lbl_805DC260; }

}
