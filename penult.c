#define __CGALIB__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <dos.h>
#include <sys/types.h>
#include "cgalib.h"
#include "keylib.h"
#include "penult.h"
#include "gametxt.h"

typedef struct DVisionTilesType {
    struct SrcCoordType {
        char X;
        char Y;
    } SrcCoord;

    struct P1CoordType {
        char X;
        char Y;
    } P1Coord;

    struct P2CoordType {
        char X;
        char Y;
    } P2Coord;
} DVisionTilesType;

const DVisionTilesType DVisionTiles[8] = {
    {
        {.X = 1, .Y = 0},
        {.X = 1, .Y = 1},
        {.X = 2, .Y = 1}
    },
    {
        {.X = 3, .Y = 0},
        {.X = 3, .Y = 1},
        {.X = 2, .Y = 1}
    },

    {
        {.X = 4, .Y = 1},
        {.X = 3, .Y = 1},
        {.X = 3, .Y = 2}
    },
    {
        {.X = 4, .Y = 3},
        {.X = 3, .Y = 3},
        {.X = 3, .Y = 2}
    },

    {
        {.X = 3, .Y = 4},
        {.X = 3, .Y = 3},
        {.X = 2, .Y = 3}
    },
    {
        {.X = 1, .Y = 4},
        {.X = 1, .Y = 3},
        {.X = 2, .Y = 3}
    },

    {
        {.X = 0, .Y = 3},
        {.X = 1, .Y = 3},
        {.X = 1, .Y = 2}
    },
    {
        {.X = 0, .Y = 1},
        {.X = 1, .Y = 1},
        {.X = 1, .Y = 2}
    }
};

struct {
    uint8_t Opaque : 1;
    uint8_t Solid : 1;
} TileProperties[NUM_TILES] = {
    {0,1},  // water rock
    {0,0},
    {0,0},
    {0,1},  // water
    {1,1},  // inner wall
    {1,0},  // fake inner wall
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {1,1},  // 10 mountains
    {0,0},
    {0,0},
    {0,0},
    {1,0},  // Dungeon enterance
    {1,0},  // Heavy forest
    {0,0},
    {1,1},  // Nothing tile
    {1,1},  // outer wall
    {0,1},  // window
    {0,0},  // 20
    {0,1},  // force field
    {0,0},
    {0,1},  // blank counter
    {0,1},  // counter A
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},  // 30
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},  // 40
    {0,1},
    {0,1},
    {0,1}, 
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},  // counter Z
    {0,1},  // 50 merchant
    {0,1},  // queen
    {0,1},  // king Rufus
    {0,1},  // healer
    {0,1},  // fighter
    {0,1},  // wizard
    {0,1},  // dwarf
    {0,1},  // iron gate
    {0,1},  // jester
    {0,1},  // guard
    {0,0},  // 60
    {0,0},
    {0,1},  // fire beetle
    {0,1},  // goblin
    {0,0},
    {0,0},
    {0,1},  // woman
    {0,0},
    {0,0},
    {0,1},  // troll/ogre
    {1,1},  // 70 pillar/tree
    {0,1},  // shadow orb
    {0,1},  // head
    {0,0},
    {0,1},  // weapon shop sign
    {0,1},  // armor shop sign
    {0,1},  // potion shop sign
    {0,1},  // healer shop sign
    {0,1},  // bar sign
    {0,1},  // food shop sign
    {0,0},  // 80 - stairs up
    {0,0},  // stairs down
    {0,1},  // woman
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},  // cobblestone floor
    {0,0},  // 90
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},  // dungeon combat wall
    {0,1},  // lava rock
    {0,0},  // dungeon combat tile 1
    {0,0},  // dungeon combat tile 2
    {0,0},  // dungeon combat tile 3
    {0,0},  // dungeon combat tile 4
    {0,0},  // dungeon combat tile 5
    {0,0},  // dungeon combat tile 6
    {0,0},  // dungeon combat tile 7
    {0,0},  // dungeon combat tile 8
    {0,0},  // dungeon combat tile 9
    {0,0},  // dungeon combat tile 10
    {0,0},  // dungeon combat tile 11
    {0,0},  // dungeon combat tile 12
    {0,0},  // dungeon combat tile 13
    {0,0},  // dungeon combat tile 14
    {0,0},  // castle alt
    {0,0},  // town alt
    {0,0},  // lava alt
    {0,1},  // 100 - water rock alt
    {0,1},  // merchant alt
    {0,1},  // king Rufus alt
    {0,1},  // queen alt
    {0,1},  // fighter alt
    {0,1},  // wizard alt
    {0,1},  // healer alt
    {0,1},  // guard alt
    {0,1},  // dwarf alt
    {0,1},  // woman alt
    {0,1},  // 110 - jester alt
    {0,1},  // water alt
    {0,0},  // lava rock alt
    {0,0},  // 
    {0,0},  // 
    {0,0},  // 
    {0,1},  // goblin alt 
    {0,0},  // 
    {0,0},  // 
    {0,0},  // 
    {0,0},  // 120
    {0,0},  // 
    {0,1},  // fire beetle alt
    {0,1},  // troll/ogre alt
    {0,1},  // shadow orb alt
    {0,1},  // head alt
    {0,1},  // lava stone alt   
    {0,0},  // 
    {0,1},  // demon guard alt
    {0,0},  // 
    {0,0},  // 130
    {0,0},  // 
    {0,0},  // 
    {0,0},  // 
    {0,0},  // 
    {0,0},  // 
    {0,0}   // 
};

const uint8_t DTilesOpaque[] = {
    1,  // wall
    1,  // door
    1,  // fake wall
    0,  // stairs-up
    0,  // stairs-down
    0,  // ladder
    0,  // trap
    0,  // energy
    0,  // fountain
    0,  // message
    0,  // wind
    0,  // chest
    0,  // orb
    0,  // teleporter
    0,  // pit
    0,  // stone floor
    0,  // hero
    1,  // fuzzy
    1,  // blank
    0,  // open chest
    0,  // alt teleporter
    0,  // alt energy
    0   // alt fountain
};

const uint8_t DTilesSolid[] = {
    1,  // wall
    0,  // door
    0,  // fake wall
    0,  // stairs-up
    0,  // stairs-down
    0,  // ladder
    0,  // trap
    0,  // energy
    0,  // fountain
    0,  // message
    0,  // wind
    0,  // chest
    0,  // orb
    0,  // teleporter
    0,  // pit
    0,  // stone floor
    0,  // hero
    1,  // fuzzy
    1,  // blank
    0,  // open chest
    0,  // alt teleporter
    0,  // alt energy
    0   // alt fountain
};

const uint8_t DTilesVisible[] = {
    1,  // wall
    2,  // door
    1,  // fake wall
    3,  // stairs-up
    4,  // stairs-down
    5,  // ladder
    13, // trap
    8,  // energy
    12, // fountain
    13, // message
    13, // wind
    9,  // chest
    19, // orb
    7,  // teleporter
    6,  // pit
    13, // stone floor
    17, // fuzzy
    18, // fuzzy2
    0,  // blank
    10  // open chest 
};

const uint8_t DTilesDark[] = {
    0,  // wall
    0,  // door
    0,  // fake wall
    0,  // stairs-up
    0,  // stairs-down
    0,  // ladder
    0, // trap
    8,  // energy
    0, // fountain
    0, // message
    0, // wind
    0,  // chest
    0, // orb
    0,  // teleporter
    0,  // pit
    0, // stone floor
    0, // fuzzy
    0, // fuzzy2
    0,  // blank
    0  // open chest 
};

const uint8_t DTilesDarkAlt[] = {
    0,  // wall
    0,  // door
    0,  // fake wall
    0,  // stairs-up
    0,  // stairs-down
    0,  // ladder
    0, // trap
    15, // energy
    0, // fountain
    0, // message
    0, // wind
    0,  // chest
    0, // orb
    0, // teleporter
    0,  // pit
    0, // stone floor
    0, // fuzzy
    0, // fuzzy2
    0,  // blank
    0  // open chest
};


const uint8_t DTilesFlippable[] = {
    0,  // wall
    0,  // door
    0,  // fake wall
    0,  // stairs-up
    0,  // stairs-down
    0,  // ladder
    0,  // trap
    1,  // energy
    1,  // fountain
    0,  // message
    0,  // wind
    0,  // chest
    0,  // orb
    1,  // teleporter
    0,  // pit
    0,  // stone floor
    0,  // fuzzy
    0,  // fuzzy2
    0,  // blank
    0   // open chest 
};

const uint8_t DTilesVisibleAlt[] = {
    1,  // wall
    2,  // door
    1,  // fake wall
    3,  // stairs-up
    4,  // stairs-down
    5,  // ladder
    13, // trap
    15, // energy
    16, // fountain
    13, // message
    13, // wind
    9,  // chest
    19, // orb
    14, // teleporter
    6,  // pit
    13, // stone floor
    17, // fuzzy
    18, // fuzzy2
    0,  // blank
    10  // open chest
};


void (*DungeonMenuActions[])() = {
    do_cast, do_loot, do_use
};

void (*OutdoorMenuActions[])() = {
    do_cast, do_use, do_stats
};

void (*TownMenuActions[])() = {
    do_talk, do_cast, do_use, do_stats
};

void (*VendorMenuActions[])() = {
    do_buy_yes, do_buy_no
};

void (*HeroCombatMenuActions[])() = {
    do_attack, do_ranged, do_cast, do_use, do_pass
};

void (*DragonCombatMenuActions[])() = {
    do_attack, do_ranged, do_dragon_heal, do_pass
};

void (*SpellMenuActions[])() = {
    do_cast_ray, do_cast_swap, do_cast_sun, do_cast_heal, do_cast_hop, do_cast_zap
};


void (**MenuActions[])() = {
    OutdoorMenuActions,
    TownMenuActions,
    VendorMenuActions,
    HeroCombatMenuActions,
    DragonCombatMenuActions,
    SpellMenuActions,
    DungeonMenuActions
};

void (*Actions[])() = {
    NULL, queen_talk, vendor_function, bartender_function, NULL,
     check_gain_fire_ritual, NULL, NULL, check_gain_energy_ritual,
     advanced_trainer_check
};


const Trigger world6[] = {
    {26, &load_energy}
};

const Trigger world19[] = {
    {26, &load_guru}
};

const Trigger world33[] = {
    {13, &load_stoneheart}
};

const Trigger world36[] = {
    {49, &load_spiretop}
};

const Trigger world38[] = {
    {27, &load_waters}
};

const Trigger world41[] = {
    {13, &load_castle}
};

const Trigger world45[] = {
    {18, &do_poison}
};

const Trigger world46[] = {
    {8, &load_phoenix}
};

const Trigger world48[] = {
    {15, &load_acadia}
};

const Trigger world57[] = {
    {57, &load_thanas_hold_west}
};

const Trigger world59[] = {
    {57, &load_thanas_hold_east}
};

const Trigger world69[] = {
    {32, &load_oak}
};

const Trigger world71[] = {
    {9, &load_duskgrove}
};

const Trigger acadia5[] = {
    {10, &save_game}
};

const Trigger castle40[] = {
    {6, &load_castleb}
};

const Trigger castleb40[] = {
    {6, &load_castle_up}
};

const Trigger castleb1[] = {
    {23, &leave_town}
};

const Trigger castleb45[] = {
    {5, &load_duskgrove_up}
};

const Trigger duskgrove45[] = {
    {5, &load_refugee_camp}
};

const TList world_triggers[] = {
    {6, world6, 1},
    {19, world19, 1},
    {33, world33, 1},
    {36, world36, 1},
    {38, world38, 1},
    {41, world41, 1},
    {45, world45, 1},
    {46, world46, 1},
    {48, world48, 1},
    {57, world57, 1},
    {59, world59, 1},
    {69, world69, 1},
    {71, world71, 1},
    {0, NULL, 0}
};

const TList castle_triggers[] = {
    {40, castle40, 1},
    {0, NULL, 0}
};

const TList acadia_triggers[] = {
    {5, acadia5, 1},
    {0, NULL, 0}
};

const TList stoneheart_triggers[] = {
    {0, NULL, 0}
};

const TList oak_triggers[] = {
    {0, NULL, 0}
};

const TList waters_triggers[] = {
    {0, NULL, 0}
};

const TList freehaven_triggers[] = {
    {0, NULL, 0}
};

const TList castleb_triggers[] = {
    {1, castleb1, 1},
    {40, castleb40, 1},
    {45, castleb45, 1},
    {0, NULL, 0}
};

const TList duskgrove_triggers[] = {
    {45, duskgrove45, 1},
    {0, NULL, 0}
};

const TList spiretop_triggers[] = {
    {0, NULL, 0}
};

const TList thanas_hold_triggers[] = {
    {0, NULL, 0}
};

const TList keep_of_shadow_triggers[] = {
    {0, NULL, 0}
};

const TList *Triggers[MAP_MAX+1] = {
    world_triggers,
    castle_triggers,
    acadia_triggers,
    stoneheart_triggers,
    oak_triggers,
    waters_triggers,
    freehaven_triggers,
    castleb_triggers,
    duskgrove_triggers,
    spiretop_triggers,
    thanas_hold_triggers,
    keep_of_shadow_triggers
};

const char *map_names[MAP_MAX+1] = {
    "world.map",
    "castle.map",
    "acadia.map",
    "stonehrt.map",
    "oak.map",
    "waters.map",
    "freehven.map",
    "castleb.map",
    "duskgrov.map",
    "spiretop.map",
    "thanahld.map",
    "keepshdw.map"
};

const char *dmap_names[DMAP_MAX+1] = {
    "phoenix.map",
    "energy.map",
    "secrets.map",
    "passage.map"
};

// 1193180 / Freq
const unsigned int blocked_sound_data[] = {0x4745, 0x4745, 0, 0, 0x4745, 0x4745, 0, 0, 0x4745, 0x4745};
const unsigned int walk_sound_data[] = {0xA000, 0xCF26};
const unsigned int cast_sound_data[] = {0x0A00, 0x0, 0x0800, 0x0, 0x0600, 0x0, 0x0A00, 0x0, 0x0800, 0x0, 0x0600, 0x0, 0x0A00, 0x0, 0x0800, 0x0, 0x0600};
const unsigned int heal_sound_data[] = {604, 538, 452, 452, 380, 302, 302, 226, 151};
const unsigned int miss_sound_data[] = {1356, 1612, 1811, 2033, 2281, 2560, 2712};
const unsigned int hit_sound_data[] = {18357, 17292, 16345, 14551, 13715};
//const unsigned int missile_sound_data[] = {25939, 25939, 29102, 29102, 29830, 29830, 31399, 31399};
const unsigned int missile_sound_data[] = {12970, 12970, 14551, 14551, 14915, 14815, 15700, 15700};
const unsigned int breath_sound_data[] = {0x6000, 0x9000, 0x6000, 0x9000, 0x6000, 0x9000, 0x6000, 0x9000};
const unsigned int door_sound_data[] = {38490, 38490, 32248, 32248, 29102, 29102, 22946, 22946, 19245, 19245, 14551, 14551, 9622, 9622};
const unsigned int energy_sound_data[] = {0x1000, 0x4745, 0x1000, 0x4745, 0x1000, 0x4745, 0x1000, 0x4745, 0x1000, 0x4745, 0x1000, 0x4745, 0x1000, 0x4745, 0x1000, 0x4745};
const unsigned int wind_sound_data[] = {0x3000, 0xB000, 0x3800, 0xB000, 0x4000, 0xB000, 0x4800, 0xB000, 0x5000, 0xB000, 0x5800, 0xB000};
const unsigned int divide_sound_data[] = {12899, 12899, 11495, 11495, 10847, 10847, 9661, 9661, 8128, 8128, 7240, 7240, 5745, 5745};
const unsigned int* Sounds[] = {
    blocked_sound_data,
    walk_sound_data,
    cast_sound_data,
    heal_sound_data,
    miss_sound_data,
    hit_sound_data,
    missile_sound_data,
    breath_sound_data,
    door_sound_data,
    energy_sound_data,
    wind_sound_data,
    divide_sound_data
};

const uint8_t SoundLength[] = {
    sizeof(blocked_sound_data)/sizeof(unsigned int),
    sizeof(walk_sound_data)/sizeof(unsigned int),
    sizeof(cast_sound_data)/sizeof(unsigned int),
    sizeof(heal_sound_data)/sizeof(unsigned int),
    sizeof(miss_sound_data)/sizeof(unsigned int),
    sizeof(hit_sound_data)/sizeof(unsigned int),
    sizeof(missile_sound_data)/sizeof(unsigned int),
    sizeof(breath_sound_data)/sizeof(unsigned int),
    sizeof(door_sound_data)/sizeof(unsigned int),
    sizeof(energy_sound_data)/sizeof(unsigned int),
    sizeof(wind_sound_data)/sizeof(unsigned int),
    sizeof(divide_sound_data)/sizeof(unsigned int),
};

// 1193180 / Freq
//const unsigned int combat_start_music_data[] = {10847, 11, 9622, 11, 3616, 10, 4831, 10, 5736, 10, 9622, 10, 7231, 13, 0xFFFF};
//const unsigned int combat_start_music_data[] = {2560, 11, 2416, 11, 1810, 10, 2416, 10, 3044, 10, 4832, 10, 3620, 13, 0xFFFF};
//const unsigned int combat_start_music_data[] = {5119, 11, 4832, 11, 3620, 10, 4832, 10, 6088, 10, 9663, 10, 7240, 13, 0xFFFF};

const unsigned int combat_start_music_data[] = {10238, 11, 9664, 11, 3620, 10, 4832, 10, 6088, 10, 9663, 10, 7240, 13, 0xFFFF};

//const unsigned int victory_music_data[] = {2416, 15, 2712, 15, 2416, 15, 2280, 15, 1918, 30, 0xFFFF};
const unsigned int victory_music_data[] = {3417, 8, 4561, 8, 3417, 8, 2712, 8, 3417, 8, 2712, 8, 2280, 8, 2712, 8, 2280, 8, 1810, 8, 2280, 8, 1810, 8, 1708, 48, 0xFFFF};

const unsigned int* Music[] = {
    combat_start_music_data,
    victory_music_data
};


uint8_t o1_indexes[] = {56, 55, 64, 54, 63, 72};
uint8_t o2_indexes[] = {66, 74, 75, 82, 83, 84, 90, 91, 92, 93};
uint8_t o3_indexes[] = {68, 77, 86, 95, 78, 87, 96, 88, 97, 98};
uint8_t o4_indexes[] = {60, 61, 70, 62, 71, 80};
uint8_t o5_indexes[] = {42, 34, 43, 26, 35, 44};
uint8_t o6_indexes[] = {32, 23, 14, 5, 24, 15, 6, 16, 7, 8};
uint8_t o7_indexes[] = {30, 21, 20, 12, 11, 10, 3, 2, 1, 0};
uint8_t o8_indexes[] = {38, 37, 36, 28, 27, 18};

static uint8_t tile_mapping[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
    49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65,
    66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82,
    83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110
};

static uint8_t tile_mapping_alt[] = {114, 1, 113, 125, 4, 5, 6, 7, 8, 9, 10, 111, 12, 112, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
    49, 115, 117, 116, 120, 118, 119, 122, 57, 124, 121, 128, 134, 136, 130, 131, 133,
    135, 67, 132, 137, 70, 138, 139, 140, 74, 75, 76, 77, 78, 79, 80, 81, 123,
    127, 141, 142, 143, 144, 145, 89, 90, 146, 147, 148, 149, 95, 126, 150, 151, 152,
    153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163
};

uint8_t viewport[VIEWPORT_WIDTH][VIEWPORT_HEIGHT];
uint8_t viewport_prev[VIEWPORT_WIDTH][VIEWPORT_HEIGHT];

Screen *MyScreen;
KeyHandler *MyKeyHandler;
short joy_x, joy_y;  // stores joystick position
unsigned char b0, b1;      // button status flags
int JoyXLeft, JoyXRight, JoyYUp, JoyYDown;
uint8_t CurrentPalette = DEFAULT_PALETTE;
unsigned volatile int ClockTicks = 0;
unsigned int PrevTicks = 0;
uint8_t LogicalTicks = 0;
extern volatile int SaveKey;
char *CurrentMap;
uint16_t *CurrentFont;
Bitmap *Tiles[NUM_TILES];
Bitmap *DTiles[NUM_DTILES];
Bitmap *ViewportBuffer;
Bitmap *ClearText;

struct {
    uint8_t FireRitual : 1;
    uint8_t EnergyRitual : 1;
    uint8_t FireAcorns : 1;
    uint8_t SpiritStone : 1;
    uint8_t HomingGem : 1;
    uint8_t DisguiseDust : 1;
    int8_t X;
    int8_t Y;
    int8_t PrevX;
    int8_t PrevY;
    uint8_t CurrentMap;
    uint8_t PrevMap;
    uint8_t HP;
    uint8_t MHP;
    uint8_t SP;
    uint8_t MSP;
    uint8_t Level;
    uint8_t XP;
    uint8_t SpellsKnown;
    uint8_t Str;
    uint8_t Dex;
    uint8_t Int;
    uint8_t Gender;
    uint8_t Food;
    int Gold;
    uint8_t Status;
    uint8_t Armor;
    uint8_t Melee;
    uint8_t Ranged;
    uint8_t HealPotions;
    uint8_t CurePotions;
    uint8_t DragonHP;
    char *Name;
} Hero;

struct {
    uint8_t Active;
    uint8_t Type;
    uint8_t Selection;
    uint8_t VendorType;
    uint8_t Choices;
    void (*Actions[6])();
    uint8_t MarkerPos[7];
    uint8_t SpellOrder[6];
    int Value;
} Menu;

struct {
   unsigned int JoystickPresent : 1;
   unsigned int Monochrome : 1;
   unsigned int Composite : 1;
   unsigned int MessageActive : 1;
   unsigned int InDungeon : 1;
   unsigned int Flipped : 1;
   unsigned int Moved : 1;
   unsigned int WeaponCorroded : 1;
   unsigned int Disguised : 1;
} Flags;

struct {
    uint8_t FlashTimer;
    uint8_t NPC;
    uint8_t MapWidth;
    uint8_t MapHeight;
    uint8_t Pause;
    uint8_t DoInvert;
    uint8_t DisguiseTile;
    unsigned long long Turns, PrevTurns;
} Game;

