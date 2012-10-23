//das ist ein test!

#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
	virtual ~Object();
	virtual void Print() = 0;

protected:
	Object();
};

#endif

//conflict should occur