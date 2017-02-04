#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

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
			vector<string> vect;
			int err =0;
			while(err == 0){
				cout<<"Ingrese una fecha YYYY/MM/DD"<<endl;
				string fecha;
				cin>>fecha;
				string ano;
				string mes;
				string dia;
				if(fecha.length()>8){
					cout<<"No puede ingresar una fecha que no existe"<<endl;
					err = 1;
				} else{
					for(int i = 0; i<4; i++){
						if(i<4){
							ano += fecha.at(i);
						}else if(i>3 && i<6){
							mes += fecha.at(i);
						}else if(i>5 && i<8){
							dia += fecha.at(i);
						}
					}
					if(ano > "2017"){
						cout<<"Ese año aun existe"<<endl;
						err = 1;
					}
					if(mes > "12"){
						cout<<"Ese mes no existe"<<endl;
						err = 1;
					}
					if((mes == "01" || mes == "03" || mes == "05" || mes == "07" || mes == "08" || mes == "10" || mes == "12") && stoi(dia) > 31){
						cout<<"Ese dia no existe"<<endl;
						err = 1;
					}else if((mes == "04" || mes == "06" || mes == "09" || mes == "11") && stoi(dia) > 30){
						cout<<"Ese dia no existe"<<endl;
						err = 1;
					} else{
						int bis = 0;
						if(stoi(ano) % 4 == 0){
							bis++;
						}
						if(stoi(ano) % 100 == 0){
							bis++;
						}
						if(stoi(ano) % 400 == 0){
							bis++;
						}
						if(bis == 3){
							if(mes == "02" && stoi(dia) >29){
								cout<<"Ese dia no existe"<<endl;
								err = 1;
							}
						}else{
							if(mes == "02" && stoi(dia) > 28){
								cout<<"Ese dia no existe"<<endl;
								err = 1;
							}
						}
					}
				cout<<"Listando..."<<endl;
				vect.push_back(fecha);
				for(int i = 0; i < vect.size(); i++){
					cout<<i<<". "<<vect[i]<<endl;
				}
				}
			}
			break;
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
			break;

		}
	}
}