struct {
    unsigned int Active : 1;
    unsigned int Victory : 1;
    unsigned int HeroGrappled : 1;
    unsigned int DragonGrappled : 1;
    unsigned int HealUsed : 1;
    uint8_t State;
    uint8_t Timer;
    uint8_t Arena;
    uint8_t EnemyNumber;
    uint8_t EnemyTile;
    uint8_t EnemyPower;
    uint8_t EnemyTraits;
    uint8_t EnemyX[4];
    uint8_t EnemyY[4];
    int EnemyHP[4];
    uint8_t EnemyAC;
    uint8_t HeroX;
    uint8_t HeroY;
    uint8_t DragonX;
    uint8_t DragonY;    
    uint8_t MissileX;
    uint8_t MissileY;
    uint8_t MissileType;
    uint8_t MissileOrigin;
    uint8_t MissileDirection;
    uint8_t MissileActive;
    uint8_t MissileDistance;
    uint8_t MissileDamage;
    uint8_t HitRoll;
    uint8_t Gold;
    uint8_t HeroGrappleEnemy;
    uint8_t DragonGrappleEnemy;
} Combat;

struct {
    uint8_t Number;
    uint8_t Level;
    uint8_t X;
    uint8_t Y;
    uint8_t Orb;
    uint8_t Light;
    uint8_t Pillar[2];
} Dungeon;

typedef struct MessagesType {
    char X;
    char Y;
    char Level;
    const short Message;
} MessagesType;

MessagesType phoenix_messages[] = {
    {.X = 1, .Y = 2, .Level = 0, .Message = DUNGEON__SOME_WALLS_ARE_FAKE},
    {.X = 2, .Y = 1, .Level = 0, .Message = DUNGEON__SOME_WALLS_ARE_FAKE},
    {.X = 15, .Y = 14, .Level = 1, .Message = DUNGEON__DRAFTY_CLUES},
    {.X = 1, .Y = 13, .Level = 2, .Message = DUNGEON__INNER_MAZE},
    {.X = 2, .Y = 14, .Level = 2, .Message = DUNGEON__INNER_MAZE},
    {.X = 1, .Y = 2, .Level = 2, .Message = DUNGEON__INNER_MAZE},
    {.X = 2, .Y = 1, .Level = 2, .Message = DUNGEON__INNER_MAZE},
    {.X = 5, .Y = 10, .Level = 3, .Message = DUNGEON__SECRETS_SECRETS_SEC},
    {.X = 0, .Y = 7, .Level = 4, .Message = DUNGEON__WATERY_ROULETTE},
    {.X = 0, .Y = 9, .Level = 4, .Message = DUNGEON__WATERY_ROULETTE},
    {.X = 14, .Y = 7, .Level = 4, .Message = DUNGEON__WATERY_ROULETTE},
    {.X = 15, .Y = 8, .Level = 4, .Message = DUNGEON__WATERY_ROULETTE},
    {.X = 6, .Y = 15, .Level = 5, .Message = DUNGEON__CENTER_YOURSELF_TO_SOAR},
    {.X = 7, .Y = 14, .Level = 5, .Message = DUNGEON__CENTER_YOURSELF_TO_SOAR},
    {.X = 9, .Y = 1, .Level = 5, .Message = DUNGEON__CENTER_YOURSELF_TO_SOAR},
    {.X = 10, .Y = 0, .Level = 5, .Message = DUNGEON__CENTER_YOURSELF_TO_SOAR},
    {.X = 7, .Y = 8, .Level = 6, .Message = DUNGEON__DEADLY_CORNERS},
    {.X = 8, .Y = 7, .Level = 6, .Message = DUNGEON__DEADLY_CORNERS},
    {.X = 9, .Y = 8, .Level = 6, .Message = DUNGEON__DEADLY_CORNERS},
    {.X = 8, .Y = 9, .Level = 6, .Message = DUNGEON__DEADLY_CORNERS},
    {.X = 3, .Y = 1, .Level = 7, .Message = DUNGEON__WINDY_ESCAPE},
    {.X = 13, .Y = 1, .Level = 7, .Message = DUNGEON__WINDY_ESCAPE},
    {.X = 3, .Y = 15, .Level = 7, .Message = DUNGEON__WINDY_ESCAPE},
    {.X = 13, .Y = 15, .Level = 7, .Message = DUNGEON__WINDY_ESCAPE},
    {.X = 0, .Y = 0, .Level = 0xFF, .Message = 0}
};

MessagesType enchantment_messages[] = {
    {.X = 3, .Y = 2, .Level = 0, .Message = DUNGEON__FOLLOW_THE_BREADCRUMBS},
    {.X = 7, .Y = 8, .Level = 1, .Message = DUNGEON__FORTUNE_AND_FALLS},
    {.X = 7, .Y = 10, .Level = 1, .Message = DUNGEON__FORTUNE_AND_FALLS},
    {.X = 14, .Y = 11, .Level = 2, .Message = DUNGEON__LAYERS_OF_DECEPTION},
    {.X = 14, .Y = 13, .Level = 2, .Message = DUNGEON__LAYERS_OF_DECEPTION},
    {.X = 6, .Y = 9, .Level = 3, .Message = DUNGEON__ONE_TWO_THREE_FOUR_FIVE},
    {.X = 0, .Y = 1, .Level = 4, .Message = DUNGEON__DONT_RISE_TOO_SOON},
    {.X = 1, .Y = 0, .Level = 4, .Message = DUNGEON__DONT_RISE_TOO_SOON},
    {.X = 15, .Y = 14, .Level = 5, .Message = DUNGEON__FAST_WAY_OR_SLOW_WAY},
    {.X = 12, .Y = 14, .Level = 6, .Message = DUNGEON__A_WINDFALL_LIFTS_YOU_UP},
    {.X = 13, .Y = 13, .Level = 6, .Message = DUNGEON__A_WINDFALL_LIFTS_YOU_UP},
    {.X = 4, .Y = 1, .Level = 7, .Message = DUNGEON__AVOID_A_PATH_TO_NOWHERE},
    {.X = 6, .Y = 1, .Level = 7, .Message = DUNGEON__AVOID_A_PATH_TO_NOWHERE},
    {.X = 0, .Y = 0, .Level = 0xFF, .Message = 0}
};

MessagesType secrets_messages[];

MessagesType passage_messages[];


const MessagesType *dungeon_messages[] = {
    {phoenix_messages},
    {enchantment_messages},
    {secrets_messages},
    {passage_messages}
};

uint8_t *CurrentTiles = tile_mapping;
uint8_t *CurrentDTiles = (uint8_t *)DTilesVisible;
volatile long DOSTimer = 0xFFFF;
volatile uint8_t CurrentSound = 0, CurrentMusic = 0, NoteLength = 0;
volatile int SoundPos = -1, MusicPos = -1;

void __interrupt __far timer_rtn()
{
    _disable();
    ClockTicks++;
    DOSTimer -= 0x4DAE;
    if(MusicPos != -1) {
        if (NoteLength) {
            NoteLength--;
        } else {
            if (Music[CurrentMusic][MusicPos] == 0xFFFF) {
                MusicPos = -1;
                SoundPos = -1;
                outp( 0x61, ( inp( 0x61 ) & 0xFC ) );
            } else {
                if(Music[CurrentMusic][MusicPos]) {
                    outp( 0x43, 0xB6 );
                    outp( 0x42, Music[CurrentMusic][MusicPos]&0xFF );
                    outp( 0x42, ( Music[CurrentMusic][MusicPos]>>8 ) );
                    outp( 0x61, ( inp( 0x61 ) | 3 ) );
                } else {
                    outp( 0x61, ( inp( 0x61 ) & 0xFC ) );
                }
                MusicPos++;
                NoteLength = Music[CurrentMusic][MusicPos];
                MusicPos++;
            }
        }
    } else if(SoundPos != -1) {
        if(SoundPos == SoundLength[CurrentSound]) {
            SoundPos = -1;
            outp( 0x61, ( inp( 0x61 ) & 0xFC ) );
        } else {
            if(Sounds[CurrentSound][SoundPos]) {
                outp( 0x43, 0xB6 );
                outp( 0x42, Sounds[CurrentSound][SoundPos]&0xFF );
                outp( 0x42, ( Sounds[CurrentSound][SoundPos]>>8 ) );
                outp( 0x61, ( inp( 0x61 ) | 3 ) );
            } else {
                outp( 0x61, ( inp( 0x61 ) & 0xFC ) );
            }
            SoundPos++;
        }
    }
    if(DOSTimer < 0) {
        DOSTimer += 0xFFFF;
        _chain_intr( prev_int_1c );
    }
    _enable();
}


void oh_shit(char *error_message) {
    cleanup();
    puts(error_message);
    exit(1);
}

int check_joystick_input() {
    int RetChar = 0;
    static int JoyTimer = 0;
    static int JoyDelay = -1;

    if(JoyTimer == LogicalTicks) {
        return 0;
    }

    if(JoyDelay > 0) {
        JoyDelay--;
        return 0;
    }

    JoyTimer = LogicalTicks;
    read_joy();
    
    if(joy_x > JoyXRight) {
        RetChar = KEY_RIGHT;
    }
    
    if(joy_x < JoyXLeft) {
        RetChar = KEY_LEFT;
    }
    
    if(joy_y < JoyYUp) {
        RetChar = KEY_UP;
    }
    
    if(joy_y > JoyYDown) {
        RetChar = KEY_DOWN;
    }
    
    if(RetChar && (JoyDelay == -1)) {
        JoyDelay = 2;
    }
    
    if(!RetChar) {
        JoyDelay = -1;
    }
    return RetChar;
}

void init_joystick() {
    read_joy();
    if(joy_x != 1023) {
        Flags.JoystickPresent = 1;
        JoyXLeft = joy_x / 2;
        JoyXRight = joy_x + (joy_x / 2);
        JoyYUp = joy_y / 2;
        JoyYDown = joy_y + (joy_y / 2);
    }
}

int check_button_press() {
    if(SaveKey == KEY_SPACE) {
        return 1;
    }
    if(Flags.JoystickPresent) {
        read_joy_buttons();
        if(!b0 || !b1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void read_joy_buttons()
{
    static int ButtonPressed = 0;

   _asm {
        mov    dx,201h
        xor    ax, ax
        in     al,dx

        mov    bl, al
        and    bl, 010h
        mov    b0, bl

        and    al, 020h
        mov    b1, al
    }

    if(b0 && b1) {
        ButtonPressed = 0;
        return;
    }

    if(ButtonPressed) {
        b0 = 1;
        b1 = 1;
        return;
    }

    ButtonPressed = 1;
}

void read_joy()
{
   _asm {
        push   si

        xor    ax,ax
    /* joystick port */
        mov    dx,201h
        mov    cx,ax
        mov    bx,ax
        mov    si, 1024   /* this number may have to be LARGER on
                            FAST machines */

        cli    /* disable interupts so that our timing loop isn't
                    interupted */

    /* begin digitize, prime joy port */
        out    dx,al
jlp:           
        dec    si
        jz     abt          /* timeout */
    /* read port */
        in     al,dx
        test   al,1
        jz     nox
    /* increment x counter if bit 0 high */
        inc    bx
nox:           
        test   al,2
        jz     noy
    /* increment y counter if bit 1 high */
        inc    cx
noy:           
        test   al,3
    /* keep going until both x and y done */
        jnz    jlp
abt:           
        sti    /* enable interupts */

    /* store x and y coordinates, and button stats */

        mov    joy_y, cx
        mov    joy_x, bx

        mov    bl, al
        and    bl, 010h
        mov    b0, bl

        and    al, 020h
        mov    b1, al

        pop    si
    }
}

void parse_option(char Opt) {
    switch(Opt) {
        case 'm':
        case 'M':
            Flags.Monochrome = 1;
            break;
        case 'c':
        case 'C':
            Flags.Composite = 1;
        case 'j':
        case 'J':
            init_joystick();
            break;
    }
}

void load_display_gui() {
    FILE *GUIFile;
    Bitmap *ScreenBuffer = bit_create(320, 200);
    Bitmap *HSep, *VSep;
    int Count;

    bit_ink(ScreenBuffer, 0);
    bit_box(ScreenBuffer, 0, 0, 320, 200);
    bit_ink(ScreenBuffer, 3);

    if (! (GUIFile = fopen ("gui.dat", "rb"))) {
        oh_shit("Can't open \"gui.dat\" for reading.");
    }
    fseek(GUIFile, 8, SEEK_SET);
    if(!(HSep = bit_read(GUIFile))) {
        oh_shit("Can't load first bitmap in \"gui.dat\".");
    }
    VSep = bit_read(GUIFile);
    fclose(GUIFile);

    for(Count = 0; Count < 320; Count += 8) {
        bit_put(ScreenBuffer, HSep, Count, 0, DRAW_PSET);
        bit_put(ScreenBuffer, HSep, Count, 148, DRAW_PSET);
        bit_put(ScreenBuffer, HSep, Count, 196, DRAW_PSET);
    }

    for(Count=0; Count < 200; Count += 8) {
        bit_put(ScreenBuffer, VSep, 0, Count, DRAW_PSET);
        if(Count < 144) {
            bit_put(ScreenBuffer, VSep, 180, Count+4, DRAW_PSET);
        }
        bit_put(ScreenBuffer, VSep, 316, Count, DRAW_PSET);
    }

    scr_put(MyScreen, ScreenBuffer, 0, 0, DRAW_PSET);

    bit_destroy(HSep);
    bit_destroy(VSep);
    bit_destroy(ScreenBuffer);
}

void draw_stats() {
    uint8_t LevelH = 0, StatusH = 0, FoodH = 0;

    if (Hero.XP > 127) {
        LevelH = 1;
    }

    if (Hero.Status) {
        StatusH = 1;
    }

    if (!Hero.Food) {
        FoodH = 1;
    }


    print_line_formatted(SW_X, SW_Y, 0,    "%s (%c)", Hero.Name, Gender[Hero.Gender][0]);
    print_line_formatted(SW_X, SW_Y+10, 0,  "Strength:    %2d", Hero.Str);
    print_line_formatted(SW_X, SW_Y+20, 0, "Dexterity:   %2d", Hero.Dex);
    print_line_formatted(SW_X, SW_Y+30, 0, "Intelligence:%2d", Hero.Int);
    print_line_formatted(SW_X, SW_Y+40, 0, "Hit Pts:  %02d/%02d", Hero.HP, Hero.MHP);
    print_line_formatted(SW_X, SW_Y+50, 0, "Spell Pts:%02d/%02d", Hero.SP, Hero.MSP);
    print_line_formatted(SW_X, SW_Y+60, 0, "Armor:%9s", Armor[Hero.Armor]);
    print_line_formatted(SW_X, SW_Y+70, 0, "Melee:%9s", Melee[Hero.Melee]);
    print_line_formatted(SW_X, SW_Y+80, 0, "Ranged:%8s", Ranged[Hero.Ranged]);
    print_line_formatted(SW_X, SW_Y+90, LevelH, "Level:       %2d", Hero.Level);
    print_line_formatted(SW_X, SW_Y+100, 0, "Gold:      %4d", Hero.Gold);
    print_line_formatted(SW_X, SW_Y+110, FoodH, "Food:        %2d", Hero.Food);
    print_line_formatted(SW_X, SW_Y+120, StatusH, "Status:%8s", Status[Hero.Status]);
    if(Combat.Active) {
        print_line_formatted(SW_X, SW_Y+130, 0, "Dragon HP:%02d", Hero.DragonHP);
    } else {
        print_line_formatted(SW_X, SW_Y+130, 0, "Wind: %s  ", "Calm");
    }
//    print_line_formatted(SW_X, SW_Y+56, 0, "Wind:        %02d", Hero.Food);
}

void load_tiles() {
    FILE *TileFile;
    FILE *DTileFile;
    int Count;

    if (! (TileFile = fopen ("tiles.cga", "rb"))) {
        oh_shit("Can't open \"tiles.cga\" for reading.");
    }
    fseek(TileFile, 8, SEEK_SET);
    for(Count = 0; Count < NUM_TILES; Count++) {
        Tiles[Count] = bit_read(TileFile);
        if(!Tiles[Count]) {
            oh_shit("Can't load tile from \"tiles.cga\"");
        }
    }
    fclose(TileFile);

    if (! (DTileFile = fopen ("dtiles.cga", "rb"))) {
        oh_shit("Can't open \"dtiles.cga\" for reading.");
    }
    fseek(DTileFile, 8, SEEK_SET);
    for(Count = 0; Count < NUM_DTILES; Count++) {
        DTiles[Count] = bit_read(DTileFile);
        if(!DTiles[Count]) {
            oh_shit("Can't load tile from \"dtiles.cga\"");
        }
    }
    fclose(DTileFile);
}

void leave_town() {
    int TmpVal;

    TmpVal = Hero.CurrentMap;
    Hero.CurrentMap = Hero.PrevMap;
    Hero.PrevMap = TmpVal;
    if (Hero.PrevMap == THANAS_HOLD_MAP) {
        if (Hero.X < 10) {
            Hero.X = 56;
        } else {
            Hero.X = 60;
        }
    } else {
        Hero.X = Hero.PrevX;
    }
    Hero.Y = Hero.PrevY;
    load_map(Hero.CurrentMap);
    if(!Hero.CurrentMap) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__EXITING_TO_FARADUR]);
        Flags.MessageActive = 1;
    }
    if(!Flags.Composite) {
        scr_palette (MyScreen, DEFAULT_PALETTE, 0);
    }
    if (Flags.Disguised) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__THE_DISGUISE_WEARS_OFF]);
        Flags.Disguised = 0;
    }
    save_game();
}

void update_town_map_at(int8_t MapX, int8_t MapY) {
    int CountX, CountY;
    int ScreenX, ScreenY;
    int DataTile;
    uint8_t FillTile = CurrentMap[0];

    ScreenY = 0;
    for(CountY = MapY; CountY < (MapY + VIEWPORT_HEIGHT); CountY++) {
        ScreenX = 0;
        for(CountX = MapX; CountX < (MapX + VIEWPORT_WIDTH); CountX++) {
            if((CountX < 0) || (CountX >= TOWN_WIDTH) || (CountY < 0) || (CountY >= TOWN_HEIGHT)) {
                DataTile = FillTile;
            } else {
                DataTile = CurrentTiles[CurrentMap[(CountY * TOWN_WIDTH) + CountX]];
            }
            viewport_prev[CountX-MapX][CountY-MapY] = viewport[CountX-MapX][CountY-MapY];
            viewport[CountX-MapX][CountY-MapY] = DataTile;

            ScreenX += 16;
        }
        ScreenY += 16;
    }
}

void update_dungeon_map_at(int8_t MapX, int8_t MapY) {
    int CountX, CountY;
    int ScreenX, ScreenY;
    int DataTile;
    int LevelOffset = Dungeon.Level * 256;
    uint8_t FillTile = 0;

    ScreenY = 0;
    for(CountY = MapY; CountY < (MapY + DUNGEON_VIEWPORT_HEIGHT); CountY++) {
        ScreenX = 0;
        for(CountX = MapX; CountX < (MapX + DUNGEON_VIEWPORT_WIDTH); CountX++) {
            if((CountX < 0) || (CountX >= DUNGEON_WIDTH) || (CountY < 0) || (CountY >= DUNGEON_HEIGHT)) {
                DataTile = FillTile;
            } else {
                DataTile = CurrentMap[(CountY * DUNGEON_WIDTH) + CountX + LevelOffset];
            }
            viewport_prev[CountX-MapX][CountY-MapY] = viewport[CountX-MapX][CountY-MapY];
            viewport[CountX-MapX][CountY-MapY] = DataTile;

            ScreenX += 16;
        }
        ScreenY += 16;
    }   
}

void update_world_map_at(int8_t MapX, int8_t MapY) {
    int CountX, CountY;
    int ScreenX, ScreenY;
    int WrapX, WrapY, WrapYWW;
    int DataTile;

    if(MapX < 0) {
        MapX += WORLD_WIDTH;
    } else if (MapX >= WORLD_WIDTH) {
        MapX -= WORLD_WIDTH;
    }
    
    if(MapY < 0) {
        MapY += WORLD_HEIGHT;
    } else if (MapY >= WORLD_HEIGHT) {
        MapY -= WORLD_HEIGHT;
    }

    ScreenY = 0;
    for(CountY = MapY; CountY < (MapY + VIEWPORT_HEIGHT); CountY++) {
        ScreenX = 0;
        WrapY = CountY;
        if(WrapY < 0) {
            WrapY += WORLD_HEIGHT;
        } else if (WrapY >= WORLD_HEIGHT) {
            WrapY -= WORLD_HEIGHT;
        }
        WrapYWW = WrapY * WORLD_WIDTH;
        for(CountX = MapX; CountX < (MapX + VIEWPORT_WIDTH); CountX++) {
            WrapX = CountX;
            if(WrapX < 0) {
                WrapX += WORLD_WIDTH;
            } else if (WrapX >= WORLD_WIDTH) {
                WrapX -= WORLD_WIDTH;
            }
            DataTile = CurrentTiles[CurrentMap[WrapYWW + WrapX]];
            viewport_prev[CountX-MapX][CountY-MapY] = viewport[CountX-MapX][CountY-MapY];
            viewport[CountX-MapX][CountY-MapY] = DataTile;
            ScreenX += 16;
        }
        ScreenY += 16;
    }
}

