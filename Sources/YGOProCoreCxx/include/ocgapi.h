/*
 * interface.h
 *
 *  Created on: 2010-4-28
 *      Author: Argon
 */

#ifndef OCGAPI_H_
#define OCGAPI_H_

#include "common.h"

#ifdef WIN32
#define DECL_DLLEXPORT __declspec(dllexport)
#else
#define DECL_DLLEXPORT
#endif

class duel;
class card;
struct card_data;
struct card_info;
class group;
class effect;
class interpreter;

typedef byte* (*script_reader)(const char*, int*);
typedef uint32 (*card_reader)(uint32, card_data*);
typedef uint32 (*message_handler)(void*, uint32);

extern "C" DECL_DLLEXPORT void set_script_reader(script_reader f);
extern "C" DECL_DLLEXPORT void set_card_reader(card_reader f);
extern "C" DECL_DLLEXPORT void set_message_handler(message_handler f);

byte* read_script(const char* script_name, int* len);
uint32 read_card(uint32 code, card_data* data);
uint32 handle_message(void* pduel, uint32 message_type);

extern "C" DECL_DLLEXPORT duel* create_duel(uint32 seed);
extern "C" DECL_DLLEXPORT void start_duel(duel* pduel, int32 options);
extern "C" DECL_DLLEXPORT void end_duel(duel* pduel);
extern "C" DECL_DLLEXPORT void set_player_info(duel* pduel, int32 playerid, int32 lp, int32 startcount, int32 drawcount);
extern "C" DECL_DLLEXPORT void get_log_message(intptr_t pduel, byte* buf);
extern "C" DECL_DLLEXPORT int32 get_message(duel* pduel, byte* buf);
extern "C" DECL_DLLEXPORT int32 process(duel* pduel);
extern "C" DECL_DLLEXPORT void new_card(duel* ptduel, uint32 code, uint8 owner, uint8 playerid, uint8 location, uint8 sequence, uint8 position);
extern "C" DECL_DLLEXPORT void new_tag_card(duel* pduel, uint32 code, uint8 owner, uint8 location);
extern "C" DECL_DLLEXPORT int32 query_card(duel* pduel, uint8 playerid, uint8 location, uint8 sequence, int32 query_flag, byte* buf, int32 use_cache);
extern "C" DECL_DLLEXPORT int32 query_field_count(duel* pduel, uint8 playerid, uint8 location);
extern "C" DECL_DLLEXPORT int32 query_field_card(duel* pduel, uint8 playerid, uint8 location, int32 query_flag, byte* buf, int32 use_cache);
extern "C" DECL_DLLEXPORT int32 query_field_info(duel* ptduel, byte* buf);
extern "C" DECL_DLLEXPORT void set_responsei(duel* pduel, int32 value);
extern "C" DECL_DLLEXPORT void set_responseb(duel* pduel, byte* buf);
extern "C" DECL_DLLEXPORT int32 preload_script(duel* pduel, const char* script, int32 len);
byte* default_script_reader(const char* script_name, int* len);
uint32 default_card_reader(uint32 code, card_data* data);
uint32 default_message_handler(void* pduel, uint32 msg_type);

#endif /* OCGAPI_H_ */
