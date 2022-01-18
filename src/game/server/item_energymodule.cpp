//===============================
// Energy Module
// Copyright arbabf Industries.
// Purpose: Replenish 100% health, 200% suit, and apply a speed buff (450) for sk_energymodule_time seconds.
//===============================

#include "cbase.h"
#include "player.h"
#include "gamerules.h"
#include "items.h"
#include "hl2_player.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CEnergyModule : public CItem
{
    public:
    DECLARE_CLASS( CEnergyModule, CItem );

	void Spawn( void );
	void Precache( void );
	bool MyTouch( CBasePlayer *pPlayer );
};

LINK_ENTITY_TO_CLASS( item_energymodule, CEnergyModule );
PRECACHE_REGISTER(item_energymodule);

void CEnergyModule::Spawn(void){
    Precache();
    SetModel("models/items/car_battery01.mdl");
    BaseClass::Spawn();
}

void CEnergyModule::Precache(void){
    PrecacheModel("models/items/car_battery01.mdl");
    PrecacheScriptSound("ItemBattery.Touch");
}

bool CEnergyModule::MyTouch( CBasePlayer *pPlayer ){
    // Always remove this item. If our player somehow grabs two energy modules back-to-back, duration just gets refreshed. Easy.
    CHL2_Player *hl2_player = dynamic_cast<CHL2_Player *>(pPlayer);
	hl2_player->SetMovement(false);
	hl2_player->TakeHealth(100, DMG_GENERIC);
	hl2_player->IncrementArmorValue(200, 200);
    UTIL_Remove(this);
	CPASAttenuationFilter filter(this, "ItemBattery.Touch");
	EmitSound(filter, entindex(), "ItemBattery.Touch");
	pPlayer->SetSuitUpdate("!HEV_E5", false, 0);
	CSingleUserRecipientFilter user(hl2_player);
	user.MakeReliable();
	
    return true;
  
}