void do_vision() {
    int CountX, CountY, Count, FinishDark;

    // Up line
    FinishDark = 0;
    CountX = 5;
    for(CountY = (VIEWPORT_HEIGHT / 2) - 1; CountY > 0; CountY--) {
        if(FinishDark) {
            viewport[CountX][CountY-1] = NOTHING_TILE;
        } else {
            if(TileProperties[viewport[CountX][CountY]].Opaque) {
                viewport[CountX][CountY-1] = NOTHING_TILE;
                FinishDark = 1;
            }
        }
    }

    // Upper Right line
    FinishDark = 0;
    CountX = 6;
    for(CountY = (VIEWPORT_HEIGHT / 2) - 1; CountY > 0; CountY--) {
        if(FinishDark) {
            viewport[CountX+1][CountY-1] = NOTHING_TILE;
        } else {
            if(TileProperties[viewport[CountX][CountY]].Opaque) {
                viewport[CountX+1][CountY-1] = NOTHING_TILE;
                FinishDark = 1;
            }
        }
        CountX++;
    }

    // Upper Left line
    FinishDark = 0;
    CountX = 4;
    for(CountY = (VIEWPORT_HEIGHT / 2) - 1; CountY > 0; CountY--) {
        if(FinishDark) {
            viewport[CountX-1][CountY-1] = NOTHING_TILE;
        } else {
            if(TileProperties[viewport[CountX][CountY]].Opaque) {
                viewport[CountX-1][CountY-1] = NOTHING_TILE;
                FinishDark = 1;
            }
        }
        CountX--;
    }

    // Lower Right line
    FinishDark = 0;
    CountX = 6;
    for(CountY = (VIEWPORT_HEIGHT / 2) + 1; CountY < (VIEWPORT_HEIGHT-1); CountY++) {
        if(FinishDark) {
            viewport[CountX+1][CountY+1] = NOTHING_TILE;
        } else {
            if(TileProperties[viewport[CountX][CountY]].Opaque) {
                viewport[CountX+1][CountY+1] = NOTHING_TILE;
                FinishDark = 1;
            }
        }
        CountX++;
    }

    // Lower Left line
    FinishDark = 0;
    CountX = 4;
    for(CountY = (VIEWPORT_HEIGHT / 2) + 1; CountY < (VIEWPORT_HEIGHT-1); CountY++) {
        if(FinishDark) {
            viewport[CountX-1][CountY+1] = NOTHING_TILE;
        } else {
            if(TileProperties[viewport[CountX][CountY]].Opaque) {
                viewport[CountX-1][CountY+1] = NOTHING_TILE;
                FinishDark = 1;
            }
        }
        CountX--;
    }

    // Down line
    FinishDark = 0;
    CountX = 5;
    for(CountY = (VIEWPORT_HEIGHT / 2) + 1; CountY < (VIEWPORT_HEIGHT-1); CountY++) {
        if(FinishDark) {
            viewport[CountX][CountY+1] = NOTHING_TILE;
        } else {
            if(TileProperties[viewport[CountX][CountY]].Opaque) {
                viewport[CountX][CountY+1] = NOTHING_TILE;
                FinishDark = 1;
            }
        }
    }

    // Left line
    FinishDark = 0;
    CountY = 4;
    for(CountX = (VIEWPORT_WIDTH / 2) - 1; CountX > 0; CountX--) {
        if(FinishDark) {
            viewport[CountX-1][CountY] = NOTHING_TILE;
        } else {
            if(TileProperties[viewport[CountX][CountY]].Opaque) {
                viewport[CountX-1][CountY] = NOTHING_TILE;
                FinishDark = 1;
            }
        }
    }

    // Right line
    FinishDark = 0;
    CountY = 4;
    for(CountX = (VIEWPORT_WIDTH / 2) + 1; CountX < (VIEWPORT_WIDTH-1); CountX++) {
        if(FinishDark) {
            viewport[CountX+1][CountY] = NOTHING_TILE;
        } else {
            if(TileProperties[viewport[CountX][CountY]].Opaque) {
                viewport[CountX+1][CountY] = NOTHING_TILE;
                FinishDark = 1;
            }
        }
    }

    // Octet 1
    for(Count = 0; Count < sizeof(o1_indexes); Count++) {
        if(!TileProperties[(*viewport)[o1_indexes[Count]+1]].Opaque) {
            continue;
        }
        if(TileProperties[(*viewport)[o1_indexes[Count]-VIEWPORT_HEIGHT+1]].Opaque) {
            (*viewport)[o1_indexes[Count]] = NOTHING_TILE;
        }
    }

    // Octet 2
    for(Count = 0; Count < sizeof(o2_indexes); Count++) {
        if(!TileProperties[(*viewport)[o2_indexes[Count]-VIEWPORT_HEIGHT]].Opaque) {
            continue;
        }
        if(TileProperties[(*viewport)[o2_indexes[Count]-VIEWPORT_HEIGHT+1]].Opaque) {
            (*viewport)[o2_indexes[Count]] = NOTHING_TILE;
        }
    }

    // Octet 3
    for(Count = 0; Count < sizeof(o3_indexes); Count++) {
        if(!TileProperties[(*viewport)[o3_indexes[Count]-VIEWPORT_HEIGHT]].Opaque) {
            continue;
        }
        if(TileProperties[(*viewport)[o3_indexes[Count]-VIEWPORT_HEIGHT-1]].Opaque) {
            (*viewport)[o3_indexes[Count]] = NOTHING_TILE;
        }
    }

    // Octet 4
    for(Count = 0; Count < sizeof(o4_indexes); Count++) {
        if(!TileProperties[(*viewport)[o4_indexes[Count]-1]].Opaque) {
            continue;
        }
        if(TileProperties[(*viewport)[o4_indexes[Count]-VIEWPORT_HEIGHT-1]].Opaque) {
            (*viewport)[o4_indexes[Count]] = NOTHING_TILE;
        }
    }

    // Octet 5
    for(Count = 0; Count < sizeof(o5_indexes); Count++) {
        if(!TileProperties[(*viewport)[o5_indexes[Count]-1]].Opaque) {
            continue;
        }
        if(TileProperties[(*viewport)[o5_indexes[Count]+VIEWPORT_HEIGHT-1]].Opaque) {
            (*viewport)[o5_indexes[Count]] = NOTHING_TILE;
        }
    }

    // Octet 6
    for(Count = 0; Count < sizeof(o6_indexes); Count++) {
        if(!TileProperties[(*viewport)[o6_indexes[Count]+VIEWPORT_HEIGHT]].Opaque) {
            continue;
        }
        if(TileProperties[(*viewport)[o6_indexes[Count]+VIEWPORT_HEIGHT-1]].Opaque) {
            (*viewport)[o6_indexes[Count]] = NOTHING_TILE;
        }
    }

    // Octet 7
    for(Count = 0; Count < sizeof(o7_indexes); Count++) {
        if(!TileProperties[(*viewport)[o7_indexes[Count]+VIEWPORT_HEIGHT]].Opaque) {
            continue;
        }
        if(TileProperties[(*viewport)[o7_indexes[Count]+VIEWPORT_HEIGHT+1]].Opaque) {
            (*viewport)[o7_indexes[Count]] = NOTHING_TILE;
        }
    }

    // Octet 8
    for(Count = 0; Count < sizeof(o8_indexes); Count++) {
        if(!TileProperties[(*viewport)[o8_indexes[Count]+1]].Opaque) {
            continue;
        }
        if(TileProperties[(*viewport)[o8_indexes[Count]+VIEWPORT_HEIGHT+1]].Opaque) {
            (*viewport)[o8_indexes[Count]] = NOTHING_TILE;
        }
    }
}

void do_dungeon_vision() {
    static char FlickerState = 16;
    int Count;

    if((rand() & 0xFF) < 48) {
        if(FlickerState == 16) {
            FlickerState = 17;
        } else {
            FlickerState = 16;
        }
    }

    if(!DTilesOpaque[viewport[1][1]] && DTilesOpaque[viewport[0][0]]) {
        viewport[0][0] = FlickerState;
    } else {
        viewport[0][0] = 18;
    }

    if(DTilesOpaque[viewport[2][1]]) {
        viewport[2][0] = 18;
    }
    if(!DTilesOpaque[viewport[3][1]] && DTilesOpaque[viewport[4][0]]) {
        viewport[4][0] = FlickerState;
    } else {
        viewport[4][0] = 18;
    }

    if(DTilesOpaque[viewport[3][2]]) {
        viewport[4][2] = 18;
    }
    if(!DTilesOpaque[viewport[3][3]] && DTilesOpaque[viewport[4][4]]) {
        viewport[4][4] = FlickerState;
    } else {
        viewport[4][4] = 18;
    }

    if(DTilesOpaque[viewport[2][3]]) {
        viewport[2][4] = 18;
    }
    if(!DTilesOpaque[viewport[1][3]] && DTilesOpaque[viewport[0][4]]) {
        viewport[0][4] = FlickerState;
    } else {
        viewport[0][4] = 18;
    }

    if(DTilesOpaque[viewport[1][2]]) {
        viewport[0][2] = 18;
    }

    for(Count = 0; Count < 8; Count++) {
        if(DTilesOpaque[viewport[DVisionTiles[Count].P1Coord.X][DVisionTiles[Count].P1Coord.Y]]
         && DTilesOpaque[viewport[DVisionTiles[Count].P2Coord.X][DVisionTiles[Count].P2Coord.Y]]) {
            viewport[DVisionTiles[Count].SrcCoord.X][DVisionTiles[Count].SrcCoord.Y] = 18;
        }
    }
}

void display_map() {
    int CountX, CountY;
    int ScreenX, ScreenY;
    uint8_t DoUpdate = 1;
    uint8_t HeroTile;

    if (Flags.Disguised) {
        HeroTile = Game.DisguiseTile;
    } else {
        HeroTile = HERO_TILE;
    }

    if (Game.FlashTimer && !Game.DoInvert) {
        DoUpdate = 0;
    }

    if (!Game.FlashTimer && Game.DoInvert) {
        DoUpdate = 0;
        invalidate_view();
    }

    ScreenX = 0;
    for(CountX = 0; CountX < VIEWPORT_WIDTH; CountX++) {
        ScreenY = 0;
        for(CountY = 0; CountY < VIEWPORT_HEIGHT; CountY++) {
            if(viewport_prev[CountX][CountY] != viewport[CountX][CountY] && DoUpdate) {
                bit_put(ViewportBuffer, Tiles[viewport[CountX][CountY]], ScreenX, ScreenY, DRAW_PSET);
            }
            ScreenY += 16;
        }
        ScreenX += 16;
    }
    if(!Combat.Active && DoUpdate && (viewport[5][4] != HERO_TILE)) {
        bit_put(ViewportBuffer, Tiles[CurrentTiles[HeroTile]], 80, 64, DRAW_PSET);
    }

    if (Game.DoInvert) {
        invert_viewport();
    }

    scr_put(MyScreen, ViewportBuffer, 4, 4, DRAW_PSET);
}

void display_dungeon_map() {
    int CountX, CountY;
    int ScreenX, ScreenY;

    ScreenX = 8;
    for(CountX = 0; CountX < DUNGEON_VIEWPORT_WIDTH; CountX++) {
        ScreenY = 0;
        for(CountY = 0; CountY < DUNGEON_VIEWPORT_HEIGHT; CountY++) {
            if((viewport_prev[CountX][CountY] != viewport[CountX][CountY])
             ||(Flags.Flipped && DTilesFlippable[viewport[CountX][CountY]])) {
                bit_put(ViewportBuffer, DTiles[CurrentDTiles[viewport[CountX][CountY]]], ScreenX, ScreenY, DRAW_PSET);
            }
            ScreenY += 28;
        }
        ScreenX += 32;
    }
    Flags.Flipped = 0;
    if(!Combat.Active && (CurrentDTiles[viewport[2][2]] != DHERO_TILE)) {
        bit_put(ViewportBuffer, DTiles[DHERO_TILE], 72, 56, DRAW_PSET);
    }
    scr_put(MyScreen, ViewportBuffer, 4, 4, DRAW_PSET);
}

int get_direction() {
    if((SaveKey == KEY_LEFT) || (SaveKey == KEY_RIGHT) ||
       (SaveKey == KEY_UP) || (SaveKey == KEY_DOWN)) {
        return SaveKey;
    }

    if(Flags.JoystickPresent) {
        return check_joystick_input();
    } else {
        return 0;
    }
}

void CheckMoveHero() {
    int Blocked = 0;
    int Direction = get_direction();

    if(!Direction) {
        return;
    }

    SaveKey = 0;

    if(Combat.Active) {
        if(((Combat.State != 1) && (Combat.State != 2)) || Combat.Timer) {
            return;
        }
        do_combat_move(Direction);
        return;
    }

    switch(Direction) {
        case KEY_LEFT:
            if(!TileProperties[viewport[4][4]].Solid) {
                Hero.X--;
            } else {
                Blocked = 1;
            }
            break;
        case KEY_RIGHT:
            if(!TileProperties[viewport[6][4]].Solid) {
                Hero.X++;
            } else {
                Blocked = 1;
            }
            break;
        case KEY_UP:
            if(!TileProperties[viewport[5][3]].Solid) {
                Hero.Y--;
            } else {
                Blocked = 1;
            }
            break;
        case KEY_DOWN:
            if(!TileProperties[viewport[5][5]].Solid) {
                Hero.Y++;
            } else {
                Blocked = 1;
            }
            break;
        default:
            return;
    }

    if(!Hero.CurrentMap) {
        Game.PrevTurns = Game.Turns;
        Game.Turns++;
    }

    if(Blocked) {
        play_sound(BLOCKED_SOUND);
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_CANT_GO_THAT_WAY]);
        Flags.MessageActive = 1;
        SaveKey = 0;
        return;
    }

    play_sound(WALK_SOUND);

    Flags.Moved = 1;

//    if(check_triggers()) {
//        return;
//    }

    if(!Hero.CurrentMap) {
        if(Hero.X < 0) {
            Hero.X += WORLD_WIDTH;
        } else if (Hero.X >= WORLD_WIDTH) {
            Hero.X -= WORLD_WIDTH;
        }

        if(Hero.Y < 0) {
            Hero.Y += WORLD_HEIGHT;
        } else if (Hero.Y >= WORLD_HEIGHT) {
            Hero.Y -= WORLD_HEIGHT;
        }
    } else {
        if((Hero.X < 0) || (Hero.X >= TOWN_WIDTH) || (Hero.Y < 0) || (Hero.Y >= TOWN_HEIGHT)) {
            leave_town();
            return;
        }
    }
    clear_text_window();
//    print_line_formatted(8, 152, "X:%02d , Y:%02d", 0, Hero.X, Hero.Y); 

}

void CheckMoveHeroDungeon() {
    int Blocked = 0;
    int Direction = get_direction();

    if(!Direction) {
        return;
    }

    SaveKey = 0;

    if(Flags.MessageActive) {
        Flags.MessageActive = 0;
        clear_text_window();
        return;
    }

    if(Combat.Active) {
        if(((Combat.State != 1) && (Combat.State != 2)) || Combat.Timer) {
            return;
        }
        do_combat_move(Direction);
        return;
    }

    switch(Direction) {
        case KEY_LEFT:
            if(!DTilesSolid[viewport[1][2]]) {
                Dungeon.X--;
            } else {
                Blocked = 1;
            }
            break;
        case KEY_RIGHT:
            if(!DTilesSolid[viewport[3][2]]) {
                Dungeon.X++;
            } else {
                Blocked = 1;
            }
            break;
        case KEY_UP:
            if(!DTilesSolid[viewport[2][1]]) {
                Dungeon.Y--;
            } else {
                Blocked = 1;
            }
            break;
        case KEY_DOWN:
            if(!DTilesSolid[viewport[2][3]]) {
                Dungeon.Y++;
            } else {
                Blocked = 1;
            }
            break;
        default:
            return;
    }

    Game.PrevTurns = Game.Turns;
    Game.Turns++;
    if (Dungeon.Light) {
        Dungeon.Light--;
        if (!Dungeon.Light) {
            do_dungeon_dark();
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__ITS_DARK]);
            Flags.MessageActive = 1;
        }
    }

    if(Blocked) {
        play_sound(BLOCKED_SOUND);
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_CANT_GO_THAT_WAY]);
        Flags.MessageActive = 1;
        SaveKey = 0;
        return;
    }

    clear_text_window();

    Flags.Moved = 1;

//    dungeon_triggers();
}


void do_pass() {
    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__PASS]);
    Game.PrevTurns = Game.Turns;
    Game.Turns++;
    if (Combat.Active) {
        Combat.Timer = 8;
        advance_combat_state();
    } else {
        Flags.Moved = 1;
    }
}

void do_dungeon_dark() {
    CurrentDTiles = (uint8_t *)DTilesDark;
    clear_dungeon_screen();
    invalidate_view();
}

void play_sound(int SoundNumber) {
    if((SoundPos != -1) && (SoundNumber <= CurrentSound)) {
        return;
    }
    SoundPos = 0;
    CurrentSound = SoundNumber;
}

void play_music(int MusicNumber) {
    if((MusicPos != -1) && (MusicNumber <= CurrentMusic)) {
        return;
    }
    MusicPos = 0;
    NoteLength = 0;
    CurrentMusic = MusicNumber;
}

void cleanup() {
    _dos_setvect( 0x1c, prev_int_1c );
    scr_destroy(MyScreen);
    MyKeyHandler->destroy();
    outp( 0x61, ( inp( 0x61 ) & 0xFC ) );
    set_timer(0);
    free(CurrentMap);
    free(CurrentFont);
}

void set_timer(unsigned int Divisor) {
    outp(0x43, 0x3C);
    outp(0x40, LOW_BYTE(Divisor));
    outp(0x40, HI_BYTE(Divisor));
}

uint8_t dungeon_triggers() {
    int Count = 0;
    uint8_t Ret = 1;
    int LevelOffset = Dungeon.Level * 256;
    char CurrentDTile = CurrentMap[(Dungeon.Y * DUNGEON_WIDTH) + Dungeon.X + LevelOffset];
    const MessagesType *DMessages = dungeon_messages[Dungeon.Number];
    uint8_t EnergyType = (Dungeon.X + Dungeon.Y) & 3;
    switch(CurrentDTile) {
        case DUNGEON_ORB:
            Dungeon.Orb = 1;
            switch(Dungeon.Number) {
                case PHOENIX_DUNGEON:
                    print_line(MW_X, MW_Y, 1, "Orb of the Phoenix found!");
                    break;
                case ENERGY_DUNGEON:
                    print_line(MW_X, MW_Y, 1, "Orb of Enchantment found!");
                    break;
                case SECRETS_DUNGEON:
                    print_line(MW_X, MW_Y, 1, "Orb of Secrets found!");
                    break;
                case PASSAGE_DUNGEON:
                    print_line(MW_X, MW_Y, 1, "Orb of Passage found!");
                    break;
            }
            print_line(MW_X, MW_Y+30, 0, "Find the dungeon exit.");
            Flags.MessageActive = 1;
            break;
        case DUNGEON_TRAP:
            do_dungeon_trap();
            break;
        case DUNGEON_ENERGY:
            switch(EnergyType) {
                case 0: // harmless energy
                    if(!(rand()&3)) {
                        print_line(MW_X, MW_Y+30, 0, "You see a vision!");
                    } else {
                        print_line(MW_X, MW_Y+30, 0, "You feel a small tingle.");
                    }
                    Flags.MessageActive = 1;
                    break;
                case 1: // replentish magic energy
                    print_line(MW_X, MW_Y+30, 0, "You feel energized!");
                    Hero.SP = Hero.MSP;
                    draw_stats();
                    break;
                case 2: // light energy
                    if(!Dungeon.Light) {
                        print_line(MW_X, MW_Y+30, 0, "The dungeon is lit!");
                        CurrentDTiles = (uint8_t *)DTilesVisible;
                        invalidate_view();
                    } else {
                        print_line(MW_X, MW_Y+30, 0, "The dungeon gets brighter!");
                    }
                    if(Dungeon.Light > 191) {
                        Dungeon.Light = 255;
                    } else {
                        Dungeon.Light += 64;
                    }
                    break;
                case 3: // drain energy
                    print_line(MW_X, MW_Y+30, 0, "You feel drained.");
                    Hero.SP = 0;
                    draw_stats();
                    break;
            }
            play_sound(ENERGY_SOUND);
            Flags.MessageActive = 1;
            break;
        case DUNGEON_FOUNTAIN:
            if(Dungeon.Light) {
                print_line(MW_X, MW_Y, 1, Messages[STATUS__DRINK_FROM_THE_FOUNTAIN]);
            } else {
                print_line(MW_X, MW_Y, 1, Messages[STATUS__YOU_HEAR_WATER_DRINK]);
            }
            print_line(MW_X, MW_Y+30, 0, ">No Yes");
            Menu.Active = 1;
            Menu.Choices = 2;
            Menu.MarkerPos[0] = 0;
            Menu.MarkerPos[1] = 3;
            Menu.Actions[0] = dungeon_cancel;
            Menu.Actions[1] = dungeon_drink;
            Menu.Selection = 0;
            break;
        case DUNGEON_STAIRS_UP:
            print_line(MW_X, MW_Y, 1, "Ascend to the next level?");
            print_line(MW_X, MW_Y+30, 0, ">No Ascend");
            Menu.Active = 1;
            Menu.Choices = 2;
            Menu.MarkerPos[0] = 0;
            Menu.MarkerPos[1] = 3;
            Menu.Actions[0] = dungeon_cancel;
            Menu.Actions[1] = dungeon_ascend;
            Menu.Selection = 0;
            break;
        case DUNGEON_STAIRS_DOWN:
            if(Dungeon.Level) {
                print_line(MW_X, MW_Y, 1, "Descend to prior level?");
            } else {
                print_line(MW_X, MW_Y, 1, "Descend to exit dungeon?");
            }
            print_line(MW_X, MW_Y+30, 0, ">No Descend");
            Menu.Active = 1;
            Menu.Choices = 2;
            Menu.MarkerPos[0] = 0;
            Menu.MarkerPos[1] = 3;
            Menu.Actions[0] = dungeon_cancel;
            Menu.Actions[1] = dungeon_descend;
            Menu.Selection = 0;
            break;
        case DUNGEON_LADDER:
            print_line(MW_X, MW_Y, 1, "Ascend or descend?");
            print_line(MW_X, MW_Y+30, 0, ">No Ascend Descend");
            Menu.Active = 1;
            Menu.Choices = 3;
            Menu.MarkerPos[0] = 0;
            Menu.MarkerPos[1] = 3;
            Menu.MarkerPos[2] = 10;
            Menu.Actions[0] = dungeon_cancel;
            Menu.Actions[1] = dungeon_ascend;
            Menu.Actions[2] = dungeon_descend;
            Menu.Selection = 0;
            break;
        case DUNGEON_PIT:
            print_line(MW_X, MW_Y+30, 0, "You fall through a pit!");
            if(Hero.HP) {
                Hero.HP--;
            }
            play_sound(HIT_SOUND);
            Flags.MessageActive = 1;
            Dungeon.Level--;
            draw_stats();
            break;
        case DUNGEON_DOOR:
        case DUNGEON_FAKE_WALL:
            play_sound(DOOR_SOUND);
            Ret = 0;
            break;
        case DUNGEON_WIND:
            print_line(MW_X, MW_Y+30, 0, "Mystic winds!");
            Dungeon.Light = 0;
            do_dungeon_dark();
            play_sound(WIND_SOUND);
            Flags.MessageActive = 1;
            break;
        case DUNGEON_TELEPORTER:
            if(Dungeon.X % 2) {
                Dungeon.X = (Dungeon.X^0x0F) + 1;
            }
            if(Dungeon.Y % 2) {
                Dungeon.Y = (Dungeon.Y^0x0F) + 1;
            }
            print_line(MW_X, MW_Y+30, 0, "Teleported!");
            Flags.MessageActive = 1;
            play_sound(CAST_SOUND);
            break;
        case DUNGEON_MESSAGE:
            while(1) {
                if(DMessages[Count].Level > Dungeon.Level) {
                    oh_shit("Dungeon message not found!");
                }
                if((Dungeon.Level == DMessages[Count].Level) &&
                 (Dungeon.X == DMessages[Count].X) &&
                 (Dungeon.X == DMessages[Count].X)) {
                    print_line(MW_X, MW_Y, 1, "A mysterious voice says:");
                    print_line(MW_X, MW_Y+30, 0, DungeonMessages[DMessages[Count].Message]);
                    Flags.MessageActive = 1;
                    break;
                }
                Count++;
            }
            play_sound(WALK_SOUND);
            break;
        default:
            play_sound(WALK_SOUND);
            Ret = 0;
            if (!Dungeon.Light) {
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__ITS_DARK]);
            }
    }
    return Ret;
}

