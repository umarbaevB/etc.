`timescale 1 ns/ 10 ps

module lab4part22(clk, RST, UP_DOWN, Q);
input clk, RST, UP_DOWN;
output reg[3:0] Q;


always @ (posedge clk) begin
	if(RST)
		Q <= 4'b0;
	else
	begin
		if(UP_DOWN)
			Q <= Q + 1;
		else
			Q <= Q - 1;
	end
end 

endmodule

