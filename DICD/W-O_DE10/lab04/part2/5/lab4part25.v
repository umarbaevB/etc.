`timescale 1 ns/ 10 ps

module lab4part25(clk, RST, SET, C1, C2, C3, PulseW1, PulseW2, PulseW3, Period1, Period2, Period3, Phase1, Phase2, Phase3);
input clk, RST, SET;
input[3:0] PulseW1, PulseW2, PulseW3;
input[3:0] Period1, Period2, Period3;
input[3:0] Phase1, Phase2, Phase3;
output reg C1, C2, C3;

reg[3:0] p_width1, p_width2, p_width3;
reg[3:0] p_period1, p_period2, p_period3;
reg[3:0] count_period1, count_period2,count_period3;
reg[3:0] count_width1, count_width2, count_width3;

always @ (posedge clk) begin
	if(RST)
	begin
		p_width1 <= PulseW1; 
		p_width2 <= PulseW2; 
		p_width3 <= PulseW3; 
		p_period1 <= Period1; 
		p_period2 <= Period2;  
		p_period3 <= Period3; 
		count_period1 <= 0;
		count_period2 <= 0;
		count_period3 <= 0;
		count_width1 <= 0;
		count_width2 <= 0;
		count_width3 <= 0;
	end
	else if(SET)
	begin
		C1 <= 0;
		C2 <= 0;
		C3 <= 0;
		p_width1 <= PulseW1; 
		p_width2 <= PulseW2; 
		p_width3 <= PulseW3; 
		p_period1 <= Period1; 
		p_period2 <= Period2;  
		p_period3 <= Period3; 
		count_period1 <= Period1 - Phase1;
		count_period2 <= Period2 - Phase2;
		count_period3 <= Period3 - Phase3;
		count_width1 <= 0;
		count_width2 <= 0;
		count_width3 <= 0;
	end
	else
	begin
		count_period1 = count_period1 + 1;
		count_period2 = count_period2 + 1;
		count_period3 = count_period3 + 1;
		
		if(C1)
		begin
			count_width1 = count_width1 + 1;
			C1 = count_width1 == p_width1 ? 0 : 1;
		end
		else if(~C1)
		begin
			C1 = count_period1 == p_period1 ? 1 : 0;
			count_width1 = 0;
			count_period1 = C1 ? 0 : count_period1;
		end
		else;

		if(C2)
		begin
			count_width2 = count_width2 + 1;
			C2 = count_width2 == p_width2 ? 0 : 1;
		end
		else if(~C2)
		begin
			C2 = count_period2 == p_period2 ? 1 : 0;
			count_width2 = 0;
			count_period2 = C2 ? 0 : count_period2;
		end
		else;

		if(C3)
		begin
			count_width3 = count_width3 + 1;
			C3 = count_width3 == p_width3 ? 0 : 1;
		end
		else if(~C3)
		begin
			C3 = count_period3 == p_period3 ? 1 : 0;
			count_width3 = 0;
			count_period3 = C3 ? 0 : count_period3;
		end
		else;
	end	
end 


endmodule

