#include "library.h"
#include <string>

void button(double xCoord, double yCoord, double size, string num, double horizontalShift, double verticalShift, double fontModifier) {

	double partitionSize = 0.2 * size;
	double buttonMargin = 0.1 * partitionSize;
	double buttonSize = partitionSize - buttonMargin;
	double outlineMargin = (1.0/90.0) * buttonSize; 

    fill_rectangle(xCoord, yCoord, buttonSize,buttonSize, color::black);
	fill_rectangle(xCoord + outlineMargin, yCoord + outlineMargin,buttonSize - 2 * outlineMargin,buttonSize - 2 * outlineMargin, color::grey);
	
	move_to(xCoord + 0.25 * buttonSize + horizontalShift, yCoord + 0.85 * buttonSize + verticalShift);
	set_font_size(1.2 * buttonSize * fontModifier);
	write_string(num);

}

void buttons(double size, double partitionSize) {

	double buttonMargin = 0.1 * partitionSize;

	button(buttonMargin * 0.5 + partitionSize * 0,partitionSize * 1,size,"7",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 1,partitionSize * 1,size,"8",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 2,partitionSize * 1,size,"9",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 3,partitionSize * 1,size,"+",(-5.0/500.0) * size,0,1);
	button(buttonMargin * 0.5 + partitionSize * 4,partitionSize * 1,size,"CM",(-15.0/500.0)*size,(-15.0/500.0)*size,0.45);

	button(buttonMargin * 0.5 + partitionSize * 0,partitionSize * 2,size,"4",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 1,partitionSize * 2,size,"5",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 2,partitionSize * 2,size,"6",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 3,partitionSize * 2,size,"-",(2.0/500.0) * size,0,1.3);
	button(buttonMargin * 0.5 + partitionSize * 4,partitionSize * 2,size,"M+",(-10/500.00)*size,(-12/500.00)*size,0.5);

	button(buttonMargin * 0.5 + partitionSize * 0,partitionSize * 3,size,"1",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 1,partitionSize * 3,size,"2",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 2,partitionSize * 3,size,"3",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 3,partitionSize * 3,size,"x",0,(-8/500.00)*size,1);
	button(buttonMargin * 0.5 + partitionSize * 4,partitionSize * 3,size,"MR",(-13/500.00)*size,(-15/500.00)*size,0.45);

	button(buttonMargin * 0.5 + partitionSize * 0,partitionSize * 4,size,"C",(-12.0/500.0)*size,0,1);
	button(buttonMargin * 0.5 + partitionSize * 1,partitionSize * 4,size,"0",0,0,1);
	button(buttonMargin * 0.5 + partitionSize * 2,partitionSize * 4,size,"=",(-5/500.0)*size,0,1);
	button(buttonMargin * 0.5 + partitionSize * 3,partitionSize * 4,size,"/",(10/500.0)*size,0,1);
	button(buttonMargin * 0.5 + partitionSize * 4,partitionSize * 4,size,"B",0,(-8/500.00)*size,0.7);


}

bool clickIsValid(int a, int b, int size) {

    double partitionSize = 0.2 * size;
	double buttonMargin = 0.1 * partitionSize;
	double buttonSize = partitionSize - buttonMargin;

	if ((b>(partitionSize + buttonMargin) && b<(2*partitionSize - buttonMargin)) || (b>(2*partitionSize + buttonMargin) && b<(3*partitionSize - buttonMargin)) ||(b>(3*partitionSize + buttonMargin) && b<(4*partitionSize - buttonMargin)) ||(b>(4*partitionSize + buttonMargin) && b<(5*partitionSize - buttonMargin)))
		{	
			if((a>(buttonMargin) && a<(partitionSize - buttonMargin)) ||(a>(partitionSize + buttonMargin) && a<(2*partitionSize - buttonMargin)) || (a>(2*partitionSize + buttonMargin) && a<(3*partitionSize - buttonMargin)) ||(a>(3*partitionSize + buttonMargin) && a<(4*partitionSize - buttonMargin)) ||(a>(4*partitionSize + buttonMargin) && a<(5*partitionSize - buttonMargin))) 
				{return true;}
			else
				{return false;}
	
		}
	
	else {return false;}


}

