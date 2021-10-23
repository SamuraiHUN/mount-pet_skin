search this:

enum ECostumeSubTypes


extend with:

	ITEM_PET_SKIN,
	ITEM_MOUNT_SKIN,
	
	//Dont forget you need match this number with Protoreader.cpp arSub28 + ItemCsvReader.cpp

search this:

enum EItemWearableFlag

extend with:

	WEARABLE_PET_SKIN			= (1 << 19), // Use the next number
	WEARABLE_MOUNT_SKIN			= (1 << 20), // Use the next number

