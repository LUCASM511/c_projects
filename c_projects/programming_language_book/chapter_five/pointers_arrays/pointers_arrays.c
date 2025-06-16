int main() {
  int a[10]; // array of size 10
  int *pa;   // pointer to int

  pa = &a[0]; // point to element zero of a,
              // pa contains the address of a[0]

  int x = *pa; // copy the contents of a[0] to x

  // pa + i points i elements after pa
  // pa - i points i elements before pa
  pa = pa + 1;
  pa = pa - 1;

  // *(pa + i); refers to the contents of a[1]
  *pa = *(pa + 1);

  return 0;
}
