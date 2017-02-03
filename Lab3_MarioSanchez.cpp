#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void menu(int);

int main(){
	cout<<"Desea usar el programa? S/N"<<endl;
	char resp;
	cin>>resp;
	while(resp == 's' || resp == 'S'){
		cout<<"1. Fechas\n2. Signos balanceados"<<endl;
		int men;
		cin>>men;
		menu(men);
		cout<<"Desea seguir S/N";
		cin>>resp;
	}
}

void menu(int men){
	switch(men){
		case 1:{
				
		}
		case 2:{
			string sign;
			string c;
			cout<<"Ingrese un caracter"<<endl;
			cin>>c;
			sign += c;
			cout<<"Desea ingresar otro signo? S/N"<<endl;
			char resp;
			cin>>resp;

			while(resp =='s' ||resp == 'S'){
				c="";
				cout<<"Ingrese un caracter"<<endl;
				cin>>c;
				sign += c;
				cout<<"Desea ingresar otro signo? S/N"<<endl;
				
				cin>>resp;
			}

			int size = sign.length();
			cout<<size<<" " <<size/2<<endl;

			if(size % 2 == 1){
				cout<<"Los signos no estan balanceados"<<endl;
			}else{
				string arre1[size/2];
				string arre2[size/2];
				for(int i = 0; i< (size/2); i++){
					arre1[i]= sign.at(i);
					cout<<"Los caracteres del arreglo 1 son "<< arre1[i]<<endl;
				}

				int j = 0;

				for(int i = size/2; i < size; i++){
					arre2[j] = sign.at(i);
					
					cout<<"Los caracteres del arreglo 2 son "<< arre2[j]<<endl;
					j++;
				}
				
				int temp = (size/2)-1;
				int cont = 0;
				
				for(int i = 0; i < (size/2); i++){
					if(arre1[i] == "{"){
						if(arre2[temp] == "}"){
							cont++;
						}
						temp--;
					}else if(arre1[i] == "("){
						if(arre2[temp] == ")"){
							cont++;
						}
						temp--;
					}else if(arre1[i] == "["){
						if(arre2[temp] == "]"){
							cont++;
						}
						temp--;		
					}
				}
				if(cont == size/2){
					cout<<"Los signos son balanceados"<<endl;
				} else {
					cout<<"Los signos no son balanceados"<<endl;
				}
			}
		}
	}
}








