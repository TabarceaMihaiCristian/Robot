#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Plan[51][51];// Matrix representing the plane in which the robot moves
int length, width; // the length and width of the matrix
int X, Y, Direction; // The coordinates of the robot in the plane (X,Y) and the cardinal point towards which it is directed
char Moves[101]; // Series of moves that the robot has to execute

char Change_Direction(char next_direction, char facing_pozition);
void Print(int Edge, int X, int Y, int Cardinal_Direction);

int main(){
    
    FILE *P19f = fopen("P19_Input_file.txt", "r"); 

    fscanf(P19f, "%d %d", &length, &width); // Plan dimension reading

    while(fscanf(P19f, "%d %d %c",&X, &Y, &Direction) != EOF){ // Coordinates and pozition reading
        
        fscanf(P19f, "%s", &Moves); // Read the series of moves
        int l = strlen(Moves); // Lenght of the series of moves
        

        int Edge = 0; // A flag for the "LOST" case
        for(int i = 0; i < l; i++){
            if(Moves[i] == 'R'){
                Direction = Change_Direction(Moves[i], Direction); // Turn Right
            }
            else
                if(Moves[i] == 'L'){
                    Direction = Change_Direction(Moves[i], Direction); // Turn Left
                }
                else 
                    if(Moves[i] == 'F'){
                        if(Direction == 'N'){
                            if(Plan[X][Y] == 0)
                                if(Y < width)
                                    Y++;
                                else{
                                    Plan[X][Y] = 1;
                                    Edge = 1;
                                    i = l+1;
                                }
                            else{
                                if(Plan[X][Y] != 1)
                                    if(Y < width)
                                        Y++;
                                    else{
                                        Plan[X][Y] = 1;
                                        Edge = 1;
                                        i = l+1;
                                    }
                            }
                        }else
                            if(Direction == 'E'){
                                if(Plan[X][Y] == 0)
                                    if(X < length)
                                        X++;
                                    else{
                                        Plan[X][Y] = 2;
                                        Edge = 1;
                                        i = l+1;
                                    }
                                else{
                                    if(Plan[X][Y] != 2)
                                        if(X < length)
                                             X++;
                                    else{
                                        Plan[X][Y] = 2;
                                        Edge = 1;
                                        i = l+1;
                                    }
                                }
                            }else
                                if(Direction == 'S'){
                                    if(Plan[X][Y] == 0)
                                        if(Y >= 0)
                                            Y--;
                                        else{
                                            Plan[X][Y] = 3;
                                            Edge = 1;
                                            i = l+1;
                                        }
                                    else{
                                        if(Plan[X][Y] != 3)
                                            if(Y >= 0)
                                            Y--;
                                        else{
                                            Plan[X][Y] = 3;
                                            Edge = 1;
                                            i = l+1;
                                        }
                                    }
                                }else
                                    if(Direction == 'W'){
                                        if(Plan[X][Y] == 0)
                                            if(X >= 0)
                                                X--;
                                            else{
                                                Plan[X][Y] = 4;
                                                Edge = 1;
                                                i = l+1;
                                            }
                                        else{
                                            if(Plan[X][Y] != 4)
                                                if(X >= 0)
                                                X--;
                                            else{
                                                Plan[X][Y] = 4;
                                                Edge = 1;
                                                i = l+1;
                                            }
                                        }
                                            
                                    }    
                    }
        }
        // Display coordinates after the "LOST" case using a print function
        Print(Edge, X, Y, Direction);
    }
    
    // Close file
    fclose(P19f);
    return 0;
}

// Cardinal point change function  
char Change_Direction(char next_direction, char facing_pozition){
    if(next_direction == 'R'){
        if(facing_pozition == 'N'){
            facing_pozition = 'E';
        }else 
            if(facing_pozition == 'E'){
                facing_pozition = 'S';
            }else
                if(facing_pozition == 'S'){
                    facing_pozition = 'W';
                }else
                    if(facing_pozition == 'W'){
                        facing_pozition = 'N';
                    }
    }
    else
        if(next_direction == 'L'){
            if(facing_pozition == 'N'){
                facing_pozition = 'W';
            }else 
                if(facing_pozition == 'E'){
                    facing_pozition = 'N';
                }else
                    if(facing_pozition == 'S'){ 
                        facing_pozition = 'E';
                    }else
                        if(facing_pozition == 'W'){
                            facing_pozition = 'S';
                        }
        }   
   return facing_pozition;
}

// Print function
void Print(int Edge, int X, int Y, int Cardinal_Direction){
    if(Edge)
        printf("%d %d %c LOST\n", X, Y, Cardinal_Direction);
    else
        printf("%d %d %c\n", X, Y, Cardinal_Direction);
}