string parseUserCoords (int xCoord, int yCoord,int size) {

    double partitionSize = 0.2 * size;

	if(xCoord<partitionSize) {
		 if(yCoord > partitionSize && yCoord < 2* partitionSize) {return "7";}
	     if(yCoord > 2*partitionSize && yCoord < 3* partitionSize) {return "4";} 
		 if(yCoord > 3*partitionSize && yCoord < 4* partitionSize) {return "1";}
	     if(yCoord > 4*partitionSize && yCoord < 5* partitionSize) {return "C";}	
	}

	if(xCoord>partitionSize && xCoord<2*partitionSize) {
		 if(yCoord > partitionSize && yCoord < 2* partitionSize) {return "8";}
	     if(yCoord > 2*partitionSize && yCoord < 3* partitionSize) {return "5";}
		 if(yCoord > 3*partitionSize && yCoord < 4* partitionSize) {return "2";}
	     if(yCoord > 4*partitionSize && yCoord < 5* partitionSize) {return "0";}	
	}

	if(xCoord>2*partitionSize && xCoord<3*partitionSize) {
		 if(yCoord > partitionSize && yCoord < 2* partitionSize) {return "9";}
	     if(yCoord > 2*partitionSize && yCoord < 3* partitionSize) {return "6";} 
		 if(yCoord > 3*partitionSize && yCoord < 4* partitionSize) {return "3";}
	     if(yCoord > 4*partitionSize && yCoord < 5* partitionSize) {return "=";}	
	}

	if(xCoord>3*partitionSize && xCoord<4*partitionSize) {
		 if(yCoord > partitionSize && yCoord < 2* partitionSize) {return "+";}
	     if(yCoord > 2*partitionSize && yCoord < 3* partitionSize) {return "-";} 
		 if(yCoord > 3*partitionSize && yCoord < 4* partitionSize) {return "x";}
	     if(yCoord > 4*partitionSize && yCoord < 5* partitionSize) {return "/";}	
	}

	if(xCoord>4*partitionSize && xCoord<5*partitionSize) {
		 if(yCoord > partitionSize && yCoord < 2* partitionSize) {return "CM";}
	     if(yCoord > 2*partitionSize && yCoord < 3* partitionSize) {return "M+";} 
		 if(yCoord > 3*partitionSize && yCoord < 4* partitionSize) {return "MR";}
	     if(yCoord > 4*partitionSize && yCoord < 5* partitionSize) {return "B";}	
	}

}

void display (double output, int size) {

	double partitionSize = 0.2*size;
	double buttonMargin = 0.1*partitionSize;
	double buttonSize = partitionSize - buttonMargin;
	double outlineMargin = (1.0/90.0) * buttonSize; 

	fill_rectangle(buttonMargin, buttonMargin, size - 2 * buttonMargin, buttonSize - buttonMargin, color::grey);

	move_to(2*buttonMargin,partitionSize-2*buttonMargin);
	set_pen_color(color::purple);
	set_font_size((70.0/500.0) * size);
	write_string(output);
}

void display (string output, int size) {

	double partitionSize = 0.2*size;
	double buttonMargin = 0.1*partitionSize;
	double buttonSize = partitionSize - buttonMargin;
	double outlineMargin = (1.0/90.0) * buttonSize; 

	fill_rectangle(buttonMargin, buttonMargin, size - 2 * buttonMargin, buttonSize - buttonMargin, color::grey);

	move_to(2*buttonMargin,partitionSize-2*buttonMargin);
	set_pen_color(color::purple);
	set_font_size((70.0/500.0) * size);
	write_string(output);
}

string userEntryType (string userEntry) {

	if (userEntry == "0" ||userEntry == "1" ||userEntry == "2" ||userEntry == "3" ||userEntry == "4" ||userEntry == "5" ||userEntry == "6" ||userEntry == "7" ||userEntry == "8" ||userEntry == "9")
		{return "number";}
	else 
		{return "command";}
}

double userNum (string userEntry) {

	if(userEntry == "0") {return 0;}
	if(userEntry == "1") {return 1;}
	if(userEntry == "2") {return 2;}
	if(userEntry == "3") {return 3;}
	if(userEntry == "4") {return 4;}
	if(userEntry == "5") {return 5;}
	if(userEntry == "6") {return 6;}
	if(userEntry == "7") {return 7;}
	if(userEntry == "8") {return 8;}
	if(userEntry == "9") {return 9;}

}

