#include "Room.h"
#include "Wall.h"
#include "Door.h"
#include "RoomLayout.h"

int main() 
{
	Side* s1 = new Wall("green",North);
	Side* s2 = new Wall("blue", West);
	Side* s3 = new Door(false, East);
	Side* s4 = new Wall("black", South);
	
	Room r1;
	r1.AddSide(s1);
	r1.AddSide(s2);
	r1.AddSide(s3);
	r1.AddSide(s4);

	Side* s5 = new Door(false, North);
	Side* s6 = new Door(false, West);
	Side* s7 = new Door(false, East);
	Side* s8 = new Door(false, South);

	Room r2;
	r2.AddSide(s5);
	r2.AddSide(s6);
	r2.AddSide(s7);
	r2.AddSide(s8);

	//r1.Print();
	//r2.Print();

	RoomLayout rl1;
	rl1.AddRoom(&r1);
	rl1.AddRoom(&r2);

	rl1.Print();

	return 0;
}