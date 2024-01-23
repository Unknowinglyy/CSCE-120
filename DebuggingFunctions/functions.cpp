int Largest(int a, int b, int c) {
  int max;
  if (a >= b && a >= c) {
    max = a;
  } 
  else if (b >= a && b >= c) {
    max = b;
  } 
  else if (c >= a && c>= b) {
    max = c;
  }
  return max;
}

bool SumIsEven(int a, int b) {
  if((a + b) % 2 == 1 || (a+b) % 2 == -1){
	return false;
  }
  else{
	return true;
  }
  return false;
}

int BoxesNeeded(int apples) {
	int numBoxes = 0;
	int numApples = 0;
	if(apples <= 0){
		return 0;
	}
	else if(apples == 20){
		return 1;
	}
	else if(apples > 20){
		numApples = apples/20;
		if(apples%20 != 0){
			numApples++;
		}
	}
	else if(apples < 20){
		numBoxes++;
	}
	numBoxes = numBoxes + numApples;
	return numBoxes;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  double Apercentage = 1.0*A_correct/A_total*1.0;
  double Bpercentage = 1.0*B_correct/B_total*1.0;
  if((A_correct > A_total) || (B_correct > B_total)){
	  throw std::invalid_argument("Invalid Argument");
  }
  else if(A_total == 0 || B_total == 0){
	  throw std::invalid_argument("Invalid Argument");
  }
  else if(A_correct < 0 || B_correct < 0 || A_total < 0 || B_total < 0){
	  throw std::invalid_argument("Invalid Argument");
  }
  if((Apercentage) > (Bpercentage)){
	  return true;
  }
  else{
	  return false;
  }
  return false;
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if (pizzas >= 10 && pizzas <= 20) {
    return true;
  }
  if (is_weekend && pizzas >= 10) {
    return true;
  }
  return false;
}

int SumBetween(int low, int high) {
  if(low > high){
	  throw std::invalid_argument("Invalid Argument");
  }
  if(low+high == -1){
	  return low;  
  }
  else if(low+high == 1){
	  return high;
  }
  if(low == high){
	  return low;
  }
  else if((low*-1) == high){
	  return 0;
  }
  int value = 0;
  for (int n = low; n <= high; n++) {
	  value += n;
	  if((value > 0 && n > 0) && (n > 2147483647 - value && 2147483647 - value != 0)){
		  throw std::overflow_error("Integer Overflow has occured.");
	  }
	  else if((value < 0 && n < 0) && (n < -2147483648 - value && -2147483648 - value != 0)){
		  throw std::overflow_error("Integer Overflow has occured.");
	  }			  
  }
  return value;
}

int Product(int a, int b) {
  if((a > 0 && b > 0 && 2147483647/a < b) || (a > 0 && b > 0 && 2147483647/b < a)){
	  throw std::overflow_error("Integer Overflow has occured.");
  }
  else if((a < 0 && b < 0 && 2147483647/a > b) || (a < 0 && b < 0 && 2147483647/b > a)){
	  throw std::overflow_error("Integer Overflow has occured.");
  }
  else if((a < 0 && b > 0 && -2147483648/a < b) ||(a < 0 && b > 0 && -2147483648/b > a)){
	  throw std::overflow_error("Integer Overflow has occured.");
  }
  else if((a > 0 && b < 0 && -2147483648/a > b) || (a > 0 && b < 0 && -2147483648/b < a)){
	  throw std::overflow_error("Integer Overflow has occured.");
  }

  return a * b;
}