#include "gametxt.h"
// #include "penult.h"

const char *Armor[] = {
    "None",
    "Leather",
    "Chain",
    "Plate",
    "M. Plate",
    "Dragon"
};

const char *Melee[] = {
    "Staff",
    "Mace",
    "Axe",
    "Sword",
    "M. Sword",
    "S.Hammer"
};

const char *Ranged[] = {
    "None",
    "Sling",
    "Bow",
    "M. Bow",
    "S.Hammer"
};

const char *Status[] = {
    "Good",
    "Poisoned",
    "Dead"
};

const char *Gender[] = {
    "Female",
    "Male",
    "Other"
};

const char *SpellName[] = {
    "Ray",
    "Swap",
    "Sun",
    "Heal",
    "Teleport",
    "Zap"
};

const char *Wind[] = {
    "North",
    "East",
    "South",
    "West",
    "Calm"
};

const char *DungeonName[] = {
    "Phoenix",
    "Enchantment",
    "Secrets",
    "Passage",
};

const char AltWall[] = {
    {0},
    {2},
    {0},
    {4},
    {6},
    {7},
    {16},
    {9},
    {11},
    {13},
    {15},
    {18}
};

const char AltWallSecret[] = {
    {1},
    {3},
    {1},
    {5},
    {1},
    {8},
    {17},
    {10},
    {12},
    {14},
    {1},
    {19}
};

const char EnemyToTile[] = {
    TROLL_TILE_NUMBER,
    DARKLING_TILE_NUMBER,
    SHADOW_RAT_TILE_NUMBER,
    GOBLIN_TILE_NUMBER,
    SKELETON_TILE_NUMBER,
    FIRE_BEETLE_TILE_NUMBER,
    OGRE_TILE_NUMBER,
    SHADOW_ORB_TILE_NUMBER,
    HEAD_TILE_NUMBER,
    GIANT_TILE_NUMBER,
    DEATH_BUG_TILE_NUMBER,
    DARK_DRAKE_TILE_NUMBER,
    NIGHT_WISP_TILE_NUMBER,
    GLOOM_VIPER_TILE_NUMBER,
    UNSEELIE_TILE_NUMBER,
    TITAN_TILE_NUMBER,
    PIRATE_TILE_NUMBER,
    SALAMANDER_TILE_NUMBER,
    DEMON_GUARD_TILE_NUMBER,
    EARTH_SHADE_TILE_NUMBER,
    WATER_SHADE_TILE_NUMBER,
    FIRE_SHADE_TILE_NUMBER,
    AIR_SHADE_TILE_NUMBER,
    SEA_SERPENT_TILE_NUMBER,
    WATER_WIGHT_TILE_NUMBER,
    GIANT_SQUID_TILE_NUMBER,
    ZOMBIE_TILE_NUMBER,
    DIRE_SPIDER_TILE_NUMBER,
    MINOTAUR_TILE_NUMBER,
    HELL_RABBIT_TILE_NUMBER,
    SLIME_TILE_NUMBER,
    ROPER_TILE_NUMBER,
    VAMPIRE_BAT_TILE_NUMBER,
    GHOST_TILE_NUMBER,
    MUMMY_TILE_NUMBER,
    ICE_DEVIL_TILE_NUMBER,
    AMOEBA_TILE_NUMBER,
    DEMON_TILE_NUMBER,
    LICH_TILE_NUMBER,
    DRAGON_MONSTER_TILE_NUMBER
};

const char EnemyPower[] = {
    3,   // troll
    1,   // darkling
    1,   // shadow rat
    1,   // goblin
    2,   // skeleton
    2,   // fire beetle
    3,   // ogre
    3,   // shadow orb
    3,   // head
    4,   // giant
    4,   // death bug
    5,   // dark drake
    4,   // night wisp
    5,   // gloom viper
    4,   // unseelie
    6,   // titan
    5,   // pirate
    4,   // salamander
    6,   // demon guard
    7,   // earth shade
    7,   // water shade
    7,   // fire shade
    7,   // air shade
    4,   // sea serpent
    3,   // water wight
    3,   // giant squid
    2,	 // zombie
    2,	 // spider
    3,	 // minotaur
    3,   // rabbit
    3,	 // slime
    3,	 // roper
    3,   // vampire bat
    3,   // ghost
    4,   // mummy
    4,   // ice devil
    5,   // amoeba
    5,   // demon
    6,   // lich
    7    // dragon
};

const char gold_range[] = {
    1,     // Shouldn't occur
    15,
    15,
    31,
    31,
    63,
    63,
    63,
    63,
    63,
    63,
    63,
    63
};

const char enemy_damage[] = {
    1, // Nothing
    1, // Darkling/Goblin
    1, // Skeleton/Fire beetle
    3, // Ogre/Minotaur/Head
    7, // Giant/Mummy
    7, // pirate/amoeba/demon
    15, // lich/demon guard
    15, // dragon/shades
    15, // something else crazy
    31, // something epic
    31 // something even more epic
};


const char EnemyStartX[] = {
    4, 6, 1, 9
};

const char EnemyStartY[] = {
    2, 2, 1, 1
};

const char TrollStartX[] = {
    2, 4, 6, 8
};

const char DungeonStartX[] = {
    2, 3, 7, 8
};

const char DungeonStartY[] = {
    2, 2, 2, 2
};

const char WaterStartX[] = {
    2, 7, 4, 5
};

const char WaterStartY[] = {
    1, 1, 8, 8
};

const char PirateStartX[] = {
    4, 5, 2, 7
};

const char PirateStartY[] = {
    2, 2, 1, 1
};

const char EnemyHPBase[] = {
    1,   // Nothing
    1,   // Darkling/Goblin
    1,   // Skeleton/Fire beetle
    3,   // Ogre/Minotaur/Head
    7,   // Giant/Mummy
    7,   // pirate/amoeba/demon
    15,   // lich/demon guard
    15,   // dragon/shades
    15,   // something else crazy
    31,   // something epic
    31   // something even more epic
};

const char MenuText[] = {
    MESSAGE__OUTDOOR_MENU,
    MESSAGE__TOWN_MENU,
    MESSAGE__YES_NO,
    MESSAGE__HERO_COMBAT_MENU,
    MESSAGE__DRAGON_COMBAT_MENU,
    0,
    MESSAGE__DUNGEON_MENU
};

const char MenuPrompt[] = {
    STATUS__ACTIONS,
    STATUS__ACTIONS,
    0,
    STATUS__ACTIONS,
    STATUS__ACTIONS,
    0,
    STATUS__ACTIONS
};

const char MenuChoices[] = {
    4,
    4,
    2,
    5,
    4,
    0,
    5
};

const char OutdoorMenuPos[] = {0, 5, 9, 19};
const char TownMenuPos[] = {0, 5, 10, 14};
const char YesNoMenuPos[] = {0, 4};
const char HeroCombatMenuPos[] = {0, 7, 14, 19, 23};
const char DragonMenuPos[] = {0, 5, 12, 17};
const char DungeonMenuPos[] = {0, 5, 10, 14, 24};

const char *MarkerPos[] = {
    OutdoorMenuPos,
    TownMenuPos,
    YesNoMenuPos,
    HeroCombatMenuPos,
    DragonMenuPos,
    0,
    DungeonMenuPos
};

//          Ranged
//          |Poison
//          ||Respawn
//          |||Strong
//          ||||Grapple
//          |||||Teleport
//          ||||||Fire
//          |||||||Incorporal


const char EnemyTraits[] = {
    0x0,
    0x0,
    0x0,
    ENEMY_RANGED,
    0x0,
    ENEMY_RANGED|ENEMY_FIRE,
    0x0,
    ENEMY_RESPAWN,
    ENEMY_RANGED|ENEMY_TELEPORT,
    ENEMY_STRONG,
    ENEMY_POISON,
    ENEMY_RANGED,
    ENEMY_INCORPORAL|ENEMY_TELEPORT,
    ENEMY_POISON|ENEMY_GRAPPLE,
    ENEMY_RANGED|ENEMY_RESPAWN|ENEMY_TELEPORT,
    ENEMY_RANGED|ENEMY_STRONG,
    ENEMY_RANGED,
    ENEMY_FIRE|ENEMY_TELEPORT,
    ENEMY_STRONG|ENEMY_TELEPORT,
    ENEMY_RANGED|ENEMY_STRONG,
    ENEMY_RESPAWN|ENEMY_STRONG,
    ENEMY_FIRE|ENEMY_INCORPORAL,
    ENEMY_STRONG,
    ENEMY_RANGED|ENEMY_STRONG|ENEMY_GRAPPLE,
    ENEMY_RANGED|ENEMY_TELEPORT,
    ENEMY_RANGED|ENEMY_POISON,
    0x0,
    ENEMY_POISON,
    ENEMY_STRONG,
    ENEMY_RANGED|ENEMY_FIRE,
    0x0,
    ENEMY_GRAPPLE,
    0x0,
    ENEMY_INCORPORAL,
    ENEMY_POISON,
    0x0,
    ENEMY_RESPAWN,
    ENEMY_RANGED|ENEMY_POISON|ENEMY_FIRE,
    ENEMY_RESPAWN|ENEMY_TELEPORT,
    ENEMY_RANGED|ENEMY_STRONG|ENEMY_INCORPORAL
};

