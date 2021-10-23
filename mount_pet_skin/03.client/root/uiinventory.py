search this:

	def RefreshCostumeSlot(self):
		getItemVNum=player.GetItemIndex

		for i in xrange(item.COSTUME_SLOT_COUNT):
			slotNumber = item.COSTUME_SLOT_START + i
			self.wndEquip.SetItemSlot(slotNumber, getItemVNum(slotNumber), 0)


add after this:

		for i in xrange(player.NEW_EQUIPMENT_SLOT_START):
			slotNumber = player.NEW_EQUIPMENT_SLOT_START + i
			self.wndEquip.SetItemSlot(slotNumber, getItemVNum(slotNumber), 0)