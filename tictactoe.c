#include <stdio.h>
#include <stdlib.h>
#define gc getchar_unlocked
inline int scan(){register int n=0,c=gc();while(c<'0'||c>'9')c=gc();while(c<='9'&&c>='0')n=(n<<1)+(n<<3)+c-'0',c=gc();return n;} 

char matrix[3][3];  /* the tic tac toe matrix */

char check(void);
void init_matrix(void);
void get_player_move(int);
void get_computer_move(int);
void disp_matrix(void);

int main(void)
{
  int choice;
  char done;
  printf(" 1 - Human Vs Human\n 2 - Human Vs Computer \n 3- Comp Vs Comp \n");
  choice = scan();
  done =  ' ';
  init_matrix();    
  
        do {
        disp_matrix();
        get_player_move(choice);
        done = check(); /* see if winner */
        if(done!= ' ') break; /* winner!*/
        get_computer_move(choice);
        done = check(); /* see if winner */
        }while(done== ' ');

        if(done=='X') {disp_matrix(); if (choice==1||2)printf("1st Human Won!\n\n"); else printf("1st Computer Won\n\n");}
        else {disp_matrix(); if (choice ==1) printf("2nd Human Won!!!!\n\n"); else printf("2nd Computer Won!!!!\n\n");}
        // /* show final positions */
      
  return 0;
}

/* Initialize the matrix. */
void init_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
    for(j=0; j<3; j++) matrix[i][j] =  ' ';
}

/* Get a player's move. */
void get_player_move(int choice)
{
  int x, y;
  int i,j;
  //printf("Enter X,Y coordinates for your move: \n");
  
  if ( choice == 1 || choice == 2 ){
  x=scan();
  y=scan();
  }//get X for human
  else 
  {
   for(i=0; i<3; i++){
     for(j=0; j<3; j++)
       if(matrix[i][j]==' ') break;
     if(matrix[i][j]==' ') break;
    }//for
  }//else  
  x--; y--;
  
  if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    get_player_move(choice);
  }
  else matrix[x][y] = 'X';
}

/* Get a move from the computer. */
void get_computer_move(int choice)
{
  int i, j ,x, y;
    
 if ( choice == 1 ){
  x=scan();
  y=scan();
  }//get 0 for human
 else {
   for(i=0; i<3; i++){
     for(j=0; j<3; j++)
       if(matrix[i][j]==' ') break;
     if(matrix[i][j]==' ') break;
    }//for
  }//else
  
  if(i*j==9)  {
    printf("draw\n");
    exit(0);
  }
  else
    matrix[i][j] = 'O';
}

/* Display the matrix on the screen. */
void disp_matrix(void)
{
  int t;
  printf("\n");
  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    if(t!=2) printf("\n---|---|---\n");
  }
  printf("\n");
}

/* See if there is a winner. */
char check(void)
{
  int i;

  for(i=0; i<3; i++)  /* check rows */
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2]) return matrix[i][0];

  for(i=0; i<3; i++)  /* check columns */
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i]) return matrix[0][i];

  /* test diagonals */
  if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2])
       return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] &&
     matrix[1][1]==matrix[2][0])
       return matrix[0][2];

  return ' ';
}

//STD INPUT 
// Choice 1 ) 1 1 1 2 1 3 1 2 2 3 3 3 1 2 1 3 2 2 3
// Choice 2 ) 2 1 1 2 1 3 1 2 2 3 3 3 1 2 1 3 2 2 3
// Choice 3 ) 3
