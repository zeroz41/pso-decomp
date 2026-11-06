#include "types.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC_8030FE74.h"


TAdChrSelBSlotGC::~TAdChrSelBSlotGC() {
    if ((u32) *(u32 *)((s8 *)this + 0x40) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x40));
        *(u32 *)((s8 *)this + 0x40) = 0U;
    }
    if ((u32) this->m_44 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x44));
        this->m_44 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x48) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x48));
        *(u32 *)((s8 *)this + 0x48) = 0U;
    }
    if ((u32) this->m_4c != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x4C));
        this->m_4c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x50) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x50));
        *(u32 *)((s8 *)this + 0x50) = 0U;
    }
    if ((u32) this->m_54 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x54));
        this->m_54 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x58) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x58));
        *(u32 *)((s8 *)this + 0x58) = 0U;
    }
    if ((u32) this->m_5c != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x5C));
        this->m_5c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x60) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x60));
        *(u32 *)((s8 *)this + 0x60) = 0U;
    }
    if ((u32) this->m_64 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x64));
        this->m_64 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x68) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x68));
        *(u32 *)((s8 *)this + 0x68) = 0U;
    }
    if ((u32) this->m_6c != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x6C));
        this->m_6c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x70));
        *(u32 *)((s8 *)this + 0x70) = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x74));
        this->m_74 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x78) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x78));
        *(u32 *)((s8 *)this + 0x78) = 0U;
    }
    if ((u32) this->m_7c != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x7C));
        this->m_7c = 0U;
    }
}
