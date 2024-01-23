#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

// TODO Write this function
int energy(const Pixel*const* image, int col, int row, int width, int height){
	int redXGradient = 0;
	int greenXGradient = 0;
	int blueXGradient = 0;
	int redYGradient = 0;
	int greenYGradient = 0;
	int blueYGradient = 0;	
	int xGradient = 0;
	int yGradient = 0;
	int result = 0;
	//if width and height are 2 or below, then they have no pixels with energy
	if(width <= 2 && height <= 2){
		return 0;
	}
	//4 cases where small images have pixels containing energy
	if(width == 1 && height == 3){
		if(row-1 == -1){
			redYGradient = image[col][row+1].r - image[col][height-1].r;
			greenYGradient = image[col][row+1].g - image[col][height-1].g;
			blueYGradient =  image[col][row+1].b - image[col][height-1].b;
			
			yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
			result = yGradient;
			return result;
		}
		else if(row+1 == height){
			redYGradient = image[col][0].r - image[col][row-1].r;
			greenYGradient = image[col][0].g - image[col][row-1].g;
			blueYGradient =  image[col][0].b - image[col][row-1].b;
			
			yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
			result = yGradient;
			return result;
		}
		else{
			redYGradient = image[col][row+1].r - image[col][row-1].r;
			greenYGradient = image[col][row+1].g - image[col][row-1].g;
			blueYGradient = image[col][row+1].b - image[col][row-1].b;
			
			yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
			result = yGradient;
			return result;
		}
	}
	if(width == 3 && height == 1){
		if(col+1 == width){
			redXGradient = image[0][row].r - image[col-1][row].r;
			greenXGradient = image[0][row].g - image[col-1][row].g;
			blueXGradient = image[0][row].b - image[col-1][row].b;
			
			xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
			result = xGradient;
			return result;
		}
		else if(col-1 == -1){
			redXGradient = image[col+1][row].r - image[width-1][row].r;
			greenXGradient = image[col+1][row].g - image[width-1][row].g;
			blueXGradient = image[col+1][row].b - image[width-1][row].b;
			
			xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
			result = xGradient;
			return result;
		}
		else{
			redXGradient = image[col+1][row].r - image[col-1][row].r;
			greenXGradient = image[col+1][row].g - image[col-1][row].g;
			blueXGradient = image[col+1][row].b - image[col-1][row].b;
			
			xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
			result = xGradient;
			return result;
		}
	}
	/*
	if(width == 2 && height == 3){
		
	}
	if(width == 3 && height == 2){
		
	}*/
	
	
	//top left border pixel
	if(col-1 == -1 && row-1 == -1){
		redXGradient = image[col+1][row].r - image[width-1][row].r;
		greenXGradient = image[col+1][row].g - image[width-1][row].g;
		blueXGradient = image[col+1][row].b - image[width-1][row].b;
		
		redYGradient = image[col][row+1].r - image[col][height-1].r;
		greenYGradient = image[col][row+1].g - image[col][height-1].g;
		blueYGradient = image[col][row+1].b - image[col][height-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}
	//bottom left border pixel
	else if(col-1 == -1 && row+1 == height){
		redXGradient = image[col+1][row].r - image[width-1][row].r;
		greenXGradient = image[col+1][row].g - image[width-1][row].g;
		blueXGradient = image[col+1][row].b - image[width-1][row].b;
		
		redYGradient = image[col][0].r - image[col][row-1].r;
		greenYGradient = image[col][0].g - image[col][row-1].g;
		blueYGradient = image[col][0].b - image[col][row-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}		
	//top right border pixel
	else if(col+1 == width && row-1 == -1){
		redXGradient = image[0][row].r - image[col-1][row].r;
		greenXGradient = image[0][row].g - image[col-1][row].g;
		blueXGradient = image[0][row].b - image[col-1][row].b;
		
		redYGradient = image[col][row+1].r - image[col][height-1].r;
		greenYGradient = image[col][row+1].g - image[col][height-1].g;
		blueYGradient = image[col][row+1].b - image[col][height-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}
	//bottom right border pixel
	else if(col+1 == width && row+1 == height){
		redXGradient = image[0][row].r - image[col-1][row].r;
		greenXGradient = image[0][row].g - image[col-1][row].g;
		blueXGradient = image[0][row].b - image[col-1][row].b;
		
		redYGradient = image[col][0].r - image[col][row-1].r;
		greenYGradient = image[col][0].g - image[col][row-1].g;
		blueYGradient = image[col][0].b - image[col][row-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}
	//catching any border pixels left behind
	else if(col-1 == -1){
		redXGradient = image[col+1][row].r - image[width-1][row].r;
		greenXGradient = image[col+1][row].g - image[width-1][row].g;
		blueXGradient = image[col+1][row].b - image[width-1][row].b;
		
		redYGradient = image[col][row+1].r - image[col][row-1].r;
		greenYGradient = image[col][row+1].g - image[col][row-1].g;
		blueYGradient = image[col][row+1].b - image[col][row-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;			
	}
	//catching any border pixels left behind
	else if(row-1 == -1){			
		redXGradient = image[col+1][row].r - image[col-1][row].r;
		greenXGradient = image[col+1][row].g - image[col-1][row].g;
		blueXGradient = image[col+1][row].b - image[col-1][row].b;
		
		redYGradient = image[col][row+1].r - image[col][height-1].r;
		greenYGradient = image[col][row+1].g - image[col][height-1].g;
		blueYGradient = image[col][row+1].b - image[col][height-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}		
	//regular right border pixel
	else if(col+1 == width){
		redXGradient = image[0][row].r - image[col-1][row].r;
		greenXGradient = image[0][row].g - image[col-1][row].g;
		blueXGradient = image[0][row].b - image[col-1][row].b;
		
		redYGradient = image[col][row+1].r - image[col][row-1].r;
		greenYGradient = image[col][row+1].g - image[col][row-1].g;
		blueYGradient = image[col][row+1].b - image[col][row-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}
	//regular left border pixel
	else if(col-1 == -1 && col+1 < width){
		redXGradient = image[col+1][row].r - image[width-1][row].r;
		greenXGradient = image[col+1][row].g - image[width-1][row].g;
		blueXGradient = image[col+1][row].b - image[width-1][row].b;
		
		redYGradient = image[col][row+1].r - image[col][row-1].r;
		greenYGradient = image[col][row+1].g - image[col][row-1].g;
		blueYGradient = image[col][row+1].b - image[col][row-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}
	//regular top border pixel
	else if(row-1 == -1 && row+1 < height){
		redXGradient = image[col+1][row].r - image[col-1][row].r;
		greenXGradient = image[col+1][row].g - image[col-1][row].g;
		blueXGradient = image[col+1][row].b - image[col-1][row].b;
		
		redYGradient = image[col][row+1].r - image[col][height-1].r;
		greenYGradient = image[col][row+1].g - image[col][height-1].g;
		blueYGradient = image[col][row+1].b - image[col][height-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}
	//regular bottom border pixel
	else if(row+1 == height){
		redXGradient = image[col+1][row].r - image[col-1][row].r;
		greenXGradient = image[col+1][row].g - image[col-1][row].g;
		blueXGradient = image[col+1][row].b - image[col-1][row].b;
		
		redYGradient = image[col][0].r - image[col][row-1].r;
		greenYGradient = image[col][0].g - image[col][row-1].g;
		blueYGradient = image[col][0].b - image[col][row-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}
	//catching the nonborder pixels
	else{
		redXGradient = image[col+1][row].r - image[col-1][row].r;
		greenXGradient = image[col+1][row].g - image[col-1][row].g;
		blueXGradient = image[col+1][row].b - image[col-1][row].b;
		
		redYGradient = image[col][row+1].r - image[col][row-1].r;
		greenYGradient = image[col][row+1].g - image[col][row-1].g;
		blueYGradient = image[col][row+1].b - image[col][row-1].b;
		
		xGradient = (redXGradient*redXGradient) + (greenXGradient*greenXGradient) + (blueXGradient*blueXGradient);
		yGradient = (redYGradient*redYGradient) + (greenYGradient*greenYGradient) + (blueYGradient*blueYGradient);
		result = xGradient + yGradient;
		return result;
	}
	return result;
}

// TODO Write this function
int getVerticalSeam(const Pixel *const*image, int start_col, int width, int height, int* seam)
{
	seam[0] = start_col;
	int col = start_col;
	int totalEnergy = energy(image, start_col, 0, width, height);
	//i = index/row
	if(width == 1){
		for(int i = 1; i < height; i++){
			totalEnergy += energy(image,col,i,width,height);
			seam[i] = col;
		}
		return totalEnergy;
	}
	for(int i = 1; i < height; i++){
		if(col == 0){
			//when middle is less than or equal to the left
			if(energy(image,col,i,width,height) <= energy(image,col+1,i,width,height)){
				totalEnergy += energy(image,col,i,width,height);
				seam[i] = col;
			}
			else{
				totalEnergy += energy(image,col+1,i,width,height);
				seam[i] = col+1;
				col++;
			}
		}
		else if(col == width-1){
			//when the middle is less than or equal to the right
			if(energy(image,col,i,width,height) <= energy(image,col-1,i,width,height)){
				totalEnergy += energy(image,col,i,width,height);
				seam[i] = col;
			}
			else{
				totalEnergy += energy(image,col-1,i,width,height);
				seam[i] = col-1;
				col--;
			}
		}
		else{
			//when middle is less than or equal to left and right
			if(energy(image,col,i,width,height) <= energy(image,col-1,i,width,height) && energy(image,col,i,width,height) <= energy(image,col+1,i,width,height)){
				totalEnergy += energy(image,col,i,width,height);
				seam[i] = col;
			}
			//when middle is equal to the left and less than the right
			else if(energy(image,col,i,width,height) == energy(image,col-1,i,width,height) && energy(image,col,i,width,height) < energy(image,col+1,i,width,height)){
				totalEnergy += energy(image,col,i,width,height);
				seam[i] = col;
			}
			//when middle is equal to right and less than the left
			else if(energy(image,col,i,width,height) == energy(image,col+1,i,width,height) && energy(image,col,i,width,height) < energy(image,col-1,i,width,height)){
				totalEnergy += energy(image,col,i,width,height);
				seam[i] = col;
			}
			//when left is less than both the middle and right
			else if(energy(image,col+1,i,width,height) < energy(image,col,i,width,height) && energy(image,col+1,i,width,height) < energy(image,col-1,i,width,height)){
				totalEnergy += energy(image,col+1,i,width,height);
				seam[i] = col+1;
				col++;
			}
			//when left is equal to the middle and less than the right
			else if(energy(image,col+1,i,width,height) == energy(image,col,i,width,height) && energy(image,col+1,i,width,height) < energy(image,col-1,i,width,height)){
				totalEnergy += energy(image,col+1,i,width,height);
				seam[i] = col+1;
				col++;
			}
			//when left is less than the middle and equal to the right
			else if(energy(image,col+1,i,width,height) < energy(image,col,i,width,height) && energy(image,col+1,i,width,height)== energy(image,col-1,i,width,height)){
				totalEnergy += energy(image,col+1,i,width,height);
				seam[i] = col+1;
				col++;
			}
			//when right is less than both the middle and left
			else if(energy(image,col-1,i,width,height) < energy(image,col,i,width,height) && energy(image,col-1,i,width,height) < energy(image,col+1,i,width,height)){
				totalEnergy += energy(image,col-1,i,width,height);
				seam[i] = col-1;
				col--;
			}
		}
	}
	return totalEnergy;
}

// TODO Write this function
void removeVerticalSeam(Pixel **image, int& width, int height, int *verticalSeam)
{
	Pixel min;
	//iterating through rows of the image
	for(int i = 0; i < height; i++){
		//getting the first minimum pixel from the minimum seam
		min = image[verticalSeam[i]][i];
		//iterating from the minimum pixel column to the last column
		for(int j = verticalSeam[i]; j < width-1;j++){
			//effectively deleting the pixel by copying the pixel from the right of it
			image[j][i] = image[j+1][i];
		}
	}
	//decreasing the width after
	width--;
}

// TODO Write this function for extra credit
int getHorizontalSeam(const Pixel *const*image, int start_row, int width, int height, int* seam)
{
	if(image == nullptr) { ; }
	if(start_row == 0) { ; }
	if(width == 0) { ; }
	if(height == 0) { ; }
	if(seam == nullptr) { ; }
	return 0;
}

// TODO Write this function for extra credit
void removeHorizontalSeam(Pixel **image, int width, int& height, int *horizontalSeam)
{
	if(image == nullptr) { ; }
	if(width == 0) { ; }
	if(height == 0) { ; }
	if(horizontalSeam == nullptr) { ; }
}

int *findMinVerticalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first col (index 0)
  int *minSeam = new int[height]{0};
  int minDist = getVerticalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[height]{0};
  int candidateDistance = -1; // invalid distance

  // start at second col (index 1) since we initialized with first col (index 0)
  for (int col = 1; col < width; ++col)
  {
    candidateDistance = getVerticalSeam(image, col, width, height, candidateSeam);

    if (candidateDistance < minDist)
    { // new min
      //  swap min & candidate
      minDist = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

  // clean up 
  delete [] candidateSeam;

  return minSeam;
}

int *findMinHorizontalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first row (index 0)
  int *minSeam = new int[width]{0};
  int minDistance = getHorizontalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[width]{0};
  int candidateDistance = -1; // invalid distance

  // start at second row (index 1) since we initialized with first row (index 0)
  for (int row = 1; row < height; ++row)
  {
    candidateDistance = getHorizontalSeam(image, row, width, height, candidateSeam);

    if (candidateDistance < minDistance)
    { // new minimum
      //  swap min and candidate seams
      minDistance = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

    // clean up 
  delete [] candidateSeam;

  return minSeam;
}

Pixel **createImage(int width, int height)
{
  cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel **image = new Pixel *[width] {}; // initializes to nullptr

  for (int col = 0; col < width; ++col)
  { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    try
    {
      image[col] = new Pixel[height];
    }
    catch (std::bad_alloc &e)
    {
      // clean up already allocated arrays
      for (int i = 0; i < col; ++i)
      {
        delete[] image[i];
      }
      delete[] image;
      // rethrow
      throw e;
    }
  }

  // initialize cells
  // cout << "Initializing cells..." << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = {0, 0, 0};
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel **image, int width)
{
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i = 0; i < width; ++i)
  {
    delete[] image[i];
  }
  delete[] image;
  image = nullptr;
  cout << "End deleteImage..." << endl;
}

bool isValidColor(int colorVal)
{
  if (colorVal < 0 || colorVal > 255)
  {
    return false;
  }
  return true;
}

Pixel ** loadImage(string filename, int &width, int &height)
{
  cout << "Start loadImage..." << endl;
  // remove
  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    throw std::invalid_argument("Failed to open input file (" + filename + ")");
  }

  string type;
  ifs >> type; // should be P3
  if (toupper(type.at(0)) != 'P' || type.at(1) != '3')
  {
    throw std::domain_error("Not PPM type P3 (" + type + ")");
  }
  ifs >> width;
  // cout << "w and h: " << w << " " << h << endl;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for width");
  }
  if (width <= 0)
  {
    ostringstream oss;
    oss << "Width in file must be greater than 0 (" << width << ")";
    throw std::domain_error(oss.str());
  }

  ifs >> height;
  if (ifs.fail())
  {
    cout << "Read non-integer value for height" << endl;
  }
  if (height <= 0)
  {
    ostringstream oss;
    oss << "Height in file must be greater than 0 (" << height << ")";
    throw std::domain_error(oss.str());
  }

  int colorMax = 0;
  ifs >> colorMax;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for max color value");
  }
  if (colorMax != 255)
  {
    ostringstream oss;
    oss << "Max color value must be 255 (" << colorMax << ")";
    throw std::domain_error(oss.str());
  }

  // load image throws exceptions but we will let them pass through
  Pixel **image = createImage(width, height);

  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "Pixel(" << col << ", " << row << ")" << endl;
      ifs >> image[col][row].r;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for red");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for red (" << image[col][row].r << ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].g;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for green");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for green (" << image[col][row].r + ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].b;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for blue");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for blue (" << image[col][row].r + ")";
        throw std::domain_error(oss.str());
      }
    }
  }
  cout << "End loadImage..." << endl;
  return image;
}

void outputImage(string filename, const Pixel *const *image, int width, int height)
{
  cout << "Start outputImage..." << endl;
  // remove code
  // declare/define and open output file stream with filename
  ofstream ofs(filename);
  // ensure file is open
  if (!ofs.is_open())
  {
    throw std::invalid_argument("Error: failed to open output file - " + filename);
  }
  ofs << "P3" << endl;
  ofs << width << " " << height << endl;
  ofs << 255 << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      ofs << image[col][row].r << " ";
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
    ofs << endl;
  }
  cout << "End outputImage..." << endl;
}