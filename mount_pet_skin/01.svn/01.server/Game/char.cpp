search this:

	m_iSyncHackCount = 0;

add under this:

	m_iChangeMountSkinTime = 0;
	m_iChangePetSkinTime = 0;

search this:

void CHARACTER::PetSummon(LPITEM petItem)
void CHARACTER::PetUnsummon(LPITEM petItem)
void CHARACTER::CheckPet()

replace the functions with this:

void CHARACTER::PetSummon(LPITEM petItem)
{
	CPetSystem* petSystem = GetPetSystem();
	LPITEM petSkinItem = GetWear(WEAR_PET_SKIN);
	DWORD mobVnum = 0;
	
	if (GetMapIndex() == 113)
		return;
	
	if (!petSystem || !petItem)
		return;
	
	if (petSkinItem)
		mobVnum = petSkinItem->GetValue(1);
	else
		mobVnum = petItem->GetValue(1);
	
	petSystem->Summon(mobVnum, petItem, false);
}

void CHARACTER::PetUnsummon(LPITEM petItem)
{
	CPetSystem* petSystem = GetPetSystem();
	LPITEM petSkinItem = GetWear(WEAR_PET_SKIN);
	DWORD mobVnum = 0;
	
	if (!petSystem || !petItem)
		return;

	if (petSkinItem)
		mobVnum = petSkinItem->GetValue(1);
	else
		mobVnum = petItem->GetValue(1);

	petSystem->Unsummon(mobVnum);
}

void CHARACTER::CheckPet()
{
	CPetSystem* petSystem = GetPetSystem();
	LPITEM petItem = GetWear(WEAR_NORMAL_PET);
	LPITEM petSkinItem = GetWear(WEAR_PET_SKIN);
	DWORD mobVnum = 0;
	
	if (GetMapIndex() == 113)
		return;	
	
	if (!petSystem || !petItem)
		return;
	
	if (petSkinItem)
		mobVnum = petSkinItem->GetValue(1);
	else
		mobVnum = petItem->GetValue(1);
	
	if(petSystem->CountSummoned() == 0)
		petSystem->Summon(mobVnum, petItem, false);
}

//Pet Skin Related
bool CHARACTER::CanChangePetSkin()
{
	return (thecore_pulse() - GetLastChangePetSkinTime() > PASSES_PER_SEC(5));
}

void CHARACTER::EquipPetSkin()
{
	if (!IsPetSummon()) return;
	
	CPetSystem* petSystem = GetPetSystem();
	LPITEM petItem = GetWear(WEAR_NORMAL_PET);
	if (!petSystem || !petItem) return;

	petSystem->Unsummon(petItem->GetValue(1));
	CheckPet();
	UpdateChangePetSkinTime();
}

void CHARACTER::RemovePetSkin(LPITEM petSkin)
{
	if (!IsPetSummon()) return;
	
	CPetSystem* petSystem = GetPetSystem();
	if (!petSystem || !petSkin) return;

	petSystem->Unsummon(petSkin->GetValue(1));
	CheckPet();
	UpdateChangePetSkinTime();
}

search this:

bool CHARACTER::IsPetSummon()
{
	return (GetWear(WEAR_NORMAL_PET));
}

add under this:

bool CHARACTER::CanChangeMountSkin()
{
	return (thecore_pulse() - GetLastChangeMountSkinTime() > PASSES_PER_SEC(5));
}

search this:

void CHARACTER::MountSummon(LPITEM mountItem)
void CHARACTER::MountUnsummon(LPITEM mountItem)
void CHARACTER::CheckMount()


replace with this:

void CHARACTER::MountSummon(LPITEM mountItem)
{
	if (IsPolymorphed() == true)
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Cant mount when you has polymorphed."));
		return;
	}

	if (GetMapIndex() == 113)
		return;
	
	if (CArenaManager::instance().IsArenaMap(GetMapIndex()) == true)
		return;

	CMountSystem* mountSystem = GetMountSystem();
	LPITEM mountSkinItem = GetWear(WEAR_MOUNT_SKIN);
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
	
	if (mountSkinItem)
		mobVnum = mountSkinItem->GetValue(1);
	else
		mobVnum = mountItem->GetValue(1);
	
	if (IsHorseRiding())
		StopRiding();
	
	if (GetHorse())
		HorseSummon(false);
	
	mountSystem->Summon(mobVnum, mountItem, false);
}

void CHARACTER::MountUnsummon(LPITEM mountItem)
{
	CMountSystem* mountSystem = GetMountSystem();
	LPITEM mountSkinItem = GetWear(WEAR_MOUNT_SKIN);
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
	
	if (mountSkinItem)
		mobVnum = mountSkinItem->GetValue(1);
	else
		mobVnum = mountItem->GetValue(1);
	
	if (GetMountVnum() == mobVnum)
		mountSystem->Unmount(mobVnum);

	mountSystem->Unsummon(mobVnum);
}

void CHARACTER::CheckMount()
{	
	CMountSystem* mountSystem = GetMountSystem();
	LPITEM mountItem = GetWear(WEAR_COSTUME_MOUNT);
	LPITEM mountSkinItem = GetWear(WEAR_MOUNT_SKIN);
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
	
	if (mountSkinItem)
		mobVnum = mountSkinItem->GetValue(1);
	else
		mobVnum = mountItem->GetValue(1);
	
	if (mountItem->GetSocket(2)) {
		mountSystem->MountAfterTeleport(mobVnum, mountItem, false);
	}
	else if(mountSystem->CountSummoned() == 0) {
		mountSystem->Summon(mobVnum, mountItem, false);
	}
}

void CHARACTER::EquipMountSkin()
{
	if (!IsRidingMount()) return;
	
	CMountSystem* mountSystem = GetMountSystem();
	LPITEM mountItem = GetWear(WEAR_COSTUME_MOUNT);
	if (!mountSystem || !mountItem) return;

	DWORD mobVnum = mountItem->GetValue(1);
	if (GetMountVnum() == mobVnum)
		mountSystem->Unmount(mobVnum);
	
	mountSystem->Unsummon(mobVnum);
	CheckMount();
	UpdateChangeMountSkinTime();
}

void CHARACTER::RemoveMountSkin(LPITEM mountSkin)
{
	if (!IsRidingMount()) return;
	
	CMountSystem* mountSystem = GetMountSystem();
	if (!mountSystem || !mountSkin) return;

	DWORD mobVnum = mountSkin->GetValue(1);
	if (GetMountVnum() == mobVnum)
		mountSystem->Unmount(mobVnum);
	
	mountSystem->Unsummon(mobVnum);
	CheckMount();
	UpdateChangeMountSkinTime();
}