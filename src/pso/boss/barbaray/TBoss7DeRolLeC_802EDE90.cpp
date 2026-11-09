#include "types.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/boss/barbaray/TBoss7Joint.h"
#include "pso/boss/barbaray/TBoss7Tentacle.h"
#include "pso/boss/barbaray/TBoss7LaserLight.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TUnk_804F1C58.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"

extern "C" {
extern const char *TBoss7DeRolLeC__class_name;
extern const CollisionBody lbl_80473C3C;
extern const Vec lbl_80473F6C;
extern s32 lbl_804E3D1C[];
extern u8 lbl_804E3C8C[];
void *mem_alloc(u32 size);
void fill_value_array(PointerBuffer *buffer);
void TObjPlayer__sub_802E7EA0(void *arg0);
}

TBoss7DeRolLeC::TBoss7DeRolLeC(TObject *parent, void *set_data) : TObjEneDD_ST(parent), unk_690(NULL) {
    u32 flags;

    m_name = TBoss7DeRolLeC__class_name;
    if (boss7_joint_state == 0) {
        boss7_joint_state = (u32)this;
    }
    reset_hp((u8 *)TLobby::register_boss(15), (u8 *)TLobby::dispatch_shared_handler_b(15), (u8 *)TLobby::register_object(15));
    unk_620 = (TBoss7DeRolLeCParams *)TLobby::dispatch_shared_handler_a(15);
    invoke_initialization_hook(set_data);
    unk_628 = 0;
    if (exchange_object_state((s32)&flags, 1) && (flags & 0x12008) == 0x12008) {
        unk_628 |= 0x8000;
    }
    init_position_vectors();
    model = (void *)get_bml_model((BmlResource *)lbl_805D6918, 0);
    texlist = TObjFish__sub_8001EDB0((BmlResource *)lbl_805D6918, 0);
    TObjPlayer__sub_802E7EA0(this);
    copy_collision_body(&unk_3C0, &lbl_80473C3C);
    set_collision_body(&unk_3C0);
    transform_part_positions();
    motion_flags = 0;
    set_field_d8((s32)&lbl_804E3D1C[4]);
    set_field_dc((s32)((BmlResource *)lbl_805D6918)->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    check_state_flag_2();
    movementParameters = lbl_804E3C8C;
    initialize_enemy_state(0x49);
    unk_37C = 20.0f;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    unk_7A8 = 0;
    crawfish_parent = new TObject(this);
    unk_62C = 0;
    unk_6B0 = 0;
    action_index = 0;
    for (s32 i = 0; i < 20; i++) {
        unk_3EC[i].x = 0.0f;
        unk_3EC[i].y = 0.0f;
        unk_3EC[i].z = 0.0f;
    }
    for (s32 i = 0; i < 4; i++) {
        unk_4DC[i].x = 0.0f;
        unk_4DC[i].y = 0.0f;
        unk_4DC[i].z = 0.0f;
    }
    unk_6D8 = (GC_Mtx *)mem_alloc(4 * sizeof(GC_Mtx));
    for (s32 i = 0; i < 4; i++) {
        set_matrix_identity((u8 *)unk_6D8[i]);
        unk_6DC[i] = new TBoss7Tentacle(&unk_690, (s32)unk_6D8[i], i);
    }
    Vec v = lbl_80473F6C;
    u16 id = entity_id + 1;
    s32 set = set_index + 1;
    for (s32 i = 0; i < 10; i++) {
        VecCopy(&unk_530[i], &v);
        unk_5F8[i] = new TBoss7Joint(this, id++, set++, &unk_530[i], i);
    }
    unk_6C0 = 0;
    unk_6C4 = 0;
    unk_6C8 = 0;
    unk_6CC = 0;
    unk_6D0 = 0;
    motion_x.init_float_block();
    motion_y.init_float_block();
    motion_z.init_float_block();
    unk_6EC.x = 0.0f;
    unk_6EC.y = 0.0f;
    unk_6EC.z = 0.0f;
    unk_6F8 = unk_6FC = unk_620->unk_18;
    unk_700 = unk_620->unk_20;
    hpmax = hp = 20000;
    unk_704 = 0;
    unk_708 = new TBoss7LaserLight(&unk_690, &unk_70C);
    unk_70C.x = 0.0f;
    unk_70C.y = 0.0f;
    unk_70C.z = 0.0f;
    unk_718 = new AreaAttackHistory(4);
    fill_value_array(unk_718);
    unk_71C = 0;
    unk_720 = 0;
    for (s32 i = 0; i < 3; i++) {
        VecCopy(&unk_50C[i], &position);
    }
    unk_6BC = 0;
    unk_6D4 = (GC_Mtx *)mem_alloc(12 * sizeof(GC_Mtx));
    for (s32 i = 0; i < 12; i++) {
        set_matrix_identity((u8 *)unk_6D4[i]);
    }
    for (s32 i = 0; i < 6; i++) {
        unk_788[i] = NULL;
    }
    unk_7A0 = 0;
    unk_724 = 0;
    unk_728 = 0;
    unk_72C = 0;
    unk_730 = 0;
    unk_734 = 0;
    unk_738 = 0;
    unk_73C = 0;
    unk_740 = 0;
    unk_744 = 0.0f;
    unk_748 = 0.0f;
    unk_74C = 0.0f;
    unk_750 = 0.0f;
    unk_754 = 0.0f;
    unk_758 = 0.0f;
    unk_75C = 0.0f;
    unk_760 = 0.0f;
    unk_764 = 0.0f;
    unk_768 = 0.0f;
    unk_76C = 0.0f;
    unk_770 = 0.0f;
    unk_774 = 0.0f;
    unk_778 = 0.0f;
    unk_77C = 0.0f;
    unk_780 = 0.0f;
    unk_784 = NULL;
    unk_6AC = 0;
    unk_624 = &controller_input_state.controllers[1];
    if (TObjEneDD::is_main_phase_15()) {
        if (update_lobby_state()) {
            unk_6B8 = 0;
        } else {
            unk_6B8 = 1;
        }
    } else {
        unk_6B8 = 0;
    }
    TBoss7DeRolLeC__sub_802EC994(this);
    if (!(unk_628 & 0x8000)) {
        mode = 1;
        dispatch_action(mode, 4);
    }
    unk_7AC = new TUnk_804F1C58(this, model);
    if (unk_7AC != NULL) {
        unk_7AC->set_field_38((s32)TObjPlayer__sub_802E8274);
    }
    unk_7B0 = 0;
    unk_7B4 = 0.0f;
    unk_7B8 = 0.0f;
    unk_7BC = 0.0f;
    unk_7C0 = 0.0f;
    unk_7C4 = 0.0f;
    unk_7C8 = 0.0f;
    unk_7CC = 0xFFFF;
    unk_7CE = 0xFFFF;
    unk_7D0 = 0xFFFF;
    unk_7D2 = 0xFFFF;
}
