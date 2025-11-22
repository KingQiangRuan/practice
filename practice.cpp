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


uint64_t get_value_64bit(const uint8_t* data, uint32_t msb, uint32_t lsb)
{
   if (msb < lsb) {
      std::cout << "msb must be bigger than lsb.\n";
      assert(0);
   }
   uint64_t value = 0;
   uint16_t bit_len = msb - lsb + 1;
   for (uint16_t i = 0; i < bit_len; i++) {
      uint16_t cur_bit = lsb + i;
      uint16_t byte_pos = cur_bit / 8;
      uint16_t bit_pos = cur_bit % 8;
      value  |= static_cast<uint64t_t>(((data[byte_pos] >> bit_pos ) & 1)) << i;
   }
   return value;
}

const st::vector<uint8_t> get_value_bigger_64bit(const uint8_t* data, uint32_t msb, uint32 lsb)
{
   if (msb < lsb) {
      std::cout << "msb must be bigger than lsb.\n";
      assert(0);
   }
   uint16_t pos = 0;
   uint16_t bit_len = msb - lsb + 1;
   uint16_t byte_num = (bit_len % 8 == 0) ? bit_len / 8 : (bit_len / 8 + 1);
   
   if (byte_num > 0xFFFF) {
      std::vector<uint8_t> data_buf_0(0);
      return data_buf_0;
   }
   
   std::vector<uint8_t> data_buf(byte_num);
   uint8_t value = 0;
   uint8_t new_bit_pos = 0;  
   
   for (uint16_t i = 0; i < bit_len; i++) {
      uint16_t cur_bit = lsb + i;
      uint16_t byte_pos = cur_bit / 8;
      uint16_t bit_pos = cur_bit % 8;
      value  |= static_cast<uint64t_t>(((data[byte_pos] >> bit_pos ) & 1)) << new_bit_pos;
      new_bit_pos++;
      
      if ((i+1) % 8 == 0) {
         data_buf[pos++] =value;
         value = 0;
         new_bit_pos = 0;
      }
   }

   if (bit_len % 8 != 0) {
       data_buf[pos++] = value;
   }
   return value;
}
