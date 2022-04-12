/**********************************************************************
Filename: AnimationManager.cpp
Author:	Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
Course Name/Number:	C++ Programming CST8219
Assignment #: Final Project
Assignment name: Animation Project in C++
Due Date: April 11,2022
Professor:	Surbhi Bahri, Justin Martin
Purpose: Initialize variables and define the functions related to Animation object
*********************************************************************/
#include <vector> 
#include <iostream>
#include <string>
#include <forward_list>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"

/********************************************************************
Function name: EditAnimation
Purpose: Edit a selected Animation by inserting, deleting or editing a frame
parameters: void
return: void
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
void AnimationManager::EditAnimation()
{
	if (animations.empty()) {
		std::cout << "no animations to edit" << std::endl;
		return;
	}
	int counter = 0;
	int choice = -1;
	int menuInput = -1;

	for (auto i = animations.begin(); i != animations.end(); i++) {
		counter++;
	}

	std::cout << "Which animation do you wish to edit? Please provide the index (from 0 to " << counter-1 << ") :" << std::endl;
	std::cin >> choice;
	counter = 0;
	for (auto i = animations.begin(); i != animations.end(); i++) {
		if (counter == choice) {
			bool flag = true;
			std::cout << "Editing Animation #" << counter << std::endl;

			std::cout << "MENU" << std::endl;
			std::cout << "1. Insert a Frame at the Front\n2. Delete a last Frame\n3. Edit a frame\n4. Quit" << std::endl;
			std::cin >> menuInput;

			std::cout << "Selected Option " << menuInput << std::endl;
			while (flag == true) {

				switch (menuInput) {
				case 1:
					std::cin >> *i;
					break;
				case 2:
					(*i).DeleteFrame();
					break;
				case 3:
					(*i).EditFrame();
					break;
				case 4:
					flag = false;
					std::cout << "Animation #" << counter << " edit is complete" << std::endl;
				}
				if (flag) {

					std::cout << "1. Insert a Frame at the Front\n2. Delete a last Frame\n3. Edit a frame\n4. Quit" << std::endl;
					std::cin >> menuInput;
				}
			}

		}
		counter++;
	}



}

/********************************************************************
Function name: DeleteAnimation
Purpose: Delete an Animation
parameters: void
return: void
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
void AnimationManager::DeleteAnimation()
{
	int counter = 0;
	int choice;

	std::cout << "Delete an Animation from the Animation manager" << std::endl;

	if (animations.empty()) {
		std::cout << "There is no Animation to delete!" << std::endl;
		return;
	}
	
	
	for (auto i = animations.begin(); i != animations.end(); i++) {
		counter++;
	}

	std::cout << "Which Animation do you wish to delete? Please give the the index in the range 0 to " << counter - 1 << "): ";
	std::cin >> choice;


	counter = 0;
	for (auto i = animations.begin(); i != animations.end(); i++) {
		if (counter == choice) {
			animations.erase(i);
			break;
		}
		counter++;
	}
	std::cout << "Animation #" << choice << " deleted" << std::endl;

}

/********************************************************************
Function name: operator>>
Purpose: Add an Animation
parameters: istream& input, AnimationManager& M
return: istream& input
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
std::istream& operator>>(std::istream& input, AnimationManager& manager)
{
	std::string name;
	std::cout << "Add an Animation to the Animation Manager " << std::endl;
	std::cout << "Please enter the Animation Name: ";
	input >> name;

	Animation* tmp = new Animation(name);
	manager.animations.push_back(*tmp);
	std::cout << "Animation entitles " << name << " added to the back of the animations" << std::endl;
	return input;
}


/********************************************************************
Function name: operator<<
Purpose: Output the Animations
parameters: ostream& output, AnimationManager& M
return: ostream& output
Author: Sarfraj Singh, Daniel Samociuk, Belent Patrus, Haroun Benmeddour
**********************************************************************/
std::ostream& operator<<(std::ostream& output, AnimationManager& manager)
{
	int counter = 0;

	output << "Animation Manager: " << manager.managerName << std::endl;
	for (auto i = manager.animations.begin(); i != manager.animations.end(); i++) {
		output << "Animation: " << counter++ << std::endl;
		output << *i;
	}
	return output;

	
}
