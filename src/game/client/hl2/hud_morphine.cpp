//========= Copyright arbabf, All rights reserved. ============//
//
// Purpose: Display morphine count.
//
//=============================================================================//

#include "cbase.h"
#include "hud.h"
#include "hudelement.h"
#include "hud_macros.h"
#include "hud_numericdisplay.h"
#include "iclientmode.h"
#include "iclientvehicle.h"
#include <vgui_controls/AnimationController.h>
#include <vgui/ILocalize.h>
#include <vgui/ISurface.h>
#include "ihudlcd.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

using namespace vgui;

class CHudMorphine : public CHudNumericDisplay, public CHudElement
{
	DECLARE_CLASS_SIMPLE(CHudMorphine, CHudNumericDisplay);
public:
	CHudMorphine(const char *pElementName);
	virtual void Init(void);
	virtual void Reset();
	virtual void VidInit(void);
	virtual void OnThink();

protected:
	virtual void Paint();

private:
	CPanelAnimationVar(vgui::HFont, m_hFont, "Font", "HudIcon");
	CPanelAnimationVarAliasType(float, m_IconX, "icon_xpos", "4", "proportional_float");
	CPanelAnimationVarAliasType(float, m_IconY, "icon_ypos", "4", "proportional_float");
	int m_nNumMorphine;
};

DECLARE_HUDELEMENT(CHudMorphine);

CHudMorphine::CHudMorphine(const char *pElementName) : BaseClass(NULL, "HudMorphine"), CHudElement(pElementName)
{
	SetHiddenBits(HIDEHUD_PLAYERDEAD | HIDEHUD_NEEDSUIT);
}

void CHudMorphine::Init(){
	Reset();
}

void CHudMorphine::Reset(){
	m_nNumMorphine = 0;
	SetDisplayValue(m_nNumMorphine);
}

void CHudMorphine::VidInit()
{
}

void CHudMorphine::Paint(){
	wchar_t* wc = L"y";
	surface()->DrawSetTextFont(m_hFont);
	surface()->DrawSetTextColor(GetFgColor());
	surface()->DrawSetTextPos(m_IconX, m_IconY);
	surface()->DrawUnicodeChar(*wc); // why do you do this vgui, why must i create a pointer then immediately dereference it
	BaseClass::Paint();
}

void CHudMorphine::OnThink(){
	C_BasePlayer *local_player = C_BasePlayer::GetLocalPlayer();
	if (local_player){
		int newMorph = local_player->GetMorphineCount();
		if (newMorph == m_nNumMorphine){
			return;
		}
		g_pClientMode->GetViewportAnimationController()->StartAnimationSequence("MorphineChanged");
		m_nNumMorphine = newMorph;
		SetDisplayValue(m_nNumMorphine);
	}
}