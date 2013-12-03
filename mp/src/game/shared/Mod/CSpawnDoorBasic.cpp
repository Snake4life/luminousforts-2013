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

#include "cbase.h"
#include "CSpawnDoorBasic.h"

//
//	Name: CSpawnDoorBasic
//	Author: Hekar Khani
//	Description: Simple "Spawn Door" based on the TF2 spawn door concept.
//				Basically, it's an invisible barrier that blocks enemy players
//				and fire from entering.
//	Notes:
//
LINK_ENTITY_TO_CLASS( lf_func_spawndoor, CSpawnDoorBasic );
BEGIN_DATADESC( CSpawnDoorBasic )
	DEFINE_KEYFIELD( m_iTeamNum, FIELD_INTEGER, "team" ),
END_DATADESC()

CSpawnDoorBasic::CSpawnDoorBasic()
{
}

CSpawnDoorBasic::~CSpawnDoorBasic()
{
}

void CSpawnDoorBasic::Spawn( void )
{
	BaseClass::Spawn();
	RemoveEffects( EF_NODRAW );

	//SetCollisionGroup( COLLISION_GROUP_BLOCKING );
	SetSolid( SOLID_VPHYSICS );
	SetMoveType( MOVETYPE_NONE );
	SetModel( STRING( GetModelName() ) );
	CreateVPhysics();
}

bool CSpawnDoorBasic::ShouldCollide( int collisionGroup, int contentsMask ) const
{
	if ( collisionGroup == COLLISION_GROUP_PLAYER || collisionGroup == COLLISION_GROUP_PLAYER_MOVEMENT )
	{
		// Don't let players not on team in
		switch( GetTeamNumber() )
		{
		case SDK_TEAM_BLUE:
			if ( ( contentsMask & CONTENTS_TEAM1 ) )
				return false;
			else
				return true;
			break;

		case SDK_TEAM_RED:
			if ( ( contentsMask & CONTENTS_TEAM2 ) )
				return false;
			else
				return true;
			break;
		}
	}

	return true;
}