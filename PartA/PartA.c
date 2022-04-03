// part1.c
//@author: Surbhi Bahri
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC // need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); 
// in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>
#include <stdio.h>
#include <string.h>
typedef enum { FALSE = 0, TRUE } BOOL;
struct Frame {
	char* frameName;
	struct Frame* pNext;
};
typedef struct {
	char* animationName;
	struct Frame* frames;
}Animation;
// Forward declarations
void InitAnimation(Animation*);
void InsertFrame(Animation*);
void DeleteFrame(Animation*);
void EditFrame(Animation*);
void ReportAnimation(Animation*);
void CleanUp(Animation*);
int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	Animation RG;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |
		_CRTDBG_LEAK_CHECK_DF);
	InitAnimation(&RG);
	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit\n");
		scanf("%c", &response);
		getchar();
		switch (response)
		{
		case '1':InsertFrame(&RG);break;
		case '2':DeleteFrame(&RG);break;
		case '3':EditFrame(&RG);break;
		case '4':ReportAnimation(&RG);break;
		case '5':RUNNING = FALSE; CleanUp(&RG); break;
		default:printf("Please enter a valid option\n");
		}
	}
	return 0;
}

void InitAnimation(Animation* animation) {

	animation->animationName = "Animation 1";

	animation->frames = malloc(sizeof(struct Frame*));
	animation->frames->frameName = (char*)malloc(sizeof(char) * (26));	
	animation->frames->pNext = NULL;
	
	if (animation->frames == NULL || animation->frames->frameName == NULL) {
		fprintf(stderr, "Memory allocation failed");
		return;
	}
	
}

void InsertFrame(Animation* animation) {

	struct Frame* newFrame = malloc(sizeof(struct Frame*));
	struct Frame* tempFrame = malloc(sizeof(struct Frame*));

	if (animation->frames != NULL){
		tempFrame = animation->frames;
	}
	
	newFrame->frameName = (char*)malloc(sizeof(char) * (26));
	
	if (newFrame->pNext == NULL || newFrame->frameName == NULL) {
		fprintf(stderr, "Memory allocation failed");
		return;
	}

	printf("Selected Option: 1\nInsert a frame in the animation\nPlease enter the frame name: ");
	if(scanf("%25[^\n]s", newFrame->frameName) == 0){
		printf("An error occured");
	}
	printf("\n");

	if (animation->frames != NULL) {
		newFrame->pNext = tempFrame;
	}

	if (getchar()) {}

	animation->frames = newFrame;
	
}

void DeleteFrame(Animation* animation) {

	if (animation->frames->pNext == NULL) {
		printf("No frames to delete\n");
		return;
	}

	struct Frame* delFrame = animation->frames;

	while (delFrame->pNext->pNext != NULL) {
		delFrame = delFrame->pNext;
	}
	
	delFrame->pNext = NULL;
	free(delFrame->pNext);
	
}

void EditFrame(Animation* animation) {
	int counter = 0;
	int index = 0;
	struct Frame* newFrame = animation->frames;

	while (newFrame->pNext != NULL) {
		newFrame = newFrame->pNext;
		counter++;
	}

	printf("Edit a frame in the animation\nThere are %d frame(s) in the list. Please specify the index (<= %d) to edit at: ", counter, (counter-1));
	if (scanf("%d", &index) == 0) {
		printf("an error occured");
	}
	counter = 0;
	newFrame = animation->frames;
	while (counter < index) {
		newFrame = newFrame->pNext;
		counter++;
	}
	if (getchar()) {}
	printf("The name of this frame is %s\nWhat do you want to replace it with?\n", newFrame->frameName);
	if (scanf("%25[^\n]s", newFrame->frameName) == 0) {
		printf("an error occured");
	}
	if (getchar()) {}
	
}

void ReportAnimation(Animation* animation) {
	int counter = 0;
	struct Frame* newFrame = animation->frames;
	printf("\nAnimation Name is: %s\nReport the animation\n", animation->animationName);
	while (newFrame->pNext != NULL) {
		printf("Image #%d, file name = %s\n\n", counter, newFrame->frameName);
		newFrame = newFrame->pNext;
		counter++;
	}
}

void CleanUp(Animation* animation) {
	
	struct Frame* delFrame = animation->frames;

	while (animation->frames->pNext != NULL) {

		delFrame = animation->frames;

		while (delFrame->pNext->pNext != NULL) {
			delFrame = delFrame->pNext;
		}
	
		delFrame->pNext = NULL;
		free(delFrame->pNext);

	}

	delFrame->frameName = NULL;
	free(delFrame->frameName);
	delFrame = NULL;
	free(delFrame);

}