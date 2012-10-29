///////////////////////////////////////////////////////////////////////////
// Workfile : Main.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Testdriver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "Room.h"
#include "Wall.h"
#include "Door.h"
#include "RoomLayout.h"


//empty Roomlayout
void testcase0()
{
	std::cout << "Testcase0: Empty roomlayout" << std::endl;

	RoomLayout rl1;

	rl1.Print();

	std::cout << std::endl << std::endl;
}

//Roomlayout with empty Rooms
void testcase1()
{
	std::cout << "Testcase1: Roomlayout with empty rooms" << std::endl;

	RoomLayout rl1;

	Room* r1 = new Room;
	Room* r2 = new Room;

	rl1.AddRoom(r1);
	rl1.AddRoom(r2);

	rl1.Print();

	delete r1;
	delete r2;

	std::cout << std::endl << std::endl;
}

//Roomlayout with wrong Rooms
void testcase2()
{
	std::cout << "Testcase2: Roomlayout with wrong rooms" << std::endl;

	RoomLayout rl1;

	Room* r1 = new Room;
	Room* r2 = new Room;

	Side* s1 = new Wall("Green",North);
	Side* s2 = new Wall("Blue",West);
	Side* s3 = new Door(true,East);
	Side* s4 = new Door(false,South);

	Side* s5 = new Wall("Green",North);
	Side* s6 = new Wall("Blue",West);
	Side* s7 = new Door(true,East);
	Side* s8 = new Door(false,South);

	r1->AddSide(s3);
	r1->AddSide(s1);
	r1->AddSide(s2);
	r1->AddSide(s4);

	r2->AddSide(s6);
	r2->AddSide(s8);
	r2->AddSide(s7);
	r2->AddSide(s5);


	rl1.AddRoom(r1);
	rl1.AddRoom(r2);

	rl1.Print();

	delete r2;

	std::cout << std::endl << std::endl;
}

//Roomlayout with correct Rooms
void testcase3()
{
	std::cout << "Testcase3: Roomlayout with correct rooms" << std::endl;

	RoomLayout rl1;

	Room* r1 = new Room;
	Room* r2 = new Room;

	Side* s1 = new Wall("Green",North);
	Side* s2 = new Wall("Blue",West);
	Side* s3 = new Door(true,East);
	Side* s4 = new Door(false,South);

	Side* s5 = new Door(true,North);
	Side* s6 = new Wall("Blue",West);
	Side* s7 = new Door(true,East);
	Side* s8 = new Door(false,South);

	r1->AddSide(s3);
	r1->AddSide(s1);
	r1->AddSide(s2);
	r1->AddSide(s4);

	r2->AddSide(s6);
	r2->AddSide(s8);
	r2->AddSide(s7);
	r2->AddSide(s5);


	rl1.AddRoom(r1);
	rl1.AddRoom(r2);

	rl1.Print();

	std::cout << std::endl << std::endl;
}


//Roomlayout with correct rooms
//Trying to add a fifth side to one room
void testcase4()
{
	std::cout << "Testcase4: Roomlayout with correct rooms." << std::endl 
		<< "Trying to add a fifth side to one room" << std::endl;

	RoomLayout rl1;

	Room* r1 = new Room;
	Room* r2 = new Room;

	Side* s1 = new Wall("Green",North);
	Side* s2 = new Wall("Blue",West);
	Side* s3 = new Door(true,East);
	Side* s4 = new Wall("Black",South);

	Side* s5 = new Wall("White",North);
	Side* s6 = new Wall("Blue",West);
	Side* s7 = new Door(true,East);
	Side* s8 = new Door(false,South);
	Side* s9 = new Door(false,North);

	r1->AddSide(s3);
	r1->AddSide(s1);
	r1->AddSide(s2);
	r1->AddSide(s4);

	r2->AddSide(s6);
	r2->AddSide(s8);
	r2->AddSide(s7);
	r2->AddSide(s5);
	r2->AddSide(s9);


	rl1.AddRoom(r1);
	rl1.AddRoom(r2);

	rl1.Print();

	delete s9;

	std::cout << std::endl << std::endl;
}


int main() 
{
	testcase0();
	testcase1();
	testcase2();
	testcase3();
	testcase4();

	return 0;
}