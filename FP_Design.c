Skyler Resnick
Final Project Design

Data:
• ImageData: 2D array of int (representing pixel values)
• ImageFileName: string (to store the name of the image file)
• BrightnessScale: int (to track the brightness level of the image)

Functions:

• main()
  Data: 2d array with unknown size, strings, ints
  Functionality: Display the menu options, load/display/edit image based on user's choice, prompt to save edited image, repeat until the user chooses to exit.

• load_Image()
  Input Parameters: None
  Returned Output: None (void)
  Functionality:
    • Prompt the user to enter the file name of the image. Store the image data into a file

display_Image()
  Input Parameters: None
  Returned Output: None (void)
  Functionality:
    • When the image is loaded, display the image using printf based on the pixel values.

edit_Image()
  Input Parameters: None
  Returned Output: None (void)
  Functionality:
-	Ask the user to perform editing operations on the image:
      • Brighten_Image(): Increase pixels by 1 (0-4 scale).
      • Dim_Image(): Decrease pixel by 1 (0-4 scale).
      • Crop_Image(): Allow the user to make a smaller selection of the picture.

save_Image()
  Input Parameters: None
  Returned Output: None (void)
  Functionality:
    • Prompt the user if they want to save the edited image.
    • If yes, prompt for a file name and save the edited image to the file name stated at the start.
    • If no, return to the main menu.

brighten_Image()
  Input Parameters: None
  Returned Output: None (void)
  Functionality:
    • Increase the brightness level of the image (0•4 scale (0 • dim, 4 • bright)) ( , ., o, O, 0)

dim_Image()
  Input Parameters: None
  Returned Output: None (void)
  Functionality:
    • Decrease the brightness level of the image (0•4 scale (0 • dim, 4 • bright)) ( , ., o, O, 0)

crop_Image()
  Input Parameters: None
  Returned Output: None (void)
  Functionality:
    • Allow the user to make a smaller selection of the picture.

Repeat until the user chooses to exit the program.

