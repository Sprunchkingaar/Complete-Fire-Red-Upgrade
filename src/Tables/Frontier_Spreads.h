#include "../config.h"
#include "../../include/global.h"
#include "../../include/new/catching.h"
#include "../../include/new/frontier.h"
#include "../../include/constants/moves.h"
#include "../../include/constants/species.h"
#include "../../include/constants/items.h"
#include "../../include/constants/trainer_classes.h"

#define ABILITY_HIDDEN 0
#define ABILITY_1 1
#define ABILITY_2 2

#ifdef UNBOUND
const struct BattleTowerSpread gSpecialTowerSpread_Palmer1[] =
{
	{
		.species = SPECIES_MILOTIC,
		.nature = NATURE_MODEST,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spAtkEv = 252,
		.ability = ABILITY_HIDDEN, //Competitive
		.item = ITEM_SHELL_BELL,
		.moves =
		{
			MOVE_SURF,
			MOVE_ICEBEAM,
			MOVE_HYPNOSIS,
			MOVE_ATTRACT,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_MILOTIC,
		.nature = NATURE_BOLD,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 252,
		.spDefEv = 4,
		.ability = ABILITY_1, //Marvel Scale
		.item = ITEM_LEFTOVERS,
		.moves =
		{
			MOVE_SURF,
			MOVE_TOXIC,
			MOVE_AQUARING,
			MOVE_RECOVER,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_RHYPERIOR,
		.nature = NATURE_BRAVE,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 0,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.atkEv = 252,
		.defEv = 4,
		.ability = ABILITY_2, //Solid Rock
		.item = ITEM_FOCUS_SASH,
		.moves =
		{
			MOVE_REVERSAL,
			MOVE_PAYBACK,
			MOVE_METALBURST,
			MOVE_HORNDRILL,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_RHYPERIOR,
		.nature = NATURE_ADAMANT,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 4,
		.atkEv = 252,
		.spDefEv = 252,
		.ability = ABILITY_2, //Solid Rock
		.item = ITEM_ROCKIUM_Z,
		.moves =
		{
			MOVE_EARTHQUAKE,
			MOVE_STONEEDGE,
			MOVE_DRAGONRUSH,
			MOVE_POISONJAB,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_DRAGONITE,
		.nature = NATURE_JOLLY,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 4,
		.atkEv = 252,
		.spdEv = 252,
		.ability = ABILITY_HIDDEN, //Multiscale
		.item = ITEM_DRAGONIUM_Z,
		.moves =
		{
			MOVE_DRAGONRUSH,
			MOVE_EARTHQUAKE,
			MOVE_IRONTAIL,
			MOVE_DRAGONDANCE,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_DRAGONITE,
		.nature = NATURE_MODEST,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 4,
		.spAtkEv = 252,
		.spdEv = 252,
		.ability = ABILITY_HIDDEN, //Multiscale
		.item = ITEM_SALAC_BERRY,
		.moves =
		{
			MOVE_DRAGONPULSE,
			MOVE_THUNDER,
			MOVE_ICEBEAM,
			MOVE_ROOST,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_STARAPTOR,
		.nature = NATURE_JOLLY,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.atkEv = 4,
		.spdEv = 252,
		.ability = ABILITY_HIDDEN, //Reckless
		.item = ITEM_CHOICE_SCARF,
		.moves =
		{
			MOVE_BRAVEBIRD,
			MOVE_CLOSECOMBAT,
			MOVE_PURSUIT,
			MOVE_FINALGAMBIT,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_STARAPTOR,
		.nature = NATURE_ADAMANT,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 4,
		.atkEv = 252,
		.spdEv = 252,
		.ability = ABILITY_HIDDEN, //Reckless
		.item = ITEM_FLYINIUM_Z,
		.moves =
		{
			MOVE_BRAVEBIRD,
			MOVE_DOUBLEEDGE,
			MOVE_FEATHERDANCE,
			MOVE_ROOST,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_VESPIQUEN,
		.nature = NATURE_CALM,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spDefEv = 252,
		.ability = ABILITY_HIDDEN, //Unnerve
		.item = ITEM_QUICK_CLAW,
		.moves =
		{
			MOVE_TOXIC,
			MOVE_DEFENDORDER,
			MOVE_HEALORDER,
			MOVE_PROTECT,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_VESPIQUEN,
		.nature = NATURE_IMPISH,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 252,
		.spDefEv = 4,
		.ability = ABILITY_1, //Pressure
		.item = ITEM_NORMALIUM_Z,
		.moves =
		{
			MOVE_ATTACKORDER,
			MOVE_POWERGEM,
			MOVE_CONFUSERAY,
			MOVE_CAPTIVATE,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_BRONZONG,
		.nature = NATURE_SASSY,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 0,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spDefEv = 252,
		.ability = ABILITY_2, //Heatproof
		.item = ITEM_FLAME_ORB,
		.moves =
		{
			MOVE_PSYSHOCK,
			MOVE_HEALBLOCK,
			MOVE_TRICK,
			MOVE_STEALTHROCK,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_BRONZONG,
		.nature = NATURE_IMPISH,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 252,
		.spDefEv = 4,
		.ability = ABILITY_HIDDEN, //Heavy Metal
		.item = ITEM_LIGHT_CLAY,
		.moves =
		{
			MOVE_HEAVYSLAM,
			MOVE_HYPNOSIS,
			MOVE_REFLECT,
			MOVE_LIGHTSCREEN,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
};

const struct BattleTowerSpread gSpecialTowerSpread_Palmer2[] =
{
	{
		.species = SPECIES_REGIGIGAS,
		.nature = NATURE_IMPISH,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 252,
		.spDefEv = 4,
		.ability = ABILITY_1, //Slow Start
		.item = ITEM_BRIGHT_POWDER,
		.moves =
		{
			MOVE_CRUSHGRIP,
			MOVE_DRAINPUNCH,
			MOVE_ENDURE,
			MOVE_THUNDERWAVE,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_REGIGIGAS,
		.nature = NATURE_CAREFUL,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spDefEv = 252,
		.ability = ABILITY_1, //Slow Start
		.item = ITEM_LEFTOVERS,
		.moves =
		{
			MOVE_DRAINPUNCH,
			MOVE_TOXIC,
			MOVE_SWAGGER,
			MOVE_GRAVITY,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_HEATRAN,
		.nature = NATURE_MODEST,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 4,
		.spAtkEv = 252,
		.spdEv = 252,
		.ability = ABILITY_1, //Flash Fire
		.item = ITEM_FIRIUM_Z,
		.moves =
		{
			MOVE_MAGMASTORM,
			MOVE_FLASHCANNON,
			MOVE_EARTHPOWER,
			MOVE_DARKPULSE,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_HEATRAN,
		.nature = NATURE_CALM,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.spAtkEv = 4,
		.spDefEv = 252,
		.ability = ABILITY_1, //Flash Fire
		.item = ITEM_AIR_BALLOON,
		.moves =
		{
			MOVE_LAVAPLUME,
			MOVE_FLASHCANNON,
			MOVE_METALSOUND,
			MOVE_STEALTHROCK,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_CRESSELIA,
		.nature = NATURE_BOLD,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 252,
		.spDefEv = 4,
		.ability = ABILITY_1, //Levitate
		.item = ITEM_LIGHT_CLAY,
		.moves =
		{
			MOVE_MOONBLAST,
			MOVE_MOONLIGHT,
			MOVE_REFLECT,
			MOVE_LIGHTSCREEN,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_CRESSELIA,
		.nature = NATURE_MODEST,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 4,
		.defEv = 252,
		.spAtkEv = 252,
		.ability = ABILITY_1, //Levitate
		.item = ITEM_PSYCHIUM_Z,
		.moves =
		{
			MOVE_PSYSHOCK,
			MOVE_MOONBLAST,
			MOVE_CALMMIND,
			MOVE_MOONLIGHT,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_TYRANITAR,
		.nature = NATURE_IMPISH,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.atkEv = 252,
		.spDefEv = 4,
		.ability = ABILITY_HIDDEN, //Unnerve
		.item = ITEM_CHOPLE_BERRY,
		.moves =
		{
			MOVE_STONEEDGE,
			MOVE_CRUNCH,
			MOVE_EARTHQUAKE,
			MOVE_DRAGONDANCE,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_TYRANITAR,
		.nature = NATURE_ADAMANT,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 4,
		.atkEv = 252,
		.spDefEv = 252,
		.ability = ABILITY_1, //Sand Stream
		.item = ITEM_TYRANITARITE,
		.moves =
		{
			MOVE_STONEEDGE,
			MOVE_PAYBACK,
			MOVE_EARTHQUAKE,
			MOVE_ICEFANG,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_ABOMASNOW,
		.nature = NATURE_CALM,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spDefEv = 252,
		.ability = ABILITY_1, //Snow Warning
		.item = ITEM_BIG_ROOT,
		.moves =
		{
			MOVE_FROSTBREATH,
			MOVE_LEECHSEED,
			MOVE_INGRAIN,
			MOVE_PROTECT,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_ABOMASNOW,
		.nature = NATURE_MODEST,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spAtkEv = 252,
		.ability = ABILITY_1, //Snow Warning
		.item = ITEM_ABOMASITE,
		.moves =
		{
			MOVE_BLIZZARD,
			MOVE_GIGADRAIN,
			MOVE_FOCUSBLAST,
			MOVE_ICESHARD,
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_CELESTEELA,
		.nature = NATURE_BRAVE,
		.hpIv = 30,
		.atkIv = 31,
		.defIv = 30,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.atkEv = 252,
		.spdEv = 4,
		.ability = ABILITY_1, //Beast Boost
		.item = ITEM_ASSAULT_VEST,
		.moves =
		{
			MOVE_HEAVYSLAM,
			MOVE_EARTHQUAKE,
			MOVE_FLAMETHROWER,
			MOVE_HIDDENPOWER, //Ice
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
	{
		.species = SPECIES_CELESTEELA,
		.nature = NATURE_MODEST,
		.hpIv = 30,
		.atkIv = 31,
		.defIv = 30,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 252,
		.spdEv = 4,
		.ability = ABILITY_1, //Beast Boost
		.item = ITEM_FLYINIUM_Z,
		.moves =
		{
			MOVE_FLASHCANNON,
			MOVE_AIRSLASH,
			MOVE_FLAMETHROWER,
			MOVE_HIDDENPOWER, //Ice
		},
		.ball = BALL_TYPE_PREMIER_BALL,
	},
};
	
const struct BattleTowerSpread gSpecialTowerSpread_Cynthia[] =
{
	{
		.species = SPECIES_MILOTIC,
		.nature = NATURE_MODEST,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spAtkEv = 252,
		.ability = ABILITY_2, //Competitive
		.item = ITEM_WIDE_LENS,
		.moves =
		{
			MOVE_HYDROPUMP,
			MOVE_BLIZZARD,
			MOVE_MIRRORCOAT,
			MOVE_RECOVER,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_MILOTIC,
		.nature = NATURE_CALM,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spDefEv = 252,
		.ability = ABILITY_1, //Marvel Scale
		.item = ITEM_LEFTOVERS,
		.moves =
		{
			MOVE_SURF,
			MOVE_ICEBEAM,
			MOVE_SLEEPTALK,
			MOVE_REST,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_GARCHOMP,
		.nature = NATURE_ADAMANT,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.atkEv = 252,
		.defEv = 4,
		.spdEv = 252,
		.ability = ABILITY_HIDDEN, //Rough Skin
		.item = ITEM_CHOICE_SCARF,
		.moves =
		{
			MOVE_OUTRAGE,
			MOVE_EARTHQUAKE,
			MOVE_CRUNCH,
			MOVE_FIREFANG,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_GARCHOMP,
		.nature = NATURE_CAREFUL,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.atkEv = 4,
		.defEv = 252,
		.ability = ABILITY_1, //Sand Veil
		.item = ITEM_GARCHOMPITE,
		.moves =
		{
			MOVE_DRAGONCLAW,
			MOVE_EARTHQUAKE,
			MOVE_STONEEDGE,
			MOVE_SANDSTORM,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_TOGEKISS,
		.nature = NATURE_BOLD,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 4,
		.defEv = 128,
		.spAtkEv = 252,
		.spdEv = 128,
		.ability = ABILITY_2, //Serene Grace
		.item = ITEM_KINGS_ROCK,
		.moves =
		{
			MOVE_AIRSLASH,
			MOVE_SHADOWBALL,
			MOVE_GRASSKNOT,
			MOVE_THUNDERWAVE,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_TOGEKISS,
		.nature = NATURE_JOLLY,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.hpEv = 4,
		.spAtkEv = 252,
		.spdEv = 252,
		.ability = ABILITY_2, //Serene Grace
		.item = ITEM_EXPERT_BELT,
		.moves =
		{
			MOVE_DAZZLINGGLEAM,
			MOVE_AIRSLASH,
			MOVE_AURASPHERE,
			MOVE_GRASSKNOT,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_SPIRITOMB,
		.nature = NATURE_IMPISH,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 252,
		.spDefEv = 4,
		.ability = ABILITY_HIDDEN, //Infiltrator
		.item = ITEM_LEFTOVERS,
		.moves =
		{
			MOVE_SHADOWSNEAK,
			MOVE_WILLOWISP,
			MOVE_SWAGGER,
			MOVE_PSYCHUP,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_SPIRITOMB,
		.nature = NATURE_CAREFUL,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.hpEv = 252,
		.defEv = 4,
		.spDefEv = 252,
		.ability = ABILITY_HIDDEN, //Infiltrator
		.item = ITEM_CUSTAP_BERRY,
		.moves =
		{
			MOVE_SUCKERPUNCH,
			MOVE_PAINSPLIT,
			MOVE_WILLOWISP,
			MOVE_SUBSTITUTE,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_LUCARIO,
		.nature = NATURE_ADAMANT,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 0,
		.spDefIv = 31,
		.atkEv = 252,
		.spDefEv = 4,
		.spdEv = 252,
		.ability = ABILITY_HIDDEN, //Justified
		.item = ITEM_LUCARIONITE,
		.moves =
		{
			MOVE_CLOSECOMBAT,
			MOVE_BULLETPUNCH,
			MOVE_BLAZEKICK,
			MOVE_ROCKSLIDE,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_LUCARIO,
		.nature = NATURE_NAIVE,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.atkEv = 56,
		.spAtkEv = 200,
		.spdEv = 252,
		.ability = ABILITY_2, //Inner Focus
		.item = ITEM_WEAKNESS_POLICY,
		.moves =
		{
			MOVE_AURASPHERE,
			MOVE_DRAGONPULSE,
			MOVE_STONEEDGE,
			MOVE_EXTREMESPEED,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_EELEKTROSS,
		.nature = NATURE_BRAVE,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.atkEv = 252,
		.defEv = 200,
		.spAtkEv = 56,
		.ability = ABILITY_1, //Levitate
		.item = ITEM_ROCKY_HELMET,
		.moves =
		{
			MOVE_WILDCHARGE,
			MOVE_DRAGONCLAW,
			MOVE_CRUNCH,
			MOVE_FLAMETHROWER,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
	{
		.species = SPECIES_ROSERADE,
		.nature = NATURE_TIMID,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spdIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spAtkEv = 252,
		.spDefEv = 4,
		.spdEv = 252,
		.ability = ABILITY_1, //Natural Cure
		.item = ITEM_WHITE_HERB,
		.moves =
		{
			MOVE_LEAFSTORM,
			MOVE_SLUDGEBOMB,
			MOVE_SHADOWBALL,
			MOVE_SLEEPPOWDER,
		},
		.ball = BALL_TYPE_ULTRA_BALL,
	},
};
#endif