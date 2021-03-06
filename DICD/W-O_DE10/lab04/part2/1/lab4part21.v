`timescale 1 ns/ 10 ps

module lab4part21(clk, RST, Q);
input clk, RST;
wire reset;
output reg[3:0] Q;

assign reset = Q[0] && Q[3];

always @ (posedge clk) begin
	if(RST || reset)
		Q <= 4'b0;
	else
		Q <= Q + 1;
end 

endmodule