void do_dungeon_trap() {
    uint8_t Count;
    
    if(((Hero.Dex / 5) < ((rand() & 15) + 1)) || !Dungeon.Light) {
        if(!(rand() & 7) && (Hero.Status != STATUS_POISONED)) {
            if(Dungeon.Light) {
                print_line(MW_X, MW_Y+30, 0, "A trap! You are hit! Poisoned!");
            } else {
                print_line(MW_X, MW_Y+30, 0, "An unseen trap hits you! Poisoned!");
            }
            Hero.Status = STATUS_POISONED;
        } else {
            if(Dungeon.Light) {
                print_line(MW_X, MW_Y+30, 0, "A trap! You are hit!");
            } else {
                print_line(MW_X, MW_Y+30, 0, "An unseen trap hits you!");
            }
            Count = (rand() & 3) + 1 + Dungeon.Level;
            if(Count >= Hero.HP) {
                Hero.HP = 0;
                print_line(MW_X+200, MW_Y+30, 0, "You die!");
                do_death();
                return;
            }
            Hero.HP -= Count;
            draw_stats();
        }
        play_sound(HIT_SOUND);
        draw_stats();
    } else {
        print_line(MW_X, MW_Y+30, 0, "A trap! But you evade it.");
        play_sound(MISS_SOUND);
    }

    Flags.MessageActive = 1;
}

void do_death() {
    Hero.PrevMap = WORLD_MAP;
    Hero.CurrentMap = CASTLE_MAP;
    Hero.PrevX = 41;
    Hero.PrevY = 13;
    Hero.X = 23;
    Hero.Y = 9;   
    Hero.Gold = 0;
    Hero.HP = Hero.MHP;
    Hero.SP = Hero.MSP;
    Hero.Status = STATUS_GOOD;
    load_map(Hero.CurrentMap);
    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_BEEN_RESTORED]);
    Flags.MessageActive = 1;
    draw_stats();
    if (Flags.InDungeon) {
        exit_dungeon();
    } else {
        save_game();
    }
}

void dungeon_cancel() {
    Menu.Active = 0;
    clear_text_window();
    Flags.MessageActive = 0;
}


void dungeon_ascend() {
    if(Dungeon.Level < 7) {
        Dungeon.Level++;
        draw_stats();
    } else {
        if(Dungeon.Orb) {
            Hero.CurrentMap = CASTLEB_MAP;
            switch(Dungeon.Number) {
                case PHOENIX_DUNGEON:
                    Hero.X = 44;
                    Hero.Y = 29;
                    break;
                case ENERGY_DUNGEON:
                    Hero.X = 44;
                    Hero.Y = 18;
                    break;
                case SECRETS_DUNGEON:
                    Hero.X = 32;
                    Hero.Y = 53;
                    Hero.CurrentMap = WORLD_MAP;
                    break;
                case PASSAGE_DUNGEON:
                    Hero.X = 34;
                    Hero.Y = 33;
                    break;
            }
            exit_dungeon();
        } else {
            print_line(MW_X, MW_Y+30, 0, "An unexpected force is stopping you!");
            Flags.MessageActive = 1;
            return;
        }
    }
    dungeon_cancel();
}

void dungeon_descend() {
    if(Dungeon.Level) {
        Dungeon.Level--;
        draw_stats();
    } else {
        exit_dungeon();
    }
    dungeon_cancel();
}

void dungeon_drink() {
    uint8_t FountainType = (Dungeon.X + Dungeon.Y) & 3;

    switch (FountainType) {
        case 0: // Normal water
            print_line(MW_X, MW_Y+30, 0, "The water is refreshing.");
            break;
        case 1: // Healing water
            print_line(MW_X, MW_Y+30, 0, "You feel fully healed!");
            Hero.HP = Hero.MHP;
            draw_stats();
            play_sound(HEAL_SOUND);
            break;
        case 2: // Curing water
            print_line(MW_X, MW_Y+30, 0, "You feel purified!");
            Hero.Status = STATUS_GOOD;
            draw_stats();
            play_sound(HEAL_SOUND);
            break;
        case 3: // Poisoned water
            print_line(MW_X, MW_Y+30, 0, "The water is poisoned!");
            Hero.Status = STATUS_POISONED;
            draw_stats();
            play_sound(HIT_SOUND);
            break;
    }
    Menu.Active = 0;
    Flags.MessageActive = 1;
}

void clear_dungeon_screen() {
    int CountX, CountY;
    int ScreenX, ScreenY;

    ScreenX = 8;
    for(CountX = 0; CountX < DUNGEON_VIEWPORT_WIDTH; CountX++) {
        ScreenY = 0;
        for(CountY = 0; CountY < DUNGEON_VIEWPORT_HEIGHT; CountY++) {
            bit_put(ViewportBuffer, DTiles[0], ScreenX, ScreenY, DRAW_PSET);
            viewport[CountX][CountY] = NOTHING_TILE;
            ScreenY += 28;
        }
        ScreenX += 32;
    }

    invalidate_view();
//    scr_put(MyScreen, ViewportBuffer, 4, 4, DRAW_PSET);
}

void exit_dungeon() {
    clear_dungeon_screen();
    Flags.InDungeon = 0;
    load_map(Hero.CurrentMap);
    if(!Flags.Composite) {
        scr_palette (MyScreen, DEFAULT_PALETTE, 0);
    }
    save_game();
}

int check_triggers() {
    int CountX = 0;
    int CountY = 0;
    const TList *CurrentTriggers = Triggers[Hero.CurrentMap];
    const Trigger *YList;
    int XEnd = CurrentTriggers[CountX].YLen;
    int YEnd;

    while(XEnd) {
        if(Hero.X == CurrentTriggers[CountX].X) {
            YList = CurrentTriggers[CountX].YList;
            YEnd = CurrentTriggers[CountX].YLen;
            CountY = 0;
            while(CountY < YEnd) {
                if(YList[CountY].Y == Hero.Y) {
                    YList[CountY].TriggerFunction();
                    SaveKey = 0;
                    return 1;
                }
                CountY++;
            }
            return 0;
        }
        CountX++;
        XEnd = CurrentTriggers[CountX].YLen;
    }

    return 0;
}

void load_acadia() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = ACADIA_MAP;
    Hero.PrevX = Hero.X;
    Hero.PrevY = Hero.Y;
    Hero.X = 1;
    Hero.Y = 14;
    load_map(Hero.CurrentMap);   
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ENTERING_ACADIA]);
    Flags.MessageActive = 1;
}

void load_castle() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = CASTLE_MAP;
    Hero.PrevX = Hero.X;
    Hero.PrevY = Hero.Y;
    Hero.X = 24;
    Hero.Y = 32;   
    load_map(Hero.CurrentMap);
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ENTERING_CASTLE_AVALINA]);
    Flags.MessageActive = 1;
}

void load_oak() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = OAK_MAP;
    Hero.PrevX = Hero.X;
    Hero.PrevY = Hero.Y;
    Hero.X = 1;
    Hero.Y = 16;   
    load_map(Hero.CurrentMap);   
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ENTERING_OAK]);
    Flags.MessageActive = 1;
}

void load_duskgrove() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = DUSKGROVE_MAP;
    Hero.PrevX = Hero.X;
    Hero.PrevY = Hero.Y;
    Hero.X = 24;
    Hero.Y = 1;   
    load_map(Hero.CurrentMap);   
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__THE_RUINS_OF_DUSKGROVE]);
    Flags.MessageActive = 1;
}

void load_stoneheart() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = STONEHEART_MAP;
    Hero.PrevX = Hero.X;
    Hero.PrevY = Hero.Y;
    Hero.X = 27;
    Hero.Y = 32;
    load_map(Hero.CurrentMap);   
    if(!Flags.Composite) {
        scr_palette (MyScreen, DUNGEON_PALETTE, 0);
    } 
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ENTERING_STONEHEART]);
    Flags.MessageActive = 1;
}

void load_waters() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = WATERS_MAP;
    Hero.PrevX = Hero.X;
    Hero.PrevY = Hero.Y;
    Hero.X = 46;
    Hero.Y = 9;   
    load_map(Hero.CurrentMap);   
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ENTERING_WATERS]);
    Flags.MessageActive = 1;
}

void load_spiretop() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = SPIRETOP_MAP;
    Hero.PrevX = Hero.X;
    Hero.PrevY = Hero.Y;
    Hero.X = 46;
    Hero.Y = 17;   
    load_map(Hero.CurrentMap);   
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ENTERING_SPIRETOP]);
    Flags.MessageActive = 1;
}

void load_thanas_hold_east() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = THANAS_HOLD_MAP;
    Hero.PrevX = 60;
    Hero.PrevY = Hero.Y;
    Hero.X = 41;
    Hero.Y = 15;   
    load_map(Hero.CurrentMap);   
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ENTERING_THANAS_HOLD]);
    Flags.MessageActive = 1;
}
void load_thanas_hold_west() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.CurrentMap = THANAS_HOLD_MAP;
    Hero.PrevX = 56;
    Hero.PrevY = Hero.Y;
//    Hero.PrevX = 49;
//    Hero.PrevY = 28;
    Hero.X = 5;
    Hero.Y = 15;   
    load_map(Hero.CurrentMap);   
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ENTERING_THANAS_HOLD]);
    Flags.MessageActive = 1;
}


void load_guru() {
    Hero.PrevMap = Hero.CurrentMap;
    Hero.PrevX = Hero.X;
    Hero.PrevY = Hero.Y;
    Hero.X = 1;
    Hero.Y = 23;   
    load_castleb();
}

void load_refugee_camp() {
    load_castleb();
}

void load_duskgrove_up() {
    Hero.CurrentMap = DUSKGROVE_MAP;
    load_map(Hero.CurrentMap);   
    scr_palette (MyScreen, DEFAULT_PALETTE, 0);   
}

void load_phoenix() {
    Dungeon.X = 1;
    Dungeon.Y = 1;
    load_dungeon(PHOENIX_DUNGEON);
}

void load_energy() {
    Dungeon.X = 4;
    Dungeon.Y = 2;
    load_dungeon(ENERGY_DUNGEON);
}

void load_secrets() {
    Dungeon.X = 1;
    Dungeon.Y = 1;
    load_dungeon(SECRETS_DUNGEON);
}

void load_passage() {
    Dungeon.X = 1;
    Dungeon.Y = 1;
    load_dungeon(PASSAGE_DUNGEON);
}

void load_dungeon(int DungeonMap) {
    int CountX, CountY;

    clear_view();
    invalidate_view();
    display_map();
    Flags.InDungeon = 1;
    Flags.WeaponCorroded = 0;
    Dungeon.Level = 0;
    Dungeon.Light = 0;
    Dungeon.Orb = 0;
    Dungeon.Number = DungeonMap;
    load_map(DungeonMap);

    if(!Flags.Composite) {
        scr_palette (MyScreen, DUNGEON_PALETTE, 0);
    }

    do_dungeon_dark();
    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__ITS_DARK]);
    Flags.MessageActive = 1;
}

void load_castleb() {
    Hero.CurrentMap = CASTLEB_MAP;
    load_map(Hero.CurrentMap);   
    scr_palette (MyScreen, DUNGEON_PALETTE, 0);   
}

void load_castle_up() {
    Hero.CurrentMap = CASTLE_MAP;
    load_map(Hero.CurrentMap);   
    scr_palette (MyScreen, DEFAULT_PALETTE, 0);   
}

void load_map(uint8_t MapNum) {
    FILE *CurrentMapFile;

    free(CurrentMap);

    if(Flags.InDungeon) {
        if(!(CurrentMapFile = fopen(dmap_names[MapNum], "rb"))) {
            oh_shit((char *)dmap_names[MapNum]);
        }

        CurrentMap = malloc(DUNGEON_WIDTH * DUNGEON_HEIGHT * DUNGEON_LEVELS);
        Game.MapWidth = DUNGEON_WIDTH;
        Game.MapHeight = DUNGEON_HEIGHT;

        if(fread(CurrentMap, 1, (DUNGEON_WIDTH * DUNGEON_HEIGHT * DUNGEON_LEVELS), CurrentMapFile) != (DUNGEON_WIDTH * DUNGEON_HEIGHT * DUNGEON_LEVELS)) {
            oh_shit("Dungeon map file is corrupt.");
        }

        fclose(CurrentMapFile);
        return;
    }

    if(!(CurrentMapFile = fopen(map_names[MapNum], "rb"))) {
        oh_shit((char *)map_names[MapNum]);
    }

    if(MapNum) {
        CurrentMap = malloc(TOWN_WIDTH * TOWN_HEIGHT);
        Game.MapWidth = TOWN_WIDTH;
        Game.MapHeight = TOWN_HEIGHT;
    } else {
        CurrentMap = malloc(WORLD_WIDTH * WORLD_HEIGHT);
        Game.MapWidth = WORLD_WIDTH;
        Game.MapHeight = WORLD_HEIGHT;
    }

    if(MapNum) {
        if(fread(CurrentMap, 1, (TOWN_WIDTH * TOWN_HEIGHT), CurrentMapFile) != (TOWN_WIDTH * TOWN_HEIGHT)) {
            oh_shit("Map file is corrupt.");
        }
    } else {
        if(fread(CurrentMap, 1, (WORLD_WIDTH * WORLD_HEIGHT), CurrentMapFile) != (WORLD_WIDTH * WORLD_HEIGHT)) {
            oh_shit("Map file is corrupt.");
        }
    }
    fclose(CurrentMapFile);

    Game.PrevTurns = Game.Turns;
    Game.Turns++;
}

void print_line_formatted(int x, int y, uint8_t Invert, const char *format, ...) {
    char OutLine[80];
    va_list args;
    va_start(args, format);
    vsprintf(OutLine, format, args);
    va_end(args);

    print_line(x, y, Invert, OutLine);
}


void print_line(int x, int y, uint8_t Invert, const char *message) {
    int b; /* character pointer */
    int r; /* row of character */
    uint16_t *v; /* value of byte in character */
    char far *d; /* pointer to destination byte on screen */
    int InvertByte;

    /* print each character */
    for (b = 0; message[b]; ++b)
        for (r = 0; r < 8; ++r) {
            d = (b*2) + ((r % 2)
                ? x / 4 + (y + r - 1) * 40 + (char far *) 0xb8002000
                : x / 4 + (y + r) * 40 + (char far *) 0xb8000000);
            v = &CurrentFont[r + (8 * (message[b] - 32))];
            if(Invert) {
                InvertByte = ~(*v);
                _fmemcpy (d, &InvertByte, 2);
            } else {
                _fmemcpy (d, v, 2);
            }
        }
}

void clear_text_window() {
    int CountY;

    for(CountY = MW_Y; CountY < MW_Y + 40; CountY += 8) {
        scr_put(MyScreen, ClearText, MW_X, CountY, DRAW_PSET);
    }
    Flags.MessageActive = 0;
    SaveKey = 0;
}


void generate_character() {
    Bitmap *TitleIconFrame = bit_create(56, 52);
    Bitmap *TitleIcon, *HeaderIcon;
    Bitmap *BS, *End;
    FILE *TitleFile;
    uint8_t CurrentField = 0;
    uint8_t LetterPos = 0;
    uint8_t Done = 0;
    uint8_t Uppercase = 1;
    uint8_t PointsRemaining = 20;
    int Direction;
    char CurrentLetter = 'A';
    char Name[9];

    bit_ink(TitleIconFrame, 1);
    bit_box(TitleIconFrame, 0, 0, 56, 52);
    bit_ink(TitleIconFrame, 3);

    if (! (TitleFile = fopen ("title.dat", "rb"))) {
        oh_shit("Can't open \"title.dat\" for reading.");
    }
    fseek(TitleFile, 8, SEEK_SET);
    if(!(TitleIcon = bit_read(TitleFile))) {
        oh_shit("Can't load first bitmap in \"title.dat\".");
    }

    HeaderIcon = bit_read(TitleFile);
    BS = bit_read(TitleFile);
    End = bit_read(TitleFile);

    fclose(TitleFile);

    bit_put(TitleIconFrame, TitleIcon, 4, 2, DRAW_PSET);
    scr_put(MyScreen, HeaderIcon, 256, 8, DRAW_PSET);
    scr_put(MyScreen, TitleIconFrame, 252, 40, DRAW_PSET);
    print_line(12, 8, 1, "What is your hero's name?");
    print_line(12, 38, 0, "Gender:");
    print_line(12, 48, 0, "Female");
    print_line(12, 68, 0, "Strength:     05");
    print_line(12, 78, 0, "Dexterity:    05");
    print_line(12, 88, 0, "Intelligence: 05");
    print_line(12, 108, 0, "Points Remaining: 20");

    bit_destroy(TitleIconFrame);
    bit_destroy(TitleIcon);

    Hero.Str = 5;
    Hero.Dex = 5;
    Hero.Int = 5;

    while(!Done) {
        print_line_formatted(12 + (LetterPos * 8), 18, 1, "%c", CurrentLetter);
        while(CurrentField == 0) {  // Name
            Direction = get_direction();
            if(Direction) {
                SaveKey = 0;
                switch(Direction) {
                    case KEY_UP:
                    case KEY_DOWN:
                        if((CurrentLetter >= 'A') && (CurrentLetter <= 'Z')) {
                            CurrentLetter += 32;
                        } else if((CurrentLetter >= 'a') && (CurrentLetter <= 'z')) {
                            CurrentLetter -= 32;
                        }
                        Uppercase ^= 1;
                        break;
                    case KEY_LEFT:
                        CurrentLetter--;
                        if((CurrentLetter == ('A' - 1)) || (CurrentLetter == ('a' - 1))) {
                            CurrentLetter = 3;
                        } else if(CurrentLetter == 1) {
                            if(Uppercase) {
                                CurrentLetter = 'Z';
                            } else {
                                CurrentLetter = 'z';
                            }
                        }
                        break;
                    case KEY_RIGHT:
                        CurrentLetter++;
                        if((CurrentLetter == ('z' + 1)) || (CurrentLetter == ('Z' + 1))) {
                            CurrentLetter = 2;
                        } else if (CurrentLetter == 4) {
                            if(Uppercase) {
                                CurrentLetter = 'A';
                            } else {
                                CurrentLetter = 'a';
                            }
                        }
                        break;
                }
                if(CurrentLetter > 3) {
                    print_line_formatted(12 + (LetterPos * 8), 18, 1, "%c", CurrentLetter);
                } else if(CurrentLetter == 3) {
                    scr_put(MyScreen, BS, 12 + (LetterPos * 8), 18, DRAW_PSET);
                } else {
                    scr_put(MyScreen, End, 12 + (LetterPos * 8), 18, DRAW_PSET);
                }
            } else {
                if(check_button_press()) {
                    SaveKey = 0;
                    if(CurrentLetter == 3)  {   // backspace
                        if(LetterPos) {
                            print_line(12 + (LetterPos * 8), 18, 0, " ");
                            Name[LetterPos] = 0;
                            LetterPos--;
                            scr_put(MyScreen, BS, 12 + (LetterPos * 8), 18, DRAW_PSET);
                        }
                    } else if(CurrentLetter == 2) { // End
                        Name[LetterPos] = 0;
                        if(validate_name(Name)) {
                            print_line(12 + (LetterPos * 8), 18, 0, " ");
                            Name[LetterPos] = 0;
                        } else {
                            strcpy(Name, "Terryn");
                            print_line(12, 18, 0, "Terryn   ");
                            CurrentLetter = 'n';
                            LetterPos = 5;
                        }
                        CurrentField++;
                        break;
                    } else {    // A-Z or a-z
                        if(LetterPos == 7) {    // End of name
                            Name[7] = CurrentLetter;
                            Name[8] = 0;
                            if(validate_name(Name)) {
                                print_line(12 + (LetterPos * 8), 18, 0, " ");
                                print_line(12, 18, 0, Name);
                            } else {
                                strcpy(Name, "Terryn");
                                print_line(12, 18, 0, "Terryn   ");
                                CurrentLetter = 'n';
                                LetterPos = 5;
                            }
                            CurrentField++;
                            break;
                        }
                        Name[LetterPos] = CurrentLetter;
                        print_line_formatted(12 + (LetterPos * 8), 18, 0, "%c", CurrentLetter);
                        LetterPos++;
                        print_line_formatted(12 + (LetterPos * 8), 18, 1, "%c", CurrentLetter);
                    }
                }
            }
        }

        print_line(12, 8, 0, "What is your hero's name?");
        print_line(12, 38, 1, "Gender:");
        print_line_formatted(12, 48, 1, "%-6s", Gender[Hero.Gender]);

        while(CurrentField == 1) {
            if(check_button_press()) {
                CurrentField++;
                SaveKey = 0;
            }
            Direction = get_direction();
            if((Direction == KEY_RIGHT) || (Direction == KEY_LEFT)) {
                if(Direction == KEY_RIGHT) {
                    Hero.Gender++;
                    if(Hero.Gender > 2) {
                        Hero.Gender = 0;
                    }
                }
                if(Direction == KEY_LEFT) {
                    Hero.Gender--;
                    if(Hero.Gender > 2) {
                        Hero.Gender = 2;
                    }
                }
                print_line_formatted(12, 48, 1, "%-6s", Gender[Hero.Gender]);
                SaveKey = 0;
            }     
        }

        print_line(12, 38, 0, "Gender:");
        print_line_formatted(12, 48, 0, "%-6s", Gender[Hero.Gender]);
        print_line_formatted(12, 68, 1, "Strength:     %02d", Hero.Str);

        while(CurrentField < 5) {
            Direction = get_direction();
            if((Direction == KEY_RIGHT) || (Direction == KEY_LEFT)) {
                SaveKey = 0;
                switch(CurrentField) {
                    case 2:
                        if(Direction == KEY_RIGHT) {
                            if((Hero.Str < 20) && (PointsRemaining >= 5)) {
                                Hero.Str += 5;
                                PointsRemaining -= 5;
                            }
                        } else {
                            if(Hero.Str >= 10) {
                                Hero.Str -= 5;
                                PointsRemaining += 5;
                            }
                        }
                        print_line_formatted(12, 68, 1, "Strength:     %02d", Hero.Str);
                        break;
                    case 3:
                        if(Direction == KEY_RIGHT) {
                            if((Hero.Dex < 20) && (PointsRemaining >= 5)) {
                                Hero.Dex += 5;
                                PointsRemaining -= 5;
                            }
                        } else {
                            if(Hero.Dex >= 10) {
                                Hero.Dex -= 5;
                                PointsRemaining += 5;
                            }
                        }
                        print_line_formatted(12, 78, 1, "Dexterity:    %02d", Hero.Dex);
                        break;
                    case 4:
                        if(Direction == KEY_RIGHT) {
                            if((Hero.Int < 20) && (PointsRemaining >= 5)) {
                                Hero.Int += 5;
                                PointsRemaining -= 5;
                            }
                        } else {
                            if(Hero.Int >= 10) {
                                Hero.Int -= 5;
                                PointsRemaining += 5;
                            }
                        }
                        print_line_formatted(12, 88, 1, "Intelligence: %02d", Hero.Int);
                        break;
                }
                print_line_formatted(12, 108, 0, "Points Remaining: %02d", PointsRemaining);
            }
            if(check_button_press()) {
                CurrentField++;
                SaveKey = 0;
                if(CurrentField == 5) {
                    print_line_formatted(12, 88, 0, "Intelligence: %02d", Hero.Int);
                    if(PointsRemaining) {
                        CurrentField = 2;
                        print_line_formatted(12, 68, 1, "Strength:     %02d", Hero.Str);
                    }
                } else if(CurrentField == 3) {
                        print_line_formatted(12, 68, 0, "Strength:     %02d", Hero.Str);
                        print_line_formatted(12, 78, 1, "Dexterity:    %02d", Hero.Dex);
                } else {
                        print_line_formatted(12, 78, 0, "Dexterity:    %02d", Hero.Dex);
                        print_line_formatted(12, 88, 1, "Intelligence: %02d", Hero.Int);
                }
            }
        }

        print_line(12, 128, 1, "Next");
        print_line(52, 128, 0, "Back");

        while((CurrentField < 7) && (CurrentField > 0)) {
            Direction = get_direction();
            if((Direction == KEY_LEFT) || (Direction == KEY_RIGHT)) {
                SaveKey = 0;
                if(CurrentField == 5) {
                    CurrentField = 6;
                    print_line(12, 128, 0, "Next");
                    print_line(52, 128, 1, "Back");
                } else {
                    CurrentField = 5;
                    print_line(12, 128, 1, "Next");
                    print_line(52, 128, 0, "Back");
                }
            }
            if(check_button_press()) {
                SaveKey = 0;
                if(CurrentField == 5) {
                    Done = 1;
                    CurrentField = 7;
                } else {
                    CurrentField = 0;
                    print_line(52, 128, 0, "Back");
                }
            }
        }
    }
    Hero.Name = malloc(strlen(Name) + 1);
    strcpy(Hero.Name, Name);

    Hero.MSP = Hero.Int + 1;
    Hero.SP = Hero.MSP;
    Hero.MHP = Hero.Str + 1;
    Hero.HP = Hero.MHP;
    Hero.X = 46;
    Hero.Y = 14;
    Hero.CurrentMap = 0;
    Hero.PrevMap = 0;
    Hero.Food = 25;
    Hero.Gold = 100;
    Hero.Level = 1;
    Hero.XP = 0;
    Hero.SpellsKnown = RAY_SPELL;
    load_map(Hero.CurrentMap);
}

