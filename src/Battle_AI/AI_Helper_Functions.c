#include "..\\defines.h"
#include "../../include/constants/items.h"
#include "../../include/new/helper_functions.h"
#include "../../include/new/item.h"

extern move_t MinimizeHitTable[];
extern move_t IgnoreAirTable[];
extern move_t IgnoreUndergoundTable[];
extern move_t IgnoreUnderwaterTable[];
extern move_t AlwaysHitRainTable[];
extern const struct SpecialZMoves gSpecialZMoveTable[];

extern s8 PriorityCalc(u8 bank, u8 action, u16 move);
extern s32 BracketCalc(u8 bank);
extern u32 SpeedCalc(u8 bank);
extern u8 CheckMoveLimitations(u8 bank, u8 unusableMoves, u8 check);
extern u32 AI_CalcDmg(u8 bankAtk, u8 bankDef, u16 move);
extern bool8 IsMega(u8 bank);
extern bool8 IsBluePrimal(u8 bank);
extern bool8 IsRedPrimal(u8 bank);

bool8 CanKillAFoe(u8 bank);
bool8 CanKnockOut(u8 bankAtk, u8 bankDef);
bool8 MoveKnocksOut(u16 move, u8 bankAtk, u8 bankDef);
bool8 IsStrongestMove(u16 currentMove, u8 bankAtk, u8 bankDef);
bool8 MoveWillHit(u16 move, u8 bankAtk, u8 bankDef);
bool8 MoveWouldHitFirst(u16 move, u16 bankAtk, u16 bankDef);
bool8 DamagingMoveInMoveset(u8 bank);
bool8 PhysicalMoveInMoveset(u8 bank);
bool8 SpecialMoveInMoveset(u8 bank);
bool8 MagicCoatableMovesInMoveset(u8 bank);
bool8 GetHealthPercentage(u8 bank);
bool8 TeamFullyHealedMinusBank(u8 bank);
bool8 HasProtectionMoveInMoveset(u8 bank, bool8 AllKinds);
move_t ShouldAIUseZMove(u8 bank, u8 moveIndex, u16 move);
u8 aiAllStatChecks(u8 viability, u8 bank, u8 cmpVal);
bool8 MoveTypeInMoveset(u8 bank, u8 moveType);
bool8 HasSnatchableMove(u8 bank);
bool8 PartyMemberStatused(u8 bank);
bool8 MoveEffectInMoveset(u8 moveEffect, u8 bank);
bool8 StatusMoveInMoveset(u8 bank);

bool8 CanKillAFoe(u8 bank) {
	u8 foe = FOE(bank);
	if (!(gAbsentBattlerFlags & gBitTable[foe]) && CanKnockOut(bank, foe))
		return TRUE;
	
	if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && !(gAbsentBattlerFlags & gBitTable[PARTNER(foe)]))
		return CanKnockOut(bank, PARTNER(foe));
	
	return FALSE;
}

