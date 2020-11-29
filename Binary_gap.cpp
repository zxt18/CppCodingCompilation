int solution(int N) {
 // write your code in C++11 (g++ 4.8.2)
 int zeros = -1;
 int max_gap = 0;

     while (N > 0) {
     if ((N & 1) == 1) {
        zeros = 0;
      }
      else if (zeros != -1) { //after first one
        zeros++;
       if (max_gap < zeros) {
          max_gap = zeros;
        }
      }

        N = N >> 1;
    }

 return max_gap;
}
