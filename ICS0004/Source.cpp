#include <stdio.h>
#include <stdlib.h>

#pragma warning ( disable : 4996 )

//SLIDES - http://www.tud.ttu.ee/im/Viktor.Leppikson/ICS0004%20Slides.html

//STRUCTS



//TOPIC FUNCTION PROTOTYPES

void Fundamentals();
void Deeper();
void Pointers();
void Structs();

//FUNDAMENTALS FUNCTION PROTOTYPES



//DEEPER FUNCTION PROTOTYPES



//POINTERS FUNCTION PROTOTYPES



//STRUCTS FUNCTION PROTOTYPES



//MAIN

int main()
{
	printf("TalTech - ICS0004 - Fundamentals of Programming\n2022-2023 exercise solutions\n");
	int action = 1;
	char buffer[100];
	while (1)
	{
		printf("\n\nSelect which topic's exercises you wish to run and enter the corresponding number:\n1 - Fundamentals\n2 - Deeper\n3 - Pointers\n4 - Structs\n5 - All\n0 - Exit\nSelection: ");
		scanf("%s", buffer);
		action = atoi(buffer);
		switch (action)
		{
		case 0:
			return 0;
		case 1:
			Fundamentals();
			break;
		case 2:
			Deeper();
			break;
		case 3:
			Pointers();
			break;
		case 4:
			Structs();
			break;
		case 5:
			Fundamentals();
			Deeper();
			Pointers();
			Structs();
			break;
		default:
			printf("Error in input data! Please try again!");
			break;
		}
	}
}

//TOPIC FUNCTIONS

void Fundamentals()
{

}

void Deeper()
{

}

void Pointers()
{

}

void Structs()
{

}

//FUNDAMENTALS FUNCTIONS



//DEEPER FUNCTIONS



//POINTERS FUNCTIONS



//STRUCTS FUNCTIONS

