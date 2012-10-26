#include "Room.h"
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

Room::Room()
{
}

Room::~Room()
{
}

//void PrintSide(Side* side)
//{
//	side->Print();
//}

//
//void PrintNorth(TVec const& sides)
//{
//	TVecItor itor = sides.begin();
//	for (;itor < sides.end(); ++itor)
//	{
//		if (((*itor)->getDirection == North) || ((*itor)->getDirection == South))
//		{
//			PrintWallOrDoor((*itor));
//		}
//		else
//		{
//			std::cout << "*       *" << std::endl;
//		if 
//			std::cout << "*       *" << std::endl;
//		}
//		
//	}
//}
//
void PrintWallOrDoorNS(Side* side/*, bool & wasDoor*/) 
{
	/*if (!wasDoor)
	{*/
		if (side->IsDoor() == false)
		{
			std::cout << "*********" << std::endl;
		}
		else
		{
			std::cout << "****D****" << std::endl;
			/*wasDoor = true;*/
		}
	/*}
	else 
	{
		wasDoor = false;
	}*/
}

void PrintWallOrDoorOW(Side* side) 
{
	if (side->IsDoor() == false)
	{
		std::cout << "*";
	}
	else
	{
		std::cout << "D";
	}
}

void PrintTwoStars()
{
	std::cout << "*       *" << std::endl;
}

void PrintSpaces()
{
	std::cout << "       ";
}

void Room::Print(/*bool & wasDoor*/) 
{
	//Wenn Raum nicht vier Seiten hat
	if (mSides.size() != maxWalls) {
		std::cout << "zu wenig seiten" << std::endl;
		return;
	}

	TVecItor itor = mSides.begin();

	//N
	PrintWallOrDoorNS(*(itor)/*,wasDoor*/);
	++itor;

	//W+O
	PrintTwoStars();
	PrintWallOrDoorOW((*itor));
	PrintSpaces();
	++itor;
	PrintWallOrDoorOW((*itor));
	std::cout << std::endl;
	PrintTwoStars();
	++itor;
	//S
	PrintWallOrDoorNS(*(itor)/*,wasDoor*/);




	/*else
	{
	TVecItor itor = mSides.begin();
	for (;itor < mSides.end(); ++itor)
	{
	if((*itor)->getSideType == Wall)
	{
	if((*itor)->getDirection == North)
	{
	std::cout << "*********" << std::endl;
	}
	else if ((*itor)->getDirection == South)
	{
	std::cout << "*********" << std::endl;
	}
	else if ((*itor)->getDirection == West)
	{

	std::cout << "*
	}
	else 
	{
	}
	}
	else
	{
	if((*itor)->getDirection == North)
	{
	std::cout << "****D****" << std::endl;
	}
	else if ((*itor)->getDirection == South)
	{
	std::cout << "****D****" << std::endl;
	}
	}
	}
	}

	std::for_each(mSides.begin(), mSides.end(), PrintSide);*/
}

bool Room::AddSide(Side* side)
{
	TVecItor itor = mSides.begin();

	//max. Anzahl der Wände noch nicht erreicht?
	if (mSides.size() < maxWalls)
	{
		//Nur Seiten einfügen, die noch nicht vorhanden sind
		for (;itor < mSides.end();++itor)
		{
			if ((*itor)->getDirection() == side->getDirection())
			{
				return false;
			}
		}
		//****************evtl noch reihenfolge überprüfen
		mSides.push_back(side);
		return true;
	}
	else
	{
		return false;
	}
}
