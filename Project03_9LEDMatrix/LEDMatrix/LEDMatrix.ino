// Declare a 2-dimensional array of variables
// called "matrix". We'll initialize it with the
// pin numbers of the LEDs we're using:

int matrix[3][3] = {2,3,4,
                    5,6,7,
                    8,9,10};

// To read a number out of the matrix, use y (vertical)
// and x (horizontal) indexes from 0 to 2:

//          X
//        0 1 2
//
//    0   2 3 4
//  Y 1   5 6 7
//    2   8 9 10

// When reading or writing from an array, enclose the
// indexes in brackets, and put the Y index first:

// matrix[0][0] returns 2
// matrix[0][1] returns 3
// matrix[1][0] returns 5
// matrix[2][0] returns 8
// matrix[2][2] returns 10

void setup()
{
  int x,y;
  
  // Step through the whole matrix using x and y
  // Make each pin an output
  // And turn the output off (LOW):

  // This for loop will step y from 0 to 2

  for (y=0; y<=2; x++)
  {
    for (x=0; x<=2; x++)
    {
      pinMode(matrix[y][x],OUTPUT);
      digitalWrite(matrix[y][x],LOW);
    }
  }
}

void loop()
{
  int x,y;

  // These random number generators will return numbers
  // from 0 to 2:

  x = random(3);
  y = random(3);

  digitalWrite(matrix[y][x],HIGH);
  delay(100);
  digitalWrite(matrix[y][x],LOW);
}

void single(int x, int y, boolean on)
{
  digitalWrite(matrix[y][x],on);
}

void row(int y, boolean on)
{
  int x;
  
  for (x=0; x<3; x++)
  {
    single(x,y,on);
  }
}

void column(int y, boolean on)
{
  int x;
  
  for (x=0; x<3; x++)
  {
    single(x,y,on);
  }
}