bool8 CanKnockOut(u8 bankAtk, u8 bankDef)
{
	u16 move;
	int i;

	if (gAbsentBattlerFlags & gBitTable[bankAtk])
		return FALSE;

	u8 moveLimitations = CheckMoveLimitations(bankAtk, 0, 0xFF);
	
	for (i = 0; i < 4; ++i) {
		#ifdef REALLY_SMART_AI
			move = gBattleMons[bankAtk].moves[i];
		#else
			if (SIDE(bankAtk) == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
				move = BATTLE_HISTORY->usedMoves[bankAtk].moves[i];
			else if (SIDE(bankAtk) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(bankAtk) == B_POSITION_PLAYER_LEFT)
				move = BATTLE_HISTORY->usedMoves[bankAtk].moves[i];
			else
				move = gBattleMons[bankAtk].moves[i];
		#endif
		
		if (move == MOVE_NONE)
			break;
		
		if (!(gBitTable[i] & moveLimitations)) {
			if (MoveKnocksOut(move, bankAtk, bankDef))
				return TRUE;
		}
	}
	return FALSE;
}

bool8 MoveKnocksOut(u16 move, u8 bankAtk, u8 bankDef) {
	u16 defHP = gBattleMons[bankDef].hp;
	
	if (SPLIT(move) == SPLIT_STATUS)
		return FALSE;
	
	if (gBattleMoves[move].effect == EFFECT_0HKO) {
		if (gBattleMons[bankAtk].level <= gBattleMons[bankDef].level)
			return FALSE;
		if (move == MOVE_SHEERCOLD && IsOfType(bankDef, TYPE_ICE))
			return FALSE;
		return TRUE;
	}
	
	if (gBattleMoves[move].effect == EFFECT_COUNTER || gBattleMoves[move].effect == EFFECT_MIRROR_COAT) //Includes Metal Burst
		return FALSE;
	
	if (gBattleMoves[move].power == 0)
		return FALSE;

	if (AI_CalcDmg(bankAtk, bankDef, move) >= defHP)
		return TRUE;
	
	return FALSE;
}

bool8 IsStrongestMove(u16 currentMove, u8 bankAtk, u8 bankDef) {
	u16 move;
	u16 strongestMove = gBattleMons[bankAtk].moves[0];
	s32 highestDamage = -1;
	int i;
	
	u8 moveLimitations = CheckMoveLimitations(bankAtk, 0, 0xFF);
	
	for (i = 0; i < 4; ++i) {
		move = gBattleMons[bankAtk].moves[i];
		if (move == MOVE_NONE)
			break;
		
		if (!(gBitTable[i] & moveLimitations)) {
			
			if (SPLIT(move) == SPLIT_STATUS)
				continue;
			
			if (gBattleMoves[move].power == 0)
				continue;
			
			if (gBattleMoves[move].effect == EFFECT_COUNTER || gBattleMoves[move].effect == EFFECT_MIRROR_COAT) //Includes Metal Burst
				continue;
	
			else if (gBattleMoves[move].effect == EFFECT_0HKO) {
				if (gBattleMons[bankAtk].level <= gBattleMons[bankDef].level)
					continue;
				if (move == MOVE_SHEERCOLD && IsOfType(bankDef, TYPE_ICE))
					continue;
				if (MoveWillHit(move, bankAtk, bankDef)) {
					strongestMove = move;
					highestDamage = 0x7FFFFFFF;
					
					if (currentMove == strongestMove)
						return TRUE;
					//Keep going because user may have another 0HKO move to be checked
				}
			}
			
			else if (AI_CalcDmg(bankAtk, bankDef, move) > (u32) highestDamage) 
			{
				highestDamage = AI_CalcDmg(bankAtk, bankDef, move);
				strongestMove = move;
			}
		}
	}
	
	if (strongestMove == currentMove)
		return TRUE;
	
	return FALSE;
}

bool8 MoveWillHit(u16 move, u8 bankAtk, u8 bankDef) {
	#ifdef REALLY_SMART_AI
		u8 defAbility = BATTLE_HISTORY->abilities[bankDef];
	#else
		u8 defAbility = ABILITY(bankDef);
	#endif
	
	if (ABILITY(bankAtk) == ABILITY_NOGUARD 
	||  defAbility == ABILITY_NOGUARD
	||  (gStatuses3[bankDef] & STATUS3_ALWAYS_HITS && gDisableStructs[bankDef].bankWithSureHit == bankAtk))
		return TRUE;
	
	if (((gStatuses3[bankDef] & (STATUS3_IN_AIR | STATUS3_SKY_DROP_ATTACKER | STATUS3_SKY_DROP_TARGET)) && !CheckTableForMove(move, IgnoreAirTable))
    ||  ((gStatuses3[bankDef] & STATUS3_UNDERGROUND) && !CheckTableForMove(move, IgnoreUndergoundTable))
    ||  ((gStatuses3[bankDef] & STATUS3_UNDERWATER) && !CheckTableForMove(move, IgnoreUnderwaterTable))
    ||   (gStatuses3[bankDef] & STATUS3_DISAPPEARED))
		return FALSE;
		
	if ((move == MOVE_TOXIC && IsOfType(bankAtk, TYPE_POISON))
	||  (CheckTableForMove(move, MinimizeHitTable) && gStatuses3[bankDef] & STATUS3_MINIMIZED)
	|| ((gStatuses3[bankDef] & STATUS3_TELEKINESIS) && gBattleMoves[move].effect != EFFECT_0HKO)
	||  gBattleMoves[move].accuracy == 0
	|| (WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_RAIN_ANY) && CheckTableForMove(move, AlwaysHitRainTable)))
		return TRUE;
	
	return FALSE;
}
	
