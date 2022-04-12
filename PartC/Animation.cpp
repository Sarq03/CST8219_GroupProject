/**********************************************************************
Filename: Animation.cpp
Author:	Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
Course Name/Number:	C++ Programming CST8219
Assignment #: Final Project
Assignment name: Animation Project in C++
Due Date: April 11,2022
Professor:	Surbhi Bahri, Justin Martin
Purpose: Initialize variables and define the functions related to Animation object
*********************************************************************/
#include <forward_list>
#include <iostream>
#include <string>
#include "Frame.h"
#include "Animation.h"

/********************************************************************
Function name: EditFrame
Purpose: edit a frame inside the linked list
parameters: void
return: void
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
void Animation::EditFrame()
{


	char name[100];
	double duration;
	int counter = 0;
	int counter2 = 0;
	int choice;

	std::cout << "Edit a Frame in the Animation" << std::endl;
	
	if (frames.empty()) {
		std::cout << "There is no frame in the animation\n";
		return;
	}

	for (auto i = frames.begin(); i != frames.end(); i++) {
		counter++;
	}
	std::cout <<"There are " << counter << "Frame(s) in the list. Please specify the index (<=0) to edit it:" << std::endl;
	std::cin >> choice;
	
	for (auto i = frames.begin(); i != frames.end(); i++) {
		if (counter2 == choice) {
			std::cout << "The name and duration of this Frame are " << *i << ". \nWhat do you wish to replace it with? \n";
			std::cin >> name;
			std::cin >> duration;
			Frame* newFrame = new Frame(name, duration);
			*i = *newFrame;
			std::cout << "Frame " << choice << " edit completed\n";
			break;
		}
		counter2++;
	}


}


/********************************************************************
Function name: DeleteFrame
Purpose: Delete the first frame inside the Animation
parameters: none
return: none
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
void Animation::DeleteFrame()
{
	if (frames.empty()) {
		std::cout << "There is no frame to be deleted!\n";
		return;
	}

	frames.pop_front();
	std::cout << "First Frame deleted" << std::endl;

}

/********************************************************************
Function name: operator>>
Purpose: inserts a frame
parameters: istream& input, Animation& A
return: istream& input
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
std::istream& operator>>(std::istream& input, Animation& animation)
{

	char name[100];
	double duration;

	std::cout << "Insert a Frame in the Animation\n";
	std::cout << "Please enter the frame name: ";
	input >> name;

	std::cout << "Please enter the Frame duration: ";
	input >> duration;

	Frame* tmp = new Frame(name, duration);

	animation.frames.push_front(*tmp);
	std::cout << "Frame " << name << " added at the front of frames " << std::endl;

	return input;
}


/********************************************************************
Function name: operator<<
Purpose: outputs details of the animation
parameters: ostream& output, Animation& A
return: ostream& output
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
std::ostream& operator<<(std::ostream& output, Animation& animation)
{
	int counter = 0;
	output << "\tAnimation Name is " << animation.AnimationName << std::endl;
	output << "\tReport the Animation" << std::endl;
	if (animation.frames.empty()) {
		output << "\tNo frames in the Animation " << std::endl;
		
	}
	else{

		
		for (auto i = animation.frames.begin(); i != animation.frames.end(); i++) {
			output << "\tFrame " << counter++ << ": " << *i << std::endl;
		}
	}

	return output;

}
