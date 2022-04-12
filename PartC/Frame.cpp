/**********************************************************************
Filename: Frame.cpp
Author:	Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
Course Name/Number:	C++ Programming CST8219
Assignment #: Final Project
Assignment name: Animation Project in C++
Due Date: April 11,2022
Professor:	Surbhi Bahri, Justin Martin
Purpose: define and implement the Frame object
*********************************************************************/

#include <iostream>
#include "Frame.h"

/********************************************************************
Function name: Frame Constructor
Purpose: Initialize values for a Frame object
parameters: char* frameName, double duration
return: void
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
Frame::Frame(char* frameName, double duration)
{
	this->frameName = new char[strlen(frameName) + 1];
	strcpy(this->frameName, frameName);

	this->duration = duration;
}


/********************************************************************
Function name: Frame Constructor
Purpose: Initialize values for a Frame object
parameters: const Frame& frame
return: void
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
Frame::Frame(const Frame& frame)
{
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(this->frameName, frame.frameName);

	this->duration = frame.duration;
}


/********************************************************************
Function name: ~Frame
Purpose: Free the allocated memory for frameName
parameters: void
return: void
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
Frame::~Frame()
{
	delete[] this->frameName;
}

/********************************************************************
Function name: operator=
Purpose: Overloaded operator = to initialize a Frame
parameters: const Frame& frame
returnn: Frame& newFrame
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
Frame& Frame::operator=(const Frame& frame)
{
	delete[] this->frameName;
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(this->frameName, frame.frameName);
	this->duration = frame.duration;
	return *this;
}

/********************************************************************
Function name: operator<<
Purpose: Overloaded operator << to print out a Frame members
parameters: ostream& output, Frame& frame
return: ostream& output
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
std::ostream& operator<<(std::ostream& output, Frame& frame)
{
	output << "frame name = " << frame.frameName << "; duration = " << frame.duration;
	return output;
}
