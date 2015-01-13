
void SetTextPosition(int Row,int Col)
{
	COORD XY = {Col,Row};
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE),XY);
}
void SetTextColor(int Color)
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),Color);
}
void ClearTheScreen()
{
	string line = "";
	for(int i = 0; i < 80; i++)
	{
		line += " ";
	}
	for(int y  = 2; y < 42; y++)
	{
		SetTextPosition(y, 0);
		cout << line;
	}
}
void PauseTheScreen()
{
	SetTextPosition(43,24);
	system("pause");
}
void Welcome()
{
	SetTextPosition(10,14);
	SetTextColor(14);
	cout << "Welcome to Project Based Software Engineering Course";
	PauseTheScreen();
}
void errorMessage(string err)
{
	string line = "";
	int xLength = err.length();
	for(int i = 0; i < xLength; i++)
	{
		line += " ";
	}
	SetTextColor(12);
	for(int i = 0; i < 5; i++)
	{
		SetTextPosition(42, 0);
		cout << err;
		Sleep(100);
		SetTextPosition(42, 0);
		cout << line;
		Sleep(100);
	}
}
void Heading()
{
	ClearTheScreen();
	SetTextColor(14);
	SetTextPosition(0,25);
	cout<< "CALIFORNIA LUTHERAN UNIVERSITY";
	SetTextPosition(1,25);
	cout << "DEPARTMENT OF COMPUTER SCIENCE";
	SetTextPosition(3,30);
	cout << " First Project csc 335";

}
void BoxMatrix(int Color, int X, int Y, int Row, int Col, int SizeX, int SizeY)
{
	unsigned char UpperLeft, UpperRight, LowerLeft;
	unsigned char LowerRight, Horizontal, Vertical;
	unsigned char TDown, TUp, TLeft, TRight, Cross;

	int width = Col * SizeY;
	int length = Row * SizeX;
	
	int k, m;
	UpperLeft = 218;
	UpperRight = 191;
	LowerLeft = 192;
	LowerRight = 217;
	Horizontal = 196;
	Vertical = 179;
	TDown = 194;
	TUp = 193;
	TLeft = 195;
	TRight = 180;
	Cross = 197;
	SetTextColor(Color);
	SetTextPosition(X,Y);
	cout << UpperLeft;
	SetTextPosition(X,Y + width);
	cout <<UpperRight;
	SetTextPosition(X + length,Y);
	cout << LowerLeft;
	SetTextPosition(X + length, Y + width);
	cout << LowerRight;
	
	for(int k = 1; k < width; k++){
		SetTextPosition(X, Y + k);
		cout << Horizontal;

			if(Row > 1){
			for(int m = 1; m < Row; m++){
					SetTextPosition(X + (m * SizeX), Y + k );
					cout << Horizontal;
			}
		}

		SetTextPosition(X + length, Y + k);
		cout << Horizontal;
	}

	for(int m = 1; m < length; m++){
		SetTextPosition(X + m, Y);
		cout << Vertical;
		if(Col > 1){
			for(int k = 1; k < Col; k++){
					SetTextPosition(X + m, Y + (k * SizeY));
					cout << Vertical;
			}
		}
		SetTextPosition(X + m, Y + width);
		cout << Vertical;
	}
	for( int k = 1; k < Row; k++){
		SetTextPosition(X + (k* SizeX), Y);
		cout << TLeft;

		SetTextPosition(X + (k * SizeX), Y + width);
		cout << TRight;

	}
	for( int k = 1; k < Col; k++){
		SetTextPosition(X, Y + (k * SizeY));
		cout << TDown;
		SetTextPosition(X + length,Y + (k * SizeY));
		cout << TUp;

	}
	if(Row > 1 || Col > 1){
		for(int k = 1; k < Col; k++){
			for(int m = 1; m < Row; m++){
				SetTextPosition(X + (m * SizeX), Y + (k * SizeY));
				cout << Cross;
			}
		}

	}
}
void ClearBox(int Color, int X, int Y, int Row, int Col, int SizeX, int SizeY)
{
	int width = Col * SizeY;
	int length = Row * SizeX;
	for(int k = 0; k <= width; k++){
		for(int m = 0; m <= length; m++){
		SetTextPosition(X+m, Y + k);
		cout << ' ';
	}
	}
}
int GetInput(int x, int y, string display){
	char Buffer[90], Holder;
	int k = 0;
	int input;
	SetTextPosition(x,y);
	cout << "               " ;
			for(int i = 0; i < 90; i ++)
			{
				Buffer[i] = '\0';
			}
			do
			{
				SetTextPosition(x,y);
				cout << display << Buffer;
				while(_kbhit()){
					_getch();
				}
				Holder = _getch();
				if(Holder > 47 && Holder < 58){
					Buffer[k] = Holder;
					k = k + 1;
				}
				else if((Holder < 47 || Holder > 56) && Holder != '\r')
					errorMessage("Non-numeric input");
				SetTextPosition(x,y);
				cout << display << Buffer;

				if(k ==2)
				{
					break;
				}
			}while(Holder != '\r');
	return atoi(Buffer);
}
void GetData()
{
	int i = 0;
	char Buffer[90], Holder;
	int k = 0;
	bool Running;
	int Color = 1, X = 1, Y = 1,  Row = 1, Col = 1, SizeX = 1, SizeY = 1;
	int counter = 0;
		for(int i = 0; i < 90; i ++)
			{
				Buffer[i] = '\0';
			}
			SetTextColor(12);
			do //Color
			{
			Color = GetInput(0, 0 , "Color : ");
				if(Color > 15 || Color < 1){
					errorMessage("Invalid Color");
				}
			}while(Color < 1 || Color > 15);

			do //X
			{
			X = GetInput(0, 17 , "X : ");
				if(X > 43 || X < 2){
					errorMessage("Invalid X Coordinate");
				}
			}while(X < 2 || X > 43);
			do  //Y
			{
			Y = GetInput(1, 17 , "Y : ");
				if(Y > 78 || Y < 0){
					errorMessage("Invalid Y coordinate");
				}
			}while(Y < 0 || Y > 78);
			do //SizeX
			{
			SizeX = GetInput(0, 29 , "SizeX : ");
				if(SizeX > 42 || SizeX < 1 || X + SizeX > 42){
					errorMessage("Invalid SizeX");
				}
			}while(SizeX > 42 || SizeX < 1 || X + SizeX > 42);
			do //SizeY
			{
			SizeY = GetInput(1, 29 , "SizeY : ");
				if(SizeY > 77 || SizeY < 1 || Y + SizeY > 77){
					errorMessage("Invalid SizeY");
				}
			}while(SizeY > 77 || SizeY < 1 || Y + SizeY > 77);
			do //Row
			{
			Row = GetInput(0, 45 , "Row : ");
				if(Row > 9 || Row < 1 || Row * SizeX + Y > 43){
					errorMessage("Invalid Row");
				}
			}while(Row > 9 || Row < 1 || Row * SizeX + Y > 43);
			
			do //Col
			{
			Col = GetInput(1, 45 , "Col : ");
				if(Col > 9 || Col < 1 || Col * SizeY + X > 79){
					errorMessage("Invalid Column");
				}
			}while(Col > 9 || Col < 1 || Col * SizeY + X > 79);
			BoxMatrix(Color, X, Y, Row, Col, SizeX, SizeY);

			while(i == 0)
			{
			if (GetKeyState(VK_UP) & 0x8000)
			{
			if ( X > 2)
				{
					ClearBox(Color,X,Y,Row,Col,SizeX,SizeY);
					X -= 1;
					BoxMatrix(Color,X,Y,Row,Col,SizeX,SizeY);
				}
			}
			if (GetKeyState(VK_DOWN) & 0x8000)
			{
				if ( (X + Row*SizeX) < 41)
				{
					ClearBox(Color,X,Y,Row,Col,SizeX,SizeY);
					X += 1;
					BoxMatrix(Color,X,Y,Row,Col,SizeX,SizeY);
				}
			}
			if (GetKeyState(VK_LEFT) & 0x8000)
			{
				if ( Y > 0)
				{
					ClearBox(Color,X,Y,Row,Col,SizeX,SizeY);
					Y -= 1;
					BoxMatrix(Color,X,Y,Row,Col,SizeX,SizeY);
				}
			}
			if (GetKeyState(VK_RIGHT) & 0x8000)
			{
				if ( Y + Col*SizeY < 78)
				{
					ClearBox(Color,X,Y,Row,Col,SizeX,SizeY);

					Y += 1;
					BoxMatrix(Color,X,Y,Row,Col,SizeX,SizeY);
				}
			}	
			if (GetKeyState(VK_SHIFT) & 0x8000 )
			{
				system("cls");
				
				GetData();

			}


			}
			

		
}
void SetWindow(int Width, int Height){
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width -1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}


