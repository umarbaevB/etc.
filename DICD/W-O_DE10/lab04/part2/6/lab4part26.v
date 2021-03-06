`timescale 1 ns/ 10 ps

module lab4part26(clk, RST, duty, Q);
input clk, RST;
input[3:0] duty;
output reg Q;

reg[3:0] count = 0;


always @ (posedge clk) begin
	if(RST)
		Q <= 0;
	else
	begin
		count <= count + 1;
		Q = count < duty + 1 ? 1 : 0;
	end
end 
 

endmodule

