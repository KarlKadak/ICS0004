#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <memory>

#define SUCCESS 0
#define NEGMEMBERS 1
#define ZEROMEMBERS 2
#define OVER1000MEMBERS 3
#define POINTERZERO 4
#define EMPTYARRAY 5

#pragma warning ( disable : 4996 )

//SLIDES - http://www.tud.ttu.ee/im/Viktor.Leppikson/ICS0004%20Slides.html

//GLOBAL VARIABLES

int RandVal[100], DeeperError;
char Table[5][5], Buf1[81], Buf2[81], selection[81] = "";

//STRUCTS



//TOPIC FUNCTION PROTOTYPES

void Fundamentals();
void Deeper();
void Pointers();
void Structs();

//FUNDAMENTALS FUNCTION PROTOTYPES

int MaxOfThree(int, int, int);//EXERCISE 11
double TempConverter(double, char);//EXERCISE 12

//DEEPER FUNCTION PROTOTYPES

int GetRandArray(int);//EXERCISE 1
void FillTable();//EXERCISE 2
void RemoveSpace();//EXERCISE 3
void ConvertToLower();//EXERCISE 4
int CountVowels();//EXERCISE 4
int CountConsonants();//EXERCISE 4

//POINTERS FUNCTION PROTOTYPES

char* Reverse(char*);//EXERCISE 1
char* ReformatName(char*);//EXERCISE 2
int CheckSum(int*, int, int*);//EXERCISE 3
char** SentenceSplit(char*, int*);//EXERCISE 4
int InsertName(char*, int, char*);//EXERCISE 5
int RemoveName(char*, char*);//EXERCISE 6
int CharFreq(char*, char);//EXERCISE 7
int* CharFreqs(char*);//EXERCISE 8

//STRUCTS FUNCTION PROTOTYPES



//MAIN

