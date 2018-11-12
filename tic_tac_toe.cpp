#include<bits/stdc++.h>
using namespace std;

void print(vector<string>a){
	long long int i, j;
	for(i=0; i<3; i++){
		j = i*3;
		cout<<" "<<a[j]<<" | "<<a[j+1]<<" | "<<a[j+2]<<endl;
		if(i<2){
			cout<<"------------"<<endl;
		}
	} 
}

bool empty(vector<string>a){
	long long int i;
	for(i=0; i<9; i++){
		if(a[i] == " "){
			return true;
		}
	} 
	return false;
}

long long int check(vector<string>a, long long int count){
	long long int i, j, p= 0;
	string s;
	for(i=0; i<3; i++){
		j = i * 3;
		if(a[j] == a[j+2] && a[j+1]==a[j+2] && a[j] != " "){
			p = 1;
			s = a[j];
			break;
		}
		if(a[i] == a[i+3] && a[i+3] == a[i+6] && a[i] != " "){
			p = 1;
			s = a[i];
			break;
		}
	}
	if(a[0] == a[4] && a[4] == a[8] && a[0] != " "){
		p = 1;
		s = a[0];
	}
	else if(a[2] == a[4] && a[4] == a[6] && a[2] != " "){
		p = 1;
		s = a[2];
	}
	if(p == 0){
		if(empty(a)){
			return 0;
		}
		else{
			return 3;
		}
	}
	if((count == 1 && s == "O") || (count == 2 && s == "X")){
		return 2;
	}
	else if((count == 1 && s == "X") || (count == 2 && s=="O")){
		return 1;
	}
}

long long int drive(vector<string>a, bool chance, long long int count){
	long long int pain, better, i;
	pain = check(a, count);
	if(pain == 1){
		return 1;
	}
	else if(pain == 2){
		return -1;
	}
	else if(pain == 3){
		return 0;
	}
	else{
		if(chance){
			better = -2;
			for(i=0; i<9; i++){
				if(a[i] == " "){
					if(count == 1){
						a[i] = "X";
					}
					else{
						a[i] = "O";
					}
					better = max(better, drive(a, !chance, count));
					a[i] = " ";
				}
			}
		}
		else{
			better = 2;
			for(i=0; i<9; i++){
				if(a[i] == " "){
					if(count == 1){
						a[i] = "O";
					}
					else{
						a[i] = "X";
					}
					better = min(better, drive(a, !chance, count));
					a[i] = " ";
				}
			}
		}
		return better;
	}
}

long long int bestmove(vector<string>a, long long int count){
	long long int value = -2, i, j, movalue, mov;
	for(i=0; i<9; i++){
		if(a[i] == " "){
			if(count == 1){
				a[i] = "X";
			}
			else{
				a[i] = "O";
			}
			movalue= drive(a, false, count);
			if(movalue > value){
				mov = i;
				value = movalue;
			}
			a[i] = " ";
		}
	}
	return mov;
}

int main(){
	long long int i, j, count=0, count1=0, count2, count3;
	cout<<"Do You want to play the game?Y/N"<<endl;
	string s, s1;
	cin>>s;
	vector<string>a;
	for(i=0; i<9; i++){
		a.push_back(" ");
	}
	if(s == "Y"){
		cout<<"Choose O or X"<<endl;
		cin>>s1;
		cout<<"Wanna play first or second(1/2)"<<endl;
		cin>>count2;
		if(s1 == "X"){
			count = 2;
		}
		else if(s1 == "O"){
			count = 1;
		}
		if(count2 == 1){
			count1 = 1;
		}
		while(empty(a)){
			if(count1 == 1){
				cout<<"Choose a box"<<endl;
				cin>>count3;
				if(count == 1){
					a[count3-1] = "O"; 
				}
				else{
					a[count3-1] = "X";
				}
				count1 = 2;
			}
			else{
				count3 = bestmove(a, count);
				if(count == 1){
					a[count3] = "X";
				}
				else{
					a[count3] = "O";
				}
				count1 = 1;
			}
			print(a);
			cout<<endl;
			if(check(a, count) != 0){
				break;
			}
		}
		if(check(a, count) == 1){
			cout<<"Victory is a constant variable;)intiated to !you "<<endl;
		}
		else if(check(a,count) == 2){
			cout<<"This never happens;)"<<endl;
		}
		else if(check(a, count) == 3){
			cout<<"Nice try"<<endl;
		}
	}
	else{
		cout<<"I can't force you to choose the right option"<<endl;
	}
	return 0;
}
