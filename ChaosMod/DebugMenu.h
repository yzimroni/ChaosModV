#pragma once
#include "EffectDispatcher.h"
#include <vector>
#include <memory>

enum EffectType : int;

typedef unsigned long DWORD;

struct DebugEffect
{
	DebugEffect(EffectType effectType, const char* effectName) : EffectType(effectType), EffectName(effectName) {}

	EffectType EffectType;
	std::string EffectName;
};

class DebugMenu
{
public:
	DebugMenu(std::vector<EffectType> effects);

	void Tick();
	void HandleInput(DWORD key, bool onRepeat);
	void SetVisible(bool state);
	inline bool IsVisible() const
	{
		return m_visible;
	}

private:
	std::vector<DebugEffect> m_effects;
	int m_selected = 0;
	bool m_visible = false;
	DWORD m_repeatTime = 0;
	bool m_dispatchEffect = false;
};