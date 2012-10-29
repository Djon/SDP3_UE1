///////////////////////////////////////////////////////////////////////////
// Workfile : Object.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Header for Object.cpp
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
	//virtual Destructor for baseclass
	virtual ~Object();
protected:
	//Default CTor for baseclass
	Object();
};

#endif