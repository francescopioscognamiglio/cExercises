extern void myOpenFunction(); // refers to the function defined in the other file
//extern void myPrivateFunction(); // should refer to the function defined in the oter file, but there it's a static (private) function, so it cannot be used

void main() {
  myOpenFunction();
  //myPrivateFunction();
}
