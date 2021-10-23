Search this:

	PyModule_AddIntConstant(poModule, "COSTUME_SLOT_START",			c_Costume_Slot_Start);

add before this:

	PyModule_AddIntConstant(poModule, "COSTUME_TYPE_PET_SKIN",		CItemData::ITEM_PET_SKIN);
	PyModule_AddIntConstant(poModule, "COSTUME_TYPE_MOUNT_SKIN",	CItemData::ITEM_MOUNT_SKIN);

search this:

	PyModule_AddIntConstant(poModule, "COSTUME_SLOT_END",			c_Costume_Slot_End);

add after this:

	PyModule_AddIntConstant(poModule, "COSTUME_SLOT_PET_SKIN",		c_Equipment_pet_skin);
	PyModule_AddIntConstant(poModule, "COSTUME_SLOT_MOUNT_SKIN",	c_Equipment_mount_skin);