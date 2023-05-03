#include<iostream>
#include<fstream>
using namespace std;

string encrypt(string s){
	int length = s.length();
	for(int i = 0; i<length; i++){
		s[i] = s[i] + 5;
	}
	return s;
}

string decrypt(string s){
	int length = s.length();
	for(int i = 0; i<length; i++){
		s[i] = s[i] - 5;
	}	
	return s;
}

int main(){
	cout<<"            Encryption and Decryption of Data"<<endl;
	cout<<"----------------------------------------------------------------"<<endl<<endl;
	while(1){
	int choice;
	string word;
	cout<<endl;
	cout<<"Encryption or Decryption should be performed "<<endl;
	cout<<"1. On String\n";
	cout<<"2. To File\n";
	cout<<"3. Exit\n";
	cout<<"Choose the number (\'1\' for string, \'2\' for file and \'3\' for exiting): ";
	cin>>choice;
	switch(choice){
		case 1:
			int ch;
			cout<<endl;
			cout<<"1. Encrypt the String"<<endl;
			cout<<"2. Decrypt the String"<<endl;
			cout<<"Choose an operation: ";
			cin>>ch;
			switch(ch){
				case 1:
					cout<<"Enter a string to encrypt: ";
					getline(cin>>ws, word);
					cout<<"The encrypted string: "<<encrypt(word)<<endl;
					break;
				case 2:
					cout<<"Enter a string to decrypt: ";
					getline(cin>>ws, word);
					cout<<"The decrypted string: "<<decrypt(word)<<endl;
					break;
				default:
					cout<<"Invalid Choice"<<endl;
					break;
			}
			break;
		case 2:
			int cho;
			cout<<endl;
			cout<<"1. Encrypt a File"<<endl;
			cout<<"2. Decrypt a File"<<endl;
			cout<<"Choose an operation: ";
			cin>>cho;
			if(cho == 1){
					char filename[45];
					char c;
					cout<<"Enter the filename you want to encrypt (with an extension) : ";
					cin>>filename;
					fstream file, fileout;
					file.open(filename, ios::in);
					fileout.open("tempfile.txt", ios::out);
					if(!file){
						cout<<"Error: opening the mentioned file\n";
						exit(1);
					}
					file.seekg(0);
					for(int i = 0; file.get(c); i++){
						fileout<<c;
					}
					file.close();
					fileout.close();
					file.open(filename, ios::out);
					fileout.open("tempfile.txt", ios::in);
					fileout.seekg(0);
					char ch;
					for(int i = 0; fileout.get(c); i++){
						ch =c + 5;
						file<<ch;
					}
					file.close();
					fileout.close();
					remove("tempfile.txt");
					cout<<"File encrypted successfully..."<<endl;
				}
				
				if(cho == 2){
					char filename[45];
					char c;
					cout<<"Enter the filename you want to decrypt (with an extension) : ";
					cin>>filename;
					fstream file, fileout;
					file.open(filename, ios::in);
					fileout.open("tempfile.txt", ios::out);
					if(!file){
						cout<<"Error: opening the mentioned file\n";
						exit(1);
					}
					file.seekg(0);
					for(int i = 0; file.get(c); i++){
						fileout<<c;
					}
					file.close();
					fileout.close();
					file.open(filename, ios::out);
					fileout.open("tempfile.txt", ios::in);
					fileout.seekg(0);
					char ch;
					for(int i = 0; fileout.get(c); i++){
						ch =c - 5;
						file<<ch;
					}
					file.close();
					fileout.close();
					remove("tempfile.txt");
					cout<<"File decrypted successfully..."<<endl;
				}
			case 3:
				return 0;
			default:
				cout<<"Invalid Choice"<<endl;
				break;
		}
	}
}
