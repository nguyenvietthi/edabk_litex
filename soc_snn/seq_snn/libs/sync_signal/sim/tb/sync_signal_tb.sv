`timescale 1ns/1ps
module sync_signal_tb ();
	reg clk1       ; 
	reg reset_n    ; 
	reg clk2       ; 
	reg rst_n2     ; 
	reg signal_in  ; 
	wire signal_out;

	sync_signal sync_signal_ins(
		.clk1       (clk1      ),
		.rst_n1     (reset_n    ),
		.clk2       (clk2      ),
		.rst_n2     (reset_n    ),
		.signal_in  (signal_in ),
		.signal_out (signal_out)
	);

	initial begin
	    clk2 = 0;
	    forever #5 clk2 = ~clk2;
	end

	initial begin
	    clk1 = 0;
	    forever #4.5 clk1 = ~clk1;
	end

	initial begin 
		reset_n = 0;
		signal_in = 0;
		@(negedge clk1); 
		reset_n = 1;
		repeat (10) @(negedge clk1); 
		signal_in = 1;
		@(negedge clk1);
		signal_in = 0;
		repeat (50) @(negedge clk1);
		signal_in = 1;
		@(negedge clk1);
		signal_in = 0;
		repeat (50) @(negedge clk1);
		$stop;
	end
endmodule