int validate_name(char *Name) {
    char FirstChar, Count;

    if(strlen(Name) < 2) {
        return 0;
    }

    FirstChar = Name[0];
    for(Count = 1; Count < strlen(Name); Count++) {
        if(Name[Count] != FirstChar) {
            return 1;
        }
    }
    return 0;
}

void save_game() {
    FILE *SaveFile;

    if((SaveFile = fopen("penult.sav","wb")) == NULL) {
        oh_shit("Can't open \"penult.sav\" for writing!");        
    }

    if(!fwrite(&Hero, sizeof(Hero), 1, SaveFile)) {
        oh_shit("Can't save to \"penult.sav\"!");
    }

    fwrite(Hero.Name, 1, (strlen(Hero.Name) + 1), SaveFile);

    fclose(SaveFile);
    print_line(MW_X, MW_Y, 0, "Game Saved!");
    Flags.MessageActive = 1;
}

void load_game() {
    FILE *LoadFile;
    char TmpName[9];
    int CurrentChar;
    uint8_t Count;

    if((LoadFile = fopen("penult.sav","rb")) == NULL) {
        oh_shit("Can't open \"penult.sav\" for reading!");        
    }

    if(!fread(&Hero, sizeof(Hero), 1, LoadFile)) {
        oh_shit("Can't read from \"penult.sav\"!");
    }

    for(Count = 0; Count < 8; Count++) {
        CurrentChar = fgetc(LoadFile);
        if((!CurrentChar) || (CurrentChar == EOF)) {
            break;
        }
        TmpName[Count] = CurrentChar;
    }
    TmpName[Count] = '\0';
    Hero.Name = malloc(Count+1);
    strcpy(Hero.Name, TmpName);
    fclose(LoadFile);
    if (Hero.EnergyRitual) {
        TileProperties[FORCE_FIELD_TILE].Solid = 0;
    }
}

void check_update_menu() {
    int Direction;

    if(Combat.Active && (Combat.State != 1) && (Combat.State != 2)) {
        return;
    }
    if(Combat.Active && Combat.Timer) {
        return;
    }
    Direction = get_direction();
    if(Direction) {
        SaveKey = 0;
        if((Direction == KEY_LEFT) || (Direction == KEY_RIGHT)) {
//            print_line(MW_X+(MarkerPos[Menu.Type][Menu.Selection] * 8), MW_Y+30, 0, " ");
            print_line(MW_X+(Menu.MarkerPos[Menu.Selection] * 8), MW_Y+30, 0, " ");
        }
        switch(Direction) {
            case KEY_DOWN:
                Menu.Active = 0;
                clear_text_window();
                break;
            case KEY_LEFT:
                if(Menu.Selection) {
                    Menu.Selection--;
                } else {
                    Menu.Selection = Menu.Choices - 1;
                }
                break;
            case KEY_RIGHT:
                if(Menu.Selection < (Menu.Choices - 1)) {
                    Menu.Selection++;
                } else {
                    Menu.Selection = 0;
                }
                break;
        }
        if((Direction == KEY_LEFT) || (Direction == KEY_RIGHT)) {
            print_line(MW_X+(Menu.MarkerPos[Menu.Selection] * 8), MW_Y+30, 0, ">");
        }
    }
}

void create_menu() {
    int Count;

    SaveKey = 0;
    if(Combat.Active && Combat.Timer) {
        return;
    }

    clear_text_window();

    if(Flags.MessageActive) {
        return;
    }
    Menu.Active = 1;
    Menu.Selection = 0;
    if(Combat.Active) {
        if(Combat.State == 1) {
            Menu.Type = HERO_COMBAT_MENU;
        } else if(Combat.State == 2) {
            Menu.Type = DRAGON_COMBAT_MENU;
        } else {
            Menu.Active = 0;
            return;
        }
    } else {
        if (Flags.InDungeon) {
            Menu.Type = DUNGEON_MENU;
        } else {
            if(Hero.CurrentMap) {
                Menu.Type = TOWN_MENU;
            } else {
                Menu.Type = OUTDOOR_MENU;
            }
        }
    }
    print_line(MW_X, MW_Y, 1, Messages[MenuPrompt[Menu.Type]]);
    print_line_formatted(MW_X, MW_Y+30, 0, ">%s", Messages[MenuText[Menu.Type]]);
    Menu.Choices = MenuChoices[Menu.Type];
    for(Count = 0; Count < Menu.Choices; Count++) {
        Menu.MarkerPos[Count] = MarkerPos[Menu.Type][Count];
        Menu.Actions[Count] = MenuActions[Menu.Type][Count];
    }
}

void activate_menu_item() {
    SaveKey = 0;
    Menu.Active = 0;
    clear_text_window();
//    (*MenuActions[Menu.Type][Menu.Selection])();
    (*Menu.Actions[Menu.Selection])();
//    Flags.MessageActive = 1;
}

char *split_line_start(const char *Source, int *SplitIndex) {
    char *RetString;
    int SourceLength = strlen(Source);
    int Index = 39;
    char TestChar = 0;

    if(SourceLength <= (Index-1)) {
        *SplitIndex = Index;
        return (char *)Source;
    }

    while(TestChar != ' ') {
        Index--;
        TestChar = Source[Index];
    }

    if(Index <= 0) {
        oh_shit("split_line_end: No spaces in source string.");
    }

    RetString = malloc(Index + 1);
    strncpy(RetString, Source, Index);
    RetString[Index] = '\0';
    *SplitIndex = Index;

    return RetString;
}

void queen_talk() {
    const char *Message;
    print_line(MW_X, MW_Y, 1, Messages[NPCName[Game.NPC]]);
    print_line_formatted(MW_X, MW_Y+20, 0, "Welcome, %s!", Hero.Name);
    if(Hero.XP > 127) {
        if(Hero.Level >= 6) {
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__FIND_THE_OTHER_TRAINERS]);
        } else {
            // Do level-up
            Hero.Level++;
            Hero.MHP += 2;
            Hero.HP = Hero.MHP;
            Hero.MSP += 2;
            Hero.SP = Hero.MSP;
            Hero.Str++;
            Hero.Dex++;
            Hero.Int++;
            flash_effect();
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_ARE_NOW_GREATER]);
            Hero.XP -= 128;
            draw_stats();
        }
    } else {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__GO_AND_EXPERIENCE_MORE]);
    }
    return;
}

void vendor_function() {
    const char *VendorPrompt = Messages[NPCName[Game.NPC]];
    int Count;

    switch(Game.NPC) {
        case GROCER:
           Menu.Value = 5;
           break;
        case SLING_VENDOR:
           Menu.Value = 50;
           break;
        case MACE_VENDOR:
           Menu.Value = 100;
           break;
        case LEATHER_VENDOR:
           Menu.Value = 200;
           break;
        case PLATE_VENDOR:
           Menu.Value = 2500;
           break;
        case AXE_VENDOR:
           Menu.Value = 400;
           break;
        case BOW_VENDOR:
           Menu.Value = 600;
           break;
        case HEALING_POTION_VENDOR:
           Menu.Value = 50;
           break;
        case SHIP_VENDOR:
           Menu.Value = 1000;
           break;
        case SWORD_VENDOR:
           Menu.Value = 1200;
           break;
        case CHAINMAIL_VENDOR:
           Menu.Value = 900;
           break;
        case CURE_POTION_VENDOR:
           Menu.Value = 100;
           break;
        case MSWORD_VENDOR:
           Menu.Value = 2400;
           break;
        case MBOW_VENDOR:
           Menu.Value = 1200;
           break;
        case HEALER:
            if(Hero.CurrentMap == 1) {
                VendorPrompt = Messages[STATUS__FREE_HEALING];
                Menu.Value = 0;
            } else {
                Menu.Value = 50;
            }
            break;
        default:
            oh_shit("Bad vendor type!");
    }
    print_line(MW_X, MW_Y, 1, VendorPrompt);  
    Menu.Type = VENDOR_MENU;
    print_line_formatted(MW_X, MW_Y+30, 0, ">%s", Messages[MenuText[Menu.Type]]);
    Menu.Choices = MenuChoices[Menu.Type];
    for(Count = 0; Count < Menu.Choices; Count++) {
        Menu.MarkerPos[Count] = MarkerPos[Menu.Type][Count];
        Menu.Actions[Count] = MenuActions[Menu.Type][Count];
    }
    Menu.Active = 1;
}

void do_buy_yes() {
    clear_text_window();
    Menu.Active = 0;
    if(Hero.Gold < Menu.Value) {
        print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_DONT_HAVE_ENOUGH]);
        return;
    }
    switch(Game.NPC) {
        case GROCER:
            if(Hero.Food >= 90) {
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_ENOUGH_ALREADY]);
                return;
            }
            Hero.Food += 10;
            break;
        case SLING_VENDOR:
            if(Hero.Ranged) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Ranged = 1;
            break;
        case MACE_VENDOR:
            if(Hero.Melee) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Melee = 1;
            break;
        case LEATHER_VENDOR:
            if(Hero.Armor) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Armor = 1;
            break;
        case PLATE_VENDOR:
            if(Hero.Armor >= 3) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Armor = 3;
            break;
        case AXE_VENDOR:
            if(Hero.Melee >= 2) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Melee = 2;
            break;
        case BOW_VENDOR:
            if(Hero.Ranged >= 2) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Ranged = 2;
            break;
        case HEALING_POTION_VENDOR:
            if(Hero.HealPotions >= 7) {
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_ENOUGH_ALREADY]);
                return;
            }
            Hero.HealPotions++;
            break;
        case SHIP_VENDOR:
           Menu.Value = 1000;
           break;
        case SWORD_VENDOR:
            if(Hero.Melee >= 3) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Melee = 3;
            break;
        case CHAINMAIL_VENDOR:
            if(Hero.Armor >= 2) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Armor = 2;
            break;
        case CURE_POTION_VENDOR:
            if(Hero.HealPotions >= 7) {
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_ENOUGH_ALREADY]);
                return;
            }
            Hero.CurePotions++;
            break;
        case MSWORD_VENDOR:
            if(Hero.Melee >= 4) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Melee = 4;
            break;
        case MBOW_VENDOR:
            if(Hero.Ranged >= 3) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Ranged = 3;
            break;
        case HEALER:
            if((Hero.Status == STATUS_GOOD) && (Hero.HP == Hero.MHP)) {
                clear_text_window();
                print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_HAVE_NO_NEED_OF_IT]);
                return;
            }
            Hero.Status = STATUS_GOOD;
            Hero.HP = Hero.MHP;
            break;
        default:
            oh_shit("Bad vendor type!");
    }
    Hero.Gold -= Menu.Value;
    clear_text_window();
    print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__THANK_YOU_COME_AGAIN]);
    draw_stats();
}

void check_gain_fire_ritual() {
    const char *TmpLine = Messages[MESSAGE__MAZINNA_THE_HERMIT_TALK];

    print_line(MW_X, MW_Y, 1, Messages[STATUS__MAZINNA_THE_HERMIT]);  
    print_pager_line(TmpLine);
    Menu.Active = 1;
    Menu.Choices = 1;
    Menu.MarkerPos[0] = 0;
    Menu.Selection = 0;
    Menu.Actions[0] = fire_ritual_function;
    SaveKey = 0;
}

void fire_ritual_function() {
    if (Hero.FireRitual) {
        print_line(MW_X, MW_Y+30, 1, "You already learned it.");  
    } else {
        Hero.FireRitual = 1;
        play_sound(CAST_SOUND);
        print_line(MW_X, MW_Y+30, 1, "You learn the fire ritual!");
    }
//    flash_effect();
    Hero.CurrentMap = WORLD_MAP;
    Hero.X = 46;
    Hero.Y = 8;
    load_map(Hero.CurrentMap);
    Menu.Active = 0;
    Flags.MessageActive = 1;
    save_game();
}

void check_gain_energy_ritual() {
    const char *TmpLine = Messages[MESSAGE__BAXTON_THE_WIZARD_TALK];

    print_line(MW_X, MW_Y, 1, Messages[STATUS__BAXTON_THE_WIZARD]);  
    print_pager_line(TmpLine);
    Menu.Active = 1;
    Menu.Choices = 1;
    Menu.MarkerPos[0] = 0;
    Menu.Selection = 0;
    Menu.Actions[0] = energy_ritual_function;
    SaveKey = 0;
}

void energy_ritual_function() {
    if (Hero.EnergyRitual) {
        print_line(MW_X, MW_Y+30, 1, "You already learned it.");  
    } else {
        Hero.EnergyRitual = 1;
        TileProperties[FORCE_FIELD_TILE].Solid = 0;
        play_sound(CAST_SOUND);
        print_line(MW_X, MW_Y+30, 1, "You learn the energy ritual!");
    }
//    flash_effect();
    Hero.CurrentMap = WORLD_MAP;
    Hero.X = 6;
    Hero.Y = 26;
    load_map(Hero.CurrentMap);
    Menu.Active = 0;
    Flags.MessageActive = 1;
    save_game();
}

void advanced_trainer_check() {
    const char *TmpLine;

    print_line(MW_X, MW_Y, 1, Messages[NPCName[Game.NPC]]);
    TmpLine = Messages[NPCText[Game.NPC]];
    print_pager_line(TmpLine);
    Menu.Active = 1;
    Menu.Choices = 1;
    Menu.MarkerPos[0] = 0;
    Menu.Selection = 0;
    Menu.Actions[0] = advanced_trainer_function;
}

void advanced_trainer_function() {
    print_line(MW_X, MW_Y, 1, Messages[STATUS__TRAIN_WITH_ME]);
    do_yes_no_menu();
    Menu.Actions[0] = advanced_trainer_yes;
    Menu.Actions[1] = advanced_trainer_no;
}

void advanced_trainer_yes() {
    Flags.MessageActive = 1;
    if ((Hero.XP < 128) || (Hero.Level < 6)) {
        print_line(MW_X, MW_Y+30, 0, "You are not ready.");
        return;
    }
    if (Hero.Level == 12) {
        print_line(MW_X, MW_Y+30, 0, "I can teach you no more.");
        return;
    }

    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_ARE_NOW_GREATER]);
    flash_effect();
    play_sound(CAST_SOUND);
    
    switch (Game.NPC) {
        case CLAN_ELDER_DURON:
            Hero.Str += 5;
            Hero.MHP += 5;
            break;
        case MAGE_MAXIMILIAN:
            Hero.Int += 5;
            Hero.MSP += 5;
            break;
        case GOLDWINE_THE_BARD:
            Hero.Dex += 5;
            Hero.MHP += 2;
            Hero.MSP += 2;
            break;
    }
    Hero.Level++;
    Hero.MHP += 2;
    Hero.MSP += 2;
    Hero.HP = Hero.MHP;
    Hero.SP = Hero.MSP;
    Hero.XP -= 128;
    draw_stats();
    save_game();
}

void advanced_trainer_no() {
    print_line(MW_X, MW_Y+30, 0, "Return when you are ready.");
    Flags.MessageActive = 1;
}


void bartender_function() {
    print_line(MW_X, MW_Y, 1, Messages[NPCName[Game.NPC]]);
    do_yes_no_menu();
    Menu.Actions[0] = do_bartender_yes;
    Menu.Actions[1] = do_bartender_no;
    Menu.Value = 5;
}

void do_bartender_yes() {
    const char *TmpLine;

    clear_text_window();
    Menu.Active = 0;
    print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_BARTENDER_SAYS]);  
    if(Hero.Gold < Menu.Value) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_DONT_HAVE_ENOUGH]);
        return;
    }

    Hero.Gold -= 5;
    TmpLine = Messages[NPCText[Game.NPC]];
    print_pager_line(TmpLine);
    draw_stats();
}

void do_bartender_no() {
    clear_text_window();
    Menu.Active = 0;
    print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_BARTENDER_SAYS]);  
    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__ANOTHER_TIME_PERHAPS]);
}


void do_buy_no() {
    print_line(MW_X, MW_Y, 1, Messages[STATUS__THE_MERCHANT_SAYS]);  
    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__ANOTHER_TIME_PERHAPS]);
    Menu.Active = 0;
}

void do_talk() {
    int Count = 0;
    uint8_t CurrentX = 0;
    uint8_t Found = 0;
    const char *TmpLine;
    const char *CurrentNPC = NPC[Hero.CurrentMap];

    clear_text_window();
    while(CurrentX != 0xFF) {
        CurrentX = CurrentNPC[Count];
        if((Hero.X == CurrentX) && (Hero.Y == CurrentNPC[Count + 1])) {
            Game.NPC = CurrentNPC[Count + 2];
            if(NPCFunction[Game.NPC]) {
                (*Actions[NPCFunction[Game.NPC]])();
                return;
            }
            print_line(MW_X, MW_Y, 1, Messages[NPCName[Game.NPC]]);
            TmpLine = Messages[NPCText[Game.NPC]];
            print_pager_line(TmpLine);
            Found = 1;
        }
        Count += 3;
    }

    if(!Found) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NO_ONE_IS_HERE]);
    }
    Menu.Active = 0;
    Flags.MessageActive = 1;
}

void print_pager_line(const char *Message) {
    int SplitIndex = 0;
    int TextY = MW_Y + 30;
    int Length;
    char *Line1, *Line2, *Line3;

    if(strlen(Message) > 38) {
        Line1 = split_line_start(Message, &SplitIndex);
        if(SplitIndex > 38) {
            TextY = MW_Y;
        } else {
            TextY = MW_Y + 10;
        }
        print_line(MW_X, TextY, 0, Line1);
        free((void *)Line1);
        Length = strlen(Message);
        Line2 = malloc(Length - SplitIndex);
        strncpy(Line2, (Message + SplitIndex + 1), (Length - SplitIndex));
        Length = strlen(Line2);
        if(Length > 38) {
            Message = split_line_start(Line2, &SplitIndex);
            Line3 = malloc(Length - SplitIndex);
            strncpy(Line3, (Line2 + SplitIndex + 1), (Length - SplitIndex));
            print_line(MW_X, MW_Y+30, 0, Line3);
            free(Line3);
            free(Line2);
            Line2 = (char *)Message;
        }
        TextY += 10;
        print_line(MW_X, TextY, 0, Line2);
        free(Line2);
    } else {
        print_line(MW_X, MW_Y+30, 0, Message);
    }
}

void do_use() {
    int Length, Count;
    int LinePos = 1;
    int ItemPos = 0;
    char ItemMenuText[40];

    if (!Hero.HomingGem && !Hero.DisguiseDust && !Hero.HealPotions
     && !Hero.CurePotions) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_TO_USE]);
        if (Combat.Active) {
            Combat.Timer = 8;
        } else {
            Flags.MessageActive = 1;
        }
        return;
    }
    Menu.Active = 1;
    Menu.Selection = 0;
    Menu.Type = ITEM_MENU;
    print_line(MW_X, MW_Y, 1, Messages[STATUS__ITEMS]);
    if (Hero.HealPotions) {
        strncpy(ItemMenuText+LinePos, "Heal Potion ", 12);
        Menu.MarkerPos[ItemPos] = LinePos - 1;
        LinePos += 12;
        Menu.Actions[ItemPos] = do_heal_potion;
        ItemPos++;
    }
    if (Hero.CurePotions) {
        strncpy(ItemMenuText+LinePos, "Cure Potion ", 12);
        Menu.MarkerPos[ItemPos] = LinePos - 1;
        LinePos += 12;
        Menu.Actions[ItemPos] = do_cure_potion;
        ItemPos++;
    }
    if (Hero.DisguiseDust) {
        strncpy(ItemMenuText+LinePos, "Dust ", 5);
        Menu.MarkerPos[ItemPos] = LinePos - 1;
        LinePos += 5;
        Menu.Actions[ItemPos] = do_disguise_dust;
        ItemPos++;
    }
    if (Hero.HomingGem) {
        strncpy(ItemMenuText+LinePos, "Gem ", 5);
        Menu.MarkerPos[ItemPos] = LinePos - 1;
        LinePos += 4;
        Menu.Actions[ItemPos] = do_homing_gem;
        ItemPos++;
    }
    LinePos--;
    ItemMenuText[0] = '>';
    ItemMenuText[LinePos] = '\0';
    print_line(MW_X, MW_Y+30, 0, ItemMenuText);
    Menu.Choices = ItemPos;
}

