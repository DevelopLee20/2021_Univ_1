int remove_multiples(n)
{
   stack_type s;
   
   init(&s);
    int i = 0;
   int sum = 0;
   int key;
   int r = 0;
   while (n != 0) {
      push(&s, n % 10);
      n /= 10;
   }
   while (!is_empty(s)) {
      key = pop(&s);
      sum += key * pow(10, i);
      while (!(is_empty(s)) && (peek(s) == key))
         pop(&s);
      i++;
   }
   while (sum) {
      r = (r * 10) + (sum % 10);
      sum /= 10;
   }
   return r;
}