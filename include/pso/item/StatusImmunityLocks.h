#ifndef PSO_ITEM_STATUSIMMUNITYLOCKS_H
#define PSO_ITEM_STATUSIMMUNITYLOCKS_H

#include "types.h"

void remove_freeze_immunity(int client);
void remove_slow_immunity(int client);
void remove_shock_immunity(int client);
void remove_paralysis_immunity(int client);
void remove_poison_immunity(int client);
void remove_status_cleanse(int client);
void add_freeze_immunity(int client);
void add_confusion_immunity(int client);
void add_paralysis_immunity(int client);
void add_shock_immunity(int client);
void add_slow_immunity(int client);
void remove_confusion_immunity(int client);

void add_poison_immunity(int client);
void add_status_cleanse(int client);
void unlock_effect(u16 client, u32 effect);
void lock_effect(u16 client, u32 effect);
void free_all();

#endif
