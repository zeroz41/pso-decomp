#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/npc/TObjNpcNgcBase_80358AE8.h"
#include "pso/npc/TObjNpcNgcBase.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"

struct Rec_803592B8 {
    s32 idx;
    void *data;
};

// Per-NPC body BML descriptors: one model (<name>.nj), no motions.
static const char *npc_delta_w_body_motion_names[1] = { NULL };
static const char *npc_delta_w_body_model_names[2] = { "n_delta_w_body.nj", NULL };
static BmlResourceDescriptor npc_delta_w_body_resource_descriptor = { "bm_n_delta_w_body.bml", npc_delta_w_body_model_names, npc_delta_w_body_motion_names, 1, 0 };
static const char *npc_elly_t_body_motion_names[1] = { NULL };
static const char *npc_elly_t_body_model_names[2] = { "n_elly_t_body.nj", NULL };
static BmlResourceDescriptor npc_elly_t_body_resource_descriptor = { "bm_n_elly_t_body.bml", npc_elly_t_body_model_names, npc_elly_t_body_motion_names, 1, 0 };
static const char *npc_karen_t_body_motion_names[1] = { NULL };
static const char *npc_karen_t_body_model_names[2] = { "n_karen_t_body.nj", NULL };
static BmlResourceDescriptor npc_karen_t_body_resource_descriptor = { "bm_n_karen_t_body.bml", npc_karen_t_body_model_names, npc_karen_t_body_motion_names, 1, 0 };
static const char *npc_leo_w_body_motion_names[1] = { NULL };
static const char *npc_leo_w_body_model_names[2] = { "n_leo_w_body.nj", NULL };
static BmlResourceDescriptor npc_leo_w_body_resource_descriptor = { "bm_n_leo_w_body.bml", npc_leo_w_body_model_names, npc_leo_w_body_motion_names, 1, 0 };
static const char *npc_michel_t_body_motion_names[1] = { NULL };
static const char *npc_michel_t_body_model_names[2] = { "n_michel_t_body.nj", NULL };
static BmlResourceDescriptor npc_michel_t_body_resource_descriptor = { "bm_n_michel_t_body.bml", npc_michel_t_body_model_names, npc_michel_t_body_motion_names, 1, 0 };
static const char *npc_nol_t_body_motion_names[1] = { NULL };
static const char *npc_nol_t_body_model_names[2] = { "n_nol_t_body.nj", NULL };
static BmlResourceDescriptor npc_nol_t_body_resource_descriptor = { "bm_n_nol_t_body.bml", npc_nol_t_body_model_names, npc_nol_t_body_motion_names, 1, 0 };
static const char *npc_paganini_t_body_motion_names[1] = { NULL };
static const char *npc_paganini_t_body_model_names[2] = { "n_paganini_t_body.nj", NULL };
static BmlResourceDescriptor npc_paganini_t_body_resource_descriptor = { "bm_n_paganini_t_body.bml", npc_paganini_t_body_model_names, npc_paganini_t_body_motion_names, 1, 0 };
static const char *npc_gunsinei_body_motion_names[1] = { NULL };
static const char *npc_gunsinei_body_model_names[2] = { "gunsinei_body.nj", NULL };
static BmlResourceDescriptor npc_gunsinei_body_resource_descriptor = { "bm_gunsinei_body.bml", npc_gunsinei_body_model_names, npc_gunsinei_body_motion_names, 1, 0 };
static const char *npc_kenkyuw2_body_motion_names[1] = { NULL };
static const char *npc_kenkyuw2_body_model_names[2] = { "kenkyuw2_body.nj", NULL };
static BmlResourceDescriptor npc_kenkyuw2_body_resource_descriptor = { "bm_kenkyuw2_body.bml", npc_kenkyuw2_body_model_names, npc_kenkyuw2_body_motion_names, 1, 0 };
static const char *npc_ncchild_body_motion_names[1] = { NULL };
static const char *npc_ncchild_body_model_names[2] = { "ncchild_body.nj", NULL };
static BmlResourceDescriptor npc_ncchild_body_resource_descriptor = { "bm_ncchild_body.bml", npc_ncchild_body_model_names, npc_ncchild_body_motion_names, 1, 0 };
static const char *npc_ncman_body_motion_names[1] = { NULL };
static const char *npc_ncman_body_model_names[2] = { "ncman_body.nj", NULL };
static BmlResourceDescriptor npc_ncman_body_resource_descriptor = { "bm_ncman_body.bml", npc_ncman_body_model_names, npc_ncman_body_motion_names, 1, 0 };
static const char *npc_nctrunk_body_motion_names[1] = { NULL };
static const char *npc_nctrunk_body_model_names[2] = { "nctrunk_body.nj", NULL };
static BmlResourceDescriptor npc_nctrunk_body_resource_descriptor = { "bm_nctrunk_body.bml", npc_nctrunk_body_model_names, npc_nctrunk_body_motion_names, 1, 0 };
static const char *npc_nctrunk2_body_motion_names[1] = { NULL };
static const char *npc_nctrunk2_body_model_names[2] = { "nctrunk2_body.nj", NULL };
static BmlResourceDescriptor npc_nctrunk2_body_resource_descriptor = { "bm_nctrunk2_body.bml", npc_nctrunk2_body_model_names, npc_nctrunk2_body_motion_names, 1, 0 };
static const char *npc_ncwoman_body_motion_names[1] = { NULL };
static const char *npc_ncwoman_body_model_names[2] = { "ncwoman_body.nj", NULL };
static BmlResourceDescriptor npc_ncwoman_body_resource_descriptor = { "bm_ncwoman_body.bml", npc_ncwoman_body_model_names, npc_ncwoman_body_motion_names, 1, 0 };

