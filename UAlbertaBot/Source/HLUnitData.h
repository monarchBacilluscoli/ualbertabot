#pragma once
#include "UnitData.h"

namespace UAlbertaBot{
	class HLUnitData
	{
		std::vector<int>						numDeadUnits;
		std::vector<int>						numUnits;
		std::vector<int>						numCompletedUnits;

		int										mineralsLost;
		int										gasLost;

		std::unordered_map<int, UnitInfo>		_unitMap;//id->info
		int										_highestID;
	public:
		HLUnitData();
		HLUnitData(const UnitData &data);
		virtual ~HLUnitData();

		//virtual methods
		void	getCloakedUnits(std::set<UnitInfo> & v)				const;
		int		numCloakedUnits()									const;
		void	getDetectorUnits(std::set<UnitInfo> & v)			const;
		void	getFlyingUnits(std::set<UnitInfo> & v)				const;
		bool	hasCloakedUnits()									const;
		bool	hasDetectorUnits()									const;
		int		getNumUnits(BWAPI::UnitType t)						const;
		int		getNumCompletedUnits(BWAPI::UnitType t)				const;
		int		getNumDeadUnits(BWAPI::UnitType t)					const;
		const	std::unordered_map<int, UnitInfo> & getUnits()		const	{ return _unitMap; }

		//new methods
		void	removeUnit(int id);
		void	addUnit(const UnitInfo &unit);
		bool	finishUnit(BWAPI::UnitType type);
		//std::vector<UnitInfo> getUnitVector()						const;
		int		highestID()											const {return _highestID;};

	};
}
