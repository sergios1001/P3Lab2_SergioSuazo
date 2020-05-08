#include <iostream>
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

				
				break;
				
				
			} 
			    
			case 3:{

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