double twoDecimalPlaces (double storedTotal) {

	return (((int)(storedTotal*100))/100.0);

}

string parseUserCommandType (string userCommand) {

	if (userCommand=="C") {return "Clear";}
	if (userCommand=="+" || userCommand=="-" || userCommand=="x" || userCommand=="/") {return "Math";}
	if (userCommand=="=") {return "Equivalence";}
	if (userCommand=="CM" || userCommand=="M+" || userCommand=="MR") {return "Memory";}
	if (userCommand=="B") {return "Binary/Hex";}

}

double mathOperation (double storedTotal, double workingTotal, string previousCommand) {

	if(previousCommand=="+") {return (storedTotal + workingTotal);}
	if(previousCommand=="-") {return (storedTotal - workingTotal);}
	if(previousCommand=="/") {return (storedTotal / workingTotal);}
	if(previousCommand=="x") {return (storedTotal * workingTotal);}

}

void makeCalculator(double size) {
	double storedTotal = 0;
	double workingTotal = 0;
	double displayedNumber = 0;
	bool isFirstTime = true;
	bool numberEntered = false;
	double storedVariable = 0;
	string userCommand = "None";
	string previousCommand = "None";
	string userCommandType = "None";

	double partitionSize = 0.2 * size;
	double buttonMargin = 0.1 * partitionSize;
	double buttonSize = partitionSize - buttonMargin;
	
	make_window(size,size);
	fill_rectangle(buttonMargin, buttonMargin, size - 2 * buttonMargin, buttonSize - buttonMargin, color::grey);
   	buttons(size, partitionSize);     
	display(storedTotal,size);

	while (true) {
		
		wait_for_mouse_click();
		int xClickCoord = get_click_x(); int yClickCoord = get_click_y();
		while (clickIsValid(xClickCoord,yClickCoord,size)==false)
			{wait_for_mouse_click(); int xClickCoord = get_click_x(); int yClickCoord = get_click_y();}
		string userEntry = parseUserCoords(xClickCoord,yClickCoord,size);
		if (userEntryType(userEntry)=="command") 
			{
			 
			 previousCommand = userCommand;

			 userCommand = userEntry;
			 userCommandType = parseUserCommandType(userCommand);
			 
			 if (userCommand == "C") {
			 
				workingTotal = 0; storedTotal = 0; isFirstTime = true; userCommand = "None"; previousCommand = "None"; 
				display(workingTotal, size);
				displayedNumber = workingTotal;

			 }

			 if (userCommandType == "Equivalence") {

				storedTotal = mathOperation(storedTotal, workingTotal, previousCommand);
				workingTotal = 0;
				display(storedTotal, size);
				displayedNumber = storedTotal;

			 }

			 if (userCommandType == "Memory") {
			 
				 if(userCommand=="CM") {storedVariable = 0;}
				 if(userCommand=="M+") {storedVariable = displayedNumber;}
				 if(userCommand=="MR") {workingTotal = storedVariable; display(workingTotal,size);}
			 
			 
			 
			 }

			 if (userCommandType == "Math") {
			 
			 if (numberEntered) {
				 if (isFirstTime) {
				    
					isFirstTime = false; 
					print("First Time ");
					storedTotal = workingTotal;
					workingTotal = 0;
					display(storedTotal,size);
				    displayedNumber = storedTotal;
				 }

				 else {
                    
					 if (parseUserCommandType(previousCommand) != "Math") {display(storedTotal,size);}
					 else {
						print("Not First Time "); 				 
						storedTotal = mathOperation(storedTotal, workingTotal, previousCommand);
						workingTotal = 0;
						display(storedTotal,size);
						displayedNumber = storedTotal;
					}
				 }
			 }
			 
			 else {display(storedTotal,size);}

			 }

			 print(userCommandType); new_line();
			}
		if (userEntryType(userEntry)=="number")
			{
			 numberEntered = true;
			 if (userCommand == "=") {workingTotal = 0;}
			 workingTotal = workingTotal * 10 + userNum(userEntry);
		     display(twoDecimalPlaces(workingTotal),size);
	        }
	}
		

	
	
	
	
	
}
	



void main() {
	
	makeCalculator(300); //500 is the native size, but the calculator can scale

}
