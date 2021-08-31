int remove_multiples(int num) {
   stack_type s;
   stack_ptr p = &s;
   init(p);
   int result = 0;
   int mul = 1;
   while (num > 0) {
      int temp = num % 10;
      num = num / 10;
      if (is_empty(s)) {
         push(p, temp);
      }
      else if (peek(p) != temp) {
         result += pop(p) * mul;
         mul *= 10;
         push(p, temp);
      }
   }
   
   while (!is_empty(s)) {
      result += pop(p) * mul;
      mul *= 10;
   }
   return result;
}