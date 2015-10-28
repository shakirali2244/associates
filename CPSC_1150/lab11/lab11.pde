int gridSize = 3;
int gapSize;
int[][] myArray = new int[gridSize][gridSize];
int circle = 1;
int cross = 2;


void setup(){
  size(400,400);
  gapSize = floor(width/gridSize);
  background(128);
  
  for (int i = 1; i < gridSize; i++)
    line(0, gapSize * i, width, gapSize * i);
  for (int i = 1; i < gridSize; i++)
    line(gapSize * i, 0, gapSize * i, width);
    
  fill(255,0,0);
  rect(400-20,400-20,10,10);
  fill(0,0,0);
  
}
void draw(){
  if (mousePressed){
    if((mouseX>380 && mouseX<390) || (mouseY>380 && mouseX<390)){
      background(128);
      for (int i = 1; i < gridSize; i++)
        line(0, gapSize * i, width, gapSize * i);
      for (int i = 1; i < gridSize; i++)
        line(gapSize * i, 0, gapSize * i, width); 
      fill(255,0,0);
      rect(400-20,400-20,10,10);
      fill(0,0,0);
          for (int i = 0; i < gridSize; i++){
            for (int j = 0; j < gridSize; j++){
              println(i+" , "+j);
              myArray[i][j] = 0;
            }
          }
          millis();
          
    }
  
    int whichX = floor((mouseX+1)/gapSize);
    int whichY = floor((mouseY+1)/gapSize);
    //print(myArray[whichX][whichY]);
    if(mouseButton == LEFT){
      if (myArray[whichX][whichY] == 0){
        ellipse(whichX*gapSize+gapSize/2, whichY*gapSize+gapSize/2, gapSize,gapSize);
        myArray[whichX][whichY] = circle;
      }
    }else if(mouseButton == RIGHT){
      if (myArray[whichX][whichY] == 0){
        line(whichX*gapSize,whichY*gapSize,whichX*gapSize+gapSize,whichY*gapSize+gapSize);
        line(whichX*gapSize,whichY*gapSize+gapSize,whichX*gapSize+gapSize,whichY*gapSize);
        myArray[whichX][whichY] = cross;
      }
    }    
    
    
    /*
    int winner = 0;
    for (int i = 0; i < gridSize; i++) {
        if (i == 0){
          for(int j = i; j < gridSize-1; j++){
            if (myArray[i][j] == myArray[i][j+1] && myArray[i][j]!=0){
              winner++;
            }
          }
        }else if (i == gridSize-1){
          for(int j = i; j>0; j--){
            if (myArray[i][j] == myArray[i][j-1] && myArray[i][j]!=0){
              winner++;
            }
          }
        }else{
          //middle
        }
    }
    if (winner >= 3 ){
      println("someone won");
    }*/
    
  }
  
}