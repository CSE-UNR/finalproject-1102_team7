//Adam Beltran

//Hi! This is what I have so far... In sort of the way that I think the project should behave If you could upload yours so that I can get an idea of your thinking for this project, that would be great. If you have any questions about anything (the outline here is a little vauge) please ask!


Final project design document
Pictures
List of tools:
    • 2D Arrays
    • File IO
    • Scanf
    • Printf
    • Iteration

Functions: 

int main()

Data: Has the 2D array of an “unknown” size (until the user decides the size of their picture) 
Functionality: Gets the input from the user for their unknown file name. 

First_menu()
Input parameters:(int choice)
Returned output: should be an integer 
Functionality: Asks the user for their choice of either loading an image, displaying current image, exit the current image, and exiting the program 

Load_Image()
Input parameters: File pointer, 2D Array, length
Returned output: None (void)
Functionality: Takes the user’s image and writes it into a file for them to have saved. It should overwrite anything else in the 2D Array

Image_brightener()
Input parameters: 2D Array, int collum, int length 
Returned output: None (Void)
Functionality: Takes users picture and increases every pixel by +1 to increase brightness (since brightness is 0-4)

Image_dimmer()
Input parameters: 2D Array, int collum, int length
Returned Output: None (void)
Functionality:  Takes users picture and decreases every pixel by -1 to “dim” the picture 

Image_crop()
Input Parameters: 2D Array, int collum, int length
Returned Output: None (void) 
Functionality: Allows the user to select a part of the image and using that part of the image only 

Save_Image()
Input parameters: File pointer, 2D Array, int columns, int length 
Returned output: None (Void)
Functionality: Should ask the user if they want to save their image into a file that they name.

