module sync_signal (
	input      clk1      ,   
	input      rst_n1    , 
	input      clk2      ,    
	input      rst_n2    ,
	input      signal_in ,
	output reg signal_out
);

	reg tmp_signal;

	always @(posedge clk1 or negedge rst_n1) begin 
		if(~rst_n1) begin
			tmp_signal <= 'b0;
		end else if(signal_in) begin 
			tmp_signal <= 'b1;
		end else if (signal_out) begin
			tmp_signal <= 'b0;
		end
	end

	always @(posedge clk2 or negedge rst_n2) begin
		if(~rst_n2) begin
			signal_out <= 'b0;
		end else if (tmp_signal) begin
			signal_out <= 'b1;
		end else begin 
			signal_out <= 'b0;
		end
	end
endmodule