void do_cast() {
    int Length, Count;
    int LinePos = 1;
    int SpellPos = 0;
    char SpellMenuText[40];

//    Hero.SpellsKnown = RAY_SPELL;
//    Hero.SP = Hero.MSP;

    SaveKey = 0;
    clear_text_window();
    Menu.Active = 1;
    Menu.Selection = 0;
    Menu.Type = SPELL_MENU;
    print_line(MW_X, MW_Y, 1, "Current Spells Known:");
    if(!Hero.SpellsKnown) {
        print_line(MW_X, MW_Y+30, 0, "No spells known!");
        return;
    }
    SpellMenuText[0] = '>';
    if(Hero.SpellsKnown&RAY_SPELL) {
        Length = strlen(SpellName[0]);
        strncpy(SpellMenuText+LinePos, SpellName[0], Length);
        LinePos += Length;
        SpellMenuText[LinePos] = ' ';
        LinePos++;
        Menu.SpellOrder[SpellPos] = 0;
        SpellPos++;
    }
    
    if(Hero.SpellsKnown&SWAP_SPELL) {
        Length = strlen(SpellName[1]);
        strncpy(SpellMenuText+LinePos, SpellName[1], Length);
        LinePos += Length;
        SpellMenuText[LinePos] = ' ';
        LinePos++;
        Menu.SpellOrder[SpellPos] = 1;
        SpellPos++;
    }
    
    if(Hero.SpellsKnown&SUN_SPELL) {
        Length = strlen(SpellName[2]);
        strncpy(SpellMenuText+LinePos, SpellName[2], Length);
        LinePos += Length;
        SpellMenuText[LinePos] = ' ';
        LinePos++;
        Menu.SpellOrder[SpellPos] = 2;
        SpellPos++;
    }
    
    if(Hero.SpellsKnown&HEAL_SPELL) {
        Length = strlen(SpellName[3]);
        strncpy(SpellMenuText+LinePos, SpellName[3], Length);
        LinePos += Length;
        SpellMenuText[LinePos] = ' ';
        LinePos++;
        Menu.SpellOrder[SpellPos] = 3;
        SpellPos++;
    }
    
    if(Hero.SpellsKnown&HOP_SPELL) {
        Length = strlen(SpellName[4]);
        strncpy(SpellMenuText+LinePos, SpellName[4], Length);
        LinePos += Length;
        SpellMenuText[LinePos] = ' ';
        LinePos++;
        Menu.SpellOrder[SpellPos] = 4;
        SpellPos++;
    }
    
    if(Hero.SpellsKnown&ZAP_SPELL) {
        Length = strlen(SpellName[5]);
        strncpy(SpellMenuText+LinePos, SpellName[5], Length);
        Menu.SpellOrder[SpellPos] = 5;
        LinePos += Length;
        SpellMenuText[LinePos] = ' ';
        LinePos++;
        SpellPos++;
    }
    LinePos--;
    SpellMenuText[LinePos] = '\0';
    if(SpellPos < 6) {
        Menu.SpellOrder[SpellPos] = 0xFF;
    }
    print_line(MW_X, MW_Y+30, 0, SpellMenuText);
    Menu.Choices = SpellPos;
    Menu.MarkerPos[0] = 0;
    Menu.Actions[0] = MenuActions[Menu.Type][Menu.SpellOrder[0]];
    for(Count = 1; Count < SpellPos; Count++) {
        Menu.MarkerPos[Count] = strlen(SpellName[Menu.SpellOrder[Count - 1]]) + Menu.MarkerPos[Count - 1] + 1;
        Menu.Actions[Count] = MenuActions[Menu.Type][Menu.SpellOrder[Count]];
    }
}

void do_yes_no_menu() {
    print_line(MW_X, MW_Y+30, 0, ">Yes No");
    Menu.Active = 1;
    Menu.Choices = 2;
    Menu.MarkerPos[0] = 0;
    Menu.MarkerPos[1] = 4;
    Menu.Selection = 0;
}

void do_stats() {
    oh_shit("do_stats");
}

void do_heal_potion() {
    if (Hero.HP == Hero.MHP) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
    } else {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__HEALED]);
        play_sound(HEAL_SOUND);
        Hero.HP = Hero.MHP;
        draw_stats();
    }

    Hero.HealPotions--;
    if (Combat.Active) {
        Combat.Timer = 8;
        advance_combat_state();
    } else {
        Flags.MessageActive = 1;
    }
}

void do_cure_potion() {
    if (Hero.Status != STATUS_POISONED) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
    } else {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__CURED]);
        play_sound(HEAL_SOUND);
        Hero.Status = STATUS_GOOD;
        draw_stats();
    }

    Hero.CurePotions--;
    if (Combat.Active) {
        Combat.Timer = 8;
        advance_combat_state();
    } else {
        Flags.MessageActive = 1;
    }
}

void do_disguise_dust() {
    Hero.DisguiseDust = 0;
    play_sound(CAST_SOUND);
    switch (Hero.CurrentMap) {
        case STONEHEART_MAP:
            Flags.Disguised = 1;
            Game.DisguiseTile = DWARF_TILE_NUMBER;
            break;
        case DUSKGROVE_MAP:
            Flags.Disguised = 1;
            Game.DisguiseTile = OGRE_TILE_NUMBER;
            break;
        case THANAS_HOLD_MAP:
            Flags.Disguised = 1;
            Game.DisguiseTile = GOBLIN_TILE_NUMBER;
            break;
        default:
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
    }
    if (Flags.Disguised) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_CHANGE_FORM]);
    }
    Flags.MessageActive = 1;
    save_game();
}

void do_homing_gem() {
    Flags.Disguised = 0;
    Hero.HomingGem = 0;
    play_sound(WIND_SOUND);
    scr_palette(MyScreen, DEFAULT_PALETTE, 0);
    Hero.X = 5;
    Hero.Y = 12;
    Hero.PrevMap = WORLD_MAP;
    Hero.PrevX = 48;
    Hero.PrevY = 15;
    Hero.CurrentMap = ACADIA_MAP;
    print_line(MW_X, MW_Y+30, 0, "Teleported!");
    Flags.MessageActive = 1;
    Combat.Active = 0;
    if (Flags.InDungeon) {
        exit_dungeon();
    } else {
        load_map(Hero.CurrentMap);   
        save_game();
    }
}

void do_loot() {
    int LevelOffset = Dungeon.Level * 256;
    int TileOffset = (Dungeon.Y * DUNGEON_WIDTH) + Dungeon.X + LevelOffset;
    char CurrentDTile = CurrentMap[TileOffset];

    if (CurrentDTile != DUNGEON_CHEST) {
        if (CurrentDTile == DUNGEON_OPEN_CHEST) {
            print_line(MW_X, MW_Y+30, 0, "Already looted!");
        } else {
            print_line(MW_X, MW_Y+30, 0, "Nothing to loot!");
        }
        Flags.MessageActive = 1;
        return;
    }

    do_yes_no_menu();
    print_line(MW_X, MW_Y, 1, Messages[STATUS__LOOT_THIS_CHEST]); 
    Menu.Actions[0] = do_loot_yes;
    Menu.Actions[1] = do_loot_no;
}

void do_loot_yes() {
    int LevelOffset = Dungeon.Level * 256;
    int TileOffset = (Dungeon.Y * DUNGEON_WIDTH) + Dungeon.X + LevelOffset;
    uint8_t gold;

    CurrentMap[TileOffset] = DUNGEON_OPEN_CHEST;

    gold = find_gold(Dungeon.Level + 1);

    if (gold) {
        print_line_formatted(MW_X, MW_Y+20, 0, "You find %d gold!", gold);
    }
    
    if (rand()&1) {
        do_dungeon_trap();
    } else {
        if (gold) {
            play_sound(HEAL_SOUND);
        }
    }

    draw_stats();
    Flags.MessageActive = 1;
}

void do_loot_no() {
    return;
}

void flash_effect() {
    if (Flags.InDungeon) {
        return;
    }
    if(!Game.FlashTimer) {
        Game.FlashTimer = 8;
        Game.DoInvert = 1;
        play_sound(CAST_SOUND);
    } else {
        Game.FlashTimer--;
        if(!Game.FlashTimer) {
            Game.DoInvert = 1;
        }
    }
}

void invalidate_view() {
    uint8_t CountX, CountY;

    for(CountX = 0; CountX < VIEWPORT_WIDTH; CountX++) {
        for(CountY = 0; CountY < VIEWPORT_HEIGHT; CountY++) {
            viewport_prev[CountX][CountY] = 0xFF;
        }
    }
}

void clear_view() {
    uint8_t CountX, CountY;

    for(CountX = 0; CountX < VIEWPORT_WIDTH; CountX++) {
        for(CountY = 0; CountY < VIEWPORT_HEIGHT; CountY++) {
            viewport[CountX][CountY] = NOTHING_TILE;
        }
    }
}

void end_combat() {
    uint8_t AdjustedPower, Count;
    uint8_t PrevXP = Hero.XP;
    char *ArenaMap;
    Combat.Active = 0;
    Combat.Victory = 0;
    
    if (Hero.HP == 0) {
        do_death();
    } else {
        if (Flags.InDungeon) {
            ArenaMap = (char *)Arena[DUNGEON_ARENA];
            scr_palette(MyScreen, DUNGEON_PALETTE, 0);
            clear_view();
            for (Count = 0; Count < 2; Count++) {
                if(Dungeon.Pillar[Count]) {
                    ArenaMap[Dungeon.Pillar[Count]] = DIRT_TILE;
                }
            }
        }
        viewport_prev[Combat.HeroX][Combat.HeroY] = 0xFF;
        if(Combat.Gold) {
            print_line_formatted(MW_X, MW_Y+30, 0, "You find %d gold!", Combat.Gold);
            Hero.Gold += Combat.Gold;
            Flags.MessageActive = 1;
        }

        AdjustedPower = (Combat.EnemyPower + 3) - Hero.Level;
        if (AdjustedPower < 1) {
            AdjustedPower = 1;
        }
        Hero.XP += (AdjustedPower * 4);
        if (Hero.XP < PrevXP) {
            Hero.XP = 0xFF;
        }

    }
    if (Hero.DragonHP) {
        viewport_prev[Combat.DragonX][Combat.DragonY] = 0xFF;
    }
    Flags.Disguised = 0;
    draw_stats();
}

void load_arena(int CurrentArena) {
    uint8_t ArenaX, ArenaY, ArenaYTW;
    const char *ArenaMap = Arena[CurrentArena];
    int Count, CurrentTile;

    if(Combat.Timer) {
        Combat.Timer--;
        if(!Combat.Timer) {
            clear_text_window();
        }
    }

    if ((Combat.State == 0xFF) && (Hero.HP == 0)) {
        if (Combat.Timer) {
            return;
        }
        end_combat();
        return;
    }

    if ((Combat.State == 0xFF) && (!Combat.Victory)) {
        if (Combat.Timer) {
            return;
        }
        clear_text_window();
        Combat.Victory = 1;
        print_line(MW_X, MW_Y+30, 0, Messages[STATUS__VICTORY]);
        play_music(VICTORY_MUSIC);
        Combat.Timer = 15;
        Combat.Gold = find_gold(Combat.EnemyPower);
        return;
    }

    if(Combat.Victory) {
        if (!Combat.Timer) {
            end_combat();
        }
        return;
    }

    if(Combat.State == 0xFF) {
        return;
    }

    if(Combat.MissileActive) {
        update_missile();
    }

    if(!Combat.State && !Combat.Timer) {
        Combat.State = 1;
        clear_text_window();
    }

    if((Combat.State > 2) && (Combat.State < 7) && !Combat.Timer && !Combat.MissileActive) {
        do_enemy_turn(Combat.State - 3);
    }

    for(ArenaX = 0; ArenaX < ARENA_WIDTH; ArenaX++) {
        for(ArenaY = 0; ArenaY < ARENA_HEIGHT; ArenaY++) {
            ArenaYTW = ArenaY * ARENA_WIDTH;
            viewport_prev[ArenaX][ArenaY] = viewport[ArenaX][ArenaY];
            viewport[ArenaX][ArenaY] = CurrentTiles[ArenaMap[ArenaYTW + ArenaX]];
        }
    }
    if((Combat.State == 1) && !Combat.Timer) {
        CurrentTile = CurrentTiles[66];
    } else {
        CurrentTile = CurrentTiles[65];
    }
    viewport[Combat.HeroX][Combat.HeroY] = CurrentTile;
    if(Hero.DragonHP) {
        if((Combat.State == 2) && !Combat.Timer) {
            CurrentTile = CurrentTiles[61];
        } else {
            CurrentTile = CurrentTiles[60];
        }
        viewport[Combat.DragonX][Combat.DragonY] = CurrentTile;
    }
    for(Count = 0; Count < 4; Count++) {
        if(Combat.EnemyHP[Count]) {
            viewport[Combat.EnemyX[Count]][Combat.EnemyY[Count]] = CurrentTiles[Combat.EnemyTile];
        }
    }

    if(Combat.MissileActive) {
        viewport[Combat.MissileX][Combat.MissileY] = 67;
    }

}

uint8_t find_gold(uint8_t GoldLevel) {
    uint8_t gold = 0;

    gold = (rand() & gold_range[GoldLevel]) + (GoldLevel * 4);
    if(gold > 99) {
        gold = 99;
    }

    if((Hero.Gold + gold) > 9999) {
        gold = 9999 - Hero.Gold;
    }

    return gold;
}

void start_combat() {
    uint8_t Count, TmpRand, RandX, RandY;
    char CurrentTile = CurrentMap[(Game.MapWidth * Hero.Y) + Hero.X];
    char *ArenaMap;

    if (CurrentTile == LAVA_TILE && !Hero.FireRitual) {
        return;
    }

    if (Flags.InDungeon) {
        Combat.Arena = DUNGEON_ARENA;
        ArenaMap = (char *)Arena[DUNGEON_ARENA];
        for (Count = 0; Count < 2; Count++) {
            TmpRand = (rand() & 7) + (rand() & 7) + (rand() & 7);
            RandX = (TmpRand / 3) + 2;
            RandY = (TmpRand % 7) + 3;
            if (RandY > 5) {
                RandY = 5;
            }
//            ArenaMap[(RandY * ARENA_WIDTH) + RandX] = ROCKY_WALL_TILE;
            Dungeon.Pillar[Count] = (RandY * ARENA_WIDTH) + RandX;
            if (ArenaMap[Dungeon.Pillar[Count]] == DIRT_TILE) {
                ArenaMap[Dungeon.Pillar[Count]] = ROCKY_WALL_TILE;
            } else {
                Dungeon.Pillar[Count] = 0;
            }
        }
        scr_palette(MyScreen, DUNGEON_COMBAT_PALETTE, 0);
        clear_dungeon_screen();
        clear_view();
    } else {
        switch(CurrentTile) {
            case GRASS_TILE:
                Combat.Arena = PLAINS_ARENA;
                break;
            case FOREST_TILE:
                Combat.Arena = FOREST_ARENA;
                break;
            case HEAVY_FOREST_TILE:
                Combat.Arena = HEAVY_FOREST_ARENA;
                break;
            case BRIDGE_TILE:
                Combat.Arena = BRIDGE_ARENA;
                break;
            case DIRT_TILE:
            case CIRCLE_TILE:
                Combat.Arena = SAND_ARENA;
                break;
            case WATER_TILE:
                Combat.Arena = SHIP_ARENA;
                break;
            case LAVA_TILE:
                Combat.Arena = LAVA_ARENA;
                break;
            default:
                return;
        }
    }

    play_music(COMBAT_START_MUSIC);
    Combat.Active = 1;
    Combat.Victory = 0;
    Combat.State = 0;
    Combat.Timer = 12;
    Combat.Gold = 0;
    Combat.HealUsed = 0;
    Combat.HeroGrappled = 0;
    Combat.DragonGrappled = 0;

    viewport[5][4] = 0;
    if (Combat.Arena == BRIDGE_ARENA) {
        Combat.EnemyNumber = TROLL_ENEMY_NUMBER;
    } else if (Combat.Arena == LAVA_ARENA) {
        Combat.EnemyNumber = SALAMANDER_ENEMY_NUMBER;
    } else if (Combat.Arena == DUNGEON_ARENA) {
        Combat.EnemyNumber = Dungeon.Number + Dungeon.Level + DUNGEON_MONSTER_OFFSET + (rand()&3);
    } else {
        Combat.EnemyNumber = (rand() % 4) + Hero.Level;
    }
    Combat.EnemyTraits = EnemyTraits[Combat.EnemyNumber];
    Combat.EnemyTile = EnemyToTile[Combat.EnemyNumber];
    Combat.EnemyPower = EnemyPower[Combat.EnemyNumber];
    Combat.EnemyAC = Combat.EnemyPower + 8;
    if (Combat.Arena == DUNGEON_ARENA) {
        Combat.HeroX = 4;
        Combat.HeroY = 6;
        Combat.DragonX = 6;
        Combat.DragonY = 6;
    } else {
        Combat.HeroX = 3;
        Combat.HeroY = 7;
        Combat.DragonX = 7;
        Combat.DragonY = 7;
    }
    Hero.DragonHP = Hero.MHP;
    for(Count = 0; Count < 4; Count++) {
        Combat.EnemyHP[Count] = (rand() % EnemyHPBase[Combat.EnemyPower]) + Combat.EnemyPower;
        if(Combat.EnemyTraits&ENEMY_STRONG) {
            Combat.EnemyHP[Count] += Combat.EnemyPower / 2;
        }
        if (Combat.Arena == DUNGEON_ARENA) {
            Combat.EnemyX[Count] = DungeonStartX[Count];
            Combat.EnemyY[Count] = DungeonStartY[Count];
        } else {
            if (Combat.Arena == BRIDGE_ARENA) {
                Combat.EnemyX[Count] = TrollStartX[Count];
            } else {
                Combat.EnemyX[Count] = EnemyStartX[Count];
            }
            Combat.EnemyY[Count] = EnemyStartY[Count];
        }
    }
    clear_text_window();
    print_line(MW_X, MW_Y, 1, "Combat Begins!");
    print_line_formatted(MW_X, MW_Y+30, 0, "You encounter %ss.", MonsterName[Combat.EnemyNumber]);
}

void do_attack() {
    int CurX, CurY, AttX, AttY, Count, HitRoll, Damage;
    int Direction = 0;
    int Enemy = 0xFF;
    // char ErrorBuf[BUFSIZ];

    Menu.Active = 0;

    if(Combat.State == 1) {
        CurX = Combat.HeroX;
        CurY = Combat.HeroY;
    } else if(Combat.State == 2) {
        CurX = Combat.DragonX;
        CurY = Combat.DragonY;
    }

    Direction = which_direction();

    if(!Direction) {
        return;
    }

    clear_text_window();

    AttX = CurX;
    AttY = CurY;

    switch(Direction) {
        case KEY_LEFT:
            AttX--;
            break;
        case KEY_RIGHT:
            AttX++;
            break;
        case KEY_UP:
            AttY--;
            break;
        case KEY_DOWN:
            AttY++;
            break;
    }
    if((AttX < 0) || (AttX >= ARENA_WIDTH) || (AttY < 0) || (AttY >= ARENA_HEIGHT)) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NO_ONE_IS_HERE]);
        play_sound(MISS_SOUND);
        Combat.Timer = 8;
        advance_combat_state();
        return;
    }

    for(Count = 0; Count < 4; Count++) {
        if((Combat.EnemyX[Count] == AttX) && (Combat.EnemyY[Count] == AttY) &&
         (Combat.EnemyHP[Count])) {
            Enemy = Count;
        }
    }

    if(Enemy == 0xFF) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NO_ONE_IS_HERE]);
        play_sound(MISS_SOUND);
        advance_combat_state();
        Combat.Timer = 8;
        return;
    }

    HitRoll = (rand() & 15) + (Hero.Str / 5) + (Hero.Level / 2);
    if(HitRoll >= Combat.EnemyAC) {
        print_line_formatted(MW_X, MW_Y+30, 0, "The %s is hit!", MonsterName[Combat.EnemyNumber]);
        play_sound(HIT_SOUND);
        if ((Combat.EnemyNumber == 30) && (Combat.State == 1)) { // slime
            if (Hero.Melee && (Hero.Melee < 5)) {
                if (Flags.WeaponCorroded) {
                    print_line_formatted(MW_X, MW_Y+20, 1, "Your %s dissolves!", Melee[Hero.Melee]);
                    Hero.Melee = 0;
                    draw_stats();
                } else {
                    print_line_formatted(MW_X, MW_Y+20, 1, "Your %s is corroded!", Melee[Hero.Melee]);
                    Flags.WeaponCorroded = 1;
                }
                Combat.Timer = 8;
            }
        }
    } else {
        print_line(MW_X, MW_Y+30, 0, "Missed.");
        play_sound(MISS_SOUND);
        advance_combat_state();
        Combat.Timer = 8;
        return;
    }

    Damage = (Hero.Str / 5);
    if(Combat.State == 1) {
        if ((Combat.EnemyTraits&ENEMY_INCORPORAL) && (Hero.Melee < 4)) {
            Damage = 0;
        } else {
            Damage += Hero.Melee * 2;
        }
    } else {
        Damage += (Hero.Level / 4) + 1;
    }

    damage_enemy(Enemy, Damage);
}

void damage_enemy(int Enemy, int Damage) {
    int Pos = (strlen(MonsterName[Combat.EnemyNumber]) + 13) * 8;
    uint8_t GrappleBroken = 0;
    
    if (!Damage) {
        print_line(MW_X + Pos, MW_Y+30, 0, "No harm!");
    }
    
    Combat.EnemyHP[Enemy] -= Damage;

    if(Combat.EnemyHP[Enemy] <= 0) {
        Combat.EnemyHP[Enemy] = 0;
        print_line(MW_X + Pos, MW_Y+30, 0, "Killed!");
        if (Combat.HeroGrappled && (Combat.HeroGrappleEnemy == Enemy)) {
            Combat.HeroGrappled = 0;
            GrappleBroken = 1;
        } else if (Combat.DragonGrappled && (Combat.DragonGrappleEnemy == Enemy)) {
            Combat.DragonGrappled = 0;
            GrappleBroken = 1;
        }
        if (GrappleBroken) {
            print_line(MW_X + Pos + 64, MW_Y+30, 0, "Freed!");
        }
    }
    advance_combat_state();
    Combat.Timer += 10;
}