bool8 MoveWouldHitFirst(u16 move, u16 bankAtk, u16 bankDef) {
	u32 temp;
	u32 bankAtkSpeed, bankDefSpeed;

//Priority Calc
	if (PriorityCalc(bankAtk, ACTION_USE_MOVE, move) > 0)
		return TRUE;
	
//BracketCalc
	if (BracketCalc(bankAtk) > BracketCalc(bankDef))
		return TRUE;
	
//SpeedCalc
	bankAtkSpeed = SpeedCalc(bankAtk);
	bankDefSpeed = SpeedCalc(bankDef);
	if (gNewBS->TrickRoomTimer) {
		temp = bankDefSpeed;
		bankDefSpeed = bankAtkSpeed;
		bankAtkSpeed = temp;
	}
	
	if (bankAtkSpeed > bankDefSpeed)
		return TRUE;
		
	return FALSE;
}

bool8 DamagingMoveInMoveset(u8 bank) {
	u16 move;
	u8 moveLimitations = CheckMoveLimitations(bank, 0, 0xFF);
	
	for (int i = 0; i < 4; ++i) {
		#ifdef REALLY_SMART_AI
			move = gBattleMons[bank].moves[i];
		#else
			if (SIDE(bank) == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else if (SIDE(bank) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(bank) == B_POSITION_PLAYER_LEFT)
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else
				move = gBattleMons[bank].moves[i];
		#endif
		
		if (move == MOVE_NONE)
			break;
		
		if (!(gBitTable[i] & moveLimitations)) {
			if (SPLIT(move) != SPLIT_STATUS
			&& gBattleMoves[move].power != 0
			&& gBattleMoves[move].effect != EFFECT_COUNTER
			&& gBattleMoves[move].effect != EFFECT_MIRROR_COAT)
				return TRUE;
		}
	}
	return FALSE;
}

bool8 PhysicalMoveInMoveset(u8 bank) {
	u16 move;
	u8 moveLimitations = CheckMoveLimitations(bank, 0, 0xFF);
	
	for (int i = 0; i < 4; ++i) {
		#ifdef REALLY_SMART_AI
			move = gBattleMons[bank].moves[i];
		#else
			if (SIDE(bank) == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else if (SIDE(bank) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(bank) == B_POSITION_PLAYER_LEFT)
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else
				move = gBattleMons[bank].moves[i];
		#endif
		
		if (move == MOVE_NONE)
			break;

		if (!(gBitTable[i] & moveLimitations)) {
			if (CalcMoveSplit(bank, move) == SPLIT_PHYSICAL
			&& gBattleMoves[move].power != 0
			&& gBattleMoves[move].effect != EFFECT_COUNTER)
				return TRUE;
		}
	}
	return FALSE;
}

bool8 SpecialMoveInMoveset(u8 bank) {
	u16 move;
	u8 moveLimitations = CheckMoveLimitations(bank, 0, 0xFF);
	
	for (int i = 0; i < 4; ++i) {
		#ifdef REALLY_SMART_AI
			move = gBattleMons[bank].moves[i];
		#else
			if (SIDE(bank) == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else if (SIDE(bank) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(bank) == B_POSITION_PLAYER_LEFT)
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else
				move = gBattleMons[bank].moves[i];
		#endif
		
		if (move == MOVE_NONE)
			break;
		
		if (!(gBitTable[i] & moveLimitations)) {
			if (CalcMoveSplit(bank, move) == SPLIT_SPECIAL
			&& gBattleMoves[move].power != 0
			&& gBattleMoves[move].effect != EFFECT_MIRROR_COAT)
				return TRUE;
		}
	}
	return FALSE;
}

bool8 MagicCoatableMovesInMoveset(u8 bank) {
	u16 move;
	u8 moveLimitations = CheckMoveLimitations(bank, 0, 0xFF);
	
	for (int i = 0; i < 4; ++i) {
		#ifdef REALLY_SMART_AI
			move = gBattleMons[bank].moves[i];
		#else
			if (SIDE(bank) == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else if (SIDE(bank) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(bank) == B_POSITION_PLAYER_LEFT)
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else
				move = gBattleMons[bank].moves[i];
		#endif
		
		if (move == MOVE_NONE)
			break;
		
		if (!(gBitTable[i] & moveLimitations)) {
			if (gBattleMoves[move].target & FLAG_MAGIC_COAT_AFFECTED)
				return TRUE;
		}
	}
	return FALSE;
}

bool8 GetHealthPercentage(u8 bank) {
	return udivsi(gBattleMons[bank].hp * 100, gBattleMons[bank].maxHP);
}

bool8 TeamFullyHealedMinusBank(u8 bank) {
	u8 firstId, lastId;
	
	pokemon_t* party = LoadPartyRange(bank, &firstId, &lastId);
	
    for (int i = firstId; i < lastId; ++i) {
        if (pokemon_getattr(&party[i], REQ_SPECIES) == SPECIES_NONE
        || pokemon_getattr(&party[i], REQ_EGG)
		|| i == gBattlerPartyIndexes[bank])
			continue;
			
		if (party[i].hp < party[i].maxHP)
			return FALSE;
    }
	return TRUE;
}

bool8 HasProtectionMoveInMoveset(u8 bank, bool8 AllKinds) {
	u16 move;
	u8 moveLimitations = CheckMoveLimitations(bank, 0, 0xFF);
	
	for (int i = 0; i < 4; ++i) {
		#ifdef REALLY_SMART_AI
			move = gBattleMons[bank].moves[i];
		#else
			if (SIDE(bank) == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else if (SIDE(bank) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(bank) == B_POSITION_PLAYER_LEFT)
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else
				move = gBattleMons[bank].moves[i];
		#endif
		
		if (move == MOVE_NONE)
			break;
		
		if (!(gBitTable[i] & moveLimitations)) {
			if (gBattleMoves[gBattleMons[bank].moves[i]].effect == EFFECT_PROTECT) {
				switch (move) {
					case MOVE_PROTECT:
					case MOVE_SPIKYSHIELD:
					case MOVE_KINGSSHIELD:
						return TRUE;
					
					case MOVE_QUICKGUARD:
					case MOVE_WIDEGUARD:
					case MOVE_CRAFTYSHIELD:
					case MOVE_MATBLOCK:
						if (AllKinds)
							return TRUE;
				}
			}
		}
	}
	return FALSE;
}

u16 ShouldAIUseZMove(u8 bank, u8 moveIndex, u16 move) {
	int i;
	bool8 isSpecialZCrystal = FALSE;
	
	if (move == 0)
		move = gBattleMons[bank].moves[moveIndex];
		
	if (IsMega(bank) 
	|| IsRedPrimal(bank) 
	|| IsBluePrimal(bank))
	{
		return FALSE;
	}
	
	if (IsZCrystal(gBattleMons[bank].item)
	||  ITEM(bank) == ITEM_ULTRA_NECROZIUM_Z) //The only "Mega Stone" that let's you use a Z-Move
	{
		for (i = 0; gSpecialZMoveTable[i].species != 0xFFFF; ++i) 
		{
			if (gSpecialZMoveTable[i].item == ITEM(bank))
			{
				isSpecialZCrystal = TRUE;
				if (gSpecialZMoveTable[i].species == SPECIES(bank)
				&&  gSpecialZMoveTable[i].move == move)
				{
					return gSpecialZMoveTable[i].zmove;
				}
			}
		}
		
		if (gBattleMoves[move].type == ITEM_QUALITY(bank) && !isSpecialZCrystal) {
			if (SPLIT(move) == SPLIT_STATUS)
				return 0xFFFF;
			else if (gBattleMoves[move].type < TYPE_FIRE)
				return MOVE_BREAKNECK_BLITZ_P + (gBattleMoves[move].type * 2) + CalcMoveSplit(bank, move);
			else
				return MOVE_BREAKNECK_BLITZ_P + ((gBattleMoves[move].type - 1) * 2) + CalcMoveSplit(bank, move);
		}
	}
	return FALSE;
}

//AI function to successively decrease viability for decreased stats
u8 aiAllStatChecks(u8 viability, u8 bank, u8 cmpVal) {
	u8 statId;
	
	for (statId = 0; statId < BATTLE_STATS_NO - 1; ++statId) 
	{
		if (gBattleMons[bank].statStages[statId] < cmpVal)
			viability -= 6;
			// multiple of reduction value?
	}
	return viability;
}


// AI function to check if any move is of given type
bool8 MoveTypeInMoveset(u8 bank, u8 moveType) {
	u8 i;
	for (i = 0; i <= 3; ++i)
	{
		if (gBattleMoves[gBattleMons[bank].moves[i]].type == moveType)
			return TRUE;
	}
	return FALSE;
}

// AI Function to check if bank has a snatchable move in moveset
bool8 HasSnatchableMove(u8 bank) {
	u8 i;
	for (i = 0; i <= 3; ++i)
	{
		if (gBattleMoves[gBattleMons[bank].moves[i]].flags & FLAG_SNATCH_AFFECTED)
			return TRUE;
	}
	return FALSE;
}

// AI function to see if a party member (attacker or attacker partner) has a primary status
bool8 PartyMemberStatused(u8 bank) {
	if (gBattleMons[bank].status1 & STATUS_ANY)
		return TRUE;
	else if (gBattleMons[PARTNER(bank)].status1 & STATUS_ANY)
		return TRUE;
	else
		return FALSE;	
}

// AI function to see if bank has a move with specific move effect
bool8 MoveEffectInMoveset(u8 moveEffect, u8 bank) {
	u8 i;
	for (i = 0; i <= 3; ++i)
	{
		if (gBattleMoves[gBattleMons[bank].moves[i]].effect == moveEffect)
			return TRUE;		
	}
	return FALSE;
}

// AI function to check if bank has a status move in their moveset
bool8 StatusMoveInMoveset(u8 bank) {
	u16 move;
	u8 moveLimitations = CheckMoveLimitations(bank, 0, 0xFF);
	
	for (int i = 0; i < 4; ++i) {
		#ifdef REALLY_SMART_AI
			move = gBattleMons[bank].moves[i];
		#else
			if (SIDE(bank) == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else if (SIDE(bank) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(bank) == B_POSITION_PLAYER_LEFT)
				move = BATTLE_HISTORY->usedMoves[bank].moves[i];
			else
				move = gBattleMons[bank].moves[i];
		#endif
		
		if (move == MOVE_NONE)
			break;
		
		if (!(gBitTable[i] & moveLimitations))
		{
			if (CalcMoveSplit(bank, move) == SPLIT_STATUS)
				return TRUE;
		}
	}
	return FALSE;	
	
	
}



