# Image_Filter

## Project Description

An Image Filtering program built in C. The program can convert an image into grayscale, mirror, blur, detect edges.

Starter code provided by CS50

## How to Run

run the program: ```./filter [-options] <input image> <output image>```

example: ```./filter -g images/courtyard.bmp courtyard_gray.bmp```

## Options

-g Grayscale (Turn the image into Black and White)

-r Reflection (Mirror the image)

- b Blur (Blur the image)

- e Edge (Highlight edges in the image)

## Arguments

input image: path to the input image (must be .bmp extension)

output image: path and filename for the filtered image (must be a .bmp extenstion)

## Output

### Grayscale
Normal            |  Grayscale
:-------------------------:|:-------------------------:
![image](https://github.com/sohankancherla/Image_Filter/assets/30853467/e7ea5619-77ac-4f65-8f9f-c4f3f402aebb) | ![image](https://github.com/sohankancherla/Image_Filter/assets/30853467/6dd9d6ab-d01c-46b5-89c7-b7e7fa715df5)

### Reflection
Normal            |  Mirrored
:-------------------------:|:-------------------------:
![image](https://github.com/sohankancherla/Image_Filter/assets/30853467/bdea7d91-3880-4f50-99e5-cc801cf705b3) | ![image](https://github.com/sohankancherla/Image_Filter/assets/30853467/59f0d9e0-0af5-4c71-94d3-63af5942b6ae)

### Blur
Normal            |  Blurred
:-------------------------:|:-------------------------:
![image](https://github.com/sohankancherla/Image_Filter/assets/30853467/2235ce86-324e-4516-abb8-8641d5ceceba) | ![image](https://github.com/sohankancherla/Image_Filter/assets/30853467/e45413fc-11bd-471a-ab02-4602e4329b38)

### Edge
Normal            |  Edges
:-------------------------:|:-------------------------:
![image](https://github.com/sohankancherla/Image_Filter/assets/30853467/104a8512-4db4-47f5-92a3-9a8fe64b8504) | ![image](https://github.com/sohankancherla/Image_Filter/assets/30853467/5a9ef384-b271-4160-9680-e223c3f4dee0)









