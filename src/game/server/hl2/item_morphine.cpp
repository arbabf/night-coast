//===============================
// Morphine shot.
// Copyright arbabf Industries.
// Purpose: Add to the number of available morphine shots, of which one can be used by pressing "+morphine" for sk_morphine health.
//===============================

#include "cbase.h"
#include "player.h"
#include "gamerules.h"
#include "items.h"
#include "hl2_player.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CItemMorphine : public CItem
{
public:
	DECLARE_CLASS(CItemMorphine, CItem);

	void Spawn(void);
	void Precache(void);
	bool MyTouch(CBasePlayer *pPlayer);
};

LINK_ENTITY_TO_CLASS(item_morphine, CItemMorphine);
PRECACHE_REGISTER(item_morphine);

void CItemMorphine::Spawn(void){
	Precache();
	SetModel("models/props_lab/jar01a.mdl");
	BaseClass::Spawn();
}

void CItemMorphine::Precache(void){
	PrecacheModel("models/props_lab/jar01a.mdl");
	PrecacheScriptSound("WallHealth.Start");
}

bool CItemMorphine::MyTouch(CBasePlayer *pPlayer){

	CHL2_Player *hl2_player = dynamic_cast<CHL2_Player *>(pPlayer);
	hl2_player->m_nNumMorphineCount += 1;
	UTIL_Remove(this);
	CPASAttenuationFilter filter(this, "WallHealth.Start");
	EmitSound(filter, entindex(), "WallHealth.Start");
	pPlayer->SetSuitUpdate("!HEV_MOAQ", false, 10);
	CSingleUserRecipientFilter user(hl2_player);
	user.MakeReliable();

	return true;

}


