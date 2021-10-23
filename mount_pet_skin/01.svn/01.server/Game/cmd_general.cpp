search this:

	LPITEM mountItem =  ch->GetWear(WEAR_COSTUME_MOUNT);
	if(mountItem)
	{
		CMountSystem* mountSystem = ch->GetMountSystem();
		
		if (!mountSystem && !mountItem)
			return;
		
		DWORD mobVnum = mountItem->GetValue(1);

		if (ch->GetMountVnum() && mountSystem->CountSummoned() == 0)
			mountSystem->Unmount(mobVnum);
		
		return;
	}

replace with this:

	LPITEM mountItem =  ch->GetWear(WEAR_COSTUME_MOUNT);
	if(mountItem)
	{
		CMountSystem* mountSystem = ch->GetMountSystem();
		LPITEM mountSkinItem = ch->GetWear(WEAR_MOUNT_SKIN);
		
		if (!mountSystem && !mountItem)
			return;
		
		DWORD mobVnum = mountSkinItem ? mountSkinItem->GetValue(1) : mountItem->GetValue(1);

		if (ch->GetMountVnum() && mountSystem->CountSummoned() == 0)
			mountSystem->Unmount(mobVnum);
		
		return;
	}

search this:

	LPITEM mountItem =  ch->GetWear(WEAR_COSTUME_MOUNT);
	if(mountItem)
	{
		CMountSystem* mountSystem = ch->GetMountSystem();
		
		if (!mountSystem && !mountItem)
			return;
		
		DWORD mobVnum = mountItem->GetValue(1);

		if (ch->GetMountVnum() && mountSystem->CountSummoned() == 0)
			mountSystem->Unmount(mobVnum);
		else if (mountSystem->CountSummoned() >= 1)
			mountSystem->Mount(mobVnum, mountItem);
		
		return;
	}

replace with this:

	LPITEM mountItem =  ch->GetWear(WEAR_COSTUME_MOUNT);
	if(mountItem)
	{
		CMountSystem* mountSystem = ch->GetMountSystem();
		LPITEM mountSkinItem = ch->GetWear(WEAR_MOUNT_SKIN);
		
		if (!mountSystem && !mountItem)
			return;
		
		DWORD mobVnum = mountSkinItem ? mountSkinItem->GetValue(1) : mountItem->GetValue(1);

		if (ch->GetMountVnum() && mountSystem->CountSummoned() == 0)
			mountSystem->Unmount(mobVnum);
		else if (mountSystem->CountSummoned() >= 1)
			mountSystem->Mount(mobVnum, mountItem);
		
		return;
	}


