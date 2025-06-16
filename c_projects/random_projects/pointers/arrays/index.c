int main() {
  char str[2];
  char *ptr;

  int len = sizeof(str) / sizeof(str[0]);

  str[0] = 'a';

  *(str + 1) = 'a'; // the same str[1] = 'a'
}
