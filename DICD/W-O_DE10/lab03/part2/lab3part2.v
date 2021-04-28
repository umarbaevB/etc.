`timescale 1 ns/ 10 ps

module lab3part2(f1, f2, f3, f4, f5, f6, x, y, z);

input x, y, z;
output f1, f2, f3, f4, f5, f6;

assign f1 = (~x & ~y & ~z) | (x & z);
assign f2 = (y & z) | (x & ~z);
assign f3 = ~x & y;
assign f4 = x & y & ~z; 
assign f5 = y | (z & ~x);
assign f6 = x | (y & z);

		
endmodule
