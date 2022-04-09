/**********************************************************************
Filename: Frame.cpp
Version: 3.8 
Author:	Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
Course Name/Number:	C++ Programming CST8219
Assignment #: Final Project
Assignment name: Animation Project in C++
Due Date: April 11,2022
Professor:	Surbhi Bahri, Justin Martin
Purpose: Initialize variables and define the functions related to Frame object
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Frame.h"
using namespace std;

/********************************************************************
Function name: Frame
Purpose: Initialize values for a Frame object
In parameters: char* frameName, double duration
Out parameters: none
Version: 3.8
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
Frame::Frame(char* frameName, double duration) {
	//Copy the name
	this->frameName = new char[strlen(frameName) + 1];
	strcpy(this->frameName, frameName);

	//Copy the duration
	this->duration = duration;
}

/********************************************************************
Function name: Frame
Purpose: Initialize values for a Frame object
In parameters: const Frame& frame
Out parameters: none
Version: 3.8
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
Frame::Frame(const Frame& frame) {
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(this->frameName, frame.frameName);

	//Copy the duration
	this->duration = frame.duration;
}

/********************************************************************
Function name: ~Frame
Purpose: Free the allocated memory for frameName
In parameters: none
Out parameters: none
Version: 3.8
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
Frame::~Frame() {
	delete[] this->frameName;
}

/********************************************************************
Function name: operator=
Purpose: Overloaded operator = to initialize a Frame
In parameters: const Frame& frame
Out parameters: Frame& newFrame
Version: 3.8
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
Frame& Frame::operator= (const Frame& frame) {
	//Copy the name
	delete [] this->frameName;
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(this->frameName, frame.frameName);

	//Copy the duration
	this->duration = frame.duration;

	return *this;
}

/********************************************************************
Function name: operator<<
Purpose: Overloaded operator << to print out a Frame members
In parameters: ostream& output, Frame& frame
Out parameters: ostream& output
Version: 3.8
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
ostream& operator<< (ostream& output, Frame& frame) {
	output << "frameName = " << frame.frameName << "; duration = " << frame.duration;
	return output;
}