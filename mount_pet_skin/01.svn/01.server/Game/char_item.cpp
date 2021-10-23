search this: (bool CHARACTER::CanEquipNow)

	switch (GetJob())

add before the function this:

	if (item->IsPetSkin() && !CanChangePetSkin())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You need wait before do that."));
		return false;
	}

	if (item->IsMountSkin() && (FindAffect(AFFECT_MOUNT)))
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You cant change skin when you are mounted."));
		return false;
	}
	
	if (item->IsMountSkin() && !CanChangeMountSkin())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You need wait before do that."));
		return false;
	}


search this:

bool CHARACTER::CanUnequipNow

extend the function with this:

	if (item->IsPetSkin() && !CanChangePetSkin())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You need wait before do that."));
		return false;
	}

	if (item->IsMountSkin() && (FindAffect(AFFECT_MOUNT)))
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You cant change skin when you are mounted."));
		return false;
	}
	
	if (item->IsMountSkin() && !CanChangeMountSkin())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You need wait before do that."));
		return false;
	}

