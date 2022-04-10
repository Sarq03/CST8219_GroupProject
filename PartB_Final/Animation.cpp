//Animation.cpp
#include "Frame.h"
#include "Animation.h"
#include <iostream>
using namespace std;

void Animation::InsertFrame() {
	//Instantiating a new frame.
	Frame* newFrame = new Frame;
	//This holds the user input
	char* newInput = new char[150];
	//This will take the userlength of the user input (name of frame)
	int userlength = strlen(newInput);
	//Asks user to name a frame that will go inside the animation that has just been created.
	cout << "Insert a frame in the animation\n Please enter the frame name: " << endl;  
	//User inputs the name of the frame.
	cin >> newInput; 
	//This stores the memory of the user input (name of frame) using linked list.
	newFrame->GetFrameName() = new char[userlength+1]; 
	//This places the variable name from the temporary storage to GetFrameName in Frame.h
	strcpy(newFrame->GetFrameName(), newInput); 
	//This removes whatever was inside the dynamic variable (we do this since we relocated the user input to GetFrameName)
	delete[] newInput; 
	//Moves the pointer to the next unoccupied spot in the frame.
	newFrame->GetpNext() = frames;
	//Makes frames the new 
	frames = newFrame; 



}

Animation::Animation() {

	frames = NULL;
	animationName = NULL;
	//This holds the user input 
	char* newInput = new char[150];
	//This will take the userlength of the user input (name of animation)
	int userlength = strlen(newInput);
	//Asking for user input for animation name
	cout << "Please enter the Animation Name: "; 
	//User inputs the name of the animation
	cin >> newInput; 
	//This allocates the user input (name of animation) memory.
	animationName = new char[userlength+1];
	//This places the variable name from the temporary storage to the animationName variable in Animation.h
	strcpy(animationName, newInput); 
	//This removes whatever was inside the dynamic variable (we do this since we relocated the user input to animationName)
	delete[] newInput; 

}


void Animation::ReportAnimation() {
	int interval = 0;
	Frame* instanceFrame = frames;
	// This will report the name of the animation.
	cout << "Animation name is: " << animationName << endl; 
	//if frame exists:
	while (instanceFrame) {
		//Display the image, count number of files and display the file name.
		cout << "Frame #" << interval << ", file name = " << instanceFrame->GetFrameName() << endl; 
		instanceFrame = instanceFrame->GetpNext();
		interval++;
	}

}


void Animation::DeleteFrame() {
	//New instance of frame
	Frame* instanceFrame = frames;  
	//If there are no frames the print out the error message below.
	if (instanceFrame == NULL) {
		cout << "There are no frames to delete." << endl;
	}
		else {
			//Loop to second last frame
			while (instanceFrame->GetpNext()->GetpNext() != NULL) {
				instanceFrame = instanceFrame->GetpNext();
			}
			//These will delete the name of frame as well as its pointer.
			delete(instanceFrame->GetpNext()->GetFrameName());
			delete(instanceFrame->GetpNext());
			//Since we deleted the pointer, it must be set to null.
			instanceFrame->GetpNext() = NULL;
		}
	}

void Animation::EditFrame() {
	//Instantiating the interval as 0 (since the frame numbers start at 0 on the example output.)
	int interval = 0;
	//Instantiating userInput.
	int userInput = 0;
	//Points to frame class
	Frame* thisFrame = frames;
	//New instance of frame
	Frame* instanceFrame = frames;
	//While there is a frame
	while (instanceFrame) {
		//Goes to the next frame
		instanceFrame = instanceFrame->GetpNext();
		//Counts how many frames there are using a loop
		interval++; 
	}
	//Shows how many frames there are and their index.
	cout << "There are " << interval << " frame(s) in the list. Please specify the index (<=" << interval-1 << ") to edit at: ";
	//User will input which index they want to edit.
	cin >> userInput; 
	
	//While user input is not 0
	while (userInput != 0) { 
		//go through all frames until the user input matches with the frame
		thisFrame = thisFrame->GetpNext(); 
		--userInput;
	}
	//Displays the name of frame and asks what the user wants to replace it with.
	cout << "The name of this Frame is " << thisFrame->GetFrameName() << ". What do you wish to replace it with? "; 
	//This will delete the GetFrameName (one that user chose)
	delete thisFrame->GetFrameName(); 
	//Need to make the frame equal null after deletion.
	thisFrame->GetFrameName() = NULL; 
	//This holds the user input
	char* newInput = new char[150]; 
	//User will input name of new frame.
	cin >> newInput; 
	//Takes the userlength of the new framename.
	int userlength = strlen(newInput);
	//This stores the memory of the user input (name of new frame) using linked list.
	thisFrame->GetFrameName() = new char[userlength+1];
	strcpy(thisFrame->GetFrameName(), newInput);
	//This will delete the temporary value
	delete[] newInput;

}

Animation::~Animation() {
	Frame* push;
	Frame* destructorFrame = frames;
	
	//delete all frames in animiation //This will delete the frames that are inside of the animation.
	while (destructorFrame != NULL) {
		//
		push = destructorFrame->GetpNext(); 
		delete(destructorFrame->GetFrameName());
		//deletes the frame
		delete(destructorFrame);
		//loops to next frame by setting the frame to the next frame to be deleted
		destructorFrame = push;
	}

}