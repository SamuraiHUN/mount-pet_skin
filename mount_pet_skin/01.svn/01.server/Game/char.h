search this:

	public:
		CPetSystem*			GetPetSystem()				{ return m_petSystem; }
		void 				PetSummon(LPITEM petItem);
		void 				PetUnsummon(LPITEM petItem);
		void 				CheckPet();
		bool 				IsPetSummon();

	protected:
		CPetSystem*			m_petSystem;

	public:
		CMountSystem*		GetMountSystem() { return m_mountSystem; }
		
		void 				MountSummon(LPITEM mountItem);
		void 				MountUnsummon(LPITEM mountItem);
		void 				CheckMount();
		bool 				IsRidingMount();

	protected:
		CMountSystem*		m_mountSystem;

replace with this:

	public:
		CPetSystem*			GetPetSystem()				{ return m_petSystem; }
		void 				PetSummon(LPITEM petItem);
		void 				PetUnsummon(LPITEM petItem);
		void 				EquipPetSkin();
		void 				RemovePetSkin(LPITEM petSkin);
		void 				CheckPet();
		bool 				IsPetSummon();
		
		bool				CanChangePetSkin();
		void				UpdateChangePetSkinTime() { m_iChangePetSkinTime = thecore_pulse(); }
		int					GetLastChangePetSkinTime() const { return m_iChangePetSkinTime; }

	protected:
		CPetSystem*			m_petSystem;

	private:
		int					m_iChangePetSkinTime;

	public:
		CMountSystem*		GetMountSystem() { return m_mountSystem; }
		
		void 				MountSummon(LPITEM mountItem);
		void 				MountUnsummon(LPITEM mountItem);
		void 				EquipMountSkin();
		void 				RemoveMountSkin(LPITEM petSkin);
		void 				CheckMount();
		bool 				IsRidingMount();

		bool				CanChangeMountSkin();
		void				UpdateChangeMountSkinTime() { m_iChangeMountSkinTime = thecore_pulse(); }
		int					GetLastChangeMountSkinTime() const { return m_iChangeMountSkinTime; }
	protected:
		CMountSystem*		m_mountSystem;

	private:
		int					m_iChangeMountSkinTime;