int which_direction() {
    int Direction = 0;

    clear_text_window();
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__WHICH_DIRECTION]);
    while(!Direction) {
        Direction = get_direction();
        if(check_button_press()) {
            clear_text_window();
            return 0;
        }
    }

    SaveKey = 0;
    return Direction;
}

void do_ranged() {
    int Direction;

    if(!Hero.Ranged && Combat.State == 1) {
        clear_text_window();
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NO_RANGED_WEAPON]);
        Combat.Timer = 8;
        return;
    }

    Direction = which_direction();
    if(!Direction) {
        return;
    }


    clear_text_window();
    Combat.MissileActive = 1;
    Combat.MissileDirection = Direction;
    Combat.MissileOrigin = 0;   // player/dragon
    Combat.HitRoll = (rand() & 15) + (Hero.Dex / 5) + (Hero.Level / 2);

    if(Combat.State == 1) {
        play_sound(MISSILE_SOUND);
        Combat.MissileX = Combat.HeroX;
        Combat.MissileY = Combat.HeroY;
        if(Hero.Ranged >= RANGED_M_BOW) {
            Combat.MissileType = 1;
        } else {
            Combat.MissileType = 0;
        }
        Combat.MissileDamage = Hero.Ranged * 2;
    } else {
        play_sound(BREATH_SOUND);
        Combat.MissileX = Combat.DragonX;
        Combat.MissileY = Combat.DragonY;
        Combat.MissileType = 1;
        Combat.MissileDamage = (Hero.Level / 4) + (Hero.Int / 5) + 1;
    }
}

void update_missile() {
    int TargetCreature;
    int Done = 0;

    TargetCreature = TileCreature(Combat.MissileX, Combat.MissileY);

    if(TargetCreature) {
        if (TargetCreature == 0xFF) {
            if(Combat.MissileOrigin == 0) {
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NO_ENEMY_THERE]);
            } else {
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__MISSED]);
                play_sound(MISS_SOUND);
            }
            Combat.MissileActive = 0;
            Combat.Timer = 8;
            advance_combat_state();
        return;
        }
        if(Combat.MissileOrigin) {
            // Enemy missile hits player/dragon
            if(TargetCreature == 1) {
                if(Combat.HitRoll >= ((Hero.Armor * 2) + 6)) {
                    damage_hero(Combat.MissileDamage);
                    Combat.MissileActive = 0;
                    Combat.Timer = 8;
                    play_sound(HIT_SOUND);
                } else {
                    clear_text_window();
                    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__MISSED]);
                    Combat.MissileActive = 0;
                    Combat.Timer = 8;
                    play_sound(MISS_SOUND);
                }

                advance_combat_state();
                return;
            } else if(TargetCreature == 2) {
                if(Combat.HitRoll >= ((Hero.Level) + 6)) {
                    damage_dragon(Combat.MissileDamage);
                    Combat.MissileActive = 0;
                    Combat.Timer = 8;
                    play_sound(HIT_SOUND);
                } else {
                    clear_text_window();
                    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__MISSED]);
                    Combat.MissileActive = 0;
                    Combat.Timer = 8;
                    play_sound(MISS_SOUND);
                }
                advance_combat_state();
                return;
            } // else enemy shot passes through enemy
            // message set by damage function?
        } else {
            // player/dragon missile hits monster
            if(TargetCreature > 2) {
                if(Combat.HitRoll >= Combat.EnemyAC) {
                    print_line_formatted(MW_X, MW_Y+30, 0, "The %s is hit!", MonsterName[Combat.EnemyNumber]);
                    play_sound(HIT_SOUND);
                    if ((Combat.EnemyTraits&ENEMY_INCORPORAL) && Combat.MissileType == 0) {
                        Combat.MissileDamage = 0;
                    } 
                    damage_enemy(TargetCreature - 3, Combat.MissileDamage);
                    Combat.MissileActive = 0;
                    return;
                } else {
                    print_line(MW_X, MW_Y+30, 0, "Missed.");
                    play_sound(MISS_SOUND);
                    advance_combat_state();
                    Combat.Timer = 8;
                    Combat.MissileActive = 0;
                    return;
                }
            }
        }
    }

    switch(Combat.MissileDirection) {
        case KEY_LEFT:
            if(!Combat.MissileX) {
                Done = 1;
            } else {
                Combat.MissileX--;
            }
            break;
        case KEY_RIGHT:
            Combat.MissileX++;
            if(Combat.MissileX == ARENA_WIDTH) {
                Done = 1;
            }
            break;
        case KEY_UP:
            if(!Combat.MissileY) {
                Done = 1;
            } else {
                Combat.MissileY--;
            }
            break;
        case KEY_DOWN:
            Combat.MissileY++;
            if(Combat.MissileY == ARENA_HEIGHT) {
                Done = 1;
            }
            break;
    }
    if(Done) {
        if(Combat.MissileOrigin == 0) {
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NO_ENEMY_THERE]);
        } else {
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__MISSED]);
            play_sound(MISS_SOUND);
        }
        Combat.MissileActive = 0;
        Combat.Timer = 8;
        advance_combat_state();
    }
}

void damage_hero(int Damage) {
    uint8_t Enemy = Combat.State - 3;
    uint8_t GrappleCheck = 0;

    clear_text_window();
    if (Damage > 256) {
        Damage -= 256;
        GrappleCheck = 1;
    }

    if(Damage < Hero.HP) {
        if ((Combat.EnemyTraits&ENEMY_POISON) && !(rand()&3) && (Hero.Status != STATUS_POISONED)) {
            print_line(MW_X, MW_Y+30, 0, "You are hit! Poisoned!");
            Hero.Status = STATUS_POISONED;
        } else {
            if (!Combat.HeroGrappled && ((Combat.EnemyX[Enemy] == Combat.HeroX)
            || (Combat.EnemyY[Enemy] == Combat.HeroY)) && GrappleCheck) {
                print_line(MW_X, MW_Y+30, 0, "You are hit! Grappled!");
                Combat.HeroGrappled = 1;
                Combat.HeroGrappleEnemy = Enemy;
            } else {
                if (Combat.HeroGrappled && (Enemy == Combat.HeroGrappleEnemy)) {
                    print_line(MW_X, MW_Y+30, 0, "You get squeezed!");
                } else {
                    print_line(MW_X, MW_Y+30, 0, "You are hit!");
                }
            }
        }
        Hero.HP -= Damage;
    } else {
        if (Combat.HeroGrappled && (Enemy == Combat.HeroGrappleEnemy)) {
            print_line(MW_X, MW_Y+30, 0, "You get squeezed! You die...");
        } else {
            print_line(MW_X, MW_Y+30, 0, "You are hit! You die...");
        }
        Combat.Timer += 20;
        Hero.HP = 0;
        Combat.State = 0xFF;
    }
    draw_stats();
}

void damage_dragon(int Damage) {
    uint8_t Enemy = Combat.State - 3;
    uint8_t GrappleCheck = 0;

    clear_text_window();
    if (Damage > 256) {
        Damage -= 256;
        GrappleCheck = 1;
    }

    clear_text_window();
    if(Damage < Hero.DragonHP) {
        if (!Combat.DragonGrappled && ((Combat.EnemyX[Enemy] == Combat.DragonX)
        || (Combat.EnemyY[Enemy] == Combat.DragonY)) && GrappleCheck) {
            print_line_formatted(MW_X, MW_Y+30, 0, "%s Grappled!", Messages[MESSAGE__THE_DRAGON_IS_HIT]);
            Combat.DragonGrappled = 1;
            Combat.DragonGrappleEnemy = Enemy;
        } else {
            if (Combat.DragonGrappled && (Enemy == Combat.DragonGrappleEnemy)) {
                print_line(MW_X, MW_Y+30, 0, "Dragon gets squeezed!");
            } else {
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__THE_DRAGON_IS_HIT]);
            }
        }
        Hero.DragonHP -= Damage;
    } else {
        if (Combat.DragonGrappled && (Enemy == Combat.DragonGrappleEnemy)) {
            print_line(MW_X, MW_Y+30, 0, "Dragon gets squeezed!");
        } else {
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__THE_DRAGON_IS_HIT]);
        }
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__FEY_DRAGON_DISSIPATES]);
        Combat.Timer += 10;
        Hero.DragonHP = 0;
    }
    draw_stats();
}

//void do_combat_use() {
//    return;
//}

void do_combat_move(int Direction) {
    int Blocked = 0;
    int NewX, NewY;
    
    if (Combat.EnemyTraits&ENEMY_GRAPPLE) {
        if ((Combat.State == 1) && (Combat.HeroGrappled)) {
            print_line(MW_X, MW_Y+30, 0, "You are grappled!");
            Combat.Timer = 8;
            advance_combat_state();
            return;
        } else if ((Combat.State == 2) && (Combat.DragonGrappled)) {
            print_line(MW_X, MW_Y+30, 0, "Dragon is grappled!");
            Combat.Timer = 8;
            advance_combat_state();
            return;
        }
    }

    if(Combat.State == 1) {
        NewX = Combat.HeroX;
        NewY = Combat.HeroY;
    } else {
        NewX = Combat.DragonX;
        NewY = Combat.DragonY;
    }

    switch(Direction) {
        case KEY_UP:
            NewY--;
            break;
        case KEY_DOWN:
            NewY++;
            break;
        case KEY_LEFT:
            NewX--;
            break;
        case KEY_RIGHT:
            NewX++;
            break;
    }

    if((NewX < 0) || (NewX >= ARENA_WIDTH) || (NewY < 0) || (NewY >= ARENA_HEIGHT)) {
        Blocked = 1;
    }

    if(!space_free(NewX, NewY)) {
        Blocked = 1;
    }

    if(Blocked) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_CANT_GO_THAT_WAY]);
        play_sound(BLOCKED_SOUND);
        Combat.Timer = 8;
        advance_combat_state();
        return;
    }

    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__MOVED]);
    play_sound(WALK_SOUND);
    if(Combat.State == 1) {
        Combat.HeroX = NewX;
        Combat.HeroY = NewY;
    } else {
        Combat.DragonX = NewX;
        Combat.DragonY = NewY;
    }
    Game.PrevTurns = Game.Turns;
    Game.Turns++;
    advance_combat_state();
    Combat.Timer = 8;
}


void do_dragon_heal() {
    int Healing = (Hero.Int / 5) + (Hero.Level * 2) + 2;
    
    clear_text_window();
    if(Combat.HealUsed) {
        print_line(MW_X, MW_Y, 0, Messages[MESSAGE__ALREADY_HEALED]);
        Combat.Timer = 8;
        draw_stats();
        advance_combat_state();
        return;
    }

    Combat.HealUsed = 1;

    if((Hero.HP == Hero.MHP) && (Hero.DragonHP == Hero.MHP)) {
        print_line(MW_X, MW_Y, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
        Combat.Timer = 8;
        advance_combat_state();
        return;
    }

    Hero.HP += Healing;
    if(Hero.HP > Hero.MHP) {
        Hero.HP = Hero.MHP;
    }

    Hero.DragonHP += Healing;
    if(Hero.DragonHP > Hero.MHP) {
        Hero.DragonHP = Hero.MHP;
    }

    play_sound(HEAL_SOUND);
    print_line(MW_X, MW_Y, 0, Messages[MESSAGE__PARTY_HEALED]);
    Combat.Timer = 8;
    draw_stats();
    advance_combat_state();
}

void advance_combat_state() {
    Menu.Active = 0;

    if (Combat.State == 0xFF) {
        return;
    }

    if(!Combat.EnemyHP[0] && !Combat.EnemyHP[1] && !Combat.EnemyHP[2] && !Combat.EnemyHP[3]) {
        Combat.State = 0xFF;
        return;
    }

    Combat.State++;
    if(Combat.State > 6) {
        Combat.State = 1;
        if(Hero.SP < Hero.MSP) {
            Hero.SP++;
            draw_stats();
        }
    }
    if((Combat.State == 2) && !Hero.DragonHP) {
        Combat.State++;
    }
    if(Combat.State > 2) {
        while(!Combat.EnemyHP[Combat.State - 3]) {
            Combat.State++;
            if (Combat.State > 6) {
                Combat.State = 1;
                break;
            }
        }
    }
}

int TileCreature(int CombatX, int CombatY) {
    const char *ArenaMap = Arena[Combat.Arena];
    uint8_t Count, ArenaTile;

    if((Combat.HeroX == CombatX) && (Combat.HeroY == CombatY)) {
        return 1;
    }
    if((Combat.DragonX == CombatX) && (Combat.DragonY == CombatY) && (Hero.DragonHP)) {
        return 2;
    }
    for(Count = 0; Count < 4; Count++) {
        if((Combat.EnemyX[Count] == CombatX) && (Combat.EnemyY[Count] == CombatY) && Combat.EnemyHP[Count]) {
            return Count + 3;
        }
    }

    ArenaTile = ArenaMap[(CombatY * ARENA_WIDTH) + CombatX];
    switch (ArenaTile) {
        case NOTHING_TILE:
        case WATER_TILE:
        case STONE_WALL_TILE:
        case ROCKY_WALL_TILE:
            return 0xFF;
    }
    return 0;
}

int space_free(int CombatX, int CombatY) {
    uint8_t Count, ArenaTile;
    const char *ArenaMap = Arena[Combat.Arena];

    if ((CombatX >= ARENA_WIDTH) || (CombatY >= ARENA_HEIGHT)
     ||(CombatX < 0) || (CombatY < 0)) {
        return 0;
    } 

    if((Combat.HeroX == CombatX) && (Combat.HeroY == CombatY)) {
        return 0;
    }
    if((Combat.DragonX == CombatX) && (Combat.DragonY == CombatY) && (Hero.DragonHP)) {
        return 0;
    }
    for(Count = 0; Count < 4; Count++) {
        if((Combat.EnemyX[Count] == CombatX) && (Combat.EnemyY[Count] == CombatY) && Combat.EnemyHP[Count]) {
            return 0;
        }
    }
    ArenaTile = ArenaMap[(CombatY * ARENA_WIDTH) + CombatX];
    switch (ArenaTile) {
        case NOTHING_TILE:
        case WATER_TILE:
        case STONE_WALL_TILE:
        case ROCKY_WALL_TILE:
            return 0;
    }
    return 1;
}

void invert_viewport() {
    char *ViewportBits = ViewportBuffer->pixels;
    Game.DoInvert = 0;

    _asm {
;        cld
        push si
        push di
        mov si,[ViewportBits]
        mov di,si
        mov ax,ds
        mov es,ax
        mov cx,3168
;        mov bx,0xFFFF
InvertLoop:
        lodsw
        not ax
        stosw
        dec cx
        jne InvertLoop
        pop di
        pop si
    }
}

void do_enemy_turn(int Enemy) {
    int MissileDirection = 0;
    int TmpCoordX = -1, TmpCoordY = -1;
    int Damage, Priority, Count;
    char Directions[8];
    char StartMove, NewX, NewY, HeroDistance, DragonDistance, CurrentPriority;
    char CurrentDirection = 0xFF;
    uint8_t DoRanged = 0;
    uint8_t RespawnX = 0xFF, RespawnY = 0xFF;
    uint8_t RespawnNum = 0xFF;
    uint8_t TempX, TempY;

    clear_text_window();
    print_line_formatted(MW_X, MW_Y, 1, "%s (%d):",
     MonsterName[Combat.EnemyNumber], Enemy + 1);
    
    // Monster respawn
    if ((Combat.EnemyTraits&ENEMY_RESPAWN) && !(rand()&7)) {
        // Find missing monster, if any
        for (Count = 0; Count < 4; Count++) {
            if (!Combat.EnemyHP[Count]) {
                RespawnNum = Count;
                break;
            }
        }

        // Check for adjacent free space; otherwise set to 0xFF

        // Check South
        if (space_free(Combat.EnemyX[Enemy],
         Combat.EnemyY[Enemy] + 1)) {
            RespawnX = Combat.EnemyX[Enemy];
            RespawnY = Combat.EnemyY[Enemy] + 1;
        }

        // Check West
        if (space_free(Combat.EnemyX[Enemy] - 1,
         Combat.EnemyY[Enemy]) && RespawnX == 0xFF) {
            RespawnX = Combat.EnemyX[Enemy] - 1;
            RespawnY = Combat.EnemyY[Enemy];
        }

        // Check East
        if (space_free(Combat.EnemyX[Enemy] + 1,
         Combat.EnemyY[Enemy]) && RespawnX == 0xFF) {
            RespawnX = Combat.EnemyX[Enemy] + 1;
            RespawnY = Combat.EnemyY[Enemy];
        }

        // Check North
        if (space_free(Combat.EnemyX[Enemy],
         Combat.EnemyY[Enemy] - 1) && RespawnX == 0xFF) {
            RespawnX = Combat.EnemyX[Enemy];
            RespawnY = Combat.EnemyY[Enemy] - 1;
        }

        if (RespawnX == 0xFF) {
            RespawnNum = 0xFF;
        }

        if (RespawnNum != 0xFF) {
        print_line(MW_X, MW_Y+30, 0, "Divides!");
        play_sound(DIVIDE_SOUND);
        Combat.EnemyX[RespawnNum] = RespawnX;
        Combat.EnemyY[RespawnNum] = RespawnY;
        Combat.EnemyHP[RespawnNum] = Combat.EnemyHP[Enemy];
        Combat.Timer = 8;
        advance_combat_state();
        return;
        }
    }

    // Monster teleport
    if ((Combat.EnemyTraits&ENEMY_TELEPORT) && !(rand()&3)) {
        TempX = (ARENA_WIDTH - 1) - Combat.EnemyX[Enemy];
        TempY = (ARENA_HEIGHT - 1) - Combat.EnemyY[Enemy];
        if (space_free(TempX, TempY)) {
            print_line(MW_X, MW_Y+30, 0, "Teleports!");
            play_sound(WIND_SOUND);
            Combat.EnemyX[Enemy] = TempX;
            Combat.EnemyY[Enemy] = TempY;
            Combat.Timer = 8;
            advance_combat_state();
            return;
        }
    }

    // Monster ranged
    if((Combat.EnemyTraits&ENEMY_RANGED) && (rand() % 4)) {
        if((Combat.HeroY == Combat.EnemyY[Enemy]) || 
         (Combat.HeroX == Combat.EnemyX[Enemy])) {
            if(Hero.HP) {
                TmpCoordX = Combat.HeroX;
                TmpCoordY = Combat.HeroY;
            }
        } else if((Combat.DragonY == Combat.EnemyY[Enemy]) || 
         (Combat.DragonX == Combat.EnemyX[Enemy])) {
            if(Hero.DragonHP) {
                TmpCoordX = Combat.DragonX;
                TmpCoordY = Combat.DragonY;
            }
        }

        if ((abs(TmpCoordX - Combat.EnemyX[Enemy]) != 1) && 
         (abs(TmpCoordY - Combat.EnemyY[Enemy]) != 1)) {
            DoRanged = 1; // not melee adjacent
        }

        if ((TmpCoordX > -1) && (DoRanged)) {
            if(TmpCoordY == Combat.EnemyY[Enemy]) {
                if(TmpCoordX > Combat.EnemyX[Enemy]) {
                    Combat.MissileDirection = KEY_RIGHT;
                } else {
                    Combat.MissileDirection = KEY_LEFT;
                }
            } else {
                if(TmpCoordY > Combat.EnemyY[Enemy]) {
                    Combat.MissileDirection = KEY_DOWN;
                } else {
                    Combat.MissileDirection = KEY_UP;
                }
            }
            Combat.MissileActive = 1;
            Combat.HitRoll = (rand()&15) + Combat.EnemyPower;
            Combat.MissileOrigin = 1;   // monster
            Combat.MissileDamage = Combat.EnemyPower;
            Combat.MissileX = Combat.EnemyX[Enemy];
            Combat.MissileY = Combat.EnemyY[Enemy];
            return;
        }
    }

    if((abs(Combat.EnemyX[Enemy] - Combat.HeroX) < 2) && (abs(Combat.EnemyY[Enemy] - Combat.HeroY) < 2)) {
        if((((rand()&15) + Combat.EnemyPower) >= ((Hero.Armor * 2) + 6))
         || (Combat.HeroGrappled && (Combat.HeroGrappleEnemy == Enemy))) {
            Damage = (rand()&enemy_damage[Combat.EnemyPower]) + Combat.EnemyPower;
            if(EnemyTraits[Combat.EnemyNumber]&ENEMY_STRONG) {
                Damage += 2;
            }
            if(EnemyTraits[Combat.EnemyNumber]&ENEMY_GRAPPLE) {
                Damage += 256;  // sentinel for grappled check
            }
            damage_hero(Damage);
            Combat.Timer = 8;
            play_sound(HIT_SOUND);
        } else {
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__MISSED]);
            Combat.Timer = 8;
            play_sound(MISS_SOUND);
        }
        advance_combat_state();
        return;
    } else if((abs(Combat.EnemyX[Enemy] - Combat.DragonX) < 2) &&
     (abs(Combat.EnemyY[Enemy] - Combat.DragonY) < 2) &&
     Hero.DragonHP) {
        if((((rand()&15) + Combat.EnemyPower) >= (Hero.Level + 6))
         || (Combat.DragonGrappled && (Combat.DragonGrappleEnemy == Enemy))) {
            Damage = (rand()&enemy_damage[Combat.EnemyPower]) + Combat.EnemyPower;
            if(EnemyTraits[Combat.EnemyNumber]&ENEMY_STRONG) {
                Damage += 2;
            }
            if(EnemyTraits[Combat.EnemyNumber]&ENEMY_GRAPPLE) {
                Damage += 256;  // sentinel for grappled check
            }
            damage_dragon(Damage);
            Combat.Timer = 8;
            play_sound(HIT_SOUND);
        } else {
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__MISSED]);
            Combat.Timer = 8;
            play_sound(MISS_SOUND);
        }
        advance_combat_state();
        return;
    }

    // Enemy Movement

    HeroDistance = abs(Combat.HeroX - Combat.EnemyX[Enemy]) + abs(Combat.HeroY - Combat.EnemyY[Enemy]);
    DragonDistance = abs(Combat.DragonX - Combat.EnemyX[Enemy]) + abs(Combat.DragonY - Combat.EnemyY[Enemy]);

    if((HeroDistance <= DragonDistance) || !Hero.DragonHP) {
        // Hero Direction 0: Up
        Priority = 0;
        if((Combat.HeroY < Combat.EnemyY[Enemy]) &&
            (Combat.HeroX == Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.HeroY < Combat.EnemyY[Enemy]) {
            Priority = 2;
        }
        Directions[0] = Priority;

        // Hero Direction 1: Up Right
        Priority = 0;
        if((Combat.HeroY < Combat.EnemyY[Enemy]) &&
            (Combat.HeroX > Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.HeroY < Combat.EnemyY[Enemy]) {
            Priority = 1;
        } else if(Combat.HeroX > Combat.EnemyX[Enemy]) {
            Priority = 1;
        }
        Directions[1] = Priority;
            
        // Hero Direction 2: Right
        Priority = 0;
        if((Combat.HeroX > Combat.EnemyX[Enemy]) &&
            (Combat.HeroY == Combat.EnemyY[Enemy])) {
            Priority = 3;
        } else if(Combat.HeroX > Combat.EnemyX[Enemy]) {
            Priority = 2;
        }
        Directions[2] = Priority;

        // Hero Direction 3: Down Right
        Priority = 0;
        if((Combat.HeroY > Combat.EnemyY[Enemy]) &&
            (Combat.HeroX > Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.HeroY > Combat.EnemyY[Enemy]) {
            Priority = 1;
        } else if(Combat.HeroX > Combat.EnemyX[Enemy]) {
            Priority = 1;
        }
        Directions[3] = Priority;
            
        // Hero Direction 4: Down
        Priority = 0;
        if((Combat.HeroY > Combat.EnemyY[Enemy]) &&
            (Combat.HeroX == Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.HeroY > Combat.EnemyY[Enemy]) {
            Priority = 2;
        }
        Directions[4] = Priority;

        // Hero Direction 5: Down Left
        Priority = 0;
        if((Combat.HeroY > Combat.EnemyY[Enemy]) &&
            (Combat.HeroX < Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.HeroY > Combat.EnemyY[Enemy]) {
            Priority = 1;
        } else if(Combat.HeroX < Combat.EnemyX[Enemy]) {
            Priority = 1;
        }
        Directions[5] = Priority;
            
        // Hero Direction 6: Left
        Priority = 0;
        if((Combat.HeroX < Combat.EnemyX[Enemy]) &&
            (Combat.HeroY == Combat.EnemyY[Enemy])) {
            Priority = 3;
        } else if(Combat.HeroX < Combat.EnemyX[Enemy]) {
            Priority = 2;
        }
        Directions[6] = Priority;

        // Hero Direction 7: Up Left
        Priority = 0;
        if((Combat.HeroY < Combat.EnemyY[Enemy]) &&
            (Combat.HeroX < Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.HeroY < Combat.EnemyY[Enemy]) {
            Priority = 1;
        } else if(Combat.HeroX < Combat.EnemyX[Enemy]) {
            Priority = 1;
        }
        Directions[7] = Priority;
    } else {
        // Dragon Direction 0: Up
        Priority = 0;
        if((Combat.DragonY < Combat.EnemyY[Enemy]) &&
            (Combat.DragonX == Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.DragonY < Combat.EnemyY[Enemy]) {
            Priority = 2;
        }
        Directions[0] = Priority;

        // Dragon Direction 1: Up Right
        Priority = 0;
        if((Combat.DragonY < Combat.EnemyY[Enemy]) &&
            (Combat.DragonX > Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.DragonY < Combat.EnemyY[Enemy]) {
            Priority = 1;
        } else if(Combat.DragonX > Combat.EnemyX[Enemy]) {
            Priority = 1;
        }
        Directions[1] = Priority;
            
        // Dragon Direction 2: Right
        Priority = 0;
        if((Combat.DragonX > Combat.EnemyX[Enemy]) &&
            (Combat.DragonY == Combat.EnemyY[Enemy])) {
            Priority = 3;
        } else if(Combat.DragonX > Combat.EnemyX[Enemy]) {
            Priority = 2;
        }
        Directions[2] = Priority;

        // Dragon Direction 3: Down Right
        Priority = 0;
        if((Combat.DragonY > Combat.EnemyY[Enemy]) &&
            (Combat.DragonX > Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.DragonY > Combat.EnemyY[Enemy]) {
            Priority = 1;
        } else if(Combat.DragonX > Combat.EnemyX[Enemy]) {
            Priority = 1;
        }
        Directions[3] = Priority;
            
        // Dragon Direction 4: Down
        Priority = 0;
        if((Combat.DragonY > Combat.EnemyY[Enemy]) &&
            (Combat.DragonX == Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.DragonY > Combat.EnemyY[Enemy]) {
            Priority = 2;
        }
        Directions[4] = Priority;

        // Dragon Direction 5: Down Left
        Priority = 0;
        if((Combat.DragonY > Combat.EnemyY[Enemy]) &&
            (Combat.DragonX < Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.DragonY > Combat.EnemyY[Enemy]) {
            Priority = 1;
        } else if(Combat.DragonX < Combat.EnemyX[Enemy]) {
            Priority = 1;
        }
        Directions[5] = Priority;
            
        // Dragon Direction 6: Left
        Priority = 0;
        if((Combat.DragonX < Combat.EnemyX[Enemy]) &&
            (Combat.DragonY == Combat.EnemyY[Enemy])) {
            Priority = 3;
        } else if(Combat.DragonX < Combat.EnemyX[Enemy]) {
            Priority = 2;
        }
        Directions[6] = Priority;

        // Dragon Direction 7: Up Left
        Priority = 0;
        if((Combat.DragonY < Combat.EnemyY[Enemy]) &&
            (Combat.DragonX < Combat.EnemyX[Enemy])) {
            Priority = 3;
        } else if(Combat.DragonY < Combat.EnemyY[Enemy]) {
            Priority = 1;
        } else if(Combat.DragonX < Combat.EnemyX[Enemy]) {
            Priority = 1;
        }
        Directions[7] = Priority;
    }

    CurrentPriority = 3;

    while(CurrentPriority) {
        StartMove = rand() & 7;
        CurrentDirection = StartMove;
        do {
            if(Directions[CurrentDirection] == CurrentPriority) {
                NewX = Combat.EnemyX[Enemy];
                NewY = Combat.EnemyY[Enemy];
                switch(CurrentDirection) {
                    case 0:
                        NewY--;
                        break;
                    case 1:
                        NewX++;
                        NewY--;
                        break;
                    case 2:
                        NewX++;
                        break;
                    case 3:
                        NewX++;
                        NewY++;
                        break;
                    case 4:
                        NewY++;
                        break;
                    case 5:
                        NewX--;
                        NewY++;
                        break;
                    case 6:
                        NewX--;
                        break;
                    case 7:
                        NewX--;
                        NewY--;
                }
                if((NewX < ARENA_WIDTH) && (NewY < ARENA_HEIGHT) &&
                space_free(NewX, NewY)) {
                    Combat.EnemyX[Enemy] = NewX;
                    Combat.EnemyY[Enemy] = NewY;
                    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__MOVED]);
                    Combat.Timer = 5;
                    advance_combat_state();
                    return;
                }
            }
            CurrentDirection++;
            if(CurrentDirection == 8) {
                CurrentDirection = 0;
            }
        } while(CurrentDirection != StartMove);
        CurrentPriority--;
    }

    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__PASS]);
    Combat.Timer = 5;
    advance_combat_state();
}

void do_cast_ray() {
    int Direction;

    Menu.Active = 0;

    if(!deduct_spell_points(5)) {
        return;
    }
    
    if(!Combat.Active) {
        if(check_new_spell()) {
            return;
        }
        play_sound(CAST_SOUND);
        flash_effect();
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
        Menu.Active = 0;
        return;
    }


    Direction = which_direction();
    if(!Direction) {
        return;
    }
    play_sound(CAST_SOUND);
    Combat.MissileActive = 1;
    Combat.MissileDirection = Direction;
    Combat.MissileOrigin = 0;   // player/dragon
    Combat.HitRoll = (rand() & 15) + (Hero.Dex / 5) + (Hero.Level / 2);
    Combat.MissileX = Combat.HeroX;
    Combat.MissileY = Combat.HeroY;
    Combat.MissileType = 1;
    Combat.HitRoll = 127;
    Combat.MissileDamage = ((Hero.Int / 5) / 2) + 1;
//    advance_combat_state();
}

void do_cast_swap() {
    int TmpPosX, TmpPosY;

    Menu.Active = 0;

    if(!deduct_spell_points(1)) {
        return;
    }

    if(!Combat.Active) {
        if(check_new_spell()) {
            return;
        }
        play_sound(CAST_SOUND);
        flash_effect();
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
        Menu.Active = 0;
        return;
    }

    play_sound(CAST_SOUND);

    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__SWAPPED]);
    TmpPosX = Combat.HeroX;
    TmpPosY = Combat.HeroY;
    Combat.HeroX = Combat.DragonX;
    Combat.HeroY = Combat.DragonY;
    Combat.DragonX = TmpPosX;
    Combat.DragonY = TmpPosY;
    Combat.Timer = 8;
    advance_combat_state();
}

void do_cast_sun() {
    Menu.Active = 0;

    if(!deduct_spell_points(10)) {
        return;
    }

    play_sound(CAST_SOUND);

    if(!Combat.Active || !Flags.InDungeon) {
        flash_effect();
        if(check_new_spell()) {
            return;
        }

        if(Flags.InDungeon) {
            if(!Dungeon.Light) {
                print_line(MW_X, MW_Y+30, 0, "The dungeon is lit!");
                CurrentDTiles = (uint8_t *)DTilesVisible;
                invalidate_view();
            } else {
                print_line(MW_X, MW_Y+30, 0, "The dungeon gets brighter!");
            }
            if(Dungeon.Light > 191) {
                Dungeon.Light = 255;
            } else {
                Dungeon.Light += 64;
            }
            Flags.MessageActive = 1;
            return;
        }
    }

    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
    Menu.Active = 0;
    Flags.MessageActive = 1;
    if(Combat.Active) {
        Combat.Timer = 8;
        advance_combat_state();
    }
}

void do_cast_heal() {
    uint8_t HP = (Hero.Level * 2) + (Hero.Int / 5) + 2;
    Menu.Active = 0;

    if(!deduct_spell_points(10)) {
        return;
    }

    if(!Combat.Active) {
        if(check_new_spell()) {
            return;
        }
        play_sound(CAST_SOUND);
        flash_effect();
        if (Hero.HP < Hero.MHP) {
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__HEALED]);
            Hero.HP += HP;
            if (Hero.HP > Hero.MHP) {
                Hero.HP = Hero.MHP;
            }
            draw_stats();
        } else { 
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
        }
        Menu.Active = 0;
        Flags.MessageActive = 1;
        return;
    }

    if(Hero.HP == Hero.MHP) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
        draw_stats();
        if(Combat.Active) {
            Combat.Timer = 8;
            advance_combat_state();
        }
        return;
    }
    Hero.HP += (Hero.Int / 5) + (Hero.Level * 2);
    if(Hero.HP > Hero.MHP) {
        Hero.HP = Hero.MHP;
    }

    print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__HEALED]);
    draw_stats();
    if(Combat.Active) {
        Combat.Timer = 8;
        advance_combat_state();
    }
}

