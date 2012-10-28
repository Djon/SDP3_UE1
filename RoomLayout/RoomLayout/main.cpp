#include <vld.h>
#include "Room.h"
#include "Wall.h"
#include "Door.h"
#include "RoomLayout.h"

int main() 
{
	Side* s1 = new Wall("green",North);
	Side* s2 = new Wall("blue", West);
	Side* s3 = new Door(false, East);
	Side* s4 = new Door(true, South);
	
	Room* r1 = new Room;
	r1->AddSide(s3);
	r1->AddSide(s1);
	r1->AddSide(s2);
	r1->AddSide(s4);


	Side* s5 = new Door(true, North);
	Side* s6 = new Door(false, West);
	Side* s7 = new Door(false, East);
	Side* s8 = new Wall("green", South);

	Room* r2 = new Room;
	r2->AddSide(s5);
	r2->AddSide(s6);
	r2->AddSide(s7);
	r2->AddSide(s8);


	Side* s9 = new Wall("yellow", North);
	Side* s10 = new Door(false, West);
	Side* s11 = new Door(false, East);
	Side* s12 = new Door(false, South);

	Room* r3 = new Room;
	r3->AddSide(s9);
	r3->AddSide(s10);
	r3->AddSide(s11);
	r3->AddSide(s12);

	RoomLayout rl1;
	rl1.AddRoom(r1);
	rl1.AddRoom(r2);
	rl1.AddRoom(r3);

	rl1.Print();

	return 0;
}