#ifndef PENULT_H
#define PENULT_H

#define STATUS_GOOD 0
#define STATUS_POISONED 1
#define STATUS_DEAD 2

#define WORLD_WIDTH 80
#define WORLD_HEIGHT 64
#define TOWN_WIDTH 48
#define TOWN_HEIGHT 34
#define DUNGEON_WIDTH 16
#define DUNGEON_HEIGHT 16
#define DUNGEON_LEVELS 8
#define ARENA_WIDTH 11
#define ARENA_HEIGHT 9
#define NUM_TILES 165
#define NUM_DTILES 20
#define NUM_CHARS 91
#define VIEWPORT_WIDTH 11
#define VIEWPORT_HEIGHT 9
#define DUNGEON_VIEWPORT_WIDTH 5
#define DUNGEON_VIEWPORT_HEIGHT 5
#define MW_X 8
#define MW_Y 154
#define MESSAGE_WINDOW_WIDTH 304
#define MESSAGE_WINDOW_HEIGHT 40
#define SW_X 188
#define SW_Y 6

#define WORLD_MAP          0
#define CASTLE_MAP         1
#define ACADIA_MAP         2
#define STONEHEART_MAP     3
#define OAK_MAP            4
#define WATERS_MAP         5
#define FREEHAVEN_MAP      6
#define CASTLEB_MAP        7
#define DUSKGROVE_MAP      8
#define SPIRETOP_MAP       9
#define THANAS_HOLD_MAP    10
#define KEEP_OF_SHADOW_MAP 11

#define MAP_MAX            KEEP_OF_SHADOW_MAP

#define DUNGEON_WALL          0
#define DUNGEON_DOOR          1
#define DUNGEON_FAKE_WALL     2
#define DUNGEON_STAIRS_UP     3
#define DUNGEON_STAIRS_DOWN   4
#define DUNGEON_LADDER        5
#define DUNGEON_TRAP          6
#define DUNGEON_ENERGY        7
#define DUNGEON_FOUNTAIN      8
#define DUNGEON_MESSAGE       9
#define DUNGEON_WIND          10
#define DUNGEON_CHEST         11
#define DUNGEON_ORB           12
#define DUNGEON_TELEPORTER    13
#define DUNGEON_PIT           14
#define DUNGEON_STONE_FLOOR   15
#define DUNGEON_HERO          16
#define DUNGEON_FUZZY         17
#define DUNGEON_BLANK         18
#define DUNGEON_OPEN_CHEST    19
#define DUNGEON_TELEPORTER_ALT 20
#define DUNGEON_ENERGY_ALT    21
#define DUNGEON_FOUNTAIN_ALT  22


#define LOW_BYTE(n) (n&0x00FF)
#define HI_BYTE(n) ((n>>8)&0x00FF)

#define DEFAULT_PALETTE    5
#define COMPOSITE_PALETTE  4
#define DUNGEON_PALETTE    2
#define DUNGEON_COMBAT_PALETTE   0