void do_cast_hop() {
    Menu.Active = 0;

    if(!deduct_spell_points(10)) {
        return;
    }
    
    if(!Combat.Active) {
        if(check_new_spell()) {
            return;
        }
    }
}

void do_cast_zap() {
    int Direction;

    Menu.Active = 0;

    if(!deduct_spell_points(10)) {
        return;
    }

    if(!Combat.Active) {
        if(check_new_spell()) {
            return;
        }
        play_sound(CAST_SOUND);
        flash_effect();
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOTHING_MUCH_HAPPENS]);
        Menu.Active = 0;
        return;
    }

    Direction = which_direction();
    if(!Direction) {
        return;
    }
    Combat.MissileActive = 1;
    Combat.MissileDirection = Direction;
    Combat.MissileOrigin = 0;   // player/dragon
    Combat.HitRoll = (rand() & 15) + (Hero.Dex / 5) + (Hero.Level / 2);
    play_sound(CAST_SOUND);
    Combat.MissileX = Combat.HeroX;
    Combat.MissileY = Combat.HeroY;
    Combat.MissileType = 1;
    Combat.HitRoll = 127;
    Combat.MissileDamage = (Hero.Int / 5) + 2;
    advance_combat_state();
}

int deduct_spell_points(int Points) {
    if(Hero.SP < Points) {
        print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__NOT_ENOUGH_SPELL_POINTS]);
        if(Combat.Active) {
            Combat.Timer = 8;
            advance_combat_state();
        } else {
            Flags.MessageActive = 1;
        }
        return 0;
    }

    Hero.SP -= Points;
    draw_stats();
    return 1;
}


int check_new_spell() {
    int SpellLearned = 0;
    int SpellMask;

    switch(Hero.X) {
        case 53:    // Sun spell
            if(Hero.Y == 21) {
                SpellLearned = 3;
                SpellMask = SUN_SPELL;
            }
            break;
        case 44:    // Swap spell
            if(Hero.Y == 52) {
                SpellLearned = 2;
                SpellMask = SWAP_SPELL;
            }
            break;
        case 34:    // Heal spell
            if(Hero.Y == 9) {
                SpellLearned = 4;
                SpellMask = HEAL_SPELL;
            }
            break;
        case 28:    // Hop spell
            if(Hero.Y == 55) {
                SpellLearned = 5;
                SpellMask = HOP_SPELL;
            }
            break;
        case 54:    // Zap spell
            if(Hero.Y == 57) {
                SpellLearned = 6;
                SpellMask = ZAP_SPELL;
            }
            break;
    }
    if(!SpellLearned || (Hero.SpellsKnown&SpellMask)) {
        return 0;
    }
    print_line_formatted(MW_X, MW_Y+30, 0, Messages[MESSAGE__YOU_LEARN_A_NEW_SPELL], SpellName[SpellLearned - 1]);
    Hero.SpellsKnown |= SpellMask;
    flash_effect();
    save_game();
    return SpellLearned;
}

void CheckEncountersAndStatus() {
    uint8_t CurrentTile = CurrentMap[(Game.MapWidth * Hero.Y) + Hero.X];
    Flags.Moved = 0;

    if (Game.Pause || Flags.MessageActive) {
        return;
    }

    if (Flags.InDungeon) {
        if (dungeon_triggers()) {
            return;
        }
    } else {
        if (check_triggers()) {
            return;
        }
    }

    if (Hero.CurrentMap) {
        return;
    }

    if (CurrentTile == BRIDGE_TILE) {
        if ((Hero.HP < Hero.MHP) && (Hero.X != 43) && (rand()&1)) {
            start_combat();
            return;
        }
    }

    if (CurrentTile == LAVA_TILE && !Hero.FireRitual) {
        play_sound(HIT_SOUND);
        flash_effect();
        if (Hero.HP > 20) {
            Hero.HP -= 20;
            print_line(MW_X, MW_Y+30, 0, "Lava!");
            print_line(MW_X+48, MW_Y+30, 1, ">>");
            draw_stats();
            Game.Pause = 0xFF;
        } else {
            print_line(MW_X, MW_Y+30, 0, "Lava! You die!");
            Hero.HP = 0;
            Game.Pause = 10;
            draw_stats();
        }
        return;
    }

    if (Hero.SP < Hero.MSP) {
        Hero.SP++;
    }

    if ((Game.Turns&7) != 4) {
        return;
    }

    // Check food, poison, etc first, and return if there
    // is a message. If not, check for outdoor/dungeon
    // encounter.

    if (Game.Turns&16) {
        if ((Hero.Status) == STATUS_GOOD && Hero.Food && (Hero.HP < Hero.MHP)) {
            Hero.HP++;
        }
    }

    if (Hero.Status == STATUS_POISONED) {
        play_sound(HIT_SOUND);
        flash_effect();
        
        if (Hero.HP > 2) {
            Hero.HP -= 2;
            print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__POISONED]);
            print_line(MW_X+80, MW_Y+30, 1, ">>");
            Game.Pause = 0xFF;
        } else {
            Hero.HP = 0;
            print_line_formatted(MW_X, MW_Y+30, 0, "%s You die!", Messages[MESSAGE__POISONED]);
            Game.Pause = 10;
        }

        if (Hero.Food && (Game.Turns&32)) {
            Hero.Food--;
        }
        draw_stats();
        return;
    }

    if (Game.Turns&32) {
        if (Hero.Food) {
            Hero.Food--;
        } else {
            play_sound(HIT_SOUND);
            flash_effect();
            if (Hero.HP > 1) {
                print_line(MW_X, MW_Y+30, 0, Messages[MESSAGE__OUT_OF_FOOD]);
                print_line(MW_X+104, MW_Y+30, 1, ">>");
                Game.Pause = 0xFF;
                Hero.HP--;
            } else {
                Hero.HP = 0;
                print_line_formatted(MW_X, MW_Y+30, 0, "%s You die!", Messages[MESSAGE__OUT_OF_FOOD]);
                Game.Pause = 10;
            }

            draw_stats();
            return;
        }
    }
    
    if (Menu.Active || (rand()&3)) {
        return;
    }

    if (Flags.InDungeon) {
        if(rand()&3) {
            start_combat();
        }
    } else {
        if(rand()&1) {
            start_combat();
        }
    }
}

void do_poison() {
    Hero.HealPotions = 7;
    Hero.CurePotions = 7;
    Hero.DisguiseDust = 1;
    Hero.HomingGem = 1;
    print_line(MW_X, MW_Y+30, 0, "Restocked!");
    Flags.MessageActive = 1;
}


int main(int argc, char *argv[]) {
    int GetChar, Count, CountX, CountY, TmpX, TmpY, Mode;
    FILE *CurrentFontFile;
    int CurrentFrame = 3;
    time_t t;

    srand((unsigned) time(&t));
    prev_int_1c = _dos_getvect( 0x1c );
    _dos_setvect( 0x1c, timer_rtn );

    set_timer(0x4DAE);  // 60hz

    Count = 1;

    while(Count < argc) {
        if(strlen(argv[Count]) == 1) {
            parse_option(argv[Count][0]);
        }
        Count++;
    }

    if(Flags.Monochrome) {
        Mode = 6;
    } else {
        if(Flags.Composite) {
            Mode = 4;
            CurrentPalette = COMPOSITE_PALETTE;
        } else {
            Mode = 5;
        }
    }

    if (!(MyScreen = scr_create(Mode))) {
        oh_shit("Unable to create screen.\n");
    }

//   outp (0x3d8, 0x0E);
//   outp (0x3d9, 0x90);

    MyKeyHandler = new_KeyHandler();

    for(CountX = 0; CountX < VIEWPORT_WIDTH; CountX++) {
        for(CountY = 0; CountY < VIEWPORT_HEIGHT; CountY++) {
            viewport[CountX][CountY] = 0;
        }
    }

    ClearText = bit_create(304, 8);
    bit_ink(ClearText, 0);
    bit_box(ClearText, 0, 0, 304, 8);
    bit_ink(ClearText, 3);

    if(!(CurrentFontFile = fopen("default.fnt", "rb"))) {
        oh_shit("Can't open \"default.fnt\"");
    }

    CurrentFont = malloc(16 * NUM_CHARS);

    if(fread(CurrentFont, 2, (8 * NUM_CHARS), CurrentFontFile) != (8 * NUM_CHARS)) {
        oh_shit("\"default.fnt\" file is corrupt.");
    }

    fclose(CurrentFontFile);  

//    generate_character();
    load_game();

//    Hero.HomingGem = 1;

    Game.Turns = 0;

//    Hero.CurrentMap = FREEHAVEN_MAP;

    load_display_gui();

    load_map(Hero.CurrentMap);

    load_tiles();
    ViewportBuffer = bit_create(176, 144);
    if(!Hero.CurrentMap) {
        update_world_map_at(Hero.X - 5, Hero.Y - 4);
    } else {
        update_town_map_at(Hero.X - 5, Hero.Y - 4);
    }
    do_vision();

    invalidate_view();

    display_map();

    draw_stats();

    while(SaveKey != KEY_Q) {
        while(abs(ClockTicks-PrevTicks) < 2) {
        }
        PrevTicks = ClockTicks;
        CurrentFrame++;
        if(CurrentFrame > 255) {
            CurrentFrame = 0;
        }

        if(Game.FlashTimer) {
            flash_effect();
        }

        switch(CurrentFrame&0x3) {
            case 0:
                LogicalTicks++;
                if (Game.Pause && Game.Pause != 0xFF) {
                    Game.Pause--;
                    if (!Game.Pause && (!Hero.HP)) {
                        do_death();
                    }
                }
                if(SaveKey == KEY_P) {
                    CurrentPalette++;
                    if(CurrentPalette > 5) {
                        CurrentPalette = 0;
                    }
                    scr_palette (MyScreen, CurrentPalette, 0);
                    SaveKey = 0;
                }
                if(!(CurrentFrame&0x15)) {
                    if(!(CurrentFrame&0x31)) {
                        CurrentTiles = tile_mapping;
                        if (Dungeon.Light) {
                            CurrentDTiles = (uint8_t *)DTilesVisible;
                        } else {
                            CurrentDTiles = (uint8_t *)DTilesDark;
                        }
                        Flags.Flipped = 1;
                    } else {
                        CurrentTiles = tile_mapping_alt;
                        if (Dungeon.Light) {
                            CurrentDTiles = (uint8_t *)DTilesVisibleAlt;
                        } else {
                            CurrentDTiles = (uint8_t *)DTilesDarkAlt;
                        }
                        Flags.Flipped = 1;
                    }
                }
                if(!Menu.Active && !Game.Pause) {
                    if(Flags.InDungeon) {
                        CheckMoveHeroDungeon();
                    } else {
                        CheckMoveHero();
                    }
                }
                break;
            case 1:
                if(!Combat.Active) {
                    if(!Game.FlashTimer && !Game.Pause) {
                        if(Flags.InDungeon) {
                            update_dungeon_map_at(Dungeon.X - 2, Dungeon.Y - 2);
                        } else {
                            if(!Hero.CurrentMap) {
                                update_world_map_at(Hero.X - 5, Hero.Y - 4);
                            } else {
                                update_town_map_at(Hero.X - 5, Hero.Y - 4);
                            }
                        }
                    }
                } else {
                    if(!Game.FlashTimer) {
                        load_arena(Combat.Arena);
                    }
                }
                if(Menu.Active && !Game.FlashTimer) {
                    check_update_menu();
                }
                if(check_button_press() && !Game.FlashTimer) {
                    if (Game.Pause == 0xFF) {
                        Game.Pause = 0;
                        clear_text_window();
                        break;
                    }
                    if(!Menu.Active) {
                        if(Flags.MessageActive) {
                            clear_text_window();
                        } else {
                            create_menu();
                        }
                    } else {
                        activate_menu_item();
                    }
                }
                break;
            case 2:
                if(!Combat.Active && !Flags.InDungeon) {
                    do_vision();
                } else if(!Combat.Active && Flags.InDungeon) {
                    do_dungeon_vision();
                }
                break;
            case 3:
                if(Flags.InDungeon && !Combat.Active) {
                    display_dungeon_map();
                } else {
                    display_map();
                }
                if(Flags.Moved && !Combat.Active) {
                    CheckEncountersAndStatus();
                    draw_stats();
                }
                break;
        }
    }

    cleanup();
    return 0;
}