#include <iostream>

using namespace std;

enum PixelValues {BLACK, WHITE}; 
const int ROWS = 10;
const int COLS = 20; 

void print(PixelValues Canvas[ROWS][COLS]){
	for ( int i  = 0 ; i < ROWS;  i++){
		for ( int j  = 0 ; j < COLS;  j++){ 
			if(Canvas[i][j]	== BLACK){
					cout << "*" ;
			}else{
				cout << "  " ;
			}
		}
		cout << endl;
	}
}
/*
bool fillBlank(PixelValues Canvas[ROWS][COLS], int i, int j){
	if (i < 0 || i >=ROWS || j <0 || j > COLS){
		return false;
	}
	if(Canvas[i][j] == BLACK){
		return true;
	}
	if(Canvas[i][j] == WHITE){
		bool b = fillBlank(Canvas,i+1,j);
		bool r =fillBlank(Canvas,i,j+1);
		bool t = fillBlank(Canvas,i-1,j);
		bool l =fillBlank(Canvas,i,j-1);
		if (b && r && t && l){
			Canvas[i][j] = BLACK;
		}
		Canvas[i][j] = BLACK;
		
	}
}
*/

void fillBlank(PixelValues Canvas[ROWS][COLS], int i, int j){
	if (i < 0 || i >=ROWS || j <0 || j > COLS){
		return;
	}
	if(Canvas[i][j] == BLACK){
		return;
	}
	if(Canvas[i][j] == WHITE){
		Canvas[i][j] = BLACK;
		fillBlank(Canvas,i+1,j);
		fillBlank(Canvas,i,j+1);
		fillBlank(Canvas,i-1,j);
		fillBlank(Canvas,i+1,j-1);
		
	}
}
	

int main(){
	PixelValues Canvas[ROWS][COLS];
	for ( int i  = 0 ; i < ROWS;  i++){
		for ( int j  = 0 ; j < COLS;  j++){ 
			if (i == 0 || j ==0 || i == ROWS-1 || j == COLS-1 ){
				Canvas[i][j] = BLACK;
			} else if( i == j) {
				Canvas[i][j] = BLACK;
			}else{
				Canvas[i][j] = WHITE;
			}
		}
	}
	print(Canvas);
	fillBlank(Canvas, ROWS-2 , 2);
	print(Canvas);
}


	

