on top:

#include "PetSystem.h"

search this:

		else if (GetSubType() == COSTUME_WEAPON)
			return WEAR_COSTUME_WEAPON;


add under this:

		else if (GetSubType() == ITEM_PET_SKIN)
			return WEAR_PET_SKIN;
		else if (GetSubType() == ITEM_MOUNT_SKIN)
			return WEAR_MOUNT_SKIN;

search this:

		if (IsMountItem() || IsPetItem())

modify to:

		if (IsMountItem() || IsPetItem() || IsPetSkin() || IsMountSkin())
		
search this:

	ch->BuffOnAttr_AddBuffsFromItem(this);

add under this:

	if (IsPetSkin())
		m_pOwner->EquipPetSkin();

	if (IsMountSkin())
		m_pOwner->EquipMountSkin();

search this in (bool CItem::Unequip()):

	m_bEquipped	= false;

add under this:

	if (IsPetSkin())
		m_pOwner->RemovePetSkin(this);
	
	if (IsMountSkin())
		m_pOwner->RemoveMountSkin(this);

search this:

bool CItem::IsMountItem()
{
	if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_MOUNT)
		return true;
	
	return false;
}

add under this:

bool CItem::IsPetSkin()
{
	return (GetType() == ITEM_COSTUME && GetSubType() == ITEM_PET_SKIN);
}

bool CItem::IsMountSkin()
{
	return (GetType() == ITEM_COSTUME && GetSubType() == ITEM_MOUNT_SKIN);
}
