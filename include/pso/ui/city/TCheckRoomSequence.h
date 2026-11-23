#ifndef PSO_UI_CITY_TCHECKROOMSEQUENCE_H
#define PSO_UI_CITY_TCHECKROOMSEQUENCE_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopSequence.h"

class TWindowBase;
struct TWindowMenu;
struct TItemData;

struct TCheckRoomSequence : public TShopSequence {
    TCheckRoomSequence(TObject *parent, TObjPlayer *player);
    virtual ~TCheckRoomSequence();
    virtual void update_state();
    virtual void restore_player_state();
    virtual void close_window();

    static int get_room_data(int a0);
    static int get_room_table_entry(int a0);
    static void *create(void *arg0);
    static void reset_slot_state();
    static void reset_slots();
    static s32 get_item_def(uaddr arg0);
    // States of the update_state table, in table order.
    void open_bank();
    void handle_root_choice();
    void handle_deposit_choice();
    void open_deposit_item_window();
    void accept_meseta_deposit(void *);
    void begin_meseta_deposit(void *);
    void begin_meseta_withdrawal(void *);
    void open_get_item_window(void *);
    void handle_withdraw_choice();
    void accept_meseta_withdrawal(void *);
    void sub_802100FC();
    void sub_802100F8();
    void handle_error_ack(void *);
    void sub_8020F1DC();
    void set_quest_list_mode_19(void *);
    void open_delete_item_window(void *);
    static void alloc_item_buffers();
    // The bank keeps 200 item records per player slot.
    static void compact_items(int slot);
    static void remove_bank_item_amount(int index, int amount, int slot);
    static s32 copy_item_record(int index, void *data, int slot);

    s32 pad_2c;
    u32 pad_30;                     // 0x30: freed with safe_free
    TWindowBase *pad_34;            // 0x34: the deposit / item windows
    TWindowBase *meseta_window;     // 0x38: create_meseta_window
    TWindowMenu *choice_menu;       // 0x3C: the room menu
    TWindowBase *deposit_window;    // 0x40: the TWindowDeposit of open_bank
    s32 pad_44;
    TObject *counter_camera;        // 0x48: set_service_counter_camera
};

s32 bank_has_free_row(s32 slot);
extern "C" {
void sort_bank_items(s32 slot);
s32 get_bank_deposit_capacity_for_item(TItemData *item, s32 slot);
s32 copy_bank_item_with_stack_limit(s32 index, void *data, s32 *count, s32 slot);
s32 store_item_in_bank(u8 *item, s32 amount, s32 slot);
void copy_bank_to_card_window(s32 slot);
}

LAYOUT_ASSERT(TCheckRoomSequence_size, sizeof(TCheckRoomSequence) == 0x4C);
LAYOUT_ASSERT(TCheckRoomSequence_choice_menu_offset, offsetof(TCheckRoomSequence, choice_menu) == 0x3C);
#endif
