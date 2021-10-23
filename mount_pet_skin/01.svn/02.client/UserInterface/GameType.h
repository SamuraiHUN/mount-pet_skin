search this:

#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	const DWORD c_New_Equipment_Start = c_Equipment_Start
	
extend with:

	const DWORD c_Equipment_pet_skin = c_New_Equipment_Start + 4;
	const DWORD c_Equipment_mount_skin = c_New_Equipment_Start + 5;
	
+ Modify this line:

	const DWORD c_New_Equipment_Count = 6;


// Don't forget need the match with length.h
