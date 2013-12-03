/* ***** BEGIN LICENSE BLOCK *****
Version: MPL 1.1/LGPL 2.1/GPL 2.0

The contents of this file are subject to the Mozilla Public License Version 
1.1 (the "License"); you may not use this file except in compliance with
...
for the specific language governing rights and limitations under the
License.

The Original Code is for LuminousForts.

The Initial Developer of the Original Code is Hekar Khani.
Portions created by the Hekar Khani are Copyright (C) 2010
Hekar Khani. All Rights Reserved.

Contributor(s):
  Hekar Khani <hekark@gmail.com>

Alternatively, the contents of this file may be used under the terms of
either of the GNU General Public License Version 2 or later (the "GPL"),
...
the terms of any one of the MPL, the GPL or the LGPL.

***** END LICENSE BLOCK ***** */


#ifndef CAMMOCRATECLASSIC_H
#define CAMMOCRATECLASSIC_H

#if 0

class CAmmoCrateClassic : public CItem_AmmoCrate
{
public:
	DECLARE_CLASS( CAmmoCrateClassic, CItem_AmmoCrate );
	DECLARE_DATADESC();

	void Spawn();
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
private:
	int m_iSourcefortsTeam;
};

#endif // 0

#endif // CAMMOCRATECLASSIC_H