// {resource slot, descriptor} lists, terminated by slot -1 (load_resources picks one per area).
static Rec_803592B8 npc_pioneer2_ep_resource_descriptor_list[] = {
    { 0, &npc_michel_t_body_resource_descriptor },
    { 1, &npc_karen_t_body_resource_descriptor },
    { 2, &npc_leo_w_body_resource_descriptor },
    { 3, &npc_paganini_t_body_resource_descriptor },
    { 4, &npc_delta_w_body_resource_descriptor },
    { 5, &npc_nol_t_body_resource_descriptor },
    { 6, &npc_elly_t_body_resource_descriptor },
    { 7, &npc_ncchild_body_resource_descriptor },
    { 8, &npc_ncwoman_body_resource_descriptor },
    { 9, &npc_ncman_body_resource_descriptor },
    { 10, &npc_gunsinei_body_resource_descriptor },
    { 11, &npc_nctrunk_body_resource_descriptor },
    { 12, &npc_nctrunk2_body_resource_descriptor },
    { 13, &npc_kenkyuw2_body_resource_descriptor },
    { -1, NULL },
};
static Rec_803592B8 npc_group_selection_resource_descriptor_list[] = {
    { 4, &npc_delta_w_body_resource_descriptor },
    { 11, &npc_nctrunk_body_resource_descriptor },
    { -1, NULL },
};
static Rec_803592B8 npc_seabed_resource_descriptor_list[] = {
    { 2, &npc_leo_w_body_resource_descriptor },
    { -1, NULL },
};

extern "C" {
s32 __ct__11TObjControlFP7TObject(int, int);
}
RecoveredGlobal_TObjNpcNgcBase__data_805439A8 TObjNpcNgcBase__data_805439A8;

extern s32 tl_04;

