//========= Copyright Valve Corporation, touched up by arbabf, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
/*

===== item_longjump.cpp ========================================================

  handling for the longjump module
*/

#include "cbase.h"
#include "player.h"
#include "gamerules.h"
#include "items.h"
#include "hl2_player.h"

class CItemLongJump : public CItem
{
public:
	DECLARE_CLASS( CItemLongJump, CItem );

	void Spawn( void )
	{ 
		Precache( );
		SetModel( "models/items/combine_rifle_ammo01.mdl" );
		BaseClass::Spawn( );
	}
	void Precache( void )
	{
		PrecacheModel ("models/items/combine_rifle_ammo01.mdl");
	}
	bool MyTouch( CBasePlayer *pPlayer )
	{
		CHL2_Player *hl2_player = dynamic_cast<CHL2_Player *>(pPlayer);
		if ( hl2_player->CanLongJump() )
		{
			return false;
		}

		if ( pPlayer->IsSuitEquipped() )
		{
			hl2_player->SetLongJump(true);// player now has longjump module

			CSingleUserRecipientFilter user( pPlayer );
			user.MakeReliable();


			pPlayer->SetSuitUpdate("!HEV_A1", false, 0);
			return true;		
		}
		return false;
	}
};

LINK_ENTITY_TO_CLASS( item_longjump, CItemLongJump );
PRECACHE_REGISTER(item_longjump);