void read_joy_buttons();
void read_joy();
void init_joystick();
int check_joystick_input();
int check_button_press();
void oh_shit(char *error_message);
void parse_option(char Opt);
void load_display_gui();
void draw_stats();
void load_tiles();
void update_world_map_at(int8_t MapX, int8_t MapY);
void update_town_map_at(int8_t MapX, int8_t MapY);
void update_dungeon_map_at(int8_t MapX, int8_t MapY);
void do_vision();
void do_dungeon_vision();
void display_map();
void display_dungeon_map();
int get_direction();
void CheckMoveHero();
void CheckMoveHeroDungeon();
void (__interrupt __far *prev_int_1c)();
void __interrupt __far timer_rtn();
void cleanup();
void set_timer(unsigned int Divisor);
void play_sound(int SoundNumber);
void play_music(int MusicNumber);
void load_acadia();
void load_castle();
void load_oak();
void load_duskgrove();
void load_stoneheart();
void load_waters();
void load_spiretop();
void load_castleb();
void load_castle_up();
void load_thanas_hold_east();
void load_thanas_hold_west();
void load_guru();
void load_refugee_camp();
void load_duskgrove_up();
void load_phoenix();
void load_energy();
void load_secrets();
void load_passage();
void load_dungeon(int DungeonMap);
void load_map(uint8_t MapNum);
int check_triggers();
uint8_t dungeon_triggers();
void do_death();
void dungeon_cancel();
void dungeon_ascend();
void dungeon_descend();
void dungeon_drink();
void clear_dungeon_screen();
void exit_dungeon();
void leave_town();
void print_line_formatted(int x, int y, uint8_t Invert, const char *fmt, ...);
void print_line(int x, int y, uint8_t Invert, const char *message);
void clear_text_window();
void generate_character();
void draw_name_letter();
int validate_name(char *Name);
void save_game();
void load_game();
void create_menu();
void check_update_menu();
void activate_menu_item();
void print_pager_line(const char *Message);
void queen_talk();
void do_buy_yes();
void do_buy_no();
void do_bartender_yes();
void do_bartender_no();
void vendor_function();
void bartender_function();
void check_gain_fire_ritual();
void fire_ritual_function();
void check_gain_energy_ritual();
void energy_ritual_function();
void advanced_trainer_check();
void advanced_trainer_function();
void advanced_trainer_yes();
void advanced_trainer_no();
void do_dungeon_dark();
void do_talk();
void do_use();
void do_cast();
void do_stats();
void do_heal_potion();
void do_cure_potion();
void do_disguise_dust();
void do_homing_gem();
void do_loot();
void do_yes_no_menu();
void do_loot_yes();
void do_loot_no();
char *split_line_start(const char *Source, int *SplitIndex);
void flash_effect();
void invalidate_view();
void clear_view();
void end_combat();
void load_arena(int CurrentArena);
void start_combat();
void do_attack();
void do_ranged();
void do_combat_move(int Direction);
void do_pass();
void do_dragon_heal();
void do_dungeon_trap();
uint8_t find_gold(uint8_t GoldLevel);
void advance_combat_state();
int which_direction();
void update_missile();
int TileCreature(int CombatX, int CombatY);
int space_free(int CombatX, int CombatY);
void invert_viewport();
void damage_hero(int Damage);
void damage_dragon(int Damage);
void damage_enemy(int Enemy, int Damage);
void do_enemy_turn(int Enemy);
void do_cast_ray();
void do_cast_swap();
void do_cast_sun();
void do_cast_heal();
void do_cast_hop();
void do_cast_zap();
int deduct_spell_points(int Points);
int check_new_spell();
void CheckEncountersAndStatus();
void do_poison();

typedef struct {
   uint8_t Y;
   void (*TriggerFunction)();
} Trigger;

typedef struct {
   uint8_t X;
   const Trigger *YList;
   uint8_t YLen;
} TList;

#define WATER_ROCK_TILE 0
#define SHIP_TILE 1
#define LAVA_TILE 2
#define WATER_TILE 3
#define INNER_WALL_TILE 4
#define INNER_WALL_SECRET_TILE 5
#define BRIDGE_TILE 6
#define DIRT_TILE 7
#define GRASS_TILE 8
#define FOREST_TILE 9
#define MOUNTAIN_TILE 10
#define CASTLE_TILE 11
#define CIRCLE_TILE 12
#define TOWN_TILE 13
#define DUNGEON_TILE 14
#define HEAVY_FOREST_TILE 15
#define HERO_TILE 16
#define DHERO_TILE 11
#define NOTHING_TILE 17
#define STONE_WALL_TILE 18
#define ROCKY_WALL_TILE 95
#define FORCE_FIELD_TILE 21

#define PLAINS_ARENA 0
#define FOREST_ARENA 1
#define HEAVY_FOREST_ARENA 2
#define BRIDGE_ARENA 3
#define SAND_ARENA 4
#define SHIP_ARENA 5
#define CITY_ARENA 6
#define LAVA_ARENA 7
#define CASTLE_ARENA 8
#define WATER_ARENA 9
#define SHIP_SHIP_ARENA 10
#define DUNGEON_ARENA 11


#define BLOCKED_SOUND   0
#define WALK_SOUND      1
#define CAST_SOUND      2
#define HEAL_SOUND      3
#define MISS_SOUND      4
#define HIT_SOUND       5
#define MISSILE_SOUND   6
#define BREATH_SOUND    7
#define DOOR_SOUND      8
#define ENERGY_SOUND    9
#define WIND_SOUND      10
#define DIVIDE_SOUND    11

#define COMBAT_START_MUSIC    0
#define VICTORY_MUSIC         1

#define PHOENIX_DUNGEON 0
#define ENERGY_DUNGEON 1
#define SECRETS_DUNGEON 2
#define PASSAGE_DUNGEON 3
#define DMAP_MAX PASSAGE_DUNGEON

#endif   // PENULT_H