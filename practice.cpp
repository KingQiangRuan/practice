/**
 * Time
 */
#inlcude <chrono>
#include <iostream>

void  high_resolution_time()
{
   auto start = std::chrono::high_resolution_clock::now();
  
   std::cout << "hehe\n";
   auto stop = std::chrono::high_resolution_clock::now();

   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

   std::cout << execution time: " << duration.count() << " ms" << std::endl;
}
