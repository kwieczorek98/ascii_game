#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <cctype>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void get_info();
void get_title();
void initialize();
void user_name();
int game();
int menu_loop();

int main(int argc, char** argv) {


		initialize();
		
		get_title();
		
		user_name();
			
		menu_loop();
	
	
	
	return 0;
}

int menu_loop()
{
	
	HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	int option;
	do{

		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN); 
		cout<<"[1]. GRAJ"<<endl;
		
		
		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE); 
		cout<<"[2]. O GRZE"<<endl;
		
		
		SetConsoleTextAttribute( hOut, FOREGROUND_RED); 
		cout<<"[3]. WYJDZ"<<endl;
		
		SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"Twoj wybor: ";
		SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin>>option;

		
					
		switch(option)
		{
			case 1: 
				game();
				break;
				
			case 2:
				get_info(); 
				break;
		}
	
			SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY);
		

	
	}while(option != 3);

};
void get_title() 
{
	string title_line;
	fstream title;
	title.open("title.txt");
       
	   if(title.good() == true)
	    {
	    
			system("COLOR 0B");
			while( getline( title,  title_line ) )
	   		
     		cout << title_line << endl;
	   	
	   		title.close();
		};
		
};

void get_info() 
{
	HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	string info_line;
				fstream info;
				info.open("info.txt");
						   if(info.good() == true)
						    {
						    	
								
								while( getline( info, info_line ) )
								{
								
						   		SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					     		cout << info_line << endl;
					     	
						   		}
						   		info.close();
							};
};


void initialize()
{
	
	
	HWND hOut = GetConsoleWindow();
	
	RECT rect;
	GetWindowRect(hOut, &rect); 
    MoveWindow(hOut, rect.left, rect.top, 1280, 720, TRUE);
    
    
	SetConsoleTitle( "Ascii Game" );
	

};

int game() 
{
				char c; 
				HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
				srand( time( NULL ));
				
				int a = rand()%25+97;
				char znak = a;
				int pkt=5; 
				do{
				SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY);
				cout<<"Wpisz klawisz: ";
				
				SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cin>>c;
				cin.ignore();
				//cout<<znak<<endl; 
				
				if(c <97 || c> 122) 
				{
					SetConsoleTextAttribute( hOut, FOREGROUND_RED);
					cout<<"To nie jest mala litera alfabetu ! Moze masz wlaczonego Caps Lock'a ?"<<endl;
				}else{
				
				
					if(a == c){
						SetConsoleTextAttribute( hOut, FOREGROUND_GREEN);
						cout<<"Brawo!"<<endl;
					
						cout<<"Twoj wynik to: "<<pkt<<" pkt!"<<endl;
							int op_wynik;
							SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							cout<<"Czy chcesz otrzymac swoj wynik w pliku ?"<<endl;
							SetConsoleTextAttribute( hOut, FOREGROUND_GREEN);
							cout<<"[1]. Tak"<<endl;
							SetConsoleTextAttribute( hOut, FOREGROUND_RED);
							cout<<"[2]. Nie"<<endl;
							SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							cin>>op_wynik;
							switch(op_wynik)
								{
								case 1:
								
									ofstream wynik("wynik.txt");;
									
									wynik<<"Twoj wynik to:"<<pkt;
									wynik.close();
									break;
								}
							
							
					}else
					{
						Beep(600,400);
						SetConsoleTextAttribute( hOut, FOREGROUND_RED);
						cout<<"Zle"<<endl;
						pkt--;
						cout<<"Twoj wynik to: "<<pkt<<" pkt!"<<endl;
					};
					if (pkt == 0){ 
						SetConsoleTextAttribute( hOut, FOREGROUND_RED);
						cout<<"Niestety nie odgadles tego co wylosowalem... Sproboj nastepnym razem !"<<endl;
						cout<<"A byla to litera: ";
						SetConsoleTextAttribute( hOut, FOREGROUND_GREEN);
						cout<<znak;
						SetConsoleTextAttribute( hOut, FOREGROUND_RED);
						cout<<" !"<<endl;
						SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY);
						return 0;
					
					}
				
				}
				}while(a != c);
};

void user_name()
{
		const short size = 100;
		char name[size];
		
		cout<<"Podaj swoje imie (lub imiona): ";
	
		cin.getline( name, size );
	
	    cout<<"Witaj "<<name<<"!"<<endl;
	       
	    

		cout<<"Prosze wybierz jedna opcje."<<endl;
};