int main()
{
	printf("TalTech - ICS0004 - Fundamentals of Programming\n2022-2023 exercise solutions\n\n");
	int action;
	char buffer[81];
	while (1)
	{
		printf("\nSelect which topic's exercises you wish to run and enter the corresponding number:\n1 - Fundamentals\n2 - Deeper\n3 - Pointers\n4 - Structs\n5 - All\n0 - Exit\nSelection: ");
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
	char line[81];
	//EXERCISE 1
	printf("\n\nEven-odd integer checker: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	int toEvenOdd = atoi(line);
	if (toEvenOdd % 2 == 0 || toEvenOdd % -2 == 0)
	{
		printf("This number is even\n\n");
	}
	else
	{
		printf("This number is odd\n\n");
	}
	//EXERCISE 2
	printf("First character type checker: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	if (line[0] > 47 && line[0] < 58)
	{
		printf("The text starts with a digit\n\n");
	}
	else if (line[0] > 64 && line[0] < 91)
	{
		printf("The text starts with an uppercase letter\n\n");
	}
	else if (line[0] > 96 && line[0] < 123)
	{
		printf("The text starts with a lowercase letter\n\n");
	}
	else
	{
		printf("The text starts with an unrecognized character\n\n");
	}
	//EXERCISE 3
	printf("Pseudo-random integer generator\n");
	for (int i = 0; i < 50; i++)
	{
		int r = rand();
		if (r < 500)
		{
			printf("%i\n", r);
		}
	}
	printf("\n");
	//EXERCISE 4
	printf("Fibonacci sequence array generator\n");
	int Fib[20] = { 1, 1 };
	for (int i = 2; i < 20; i++)
	{
		Fib[i] = Fib[i - 2] + Fib[i - 1];
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%i ", Fib[i]);
	}
	printf("\n\n");
	//EXERCISE 5
	printf("Pseudo random integer array generator with maximum value finder\n");
	int Rand[50], max = 0;
	for (int i = 0; i < 50; i++)
	{
		Rand[i] = rand();
		if (Rand[i] > max)
		{
			max = Rand[i];
		}
	}
	printf("The maximum value is %i\n\n", max);
	//EXERCISE 6
	printf("Input validity checker with \"a\"/\"A\" counter: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	int lowerCount = 0, upperCount = 0;
	for (int i = 0; line[i] != 0 && i < 82; i++)
	{
		if (!((line[i] > 64 && line[i] < 91) || (line[i] > 96 && line[i] < 123)))
		{
			printf("Illegal input!\n\n");
			break;//PROGRAM DOES NOT QUIT AS REQUIRED IN INSTRUCTIONS, BUT CONTINUES WITHOUT SHOWING CHARACTER COUNTS
		}
		else if (line[i] == 'a')
		{
			lowerCount++;
		}
		else if (line[i] == 'A')
		{
			upperCount++;
		}
		if (line[i + 1] == 0 || i == 81)
		{
			printf("\"a\" - %i, \"A\" - %i\n\n", lowerCount, upperCount);
		}
	}
	//EXERCISE 7
	printf("Undercase vowel counter: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	char vowels[] = "aeiouy";
	int vowelsCount = 0;
	for (int i = 0; line[i] != 0 && i < 82; i++)
	{
		for (int j = 0; vowels[j] != 0; j++)
		{
			if (line[i] == vowels[j])
			{
				vowelsCount++;
				break;
			}
		}
	}
	printf("Total vowels: %i\n\n", vowelsCount);
	//EXERCISE 8
	printf("Input character-by-character checker with _getche(): ");
	char text[21];
	for (int i = 0; i < 21; i++)
	{
		if (i == 20)
		{
			text[20] = 0;
			printf("\nResult is: %s\n\n", text);
			break;
		}
		text[i] = _getche();
		if (text[i] == 27)
		{
			text[i] = 0;
			printf("\nRResult is: %s\n\n", text);//HERE, THE EXTRA CHARACTER BEFORE THE "R" IS NECESSARY DUE TO KEYBOARD BUFFER ISSUES CAUSED BY _getche()
			break;
		}
	}
	//EXERCISE 9
	printf("Lowercase vowel counter with _getche(): ");
	int vowelCounts[6] = { 0 };
	for (int i = 0; i < 21; i++)
	{
		if (i == 20)
		{
			text[20] = 0;
			break;
		}
		text[i] = _getche();
		if (text[i] == '\r')
		{
			text[i] = 0;
			break;
		}
		for (int j = 0; j < 6; j++)
		{
			if (text[i] == vowels[j])
			{
				vowelCounts[j]++;
				break;
			}
		}
	}
	printf("\n");//EXTRA \n IS NECESSARY ON BOTH OCCASIONS DUE TO _getche() DISPLAYING \r ON PRESSING ENTER
	for (int i = 0; i < 6; i++)
	{
		printf("%c - %i\n", vowels[i], vowelCounts[i]);
	}
	printf("\n");
	//EXERCISE 10
	printf("Integer finder from text with even-odd checker: ");
	for (int i = 0; i < 82; i++)
	{
		line[i] = _getche();
		if (line[i] == '\r' || i == 81)
		{
			line[i] = 0;
			printf("\n");
			break;
		}
	}//DUE TO KEYBOARD BUFFER ISSUES, THIS SOLUTION IS NECESSARY FOR GETTING USER INPUT BUT IT DISABLES THE FUNCTIONALITY OF BACKSPACE
	char buf[20];
	int intFromText = 0;
	for (int i = 0; line[i] != 0; i++)
	{
		if (line[i] > 47 && line[i] < 58)
		{
			for (int j = 0; line[i + j] != ' ' && line[i + j] != 0; j++)
			{
				buf[j] = line[i + j];
				buf[j + 1] = 0;
			}
			intFromText = atoi(buf);
			if (i != 0 && line[i - 1] == 45)
			{
				intFromText *= -1;
			}
			break;
		}
	}
	if (intFromText % 2 == 0 || intFromText % -2 == 0)
	{
		printf("This number is even\n\n");
	}
	else
	{
		printf("This number is odd\n\n");
	}
	//EXERCISE 11
	printf("MaxOfThree\nEnter the first value: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	int toMax1, toMax2, toMax3;
	toMax1 = atoi(line);
	printf("Enter the second value: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	toMax2 = atoi(line);
	printf("Enter the third value: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	toMax3 = atoi(line);
	int fromMaxOfThree = MaxOfThree(toMax1, toMax2, toMax3);
	printf("The maximum is: %i\n\n", fromMaxOfThree);
	//EXERCISE 12
	printf("TempConverter, enter \"F\"/\"f\" for converting to Fahrenheit, or \"C\"/\"c\" for converting to Celsius: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	char unitToConvert = line[0];
	printf("Enter the value to convert from: ");
	scanf("%s", line);//INSTRUCTIONS SUGGEST USING gets_s(), DUE TO KEYBOARD BUFFER ISSUES THIS IS CHANGED
	double tempToConvert = atof(line), fromTempConverter = TempConverter(tempToConvert, unitToConvert);
	if (isnan(fromTempConverter))
	{
		printf("No solution\n\n");
	}
	else
	{
		printf("%lg\n\n", fromTempConverter);
	}
}

void Deeper()
{
	char line[81];
	//EXERCISE 1
	printf("\n\nPseudo-random number array generator function\nEnter number of values: ");
	scanf("%s", line);
	int toRandArray = atoi(line), fromRandArray = GetRandArray(toRandArray);
	if (DeeperError == 0)
	{
		printf("Maximum of %i generated numbers: %i\n\n", toRandArray, fromRandArray);
	}
	else
	{
		printf("Error in input data!\n\n");
	}
	//EXERCISE 2
	printf("Table pattern filler function:\n");
	FillTable();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c ", Table[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//EXERCISE 3
	printf("Excess space remover function: ");
	for (int i = 0; i < 82; i++)
	{
		Buf1[i] = _getche();
		if (Buf1[i] == '\r' || i == 81)
		{
			Buf1[i] = 0;
			printf("\n");
			break;
		}
	}//DUE TO KEYBOARD BUFFER ISSUES, THIS SOLUTION IS NECESSARY FOR GETTING USER INPUT BUT IT DISABLES THE FUNCTIONALITY OF BACKSPACE
	RemoveSpace();
	printf("Text after compressing: %s\n\n", Buf2);
	//EXERCISE 4
	printf("Menu selection:");
	while (selection[0] != 'x')
	{
		printf("\nv - count vowels\nc - count consonants\nx - exit\n");
		scanf("%s", selection);
		selection[0] = tolower(selection[0]);
		if (selection[0] == 'v')
		{
			printf("Type the text you wish to count vowels from: ");
			for (int i = 0; i < 82; i++)
			{
				Buf1[i] = _getche();
				if (Buf1[i] == '\r' || i == 81)
				{
					Buf1[i] = 0;
					printf("\n");
					break;
				}
			}//DUE TO KEYBOARD BUFFER ISSUES, THIS SOLUTION IS NECESSARY FOR GETTING USER INPUT BUT IT DISABLES THE FUNCTIONALITY OF BACKSPACE
			printf("Total vowels: %i\n", CountVowels());
		}
		else if (selection[0] == 'c')
		{
			printf("Type the text you wish to count consonants from: ");
			for (int i = 0; i < 82; i++)
			{
				Buf1[i] = _getche();
				if (Buf1[i] == '\r' || i == 81)
				{
					Buf1[i] = 0;
					printf("\n");
					break;
				}
			}//DUE TO KEYBOARD BUFFER ISSUES, THIS SOLUTION IS NECESSARY FOR GETTING USER INPUT BUT IT DISABLES THE FUNCTIONALITY OF BACKSPACE
			printf("Total consonants: %i\n", CountConsonants());
		}
		else if (selection[0] == 'x')
		{
			break;
		}
		else
		{
			printf("Unrecognized character, try again!\n");
		}
	}
	printf("\n\n");
}

void Pointers()
{
	//INPUTS FOR FUNCTIONS ARE CONSTANT - NO USER INPUT IS NEEDED, USER CAN MODIFY FUNCTION INPUTS FROM THE SOURCE CODE
	//EXAMPLE FUNCTIONS LIKE CreateRandomString() AND CreateRandomName() ARE NOT USED
	//EXERCISE 1
	char toReverse[] = "My name is John";//INPUT
	printf("\n\nReverse\n%s\n", toReverse);
	char* fromReverse = Reverse(toReverse);
	if (fromReverse)
	{
		printf("%s\n\n", fromReverse);
		free(fromReverse);
	}
	else
	{
		printf("Input error!\n\n");
	}
	//EXERCISE 2
	char toReformatName[] = "John Smith";//INPUT
	printf("\n\ReformatName\n%s\n", toReformatName);
	char* fromReformatName = ReformatName(toReformatName);
	if (fromReformatName)
	{
		printf("%s\n\n", fromReformatName);
		free(fromReformatName);
	}
	else
	{
		printf("Input error!\n\n");
	}
	//EXERCISE 3
	int toCheckSum[] = { 2, 3, 105, 18, 72 };//INPUT
	int nCheckSumElements = sizeof(toCheckSum) / sizeof(int), errorCode;
	printf("CheckSum\ntoCheckSum, %i, &errorCode\n", nCheckSumElements);
	int fromCheckSum = CheckSum(toCheckSum, nCheckSumElements, &errorCode);
	switch (errorCode)
	{
	case SUCCESS:
		printf("%i\n\n", fromCheckSum);
		break;
	case NEGMEMBERS:
		printf("Negative members in array!\n\n");
		break;
	case ZEROMEMBERS:
		printf("0 value members in array!\n\n");
		break;
	case OVER1000MEMBERS:
		printf(">1000 value members in array!\n\n");
		break;
	case POINTERZERO:
		printf("Pointer to array is 0!\n\n");
		break;
	case EMPTYARRAY:
		printf("Empty array!\n\n");
		break;
	default:
		printf("Unknown error!\n\n");
		break;
	}
	//EXERCISE 4
	char toSentenceSplit[] = "My name is John";//INPUT
	int nSentenceSplitWords = 1;
	printf("SentenceSplit\n%s, &nSentenceSplitWords\n", toSentenceSplit);
	char** fromSentenceSplit = SentenceSplit(toSentenceSplit, &nSentenceSplitWords);
	if (fromSentenceSplit)
	{
		for (int i = 0; i < nSentenceSplitWords; i++)
		{
			printf("%s\n", fromSentenceSplit[i]);
			free(fromSentenceSplit[i]);
		}
		free(fromSentenceSplit);
	}
	else
	{
		printf("Input error!\n");
	}
	printf("\n");
	//EXERCISE 5
	const int toInsertNameBytes = 32; char toInsertName[toInsertNameBytes] = "John,Mary,James,Elizabeth", nameToInsert[] = "David";//INPUT
	printf("InsertName\n%s, %i, %s\n", toInsertName, toInsertNameBytes, nameToInsert);
	int fromInsertName = InsertName(toInsertName, toInsertNameBytes, nameToInsert);
	if (fromInsertName)
	{
		printf("%s\n\n", toInsertName);
	}
	else
	{
		printf("Not enough bytes for the expanded list / input error!\n\n");
	}
	//EXERCISE 6
	char toRemoveName[] = "John,Mary,James,Elizabeth", nameToRemove[] = "John";//INPUT
	printf("RemoveName\n%s, %s\n", toRemoveName, nameToRemove);
	int fromRemoveName = RemoveName(toRemoveName, nameToRemove);
	if (fromRemoveName)
	{
		printf("%s\n\n", toRemoveName);
	}
	else
	{
		printf("Name was not found from the list / input error!\n\n");
	}
	//EXERCISE 7
	char toCharFreq[] = "Jesse James", charToFreq = 'e';//INPUT
	printf("CharFreq\n%s, %c\n", toCharFreq, charToFreq);
	int fromCharFreq = CharFreq(toCharFreq, charToFreq);
	if (fromCharFreq)
	{
		printf("%i\n\n", fromCharFreq);
	}
	else
	{
		printf("Character was not found from input string / input error!\n\n");
	}
	//EXERCISE 8
	char toCharFreqs[] = "Butch Cassidy";//INPUT
	printf("CharFreqs\n%s\n", toCharFreqs);
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int* fromCharFreqs = CharFreqs(toCharFreqs);
	if (fromCharFreqs)
	{
		for (int i = 0; i < 26; i++)
		{
			printf("%c - %i  ", alphabet[i], fromCharFreqs[i]);
		}
		free(fromCharFreqs);
	}
	else
	{
		printf("Input error!");
	}
	printf("\n\n");
}

void Structs()
{

}

//FUNDAMENTALS FUNCTIONS

int MaxOfThree(int int1, int int2, int int3)//EXERCISE 11
{
	if (int1 >= int2)
	{
		if (int1 >= int3)
		{
			return int1;
		}
		else
		{
			return int3;
		}
	}
	else if (int2 >= int3)
	{
		return int2;
	}
	else
	{
		return int3;
	}
}

double TempConverter(double value, char unit)//EXERCISE 12
{
	if (unit == 'F' || unit == 'f')
	{
		return (value * 9 / 5 + 32);
	}
	else if (unit == 'C' || unit == 'c')
	{
		return ((value - 32) * 5 / 9);
	}
	else
	{
		return NAN;
	}
}

//DEEPER FUNCTIONS

int GetRandArray(int nValues)//EXERCISE 1
{
	if (nValues < 1 || nValues > 100)
	{
		DeeperError = -1;
		return 0;
	}
	int output = 0;
	for (int i = 0; i < nValues; i++)
	{
		RandVal[i] = rand();
		if (RandVal[i] > output)
		{
			output = RandVal[i];
		}
	}
	DeeperError = 0;
	return output;
}

void FillTable()//EXERCISE 2
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
			{
				Table[i][j] = '*';
			}
			else if (i < j)
			{
				Table[i][j] = '+';
			}
			else
			{
				Table[i][j] = '-';
			}
		}
	}
}

void RemoveSpace()//EXERCISE 3
{
	for (int i = 0, j = 0; Buf1[i] != 0; i++)
	{
		if (Buf1[i] == ' ')
		{
			if (i != 0 && Buf1[i - 1] != ' ')
			{
				Buf2[j++] = ' ';
			}
		}
		else
		{
			Buf2[j++] = Buf1[i];
		}
		if (Buf1[i + 1] == 0)
		{
			Buf2[j + 1] = 0;
		}
	}
}

void ConvertToLower()//EXERCISE 4
{
	for (int i = 0; Buf1[i] != 0; i++)
	{
		Buf1[i] = tolower(Buf1[i]);
	}
}

int CountVowels()//EXERCISE 4
{
	ConvertToLower();
	int output = 0;
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	for (int i = 0; Buf1[i] != 0; i++)
	{
		if (isalpha(Buf1[i]))
		{
			for (int j = 0; j < 6; j++)
			{
				if (Buf1[i] == vowels[j])
				{
					output++;
					break;
				}
			}
		}
	}
	return output;
}

int CountConsonants()//EXERCISE 4
{
	ConvertToLower();
	int output = 0;
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	for (int i = 0; Buf1[i] != 0; i++)
	{
		if (isalpha(Buf1[i]))
		{
			for (int j = 0; j < 6; j++)
			{
				if (Buf1[i] == vowels[j])
				{
					break;
				}
				if (j == 5)
				{
					output++;
				}
			}
		}
	}
	return output;
}

//POINTERS FUNCTIONS

char* Reverse(char* input)//EXERCISE 1
{
	if (input == 0 || *input == 0)
	{
		return 0;
	}
	int length = 0;
	while (input[++length] != 0);
	char* output = (char*)malloc(sizeof(char) * (length + 1));
	for (int i = 0; i < length; i++)
	{
		output[i] = input[length - i - 1];
	}
	output[length] = 0;
	return output;
}

char* ReformatName(char* input)
{
	if (input == 0 || *input == 0)
	{
		return 0;
	}
	int foreLength = 0, surLength = 0;
	while (input[++foreLength] != ' ');
	while (input[++surLength + foreLength + 1] != 0);
	char* output = (char*)malloc(sizeof(char) * (foreLength + surLength + 3));
	for (int i = 0; i < surLength; i++)
	{
		output[i] = input[foreLength + 1 + i];
	}
	output[surLength] = ',';
	output[surLength + 1] = ' ';
	for (int i = 0; i < foreLength; i++)
	{
		output[surLength + 2 + i] = input[i];
	}
	output[surLength + foreLength + 2] = 0;
	return output;
}

int CheckSum(int* input, int nElements, int* errorCode)//EXERCISE 3
{
	if (input == 0)
	{
		*errorCode = POINTERZERO;
		return 0;
	}
	if (nElements == 0)
	{
		*errorCode = EMPTYARRAY;
		return 0;
	}
	int output = 0;
	for (int i = 0; i < nElements; i++)
	{
		if (input[i] < 0)
		{
			*errorCode = NEGMEMBERS;
			return 0;
		}
		if (input[i] == 0)
		{
			*errorCode = ZEROMEMBERS;
			return 0;
		}
		if (input[i] > 1000)
		{
			*errorCode = OVER1000MEMBERS;
			return 0;
		}
		output += input[i];
	}
	*errorCode = SUCCESS;
	return output;
}

char** SentenceSplit(char* input, int* nWords)//EXERCISE 4
{
	if (input == 0 || *input == 0 || nWords == 0)
	{
		return 0;
	}
	for (int i = 0; input[i] != 0; i++)
	{
		if (input[i] == ' ')
		{
			(*nWords)++;
		}
	}
	int toSkip = 0, length;
	char** output = (char**)malloc(sizeof(char*) * *nWords);
	for (int i = 0; i < *nWords; i++)
	{
		for (length = 0; input[toSkip + length] != ' ' && input[toSkip + length] != 0; length++);
		output[i] = (char*)malloc(sizeof(char) * (length + 1));
		for (int j = 0; j < length; j++)
		{
			output[i][j] = input[toSkip + j];
		}
		output[i][length] = 0;
		toSkip += length + 1;
	}
	return output;
}

int InsertName(char* list, int nBytes, char* name)//EXERCISE 5
{
	if (list == 0 || *list == 0 || name == 0 || *name == 0)
	{
		return 0;
	}
	int listLength = 0, nameLength = 0;
	while (list[++listLength] != 0);
	while (name[++nameLength] != 0);
	if (listLength + nameLength + 2 > nBytes)
	{
		return 0;
	}
	list[listLength] = ',';
	for (int i = 0; i < nameLength; i++)
	{
		list[listLength + 1 + i] = name[i];
	}
	list[listLength + nameLength + 1] = 0;
	return 1;
}

int RemoveName(char* list, char* name)//EXERCISE 6
{
	if (list == 0 || *list == 0 || name == 0 || *name == 0)
	{
		return 0;
	}
	int listLength = 0, nameLength = 0;
	while (list[++listLength] != 0);
	while (name[++nameLength] != 0);
	for (int i = 0; i < listLength; i++)
	{
		if (!memcmp(list + i, name, sizeof(char) * nameLength))
		{
			memmove(list + i, list + i + sizeof(char) * nameLength + 1, listLength - i - nameLength);
			list[listLength - nameLength - 1] = 0;
			return 1;
		}
	}
	return 0;
}

int CharFreq(char* input, char c)//EXERCISE 7
{
	if (input == 0 || *input == 0)
	{
		return 0;
	}
	int output = 0;
	char* buffer = input;
	while (strchr(buffer, c))
	{
		output++;
		buffer = strchr(buffer, c) + 1;
	}
	return output;
}

int* CharFreqs(char* input)//EXERCISE 8
{
	if (input == 0 || *input == 0)
	{
		return 0;
	}
	int* output = (int*)malloc(sizeof(int) * 26);
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 26; i++)
	{
		output[i] = CharFreq(input, alphabet[i]);
		output[i] += CharFreq(input, tolower(alphabet[i]));
	}
	return output;
}

//STRUCTS FUNCTIONS

