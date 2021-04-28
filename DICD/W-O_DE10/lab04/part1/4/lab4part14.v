`timescale 1 ns/ 10 ps

module lab4part14(clk, R, S, Size, D, Q);
input clk, R, S;
input[0:3] Size;
input[7:0] D;
output reg[15:0] Q;
reg O;
integer i;

always @ (posedge clk) begin 
	if (R) 
		 Q <= 16'b0;
	else
	begin
		if(S)
		begin
		for (i = 0; i < Size; i = i + 1)
         	begin
            	O = Q[0];
		Q = {O, Q[15:1]};
            	end
		end
		else
        	Q <= {Q[15:8], D};
	end
end 

endmodule

