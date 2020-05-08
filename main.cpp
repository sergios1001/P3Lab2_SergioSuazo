#include <iostream>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int menu(){
	int retValue=0;
	
	while(retValue < 1 || retValue > 5){
		
		cout<<"         MENU"<<endl
			<<"1.- Funcion Euler"<<endl
			<<"2.- Triangulo Pascal"<<endl
			<<"3.- Juego de Arreglos"<<endl
			<<"4.- Salir"<<endl
			<<"Ingrese una opcion entre 1 y 4: ";
			
			cin>>retValue;

			
			if(retValue >= 1 && retValue <= 5){
				break;
			}
				
			else{
						
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;
			}
					
	}//end while
	
	
	return retValue;
}

int mcd(int a,int b)
{
	int valor=1;
	int temp;
	while(a>b&&b>1)
	{
		if(a%b==0)
		{
			valor=0;
			//cout<<a<<endl;
			//cout<<b<<endl;
			//cout<<"entra";
			break;
		}
		temp=a;
		a=b;
		b=temp-a;
		if(b>a)
		{
			temp=b;
			b=a;
			a=temp;
		}
	}
	
	return valor;
}

void piramide(int n)
{
	int pascal[n][n];
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			pascal[i][0]=1;
		}
		else if(i==1)
		{
			pascal[i][0]=1;
			pascal[i][1]=1;
		}
		else
		{
			for(int j=1;j<i;j++)
			{
				pascal[i][i]=1;
				pascal[i][0]=1;
				pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			cout<<pascal[i][j]<<" ";
		}
		cout<<endl;
	}
}



int main(int argc, char** argv) {
	
	int option=0;
	while( option != 4 ) {
		
		switch( option = menu() ){ 
		
			case 1:{
				int n,euler=0;
				cout<<"Ingrese el numero n: ";
				cin>>n;
				for(int i=n-1;i>=1;i--)
				{
					if(mcd(n,i)==1)
					{
						euler++;
					}
				}
				cout<<"phi("<<n<<") = "<<euler<<endl;
				break;
			}
			case 2:{

				int size;
				cout<<"Ingrese el tamaño de la piramide: ";
				cin>>size;
				while(size<1)
				{
					cout<<"Ingrese un tamaño superior a 0: ";
					cin>>size;
				}
				piramide(size);
				break;	
			} 
			    
			case 3:{

				int size;
				cout<<"Ingrese un numero par: ";
				cin>>size;
				
				while(size<=0||size%2!=0)
				{
					cout<<"Error, porfavor ingrese un numero par: ";
					cin>>size;
				}
				int juego[size];
				
				for(int i=0;i<size;i++)
				{
					juego[i]=(-50)+rand()%((51)-(-50));
				}
				
				int ronda=2;
				
				int usados[ronda*2];
				
				int jugador1,jugador2,puntaje1=0,puntaje2=0;
				
				for(int i=0;i<ronda;i++)
				{
					cout<<"J1 escoge: ";
					cin>>jugador1;
					cout<<"Obtuvo: "<<juego[jugador1]<<endl;
					puntaje1+=juego[jugador1];
					
					cout<<"J2 escoge: ";
					cin>>jugador2;
					cout<<"Obtuvo: "<<juego[jugador2]<<endl;
					puntaje2+=juego[jugador2];
					
					if(i==ronda-1)
					{
						cout<<"FINAL - [PTS J1: "<<puntaje1<<" <-> PTS J2: "<<puntaje2<<"]"<<endl;
					}
					else
					{
						cout<<"Ronda"<<i+1<<" - [PTS J1: "<<puntaje1<<" <-> PTS J2: "<<puntaje2<<"]"<<endl;
					}
					
				}
				cout<<"Arreglo utilizado: [";
				for(int i=0;i<size;i++)
				{
					cout<<juego[i]<<" ";
				}
				cout<<"]"<<endl;

				break;
			}
			
			case 4:{

				//salir
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
						
		}//switch
	
	}//while
	return 0;
}