s32 TObjNpcNgcBase::create_variant_13(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x34)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new((int) ((0, 0x20))));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x34))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create_nctrunk2(s32 set_data) {
  s32 temp_r3;
  saddr player;
  int new_var;
  saddr var_r0;
  s32 parent;
  new_var = 0x3B8;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x30)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(new_var);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x30))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create_nctrunk(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x2C)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x2C))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create_gunsinei(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x28)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x28))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create_ncman(s32 set_data) {
  s8 *new_var;
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  new_var = (s8 *) (&TObjNpcNgcBase__data_805439A8.value);
  if (((u32) (*((u32 *)(new_var + 0x24)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *)(new_var + 0x24))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase::create_variant_8(s32 set_data) {
  s32 temp_r3;
  saddr player;
  u32 *new_var;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x20)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    var_r0 = (saddr)TObject::operator new(0x3B8);
    player = var_r0;
    var_r0 = player;
    if (var_r0 != 0)
    {
      new_var = (u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x20);
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*new_var));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase::create_variant_7(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  s8 *new_var;
  new_var = (s8 *) (&TObjNpcNgcBase__data_805439A8.value);
  if (((u32) (*((u32 *)(new_var + 0x1C)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x1C))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase::create_variant_6(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x18)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x18))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase::create_variant_5(s32 set_data) {
  int new_var;
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x14)))) != 0U)
  {
    new_var = 0x20;
    temp_r3 = (parent = (saddr)TObject::operator new((int) new_var));
    if (1)
    {
      if (parent != 0)
      {
        parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
      }
      player = (saddr)TObject::operator new(0x3B8);
      var_r0 = player;
      if (var_r0 != 0)
      {
        var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x14))));
      }
      return var_r0;
    }
  }
  return 0;
}

s32 TObjNpcNgcBase__create_delta_w(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x10)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new((int) ((0, 0x20))));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x10))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create_paganini_t(s32 set_data) {
  saddr player;
  saddr var_r0;
  s32 parent;
  s32 temp_r3;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0xC)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0xC))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create_leo_w(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 8)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player & 0xFFFFFFFFFFFFFFFF;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 8))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create_karen_t(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x4)))) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new((int) ((0, 0x20))));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, (*((u32 *) (((s8 *) (&TObjNpcNgcBase__data_805439A8.value)) + 0x4))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create(s32 set_data) {
  s32 temp_r3;
  saddr player;
  saddr var_r0;
  s32 parent;
  if (((u32) TObjNpcNgcBase__data_805439A8.value) != 0U)
  {
    temp_r3 = (parent = (saddr)TObject::operator new(0x20));
    if (parent != 0)
    {
      parent = __ct__11TObjControlFP7TObject((int) temp_r3, (int) tl_04);
    }
    player = (saddr)TObject::operator new(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (saddr)__ct__14TObjNpcNgcBaseFP7TObjectPvPv((u8 *)player, parent, set_data, TObjNpcNgcBase__data_805439A8.value);
    }
    return var_r0;
  }
  return 0;
}
void TObjNpcNgcBase::free_shared_resources() {
    s32 i;
    for (i = 0xd; i >= 0; i--) {
        if (((void * *)&TObjNpcNgcBase__data_805439A8)[i] != 0) {
            delete (BmlResource *)((void * *)&TObjNpcNgcBase__data_805439A8)[i];
            ((void * *)&TObjNpcNgcBase__data_805439A8)[i] = 0;
        }
    }
}
void TObjNpcNgcBase::load_resources() {
    Rec_803592B8 *p;
    s32 i;
    void *obj;
    for (i = 0; i < 14; i++) {
        ((u32 *)&TObjNpcNgcBase__data_805439A8)[i] = 0;
    }
    p = NULL;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        p = npc_pioneer2_ep_resource_descriptor_list;
        break;
    case AREA_CENTRAL_CONTROL_AREA: case AREA_JUNGLE_NORTH: case AREA_JUNGLE_EAST: case AREA_MOUNTAIN: case AREA_SEASIDE:
    case AREA_SEASIDE_NIGHT: case AREA_TOWER:
        p = npc_group_selection_resource_descriptor_list;
        break;
    case AREA_SEABED_UPPER: case AREA_SEABED_LOWER:
        p = npc_seabed_resource_descriptor_list;
        break;
    }
    if (p != NULL) {
        while (p->idx != -1) {
            obj = new BmlResource(1, (BmlResourceDescriptor *)p->data, 0, 0, NULL);
            ((void **)&TObjNpcNgcBase__data_805439A8)[p->idx] = obj;
            p++;
        }
    }
}

