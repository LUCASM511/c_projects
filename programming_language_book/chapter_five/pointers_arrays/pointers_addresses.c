int main() {
  int x = 1, y = 2, z[10];
  int *ip; // is a pointer to int

  ip = &x;    // ip now points to x
  y = *ip;    // y is now 1
  *ip = 0;    // x is now 0
  ip = &z[0]; // ip now points tp z[0]

  double *dp, atof(char *c); // convert a string for a floating-point number

  return 0;
}
