#include "AnimationManager.h"
#include <iostream>
void AnimationManager::EditAnimation()
{

	//output to user 
	//Which animation do you wish to edit? Please provide the index (from 0 to n):	__		Editing Animation #__


}

void AnimationManager::DeleteAnimation()
{
}

std::istream& operator>>(std::istream& input, AnimationManager&)
{
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& output, AnimationManager& manager)
{
	int counter = 0;

	output << "Animation Manager: " << manager.managerName << std::endl;
	for (auto i = manager.animations.begin(); i != manager.animations.end(); i++) {
		output << "Animation: " << counter++ << std::endl;
		manager.animations << (output, i);
	}

	return output;

	// TODO: insert return statement here
}