const char plains_arena[9][11] = {
    {9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 9},
    {9, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    {9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    {9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 9},
    {9, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9}
};

const char forest_arena[9][11] = {
    {9,9,9,9,8,9,9,8,8,9,9},
    {9,9,8,8,8,8,8,8,9,9,9},
    {8,8,8,8,9,8,8,8,9,8,8},
    {8,9,9,9,9,8,8,8,8,8,8},
    {8,9,9,9,9,8,8,8,8,8,8},
    {8,9,9,9,9,8,8,8,8,8,8},
    {9,9,9,9,8,8,9,9,9,9,8},
    {9,9,9,9,8,8,8,9,9,9,9},
    {8,8,8,9,9,8,8,8,8,9,9}
};

const char heavy_forest_arena[9][11] = {
    {15,15,15,15,8,8,15,15,15,15,15},
    {15,15,15,8,8,8,8,8,8,15,8},
    {15,15,15,8,15,15,15,15,8,8,8},
    {15,15,8,8,8,15,15,15,8,8,8},
    {15,15,8,8,8,15,15,15,8,8,8},
    {15,15,8,8,8,15,15,15,8,8,8},
    {8,8,8,8,8,15,8,8,8,15,15},
    {8,8,8,15,15,8,8,8,15,15,15},
    {8,15,15,15,15,8,15,15,15,15,15}
};

const char bridge_arena[9][11] = {
    {3,18,22,22,22,22,22,22,22,18,3},
    {3,18,22,22,22,22,22,22,22,18,3},
    {3,18,22,22,22,22,22,22,22,18,3},
    {3,18,22,22,22,22,22,22,22,18,3},
    {3,18,22,22,22,22,22,22,22,18,3},
    {3,18,22,22,22,22,22,22,22,18,3},
    {3,18,22,22,22,22,22,22,22,18,3},
    {3,18,22,22,22,22,22,22,22,18,3},
    {3,18,22,22,22,22,22,22,22,18,3}
};

const char lava_bridge_arena[9][11] = {
    {2,95,89,89,89,89,89,89,89,95,2},
    {2,95,89,89,89,89,89,89,89,95,2},
    {2,95,89,89,89,89,89,89,89,95,2},
    {2,95,89,89,89,89,89,89,89,95,2},
    {2,95,89,89,89,89,89,89,89,95,2},
    {2,95,89,89,89,89,89,89,89,95,2},
    {2,95,89,89,89,89,89,89,89,95,2},
    {2,95,89,89,89,89,89,89,89,95,2},
    {2,95,89,89,89,89,89,89,89,95,2}
};


const char sand_arena[9][11] = {
    {8,8,7,7,7,7,7,7,7,8,8},
    {8,8,7,7,7,7,7,7,7,7,8},
    {8,7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7,7},
    {8,8,7,7,7,7,7,7,7,8,8},
    {8,7,7,7,7,7,7,7,7,8,8}
};

const char ship_arena[9][11] = {
    { 4, 4, 4,89,89,89,89, 4, 4, 4, 3},
    { 4,89,89,89,89,89,89,89,89,89, 4},
    { 4,89,89,89,89,89,89,89,89,89, 4},
    { 4, 4, 4,89,89,89,89, 4, 4, 4, 3},
    { 3, 3, 3, 6, 6, 6, 6, 6, 3, 3, 3},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}
};

const char city_arena[9][11] = {
    {8,8,8,8,8,8,8,8,8,8,8},
    {8,8,9,8,8,8,8,8,9,8,8},
    {20,20,20,20,20,20,20,20,20,20,20},
    {20,20,20,20,20,20,20,20,20,20,20},
    {20,20,20,20,20,20,20,20,20,20,20},
    {20,20,20,20,20,20,20,20,20,20,20},
    {20,20,20,20,20,20,20,20,20,20,20},
    {8,8,9,8,8,8,8,8,9,8,8},
    {8,8,8,8,8,8,8,8,8,8,8}
};

const char lava_arena[9][11] = {
    {2,7,2,2,7,7,2,2,2,7,7},
    {7,7,2,2,2,2,2,2,2,2,2},
    {7,2,2,2,7,7,2,2,2,2,2},
    {2,2,2,7,7,7,2,2,2,7,2},
    {2,2,2,7,7,7,2,2,2,7,2},
    {2,2,2,7,7,7,2,2,2,7,2},
    {2,2,2,2,7,7,2,2,2,2,2},
    {2,7,2,2,2,2,2,2,2,7,7},
    {7,2,2,2,2,7,2,2,2,7,2}
};

const char castle_arena[9][11] = {
    {22,22,22,22,22,22,22,22,22,22,22},
    {22,22,22,22,22,22,22,22,22,22,22},
    {22,22,22,22,22,22,22,22,22,22,22},
    {22,22,22,22,22,22,22,22,22,22,22},
    {22,22,22,22,22,22,22,22,22,22,22},
    {22,22,22,22,22,22,22,22,22,22,22},
    {22,22,22,22,22,22,22,22,22,22,22},
    {22,22,22,22,22,22,22,22,22,22,22},
    {22,22,22,22,22,22,22,22,22,22,22}
};

const char water_arena[9][11] = {
    { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
    { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
    { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
    { 4, 4, 4,89,89,89,89, 4, 4, 4, 3},
    { 4,89,89,89,89,89,89,89,89,89, 4},
    { 4,89,89,89,89,89,89,89,89,89, 4},
    { 4, 4, 4,89,89,89,89, 4, 4, 4, 3},
    { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
    { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
};

const char ship_ship_arena[9][11] = {
    { 4, 4, 4,89,89,89,89, 4, 4, 4, 3},
    { 4,89,89,89,89,89,89,89,89,89, 4},
    { 4,89,89,89,89,89,89,89,89,89, 4},
    { 4, 4, 4,89,89,89,89, 4, 4, 4, 3},
    { 3, 3, 3, 6, 6, 6, 6, 3, 3, 3, 3},
    { 4, 4, 4,89,89,89,89, 4, 4, 4, 3},
    { 4,89,89,89,89,89,89,89,89,89, 4},
    { 4,89,89,89,89,89,89,89,89,89, 4},
    { 4, 4, 4,89,89,89,89, 4, 4, 4, 3},
};

const char dungeon_arena[9][11] = {
    {17,17,17,17,17,17,17,17,17,17,17},
    {17,95,95,95,95,95,95,95,95,95,17},
    {17,95, 7, 7, 7, 7, 7, 7, 7,95,17},
    {17,95, 7, 7, 7, 7, 7, 7, 7,95,17},
    {17,95, 7, 7, 7, 7, 7, 7, 7,95,17},
    {17,95, 7, 7, 7, 7, 7, 7, 7,95,17},
    {17,95, 7, 7, 7, 7, 7, 7, 7,95,17},
    {17,95,95,95,95,95,95,95,95,95,17},
    {17,17,17,17,17,17,17,17,17,17,17}
};

const char *Arena[] = {
    {plains_arena},
    {forest_arena},
    {heavy_forest_arena},
    {bridge_arena},
    {sand_arena},
    {ship_arena},
    {city_arena},
    {lava_arena},
    {castle_arena},
    {water_arena},
    {ship_ship_arena},
    {dungeon_arena},
    {lava_bridge_arena}
};


const short NPCText[] = {
    {0},    // Queen Avaline
    {MESSAGE__RUFUS_TALK},
    {MESSAGE__EZIN_THE_SAGE_TALK},
    {MESSAGE__DALIN_THE_DWARF_TALK},
    {MESSAGE__GUARD_TALK},
    {MESSAGE__IDA_THE_JESTER_TALK},
    {MESSAGE__SWORDSMAN_PENGENAR_TALK},
    {0},  // GROCER
    {MESSAGE__ROBIN_THE_BARFLY_TALK},
    {MESSAGE__RANDALL_THE_LONER_TALK},
    {MESSAGE__ALISTAIR_THE_ELDER_TALK},
    {MESSAGE__GUARDSMAN_TAYLOR_TALK},
    {MESSAGE__EVA_THE_FIGHTER_TALK},
    {0},  // SLING VENDOR
    {0},  // LEATHER VENDOR
    {MESSAGE__ACADIA_BARTENDER_TALK},
    {MESSAGE__MAYOR_WADE_TALK},
    {MESSAGE__CASTLE_BARTENDER_TALK},
    {0},  // HEALER
    {MESSAGE__MYSTERIOUS_HERMIT_TALK},
    {MESSAGE__BAERN_THE_SMITH_TALK},
    {MESSAGE__CLAN_CHIEF_TRAVOK_TALK},
    {MESSAGE__STONEHEART_BARTENDER_TALK},
    {MESSAGE__AMBER_THE_JUVENILE_TALK},
    {MESSAGE__VISTRA_THE_SMITH_TALK},
    {MESSAGE__RUTGAR_THE_MINER_TALK},
    {MESSAGE__BORIN_THE_MINER_TALK},
    {MESSAGE__SOLDIER_GADORA_TALK},
    {0},  // PLATE VENDOR
    {MESSAGE__FORGEGURU_RISWYNN_TALK},
    {0},  // AXE VENDOR
    {0},  // MACE VENDOR
    {MESSAGE__GROVE_WARDEN_GLYNN_TALK},
    {0},  // BOW VENDOR
    {MESSAGE__ORACLE_GUARD_TALK},
    {MESSAGE__GILES_THE_RANGER_TALK},
    {MESSAGE__NESTA_THE_RANGER_TALK},
    {MESSAGE__NIGEL_THE_LOST_TALK},
    {MESSAGE__ELENA_THE_YOUTH_TALK},
    {MESSAGE__TERRIC_THE_SAGE_TALK},
    {MESSAGE__OAK_BARTENDER_TALK},
    {0},  // HEALING POTION VENDOR
    {MESSAGE__MAYOR_BALDRIC_TALK},
    {MESSAGE__WATERS_BARTENDER_TALK},
    {MESSAGE__DECKHAND_JORDAN_TALK},
    {MESSAGE__FRIAR_HENRY_TALK},
    {0},  // SHIP VENDOR
    {MESSAGE__CAPTAIN_SABINA_TALK},
    {MESSAGE__ISABEL_THE_RECLUSE_TALK},
    {MESSAGE__FARMER_WILLIAM_TALK},
    {0},  // SWORD VENDOR
    {0},  // CHAINMAIL VENDOR
    {MESSAGE__FORWIN_THE_WIZARD_TALK},
    {MESSAGE__MILLIE_THE_GOSSIP_TALK},
    {MESSAGE__WARDEN_GREGORY_TALK},
    {MESSAGE__SERVER_XAVIER_TALK},
    {MESSAGE__EXPLORER_CONSTANCE_TALK},
    {MESSAGE__FENRICK_TALK},
    {MESSAGE__CASTLE_ORACLE_TALK},
    {0},  // CURE POTION VENDOR
    {MESSAGE__BEATRICE_THE_GUARD_TALK},
    {MESSAGE__ROXANNE_THE_MAID_TALK},
    {MESSAGE__GROUNDSMAN_HECTOR_TALK},
    {MESSAGE__MAZINNA_THE_HERMIT_TALK},
    {MESSAGE__LETA_THE_GARDENER_TALK},
    {MESSAGE__FREEHAVEN_BARTENDER_TALK},
    {MESSAGE__JAYLAN_THE_SMITH_TALK},
    {MESSAGE__CAPTAIN_RODRICK_TALK},
    {MESSAGE__FIRST_MATE_WILLIE_TALK},
    {MESSAGE__GRETA_THE_GOBLIN_TALK},
    {MESSAGE__EX_PIRATE_FLETA_TALK},
    {MESSAGE__GUARD_MADDOX_TALK},
    {MESSAGE__GARRICK_THE_WIZARD_TALK},
    {MESSAGE__MARDEN_THE_ELDER_TALK},
    {MESSAGE__FAY_THE_TRAVELER_TALK},
    {MESSAGE__WIXA_THE_ALCHEMIST_TALK},
    {MESSAGE__BAXTON_THE_WIZARD_TALK},
    {MESSAGE__MAGE_MAXIMILIAN_TALK},
    {MESSAGE__CLAN_ELDER_DURON_TALK},
    {MESSAGE__GOLDWINE_THE_BARD_TALK},
    {MESSAGE__WIK_THE_GRUNT_TALK},
    {MESSAGE__OGRE_CHIEFTAIN_DAK_TALK},
    {MESSAGE__OVERSEER_THAL_TALK},
    {MESSAGE__OVERSEER_YARGOT_TALK},
    {MESSAGE__GRUNT_BALUZAG_TALK},
    {MESSAGE__GRUNT_ERUK_TALK},
    {MESSAGE__DESERTER_TRAGUT_TALK},
    {MESSAGE__GRUNT_BOKUR_TALK},
    {MESSAGE__DUSKGROVE_BARTENDER_TALK},
    {MESSAGE__SAMUEL_THE_MEDIC_TALK},
    {MESSAGE__MAYORINEXILE_JUL_TALK},
    {MESSAGE__WATCHMAN_BERNARD_TALK},
    {MESSAGE__SPIRETOP_BARTENDER_TALK},
    {MESSAGE__EDWIN_THE_WAYFARER_TALK},
    {MESSAGE__THEOBALD_THE_SAGE_TALK},
    {MESSAGE__RANULF_THE_WIZARD_TALK},
    {MESSAGE__RANGER_JULIANA_TALK},
    {MESSAGE__HIGH_PRIESTESS_ADA_TALK},
    {MESSAGE__ELDER_SAPPHIRE_TALK},
    {MESSAGE__ALDERNEY_THE_SEER_TALK},
    {MESSAGE__AVIL_THE_WARRIOR_TALK},
    {MESSAGE__CLAN_ELDER_THORINA_TALK},
    {MESSAGE__BARNABY_THE_PIRATE_TALK},
    {MESSAGE__AUDREY_THE_CONVICT_TALK},
    {MESSAGE__JOHN_THE_INSURGENT_TALK},
    {MESSAGE__DOROTHY_THE_TIPSY_TALK},
    {MESSAGE__STEWARD_ROWLAND_TALK},
    {MESSAGE__MARSHAL_CATHERINE_TALK},
    {MESSAGE__SOLDIER_LEONARD_TALK},
    {MESSAGE__OAK_ORACLE_TALK},
    {MESSAGE__SAILOR_TOBIAS_TALK},
    {MESSAGE__GYMARA_THE_SAILOR_TALK},
    {MESSAGE__THANAS_HOLD_BARTENDER_TALK},
    {MESSAGE__DEMON_GUARD_TALK},
    {MESSAGE__UMFREY_THE_SPY_TALK},
    {MESSAGE__MAGE_MARY_ANN_TALK},
    {MESSAGE__HILDA_THE_EXPLORER_TALK},
    {MESSAGE__PROSPECTOR_DIVANA_TALK},
    {MESSAGE__BRONK_THE_SERVANT_TALK},
    {MESSAGE__OPEN_SESAME},
    {MESSAGE__GO_AWAY_FORCE_FIELD},
    {MESSAGE__FOOL_YOU_CANT_HARM_ME},
    {0},    // MSWORD VENDOR
    {0},    // MBOW VENDOR
    {MESSAGE__FULK_THE_DEPARTED},
    {MESSAGE__SIR_DEVON_TALK},
    {MESSAGE__RAY_THE_APPRENTICE_TALK},
    {MESSAGE__SAM_THE_ADVENTURER_TALK},
    {MESSAGE__ROLF_THE_MIGHTY_TALK}};

const short NPCName[] = {
    {STATUS__QUEEN_AVALINE},
    {STATUS__KING_RUFUS},
    {STATUS__EZIN_THE_SAGE},
    {STATUS__DALIN_THE_DWARF},
    {STATUS__GUARD},
    {STATUS__IDA_THE_JESTER},
    {STATUS__SWORDSMAN_PENGENAR},
    {STATUS__GROCER},
    {STATUS__ROBIN_THE_BARFLY},
    {STATUS__RANDALL_THE_LONER},
    {STATUS__ALISTAIR_THE_ELDER},
    {STATUS__GUARDSMAN_TAYLOR},
    {STATUS__EVA_THE_FIGHTER},
    {STATUS__SLING_VENDOR},
    {STATUS__LEATHER_VENDOR},
    {STATUS__BARTENDER},
    {STATUS__MAYOR_WADE},
    {STATUS__BARTENDER},
    {STATUS__HEALER},
    {STATUS__MYSTERIOUS_HERMIT},
    {STATUS__BAERN_THE_SMITH},
    {STATUS__CLAN_CHIEF_TRAVOK},
    {STATUS__BARTENDER},
    {STATUS__AMBER_THE_JUVENILE},
    {STATUS__VISTRA_THE_SMITH},
    {STATUS__RUTGAR_THE_MINER},
    {STATUS__BORIN_THE_MINER},
    {STATUS__SOLDIER_GADORA},
    {STATUS__PLATE_VENDOR},
    {STATUS__FORGEGURU_RISWYNN},
    {STATUS__AXE_VENDOR},
    {STATUS__MACE_VENDOR},
    {STATUS__GROVE_WARDEN_GLYNN},
    {STATUS__BOW_VENDOR},
    {STATUS__ORACLE_GUARD},
    {STATUS__GILES_THE_RANGER},
    {STATUS__NESTA_THE_RANGER},
    {STATUS__NIGEL_THE_LOST},
    {STATUS__ELENA_THE_YOUTH},
    {STATUS__TERRIC_THE_SAGE},
    {STATUS__BARTENDER},
    {STATUS__HEALING_POTION_VENDOR},
    {STATUS__MAYOR_BALDRIC},
    {STATUS__BARTENDER},
    {STATUS__DECKHAND_JORDAN},
    {STATUS__FRIAR_HENRY},
    {STATUS__SHIP_VENDOR},
    {STATUS__CAPTAIN_SABINA},
    {STATUS__ISABEL_THE_RECLUSE},
    {STATUS__FARMER_WILLIAM},
    {STATUS__SWORD_VENDOR},
    {STATUS__CHAINMAIL_VENDOR},
    {STATUS__FORWIN_THE_WIZARD},
    {STATUS__MILLIE_THE_GOSSIP},
    {STATUS__WARDEN_GREGORY},
    {STATUS__SERVER_XAVIER},
    {STATUS__EXPLORER_CONSTANCE},
    {STATUS__FENRICK},
    {STATUS__THE_ORACLE_SAYS},
    {STATUS__CURE_POTION_VENDOR},
    {STATUS__BEATRICE_THE_GUARD},
    {STATUS__ROXANNE_THE_MAID},
    {STATUS__GROUNDSMAN_HECTOR},
    {STATUS__MAZINNA_THE_HERMIT},
    {STATUS__LETA_THE_GARDENER},
    {STATUS__BARTENDER},
    {STATUS__JAYLAN_THE_SMITH},
    {STATUS__CAPTAIN_RODRICK},
    {STATUS__FIRST_MATE_WILLIE},
    {STATUS__GRETA_THE_GOBLIN},
    {STATUS__EX_PIRATE_FLETA},
    {STATUS__GUARD_MADDOX},
    {STATUS__GARRICK_THE_WIZARD},
    {STATUS__MARDEN_THE_ELDER},
    {STATUS__FAY_THE_TRAVELER},
    {STATUS__WIXA_THE_ALCHEMIST},
    {STATUS__BAXTON_THE_WIZARD},
    {STATUS__MAGE_MAXIMILIAN},
    {STATUS__CLAN_ELDER_DURON},
    {STATUS__GOLDWINE_THE_BARD},
    {STATUS__WIK_THE_GRUNT},
    {STATUS__OGRE_CHIEFTAIN_DAK},
    {STATUS__OVERSEER_THAL},
    {STATUS__OVERSEER_YARGOT},
    {STATUS__GRUNT_BALUZAG},
    {STATUS__GRUNT_ERUK},
    {STATUS__DESERTER_TRAGUT},
    {STATUS__GRUNT_BOKUR},
    {STATUS__BARTENDER},
    {STATUS__SAMUEL_THE_MEDIC},
    {STATUS__MAYORINEXILE_JUL},
    {STATUS__WATCHMAN_BERNARD},
    {STATUS__BARTENDER},
    {STATUS__EDWIN_THE_WAYFARER},
    {STATUS__THEOBALD_THE_SAGE},
    {STATUS__RANULF_THE_WIZARD},
    {STATUS__RANGER_JULIANA},
    {STATUS__HIGH_PRIESTESS_ADA},
    {STATUS__ELDER_SAPPHIRE},
    {STATUS__ALDERNEY_THE_SEER},
    {STATUS__AVIL_THE_WARRIOR},
    {STATUS__CLAN_ELDER_THORINA},
    {STATUS__BARNABY_THE_PIRATE},
    {STATUS__AUDREY_THE_CONVICT},
    {STATUS__JOHN_THE_INSURGENT},
    {STATUS__DOROTHY_THE_TIPSY},
    {STATUS__STEWARD_ROWLAND},
    {STATUS__MARSHAL_CATHERINE},
    {STATUS__SOLDIER_LEONARD},
    {STATUS__THE_ORACLE_SAYS},
    {STATUS__SAILOR_TOBIAS},
    {STATUS__GYMARA_THE_SAILOR},
    {STATUS__BARTENDER},
    {STATUS__DEMON_GUARD},
    {STATUS__UMFREY_THE_SPY},
    {STATUS__MAGE_MARY_ANN},
    {STATUS__HILDA_THE_EXPLORER},
    {STATUS__PROSPECTOR_DIVANA},
    {STATUS__BRONK_THE_SERVANT},
    {STATUS__YOU_SAY},
    {STATUS__YOU_SAY},
    {STATUS__THANA_THE_USURPER},
    {STATUS__MSWORD_VENDOR},
    {STATUS__MBOW_VENDOR},
    {STATUS__FULK_THE_DEPARTED},
    {STATUS__SIR_DEVON},
    {STATUS__RAY_THE_APPRENTICE},
    {STATUS__SAM_THE_ADVENTURER},
    {STATUS__ROLF_THE_MIGHTY}
};

const char OutdoorNPC[][3] = {
    {0xFF, 0xFF, 0xFF}
};

const char CastleNPC[][3] = {
    {23, 9, QUEEN_AVALINE},
    {27, 11, KING_RUFUS},
    {20, 9, EZIN_THE_SAGE},
    {20, 11, EZIN_THE_SAGE},
    {19, 10, EZIN_THE_SAGE},
    {21, 10, EZIN_THE_SAGE},
    {22, 13, GUARD},
    {22, 15, GUARD},
    {23, 14, GUARD},
    {25, 13, GUARD},
    {25, 15, GUARD},
    {24, 14, GUARD},
    {22, 23, GUARD},
    {21, 24, GUARD},
    {23, 24, GUARD},
    {25, 23, GUARD},
    {24, 24, GUARD},
    {26, 24, GUARD},
    {29, 16, IDA_THE_JESTER},
    {28, 15, IDA_THE_JESTER},
    {41, 26, GUARD},
    {41, 28, GUARD},
    {40, 27, GUARD},
    {36, 18, DALIN_THE_DWARF},
    {35, 19, DALIN_THE_DWARF},
    {37, 19, DALIN_THE_DWARF},
    {10, 18, SIR_DEVON},
    {12, 18, SIR_DEVON},
    {10, 8, GROCER},
    {9, 7, GROCER},
    {11, 7, GROCER},
    {36, 11, HEALER},
    {12, 16, MILLIE_THE_GOSSIP},
    {14, 16, MILLIE_THE_GOSSIP},
    {10, 11, SERVER_XAVIER},
    {9, 12, SERVER_XAVIER},
    {11, 12, SERVER_XAVIER},
    {31, 11, EXPLORER_CONSTANCE},
    {31, 13, EXPLORER_CONSTANCE},
    {7, 21, BEATRICE_THE_GUARD},
    {7, 23, BEATRICE_THE_GUARD},
    {8, 22, BEATRICE_THE_GUARD},
    {8, 25, ROXANNE_THE_MAID},
    {8, 27, ROXANNE_THE_MAID},
    {7, 26, ROXANNE_THE_MAID},
    {10, 3, GROUNDSMAN_HECTOR},
    {11, 4, GROUNDSMAN_HECTOR},
    {0xFF, 0xFF, 0xFF}
};

const char AcadiaNPC[][3] = {
    {47, 14, GUARD},
    {47, 15, GUARD},
    {0, 14, GUARD},
    {0, 15, GUARD},
    {38, 20, GROCER},
    {9, 5, ROBIN_THE_BARFLY},
    {10, 6, ROBIN_THE_BARFLY},
    {32, 5, RANDALL_THE_LONER},
    {40, 29, ALISTAIR_THE_ELDER},
    {41, 30, ALISTAIR_THE_ELDER},
    {42, 29, ALISTAIR_THE_ELDER},
    {41, 28, ALISTAIR_THE_ELDER},
    {16, 20, GUARDSMAN_TAYLOR},
    {17, 21, GUARDSMAN_TAYLOR},
    {18, 20, GUARDSMAN_TAYLOR},
    {17, 19, GUARDSMAN_TAYLOR},
    {29, 6, EVA_THE_FIGHTER},
    {30, 7, EVA_THE_FIGHTER},
    {24, 6, SLING_VENDOR},
    {28, 6, MACE_VENDOR},
    {37, 5, LEATHER_VENDOR},
    {13, 5, ACADIA_BARTENDER},
    {5, 23, MAYOR_WADE},
    {7, 23, MAYOR_WADE},
    {6, 22, MAYOR_WADE},
    {6, 24, MAYOR_WADE},
    {4, 3, LETA_THE_GARDENER},
    {4, 5, LETA_THE_GARDENER},
    {3, 4, LETA_THE_GARDENER},
    {5, 4, LETA_THE_GARDENER},
    {0xFF, 0xFF, 0xFF}
};

const char StoneheartNPC[][3] = {
    {9, 29, GROCER},
    {31, 4, BAERN_THE_SMITH},
    {32, 3, BAERN_THE_SMITH},
    {32, 5, BAERN_THE_SMITH},
    {34, 4, BAERN_THE_SMITH},
    {13, 3, CLAN_CHIEF_TRAVOK},
    {14, 4, CLAN_CHIEF_TRAVOK},
    {15, 3, CLAN_CHIEF_TRAVOK},
    {10, 19, STONEHEART_BARTENDER},
    {36, 25, AMBER_THE_JUVENILE},
    {37, 24, AMBER_THE_JUVENILE},
    {44, 3, VISTRA_THE_SMITH},
    {45, 2, VISTRA_THE_SMITH},
    {46, 3, VISTRA_THE_SMITH},
    {45, 5, VISTRA_THE_SMITH},
    {7, 11, RUTGAR_THE_MINER},
    {8, 10, RUTGAR_THE_MINER},
    {3, 9, BORIN_THE_MINER},
    {2, 8, BORIN_THE_MINER},
    {5, 19, SOLDIER_GADORA},
    {6, 18, SOLDIER_GADORA},
    {7, 19, SOLDIER_GADORA},
    {40, 24, PLATE_VENDOR},
    {31, 30, FORGEGURU_RISWYNN},
    {30, 29, FORGEGURU_RISWYNN},
    {29, 30, FORGEGURU_RISWYNN},
    {40, 28, AXE_VENDOR},
    {33, 13, CLAN_ELDER_DURON},
    {34, 14, CLAN_ELDER_DURON},
    {20, 10, CLAN_ELDER_THORINA},
    {21, 11, CLAN_ELDER_THORINA},
    {0xFF, 0xFF, 0xFF}
};

const char OakNPC[][3] = {
    {19, 15, GROVE_WARDEN_GLYNN},
    {20, 14, GROVE_WARDEN_GLYNN},
    {20, 16, GROVE_WARDEN_GLYNN},
    {21, 15, GROVE_WARDEN_GLYNN},
    {38, 23, BOW_VENDOR},
    {19, 8, ORACLE_GUARD},
    {19, 6, ORACLE_GUARD},
    {18, 7, ORACLE_GUARD},
    {20, 7, ORACLE_GUARD},
    {7, 27, HEALER},
    {7, 4, GROCER},
    {39, 5, GILES_THE_RANGER},
    {39, 3, GILES_THE_RANGER},
    {38, 4, GILES_THE_RANGER},
    {40, 4, GILES_THE_RANGER},
    {44, 4, NESTA_THE_RANGER},
    {43, 3, NESTA_THE_RANGER},
    {45, 3, NESTA_THE_RANGER},
    {32, 10, NIGEL_THE_LOST},
    {32, 12, NIGEL_THE_LOST},
    {31, 11, NIGEL_THE_LOST},
    {33, 11, NIGEL_THE_LOST},
    {34, 21, ELENA_THE_YOUTH},
    {34, 23, ELENA_THE_YOUTH},
    {35, 22, ELENA_THE_YOUTH},
    {45, 30, TERRIC_THE_SAGE},
    {45, 32, TERRIC_THE_SAGE},
    {44, 31, TERRIC_THE_SAGE},
    {46, 31, TERRIC_THE_SAGE},
    {22, 5, OAK_ORACLE},
    {22, 7, OAK_ORACLE},
    {21, 6, OAK_ORACLE},
    {23, 6, OAK_ORACLE},
    {42, 3, OAK_BARTENDER},
    {22, 30, HEALING_POTION_VENDOR},
    {0xFF, 0xFF, 0xFF}
};

const char WatersNPC[][3] = {
    {28, 16, MAYOR_BALDRIC},
    {27, 15, MAYOR_BALDRIC},
    {39, 3, WATERS_BARTENDER},
    {27, 9, DECKHAND_JORDAN},
    {26, 8, DECKHAND_JORDAN},
    {28, 8, DECKHAND_JORDAN},
    {36, 4, FRIAR_HENRY},
    {35, 3, FRIAR_HENRY},
    {37, 3, FRIAR_HENRY},
    {19, 9, SHIP_VENDOR},
    {30, 3, CAPTAIN_SABINA},
    {31, 4, CAPTAIN_SABINA},
    {6, 11, ISABEL_THE_RECLUSE},
    {6, 13, ISABEL_THE_RECLUSE},
    {5, 12, ISABEL_THE_RECLUSE},
    {7, 12, ISABEL_THE_RECLUSE},
    {9, 2, FARMER_WILLIAM},
    {8, 1, FARMER_WILLIAM},
    {7, 27, SWORD_VENDOR},
    {13, 27, CHAINMAIL_VENDOR},
    {46, 2, FORWIN_THE_WIZARD},
    {45, 1, FORWIN_THE_WIZARD},
    {37, 26, GROCER},
    {15, 25, ROLF_THE_MIGHTY},
    {14, 24, ROLF_THE_MIGHTY},
    {0xFF, 0xFF, 0xFF}
};

const char FreehavenNPC[][3] = {
    {42, 3, CURE_POTION_VENDOR},
    {15, 30, GROCER},
    {32, 30, HEALER},
    {10, 30, FREEHAVEN_BARTENDER},
    {43, 29, JAYLAN_THE_SMITH},
    {44, 30, JAYLAN_THE_SMITH},
    {30, 13, CAPTAIN_RODRICK},
    {30, 15, CAPTAIN_RODRICK},
    {29, 14, CAPTAIN_RODRICK},
    {31, 14, CAPTAIN_RODRICK},
    {33, 13, FIRST_MATE_WILLIE},
    {33, 15, FIRST_MATE_WILLIE},
    {32, 14, FIRST_MATE_WILLIE},
    {34, 14, FIRST_MATE_WILLIE},
    {18, 29, GRETA_THE_GOBLIN},
    {17, 30, GRETA_THE_GOBLIN},
    {8, 11, EX_PIRATE_FLETA},
    {8, 28, SAILOR_TOBIAS},
    {9, 27, SAILOR_TOBIAS},
    {45, 7, GYMARA_THE_SAILOR},
    {44, 6, GYMARA_THE_SAILOR},
    {46, 6, GYMARA_THE_SAILOR},
    {6, 2, GUARD_MADDOX},
    {6, 4, GUARD_MADDOX},
    {5, 3, GUARD_MADDOX},
    {7, 3, GUARD_MADDOX},
    {16, 28, GARRICK_THE_WIZARD},
    {17, 27, GARRICK_THE_WIZARD},
    {5, 25, MARDEN_THE_ELDER},
    {4, 26, MARDEN_THE_ELDER},
    {23, 26, FAY_THE_TRAVELER},
    {22, 25, FAY_THE_TRAVELER},
    {29, 10, SAM_THE_ADVENTURER},
    {0xFF, 0xFF, 0xFF}
};

const char CastleBNPC[][3] = {
    {1, 18, MYSTERIOUS_HERMIT},
    {2, 17, MYSTERIOUS_HERMIT},
    {20, 9, SWORDSMAN_PENGENAR},
    {21, 10, SWORDSMAN_PENGENAR},
    {31, 21, WARDEN_GREGORY},
    {7, 28, FENRICK},
    {12, 23, CASTLE_ORACLE},
    {16, 9, CASTLE_BARTENDER},
    {36, 31, MAZINNA_THE_HERMIT},
    {2, 30, WIXA_THE_ALCHEMIST},
    {46, 11, BAXTON_THE_WIZARD},
    {46, 13, BAXTON_THE_WIZARD},
    {45, 12, BAXTON_THE_WIZARD},
    {47, 12, BAXTON_THE_WIZARD},
    {31, 25, MAGE_MAXIMILIAN},
    {30, 26, MAGE_MAXIMILIAN},
    {35, 25, BARNABY_THE_PIRATE},
    {34, 26, BARNABY_THE_PIRATE},
    {41, 27, AUDREY_THE_CONVICT},
    {40, 26, AUDREY_THE_CONVICT},
    {25, 25, JOHN_THE_INSURGENT},
    {26, 26, JOHN_THE_INSURGENT},
    {9, 12, DOROTHY_THE_TIPSY},
    {8, 11, DOROTHY_THE_TIPSY},
    {12, 9, STEWARD_ROWLAND},
    {13, 10, STEWARD_ROWLAND},
    {29, 15, MARSHAL_CATHERINE},
    {28, 14, MARSHAL_CATHERINE},
    {30, 14, MARSHAL_CATHERINE},
    {37, 11, SOLDIER_LEONARD},
    {36, 1, SAMUEL_THE_MEDIC},
    {46, 6, GUARD},
    {45, 7, GUARD},
    {23, 21, GUARD},
    {22, 22, GUARD},
    {47, 1, MAYORINEXILE_JUL},
    {39, 2, WATCHMAN_BERNARD},
    {41, 2, WATCHMAN_BERNARD},
    {14, 1, FULK_THE_DEPARTED},
    {0xFF, 0xFF, 0xFF}
};

const char DuskgroveNPC[][3] = {
    {29, 12, WIK_THE_GRUNT},
    {28, 11, WIK_THE_GRUNT},
    {5, 30, OGRE_CHIEFTAIN_DAK},
    {7, 30, OGRE_CHIEFTAIN_DAK},
    {6, 26, OVERSEER_THAL},
    {8, 26, OVERSEER_THAL},
    {39, 13, OVERSEER_YARGOT},
    {40, 12, OVERSEER_YARGOT},
    {42, 25, GRUNT_BALUZAG},
    {41, 24, GRUNT_BALUZAG},
    {43, 28, GRUNT_ERUK},
    {31, 18, DESERTER_TRAGUT},
    {31, 20, DESERTER_TRAGUT},
    {30, 19, DESERTER_TRAGUT},
    {32, 19, DESERTER_TRAGUT},
    {4, 12, GRUNT_BOKUR},
    {42, 28, DUSKGROVE_BARTENDER},
    {0xFF, 0xFF, 0xFF}
};

const char SpiretopNPC[][3] = {
    {17, 6, GOLDWINE_THE_BARD},
    {41, 27, GROCER},
    {37, 27, HEALING_POTION_VENDOR},
    {33, 27, HEALER},
    {29, 6, SPIRETOP_BARTENDER},
    {43, 24, EDWIN_THE_WAYFARER},
    {42, 25, EDWIN_THE_WAYFARER},
    {43, 4, THEOBALD_THE_SAGE},
    {38, 8, RANULF_THE_WIZARD},
    {27, 6, RANGER_JULIANA},
    {26, 8, HIGH_PRIESTESS_ADA},
    {27, 9, HIGH_PRIESTESS_ADA},
    {43, 15, ELDER_SAPPHIRE},
    {43, 17, ELDER_SAPPHIRE},
    {42, 16, ELDER_SAPPHIRE},
    {44, 16, ELDER_SAPPHIRE},
    {6, 27, ALDERNEY_THE_SEER},
    {7, 26, ALDERNEY_THE_SEER},
    {7, 30, AVIL_THE_WARRIOR},
    {8, 31, AVIL_THE_WARRIOR},
    {21, 30, MSWORD_VENDOR},
    {24, 30, MBOW_VENDOR},
    {45, 29, RAY_THE_APPRENTICE},
    {0xFF, 0xFF, 0xFF}
};

const char ThanasHoldNPC[][3] = {
    {9, 30, THANAS_HOLD_BARTENDER},
    {35, 23, GROCER},
    {36, 8, HEALING_POTION_VENDOR},
    {39, 8, CURE_POTION_VENDOR},
    {23, 21, DEMON_GUARD},
    {24, 21, DEMON_GUARD},
    {5, 12, DEMON_GUARD},
    {41, 12, DEMON_GUARD},
    {5, 19, DEMON_GUARD},
    {41, 19, DEMON_GUARD},
    {5, 15, DEMON_GUARD},
    {5, 16, DEMON_GUARD},
    {41, 15, DEMON_GUARD},
    {41, 16, DEMON_GUARD},
    {28, 28, DEMON_GUARD},
    {29, 29, DEMON_GUARD},
    {15, 9, UMFREY_THE_SPY},
    {15, 6, MAGE_MARY_ANN},
    {6, 6, HILDA_THE_EXPLORER},
    {6, 9, PROSPECTOR_DIVANA},
    {41, 29, BRONK_THE_SERVANT},
    {0xFF, 0xFF, 0xFF}
};

const char KeepofShadowNPC[][3] = {
    {4, 15, PASSWORD_SQUARE},
    {24, 13, CIRCLE_CONTROL},
    {24, 12, THANA_THE_USURPER},
    {0xFF, 0xFF, 0xFF}
};

const char NPCFunction[] = {
    {QUEEN_FUNCTION},           // QUEEN_AVALINE
    {DEFAULT_FUNCTION},         // KING_RUFUS
    {DEFAULT_FUNCTION},         // EZIN_THE_SAGE
    {DEFAULT_FUNCTION},         // DALIN_THE_DWARF
    {DEFAULT_FUNCTION},         // GUARD
    {DEFAULT_FUNCTION},         // IDA_THE_JESTER
    {DEFAULT_FUNCTION},         // SWORDSMAN_PENGENAR
    {VENDOR_FUNCTION},          // GROCER
    {DEFAULT_FUNCTION},         // ROBIN_THE_BARFLY
    {DEFAULT_FUNCTION},         // RANDALL_THE_LONER
    {DEFAULT_FUNCTION},         // ALISTAIR_THE_ELDER
    {DEFAULT_FUNCTION},         // GUARDSMAN_TAYLOR
    {DEFAULT_FUNCTION},         // EVA_THE_FIGHTER
    {VENDOR_FUNCTION},    // SLING_VENDOR
    {VENDOR_FUNCTION},  // LEATHER_VENDOR
    {BARTENDER_FUNCTION},       // ACADIA_BARTENDER
    {DEFAULT_FUNCTION},         // MAYOR_WADE
    {BARTENDER_FUNCTION},       // CASTLE_BARTENDER
    {VENDOR_FUNCTION},          // HEALER
    {MYSTERIOUS_HERMIT_FUNCTION},   // MYSTERIOUS_HERMIT
    {DEFAULT_FUNCTION},    // BAERN_THE_SMITH
    {DWARF_DISGUISE_FUNCTION},    // CLAN_CHIEF_TRAVOK
    {BARTENDER_FUNCTION},  // STONEHEART_BARTENDER
    {DEFAULT_FUNCTION},    // AMBER_THE_JUVENILE
    {DEFAULT_FUNCTION},    // VISTRA_THE_SMITH
    {DEFAULT_FUNCTION},    // RUTGAR_THE_MINER
    {DEFAULT_FUNCTION},    // BORIN_THE_MINER
    {DEFAULT_FUNCTION},    // SOLDIER_GADORA
    {VENDOR_FUNCTION},    // PLATE_VENDOR
    {RISWYNN_FUNCTION},    // FORGEGURU_RISWYNN
    {VENDOR_FUNCTION}, // AXE_VENDOR
    {VENDOR_FUNCTION},// MACE_VENDOR
    {DEFAULT_FUNCTION},    // GROVE_WARDEN_GLYNN
    {VENDOR_FUNCTION}, // BOW_VENDOR
    {DEFAULT_FUNCTION},    // ORACLE_GUARD
    {DEFAULT_FUNCTION},    // GILES_THE_RANGER
    {DEFAULT_FUNCTION},    // NESTA_THE_RANGER
    {DEFAULT_FUNCTION},    // NIGEL_THE_LOST
    {DEFAULT_FUNCTION},    // ELENA_THE_YOUTH
    {DEFAULT_FUNCTION},    // TERRIC_THE_SAGE
    {BARTENDER_FUNCTION},  // OAK_BARTENDER
    {VENDOR_FUNCTION},    // HEALING_POTION_VENDOR
    {DEFAULT_FUNCTION},    // MAYOR_BALDRIC
    {BARTENDER_FUNCTION},  // WATERS_BARTENDER
    {DEFAULT_FUNCTION},    // DECKHAND_JORDAN
    {DEFAULT_FUNCTION},    // FRIAR_HENRY
    {VENDOR_FUNCTION},// SHIP_VENDOR
    {DEFAULT_FUNCTION},    // CAPTAIN_SABINA
    {DEFAULT_FUNCTION},    // ISABEL_THE_RECLUSE
    {DEFAULT_FUNCTION},    // FARMER_WILLIAM
    {VENDOR_FUNCTION},    // SWORD_VENDOR
    {VENDOR_FUNCTION},    // CHAINMAIL_VENDOR
    {DEFAULT_FUNCTION},    // FORWIN_THE_WIZARD
    {DEFAULT_FUNCTION},    // MILLIE_THE_GOSSIP
    {DEFAULT_FUNCTION},    // WARDEN_GREGORY
    {DEFAULT_FUNCTION},    // SERVER_XAVIER
    {DEFAULT_FUNCTION},    // EXPLORER_CONSTANCE
    {DEFAULT_FUNCTION},    // FENRICK
    {DEFAULT_FUNCTION},    // CASTLE_ORACLE
    {VENDOR_FUNCTION},    // CURE_POTION_VENDOR
    {DEFAULT_FUNCTION},    // BEATRICE_THE_GUARD
    {DEFAULT_FUNCTION},    // ROXANNE_THE_MAID
    {DEFAULT_FUNCTION},    // GROUNDSMAN_HECTOR
    {MAZINNA_FR_FUNCTION}, // MAZINNA_THE_HERMIT
    {DEFAULT_FUNCTION},    // LETA_THE_GARDENER
    {BARTENDER_FUNCTION},  // FREEHAVEN_BARTENDER
    {JAYLAN_DA_FUNCTION},  // JAYLAN_THE_SMITH
    {DEFAULT_FUNCTION},    // CAPTAIN_RODRICK
    {DEFAULT_FUNCTION},    // FIRST_MATE_WILLIE
    {DEFAULT_FUNCTION},    // GRETA_THE_GOBLIN
    {DEFAULT_FUNCTION},    // EX_PIRATE_FLETA
    {DEFAULT_FUNCTION},    // GUARD_MADDOX
    {DEFAULT_FUNCTION},    // GARRICK_THE_WIZARD
    {DEFAULT_FUNCTION},    // MARDEN_THE_ELDER
    {DEFAULT_FUNCTION},    // FAY_THE_TRAVELER
    {WIXA_FUNCTION},       // WIXA_THE_ALCHEMIST
    {BAXTON_ER_FUNCTION},  // BAXTON_THE_WIZARD
    {ADVANCED_TRAINER_FUNCTION},  // MAGE_MAXIMILIAN
    {ADVANCED_TRAINER_FUNCTION},       // CLAN_ELDER_DURON
    {ADVANCED_TRAINER_FUNCTION},    // GOLDWINE_THE_BARD
    {EVIL_PLACE_FUNCTION},  // WIK_THE_GRUNT
    {EVIL_PLACE_FUNCTION},  // OGRE_CHIEFTAIN_DAK
    {EVIL_PLACE_FUNCTION},  // OVERSEER_THAL
    {EVIL_PLACE_FUNCTION},  // OVERSEER_YARGOT
    {EVIL_PLACE_FUNCTION},  // GRUNT_BALUZAG
    {EVIL_PLACE_FUNCTION},  // GRUNT_ERUK
    {TRAGUT_FUNCTION},     // DESERTER_TRAGUT
    {EVIL_PLACE_FUNCTION},   // GRUNT_BOKUR
    {BARTENDER_FUNCTION},  // DUSKGROVE_BARTENDER
    {SAMUEL_FUNCTION},     // SAMUEL_THE_MEDIC
    {DEFAULT_FUNCTION},    // MAYORINEXILE_JUL
    {DEFAULT_FUNCTION},    // WATCHMAN_BERNARD
    {BARTENDER_FUNCTION},  // SPIRETOP_BARTENDER
    {DEFAULT_FUNCTION},    // EDWIN_THE_WAYFARER
    {DEFAULT_FUNCTION},    // THEOBALD_THE_SAGE
    {DEFAULT_FUNCTION},    // RANULF_THE_WIZARD
    {DEFAULT_FUNCTION},    // RANGER_JULIANA
    {DEFAULT_FUNCTION},    // HIGH_PRIESTESS_ADA
    {DEFAULT_FUNCTION},    // ELDER_SAPPHIRE
    {ALDERNEY_FUNCTION},   // ALDERNEY_THE_SEER
    {AVIL_FUNCTION},       // AVIL_THE_WARRIOR
    {DWARF_DISGUISE_FUNCTION},    // CLAN_ELDER_THORINA
    {DEFAULT_FUNCTION},    // BARNABY_THE_PIRATE
    {DEFAULT_FUNCTION},    // AUDREY_THE_CONVICT
    {DEFAULT_FUNCTION},    // JOHN_THE_INSURGENT
    {DEFAULT_FUNCTION},    // DOROTHY_THE_TIPSY
    {DEFAULT_FUNCTION},    // STEWARD_ROWLAND
    {DEFAULT_FUNCTION},    // MARSHAL_CATHERINE
    {DEFAULT_FUNCTION},    // SOLDIER_LEONARD
    {DEFAULT_FUNCTION}, // OAK_ORACLE
    {DEFAULT_FUNCTION},    // SAILOR_TOBIAS
    {DEFAULT_FUNCTION},    // GYMARA_THE_SAILOR
    {BARTENDER_FUNCTION},  // THANAS_HOLD_BARTENDER
    {EVIL_PLACE_FUNCTION},  // DEMON_GUARD
    {EVIL_PLACE_FUNCTION},  // UMFREY_THE_SPY
    {EVIL_PLACE_FUNCTION},  // MAGE_MARY_ANN
    {EVIL_PLACE_FUNCTION},  // HILDA_THE_EXPLORER
    {EVIL_PLACE_FUNCTION},  // PROSPECTOR_DIVANA
    {EVIL_PLACE_FUNCTION},  // BRONK_THE_SERVANT
    {PASSWORD_SQUARE_FUNCTION},    // PASSWORD_SQUARE
    {CIRCLE_CONTROL_FUNCTION},     // CIRCLE_CONTROL
    {THANA_FUNCTION},              // THANA_THE_USURPER
    {VENDOR_FUNCTION},      // MSWORD_VENDOR
    {VENDOR_FUNCTION},        // MBOW_VENDOR
    {FULK_FUNCTION},       // FULK_THE_DEPARTED
    {DEFAULT_FUNCTION},    // SIR_DEVON
    {DEFAULT_FUNCTION},    // RAY_THE_APPRENTICE
    {DEFAULT_FUNCTION},    // SAM_THE_ADVENTURER
    {DEFAULT_FUNCTION}     // ROLF_THE_MIGHTY
};

const char *NPC[] = {
    OutdoorNPC,
    CastleNPC,
    AcadiaNPC,
    StoneheartNPC,
    OakNPC,
    WatersNPC,
    FreehavenNPC,
    CastleBNPC,
    DuskgroveNPC,
    SpiretopNPC,
    ThanasHoldNPC,
    KeepofShadowNPC
};

const char *MonsterName[] = {
    "troll",
    "darkling",
    "shadow rat",
    "goblin",
    "skeleton",
    "fire beetle",
    "ogre",
    "shadow orb",
    "head",
    "giant",
    "death bug",
    "dark drake",
    "night wisp",
    "gloom viper",
    "unseelie",
    "titan",
    "pirate",
    "salamander",
    "demon guard",
    "earth shade",
    "water shade",
    "fire shade",
    "air shade",
    "sea serpent",
    "water wight",
    "giant squid",
    "zombie",
    "dire spider",
    "minotaur",
    "hell rabbit",
    "slime",
    "roper",
    "vampire bat",
    "ghost",
    "mummy",
    "ice devil",
    "amoeba",
    "demon",
    "lich",
    "dragon"
};

const char *Messages[] = {
    "Queen Avaline says:",
    "A mysterious voice says:",
    "Loot this chest?",
    "Warden Gregory says:",
    "Server Xavier says:",
    "Explorer Constance says:",
    "Fenrick says:",
    "The Oracle says:",
    "Buy a cure potion for 100 gold?",
    "Beatrice the Guard says:",
    "Roxanne the Maid asks:",
    "Groundsman Hector says:",
    "Mazinna the hermit says:",
    "Leta the Gardener says:",
    "Drink from the fountain?",
    "You hear water. Take a drink?",
    "Jaylan the Smith says:",
    "Captain Rodrick says:",
    "First Mate Willie says:",
    "Greta the Goblin asks:",
    "Ex-pirate Fleta says:",
    "Guard Maddox says:",
    "Garrick the Wizard says:",
    "Marden the Elder says:",
    "Fay the Traveler says:",
    "Wixa the Alchemist says:",
    "Baxton the Wizard says:",
    "Did you bring me acorns?",
    "Mage Maximilian says:",
    "Would you like to train with me?",
    "Clan-elder Duron says:",
    "Goldwine the Bard says:",
    "The prisoner says:",
    "The ogre says:",
    "The creature says:",
    "Wik the Grunt asks:",
    "Overseer Thal asks:",
    "Overseer Yargot asks:",
    "Grunt Baluzag asks:",
    "Grunt Eruk says:",
    "Deserter Tragut says:",
    "Grunt Bokur asks:",
    "Samuel the Medic says:",
    "How many potions do you give?",
    "Mayor-in-exile Jul says:",
    "Watchman Bernard says:",
    "Edwin the Wayfarer says:",
    "Theobald the Sage says:",
    "Ranulf the Wizard says:",
    "Ranger Juliana says:",
    "High Priestess Ada says:",
    "Elder Sapphire says:",
    "Alderney the Seer says:",
    "Avil the Warrior says:",
    "Ray the Apprentice says:",
    "Sam the Adventurer says:",
    "Audrey the Convict says:",
    "Barnaby the Pirate says:",
    "John the Insurgent says:",
    "Clan-elder Thorina says:",
    "Dorothy the Tipsy slurs:",
    "Steward Rowland says:",
    "Marshal Catherine says:",
    "Soldier Leonard asks:",
    "Sailor Tobias asks:",
    "Gymara the Sailor says:",
    "Demon Guard says:",
    "Umfrey the Spy says:",
    "Mage Mary Ann says:",
    "Hilda the Explorer says:",
    "Prospector Divana says:",
    "Bronk the Servant says:",
    "You say:",
    "Thana the Usurper says:",
    "The Bartender says:",
    "King Rufus says:",
    "Ida the Jester says:",
    "Purchase 10 rations for 5 gold?",
    "Robin the Barfly says:",
    "Mayor Wade says:",
    "Clan-chief Travok says:",
    "Rutgar the Miner says:",
    "Borin the Miner says:",
    "Amber the Juvenile says:",
    "Soldier Gadora says:",
    "Vistra the Smith says:",
    "Eva the Fighter says:",
    "Randall the Loner says:",
    "Alistair the Elder says:",
    "The Guard says:",
    "Ezin the Sage says:",
    "The Mysterious Hermit says:",
    "Fulk the Departed says:",
    "Dalin the Dwarf says:",
    "Sir Devon says:",
    "Swordsman Pengenar says:",
    "Baern the Smith says:",
    "Buy a sling for 50 gold?",
    "Buy a bow for 600 gold?",
    "Buy an axe for 400 gold?",
    "Buy a mace for 100 gold?",
    "Buy a sword for 1,200 gold?",
    "Buy chainmail armor for 900?",
    "Buy leather armor for 200 gold?",
    "Buy platemail armor for 2,500?",
    "Do you need healing for 50 gold?",
    "Buy a healing potion for 50?",
    "Grove-warden Glynn says:",
    "Mayor Baldric says:",
    "Deckhand Jordan says:",
    "Friar Henry says:",
    "Captain Sabina says:",
    "Millie the Gossip asks:",
    "Farmer William asks:",
    "Isabel the Recluse asks:",
    "Forwin the Wizard says:",
    "Rolf the Mighty says:",
    "Giles the Ranger says:",
    "Nesta the Ranger says:",
    "Nigel the Lost asks:",
    "Terric the Sage says:",
    "Elena the Youth says:",
    "The Oracle Guard says:",
    "Buy a ship for 1,000 gold?",
    "Have a drink for 5 gold?",
    "The merchant says:",
    "The healer says:",
    "Do you require healing?",
    "Ascend to the next level?",
    "Descend to the previous level?",
    "Do you ascend or descend?",
    "Actions:",
    "Cast which spell?",
    "Items:",
    "Rest here and save your game?",
    "Rest here?",
    "Victory!",
    "Buy a magical sword for 2,400?",
    "Buy a magic bow for 1,200 gold?",
    "Forge-guru Riswynn says:",
    "Clan-elder Duron says:",
    "Goldwine the Bard says:",
    "Buy platemail armor for 2,500?",
    "Ogre Chieftain Dak says:",
    "Guardsman Taylor says:",
    "Return when your deeds are more noteworthy.",
    "Entering Stoneheart.",
    "Entering Waters.",
    "Entering Oak.",
    "Entering Castle Avalina.",
    "Entering Spiretop.",
    "Exiting to the high sea.",
    "Entering Thana's Hold.",
    "Entering Freehaven.",
    "Entering Keep of Shadow.",
    "The disguise wears off.",
    "You find some fire acorns!",
    "You find a spirit stone!",
    "Entering Acadia.",
    "Yes No",
    "Exiting to Faradur.",
    "Entering the ruins of Duskgrove.",
    "Go and experience more.",
    "You can't go that way.",
    "Cast Loot Use Inventory Pass",
    "Cast Loot Use Ascend",
    "Cast Loot Use Descend",
    "Cast Loot Use Ascend Descend",
    "Cast Use Inventory Pass",
    "Attack Ranged Cast Use Pass",
    "Bite Breath Heal Pass",
    "Talk Cast Use Inventory",
    "Swapped! Grapple Broken!",
    "Not enough spell points!",
    "Nothing much happens.",
    "Party healed!",
    "Cured!",
    "Which direction?",
    "Already healed!",
    "Saved!",
    "Rested!",
    "Swapped!",
    "Not here!",
    "You change form!",
    "No ranged weapon!",
    "Nothing to use!",
    "Homing gem invoked!",
    "The Fey Dragon is not here!",
    "Moved.",
    "Meow.",
    "Seek the magic circles!",
    "Have you ever been to Stoneheart?",
    "Good day.",
    "I bet Rufus is the real power behind the throne.",
    "Slaying beasts is thirsty work!",
    "Stay and have a drink!",
    "Beware of lava unless you know the ritual.",
    "The mountains to the south hold great magic.",
    "Beware of troll bridges.",
    "Arms are scarce now due to our troubled times.",
    "I hear dwarves make superior arms and armor.",
    "Welcome to Acadia!",
    "They say only magical lights work in dungeons.",
    "You can use your spells to travel where you can neither walk nor sail.",
    "Riswynn is the greatest smith who ever lived.",
    "Welcome to Stoneheart, city of the dwarves.",
    "They say that there are some who can walk on lava.",
    "Slay a goblin for me!",
    "Don't touch anything!",
    "The goblins have been bolder since the Incursions started.",
    "Heigh-ho!",
    "Avil could save us, but he is missing.",
    "Find the Spirit Stone, and I can make a weapon that you can never lose.",
    "Welcome to Oak!",
    "You may approach the Oracle only if you are worthy.",
    "The surrounding forest is beset with fell foes.",
    "We protect the Oak folk from the Incursions.",
    "Which way is North?",
    "I want to learn archery.",
    "Learn the rituals!",
    "I hear some places can only be found via magic.",
    "Welcome to Waters!",
    "They say that trolls attack those who appear weak.",
    "Ships may be purchased only by worthy heroes.",
    "Grog is my holy water.",
    "I miss my ship.",
    "The Southern continent holds great mysteries.",
    "Are you the new hero?",
    "A skilled mage can use \"Sun\" for divination.",
    "What is your name? Your job?",
    "The force barriers will keep most from passing.",
    "The castle probably has many secret passages.",
    "Avoid the dungeons until you are strong enough.",
    "Lava is very hot.",
    "Each dungeon has an orb you must find to emerge victorious.",
    "I'm on my wine break.",
    "What are you doing in the Queen's bedchamber?",
    "A reward awaits you at the top of each dungeon.",
    "Well done, hero! I will teach you what I know.",
    "Be careful not to stray too far from home yet.",
    "I hear that there's a hidden city settled by heroes.",
    "Go away. I'm busy.",
    "The sovereign hamlet of Freehaven welcomes you!",
    "We are a haven for those who do not fit in elsewhere.",
    "Have you ever met a real gobin?",
    "It be a bad time to be in the ship business.",
    "I am on lookout duty to warn of coming monsters.",
    "I hope we won't share the same fate as Duskgrove.",
    "Our hidden location has kept us mostly safe.",
    "I'm stranded here until the Incursions are over.",
    "I need more fire acorns!",
    "Most impressive! I will teach you what I know.",
    "I regret my crimes, but I can impart my knowledge of magic upon you if you wish. >>",
    "I was once the greatest warrior of the dwarves. I can teach you to be a more effective warrior. >>",
    "I've traveled the lands for ages before settling here. I'm fleet of foot, and know many skills. >>",
    "Did you see a human?",
    "Praise to Thana, grunt!",
    "Are you ready for the invasion, grunt?",
    "I can't find Tragut!",
    "Wanna play spears?",
    "I think Tragut may have deserted on us.",
    "Thana must be stopped! Her stronghold may only be reached by magic.",
    "Where is your post?",
    "I hear that Thana's Hold has the best ale.",
    "Can you spare any heal potions for the sick?",
    "Welcome to Duskgrove's refugee bunker.",
    "We are hiding people until out city is liberated.",
    "I hear there's a magic gem that can send you home.",
    "It looks like you are stuck here now with the rest of us.",
    "We came to Spiretop to retire in peace.",
    "Magic wards bar us from leaving this valley.",
    "We want to help, but we can't leave this valley.",
    "The rift must be healed, or Faradur is doomed.",
    "Hi! Welcome to Spiretop: hidden city of heroes.",
    "Thana was one of us until her power-lust led her to seek dark magic. She opened a rift to shadow, >>",
    "If you can find a way to leave, tell Jaylan that I sent you.",
    "Leave me alone, human.",
    "I should have stayed in Freehaven.",
    "The queen did not appreciate me impersonating her.",
    "Join me to depose the Queen.",
    "This is the safest place to drink in all of Faradur.",
    "Long live the Queen!",
    "Our soldiers are spread too thin.",
    "Did you hear about the fall of Duskgrove?",
    "One circle of power lies beneath the ocean waves.",
    "'Ave ye seen me brother Barnaby?",
    "Dwarven sailors are very rare.",
    "I hear the password was changed to 'New Liege'.",
    "Praise Thana, goblin.",
    "Enter the keep from the west side if you attain the password.",
    "You must close the rift to the Shadow Realm!",
    "This city is dangerous without disguise dust.",
    "I picked the wrong hill to mine.",
    "Goblins no have to hide no more once Thana takes over.",
    "\"Open sesame!\" >>",
    "\"Go away, force field!\" >>",
    "Fool! You can't harm me or the force field.",
    "To dispel magic, recite:",
    "You must travel to Oak to find healing potions.",
    "I can't believe that Thana turned on us!",
    "You will need magic to explore the nearby dungeon.",
    "They have better armor in Freehaven.",
    "With this gift, you may never be found unarmed. >>",
    "Thank you for your help.",
    "Safe journeys, Hero.",
    "You are now greater!",
    "A human! Attack!",
    "Another time, perhaps.",
    "You risk killing us all if you use your magic here.",
    "Fulk was the wisest of all sages. Seek him at Cave of the Dead.",
    "Thank you. Come again!",
    "Use this only when your peril is most dire.",
    "and trapped us here. You must penetrate her lair on the island to the east of here.",
    "Avil sent you? You may have my greatest work.",
    "You have enough already.",
    "Go away!",
    "You have no need of it.",
    "Wield your hammer with honor.",
    "Why not?",
    "\"An-Mar-Bok-Fi-Lot!\"",
    "Go find the other trainers!",
    "You don't have enough.",
    "Where?",
    "Spirit Stones are found in the Cave of the Dead on the Isle of Mystery.",
    "No one is here!",
    "Poisoned!",
    "Out of food!",
    "No enemy there.",
    "Missed.",
    "Pass.",
    "The dragon is hit!",
    "Fey Dragon dissapates.",
    "You have been restored!",
    "Healed!",
    "You learn the %s spell!",
    "It's dark!"
};


const char *DungeonMessages[] = {
    "Some walls are fake.",
    "Drafty clues.",
    "Inner maze.",
    "Secrets, secrets, secrets...",
    "Watery roulette.",
    "Center yourself to soar.",
    "Deadly corners.",
    "Windy escape.",
    "Follow the breadcrumbs.",
    "Fortune and falls.",
    "Layers of deception.",
    "One, two, three, four, five.",
    "Don't rise too soon.",
    "Fast way, or slow way.",
    "A windfall lifts you up.",
    "Avoid a path to nowhere.",
    "Paths of darkness.",
    "Pits and ladders.",
    "Drop to advance.",
    "Corridor of doom.",
    "Cavern of wonders.",
    "Mining for secrets.",
    "Easier than it seems.",
    "The long march.",
    "Magic will take you far.",
    "Pillar of riches.",
    "Find the energy source.",
    "Hidden maze.",
    "Rewards and despair.",
    "Watch your step.",
    "Windy stash.",
    "Boons and escape."
};
